#define Mulijet_cxx
#include "Mulijet.h"
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include"TGraphErrors.h"
#include"TGraphAsymmErrors.h"
#include "btag/BTagCorrector.h"


using namespace std;
bool applISRWtsTottbar=true;
bool full_Run2=true;
bool applyE_SF=false;
bool apply_METfilters=true;
bool apply_L1=true;
bool apply_HEMveto=true;
bool applytrg=true;
bool applybTagSFs=false;
bool do_prediction=false;
bool applyRf=false;
bool applyKf=false;
bool applyKxR=true;
bool applyPUwt=true;
bool highdphi=false;
bool useValRegion=true;
bool debug = false;
bool hadj=false;
TString puwt="central";
//TString puwt="up";
bool old=false;
int main(int argc, char* argv[])
{

  if (argc < 2) {
    cerr << "Please give 3 arguments " << "runList " << " " << "outputFileName" << " " << "dataset" << endl;
    return -1;
  }
  const char *inputFileList = argv[1];
  const char *outFileName   = argv[2];
  const char *data          = argv[3];

  Mulijet ana(inputFileList, outFileName, data);
  cout << "dataset " << data << " " << endl;

  ana.EventLoop(data,inputFileList);

  return 0;
}

void Mulijet::EventLoop(const char *data,const char *inputFileList) {
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  cout << "nentries " << nentries << endl;
  cout << "Analyzing dataset " << data << " " << endl;

  TString s_data=data;
  Long64_t nbytes = 0, nb = 0;
  int decade = 0;
  // if(s_data.Contains("elec_data")) {elec=true,muon=false;}
  // if(s_data.Contains("muon_data")) {elec=false,muon=true;}
  TCanvas *cA = new TCanvas("METEff","Signal efficiency",1500,850);
  int evtSurvived=0;  
  int EW_evtSurvived=0;
  int EW_evtSurvived_SB=0;  
  int EW_evtSurvived_htag=0;  
  int EW_evtSurvived_wtag=0;  
  int SP_evtSurvived=0;  
  int EW_noSB_evtSurvived=0;

  TFile *pufile,*TF,*TF2,*TF3,*E_SF,*Egamma_SF,*TF4,*TF5;
  cout<<"Applying electron scale factors ? "<<applyE_SF<<endl;
  cout<<"Applying MET filters ? "<<apply_METfilters<<endl;
  if(s_data.Contains("v17_2016")){
    pufile = TFile::Open("../PileupHistograms_2016_69mb_pm5.root","READ");
    cout<<"Applying L1 prefiring prob.? "<<apply_L1<<endl;
  }
  if(s_data.Contains("v17_2017")){
    pufile = TFile::Open("../PileupHistograms_2017_69mb_pm5.root","READ");
    cout<<"Applying L1 prefiring prob.? "<<apply_L1<<endl;
  }
  if(s_data.Contains("v17_2018")){
    pufile = TFile::Open("../PileupHistograms_2018_69mb_pm5.root","READ");
    cout<<"Applying HEM veto? "<<apply_HEMveto<<endl;
  }

  double puWtNom = 1.0, puWtup = 1.0, puWtdown = 1.0;


  TH1D *tf,*tf4,*tf5;
  TH3D *tf1;//\,*tf_SP,*tf_SP_2,*tf_SP_3;
  TH2F *e_id, *e_iso, *e_SF;
  TH2D *tf2,*tf3;
  if(do_prediction)
    {
      //      TF = TFile::Open("RK_lowMET_data.root","READ");
      TF = TFile::Open("K_validation.root","READ");  
      tf=(TH1D*)TF->FindObjectAny("fr");
    }
  TH1* puhist ;
  TH1* puhistUp;  
  TH1* puhistDown;

  if(s_data.Contains("v17"))
    {
      puhist     = (TH1*)pufile->Get("pu_weights_central");
      puhistUp   = (TH1*)pufile->Get("pu_weights_up");
      puhistDown = (TH1*)pufile->Get("pu_weights_down");

    
    }
  int fListIndxOld=-1;
  double prob0=-100,prob1=-100;
  double prob2=-100,prob3=-100;
  double total_prob0=0,total_prob1=0;
  double total_prob2=0,total_prob3=0;

 
  vector<TString> inFileName;  
  TString sampleName;
  string str1;
  ifstream runListFile(inputFileList);
  TFile *currFile;
  while (std::getline(runListFile, str1)) {
    inFileName.push_back(str1);
  }runListFile.close();
  cout<<"applying b-tag SFs for MC? "<<applybTagSFs<<endl;
  BTagCorrector btagcorr;
 

  bool v17=true, v12=false;
  // bool v17=false, v12=true;
  bool EWselection=true;
  double qmulti=-1,leadjet_qmulti=-1,leadjet_Pt=-1,leadbjet_tag=-1 ,leadbjet_tag1=-1,leadbjet_tag2=-1,leadbjet_tag3=-1,qmulti1=-1,qmulti2=-1,qmulti3=-1;
  int genphomatch_after=0,genphomatch_before=0,remain=0,after_bjetdisc=0;
  int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,met=0,st=0,nbj0=0,nbj1=0,nbj2=0,nbj3=0,lep=0,lep1=0,lep2=0,lep3=0,lep3_v2=0,lep3_v1=0,zwin=0,reg_A=0,reg_B=0,reg_C=0,reg_D=0, phopt_not0=0,phopt_0=0;
  double wt_nbj0=0,wt_nbj1=0,wt_nbj2=0,wt_nbj3=0;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //  for (Long64_t jentry=0; jentry<1000;jentry++) {
    int total_lost_el = 0,cr_el=0,sr_el,e_index=-1,nlep=0;

    // ==============print number of events done == == == == == == == =
    double progress = 10.0 * jentry / (1.0 * nentries);
    int k = int (progress);
    if (k > decade)
      cout << 10 * k << " %" << endl;
    decade = k;
    

    // ===============read this entry == == == == == == == == == == == 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;


    //handles for EW region ///////////////
     bool EWselec=false;
    bool EWselec_Wtag=false;
    bool EWselec_Htag=false;
    bool EWselec_SB1=false;
    bool EWselec_SB2=false;
    bool EWselec1=false;
    ////////////////////////////////
    double p0=-100, p1=-100, p2=-100;
    double p0_=-100, p1_=-100, p2_=-100;
    if(debug) cout<<"===================== event no. : "<<jentry<<endl;
    if(!s_data.Contains("data"))
      {
	highdphi=true;
        if(s_data.Contains("2016") && highdphi) {lumiInfb=35.922; p0_=1.66539e+02; p1_=8.13254e+01; p2_=9.71152e-01; deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017") && highdphi) {lumiInfb=41.529; p0_=1.86744e+02; p1_=6.74978e+01; p2_=9.65333e-01; deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018") && highdphi) {lumiInfb=59.74; p0_=1.89868e+02; p1_=6.60434e+01; p2_=9.79618e-01; deepCSVvalue = 0.4184;}
	highdphi=false;
        if(s_data.Contains("2016") && !highdphi) {lumiInfb=35.922; p0=1.67229e+02; p1=8.52729e+01; p2=8.29784e-01; deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017") && !highdphi) {lumiInfb=41.529; p0=1.67641e+02; p1=1.21487e+02; p2=9.23864e-01; deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018") && !highdphi) {lumiInfb=59.74; p0=1.45529e+02; p1=1.08431e+02; p2=9.27220e-01; deepCSVvalue = 0.4184;}
	/*
        if(s_data.Contains("2016") && !highdphi) {lumiInfb=35.922; p0=1.87520e+02; p1=1.73112e+02; p2=9.34438e-01; deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017") && !highdphi) {lumiInfb=41.529; p0=1.64589e+02; p1=1.98374e+02; p2=9.24154e-01; deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018") && !highdphi) {lumiInfb=59.74; p0=1.38193e+02; p1=1.72334e+02; p2=9.52805e-01; deepCSVvalue = 0.4184;}
	*/
	
	if(s_data.Contains("FastSim") && s_data.Contains("2016")) {lumiInfb=137.19; deepCSVvalue = 0.6321;}
      }

    if(s_data.Contains("data"))
      {
	if(s_data.Contains("2016")) {deepCSVvalue = 0.6321;}
	if(s_data.Contains("2017")) {deepCSVvalue = 0.4941;}
	if(s_data.Contains("2018")) {deepCSVvalue = 0.4184;}
      }
      
    if(s_data.Contains("data")) wt=1.0;
    if(applyPUwt && s_data.Contains("v17")){
      puWtNom = (puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1)))));
      if(puWtNom > 1e-10 && puWtNom < 100){
	wt = wt * puWtNom;
	puWtup = (puhistUp->GetBinContent(puhistUp->GetXaxis()->FindBin(min(TrueNumInteractions,puhistUp->GetBinLowEdge(puhistUp->GetNbinsX()+1)))))/puWtNom;
	puWtdown = (puhistDown->GetBinContent(puhistDown->GetXaxis()->FindBin(min(TrueNumInteractions,puhistDown->GetBinLowEdge(puhistDown->GetNbinsX()+1)))))/puWtNom;
	if(puWtup/puWtNom > 100) puWtup = 1.0;
	if(puWtdown/puWtNom > 100) puWtdown = 1.0;
      }
    }
    else {puWtup = 1.0; puWtdown = 1.0;}


    ///////=======  L1 Prefiring issue ===========/////////
 
    if((s_data.Contains("v17_2016") || s_data.Contains("v17_2017") ) && apply_L1){
     if(puwt=="up") wt=Weight*1000.0*NonPrefiringProb*lumiInfb*puWtup; 
     if(puwt=="down") wt=Weight*1000.0*NonPrefiringProb*lumiInfb*puWtdown; 
     else wt=Weight*1000.0*NonPrefiringProb*lumiInfb*puWtNom;
     h_nEvts->Fill(1,wt);
   }

   if((s_data.Contains("v17_2016") || s_data.Contains("v17_2017") ) && !apply_L1){
      if(puwt=="up") wt=Weight*1000.0*lumiInfb*puWtup; 
      if(puwt=="down") wt=Weight*1000.0*lumiInfb*puWtdown; 
      else wt=Weight*1000.0*lumiInfb*puWtNom;
      h_nEvts->Fill(1,wt);
   }


   if(s_data.Contains("v17_2018")){
      if(puwt=="up") wt=Weight*1000.0*lumiInfb*puWtup; 
      if(puwt=="down") wt=Weight*1000.0*lumiInfb*puWtdown; 
      else wt=Weight*1000.0*lumiInfb*puWtNom;
      h_nEvts->Fill(1,wt);
    }
   if(debug) cout<<"before HEM filters"<<endl;

   //HEM veto------------
 
   bool HEMaffected = false;
   if(s_data.Contains("data_2018") && RunNum >=319077){
     for(int i=0;i<Jets->size();i++){
       if((*Jets)[i].Pt() < 30) continue;
       if( (*Jets)[i].Eta() >= -3.20 && (*Jets)[i].Eta() <= -1.2 && (*Jets)[i].Phi() >= -1.77 && (*Jets)[i].Phi() <= -0.67 && (abs(DeltaPhi(METPhi,(*Jets)[i].Phi())) < 0.5) ){HEMaffected = true; break;}
     }
   }
   /*
   if(s_data.Contains("v17_2018")){//for MC 2018
     if( (EvtNum % 1000 > 1000*21.0/59.6)) 
       {
	 for(int i=0;i<Jets->size();i++){
	   if((*Jets)[i].Pt() < 30) continue;
	   if( (*Jets)[i].Eta() >= -3.20 && (*Jets)[i].Eta() <= -1.2 && (*Jets)[i].Phi() >= -1.77 && (*Jets)[i].Phi() <= -0.67 && (abs(DeltaPhi(METPhi,(*Jets)[i].Phi())) < 0.5) ){HEMaffected =true; break;}
	 }
       }
   }
   */
   if(HEMaffected) continue;
   
/*
     bool HEMaffected = false;
    //////-======== HEM issue ==================//////////////
    if(s_data.Contains("2018") && apply_HEMveto){
      for(int i=0; i<Electrons->size();i++)
	{
	  if((*Electrons_passIso)[i]==1)
	    { 
	      if((*Electrons)[i].Pt() >30 && (*Electrons)[i].Eta() > -3.0 && (*Electrons)[i].Eta() < -1.4 && (*Electrons)[i].Phi() > -1.57 && (*Electrons)[i].Phi() < -0.87) {HEMaffected = true; break;}
	    }      
	}
      for(int i=0; i<Jets->size();i++)
        if((*Jets)[i].Pt() > 30 && (*Jets)[i].Eta() > -3.2 && (*Jets)[i].Eta() < -1.2 && (*Jets)[i].Phi() > -1.77 && (*Jets)[i].Phi() < -0.67 && DeltaPhi((*Jets)[i].Pt(),METPhi)<0.5) {HEMaffected = true; break;}
     if(HEMaffected == true) continue;
   }
   */
   if(debug) cout<<"after HEM filters"<<endl;

    bool tighte_trgpass=true;
    if(s_data.Contains("data") && applytrg)
      {
	wt=1;
        if(TriggerPass->size()!=148) continue;
        if(((*TriggerPass)[124]==1 || (*TriggerPass)[110]==1 || (*TriggerPass)[112]==1 || (*TriggerPass)[116]==1 || (*TriggerPass)[118]==1 || (*TriggerPass)[120]==1 )) tighte_trgpass=true;

	else tighte_trgpass=false;
        if(tighte_trgpass==false)  continue;
      }
    double wt_trg_hd=1,wt_trg_ld=1;
    if(!s_data.Contains("data") && !s_data.Contains("FastSim") && applytrg)
      {
	wt_trg_hd = (((TMath::Erf((MET - p0)/p1)+1)/2.0)*p2);
        wt_trg_ld = (((TMath::Erf((MET - p0_)/p1_)+1)/2.0)*p2_);
      }

    if(!s_data.Contains("FastSim") && apply_METfilters){
     
      if(s_data.Contains("data"))
      	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedExtraFilter && eeBadScFilter==1 && NVtx>0 && eeBadScFilter)) continue;

      if(s_data.Contains("v17"))
      	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedExtraFilter && NVtx>0 && eeBadScFilter)) continue;

    if(PFCaloMETRatio >=  5) continue;
    if(MET/CaloMET > 2.0) continue;

    }
    if(debug) cout<<"after filters"<<endl;
 
    if(globalSuperTightHalo2016Filter) a++;
    if(HBHENoiseFilter) b++;
    if(HBHEIsoNoiseFilter) c++;
    if(EcalDeadCellTriggerPrimitiveFilter) d++;
    if(ecalBadCalibReducedExtraFilter) e++;
    if(BadPFMuonFilter) f++;
    if(PrimaryVertexFilter) g++;
    if(NVtx>0) h++;
    //    if(wt<0) continue;   

    //-----------------------------------------cutflows--------------------------------------    
    h_selectBaselineYields_->Fill("No cuts, evt in 35.9/fb",1);
    h_selectBaselineYields_2->Fill("No cuts, evt in 35.9/fb",wt);
    h_selectBaselineYields_2->Fill("Good #gamma with Pt > 100",wt);
    h_selectBaselineYields_2->Fill("veto electron Muon",wt);
    h_selectBaselineYields_2->Fill("veto electron > 1",wt);
    h_selectBaselineYields_2->Fill("Iso track",wt);
    h_selectBaselineYields_2->Fill("MET>100",wt);
    h_selectBaselineYields_2->Fill("nJets >= 2",wt);
    //h_selectBaselineYields_2->Fill("ST & photon pt selec",wt);
    h_selectBaselineYields_2->Fill("MET & photon pt selec",wt);
    h_selectBaselineYields_2->Fill("dPhi1 & dPhi2 >= 0.3",wt);
    h_selectBaselineYields_2->Fill("Before Pre-Selections",wt);
    h_selectBaselineYields_2->Fill("real photon",wt);
    h_selectBaselineYields_2->Fill("Pass Acceptance",wt);
    h_selectBaselineYields_2->Fill("Pass el^{-} ID",wt);
    h_selectBaselineYields_2->Fill("Pass Isolation",wt);

    h_selectBaselineYields_2->Fill("SR : Electrons = 0",wt);
    h_selectBaselineYields_2->Fill("CR : Electrons = 1",wt);

   bool event_passed_old=false, event_passed_new=false;

   if(s_data.Contains("TTJets2") && madHT>600) continue; 

   //============== Baseline Selections====================//

   if(applISRWtsTottbar && ((s_data.Contains("TTJets_v17_2016")||s_data.Contains("TTJets2_v17_2016")||s_data.Contains("TTG_v17_2016")))){
     double isrWt = 0;
     vector<double> D_values={1.0697, 1.0150, 0.9917, 0.9435, 0.95};
     vector<double> isrwt_arr={1., 0.920, 0.821, 0.715, 0.662, 0.561, 0.511};
     if(NJetsISR>=6) isrWt = isrwt_arr[6];
     else isrWt = isrwt_arr[NJetsISR];

     if(madHT<600) isrWt = isrWt*D_values[0];
     else if(madHT < 800) isrWt = isrWt*D_values[1];
     else if(madHT < 1200) isrWt = isrWt*D_values[2];
     else if(madHT < 2500) isrWt = isrWt*D_values[3];
     else isrWt = isrWt*D_values[4];
     wt = wt*isrWt;
   }
   int hasEle=0, hasPho=0, hasPho_px=0;
   TLorentzVector bestPhoton=getBestPhoton_0();
   TLorentzVector nobestPhoton=getPhoton_withoutfullID();
   bool bestPhoHasPxlSeed=true;

   if(!s_data.Contains("data"))
     {
       
       genphomatch_before++;
       double mindr_Pho_genlep=getGenLep(bestPhoton);
       double mindr_genPho_genlep=getGendRLepPho();
       
       if(s_data=="genprompt" || s_data.Contains("TTG") )
	 {
	   if(!hasGenPromptPhoton)
	     {
	       if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	     }
	   else if(hasGenPromptPhoton)
	     {
	       if(!(madMinPhotonDeltaR >= 0.3 && mindr_Pho_genlep >=0.5 ))continue;
	     }
	 }//Gen prompt                                                                                                                                                      
       if(s_data=="genprompt" || s_data.Contains("WG"))
	 {
	   if(!hasGenPromptPhoton)
	     {
	       if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	     }
	   else if(hasGenPromptPhoton)
	     {
	       if(!(madMinPhotonDeltaR >= 0.5 && mindr_Pho_genlep >=0.5 ))continue;
	     }
	 }//Gen prompt                                                                                                                                                      

       if(s_data.Contains("WJets"))
	 {
	   if(!hasGenPromptPhoton)
	     {
	       if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	     }
	   else if(hasGenPromptPhoton)
	     {
	       if(!(madMinPhotonDeltaR < 0.5 || mindr_Pho_genlep < 0.5)) continue;
	     }
	 }
       if(s_data.Contains("TTJets") || s_data.Contains("TTJets_v17") || s_data.Contains("TTJets2_v17"))
	 {
	   if(!hasGenPromptPhoton)
	     {
	       if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	     }
	   else if(hasGenPromptPhoton)
	     {
	       if(!(madMinPhotonDeltaR < 0.3 || mindr_Pho_genlep < 0.5)) continue;
	     }
	 }
       if(hasGenPromptPhoton && (s_data.Contains("GJetsDR")))
	 {
	   //	   if(!(madMinPhotonDeltaR>0.5  && madMinDeltaRStatus==1 )) continue;
           if(!(madMinPhotonDeltaR>0.4)) continue;
	   h_madminphotonDR->Fill(madMinPhotonDeltaR,wt);
	   h_mindr_ph_lep->Fill(mindr_Pho_genlep,wt);
	   h_mindr_genph_lep->Fill(madMinDeltaRStatus,wt);
	 }
       if(hasGenPromptPhoton && (s_data.Contains("GJetsHT")))
	 {
	   if(!(madMinPhotonDeltaR<=0.4)) continue;
	   h_madminphotonDR->Fill(madMinPhotonDeltaR,wt);
	   h_mindr_ph_lep->Fill(mindr_Pho_genlep,wt);
	   h_mindr_genph_lep->Fill(madMinDeltaRStatus,wt);
	 }
       
       if(hasGenPromptPhoton && (s_data.Contains("QCD")))
	 {
           if((madMinPhotonDeltaR>0.4)) continue;
	   //	   if(!(madMinPhotonDeltaR<=0.5 || mindr_Pho_genlep<=0.5) ) continue;
	   h_madminphotonDR->Fill(madMinPhotonDeltaR,wt);
	   h_mindr_ph_lep->Fill(mindr_Pho_genlep,wt);
	   h_mindr_genph_lep->Fill(madMinDeltaRStatus,wt);
	 }
       if(hasGenPromptPhoton && (s_data.Contains("ZG")))
	 {
	   if(!(madMinPhotonDeltaR>0.5)) continue;
	 }
       if(hasGenPromptPhoton && (s_data.Contains("ZJets")))
	 {
	   if(!(madMinPhotonDeltaR<=0.5)) continue;
	 }

     }//Gen prompt                                                                                                                                                      

     
   genphomatch_after++;




   vector<TLorentzVector> goodPho_;
   // vector<int> goodPhoIndx;
   for(int iPho=0;iPho<Photons->size();iPho++){
     if( (*Photons_fullID)[iPho] ) 
       {
	 goodPho_.push_back( (*Photons)[iPho] );
	 // goodPhoIndx.push_back(iPho);
       }
   }

   //   if((*Photons_hasPixelSeed)[bestPhotonIndxAmongPhotons]<0.001) bestPhoHasPxlSeed=false;
   //  if( bestPhoHasPxlSeed ) continue;
   met++;
   if(bestPhoton.Pt()>=1) phopt_not0++;
   if(bestPhoton.Pt()<1)
     {
       h_selectBaselineYields_->Fill("Good #gamma with Pt > 100",wt);
     }
   else continue;
   phopt_0++;
   if(isoElectronTracks!=0 || isoMuonTracks!=0 || isoPionTracks!=0) continue;
   if(NElectrons!=0 || NMuons!=0) continue;
   
   
   if( MET > 100 )    
     {    
       h_selectBaselineYields_->Fill("MET > 100",wt);
       //cout<<MET<<endl;
     }
   else
     {
       continue;
     }    //---------------------------------------------------------------------------------                                    
   //   cout<<"Event with 0 good photon & Photons->Pt() = "<<bestPhoton.Pt()<<endl;


   int proxyJetIdx = -100;
   double proxyJetPhoFrac = 0.0;
   bool isProxyPho = false;
   if(useValRegion){
     for(int i=0;i<Jets->size();i++){
       if((*Jets)[i].Pt() < 100 || abs((*Jets)[i].Eta()) > 2.4 || (*Jets_photonEnergyFraction)[i] < 0.0) continue;
       if(abs((*Jets)[i].Eta()) > 1.4442 && abs((*Jets)[i].Eta()) < 1.566) continue;
       if(proxyJetPhoFrac < (*Jets_photonEnergyFraction)[i]){
	 proxyJetPhoFrac = (*Jets_photonEnergyFraction)[i];
	 proxyJetIdx = i;
       }
     }
     // if((*Jets)[0].Pt() < 100 || abs((*Jets)[0].Eta()) > 2.4 || (*Jets_photonEnergyFraction)[0] < 0.6) continue;
     // proxyJetPhoFrac = (*Jets_photonEnergyFraction)[0];
     // proxyJetIdx = 0;
     if(proxyJetIdx >= 0) bestPhoton = (*Jets)[proxyJetIdx];
     isProxyPho = true;
   }
   if(useValRegion && !isProxyPho) continue;//reject event if no proxy is found in VR
   //    bool eMatchedG=check_eMatchedtoGamma();//this may not be necessary since e veto is there.
   //    if(bestPhoton.Pt()<100) continue;



   float dphi1_=4;

   double nbjets=0;
   int bJet1Idx = -1;

   vector<TLorentzVector> nonbjets,bjets;

   //calulate ST and HadJets by cleaning the matching jet.
   bool hadJetID=false, EMJetID=true;
   int minDRindx=-100,phoMatchingJetIndx=-100,nHadJets=0, minDRindxl1=-100, minDRindxl2=-100, minDRindxl3=-100;
   double minDR=99999, ST=0, remJetPt=0, minDRl1=10000, minDRl2=10000, minDRl3=10000,mt_Pho=0.;
   vector<TLorentzVector> hadJets, EMJets;
   vector<int> hadJets_hadronFlavor;
   vector<bool> hadJets_HTMask;
   vector<double> hadJets_bJetTagDeepCSVBvsAll;

   for(int i=0;i<Jets->size();i++){
     if( ((*Jets)[i].Pt() > 30) && (abs((*Jets)[i].Eta()) <= 2.4) ){
       double dR=bestPhoton.DeltaR((*Jets)[i]);
       if(dR<minDR){minDR=dR;minDRindx=i;}
     }
   }//loop over jets
   if( minDR > 0.3 )  minDRindx   = -100;

   int q=0;
   for(int i=0;i<Jets->size();i++){
     if( ((*Jets)[i].Pt() > 30) && (abs((*Jets)[i].Eta()) <=  2.4) ){
       q++;
       if(q==1){
	 h2_JetEta_Phi->Fill((*Jets)[0].Eta(),(*Jets)[0].Phi(),wt); 
	 h_JetPt->Fill((*Jets)[0].Pt(),wt);
	 h_JetEta->Fill((*Jets)[0].Eta(),wt);
	 h_JetPhi->Fill((*Jets)[0].Phi(),wt);
	 h2_JetEta_Pt->Fill((*Jets)[0].Eta(),(*Jets)[0].Pt(),wt);
       }
       if((i!=minDRindx))
	 {

	   hadJetID=(*Jets_ID)[i];
	   if(hadJetID)
	     {

	       hadJets_hadronFlavor.push_back((*Jets_hadronFlavor)[i]);
	       hadJets_HTMask.push_back((*Jets_HTMask)[i]);
	       hadJets_bJetTagDeepCSVBvsAll.push_back((*Jets_bJetTagDeepCSVBvsAll)[i]);
	       hadJets.push_back((*Jets)[i]);
	       if((*Jets_bJetTagDeepCSVBvsAll)[i] > deepCSVvalue){                                        
		 bjets.push_back((*Jets)[i]); bJet1Idx = i;}
	     }
	 }
       else if(i==minDRindx)
	 {
	   EMJets.push_back((*Jets)[i]);
	   if(EMJetID) EMJetID=(*Jets_ID)[i];
	   // cout<<jentry<<" : "<<i<<" , minDR for photon having idx "<<minDRindx<<" : "<<minDR<<" , minDR for e having idx "<<minDRindxl1<<" : "<<minDRl1<<" , minDR for e having idx "<<minDRindxl2<<" : "<<minDRl2<<endl;
	 }
     }
   }
   for(int i=0;i<hadJets.size();i++){
     if( (abs(hadJets[i].Eta()) < 2.4) ){ST=ST+(hadJets[i].Pt());}
     if( (abs(hadJets[i].Eta()) < 2.4) ){nHadJets++;}
   }

   for(int i=0;i<bjets.size();i++)
     if( (abs(bjets[i].Eta()) < 2.4) ){nbjets++;}

   h_deepcsv->Fill(bjets.size(),wt);


   if( minDR<0.3 )
     {
       phoMatchingJetIndx=minDRindx;
       leadbjet_tag1=(*Jets_bJetTagDeepCSVBvsAll)[phoMatchingJetIndx];
       qmulti1=(*Jets_chargedMultiplicity)[phoMatchingJetIndx];
     }


   if( minDR<0.3 ){
     ST=ST+bestPhoton.Pt();
   }
   sortTLorVec(&hadJets);

   //ST and HadJets have been determined. Now calulate dPhi b/w MET and leading HadJets.
   double dPhi_METjet1=3.8,dPhi_METjet2=3.8,dPhi_METjet3=3.8,dPhi_METjet4=3.8,dphiPho_MET=3.8,dphi_PhoLep1=3.8,dphi_PhoLep2=3.8,dRphoClstLep=1000.0;
   double mindphi=1000;
   if(bestPhoton.Pt()>0.1) dphiPho_MET=abs(DeltaPhi(METPhi,bestPhoton.Phi()));
   if(nHadJets > 0 ) {dPhi_METjet1 = abs(DeltaPhi(METPhi,(hadJets)[0].Phi())); mindphi=dPhi_METjet1;}
   if(nHadJets > 1 ) {dPhi_METjet2 = abs(DeltaPhi(METPhi,(hadJets)[1].Phi())); if(dPhi_METjet2<mindphi) mindphi=dPhi_METjet2;}
   if(nHadJets > 2 ) dPhi_METjet3 = abs(DeltaPhi(METPhi,(hadJets)[2].Phi()));
   if(nHadJets > 3 ) dPhi_METjet4 = abs(DeltaPhi(METPhi,(hadJets)[3].Phi()));
 


      float dphi1=4, dphi2=4, dphi3=4, dphi4=4;
      if(Jets->size() > 0 && (*Jets)[0].Pt() > 30 && abs((*Jets)[0].Eta()) < 5.0)
      dphi1 = (abs(DeltaPhi(METPhi,(*Jets)[0].Phi())));
    if(Jets->size() > 1 && (*Jets)[1].Pt() > 30 && abs((*Jets)[1].Eta()) < 5.0)
      dphi2 = (abs(DeltaPhi(METPhi,(*Jets)[1].Phi())));
    if(Jets->size() > 2 && (*Jets)[2].Pt() > 30 && abs((*Jets)[2].Eta()) < 5.0)
      dphi3 = (abs(DeltaPhi(METPhi,(*Jets)[2].Phi())));
    if(Jets->size() > 3 && (*Jets)[3].Pt() > 30 && abs((*Jets)[3].Eta()) < 5.0)
      dphi4 = (abs(DeltaPhi(METPhi,(*Jets)[3].Phi())));
    //    if((dphi1 < 1.5) || (dphi2 < 0.5) || (dphi3 < 0.3) || (dphi4 < 0.3)) continue; 

    if(phoMatchingJetIndx>=0 && ((*Jets)[phoMatchingJetIndx].Pt())/(bestPhoton.Pt()) < 1.0) continue;
    if(phoMatchingJetIndx<0) continue;

    double METcut=MET;
    if(old)
      {
	if( (ST <= 500) ) continue;                                                                                                                      
	if( !((ST>800 && bestPhoton.Pt()>100) || (bestPhoton.Pt()>190)) ) continue;                                                                           	
	METcut=100;
      }
    else METcut=200;
    bool process=true, cr=false, sr=false, region_A=false, region_B=false, region_C=false, region_D=false; 
	
    process = process &&  ST>300 && nHadJets >=2 && bestPhoton.Pt() >= 100 && NElectrons==0 && NMuons==0 && MET>METcut;    
    if(process) 
      sr=true;
    else continue;

    remain++;
	
    if(sr && MET<(METcut+100) && !(dPhi_METjet1>0.3 && dPhi_METjet2>0.3) )
      {      region_A=true; reg_A++; wt=wt;}//*wt_trg_hd;}
    else if(sr && MET>=(METcut+100) && !(dPhi_METjet1>0.3 && dPhi_METjet2>0.3) )
      {      region_B=true; reg_B++; wt=wt;}//*wt_trg_hd;}
    else if(sr && MET<(METcut+100) && (dPhi_METjet1>0.3 && dPhi_METjet2>0.3) )
      {      region_C=true; reg_C++; wt=wt;}//*wt_trg_ld;}
    else if(sr && MET>=(METcut+100) && (dPhi_METjet1>0.3 && dPhi_METjet2>0.3) )
      {      region_D=true; reg_D++; wt=wt;}//*wt_trg_hd;}
    else
      {
	cout<<"Event is invalid !!!!!"<<endl;
	continue;
      }
      

    //mindphi
    bool tmpcheck=false;
    if(tmpcheck)
      {
	cout<<jentry<<" : "<<mindphi<<" , dPhi_METjet1 = "<<dPhi_METjet1<<" , dPhi_METjet2 = "<<dPhi_METjet2<<endl;
	if(sr && MET<300 && !(mindphi>0.3) )
	  {      region_A=true; reg_A++;}
	else if(sr && MET>=300 && !(mindphi>0.3) )
	  {      region_B=true; reg_B++;}
	else if(sr && MET<300 && (mindphi>0.3) )
	  {      region_C=true; reg_C++;}
	else if(sr && MET>=300 && (mindphi>0.3) )
	  {      region_D=true; reg_D++;}
	else
	  {
	    cout<<"Event is invalid !!!!!"<<endl;
	    continue;
	  }
      }
    //    if(!(hadJetID && process)) continue;
    if(region_A||region_B||region_C||region_D)
      st++;
    //      if(!(region_A||region_B)) continue;
    //
   //=============Ak8 EW selection=====================//                                                                                                  


    if(fListIndxOld!=fCurrent){
      fListIndxOld = fCurrent;

      sampleName = inFileName[fCurrent];
      cout<<" sample name : "<<sampleName<<endl;
      if(applybTagSFs && s_data.Contains("v17")){
	currFile = TFile::Open(sampleName);
	btagcorr.SetEffs(currFile);
	if(s_data.Contains("v17_2016")) btagcorr.SetCalib("btag/DeepCSV_Moriond17_B_H_mod.csv");
	if(s_data.Contains("v17_2017")) btagcorr.SetCalib("btag/DeepCSV_94XSF_V3_B_F_mod.csv");
	if(s_data.Contains("v17_2018")) btagcorr.SetCalib("btag/DeepCSV_102XSF_V1_mod.csv");
      }
    }

    double corrbtag = 1.0;
    vector<double> prob;
    prob0=0;
    prob1=0;

    if(applybTagSFs && s_data.Contains("v17")){
      prob = btagcorr.GetCorrections(hadJets,hadJets_hadronFlavor,hadJets_HTMask);
      prob0=prob[0];
      prob1=prob[1]+prob[2]+prob[3];
    }
    else 
      {
	prob0=1;
	prob1=1;
      }
    


   //===============Ak8 Jets =====================                                                                                                          
   bool hadAK8JetID =false;
   int minDR4indx=-100,minDR4indxl1=-100,minDR4indxl2=-100,minDR5indx , Ak8ID=-100;//photonMatchingJetIndx=-100,nHadJets=0;                                                                     
   double minDR4=99999,minDR4l1=99999,minDR4l2=99999,minDR5;
   double minDPhi4=99999,minDPhi4l1=99999,minDPhi4l2=99999;
   vector<TLorentzVector> hadAK8Jets;
   vector<TLorentzVector> hadAK8Jets_matchedW;
   vector<double> hadAK8Mass, hadAK8Mass_matchedW;
   double Ak8Mass=-100,max=0.0,Ak8Mass1;
   for(int i=0;i<JetsAK8->size();i++)
     {
       if( ((*JetsAK8)[i].Pt() > 200.0) && (abs((*JetsAK8)[i].Eta()) <= 2.4) ){
	 double dR4=bestPhoton.DeltaR((*JetsAK8)[i]);
	 if(dR4<minDR4){minDR4=dR4;minDR4indx=i; minDPhi4=abs(DeltaPhi(bestPhoton.Phi(),(*JetsAK8)[i].Phi()));}
	 if((*JetsAK8_softDropMass)[i]< 105 && (*JetsAK8_softDropMass)[i]>=65 )
	   cout<<jentry<<" : "<<i<<" , Ak8Mass = "<<(*JetsAK8_softDropMass)[i]<<" , njets = "<<hadJets.size()<<" , dr(Ak8,photon) = "<<bestPhoton.DeltaR((*JetsAK8)[i])<<endl;

       }

     }
       
   if(hadj)
    {
      if(minDR4 > 0.8) minDR4indx=-100;
      if(minDR4l1 > 0.8) minDR4indxl1=-100;
      if(minDR4l2 > 0.8) minDR4indxl2=-100;
    }
  else
    {
      if(minDR4 > 0.5) minDR4indx=-100;
      if(minDR4l1 > 0.8) minDR4indxl1=-100;
      if(minDR4l2 > 0.8) minDR4indxl2=-100;
    }


   for(int i=0;i<JetsAK8->size();i++)
     if( ((*JetsAK8)[i].Pt() > 200.0) && (abs((*JetsAK8)[i].Eta()) <= 2.4) ){

       if( i!=minDR4indx ){
     
	 hadAK8JetID=(*JetsAK8_ID)[i];

	 if(hadAK8JetID)
	   {
	     hadAK8Jets.push_back((*JetsAK8)[i]);
	     hadAK8Mass.push_back((*JetsAK8_softDropMass)[i]);
	     Ak8ID=i;

	   }
       }
     }


   if(hadAK8Jets.size() == 0)
     {

       Ak8Mass=0;
     }
   else if (hadAK8Jets.size() != 0)
     {
       Ak8Mass=hadAK8Mass[0];

     }

   if(EWselection)
     {
       //for(int i=0;i<hadAK8Jets.size();i++)                                                                                                               
       EWselec=false;
       EWselec_Htag=false;
       EWselec_Wtag=false;
       EWselec_SB1=false;
       EWselec_SB2=false;


       if(hadAK8Jets.size() != 0)
	 {
	   if ((hadAK8Mass[0] < 105 && hadAK8Mass[0] >= 65))// || (hadAK8Mass[0] < 110 && hadAK8Mass[0] > 140))                                             
	     {
	       EWselec=true;
	       EWselec_Wtag=true;
	       EWselec_Htag=false;
	       EWselec_SB1=false;
	       EWselec_SB2=false;
	     }
	   else if ((hadAK8Mass[0] < 140 && hadAK8Mass[0] >= 105))
	     {
	       EWselec=true;
	       EWselec_Htag=true;
	       EWselec_Wtag=false;
	       EWselec_SB1=false;
	       EWselec_SB2=false;

	     }


	   else
	     {
	       EWselec=false;
	       EWselec_Htag=false;
	       EWselec_Wtag=false;
	       EWselec_SB1=false;
	       EWselec_SB2=false;

	     } 
	 }


       if(hadJets.size()<=6)
	 EWselec1=true;
       else
	 EWselec1=false;
     }

   if(EWselec && EWselec1 && EWselec_Htag)
     h_hadAk8Mass_EW_htag->Fill(Ak8Mass,wt);
   if(EWselec && EWselec1 && EWselec_Wtag)
     h_hadAk8Mass_EW_wtag->Fill(Ak8Mass,wt);

   //   if(!(EWselec && EWselec1 && EWselec_Wtag)) continue;
 //     cout<<jentry<<" , Ak8Mass = "<<Ak8Mass<<" , njets = "<<hadJets.size()<<""<<endl;
   //   remain++;
   //   if(MET<450) continue;
   int btag_org=-1,btag_org2=-1;
   btag_org=nbjets;
   btag_org2=BTagsDeepCSV;


  {

     int sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
     //     h_SBins_v6_CD_EW_50bin_elec0->Fill(sBin6_50bin,wt);
     //     if(!(EWselec && EWselec1))
       {
	 int sBin7= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 //	 h_SBins_v7_CD->Fill(sBin7,wt);
       }

     int sBin6 = getBinNoV7_le(nHadJets,nbjets);
     h_SBins_v6_CD->Fill(sBin6,wt);

     int sBin_TF=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
     //   h_SBins_v7_CD_SP->Fill(sBin_TF,wt);

     h_BTags->Fill(BTagsDeepCSV,wt);
     h_deepcsv_v4->Fill(nbjets,wt);
     h2_btag_probwt->Fill(nbjets,leadbjet_tag2,wt);

   

   }
   if(s_data.Contains("data")) wt=1;
   double wt2=wt , wt1=wt; 

   if(do_prediction && !old && applyKxR)
     {
       if(!(EWselec && EWselec1)){
	 if(nbjets==0){
	   if(nHadJets>=2 && nHadJets<=4 && MET<=300)     { wt2=wt*tf->GetBinContent(2);}
	   else if(nHadJets>=2 && nHadJets<=4 && MET>300)     { wt2=wt*tf->GetBinContent(3);}
	   else if((nHadJets==5 || nHadJets==6) && MET<=300){ wt2=wt*tf->GetBinContent(9);}
	   else if((nHadJets==5 || nHadJets==6) && MET>300){ wt2=wt*tf->GetBinContent(10);}
	   else if(nHadJets>=7  && MET<=300)   { wt2=wt*tf->GetBinContent(15);}
	   else if(nHadJets>=7 && MET>300)   { wt2=wt*tf->GetBinContent(16);}
	 }
	 else{
	   if(nHadJets>=2 && nHadJets<=4 && MET<=300)      { wt2=wt*tf->GetBinContent(20);}
	   else if(nHadJets>=2 && nHadJets<=4 && MET>300)      { wt2=wt*tf->GetBinContent(21);}
	   else if((nHadJets==5 || nHadJets==6) && MET<=300){ wt2=wt*tf->GetBinContent(25);}
	   else if((nHadJets==5 || nHadJets==6) && MET>300){ wt2=wt*tf->GetBinContent(26);}
	   else if(nHadJets>=7 && MET<=300)   { wt2=wt*tf->GetBinContent(30);}
	   else if(nHadJets>=7 && MET>300)   { wt2=wt*tf->GetBinContent(31);}
	 }
       }
       else if((EWselec && EWselec1)){
	 if(EWselec_Wtag && !EWselec_Htag && MET<=300)     { wt2=wt*tf->GetBinContent(35);}
	 else if(EWselec_Wtag && !EWselec_Htag && MET>300)     { wt2=wt*tf->GetBinContent(36);}
	 else if(EWselec_Htag && !EWselec_Wtag  && MET<=300)      { wt2=wt*tf->GetBinContent(41);}
	 else if(EWselec_Htag && !EWselec_Wtag && MET>300)      { wt2=wt*tf->GetBinContent(42);}
       }
       wt1=wt2;
     }
     
   if(region_A)
     {
       int nbjets_org=nbjets;
       int sBin_RF_A=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
       int sBin6_50bin_A= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6_7bin_A= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6 = getBinNoV7_le(nHadJets,nbjets);

       if(applybTagSFs && s_data.Contains("v17")){
	
	 nbjets=0;
	 sBin_RF_A=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	 h_SBins_v7_CD_SP_A->Fill(sBin_RF_A,wt1*prob0);
	 sBin6_50bin_A= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_A,wt1*prob0);
	 h_SBins_v6_CD_EW_50bin_A->Fill(sBin6_50bin_A,wt1*prob0);
	 sBin6_7bin_A= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_A,wt1*prob0);
	 sBin6 = getBinNoV7_le(nHadJets,nbjets);
	 h_SBins_v6_CD_A->Fill(sBin6,wt*prob0);
	 if(!(EWselec && EWselec1)){
	   h2_nJetsMET_A->Fill(MET,nHadJets,wt*prob0); 
	   h2_nJetsMET_v2_A->Fill(MET,nHadJets,wt*prob0); 
	 }

	 nbjets=1;
	 sBin_RF_A=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	 h_SBins_v7_CD_SP_A->Fill(sBin_RF_A,wt1*prob1);
	 sBin6_50bin_A= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_A,wt1*prob1);
	 h_SBins_v6_CD_EW_50bin_A->Fill(sBin6_50bin_A,wt1*prob1);
	 sBin6_7bin_A= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_A,wt1*prob1);
	 sBin6 = getBinNoV7_le(nHadJets,nbjets);
	 h_SBins_v6_CD_A->Fill(sBin6,wt*prob1);
	 if(!(EWselec && EWselec1)){
           h2_nJetsMET_B->Fill(MET,nHadJets,wt*prob1);
           h2_nJetsMET_v2_B->Fill(MET,nHadJets,wt*prob1);
	 }

	 nbjets=nbjets_org;
	   
	   h_BTags_A->Fill(0.0,wt*prob0);
	   h_BTags_A->Fill(1.0,wt*prob[1]);
	   h_BTags_A->Fill(2.0,wt*prob[2]);
	   h_BTags_A->Fill(3.0,wt*prob[3]);
	   
       }
       else
	 {
	   sBin_RF_A=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	   h_SBins_v7_CD_SP_A->Fill(sBin_RF_A,wt1);
	   sBin6_50bin_A= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_A,wt1);
	   h_SBins_v6_CD_EW_50bin_A->Fill(sBin6_50bin_A,wt1);
	   sBin6_7bin_A= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_A,wt1);
	   sBin6 = getBinNoV7_le(nHadJets,nbjets);
	     h_SBins_v6_CD_A->Fill(sBin6,wt);
	     if(!(EWselec && EWselec1))
	       {
		 if(nbjets==0)   {nbjets=0; h2_nJetsMET_A->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_A->Fill(MET,nHadJets,wt*prob0);}
		 if(nbjets>0)  { nbjets=1; h2_nJetsMET_B->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_B->Fill(MET,nHadJets,wt*prob1);}
	       }
	     else if(EWselec && EWselec1)
	       {
		 if(EWselec_Wtag) {h_nJetsMET_P->Fill(MET,wt);}
		 if(EWselec_Htag) {h_nJetsMET_Q->Fill(MET,wt);}

	       }

       h_BTags_A->Fill(nbjets,wt);
	 }
       if(EWselec && EWselec1 && EWselec_Htag)
	 h_hadAk8Mass_EW_htag_A->Fill(Ak8Mass,wt1);
       if(EWselec && EWselec1 && EWselec_Wtag)
	 h_hadAk8Mass_EW_wtag_A->Fill(Ak8Mass,wt1);
       h_nJets_A->Fill(nHadJets,wt);
       h_ST_A->Fill(ST,wt);
       h_MET_A->Fill(MET,wt);
       h_BestPhotonPt_A->Fill(bestPhoton.Pt(),wt);
       h_BestPhotonPhi_A->Fill((bestPhoton.Phi()),wt);
       h_BestPhotonEta_A->Fill((bestPhoton.Eta()),wt);
       h_dPhi_METjet1_A->Fill(dPhi_METjet1,wt);
       h_dPhi_METjet2_A->Fill(dPhi_METjet2,wt);
       h_dPhi_METjet3_A->Fill(dPhi_METjet3,wt);
       h_dPhi_METjet4_A->Fill(dPhi_METjet4,wt);

       h2_MET_dPhiMETj_A->Fill(MET,mindphi,wt);
       h2_MET_dPhiMETj1_A->Fill(MET,dPhi_METjet1,wt);
       h2_MET_dPhiMETj2_A->Fill(MET,dPhi_METjet2,wt);
       h_JetPt_A->Fill(hadJets[0].Pt(),wt);
       h_JetEta_A->Fill(hadJets[0].Eta(),wt);
       h_JetPhi_A->Fill(hadJets[0].Phi(),wt);
       h_dPhi_phoMET_A->Fill(dphiPho_MET,wt);
       h_mindphi1dphi2_A->Fill(mindphi,wt);
       if(hadJets.size()>0){     
	 h_JetPt1_A->Fill(hadJets[0].Pt(),wt);
	 h_JetPhi1_A->Fill(hadJets[0].Phi(),wt);
	 h_JetEta1_A->Fill(hadJets[0].Eta(),wt);
       }
       if(hadJets.size()>1){
	 h_JetPt2_A->Fill(hadJets[1].Pt(),wt);
	 h_JetPhi2_A->Fill(hadJets[1].Phi(),wt);
	 h_JetEta2_A->Fill(hadJets[1].Eta(),wt);
       } 
       if(hadJets.size()>2){
	 h_JetPt3_A->Fill(hadJets[2].Pt(),wt);
	 h_JetPhi3_A->Fill(hadJets[2].Phi(),wt);
	 h_JetEta3_A->Fill(hadJets[2].Eta(),wt);
       } 
       if(hadJets.size()>3){
	 h_JetPt4_A->Fill(hadJets[3].Pt(),wt);
	 h_JetPhi4_A->Fill(hadJets[3].Phi(),wt);
	 h_JetEta4_A->Fill(hadJets[3].Eta(),wt);
       } 


       if(EWselec && EWselec1)
	 {
	   if(EWselec_Wtag) {h_nJetsMET_P->Fill(MET,wt);}
           if(EWselec_Htag) {h_nJetsMET_Q->Fill(MET,wt);}

	 }

     }
   tmpcheck=false;
   if(tmpcheck)
     {
       if(region_A || region_B)      
	 {
	   //       h2_nJetsMET_A->Fill(MET,nHadJets,wt);
	   int sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_50bin_elec1->Fill(sBin6_50bin,wt2);
	   int sBin6_7bin= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
           h_SBins_v6_CD_EW_7bin_elec1->Fill(sBin6_7bin,wt2);
	 }
       if(region_C || region_D)       
	 { 
	   //       h2_nJetsMET_C->Fill(MET,nHadJets,wt);
	   int sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_50bin_elec0->Fill(sBin6_50bin,wt);
	   int sBin6_7bin= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
           h_SBins_v6_CD_EW_7bin_elec0->Fill(sBin6_7bin,wt);

	 }
       if(region_B || region_D)
	 {
	   int sBin_KF_B=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	   h_SBins_v7_CD_SP_BD->Fill(sBin_KF_B,wt);
	 }
       if(region_C || region_A)
	 {
	   int sBin_KF_A=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	   h_SBins_v7_CD_SP_CA->Fill(sBin_KF_A,wt);
	 }
     }

   if(region_B)
     {
       //       if(applyKxR)       wt2=wt1;
       int sBin_RF_B=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
       int sBin6_50bin_B= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6_7bin_B= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6 = getBinNoV7_le(nHadJets,nbjets);
       double nbjets_org=nbjets;
       if(applybTagSFs && s_data.Contains("v17")){
	 nbjets=0;
	 sBin_RF_B=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	 h_SBins_v7_CD_SP_B->Fill(sBin_RF_B,wt2*prob0);
	 sBin6_50bin_B= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_50bin_B->Fill(sBin6_50bin_B,wt1*prob0);
	 h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_B,wt1*prob0);
	 sBin6_7bin_B= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_B,wt2*prob0);
	 sBin6 = getBinNoV7_le(nHadJets,nbjets);
	 h_SBins_v6_CD_B->Fill(sBin6,wt2*prob0);
	 if(!(EWselec && EWselec1))
	   { h2_nJetsMET_A->Fill(MET,nHadJets,wt2*prob0); h2_nJetsMET_v2_A->Fill(MET,nHadJets,wt2*prob0);}

	 nbjets=1;
         sBin_RF_B=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
         h_SBins_v7_CD_SP_B->Fill(sBin_RF_B,wt2*prob1);
         sBin6_50bin_B= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_50bin_B->Fill(sBin6_50bin_B,wt1*prob1);
         h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_B,wt1*prob1);
         sBin6_7bin_B= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_B,wt2*prob1);
         sBin6 = getBinNoV7_le(nHadJets,nbjets);
         h_SBins_v6_CD_B->Fill(sBin6,wt2*prob1);
         if(!(EWselec && EWselec1))
           { h2_nJetsMET_B->Fill(MET,nHadJets,wt2*prob1); h2_nJetsMET_v2_B->Fill(MET,nHadJets,wt2*prob1);}

	 nbjets=nbjets_org;
	 h_BTags_B->Fill(0.0,wt2*prob0);
	 h_BTags_B->Fill(1.,wt2*prob[1]);
	 h_BTags_B->Fill(2.,wt2*prob[2]);
	 h_BTags_B->Fill(3.,wt2*prob[3]);       
       }
       else
	 {
	   sBin_RF_B=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	   h_SBins_v7_CD_SP_B->Fill(sBin_RF_B,wt2);
	   sBin6_50bin_B= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_50bin_B->Fill(sBin6_50bin_B,wt1);
	   h_SBins_v6_CD_EW_50bin_AB->Fill(sBin6_50bin_B,wt1);
	   sBin6_7bin_B= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	   h_SBins_v6_CD_EW_7bin_B->Fill(sBin6_7bin_B,wt2);
	   sBin6 = getBinNoV7_le(nHadJets,nbjets);
	   h_SBins_v6_CD_B->Fill(sBin6,wt2);
	   if(!(EWselec && EWselec1))
	     {
	       if(nbjets==0)  { nbjets=0; h2_nJetsMET_A->Fill(MET,nHadJets,wt2); h2_nJetsMET_v2_A->Fill(MET,nHadJets,wt2*prob0);}
	       if(nbjets>0)  { nbjets=1; h2_nJetsMET_B->Fill(MET,nHadJets,wt2); h2_nJetsMET_v2_B->Fill(MET,nHadJets,wt2*prob1);}
	     }
	   else if(EWselec && EWselec1)
	     {
	       if(EWselec_Wtag) {h_nJetsMET_P->Fill(MET,wt2);}
	       if(EWselec_Htag) {h_nJetsMET_Q->Fill(MET,wt2);}
	     }
	   h_BTags_B->Fill(nbjets,wt2);
	 }
       if(EWselec && EWselec1 && EWselec_Htag)
	 h_hadAk8Mass_EW_htag_B->Fill(Ak8Mass,wt2);
       if(EWselec && EWselec1 && EWselec_Wtag)
	 h_hadAk8Mass_EW_wtag_B->Fill(Ak8Mass,wt2);
       h_nJets_B->Fill(nHadJets,wt2);
       h_ST_B->Fill(ST,wt2);
       h_MET_B->Fill(MET,wt2);
       h_BestPhotonPt_B->Fill(bestPhoton.Pt(),wt2);
       h_BestPhotonPhi_B->Fill((bestPhoton.Phi()),wt2);
       h_BestPhotonEta_B->Fill((bestPhoton.Eta()),wt2);
       h_dPhi_METjet1_B->Fill(dPhi_METjet1,wt2);
       h_dPhi_METjet2_B->Fill(dPhi_METjet2,wt2);
       h_dPhi_METjet3_B->Fill(dPhi_METjet3,wt2);
       h_dPhi_METjet4_B->Fill(dPhi_METjet4,wt2);
       h2_MET_dPhiMETj_B->Fill(MET,mindphi,wt2);
       h2_MET_dPhiMETj1_B->Fill(MET,dPhi_METjet1,wt2);
       h2_MET_dPhiMETj2_B->Fill(MET,dPhi_METjet2,wt2);
       h_JetPt_B->Fill(hadJets[0].Pt(),wt2);
       h_JetEta_B->Fill(hadJets[0].Eta(),wt2);
       h_JetPhi_B->Fill(hadJets[0].Phi(),wt2);
       //       h2_nJetsMET_B->Fill(MET,nHadJets,wt22);
       h_dPhi_phoMET_B->Fill(dphiPho_MET,wt);
       h_mindphi1dphi2_B->Fill(mindphi,wt);
       if(hadJets.size()>0){
         h_JetPt1_B->Fill(hadJets[0].Pt(),wt);
         h_JetPhi1_B->Fill(hadJets[0].Phi(),wt);
         h_JetEta1_B->Fill(hadJets[0].Eta(),wt);
       }
       if(hadJets.size()>1){
         h_JetPt2_B->Fill(hadJets[1].Pt(),wt);
         h_JetPhi2_B->Fill(hadJets[1].Phi(),wt);
         h_JetEta2_B->Fill(hadJets[1].Eta(),wt);
       }
       if(hadJets.size()>2){
         h_JetPt3_B->Fill(hadJets[2].Pt(),wt);
         h_JetPhi3_B->Fill(hadJets[2].Phi(),wt);
         h_JetEta3_B->Fill(hadJets[2].Eta(),wt);
       }
       if(hadJets.size()>3){
         h_JetPt4_B->Fill(hadJets[3].Pt(),wt);
         h_JetPhi4_B->Fill(hadJets[3].Phi(),wt);
         h_JetEta4_B->Fill(hadJets[3].Eta(),wt);
       }


       if(EWselec && EWselec1)
	 {
	   if(EWselec_Wtag) {h_nJetsMET_P->Fill(MET,wt2);}
	   if(EWselec_Htag) {h_nJetsMET_Q->Fill(MET,wt2);}
	 }
	 
     }
   if(region_C)
     {
       int sBin_RF_C=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
       int sBin6_50bin_C= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6_7bin_C= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6 = getBinNoV7_le(nHadJets,nbjets);

       double nbjets_org=nbjets;
       if(applybTagSFs && s_data.Contains("v17")){
         nbjets=0;
	 sBin_RF_C=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	 h_SBins_v7_CD_SP_C->Fill(sBin_RF_C,wt*prob0);
	 sBin6_50bin_C= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_50bin_C->Fill(sBin6_50bin_C,wt*prob0);
	 h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_C,wt*prob0); 
	 sBin6_7bin_C= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_C,wt*prob0);
	 sBin6 = getBinNoV7_le(nHadJets,nbjets);
	 h_SBins_v6_CD_C->Fill(sBin6,wt*prob0);
         if(!(EWselec && EWselec1))
           {
             h2_nJetsMET_C->Fill(MET,nHadJets,wt*prob0); h2_nJetsMET_v2_C->Fill(MET,nHadJets,wt*prob0);
	   }

         nbjets=1;
         sBin_RF_C=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
         h_SBins_v7_CD_SP_C->Fill(sBin_RF_C,wt*prob1);
         sBin6_50bin_C= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_50bin_C->Fill(sBin6_50bin_C,wt*prob1);
         h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_C,wt*prob1);
         sBin6_7bin_C= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_C,wt*prob1);
         sBin6 = getBinNoV7_le(nHadJets,nbjets);
         h_SBins_v6_CD_C->Fill(sBin6,wt*prob1);
         if(!(EWselec && EWselec1))
           {
             h2_nJetsMET_D->Fill(MET,nHadJets,wt*prob1); h2_nJetsMET_v2_D->Fill(MET,nHadJets,wt*prob1);
           }
	 nbjets=nbjets_org;
	 h_BTags_C->Fill(0.,wt*prob0);
	 h_BTags_C->Fill(1.,wt*prob[1]);
	 h_BTags_C->Fill(2.,wt*prob[2]);
	 h_BTags_C->Fill(3.,wt*prob[3]);      
       }
       else{
	 h_BTags_C->Fill(nbjets,wt);
	 h_SBins_v7_CD_SP_C->Fill(sBin_RF_C,wt);
	 h_SBins_v6_CD_EW_50bin_C->Fill(sBin6_50bin_C,wt);
	 h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_C,wt);
	 h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_C,wt);
	 h_SBins_v6_CD_C->Fill(sBin6,wt);
	 if(!(EWselec && EWselec1))
	   {
	     if(nbjets==0)   {nbjets=0; h2_nJetsMET_C->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_C->Fill(MET,nHadJets,wt*prob0);}
	     if(nbjets>0)   { nbjets=1; h2_nJetsMET_D->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_D->Fill(MET,nHadJets,wt*prob1);}
	   }
	 else if(EWselec && EWselec1)
	   {
	     if(EWselec_Wtag) {h_nJetsMET_R->Fill(MET,wt);}
	     if(EWselec_Htag) {h_nJetsMET_S->Fill(MET,wt);}
	   }
       }
       if(EWselec && EWselec1 && EWselec_Htag)
	 h_hadAk8Mass_EW_htag_C->Fill(Ak8Mass,wt);
       if(EWselec && EWselec1 && EWselec_Wtag)
	 h_hadAk8Mass_EW_wtag_C->Fill(Ak8Mass,wt);
       h_nJets_C->Fill(nHadJets,wt);
       h_ST_C->Fill(ST,wt);
       h_MET_C->Fill(MET,wt);
       h_BestPhotonPt_C->Fill(bestPhoton.Pt(),wt);
       h_BestPhotonPhi_C->Fill((bestPhoton.Phi()),wt);
       h_BestPhotonEta_C->Fill((bestPhoton.Eta()),wt);
       h_dPhi_METjet1_C->Fill(dPhi_METjet1,wt);
       h_dPhi_METjet2_C->Fill(dPhi_METjet2,wt);
       h_dPhi_METjet3_C->Fill(dPhi_METjet3,wt);
       h_dPhi_METjet4_C->Fill(dPhi_METjet4,wt);
       h2_MET_dPhiMETj_C->Fill(MET,mindphi,wt);
       h2_MET_dPhiMETj1_C->Fill(MET,dPhi_METjet1,wt);
       h2_MET_dPhiMETj2_C->Fill(MET,dPhi_METjet2,wt);
       h_JetPt_C->Fill(hadJets[0].Pt(),wt);
       h_JetEta_C->Fill(hadJets[0].Eta(),wt);
       h_JetPhi_C->Fill(hadJets[0].Phi(),wt);
       h_dPhi_phoMET_C->Fill(dphiPho_MET,wt);
       h_mindphi1dphi2_C->Fill(mindphi,wt);
       if(hadJets.size()>0){
         h_JetPt1_C->Fill(hadJets[0].Pt(),wt);
         h_JetPhi1_C->Fill(hadJets[0].Phi(),wt);
         h_JetEta1_C->Fill(hadJets[0].Eta(),wt);
       }
       if(hadJets.size()>1){
         h_JetPt2_C->Fill(hadJets[1].Pt(),wt);
         h_JetPhi2_C->Fill(hadJets[1].Phi(),wt);
         h_JetEta2_C->Fill(hadJets[1].Eta(),wt);
       }
       if(hadJets.size()>2){
         h_JetPt3_C->Fill(hadJets[2].Pt(),wt);
         h_JetPhi3_C->Fill(hadJets[2].Phi(),wt);
         h_JetEta3_C->Fill(hadJets[2].Eta(),wt);
       }
       if(hadJets.size()>3){
         h_JetPt4_C->Fill(hadJets[3].Pt(),wt);
         h_JetPhi4_C->Fill(hadJets[3].Phi(),wt);
         h_JetEta4_C->Fill(hadJets[3].Eta(),wt);
       }

       if(EWselec && EWselec1)
         {
           if(EWselec_Wtag) {h_nJetsMET_R->Fill(MET,wt);}
           if(EWselec_Htag) {h_nJetsMET_S->Fill(MET,wt);}
         }

     }
   if(region_D)
     {
       double nbjets_org=nbjets;
       int sBin_RF_D=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
       int sBin6_50bin_D= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6_7bin_D= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
       int sBin6 = getBinNoV7_le(nHadJets,nbjets);
       if(applybTagSFs && s_data.Contains("v17")){
         nbjets=0;
	 sBin_RF_D=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
	 h_SBins_v7_CD_SP_D->Fill(sBin_RF_D,wt*prob0);
	 sBin6_50bin_D= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_50bin_D->Fill(sBin6_50bin_D,wt*prob0);
	 h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_D,wt*prob0);
	 sBin6_7bin_D= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
	 h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_D,wt*prob0);
	 sBin6 = getBinNoV7_le(nHadJets,nbjets);
	 h_SBins_v6_CD_D->Fill(sBin6,wt*prob0);
	 if(!(EWselec && EWselec1))
	   {
	     h2_nJetsMET_C->Fill(MET,nHadJets,wt*prob0); h2_nJetsMET_v2_C->Fill(MET,nHadJets,wt*prob0);
	   }


         nbjets=1;
         sBin_RF_D=getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets);
         h_SBins_v7_CD_SP_D->Fill(sBin_RF_D,wt*prob1);
         sBin6_50bin_D= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_50bin_D->Fill(sBin6_50bin_D,wt*prob1);
         h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_D,wt*prob1);
         sBin6_7bin_D= getBinNoV6_EWplusSP_SR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nHadJets,nbjets,MET);
         h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_D,wt*prob1);
         sBin6 = getBinNoV7_le(nHadJets,nbjets);
         h_SBins_v6_CD_D->Fill(sBin6,wt*prob1);
         if(!(EWselec && EWselec1))
           {
             h2_nJetsMET_D->Fill(MET,nHadJets,wt*prob1); h2_nJetsMET_v2_D->Fill(MET,nHadJets,wt*prob1);
           }
         nbjets=nbjets_org;
         h_BTags_D->Fill(0.,wt*prob0);
         h_BTags_D->Fill(1.,wt*prob[1]);
         h_BTags_D->Fill(2.,wt*prob[2]);
         h_BTags_D->Fill(3.,wt*prob[3]);
       }
       else{
	   h_BTags_D->Fill(nbjets,wt);
	   h_SBins_v7_CD_SP_D->Fill(sBin_RF_D,wt);
	   h_SBins_v6_CD_EW_50bin_D->Fill(sBin6_50bin_D,wt);
	   h_SBins_v6_CD_EW_50bin_CD->Fill(sBin6_50bin_D,wt);
	   h_SBins_v6_CD_EW_7bin_D->Fill(sBin6_7bin_D,wt);
	   h_SBins_v6_CD_D->Fill(sBin6,wt);
	   if(!(EWselec && EWselec1))
	     {
	       if(nbjets==0) { nbjets=0; h2_nJetsMET_C->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_C->Fill(MET,nHadJets,wt*prob0);}
	       if(nbjets>0)  { nbjets=1; h2_nJetsMET_D->Fill(MET,nHadJets,wt); h2_nJetsMET_v2_D->Fill(MET,nHadJets,wt*prob1);}
	     }
	   else if(EWselec && EWselec1)
	     {
	       if(EWselec_Wtag) {h_nJetsMET_R->Fill(MET,wt); }
	       if(EWselec_Htag) {h_nJetsMET_S->Fill(MET,wt); }
	     }
       }
       if(EWselec && EWselec1 && EWselec_Htag)
	 h_hadAk8Mass_EW_htag_D->Fill(Ak8Mass,wt);
       if(EWselec && EWselec1 && EWselec_Wtag)
	 h_hadAk8Mass_EW_wtag_D->Fill(Ak8Mass,wt);
       h_nJets_D->Fill(nHadJets,wt);
       h_ST_D->Fill(ST,wt);
       h_MET_D->Fill(MET,wt);
       h_BestPhotonPt_D->Fill(bestPhoton.Pt(),wt);
       h_BestPhotonPhi_D->Fill((bestPhoton.Phi()),wt);
       h_BestPhotonEta_D->Fill((bestPhoton.Eta()),wt);
       h_dPhi_METjet1_D->Fill(dPhi_METjet1,wt);
       h_dPhi_METjet2_D->Fill(dPhi_METjet2,wt);
       h_dPhi_METjet3_D->Fill(dPhi_METjet3,wt);
       h_dPhi_METjet4_D->Fill(dPhi_METjet4,wt);
       h2_MET_dPhiMETj_D->Fill(MET,mindphi,wt);
       h2_MET_dPhiMETj1_D->Fill(MET,dPhi_METjet1,wt);
       h2_MET_dPhiMETj2_D->Fill(MET,dPhi_METjet2,wt);
       h_JetPt_D->Fill(hadJets[0].Pt(),wt);
       h_JetEta_D->Fill(hadJets[0].Eta(),wt);
       h_JetPhi_D->Fill(hadJets[0].Phi(),wt);
       //       h2_nJetsMET_D->Fill(MET,nHadJets,wt);
       h_dPhi_phoMET_D->Fill(dphiPho_MET,wt);
       h_mindphi1dphi2_D->Fill(mindphi,wt);
       if(hadJets.size()>0){
         h_JetPt1_D->Fill(hadJets[0].Pt(),wt);
         h_JetPhi1_D->Fill(hadJets[0].Phi(),wt);
         h_JetEta1_D->Fill(hadJets[0].Eta(),wt);
       }
       if(hadJets.size()>1){
         h_JetPt2_D->Fill(hadJets[1].Pt(),wt);
         h_JetPhi2_D->Fill(hadJets[1].Phi(),wt);
         h_JetEta2_D->Fill(hadJets[1].Eta(),wt);
       }
       if(hadJets.size()>2){
         h_JetPt3_D->Fill(hadJets[2].Pt(),wt);
         h_JetPhi3_D->Fill(hadJets[2].Phi(),wt);
         h_JetEta3_D->Fill(hadJets[2].Eta(),wt);
       }
       if(hadJets.size()>3){
         h_JetPt4_D->Fill(hadJets[3].Pt(),wt);
         h_JetPhi4_D->Fill(hadJets[3].Phi(),wt);
         h_JetEta4_D->Fill(hadJets[3].Eta(),wt);
       }

       if(EWselec && EWselec1)
         {
           if(EWselec_Wtag) {h_nJetsMET_R->Fill(MET,wt); }
           if(EWselec_Htag) {h_nJetsMET_S->Fill(MET,wt); }
         }

     }

   h_nJets->Fill(nHadJets,wt);
   h_ST->Fill(ST,wt);
   h_MET->Fill(MET,wt);
   h_BestPhotonPt->Fill(bestPhoton.Pt(),wt);
   h_BestPhotonPhi->Fill((bestPhoton.Phi()),wt);
   h_BestPhotonEta->Fill((bestPhoton.Eta()),wt);
   h_dPhi_METjet1->Fill(dPhi_METjet1,wt);
   h_dPhi_METjet2->Fill(dPhi_METjet2,wt);
   h_dPhi_METjet3->Fill(dPhi_METjet3,wt);
   h_dPhi_METjet4->Fill(dPhi_METjet4,wt);


   h2_nJetsMET->Fill(MET,nHadJets,wt);
   h_mindphi1dphi2->Fill(mindphi,wt);   
   h2_MET_dPhiMETj->Fill(MET,mindphi,wt);
   h2_MET_dPhiMETj1-> Fill(MET,dPhi_METjet1,wt);
   h2_MET_dPhiMETj2->Fill(MET,dPhi_METjet2,wt);
  }

    //=========================================================================//

  cout<<"Cross-section : "<<CrossSection<<endl;
  cout<<"Weight ib pb-1 : "<<Weight<<endl;

  cout<<"globalSuperTightHalo2016Filter : "<<a<<endl;
  cout<<"HBHENoiseFilter : "<<b<<endl;
  cout<<"HBHEIsoNoiseFilter : "<<c<<endl;
  cout<<"EcalDeadCellTriggerPrimitiveFilter : "<<d<<endl;
  cout<<"ecalBadCalibReducedFilter : "<<e<<endl;
  cout<<"BadPFMuonFilter : "<<f<<endl;
  cout<<"PrimaryVertexFilter : "<<g<<endl;
  cout<<"NVtx>0 : "<<h<<endl;

  cout<<"Events having 0 good photon : "<<phopt_0<<endl;
  cout<<"Events having >0 good photon : "<<phopt_not0<<endl;
  cout<<"Events survived after MET<200 cut : "<<met<<endl;
  cout<<"remaining  A region : "<<reg_A<<endl;
  cout<<"remaining  B region : "<<reg_B<<endl;
  cout<<"remaining  C region : "<<reg_C<<endl;
  cout<<"remaining  D region : "<<reg_D<<endl;
  cout<<"Total  : "<<reg_A+reg_B+reg_C+reg_D<<endl;
  cout<<"remaining : "<<remain<<endl;

  cout<<"Total events : "<<st<<endl;
  // cout<<"Events after bjet discriminator : "<<after_bjetdisc<<endl;  
  cout<<"================="<<endl;

  // cout<<"no. of events with bjet=0 : "<<nbj0<<" with wt : "<<wt_nbj0<<" , total prob = "<<total_prob0<<endl;
  // cout<<"no. of events with bjet=1 : "<<nbj1<<" with wt : "<<wt_nbj1<<" , total prob = "<<total_prob1<<endl;
  // cout<<"no. of events with bjet=2 : "<<nbj2<<" with wt : "<<wt_nbj2<<" , total prob = "<<total_prob2<<endl;
  // cout<<"no. of events with bjet>=3 : "<<nbj3<<" with wt : "<<wt_nbj3<<" , total prob = "<<total_prob3<<endl;
  // cout<<"total weighted events = "<<total_prob0+total_prob1+total_prob2+total_prob3<<endl;
}
TLorentzVector Mulijet::getBestPhoton(){
  vector<TLorentzVector> goodPho;
  vector<int> goodPhoIndx;
  //  allBestPhotons.resize(0);
  for(int iPho=0;iPho<Photons->size();iPho++){
    if( (*Photons_fullID)[iPho] && ((*Photons_hasPixelSeed)[iPho]<0.001) ) {
      goodPho.push_back( (*Photons)[iPho] );
      goodPhoIndx.push_back(iPho);
      allBestPhotons.push_back((*Photons)[iPho]);
    }
  }
  
  int highPtIndx=-100;
  for(int i=0;i<goodPho.size();i++){
    if(i==0) highPtIndx=0;
    else if( (goodPho[highPtIndx].Pt()) < (goodPho[i].Pt()) ){highPtIndx=i;}
  }

  if(highPtIndx>=0){
    bestPhotonIndxAmongPhotons = goodPhoIndx[highPtIndx];
  }
  else bestPhotonIndxAmongPhotons = -100;
  if(highPtIndx==-100){TLorentzVector v0;return v0;}
  else return goodPho[highPtIndx];  
}

TLorentzVector Mulijet::getBestPhoton_0(){
  int bestPhoIndx=-100;
  TLorentzVector v1;
  vector<TLorentzVector> goodPho;
  for(int iPhoton=0;iPhoton<Photons->size();iPhoton++){
    if( ((*Photons_fullID)[iPhoton]) && ((*Photons_hasPixelSeed)[iPhoton]<0.001) ) goodPho.push_back( (*Photons)[iPhoton] );
  }

  if(goodPho.size()==0) return v1;
  else if(goodPho.size()==1) return goodPho[0];
  else{
    for(int i=0;i<goodPho.size();i++){
      if(i==0) bestPhoIndx=0;
      else if(goodPho[bestPhoIndx].Pt() < goodPho[i].Pt()) bestPhoIndx=i;
    }
    return goodPho[bestPhoIndx];
  }
}

TLorentzVector Mulijet::getPhoton_withoutfullID(){
  vector<TLorentzVector> nogoodPho;
  vector<int> nogoodPhoIndx;
  for(int iPho=0;iPho<Photons->size();iPho++){
    if( !(*Photons_fullID)[iPho] ) 
      {
      nogoodPho.push_back( (*Photons)[iPho] );
      nogoodPhoIndx.push_back(iPho);
    }
  }

  int highPtIndx=-100;
  for(int i=0;i<nogoodPho.size();i++){
    if(i==0) highPtIndx=0;
    else if( (nogoodPho[highPtIndx].Pt()) < (nogoodPho[i].Pt()) ){highPtIndx=i;}
  }

  if(highPtIndx>=0){
    eIndxAmongPhotons = nogoodPhoIndx[highPtIndx];
  }
  else eIndxAmongPhotons = -100;

  if(highPtIndx==-100){TLorentzVector v0;return v0;}
  else return nogoodPho[highPtIndx];
}

int Mulijet::getBinNoV7(TLorentzVector bestPhoton,double qmulti, double minDRindx){
  int sBin=0,m_i=-1,sBin1=0,n_i=-1;; 
  for(int i=0;i<BestPhotonPtBinLowEdge.size()-1;i++){
    if(BestPhotonPtBinLowEdge[i]<99.99) continue; 
    //if(qmulti>=10) continue;
    m_i++;  
    if(bestPhoton.Pt() >= BestPhotonPtBinLowEdge[i] && bestPhoton.Pt() < BestPhotonPtBinLowEdge[i+1])
      {
	sBin = sBin+(m_i*4);

	break;

     }
    else if(bestPhoton.Pt() >= BestPhotonPtBinLowEdge[BestPhotonPtBinLowEdge.size()-1])
      {
	sBin = 40;
	break;
      }
  }

  if(sBin%4==0)// || sBin==4 || sBin==8 || sBin==12 || sBin==16 || sBin==20 )
    {
      //	cout<<"bestPhoton : "<<bestPhoton.Pt()<<" , Qmult : "<<qmulti<<" , sBin = "<<sBin1<<endl;

      for(int i=0;i<QMultLowedge.size()-1;i++){
	n_i++;
	if(qmulti>=QMultLowedge[i] && qmulti<QMultLowedge[i+1]) {sBin1=sBin+n_i; break;}
	else if(qmulti>=QMultLowedge[QMultLowedge.size()-1]){sBin1=sBin1+(QMultLowedge.size()-1); break;}
	//	else sBin1=-999;
      }
    }
  
  //   if((qmulti>=7 && qmulti<10) && bestPhoton.Pt()>=100 && bestPhoton.Pt() <120)
  // if(bestPhoton.Pt()>=200 && bestPhoton.Pt() <230)
  //   cout<<"bestPhoton : "<<bestPhoton.Pt()<<" , Qmult : "<<qmulti<<" , sBin = "<<sBin1<<endl;
  return sBin1;  
}


int Mulijet::getBinNoV6(TLorentzVector bestPhoton, int nHadJets){
  int sBin=0,m_i=-1,sBin1=0,n_i=-1;; 
  for(int i=0;i<BestPhotonPtBinLowEdge.size()-1;i++){
    if(BestPhotonPtBinLowEdge[i]<99.99) continue; 
    m_i++;  
    if(bestPhoton.Pt() >= BestPhotonPtBinLowEdge[i] && bestPhoton.Pt() < BestPhotonPtBinLowEdge[i+1])
      {
	sBin = sBin+(m_i*4);

	break;

     }
    else if(bestPhoton.Pt() >= BestPhotonPtBinLowEdge[BestPhotonPtBinLowEdge.size()-1])
      {
	sBin = 40;
	break;
      }
  }

  if(sBin%4==0)// || sBin==4 || sBin==8 || sBin==12 || sBin==16 || sBin==20 )
    {
      for(int i=0;i<nJetsLowedge.size()-1;i++){
	n_i++;
	if(nHadJets>=nJetsLowedge[i] && nHadJets<nJetsLowedge[i+1]) {sBin1=sBin+n_i; break;}
	else if(nHadJets>=nJetsLowedge[nJetsLowedge.size()-1]){sBin1=sBin1+(nJetsLowedge.size()-1); break;}
	//	else sBin1=-999;
      }
    }
  
  //   if((nHadJets>=7 && nHadJets<10) && bestPhoton.Pt()>=100 && bestPhoton.Pt() <120)
  // if(bestPhoton.Pt()>=200 && bestPhoton.Pt() <230)
  //   cout<<"bestPhoton : "<<bestPhoton.Pt()<<" , Qmult : "<<nHadJets<<" , sBin = "<<sBin1<<endl;
  return sBin1;  
}

int Mulijet::getBinNoV7_le(int nHadJets, int nbjets){
  int sBin=-100,m_i=0;
  //  if(nbjets==0){
  //  if(BTagsclean==0){
  if(nbjets==0){
    if(nHadJets==2)     { sBin=1;}
    else if(nHadJets==3)     { sBin=2;}
    else if(nHadJets==4)     { sBin=3;}
    else if((nHadJets==5 || nHadJets==6)){ sBin=4;}
    else if(nHadJets>=7)   { sBin=5;}
  }
  else{
    if(nHadJets>=2 && nHadJets<=4)      { sBin=6;}
    else if((nHadJets==5 || nHadJets==6)){ sBin=7;}
    else if(nHadJets>=7)   { sBin=8;}
  }
  return sBin;
}

int Mulijet::getBinNoV7_le2(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nHadJets, int nbjets){
  int sBin=-100,m_i=0;
  if(!(EWselec && EWselec1))
    {
      if(nbjets==0){
        if(nHadJets==2)     { sBin=1;}
        else if(nHadJets==3)     { sBin=1;}
        else if(nHadJets==4)     { sBin=1;}
        else if((nHadJets==5 || nHadJets==6)){ sBin=2;}
        else if(nHadJets>=7)   { sBin=3;}
      }
      else{
        if(nHadJets>=2 && nHadJets<=4)      { sBin=4;}
        else if((nHadJets==5 || nHadJets==6)){ sBin=5;}
        else if(nHadJets>=7)   { sBin=6;}
      }
    }
  else if ((EWselec && EWselec1))
    {
      if(EWselec_Wtag)
	sBin=7;
      if(EWselec_Htag)
	sBin=8;
    }
  
  return sBin;
}




int Mulijet::getBinNoV6_EWplusSP_CR(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nHadJets, int nbjets, double MET_){

  int sBin=-100,m_i=0;

  //  if(!((EWselec_Wtag || EWselec_Htag) && EWselec1))
   if(!(EWselec && EWselec1))
    { 
      if(nbjets==0 ){
	if(nHadJets>=2 && nHadJets<=4)     { sBin=0;}
	else if(nHadJets==5 || nHadJets==6){ sBin=7;}
	else if(nHadJets>=7)               { sBin=13;}
      }
      else{
	if(nHadJets>=2 && nHadJets<=4)     { sBin=18;}//19;}
	else if(nHadJets==5 || nHadJets==6){ sBin=23;}//25;}
	else if(nHadJets>=7)               { sBin=28;}//31;}
      }
    }
   if((EWselec_Wtag && !EWselec_Htag) && EWselec1){
     sBin=33;//37;
   }
   else if((!EWselec_Wtag && EWselec_Htag) && EWselec1){
     sBin=39;//44;
   }
  if(sBin==0){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<199.99) continue;
      int sBin1=sBin;
      m_i++;
      if(MET_ >= METLowEdge_v3[i] && MET_ < METLowEdge_v3[i+1]){ sBin = sBin+m_i;
break; }
      else if(MET_ >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = 7         ;
	break; }
    }
  }


  //  else if(sBin==7 || sBin==13 || sBin==19 || sBin==25 || sBin==31){
  else if(sBin==7 || sBin==33 || sBin==39){ 
   int sBin1=sBin;
    for(int i=0;i<METLowEdge_v3_1.size()-1;i++){
      if(METLowEdge_v3_1[i]<199.99) continue;
      m_i++;
      if(MET_ >= METLowEdge_v3_1[i] && MET_ < METLowEdge_v3_1[i+1]){ sBin = sBin+m_i;
	break;}
      else if(MET_ >= METLowEdge_v3_1[METLowEdge_v3_1.size()-1])  { sBin = sBin+6;
	break; }
    }
  }

  //  else if(sBin==37 || sBin==44){
  else{  
    for(int i=0;i<METLowEdge_v3_2.size()-1;i++){
      if(METLowEdge_v3_2[i]<199.99) continue;
      m_i++;
      if(MET_ >= METLowEdge_v3_2[i] && MET_ < METLowEdge_v3_2[i+1]){ sBin = sBin+m_i;break; }
      else if(MET_ >= METLowEdge_v3_2[METLowEdge_v3_2.size()-1])  { sBin = sBin+5   ;break; }

   }
  }
  return sBin;

}

int Mulijet::getBinNoV6_EWplusSP_SR(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nHadJets, int nbjets, double MET_){

  int sBin=-100,m_i=0;

  if(nbjets==0 ){
    if(nHadJets>=2 && nHadJets<=4)     { sBin=0;}
    else if(nHadJets==5 || nHadJets==6){ sBin=6;}
    else if(nHadJets>=7)               { sBin=11;}
  }
  else{
    if(nHadJets>=2 && nHadJets<=4)     { sBin=16;}
    else if(nHadJets==5 || nHadJets==6){ sBin=21;}
    else if(nHadJets>=7)               { sBin=26;}
  }
  
  if(sBin==1){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<99.99) continue;
      int sBin1=sBin;
      m_i++;
      if(MET_ >= METLowEdge_v2[i] && MET_ < METLowEdge_v2[i+1]){ sBin = sBin+m_i;
	break; }
      else if(MET_ >= METLowEdge_v2[METLowEdge_v2.size()-1])  { sBin = 6        ;
	break; }
    }
  }


  else{
    int sBin1=sBin;
    for(int i=0;i<METLowEdge_v2_1.size()-1;i++){
      if(METLowEdge_v2_1[i]<99.99) continue;
      m_i++;
      if(MET_ >= METLowEdge_v2_1[i] && MET_ < METLowEdge_v2_1[i+1]){ sBin = sBin+m_i;
	break;}
      else if(MET_ >= METLowEdge_v2_1[METLowEdge_v2_1.size()-1])  { sBin = sBin+5;
	break; }
    }
  }


  return sBin;
}


int Mulijet::getBinNoV6_SP(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nHadJets, int nbjets, double MET_)
{
  int sBin=-100,m_i=0;

  //  if(!((EWselec_Wtag || EWselec_Htag) && EWselec1))
   if(!(EWselec && EWselec1))
    { 
      if(nbjets==0 )	sBin=1;
      else sBin = 2;      
    }

   if((EWselec && EWselec1))
     {
       if(EWselec_Wtag && !EWselec_Htag)  sBin=3;
       else if(!EWselec_Wtag && EWselec_Htag)  sBin=4;
     }

  return sBin;
}


int Mulijet::getBinNoV6_EW(bool EWselec_Htag , bool EWselec_Wtag, double MET_){
  int sBin=-100,m_i=0;
  if(EWselec_Wtag && !EWselec_Htag){
    sBin=0;
  }
  else if(!EWselec_Wtag && EWselec_Htag){
    sBin=7;
  }
  if(sBin==0){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<249.99) continue;
      m_i++;
      if(MET_ >= METLowEdge_v3[i] && MET_ < METLowEdge_v3[i+1]){ sBin = sBin+m_i;break; }
      else if(MET_ >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = 7         ;break; }
    }
  }
  else if(sBin==7){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<249.99) continue;
      m_i++;
      if(MET_ >= METLowEdge_v3[i] && MET_ < METLowEdge_v3[i+1]){ sBin = sBin+m_i;break; }
      else if(MET_ >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = sBin+7   ;break; }
    }
  }
  return sBin;
}


bool Mulijet::check_eMatchedtoGamma(TLorentzVector bestPhoton){
  for(int i=0;i<Electrons->size();i++)
    {
      if( bestPhoton.DeltaR((*Electrons)[i]) < 0.1)
        return true;
    }
  return false;
}

bool Mulijet::check_muMatchedtoGamma(TLorentzVector bestPhoton){
  for(int i=0;i<Muons->size();i++)
    {
      if( bestPhoton.DeltaR((*Muons)[i]) < 0.1)
        return true;
    }
  return false;
}
double Mulijet::getGenLep(TLorentzVector bestPhoton){//MC only
  vector<TLorentzVector> v_genLep2;
  TLorentzVector genMu1, genEle1;  
  for(int i=0 ; i < GenElectrons->size(); i++)
    {
      if((*GenElectrons)[i].Pt()!=0)
	{
	  genEle1 = ((*GenElectrons)[i]);
	  v_genLep2.push_back(genEle1);
	}
	      
    }
  for(int i=0 ; i < GenMuons->size(); i++)
    {
      if((*GenMuons)[i].Pt()!=0)
	{
	  genMu1 = ((*GenMuons)[i]);
	  v_genLep2.push_back(genMu1);
	}
    }
  return MinDr(bestPhoton,v_genLep2);
  
}

double Mulijet::getGendRLepPho(){//MC only
  TLorentzVector genPho1,genLep1;
  int leadGenPhoIdx=-100;
  for(int i=0;i<GenParticles->size();i++){
    if((*GenParticles)[i].Pt()!=0){
      if((abs((*GenParticles_PdgId)[i])==22) && ((abs((*GenParticles_ParentId)[i])<=25) || ((*GenParticles_ParentId)[i]==2212) ) && (*GenParticles_Status)[i]==1 ){
	if(genPho1.Pt() < (*GenParticles)[i].Pt()){
	  leadGenPhoIdx = i;
	  genPho1 = ((*GenParticles)[i]);
	}
      }
      if( (abs((*GenParticles_PdgId)[i])==11 || abs((*GenParticles_PdgId)[i])==13 || abs((*GenParticles_PdgId)[i])==15 ) && (abs((*GenParticles_ParentId)[i])<=25) && (abs((*GenParticles_ParentId)[i])!=15) ){
	if(genLep1.Pt() < ((*GenParticles)[i]).Pt()) genLep1 = ((*GenParticles)[i]);
      }
    }
  }//for
  if(genPho1.Pt() > 0. && genLep1.Pt() > 0.) return genLep1.DeltaR(genPho1);
  else return 1000.0;
}
