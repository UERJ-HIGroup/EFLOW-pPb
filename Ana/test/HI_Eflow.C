
TH1D Normalize(TH1D *histo)
{
  Int_t entries = histo->GetEntries();
  Double_t integrale = histo->Integral();
  return histo->Scale(1./integrale);
} 

//
void Uniform()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetTitleFillColor(10);
  gStyle->SetCanvasColor(10);
  gStyle->SetPadColor(10);
  gStyle->SetFrameFillColor(10);
  gStyle->SetFillColor(10);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetStatColor(10);
  gStyle->SetPalette(1);
  gStyle->SetStatBorderSize(1);
}


TH1D*Normalize_byEvents_byBinWidth(TH1D *h1, TH1D *h2, Int_t NofEvnt)
{
  Double_t normalized_content;
  const size_t N2 =h1->GetNbinsX();
  for (size_t i=1;i<=N2;i++) // we start at i=1 since i=0 is for underflows
    {
      normalized_content = (h1->GetBinContent(i)/(NofEvnt*2*h1->GetBinWidth(i)));
      h2->AddBinContent(i,normalized_content);
      //h2->SetBinError(i,(h2->GetBinError(i)));
     
    }
    return h2;
} 



TH1D*Normalize_byEvents_byBinWidth_bySide(TH1D *h1, TH1D *h2, Int_t NofEvnt)
{
  Double_t normalized_content;
  const size_t N2 =h1->GetNbinsX();
  for (size_t i=1;i<=N2;i++) // we start at i=1 since i=0 is for underflows
    {
      normalized_content = (h1->GetBinContent(i)/(NofEvnt*h1->GetBinWidth(i)));
      h2->AddBinContent(i,normalized_content);
      //      h2->SetBinError(i,(h2->GetBinError(i)));
     
    }
    return h2;
} 



TChain *CreateChain(const char* treeName)
{
  TChain* chain = new TChain(treeName);

chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_10_1_xy3.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_11_1_gQr.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_12_1_vht.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_13_1_Xlf.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_14_1_dOx.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_15_1_Tu8.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_16_1_T8Y.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_17_1_pAR.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_18_1_uhc.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_19_1_yYw.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_1_1_D5R.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_20_1_q55.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_21_1_Mrg.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_22_1_YLk.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_23_1_iEv.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_24_1_Ztw.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_25_1_5ft.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_26_1_XfU.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_27_1_JG8.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_28_1_fZv.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_29_1_9NC.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_2_1_goe.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_30_1_m5m.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_31_1_5Io.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_32_1_gFR.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_3_1_MSV.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_4_1_PBF.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_5_1_8W9.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_6_1_UGv.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_7_1_pJJ.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_8_1_Fzi.root");
chain->Add("files_data_core_centHFHitsUpdated_HLT_HIMinBiasHfOrBSC_Core_fullEvSel_hiPixelClusterVertex_VtxCutAbsZlessthan19_9_1_hOn.root");

  return chain;
} 



void HI_Eflow(bool save=false)
{

  TChain *chain1 = CreateChain("Mytreemaker/ctTree_perEvent");

  TChain *chain2 = CreateChain("Mytreemaker/info_perEvent");


  Uniform();  
  
  float fCaloTowerEnergy[10000];
  float fCaloTowerEta[10000];
  float fCaloTowerTransverseEnergy[10000];
  Int_t fNumCaloTowers;

  Int_t NbOfAnalyzedEvents;
  Int_t centralityBin;
  int fNumCaloTowers;
  int fNumRecHits ;


  int entries;
  int NofEvnt_0_3=0;
  int NofEvnt_3_7=0;
  int NofEvnt_7_11=0;
  int NofEvnt_11_15=0;
  int NofEvnt_15_19=0;
  int NofEvnt_19_23=0;
  int NofEvnt_23_27=0;
  int NofEvnt_27_31=0;
  int NofEvnt_31_35=0;
  int NofEvnt_35_39=0;


  
  chain1->SetBranchAddress("CaloTowerEnergy",&fCaloTowerEnergy);
  chain1->SetBranchAddress("CaloTowerEta",&fCaloTowerEta);
  chain1->SetBranchAddress("NumCaloTowers",&fNumCaloTowers);
  chain1->SetBranchAddress("CaloTowerTransverseEnergy",&fCaloTowerTransverseEnergy); 

  chain2->SetBranchAddress("NbOfAnalyzedEvents",&NbOfAnalyzedEvents);
  chain2->SetBranchAddress("fNumRecHits",&fNumRecHits);
  chain2->SetBranchAddress("fNumCaloTowers",&fNumCaloTowers);
  chain2->SetBranchAddress("centralityBin",&centralityBin);


 
  double xBins[14] = {2.866,2.976,3.152,3.327,3.503,3.677,3.853,4.027,4.204,4.377,4.552,4.730,4.903,5.205};
  const int nBins = 13;

  //Non normalized histograms

 
  
  // Histograms for total centrality bin


  TH1D *HF_Et=new TH1D("HF_Et","HF_Et",nBins, xBins);
  HF_Et->Sumw2(); 
  TH1D *HF_E=new TH1D("HF_E","HF_Energy", nBins, xBins);
  HF_E->Sumw2();
  TH1D *HFplus_E=new TH1D("HFplus_E","HFplus", nBins, xBins);
  HFplus_E->Sumw2();
  TH1D *HFminus_E=new TH1D("HFminus_E","HF_minus", nBins, xBins);
  HFminus_E->Sumw2();


  TH1D *SUB_HF_E=new TH1D("SUB_HF_E","", nBins, xBins);
  TH1D *SUM_HF_E=new TH1D("SUM_HF_E","", nBins, xBins);
  TH1D *Ratio_HF_E=new TH1D("Ratio_HF_E","Ratio_HF_E", nBins, xBins);


  // Histograms for ten ranges of centrality bin


  TH1D *HF_Et_0_3=new TH1D("HF_ET_Bin_0-3","HF_TransverseEnergy",nBins, xBins);
  HF_Et_0_3->Sumw2(); 
  TH1D *HF_E_0_3=new TH1D("HF_E_Bin_0-3","HF_Energy", nBins, xBins);
  HF_E_0_3->Sumw2();

  TH1D *HF_Et_3_7=new TH1D("HF_ET_Bin_3-7","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_3_7->Sumw2();
  TH1D *HF_E_3_7=new TH1D("HF_E_Bin_3-7","HF_Energy", nBins, xBins);
  HF_E_3_7->Sumw2();


  TH1D *HF_Et_7_11=new TH1D("HF_ET_Bin_7-11","HF_TransverseEnergy",nBins, xBins);
  HF_Et_7_11->Sumw2();
  TH1D *HF_E_7_11=new TH1D("HF_E_Bin_7-11","HF_Energy", nBins, xBins);
  HF_E_7_11->Sumw2();
  
  TH1D *HF_Et_11_15=new TH1D("HF_ET_Bin_11-15","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_11_15->Sumw2();
  TH1D *HF_E_11_15=new TH1D("HF_E_Bin_11-15","HF_Energy", nBins, xBins);
  HF_E_11_15->Sumw2();
 
  TH1D *HF_Et_15_19=new TH1D("HF_ET_Bin_15-19","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_15_19->Sumw2();
  TH1D *HF_E_15_19=new TH1D("HF_E_Bin_15-19","HF_Energy", nBins, xBins);
  HF_E_15_19->Sumw2();

  TH1D *HF_Et_19_23=new TH1D("HF_ET_Bin_19-23","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_19_23->Sumw2();
  TH1D *HF_E_19_23=new TH1D("HF_E_Bin_19-23","HF_Energy", nBins, xBins);
  HF_E_19_23->Sumw2();
  
  TH1D *HF_Et_23_27=new TH1D("HF_ET_Bin_23-27","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_23_27->Sumw2();
  TH1D *HF_E_23_27=new TH1D("HF_E_Bin_23-27","HF_Energy", nBins, xBins);
  HF_E_23_27->Sumw2();
  
  TH1D *HF_Et_27_31=new TH1D("HF_ET_Bin_27-31","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_27_31->Sumw2();
  TH1D *HF_E_27_31=new TH1D("HF_E_Bin_27-31","HF_Energy", nBins, xBins);
  HF_E_27_31->Sumw2();

  TH1D *HF_Et_31_35=new TH1D("HF_ET_Bin_31-35","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_31_35->Sumw2();
  TH1D *HF_E_31_35=new TH1D("HF_E_Bin_31-35","HF_Energy", nBins, xBins);
  HF_E_31_35->Sumw2();
 
  TH1D *HF_Et_35_39=new TH1D("HF_ET_Bin_35-39","HF_TransverseEnergy",nBins, xBins); 
  HF_Et_35_39->Sumw2();
  TH1D *HF_E_35_39=new TH1D("HF_E_Bin_35-39","HF_Energy", nBins, xBins);
  HF_E_35_39->Sumw2();


  //Normalized histograms

  TH1D *HF_E_N=new TH1D("HF_E_N","HF_E_N", nBins, xBins);
  TH1D *HF_Et_N=new TH1D("HF_Et_N","HF_Et_N", nBins, xBins);
  TH1D *HFplus_E_N=new TH1D("HFplus_E_N","HFplus_E_N", nBins, xBins);
  TH1D *HFminus_E_N=new TH1D("HFminus_E_N","HFminus_E_N", nBins, xBins);


  TH1D *HF_E_0_3N=new TH1D("HF_E3N","HF_Energy", nBins, xBins);
  TH1D *HF_E_3_7N=new TH1D("HF_E7N","HF_Energy", nBins, xBins);
  TH1D *HF_E_7_11N=new TH1D("HF_E11N","HF_Energy", nBins, xBins);
  TH1D *HF_E_11_15N=new TH1D("HF_E15N","HF_Energy", nBins, xBins);
  TH1D *HF_E_15_19N=new TH1D("HF_E19N","HF_Energy", nBins, xBins);
  TH1D *HF_E_19_23N=new TH1D("HF_E23N","HF_Energy", nBins, xBins);
  TH1D *HF_E_23_27N=new TH1D("HF_E27N","HF_Energy", nBins, xBins);
  TH1D *HF_E_27_31N=new TH1D("HF_E31N","HF_Energy", nBins, xBins);
  TH1D *HF_E_31_35N=new TH1D("HF_E35N","HF_Energy", nBins, xBins);
  TH1D *HF_E_35_39N=new TH1D("HF_E39N","HF_Energy", nBins, xBins);


  TH1D *HF_Et_0_3N=new TH1D("HF_Et_3N","HF_Et", nBins, xBins);
  TH1D *HF_Et_3_7N=new TH1D("HF_Et_7N","HF_Et", nBins, xBins);
  TH1D *HF_Et_7_11N=new TH1D("HF_Et_11N","HF_Et", nBins, xBins);
  TH1D *HF_Et_11_15N=new TH1D("HF_Et_15N","HF_Et", nBins, xBins);
  TH1D *HF_Et_15_19N=new TH1D("HF_Et_19N","HF_Et", nBins, xBins);
  TH1D *HF_Et_19_23N=new TH1D("HF_Et_23N","HF_Et", nBins, xBins);
  TH1D *HF_Et_23_27N=new TH1D("HF_Et_27N","HF_Et", nBins, xBins);
  TH1D *HF_Et_27_31N=new TH1D("HF_Et_31N","HF_Et", nBins, xBins);
  TH1D *HF_Et_31_35N=new TH1D("HF_Et_35N","HF_Et", nBins, xBins);
  TH1D *HF_Et_35_39N=new TH1D("HF_Et_39N","HF_Et", nBins, xBins);



  Int_t entries_chain1 =(Int_t)chain1->GetEntries(); 

  cout<<" Entries of chain1:  " << entries_chain1<<endl; 
  cout<<" Entries of chain2:  " << chain2->GetEntries()<<endl << endl;

  for (Int_t nchain=0;nchain<chain1->GetEntries();nchain++)
    {
      chain1->GetEntry(nchain);
      chain2->GetEntry(nchain);
 
      // Energy distribution for all centrality bin

      for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	{
	  if (fCaloTowerEnergy[nCalo] > 4.0)
	    { 	    
	      HF_Et->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
	      HF_E->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);

	      if (fCaloTowerEta[nCalo] > 0.) 
		{ 
		  HFplus_E->Fill(fCaloTowerEta[nCalo],fCaloTowerEnergy[nCalo]);
		}
    
	      if (fCaloTowerEta[nCalo] < 0.) 
		{ 
		  HFminus_E->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}    
	    }                            
	}                            //end of  CaloTower


  
      if(centralityBin<=3)
	{ 
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_0_3->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_0_3->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}  
	    }

	  NofEvnt_0_3++;
	}                        //end of centrality          

 

      if(centralityBin>3 && centralityBin<=7)
        {       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_3_7->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_3_7->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);	  	  
		}  
	    }                  //end of CaloTower
	  NofEvnt_3_7++;
	}                      //end of centrality



      if(centralityBin>7 && centralityBin<=11)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{ 	    
		  HF_Et_7_11->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
	          HF_E_7_11->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);	  	  
		}                             
	    }                //end of CaloTower 
	  NofEvnt_7_11++;
	}                   //end of centrality



      if(centralityBin>11 && centralityBin<=15)
	{       	 	 
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_11_15->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_11_15->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}
	    }                             //end of CaloTower
	  NofEvnt_11_15++;
	}                         //end of centrality



      if(centralityBin>15 && centralityBin<=19)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_15_19->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_15_19->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}
	    }                             //end of CaloTower
	  NofEvnt_15_19++;
	}                         //end of centrality



      if(centralityBin>19 && centralityBin<=23)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
 	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_19_23->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_19_23->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);	  	  
		}
	    }                             //end of CaloTower
	  NofEvnt_19_23++;
	}                         //end of centrality



      if(centralityBin>23 && centralityBin<=27)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_23_27->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_23_27->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);	  	  
		}
	    }                             //end of CaloTower
	  NofEvnt_23_27++;
	}                         //end of centrality



      if(centralityBin>27 && centralityBin<=31)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_27_31->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_27_31->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}
	    }                             //end of CaloTower
	  NofEvnt_27_31++;
	}                         //end of centrality



      if(centralityBin>31 && centralityBin<=35)
	{       
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_31_35->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_31_35->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}
	    }                             //end of CaloTower
	  NofEvnt_31_35++;
	}                         //end of centrality



      if(centralityBin>35)
	{
	  NofEvnt_35_39 = NofEvnt_35_39+1;
	  for (Int_t nCalo=0; nCalo<fNumCaloTowers; nCalo++)
	    {
	      if (fCaloTowerEnergy[nCalo] > 4.0)
		{
		  HF_Et_35_39->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerTransverseEnergy[nCalo]);
		  HF_E_35_39->Fill(TMath::Abs(fCaloTowerEta[nCalo]),fCaloTowerEnergy[nCalo]);
		}
	    }                             //end of CaloTower
	}                         //end of centrality

  

  
    }                                     //end of events


  Normalize_byEvents_byBinWidth(HF_E, HF_E_N, entries_chain1);
  Normalize_byEvents_byBinWidth(HF_Et, HF_Et_N, entries_chain1);
  
  Normalize_byEvents_byBinWidth_bySide(HFplus_E, HFplus_E_N, entries_chain1);
  Normalize_byEvents_byBinWidth_bySide(HFminus_E, HFminus_E_N, entries_chain1);

  SUB_HF_E->Add(HFminus_E_N,HFplus_E_N,1,-1);
  SUM_HF_E->Add(HFminus_E_N,HFplus_E_N,1,1);
  Ratio_HF_E->Divide(SUB_HF_E,SUM_HF_E,1,1);


 
 
  cout << "NofEvnt_0_3  "<<  NofEvnt_0_3 << endl;
  cout << "NofEvnt_3_7  "<<  NofEvnt_3_7 << endl;
  cout << "NofEvnt_7_11  "<<  NofEvnt_7_11 << endl;
  cout << "NofEvnt_11_15  "<<  NofEvnt_11_15 << endl;
  cout << "NofEvnt_15_19  "<<  NofEvnt_15_19 << endl;
  cout << "NofEvnt_19_23  "<<  NofEvnt_19_23 << endl;
  cout << "NofEvnt_23_27  "<<  NofEvnt_23_27 << endl;
  cout << "NofEvnt_27_31  "<<  NofEvnt_27_31 << endl;
  cout << "NofEvnt_31_35  "<<  NofEvnt_31_35 << endl;
  cout << "NofEvnt_35_39  "<<  NofEvnt_35_39 << endl;
     
 

		  
  Normalize_byEvents_byBinWidth(HF_E_0_3, HF_E_0_3N, NofEvnt_0_3);
  /*
      TCanvas *c1=new TCanvas("c1","c1");
      HF_E_0_3N->GetXaxis()->SetTitle("|#eta|");
      HF_E_0_3N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_0_3N->SetLineWidth(2);
      HF_E_0_3N->Draw();
      c1->Update();
		  */

  Normalize_byEvents_byBinWidth(HF_E_3_7, HF_E_3_7N, NofEvnt_3_7);
     /*
      TCanvas *c2=new TCanvas("c2","c2");
      HF_E_3_7N->GetXaxis()->SetTitle("|#eta|");
      HF_E_3_7N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_3_7N->SetLineWidth(2);
      HF_E_3_7N->Draw();
      c2->Update();
     */

  Normalize_byEvents_byBinWidth(HF_E_7_11, HF_E_7_11N, NofEvnt_7_11);
     /*
      TCanvas *c3=new TCanvas("c3","c3");
      HF_E_7_11N->GetXaxis()->SetTitle("|#eta|");
      HF_E_7_11N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_7_11N->SetLineWidth(2);
      HF_E_7_11N->Draw();
      c3->Update();
     */

  Normalize_byEvents_byBinWidth(HF_E_11_15, HF_E_11_15N, NofEvnt_11_15);
     /*
      TCanvas *c4=new TCanvas("c4","c4");
      HF_E_11_15N->GetXaxis()->SetTitle("|#eta|");
      HF_E_11_15N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_11_15N->SetLineWidth(2);
      HF_E_11_15N->Draw();
      c4->Update();
     */

  Normalize_byEvents_byBinWidth(HF_E_15_19, HF_E_15_19N, NofEvnt_15_19);
     /*
      TCanvas *c5=new TCanvas("c5","c5");
      HF_E_15_19N->GetXaxis()->SetTitle("|#eta|");
      HF_E_15_19N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_15_19N->SetLineWidth(2);
      HF_E_15_19N->Draw();
      c5->Update();
     */


  Normalize_byEvents_byBinWidth(HF_E_19_23, HF_E_19_23N, NofEvnt_19_23);
     /*
      TCanvas *c6=new TCanvas("c6","c6");
      HF_E_19_23N->GetXaxis()->SetTitle("|#eta|");
      HF_E_19_23N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_19_23N->SetLineWidth(2);
      HF_E_19_23N->Draw();
      c6->Update();
     */


  Normalize_byEvents_byBinWidth(HF_E_23_27, HF_E_23_27N, NofEvnt_23_27);
     /*
      TCanvas *c7=new TCanvas("c7","c7");
      HF_E_23_27N->GetXaxis()->SetTitle("|#eta|");
      HF_E_23_27N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_23_27N->SetLineWidth(2);
      HF_E_23_27N->Draw();
      c7->Update();
     */


  Normalize_byEvents_byBinWidth(HF_E_27_31, HF_E_27_31N, NofEvnt_27_31);
     /*
      TCanvas *c8=new TCanvas("c8","c8");
      HF_E_27_31N->GetXaxis()->SetTitle("|#eta|");
      HF_E_27_31N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_27_31N->SetLineWidth(2);
      HF_E_27_31N->Draw();
      c7->Update();
     */

  Normalize_byEvents_byBinWidth(HF_E_31_35, HF_E_31_35N, NofEvnt_31_35);
     /*
      TCanvas *c9=new TCanvas("c9","c9");
      HF_E_31_35N->GetXaxis()->SetTitle("|#eta|");
      HF_E_31_35N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_31_35N->SetLineWidth(2);
      HF_E_31_35N->Draw();
      c9->Update();
     */

  Normalize_byEvents_byBinWidth(HF_E_35_39, HF_E_35_39N, NofEvnt_35_39);
     /*
      TCanvas *c10=new TCanvas("c10","c10");
      HF_E_35_39N->GetXaxis()->SetTitle("|#eta|");
      HF_E_35_39N->GetYaxis()->SetTitle("1/N_{event} #times dE_{T}/d#eta");
      HF_E_35_39N->SetLineWidth(2);
      HF_E_35_39N->Draw();
      c10->Update();
     */

 

  /*    
	   TCanvas *c00=new TCanvas("c00","c00");
	   HF_Et_N->SetLineWidth(2);
	   HF_Et_N->SetMarkerStyle(3);
	   HF_Et_N->GetXaxis()->SetTitle("|#eta|");
	   HF_Et_N->GetYaxis()->SetTitle("1/N.dE_t/d|#eta|"); 
	   HF_Et_N->Draw();
	   c00->Update();

	   
	   TCanvas *c01=new TCanvas("c01","c01");
	   HF_E_N->SetLineWidth(2);
	   HF_E_N->SetMarkerStyle(3);
	   HF_E_N->GetXaxis()->SetTitle("|#eta|");
	   HF_E_N->GetYaxis()->SetTitle("Energy"); 
	   HF_E_N->Draw();
	   c01->Update();

    
	   TCanvas *c02=new TCanvas("c02","c02");
	   HFplus_E_N->SetLineWidth(2);
	   HFplus_E_N->SetMarkerStyle(3);
	   HFplus_E_N->GetXaxis()->SetTitle("|#eta|");
	   HFplus_E_N->GetYaxis()->SetTitle("Energy"); 
	   HFplus_E_N->Draw();
	   c02->Update();

	   
	   TCanvas *c03=new TCanvas("c03","c03");
	   HFminus_E_N->SetLineWidth(2);
	   HFminus_E_N->SetMarkerStyle(3);
	   HFminus_E_N->GetXaxis()->SetTitle("|#eta|");
	   HFminus_E_N->GetYaxis()->SetTitle("Energy"); 
	   HFminus_E_N->Draw();
	   c03->Update();


	   TCanvas *c04=new TCanvas("c04","c04");
	   Ratio_HF_E->SetLineWidth(2);
	   Ratio_HF_E->SetMarkerStyle(3);
	   Ratio_HF_E->GetXaxis()->SetTitle("|#eta|");
	   Ratio_HF_E->GetYaxis()->SetTitle("Energy"); 
	   Ratio_HF_E->Draw();
	   c04->Update();

  */

     
  // For MC dataset             
  // TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_MC.root"),"recreate");

  // For Data
  //TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_Data1.root"),"recreate");
  // TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_Data2.root"),"recreate");
  // TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_Data3.root"),"recreate");
  // TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_Data4.root"),"recreate");
   TFile *file =new TFile(Form("/storage1/prado/HeavyIonAna/HF_Data5.root"),"recreate");



	   HF_Et_N->Write();
	   HF_E_N->Write();
           Ratio_HF_E->Write();	   

	  
	   HF_Et_0_3N->Write();
	   HF_E_0_3N->Write();
	   
	   HF_Et_3_7N->Write();
	   HF_E_3_7N->Write();

	   HF_Et_7_11N->Write();
	   HF_E_7_11N->Write();

	   HF_Et_11_15N->Write();
	   HF_E_11_15N->Write();

	   HF_Et_15_19N->Write();
	   HF_E_15_19N->Write();

	   HF_Et_19_23N->Write();
	   HF_E_19_23N->Write();

	   HF_Et_23_27N->Write();
	   HF_E_23_27N->Write();

	   HF_Et_27_31N->Write();
	   HF_E_27_31N->Write();

	   HF_Et_31_35N->Write();
	   HF_E_31_35N->Write();

	   HF_Et_35_39N->Write();
	   HF_E_35_39N->Write();
	   
	   file->Close();   
      
     
}// end of method
