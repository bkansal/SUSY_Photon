#include <TH2D.h>
#include <TFile.h>
#include <TCanvas.h>
#include<iostream>
#include<iomanip>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TF1.h"
#include<string>
#include<vector>
#include"TGraphErrors.h"
#include"TGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TCanvas.h"
#include"TGraph2D.h"
TLatex textOnTop,textOnTop2,intLumiE;
double intLumi = 137.0;
char name3[100];


void phoeff(TString fname="rootoutput/phoeff/T5qqqqHg_2250_2100_FastSim_v18.root",TString modelName="T5qqqqHg",TString mass="2100"){
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  int n=9;
  textOnTop.SetTextSize(0.04);
  textOnTop2.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  sprintf(name3,"#bf{%0.0f fb^{-1} (13 TeV)}",intLumi);
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.50, 0.50, 1.00, 1.00, 1.00 };
  Double_t green[NRGBs] = { 0.50, 1.00, 1.00, 0.60, 0.50 };
  Double_t blue[NRGBs]  = { 1.00, 1.00, 0.50, 0.40, 0.50 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat("4.2f ");
  // Open input ROOT file and get the TH2D histogram
  TFile* inputFile = new TFile(fname, "READ");
  //  TFile* inputFile = new TFile("T5bbbbZg_2200_1000_maskingSRbins/fitDiagnosticsTest.root", "READ");
  TH2D *h_num[9],*h_deno[9],*h_phoeff[9];
  TString v_num[9]={"genPhoBestPho_pteta","genPhoBestPho_pteta_nj2nb0","genPhoBestPho_pteta_nj5nb0","genPhoBestPho_pteta_nj7nb0","genPhoBestPho_pteta_nj2nb1","genPhoBestPho_pteta_nj5nb1","genPhoBestPho_pteta_nj7nb1","genPhoBestPho_pteta_vtag","genPhoBestPho_pteta_htag"};
  TString v_deno[9]={"genPho_pteta","genPho_pteta_nj2nb0","genPho_pteta_nj5nb0","genPho_pteta_nj7nb0","genPho_pteta_nj2nb1","genPho_pteta_nj5nb1","genPho_pteta_nj7nb1","genPho_pteta_vtag","genPho_pteta_htag"};
  TString title[9]={"Photon efficiency for inclusive bins","Photon efficiency for 2 \\leq N_{j} \\leq 4 , N_{bj} = 0 ", "Photon efficiency for 5 \\leq N_{j} \\leq 6 , N_{bj} = 0","Photon efficiency for  N_{j} \\geq 7, N_{bj} = 0","Photon efficiency for 2 \\leq N_{j} \\leq 4 , N_{bj} >  0", "Photon efficiency for 5 \\leq N_{j} \\leq 6 , N_{bj} >  0","Photon efficiency for  N_{j} \\geq 7 , N_{bj} >   0","Photon efficiency for V-tag","Photon efficiency for H-tag" };
  TString title_[9]={"0","1","2","3","4","5","6","7","8"};
  TCanvas* canvas;
  TPaveText *decayMode;
  for(int i=0; i<n; i++){
    canvas = new TCanvas("covariance", "Covariance between search region");
    canvas->cd();
    canvas->SetLeftMargin(0.08);
    canvas->SetRightMargin(0.14);
  
    h_num[i] = (TH2D*)inputFile->FindObjectAny(v_num[i]);
    h_deno[i] = (TH2D*)inputFile->FindObjectAny(v_deno[i]);
    h_num[i]->Sumw2();
    h_num[i]->SetStats(0);      // No statistics on lower plot
    h_num[i]->Divide(h_deno[i]);
    h_num[i]->SetTitle(0);
    h_num[i]->GetZaxis()->SetRangeUser(0.5,1);
    h_num[i]->GetZaxis()->SetTitle(title[i]);// + " , (M_{#tilde{g}} = "+mass+" GeV)");
    if(i==0 || i>=7) {h_num[i]->GetZaxis()->SetTitleSize(0.04);h_num[i]->GetZaxis()->SetTitleOffset(1.05);} 
    else  {h_num[i]->GetZaxis()->SetTitleSize(0.033); h_num[i]->GetZaxis()->SetTitleOffset(1.2);}
    h_num[i]->GetZaxis()->SetLabelSize(0.03);
    //    h_num[i]->GetZaxis()->SetTitleOffset(1.05);
    h_num[i]->GetXaxis()->SetTitle("p_{T}^{#gamma} (GeV)");
    h_num[i]->GetXaxis()->SetTitleSize(0.045);
    h_num[i]->GetXaxis()->SetLabelSize(0.035);
    h_num[i]->GetXaxis()->SetTitleOffset(0.98);
    h_num[i]->GetXaxis()->SetRangeUser(100,550);
    h_num[i]->GetYaxis()->SetRangeUser(0,2.75);
    h_num[i]->GetYaxis()->SetTitle("#gamma |#eta|");
    h_num[i]->GetYaxis()->SetTitleSize(0.045);
    h_num[i]->GetYaxis()->SetLabelSize(0.035);
    h_num[i]->GetYaxis()->SetTitleOffset(0.8);
    h_num[i]->SetMarkerSize(1.5);
    h_num[i]->Draw("COLZ text0 e");
    h_num[i]->GetXaxis()->SetTickLength(0.015);
    h_num[i]->GetYaxis()->SetTickLength(0.015);

    textOnTop.DrawLatexNDC(0.08,0.915,"CMS");
    textOnTop2.DrawLatexNDC(0.14,0.915,"#it{#bf{Simulation Supplementary}}");
    intLumiE.DrawLatexNDC(0.685,0.915,name3);
    TString model=modelName+"_"+mass;
    TString path="pdf/phoeff/"+model;
    TString pdf=path+"_"+title_[i];
    decayMode = new TPaveText(0.08,0.77, 0.857,0.9,"NDC");
    decayMode->SetShadowColor(0);   decayMode->SetFillColor(0);
    decayMode->SetLineWidth(2);
    decayMode->SetTextSize(0.04);
    if(modelName.Contains("T5qqqqHg")){
      decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{ 1}^{ 0}, #it{B}(#tilde{#chi}_{ 1}^{ 0}#rightarrow #gamma #tilde{G}) = #it{B}(#tilde{#chi}_{ 1}^{ 0}#rightarrow H #tilde{G}) = 50%}");
      decayMode->AddText(" #bf{M_{#tilde{g}} = "+mass+" GeV and inclusive in M_{#tilde{#chi}_{ 1}^{ 0}}}");
      modelName="T5qqqqHg";}
    else if(modelName.Contains("T5ttttZg")){
      decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{ 1}^{ 0}, #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma #tilde{G}) = #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow Z #tilde{G}) = 50%}");
      decayMode->AddText(" #bf{M_{#tilde{g}} = "+mass+" GeV and inclusive in M_{#tilde{#chi}_{ 1}^{ 0}}}");
      modelName="T5ttttZg";}
    else if(modelName.Contains("T5bbbbZg")){
      decayMode->AddText("#bf{pp #rightarrow #tilde{g} #tilde{g}, #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{ 1}^{ 0}, #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma #tilde{G}) = #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow Z #tilde{G}) = 50%}");
      decayMode->AddText(" #bf{M_{#tilde{g}} = "+mass+" GeV and inclusive in M_{#tilde{#chi}_{ 1}^{ 0}}}");
      modelName="T5bbbbZg";}
    else if(modelName.Contains("T6ttZg")){
      decayMode->AddText("#bf{pp #rightarrow #tilde{t} #bar{#tilde{t}}, #tilde{t} #rightarrow t #tilde{#chi}_{ 1}^{ 0}, #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow #gamma #tilde{G}) = #it{B}(#tilde{#chi}_{ 1}^{ 0} #rightarrow Z #tilde{G}) = 50%}");
      decayMode->AddText(" #bf{M_{#tilde{t}} = "+mass+" GeV and inclusive in M_{#tilde{#chi}_{ 1}^{ 0}}}");
      modelName="T6ttZg";}

    decayMode->Draw();
    canvas->SaveAs(pdf+".pdf");
    canvas->SaveAs(pdf+".png");

  }

  TFile* covariance_f = new TFile("Photonefficiency.root", "RECREATE");
  covariance_f->cd();
  for(int i=0; i<n; i++) h_num[i]->Write();
  covariance_f->Close();


}
