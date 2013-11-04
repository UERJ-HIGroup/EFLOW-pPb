

TH1D Normalize(TH1D *histo)
{
  Int_t entries = histo->GetEntries();
  Double_t integrale = histo->Integral();
  ////cout<<integrale<<endl;
  return histo->Scale(1./integrale);
} 


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

void Eflow_plots()
{	          

  Uniform();
//========
double xBins[14] = {2.866,2.976,3.152,3.327,3.503,3.677,3.853,4.027,4.204,4.377,4.552,4.730,4.903,5.205};
const int nBins = 13;
TH1D *Ratio_HF_E_17Over19=new TH1D("Ratio_HF_E_17Over19","Ratio_HF_E_17Over19", nBins, xBins);
TH1D *Ratio_HF_E_21Over19=new TH1D("Ratio_HF_E_21Over19","Ratio_HF_E_21Over19", nBins, xBins);
TH1D *Ratio_HF_Et_17Over19=new TH1D("Ratio_HF_Et_17Over19","Ratio_HF_Et_17Over19", nBins, xBins);
TH1D *Ratio_HF_Et_21Over19=new TH1D("Ratio_HF_Et_21Over19","Ratio_HF_Et_21Over19", nBins, xBins);
TH1D *MinBiasFullEvents_V19OverMimBias_V19=new TH1D("MinBiasFullEvents_V19OverMimBias_V19","MinBiasFullEvents_V19OverMimBias_V19", nBins, xBins);
//cout<<MinBiasFullEvents_V19OverMimBias_V19<<endl;

//
 TFile *file1 =new TFile("HF_Data1.root","READ");
 TH1D *h1=(TH1D *)file1->FindObjectAny("HF_E_N");
 TH1D *h4=(TH1D *)file1->FindObjectAny("HF_Et_N");


 TFile *file2 =new TFile("HF_Data2.root","READ");
 TH1D *h2=(TH1D *)file2->FindObjectAny("HF_E_N");
 TH1D *h5=(TH1D *)file2->FindObjectAny("HF_Et_N");

 TFile *file3 =new TFile("HF_Data3.root","READ");
 TH1D *h3=(TH1D *)file3->FindObjectAny("HF_E_N");
 TH1D *h6=(TH1D *)file3->FindObjectAny("HF_Et_N");
//========
// TFile *file4 =new TFile("HF_Data4.root","READ");
// TH1D *h7=(TH1D *)file4->FindObjectAny("HF_E_N");
// TH1D *h9=(TH1D *)file4->FindObjectAny("HF_Et_N");
 TFile *file4 =new TFile("HF_Data6.root","READ");
 TH1D *h7=(TH1D *)file4->FindObjectAny("HF_E_N");
 TH1D *h9=(TH1D *)file4->FindObjectAny("HF_Et_N");
//========
 TFile *file5 =new TFile("HF_Data5.root","READ");
 TH1D *h8=(TH1D *)file5->FindObjectAny("HF_E_N");
 TH1D *h10=(TH1D *)file5->FindObjectAny("HF_Et_N");
//========
 TFile *file6 =new TFile("HF_MC.root","READ");
 TH1D *h11=(TH1D *)file6->FindObjectAny("HF_E_N");
 TH1D *h12=(TH1D *)file6->FindObjectAny("HF_Et_N");
//========
TCanvas *c1 = new TCanvas("c1", "c1");
 h1->SetLineWidth(3);
 h1->SetLineColor(2);
 h1->GetXaxis()->SetTitle("|#eta|");
 h1->GetYaxis()->SetTitle("E"); 
 h1->Draw();
 h2->SetLineWidth(3);
 h2->SetLineStyle(9);
 h2->Draw("same");
 h3->SetLineWidth(3);
 h3->SetLineStyle(7);
 h3->SetLineColor(kBlue);
 h3->Draw("same");

 TLegend *l1  = new TLegend(0.45,0.3,0.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
// l1->AddEntry(h1,"Data_PH_HIMinBiasHfOrBSC_vtx19","l"); 
 l1->AddEntry(h1,"Data_HLT_HIMinBiasHforBSC_Core_vtx19","l"); 
 l1->AddEntry(h2,"Data_HLT_HIMinBiasHforBSC_Core_vtx17" ,"l"); 
 l1->AddEntry(h3,"Data_HLT_HIMinBiasHforBSC_Core_vtx21" ,"l"); 
 l1->Draw(); 
 c1->Update();
//==========
           Ratio_HF_E_17Over19->Divide(h2,h1,1,1);
           Ratio_HF_E_21Over19->Divide(h3,h1,1,1);
//
           TCanvas *c11=new TCanvas("c11","Ratio Of Data_HLT_HIMinBiasHforBSC_Core_Vtx...Over19");
           //c1-1->SetLogy();
	   Ratio_HF_E_17Over19->SetLineWidth(2);
	   Ratio_HF_E_17Over19->SetMarkerStyle(3);
           Ratio_HF_E_17Over19->SetLineColor(2);
	   Ratio_HF_E_17Over19->GetXaxis()->SetTitle("|#eta|");
	   Ratio_HF_E_17Over19->GetYaxis()->SetTitle("RatioOfE"); 
	   Ratio_HF_E_17Over19->GetYaxis()->SetRangeUser(0.995,1.005);
	   Ratio_HF_E_17Over19->Draw();

//
	   Ratio_HF_E_21Over19->SetLineWidth(3);
	   Ratio_HF_E_21Over19->SetLineColor(kBlue);
	   Ratio_HF_E_21Over19->Draw("same");

 TLegend *l1  = new TLegend(0.35,0.3,.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(Ratio_HF_E_17Over19,"Vertex17OverVertex19","l"); 
 l1->AddEntry(Ratio_HF_E_21Over19,"Vertex21OverVertex19" ,"l"); 
 l1->Draw(); 
 c11->Update();


//========

TCanvas *c2 = new TCanvas("c2", "E_transverse");
// gStyle->Clear();
 h4->SetLineWidth(4);
 h4->SetLineColor(2);
 h4->GetXaxis()->SetTitle("|#eta|");
 h4->GetYaxis()->SetTitle("E_t"); 
 h4->Draw();
 h5->SetLineWidth(3);
 h5->SetLineStyle(9);
 h5->Draw("same");
 h6->SetLineWidth(3);
 h6->SetLineStyle(7);
 h6->SetLineColor(kBlue);
 h6->Draw("same");

 TLegend *l2  = new TLegend(0.15,0.7,0.55,0.89); 
 l2->AddEntry(h4,"Data_HLT_HIMinBiasHforBSC_Core_vtx19","l"); 
 l2->AddEntry(h5,"Data_HLT_HIMinBiasHforBSC_Core_vtx17" ,"l"); 
 l2->AddEntry(h6,"Data_HLT_HIMinBiasHforBSC_Core_vtx21" ,"l"); 
 l2->Draw(); 
//
 c2->Update();
//
//==========
           Ratio_HF_Et_17Over19->Divide(h5,h4,1,1);
           Ratio_HF_Et_21Over19->Divide(h6,h4,1,1);
//
           TCanvas *c21=new TCanvas("c21","Et_Ratio Of Data_HLT_HIMinBiasHforBSC_Core_Vtx...Over19");
           //c1-1->SetLogy();
	   Ratio_HF_Et_17Over19->SetLineWidth(2);
	   Ratio_HF_Et_17Over19->SetMarkerStyle(3);
           Ratio_HF_Et_17Over19->SetLineColor(2);
	   Ratio_HF_Et_17Over19->GetXaxis()->SetTitle("|#eta|");
	   Ratio_HF_Et_17Over19->GetYaxis()->SetTitle("RatioOfEt"); 
	   Ratio_HF_Et_17Over19->GetYaxis()->SetRangeUser(0.995,1.005);
	   Ratio_HF_Et_17Over19->Draw();

//
	   Ratio_HF_Et_21Over19->SetLineWidth(3);
	   Ratio_HF_Et_21Over19->SetLineColor(kBlue);
	   Ratio_HF_Et_21Over19->Draw("same");

 TLegend *l1  = new TLegend(0.35,0.3,.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(Ratio_HF_Et_17Over19,"Et_Vertex_17OverVertex19","l"); 
 l1->AddEntry(Ratio_HF_Et_21Over19,"Et_Vertex21OverVertex19" ,"l"); 
 l1->Draw(); 
 c11->Update();


//========

TCanvas *c3 = new TCanvas("c3", "Data and MC");
//====
// gStyle->Clear();
 h1->SetLineWidth(3);
 h1->SetLineColor(2);
 h1->Draw();
 h8->SetLineWidth(3);
 h8->SetLineStyle(9);
 h8->Draw("same");
 h8->SetLineWidth(2);
 h11->SetLineWidth(2);
 h11->SetLineStyle(1);
 h11->SetLineColor(kBlue);
 h11->Draw("same");

//====
 TLegend *l1  = new TLegend(0.45,0.3,0.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(h1,"Data_HLT_HIMinBiasHforBSC_Core_vtx19","l"); 
 l1->AddEntry(h8,"Data_HLT_Update_HIMinBiasHforBSC_Core_vtx19" ,"l"); 
 l1->AddEntry(h11,"MC-AMPT_BOFF_PH_HIPixel-vtx19" ,"l"); 

 l1->Draw(); 
 c3->Update();

TCanvas *c4 = new TCanvas("c4", "c4");
// gStyle->Clear();
 h4->SetLineWidth(3);
 h4->SetLineColor(2);
 h4->Draw();
 h10->SetLineWidth(3);
 h10->SetLineStyle(9);
 h10->Draw("same");
 h10->SetLineWidth(2);
 h12->SetLineWidth(2);
 h12->SetLineStyle(1);
// h12->SetLineColor(kGreen);
 h12->SetLineColor(kBlue+2);
 h12->Draw("same");

// gStyle->Clear();
 TLegend *l2  = new TLegend(0.15,0.7,0.55,0.89); 
 l2->AddEntry(h4,"Data_HLT_HIMinBiasHforBSC_Core_vtx19","l"); 
 l2->AddEntry(h10,"Data_HLT_Update_HIMinBiasHforBSC_Core_vtx19" ,"l"); 
 l2->AddEntry(h12,"MC-AMPT_BOFF_PH_HIPixel-vtx19" ,"l"); 
 l2->Draw(); 
 c4->Update();

//=========================================

TCanvas *c5 = new TCanvas("c5", "Data Core and All Physics");
// gStyle->Clear();
 h7->GetXaxis()->SetTitle("|#eta|");
 h7->GetYaxis()->SetTitle("E"); 
 h7->SetLineWidth(3);
 h7->SetLineStyle(1);
 h7->Draw();
 h1->SetLineWidth(2);
 h1->SetLineColor(2);
 h1->Draw("same");

 TLegend *l1  = new TLegend(0.45,0.3,0.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(h1,"Data_HLT_HIMinBiasHforBSC_Core_vtx19","l"); 
 l1->AddEntry(h7,"Data_HLT_HIMinBiasHfOrBSC_AllPhysics_vtx19" ,"l"); 
 l1->Draw();
 c5->Update();
//
//==========
           MinBiasFullEvents_V19OverMimBias_V19->Divide(h7,h1,1,1);

           TCanvas *c51=new TCanvas("c51","E_RateOfData_HLT_HIMinBiasHforBSC_CoreAndAllPhysics_Vtx19");
	   MinBiasFullEvents_V19OverMimBias_V19->SetLineWidth(2);
	   MinBiasFullEvents_V19OverMimBias_V19->SetMarkerStyle(3);
           MinBiasFullEvents_V19OverMimBias_V19->SetLineColor(kRed);
	   MinBiasFullEvents_V19OverMimBias_V19->GetXaxis()->SetTitle("|#eta|");
	   MinBiasFullEvents_V19OverMimBias_V19->GetYaxis()->SetTitle("RatioOfE"); 
	   MinBiasFullEvents_V19OverMimBias_V19->GetYaxis()->SetRangeUser(0.98,1.002);
	   MinBiasFullEvents_V19OverMimBias_V19->Draw();

 TLegend *l1  = new TLegend(0.35,0.3,.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(MinBiasFullEvents_V19OverMimBias_V19,"RatioOfData_HLT_HIMinBiasHforBSC_CoreAndAllPhysics" ,"l"); 
 l1->Draw(); 
 c51->Update();
//========

TCanvas *c6 = new TCanvas("c6", "c6");
// gStyle->Clear();
 h9->GetXaxis()->SetTitle("|#eta|");
 h9->GetYaxis()->SetTitle("E_t"); 
 h9->SetLineWidth(3);
 h9->SetLineColor(1);
 h9->Draw();
 h4->SetLineWidth(2);
// h4->SetLineStyle(9);
 h4->SetLineStyle(1);
 h4->Draw("same");

 TLegend *l2  = new TLegend(0.15,0.7,0.55,0.89); 
 l2->AddEntry(h4,"Data_PH_HIMinBiasHfOrBSC_vtx19","l");
 l2->AddEntry(h9,"Data_HLT_HIMinBiasHfOrBSC_AllPhysics_vtx19" ,"l"); 
 l2->Draw(); 
 c6->Update();
//==========
           MinBiasFullEvents_V19OverMimBias_V19->Divide(h9,h4,1,1);
           TCanvas *c51=new TCanvas("c61","Et_RateOfData_HLT_HIMinBiasHforBSC_CoreAndAllPhysics_Vtx19");
	   MinBiasFullEvents_V19OverMimBias_V19->SetLineWidth(2);
	   MinBiasFullEvents_V19OverMimBias_V19->SetMarkerStyle(3);
           MinBiasFullEvents_V19OverMimBias_V19->SetLineColor(kRed);
	   MinBiasFullEvents_V19OverMimBias_V19->GetXaxis()->SetTitle("|#eta|");
	   MinBiasFullEvents_V19OverMimBias_V19->GetYaxis()->SetTitle("RatioOfEt"); 
	   MinBiasFullEvents_V19OverMimBias_V19->GetYaxis()->SetRangeUser(0.98,1.002);
	   MinBiasFullEvents_V19OverMimBias_V19->Draw();

 TLegend *l1  = new TLegend(0.35,0.3,.85,0.2,NULL,"brNDC"); 
 l1->SetTextSize(0.025);
 l1->AddEntry(MinBiasFullEvents_V19OverMimBias_V19,"RatioOfData_HLT_HIMinBiasHforBSC_CoreAndAllPhysics" ,"l"); 
 l1->Draw(); 
 c61->Update();
//========

//=======================================

}

// end of method
