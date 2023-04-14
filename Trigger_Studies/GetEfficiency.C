#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TTree.h"
#include"TBrowser.h"
#include"TF1.h"
#include<iomanip>
#include"TGraphErrors.h"
#include"TGraphAsymmErrors.h"
#include"TGraph.h"
#include"TCanvas.h"
#include"TPaveStats.h"
#include"TStyle.h"
#include"TLegend.h"

//#include"Variables.h"

using namespace std;

void nameLegend2(const char*);
void decorate(TH1D*,int);
TList *FileList;
vector<TString> legName;
vector<TString> histName1,histName2;
TLatex textOnTop,intLumiE;

TLegend *legend1=new TLegend(0.25,0.35,0.35,0.7);
TString xAxisLabel;
char name[100];
int col[7]={kBlue,kRed,kOrange-3,kTeal+9,kMagenta,kOrange,kCyan};

int rebin=1;

void GetEfficiency(){
  TH1::SetDefaultSumw2(1);

  FileList = new TList();
  int nfiles=1;
  TFile *f[nfiles];
  TString name="PhotonPt_HT";
  //  xAxisLabel="#gamma p^{T}(GeV)";
  //  xAxisLabel="ST(GeV)";
  xAxisLabel="e pT(GeV)";

  //f[0] = new TFile("Run2016_MET_03Feb2017_SingEleTrg_NoIsoTightID_ST500_v2.root");
  // f[0] = new TFile("Run2016CtoH_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[0] = new TFile("Run2016B_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[1] = new TFile("Run2016C_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[2] = new TFile("Run2016D_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[3] = new TFile("Run2016E_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[4] = new TFile("Run2016F_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[5] = new TFile("Run2016G_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");
  // f[6] = new TFile("Run2016H_MET_03Feb2017_Ele15_IsoVVVL_PFHT400Pho165_AtLeast1Ele.root");

  f[0] = new TFile("Run2016_MET_03Feb2017_ElexHT_1Ele.root");
  
  // histName1.push_back("PhotonPt_PhoPt");
  // histName2.push_back("PhotonPt_HT");
  // histName1.push_back("HT_HT");
  // histName2.push_back("HT_PhoPt");
  for(int i=0;i<nfiles;i++){
    // histName1.push_back("HT_Req");
    // histName2.push_back("HT");
    // histName1.push_back("PhoPtvBin_Req");
    // histName2.push_back("PhoPtvBin");
    // histName1.push_back("STvBin_Req");
    // histName2.push_back("STvBin");
    // histName1.push_back("Ele1PtvBin_Req");
    // histName2.push_back("Ele1PtvBin");
    histName1.push_back("Ele1Pt_Req");
    histName2.push_back("Ele1Pt");
    // histName1.push_back("Ele2Pt_Req");
    // histName2.push_back("Ele2Pt");

  }

  // histName1.push_back("MET_PhoPt"); 
  // histName2.push_back("MET_HT"); 
  rebin=1;
  //  legName.push_back("2016C to 2016H (35.1 fb^{-1})");
  legName.push_back("2016 (35.9 fb^{-1})");
  // legName.push_back("2016B (5.78 fb^{-1})");
  // legName.push_back("2016C (2.57 fb^{-1})");
  // legName.push_back("2016D (4.25 fb^{-1})");
  // legName.push_back("2016E (4.01 fb^{-1})");
  // legName.push_back("2016F (3.10 fb^{-1})");
  // legName.push_back("2016G (7.54 fb^{-1})");
  // legName.push_back("2016H (8.61 fb^{-1})");
  vector<double> STLowEdge={0,100,200,300,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,580,600,620,640,680,720,740,760,780,800,820,840,880,920,960,1000,1400,1800,2500,3500,5000};
  vector<double> PhoPtLowEdge={0,50,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,240,260,280,300,320,340,360,380,400,440,480,520,580,650,750,900,1050,1400,2000};


  TCanvas *cA = new TCanvas("TrgEff","Trigger efficiency",1500,850);
  TCanvas *cB = new TCanvas("his","hist",1500,850);
  cA->SetTickx();cA->SetTicky();
  TGraphAsymmErrors *h_grAE[nfiles];
  TH1D *h1,*h2,*h1r,*h2r;

  for(int i=0;i<nfiles;i++){
    h1 = (TH1D*)f[i]->FindObjectAny(histName1[i]);
    h2 = (TH1D*)f[i]->FindObjectAny(histName2[i]);
    h1->Rebin(rebin);
    h2->Rebin(rebin);
    h_grAE[i] = new TGraphAsymmErrors(h1,h2);
    // h1r = dynamic_cast<TH1D*>(h1->Rebin(PhoPtLowEdge.size()-1,"h1new",&(PhoPtLowEdge[0])));
    // h2r = dynamic_cast<TH1D*>(h1->Rebin(PhoPtLowEdge.size()-1,"h2new",&(PhoPtLowEdge[0])));
    // h_grAE[i] = new TGraphAsymmErrors(h1r,h2r);
    // decorate(h1,i);
    //  decorate(h2,i);
    
    //   h_grAE[i]->SetMarkerStyle(20+i);
    h_grAE[i]->SetMarkerColor(col[i]);
    h_grAE[i]->SetLineColor(col[i]);
    h_grAE[i]->SetLineWidth(2);
    h_grAE[i]->SetMinimum(0.);
    h_grAE[i]->SetMaximum(1.1);
    
    cA->cd();
    cA->SetGridx();
    cA->SetGridy();
    if(i==0) {
      h_grAE[i]->Draw();
      h_grAE[i]->SetTitle(0);
      h_grAE[i]->GetXaxis()->SetTitle(xAxisLabel);
      h_grAE[i]->GetYaxis()->SetTitle("#varepsilon");
      h_grAE[i]->GetYaxis()->SetTitleOffset(0.5);
      h_grAE[i]->GetYaxis()->SetTitleSize(0.06);
    }
    else h_grAE[i]->Draw("sames");
    legend1->AddEntry(h_grAE[i],legName[i],"lpe");
    gPad->Update();
  }

  legend1->Draw();
  cB->cd();
  h1->Draw();
  h2->Draw("sames");

  cA->cd();

  char name2[100];  
  textOnTop.SetTextSize(0.035);
  intLumiE.SetTextSize(0.035);
  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Preliminary}}");
  sprintf(name2,"#bf{35.9 fb^{-1}(13TeV)}");
  intLumiE.DrawLatexNDC(0.73,0.91,name2);

  TFile *fout=new TFile("Eff_"+histName2[0]+f[0]->GetName(),"RECREATE");
  fout->cd();
  for(int i=0;i<nfiles;i++){
    h_grAE[i]->Write();
  }
  /*
  TCanvas *c_cC=new TCanvas("PhoPtST_Eff","PhoPtST_Eff",1500,850);
  TH2D *h2_den=(TH2D*)f[0]->FindObjectAny("PhoPtST");
  TH2D *h2_num=(TH2D*)f[0]->FindObjectAny("PhoPtST_Req");
  TH2D *h2_numC1=(TH2D*)h2_num->Clone("h2_NumCopy1");
  h2_numC1->Divide(h2_den);
  h2_numC1->Draw("colz");*/
}

  //  FileList->Add(TFile::Open("b.root") );  histName.push_back(name); legName.push_back("HE_RBX_plus0p10");
   
void decorate(TH1D* h,int i){
  h->SetLineColor(col[i]);
  h->SetLineWidth(2);
  //  h->SetFillColor(h->GetLineColor());
  h->SetMarkerStyle(20+i);
  h->SetMarkerColor(col[i]);
}
