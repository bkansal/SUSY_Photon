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
void decorate2(TH1D*,int);


void plotstack_accid(TString process)
{
  TLatex textOnTop,intLumiE;
  gStyle->SetPalette(kOcean);
  TFile *f1;
  TString fname,path;
   TString path1[1]={"./"};
   //  TString process[1]={"TTWGJets_2016_CR_v18.root"};
  TString fname1[4]={"AllSBins_v6_CD_elec1_id","AllSBins_v6_CD_elec0_acc","AllSBins_v6_CD_elec0_id","AllSBins_v6_CD_elec0_hadtau"};
  TString fname2[4]={"lepton passed Acc.x id x iso","lepton failed Acc.","lepton failed id x iso","hadronic #tau"};

  TH1D *sr[4];
  int xmin_=1, xmax_=9;
  f1 = new TFile(process);
  sr[0] = (TH1D*)f1->Get(fname1[0]);
  sr[1] = (TH1D*)f1->Get(fname1[1]);
  sr[2] = (TH1D*)f1->Get(fname1[2]);
  sr[3] = (TH1D*)f1->Get(fname1[3]);
  TCanvas *c1= new TCanvas("stackhist","stackhist",1000,1000);
  double sum[4],sum1[4];
  TH1D *total = new TH1D("total","Total events",8,1,9);
  TH1D *total_sr = new TH1D("total_sr","Total_Sr events",8,1,9);
  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);
  pad1->SetBottomMargin(0.3);
  pad1->Draw();pad1->SetGridx();
  TPad *pad2 = new TPad("pad2","pad2",0,0.0,1,0.3);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad1->cd();

  total->Add(sr[0]);
  total->Add(sr[1]);
  total->Add(sr[2]);
  total->Add(sr[3]);
  sr[0]->Divide(total);
  sr[1]->Divide(total);
  sr[2]->Divide(total);
  sr[3]->Divide(total);
  total_sr->Add(sr[1]);
  total_sr->Add(sr[2]);
  total_sr->Add(sr[3]);

  //  total->Draw();   

  THStack *hs_var=new THStack("var_Stack","SR events");
  decorate2(sr[0],0);
  decorate(sr[1],1);
  decorate(sr[2],2);
  decorate(sr[3],3);
  hs_var->Add(sr[0]);
  hs_var->Add(sr[1]);
  hs_var->Add(sr[2]);
  hs_var->Add(sr[3]);
  hs_var->Draw("hist");
  hs_var->SetMaximum(1.6);
  hs_var->SetMinimum(0.01);
  hs_var->GetYaxis()->SetLabelSize(0.04);
  hs_var->SetTitle(0);
  hs_var->GetYaxis()->SetTitle("Fractions");

  TLegend *legend = new TLegend(0.1,0.83,0.9,0.9);
  legend->SetNColumns(4);
  legend->SetTextSize(0.025);
  for(int i=1; i<4; i++)
    legend->AddEntry(sr[i],fname2[i],"f");
  legend->AddEntry(sr[0],fname2[0],"f");

  legend->Draw();
  /*
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
  */

  TLine *line1V6=new TLine( 1,0,  1,1);
  TLine *line2V6=new TLine( 2,0,  2,1);
  TLine *line3V6=new TLine( 3,0,  3,1);
  TLine *line4V6=new TLine( 4,0,  4,1);
  TLine *line5V6=new TLine( 5,0,  5,1);
  TLine *line6V6=new TLine( 6,0,  6,1);
  TLine *line7V6=new TLine( 7,0,  7,1);
  TLine *line8V6=new TLine( 8,0,  8,1);
  
  pad1->cd(); pad1->SetGridx(0); pad1->SetGridy(0);
  line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
  line4V6->Draw();      line5V6->Draw(); line6V6->Draw();
  line7V6->Draw(); line8V6->Draw();
  
  TArrow *arrow1 = new TArrow( 1, 1.1, 2, 1.1,0.01,"<|>");
  TArrow *arrow2 = new TArrow( 2, 1.1, 3, 1.1,0.01,"<|>");
  TArrow *arrow3 = new TArrow( 3, 1.1, 4, 1.1,0.01,"<|>");
  TArrow *arrow4 = new TArrow( 4, 1.1, 5, 1.1,0.01,"<|>");
  TArrow *arrow5 = new TArrow( 5, 1.1, 6, 1.1,0.01,"<|>");
  TArrow *arrow6 = new TArrow( 6,1.1, 7,1.1,0.01,"<|>");
  TArrow *arrow7 = new TArrow( 7,1.1, 8,1.1,0.01,"<|>");
  TArrow *arrow8 = new TArrow( 8,1.1, 9,1.1,0.01,"<|>");
  TArrow *arrow13 = new TArrow( 1,1.25, 7,1.25,0.01,"<|>");
  TArrow *arrow14 = new TArrow( 7,1.25, 9,1.25,0.01,"<|>");

  arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
  arrow4->Draw();
  arrow5->Draw(); arrow6->Draw();
  arrow7->Draw(); arrow8->Draw();
  arrow13->Draw(); arrow14->Draw();

  TLatex Tl,T2;
  T2.SetTextSize(0.03);
  Tl.SetTextSize(0.03);
  Tl.DrawLatex(1.25,1.14,"N^{ 0}_{ 2-4}");
  Tl.DrawLatex(2.25,1.14,"N^{ 0}_{ 5-6}");
  Tl.DrawLatex(3.25,1.14,"N^{ 0}_{ #geq7}");
  Tl.DrawLatex(4.25,1.14,"N^{ #geq1}_{ 2-4}");
  Tl.DrawLatex(5.25,1.14,"N^{ #geq1}_{ 5-6}");
  Tl.DrawLatex(6.25,1.14,"N^{ #geq1}_{ #geq7}");
  Tl.DrawLatex(7.25,1.14,"WTag");
  Tl.DrawLatex(8.25,1.14,"HTag");
  T2.DrawLatex(4.5,1.3,"SP region");
  T2.DrawLatex(7.5,1.3,"EW region");


  TH1D *h1 = (TH1D*)total_sr->Clone("h1");
  TH1D *h2 = (TH1D*)sr[0]->Clone("h2");

  textOnTop.SetTextSize(0.04);
  intLumiE.SetTextSize(0.04);
  textOnTop.DrawLatexNDC(0.1,0.91,"CMS  #it{#bf{Simulation}}");
  intLumiE.DrawLatexNDC(0.7,0.91,"#bf{137 fb^{-1} (13 TeV)}");

  pad2->cd();
  pad2->SetGrid(1);
  h1->GetYaxis()->SetNdivisions(5);
  h1->GetYaxis()->SetRangeUser(0,2.5);
  h1->GetYaxis()->SetTitleOffset(0.24);
  h1->GetYaxis()->SetTitleSize(0.15);
  h1->GetYaxis()->SetLabelSize(0.13);
  h1->SetLineColor(kBlack);
  h1->SetMinimum(0);  // Define Y ..                                                                                                                                    
  h1->SetMaximum(1.9); // .. range                                                                                                                                       
  h1->Sumw2();
  h1->SetStats(0);      // No statistics on lower plot                                                                                                                    
  h1->Divide(h2);
  h1->SetMarkerStyle(20);
  h1->SetMarkerSize(0.6);
  h1->Draw("ep");       // Draw the ratio plot

  h1->SetTitle(0);
  h1->GetXaxis()->SetTitleOffset(1.06);
  h1->GetXaxis()->SetTitleSize(0.14);
  h1->GetXaxis()->SetTitle("Bin no.");
  h1->GetXaxis()->SetLabelSize(0.15);
  h1->GetYaxis()->SetTitle("SR/CR");
  TLine *line= new TLine(xmin_,1.0,xmax_,1.0);
  line->SetLineColor(1);
  line->SetLineWidth(2);
  line->Draw();
  c1->SaveAs("pdf/LL_fraction.pdf");
  c1->SaveAs("png/LL_fraction.png");

}

void decorate(TH1D* hist,int i){
  hist->SetFillStyle(3008);
  hist->SetLineColor(col[i]);
  hist->SetFillColor(col[i]);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(1);
  hist->SetTitle(0);
  hist->GetXaxis()->SetTitleSize(0.06);
  gStyle->SetOptStat(0);

}
void decorate2(TH1D* hist,int i){
  hist->SetFillColor(col[i]);
  hist->SetLineColor(kBlack);
  hist->SetLineWidth(1);
  hist->SetTitle(0);
  hist->GetXaxis()->SetTitleSize(0.06);
  gStyle->SetOptStat(0);
}
