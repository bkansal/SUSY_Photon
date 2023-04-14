#ifndef Single_elec_H
#define Single_elec_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "NtupleVariables.h"
#include "TH1F.h"
#include "TH2.h"
#include <TProfile.h>
#include "TFile.h"
#include "TLorentzVector.h"
#include "TDirectory.h"

class Single_elec : public NtupleVariables{

 public:
  Single_elec(const TString &inputFileList="foo.txt", const char *outFileName="histo.root",const char *dataset="data");
  ~Single_elec();
  Bool_t   FillChain(TChain *chain, const TString &inputFileList);
  Long64_t LoadTree(Long64_t entry);
  void     EventLoop(const char *,const char *);
  void     BookHistogram(const char*);
  TLorentzVector getBestPhoton();
  TLorentzVector getBestPhoton_0();
  double getGenLep(TLorentzVector);
  int getBinNoV6_EWplusSP_CR(bool,bool,bool,bool,int,int);
  int bestPhotonIndxAmongPhotons = -100;   
  double deepCSVvalue=0;

  //Variables defined
  vector<double> STLowEdge={0,100,200,300,400,410,420,430,440,460,480,500,520,540,560,580,600,620,640,660,680,700,720,740,760,780,800,820,840,860,880,920,960,1000,1100,1300,1500,1800,2500,3500,5000};
  vector<double> PhoPtLowEdge={0,50,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,240,260,280,300,320,340,360,380,400,440,480,520,580,650,750,900,1050,1400,2000};
  vector<double> METLowEdge={0,50,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,240,260,280,300,320,340,360,380,400,450,500,600,1000,1400};
  //  vector<double> METLowEdge_v2={100,200,300,370,450,600,2000};
  vector<double> METLowEdge_v2={200,300,370,450,600,750,900,2000};
  vector<double> METLowEdge_v2_1={200,300,370,450,600,750,2000};
  vector<double> METLowEdge_v2_2={200,300,370,450,600,2000};

  vector<double> METLowEdge_v3={200,300,370,450,600,750,2000};

  /* vector<double> METLowEdge={0,50,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,240,260,280,300,320,340,360,380,400,440,480,520,600,1000,1400}; */
 vector<double> PhoPtLowEdge2={0,50,80,90,100,110,120,140,160,180,210,240,280,320,360,400,440,480,520,580,650,750,900,1050,1400,2000};
  vector<double> ElePtLowEdge={0,10,15,20,25,30,35,40,45,50,55,60,70,80,90,100,110,120,140,160,180,210,240,280,320,380,440,500,580,700,1500};
  vector<string> trigNames1={"HLT_CaloJet500_NoJetID_v","HLT_DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v","HLT_DoubleMu8_Mass8_PFHT300_v","HLT_Ele105_CaloIdVT_GsfTrkIdT_v","HLT_Ele115_CaloIdVT_GsfTrkIdT_v","HLT_Ele15_IsoVVVL_PFHT350_PFMET50_v","HLT_Ele15_IsoVVVL_PFHT350_v","HLT_Ele15_IsoVVVL_PFHT400_v","HLT_Ele15_IsoVVVL_PFHT600_v","HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v" ,"HLT_Ele25_eta2p1_WPTight_Gsf_v" ,"HLT_Ele27_WPTight_Gsf_v" ,"HLT_Ele27_eta2p1_WPLoose_Gsf_v" ,"HLT_Ele45_WPLoose_Gsf_v" ,"HLT_Ele50_IsoVVVL_PFHT400_v" ,"HLT_IsoMu16_eta2p1_MET30_v" ,"HLT_IsoMu22_eta2p1_v" ,"HLT_IsoMu22_v" ,"HLT_IsoMu24_v" ,"HLT_IsoTkMu22_v" ,"HLT_IsoTkMu24_v" ,"HLT_Mu15_IsoVVVL_PFHT350_PFMET50_v" ,"HLT_Mu15_IsoVVVL_PFHT350_v" ,"HLT_Mu15_IsoVVVL_PFHT400_v" ,"HLT_Mu15_IsoVVVL_PFHT600_v" ,"HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v" ,"HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v" ,"HLT_Mu45_eta2p1_v" ,"HLT_Mu50_IsoVVVL_PFHT400_v" ,"HLT_Mu50_v" ,"HLT_PFHT200_v" ,"HLT_PFHT250_v" ,"HLT_PFHT300_PFMET100_v" ,"HLT_PFHT300_PFMET110_v" ,"HLT_PFHT300_v" ,"HLT_PFHT350_v" ,"HLT_PFHT400_v" ,"HLT_PFHT475_v" ,"HLT_PFHT600_v" ,"HLT_PFHT650_v" ,"HLT_PFHT800_v" ,"HLT_PFHT900_v" ,"HLT_PFMET100_PFMHT100_IDTight_v" ,"HLT_PFMET110_PFMHT110_IDTight_v" ,"HLT_PFMET120_PFMHT120_IDTight_v" ,"HLT_PFMET90_PFMHT90_IDTight_v" ,"HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_v" ,"HLT_PFMETNoMu110_PFMHTNoMu110_IDTight_v" ,"HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_v" ,"HLT_PFMETNoMu90_PFMHTNoMu90_IDTight_v" ,"HLT_Photon135_PFMET100_v" ,"HLT_Photon165_HE10_v" ,"HLT_Photon175_v" ,"HLT_Photon90_CaloIdL_PFHT500_v" ,"HLT_Photon90_CaloIdL_PFHT600_v" ,"HLT_TkMu50_v"};

  TH1F *h_selectBaselineYields_;
  TH1D *h_TrigDec;
  TH2D *h2_TrigPS;
  TH1D *h_ST;
  TH1D *h_MET;
  TH1D *h_nHadJets;
  TH1D *h_BTags;
  TH1D *h_BestPhotonPt;
  TH1D *h_BestPhotonEta;
  TH1D *h_dPhiMETPho;
  TH1D *h_Ele1Pt;
  TH1D *h_Ele2Pt;
  TH1D *h_Ele1Eta;
  TH1D *h_HT;
  TH1D *h_MHT;
  TH1D *h_nJets;
  TH1D *h_METvBin;
  TH1D *h_METvBin_Req;
  TH1D *h_METvBin2;
  TH1D *h_METvBin2_Req;
  TH1D *h_METvBin3;
  TH1D *h_METvBin3_Req;

  TH1D *h_METvBin_nj2;
  TH1D *h_METvBin_nj2_Req;
  TH1D *h_METvBin_nj5;
  TH1D *h_METvBin_nj5_Req;
  TH1D *h_METvBin_nj7;
  TH1D *h_METvBin_nj7_Req;
  TH1D *h_MHTvBin;
  TH1D *h_MHTvBin_Req;

  TH1D *h_METvBin_nj2_nb0;
  TH1D *h_METvBin_nj2_nb0_Req;
  TH1D *h_METvBin_nj5_nb0;
  TH1D *h_METvBin_nj5_nb0_Req;
  TH1D *h_METvBin_nj7_nb0;
  TH1D *h_METvBin_nj7_nb0_Req;

  TH1D *h_METvBin_nj2_nb1;
  TH1D *h_METvBin_nj2_nb1_Req;
  TH1D *h_METvBin_nj5_nb1;
  TH1D *h_METvBin_nj5_nb1_Req;
  TH1D *h_METvBin_nj7_nb1;
  TH1D *h_METvBin_nj7_nb1_Req;

  TH1D *h_STvBin;
  TH1D *h_BestPhotonPt_vBin;
  TH1D *h_BestPhotonPt_vBin2;
  TH1D *h_Ele1Pt_vBin;
  TH1D *h_Ele2Pt_vBin;
  TH1D *h_HTvBin;
  TH2D *h2_PhoPtST;
  TH1D *h_MuPt;
  TH1D *h_MuPt_vBin;
  TH1D *h_QIsoRhoCorrEB;
  TH1D *h_QIsoRhoCorrEE;
  TH1D *h_sieieEB;
  TH1D *h_sieieEE;
  TH1D *h_PhoHOverE;
  TH1D *h_dPhi1;
  TH1D *h_dPhi2;
  TH2D *h2_QIsoSieieEB;
  TH2D *h2_QIsoSieieEE;
  TH1D *h_SBins_v6_CD_EW_50bin;

  TH1D *h_Prescale_Req;
  TH1D *h_ST_Req;
  TH1D *h_MET_Req;
  TH1D *h_nHadJets_Req;
  TH1D *h_BTags_Req;
  TH1D *h_BestPhotonPt_Req;
  TH1D *h_BestPhotonEta_Req;
  TH1D *h_dPhiMETPho_Req;
  TH1D *h_Ele1Pt_Req;
  TH1D *h_Ele2Pt_Req;
  TH1D *h_Ele1Eta_Req;
  TH1D *h_HT_Req;
  TH1D *h_MHT_Req;
  TH1D *h_nJets_Req;

  TH1D *h_STvBin_Req;
  TH1D *h_BestPhotonPt_vBin_Req;
  TH1D *h_BestPhotonPt_vBin2_Req;
  TH1D *h_Ele1Pt_vBin_Req;
  TH1D *h_Ele2Pt_vBin_Req;
  TH1D *h_HTvBin_Req;

  TH1D *h_MuPt_Req;
  TH1D *h_MuPt_vBin_Req;
  TH1D *h_SBins_v6_CD_EW_50bin_Req;

  TH1D *h_QIsoRhoCorrEB_Req;
  TH1D *h_QIsoRhoCorrEE_Req;
  TH1D *h_sieieEB_Req;
  TH1D *h_sieieEE_Req;
  TH1D *h_PhoHOverE_Req;
  TH1D *h_dPhi1_Req;
  TH1D *h_dPhi2_Req;
  TH2D *h2_QIsoSieieEB_Req;
  TH2D *h2_QIsoSieieEE_Req;

  TH2D *h2_PhoPtST_Req;
  TFile *oFile;
  
};
#endif

#ifdef Single_elec_cxx

void Single_elec::BookHistogram(const char *outFileName) {

  //  char hname[200], htit[200];
  //  double xlow = 0.0,  xhigh = 2000.0;
  //  int nbins = 2000;
  char name[100],title[100];
  oFile = new TFile(outFileName, "recreate");
  TH1::SetDefaultSumw2(1);
  TH2::SetDefaultSumw2(1);

  h_selectBaselineYields_ = new TH1F("selectBaselineYields_","selectBaselineYields_",100,-0.5,99.5);
  h_TrigDec = new TH1D("TrigDec","Trigger decision. Filled with trigger number mentioned in RA2 twiki, weighted with 0:fail, 1:pass, -1:not run",200,-0.75,99.25);
  h2_TrigPS = new TH2D("TrigPS","Trigger prescale. x:trigger number mentioned in RA2 twiki, y:prescale of the trigger, z:# of events",200,-0.75,99.25,1000,0,1000); 

  h_METvBin2=new TH1D("METvBin2","MET in variable bins for events passing trigger",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin3=new TH1D("METvBin3","MET in variable bins for events passing trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin=new TH1D("METvBin","MET in variable bins for events passing denominator trigger",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin_nj2=new TH1D("METvBin_nj2","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5=new TH1D("METvBin_nj5","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7=new TH1D("METvBin_nj7","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));

  h_METvBin_nj2_nb0=new TH1D("METvBin_nj2_nb0","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5_nb0=new TH1D("METvBin_nj5_nb0","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7_nb0=new TH1D("METvBin_nj7_nb0","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj2_nb1=new TH1D("METvBin_nj2_nb1","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5_nb1=new TH1D("METvBin_nj5_nb1","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7_nb1=new TH1D("METvBin_nj7_nb1","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));

  h_MHTvBin=new TH1D("MHTvBin","MHT in variable bins for events passing denominator trigger",METLowEdge.size()-1,&(METLowEdge[0]));

  h_ST=new TH1D("ST","ST for events passing denominator trigger",400,0,4000);
  h_MET=new TH1D("MET","MET for events passing denominator trigger",200,0,2000);
  h_nHadJets=new TH1D("nHadJets","no. of jets(only hadronic jets,not counting photon) for events passing denominator trigger",25,0,25);
  h_BTags=new TH1D("nBTags","no. of B tags for events passing denominator trigger",10,0,10);
  h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the best photon for events passing denominator trigger",150,0,1500);
  h_BestPhotonEta=new TH1D("BestPhotonEta","Eta of the best photon for events passing denominator trigger",100,-5,5);
  h_dPhiMETPho=new TH1D("dPhiMETPho","#Delta#Phi(MET,#gamma)",400,0,4);
  h_Ele1Pt=new TH1D("Ele1Pt","Leading ele Pt for events passing denominator trigger",200,0,2000);
  h_Ele2Pt=new TH1D("Ele2Pt","2nd leading ele Pt for events passing denominator trigger",200,0,2000);
  h_Ele1Eta=new TH1D("Ele1Eta","Leading ele eta for events passing denominator trigger",100,-5,5);

  h_QIsoRhoCorrEB=new TH1D("QIsoRhoCorrEB","Barrel Photon Q Isolatoin Rho Corrected",200,0,100);
  h_sieieEB=new TH1D("sieieEB","#sigma_{i#etai#eta} for Barrel photon",50,0,0.05);
  h_QIsoRhoCorrEE=new TH1D("QIsoRhoCorrEE","Endcap Photon Q Isolatoin Rho Corrected",200,0,100);
  h_sieieEE=new TH1D("sieieEE","#sigma_{i#etai#eta} for Endcap photon",50,0,0.05);
  h_PhoHOverE=new TH1D("PhotonHoverE","H/E for photon",60,0,0.06);
  h_HT=new TH1D("HT","HT for events passing denominator trigger",400,0,4000);
  h_MHT=new TH1D("MHT","MHT for events passing denominator trigger",200,0,2000);
  h_nJets=new TH1D("nJets","nJets for events passing denominator trigger",25,0,25);

  h_STvBin=new TH1D("STvBin","ST in variable bins for events passing denominator trigger",STLowEdge.size()-1,&(STLowEdge[0]));
  h_BestPhotonPt_vBin=new TH1D("PhoPtvBin","Photon Pt in variable bins for events passing denominator trigger",PhoPtLowEdge.size()-1,&(PhoPtLowEdge[0]));
  h_BestPhotonPt_vBin2=new TH1D("PhoPtvBin2","Photon Pt in variable bins2 for events passing denominator trigger",PhoPtLowEdge.size()-1,&(PhoPtLowEdge[0]));
  h_Ele1Pt_vBin=new TH1D("Ele1PtvBin","Leading ele Pt in variable bins for events passing denominator trigger",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));
  h_Ele2Pt_vBin=new TH1D("Ele2PtvBin","2nd leading ele Pt in variable bins for events passing denominator trigger",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));
  h_HTvBin=new TH1D("HTvBin","HT in variable bins for events passing denominator trigger",STLowEdge.size()-1,&(STLowEdge[0]));

  h_MuPt=new TH1D("MuPt","Muon Pt",200,0,2000);
  h_MuPt_vBin=new TH1D("MuPt_vBin","Muon Pt in vBins",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));
  h_dPhi1=new TH1D("dPhi1","#Delta#Phi(leading jet,MEt)",80,0,4);
  h_dPhi2=new TH1D("dPhi2","#Delta#Phi(sub-leading jet,MEt)",80,0,4);

  h2_PhoPtST=new TH2D("PhoPtST","x:Photon Pt vs ST for events passing denominator trigger",200,0,2000,500,0,5000);
  h2_QIsoSieieEB=new TH2D("QIsoSieieEB","x:Q Isolatoin Rho Corrected vs #sigma_{i#etai#eta} for Barrel photon",200,0,100,50,0,0.05);
  h2_QIsoSieieEE=new TH2D("QIsoSieieEE","x:Q Isolatoin Rho Corrected vs #sigma_{i#etai#eta} for Endcap photon",200,0,100,50,0,0.05);
  h_SBins_v6_CD_EW_50bin = new TH1D("AllSBins_v6_CD_EW_50bin","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);

   //===============================================================
  h_SBins_v6_CD_EW_50bin_Req = new TH1D("AllSBins_v6_CD_EW_50bin_Req","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);

  h_Prescale_Req=new TH1D("Prescale_Req","Prescale for the required trigger",1001,-1,1000);
  h_ST_Req=new TH1D("ST_Req","ST_Req",400,0,4000);
  h_MET_Req=new TH1D("MET_Req","MET_Req",200,0,2000);
  h_nHadJets_Req=new TH1D("nHadJets_Req","no. of jets(only hadronic jets,not counting photon)_Req",25,0,25);
  h_BTags_Req=new TH1D("nBTags_Req","no. of B tags_Req",10,0,10);
  h_BestPhotonPt_Req=new TH1D("BestPhotonPt_Req","Pt of the best photon for events_Req",150,0,1500);
  h_BestPhotonEta_Req=new TH1D("BestPhotonEta_Req","Eta of the best photon for events passing denominator trigger_Req",100,-5,5);
  h_dPhiMETPho_Req=new TH1D("dPhiMETPho_Req","#Delta#Phi(MET,#gamma)_Req",400,0,4);
  h_Ele1Pt_Req=new TH1D("Ele1Pt_Req","Leading ele Pt events_Req",200,0,2000);
  h_Ele2Pt_Req=new TH1D("Ele2Pt_Req","2nd leading ele Pt events_Req",200,0,2000);
  h_Ele1Eta_Req=new TH1D("Ele1Eta_Req","Leading ele eta for events_req",100,-5,5);

  h_HT_Req=new TH1D("HT_Req","HT_Req",400,0,4000);
  h_MHT_Req=new TH1D("MHT_Req","MHT_Req",200,0,2000);
  h_nJets_Req=new TH1D("nJets_Req","nJets_Req",25,0,25);

  h_METvBin_Req=new TH1D("METvBin_Req","MET in variable bins for events passing trigger_Req",METLowEdge.size()-1,&(METLowEdge[0]));
  h_METvBin2_Req=new TH1D("METvBin2_Req","MET in variable bins for events passing trigger_Req",METLowEdge_v2.size()-1,&(METLowEdge_v2[0]));
  h_METvBin3_Req=new TH1D("METvBin3_Req","MET in variable bins for events passing trigger_Req",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj2_Req=new TH1D("METvBin_nj2_Req","MET in variable bins for events passing trigger_Req",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5_Req=new TH1D("METvBin_nj5_Req","MET in variable bins for events passing trigger_Req",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7_Req=new TH1D("METvBin_nj7_Req","MET in variable bins for events passing trigger_Req",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));

  h_METvBin_nj2_nb0_Req=new TH1D("METvBin_nj2_nb0_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5_nb0_Req=new TH1D("METvBin_nj5_nb0_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7_nb0_Req=new TH1D("METvBin_nj7_nb0_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj2_nb1_Req=new TH1D("METvBin_nj2_nb1_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj5_nb1_Req=new TH1D("METvBin_nj5_nb1_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));
  h_METvBin_nj7_nb1_Req=new TH1D("METvBin_nj7_nb1_Req","MET in variable bins for events passing denominator trigger",METLowEdge_v3.size()-1,&(METLowEdge_v3[0]));

  h_MHTvBin_Req=new TH1D("MHTvBin_Req","MHT in variable bins for events passing trigger_Req",METLowEdge.size()-1,&(METLowEdge[0]));

  h_STvBin_Req=new TH1D("STvBin_Req","ST in variable bins for events passing trigger_Req",STLowEdge.size()-1,&(STLowEdge[0]));
  h_BestPhotonPt_vBin_Req=new TH1D("PhoPtvBin_Req","Photon Pt in variable bins for events passing trigger_Req",PhoPtLowEdge.size()-1,&(PhoPtLowEdge[0]));
  h_BestPhotonPt_vBin2_Req=new TH1D("PhoPtvBin2_Req","Photon Pt in variable bins2 for events passing trigger_Req",PhoPtLowEdge.size()-1,&(PhoPtLowEdge[0]));
  h_Ele1Pt_vBin_Req=new TH1D("Ele1PtvBin_Req","Leading ele Pt in variable bins for events passing trigger_Req",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));
  h_Ele2Pt_vBin_Req=new TH1D("Ele2PtvBin_Req","2nd leading ele Pt in variable bins for events passing trigger_Req",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));
  h_HTvBin_Req=new TH1D("HTvBin_Req","HT in variable bins for events passing trigger_Req",STLowEdge.size()-1,&(STLowEdge[0]));

  h_MuPt_Req=new TH1D("MuPt_Req","Muon Pt_Req",200,0,2000);
  h_MuPt_vBin_Req=new TH1D("MuPt_vBin_Req","Muon Pt in vBins_Req",ElePtLowEdge.size()-1,&(ElePtLowEdge[0]));

  h_QIsoRhoCorrEB_Req=new TH1D("QIsoRhoCorrEB_Req","Barrel Photon Q Isolatoin Rho Corrected_Req",200,0,100);
  h_sieieEB_Req=new TH1D("sieieEB_Req","#sigma_{i#etai#eta} for Barrel photon_Req",50,0,0.05);
  h_QIsoRhoCorrEE_Req=new TH1D("QIsoRhoCorrEE_Req","Endcap Photon Q Isolatoin Rho Corrected_Req",200,0,100);
  h_sieieEE_Req=new TH1D("sieieEE_Req","#sigma_{i#etai#eta} for Endcap photon_Req",50,0,0.05);
  h_PhoHOverE_Req=new TH1D("PhotonHoverE_Req","H/E for photon_Req",60,0,0.06);
  h_dPhi1_Req=new TH1D("dPhi1_Req","#Delta#Phi(leading jet,MEt)_Req",80,0,4);
  h_dPhi2_Req=new TH1D("dPhi2_Req","#Delta#Phi(sub-leading jet,MEt)_Req",80,0,4);

  h2_PhoPtST_Req=new TH2D("PhoPtST_Req","x:Photon Pt vs ST for events passing trigger_Req",200,0,2000,500,0,5000);
  h2_QIsoSieieEB_Req=new TH2D("QIsoSieieEB_Req","x:Q Isolatoin Rho Corrected vs #sigma_{i#etai#eta} for Barrel photon_Req",200,0,100,50,0,0.05);
  h2_QIsoSieieEE_Req=new TH2D("QIsoSieieEE_Req","x:Q Isolatoin Rho Corrected vs #sigma_{i#etai#eta} for Endcap photon_Req",200,0,100,50,0,0.05);
 
}

Single_elec::Single_elec(const TString &inputFileList, const char *outFileName, const char* dataset) {
  string nameData=dataset;//vvv
  TChain *tree;
  if(nameData=="data") tree = new TChain("TreeMaker2/PreSelection");
  else tree = new TChain("PreSelection");
  //if(nameData=="signalH") tree = new TChain("TreeMaker2/PreSelection");//vvv
  if( ! FillChain(tree, inputFileList) ) {
    std::cerr << "Cannot get the tree " << std::endl;
  } else {
    std::cout << "Initiating analysis of dataset " << dataset << std::endl;
  }

  //if(nameData!="signalH") nameData="BG";
  //cout<<"Treating the input files as "<<nameData<<" for setting tree branches"<<endl;
  NtupleVariables::Init(tree,nameData);

  char outflName[100];
  sprintf(outflName,"%s_%s",dataset,outFileName);
  BookHistogram(outFileName);
}

Bool_t Single_elec::FillChain(TChain *chain, const TString &inputFileList) {

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

Long64_t Single_elec::LoadTree(Long64_t entry) {
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

Single_elec::~Single_elec() { 

  if (!fChain) return;
  delete fChain->GetCurrentFile();
  oFile->cd();
  oFile->Write();
  oFile->Close();

}

#endif

