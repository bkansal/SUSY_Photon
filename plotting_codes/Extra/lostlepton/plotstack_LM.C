////////////// fraction of CR & SR events in Lost Muon estimation ////////// 
#include<iomanip>
#include"TH1.h"
#include"TROOT.h"
#include"TH2.h"
#include"TFile.h"
#include"TDirectory.h"
#include"TTree.h"
#include"TBrowser.h"
#include"TF1.h"
#include<string>
#include<vector>
#include"TGraphErrors.h"
#include"TGraph.h"
#include"TLegend.h"
#include"TLatex.h"
#include"TCanvas.h"
#include"THStack.h"
#include"TStyle.h"
vector<int> col={kGray,kTeal+9,kOrange,kCyan-1,kBlack};

void decorate(TH1D*,int);


void plotstack_LM()
{
  gStyle->SetPalette(kOcean);
  TFile *f[4][4];
  TString fname,path;
  TH1D *sr1_[4][4];
  TH1D  *h_SR[4][4];
  //  TH1D *h_SRmc= new TH1D("SRmc","Expected events in 51 SR bins",nbin,xmin,xmax);
  TString path1[4]={ "rootoutput/new/nominal_fr/LM_onlymu/","rootoutput/new/nominal_fr/LM_onlymu/","rootoutput/new/nominal_fr/LM_onlymu/", "rootoutput/new/nominal_fr/LM_hadtau/"};
  TString process[4]={"TTJets_2016_CR_v18.root","TTGJets_2016_CR_v18.root","WJets_2016_CR_v18.root","WGJets_2016_CR_v18.root"};
  TString fname1[4]={"1Muon_CR","LM_SR","LM_emuSR","hadtau_SR"};
  TString fname3[4]={"CR: 1 #mu + 1#gamma","SR: lost #mu + 1#gamma","SR : 1e , lost-#mu  + 1#gamma","SR : #tau hadronic + #gamma"};
  TString fname2[4]={"ttjets","ttg","wjets","wg"};
  TH1D *sr[4];

  for(int i=0; i<4 ; i++)
    {
      sr[i] = new TH1D(fname1[i],fname1[i],6,0,6); 
      for(int j=0; j<4 ; j++)
	{
	  path=path1[i]+process[j];
	  fname=fname1[i]+"_"+fname2[j];
	  f[i][j]= new TFile(path);
	  if(i==0) sr1_[i][j]= (TH1D*)f[i][j]->Get("hasGenPromptPhoton");
	  else if(i==2) sr1_[i][j]= (TH1D*)f[i][j]->Get("hasGenPromptPhoton_ele_elec0");
	  else  sr1_[i][j]= (TH1D*)f[i][j]->Get("hasGenPromptPhoton_elec0");
	  h_SR[i][j]= new TH1D(fname,"Integral",1,0,1);
	  h_SR[i][j]->SetBinContent(0,sr1_[i][j]->Integral());
	  cout<<"sample : "<<fname<<endl;
	  cout<<h_SR[i][j]->GetBinContent(0)<<endl;
	  sr[i]->SetBinContent(j+1,sr1_[i][j]->Integral());
	}
    }
  double sum[4],sum1[4];
  TH1D *total = new TH1D("total","Total events",6,0,6);
  total->Add(sr[0]);
  total->Add(sr[1]);
  total->Add(sr[2]);
  total->Add(sr[3]);

  sr[0]->Divide(total);
  sr[1]->Divide(total);
  sr[2]->Divide(total);
  sr[3]->Divide(total);


  for(int j=0; j<5; j++)
    {
      cout<<j<<" : "<<total->GetBinContent(j)<<endl;
    }
   
   total->Draw();
   


  THStack *hs_var=new THStack("var_Stack","SR events");
  decorate(sr[0],0);
  decorate(sr[1],1);
  decorate(sr[2],2);
  decorate(sr[3],4);

  hs_var->Add(sr[0]);
  hs_var->Add(sr[1]);
  hs_var->Add(sr[2]);
  hs_var->Add(sr[3]);
  hs_var->Draw("hist");

  TLegend *legend = new TLegend(0.65,0.5,0.9,0.9);
  legend->SetTextSize(0.035);
  for(int i=0; i<4; i++)
    legend->AddEntry(sr[i],fname3[i],"f");
  legend->Draw();
  TText t;
  Float_t x, y;
  y = gPad->GetUymin() - 0.2*hs_var->GetYaxis()->GetBinWidth(1);
  t.SetTextAngle(0);
  t.SetTextSize(0.04);
  t.SetTextAlign(33);
  for (int i=0;i<4;i++) {
    x = hs_var->GetXaxis()->GetBinCenter(i+1);
    t.DrawText(x+0.05,-0.025,fname2[i]);
   }
}

void decorate(TH1D* hist,int i){
  hist->SetFillStyle(3008);
  hist->SetLineColor(col[i]);
  hist->SetFillColor(col[i]);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(1);
  hist->SetTitle(0);
  /* hist->GetXaxis()->SetLabelSize(.06); */
  /* hist->GetYaxis()->SetLabelSize(.10); */
  hist->GetXaxis()->SetTitleSize(0.06);
  gStyle->SetOptStat(0);

}
