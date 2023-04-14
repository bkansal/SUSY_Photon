#ifndef Fakerate_H
#define Fakerate_H
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

class Fakerate : public NtupleVariables{

 public:
  Fakerate(const TString &inputFileList="foo.txt", const char *outFileName="histo.root",const char *dataset="data");
  ~Fakerate();
  Bool_t   FillChain(TChain *chain, const TString &inputFileList);
  Long64_t LoadTree(Long64_t entry);
  void     EventLoop(const char *,const char *);
  void     BookHistogram(const char *);
  TLorentzVector getBestPhoton();
  TLorentzVector getPhoton_withoutfullID();
  int getBinNoV4(int);
  int getBinNoV7(TLorentzVector, double);
  //  int getBinNoV7_closure(int,TFile);
  int getBinNoV7_v1(int);
  //  int getBinNoV6(int);
  int getBinNoV6(bool,bool,bool,bool,int);
  int getBinNoV6_EW(bool,bool);
  int getBinNoV6_EW1(bool);
  int getBinNoV6_EWplusSP_SR(bool,bool,bool,int);
  int getBinNoV6_EWplusSP_CR(bool,bool,bool,bool,int);
  int getBinNoV7_le(int);
  int getBinNoV7_le2(bool,bool,bool,bool,int);
  
  double getGendRLepPho();
  bool check_eMatchedtoGamma(TLorentzVector);
  void print(Long64_t);
  void findObjMatchedtoG(TLorentzVector);
  double getGenLep(TLorentzVector);
  
  //Variables defined
  int bestPhotonIndxAmongPhotons=-100;
  int eIndxAmongPhotons=-100;
  float HT_PtCut=30;
  float MHT_PtCut=30;//keep MHT_PtCut <= HT_PtCut and <= Njets_PtCut
  float Njets_PtCut=30;
  double deepCSVvalue = 0;

  double invariantmass=-1;
  float HT_EtaCut=2.4;
  float MHT_EtaCut=5;
  float Njets_EtaCut=2.4;
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
  vector<double> METLowEdge_v2={200,250,300,370,450,600,750,900,2000};
  vector<double> METLowEdge_v2_1={200,250,300,370,450,600,750,2000};
  vector<double> METLowEdge_v3={300,370,450,600,750,900,2000};
  vector<double> METLowEdge_v3_1={300,370,450,600,750,2000};

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

  vector<double> QMultLowedge={0,2,4,7,100};
  //  vector<double> QMultLowedge2={0,2,100};
  //  vector<double> QMultLowedge={0,2,5,7,10,15,20,100};
  vector<double>  nJetsLowedge={2,10,20};
  vector<double>  nbtagsLowedge={0,1,10};

  vector<double> BestPhotonPtBinLowEdge={100,120,140,160,180,200,230,260,300,380,500,600};
  double ptLow2[13]={0,100,120,140,160,180,200,230,260,300,380,500,600};
  double QMultLow[6]={0,2,4,7,100};
  vector<TLorentzVector> allBestPhotons;
  //histograms
  TH1D *h_nvtx;
  TH1D *h_nvtx_all;
  TH1D *h_nEvts;
  TH1I *h_RunNum;
  TH1D *h_intLumi;
  TH1D *h_ST;
  TH2D *h2_MET_nJets;
  TH1D *h_qmulti;
  TH2D *h2_MET_elepT;
  TH2D *h2_METvBin2_nJets;
  TH2D *h2_nbjets_nJets;
  TH1D *h_MET;
  TH1D *h_METPhi;
  TH1D *h_METvBin;
  TH1D *h_METvBin2;  
  TH1D *h_BTags;
  TH1D *h_DBTags;
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
  TH1D *h_minDr_bestphoEle;
  TH2D *h2_minDr_tagEle_pt;
  TH1D *h_minDr_bestphoJets;
  TH1D *h_minDr_bestphoremEle;
  TH1D *h_minDr_bestphoremJets;
  TH1D *h_NEMobj;
  TH1D *h_invMass;
  TH1D *h_ElectronPt;
  TH1D *h_ElectronPhi;
  TH1D *h_ElectronEta;
  TH1D *h_trackElectronPt;
  TH1D *h_trackElectronPhi;
  TH1D *h_trackElectronEta;
  TH1D *h_JetPt;
  TH1D *h_JetPhi;
  TH1D *h_JetEta;
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
  TH1D *h_leadElectronPt;
  TH1D *h_leadElectronPhi;
  TH1D *h_leadElectronEta;
  TH2D *h2_leadElectronEta_Phi;
  TH1D *h_leadJetPt;
  TH1D *h_leadJetPhi;
  TH1D *h_leadJetEta;
  TH2D *h2_leadJetEta_Phi;
  TH2D *h2_leadJetEta_Pt;
  TH2D *h2_JetEta_Pt;
  TH2D *h2_BestPhoEta_Pt;
  TH2D *h2_JetEta_Phi;
  TH2D *h2_ElectronEta_Phi;
  TH2D *h2_trackElectronEta_Phi;
  TH1D *h_dPhi_METlep;
  TH1D *h_dPhi_METlep1;
  TH2D *h2_BestPhotonPt_jetmatchphoratio;
  TH2D *h2_BestPhotonPt_jetphoratio;
  TH1D *h_minDr_Elejet1;
  TH1D *h_minDr_Elejet2;
  TH1D *h_minDr_Elejet3;
  TH1D *h_minDr_Elejet4;
  TH1D *h_minDr_EleJets;
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
  TH1D *h_CM_tagEle;
  TH1D *h_EMObj_pT;
  TH1D *h_tagObj_pT;
  TH1D *h_hlt_pT;
  //  TH1D *h_EMObj_phi;
  //TH1D *h_tagObj_phi;
  TH2D *h2_PhoPtQMultJet;
  TH2D *h2_PhoPtnJets;
  TH3D *h3_PhoPtnJetsbtags;
  TH2D *h2_nJetsQMultJet;
  TH2D *h2_QMultlleadbJet;
  TH1D *h_deepcsv;


  
  TH1D *h_nvtx_elec0;
  TH1D *h_nvtx_all_elec0;
  TH1D *h_ST_elec0;
  TH1D *h_MET_elec0;
  TH1D *h_qmulti_elec0;
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
  TH1D *h_BestPhotonPt_0b_elec0;
  TH1D *h_BestPhotonPt_ge1b_elec0;
  TH1D *h_BestPhotonPt_0b_vBin_elec0;
  TH1D *h_BestPhotonPt_ge1b_vBin_elec0;
  TH1D *h_minDr_bestphoEle_elec0;
  TH1D *h_minDr_bestphoJets_elec0;
  TH1D *h_minDr_bestphoremEle_elec0;
  TH1D *h_minDr_bestphoremJets_elec0;
  TH1D *h_NEMobj_elec0;
  TH1D *h_invMass_elec0;
  TH1D *h_ElectronPt_elec0;
  TH1D *h_ElectronPhi_elec0;
  TH1D *h_ElectronEta_elec0;
  TH1D *h_trackElectronPt_elec0;
  TH1D *h_trackElectronPhi_elec0;
  TH1D *h_trackElectronEta_elec0;
  TH2D *h2_BestPhoEta_Pt_elec0;
  TH1D *h_JetPt_elec0;
  TH1D *h_JetPhi_elec0;
  TH1D *h_JetEta_elec0;
  TH1D *h_remJetPt_elec0;
  TH1D *h_remJetPhi_elec0;
  TH1D *h_remJetEta_elec0;
  TH1D *h_mTPhoMET_elec0;
  TH1D *h_dPhi_METjet1_elec0;
  TH1D *h_dPhi_METjet2_elec0;
  TH1D *h_dPhi_phojet1_elec0;
  TH1D *h_dPhi_phojet2_elec0;
  TH1D *h_dPhi_phoMET_elec0;
  TH1D *h_leadElectronPt_elec0;
  TH2D *h2_leadElectronEta_Phi_elec0;
  TH2D *h2_ElectronEta_Phi_elec0;
  TH2D *h2_trackElectronEta_Phi_elec0;
  TH1D *h_leadJetPt_elec0;
  TH1D *h_leadJetPhi_elec0;
  TH1D *h_leadJetEta_elec0;
  TH2D *h2_leadJetEta_Phi_elec0;
  TH2D *h2_njetnbjet_phopt_vBin_elec0;
  TH2D *h2_njetnbjet_phopt_elec0;
  TH1D *h_hadAk8jetPt_elec0;
  TH1D *h_hadAk8Mass_elec0;
  TH1D *h_CM_Pho;
  TH1D *h_CM_tagEle_elec0;
  TH1D *h_EMObj_pT_elec0;
  TH2D *h2_PhoPtQMultJet_elec0;
  TH2D *h2_PhoPtnJets_elec0;
  TH3D *h3_PhoPtnJetsbtags_elec0;
  TH2D *h2_nJetsQMultJet_elec0;
  TH1D *h_tagObj_pT_elec0;
  // TH1D *h_tagObj_phi_elec0;
  // TH1D *h_EMObj_phi_elec0;


  
  TH1D *h_nvtx_elec1_closure;
  TH1D *h_hadAk8Mass_elec1_closure;
  TH1D *h_ST_elec1_closure;
  TH1D *h_qmulti_elec1_closure;
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
  TH1D *h_invMass_elec1_closure;
  TH1D *h_ElectronPt_elec1_closure;
  TH1D *h_ElectronPhi_elec1_closure;
  TH1D *h_ElectronEta_elec1_closure;
  TH1D *h_JetPt_elec1_closure;
  TH1D *h_JetPhi_elec1_closure;
  TH1D *h_JetEta_elec1_closure;
  TH1D *h_remJetPt_elec1_closure;
  TH1D *h_remJetPhi_elec1_closure;
  TH1D *h_remJetEta_elec1_closure;
  TH1D *h_mTPhoMET_elec1_closure;
  TH1D *h_dPhi_METjet1_elec1_closure;
  TH1D *h_dPhi_METjet2_elec1_closure;
  TH1D *h_dPhi_phojet1_elec1_closure;
  TH1D *h_dPhi_phojet2_elec1_closure;
  TH1D *h_dPhi_phoMET_elec1_closure;
  TH2D *h2_leadElectronEta_Phi_elec1_closure;
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
  TH2D *h2_PhoPtnJets_elec1_closure;
  TH3D *h3_PhoPtnJetsbtags_elec1_closure;
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

  TH1D *h_HT;
  TH1D *h_MHT;
  TH1D *h_HT_elec0;
  TH1D *h_MHT_elec0;

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
  TH1D *h_SBins_v6_CD_EW_7bin_noSB;

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

  TFile *oFile;
  
};
#endif

#ifdef Fakerate_cxx

void Fakerate::BookHistogram(const char *outFileName) {

  //  char hname[200], htit[200];
  //  double xlow = 0.0,  xhigh = 2000.0;
  //  int nbins = 2000;
  char name[100],title[100];
 
  oFile = new TFile(outFileName, "recreate");
  TH1::SetDefaultSumw2(1);
  h_selectBaselineYields_ = new TH1F("cutflows","cutflows",12,-0.5,12.5);
  h_selectBaselineYields_2 = new TH1F("cutflows2","cutflows2",12,-0.5,12.5);


  h_nvtx=new TH1D("nvtx","no. of vertices",100,0,100);
  h_nvtx_all=new TH1D("nvtx_all","no. of all vertices",100,0,100);

  h_nEvts=new TH1D("nEvents","no. of events in this tree",4,0,4);
  h_RunNum=new TH1I("runs","Run nos.",300000,0,300000);
  h_intLumi=new TH1D("intLumi","integrated luminosity in /fb",10000,25,200); 
  h_ST=new TH1D("ST","ST",400,0,4000);
  h_MET=new TH1D("MET","MET",200,0,2000);
  h2_MET_nJets=new TH2D("MET_nJets","MET (Y axis) wrt nJets (X axis)",25,0,25,200,0,2000);
  h2_MET_elepT=new TH2D("MET_elepT","MET (Y axis) wrt Electron pT (X axis)",300,0,1500,200,0,2000);
  h2_METvBin2_nJets=new TH2D("METvBin2_nJets","MET (Y axis) wrt nJets (X axis)",25,0,25,METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h2_nbjets_nJets=new TH2D("nbjets_nJets","nbjets (Y axis) wrt nJets (X axis)",25,0,25,10,0,10);
  h_METPhi=new TH1D("METPhi","MET Phi",400,-5,5);
  h_BTags=new TH1D("nBTags","no. of B tags",10,0,10);
  h_DBTags=new TH1D("DnBTags","#bjets - #Btags",10,0,10);
  //  h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",300,0,1500);
  h_nJets=new TH1D("nJets","nJets",25,0,25);
  h_nremJets=new TH1D("nremJets","nJets",25,0,25);
  h_minDr_bestphoEle=new TH1D("h_minDr_bestphoEle","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h2_minDr_tagEle_pt=new TH2D("h2_minDr_tagEle_pt","Mindr b/w tag e & HLT e wrt pt ",300,0,1500,500,0,5);
  h_minDr_bestphoJets=new TH1D("h_minDr_bestphoJets","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_minDr_bestphoremEle=new TH1D("h_minDr_bestphoremEle","Mindr b/w Reco Photon and Reco Lepton ",500,0,5);
  h_minDr_bestphoremJets=new TH1D("h_minDr_bestphoremJets","Mindr b/w Reco Photon and Reco Jets ",500,0,5);
  h_dPhi_phoMET=new TH1D("dPhi_phoMET","dphi between photon and MET",80,-4,4);
  h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",300,0,1500);
  h_BestPhotonPt_vBin=new TH1D("BestPhotonPt_vBin","Photon pt in variable bins",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_0b=new TH1D("BestPhotonPt_0b","Pt of the Best Photon for bTag=0",300,0,1500);
  h_BestPhotonPt_ge1b=new TH1D("BestPhotonPt_ge1b","Pt of the Best Photon for bTag > 0",300,0,1500);
  h_BestPhotonPt_0b_vBin=new TH1D("BestPhotonPt_0b_vBin","Pt of the Best Photon for bTag=0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonPt_ge1b_vBin=new TH1D("BestPhotonPt_ge1b_vBin","Pt of the Best Photon for bTag > 0",PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h_BestPhotonEta=new TH1D("BestPhotonEta","Eta of the Best Photon",400,-5,5);
  h_BestPhotonPhi=new TH1D("BestPhotonPhi","Phi of the Best Photon",400,-5,5);
  h_NEMobj=new TH1D("NEMobj","No. of the Electrons",10,0,10);
  h_invMass=new TH1D("invMass","invariant mass from e(tag) & e(probe)",2000,0,500);
  h_ElectronPt=new TH1D("ElectronPt","Pt of the Electrons",300,0,1500);
  h_ElectronEta=new TH1D("ElectronEta","Eta of the Electrons",400,-5,5);
  h_ElectronPhi=new TH1D("ElectronPhi","Phi of the Electrons",400,-5,5);
  h_trackElectronPt=new TH1D("trackElectronPt","Pt of the trackElectrons",300,0,1500);
  h_trackElectronEta=new TH1D("trackElectronEta","Eta of the trackElectrons",400,-5,5);
  h_trackElectronPhi=new TH1D("trackElectronPhi","Phi of the trackElectrons",400,-5,5);
  h_JetPt=new TH1D("JetPt","Pt of the Jets",300,0,1500);
  h_JetEta=new TH1D("JetEta","Eta of the Jets",400,-5,5);
  h_JetPhi=new TH1D("JetPhi","Phi of the Jets",400,-5,5);
  h_remJetPt=new TH1D("remJetPt","Pt of the remJets",300,0,1500);
  h_remJetEta=new TH1D("remJetEta","Eta of the remJets",400,-5,5);
  h_remJetPhi=new TH1D("remJetPhi","Phi of the remJets",400,-5,5);
  h_leadElectronPt=new TH1D("leadElectronPt","Leading Electron Pt ",300,0,1500);
  h_leadElectronPhi=new TH1D("leadElectronPhi","Leading Electron Phi ",400,-5,5);
  h_leadElectronEta=new TH1D("leadElectronEta","Leading Electron Eta ",400,-5,5);
  h2_leadElectronEta_Phi=new TH2D("leadElectronEta_Phi","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_leadJetPt=new TH1D("leadJetPt","Leading Jet Pt ",300,0,1500);
  h_leadJetPhi=new TH1D("leadJetPhi","Leading Jet Phi ",400,-5,5);
  h_leadJetEta=new TH1D("leadJetEta","Leading Jet Eta ",400,-5,5);
  h2_leadJetEta_Phi=new TH2D("leadJetEta_Phi","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_leadJetEta_Pt=new TH2D("leadJetEta_Pt","Leading Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Pt=new TH2D("JetEta_Pt","Jet Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_BestPhoEta_Pt=new TH2D("BestPhoEta_Pt","Best Photon Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h2_JetEta_Phi=new TH2D("JetEta_Phi","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_ElectronEta_Phi=new TH2D("ElectronEta_Phi","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_trackElectronEta_Phi=new TH2D("trackElectronEta_Phi","Leading trackElectron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_dPhi_METlep=new TH1D("dPhi_METlep","dphi between MET Vec and Muon",40,0,4);
  h_dPhi_METlep1=new TH1D("dPhi_METlep1","dphi between leading MET Vec and Muon",40,0,4);
  h2_BestPhotonPt_jetmatchphoratio=new TH2D("BestPhotonPt_jetmatchphoratio","Best Photon Pt (x axis) vs jet(match to photon) Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
  h2_BestPhotonPt_jetphoratio=new TH2D("BestPhotonPt_jetphoratio","Best Photon Pt (x axis) vs jet Pt/Photon Pt (yaxis)",300,0,1500,1000,0,5);
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
  h2_njetnbjet_phopt_vBin=new TH2D("njetnbjet_phopt_vBin","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h2_njetnbjet_phopt=new TH2D("njetnbjet_phopt","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,300,0,1500);
  h_hadAk8jetPt=new TH1D("hadAk8jetPt","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_CM_Ele=new TH1D("Qmulti","charged multiplicity in jet matching Ele",50,0,50);
  h_CM_tagEle=new TH1D("Qmulti_tag","charged multiplicity in jet matching Ele",50,0,50);
 //  h_qmulti=new TH1D("Qmulti_SF","charged multiplicity in jet matching Ele",QMultLowedge2.size()-1,&(QMultLowedge2[0]));
  h_EMObj_pT=new TH1D("EMObj_Pt","Pt of the EM object",300,0,1500);
  h_tagObj_pT=new TH1D("tagObj_Pt","Pt of the tag object",300,0,1500);
  h_hlt_pT=new TH1D("hlt_Pt","Pt of the tag object",300,0,1500);
  //  h_EMObj_phi=new TH1D("EMObj_Phi","Phi of the EM object",300,0,1500);
  //  h_tagObj_phi=new TH1D("tagObj_Phi","Phi of the tag object",300,0,1500);
  h2_PhoPtQMultJet=new TH2D("PhoPtQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_PhoPtnJets=new TH2D("PhoPtnJets","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]));
  h3_PhoPtnJetsbtags=new TH3D("PhoPtnJetsbtags","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  //  h2_PhoPtQMultJet=new TH2D("PhoPtQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",12,ptLow2,sizeof(QMultLow)/sizeof(double)-1,QMultLow);
  //  h2_nJetsQMultJet=new TH2D("nJetsQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_nJetsQMultJet=new TH2D("nJetsQMultJet","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);
  h_deepcsv=new TH1D("h_deepcsv","Deep CSV",500,0,5);
  h2_QMultlleadbJet=new TH2D("QMultlleadbJet","x: Qmultiplicity in jet matched to e & y: Deep CSV for jet matched to e",50,0,50,300,0,3);
  
  h_nvtx_elec0=new TH1D("nvtx_elec0","no. of vertices",100,0,100);
  h_nvtx_all_elec0=new TH1D("nvtx_all_elec0","no. of all vertices",100,0,100);
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
  h_dPhi_METjet1_elec0=new TH1D("dPhi_METjet1_elec0","dphi between MET Vec and Jet1",80,-4,4);
  h_dPhi_METjet2_elec0=new TH1D("dPhi_METjet2_elec0","dphi between MET Vec and Jet2",80,-4,4);
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
  h_NEMobj_elec0=new TH1D("NEMobj_elec0","No. of the Photons",10,0,10);
  h_invMass_elec0=new TH1D("invMass_elec0","invariant mass from e(tag) & photon(probe)",2000,0,500);
  h_leadElectronPt_elec0=new TH1D("leadElectronPt_elec0","Leading Electron Pt ",300,0,1500);
  h_ElectronPt_elec0=new TH1D("ElectronPt_elec0","Pt of the Electrons",300,0,1500);
  h_ElectronEta_elec0=new TH1D("ElectronEta_elec0","Eta of the Electrons",400,-5,5);
  h_ElectronPhi_elec0=new TH1D("ElectronPhi_elec0","Phi of the Electrons",400,-5,5);
  h_trackElectronPt_elec0=new TH1D("trackElectronPt_elec0","Pt of the trackElectrons",300,0,1500);
  h_trackElectronEta_elec0=new TH1D("trackElectronEta_elec0","Eta of the trackElectrons",400,-5,5);
  h_trackElectronPhi_elec0=new TH1D("trackElectronPhi_elec0","Phi of the trackElectrons",400,-5,5);
  h2_BestPhoEta_Pt_elec0=new TH2D("BestPhoEta_Pt_elec0","Best Photon Eta (x axis) vs Pt (yaxis)",200,-5,5,300,0,1500);
  h_JetPt_elec0=new TH1D("JetPt_elec0","Pt of the Jets",300,0,1500);
  h_JetEta_elec0=new TH1D("JetEta_elec0","Eta of the Jets",400,-5,5);
  h_JetPhi_elec0=new TH1D("JetPhi_elec0","Phi of the Jets",400,-5,5);
  h_remJetPt_elec0=new TH1D("remJetPt_elec0","Pt of the remJets",300,0,1500);
  h_remJetEta_elec0=new TH1D("remJetEta_elec0","Eta of the remJets",400,-5,5);
  h_remJetPhi_elec0=new TH1D("remJetPhi_elec0","Phi of the remJets",400,-5,5);
  h2_leadElectronEta_Phi_elec0=new TH2D("leadElectronEta_Phi_elec0","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_ElectronEta_Phi_elec0=new TH2D("ElectronEta_Phi_elec0"," Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_trackElectronEta_Phi_elec0=new TH2D("trackElectronEta_Phi_elec0"," Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h_leadJetPt_elec0=new TH1D("leadJetPt_elec0","Leading Jet Pt ",300,0,1500);
  h_leadJetPhi_elec0=new TH1D("leadJetPhi_elec0","Leading Jet Phi ",400,-5,5);
  h_leadJetEta_elec0=new TH1D("leadJetEta_elec0","Leading Jet Eta ",400,-5,5);
  h2_leadJetEta_Phi_elec0=new TH2D("leadJetEta_Phi_elec0","Leading Jet Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
  h2_njetnbjet_phopt_vBin_elec0=new TH2D("njetnbjet_phopt_vBin_elec0","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,PhoLowEdge.size()-1,&(PhoLowEdge[0]));
  h2_njetnbjet_phopt_elec0=new TH2D("njetnbjet_phopt_elec0","NJet x NbTag (x axis) wrt #gamma pT (yaxis)",10,1,11,300,0,1500);
  h_hadAk8jetPt_elec0=new TH1D("hadAk8jetPt_elec0","Soft dropped Pt of AK8 Jet",2000,0,1000);
  h_hadAk8Mass_elec0=new TH1D("hadAk8Mass_elec0","Soft dropped mass of AK8 Jet",1000,0,300);
  h_CM_Pho=new TH1D("Qmulti_elec0","charged multiplicity in jet matching Pho",50,0,50);
  h_CM_tagEle_elec0=new TH1D("Qmulti_tag_elec0","charged multiplicity in jet matching Ele",50,0,50);
   //    h_qmulti_elec0=new TH1D("Qmulti_SF_elec0","charged multiplicity in jet matching Ele",QMultLowedge2.size()-1,&(QMultLowedge2[0]));
  h_EMObj_pT_elec0=new TH1D("EMObj_Pt_elec0","Pt of the EM object",300,0,1500); 
  h_tagObj_pT_elec0=new TH1D("tagObj_Pt_elec0","Pt of the tag object",300,0,1500);
    h2_PhoPtQMultJet_elec0=new TH2D("PhoPtQMultJet_elec0","x: Photon Pt vs charged multiplicity in the matching jet",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_PhoPtnJets_elec0=new TH2D("PhoPtnJets_elec0","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]));
  h3_PhoPtnJetsbtags_elec0=new TH3D("PhoPtnJetsbtags_elec0","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  h2_nJetsQMultJet_elec0=new TH2D("nJetsQMultJet_elec0","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);


  
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
  h_NEMobj_elec1_closure=new TH1D("NEMobj_elec1_closure","No. of the Pred. Photons",10,0,10);
  h_invMass_elec1_closure=new TH1D("invMass_elec1_closure","invariant mass from e(tag) & e(probe)",2000,0,500);
  h_ElectronPt_elec1_closure=new TH1D("ElectronPt_elec1_closure","Pt of the Electrons",300,0,1500);
  h_ElectronEta_elec1_closure=new TH1D("ElectronEta_elec1_closure","Eta of the Electrons",400,-5,5);
  h_ElectronPhi_elec1_closure=new TH1D("ElectronPhi_elec1_closure","Phi of the Electrons",400,-5,5);
  h_JetPt_elec1_closure=new TH1D("JetPt_elec1_closure","Pt of the Jets",300,0,1500);
  h_JetEta_elec1_closure=new TH1D("JetEta_elec1_closure","Eta of the Jets",400,-5,5);
  h_JetPhi_elec1_closure=new TH1D("JetPhi_elec1_closure","Phi of the Jets",400,-5,5);
   h_remJetPt_elec1_closure=new TH1D("remJetPt_elec1_closure","Pt of the remJets",300,0,1500);
  h_remJetEta_elec1_closure=new TH1D("remJetEta_elec1_closure","Eta of the remJets",400,-5,5);
  h_remJetPhi_elec1_closure=new TH1D("remJetPhi_elec1_closure","Phi of the remJets",400,-5,5);
  h2_leadElectronEta_Phi_elec1_closure=new TH2D("leadElectronEta_Phi_elec1_closure","Leading Electron Eta (x axis) vs Phi (yaxis)",200,-5,5,200,-5,5);
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
  h2_PhoPtQMultJet_elec1_closure=new TH2D("PhoPtQMultJet_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),QMultLowedge.size()-1,&(QMultLowedge[0]));
  h2_PhoPtnJets_elec1_closure=new TH2D("PhoPtnJets_elec1_closure","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]));
  h3_PhoPtnJetsbtags_elec1_closure=new TH3D("PhoPtnJetsbtags_elec1_closure","x: Photon Pt vs no. of jets",BestPhotonPtBinLowEdge.size()-1,&(BestPhotonPtBinLowEdge[0]),nJetsLowedge.size()-1,&(nJetsLowedge[0]),nbtagsLowedge.size()-1,&(nbtagsLowedge[0]));
  h2_nJetsQMultJet_elec1_closure=new TH2D("nJetsQMultJet_elec1_closure","x: Photon Pt vs charged multiplicity in the matching jet",25,0,25,50,0,50);

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

  h_HT=new TH1D("HT","HT",400,0,4000); 
  h_MHT=new TH1D("MHT","MHT",200,0,2000); 
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
  h_mindr_ph_lep=new TH1D("h_mindr_ph_lep","Mindr b/w gen Photon and gen electron ",500,0,5);
  h_mindr_ph_ele=new TH1D("h_mindr_ph_ele","Mindr b/w good Photon and gen electron ",500,0,5);
  h_mindr_ph_mu=new TH1D("h_mindr_ph_mu","Mindr b/w good Photon and gen muon ",500,0,5);
  h_mindr_ph_tau=new TH1D("h_mindr_ph_tau","Mindr b/w good Photon and gen tau ",500,0,5);
  h_mindr_genph_lep=new TH1D("h_mindr_genph_lep","Mindr b/w gen Photon and gen lepton ",500,0,5);
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
  h_METvBin2=new TH1D("METvBin2","MET in variable bins",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
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

  h_SBins_v6_CD = new TH1D("AllSBins_v6_CD","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",36,0.5,36.5);
 h_SBins_v6_CD_EW_43bin = new TH1D("AllSBins_v6_CD_EW_43bin","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] [(WTag : [65,105]),(HTag : [105,140])]",43,0.5,43.5);
 h_SBins_v6_CD_EW_50bin = new TH1D("AllSBins_v6_CD_EW_50bin","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
 h_SBins_v6_CD_EW_14bin = new TH1D("AllSBins_v6_CD_EW_14bin","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)] [(WTag : [65,105]),(HTag : [105,140])]",14,0.5,14.5);
 h_SBins_v6_CD_EW_7bin = new TH1D("AllSBins_v6_CD_EW_7bin","search bins v6:[(WTag : [65,105])]",7,0.5,7.5);
 h_SBins_v6_CD_EW_7bin_noSB = new TH1D("AllSBins_v6_CD_EW_7bin_noSB","search bins v6:[(WTag : [65,105])]",7,0.5,7.5);

  h_SBins_v6_CD_EW = new TH1D("AllSBins_v6_CD_EW","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",37,0.5,37.5);
  h_SBins_v6_CD_EW_htag = new TH1D("AllSBins_v6_CD_EW_htag","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",37,0.5,37.5);
  h_SBins_v6_CD_SP = new TH1D("AllSBins_v6_CD_SP","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );

  h_SBins_v7_CD = new TH1D("AllSBins_v7_CD","search bins v7:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",31,0.5,31.5);
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
  h_SBins_v6_CD_EW_50bin_elec0 = new TH1D("AllSBins_v6_CD_EW_50bin_elec0","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
  h_SBins_v6_CD_EW_50bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_50bin_elec1_closure","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);
  h_SBins_v6_CD_EW_50bin_elec1 = new TH1D("AllSBins_v6_CD_EW_50bin_elec1","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",51,0.5,51.5);

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
  h_SBins_v6_CD_SP_elec0 = new TH1D("AllSBins_v6_CD_SP_elec0","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );
  h_SBins_v6_CD_SP_elec1 = new TH1D("AllSBins_v6_CD_SP_elec1","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );
  h_SBins_v6_CD_SP_elec1_closure = new TH1D("AllSBins_v6_CD_SP_elec1_closure","search bins v6:[0b,1b] x [(NJ=2to4),(NJ:5or6),(NJ>=7)]_CD",12,1,13 );

  
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


Fakerate::Fakerate(const TString &inputFileList, const char *outFileName, const char* dataset) {
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

Bool_t Fakerate::FillChain(TChain *chain, const TString &inputFileList) {

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

Long64_t Fakerate::LoadTree(Long64_t entry) {
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

Fakerate::~Fakerate() { 

  if (!fChain) return;
  delete fChain->GetCurrentFile();
  oFile->cd();
  oFile->Write();
  oFile->Close();

}

#endif

