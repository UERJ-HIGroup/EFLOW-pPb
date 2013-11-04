import FWCore.ParameterSet.Config as cms

process = cms.Process("EnergyFlowHIAnalyzer")
process.TFileService = cms.Service("TFileService", fileName = cms.string('/afs/cern.ch/work/p/prado/private/EFLOW2013/Test-NoPixelTrack-Vertex.root') )

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10000

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                                 'file:/afs/cern.ch/work/p/prado/private/EFLOW2013/out-08BE6D25-C273-E211-BB7C-001D09F2924F.root'
                               # 'file:/afs/cern.ch/work/m/malek/private/PilotpPbrun/ampt_pPb_f2976_e.root'
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/F80DCC31-61FD-E111-887A-0019B9F4A1D7.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/F85EADE5-61FD-E111-B444-0019B9F72F97.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/F8A827C4-5FFD-E111-BE50-0030486730C6.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/F8F782C0-45FD-E111-8AC6-003048D2C0F4.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/F8FD4F08-58FD-E111-888C-003048D374F2.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA02EA78-46FD-E111-BACF-003048D2BBF0.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA10F66C-65FD-E111-B76E-BCAEC5364C4C.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA13253A-61FD-E111-9C4D-001D09F24D67.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA13FC85-48FD-E111-A5F7-003048D2BB90.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA21B49B-62FD-E111-B4CF-001D09F23D1D.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA231EBA-64FD-E111-95CB-001D09F251FE.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FA503A80-41FD-E111-B61D-001D09F29169.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FC2BABCE-5EFD-E111-A5BC-001D09F28D54.root' ,
        #'/store/hidata/express/PARun2012/ExpressPhysics/FEVT/Express-v1/000/202/792/FC88600C-5FFD-E111-B55E-001D09F24763.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/0ADA3642-1464-E211-B190-5404A63886EF.root' ,
        #'/store/hidata/HIRun2013/PAMinBiasUPC/RECO/PromptReco-v1/000/210/855/00000/0249E200-C569-E211-9989-E0CB4E55365D.root',
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/0E2CCA75-0B64-E211-AAE3-001D09F2841C.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/0E9C0388-3B64-E211-9164-BCAEC518FF63.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/10F9059C-1B64-E211-B78F-003048D2BEA8.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/12016D17-1664-E211-86C0-003048F1C424.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/1292E6F4-0F64-E211-8136-003048D2BC52.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/1294E21B-4064-E211-BFC9-001D09F29146.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/12BE2C85-1264-E211-87F4-001D09F251FE.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/12CC0F3D-0064-E211-A3AB-5404A6388697.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/14135917-1664-E211-8431-003048F117B6.root' ,
        #'/store/express/HIRun2013/ExpressPhysics/FEVT/Express-v1/000/210/614/00000/14E30B41-1464-E211-9D94-5404A63886B7.root' ,    
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/211/635/00000/609A17DD-2075-E211-AB2C-003048D2BC4C.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/0676271D-8B66-E211-A3B9-002590489E02.root',
        #'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/3429FF41-8A66-E211-BD0C-001D09F26C5C.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/0867DA46-A766-E211-BD0B-003048F117B4.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/007B5E37-8B66-E211-871E-001D09F244DE.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/F05DBB72-BB66-E211-A628-BCAEC5364CED.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/20115CA0-8C66-E211-99CA-BCAEC518FF74.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/EA898DA4-BE66-E211-82C2-002590489DFA.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/EAA11F6B-8A66-E211-8E07-001D09F241F0.root',
	#'/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/614/00000/EE0E893A-8B66-E211-9009-003048D2BDD8.root',


#	'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/211/571/00000/BA5BD62C-BC73-E211-96D5-485B39897227.root',
#	'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/211/571/00000/C412B92E-BC73-E211-BD91-5404A640A639.root',
#	'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/211/571/00000/C499E831-BC73-E211-A0DE-BCAEC518FF80.root',
#	'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/211/571/00000/F8BB3E35-BC73-E211-99AD-001D09F290CE.root',
	 
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/06E52E07-DE67-E211-B6E0-0025901D5DF4.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/0C3C7F09-DE67-E211-A501-001D09F2512C.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/0E614409-DE67-E211-BF3C-BCAEC518FF89.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/12191509-DE67-E211-BEA3-002481E0D73C.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/18C60B0A-DE67-E211-A17D-001D09F25041.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/2055FC09-DE67-E211-8B14-001D09F25109.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/26D364E5-DE67-E211-8403-003048D2C16E.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/2E8CB907-DE67-E211-9288-5404A63886C1.root',
#        '/store/hidata/HIRun2013/MinimumBias/RECO/PromptReco-v1/000/210/676/00000/3080A00C-DE67-E211-81FD-5404A640A648.root',




	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/FC62F647-3C65-E211-B0ED-BCAEC518FF89.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/CEF2E946-3D65-E211-B647-002481E0D524.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/FA6E8E46-3C65-E211-A234-BCAEC5329719.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/F2DD97E0-3665-E211-9BE9-5404A63886C7.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/E6470ADD-3C65-E211-AB26-003048D2C092.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/CA682C46-3E65-E211-A094-5404A63886EB.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/E4839143-5165-E211-A954-5404A63886CC.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/9A06393C-3765-E211-A863-001D09F24D67.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/E09AB5AC-5165-E211-9383-003048D37456.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/E0425FA2-3765-E211-A929-BCAEC518FF30.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/D6AE4FA7-3F65-E211-873B-5404A63886D2.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/04E56503-3765-E211-B806-001D09F23D1D.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/061DF258-3965-E211-981A-003048D2BC4C.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/1032D3A1-3B65-E211-8F80-003048D2C020.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/06912859-3965-E211-B6E1-001D09F24DA8.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/0C686CAD-3765-E211-9258-001D09F276CF.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/10E12BF7-3D65-E211-9682-002481E0CC00.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/18C518D2-5265-E211-AC73-5404A63886AF.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/1032D448-3E65-E211-8E19-5404A6388694.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/1C51BD79-3A65-E211-863C-001D09F28D4A.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/381984A0-3B65-E211-ABBD-003048D2C01A.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/20527D4B-3F65-E211-A13A-BCAEC518FF8D.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/4E741982-3F65-E211-971E-002481E0D7C0.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/46CF647F-3F65-E211-9B09-BCAEC518FF89.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/3C451E09-3B65-E211-A0D6-5404A640A648.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/3ECC1ED5-3F65-E211-BD76-003048D3751E.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/4CD5C957-3765-E211-9242-003048F110BE.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/508965A3-3D65-E211-B714-E0CB4E4408C4.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/50F4B244-5765-E211-AEC7-003048D3C980.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/503DA23A-3865-E211-B9A0-5404A640A648.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/58318B52-3665-E211-8BD4-BCAEC518FF8A.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/62A29F43-3D65-E211-9A4E-003048F1C82A.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/527BCC56-3965-E211-B1D3-003048CFB40C.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/6AECD393-3E65-E211-9E35-003048D3751E.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/642406D7-5065-E211-AB1F-003048D2C092.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/72393C95-3E65-E211-A083-001D09F2932B.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/7422B5BB-3665-E211-86E5-BCAEC532970D.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/902B3315-3A65-E211-BB5D-001D09F24024.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/7AAB2F16-5065-E211-8B3E-BCAEC53296F4.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/7C403FD1-5265-E211-9F0F-0025901D5DEE.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/9000B244-5265-E211-990D-5404A63886AC.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/9A06393C-3765-E211-A863-001D09F24D67.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/867D1147-3C65-E211-AEDA-BCAEC518FF54.root',
	#'/store/hidata/HIRun2013/PAMinBias1/RECO/PromptReco-v1/000/210/534/00000/9E105B96-5765-E211-ADC9-0019B9F72D71.root',


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
    HistogramFile = cms.untracked.string('hltbitanalysis-v2.root')
    )
                                        )##end of HLT


################process.fwdana = cms.EDAnalyzer('ForwardAnalyzer')


################process.upcpixeltrackana = cms.EDAnalyzer('UPCTrackAnalyzer',
################                                          trackCollection=cms.string("pixelTracks"))


process.load('RecoHI.HiCentralityAlgos.HiCentrality_cfi')
process.load('RecoHI.HiCentralityAlgos.CentralityBin_cfi')
################process.load('Appeltel.RpPbAnalysis.PAPileUpVertexFilter_cff')

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


#process.p = cms.Path(process.PAcollisionEventSelection * process.pileupVertexFilterCutGplus * process.pACentrality_step * process.Mytreemaker * process.fwdana * process.upcpixeltrackana * process.centralityBin) 

process.p = cms.Path(process.PAcollisionEventSelection * process.pACentrality_step * process.Mytreemaker * process.centralityBin) #coment fwdana,  pileupVertexFilterCutGplus, upcpixeltrackana, pACentrality_step, centralityBin, PAAcollisionEventSelection
#used for testing
