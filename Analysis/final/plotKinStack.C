#include<iostream>
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

char name[100];
char name2[100];
TString name3;
TLatex textOnTop,intLumiE;
const int nfiles=9,nBG=6;    //Specify no. of files
TFile *f[nfiles];
bool savePlots=1;
bool isPaper=0;
bool newbin=true;
double yset_=2;
vector<int> col={kPink+1,kTeal+9,kYellow,kGray,kOrange,kCyan,kBlue,kRed,kBlue+2,kMagenta,kCyan};  //Specify Colors b's
TCanvas *c_cA=new TCanvas("kinVar","plot of a kin var",1400,900);

string getfname(const char *fname1){string fname=fname1;fname.pop_back();fname.pop_back();fname.pop_back();fname.pop_back();fname.pop_back();return fname;}
void decorate(TH1D*,int,const char*);
void decorate(THStack*,int,const char*);
void drawlegend(TH1D*,int,const char*);
void printInt(TH1D*,int,const char*);

//TLegend *legend1=new TLegend(0.655,0.73,0.94,0.89);
//TLegend *legend2=new TLegend(0.12,0.67,0.60,0.89);

TLegend *legend1=new TLegend(0.6,0.54,0.92,0.7);
TLegend *legend2=new TLegend(0.12,0.7,0.60,0.89);

void setLastBinAsOverFlow(TH1D*);
TH1D* setMyRange(TH1D*,double,double);

//void plotKinStack(TString varName="AllSBins_v6_CD_EW_50bin", TString ext="" ,TString year="full_Run2",int seq=0,TString path="rootoutput/rootfiles_MCcutflow_MET300/"){
void plotKinStack(TString varName="AllSBins_v6_CD_EW_50bin", TString ext="" ,TString year="full_Run2",int seq=0,TString path="rootoutput/nphotons/"){
//void plotKinStack(TString varName="AllSBins_v6_CD_EW_50bin", TString ext="" ,TString year="full_Run2",int seq=0,TString path="PFCaloMET_Checks/withPFCaloMET/"){
  TString varName_=varName+ext;
  double sr_Integral=0,cr_Integral=0;
  TH1::SetDefaultSumw2(1);
  gStyle->SetOptStat(0);
  gStyle->SetTitle(0);
  double yMin=0.1,yMax = 1000;
  double xMin=0.0,xMax = 2000;
  int rebin;
  TString xLabel;

  if(varName == "ST") { xLabel = "H_{T}^{#gamma} (GeV)"; rebin=5; yMin=0.5,yMax = 11000; xMin=300.0,xMax = 5000;}
  if(varName == "MET_B"||varName == "MET_D") {xLabel = "p_{T}^{miss} (GeV)";   rebin=5; yMin=0.1,yMax = 1000000; xMin=300.0,xMax = 1500;}
  if(varName == "MET_C"||varName == "MET_A") {xLabel = "p_{T}^{miss} (GeV)";   rebin=1; yMin=0.1,yMax = 1000000; xMin=200.0,xMax = 300;}
  if(varName == "MET"||varName == "MET_SP" ||varName == "MET_EW") {xLabel = "p_{T}^{miss} (GeV)";   rebin=5; yMin=0.1,yMax = 1000000; xMin=100.0,xMax = 1500;}
  if(varName == "hadAk8Mass"||varName == "hadAk8Mass_EW" ||varName == "hadAk8Mass_SP") {xLabel = "Mass_{Leading Ak8Jet} (GeV)";  rebin=25,yMin=0.1,yMax = 1000000;
    if(varName == "hadAk8Mass_EW") xMin=0,xMax = 200;
    else xMin=0,xMax = 300;
  }
  if(varName.Contains("BestPhotonPt")){ xLabel = "p_{T}^{#gamma} (GeV)";  rebin=10; yMin=0.5,yMax = 100000; xMin=0.0,xMax = 600;}
  if(varName == "nPhotons" || varName == "nPhotons_SP" || varName == "nPhotons_EW" || varName == "nPhotons_C" || varName == "nPhotons_D"  ) { xLabel = "N_{#gamma}";   rebin=1; yMin=0.1,yMax = 10000000; xMin=1,xMax = 5;}
  if(varName == "nJets" || varName == "nJets_SP" || varName == "nJets_EW" || varName == "nJets_C" || varName == "nJets_D" || varName.Contains("h_PFCaloMETRatio") ) { xLabel = "N_{ jets}";   rebin=1; yMin=0.1,yMax = 100000; xMin=1,xMax = 14;}
  if(varName == "nBTags" || varName == "nBTags_A" ||varName == "nBTags_B" ||varName == "nBTags_C" ||varName == "nBTags_D") { xLabel = "N_{ b-jets}";   rebin=1; yMin=0.1,yMax = 100000; xMin=1,xMax = 8;}
  if(varName_ == "mindPhi1dPhi2"){ xLabel = "min(#Delta#phi_{1}, #Delta#phi_{2})"; rebin=1; yMin=0.3,yMax = 150000; xMin=0,xMax = 4;}
  if(varName == "AllSBins_v6_CD_EW_50bin" || varName == "AllSBins_v6_CD_EW_50bin_A" || varName == "AllSBins_v6_CD_EW_50bin_B" || varName == "AllSBins_v6_CD_EW_50bin_C" || varName == "AllSBins_v6_CD_EW_50bin_D" || varName == "AllSBins_v6_CD_EW_50bin_elec1_closure" || varName == "AllSBins_v7_CD"){ xLabel = "Bin index";  rebin=1; yMin=0.5,yMax = 10000000; xMin=2,xMax =45;}
  if(varName_ == "dPhi_METjet1"){ xLabel = "dPhi b/w Met & Jet1"; rebin=1;  yMin=0.3,yMax = 15000; xMin=0,xMax = 4;}
  if(varName_ == "dPhi_METjet2"){ xLabel = "dPhi b/w Met & Jet2"; rebin=1; yMin=0.3,yMax = 15000; xMin=0,xMax = 4;}
  if(varName_ == "dPhi_METjet3"){ xLabel = "dPhi b/w Met & Jet3"; rebin=1; yMin=0.3,yMax = 15000; xMin=0,xMax = 4;}
  if(varName_ == "dPhi_METjet4"){ xLabel = "dPhi b/w Met & Jet4"; rebin=1; yMin=0.3,yMax = 15000; xMin=0,xMax = 4;}
  if(varName_ == "dPhi_phoMET"){ xLabel = "dPhi b/w Met & Photon"; rebin=1; yMin=0.3,yMax = 15000; xMin=0,xMax = 4;}
  if(varName_ == "JetPt1" || varName_ == "JetPt2" || varName_ == "JetPt3" || varName_ == "JetPt4" ){ xLabel = varName_; rebin=2; yMin=0.3,yMax = 15000; xMin=0,xMax = 1000;
  }
  if(varName_ == "JetPhi1" || varName_ == "JetPhi2" || varName_ == "JetPhi3" || varName_ == "JetPhi4" || varName_ == "BestPhotonPhi"){ xLabel = varName_; rebin=2; yMin=0.3,yMax= 15000; xMin=-4,xMax = 4;}
  if(varName_ == "JetEta1" || varName_ == "JetEta2" || varName_ == "JetEta3" || varName_ == "JetEta4" || varName_ == "BestPhotonEta"){ xLabel = varName_; rebin=2; yMin=0.3,yMax = 15000; xMin=-4,xMax = 4;}

  if(year=="full_Run2")
      {
	//	if(varName.Contains("MET") || varName.Contains("AllSBins_v6_CD_EW_50bin") || varName.Contains("nPhotons"))path="rootoutput/nphotons/";
	if( varName.Contains("AllSBins_v6_CD_EW_50bin") || varName.Contains("nPhotons"))path="rootoutput/nphotons/";
	TString fname=path+"TTGJets_v18.root";
        fname=path+"GJetsQCD_new_v18.root";
	f[0] = new TFile(fname);
        fname=path+"ZGZJ_NuNuG_v18.root";
	f[1] = new TFile(fname);//ZGJetsToNuNuG_2018_v17.root
        fname=path+"TTJetsHT_v18.root";
	f[2] = new TFile(fname);
        fname=path+"WJetsToLNu_v18.root";
        f[3] = new TFile(fname);
        fname=path+"TTGJets_v18.root";
        f[4] = new TFile(fname);
	fname=path+"WGJetsToLNuG_v18.root";
	f[5] = new TFile(fname);
	col.resize(0);
        col={kCyan,kOrange,kTeal+9,kCyan-1,kGray,kRed,kBlue,kMagenta+3,kPink+10,kOrange+7,kBlack,kMagenta};
	//	if(varName.Contains("MET") || varName.Contains("AllSBins_v6_CD_EW_50bin") || varName.Contains("nPhotons")) path="rootoutput/nphotons/";
	if( varName.Contains("AllSBins_v6_CD_EW_50bin") || varName.Contains("nPhotons"))path="rootoutput/nphotons/";
	else path="rootoutput/nphotons_MET300/";
        fname=path+"T5bbbbZg_2200_200_FastSim_v18.root";
        f[6] = new TFile(fname);
        fname=path+"T5bbbbZg_2200_2100_FastSim_v18.root";
        f[7] = new TFile(fname);
	fname=path+"TChiWg_0_1200_FastSim_v18.root";
	f[8] = new TFile(fname);
	//        fname=path+"TChiWg_0_1000_FastSim_v18.root";
	//        f[9] = new TFile(fname);
      }
  
  //  gStyle->SetTextSize(2);
  THStack *hs_var=new THStack("var_Stack","MET Stacked");
  //TH1D *h_R;
  TH1D *h_MET_R[nfiles];
  for(int i=0;i<nfiles;i++){
    sprintf(name,"hist_file%i",i);
    h_MET_R[i]=new TH1D(name,name,21,0.5,21.5);
  }
  vector<double> Bcnt;
  double intLumi=0.0;
  TLatex tl1;

  for(int i=0;i<nfiles;i++){
    TH1D *h_MET;
    if(i<=nBG-1) h_MET=(TH1D*)f[i]->FindObjectAny(varName_);
    if(i>=nBG) h_MET=(TH1D*)f[i]->FindObjectAny(varName_);
    h_MET->Rebin(rebin);

    decorate(h_MET,i,f[i]->GetName());
    h_MET = setMyRange(h_MET,xMin,xMax);
    //    h_MET->GetXaxis()->SetRangeUser(xMin,xMax);
    
    if(i<=(nBG-1))  hs_var->Add(h_MET);

    if(i==nBG-1) {
      c_cA->cd();
      //      hs_var->Draw("BAR HIST");
      hs_var->Draw("hist");
      hs_var->SetMinimum(yMin);
      hs_var->SetMaximum(yMax);
      decorate(hs_var,i,f[i]->GetName()); 
      if(xMin > -10000 && xMax < 10000) hs_var->GetXaxis()->SetRangeUser(xMin-0.1,0.1+xMax);
    }
    if(i>=nBG && i<=9){ 
      c_cA->cd(); 
      h_MET->SetMarkerStyle(20);
      h_MET->SetMarkerColor(col[i]);
      h_MET->SetLineColor(col[i]);
      h_MET->SetLineWidth(3);
      if(i==9) h_MET->SetLineWidth(4);
      h_MET->Draw(" hist same");
    }
    if(i>10)
      {
	c_cA->cd();
	h_MET->SetMarkerStyle(20);
	h_MET->SetMarkerColor(col[i]);
	h_MET->SetLineColor(col[i]);
	h_MET->SetLineWidth(3);
	h_MET->SetLineStyle(1);
	h_MET->Draw("e1 same");
      }
    
    drawlegend(h_MET,i,f[i]->GetName());
    if(i==nfiles-1){ 
      hs_var->GetXaxis()->SetTitleOffset(1.0);
      hs_var->GetXaxis()->SetTitle(xLabel); hs_var->GetYaxis()->SetTitle("Events");hs_var->SetTitle(0);
      hs_var->GetYaxis()->SetTitleOffset(.90);
      hs_var->GetXaxis()->SetTitleSize(0.04);
      TString temp=h_MET->GetName(),temp2;
      if(temp.Contains("nJets") || temp.Contains("nBTags")  || temp.Contains("nPhotons")){
	gPad->SetTickx(0);
	hs_var->GetXaxis()->SetLabelSize(0.06);
	for(int i=1;i<=h_MET->GetNbinsX();i++){
	  temp2 = to_string(i-1);
	  if(i%2==0 && temp.Contains("nHadJets")) continue;
	    hs_var->GetXaxis()->SetBinLabel(i,temp2);
	}
	//      cout<<hist->GetName()<<endl;
      }
    }
    
  }
  if(varName.Contains("AllSBins_v6_CD_EW_50bin")){
    hs_var->GetXaxis()->SetTickLength(0);
    TString temp2;
    for(double j=1;j<=46;j++){
      temp2 = to_string(j-1);
      if((j-1)==5){temp2=to_string(5); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==10){temp2=to_string(10); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==15){temp2=to_string(15); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==20){temp2=to_string(20); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==25){temp2=to_string(25); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==30){temp2=to_string(30); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==35){temp2=to_string(35); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==40){temp2=to_string(40); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}
      else if((j-1)==45){temp2=to_string(45); hs_var->GetXaxis()->SetBinLabel(j+0.5,temp2);}   
    }
    
    hs_var->GetXaxis()->LabelsOption("h");
    hs_var->GetXaxis()->SetLabelSize(0.06);
    hs_var->GetXaxis()->SetLabelOffset(0.005);
    hs_var->GetXaxis()->SetTickLength(0);
    TF1 *f1_=new TF1("f1_","x",1.5,46.5);
    TGaxis *A1 = new TGaxis(1,0.1,46,0.1,"f1_",45,"U");
    A1->SetLabelSize(0.1);
    A1->Draw("B");
  }


  legend1->SetFillStyle(0); legend2->SetFillStyle(0);  
  legend1->SetNColumns(2);
  legend1->SetBorderSize(0);
  legend2->SetBorderSize(0);
  legend2->SetMargin(0.12);
  c_cA->cd(); gPad->SetLogy();legend1->Draw();
  c_cA->cd(); gPad->SetLogy();legend2->Draw();
 
  textOnTop.SetTextSize(0.038);
  intLumiE.SetTextSize(0.036);
  //  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation Supplementary}}");
  textOnTop.DrawLatexNDC(0.1,0.91,"CMS #it{#bf{Simulation Supplementary}}");
  // textOnTop.DrawLatexNDC(0.12,0.91,"work in progress");
  intLumiE.DrawLatexNDC(0.75,0.915,"#bf{137 fb^{-1} (13 TeV)}");
  TLatex Tl;
  Tl.SetTextSize(0.04);
  // if(isPaper) Tl.DrawLatexNDC(0.48,0.91,"#bf{arXiv:xxxx.xxxxx}");

  if(varName == "mindPhi1dPhi2"){
    TLine *line1=new TLine( 0.3,0.11,  0.3,yMax);
    line1->Draw();
    line1->SetLineStyle(2);
    TArrow *arrow1 = new TArrow(0.3,500,1.2,500,0.01,"|>");
    arrow1->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(0.33,540,"#bf{Signal Region}");
    //  Tl.SetTextSize(0.04);
    //  Tl.DrawLatexNDC(0.48,0.91,"#bf{arXiv:xxxx.xxxxx}");
  }
  /*
  if(varName.Contains("MET")){
    TLine *line1=new TLine( 300,yMin/5,  300,5000);
    line1->Draw();
    line1->SetLineStyle(2);
    TArrow *arrow1 = new TArrow(300,1500,xMax,1500,0.01,"|>");
    arrow1->Draw();
    TLatex Tl;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(320,2000,"#bf{Signal Region}");
  }
  */
  // //  c_cB->SaveAs("searchBins.png");
  //------------------------------------
  c_cA->cd(); c_cA->SetGridx(0); c_cA->SetGridy(0);
  

  if(varName=="AllSBins_v6_CD_EW_50bin" && newbin){

    yset_=1.5;
    TLine *line1V6=new TLine( 8,0.5,  8,yset_*5500);
    TLine *line2V6=new TLine(14,0.5, 14,yset_*5500);
    TLine *line3V6=new TLine(19,0.5, 19,yset_*5500);
    TLine *line4V6=new TLine(24,0.5, 24,yset_*5500);
    TLine *line5V6=new TLine(29,0.5, 29,yset_*5500);
    TLine *line6V6=new TLine(34,0.5, 34,yset_*5500);
    TLine *line7V6=new TLine(40,0.5, 40,yset_*5500);
    TLine *line8V6=new TLine(46,0.5, 46,yset_*5500);
    
    c_cA->cd(); c_cA->SetGridx(0); c_cA->SetGridy(0);
    line1V6->Draw();      line2V6->Draw();  line3V6->Draw();
    line4V6->Draw();      line5V6->Draw();
    line6V6->Draw();      line7V6->Draw();
    yset_=1;
     TArrow *arrow1 = new TArrow( 1,yset_*5000, 8,yset_*5000,0.01,"<|>");
     TArrow *arrow2 = new TArrow( 8,yset_*5000,14,yset_*5000,0.01,"<|>");
     TArrow *arrow3 = new TArrow(14,yset_*5000, 19,yset_*5000,0.01,"<|>");
     TArrow *arrow4 = new TArrow(19,yset_*5000, 24,yset_*5000,0.01,"<|>");
     TArrow *arrow5 = new TArrow(24,yset_*5000, 29,yset_*5000,0.01,"<|>");
     TArrow *arrow6 = new TArrow(29,yset_*5000, 34,yset_*5000,0.01,"<|>");
     TArrow *arrow7 = new TArrow(34,yset_*5000, 40,yset_*5000,0.01,"<|>");
     TArrow *arrow8 = new TArrow(40,yset_*5000, 46,yset_*5000,0.01,"<|>");

    arrow1->Draw(); arrow2->Draw(); arrow3->Draw();
    arrow4->Draw(); arrow5->Draw(); arrow6->Draw();
    arrow7->Draw(); arrow8->Draw();
    TLatex Tl;
    yset_=1.5;
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(3.5,5000*yset_,"N^{ 0}_{ 2-4}");
    Tl.DrawLatex(9.75,5000*yset_,"N^{ 0}_{ 5-6}");
    Tl.DrawLatex(15.5,5000*yset_,"N^{ 0}_{ #geq7}");
    Tl.DrawLatex(20.5,5000*yset_,"N^{ #geq1}_{ 2-4}");
    Tl.DrawLatex(25.5,5000*yset_,"N^{ #geq1}_{ 5-6}");
    Tl.DrawLatex(30.5,5000*yset_,"N^{ #geq1}_{ #geq7}");
    Tl.SetTextSize(0.04);
    Tl.DrawLatex(35.75,5000*yset_,"V tag");
    Tl.DrawLatex(41.5,5000*yset_,"H tag");
  }
  
  //------------------------------------
  if(savePlots){
    TString pdf,png;
    TString saveName = "supp_Sim_"+varName;
    TString modelName = f[6]->GetName();
    if(modelName.Contains("T5bbbb")) modelName = "T5bbbbZG";
    else if(modelName.Contains("T5qqqq")) modelName = "T5qqqqHG";
    else if(modelName.Contains("T5tttt")) modelName = "T5ttttZG";
    else if(modelName.Contains("T6tt")) modelName = "T6ttZG";
    else if(modelName.Contains("TChiW")) modelName = "TChiWG";
    else if(modelName.Contains("TChiN")) modelName = "TChiNG";

    saveName = saveName+"_"+modelName+".pdf";
    //c_cA->SaveAs(saveName);
    //    pdf="pdf/"+varName_+"_"+year+ext+".pdf";
    // png="png/"+varName_+"_"+year+ext+".png";
    //pdf=modelName+"/highdphi/pdf/"+varName_+"_full_Run2.pdf";
    //png=modelName+"/highdphi/png/"+varName_+"_full_Run2.png";
    //    pdf=path+"/pdf/"+varName+"/"+"0"+seq+"_"+varName_+"_full_Run2.pdf";
    //png=path+"/png/"+varName+"/"+"0"+seq+"_"+varName_+"_full_Run2.png";
    pdf="pdf/"+varName_+"_full_Run2.pdf";
    png="png/"+varName_+"_full_Run2.png";
    c_cA->SaveAs(pdf);
    c_cA->SaveAs(png);

  }
}

void decorate(THStack *hs,int i,const char* fname){
  //  hs->SetMinimum(0.5);
  //hs->SetTitle(0);
  hs->GetXaxis()->SetLabelSize(.04);
  hs->GetYaxis()->SetLabelSize(.05);
  hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitleSize(0.05);
  //  drawlegend(hist,i,fname);
  //  gPad->Update();
  gStyle->SetOptStat(0);
}
void decorate(TH1D* hist,int i,const char* fname){
  hist->SetLineColor(col[i]);
  if(i<nBG) {
    hist->SetFillColor(col[i]);
    hist->SetLineColor(kBlack);
    hist->SetLineWidth(1);
  }
  else hist->SetLineWidth(3);
  hist->SetTitle(0);
  hist->GetXaxis()->SetLabelSize(.05);
  hist->GetYaxis()->SetLabelSize(.06);
  //hist->SetXLabelSize(0.05);
  hist->GetXaxis()->SetTitleSize(0.04);
  // drawlegend(hist,i,fname);
  //  gPad->Update();
  setLastBinAsOverFlow(hist);
  gStyle->SetOptStat(0);
  
  //Hlist.Add(hist);
}

void drawlegend(TH1D *hist,int i,const char* fname){
  gStyle->SetLegendBorderSize(0);
 
  TString lName=fname;
  
  if(lName.Contains("ZGZJ")){lName="Z(#nu#bar{#nu}) + #gamma";}
  else if(lName.Contains("lost")) {lName = "lost lepton";}
  else if(lName.Contains("Fakerate")) {lName = "e fake #gamma";}
  else if(lName.Contains("Zin")) {lName = "Z(#nu#bar{#nu}) + #gamma";}
  else if(lName.Contains("multi")){lName="#gamma + jets";}

  else if(lName.Contains("ZJets")){lName="Z(#nu#bar{#nu}) + jets";}
  else if(lName.Contains("DYJetsToLL")){lName="DY(l^{+}l^{-})";}
  else if(lName.Contains("WJetsToLNu")){lName="W(l#nu) + jets";}
  else if(lName.Contains("RareProcess")){}
  else if(lName.Contains("TTJetsHT")){lName="t #bar{t}";}
  else if(lName.Contains("WGJetsToLNuG")){lName="W(l#nu) + #gamma";}
  else if(lName.Contains("ZGJetsToNuNuG")){lName="Z(#nu#bar{#nu}) + #gamma";}
  else if(lName.Contains("TTGJets")){lName="t #bar{t} + #gamma";}
  //  else if(lName.Contains("QCD")){lName="QCD";}
  else if(lName.Contains("GJets")){lName="#gamma + jets";}
  else if(lName.Contains("Run2")){lName="Data";}
  //  else if(lName.Contains("T5bbbbZg_1600_150")){lName="T5bbbbZg 1600, 150";}
  else if(lName.Contains("T5bbbbZg_1600_150")){lName = "pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1600 GeV, m_{#tilde{#chi}_{1}^{0}} = 150 GeV)";}
  else if(lName.Contains("T5bbbbZg_1600_1550")){lName = "#tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1600 GeV, m_{#tilde{#chi}_{1}^{0}} = 1550 GeV)";}
  else if(lName.Contains("T5bbbbZG_1800_150")){lName = "#tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 150 GeV)";}
  else if(lName.Contains("T5bbbbZG_1800_1750")){lName = "#tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1750 GeV)";}

  else if(lName.Contains("T5bbbbZg_2200_200")){lName = "pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T5bbbbZg_2200_1800")){lName = "#tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 1800 GeV)";}
  else if(lName.Contains("T5bbbbZg_2200_2100")){lName = "pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 2100 GeV)";}
  else if(lName.Contains("T5bbbbZg_1800_1000")){lName = "#tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1000 GeV)";}
  else if(lName.Contains("T5bbbbZg_2250_200")){lName = "pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2250 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T5bbbbZg_2250_2100")){lName = "pp #rightarrow #tilde{g}#tilde{g} , #tilde{g} #rightarrow b #bar{b} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2250 GeV, m_{#tilde{#chi}_{1}^{0}} = 2100 GeV)";}

 else if(lName.Contains("T5qqqqHg_1800_150")){lName = "#tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/H #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 150 GeV)";}
  else if(lName.Contains("T5qqqqHg_1800_1750")){lName = "#tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/H #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1750 GeV)";}
 else if(lName.Contains("T5qqqqHg_2200_200")){lName = "#tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/H #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T5qqqqHg_2200_1800")){lName = "#tilde{g} #rightarrow q #bar{q} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/H #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 1800 GeV)";}

  else if(lName.Contains("T5ttttZg_1800_150_")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 150 GeV)";}
  else if(lName.Contains("T5ttttZg_1800_1500")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1500 GeV)";}
  else if(lName.Contains("T5ttttZg_2200_200_")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T5ttttZg_2200_1800")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 2200 GeV, m_{#tilde{#chi}_{1}^{0}} = 1800 GeV)";}
  else if(lName.Contains("T5ttttZg_1800_1550")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1550 GeV)";}
  else if(lName.Contains("T5ttttZg_1800_1575")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1575 GeV)";}
  else if(lName.Contains("T5ttttZg_1800_1000")){lName = "#tilde{g} #rightarrow t #bar{t} #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1800 GeV, m_{#tilde{#chi}_{1}^{0}} = 1000 GeV)";}

  else if(lName.Contains("T6ttZg_1000_100")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1000 GeV, m_{#tilde{#chi}_{1}^{0}} = 100 GeV)";}
  else if(lName.Contains("T6ttZg_1000_900")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1000 GeV, m_{#tilde{#chi}_{1}^{0}} = 900 GeV)";}
  else if(lName.Contains("T6ttZg_1200_200")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1200 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T6ttZg_1200_1000")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1200 GeV, m_{#tilde{#chi}_{1}^{0}} = 1000 GeV)";}
  else if(lName.Contains("T6ttZg_1400_200")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1400 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T6ttZg_1400_1200")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1400 GeV, m_{#tilde{#chi}_{1}^{0}} = 1200 GeV)";}
  else if(lName.Contains("T6ttZg_1700_200")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1700 GeV, m_{#tilde{#chi}_{1}^{0}} = 200 GeV)";}
  else if(lName.Contains("T6ttZg_1700_1500")){lName = "#tilde{t} #rightarrow t #tilde{#chi}_{1}^{0}, #tilde{#chi}_{1}^{0} #rightarrow #gamma/Z #tilde{G} (m_{#tilde{g}} = 1700 GeV, m_{#tilde{#chi}_{1}^{0}} = 1500 GeV)";}

  // else if(lName.Contains("T5bbbbZg_1600_150")){lName = "T5bbbbZG (m_{#tilde{g}} = 1600 GeV, m_{#tilde{#chi}_{1}^{0}} = 150 GeV)";}
  // else if(lName.Contains("T5bbbbZg_1600_1550")){lName = "T5bbbbZG (m_{#tilde{g}} = 1600 GeV, m_{#tilde{#chi}_{1}^{0}} = 1550 GeV)";}
  else if(lName.Contains("T5bbbbZg_1600_1550")){lName="T5bbbbZg 1600, 1550";}
  else if(lName.Contains("T5qqqqHg_1600_1550")){lName="T5qqqqHg_1550";}
  else if(lName.Contains("T5qqqqHg_1600_150")){lName="T5qqqqHg_150";}
  else if(lName.Contains("TChiWg_0_400")){lName="pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{0} ,  #tilde{#chi}_{1}^{0}/#tilde{#chi}_{1}^{+/-} #rightarrow #gamma/W^{#pm} #tilde{G} , (m_{#tilde{#chi}_{1}^{0}} = m_{#tilde{#chi}_{1}^{+/-}} = 400 GeV)";}
  else if(lName.Contains("TChiWg_0_800")){lName="pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{0} ,  #tilde{#chi}_{1}^{0}/#tilde{#chi}_{1}^{+/-} #rightarrow #gamma/W^{#pm} #tilde{G} , (m_{#tilde{#chi}_{1}^{0}} = m_{#tilde{#chi}_{1}^{+/-}} = 800 GeV)";}
  else if(lName.Contains("TChiWg_0_1000")){lName="pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{0} ,  #tilde{#chi}_{1}^{0}/#tilde{#chi}_{1}^{+/-} #rightarrow #gamma/W^{#pm} #tilde{G}  , M#tilde{#chi}_{1}^{0} = M#tilde{#chi}_{1}^{+/-} = 1000 GeV";}
  else if(lName.Contains("TChiWg_0_1200")){lName="pp #rightarrow #tilde{#chi}_{1}^{+/-}#tilde{#chi}_{1}^{0} ,  #tilde{#chi}_{1}^{0}/#tilde{#chi}_{1}^{+/-} #rightarrow #gamma/W^{#pm} #tilde{G}  , M#tilde{#chi}_{1}^{0} = M#tilde{#chi}_{1}^{+/-} = 1200 GeV";}
  else if(lName.Contains("TChiNg_N1C2_C1C2_0_400")){lName="TChiNg , M#tilde{#chi}_{1}^{+/-} = M#tilde{#chi}_{1}^{0} = 400 GeV";}
  else if(lName.Contains("TChiNg_N1C2_C1C2_0_800")){lName="TChiNg , M#tilde{#chi}_{1}^{+/-} = M#tilde{#chi}_{1}^{0} = 800 GeV";}

  else if(lName.Contains("TChiNg_N1C2_C1C2_0_1200")){lName="TChiNg , M#tilde{#chi}_{1}^{+/-} = M#tilde{#chi}_{1}^{0} = 1200 GeV";}
  else if(lName.Contains("TChiNg_0_400")){lName="TChiNg , M#tilde{#chi}_{2}^{0} = M#tilde{#chi}_{3}^{0} = 400 GeV";}
  else if(lName.Contains("TChiNg_0_800")){lName="pp #rightarrow #tilde{#chi}_{1}^{#pm}#tilde{#chi}_{1/2}^{0} ,  #tilde{#chi}_{1}^{0} #rightarrow #gamma/H/Z #tilde{G} , M#tilde{#chi}_{1/2}^{0}/M#tilde{#chi}_{1}^{#pm} = 800 GeV";}
  else if(lName.Contains("TChiNg_0_1000")){lName="pp #rightarrow #tilde{#chi}_{1}^{#pm}#tilde{#chi}_{1/2}^{0} ,  #tilde{#chi}_{1}^{0} #rightarrow #gamma/H/Z #tilde{G} , M#tilde{#chi}_{1/2}^{0}/M#tilde{#chi}_{1}^{#pm} = 1000 GeV";}
  else if(lName.Contains("TChiNg_0_1200")){lName="pp #rightarrow #tilde{#chi}_{1}^{#pm}#tilde{#chi}_{1/2}^{0} ,  #tilde{#chi}_{1}^{0} #rightarrow #gamma/H/Z #tilde{G} , M#tilde{#chi}_{1/2}^{0}/M#tilde{#chi}_{1}^{#pm} = 1200 GeV";}

  // else if(lName.Contains("TChiNg_0_800")){lName="TChiNg , M#tilde{#chi}_{2}^{0} = M#tilde{#chi}_{3}^{0} = 800 GeV";}
  //  else if(lName.Contains("TChiNg_0_1200")){lName="TChiNg , M#tilde{#chi}_{2}^{0} = M#tilde{#chi}_{3}^{0} = 1200 GeV";}

  // const char *l_name=lName.c_str();
  if(i<nBG)legend1->AddEntry(hist,lName,"f");
  else
    {
      //      if(!lName.Contains("Run2"))
      if(i==8) legend2->AddEntry(hist,lName,"l");
      else legend2->AddEntry(hist,lName,"l");
    }
  legend1->SetTextSize(0.040);
  legend2->SetTextSize(0.038);
}


void setLastBinAsOverFlow(TH1D* h_hist){
  double lastBinCt =h_hist->GetBinContent(h_hist->GetNbinsX()),overflCt =h_hist->GetBinContent(h_hist->GetNbinsX()+1);
  double lastBinErr=h_hist->GetBinError(h_hist->GetNbinsX()),  overflErr=h_hist->GetBinError(h_hist->GetNbinsX()+1);
  
  if(lastBinCt!=0 && overflCt!=0)
    lastBinErr = (lastBinCt+overflCt)* (sqrt( ((lastBinErr/lastBinCt)*(lastBinErr/lastBinCt)) + ((overflErr/overflCt)*(overflErr/overflCt)) ) );
  
  else if(lastBinCt==0 && overflCt!=0)
    lastBinErr = overflErr;
  else if(lastBinCt!=0 && overflCt==0)
    lastBinErr = lastBinErr;
  else lastBinErr=0;

  lastBinCt = lastBinCt+overflCt;
  h_hist->SetBinContent(h_hist->GetNbinsX(),lastBinCt);
  h_hist->SetBinError(h_hist->GetNbinsX(),lastBinErr);
    
}

TH1D* setMyRange(TH1D *h1,double xLow,double xHigh){
  //call it after setting last bin as overflow
  double err=0;
  if(xHigh > 13000) return h1;
  if(xLow < -13000) return h1;
  // h1->Print("all");
  int nMax=h1->FindBin(xHigh);
  h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  h1->SetBinError(nMax,err);
  //  cout<<nMax<<endl;
  for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
    h1->SetBinContent(i,0);
    h1->SetBinError(i,0);
    //    cout<<":";
  }
  //  h1->Print("all");
  //  cout<<endl;
  return h1;
  //  h1->GetXaxis()->SetRangeUser(xLow,xHigh);                                                                                                                      
}
