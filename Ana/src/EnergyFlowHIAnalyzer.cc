// system include files
#include <memory>
#include <algorithm>
#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>


// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/HcalRecHit/interface/CastorRecHit.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/HcalDetId/interface/HcalCastorDetId.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/HcalDigi/interface/CastorDataFrame.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"

#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/Records/interface/CastorGeometryRecord.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"

#include "DataFormats/HcalRecHit/interface/HFRecHit.h"
#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "CondFormats/HcalObjects/interface/HcalQIECoder.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrations.h"
#include "RecoLocalCalo/HcalRecAlgos/interface/HcalCaloFlagLabels.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"

#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/CaloTowers/interface/CaloTower.h"
#include "DataFormats/Candidate/interface/Candidate.h"


#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrations.h"
#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloTopology/interface/HcalTopology.h"


///
#include "FWCore/Common/interface/TriggerNames.h"
#include "HLTrigger/HLTanalyzers/interface/HLTrigReport.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "L1Trigger/L1ExtraFromDigis/interface/L1ExtraParticleMapProd.h"
#include "DataFormats/L1Trigger/interface/L1ParticleMap.h"
#include "DataFormats/L1Trigger/interface/L1ParticleMapFwd.h"
#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetupFwd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetup.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"
///

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TGraphErrors.h"
#include "TProfile.h"
#include "TLorentzVector.h"
#include "TNtuple.h"
#include <TRandom3.h>


#include "DataFormats/HeavyIonEvent/interface/CentralityProvider.h"

#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHitCollection.h"
#include "DataFormats/SiPixelDetId/interface/PixelSubdetector.h"
#include "DataFormats/SiPixelDetId/interface/PXBDetId.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/SiPixelCluster/interface/SiPixelCluster.h" 
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetUnit.h"
#include "Geometry/TrackerGeometryBuilder/interface/PixelGeomDetType.h"
//#include "Geometry/TrackerTopology/interface/RectangularPixelTopology.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "CalibFormats/CaloTPG/interface/CaloTPGRecord.h"


#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h" 
#include "Geometry/TrackerGeometryBuilder/interface/TrackerGeometry.h"




// CaloMET
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETFwd.h"
// TCMET
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METFwd.h"
// PFMET
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h"


//pf candidates
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"



//ecal cleaner

#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgo.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include "CondFormats/DataRecord/interface/EcalChannelStatusRcd.h"
#include "CondFormats/EcalObjects/interface/EcalChannelStatusCode.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"

#include "DataFormats/HcalRecHit/interface/HBHERecHit.h"
//#include "DataFormats/HcalRecHit/interface/HBHERecHitCollections.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"




#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"


#define debug 0

using namespace edm;
using namespace std;
using namespace reco;

//
// class declaration
//

class EnergyFlowHIAnalyzer : public edm::EDAnalyzer {
public:
  explicit EnergyFlowHIAnalyzer(const edm::ParameterSet&);
  ~EnergyFlowHIAnalyzer();
  
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  const CaloGeometry* fGeo;
  edm::ESHandle<HcalDbService> conditions;
  
  // ----------member data ---------------------------
  
  CentralityProvider * centrality_;
  

  //  bool ifCASTOR;
  Int_t eventNum;
  Int_t lumiBlock;
  Int_t runNumber;
  Int_t bunchCrossing;
  
  Double_t TotalHFRecHitEnergy;

  Int_t NbOfAnalyzedEvents;
  Int_t nbOfHFRecHits;
  Int_t nbOfCaloTowers;
  TTree*perEvent;

  Double_t HFRecHitEnergy;
  Double_t RecHitEta; 
  
  
  int fNumRecHits;
  int fNumHBHERecHits;
  int fNumECALRecHits;
  int fNumECALEERecHits;

  ////rec hits
  float fEnergy[1728];
  float fTransverseEnergy[1728];
  float fEta[1728];
  int fHFieta[1728];


  float fHBHERecHitEta[10000];
  float fHBHERecHitEnergy[10000];
  float fHBHERecHitTransverseEnergy[10000];
  int fHBHEieta[10000];


  float fECALRecHitEta[100000];
  float fECALRecHitEnergy[100000];
  float fECALRecHitTransverseEnergy[100000];
 

  float fECALEERecHitEta[100000];
  float fECALEERecHitEnergy[100000];
  float fECALEERecHitTransverseEnergy[100000];
 




  ///


  float fLongEnergyT[864];
  float fShortEnergyT[864];

  Int_t depth[1728];
  float time[1728];
  
  
  TTree* fTree; 
  TTree*HF_tree;
  
  
  //for CaloTowers
  int fNumCaloTowers;
  float fCaloTowerEnergy[10000];
  float fCaloTowerEta[10000];
  float fCaloTowerTransverseEnergy[10000];
  int fieta[10000];
  int fiphi[10000];
  
  float CaloTowerEnergy;
  float CaloTowerEta;
  float CaloTowerTransverseEnergy;


  float emfraction[10000];
  float hadfraction[10000];

  
  TTree*ctTree;
  TTree*ct1Tree;

  Int_t centralityBin;

  Int_t LRecHits;
  Int_t SRecHits;



  //for pf candidates
  int fNumOfPFCandidates;
  float pfEnergy[10000];
  float pfEta[10000];
  float pfTransverseEnergy[10000];
  TTree*pfTree;
 
  edm::InputTag pfCandidateLabel_;
  bool pfana_;


  TH1D* EnergyFlowPlot;
  TH1D* EnergyFlowPlotPF;
   edm::Service<TFileService> fileService;

  Int_t nPixelTracks;
  //ecal cleaner
  /*
  edm::InputTag ebReducedRecHitCollection_;
  double minEt_;
  double swissThreshold_;
  double timeThreshold_;
  bool avoidIeta85_;
  */
  
};

EnergyFlowHIAnalyzer::EnergyFlowHIAnalyzer(const edm::ParameterSet& iConfig)
{
  
    pfCandidateLabel_ = iConfig.getParameter<edm::InputTag>("pfCandidateLabel");
    pfana_ = iConfig.getParameter<bool>("PFana");



    double eta_bin[83]={-5.191,-4.889,-4.716,-4.538,-4.363,-4.191,-4.013
			,-3.839,-3.664,-3.489,-3.314,-3.139,-2.964,-2.853
			,-2.650,-2.500,-2.322,-2.172,-2.043,-1.930,-1.830
			,-1.740,-1.653,-1.566,-1.479,-1.392,-1.305,-1.218
			,-1.131,-1.044,-0.957,-0.879,-0.783,-0.696,-0.609
			,-0.522,-0.435,-0.348,-0.261,-0.174,-0.087,0.000
			,0.087,0.174,0.261,0.348,0.435,0.522,0.609,0.696
			,0.783,0.879,0.957,1.044,1.131,1.218,1.305,1.392
			,1.479,1.566,1.653,1.740,1.830,1.930,2.043,2.172
			,2.322,2.500,2.650,2.853,2.964,3.139,3.314,3.489
			,3.664,3.839,4.013,4.191,4.363,4.538,4.716,4.889
			,5.191};
    
    
    EnergyFlowPlot = fileService->make<TH1D>("EnergyFlowPlot", "Energy Flow; #eta ; Energy (GeV)", 82, eta_bin);
    EnergyFlowPlotPF = fileService->make<TH1D>("EnergyFlowPlotPF", "Energy Flow PF; #eta ; Energy (GeV)", 82, eta_bin);

    /*

    //ecal cleaner

    ebReducedRecHitCollection_       = iConfig.getParameter<edm::InputTag>("ebReducedRecHitCollection"); //,"reducedEcalRecHitsEB");
    minEt_                          = iConfig.getParameter<double>("minEt");
    swissThreshold_                 = iConfig.getParameter<double>("swissThreshold");
    timeThreshold_                 = iConfig.getParameter<double>("timeThreshold");
    avoidIeta85_                    = iConfig.getParameter<bool>("avoidIeta85");
    */
    
}
  EnergyFlowHIAnalyzer::~EnergyFlowHIAnalyzer()
  {
  }

// ------------ method called to for each event  ------------
void EnergyFlowHIAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  NbOfAnalyzedEvents++;
  centralityBin=0;
  
  if(!centrality_) centrality_ = new CentralityProvider(iSetup); 
  centrality_->newEvent(iEvent,iSetup);  // make sure you do this first in every event
  
  double c = centrality_->centralityValue();
  int bin = centrality_->getBin();
  centralityBin=bin;
  
  //cout<<"event   "<<NbOfAnalyzedEvents<<"\t"<<centralityBin<<endl;

  edm::Handle<reco::TrackCollection> pixelTracks;
     iEvent.getByLabel("pixelTracks",pixelTracks);
      nPixelTracks = pixelTracks->size();

   //   cout<<"nPixelTracks  "<<nPixelTracks<<endl;


  //cout<<centralityBin<<"\t"<<NpartSigmaOfBin(bin)<<endl;

  //cout<<"event  "<<NbOfAnalyzedEvents<<"\t"<<bin<<"\t"<<centrality_->NpartMeanOfBin(bin)<<"\t"<<centrality_->NpartSigmaOfBin(bin)<<endl;

  //trigger path print
///trigger
/*
  Handle<TriggerResults> HLTR;
  iEvent.getByLabel("TriggerResults",HLTR);
  
const edm::TriggerNames & triggerNames = iEvent.triggerNames(*HLTR);

const unsigned int n(triggerNames.size());

  cout<<"size of the trigger table:  "<<n<<endl;
  for (unsigned int i=0; i!=n; ++i) {
    std::string pathname = triggerNames.triggerName(i); 
    cout<<"pathnames in this event:  "<<pathname<<endl;
  }

*/

  /*
  //Ecal spike cleaner
  //grab rechits
   edm::Handle<EcalRecHitCollection> EBReducedRecHits;
   iEvent.getByLabel(ebReducedRecHitCollection_, EBReducedRecHits);
   const EcalRecHitCollection *rechits = EBReducedRecHits.product();

   //get the rechit geometry
   edm::ESHandle<CaloGeometry> theCaloGeom;
   iSetup.get<CaloGeometryRecord>().get(theCaloGeom);
   const CaloGeometry* caloGeom = theCaloGeom.product();

   bool tagecal=false;
   double rhEt;
   if(rechits) {
       for(EcalRecHitCollection::const_iterator it=rechits->begin(); it!=rechits->end(); it++) {
           const GlobalPoint &position = caloGeom->getPosition(it->id());
           rhEt = it->energy()/cosh(position.eta());
           if(rhEt > minEt_ && (EcalSeverityLevelAlgo::swissCross(it->id(), *rechits,0,avoidIeta85_) > swissThreshold_ || 
abs(it->time()) > timeThreshold_)) {
               tagecal = false;
           }
       }
   }
   tagecal = true;
   

  */





  //cout<<bin<<"\t"<<centrality_->NpartMeanOfBin(bin)<<endl;
        
      
      TotalHFRecHitEnergy=0.;
      nbOfHFRecHits=0;
      nbOfCaloTowers=0;
      
      iSetup.get < HcalDbRecord > ().get(conditions);
      edm::ESHandle < CaloGeometry > caloGeom;
      iSetup.get < CaloGeometryRecord > ().get(caloGeom);
      fGeo = caloGeom.product();
      
      if(debug) cout<<""<<endl;
      eventNum      = iEvent.id().event() ;
      runNumber     = iEvent.id().run() ;
      lumiBlock     = iEvent.luminosityBlock() ;
      bunchCrossing = iEvent.bunchCrossing();
      
      
      //----------------------
      //RecHits analysis     -
      //----------------------
      // hf rechits
      Handle < HFRecHitCollection > hf_recHits_h;
      iEvent.getByLabel("hfreco", hf_recHits_h);
      nbOfHFRecHits = hf_recHits_h->size();
      //cout<<"hfreco  "<<hf_recHits_h->size()<<endl;
      
      const HFRecHitCollection *hf_recHits = hf_recHits_h.failedToGet()? 0 : &*hf_recHits_h;
      //if (hf_recHits) {           // object is available 
        
	int NumRecHits = 0;
	int nHits = 0;
	fNumRecHits = 0;
	
	LRecHits=0;
	SRecHits=0;
	
	for (int i = 0; i < 1728; ++i) 
	  {
	    fEnergy[i] = -999.;
	    fTransverseEnergy[i] = -999.;
	    fEta[i] = -999.;
	    depth[i] = -999;
	    time[i] = -999.;
	    //cout<<depth[i]<<endl;
	    //fLongEnergyT[i]=-999.;
	    //fShortEnergyT[i]=-999.;
	  }
	
	for (int ii = 0; ii < 864; ++ii) 
	  {
	    fLongEnergyT[ii]=-999.;
	    fShortEnergyT[ii]=-999.;
	    
	  }

for (int iii = 0; iii < 10000; ++iii) 
	  {

	    fHBHERecHitEta[iii]=-999.;
	    fHBHERecHitEnergy[iii]=-999.;
	    fHBHERecHitTransverseEnergy[iii]=-999.;

	  }



for (int iiii = 0; iiii < 100000; ++iiii) 
	  {
  fECALRecHitEta[iiii]=-999.;
   fECALRecHitEnergy[iiii]=-999.;
   fECALRecHitTransverseEnergy[iiii]=-999.;
	  }

	


 for (int iiiii = 0; iiiii < 100000; ++iiiii) 
	  {
  fECALEERecHitEta[iiiii]=-999.;
   fECALEERecHitEnergy[iiiii]=-999.;
   fECALEERecHitTransverseEnergy[iiiii]=-999.;
	  }





	for (HFRecHitCollection::const_iterator hhit = hf_recHits->begin(); hhit != hf_recHits->end(); hhit++) {
	  HFRecHitEnergy = hhit->energy();
	  HcalDetId idHF = hhit->id(); 
	  GlobalPoint fPos = fGeo->getPosition(hhit->detid()); 
	  RecHitEta = fPos.eta();
	  TotalHFRecHitEnergy+=HFRecHitEnergy;
	  
	  HF_tree->Fill();
	  
	  ++NumRecHits;
	  fEnergy[nHits] = hhit->energy();
	  fEta[nHits] = fPos.eta();
	  depth[nHits] = idHF.depth();
	  time[nHits] = hhit->time();
	  fTransverseEnergy[nHits] = hhit->energy()/TMath::CosH(fPos.eta());
	  //cout<<"HFhit   "<<nHits<<"\t"<<idHF.depth()<<endl;
	  fHFieta[nHits] = idHF.ieta();
	  if(idHF.depth()==1)
	    {
	      ++LRecHits;
	      fLongEnergyT[LRecHits]=hhit->energy()/TMath::CosH(fPos.eta());
	    }
	  if(idHF.depth()==2)
	    {
	      ++SRecHits;
	      fShortEnergyT[SRecHits]=hhit->energy()/TMath::CosH(fPos.eta());
	    }
	  
	  ++nHits;
	} //hf rechit collection
	
	
	fNumRecHits = nHits;
	//fTree->Fill();
	
	// } //if hf rechits available





      //HBHE rechits
      edm::Handle<HBHERecHitCollection> hbhe;
      iEvent.getByLabel("hbhereco",hbhe);
      //nbOfHFBHERecHits = hbhe->size();
      // cout<<"hbhesize   "<<hbhe->size()<<endl;
      
      const HBHERecHitCollection *hbhe_recHits = hbhe.failedToGet()? 0 : &*hbhe;
      
      // if(hbhe_recHits)
      //{
	  int NumHBHERecHits = 0;
	  fNumHBHERecHits = 0;
	  
	  
	  for(HBHERecHitCollection::const_iterator hbheItr = hbhe_recHits->begin(); hbheItr != hbhe_recHits->end(); hbheItr++)
	    {
	      GlobalPoint fPos = fGeo->getPosition(hbheItr->detid()); 
	      HcalDetId idHBHE = hbheItr->id(); 

	      // fPos.eta();
	      //cout<<NumHBHERecHits<<"\t"<<hbheItr->energy()<<"\t"<<fPos.eta()<<endl;


	      fHBHERecHitEta[NumHBHERecHits]=fPos.eta();
	      fHBHERecHitEnergy[NumHBHERecHits]=hbheItr->energy();
	      fHBHERecHitTransverseEnergy[NumHBHERecHits]=hbheItr->energy()/TMath::CosH(fPos.eta());
	      fHBHEieta[NumHBHERecHits] = idHBHE.ieta();

	      ++NumHBHERecHits;

	      //cout<<"HBHEhit  "<<NumHBHERecHits<<"\t"<<idHBHE.ieta()<<endl;
	    }
	  
	  fNumHBHERecHits=NumHBHERecHits;
	  //	}




	  //ECAL rechits
	  /*
	  edm::Handle<EcalRecHitCollection> EBReducedRecHits;
	  iEvent.getByLabel("ecalRecHit","EcalRecHitsEB", EBReducedRecHits);
	  const EcalRecHitCollection *rechits = EBReducedRecHits.product();
	  */

	  edm::Handle<EcalRecHitCollection> EBRecHits;
	  iEvent.getByLabel("ecalRecHit","EcalRecHitsEB", EBRecHits);
	  const EcalRecHitCollection *rechits = EBRecHits.product();	  
	  
	 
	  int NumECALRecHits = 0;
	  fNumECALRecHits = 0;

	  for(EcalRecHitCollection::const_iterator ecalit=rechits->begin(); ecalit!=rechits->end(); ecalit++) {

	    GlobalPoint fPos = fGeo->getPosition(ecalit->detid()); 
	    DetId idECAL = ecalit->id(); 


	    fECALRecHitEta[NumECALRecHits]=fPos.eta();
	    fECALRecHitEnergy[NumECALRecHits]=ecalit->energy();
	    fECALRecHitTransverseEnergy[NumECALRecHits]=ecalit->energy()/TMath::CosH(fPos.eta());

	    ++NumECALRecHits;

	    //hbheItr->energy()/TMath::CosH(fPos.eta());
	    //cout<<"\t"<<fPos.eta()<<"\t"<<ecalit->energy()<<endl;
	    
	    //cout<<idECAL.ieta()<<endl;

	    //const GlobalPoint &position = caloGeom->getPosition(it->id());
	    //cout<<it->energy()/TMath::CosH(position.eta())<<endl;
	    
	  }
	  fNumECALRecHits=NumECALRecHits;
	  
	  
  
	  //ECAL EE rechits

	  edm::Handle<EcalRecHitCollection> EERecHits;
	  iEvent.getByLabel("ecalRecHit","EcalRecHitsEE", EERecHits);
	  const EcalRecHitCollection *rechitsEE = EERecHits.product();	 

	  // cout<<EERecHits->size()<<endl;
	  int NumECALEERecHits = 0;
	  fNumECALEERecHits = 0;

	  for(EcalRecHitCollection::const_iterator ecaleeit=rechitsEE->begin(); ecaleeit!=rechitsEE->end(); ecaleeit++) {
	    GlobalPoint fPos = fGeo->getPosition(ecaleeit->detid()); 
	    DetId idECALEE = ecaleeit->id(); 
	    //cout<<fPos.eta()<<"\t"<<ecaleeit->energy()/TMath::CosH(fPos.eta())<<endl;



	    fECALEERecHitEta[NumECALEERecHits]=fPos.eta();
	    fECALEERecHitEnergy[NumECALEERecHits]=ecaleeit->energy();
	    fECALEERecHitTransverseEnergy[NumECALEERecHits]=ecaleeit->energy()/TMath::CosH(fPos.eta());

	    ++NumECALEERecHits;




	  }
	  fNumECALEERecHits=NumECALEERecHits;

	   fTree->Fill();
      
      //----------------------
      //CaloTowers analysis  -
      //----------------------
      
      CaloTowerEnergy = 0.;
      CaloTowerEta = 0.;
      CaloTowerTransverseEnergy =0.;
      // calo towers
      Handle < CaloTowerCollection > calo_h;
      iEvent.getByLabel("towerMaker", calo_h); 
      

      const CaloTowerCollection *towers = calo_h.failedToGet()? 0 : &*calo_h;
      nbOfCaloTowers = calo_h->size();
      
      if (towers) {
	fNumCaloTowers = 0;
	int NumCaloTowers = 0;
	
	for (int i = 0; i < 10000; ++i) {
	  fCaloTowerEnergy[i] = -999.;
	  fCaloTowerEta[i] = -999;
	  fCaloTowerTransverseEnergy[i] = -999;
	  fieta[i] =-999;
	  fiphi[i]=-999; 
	  emfraction[i]=-999;
	  hadfraction[i]=-999;
	}
	for (CaloTowerCollection::const_iterator cal = towers->begin(); cal != towers->end(); cal++) {
	  
	  EnergyFlowPlot->Fill(cal->eta(), cal->et() );


	  fCaloTowerEnergy[NumCaloTowers] = cal->energy();
	  fCaloTowerTransverseEnergy[NumCaloTowers] = cal->et();
	  fCaloTowerEta[NumCaloTowers] = cal->eta();
	  fieta[NumCaloTowers] = cal->ieta();
	  fiphi[NumCaloTowers] = cal->iphi();

	  emfraction[NumCaloTowers]= cal->emEt();
	  hadfraction[NumCaloTowers]= cal->hadEt();

	  
	  
	  ++NumCaloTowers;
	  
	  
	  CaloTowerEnergy = cal->energy();
	  CaloTowerEta =  cal->eta();
	  CaloTowerTransverseEnergy = cal->et();
	  
	  ct1Tree->Fill();
	  
	}
	fNumCaloTowers = NumCaloTowers;
	ctTree->Fill();
      } else {
	cout << "CaloTowers are not avaliable or wrong label: towerMaker. Check the label" << endl;
      }
      
      
      perEvent->Fill();
      
      /////
      
    
      ///pf analysis
      if(pfana_)
	{
      
      fNumOfPFCandidates = 0;
      int NumOfPFCandidates = 0;

      for (int ii = 0; ii < 10000; ++ii) {
	  pfEnergy[ii] = -999.;
	  pfEta[ii] = -999.;
	  pfTransverseEnergy[ii] = -999.;
      }
      
      
      edm::Handle<reco::PFCandidateCollection> pfCandidates;
      iEvent.getByLabel(pfCandidateLabel_,pfCandidates);
      
      const reco::PFCandidateCollection *pfCandidateColl = &(*pfCandidates);
      
      for(unsigned icand=0;icand<pfCandidates->size(); icand++) 
	{
	  const reco::PFCandidate pfCandidate = pfCandidateColl->at(icand);
	  
	  pfEnergy[NumOfPFCandidates] = pfCandidate.energy();
	  pfEta[NumOfPFCandidates] = pfCandidate.eta(); 
	  pfTransverseEnergy[NumOfPFCandidates]=pfCandidate.et();

	  EnergyFlowPlotPF->Fill(pfCandidate.eta(), pfCandidate.et());
	  
	    
	  ++NumOfPFCandidates;
	  
	}
      fNumOfPFCandidates = NumOfPFCandidates;
      //	cout<<"fNumOfPFCandidates  "<<fNumOfPFCandidates<<"  size  "<<pfCandidates->size()<<endl;
      
      pfTree->Fill();
      
	}
      
}// end of analyze()


// ------------ method called once each job just before starting event loop  ------------
void 
EnergyFlowHIAnalyzer::beginJob()
{
  centrality_ = 0;
  NbOfAnalyzedEvents = 0;
  
  edm::Service<TFileService> fs;
  TFileDirectory HI = fs->mkdir( "HI" );
  
  //some general per event
  perEvent = new TTree("info_perEvent","info_perEvent");
  perEvent->Branch("NbOfAnalyzedEvents",&NbOfAnalyzedEvents,"NbOfAnalyzedEvents/I");
  perEvent->Branch("fNumRecHits",&fNumRecHits,"fNumRecHits/I");
  perEvent->Branch("fNumCaloTowers",&fNumCaloTowers,"fNumCaloTowers/I");
  perEvent->Branch("centralityBin",&centralityBin,"centralityBin/I");
  perEvent->Branch("fNumHBHERecHits", &fNumHBHERecHits, "fNumHBHERecHits/I");
  perEvent->Branch("nPixelTracks",&nPixelTracks,"nPixelTracks/I");

  
  
  //HF per rechit fill
  HF_tree = new TTree("hfTree_perRecHits","HF_perRecHits");
  HF_tree->Branch("HFRecHitEnergy",&HFRecHitEnergy,"HFRecHitEnergy/D");
  HF_tree->Branch("RecHitEta",&RecHitEta,"RecHitEta/D");
  

  //HF and HBHE rechit per event fill of the table
  fTree = new TTree("hfTree_perEvent", "hfTree_perEvent");
  fTree->Branch("NumRecHits", &fNumRecHits, "NumRecHits/I");
  fTree->Branch("Energy", fEnergy, "Energy[NumRecHits]/F");
  fTree->Branch("fTransverseEnergy", fTransverseEnergy, "TransverseEnergy[NumRecHits]/F");
  fTree->Branch("Eta", fEta, "Eta[NumRecHits]/F");
  fTree->Branch("HFieta", fHFieta, "fHFieta[NumRecHits]/I");



  fTree->Branch("depth", depth, "depth[NumRecHits]/I");
  //fTree->Branch("time", time, "time[NumRecHits]/F");
  fTree->Branch("fLongEnergyT", fLongEnergyT, "fLongEnergyT[864]/F");
  fTree->Branch("fShortEnergyT", fShortEnergyT, "fShortEnergyT[864]/F");
  fTree->Branch("fNumHBHERecHits", &fNumHBHERecHits, "fNumHBHERecHits/I");
  fTree->Branch("fHBHERecHitTransverseEnergy", fHBHERecHitTransverseEnergy, "fHBHERecHitTransverseEnergy[fNumHBHERecHits]/F");
  fTree->Branch("fHBHERecHitEnergy", fHBHERecHitEnergy, "fHBHERecHitEnergy[fNumHBHERecHits]/F");
  fTree->Branch("fHBHERecHitEta", fHBHERecHitEta, "fHBHERecHitEta[fNumHBHERecHits]/F");
  fTree->Branch("HBHEieta", fHBHEieta, "fHBHEieta[fNumHBHERecHits]/I");


  fTree->Branch("fNumECALRecHits", &fNumECALRecHits, "fNumECALRecHits/I");
  fTree->Branch("fECALRecHitEta", fECALRecHitEta, "fECALRecHitEta[fNumECALRecHits]/F");
  fTree->Branch("fECALRecHitEnergy", fECALRecHitEnergy, "fECALRecHitEnergy[fNumECALRecHits]/F");
  fTree->Branch("fECALRecHitTransverseEnergy", fECALRecHitTransverseEnergy, "fECALRecHitTransverseEnergy[fNumECALRecHits]/F");


  fTree->Branch("fNumECALEERecHits", &fNumECALEERecHits, "fNumECALEERecHits/I");
  fTree->Branch("fECALEERecHitEta", fECALEERecHitEta, "fECALEERecHitEta[fNumECALEERecHits]/F");
  fTree->Branch("fECALEERecHitEnergy", fECALEERecHitEnergy, "fECALEERecHitEnergy[fNumECALEERecHits]/F");
  fTree->Branch("fECALEERecHitTransverseEnergy", fECALEERecHitTransverseEnergy, "fECALEERecHitTransverseEnergy[fNumECALEERecHits]/F");

  
  
  /*

fHBHERecHitEta[iii]=-999.;
	    fHBHERecHitEnergy[iii]=-999.;
	    fHBHERecHitTransverseEnergy[iii]=-999.;
   */


  // fTree->Branch("Energy", fEnergy, "Energy[1728]/F");
  // fTree->Branch("Eta", fEta, "Eta[1728]/F");
  
  
  //HF CaloTowers per event fill of the table
  ctTree = new TTree("ctTree_perEvent", "ctTree_perEvent");
  ctTree->Branch("NumCaloTowers", &fNumCaloTowers, "NumCaloTowers/I");
  ctTree->Branch("CaloTowerTransverseEnergy", fCaloTowerTransverseEnergy, "fCaloTowerTransverseEnergy[NumCaloTowers]/F");
  ctTree->Branch("CaloTowerEnergy", fCaloTowerEnergy, "CaloTowerEnergy[NumCaloTowers]/F");
  ctTree->Branch("CaloTowerEta", fCaloTowerEta, "CaloTowerEta[NumCaloTowers]/F");
  ctTree->Branch("CaloToweriEta", fieta, "fieta[NumCaloTowers]/I");
  ctTree->Branch("CaloToweriPhi", fiphi, "fiphi[NumCaloTowers]/I");

  ctTree->Branch("emfraction", emfraction, "emfraction[NumCaloTowers]/F");
  ctTree->Branch("hadfraction", hadfraction, "hadfraction[NumCaloTowers]/F");


  
  //HF CaloTowers per CaloTower fill
  ct1Tree = new TTree("ctTree_perCaloTower", "ctTree_perCaloTower");
  ct1Tree->Branch("CaloTowerEnergy", &CaloTowerEnergy, "CaloTowerEnergy/F");
  ct1Tree->Branch("CaloTowerEta", &CaloTowerEta, "CaloTowerEta/F");
  ct1Tree->Branch("CaloTowerTransverseEnergy", &CaloTowerTransverseEnergy, "CaloTowerTransverseEnergy/F");

  
  //pf candidates tree
  pfTree = new TTree("pfCandidatesTree","pfCandidatesTree");
  pfTree->Branch("fNumOfPFCandidates", &fNumOfPFCandidates, "fNumOfPFCandidates/I");
  pfTree->Branch("pfEnergy", pfEnergy, "pfEnergy[fNumOfPFCandidates]/F");
  pfTree->Branch("pfEta", pfEta, "pf[fNumOfPFCandidates]/F");
  pfTree->Branch("pfTransverseEnergy", pfTransverseEnergy, "pfTransverseEnergy[fNumOfPFCandidates]/F");
  
}

// ------------ method called once each job just after ending the event loop  ------------
void 
EnergyFlowHIAnalyzer::endJob() {
}

//define this as a plug-in
DEFINE_FWK_MODULE(EnergyFlowHIAnalyzer);





