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

const int nfiles=4;    //Specify no. of files
vector<int> col={kCyan,kOrange,kTeal+9,kCyan-1,kRed,kBlack};

void decorate(TH1D*,int,const char*);
TString name;
bool saveCanvas=1, set0binsSmallValue = 1, sepSystStat = 1, plotPostFitSignal = 0, printTable = 1;
void set0PredSmall(TH1D*,double);
void setLastBinAsOverFlow(TH1D*);
void setMyRange(TH1D*,double,double);
void setMyRange(THStack*,double,double);
TString getLegName(TString);
TString getXaxisName(TString);
double data_Integral=0,mc_Integral=0, datatIntgrErr = 0, mcIntgrErr = 0, stackHistMinVal = 0.7;
TLatex textOnTop,intLumiE,textOnTop2;
double intLumi=35.9;
TFile *f, *fSig[nfiles-1];

void DataVsPredFit_1D(TString sample="general",TString iFname="rootoutput/SR_prefitPredictions_Run2_v4.root", TString catName="MET")
{
  f = new TFile(iFname);
  vector<int> col={kGray,kTeal+9,kOrange,kCyan-1,kRed,kBlack};

  TH1D *hz = (TH1D*)f->Get("Zin");
  TH1D *hl = (TH1D*)f->Get("LL");
  TH1D *hf = (TH1D*)f->Get("FR");
  TH1D *hq = (TH1D*)f->Get("QCD");
  TH1D *hT = (TH1D*)f->Get("TotalBG");
  TH1D *hd = (TH1D*)f->Get("DataFit");
  //////////////////////////////////////////////////

  TH1D *zin = (TH1D*)f->Get("Zin");
  TH1D *ll = (TH1D*)f->Get("LL");
  TH1D *fr = (TH1D*)f->Get("FR");
  TH1D *multi = (TH1D*)f->Get("QCD");
  TH1D *total = (TH1D*)f->Get("TotalBG");
  ////////////////////////////////////////////////
  TH1D *h_[6];
  h_[0] = (TH1D*)hz->Clone("Zin");
  h_[1] = (TH1D*)hl->Clone("LL");
  h_[2] = (TH1D*)hf->Clone("FR");
  h_[3] = (TH1D*)hq->Clone("QCD");
  h_[4] = (TH1D*)hT->Clone("TotalBG");
  h_[5] = (TH1D*)hd->Clone("DataFit");

  THStack *hs_var=new THStack("var_Stack",catName);


  vector<string> binBound = {"$200-250$","$250-300$","$300-350$","$350-400$","$400-450$","$450-500$","$500-600$","$600-800$","$\\geq 800$"};
    //    cout<<"Rare\t\t\t\t\t&\tTop\t\t\t\t\t&\tNonresonant\t\t\t\t\t&\tTotal\t\t\t\t\t&\tData\t&\tPull"<<endl;
    //    cout<<"\\ptmiss  &  Rare  &  Top  &  Nonresonant  &  Total  &  Observation  &  Pull  &  Signal\\\\ \\hline"<<endl;
  cout<<"Bin | Zin | LL | FR | QCD| Total |  Observation  |  Data/Pred | Pull"<<endl;
  for(int b=1;b<=hz->GetNbinsX();b++){
    char name3[10000];
    if(hT->GetBinContent(b) > 1e-9){
      float pull = (hd->GetBinContent(b) - hT->GetBinContent(b))/sqrt(hT->GetBinError(b)*hT->GetBinError(b) + hd->GetBinError(b)*hd->GetBinError(b));
      cout<<b<<" | "
	  <<hz->GetBinContent(b)<<" "<<hz->GetBinError(b)<<" | "
	  <<hl->GetBinContent(b)<<" "<<hl->GetBinError(b)<<" | "
	  <<hf->GetBinContent(b)<<" "<<hf->GetBinError(b)<<" | "
	  <<hq->GetBinContent(b)<<" "<<hq->GetBinError(b)<<" | "
	  <<hT->GetBinContent(b)<<" "<<hT->GetBinError(b)<<" | "
	  <<hd->GetBinContent(b)<<" | "
	  <<hd->GetBinContent(b)/hT->GetBinContent(b)<<" | "
	  <<pull<<endl;
   
    }
  }
  double hz_MET[6][6], herr_MET[6][6];
  vector<double> METLowEdge={200,300,370,450,600,2000};
  TH1D *h_METvBin[6];
  h_METvBin[0]=new TH1D("z_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin[1]=new TH1D("l_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin[2]=new TH1D("f_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin[3]=new TH1D("q_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin[4]=new TH1D("t_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin[5]=new TH1D("d_METvBin","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));

  double ymin=0.01 , ymax=1.99, ymin_=0.5 , ymax_=100000,ymax2_=1000, yset_=200;

  for(int i=0; i<6; i++)
    {
      if(catName=="MET"){
    
	hz_MET[i][0] = h_[i]->GetBinContent(1)+h_[i]->GetBinContent(8)+h_[i]->GetBinContent(14)+h_[i]->GetBinContent(19)+h_[i]->GetBinContent(24)+h_[i]->GetBinContent(29)+h_[i]->GetBinContent(34)+h_[i]->GetBinContent(40);
	
	hz_MET[i][1] = h_[i]->GetBinContent(2)+h_[i]->GetBinContent(9)+h_[i]->GetBinContent(15)+h_[i]->GetBinContent(20)+h_[i]->GetBinContent(25)+h_[i]->GetBinContent(30)+h_[i]->GetBinContent(35)+h_[i]->GetBinContent(41);

	hz_MET[i][2] = h_[i]->GetBinContent(3)+h_[i]->GetBinContent(10)+h_[i]->GetBinContent(16)+h_[i]->GetBinContent(21)+h_[i]->GetBinContent(26)+h_[i]->GetBinContent(31)+h_[i]->GetBinContent(36)+h_[i]->GetBinContent(42);
	
	hz_MET[i][3] = h_[i]->GetBinContent(4)+h_[i]->GetBinContent(11)+h_[i]->GetBinContent(17)+h_[i]->GetBinContent(22)+h_[i]->GetBinContent(27)+h_[i]->GetBinContent(32)+h_[i]->GetBinContent(37)+h_[i]->GetBinContent(43);
	hz_MET[i][4] = h_[i]->GetBinContent(5)+h_[i]->GetBinContent(6)+h_[i]->GetBinContent(7)+h_[i]->GetBinContent(12)+h_[i]->GetBinContent(13)+h_[i]->GetBinContent(18)+h_[i]->GetBinContent(23)+h_[i]->GetBinContent(28)+h_[i]->GetBinContent(33)+h_[i]->GetBinContent(38)+h_[i]->GetBinContent(39)+h_[i]->GetBinContent(44)+h_[i]->GetBinContent(45);


	h_METvBin[i]->Fill(METLowEdge[0],hz_MET[i][0]);
        h_METvBin[i]->Fill(METLowEdge[1],hz_MET[i][1]);
        h_METvBin[i]->Fill(METLowEdge[2],hz_MET[i][2]);
        h_METvBin[i]->Fill(METLowEdge[3],hz_MET[i][3]);
        h_METvBin[i]->Fill(METLowEdge[4],hz_MET[i][4]);
	if(i==4 || i==5){
	  herr_MET[i][0] = pow(pow(h_[i]->GetBinError(1),2) + pow(h_[i]->GetBinError(8),2) + pow(h_[i]->GetBinError(14),2)+ pow(h_[i]->GetBinError(19),2) + pow(h_[i]->GetBinError(24),2) + pow(h_[i]->GetBinError(29),2) + pow(h_[i]->GetBinError(34),2) + pow(h_[i]->GetBinError(40),2) ,0.5);
	  cout<<herr_MET[i][0]<<endl;
	  herr_MET[i][1] = pow(pow(h_[i]->GetBinError(2),2) + pow(h_[i]->GetBinError(9),2) + pow(h_[i]->GetBinError(15),2)+ pow(h_[i]->GetBinError(20),2) + pow(h_[i]->GetBinError(25),2) + pow(h_[i]->GetBinError(30),2) + pow(h_[i]->GetBinError(35),2) + pow(h_[i]->GetBinError(41),2) ,0.5);

          herr_MET[i][2] = pow(pow(h_[i]->GetBinError(3),2) + pow(h_[i]->GetBinError(10),2) + pow(h_[i]->GetBinError(16),2)+ pow(h_[i]->GetBinError(21),2) + pow(h_[i]->GetBinError(26),2) + pow(h_[i]->GetBinError(31),2) + pow(h_[i]->GetBinError(36),2) + pow(h_[i]->GetBinError(42),2) ,0.5);
          herr_MET[i][3] = pow(pow(h_[i]->GetBinError(4),2) + pow(h_[i]->GetBinError(11),2) + pow(h_[i]->GetBinError(17),2)+ pow(h_[i]->GetBinError(22),2) + pow(h_[i]->GetBinError(27),2) + pow(h_[i]->GetBinError(32),2) + pow(h_[i]->GetBinError(37),2) + pow(h_[i]->GetBinError(43),2) ,0.5);
          herr_MET[i][4] = pow(pow(h_[i]->GetBinError(5),2) + pow(h_[i]->GetBinError(6),2) + pow(h_[i]->GetBinError(7),2) + pow(h_[i]->GetBinError(12),2) + pow(h_[i]->GetBinError(13),2) + pow(h_[i]->GetBinError(18),2)+ pow(h_[i]->GetBinError(23),2) + pow(h_[i]->GetBinError(28),2) + pow(h_[i]->GetBinError(33),2) + pow(h_[i]->GetBinError(38),2) + pow(h_[i]->GetBinError(39),2) + pow(h_[i]->GetBinError(44),2)+ pow(h_[i]->GetBinError(45),2)  ,0.5);
	  if(i==5) herr_MET[i][4] = pow(pow(h_[i]->GetBinError(5),2) + pow(h_[i]->GetBinError(6),2) + pow(h_[i]->GetBinError(7),2) + pow(h_[i]->GetBinError(12),2) + pow(1.8,2) + pow(h_[i]->GetBinError(18),2)+ pow(h_[i]->GetBinError(23),2) + pow(h_[i]->GetBinError(28),2) + pow(h_[i]->GetBinError(33),2) + pow(h_[i]->GetBinError(38),2) + pow(h_[i]->GetBinError(39),2) + pow(h_[i]->GetBinError(44),2)+ pow(h_[i]->GetBinError(45),2)  ,0.5);
	  h_METvBin[i]->SetBinError(1,herr_MET[i][0]);
          h_METvBin[i]->SetBinError(2,herr_MET[i][1]);
          h_METvBin[i]->SetBinError(3,herr_MET[i][2]);
          h_METvBin[i]->SetBinError(4,herr_MET[i][3]);
          h_METvBin[i]->SetBinError(5,herr_MET[i][4]);

	}
      }
    }


  gStyle->SetOptStat(0);
  TCanvas *c1= new TCanvas("stackhist","stackhist",1600,1000);
  TPad *pad1 = new TPad("pad1","pad1",0,0,1,1);

  pad1->SetBottomMargin(0.355);
  pad1->SetRightMargin(0.03);
  pad1->Draw();pad1->SetGridx(0);

  pad1->cd();
  pad1->SetLogy();

  
  decorate(h_METvBin[3],3,f->GetName());
  decorate(h_METvBin[0],0,f->GetName());
  decorate(h_METvBin[1],1,f->GetName());
  decorate(h_METvBin[2],2,f->GetName());

  hs_var->Add(h_METvBin[0]);
  hs_var->Add(h_METvBin[1]);
  hs_var->Add(h_METvBin[2]);
  hs_var->Add(h_METvBin[3]);

  hs_var->Draw("hist");
  hs_var->GetYaxis()->SetLabelSize(0.05);
  hs_var->SetTitle(0);
  hs_var->GetYaxis()->SetTitle("Events");
  hs_var->GetXaxis()->SetTitle(0);
  hs_var->GetYaxis()->SetTitleSize(0.05);
  hs_var->GetYaxis()->SetTitleOffset(0.86);


  hs_var->SetMinimum(ymin_);
  hs_var->SetMaximum(ymax_);
  h_METvBin[5]->SetMarkerStyle(20);
  h_METvBin[5]->SetMarkerSize(1.2);
  h_METvBin[5]->SetMarkerColor(kBlack);
  h_METvBin[5]->SetLineColor(kBlack);
  h_METvBin[5]->SetLineWidth(2);

  h_METvBin[4]->SetFillColor(kGray+6);
  h_METvBin[4]->SetFillStyle(3013);
  h_METvBin[4]->Draw("e2 same");  
  h_METvBin[5]->Draw("ep same");
  h_METvBin[4]->Print("all");
  TH1D *predsys = (TH1D*)h_METvBin[4]->Clone("predsys");
  for(int i=1; i<6;i++)
    {
     predsys->SetBinError(i,h_METvBin[4]->GetBinError(i)/h_METvBin[4]->GetBinContent(i));
     predsys->SetBinContent(i,1);
    }
  for(int i=1; i<h_METvBin[4]->GetNbinsX();i++)
    {
      h_METvBin[4]->SetBinError(i,0);
    }
  h_[4]->Print("all");
  TH1D *h4 = (TH1D*)h_METvBin[4]->Clone("h4");
  TH1D *h3 = (TH1D*)h_METvBin[5]->Clone("h3");
  TPad *pad2 = new TPad("pad1","pad1",0,0.0,1,0.35);
  pad2->Draw();
  pad2->SetTopMargin(0);
  pad2->SetBottomMargin(0.3);
  pad2->SetRightMargin(0.03);
  pad2->cd();
  pad2->SetGrid(0);
  h3->GetYaxis()->SetNdivisions(5);
  h3->GetYaxis()->SetRangeUser(0,2.5);
  h3->GetYaxis()->SetTitleOffset(0.34);
  h3->GetYaxis()->SetTitleSize(0.13);
  h3->GetYaxis()->SetLabelSize(0.13);
  h3->GetYaxis()->CenterTitle();
  h3->SetLineColor(kBlack);
  h3->SetMinimum(ymin);  // Define Y ..                                                                                                       
  h3->SetMaximum(ymax); // .. range                                                                                                           
  h3->Sumw2();
  h3->SetStats(0);      // No statistics on lower plot                                                                                        
  h3->Divide(h4);
  h3->SetMarkerStyle(20);
  h3->SetMarkerSize(0.95);

  h3->Draw("ep");       // Draw the ratio plot                                                                                                
  predsys->SetFillStyle(3244);
  predsys->SetMarkerColor(kGray+1);
  predsys->SetFillColor(kGray+1);
  predsys->Draw("E2 sames");
  h3->Draw("ep sames");

  h3->SetTitle(0);
  h3->GetXaxis()->SetTitle(catName);
  h3->GetXaxis()->SetLabelSize(0.13);
  h3->GetYaxis()->SetTitle("#frac{Data}{Simulation}");
  
  //  TLine *line= new TLine(xmin_,1.0,xmax_,1.0);
  
  // line->SetLineColor(1);
  //  line->SetLineWidth(2);
  //  line->Draw();
  


}


TString getLegName(TString fname){
  if(fname.Contains("TTJets")) return "t#bar{t}";
  else if(fname.Contains("WJets")) return "W+Jets";
  else if(fname.Contains("ZJets")) return "Z+Jets";
  else if(fname.Contains("Rare")) return "Rare";
  else if(fname.Contains("ST__")) return "Single t";
  else if(fname.Contains("Nonres")) return "0-res";
  else if(fname.Contains("Top")) return "Top";
  else if(fname.Contains("TChiWH_800_100")) return "TChiWH (800, 100)";
  else if(fname.Contains("TChiWZ_800_100")) return "TChiWZ (800, 100)";
  else if(fname.Contains("TChiWW_800_100")) return "TChiWW (800, 100)";
  else if(fname.Contains("TChiWH_900_1")) return "TChiWH (900, 1)";
  else if(fname.Contains("TChiHZ_900_1")) return "TChiHZ (900, 1)";
  else if(fname.Contains("TChiWH_1000_100")) return "TChiWH (1000, 100)";
  else if(fname.Contains("TChiWZ_1000_100")) return "TChiWZ (1000, 100)";  
  else if(fname.Contains("T5bbbbZg_2200_2100")) return "T5bbbbZg (2200, 2100)";
  else if(fname.Contains("T5bbbbZg_2200_200")) return "T5bbbbZg (2200, 200)";
  else if(fname.Contains("T5bbbbZg_2250_200")) return "T5bbbbZg (2250, 200)";
  else if(fname.Contains("T5bbbbZg_2250_1600")) return "T5bbbbZg (2250, 1600)";
  else if(fname.Contains("T5bbbbZg_2250_2150")) return "T5bbbbZg (2250, 2150)";
  else if(fname.Contains("T5bbbbZg_2250_2100")) return "T5bbbbZg (2250, 2100)";
  else if(fname.Contains("T5qqqqHg_2250_200")) return "T5qqqqHg (2250, 200)";
  else if(fname.Contains("T5qqqqHg_2250_1000")) return "T5qqqqHg (2250, 1000)";
  else if(fname.Contains("T5qqqqHg_2250_1600")) return "T5qqqqHg (2250, 1600)";
  else if(fname.Contains("T5qqqqHg_2250_2150")) return "T5qqqqHg (2250, 2150)";
  else if(fname.Contains("T5ttttZg_2200_200")) return "T5ttttZg (2200, 200)";
  else if(fname.Contains("T5ttttZg_2200_1000")) return "T5ttttZg (2200, 1000)";
  else if(fname.Contains("T5ttttZg_2200_1975")) return "T5ttttZg (2200, 1975)";
  else if(fname.Contains("T6ttZg_1300_200")) return "T6ttZg (1300, 200)";
  else if(fname.Contains("T6ttZg_1300_600")) return "T6ttZg (1300, 600)";
  else if(fname.Contains("T6ttZg_1300_1200")) return "T6ttZg (1300, 1200)";

  else if(fname.Contains("TChiWG_0_600")) return "TChiWG (0, 600)";
  else if(fname.Contains("TChiWG_0_1000")) return "TChiWG (0, 1000)";
  else if(fname.Contains("TChiWG_0_1200")) return "TChiWG (0, 1200)";
  else if(fname.Contains("TChiNG_0_600")) return "TChiNG (0, 600)";
  else if(fname.Contains("TChiNG_0_1000")) return "TChiNG (0, 1000)";
  else if(fname.Contains("TChiNG_0_1200")) return "TChiNG (0, 1200)";
  else if(fname.Contains("TChiNGnn_0_500")) return "TChiNGnn (0, 500)";
  else if(fname.Contains("TChiNGnn_0_600")) return "TChiNGnn (0, 600)";
  else if(fname.Contains("TChiNGnn_0_700")) return "TChiNGnn (0, 700)";

  else return fname;
}
TString getXaxisName(TString axname){
  if(axname.Contains("NJets")) return "N_{Jets}";
  else if(axname.Contains("HT")) return "HT(GeV)";
  else if(axname.Contains("BTags")) return "b tags";
  else if(axname.Contains("ElePt")) return "e pT(GeV)";
  else if(axname.Contains("MuPt")) return "#mu pT(GeV)";
  else if(axname.Contains("MuEta")) return "#mu #eta";
  else if(axname.Contains("PhotonPt")) return "#gamma pT(GeV)";
  else if(axname.Contains("PhotonEta")) return "#gamma #eta";
  else if(axname.Contains("PhotonPhi")) return "#gamma #Phi";
  else if(axname.Contains("mTLep")) return "mT(l,p_{T}^{miss})(GeV)";
  else if(axname.Contains("dR_MuPho")) return "#DeltaR(#mu,#gamma)";
  else if(axname.Contains("AllSBin")) return "Bin Number";
  else if(axname.Contains("nVtx")) return "No. of primary vertices";
  else if(axname.Contains("dPhi_METjet1") || axname.Contains("dphi1_METjet1")) return "#Delta#Phi_{1}";
  else if(axname.Contains("dPhi_METjet2") || axname.Contains("dphi2_METjet2")) return "#Delta#Phi_{2}";
  else if(axname.Contains("dPhi_METBestPhoton") ) return "#Delta#Phi(MET,#gamma)";
  else if(axname.Contains("dPhi_Muon_Photon") ) return "#Delta#Phi(#mu,#gamma)";
  else if(axname.Contains("QMut") || axname.Contains("Qmut")) return "QMult";
  else if(axname.Contains("MT_Mu")) return "mT(#mu,p_{T}^{miss})(GeV)";
  else if(axname.Contains("METPhi")) return "p_{T}^{miss} #phi";
  else if(axname.Contains("MET")) return "p_{T}^{miss}(GeV)";
  else return axname;

}

void setMyRange(TH1D *h1,double xLow,double xHigh){
  double err=0;
  if(xHigh > 13000) return;
  if(xLow < 13000) return;
  int nMax=h1->FindBin(xHigh);
  h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  h1->SetBinError(nMax,err);
  for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
    h1->SetBinContent(i,0);
    h1->SetBinError(i,0);
  }
  //  h1->GetXaxis()->SetRangeUser(xLow,xHigh);
}
void setMyRange(THStack *h1,double xLow,double xHigh){
  // double err=0;
  // if(xHigh > 13000) return;
  // int nMax=h1->FindBin(xHigh);
  // h1->SetBinContent(nMax,h1->IntegralAndError(nMax,h1->GetNbinsX(),err));
  // h1->SetBinError(nMax,err);
  // for(int i=nMax+1;i<=h1->GetNbinsX()+1;i++){
  //   h1->SetBinContent(i,0);
  //   h1->SetBinError(i,0);
  // }
  //h1->GetXaxis()->SetRangeUser(xLow,xHigh);
}

void set0PredSmall(TH1D* h, double val){
  double err=1.0;
  for(int i=1;i<=h->GetNbinsX();i++){
    if(h->GetBinContent(i) < 0.000001){
      err = h->GetBinError(i);
      cout<<"************* To make hashed errors visible, setting 0 pred bin "<<i<<" a value of "<<val<<" for hist "<<h->GetName()<<endl;
      h->SetBinContent(i,val);
      h->SetBinError(i,err);
      cout<<h->GetBinContent(i)<<" "<<h->GetBinError(i)<<" | ";
    }
  }
}
void setLastBinAsOverFlow(TH1D* h_hist){
  double lastBinCt =h_hist->GetBinContent(h_hist->GetNbinsX()),overflCt =h_hist->GetBinContent(h_hist->GetNbinsX()+1);
  double lastBinErr=h_hist->GetBinError(h_hist->GetNbinsX()),  overflErr=h_hist->GetBinError(h_hist->GetNbinsX()+1);

  lastBinCt = lastBinCt+overflCt;
  lastBinErr = sqrt( (lastBinErr*lastBinErr) + (overflErr*overflErr) );
  
  h_hist->SetBinContent(h_hist->GetNbinsX(),lastBinCt);
  h_hist->SetBinError(h_hist->GetNbinsX(),lastBinErr);
    
}
void decorate(TH1D* hist,int i,const char* fname){
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
