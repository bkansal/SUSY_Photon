#ifndef Mulijet_H
#define Mulijet_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "NtupleVariables.h"
#include "TH1F.h"
#include "TH2.h"
#include "TH3.h"
#include <TProfile.h>
#include "TFile.h"
#include "TLorentzVector.h"
#include "TDirectory.h"
#include"TGraphErrors.h"
#include"TGraphAsymmErrors.h"

class Mulijet : public NtupleVariables{

 public:
  Mulijet(const TString &inputFileList="foo.txt", const char *outFileName="histo.root",const char *dataset="data");
  ~Mulijet();
  Bool_t   FillChain(TChain *chain, const TString &inputFileList);
  Long64_t LoadTree(Long64_t entry);
  void     EventLoop(const char *,const char *);
  void     BookHistogram(const char *);
  TLorentzVector getBestPhoton();
  TLorentzVector getBestPhoton_0();
  TLorentzVector getPhoton_withoutfullID();
  int getBinNoV4(int);
  int getBinNoV7(TLorentzVector, double, double);
  //  int getBinNoV7_closure(int,TFile);
  int getBinNoV7_v1(int);
  //  int getBinNoV6(int);
 int getBinNoV6(TLorentzVector, int);
  int getBinNoV6_EW(bool,bool,double);
  int getBinNoV6_SP(bool,bool,bool,bool,int,int,double);
  int getBinNoV6_EW1(bool);
  int getBinNoV6_EWplusSP_SR(bool,bool,bool,bool,int,int,double);
  int getBinNoV6_EWplusSP_CR(bool,bool,bool,bool,int,int,double);
  int getBinNoV7_le(int,int);
  int getBinNoV7_le2(bool,bool,bool,bool,int,int);
  void storeBTagEff();
  
  double getGendRLepPho();
  bool check_eMatchedtoGamma(TLorentzVector);
  bool check_muMatchedtoGamma(TLorentzVector);
  void print(Long64_t);
  void findObjMatchedtoG(TLorentzVector);
  double getGenLep(TLorentzVector);
  
  //Variables defined
  int bestPhotonIndxAmongPhotons=-100;
  int eIndxAmongPhotons=-100;
  float HT_PtCut=30;
  float MHT_PtCut=30;//keep MHT_PtCut <= HT_PtCut and <= Njets_PtCut
  float Njets_PtCut=30;

  float HT_EtaCut=2.4;
  float MHT_EtaCut=5;
  float Njets_EtaCut=2.4;
  double deepCSVvalue = 0;
  double deepCSVWP = 0.0;
  double wt=0,wt2=0,lumiInfb=59.546;//41.486;//35.9;//35.86;//36.814;//35.862824;//36.814;
  bool isSignal=false;
  //vector<double> HTBinLowEdge ={0,500,550,600,650,700,750,800,900,1000,1100,1200,1400,1600,1800,2000,2400,2800,3200};
  //  vector<double> HTBinLowEdge ={0,100,200,300,400,500,600,700,800,900,1000,1200,1500,2000,2500};
  //  vector<double> MHTBinLowEdge={0,20,40,60,80,100,120,160,200,270,350,500};
  vector<double> STBinLowEdge ={0,200,220,240,260,300,360,420,500,600,700,850,1000,1200,1500,2000,2500,3000};
  // vector<double> METLowEdge={0,20,40,60,80,100,120,160,200,220,240,260,300,340,380,420,480,520,560,600,660,720,800,900,1000,1200};
  vector<double> METLowEdge={200,270,350,450,750,2000};
  vector<double> METLowEdge1={100,200,270,350,450,750,2000};
  vector<double> METLowEdge3={250,270,350,450,750,2000};
  vector<double> METLowEdge2={100,200,270,350,450,2000};

  vector<double> METLowEdge_v1={100,250,270,350,450,600,750,900,2000};
  //  vector<double> METLowEdge_v2={200,250,300,370,450,600,750,900,2000};
  // vector<double> METLowEdge_v2_1={200,250,300,370,450,600,750,2000};
  vector<double> METLowEdge_v2={100,200,270,350,450,750,2000};
  vector<double> METLowEdge_v2_1={100,200,270,350,450,2000};  
  vector<double> METLowEdge_v3={200,300,370,450,600,750,900,2000};
  vector<double> METLowEdge_v3_1={200,300,370,450,600,750,2000};
  vector<double> METLowEdge_v3_2={200,300,370,450,600,2000};
  vector<float> xbins = {20,30,40,50,60,70,80,100,120,160,210,260,320,400,500,600,800,99999}, ybins = {0.0,0.8,1.6,2.4};


  /* vector<double> METLowEdge1={200,270,350,450,750,2000}; */
  /* vector<double> METLowEdge2={200,270,350,450,2000}; */
  // vector<double> METLowEdge1={0,20,40,60,80,100,120,160,200,220,240,260,300,340,380,420,460,520,580,640,700,780,860,940,1000,1200};
  // vector<double> METLowEdge2={0,20,40,60,80,100,120,160,200,220,240,260,280,300,340,380,420,480,540,600,700,800,900,1000,1200};
  // vector<double> METLowEdge={0,200,210,220,240,260,280,300,320,340,360,380,400,450,500,600,1000,1400};
  vector<double> METBinLowEdgeV4_njLow={0,100,125,160,200,270,350,450,750,900};//{0,100,200,270,350,450,750,900}; 
  vector<double> METBinLowEdgeV4={0,100,125,160,200,270,350,450,750};
  vector<double> METBinLowEdgeV7_njLow={0,100,200,270,350,450,750,900};
  vector<double> METBinLowEdgeV7={0,100,200,270,350,450,750};
  vector<double> Ak8_vMass_EW={30,65,105,200};

  vector<double> METBinLowEdge={0,20,40,60,80,100,125,160,200,270,350,500,600};
  vector<double> METBinLowEdge2bJ={0,20,40,60,80,100,125,160,200,270,350,500};
  vector<double> METBinLowEdge2={0,20,40,60,80,100,120,160,200,270,350,450,500};
  vector<double> PhoLowEdge={0,100,120,140,160,180,200,220,250,280,320,380,450,550,650,750};
  vector<double> PhoLowEdge1={0,100,120,140,160,180,200,220,250,280,320,380,450,550,650,750,800,1000,1200};
  vector<double> PhoLowEdge2={0,100,120,140,160,180,200,220,250,280,320,380,450,550,650,750,800,900,1000,1100,1200};

  vector<double> QMultLowedge={0,2,4,7,100};//Qmultibin
  //  vector<double> QMultLowedge={0,2,4,8,10,100};//Qmultibin1 v1
  // vector<double> QMultLowedge={0,2,4,6,8,10,14,100};//Qmultibin2 
  vector<double> QMultLowedge_v2={0,2,4,6,8,10,100};//Qmultibin2 v1
  //vector<double> QMultLowedge={0,2,4,7,10,50};////Qmultibin2 
  //  vector<double> QMultLowedge={0,2,5,7,10,15,20,100};
  //  vector<double>  nJetsLowedge={2,4,7,10,20};
  vector<double>  nJetsLowedgev1={2,5,20};
  vector<double>  nJetsLowedge={2,5,20};
  vector<double>  nbtagsLowedge={0,1,10};
  vector<double>  EMEtaLowedge={-3.5,-1.5,-1,-0.5,0,0.5,1,1.5,3.5};

  vector<double>  njets={2,3,4,5,6,7,20};
  vector<double>  njets2={2,5,7,20};
  vector<double> metbin={200,300,10000};
  //  vector<double> BestPhotonPtBinLowEdge={100,120,140,160,180,200,230,260,300,380,500,600,1000};
  vector<double> BestPhotonPtBinLowEdge={100,120,140,160,180,200,220,240,260,300,400,600,1000};
  //  vector<double> ptlow2={100,120,140,160,180,200,230,260,300,380,450,600};//phoptbin1
  //  vector<double> ptlow2={100,120,140,160,180,200,230,260,300,380,450,600};//phoptbin1
  vector<double> ptlow2={100,120,140,160,200,240,300,450,600};//phoptbin2 v1
  vector<double> ptlow2_v2={300,330,380,450,600,2000};//phoptbin2 v2
  // vector<double> ptlow2={100,120,140,160,180,200,220,240,260,280,300};//phoptbin3 v1
  // vector<double> ptlow2_v2={300,340,380,420,480,600,2000};//phoptbin3 v2
  double QMultLow[6]={0,2,4,7,100};
  vector<TLorentzVector> allBestPhotons;
  //histograms

  TH1D *h_ST_A;
  TH1D *h_MET_A;
  TH1D *h_nJets_A;
  TH1D *h_BTags_A;
  TH1D *h_BestPhotonPt_A;
  TH1D *h_BestPhotonPhi_A;
  TH1D *h_BestPhotonEta_A;
  TH2D *h2_MET_dPhiMETj1_A;
  TH2D *h2_MET_dPhiMETj2_A;
  TH2D *h2_MET_dPhiMETj_A;
  TH1D *h_dPhi_METjet1_A;
  TH1D *h_dPhi_METjet2_A;
  TH1D *h_dPhi_METjet3_A;
  TH1D *h_dPhi_METjet4_A;
  TH1D *h_dPhi_phojet1_A;
  TH1D *h_dPhi_phojet2_A;
  TH1D *h_dPhi_phojet3_A;
  TH1D *h_dPhi_phojet4_A;
  TH1D *h_JetPt_A;
  TH1D *h_JetPhi_A;
  TH1D *h_JetEta_A;
  TH1D *h_mindphi1dphi2;

  TH1D *h_dPhi_phoMET_B;
  TH1D *h_mindphi1dphi2_B;
  TH1D *h_JetPt1_B;
  TH1D *h_JetPhi1_B;
  TH1D *h_JetEta1_B;
  TH1D *h_JetPt2_B;
  TH1D *h_JetPhi2_B;
  TH1D *h_JetEta2_B;
  TH1D *h_JetPt3_B;
  TH1D *h_JetPhi3_B;
  TH1D *h_JetEta3_B;
  TH1D *h_JetPt4_B;
  TH1D *h_JetPhi4_B;
  TH1D *h_JetEta4_B;

  TH1D *h_dPhi_phoMET_C;
  TH1D *h_mindphi1dphi2_C;
  TH1D *h_JetPt1_C;
  TH1D *h_JetPhi1_C;
  TH1D *h_JetEta1_C;
  TH1D *h_JetPt2_C;
  TH1D *h_JetPhi2_C;
  TH1D *h_JetEta2_C;
  TH1D *h_JetPt3_C;
  TH1D *h_JetPhi3_C;
  TH1D *h_JetEta3_C;
  TH1D *h_JetPt4_C;
  TH1D *h_JetPhi4_C;
  TH1D *h_JetEta4_C;

  TH1D *h_dPhi_phoMET_D;
  TH1D *h_mindphi1dphi2_D;
  TH1D *h_JetPt1_D;
  TH1D *h_JetPhi1_D;
  TH1D *h_JetEta1_D;
  TH1D *h_JetPt2_D;
  TH1D *h_JetPhi2_D;
  TH1D *h_JetEta2_D;
  TH1D *h_JetPt3_D;
  TH1D *h_JetPhi3_D;
  TH1D *h_JetEta3_D;
  TH1D *h_JetPt4_D;
  TH1D *h_JetPhi4_D;
  TH1D *h_JetEta4_D;

  TH1D *h_dPhi_phoMET_A;
  TH1D *h_mindphi1dphi2_A;
  TH1D *h_JetPt1_A;
  TH1D *h_JetPhi1_A;
  TH1D *h_JetEta1_A;
  TH1D *h_JetPt2_A;
  TH1D *h_JetPhi2_A;
  TH1D *h_JetEta2_A;
  TH1D *h_JetPt3_A;
  TH1D *h_JetPhi3_A;
  TH1D *h_JetEta3_A;
  TH1D *h_JetPt4_A;
  TH1D *h_JetPhi4_A;
  TH1D *h_JetEta4_A;

  TH2D *h2_JetEta_Pt_A;
  TH2D *h2_JetEta_Phi_A;
  TH1D *h_SBins_v6_CD_EW_7bin_A;
  TH1D *h_SBins_v7_CD_SP_A;
  TH1D *h_SBins_v7_CD_SP_CA;
  TH1D *h_SBins_v7_CD_SP_BD;
  TH2D *h2_nJetsMET_A;
  TH2D *h2_nJetsMET_v2_A;
  TH1D *h_SBins_v6_CD_EW_50bin_A;
  TH1D *h_SBins_v6_CD_EW_50bin_AB;
  TH1D *h_SBins_v6_CD_EW_50bin_CD;

  TH1D *h_SBins_v6_CD_A;
  TH1D *h_ST_B;
  TH1D *h_MET_B;
  TH1D *h_nJets_B;
  TH1D *h_BTags_B;
  TH1D *h_BestPhotonPt_B;
  TH1D *h_BestPhotonPhi_B;
  TH1D *h_BestPhotonEta_B;
  TH2D *h2_MET_dPhiMETj1_B;
  TH2D *h2_MET_dPhiMETj2_B;
  TH2D *h2_MET_dPhiMETj_B;
  TH1D *h_dPhi_METjet1_B;
  TH1D *h_dPhi_METjet2_B;
  TH1D *h_dPhi_METjet3_B;
  TH1D *h_dPhi_METjet4_B;
  TH1D *h_dPhi_phojet1_B;
  TH1D *h_dPhi_phojet2_B;
  TH1D *h_dPhi_phojet3_B;
  TH1D *h_dPhi_phojet4_B;
  TH1D *h_JetPt_B;
  TH1D *h_JetPhi_B;
  TH1D *h_JetEta_B;
  TH2D *h2_JetEta_Pt_B;
  TH2D *h2_JetEta_Phi_B;
  TH1D *h_SBins_v6_CD_EW_7bin_B;
  TH1D *h_SBins_v7_CD_SP_B;
  TH2D *h2_nJetsMET_B;
  TH2D *h2_nJetsMET_v2_B;
  TH1D *h_SBins_v6_CD_EW_50bin_B;
  TH1D *h_SBins_v6_CD_B;
  TH1D *h_nJetsMET_P;
  TH1D *h_nJetsMET_Q;
  TH1D *h_nJetsMET_R;
  TH1D *h_nJetsMET_S;

  TH1D *h_ST_C;
  TH1D *h_MET_C;
  TH1D *h_nJets_C;
  TH1D *h_BTags_C;
  TH1D *h_BestPhotonPt_C;
  TH1D *h_BestPhotonPhi_C;
  TH1D *h_BestPhotonEta_C;
  TH2D *h2_MET_dPhiMETj1_C;
  TH2D *h2_MET_dPhiMETj2_C;
  TH2D *h2_MET_dPhiMETj_C;
  TH1D *h_dPhi_METjet1_C;
  TH1D *h_dPhi_METjet2_C;
  TH1D *h_dPhi_METjet3_C;
  TH1D *h_dPhi_METjet4_C;
  TH1D *h_dPhi_phojet1_C;
  TH1D *h_dPhi_phojet2_C;
  TH1D *h_dPhi_phojet3_C;
  TH1D *h_dPhi_phojet4_C;
  TH1D *h_JetPt_C;
  TH1D *h_JetPhi_C;
  TH1D *h_JetEta_C;
  TH2D *h2_JetEta_Pt_C;
  TH2D *h2_JetEta_Phi_C;
  TH1D *h_SBins_v6_CD_EW_7bin_C;
  TH1D *h_SBins_v7_CD_SP_C;
  TH2D *h2_nJetsMET_C;
  TH2D *h2_nJetsMET_v2_C;
  TH1D *h_SBins_v6_CD_EW_50bin_C;
  TH1D *h_SBins_v6_CD_C;

  TH1D *h_ST_D;
  TH1D *h_MET_D;
  TH1D *h_nJets_D;
  TH1D *h_BTags_D;
  TH1D *h_BestPhotonPt_D;
  TH1D *h_BestPhotonPhi_D;
  TH1D *h_BestPhotonEta_D;
  TH2D *h2_MET_dPhiMETj1_D;
  TH2D *h2_MET_dPhiMETj2_D;
  TH2D *h2_MET_dPhiMETj_D;
  TH1D *h_dPhi_METjet1_D;
  TH1D *h_dPhi_METjet2_D;
  TH1D *h_dPhi_METjet3_D;
  TH1D *h_dPhi_METjet4_D;
  TH1D *h_dPhi_phojet1_D;
  TH1D *h_dPhi_phojet2_D;
  TH1D *h_dPhi_phojet3_D;
  TH1D *h_dPhi_phojet4_D;
  TH1D *h_JetPt_D;
  TH1D *h_JetPhi_D;
  TH1D *h_JetEta_D;
  TH2D *h2_JetEta_Pt_D;
  TH2D *h2_JetEta_Phi_D;
  TH1D *h_SBins_v6_CD_EW_7bin_D;
  TH1D *h_SBins_v7_CD_SP_D;
  TH2D *h2_nJetsMET_D;
  TH2D *h2_nJetsMET_v2_D;
  TH1D *h_SBins_v6_CD_EW_50bin_D;
  TH1D *h_SBins_v6_CD_D;

  TH1D *h_nvtx;
  TH1D *h_nEvts;
  TH1I *h_RunNum;
  TH1D *h_intLumi;
  TH1D *h_ST;
  TH2D *h2_MET_nJets;
  TH2D *h2_MET_elepT;
  TH2D *h2_METvBin2_nJets;
  TH2D *h2_nbjets_nJets;
  TH1D *h_MET;
  TH1D *h_METPhi;
  TH1D *h_METvBin;
  TH1D *h_METvBin2;  
  TH1D *h_BTags;
  TH1D *h_nJets;
  TH1D *h_nremJets;
  TH1D *h_BestPhotonPt;
  TH1D *h_BestPhotonPt_vBin;
  TH1D *h_BestPhotonPt_0b;
  TH1D *h_BestPhotonPt_ge1b;
  TH1D *h_BestPhotonPt_0b_vBin;
  TH1D *h_BestPhotonPt_ge1b_vBin;
  TH1D *h_BestPhotonPhi;
  TH1D *h_BestPhotonEta;
  TH2D *h2_BestPhotonEta_Qmulti;
  TH2D *h2_BestPhotonEta_nJets;
  TH2D *h2_BestPhotonEta_MET;
  TH1D *h_minDr_bestphoEle;
  TH1D *h_minDr_bestphoJets;
  TH1D *h_minDr_bestphoremEle;
  TH1D *h_minDphi_bestphoJets;
  TH1D *h_minDr_bestphoremJets;
  TH1D *h_dRgenl1recol1;
  TH1D *h_dRgenl2recol2;
  TH2D *h2_dRgenl1recol1_PID;
  TH1D *h_genzMass;
  TH1D *h_NEMobj;
  TH1D *h_ElectronPt;
  TH1D *h_ElectronPhi;
  TH1D *h_ElectronEta;
  TH1D *h_JetPt;
  TH1D *h_JetPhi;
  TH1D *h_JetEta;
  TH2D *h2_JetEta_Pt;
  TH2D *h2_JetEta_Phi;
  TH1D *h_JetPt1;
  TH1D *h_JetPhi1;
  TH1D *h_JetEta1;
  TH2D *h2_JetEta_Pt1;
  TH2D *h2_JetEta_Phi1;
  TH1D *h_JetPt2;
  TH1D *h_JetPhi2;
  TH1D *h_JetEta2;
  TH2D *h2_JetEta_Pt2;
  TH2D *h2_JetEta_Phi2;
  TH1D *h_JetPt3;
  TH1D *h_JetPhi3;
  TH1D *h_JetEta3;
  TH2D *h2_JetEta_Pt3;
  TH2D *h2_JetEta_Phi3;
  TH1D *h_JetPt4;
  TH1D *h_JetPhi4;
  TH1D *h_JetEta4;
  TH2D *h2_JetEta_Pt4;
  TH2D *h2_JetEta_Phi4;
  TH1D *h_remJetPt;
  TH1D *h_remJetPhi;
  TH1D *h_remJetEta;
  TH1D *h_mTPhoMET;
  TH1D *h_dPhi_METjet1;
  TH1D *h_dPhi_METjet2;
  TH1D *h_dPhi_METjet3;
  TH1D *h_dPhi_METjet4;
  TH1D *h_dPhi_phojet1;
  TH1D *h_dPhi_phojet2;
  TH1D *h_dPhi_phojet3;
  TH1D *h_dPhi_phojet4;
  TH1D *h_dPhi_phoMET;
  TH1D *h_dPhi_MET_CaloMET;
  TH1D *h_MET_CaloMET;
  TH2D *h2_HT5HT_dPhiMETj1;
  TH2D *h2_HT5HT_dPhiMETj2;
  TH2D *h2_HT5HT_dPhiMETj3;
  TH2D *h2_HT5HT_dPhiMETj4;
  TH2D *h2_JPt_dPhiMETj1;
  TH2D *h2_JPt_dPhiMETj2;
  TH2D *h2_JPt_dPhiMETj3;
  TH2D *h2_JPt_dPhiMETj4;
  TH2D *h2_MET_dPhiMETj1;
  TH2D *h2_MET_dPhiMETj2;
  TH2D *h2_MET_dPhiMETj;
  TH1D *h_HT5HT;
  TH1D *h_invMass;
  TH1D *h_leadElectronPt;
  TH1D *h_leadElectronPhi;
  TH1D *h_leadElectronEta;
  TH2D *h2_leadElectronEta_Phi;
  TH2D *h2_leadElectronPt_Eta;
  TH2D *h2_leadElectronPt_Phi;
  TH1D *h_leadJetPt;
  TH1D *h_leadJetPhi;
  TH1D *h_leadJetEta;
  TH2D *h2_leadJetEta_Phi;
  TH2D *h2_leadJetEta_Pt;
  TH2D *h2_2leadJetEta_Pt;
  TH2D *h2_3leadJetEta_Pt;
  TH2D *h2_4leadJetEta_Pt;
  TH2D *h2_BestPhoEta_Pt;
  TH2D *h2_ElectronEta_Phi;
  TH1D *h_dPhi_METlep;
  TH1D *h_dPhi_METlep1;
  TH2D *h2_BestPhotonPt_jetmatchphoratio;
  TH2D *h2_BestPhotonPt_jetphoratio;
  TH1D *h_minDr_Elejet1;
  TH1D *h_minDr_Elejet2;
  TH1D *h_minDr_Elejet3;
  TH1D *h_minDr_Elejet4;
  TH1D *h_minDr_EleJets;
  TH1D *h_minDphi_Elejet1;
  TH1D *h_minDr_Zjet1;
  TH1D *h_minDphi_Zjet1;
  TH1D *h_minDphi_Elejet2;
  TH2D *h2_dPhivseta_jet1;
  TH2D *h2_dPhivseta_jet2;
  TH2D *h2_dPhivseta_jet3;
  TH2D *h2_dPhivseta_jet4;
  TH2D *h2_Phivseta_jet1;
  TH2D *h2_Phivseta_jet2;
  TH2D *h2_Phivseta_jet3;
  TH2D *h2_Phivseta_jet4;
  TH2D *h2_njetnbjet_phopt_vBin;
  TH2D *h2_njetnbjet_phopt;
  TH1D *h_hadAk8jetPt;
  TH1D *h_CM_Ele;
  TH1D *h_EMObj_pT;
  TH1D *h_EMObj_Eta;
  TH1D *h_EMObj_Phi;
  TH2D *h2_PhoPtQMultJet;
  TH2D *h2_PhoPtQMultJet_v2;
  TH2D *h2_PhoPtnJets;
  TH3D *h3_PhoPtnJetsbtags;
  TH3D *h3_PhoPtnJetsQmult;
  TH2D *h2_nJetsQMultJet;
  TH2D *h2_PhoPtQMultJet_v3;
  TH2D *h2_nJetsMET;
  TH2D *h2_METQMultJet;
  TH2D *h2_PhoPtMET;
  TH1D *h_dR_bandgene;
  TH1D *h_dR_bandjets;
  TH1D *h_dR_bandrecoe;
  TH1D *h_deepcsv;
  TH1D *h_deepcsv_v2;
  TH1D *h_deepcsv_v3;
  TH1D *h_deepcsv_v4;
  TH1D *h_dR_geneandrecoe;
  TH2D *h2_QMultlleadJetPt;
  TH2D *h2_QMultlleadbJet;
  TH2D *h2_METleadbJet;
  TH2D *h2_QMultlleadbJet_v2;
  TH2D *h2_btag_probwt;
  TH1D *h_zpt;  
  TH1D *h_HT;
  TH1D *h_genzpt;  

  TH1D *h_nvtx_elec0;
  TH1D *h_ST_elec0;
  TH1D *h_MET_elec0;
  TH2D *h2_MET_nJets_elec0;
  TH2D *h2_METvBin2_nJets_elec0;
  TH2D *h2_nbjets_nJets_elec0;
  TH1D *h_METvBin2_elec0;
  TH1D *h_BTags_elec0;
  TH1D *h_nJets_elec0;
  TH1D *h_nremJets_elec0;
  TH1D *h_BestPhotonPt_elec0;
  TH1D *h_BestPhotonPt_vBin_elec0;
  TH1D *h_BestPhotonPhi_elec0;
  TH1D *h_BestPhotonEta_elec0;
  TH2D *h2_BestPhotonEta_Qmulti_elec0;
  TH2D *h2_BestPhotonEta_nJets_elec0;
  TH2D *h2_BestPhotonEta_MET_elec0;
  TH1D *h_BestPhotonPt_0b_elec0;
  TH1D *h_BestPhotonPt_ge1b_elec0;
  TH1D *h_BestPhotonPt_0b_vBin_elec0;
  TH1D *h_BestPhotonPt_ge1b_vBin_elec0;
  TH1D *h_minDr_bestphoEle_elec0;
  TH1D *h_minDr_bestphoJets_elec0;
  TH1D *h_minDr_bestphoremEle_elec0;
  TH1D *h_minDr_bestphoremJets_elec0;
  TH1D *h_NEMobj_elec0;
  TH1D *h_ElectronPt_elec0;
  TH1D *h_ElectronPhi_elec0;
  TH1D *h_ElectronEta_elec0;
  TH1D *h_JetPt_elec0;
  TH1D *h_JetPhi_elec0;
  TH1D *h_JetEta_elec0;
  TH1D *h_JetPt1_elec0;
  TH1D *h_JetPhi1_elec0;
  TH1D *h_JetEta1_elec0;
  TH2D *h2_JetEta_Pt1_elec0;
  TH2D *h2_JetEta_Phi1_elec0;
  TH1D *h_JetPt2_elec0;
  TH1D *h_JetPhi2_elec0;
  TH1D *h_JetEta2_elec0;
  TH2D *h2_JetEta_Pt2_elec0;
  TH2D *h2_JetEta_Phi2_elec0;
  TH1D *h_JetPt3_elec0;
  TH1D *h_JetPhi3_elec0;
  TH1D *h_JetEta3_elec0;
  TH2D *h2_JetEta_Pt3_elec0;
  TH2D *h2_JetEta_Phi3_elec0;
  TH1D *h_JetPt4_elec0;
  TH1D *h_JetPhi4_elec0;
  TH1D *h_JetEta4_elec0;
  TH2D *h2_JetEta_Pt4_elec0;
  TH2D *h2_JetEta_Phi4_elec0;

  TH1D *h_remJetPt_elec0;
  TH1D *h_remJetPhi_elec0;
  TH1D *h_remJetEta_elec0;
  TH1D *h_mTPhoMET_elec0;
  //####
  TH1D *h_dPhi_METjet1_elec0;
  TH1D *h_dPhi_METjet2_elec0;
  TH1D *h_dPhi_METjet3_elec0;
  TH1D *h_dPhi_METjet4_elec0;
  TH1D *h_dPhi_MET_CaloMET_elec0;
  TH1D *h_MET_CaloMET_elec0;
  TH1D *h_HT5HT_elec0;
  // TH1D *h_dPhi_METjet1_elec0;
  // TH1D *h_dPhi_METjet2_elec0;
  TH1D *h_dPhi_phojet1_elec0;
  TH1D *h_dPhi_phojet2_elec0;
  TH1D *h_dPhi_phoMET_elec0;
  TH2D *h2_leadElectronEta_Phi_elec0;
  TH2D *h2_leadElectronPt_Eta_elec0;
  TH2D *h2_leadElectronPt_Phi_elec0;
  TH2D *h2_BestPhotonPt_jetmatchphoratio_elec0;
  TH2D *h2_BestPhotonPt_jetphoratio_elec0;
  TH1D *h_leadJetPt_elec0;
  TH1D *h_leadJetPhi_elec0;
  TH1D *h_leadJetEta_elec0;
  TH2D *h2_leadJetEta_Phi_elec0;
  TH2D *h2_njetnbjet_phopt_vBin_elec0;
  TH2D *h2_njetnbjet_phopt_elec0;
  TH1D *h_hadAk8jetPt_elec0;
  TH1D *h_hadAk8Mass_elec0;
   TH1D *h_CM_Pho;
  TH1D *h_EMObj_pT_elec0;
 TH2D *h2_PhoPtQMultJet_elec0;
 TH2D *h2_PhoPtQMultJet_v2_elec0;
  TH2D *h2_PhoPtQMultJet_v3_elec0;
  TH2D *h2_nJetsMET_elec0;
  TH2D *h2_METQMultJet_elec0;
  TH2D *h2_PhoPtMET_elec0;
  TH2D *h2_PhoPtnJets_elec0;
  TH3D *h3_PhoPtnJetsbtags_elec0;
  TH3D *h3_PhoPtnJetsQmult_elec0;
  TH2D *h2_nJetsQMultJet_elec0;
  TH2D *h2_QMultlleadJetPt_elec0;
  TH2D *h2_QMultlleadbJet_elec0;
  TH2D *h2_QMultlleadbJet_v2_elec0;

  
  TH1D *h_nvtx_elec1_closure;
  TH1D *h_hadAk8Mass_elec1_closure;
  TH1D *h_ST_elec1_closure;
  TH1D *h_MET_elec1_closure;
  TH2D *h2_MET_nJets_elec1_closure;
  TH2D *h2_METvBin2_nJets_elec1_closure;
  TH2D *h2_nbjets_nJets_elec1_closure;
  TH1D *h_METvBin2_elec1_closure;
  TH1D *h_BTags_elec1_closure;
  TH1D *h_nJets_elec1_closure;
  TH1D *h_nremJets_elec1_closure;
  TH1D *h_BestPhotonPt_elec1_closure;
  TH1D *h_BestPhotonPt_vBin_elec1_closure;
  TH1D *h_BestPhotonPhi_elec1_closure;
  TH1D *h_BestPhotonEta_elec1_closure;
  TH2D *h2_BestPhotonEta_Qmulti_elec1_closure;
  TH2D *h2_BestPhotonEta_nJets_elec1_closure;
  TH2D *h2_BestPhotonEta_MET_elec1_closure;
  TH1D *h_BestPhotonPt_0b_elec1_closure;
  TH1D *h_BestPhotonPt_ge1b_elec1_closure;
  TH1D *h_BestPhotonPt_0b_vBin_elec1_closure;
  TH1D *h_BestPhotonPt_ge1b_vBin_elec1_closure;
  // TH1D *h_BestPhotonPt_elec1_closure_0b_vBin;
  // TH1D *h_BestPhotonPt_elec1_closure_ge1b_vBin;
  TH1D *h_minDr_bestphoEle_elec1_closure;
  TH1D *h_minDr_bestphoJets_elec1_closure;
  TH1D *h_minDr_bestphoremEle_elec1_closure;
  TH1D *h_minDr_bestphoremJets_elec1_closure;
  TH1D *h_NEMobj_elec1_closure;
  TH1D *h_ElectronPt_elec1_closure;
  TH1D *h_ElectronPhi_elec1_closure;
  TH1D *h_ElectronEta_elec1_closure;
  TH1D *h_JetPt_elec1_closure;
  TH1D *h_JetPhi_elec1_closure;
  TH1D *h_JetEta_elec1_closure;
  TH1D *h_JetPt1_elec1_closure;
  TH1D *h_JetPhi1_elec1_closure;
  TH1D *h_JetEta1_elec1_closure;
  TH2D *h2_JetEta_Pt1_elec1_closure;
  TH2D *h2_JetEta_Phi1_elec1_closure;
  TH1D *h_JetPt2_elec1_closure;
  TH1D *h_JetPhi2_elec1_closure;
  TH1D *h_JetEta2_elec1_closure;
  TH2D *h2_JetEta_Pt2_elec1_closure;
  TH2D *h2_JetEta_Phi2_elec1_closure;
  TH1D *h_JetPt3_elec1_closure;
  TH1D *h_JetPhi3_elec1_closure;
  TH1D *h_JetEta3_elec1_closure;
  TH2D *h2_JetEta_Pt3_elec1_closure;
  TH2D *h2_JetEta_Phi3_elec1_closure;
  TH1D *h_JetPt4_elec1_closure;
  TH1D *h_JetPhi4_elec1_closure;
  TH1D *h_JetEta4_elec1_closure;
  TH2D *h2_JetEta_Pt4_elec1_closure;
  TH2D *h2_JetEta_Phi4_elec1_closure; 
  TH1D *h_remJetPt_elec1_closure;
  TH1D *h_remJetPhi_elec1_closure;
  TH1D *h_remJetEta_elec1_closure;
  TH1D *h_mTPhoMET_elec1_closure;
  TH1D *h_dPhi_METjet1_elec1_closure;
  TH1D *h_dPhi_METjet2_elec1_closure;
  TH1D *h_dPhi_phojet1_elec1_closure;
  TH1D *h_dPhi_phojet2_elec1_closure;
  TH1D *h_dPhi_phoMET_elec1_closure;
  TH2D *h2_BestPhotonPt_jetmatchphoratio_elec1_closure;
  TH2D *h2_BestPhotonPt_jetphoratio_elec1_closure;
  TH2D *h2_leadElectronEta_Phi_elec1_closure;
  TH2D *h2_leadElectronPt_Eta_elec1_closure;
  TH1D *h_leadJetPt_elec1_closure;
  TH1D *h_leadJetPhi_elec1_closure;
  TH1D *h_leadJetEta_elec1_closure;
  TH2D *h2_leadJetEta_Phi_elec1_closure;
  TH2D *h2_njetnbjet_phopt_vBin_elec1_closure;
  TH2D *h2_njetnbjet_phopt_elec1_closure; 
  TH1D *h_hadAk8jetPt_elec1_closure;
  TH1D *h_CM_elec1_closure;
  TH1D *h_EMObj_pT_elec1_closure;
  TH2D *h2_PhoPtQMultJet_elec1_closure;
  TH2D *h2_PhoPtQMultJet_v2_elec1_closure;
  TH2D *h2_PhoPtQMultJet_v3_elec1_closure;
  TH2D *h2_nJetsMET_elec1_closure;
  TH2D *h2_METQMultJet_elec1_closure;
  TH2D *h2_PhoPtMET_elec1_closure;
  TH2D *h2_PhoPtnJets_elec1_closure;
  TH3D *h3_PhoPtnJetsbtags_elec1_closure;
  TH3D *h3_PhoPtnJetsQmult_elec1_closure;
  TH2D *h2_nJetsQMultJet_elec1_closure;
  

  
  TH1D *h_intLumi_EW;
  TH1D *h_ST_EW;
  TH1D *h_MET_EW;
  TH1D *h_BTags_EW;
  TH1D *h_BestPhotonPt_EW;
  TH1D *h_nJets_EW;

  TH1D *h_intLumi_EW_noSB;
  TH1D *h_ST_EW_noSB;
  TH1D *h_MET_EW_noSB;
  TH1D *h_BTags_EW_noSB;
  TH1D *h_BestPhotonPt_EW_noSB;
  TH1D *h_nJets_EW_noSB;

  TH1D *h_intLumi_EW_SB;
  TH1D *h_ST_EW_SB;
  TH1D *h_MET_EW_SB;
  TH1D *h_BTags_EW_SB;
  TH1D *h_BestPhotonPt_EW_SB;
  TH1D *h_nJets_EW_SB;

  TH1D *h_intLumi_EW_htag;
  TH1D *h_ST_EW_htag;
  TH1D *h_MET_EW_htag;
  TH1D *h_BTags_EW_htag;
  TH1D *h_BestPhotonPt_EW_htag;
  TH1D *h_nJets_EW_htag;

  TH1D *h_intLumi_EW_wtag;
  TH1D *h_ST_EW_wtag;
  TH1D *h_MET_EW_wtag;
  TH1D *h_BTags_EW_wtag;
  TH1D *h_BestPhotonPt_EW_wtag;
  TH1D *h_nJets_EW_wtag;

  TH1D *h_intLumi_SP;
  TH1D *h_ST_SP;
  TH1D *h_MET_SP;
  TH1D *h_BTags_SP;
  TH1D *h_BestPhotonPt_SP;
  TH1D *h_nJets_SP;

  TH1D *h_intLumi_2018;
  TH1D *h_ST_2018;
  TH1D *h_MET_2018;
  TH1D *h_BTags_2018;
  TH1D *h_BestPhotonPt_2018;
  TH1D *h_nJets_2018;

  TH1D *h_dR_q_b_matched;
  TH1D *h_GenWpt;
  TH1D *h_GenWeta;
  TH1D *h_GenWpt1;
  TH1D *h_GenWpt1_1;
  TH1D *h_GenWM1_1;
  TH1D *h_GenWeta1;
  TH1D *h_GenWpt2_1;
  TH1D *h_GenWeta2_1;
  TH1D *h_GenWM2_1;
  TH1D *h_GenWpt2_2;
  TH1D *h_GenWM2_2;
  TH1D *h_GenWeta2_2;
  TH1D *h_GenWpt2;
  TH1D *h_GenWeta2;

  TH2D *h2_PtPhotonvsMET;
  TH2D *h2_GenPhotonvsGenMET;
  TH2D *h2_GenWvsnjet;
  TH1D *h_METvBin_EW;
  TH1D *h_METvBin_EW_htag;
  TH1D *h_METvBin_SP;
  TH1D *h_METvBin_EW_v1;
  TH1D *h_METvBin_EW_htag_v1;
  TH1D *h_METvBin_SP_v1;
  TH1D *h_METvBin_EW_v2;
  TH1D *h_METvBin_EW_noSB_v2;
  TH1D *h_METvBin_EW_SB_v2;
  TH1D *h_METvBin_EW_wtag_v2;
  TH1D *h_METvBin_EW_htag_v2;
  TH1D *h_METvBin_SP_v2;
  TH1D *h_METvBin_nocut;
  TH1D *h_METvBin1;
  TH1D *h_METvBin_nocut1;
  TH1D *h_METvBin_nocut2;
  TH1D *h_MET_nj1;
  TH1D *h_METvBin_nj1;
  TH1D *h_METvBin1_nj1;
  TH1D *h_METvBin2_nj1;
  TH1D *h_MET_nj2to4_nbjet0;
  TH1D *h_METvBin_nj2to4_nbjet0;
  TH1D *h_METvBin1_nj2to4_nbjet0;
  TH1D *h_METvBin2_nj2to4_nbjet0;
  TH1D *h_MET_nj5to6_nbjet0;
  TH1D *h_METvBin_nj5to6_nbjet0;
  TH1D *h_METvBin1_nj5to6_nbjet0;
  TH1D *h_METvBin2_nj5to6_nbjet0;
  TH1D *h_MET_nj7toinf_nbjet0;
  TH1D *h_METvBin_nj7toinf_nbjet0;
  TH1D *h_METvBin1_nj7toinf_nbjet0;
  TH1D *h_METvBin2_nj7toinf_nbjet0;

  TH1D *h_MET_nj2to4_nbjet1;
  TH1D *h_METvBin_nj2to4_nbjet1;
  TH1D *h_METvBin1_nj2to4_nbjet1;
  TH1D *h_METvBin2_nj2to4_nbjet1;
  TH1D *h_MET_nj5to6_nbjet1;
  TH1D *h_METvBin_nj5to6_nbjet1;
  TH1D *h_METvBin1_nj5to6_nbjet1;
  TH1D *h_METvBin2_nj5to6_nbjet1;
  TH1D *h_MET_nj7toinf_nbjet1;
  TH1D *h_METvBin_nj7toinf_nbjet1;
  TH1D *h_METvBin1_nj7toinf_nbjet1;
  TH1D *h_METvBin2_nj7toinf_nbjet1;

  TH1D *h_MET_nj2to4_nbjetnot0;
  TH1D *h_METvBin_nj2to4_nbjetnot0;
  TH1D *h_METvBin1_nj2to4_nbjetnot0;
  TH1D *h_METvBin2_nj2to4_nbjetnot0;
  TH1D *h_MET_nj5to6_nbjetnot0;
  TH1D *h_METvBin_nj5to6_nbjetnot0;
  TH1D *h_METvBin1_nj5to6_nbjetnot0;
  TH1D *h_METvBin2_nj5to6_nbjetnot0;
  TH1D *h_MET_nj7toinf_nbjetnot0;
  TH1D *h_METvBin_nj7toinf_nbjetnot0;
  TH1D *h_METvBin1_nj7toinf_nbjetnot0;
  TH1D *h_METvBin2_nj7toinf_nbjetnot0;

  TH1D *h_PhovBin;
  TH1D *h_PhovBin_nocut;
  TH1D *h_PhovBin1;
  TH1D *h_PhovBin_nocut1;
  TH1D *h_PhovBin2;
  TH1D *h_PhovBin_nocut2;
  TH1D *h_hadAk8Mass;
  TH1D *h_hadAk8Mass_vBin;
  TH1D *h_hadAk8Mass_EW_vBin;
  TH1D *h_hadAk8Mass_EW_htag_vBin;
  TH1D *h_hadAk8Mass_EW_wtag_vBin;
  TH1D *h_hadAk8Mass_SP_vBin;
  TH1D *h_hadAk8Mass_matchedW;
  TH1D *h_hadAk8Mass_EW_nAk8jet_ge1;
  TH1D *h_hadAk8Mass_EW;
  TH1D *h_hadAk8Mass_EW_SB;
  TH1D *h_hadAk8Mass_EW_noSB;
  TH1D *h_hadAk8Mass_EW_htag_A;
  TH1D *h_hadAk8Mass_EW_wtag_A;
  TH1D *h_hadAk8Mass_EW_htag_B;
  TH1D *h_hadAk8Mass_EW_wtag_B;
  TH1D *h_hadAk8Mass_EW_htag_C;
  TH1D *h_hadAk8Mass_EW_wtag_C;
  TH1D *h_hadAk8Mass_EW_htag_D;
  TH1D *h_hadAk8Mass_EW_wtag_D;
  TH1D *h_hadAk8Mass_EW_htag;
  TH1D *h_hadAk8Mass_EW_wtag;
  TH1D *h_hadAk8Mass_SP;
  TH1D *h_hadAk8Mass_Ak8jet2to5;
  TH1D *h_hadAk8Mass_Ak8jetge6;
  TH1D *h_hadAk8Mass_Ak8jet2to5_noEW;
  TH1D *h_hadAk8Mass_Ak8jetge6_EW;
  TH1D *h_hadAk8Mass_Ak8jetge6_noEW;
  TH1D *h_hadAk8Mass_Ak8jet0;
  TH1D *h_hadAk8Mass_Ak8jet0_EW_noSB;
  TH1D *h_hadAk8Mass_Ak8jet0_EW_SB;
  TH1D *h_hadAk8Mass_Ak8jet0_SP;
  TH1D *h_hadAk8Mass_Ak8jet0_EW;
  TH1D *h_hadAk8Pt;
  TH1D *h_hadAk8Pt_matchedW;
  TH1D *h_hadAk8Pt_EW_nAk8jet_ge1;
  TH1D *h_hadAk8Pt_EW;
  TH1D *h_hadAk8Pt_EW_htag;
  TH1D *h_hadAk8Pt_SP;
  TH1D *h_hadAk8Pt_Ak8jet2to5;
  TH1D *h_hadAk8Pt_Ak8jetge6;
  TH1D *h_hadAk8Pt_Ak8jet0;
  TH1D *h_hadAk8Pt_Ak8jet0_EW_noSB;
  TH1D *h_hadAk8Pt_Ak8jet0_EW_SB;
  TH1D *h_hadAk8Pt_Ak8jet0_SP;
  TH1D *h_hadAk8Pt_Ak8jet0_EW;
  TH1D *h_nHadJets_nAk8jet_ge1;
  TH1D *h_nHadAk8Jets_nAk8jet_ge1;
  TH1D *h_BTags_nAk8jet_ge1;
  TH1D *h_nHadJets_nAk8jet_jet2to5;
  TH1D *h_nHadAk8Jets_nAk8jet_jet2to5;
  TH1D *h_BTags_nAk8jet_jet2to5;
  TH1D *h_nHadJets_nAk8jet_jetge6;
  TH1D *h_nHadAk8Jets_nAk8jet_jetge6;
  TH1D *h_nHadJets_nAk8jet0_SP;
  TH1D *h_nHadAk8Jets_nAk8jet0_SP;

  TH1D *h_nHadJets_nAk8jet_jet2to5_noEW;
  TH1D *h_nHadJets_nAk8jet_jetge6_EW;
  TH1D *h_nHadJets_nAk8jet_jetge6_noEW;

  TH1D *h_BTags_nAk8jet_jetge6;
  TH1D *h_BTags_nAk8jet1;
  TH1D *h_BTags_nAk8jet2;
  TH1D *h_BTags_nAk8jet3;
  /* TH2D *h2_STvsHT; */

  /* TH1D *h_dPhi_METBestPhoton; */
  // TH1D *h_dPhi_METjet1;
  // TH1D *h_dPhi_METjet2;
  // TH1D *h_dPhi_phojet1;
  // TH1D *h_dPhi_phojet2;
  // TH1D *h_dPhi_phoMET;

  //for numerator
  TH1D *h_nEvts_num;
  TH1I *h_RunNum_num;
  TH1D *h_intLumi_num;
  TH1D *h_ST_num;
  TH1D *h_MET_num;
  /* TH1D *h_nHadJets_num; */
  TH1D *h_BTags_num;
  TH1D *h_BestPhotonPt_num;

  /* TH1D *h_HT_num; */
  /* TH1D *h_MHT_num; */
  /* TH1D *h_MHTstar_num; */
  TH1D *h_nJets_num;
  TH1D *h_dR_jetandW;
  TH1D *h_dR_jet1andW;
  TH1D *h_dR_jet2andW;
  TH1D *h_dR_jet1andjet2;
  TH1D *h_dR_Genpho_Genjet;
  TH2D *h2_PtPhotonvsMET_num;
  TH1D *h_mTPhoMET_num;

  /* TH2D *h2_STvsHT_num; */

  /* TH1D *h_dPhi_METBestPhoton_num; */
  TH1D *h_dPhi_METjet1_num;
  TH1D *h_dPhi_METjet2_num;
  TH1D *h_dPhi_phojet1_num;
  TH1D *h_dPhi_phojet2_num;
  TH1D *h_dPhi_phoMET_num;
  TGraphAsymmErrors *h_MET_eff;
  TGraphAsymmErrors *h_nJets_eff;
  TGraphAsymmErrors *h_BestPhotonPt_eff;

  //for numerator1
  TH1D *h_nEvts_nocut;
  TH1I *h_RunNum_nocut;
  TH1D *h_intLumi_nocut;
  TH1D *h_ST_nocut;
  TH1D *h_MET_nocut;
  /* TH1D *h_nHadJets_nocut; */
  TH1D *h_BTags_nocut;
  TH1D *h_BestPhotonPt_nocut;

  /* TH1D *h_HT_nocut; */
  /* TH1D *h_MHT_nocut; */
  /* TH1D *h_MHTstar_nocut; */
  TH1D *h_nJets_nocut;

  TH2D *h2_PtPhotonvsMET_nocut;
  TH1D *h_mTPhoMET_nocut;

  /* TH2D *h2_STvsHT_nocut; */
  TH1D *h_mindr_lep_goodph;
  TH1D *h_mindr_genph_lep;
  TH1D *h_mindr_ph_lep;
  TH1D *h_mindr_genph_had;
  TH1D *h_madminphotonDR;
  TH1D *h_mindr_ph_ele;
  TH1D *h_mindr_ph_mu;
  TH1D *h_mindr_ph_tau;
  TH1D *h_mindr_goodph_lep;
  TH1D *h_mindr_goodph_ph;
  TH1D *h_mindr_goodph_had;
  TH1D *h_mindr_gentau_jet2;
  TH1D *h_mindr_gentau_pt;
  TH1D *h_mindr_gentau_jet;
  TH1D *h_mindr_gentau_mu;
  TH1D *h_mindr_gentau_ele;
  TH1D *h_minDr_bestphoEle_EW;
  TH1D *h_minDr_bestphoJets_EW;
  TH1D *h_minDr_bestphoEle_SP;
  TH1D *h_minDr_bestphoJets_SP;
  /* TH1D *h_dPhi_METBestPhoton_nocut; */
  TH1D *h_dPhi_METjet1_nocut;
  TH1D *h_dPhi_METjet2_nocut;
  TH1D *h_dPhi_phojet1_nocut;
  TH1D *h_dPhi_phojet2_nocut;
  TH1D *h_dPhi_phoMET_nocut;
  TGraphAsymmErrors *h_MET_eff1;
  TGraphAsymmErrors *h_nJets_eff1;
  TGraphAsymmErrors *h_BestPhotonPt_eff1;
  TH1F *h_selectBaselineYields_;
  TH1F *h_selectBaselineYields_2;

  TH1D *h_GmatchedObj;
  TH1D *h_PdgIdPhoParent;

  TH1D *h_SBins_v6_CD;
  TH1D *h_SBins_v6_CD_EW;
  TH1D *h_SBins_v6_CD_EW_htag;
  TH1D *h_SBins_v6_CD_SP;
  TH1D *h_SBins_v7_CD;
  TH1D *h_SBins_v7_CD_EW;
  TH1D *h_SBins_v7_CD_EW_htag;
  TH1D *h_SBins_v7_CD_EW_wtag;
  TH1D *h_SBins_v7_CD_SP;
  TH1D *h_SBins_v7_CD_2018;
  TH1D *h_SBins_v6_CD_EW_14bin;
  TH1D *h_SBins_v6_CD_EW_43bin;
  TH1D *h_SBins_v6_CD_EW_50bin;
  TH1D *h_SBins_v6_CD_EW_7bin;
  TH1D *h_SBins_v6_CD_EW_7bin_elec1;
  TH1D *h_SBins_v6_CD_EW_7bin_elec0;
  TH1D *h_SBins_v6_CD_EW_7bin_elec1_closure;

  TH1D *h_SBins_v6_CD_elec0_acc;                                                                                               
  TH1D *h_SBins_v6_CD_elec0_id;                                                                                                  
  TH1D *h_SBins_v6_CD_elec0_iso;                                                                                                 
  TH1D *h_SBins_v6_CD_elec0;                                                                                                     
  TH1D *h_SBins_v6_CD_elec1; 
  TH1D *h_SBins_v6_CD_elec1_closure; 
  TH1D *h_SBins_v6_CD_EW_50bin_elec1_closure;
  TH1D *h_SBins_v6_CD_EW_50bin_elec1;
  TH1D *h_SBins_v6_CD_EW_50bin_elec0;

  TH1D *h_SBins_v7_CD_elec0_acc;                                                                                                 
  TH1D *h_SBins_v7_CD_elec0_id;                                                                                                  
  TH1D *h_SBins_v7_CD_elec0_iso;                                                                                                
  TH1D *h_SBins_v7_CD_elec0;                                                                                                     
  TH1D *h_SBins_v7_CD_elec1;                                                                                                     

  TH1D *h_SBins_v7_1_CD_elec0_acc;                                                                                                 
  TH1D *h_SBins_v7_1_CD_elec0_id;                                                                                                  
  TH1D *h_SBins_v7_1_CD_elec0_iso;                                                                                                
  TH1D *h_SBins_v7_1_CD_elec0;                                                                                                     
  TH1D *h_SBins_v7_1_CD_elec1;                                                                                                     
  
  TH1D *h_SBins_v6_CD_SP_elec0_acc;
  TH1D *h_SBins_v6_CD_SP_elec0_id;
  TH1D *h_SBins_v6_CD_SP_elec0_iso;
  TH1D *h_SBins_v6_CD_SP_elec0;
  TH1D *h_SBins_v6_CD_SP_elec1;
  TH1D *h_SBins_v6_CD_SP_elec1_closure;

  TH1D *h_SBins_v7_CD_SP_elec0_acc;
  TH1D *h_SBins_v7_CD_SP_elec0_id;
  TH1D *h_SBins_v7_CD_SP_elec0_iso;
  TH1D *h_SBins_v7_CD_SP_elec0;
  TH1D *h_SBins_v7_CD_SP_elec1;
  TH1D *h_SBins_v7_CD_SP_elec1_closure;

  TH1D *h_SBins_v7_CD_SP_tmp_elec0;
  TH1D *h_SBins_v7_CD_SP_tmp_elec1;
  TH1D *h_SBins_v7_CD_SP_tmp_elec1_closure;
  TH2F *d_eff_b, *n_eff_b;
  TH2F *d_eff_c, *n_eff_c;
  TH2F *d_eff_udsg, *n_eff_udsg; 

  TFile *oFile;
  
};
#endif

#ifdef Mulijet_cxx

void Mulijet::BookHistogram(const char *outFileName) {

  //  char hname[200], htit[200];
  //  double xlow = 0.0,  xhigh = 2000.0;
  //  int nbins = 2000;
  char name[100],title[100];
 
  oFile = new TFile(outFileName, "recreate");
  TH1::SetDefaultSumw2(1);
  h_selectBaselineYields_ = new TH1F("cutflows","cutflows",12,-0.5,12.5);
  h_selectBaselineYields_2 = new TH1F("cutflows2","cutflows2",12,-0.5,12.5);


  d_eff_b = new TH2F("d_eff_b","d_eff_b",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));
  n_eff_b = new TH2F("n_eff_b","n_eff_b",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));
  
  d_eff_c = new TH2F("d_eff_c","d_eff_c",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));
  n_eff_c = new TH2F("n_eff_c","n_eff_c",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));
  
  d_eff_udsg = new TH2F("d_eff_udsg","d_eff_udsg",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));
  n_eff_udsg = new TH2F("n_eff_udsg","n_eff_udsg",xbins.size()-1,&(xbins[0]), ybins.size()-1,&(ybins[0]));   
  h_mindphi1dphi2=new TH1D("mindPhi1dPhi2","mindphi between MET Vec and Jet1 or Jet2",40,0,4);

  h_mindphi1dphi2_A=new TH1D("mindPhi1dPhi2_A","mindphi between MET Vec and Jet1 or Jet2",40,0,4);
  h_dPhi_phoMET_A=new TH1D("dPhi_phoMET_A","dphi between photon and MET",40,0,4);
  h_JetPt1_A=new TH1D("JetPt1_A","Pt of the Jet 1",150,0,1500);
  h_JetPhi1_A=new TH1D("JetPhi1_A","Phi of the Jet 1",80,-4,4);
  h_JetEta1_A=new TH1D("JetEta1_A","Eta of the Jet 1",80,-4,4);
  h_JetPt2_A=new TH1D("JetPt2_A","Pt of the Jet 2",150,0,1500);
  h_JetPhi2_A=new TH1D("JetPhi2_A","Phi of the Jet 2",80,-4,4);
  h_JetEta2_A=new TH1D("JetEta2_A","Eta of the Jet 2",80,-4,4);
  h_JetPt3_A=new TH1D("JetPt3_A","Pt of the Jet 3",150,0,1500);
  h_JetPhi3_A=new TH1D("JetPhi3_A","Phi of the Jet 3",80,-4,4);
  h_JetEta3_A=new TH1D("JetEta3_A","Eta of the Jet 3",80,-4,4);
  h_JetPt4_A=new TH1D("JetPt4_A","Pt of the Jet 4",150,0,1500);
  h_JetPhi4_A=new TH1D("JetPhi4_A","Phi of the Jet 4",80,-4,4);
  h_JetEta4_A=new TH1D("JetEta4_A","Eta of the Jet 4",80,-4,4);

  h_mindphi1dphi2_B=new TH1D("mindPhi1dPhi2_B","mindphi between MET Vec and Jet1 or Jet2",40,0,4);
  h_dPhi_phoMET_B=new TH1D("dPhi_phoMET_B","dphi between photon and MET",40,0,4);
  h_JetPt1_B=new TH1D("JetPt1_B","Pt of the Jet 1",150,0,1500);
  h_JetPhi1_B=new TH1D("JetPhi1_B","Phi of the Jet 1",80,-4,4);
  h_JetEta1_B=new TH1D("JetEta1_B","Eta of the Jet 1",80,-4,4);
  h_JetPt2_B=new TH1D("JetPt2_B","Pt of the Jet 2",150,0,1500);
  h_JetPhi2_B=new TH1D("JetPhi2_B","Phi of the Jet 2",80,-4,4);
  h_JetEta2_B=new TH1D("JetEta2_B","Eta of the Jet 2",80,-4,4);
  h_JetPt3_B=new TH1D("JetPt3_B","Pt of the Jet 3",150,0,1500);
  h_JetPhi3_B=new TH1D("JetPhi3_B","Phi of the Jet 3",80,-4,4);
  h_JetEta3_B=new TH1D("JetEta3_B","Eta of the Jet 3",80,-4,4);
  h_JetPt4_B=new TH1D("JetPt4_B","Pt of the Jet 4",150,0,1500);
  h_JetPhi4_B=new TH1D("JetPhi4_B","Phi of the Jet 4",80,-4,4);
  h_JetEta4_B=new TH1D("JetEta4_B","Eta of the Jet 4",80,-4,4);

  h_mindphi1dphi2_C=new TH1D("mindPhi1dPhi2_C","mindphi between MET Vec and Jet1 or Jet2",40,0,4);
  h_dPhi_phoMET_C=new TH1D("dPhi_phoMET_C","dphi between photon and MET",40,0,4);
  h_JetPt1_C=new TH1D("JetPt1_C","Pt of the Jet 1",150,0,1500);
  h_JetPhi1_C=new TH1D("JetPhi1_C","Phi of the Jet 1",80,-4,4);
  h_JetEta1_C=new TH1D("JetEta1_C","Eta of the Jet 1",80,-4,4);
  h_JetPt2_C=new TH1D("JetPt2_C","Pt of the Jet 2",150,0,1500);
  h_JetPhi2_C=new TH1D("JetPhi2_C","Phi of the Jet 2",80,-4,4);
  h_JetEta2_C=new TH1D("JetEta2_C","Eta of the Jet 2",80,-4,4);
  h_JetPt3_C=new TH1D("JetPt3_C","Pt of the Jet 3",150,0,1500);
  h_JetPhi3_C=new TH1D("JetPhi3_C","Phi of the Jet 3",80,-4,4);
  h_JetEta3_C=new TH1D("JetEta3_C","Eta of the Jet 3",80,-4,4);
  h_JetPt4_C=new TH1D("JetPt4_C","Pt of the Jet 4",150,0,1500);
  h_JetPhi4_C=new TH1D("JetPhi4_C","Phi of the Jet 4",80,-4,4);
  h_JetEta4_C=new TH1D("JetEta4_C","Eta of the Jet 4",80,-4,4);

  h_mindphi1dphi2_D=new TH1D("mindPhi1dPhi2_D","mindphi between MET Vec and Jet1 or Jet2",40,0,4);
  h_dPhi_phoMET_D=new TH1D("dPhi_phoMET_D","dphi between photon and MET",40,0,4);
  h_JetPt1_D=new TH1D("JetPt1_D","Pt of the Jet 1",150,0,1500);
  h_JetPhi1_D=new TH1D("JetPhi1_D","Phi of the Jet 1",80,-4,4);
  h_JetEta1_D=new TH1D("JetEta1_D","Eta of the Jet 1",80,-4,4);
  h_JetPt2_D=new TH1D("JetPt2_D","Pt of the Jet 2",150,0,1500);
  h_JetPhi2_D=new TH1D("JetPhi2_D","Phi of the Jet 2",80,-4,4);
  h_JetEta2_D=new TH1D("JetEta2_D","Eta of the Jet 2",80,-4,4);
  h_JetPt3_D=new TH1D("JetPt3_D","Pt of the Jet 3",150,0,1500);
  h_JetPhi3_D=new TH1D("JetPhi3_D","Phi of the Jet 3",80,-4,4);
  h_JetEta3_D=new TH1D("JetEta3_D","Eta of the Jet 3",80,-4,4);
  h_JetPt4_D=new TH1D("JetPt4_D","Pt of the Jet 4",150,0,1500);
  h_JetPhi4_D=new TH1D("JetPhi4_D","Phi of the Jet 4",80,-4,4);
  h_JetEta4_D=new TH1D("JetEta4_D","Eta of the Jet 4",80,-4,4);

  h_ST_A=new TH1D("ST_A","ST",400,0,4000);
  h_MET_A=new TH1D("MET_A","MET",200,0,2000);
  h_nJets_A=new TH1D("nJets_A","nJets",25,0,25);
  h_BTags_A=new TH1D("nBTags_A","no. of B tags",10,0,10);
  h_BestPhotonPt_A=new TH1D("BestPhotonPt_A","Pt of the Best Photon",300,0,1500);
  h_JetPt_A=new TH1D("JetPt_A","Pt of the Jets",300,0,1500);
  h_BestPhotonEta_A=new TH1D("BestPhotonEta_A","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_A=new TH1D("BestPhotonPhi_A","Phi of the Best Photon",400,-5,5);
  h_JetEta_A=new TH1D("JetEta_A","Eta of the Jets",400,-5,5);
  h_JetPhi_A=new TH1D("JetPhi_A","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt_A=new TH2D("JetEta_Pt_A","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi_A=new TH2D("JetEta_Phi_A","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METjet1_A=new TH1D("dPhi_METjet1_A","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_A=new TH1D("dPhi_METjet2_A","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3_A=new TH1D("dPhi_METjet3_A","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4_A=new TH1D("dPhi_METjet4_A","dphi between MET Vec and Jet4",80,-4,4);
  h_dPhi_phojet1_A=new TH1D("dPhi_phojet1_A","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_A=new TH1D("dPhi_phojet2_A","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phojet3_A=new TH1D("dPhi_phojet3_A","dphi between photon and Jet3",80,-4,4);
  h2_MET_dPhiMETj1_A=new TH2D("MET_dPhiMETj1_A","MET vs dPhi(MET, J1)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj2_A=new TH2D("MET_dPhiMETj2_A","MET vs dPhi(MET, J2)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj_A=new TH2D("MET_dPhiMETj_A","MET vs mindPhi(MET, J)",300,0,1500,200, 0, 4);
  h_SBins_v6_CD_EW_7bin_A = new TH1D("AllSBins_v6_CD_EW_7bin_A","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);
  h_SBins_v7_CD_SP_A = new TH1D("AllSBins_v7_CD_SP_A","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_CA = new TH1D("AllSBins_v7_CD_SP_CA","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_BD = new TH1D("AllSBins_v7_CD_SP_BD","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h2_nJetsMET_v2_A=new TH2D("nJetsMET_v2_A","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets2.size()-1,&(njets2[0]));
  h2_nJetsMET_A=new TH2D("nJetsMET_A","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets.size()-1,&(njets[0]));
  h_SBins_v6_CD_EW_50bin_A = new TH1D("AllSBins_v6_CD_EW_50bin_A","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_EW_50bin_AB = new TH1D("AllSBins_v6_CD_EW_50bin_AB","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_EW_50bin_CD = new TH1D("AllSBins_v6_CD_EW_50bin_CD","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_A = new TH1D("AllSBins_v6_CD_A","8 search bins : NJets x NbTags",8,1,9);
  h_ST_B=new TH1D("ST_B","ST",400,0,4000);
  h_MET_B=new TH1D("MET_B","MET",200,0,2000);
  h_nJets_B=new TH1D("nJets_B","nJets",25,0,25);
  h_BTags_B=new TH1D("nBTags_B","no. of B tags",10,0,10);
  h_BestPhotonPt_B=new TH1D("BestPhotonPt_B","Pt of the Best Photon",300,0,1500);
  h_JetPt_B=new TH1D("JetPt_B","Pt of the Jets",300,0,1500);
  h_BestPhotonEta_B=new TH1D("BestPhotonEta_B","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_B=new TH1D("BestPhotonPhi_B","Phi of the Best Photon",400,-5,5);
  h_JetEta_B=new TH1D("JetEta_B","Eta of the Jets",400,-5,5);
  h_JetPhi_B=new TH1D("JetPhi_B","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt_B=new TH2D("JetEta_Pt_B","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi_B=new TH2D("JetEta_Phi_B","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METjet1_B=new TH1D("dPhi_METjet1_B","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_B=new TH1D("dPhi_METjet2_B","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3_B=new TH1D("dPhi_METjet3_B","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4_B=new TH1D("dPhi_METjet4_B","dphi between MET Vec and Jet4",80,-4,4);
  h_dPhi_phojet1_B=new TH1D("dPhi_phojet1_B","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_B=new TH1D("dPhi_phojet2_B","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phojet3_B=new TH1D("dPhi_phojet3_B","dphi between photon and Jet3",80,-4,4);
  h2_MET_dPhiMETj1_B=new TH2D("MET_dPhiMETj1_B","MET vs dPhi(MET, J1)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj2_B=new TH2D("MET_dPhiMETj2_B","MET vs dPhi(MET, J2)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj_B=new TH2D("MET_dPhiMETj_B","MET vs mindPhi(MET, J)",300,0,1500,200, 0, 4);
  h_SBins_v6_CD_EW_7bin_B = new TH1D("AllSBins_v6_CD_EW_7bin_B","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);
  h_SBins_v7_CD_SP_B = new TH1D("AllSBins_v7_CD_SP_B","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h2_nJetsMET_v2_B=new TH2D("nJetsMET_v2_B","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets2.size()-1,&(njets2[0]));
  h2_nJetsMET_B=new TH2D("nJetsMET_B","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets.size()-1,&(njets[0]));
  h_SBins_v6_CD_EW_50bin_B = new TH1D("AllSBins_v6_CD_EW_50bin_B","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_B = new TH1D("AllSBins_v6_CD_B","8 search bins : NJets x NbTags",8,1,9);
  h_nJetsMET_P=new TH1D("nJetsMET_P","x: MET",metbin.size()-1,&(metbin[0]));
  h_nJetsMET_Q=new TH1D("nJetsMET_Q","x: MET",metbin.size()-1,&(metbin[0]));
  h_nJetsMET_R=new TH1D("nJetsMET_R","x: MET",metbin.size()-1,&(metbin[0]));
  h_nJetsMET_S=new TH1D("nJetsMET_S","x: MET",metbin.size()-1,&(metbin[0]));

  h_ST_C=new TH1D("ST_C","ST",400,0,4000);
  h_MET_C=new TH1D("MET_C","MET",200,0,2000);
  h_nJets_C=new TH1D("nJets_C","nJets",25,0,25);
  h_BTags_C=new TH1D("nBTags_C","no. of B tags",10,0,10);
  h_BestPhotonPt_C=new TH1D("BestPhotonPt_C","Pt of the Best Photon",300,0,1500);
  h_JetPt_C=new TH1D("JetPt_C","Pt of the Jets",300,0,1500);
  h_BestPhotonEta_C=new TH1D("BestPhotonEta_C","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_C=new TH1D("BestPhotonPhi_C","Phi of the Best Photon",400,-5,5);
  h_JetEta_C=new TH1D("JetEta_C","Eta of the Jets",400,-5,5);
  h_JetPhi_C=new TH1D("JetPhi_C","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt_C=new TH2D("JetEta_Pt_C","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi_C=new TH2D("JetEta_Phi_C","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METjet1_C=new TH1D("dPhi_METjet1_C","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_C=new TH1D("dPhi_METjet2_C","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3_C=new TH1D("dPhi_METjet3_C","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4_C=new TH1D("dPhi_METjet4_C","dphi between MET Vec and Jet4",80,-4,4);
  h_dPhi_phojet1_C=new TH1D("dPhi_phojet1_C","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_C=new TH1D("dPhi_phojet2_C","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phojet3_C=new TH1D("dPhi_phojet3_C","dphi between photon and Jet3",80,-4,4);
  h2_MET_dPhiMETj1_C=new TH2D("MET_dPhiMETj1_C","MET vs dPhi(MET, J1)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj2_C=new TH2D("MET_dPhiMETj2_C","MET vs dPhi(MET, J2)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj_C=new TH2D("MET_dPhiMETj_C","MET vs mindPhi(MET, J)",300,0,1500,200, 0, 4);
  h_SBins_v6_CD_EW_7bin_C = new TH1D("AllSBins_v6_CD_EW_7bin_C","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);
  h_SBins_v7_CD_SP_C = new TH1D("AllSBins_v7_CD_SP_C","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h2_nJetsMET_v2_C=new TH2D("nJetsMET_v2_C","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets2.size()-1,&(njets2[0]));
  h2_nJetsMET_C=new TH2D("nJetsMET_C","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets.size()-1,&(njets[0]));
  h_SBins_v6_CD_EW_50bin_C = new TH1D("AllSBins_v6_CD_EW_50bin_C","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_C = new TH1D("AllSBins_v6_CD_C","8 search bins : NJets x NbTags",8,1,9);

  h_ST_D=new TH1D("ST_D","ST",400,0,4000);
  h_MET_D=new TH1D("MET_D","MET",200,0,2000);
  h_nJets_D=new TH1D("nJets_D","nJets",25,0,25);
  h_BTags_D=new TH1D("nBTags_D","no. of B tags",10,0,10);
  h_BestPhotonPt_D=new TH1D("BestPhotonPt_D","Pt of the Best Photon",300,0,1500);
  h_JetPt_D=new TH1D("JetPt_D","Pt of the Jets",300,0,1500);
  h_BestPhotonEta_D=new TH1D("BestPhotonEta_D","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_D=new TH1D("BestPhotonPhi_D","Phi of the Best Photon",400,-5,5);
  h_JetEta_D=new TH1D("JetEta_D","Eta of the Jets",400,-5,5);
  h_JetPhi_D=new TH1D("JetPhi_D","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt_D=new TH2D("JetEta_Pt_D","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi_D=new TH2D("JetEta_Phi_D","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METjet1_D=new TH1D("dPhi_METjet1_D","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_D=new TH1D("dPhi_METjet2_D","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3_D=new TH1D("dPhi_METjet3_D","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4_D=new TH1D("dPhi_METjet4_D","dphi between MET Vec and Jet4",80,-4,4);
  h_dPhi_phojet1_D=new TH1D("dPhi_phojet1_D","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_D=new TH1D("dPhi_phojet2_D","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phojet3_D=new TH1D("dPhi_phojet3_D","dphi between photon and Jet3",80,-4,4);
  h2_MET_dPhiMETj1_D=new TH2D("MET_dPhiMETj1_D","MET vs dPhi(MET, J1)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj2_D=new TH2D("MET_dPhiMETj2_D","MET vs dPhi(MET, J2)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj_D=new TH2D("MET_dPhiMETj_D","MET vs mindPhi(MET, J)",300,0,1500,200, 0, 4);
  h_SBins_v6_CD_EW_7bin_D = new TH1D("AllSBins_v6_CD_EW_7bin_D","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);
  h_SBins_v7_CD_SP_D = new TH1D("AllSBins_v7_CD_SP_D","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h2_nJetsMET_v2_D=new TH2D("nJetsMET_v2_D","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets2.size()-1,&(njets2[0]));
  h2_nJetsMET_D=new TH2D("nJetsMET_D","x: nJets vs MET",metbin.size()-1,&(metbin[0]),njets.size()-1,&(njets[0]));
  h_SBins_v6_CD_EW_50bin_D = new TH1D("AllSBins_v6_CD_EW_50bin_D","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_D = new TH1D("AllSBins_v6_CD_D","8 search bins : NJets x NbTags",8,1,9);


  h_nvtx=new TH1D("nvtx","no. of vertices",100,0,100);
    h_nEvts=new TH1D("nEvents","no. of events in this tree",4,0,4);
  h_RunNum=new TH1I("runs","Run nos.",300000,0,300000);
  h_intLumi=new TH1D("intLumi","integrated luminosity in /fb",10000,25,200); 
  h_ST=new TH1D("ST","ST",400,0,4000);
  h_HT=new TH1D("HT","HT",400,0,4000);
  h_MET=new TH1D("MET","MET",200,0,2000);
  h2_MET_nJets=new TH2D("MET_nJets","MET (Y axis) wrt nJets (X axis)",25,0,25,200,0,2000);
  h2_MET_elepT=new TH2D("MET_elepT","MET (Y axis) wrt Electron pT (X axis)",300,0,1500,200,0,2000);
  h2_METvBin2_nJets=new TH2D("METvBin2_nJets","MET (Y axis) wrt nJets (X axis)",25,0,25,METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h2_nbjets_nJets=new TH2D("nbjets_nJets","nbjets (Y axis) wrt nJets (X axis)",25,0,25,10,0,10);
  h_METPhi=new TH1D("METPhi","MET Phi",400,-5,5);
  h_BTags=new TH1D("nBTags","no. of B tags",10,0,10);
  //  h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",300,0,1500);
  h_nJets=new TH1D("nJets","nJets",25,0,25);
  h_nremJets=new TH1D("nremJets","nJets",25,0,25);
  h_dR_bandgene=new TH1D("h_dR_bandgene","MinDr b/w gen b and gen e",500,0,5);
  h_deepcsv=new TH1D("h_deepcsv","Deep CSV",10,0,10);
  h_deepcsv_v2=new TH1D("h_deepcsv_v2","Deep CSV",10,0,10);
  h_deepcsv_v3=new TH1D("h_deepcsv_v3","Deep CSV",10,0,10);
  h_deepcsv_v4=new TH1D("h_deepcsv_v4","Deep CSV",10,0,10);
  h_dR_bandjets=new TH1D("h_dR_bandjets","MinDr b/w gen b and jets",500,0,5);
  h_dR_bandrecoe=new TH1D("h_dR_bandrecoe","MinDr b/w gen b and Reco EMobject",500,0,5);
  h_dR_geneandrecoe=new TH1D("h_dR_geneandrecoe","Dr b/w gen e and Reco EMobject",500,0,5);
  h_minDr_bestphoEle=new TH1D("h_minDr_bestphoEle","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoJets=new TH1D("h_minDr_bestphoJets","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_minDphi_bestphoJets=new TH1D("h_minDphi_bestphoJets","dphi b/w Reco Photon and Reco Jets ",500,-5,5);
  h_minDr_bestphoremEle=new TH1D("h_minDr_bestphoremEle","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoremJets=new TH1D("h_minDr_bestphoremJets","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h2_dRgenl1recol1_PID=new TH2D("h2_dRgenl1recol1_PID","Mindr b/w gen l1 and Reco l1 ",500,0,5,200,-100,100);
  h_dRgenl1recol1=new TH1D("h_dRgenl1recol1","Mindr b/w gen l1 and Reco l1 ",500,0,5);
  h_dRgenl2recol2=new TH1D("h_dRgenl2recol2","Mindr b/w gen l2 and Reco l2 ",500,0,5);
  h_dPhi_phoMET=new TH1D("dPhi_phoMET","dphi between photon and MET",80,-4,4);
  h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",300,0,1500);
  h_BestPhotonPt_vBin=new TH1D("BestPhotonPt_vBin","Photon pt in variable bins",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_0b=new TH1D("BestPhotonPt_0b","Pt of the Best Photon for bTag=0",300,0,1500);
  h_BestPhotonPt_ge1b=new TH1D("BestPhotonPt_ge1b","Pt of the Best Photon for bTag > 0",300,0,1500);
  h_BestPhotonPt_0b_vBin=new TH1D("BestPhotonPt_0b_vBin","Pt of the Best Photon for bTag=0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_ge1b_vBin=new TH1D("BestPhotonPt_ge1b_vBin","Pt of the Best Photon for bTag > 0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonEta=new TH1D("BestPhotonEta","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi=new TH1D("BestPhotonPhi","Phi of the Best Photon",400,-5,5);
  h2_BestPhotonEta_Qmulti=new TH2D("BestPhotonEta_Qmulti","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_BestPhotonEta_nJets=new TH2D("BestPhotonEta_nJets","x: Electron Eta vs charged multiplicity in the matching jet",200,-5,5,25,0,25);
  h2_BestPhotonEta_MET=new TH2D("BestPhotonEta_MET","x: Electron Eta vs charged multiplicity in the matching jet",200,-5,5,200,0,2000);
  h_NEMobj=new TH1D("NEMobj","No. of the Electrons",10,0,10);
  h_zpt=new TH1D("zPt","Pt of the z",300,0,1500);
  h_genzpt=new TH1D("genzPt","Pt of the gen z",300,0,1500);
  h_ElectronPt=new TH1D("ElectronPt","Pt of the Electrons",300,0,1500);
  h_ElectronEta=new TH1D("ElectronEta","Eta of the Electrons",400,-5,5);
  h_ElectronPhi=new TH1D("ElectronPhi","Phi of the Electrons",400,-5,5);
  h_JetPt=new TH1D("JetPt","Pt of the Jets",300,0,1500);
  h_JetEta=new TH1D("JetEta","Eta of the Jets",400,-5,5);
  h_JetPhi=new TH1D("JetPhi","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt=new TH2D("JetEta_Pt","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi=new TH2D("JetEta_Phi","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt1=new TH1D("JetPt1","Pt of the Jets",300,0,1500);
  h_JetEta1=new TH1D("JetEta1","Eta of the Jets",400,-5,5);
  h_JetPhi1=new TH1D("JetPhi1","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt1=new TH2D("JetEta_Pt1","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi1=new TH2D("JetEta_Phi1","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt2=new TH1D("JetPt2","Pt of the Jets",300,0,1500);
  h_JetEta2=new TH1D("JetEta2","Eta of the Jets",400,-5,5);
  h_JetPhi2=new TH1D("JetPhi2","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt2=new TH2D("JetEta_Pt2","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi2=new TH2D("JetEta_Phi2","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt3=new TH1D("JetPt3","Pt of the Jets",300,0,1500);
  h_JetEta3=new TH1D("JetEta3","Eta of the Jets",400,-5,5);
  h_JetPhi3=new TH1D("JetPhi3","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt3=new TH2D("JetEta_Pt3","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi3=new TH2D("JetEta_Phi3","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt4=new TH1D("JetPt4","Pt of the Jets",300,0,1500);
  h_JetEta4=new TH1D("JetEta4","Eta of the Jets",400,-5,5);
  h_JetPhi4=new TH1D("JetPhi4","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt4=new TH2D("JetEta_Pt4","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi4=new TH2D("JetEta_Phi4","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_remJetPt=new TH1D("remJetPt","Pt of the remJets",300,0,1500);
  h_remJetEta=new TH1D("remJetEta","Eta of the remJets",400,-5,5);
  h_remJetPhi=new TH1D("remJetPhi","Phi of the remJets",400,-5,5);
  h_leadElectronPt=new TH1D("leadElectronPt","Leading Electron Pt ",300,0,1500);
  h_leadElectronPhi=new TH1D("leadElectronPhi","Leading Electron Phi ",400,-5,5);
  h_leadElectronEta=new TH1D("leadElectronEta","Leading Electron Eta ",400,-5,5);
  h2_leadElectronEta_Phi=new TH2D("leadElectronEta_Phi","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  //  h2_leadElectronPt_Eta=new TH2D("leadElectronPt_Eta","Leading Electron Pt (x axis) vs Eta (yaxis)",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),EMEtaLowedge.size()-1,&(EMEtaLowedge[0]));
  h2_leadElectronPt_Eta=new TH2D("leadElectronPt_Eta","Leading Electron Pt (x axis) vs Eta (yaxis)",300,0,1500,200,-5,5);
  h2_leadElectronPt_Phi=new TH2D("leadElectronPt_Phi","Leading Electron Pt (x axis) vs Phi (yaxis)",300,0,1500,200,-5,5);
  h_leadJetPt=new TH1D("leadJetPt","Leading Jet Pt ",300,0,1500);
  h_leadJetPhi=new TH1D("leadJetPhi","Leading Jet Phi ",400,-5,5);
  h_leadJetEta=new TH1D("leadJetEta","Leading Jet Eta ",400,-5,5);
  h2_leadJetEta_Phi=new TH2D("leadJetEta_Phi","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_leadJetEta_Pt=new TH2D("leadJetEta_Pt","Leading Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_2leadJetEta_Pt=new TH2D("2leadJetEta_Pt","2nd Leading Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_3leadJetEta_Pt=new TH2D("3leadJetEta_Pt","3rd Leading Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_4leadJetEta_Pt=new TH2D("4leadJetEta_Pt","3rd Leading Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_BestPhoEta_Pt=new TH2D("BestPhoEta_Pt","Best Photon Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_ElectronEta_Phi=new TH2D("ElectronEta_Phi","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METlep=new TH1D("dPhi_METlep","dphi between MET Vec and Muon",40,0,4);
  h_dPhi_METlep1=new TH1D("dPhi_METlep1","dphi between leading MET Vec and Muon",40,0,4);
  h2_BestPhotonPt_jetmatchphoratio=new TH2D("BestPhotonPt_jetmatchphoratio","Best Photon Pt (x axis) vs jet(match to photon) Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
  h2_BestPhotonPt_jetphoratio=new TH2D("BestPhotonPt_jetphoratio","Best Photon Pt (x axis) vs jet Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
  h_minDphi_Zjet1=new TH1D("h_minDphi_Zjet1","dphi b/w Reco lepton and Reco first leading jet ",500,-5,5);
  h_minDphi_Elejet1=new TH1D("h_minDphi_Elejet1","dphi b/w Reco lepton and Reco first leading jet ",500,-5,5);
  h_minDphi_Elejet2=new TH1D("h_minDphi_Elejet2","dphi b/w Reco lepton and Reco Second leading jet ",500,-5,5);
  h_minDr_Zjet1=new TH1D("h_minDr_Zjet1","dr b/w Reco lepton and Reco first leading jet ",500,0,5);
  h_minDr_Elejet1=new TH1D("h_minDr_Elejet1","dr b/w Reco lepton and Reco first leading jet ",500,0,5);
  h_minDr_Elejet2=new TH1D("h_minDr_Elejet2","dr b/w Reco lepton and Reco Second leading jet ",500,0,5);
  h_minDr_Elejet3=new TH1D("h_minDr_Elejet3","dr b/w Reco lepton and Reco third leading jet ",500,0,5);
  h_minDr_Elejet4=new TH1D("h_minDr_Elejet4","dr b/w Reco lepton and Reco fourth leading jet ",500,0,5);
  h_minDr_EleJets=new TH1D("h_minDr_EleJets","Mindr b/w Reco lepton and Reco hadronic jets",500,0,5);
  h2_dPhivseta_jet1=new TH2D("h2_dPhivseta_jet1","dPhi b/w MET and 1st Jet (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_dPhivseta_jet2=new TH2D("h2_dPhivseta_jet2","dPhi b/w MET and 2nd Jet (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_dPhivseta_jet3=new TH2D("h2_dPhivseta_jet3","dPhi b/w MET and 3rd Jet (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_dPhivseta_jet4=new TH2D("h2_dPhivseta_jet4","dPhi b/w MET and 4th Jet (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_Phivseta_jet1=new TH2D("h2_Phivseta_jet1","1st Jet Phi (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_Phivseta_jet2=new TH2D("h2_Phivseta_jet2","2nd Jet Phi (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_Phivseta_jet3=new TH2D("h2_Phivseta_jet3","3rd Jet Phi (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h2_Phivseta_jet4=new TH2D("h2_Phivseta_jet4","4th Jet Phi (x axis) vs Eta (y axis)",200,-5,5,200,-5,5);
  h_dPhi_METjet1=new TH1D("dPhi_METjet1","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2=new TH1D("dPhi_METjet2","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3=new TH1D("dPhi_METjet3","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4=new TH1D("dPhi_METjet4","dphi between MET Vec and Jet4",80,-4,4);
  h_dPhi_phojet1=new TH1D("dPhi_phojet1","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2=new TH1D("dPhi_phojet2","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phojet3=new TH1D("dPhi_phojet3","dphi between photon and Jet3",80,-4,4);
  h_dPhi_phojet4=new TH1D("dPhi_phojet4","dphi between photon and Jet4",80,-4,4);
  h_MET_CaloMET=new TH1D("MET_CaloMET","MET/Calo MET ",500,0,10);
  h_dPhi_MET_CaloMET=new TH1D("dPhi_MET_CaloMET","dPhi(MET,Calo MET) ",80,-4,4);
  h_genzMass=new TH1D("genzMass","invariant mass from e- & e+",2000,0,500);
  h_invMass=new TH1D("invMass","invariant mass from e- & e+",2000,0,500);
  h2_HT5HT_dPhiMETj1=new TH2D("HT5HT_dPhiMETj1","HT5/HT vs dPhi(MET, J1)",200,0,4,100,0,3);
  h2_HT5HT_dPhiMETj2=new TH2D("HT5HT_dPhiMETj2","HT5/HT vs dPhi(MET, J2)",200,0,4,100,0,3);
  h2_HT5HT_dPhiMETj3=new TH2D("HT5HT_dPhiMETj3","HT5/HT vs dPhi(MET, J3)",200,0,4,100,0,3);
  h2_HT5HT_dPhiMETj4=new TH2D("HT5HT_dPhiMETj4","HT5/HT vs dPhi(MET, J4)",200,0,4,100,0,3);
  h2_JPt_dPhiMETj1=new TH2D("JPt_dPhiMETj1","1st lead Jet Pt vs dPhi(MET, J1)",200,0,4,300,0,1500);
  h2_JPt_dPhiMETj2=new TH2D("JPt_dPhiMETj2","2nd lead Jet Pt vs dPhi(MET, J2)",200,0,4,300,0,1500);
  h2_JPt_dPhiMETj3=new TH2D("JPt_dPhiMETj3","3rd lead Jet Pt vs dPhi(MET, J3)",200,0,4,300,0,1500);
  h2_JPt_dPhiMETj4=new TH2D("JPt_dPhiMETj4","4th lead Jet Pt vs dPhi(MET, J4)",200,0,4,300,0,1500);
  h2_MET_dPhiMETj1=new TH2D("MET_dPhiMETj1","MET vs dPhi(MET, J1)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj2=new TH2D("MET_dPhiMETj2","MET vs dPhi(MET, J2)",300,0,1500,200, 0, 4);
  h2_MET_dPhiMETj=new TH2D("MET_dPhiMETj","MET vs mindPhi(MET, J)",300,0,1500,200, 0, 4);
  h_HT5HT=new TH1D("HT5HT"," HT5/HT ",100,0,3);
  h2_njetnbjet_phopt_vBin=new TH2D("njetnbjet_phopt_vBin","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h2_njetnbjet_phopt=new TH2D("njetnbjet_phopt","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,300,0,1500);
  h_hadAk8jetPt=new TH1D("hadAk8jetPt","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_CM_Ele=new TH1D("Qmulti","charged multiplicity in jet matching Ele",50,0,50);
  h_EMObj_pT=new TH1D("EMObj_Pt","Pt of the EM object",300,0,1500);
  h_EMObj_Eta=new TH1D("EMObj_Eta","Eta of the EM object",400,-5,5);
  h_EMObj_Phi=new TH1D("EMObj_Phi","Phi of the EM object",400,-5,5);
   h2_PhoPtQMultJet=new TH2D("PhoPtQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2.size()-1,&(ptlow2[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
   h2_PhoPtMET=new TH2D("PhoPtMET","x: Photon Pt vs MET",300,0,1500,200,0,2000);
   h2_nJetsMET=new TH2D("nJetsMET","x: nJets vs MET",200,0,2000,25,0,25);
   h2_METQMultJet=new TH2D("METQMultJet","x: MET vs charged multiplicity in the matching jet",200,0,2000,50,0,50);
  h2_PhoPtQMultJet_v3=new TH2D("PhoPtQMultJet_v3","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,50,0,50);
   // h2_PhoPtQMultJet=new TH2D("PhoPtQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,25,0,25);
  h2_PhoPtQMultJet_v2=new TH2D("PhoPtQMultJet_v2","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2_v2.size()-1,&(ptlow2_v2[0]),QMultLowedge_v2.size()-1,&(QMultLowedge_v2[0]));
  //  h2_PhoPtnJets=new TH2D("PhoPtnJets","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]));
  h2_PhoPtnJets=new TH2D("PhoPtnJets","x: Photon Pt vs njets",300,0,1500,25,0,25);
  h3_PhoPtnJetsbtags=new TH3D("PhoPtnJetsbtags","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  // h3_PhoPtnJetsQmult=new TH3D("PhoPtnJetsQMult","x: Photon Pt vs no. of jets vs Qmult",ptlow2.size()-1,&(ptlow2[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h3_PhoPtnJetsQmult=new TH3D("PhoPtnJetsQMult","x: Photon Pt vs no. of jets vs Qmult",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  //  h2_PhoPtQMultJet=new TH2D("PhoPtQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",12,ptLow2,sizeof(QMultLow)/sizeof(double)-1,QMultLow);
  //  h2_nJetsQMultJet=new TH2D("nJetsQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_nJetsQMultJet=new TH2D("nJetsQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);
  h2_QMultlleadJetPt=new TH2D("QMultlleadJetPt","x: Lead Jet Pt vs y: Qmultiplicity in lead jet",300,0,1500,50,0,50);
  h2_QMultlleadbJet=new TH2D("QMultlleadbJet","x: Qmultiplicity in jet matched to e & y: Deep CSV for jet matched to e",50,0,50,300,0,3);
  h2_METleadbJet=new TH2D("METleadbJet","x: MET & y: Deep CSV for jet matched to e",200,0,2000,300,0,3);
  h2_QMultlleadbJet_v2=new TH2D("QMultlleadbJet_v2","x: Qmultiplicity in jet matched to EMobject as e & y: dR(b tag,EM object as e)",300,0,1500,300,-3,3);
  h2_btag_probwt=new TH2D("h2_btag_probwt","x : nBTags & y : wt * prob",50,0,50,2000,0,2);
  
  h_nvtx_elec0=new TH1D("nvtx_elec0","no. of vertices",100,0,100);
  h_ST_elec0=new TH1D("ST_elec0","ST",400,0,4000);
  h_MET_elec0=new TH1D("MET_elec0","MET",200,0,2000);
  h2_MET_nJets_elec0=new TH2D("MET_nJets_elec0","MET (Y axis) wrt nJets (X axis)",25,0,25,200,0,2000);
  h2_METvBin2_nJets_elec0=new TH2D("METvBin2_nJets_elec0","MET (Y axis) wrt nJets (X axis)",25,0,25,METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h2_nbjets_nJets_elec0=new TH2D("nbjets_nJets_elec0","nbjets (Y axis) wrt nJets (X axis)",25,0,25,10,0,10);
  h_BTags_elec0=new TH1D("nBTags_elec0","no. of B tags",10,0,10);
   h_nJets_elec0=new TH1D("nJets_elec0","nJets",25,0,25);
   h_nremJets_elec0=new TH1D("nremJets_elec0","nJets",25,0,25);
  h_METvBin2_elec0=new TH1D("METvBin2_elec0","MET in variable bins",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_minDr_bestphoEle_elec0=new TH1D("h_minDr_bestphoEle_elec0","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoJets_elec0=new TH1D("h_minDr_bestphoJets_elec0","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_minDr_bestphoremEle_elec0=new TH1D("h_minDr_bestphoremEle_elec0","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoremJets_elec0=new TH1D("h_minDr_bestphoremJets_elec0","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  // h_dPhi_METjet1_elec0=new TH1D("dPhi_METjet1_elec0","dphi between MET Vec and Jet1",80,-4,4);
  // h_dPhi_METjet2_elec0=new TH1D("dPhi_METjet2_elec0","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet1_elec0=new TH1D("dPhi_METjet1_elec0","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_elec0=new TH1D("dPhi_METjet2_elec0","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_METjet3_elec0=new TH1D("dPhi_METjet3_elec0","dphi between MET Vec and Jet3",80,-4,4);
  h_dPhi_METjet4_elec0=new TH1D("dPhi_METjet4_elec0","dphi between MET Vec and Jet4",80,-4,4);
  h_MET_CaloMET_elec0=new TH1D("MET_CaloMET_elec0","MET/Calo MET ",500,0,10);
  h_dPhi_MET_CaloMET_elec0=new TH1D("dPhi_MET_CaloMET_elec0","dPhi(MET,Calo MET) ",80,-4,4);
  h_HT5HT_elec0=new TH1D("HT5HT_elec0"," HT5/HT ",100,0,3);

  h_dPhi_phojet1_elec0=new TH1D("dPhi_phojet1_elec0","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_elec0=new TH1D("dPhi_phojet2_elec0","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phoMET_elec0=new TH1D("dPhi_phoMET_elec0","dphi between photon and MET",80,-4,4);
  h_mTPhoMET_elec0=new TH1D("mTPhoMET_elec0","mT b/w bestPhoton and MET",200,0,2000);
  h_BestPhotonPt_vBin_elec0=new TH1D("BestPhotonPt_vBin_elec0","Photon pt in variable bins",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_0b_elec0=new TH1D("BestPhotonPt_0b_elec0","Pt of the Best Photon for bTag=0",300,0,1500);
  h_BestPhotonPt_ge1b_elec0=new TH1D("BestPhotonPt_ge1b_elec0","Pt of the Best Photon for bTag > 0",300,0,1500);
  h_BestPhotonPt_0b_vBin_elec0=new TH1D("BestPhotonPt_0b_vBin_elec0","Pt of the Best Photon for bTag=0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_ge1b_vBin_elec0=new TH1D("BestPhotonPt_ge1b_vBin_elec0","Pt of the Best Photon for bTag > 0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_elec0=new TH1D("BestPhotonPt_elec0","Pt of the Best Photon",300,0,1500);
  h_BestPhotonEta_elec0=new TH1D("BestPhotonEta_elec0","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_elec0=new TH1D("BestPhotonPhi_elec0","Phi of the Best Photon",400,-5,5);
  h2_BestPhotonEta_Qmulti_elec0=new TH2D("BestPhotonEta_Qmulti_elec0","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_BestPhotonEta_nJets_elec0=new TH2D("BestPhotonEta_nJets_elec0","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),25,0,25);
  h2_BestPhotonEta_MET_elec0=new TH2D("BestPhotonEta_MET_elec0","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),200,0,2000);
  h_NEMobj_elec0=new TH1D("NEMobj_elec0","No. of the Photons",10,0,10);
  h_ElectronPt_elec0=new TH1D("ElectronPt_elec0","Pt of the Electrons",300,0,1500);
  h_ElectronEta_elec0=new TH1D("ElectronEta_elec0","Eta of the Electrons",400,-5,5);
  h_ElectronPhi_elec0=new TH1D("ElectronPhi_elec0","Phi of the Electrons",400,-5,5);
  h_JetPt_elec0=new TH1D("JetPt_elec0","Pt of the Jets",300,0,1500);
  h_JetEta_elec0=new TH1D("JetEta_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi_elec0=new TH1D("JetPhi_elec0","Phi of the Jets",400,-5,5);
  h_JetPt1_elec0=new TH1D("JetPt1_elec0","Pt of the Jets",300,0,1500);
  h_JetEta1_elec0=new TH1D("JetEta1_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi1_elec0=new TH1D("JetPhi1_elec0","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt1_elec0=new TH2D("JetEta_Pt1_elec0","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi1_elec0=new TH2D("JetEta_Phi1_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt2_elec0=new TH1D("JetPt2_elec0","Pt of the Jets",300,0,1500);
  h_JetEta2_elec0=new TH1D("JetEta2_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi2_elec0=new TH1D("JetPhi2_elec0","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt2_elec0=new TH2D("JetEta_Pt2_elec0","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi2_elec0=new TH2D("JetEta_Phi2_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt3_elec0=new TH1D("JetPt3_elec0","Pt of the Jets",300,0,1500);
  h_JetEta3_elec0=new TH1D("JetEta3_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi3_elec0=new TH1D("JetPhi3_elec0","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt3_elec0=new TH2D("JetEta_Pt3_elec0","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi3_elec0=new TH2D("JetEta_Phi3_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt4_elec0=new TH1D("JetPt4_elec0","Pt of the Jets",300,0,1500);
  h_JetEta4_elec0=new TH1D("JetEta4_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi4_elec0=new TH1D("JetPhi4_elec0","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt4_elec0=new TH2D("JetEta_Pt4_elec0","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi4_elec0=new TH2D("JetEta_Phi4_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_remJetPt_elec0=new TH1D("remJetPt_elec0","Pt of the remJets",300,0,1500);
  h_remJetEta_elec0=new TH1D("remJetEta_elec0","Eta of the remJets",400,-5,5);
  h_remJetPhi_elec0=new TH1D("remJetPhi_elec0","Phi of the remJets",400,-5,5);
  h2_leadElectronEta_Phi_elec0=new TH2D("leadElectronEta_Phi_elec0","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_leadElectronPt_Eta_elec0=new TH2D("leadElectronPt_Eta_elec0","Leading Electron Pt (x axis) vs Eta (yaxis)",300,0,1500,200,-5,5);
  h2_leadElectronPt_Phi_elec0=new TH2D("leadElectronPt_Phi_elec0","Leading Electron Pt (x axis) vs Phi (yaxis)",300,0,1500,200,-5,5);
  // h2_leadElectronPt_Eta_elec0=new TH2D("leadElectronPt_Eta_elec0","Leading Electron Pt (x axis) vs Eta (yaxis)",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),EMEtaLowedge.size()-1,&(EMEtaLowedge[0]));				 
  h_leadJetPt_elec0=new TH1D("leadJetPt_elec0","Leading Jet Pt ",300,0,1500);
  h_leadJetPhi_elec0=new TH1D("leadJetPhi_elec0","Leading Jet Phi ",400,-5,5);
  h_leadJetEta_elec0=new TH1D("leadJetEta_elec0","Leading Jet Eta ",400,-5,5);
  h2_leadJetEta_Phi_elec0=new TH2D("leadJetEta_Phi_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_njetnbjet_phopt_vBin_elec0=new TH2D("njetnbjet_phopt_vBin_elec0","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h2_njetnbjet_phopt_elec0=new TH2D("njetnbjet_phopt_elec0","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,300,0,1500);
  h_hadAk8jetPt_elec0=new TH1D("hadAk8jetPt_elec0","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_hadAk8Mass_elec0=new TH1D("hadAk8Mass_elec0","Soft dropped mass of AK8 Jet",1000,0,300);
    h_CM_Pho=new TH1D("Qmulti_elec0","charged multiplicity in jet matching Pho",50,0,50);
  h_EMObj_pT_elec0=new TH1D("EMObj_Pt_elec0","Pt of the EM object",300,0,1500);
  h2_PhoPtQMultJet_elec0=new TH2D("PhoPtQMultJet_elec0","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2.size()-1,&(ptlow2[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
 //  h2_PhoPtQMultJet_elec0=new TH2D("PhoPtQMultJet_elec0","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,25,0,25);
  // h2_PhoPtQMultJet_v2_elec0=new TH2D("PhoPtQMultJet_v2_elec0","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,50,0,50);
  //  h2_PhoPtnJets_elec0=new TH2D("PhoPtnJets_elec0","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]));
  h2_PhoPtnJets_elec0=new TH2D("PhoPtnJets_elec0","x: Photon Pt vs njets",300,0,1500,25,0,25);
  h3_PhoPtnJetsbtags_elec0=new TH3D("PhoPtnJetsbtags_elec0","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  h2_PhoPtQMultJet_v2_elec0=new TH2D("PhoPtQMultJet_v2_elec0","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2_v2.size()-1,&(ptlow2_v2[0]),QMultLowedge_v2.size()-1,&(QMultLowedge_v2[0]));
  //  h3_PhoPtnJetsQmult_elec0=new TH3D("PhoPtnJetsQMult_elec0","x: Photon Pt vs no. of jets vs Qmult",ptlow2.size()-1,&(ptlow2[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_PhoPtMET_elec0=new TH2D("PhoPtMET_elec0","x: Photon Pt vs MET",300,0,1500,200,0,2000);
   h2_nJetsMET_elec0=new TH2D("nJetsMET_elec0","x: nJets vs MET",25,0,25,200,0,2000);
   h2_METQMultJet_elec0=new TH2D("METQMultJet_elec0","x: MET vs charged multiplicity in the matching jet",200,0,2000,50,0,50);
  h2_PhoPtQMultJet_v3_elec0=new TH2D("PhoPtQMultJet_v3_elec0","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,50,0,50);
  h3_PhoPtnJetsQmult_elec0=new TH3D("PhoPtnJetsQMult_elec0","x: Photon Pt vs no. of jets vs Qmult",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_nJetsQMultJet_elec0=new TH2D("nJetsQMultJet_elec0","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);
  h2_QMultlleadJetPt_elec0=new TH2D("QMultlleadJetPt_elec0","x: Lead Jet Pt vs y: Qmultiplicity in lead jet",300,0,1500,50,0,50);
  h2_QMultlleadbJet_elec0=new TH2D("QMultlleadbJet_elec0","x: Qmultiplicity in jet matched to e & y: Deep CSV for jet matched to e",50,0,50,300,0,3);
  h2_QMultlleadbJet_v2_elec0=new TH2D("QMultlleadbJet_v2_elec0","x: Qmultiplicity in jet matched to EMobject as e & y: dR(b tag,EM object as e)",50,0,50,150,0,3);
  h2_BestPhotonPt_jetmatchphoratio_elec0=new TH2D("BestPhotonPt_jetmatchphoratio_elec0","Best Photon Pt (x axis) vs jet(match to photon) Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
  h2_BestPhotonPt_jetphoratio_elec0=new TH2D("BestPhotonPt_jetphoratio_elec0","Best Photon Pt (x axis) vs jet Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);


  
  h_nvtx_elec1_closure=new TH1D("nvtx_elec1_closure","no. of vertices",100,0,100);
  h_ST_elec1_closure=new TH1D("ST_elec1_closure","ST",400,0,4000);
  h_MET_elec1_closure=new TH1D("MET_elec1_closure","MET",200,0,2000);
  h2_MET_nJets_elec1_closure=new TH2D("MET_nJets_elec1_closure","MET (Y axis) wrt nJets (X axis)",25,0,25,200,0,2000);
  h2_METvBin2_nJets_elec1_closure=new TH2D("METvBin2_nJets_elec1_closure","MET (Y axis) wrt nJets (X axis)",25,0,25,METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h2_nbjets_nJets_elec1_closure=new TH2D("nbjets_nJets_elec1_closure","nbjets (Y axis) wrt nJets (X axis)",25,0,25,10,0,10);
  h_BTags_elec1_closure=new TH1D("nBTags_elec1_closure","no. of B tags",10,0,10);
  h_nJets_elec1_closure=new TH1D("nJets_elec1_closure","nJets",25,0,25);
  h_nremJets_elec1_closure=new TH1D("nremJets_elec1_closure","nJets",25,0,25);
  h_METvBin2_elec1_closure=new TH1D("METvBin2_elec1_closure","MET in variable bins",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_minDr_bestphoremEle_elec1_closure=new TH1D("h_minDr_bestphoremEle_elec1_closure","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoremJets_elec1_closure=new TH1D("h_minDr_bestphoremJets_elec1_closure","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_minDr_bestphoEle_elec1_closure=new TH1D("h_minDr_bestphoEle_elec1_closure","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoJets_elec1_closure=new TH1D("h_minDr_bestphoJets_elec1_closure","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_dPhi_METjet1_elec1_closure=new TH1D("dPhi_METjet1_elec1_closure","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_elec1_closure=new TH1D("dPhi_METjet2_elec1_closure","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_phojet1_elec1_closure=new TH1D("dPhi_phojet1_elec1_closure","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_elec1_closure=new TH1D("dPhi_phojet2_elec1_closure","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phoMET_elec1_closure=new TH1D("dPhi_phoMET_elec1_closure","dphi between photon and MET",80,-4,4);
  h_mTPhoMET_elec1_closure=new TH1D("mTPhoMET_elec1_closure","mT b/w bestPhoton and MET",200,0,2000);
  h_BestPhotonPt_vBin_elec1_closure=new TH1D("BestPhotonPt_vBin_elec1_closure","Photon pt in variable bins",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_0b_elec1_closure=new TH1D("BestPhotonPt_0b_elec1_closure","Pt of the Best Photon for bTag=0",300,0,1500);
  h_BestPhotonPt_ge1b_elec1_closure=new TH1D("BestPhotonPt_ge1b_elec1_closure","Pt of the Best Photon for bTag > 0",300,0,1500);
  h_BestPhotonPt_0b_vBin_elec1_closure=new TH1D("BestPhotonPt_0b_vBin_elec1_closure","Pt of the Best Photon for bTag=0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_ge1b_vBin_elec1_closure=new TH1D("BestPhotonPt_ge1b_vBin_elec1_closure","Pt of the Best Photon for bTag > 0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_elec1_closure=new TH1D("BestPhotonPt_elec1_closure","Pt of the Best Photon",300,0,1500);
  h_BestPhotonEta_elec1_closure=new TH1D("BestPhotonEta_elec1_closure","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi_elec1_closure=new TH1D("BestPhotonPhi_elec1_closure","Phi of the Best Photon",400,-5,5);
  h2_BestPhotonEta_Qmulti_elec1_closure=new TH2D("BestPhotonEta_Qmulti_elec1_closure","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_BestPhotonEta_nJets_elec1_closure=new TH2D("BestPhotonEta_nJets_elec1_closure","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),25,0,25);
  h2_BestPhotonEta_MET_elec1_closure=new TH2D("BestPhotonEta_MET_elec1_closure","x: Electron Eta vs charged multiplicity in the matching jet",EMEtaLowedge.size()-1,&(EMEtaLowedge[0]),200,0,2000);
  h_NEMobj_elec1_closure=new TH1D("NEMobj_elec1_closure","No. of the Pred. Photons",10,0,10);
  h_ElectronPt_elec1_closure=new TH1D("ElectronPt_elec1_closure","Pt of the Electrons",300,0,1500);
  h_ElectronEta_elec1_closure=new TH1D("ElectronEta_elec1_closure","Eta of the Electrons",400,-5,5);
  h_ElectronPhi_elec1_closure=new TH1D("ElectronPhi_elec1_closure","Phi of the Electrons",400,-5,5);
  h_JetPt_elec1_closure=new TH1D("JetPt_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta_elec1_closure=new TH1D("JetEta_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi_elec1_closure=new TH1D("JetPhi_elec1_closure","Phi of the Jets",400,-5,5);
  h_JetPt1_elec1_closure=new TH1D("JetPt1_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta1_elec1_closure=new TH1D("JetEta1_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi1_elec1_closure=new TH1D("JetPhi1_elec1_closure","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt1_elec1_closure=new TH2D("JetEta_Pt1_elec1_closure","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi1_elec1_closure=new TH2D("JetEta_Phi1_elec1_closure","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt2_elec1_closure=new TH1D("JetPt2_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta2_elec1_closure=new TH1D("JetEta2_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi2_elec1_closure=new TH1D("JetPhi2_elec1_closure","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt2_elec1_closure=new TH2D("JetEta_Pt2_elec1_closure","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi2_elec1_closure=new TH2D("JetEta_Phi2_elec1_closure","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt3_elec1_closure=new TH1D("JetPt3_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta3_elec1_closure=new TH1D("JetEta3_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi3_elec1_closure=new TH1D("JetPhi3_elec1_closure","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt3_elec1_closure=new TH2D("JetEta_Pt3_elec1_closure","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi3_elec1_closure=new TH2D("JetEta_Phi3_elec1_closure","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_JetPt4_elec1_closure=new TH1D("JetPt4_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta4_elec1_closure=new TH1D("JetEta4_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi4_elec1_closure=new TH1D("JetPhi4_elec1_closure","Phi of the Jets",400,-5,5);
  h2_JetEta_Pt4_elec1_closure=new TH2D("JetEta_Pt4_elec1_closure","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi4_elec1_closure=new TH2D("JetEta_Phi4_elec1_closure","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
   h_remJetPt_elec1_closure=new TH1D("remJetPt_elec1_closure","Pt of the remJets",300,0,1500);
  h_remJetEta_elec1_closure=new TH1D("remJetEta_elec1_closure","Eta of the remJets",400,-5,5);
  h_remJetPhi_elec1_closure=new TH1D("remJetPhi_elec1_closure","Phi of the remJets",400,-5,5);
  h2_leadElectronEta_Phi_elec1_closure=new TH2D("leadElectronEta_Phi_elec1_closure","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_leadElectronPt_Eta_elec1_closure=new TH2D("leadElectronPt_Eta_elec1_closure","Leading Electron Pt (x axis) vs Eta (yaxis)",300,0,1500,200,-5,5);
  //  h2_leadElectronPt_Eta_elec1_closure=new TH2D("leadElectronPt_Eta_elec1_closure","Leading Electron Pt (x axis) vs Eta (yaxis)",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),EMEtaLowedge.size()-1,&(EMEtaLowedge[0]));
  h_leadJetPt_elec1_closure=new TH1D("leadJetPt_elec1_closure","Leading Jet Pt ",300,0,1500);
  h_leadJetPhi_elec1_closure=new TH1D("leadJetPhi_elec1_closure","Leading Jet Phi ",400,-5,5);
  h_leadJetEta_elec1_closure=new TH1D("leadJetEta_elec1_closure","Leading Jet Eta ",400,-5,5);
  h2_leadJetEta_Phi_elec1_closure=new TH2D("leadJetEta_Phi_elec1_closure","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_njetnbjet_phopt_vBin_elec1_closure=new TH2D("njetnbjet_phopt_vBin_elec1_closure","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h2_njetnbjet_phopt_elec1_closure=new TH2D("njetnbjet_phopt_elec1_closure","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,300,0,1500);
  h_hadAk8jetPt_elec1_closure=new TH1D("hadAk8jetPt_elec1_closure","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_hadAk8Mass_elec1_closure=new TH1D("hadAk8Mass_elec1_closure","Soft dropped mass of AK8 Jet",1000,0,300);
  h_CM_elec1_closure=new TH1D("Qmulti_elec1_closure","charged multiplicity in jet matching Pho",50,0,50);
  h_EMObj_pT_elec1_closure=new TH1D("EMObj_Pt_elec1_closure","Pt of the EM object",300,0,1500);
  h2_PhoPtQMultJet_elec1_closure=new TH2D("PhoPtQMultJet_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2.size()-1,&(ptlow2[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_PhoPtQMultJet_v2_elec1_closure=new TH2D("PhoPtQMultJet_v2_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",ptlow2_v2.size()-1,&(ptlow2_v2[0]),QMultLowedge_v2.size()-1,&(QMultLowedge_v2[0]));
  h2_PhoPtMET_elec1_closure=new TH2D("PhoPtMET_elec1_closure","x: Photon Pt vs MET",300,0,1500,200,0,2000);
   h2_nJetsMET_elec1_closure=new TH2D("nJetsMET_elec1_closure","x: nJets vs MET",25,0,25,200,0,2000);
   h2_METQMultJet_elec1_closure=new TH2D("METQMultJet_elec1_closure","x: MET vs charged multiplicity in the matching jet",200,0,2000,50,0,50);
  h2_PhoPtQMultJet_v3_elec1_closure=new TH2D("PhoPtQMultJet_v3_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",300,0,1500,50,0,50);
  //  h2_PhoPtnJets_elec1_closure=new TH2D("PhoPtnJets_elec1_closure","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]));
  h2_PhoPtnJets_elec1_closure=new TH2D("PhoPtnJets_elec1_closure","x: Photon Pt vs njets",300,0,1500,25,0,25);
  h3_PhoPtnJetsbtags_elec1_closure=new TH3D("PhoPtnJetsbtags_elec1_closure","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  h2_nJetsQMultJet_elec1_closure=new TH2D("nJetsQMultJet_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);
  h3_PhoPtnJetsQmult_elec1_closure=new TH3D("PhoPtnJetsQMult_elec1_closure","x: Photon Pt vs no. of jets vs Qmult",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  //  h3_PhoPtnJetsQmult_elec1_closure=new TH3D("PhoPtnJetsQMult_elec1_closure","x: Photon Pt vs no. of jets vs Qmult",ptlow2.size()-1,&(ptlow2[0]),nJetsLowedgev1.size()-1,&(nJetsLowedgev1[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_BestPhotonPt_jetmatchphoratio_elec1_closure=new TH2D("BestPhotonPt_jetmatchphoratio_elec1_closure","Best Photon Pt (x axis) vs jet(match to photon) Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
  h2_BestPhotonPt_jetphoratio_elec1_closure=new TH2D("BestPhotonPt_jetphoratio_elec1_closure","Best Photon Pt (x axis) vs jet Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);

  h_intLumi_EW=new TH1D("intLumi_EW","2016 integrated luminosity in /fb",2500,25,50); 
  h_ST_EW=new TH1D("ST_EW","ST 2016",400,0,4000);
  h_MET_EW=new TH1D("MET_EW","MET 2016",200,0,2000);
  h_BTags_EW=new TH1D("nBTags_EW","no. of B tags 2016",10,0,10);
  h_BestPhotonPt_EW=new TH1D("BestPhotonPt_EW","Pt of the Best Photon 2016",150,0,1500);
  h_nJets_EW=new TH1D("nJets_EW","nJets 2016",25,0,25);

  h_intLumi_EW_noSB=new TH1D("intLumi_EW_noSB"," integrated luminosity in /fb",2500,25,50); 
  h_ST_EW_noSB=new TH1D("ST_EW_noSB","ST ",400,0,4000);
  h_MET_EW_noSB=new TH1D("MET_EW_noSB","MET ",200,0,2000);
  h_BTags_EW_noSB=new TH1D("nBTags_EW_noSB","no. of B tags ",10,0,10);
  h_BestPhotonPt_EW_noSB=new TH1D("BestPhotonPt_EW_noSB","Pt of the Best Photon ",150,0,1500);
  h_nJets_EW_noSB=new TH1D("nJets_EW_noSB","nJets",25,0,25);

  h_intLumi_EW_SB=new TH1D("intLumi_EW_SB"," integrated luminosity in /fb",2500,25,50); 
  h_ST_EW_SB=new TH1D("ST_EW_SB","ST ",400,0,4000);
  h_MET_EW_SB=new TH1D("MET_EW_SB","MET ",200,0,2000);
  h_BTags_EW_SB=new TH1D("nBTags_EW_SB","no. of B tags ",10,0,10);
  h_BestPhotonPt_EW_SB=new TH1D("BestPhotonPt_EW_SB","Pt of the Best Photon ",150,0,1500);
  h_nJets_EW_SB=new TH1D("nJets_EW_SB ","nJets",25,0,25);


  h_intLumi_EW_wtag=new TH1D("intLumi_EW_wtag"," integrated luminosity in /fb",2500,25,50); 
  h_ST_EW_wtag=new TH1D("ST_EW_wtag","ST ",400,0,4000);
  h_MET_EW_wtag=new TH1D("MET_EW_wtag","MET ",200,0,2000);
  h_BTags_EW_wtag=new TH1D("nBTags_EW_wtag","no. of B tags ",10,0,10);
  h_BestPhotonPt_EW_wtag=new TH1D("BestPhotonPt_EW_wtag","Pt of the Best Photon ",150,0,1500);
  h_nJets_EW_wtag=new TH1D("nJets_EW_wtag","nJets",25,0,25);


  h_intLumi_EW_htag=new TH1D("intLumi_EW_htag","2016 integrated luminosity in /fb",2500,25,50); 
  h_ST_EW_htag=new TH1D("ST_EW_htag","ST 2016",400,0,4000);
  h_MET_EW_htag=new TH1D("MET_EW_htag","MET 2016",200,0,2000);
  h_BTags_EW_htag=new TH1D("nBTags_EW_htag","no. of B tags 2016",10,0,10);
  h_BestPhotonPt_EW_htag=new TH1D("BestPhotonPt_EW_htag","Pt of the Best Photon 2016",150,0,1500);
  h_nJets_EW_htag=new TH1D("nJets_EW_htag","nJets 2016",25,0,25);

  h_intLumi_SP=new TH1D("intLumi_SP","integrated luminosity in /fb",2500,25,50); 
  h_ST_SP=new TH1D("ST_SP","ST",400,0,4000);
  h_MET_SP=new TH1D("MET_SP","MET",200,0,2000);
  h_BTags_SP=new TH1D("nBTags_SP","no. of B tags",10,0,10);
  h_BestPhotonPt_SP=new TH1D("BestPhotonPt_SP","Pt of the Best Photon",150,0,1500);
  h_nJets_SP=new TH1D("nJets_SP","nJets",25,0,25);

  h_intLumi_2018=new TH1D("intLumi_2018","integrated luminosity in /fb",2500,25,50); 
  h_ST_2018=new TH1D("ST_2018","ST",400,0,4000);
  h_MET_2018=new TH1D("MET_2018","MET",200,0,2000);
  h_BTags_2018=new TH1D("nBTags_2018","no. of B tags",10,0,10);
  h_BestPhotonPt_2018=new TH1D("BestPhotonPt_2018","Pt of the Best Photon",150,0,1500);
  h_nJets_2018=new TH1D("nJets_2018","nJets",25,0,25);

  h_GenWpt=new TH1D("GenWpt","Gen W Pt",200,0,2000);
  h_GenWeta=new TH1D("GenWeta","Gen W #eta",200,0,5);
  h_GenWpt1=new TH1D("GenWpt1","Gen W Pt (for events only have 1 had jet)",200,0,2000);
  h_GenWM1_1=new TH1D("GenWM1_1","Jet Mass (for events only have 1 had jet)",200,0,200);
  h_GenWpt1_1=new TH1D("GenWpt1_1","Jet Pt (for events only have 1 had jet)",200,0,2000);
  h_GenWeta1=new TH1D("GenWeta1","Gen W #eta (for events only have 1 had jet)",200,0,5);
  h_GenWpt2_1=new TH1D("GenWpt2_1","Jet1 Pt  (for events only have 2 had jet)",200,0,2000);
  h_GenWeta2_1=new TH1D("GenWeta2_1","Jet1 #eta (for events only have 2 had jet)",200,0,5);
  h_GenWM2_1=new TH1D("GenWM2_1","Jet1 Mass  (for events only have 2 had jet)",200,0,200);
  h_GenWpt2_2=new TH1D("GenWpt2_2","Jet2 Pt (for events only have 2 had jet)",200,0,2000);
  h_GenWeta2_2=new TH1D("GenWeta2_2","Jet2 #eta (for events only have 2 had jet)",200,0,5);
  h_GenWM2_2=new TH1D("GenWM2_2","Jet2 Mass  (for events only have 2 had jet)",200,0,200);
  h_GenWpt2=new TH1D("GenWpt2","Gen W Pt (for events only have 2 had jet)",200,0,2000);
  h_GenWeta2=new TH1D("GenWeta2","Gen W #eta (for events only have 2 had jet)",200,0,5);
  /* h_nHadJets=new TH1D("nHadJets","no. of jets(only hadronic jets,not counting photon)",25,0,25); */
  h_BTags_nAk8jet1=new TH1D("BTags_nAk8jet1","no. of b jets in events having 1 Ak8 jets (atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);
  h_BTags_nAk8jet2=new TH1D("BTags_nAk8jet2","no. of b jets in events having 2 Ak8 jets (atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);
  h_BTags_nAk8jet3=new TH1D("BTags_nAk8jet3","no. of b jets in events having 3 Ak8 jets (atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);
  h_BTags_nAk8jet_ge1=new TH1D("BTags_nAk8jet_ge1","no. of b jets (after atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);
  h_nHadJets_nAk8jet_ge1=new TH1D("nHadJets_nAk8jet_ge1","no. of Ak4  jets (after atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);
  h_nHadAk8Jets_nAk8jet_ge1=new TH1D("nHadAk8Jets_nAk8jet_ge1","no. of Ak8  jets (after atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range)",25,0,25);

  h_BTags_nAk8jet_jet2to5=new TH1D("BTags_nAk8jet_jet2to5","no. of b jets  ( 2<=njet<=5 )",25,0,25);
  h_nHadJets_nAk8jet_jet2to5=new TH1D("nHadJets_nAk8jet_jet2to5","no. of Ak4  jets ( 2<=njet<=5 )",25,0,25);
  h_nHadAk8Jets_nAk8jet_jet2to5=new TH1D("nHadAk8Jets_nAk8jet_jet2to5","no. of Ak8  jets ( 2<=njet<=5 )",25,0,25);

  h_BTags_nAk8jet_jetge6=new TH1D("BTags_nAk8jet_jetge6","no. of b jets ( njet>=6 )",25,0,25);
  h_nHadJets_nAk8jet_jetge6=new TH1D("nHadJets_nAk8jet_jetge6","no. of Ak4  jets ( njet>=6 )",25,0,25);
  h_nHadAk8Jets_nAk8jet_jetge6=new TH1D("nHadAk8Jets_nAk8jet_jetge6","no. of Ak8  jets ( njet>=6 )",25,0,25);

  h_nHadJets_nAk8jet0_SP=new TH1D("nHadJets_nAk8jet0_SP","no. of Ak4  jets ( njet>=6 )",25,0,25);
  h_nHadAk8Jets_nAk8jet0_SP=new TH1D("nHadAk8Jets_nAk8jet0_SP","no. of Ak8  jets ( njet>=6 )",25,0,25);

  h_nHadJets_nAk8jet_jet2to5_noEW=new TH1D("nHadJets_nAk8jet_jet2to5_noEW","no. of Ak4  jets ( 2<=njet<=5 )",25,0,25);
  h_nHadJets_nAk8jet_jetge6_EW=new TH1D("nHadJets_nAk8jet_jetge6_EW","no. of Ak4  jets ( njet>=6 )",25,0,25);
  h_nHadJets_nAk8jet_jetge6_noEW=new TH1D("nHadJets_nAk8jet_jetge6_noEW","no. of Ak4  jets ( njet>=6 )",25,0,25);


  h_hadAk8Mass=new TH1D("hadAk8Mass","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_vBin=new TH1D("hadAk8Mass_vBin","Soft dropped Mass of AK8 Jet using variable binning",Ak8_vMass_EW.size()-1,&(Ak8_vMass_EW[0]));
  h_hadAk8Mass_EW_vBin=new TH1D("hadAk8Mass_EW_vBin","Soft dropped Mass of AK8 Jet using variable binning after EW selection",Ak8_vMass_EW.size()-1,&(Ak8_vMass_EW[0]));

  h_hadAk8Mass_EW_htag_vBin=new TH1D("hadAk8Mass_EW_htag_vBin","Soft dropped Mass of AK8 Jet using variable binning after EW selection",Ak8_vMass_EW.size()-1,&(Ak8_vMass_EW[0]));
  h_hadAk8Mass_SP_vBin=new TH1D("hadAk8Mass_SP_vBin","Soft dropped Mass of AK8 Jet using variable binning after SP selection",Ak8_vMass_EW.size()-1,&(Ak8_vMass_EW[0]));
  h_hadAk8Mass_matchedW=new TH1D("hadAk8Mass_matchedW","Soft dropped Mass of AK8 Jet which are matched with W ",1000,0,200);
  h_hadAk8Mass_Ak8jet2to5=new TH1D("hadAk8Mass_Ak8jet2to5","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jetge6=new TH1D("hadAk8Mass_Ak8jetge6","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet2to5_noEW=new TH1D("hadAk8Mass_Ak8jet2to5_noEW","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jetge6_EW=new TH1D("hadAk8Mass_Ak8jetge6_EW","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jetge6_noEW=new TH1D("hadAk8Mass_Ak8jetge6_noEW","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet0=new TH1D("hadAk8Mass_Ak8jet0","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet0_SP=new TH1D("hadAk8Mass_Ak8jet0_EW_SP","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet0_EW=new TH1D("hadAk8Mass_Ak8jet0_EW","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet0_EW_SB=new TH1D("hadAk8Mass_Ak8jet0_EW_SB","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_Ak8jet0_EW_noSB=new TH1D("hadAk8Mass_Ak8jet0_EW_noSB","Soft dropped Mass of leading AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW=new TH1D("hadAk8Mass_EW","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_noSB=new TH1D("hadAk8Mass_EW_noSB","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_SB=new TH1D("hadAk8Mass_EW_SB","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_wtag=new TH1D("hadAk8Mass_EW_wtag","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_htag=new TH1D("hadAk8Mass_EW_htag","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_wtag_A=new TH1D("hadAk8Mass_EW_wtag_A","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_htag_A=new TH1D("hadAk8Mass_EW_htag_A","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_wtag_B=new TH1D("hadAk8Mass_EW_wtag_B","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_htag_B=new TH1D("hadAk8Mass_EW_htag_B","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_wtag_C=new TH1D("hadAk8Mass_EW_wtag_C","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_htag_C=new TH1D("hadAk8Mass_EW_htag_C","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_wtag_D=new TH1D("hadAk8Mass_EW_wtag_D","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Mass_EW_htag_D=new TH1D("hadAk8Mass_EW_htag_D","Soft dropped Mass of AK8 Jet",1000,0,300);

  h_hadAk8Mass_EW_nAk8jet_ge1=new TH1D("hadAk8Mass_EW_nAk8jet_ge1","Soft dropped Mass of AK8 Jet after atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range",1000,0,200);
  h_hadAk8Mass_SP=new TH1D("hadAk8Mass_SP","Soft dropped Mass of AK8 Jet",1000,0,300);
  h_hadAk8Pt=new TH1D("hadAk8Pt","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_hadAk8Pt_matchedW=new TH1D("hadAk8Pt_matchedW"," Pt of AK8 Jet which are matched with W",2000,0,1000);
  h_hadAk8Pt_Ak8jet2to5=new TH1D("hadAk8Pt_Ak8jet2to5","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jetge6=new TH1D("hadAk8Pt_Ak8jetge6","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jet0=new TH1D("hadAk8Pt_Ak8jet0","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jet0_EW_noSB=new TH1D("hadAk8Pt_Ak8jet0_EW_noSB","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jet0_EW_SB=new TH1D("hadAk8Pt_Ak8jet0_EW_SB","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jet0_EW=new TH1D("hadAk8Pt_Ak8jet0_EW","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_Ak8jet0_SP=new TH1D("hadAk8Pt_Ak8jet0_EW_SP","Pt of leading AK8 Jet",2000,0,1000);
  h_hadAk8Pt_EW=new TH1D("hadAk8Pt_EW","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_hadAk8Pt_EW_nAk8jet_ge1=new TH1D("hadAk8Pt_EW_nAk8jet_ge1 ","Soft dropped Pt of AK8 Jet after atleast 1 Ak8 jet mass in 65 GeV - 100 GeV range",2000,0,1000);
  h_hadAk8Pt_SP=new TH1D("hadAk8Pt_SP","Soft dropped Pt of AK8 Jet",2000,0,1000);

  /* h_HT=new TH1D("HT","HT",400,0,4000); */
  /* h_MHT=new TH1D("MHT","MHT",200,0,2000); */
  /* h_MHTstar=new TH1D("MHTstar","MHT calculated using ST like definition",200,0,2000); */
  
  h2_PtPhotonvsMET=new TH2D("BestPhotonPtvsMET","Best photon Pt vs MET",150,0,1500,200,0,2000);
  h2_GenPhotonvsGenMET=new TH2D("GenPhotonvsGenMET","Gen photon Pt vs GenMET",150,0,1500,200,0,2000);
  h2_GenWvsnjet=new TH2D("GenWvsnjet","Gen W Pt vs njets",150,0,1500,20,0,20);
  h_mTPhoMET=new TH1D("mTPhoMET","mT b/w bestPhoton and MET",200,0,2000);

  h_dR_jetandW=new TH1D("dR_jetandW","dR between jet and W (for events only have 1 had jet)",200,0,5);
  h_dR_jet1andW=new TH1D("dR_jet1andW","dR between jet1 and W (for events only have 2 had jet)",200,0,5);
  h_dR_jet2andW=new TH1D("dR_jet2andW","dR between jet2 and W (for events only have 2 had jet)",200,0,5);
  h_dR_jet1andjet2=new TH1D("dR_jet1andjet2","dR between jet1 and jet2 (for events only have 2 had jet)",200,0,5);
  h_dR_Genpho_Genjet=new TH1D("dR_Genpho_Genjet","dR between gen photon and gen jet",100,0,5);
  h_dR_q_b_matched=new TH1D("dR_q_b_matched","dR between gen b quark and gen jet from W",100,0,5);

  h_mindr_lep_goodph=new TH1D("h_mindr_lep_goodph","Mindr b/w gen lepton and good Photon ",500,0,5);
  h_mindr_ph_lep=new TH1D("h_mindr_ph_lep","Mindr b/w good Photon and gen lepton ",500,0,5);
  h_mindr_ph_ele=new TH1D("h_mindr_ph_ele","Mindr b/w good Photon and gen electron ",500,0,5);
  h_mindr_ph_mu=new TH1D("h_mindr_ph_mu","Mindr b/w good Photon and gen muon ",500,0,5);
  h_mindr_ph_tau=new TH1D("h_mindr_ph_tau","Mindr b/w good Photon and gen tau ",500,0,5);
  h_mindr_genph_lep=new TH1D("h_mindr_genph_lep","Mindr b/w gen Photon and gen lepton ",200,-100,100);
  h_mindr_genph_had=new TH1D("h_mindr_genph_had","Mindr b/w gen Photon and quarks ",500,0,5);
  h_madminphotonDR=new TH1D("h_madminphotonDR","MinDr between the #gamma and quarks (q,g) using madMinPhotonDeltaR ",500,0,5);
  h_mindr_goodph_lep=new TH1D("h_mindr_goodph_lep","MinDr between the good #gamma and gen lepton",500,0,5);
  h_mindr_goodph_ph=new TH1D("h_mindr_goodph_ph","Mindr b/w good photon and gen Photon ",500,0,5);
  h_mindr_goodph_had=new TH1D("h_mindr_goodph_had","Mindr b/w good photon and quarks ",500,0,5);
  h_mindr_gentau_jet2=new TH1D("h_mindr_gentau_jet2","Mindr b/w gen tau and hadjets ",500,0,5);
  h_mindr_gentau_jet=new TH1D("h_mindr_gentau_jet","Mindr b/w gen tau and hadjets ",500,0,5);
  h_mindr_gentau_pt=new TH1D("h_mindr_gentau_pt","Pt for gen tau ",2000,0,500);
  h_mindr_gentau_ele=new TH1D("h_mindr_gentau_ele","Mindr b/w gen tau and Electron ",500,0,5);
  h_mindr_gentau_mu=new TH1D("h_mindr_gentau_mu","Mindr b/w gen tau and Muon ",500,0,5);
  h_minDr_bestphoEle_SP=new TH1D("h_minDr_bestphoEle_SP","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoJets_SP=new TH1D("h_minDr_bestphoJets_SP","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_minDr_bestphoEle_EW=new TH1D("h_minDr_bestphoEle_EW","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoJets_EW=new TH1D("h_minDr_bestphoJets_EW","Mindr b/w Reco Photon and Reco Jets ",500,0,5);


  // for numerator

  h_nEvts_num=new TH1D("nEvents_num","no. of events in this tree (for numerator)",4,0,4);
  h_RunNum_num=new TH1I("runs_num","Run nos.",300000,0,300000);
  h_intLumi_num=new TH1D("intLumi_num","integrated luminosity in /fb",2500,25,50); 
  h_ST_num=new TH1D("ST_num","ST",400,0,4000);
  h_MET_num=new TH1D("MET_num","MET",200,0,2000);
  /* h_nHadJets_num=new TH1D("nHadJets_num","no. of jets(only hadronic jets,not counting photon)",25,0,25); */
  h_BTags_num=new TH1D("nBTags_num","no. of B tags",10,0,10);
  h_BestPhotonPt_num=new TH1D("BestPhotonPt_num","Pt of the Best Photon",150,0,1500);
  h_METvBin=new TH1D("METvBin","MET in variable bins",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));//Ak8_vMass_EW
  h_METvBin_EW=new TH1D("METvBin_EW","MET in variable bins after EW selctions",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin_EW_htag=new TH1D("METvBin_EW_htag","MET in variable bins after EW selctions",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin_SP=new TH1D("METvBin_SP","MET in variable bins after SP elections",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin_EW_v1=new TH1D("METvBin_EW_v1","MET in variable bins after EW selctions",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));
  h_METvBin_EW_htag_v1=new TH1D("METvBin_EW_htag_v1","MET in variable bins after EW selctions",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));
  h_METvBin_SP_v1=new TH1D("METvBin_SP_v1","MET in variable bins after SP elections",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));
  h_METvBin_EW_htag_v2=new TH1D("METvBin_EW_htag_v2","MET in variable bins after EW selctions",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_EW_v2=new TH1D("METvBin_EW_v2","MET in variable bins after EW selctions",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_EW_noSB_v2=new TH1D("METvBin_EW_noSB_v2","MET in variable bins after EW selctions",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_EW_SB_v2=new TH1D("METvBin_EW_SB_v2","MET in variable bins after EW selctions",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_EW_wtag_v2=new TH1D("METvBin_EW_wtag_v2","MET in variable bins after EW selctions",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_SP_v2=new TH1D("METvBin_SP_v2","MET in variable bins after SP elections",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin_nocut=new TH1D("METvBin_nocut","MET in variable bins without any cut",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1=new TH1D("METvBin1","MET in variable bins",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));
  h_METvBin_nocut1=new TH1D("METvBin_nocut1","MET in variable bins without any cut",METLowEdge_v1.size()-1,&(METLowEdge_v1[0]));
  h_METvBin2=new TH1D("METvBin2","MET in variable bins",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nocut2=new TH1D("METvBin_nocut2","MET in variable bins without any cut",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));

  h_MET_nj1=new TH1D("MET_nj1","MET",200,0,1200);  
  h_METvBin_nj1=new TH1D("METvBin_nj1","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj1=new TH1D("METvBin1_nj1","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj1=new TH1D("METvBin2_nj1","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj2to4_nbjet0=new TH1D("MET_nj2to4_nbjet0","MET",200,0,1200);  
  h_METvBin_nj2to4_nbjet0=new TH1D("METvBin_nj2to4_nbjet0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj2to4_nbjet0=new TH1D("METvBin1_nj2to4_nbjet0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj2to4_nbjet0=new TH1D("METvBin2_nj2to4_nbjet0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj5to6_nbjet0=new TH1D("MET_nj5to6_nbjet0","MET",200,0,1200);  
  h_METvBin_nj5to6_nbjet0=new TH1D("METvBin_nj5to6_nbjet0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj5to6_nbjet0=new TH1D("METvBin1_nj5to6_nbjet0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj5to6_nbjet0=new TH1D("METvBin2_nj5to6_nbjet0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj7toinf_nbjet0=new TH1D("MET_nj7toinf_nbjet0","MET",200,0,1200);  
  h_METvBin_nj7toinf_nbjet0=new TH1D("METvBin_nj7toinf_nbjet0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj7toinf_nbjet0=new TH1D("METvBin1_nj7toinf_nbjet0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj7toinf_nbjet0=new TH1D("METvBin2_nj7toinf_nbjet0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj2to4_nbjet1=new TH1D("MET_nj2to4_nbjet1","MET",200,0,1200);  
  h_METvBin_nj2to4_nbjet1=new TH1D("METvBin_nj2to4_nbjet1","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj2to4_nbjet1=new TH1D("METvBin1_nj2to4_nbjet1","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj2to4_nbjet1=new TH1D("METvBin2_nj2to4_nbjet1","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj5to6_nbjet1=new TH1D("MET_nj5to6_nbjet1","MET",200,0,1200);  
  h_METvBin_nj5to6_nbjet1=new TH1D("METvBin_nj5to6_nbjet1","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj5to6_nbjet1=new TH1D("METvBin1_nj5to6_nbjet1","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj5to6_nbjet1=new TH1D("METvBin2_nj5to6_nbjet1","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj7toinf_nbjet1=new TH1D("MET_nj7toinf_nbjet1","MET",200,0,1200);  
  h_METvBin_nj7toinf_nbjet1=new TH1D("METvBin_nj7toinf_nbjet1","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj7toinf_nbjet1=new TH1D("METvBin1_nj7toinf_nbjet1","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj7toinf_nbjet1=new TH1D("METvBin2_nj7toinf_nbjet1","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj2to4_nbjetnot0=new TH1D("MET_nj2to4_nbjetnot0","MET",200,0,1200);  
  h_METvBin_nj2to4_nbjetnot0=new TH1D("METvBin_nj2to4_nbjetnot0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj2to4_nbjetnot0=new TH1D("METvBin1_nj2to4_nbjetnot0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj2to4_nbjetnot0=new TH1D("METvBin2_nj2to4_nbjetnot0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj5to6_nbjetnot0=new TH1D("MET_nj5to6_nbjetnot0","MET",200,0,1200);  
  h_METvBin_nj5to6_nbjetnot0=new TH1D("METvBin_nj5to6_nbjetnot0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj5to6_nbjetnot0=new TH1D("METvBin1_nj5to6_nbjetnot0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj5to6_nbjetnot0=new TH1D("METvBin2_nj5to6_nbjetnot0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  h_MET_nj7toinf_nbjetnot0=new TH1D("MET_nj7toinf_nbjetnot0","MET",200,0,1200);  
  h_METvBin_nj7toinf_nbjetnot0=new TH1D("METvBin_nj7toinf_nbjetnot0","MET in variable bins",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin1_nj7toinf_nbjetnot0=new TH1D("METvBin1_nj7toinf_nbjetnot0","MET in variable bins",METLowEdge1.size()-1,&(METLowEdge1[0]));
  h_METvBin2_nj7toinf_nbjetnot0=new TH1D("METvBin2_nj7toinf_nbjetnot0","MET in variable bins",METLowEdge2.size()-1,&(METLowEdge2[0]));

  
  h_PhovBin=new TH1D("PhovBin","Pho in variable bins",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_PhovBin_nocut=new TH1D("PhovBin_nocut","Pho in variable bins without any cut",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_PhovBin1=new TH1D("PhovBin1","Pho in variable bins",PhoLowEdge1.size()-1,&(PhoLowEdge1[0]));
  h_PhovBin_nocut1=new TH1D("PhovBin_nocut1","Pho in variable bins without any cut",PhoLowEdge1.size()-1,&(PhoLowEdge1[0]));
  h_PhovBin2=new TH1D("PhovBin2","Pho in variable bins",PhoLowEdge2.size()-1,&(PhoLowEdge2[0]));
  h_PhovBin_nocut2=new TH1D("PhovBin_nocut2","Pho in variable bins without any cut",PhoLowEdge2.size()-1,&(PhoLowEdge2[0]));

  /* h_HT_num=new TH1D("HT_num","HT",400,0,4000); */
  /* h_MHT_num=new TH1D("MHT_num","MHT",200,0,2000); */
  h_nJets_num=new TH1D("nJets_num","nJets",25,0,25);
  /* h_MHTstar_num=new TH1D("MHTstar_num","MHT calculated using ST like definition",200,0,2000); */
  
  /* h2_PtPhotonvsMET_num=new TH2D("BestPhotonPtvsMET_num","Best photon Pt vs MET",150,0,1500,200,0,2000); */
  h_mTPhoMET_num=new TH1D("mTPhoMET_num","mT b/w bestPhoton and MET",200,0,2000);

  h_dPhi_METjet1_num=new TH1D("dPhi_METjet1_num","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_num=new TH1D("dPhi_METjet2_num","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_phojet1_num=new TH1D("dPhi_phojet1_num","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_num=new TH1D("dPhi_phojet2_num","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phoMET_num=new TH1D("dPhi_phoMET_num","dphi between photon and MET",80,-4,4);


  // for numerator1

  h_nEvts_nocut=new TH1D("nEvents_nocut","no. of events in this tree (for num1erator)",4,0,4);
  h_RunNum_nocut=new TH1I("runs_nocut","Run nos.",300000,0,300000);
  h_intLumi_nocut=new TH1D("intLumi_nocut","integrated luminosity in /fb",2500,25,50); 
  h_ST_nocut=new TH1D("ST_nocut","ST",400,0,4000);
  h_MET_nocut=new TH1D("MET_nocut","MET",200,0,2000);
  /* h_nHadJets_nocut=new TH1D("nHadJets_nocut","no. of jets(only hadronic jets,not counting photon)",25,0,25); */
  h_BTags_nocut=new TH1D("nBTags_nocut","no. of B tags",10,0,10);
  h_BestPhotonPt_nocut=new TH1D("BestPhotonPt_nocut","Pt of the Best Photon",150,0,1500);

  /* h_HT_nocut=new TH1D("HT_nocut","HT",400,0,4000); */
  /* h_MHT_nocut=new TH1D("MHT_nocut","MHT",200,0,2000); */
  h_nJets_nocut=new TH1D("nJets_nocut","nJets",25,0,25);
  /* h_MHTstar_nocut=new TH1D("MHTstar_nocut","MHT calculated using ST like definition",200,0,2000); */
  
  h2_PtPhotonvsMET_nocut=new TH2D("BestPhotonPtvsMET_nocut","Best photon Pt vs MET",150,0,1500,200,0,2000);
  // h2_PtPhotonvsMET=new TH2D("BestPhotonPtvsMET","Best photon Pt vs MET",150,0,1500,200,0,2000);
  h_mTPhoMET_nocut=new TH1D("mTPhoMET_nocut","mT b/w bestPhoton and MET",200,0,2000);

  h_dPhi_METjet1_nocut=new TH1D("dPhi_METjet1_nocut","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_nocut=new TH1D("dPhi_METjet2_nocut","dphi between MET Vec and Jet2",80,-4,4);
  h_dPhi_phojet1_nocut=new TH1D("dPhi_phojet1_nocut","dphi between photon and Jet1",80,-4,4);
  h_dPhi_phojet2_nocut=new TH1D("dPhi_phojet2_nocut","dphi between photon and Jet2",80,-4,4);
  h_dPhi_phoMET_nocut=new TH1D("dPhi_phoMET_nocut","dphi between photon and MET",80,-4,4);
  

  h_GmatchedObj=new TH1D("GmatchedObj","Gen Obj close to Reco-Gamma",62,-0.75,30.25);
  h_PdgIdPhoParent = new TH1D("PdgIdPhoParent","PdgID of the Photon's parent",62,-0.75,30.25);

  h_SBins_v6_CD = new TH1D("AllSBins_v6_CD","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",8,1,9);
 h_SBins_v6_CD_EW_43bin = new TH1D("AllSBins_v6_CD_EW_43bin","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] [(WTag : [65,105]),(HTag : [105,140])]",43,0.5,43.5);
 h_SBins_v6_CD_EW_50bin = new TH1D("AllSBins_v6_CD_EW_50bin","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);  
 // h_SBins_v6_CD_EW_50bin = new TH1D("AllSBins_v6_CD_EW_50bin","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
 h_SBins_v6_CD_EW_14bin = new TH1D("AllSBins_v6_CD_EW_14bin","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] [(WTag : [65,105]),(HTag : [105,140])]",14,0.5,14.5);
 h_SBins_v6_CD_EW_7bin = new TH1D("AllSBins_v6_CD_EW_7bin","search bins v6:[(WTag : [65,105])]",4,1,5);
 h_SBins_v6_CD_EW_7bin_elec0 = new TH1D("AllSBins_v6_CD_EW_7bin_elec0","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);
 h_SBins_v6_CD_EW_7bin_elec1 = new TH1D("AllSBins_v6_CD_EW_7bin_elec1","search bins v6:[(WTag : [65,105])]",31,0.5,31.5);

 h_SBins_v6_CD_EW_7bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_7bin_elec1_closure","search bins v6:[(WTag : [65,105])]",4,1,5);

  h_SBins_v6_CD_EW = new TH1D("AllSBins_v6_CD_EW","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",37,0.5,37.5);
  h_SBins_v6_CD_EW_htag = new TH1D("AllSBins_v6_CD_EW_htag","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",37,0.5,37.5);

  h_SBins_v6_CD_SP = new TH1D("AllSBins_v6_CD_SP","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );

  h_SBins_v7_CD = new TH1D("AllSBins_v7_CD","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",37,1,38);
  h_SBins_v7_CD_EW = new TH1D("AllSBins_v7_CD_EW","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5);
  h_SBins_v7_CD_EW_htag = new TH1D("AllSBins_v7_CD_EW_htag","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5);
  h_SBins_v7_CD_SP = new TH1D("AllSBins_v7_CD_SP","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5 );
  h_SBins_v7_CD_2018 = new TH1D("AllSBins_v7_CD_2018","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5);


  //v7 old selections for Lost electron scale factors                                                                            
  h_SBins_v7_1_CD_elec0_acc = new TH1D("AllSBins_v7_1_CD_elec0_acc","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",16,1,17);
  h_SBins_v7_1_CD_elec0_id = new TH1D("AllSBins_v7_1_CD_elec0_id","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",16,1,17);
  h_SBins_v7_1_CD_elec0_iso = new TH1D("AllSBins_v7_1_CD_elec0_iso","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",16,1,17);
  h_SBins_v7_1_CD_elec0 = new TH1D("AllSBins_v7_1_CD_elec0","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",16,1,17);
  h_SBins_v7_1_CD_elec1 = new TH1D("AllSBins_v7_1_CD_elec1","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",16,1,17);

  //v7 old selections for Lost electron scale factors                                                                                         
  h_SBins_v7_CD_elec0_acc = new TH1D("AllSBins_v7_CD_elec0_acc","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,1,32);
  h_SBins_v7_CD_elec0_id = new TH1D("AllSBins_v7_CD_elec0_id","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,1,32);
  h_SBins_v7_CD_elec0_iso = new TH1D("AllSBins_v7_CD_elec0_iso","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,1,32);
  h_SBins_v7_CD_elec0 = new TH1D("AllSBins_v7_CD_elec0","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,1,32);
  h_SBins_v7_CD_elec1 = new TH1D("AllSBins_v7_CD_elec1","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,1,32);

  
  
  //v6 new selections for Lost electron scale factors                                                                            
  // h_SBins_v6_CD_elec0_acc = new TH1D("AllSBins_v6_CD_elec0_acc","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",44,1,);
  // h_SBins_v6_CD_elec0_id = new TH1D("AllSBins_v6_CD_elec0_id","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",8,1,9);
  // h_SBins_v6_CD_elec0_iso = new TH1D("AllSBins_v6_CD_elec0_iso","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",8,1,9);
  h_SBins_v6_CD_elec0 = new TH1D("AllSBins_v6_CD_elec0","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49);
  h_SBins_v6_CD_elec1 = new TH1D("AllSBins_v6_CD_elec1","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49);
  h_SBins_v6_CD_elec1_closure = new TH1D("AllSBins_v6_CD_elec1_closure","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49);
  h_SBins_v6_CD_EW_50bin_elec0 = new TH1D("AllSBins_v6_CD_EW_50bin_elec0","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  h_SBins_v6_CD_EW_50bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_50bin_elec1_closure","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
   h_SBins_v6_CD_EW_50bin_elec1 = new TH1D("AllSBins_v6_CD_EW_50bin_elec1","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  //  h_SBins_v6_CD_EW_50bin_elec0 = new TH1D("AllSBins_v6_CD_EW_50bin_elec0","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
  // h_SBins_v6_CD_EW_50bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_50bin_elec1_closure","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
  // h_SBins_v6_CD_EW_50bin_elec1 = new TH1D("AllSBins_v6_CD_EW_50bin_elec1","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);

  h_SBins_v7_CD_SP_elec0_acc = new TH1D("AllSBins_v7_CD_SP_elec0_acc","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_elec0_id = new TH1D("AllSBins_v7_CD_SP_elec0_id","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_elec0_iso = new TH1D("AllSBins_v7_CD_SP_elec0_iso","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);

  h_SBins_v7_CD_SP_elec0 = new TH1D("AllSBins_v7_CD_SP_elec0","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_elec1 = new TH1D("AllSBins_v7_CD_SP_elec1","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);
  h_SBins_v7_CD_SP_elec1_closure = new TH1D("AllSBins_v7_CD_SP_elec1_closure","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",10,1,11);

  h_SBins_v7_CD_SP_tmp_elec0 = new TH1D("AllSBins_v7_CD_SP_tmp_elec0","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",18,1,19);
  h_SBins_v7_CD_SP_tmp_elec1 = new TH1D("AllSBins_v7_CD_SP_tmp_elec1","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",18,1,19);
  h_SBins_v7_CD_SP_tmp_elec1_closure = new TH1D("AllSBins_v7_CD_SP_tmp_elec1_closure","search bins SP:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] + EW : Wtag & Htag",18,1,19);

  
  h_SBins_v6_CD_SP_elec0_acc = new TH1D("AllSBins_v6_CD_SP_elec0_acc","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );
  h_SBins_v6_CD_SP_elec0_id = new TH1D("AllSBins_v6_CD_SP_elec0_id","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );
  h_SBins_v6_CD_SP_elec0_iso = new TH1D("AllSBins_v6_CD_SP_elec0_iso","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );
  h_SBins_v6_CD_SP_elec0 = new TH1D("AllSBins_v6_CD_SP_elec0","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49 );
  h_SBins_v6_CD_SP_elec1 = new TH1D("AllSBins_v6_CD_SP_elec1","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49 );
  h_SBins_v6_CD_SP_elec1_closure = new TH1D("AllSBins_v6_CD_SP_elec1_closure","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",48,1,49 );

  
  //---------------Search Bins ----------------------------
  /* h_MET_R_v2[0] =new TH1D("MET_R1_v2","MET for 0b, NJ=2to4 ",METBinLowEdge.size()-1,&(METBinLowEdge[0])); */
  /* h_MET_R_v2[1] =new TH1D("MET_R2_v2","MET for 0b, NJ>=5 ",METBinLowEdge.size()-1,&(METBinLowEdge[0])); */
  /* h_MET_R_v2[2] =new TH1D("MET_R3_v2","MET for 1b, NJ=2to4 ",METBinLowEdge.size()-1,&(METBinLowEdge[0])); */
  /* h_MET_R_v2[3] =new TH1D("MET_R4_v2","MET for 1b, NJ>=5 ",METBinLowEdge.size()-1,&(METBinLowEdge[0])); */
  /* h_MET_R_v2[4] =new TH1D("MET_R5_v2","MET for b>=2 ",METBinLowEdge2bJ.size()-1,&(METBinLowEdge2bJ[0])); */

  /* h_SBins = new TH1D("AllSBins","all search bins:(0b, NJ=2to4)(0b, NJ>=5)(1b, NJ=2to4)(1b, NJ>=5)(b>=2)",34,0.5,34.5); */
  /* h_SBins_v1 = new TH1D("AllSBins_v1","search bins:(NJ=2to4) (NJ:5or6) (NJ>=7)",21,0.5,21.5); */
  /* h_SBins_v3 = new TH1D("AllSBins_v3","search bins: [ NJ:2-4, NJ:5or6, NJ>=7] x [0b, 1b, >=2b]",63,0.5,63.5); */

  /* h_SBins_v4_CD = new TH1D("AllSBins_v4_CD","search bins:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",43,0.5,43.5); */

  /* h_SBins_v7_CD = new TH1D("AllSBins_v7_CD","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5); */

}


Mulijet::Mulijet(const TString &inputFileList, const char *outFileName, const char* dataset) {
  string nameData=dataset;//vvv

  TChain *tree = new TChain("PreSelection");
  /* if(nameData=="bkg") tree = new TChain("TreeMaker2/PreSelection");//vvv */
  /* if(nameData=="FastSim_TChiWg_0_400_v17") tree = new TChain("tree");//vvv */
  /* if(nameData=="FastSim_TChiWg_0_800_v17") tree = new TChain("tree");//vvv */
  /* if(nameData=="FastSim_TChiWg_0_1200_v17") tree = new TChain("tree");//vvv */
  if( ! FillChain(tree, inputFileList) ) {
    std::cerr << "Cannot get the tree " << std::endl;
  } else {
    std::cout << "Initiating analysis of dataset " << dataset << std::endl;
  }

  if(nameData!="signalH") nameData="BG";
  if(nameData=="signalH") nameData="signal";
  cout<<"Treating the input files as "<<nameData<<" for setting tree branches"<<endl;
  NtupleVariables::Init(tree,nameData);

  BookHistogram(outFileName);
  
}

Bool_t Mulijet::FillChain(TChain *chain, const TString &inputFileList) {

  ifstream infile(inputFileList, ifstream::in);
  std::string buffer;

  if(!infile.is_open()) {
    std::cerr << "** ERROR: Can't open '" << inputFileList << "' for input" << std::endl;
    return kFALSE;
  }

  std::cout << "TreeUtilities : FillChain " << std::endl;
  while(1) {
    infile >> buffer;
    if(!infile.good()) break;
    //std::cout << "Adding tree from " << buffer.c_str() << std::endl;                                                              
    chain->Add(buffer.c_str());
  }
  std::cout << "No. of Entries in this tree : " << chain->GetEntries() << std::endl;
  return kTRUE;
}

Long64_t Mulijet::LoadTree(Long64_t entry) {
  // Set the environment to read one entry                                                                                          
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (!fChain->InheritsFrom(TChain::Class()))  return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();
    //    Notify();
  }
  return centry;
}

Mulijet::~Mulijet() { 

  if (!fChain) return;
  delete fChain->GetCurrentFile();
  oFile->cd();
  oFile->Write();
  oFile->Close();

}

#endif

