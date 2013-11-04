import FWCore.ParameterSet.Config as cms

process = cms.Process("EnergyFlowHIAnalyzer")
process.TFileService = cms.Service("TFileService", fileName = cms.string('/afs/cern.ch/work/p/prado/private/EFLOW2013/Test-Nov-01.root') )

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                               # 'file:/afs/cern.ch/work/m/malek/private/PilotpPbrun/ampt_pPb_f2976_e.root'
                               'file:/afs/cern.ch/work/p/prado/private/EFLOW2013/out-08BE6D25-C273-E211-BB7C-001D09F2924F.root'
       
        ),
)

process.load('HeavyIonsAnalysis.Configuration.collisionEventSelection_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#data
process.GlobalTag.globaltag = 'GR_P_V43::All'
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('RecoLocalTracker.SiPixelRecHits.PixelCPEESProducers_cff')



process.Mytreemaker = cms.EDAnalyzer('EnergyFlowHIAnalyzer',
						 PFana = cms.bool(False),
						 pfCandidateLabel = cms.InputTag("particleFlow","","MyRecoPF"),
) 

process.hltbitanalysis = cms.EDAnalyzer('HLTBitAnalyzer',

                                        ### Trigger objects
                                        l1GctHFBitCounts                = cms.InputTag("gctDigis"),
                                        l1GctHFRingSums                 = cms.InputTag("gctDigis"),
                                        l1GtObjectMapRecord             = cms.InputTag("hltL1GtObjectMap::HLT"),
                                        l1GtReadoutRecord               = cms.InputTag("gtDigis::RECO"),

                                        l1extramc                       = cms.string('l1extraParticles'),
                                        l1extramu                       = cms.string('l1extraParticles'),
                                        hltresults                      = cms.InputTag("TriggerResults::HLT"),
                                        HLTProcessName                  = cms.string("HLT"),
                                        UseTFileService                 = cms.untracked.bool(True),

                                        ### Run parameters
                                        RunParameters = cms.PSet(
    HistogramFile = cms.untracked.string('hltbitanalysis.root')
    )
                                        )##end of HLT


#process.fwdana = cms.EDAnalyzer('ForwardAnalyzer')


#process.upcpixeltrackana = cms.EDAnalyzer('UPCTrackAnalyzer',
#                                          trackCollection=cms.string("pixelTracks"))


process.load('RecoHI.HiCentralityAlgos.HiCentrality_cfi')
process.load('RecoHI.HiCentralityAlgos.CentralityBin_cfi')
process.load('Appeltel.RpPbAnalysis.PAPileUpVertexFilter_cff')

from HeavyIonsAnalysis.Configuration.CommonFunctions_cff import *
overrideCentrality(process)

process.HeavyIonGlobalParameters = cms.PSet(
  centralityVariable = cms.string("HFtowersTrunc"),
  nonDefaultGlauberModel = cms.string(""),
  centralitySrc = cms.InputTag("pACentrality"),
  pbRunFlip = cms.untracked.uint32(99999999)
  )

process.hiEvtAnalyzer = cms.EDAnalyzer('HiEvtAnalyzer',
   Centrality    = cms.InputTag("hiCentrality"),
   CentralityBin = cms.InputTag("centralityBin"),
   EvtPlane      = cms.InputTag("hiEvtPlane","recoLevel"),
   EvtPlaneFlat  = cms.InputTag("hiEvtPlaneFlat",""),                               
   Vertex        = cms.InputTag("hiSelectedVertex"),
   HiMC          = cms.InputTag("heavyIon"),
   doCentrality  = cms.bool(True),
   doEvtPlane    = cms.bool(False),
   doEvtPlaneFlat= cms.bool(False),                               
   doVertex      = cms.bool(True),
   doMC          = cms.bool(False)
)






#process.load("HLTrigger.HLTfilters.hltHighLevel_cfi")
#process.hltZeroBias = process.hltHighLevel.clone()
#process.hltZeroBias.HLTPaths = ["HLT_PAZeroBiasPixel_SingleTrack_v1"]


#import HLTrigger.HLTfilters.hltHighLevel_cfi
#process.hltMB = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
#process.hltMB.HLTPaths = ['HLT_PAZeroBiasPixel_SingleTrack__v*']
#process.hltMB.andOr = cms.bool(True)
#process.hltMB.throw = cms.bool(False)


#triggerSelection = cms.EDFilter( "TriggerResultsFilter",
#    triggerConditions = cms.vstring(
#     'HLT_PAZeroBiasSinglePixelTrack'),
#    hltResults = cms.InputTag( "TriggerResults", "", "HLT" ),
#    l1tResults = cms.InputTag( "gtDigis" ),
#    l1tIgnoreMask = cms.bool( False ),
#    l1techIgnorePrescales = cms.bool( False ),
#    daqPartitions = cms.uint32( 1 ),
#    throw = cms.bool( True )
#)


#######process.p = cms.Path(process.PAcollisionEventSelection * process.pileupVertexFilterCutGplus * process.pACentrality_step * process.Mytreemaker * process.fwdana * process.upcpixeltrackana * process.centralityBin) 

process.p = cms.Path(process.PAcollisionEventSelection * process.pACentrality_step * process.Mytreemaker * process.centralityBin) #* process.fwdana *process.upcpixeltrackana  * process.pileupVertexFilterCutGplus


####process.p = cms.Path(process.Mytreemaker) #* process.fwdana *process.upcpixeltrackana  * process.pileupVertexFilterCutGplus


#used for testing









