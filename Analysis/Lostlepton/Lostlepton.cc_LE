#define Lostlepton_cxx
#include "Lostlepton.h"
#include <TH2.h>
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
TString Tf="sBin7_SP";
//TString Tf="nHadJets";
//TString Tf="MET";
//TString Tf="METvBin2";
bool full_Run2=false;
bool apply_METfilters=true;
bool apply_L1=true;
bool apply_HEMveto=true;
bool elec=true;
bool muon=false;
bool highdphi=true;
bool EWKsub=false;
bool applytrg=true;
bool applyE_SF=true;
bool applybTagSFs=true;
bool applysys=false;
bool savePDFscaleUnc=false;

int main(int argc, char* argv[])
{

  if (argc < 2) {
    cerr << "Please give 3 arguments " << "runList " << " " << "outputFileName" << " " << "dataset" << endl;
    return -1;
  }
  const char *inputFileList = argv[1];
  const char *outFileName   = argv[2];
  const char *data          = argv[3];

  Lostlepton ana(inputFileList, outFileName, data);
  cout << "dataset " << data << " " << endl;

  ana.EventLoop(data,inputFileList);

  return 0;
}

void Lostlepton::EventLoop(const char *data,const char *inputFileList) {
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  cout << "nentries " << nentries << endl;
  cout << "Analyzing dataset " << data << " " << endl;

  TString s_data=data;
  Long64_t nbytes = 0, nb = 0;
  int decade = 0;
  TCanvas *cA = new TCanvas("METEff","Signal efficiency",1500,850);
  int evtSurvived=0;  
  int EW_evtSurvived=0;
  int EW_evtSurvived_SB=0;  
  int EW_evtSurvived_htag=0;  
  int EW_evtSurvived_wtag=0;  
  int SP_evtSurvived=0;  
  int EW_noSB_evtSurvived=0;

  TFile *pufile,*TF,*E_SF,*Egamma_SF,*TF2,*RK;
  cout<<"Applying electron scale factors ? "<<applyE_SF<<endl;
  cout<<"Saving hists for PDF & Scale syst? "<<savePDFscaleUnc<<endl;

  cout<<"Applying MET filters ? "<<apply_METfilters<<endl;
  if(s_data.Contains("v17_2016")){
    pufile = TFile::Open("PileupHistograms_2016_69mb_pm5.root","READ");
    cout<<"Applying L1 prefiring prob.? "<<apply_L1<<endl;
  }
  if(s_data.Contains("v17_2017")){
    pufile = TFile::Open("PileupHistograms_2017_69mb_pm5.root","READ");
    cout<<"Applying L1 prefiring prob.? "<<apply_L1<<endl;
  }
  if(s_data.Contains("v17_2018")){
    pufile = TFile::Open("PileupHistograms_2018_69mb_pm5.root","READ");
    cout<<"Applying HEM veto? "<<apply_HEMveto<<endl;
  }

  
  TH1* puhist;
  TH1D *tf,*tf_SP,*tf_SP_2,*tf_SP_3,*mj_wt;
  TH2F *e_recoSF, *e_SF;
  if(highdphi)
  {

    TF = TFile::Open("lostlepton_highdphi.root","READ");
    RK  = TFile::Open("RK_lowMET_data.root","READ");
  }
  else
    {
      TF = TFile::Open("lostlepton_lowdphi.root","READ");
      RK  = TFile::Open("RK_lowMET_data.root","READ");
    }
  if(!full_Run2)
    {
      if(s_data.Contains("2017")){
	E_SF= TFile::Open("LeptonSFs.root","READ");
	e_SF=(TH2F*)E_SF->Get("EleSF_2017");
	e_recoSF=(TH2F*)E_SF->Get("EleSF_reco_2017");
	  //          e_SF->Multiply(e_recoSF);
      }
      if(s_data.Contains("2018")){
	E_SF= TFile::Open("LeptonSFs.root","READ");
	e_SF=(TH2F*)E_SF->Get("EleSF_2018");
	e_recoSF=(TH2F*)E_SF->Get("EleSF_reco_2018");
	
      }
      if(s_data.Contains("2016")){
	E_SF= TFile::Open("LeptonSFs.root","READ");
	e_SF=(TH2F*)E_SF->Get("EleSF_2016");
	e_recoSF=(TH2F*)E_SF->Get("EleSF_reco_2016");	
      }
    }
  // if(s_data.Contains("full")){
  //   TF = TFile::Open("Runfull_Run2_TF_lowdphi_LE_v6_CD.root","READ");
  // }
  
  if(Tf=="sBin6")
    tf = (TH1D*)TF->Get("tf");
  if(Tf=="sBin6_SP")
    tf_SP = (TH1D*)TF->Get("tf_SP");
  if(Tf=="sBin7_SP" || Tf=="nHadJets" || Tf=="BTagsDeepCSV" || Tf=="MET" || Tf=="METvBin2")
    tf_SP_2 = (TH1D*)TF->Get("tf_SP_2");
  if(Tf=="sBin7_SP_tmp")
    tf_SP_3 = (TH1D*)TF->Get("tf_SP_3");

  if(EWKsub)  mj_wt= (TH1D*)RK->Get("fr");
  else mj_wt= (TH1D*)RK->Get("fr1");
  /*
  if(!EWKsub)
    {
      for (Int_t i=0; i < mj_wt->GetEntries(); i++)
	{
	  mj_wt->SetBinContent(i,1);
          mj_wt->SetBinError(i,0);
	}
    }
  */
  if(s_data.Contains("v17"))
    {
      puhist = (TH1*)pufile->Get("pu_weights_up");
    }
  //  for(int i=1;i<mj_wt->GetEntries(); i++)
  //    cout<< mj_wt->GetBinContent(i)<<endl;
  //=========================================
  int fListIndxOld=-1;
  double prob0=-100,prob1=-100;
  double prob2=-100,prob3=-100;
  double total_prob0=0,total_prob1=0;
  double total_prob2=0,total_prob3=0;
  vector<TString> inFileName;
  TString sampleName;
  //  TString sampleName="CR_Summer16v3.DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.root";                                                      
  cout<<"inputFileList : "<<inputFileList<<endl; 
  string str1;
  ifstream runListFile(inputFileList);
  TFile *currFile;
  while (std::getline(runListFile, str1)) {
    inFileName.push_back(str1);
  }runListFile.close();
  cout<<"applying b-tag SFs for MC? "<<applybTagSFs<<endl;
  BTagCorrector btagcorr;
  //=========================================


  bool v17=true, v12=false;
  // bool v17=false, v12=true;
  bool EWselection=true;
  int elec_reco=0,elec_reco0_before=0,elec_reco1_before=0,muon_reco=0,elec_gen3=0,elec_gen2=0, elec_gen=0, muon_gen=0,elec_reco0=0,elec_reco1=0,evtSurvived_preselec=0,elec_reco2=0,elec2_reco=0,survived_vetohad=0,elec_reco1_CR=0,survived_elecge1=0,events_cr=0,events_sr=0,total=0,remain=0,elec_reco0_genel=0,efakepho=0,ele=0,genphomatch_after=0,genphomatch_before=0,elec_gen4=0,gentauhad2=0,lep2=0,lep=0,recoelec1=0,recoelec2=0;
  int fail_realphoton=0;
  int no_realphoton=0;
  int fail_realphoton_v2=0;
  int pass_realphoton=0;
  int pass_realphoton_v2=0;
  int fail_acceptance=0;
  int pass_acceptance=0;
  int fail_id=0;
  int pass_id=0;
  int fail_iso=0;
  int pass_iso=0;
  int pass_hadtau=0;
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

    bool EWselec=false;
    bool EWselec_Wtag=false;
    bool EWselec_Htag=false;
    bool EWselec_SB1=false;
    bool EWselec_SB2=false;
    bool EWselec1=false;

    double p0=-100, p1=-100, p2=-100;

    if(!s_data.Contains("data"))
      {

	if(s_data.Contains("2016") && highdphi) {lumiInfb=35.922; p0=1.66539e+02; p1=8.13254e+01; p2=9.71152e-01; deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017") && highdphi) {lumiInfb=41.529; p0=1.86744e+02; p1=6.74978e+01; p2=9.65333e-01; deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018") && highdphi) {lumiInfb=59.74; p0=1.89868e+02; p1=6.60434e+01; p2=9.79618e-01; deepCSVvalue = 0.4184;}

        if(s_data.Contains("2016") && !highdphi) {lumiInfb=35.922; p0=1.67229e+02; p1=8.52729e+01; p2=8.29784e-01; deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017") && !highdphi) {lumiInfb=41.529; p0=1.67641e+02; p1=1.21487e+02; p2=9.23864e-01; deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018") && !highdphi) {lumiInfb=59.74; p0=1.45529e+02; p1=1.08431e+02; p2=9.27220e-01; deepCSVvalue = 0.4184;}

	if(s_data.Contains("FastSim") && s_data.Contains("2016")) {lumiInfb=137.19; deepCSVvalue = 0.6321;}
      }
    if(s_data.Contains("data"))
      {
        if(s_data.Contains("2016")) {deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017")) {deepCSVvalue = 0.4941;}
        if(s_data.Contains("2018")) {deepCSVvalue = 0.4184;}
      }

    if(!s_data.Contains("v17")) savePDFscaleUnc = false;

    if(savePDFscaleUnc){
      if((s_data.Contains("v17_2016") || s_data.Contains("v17_2017"))) wt=Weight*1000.0*NonPrefiringProb*lumiInfb;
      if(s_data.Contains("v17_2018")) wt=Weight*1000.0*lumiInfb;
      for(int si=0;si<ScaleWeights->size();si++)
	h_SclWt->Fill(si,(*ScaleWeights)[si]*wt);
      for(int pi=0;pi<PDFweights->size();pi++)
	h_PDFWt->Fill(pi,(*PDFweights)[pi]*wt);
    }

    if((s_data.Contains("v17_2016") || s_data.Contains("v17_2017") ) && apply_L1){
      //      cout<<jentry<<" : NonPrefiringProb ="<<NonPrefiringProb<<" , lumiInfb = "<<lumiInfb<<" , pile up = "<<puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1))))<<endl;
      wt=Weight*1000.0*NonPrefiringProb*lumiInfb*(puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1)))));
      h_nEvts->Fill(1,wt);
      }

    if(s_data.Contains("v17_2018") && apply_HEMveto){
      wt=Weight*1000.0*lumiInfb*(puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1)))));
      h_nEvts->Fill(1,wt);
    }

    bool HEMaffected = false;
    //////-======== HEM issue ==================//////////////                                                                                                            
    if(s_data.Contains("2018") && apply_HEMveto){
      for(int i=0; i<Electrons->size();i++)
        if((*Electrons)[i].Pt() >30 && (*Electrons)[i].Eta() > -3.0 && (*Electrons)[i].Eta() < -1.4 && (*Electrons)[i].Phi() > -1.57 && (*Electrons)[i].Phi() < -0.87) {
HEMaffected = true; break;}
      for(int i=0; i<Jets->size();i++)
        if((*Jets)[i].Pt() > 30 && (*Jets)[i].Eta() > -3.2 && (*Jets)[i].Eta() < -1.2 && (*Jets)[i].Phi() > -1.77 && (*Jets)[i].Phi() < -0.67 && DeltaPhi((*Jets)[i].Pt(),METPhi)<0.5) {HEMaffected = true; break;}
      if(HEMaffected == true) continue;
    }
 

    bool tighte_trgpass=true;
    if(s_data.Contains("data") && applytrg)
      {
      wt=1;
	if(TriggerPass->size()!=148) continue;
	if((*TriggerPass)[124]==1 || (*TriggerPass)[110]==1 || (*TriggerPass)[112]==1 || (*TriggerPass)[116]==1 || (*TriggerPass)[118]==1 || (*TriggerPass)[120]==1 ) tighte_trgpass=true;
	  else tighte_trgpass=false;
	
	if(tighte_trgpass==false)  continue;
      }
    if(!s_data.Contains("data") && !s_data.Contains("FastSim") && applytrg)
      {
	if(MET>300) wt = wt * (((TMath::Erf((MET - p0)/p1)+1)/2.0)*p2);
	else wt = wt * 0.98;
      }
    


    //ISR weighting, end.
    //    if(!(MET<500 || MET>600)) continue;
    if(PFCaloMETRatio >=  5) continue;
    //    if(MET/CaloMET > 2.0) continue;
   //=================================================================================================
    if(s_data.Contains("TTJets2"))
      {//cout<<" correct "<<endl;
   	if ( madHT>600) continue;
      }	

    TLorentzVector bestPhoton=getBestPhoton();	

    if(!s_data.Contains("FastSim") && apply_METfilters==true){

      //  if(s_data.Contains("data"))
      // 	 {
      // 	   //      	  if(s_data.Contains("2016")) ecalBadCalibReducedExtraFilter = 1;                                        
      // 	   if(!(globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter  && eeBadScFilter==1 && NVtx>0  && JetID && JetIDAK8 && ecalBadCalibReducedExtraFilter)) continue;
      //   }
      // if(s_data.Contains("v17"))
      //   {
      // 	  //      	  eeBadScFilter = 1;                                                                                              
      //     if(!(globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && NVtx>0 && eeBadScFilter==1 && JetID && JetIDAK8 && ecalBadCalibReducedExtraFilter)) continue;
      //   }
      if(PFCaloMETRatio >=  5) continue;

    
      if(s_data.Contains("data"))
      	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter  && eeBadScFilter==1 && NVtx>0)) continue;

      if(s_data.Contains("v17"))
      	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && NVtx>0)) continue;
      
      // if(s_data.Contains("data_2018") || s_data.Contains("data_2017"))
      // 	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter==1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedFilter && ecalBadCalibReducedExtraFilter && eeBadScFilter==1)) continue;

      // if(s_data.Contains("v17_2018") || s_data.Contains("v17_2017"))
      // 	if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter==1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedFilter && ecalBadCalibReducedExtraFilter)) continue;

      //      if(!(CSCTightHaloFilter==1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && eeBadScFilter==1 && EcalDeadCellTriggerPrimitiveFilter==1 && BadPFMuonFilter && NVtx > 0) ) continue;
    }
    // wt=Weight*1000*lumiInfb;
    // cout<<"wt : "<<wt<<endl;
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

    // h_selectBaselineYields_2->Fill("MET>200",wt);
    // h_selectBaselineYields_2->Fill("BTagsDeepCSV >= 1",wt);
    // h_selectBaselineYields_2->Fill("BTagsDeepCSV = 0",wt);

   bool event_passed_old=false, event_passed_new=false;



   //============== Baseline Selections====================//

   if(bestPhotonIndxAmongPhotons<0) continue;
   bool bestPhoHasPxlSeed=true;
   if((*Photons_hasPixelSeed)[bestPhotonIndxAmongPhotons]<0.001) bestPhoHasPxlSeed=false;

   if( bestPhoHasPxlSeed ) continue;
   if(s_data.Contains("v17_2016"))
     {
       if((s_data.Contains("TTJets")||s_data.Contains("TTJets_v17")||s_data.Contains("TTJets2_v17"))){
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
     }
  
    //=========================================================================//

    //photon pt cut
    if(bestPhoton.Pt()>100)
      {
	h_selectBaselineYields_->Fill("Good #gamma with Pt > 100",wt);

      }
    else continue;

    
    double mt_ele=0,mt_pho=0,mt_ele1=0;

    TLorentzVector v_lep1,v_lep2;

    if(elec)
      {
	if (NMuons > 0) continue;
	else
	  h_selectBaselineYields_->Fill("veto Muon",wt);

	// //exactly 1 reco electron or 0 reco electron                                                                                                                    
	if (NElectrons > 1) continue;
	else
	  h_selectBaselineYields_2->Fill("veto electron > 1",wt);

        //No iso tracks from mu and pion                                                                                                                                   
	if(isoMuonTracks ==0 && isoPionTracks==0)
	  {
	    int a;
	    h_selectBaselineYields_->Fill("Iso track",wt);
	  }
	else continue;

	//selsct iso electron
	for(int i=0 ; i<Electrons->size() ; i++)
	  if(NElectrons==1 && (*Electrons_passIso)[i]==1)
	    {
	      if( ((*Electrons)[i].Pt() > 10) && abs((*Electrons)[i].Eta()) < 2.5 )
		{
		  lep++;
		  nlep++;
		  e_index=i;
		  v_lep1=(*Electrons)[i];
		  if(nlep>1) cout<<i<<""<<e_index<<" , e pt = "<<v_lep1.Pt()<<endl;
		}
	    }
      }
    
    mt_ele=sqrt(2*v_lep1.Pt()*MET*(1-cos(DeltaPhi(METPhi,v_lep1.Phi()))));

    
    if( bestPhoHasPxlSeed || (bestPhoton.Pt()<100)  )
      continue;

    //========= hadjet -> removing jets which are matched with photon within mindr 0.3 =====//
    bool hadJetID=false;
 
    double nbjets=0;
    int bJet1Idx = -1;

    vector<TLorentzVector> nonbjets,bjets;
    int minDRindx=-100,photonMatchingJetIndx=-100,nHadJets=0;
    double minDR=99999,ST=0;
    vector<TLorentzVector> hadJets;
    vector<int> hadJets_hadronFlavor;
    vector<bool> hadJets_HTMask;
    vector<double> hadJets_bJetTagDeepCSVBvsAll;

    for(int i=0;i<Jets->size();i++){
      if( ((*Jets)[i].Pt() > 30.0) && (abs((*Jets)[i].Eta()) <= 2.4) )
	{
            {
	      double dR=bestPhoton.DeltaR((*Jets)[i]);
	      if(dR<minDR){minDR=dR;minDRindx=i;}
	    }
	}
    }

    if( minDR > 0.3 )  minDRindx   = -100;

    for(int i=0;i<Jets->size();i++){
      if( ((*Jets)[i].Pt() > 30.0) && (abs((*Jets)[i].Eta()) <= 2.4) ){
        if(  i!=minDRindx ){
	  hadJetID=(*Jets_ID)[i];
	  if(hadJetID)
	    {
	    hadJets.push_back((*Jets)[i]);
	    hadJets_hadronFlavor.push_back((*Jets_hadronFlavor)[i]);
	    hadJets_HTMask.push_back((*Jets_HTMask)[i]);
	    hadJets_bJetTagDeepCSVBvsAll.push_back((*Jets_bJetTagDeepCSVBvsAll)[i]);
	    if((*Jets_bJetTagDeepCSVBvsAll)[i] > deepCSVvalue){
	      bjets.push_back((*Jets)[i]); bJet1Idx = i;}	    
	    }
	}
      }
    }
    
    
    
    if( minDR<0.3 ) photonMatchingJetIndx=minDRindx;

    if(hadJets.size() == 0) continue;  
    for(int i=0;i<hadJets.size();i++)
      {
	if( (abs(hadJets[i].Eta()) < 2.4) ){ST=ST+(hadJets[i].Pt());}
	if( (abs(hadJets[i].Eta()) < 2.4) ){nHadJets++;}
      }
    for(int i=0;i<bjets.size();i++)
      if( (abs(bjets[i].Eta()) < 2.4) ){nbjets++;}
    
    if( minDR<0.3 ){
      ST=ST+bestPhoton.Pt();
    }
    sortTLorVec(&hadJets);

    
    //Minimum MET
    if( MET>200)  
      {
	h_selectBaselineYields_->Fill("MET>200",wt);
      }
    else continue;

    // Minimum 2 jets (photon is not counted as jet)
    if( nHadJets >= 2 )
      {
      	h_selectBaselineYields_->Fill("nJets >= 2",wt);
      }

    else
      {
      continue;
      }
    
    TLorentzVector Met;
    // double mT=0, dPhi_METjet1=3.8,dPhi_METjet2=3.8, dPhi_phojet1=3.8, dPhi_phojet2=3.8, dPhi_phoMET=3.8;
    // double dPhi_METjet3=3.8,dPhi_METjet4=3.8, dPhi_phojet3=3.8, dPhi_phojet4=3.8;
    double mT=0, dPhi_METjet1=10,dPhi_METjet2=10, dPhi_phojet1=10, dPhi_phojet2=10, dPhi_phoMET=10;
    double dPhi_METjet3=10,dPhi_METjet4=10, dPhi_phojet3=10, dPhi_phojet4=10;
    Met.SetPtEtaPhiE(MET,0,METPhi,0);

    if(hadJets.size() > 0)    dPhi_phojet1 = abs(bestPhoton.DeltaPhi(hadJets[0])); 
    if(hadJets.size() > 1)    dPhi_phojet2 = abs(bestPhoton.DeltaPhi(hadJets[1]));
    dPhi_phoMET = abs(bestPhoton.DeltaPhi(Met));

    double mindphi=1000;
    if(hadJets.size() > 0) {   dPhi_METjet1 = abs(Met.DeltaPhi(hadJets[0]));mindphi=dPhi_METjet1;}
    if(hadJets.size() > 1)  {  dPhi_METjet2 = abs(Met.DeltaPhi(hadJets[1])); if(dPhi_METjet2<mindphi) mindphi=dPhi_METjet2;}

    double mTPhoMET=sqrt(2*(bestPhoton.Pt())*MET*(1-cos(DeltaPhi(METPhi,bestPhoton.Phi()))));

    //Minimum dPhi cut between MET and leading two jets
    if(highdphi){
      if(dPhi_METjet1 > 0.3 && dPhi_METjet2 > 0.3 )
	{
	  h_selectBaselineYields_->Fill("dPhi1 & dPhi2 >= 0.3",wt);
	}
      else continue;
    }
    if(!highdphi){
      if(!(dPhi_METjet1 > 0.3 && dPhi_METjet2 > 0.3 ))
        {
          h_selectBaselineYields_->Fill("dPhi1 & dPhi2 >= 0.3",wt);
        }
      else continue;
    }   

    //    if(photonMatchingJetIndx>=0 && (((*Jets)[photonMatchingJetIndx].Pt())/(bestPhoton.Pt()) < 1.0 || ((*Jets)[photonMatchingJetIndx].Pt())/(bestPhoton.Pt()) > 1.2)) continue;
    if(photonMatchingJetIndx>=0 && (((*Jets)[photonMatchingJetIndx].Pt())/(bestPhoton.Pt()) < 1.0)) continue;
    if(photonMatchingJetIndx<0) continue;

    // //============== New Trigger selections ================				     
    if( (ST <= 300) ) continue;

    if( !((MET>200 && bestPhoton.Pt()>100) ) )continue;
    else 
    h_selectBaselineYields_->Fill("MET>200 & photon pt>100 selec",wt);
    bool process= true;
    if(highdphi)
      {
	process = process && !bestPhoHasPxlSeed && bestPhoton.Pt()>=100 && ST>300 && nHadJets>=2 && MET > 200 && dPhi_METjet1 > 0.3 && dPhi_METjet2 > 0.3 && NMuons==0 && isoMuonTracks==0 && isoPionTracks==0;
      }

    if(!highdphi)
      {
	//        process = process && !bestPhoHasPxlSeed && bestPhoton.Pt()>=100 && ST>300 && nHadJets>=2 && MET > 300 && NMuons==0 && isoMuonTracks==0 && isoPionTracks==0;
	process = process && !bestPhoHasPxlSeed && bestPhoton.Pt()>=100 && ST>300 && nHadJets>=2 && MET > 200 && (!(dPhi_METjet1 > 0.3 && dPhi_METjet2 > 0.3)) && NMuons==0 && isoMuonTracks==0 && isoPionTracks==0;
      }

      if(!process) continue;

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

      if(applybTagSFs && s_data.Contains("v17")){

	prob = btagcorr.GetCorrections(hadJets,hadJets_hadronFlavor,hadJets_HTMask);
	prob0=prob[0];
	prob1=(prob[1]+prob[2]+prob[3]);

      }




    //============== EWkino selections ===============

  
    //===============Ak8 Jets =====================
    bool hadAK8JetID =false;
    int minDR4indx=-100,minDR5indx , Ak8ID=-100;//photonMatchingJetIndx=-100,nHadJets=0;
    double minDR4=99999,minDR5;
    vector<TLorentzVector> hadAK8Jets;
    vector<TLorentzVector> hadAK8Jets_matchedW;
    vector<double> hadAK8Mass, hadAK8Mass_matchedW;
    double Ak8Mass,max=0.0,Ak8Mass1;
    for(int i=0;i<JetsAK8->size();i++)
      if( ((*JetsAK8)[i].Pt() > 200.0) && (abs((*JetsAK8)[i].Eta()) <= 2.4) ){
	double dR4=bestPhoton.DeltaR((*JetsAK8)[i]);
	if(dR4<minDR4){minDR4=dR4;minDR4indx=i;}
      }
    
    for(int i=0;i<JetsAK8->size();i++)
      if( ((*JetsAK8)[i].Pt() > 200.0) && (abs((*JetsAK8)[i].Eta()) <= 2.4) ){
	if( !(minDR4 < 0.8 && i==minDR4indx) ){
	  hadAK8JetID=(*JetsAK8_ID)[i];
	  if(hadAK8JetID)
	    {
	      hadAK8Jets.push_back((*JetsAK8)[i]);
	      hadAK8Mass.push_back((*JetsAK8_softDropMass)[i]);
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

    
    //==============Ak8 EW selection=====================//
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

	
      //   //================================================
    evtSurvived_preselec++;     

    int nGenMu=0,nGenEle=0,nGenTau=0,nGenHad=0,nGenLep=0,nGenEle_tau=0,nGenMu_tau=0,nGentau_lep=0,nGentau_had=0,nGentau_had1=0,nGenTau1=0,nGenEle1=0,nGenEle_tau1=0,nGenMu1=0,nGenMu_tau1=0,o=0;
    vector<TLorentzVector> v_genEle1, v_genPho1, v_genMu1,v_genTau1,v_genHad1,v_genLep1,v_gentau_lep1,v_gentau_had1,v_gentau_had2,v_genTau2,v_genEle2,v_genMu2,v_genLep2;

    if(process && EWselection && hadJetID)
      {
	//	cout<<"======== 1 =====>"<<endl;

	if(NElectrons>0 && elec){
	  double dr2=bestPhoton.DeltaR((*Electrons)[e_index]);
	}
	if(NElectrons==1 && nlep==1 && elec) ele++;

	//==================================== After Baseline Events selection ========================
	//	int nGenMu=0,nGenEle=0,nGenTau=0,nGenHad=0,nGenLep=0,nGenEle_tau=0,nGenMu_tau=0,nGentau_lep=0,nGentau_had=0,nGentau_had1=0,nGenTau1=0,nGenEle1=0,nGenEle_tau1=0,nGenMu1=0,nGenMu_tau1=0,o=0;
	TLorentzVector genPho1,genEle1,neutr,genMu1,genTau1,genHad1,genLep1,gentau_lep1,gentau_had1,v_elec;
	//	vector<TLorentzVector> v_genEle1, v_genPho1, v_genMu1,v_genTau1,v_genHad1,v_genLep1,v_gentau_lep1,v_gentau_had1,v_gentau_had2,v_genTau2,v_genEle2,v_genMu2,v_genLep2;
	int leadGenPhoIdx=-100;
	double ratio=-10,mindr_=-10;

	if(!s_data.Contains("data") ){
	  
	  // cout<"++++++++++++++++"<<endl;
	  for(int i=0;i<GenParticles->size();i++){
	    if((*GenParticles)[i].Pt()!=0){
	      if((abs((*GenParticles_PdgId)[i])==22) && ((abs((*GenParticles_ParentId)[i])<=25) || ((*GenParticles_ParentId)[i]==2212) ) && (*GenParticles_Status)[i]==1 ){
		leadGenPhoIdx = i;
		genPho1 = ((*GenParticles)[i]);
		v_genPho1.push_back(genPho1);
	      }
	      /*
              if((abs((*GenParticles_PdgId)[i])==11) && ((abs((*GenParticles_ParentId)[i])<=25) || ((*GenParticles_ParentId)[i]==2212) ) && (*GenParticles_Status)[i]==1 ){
                leadGenPhoIdx = i;
                genPho1 = ((*GenParticles)[i]);
                v_genEle1.push_back(genPho1);
              }
	      */
	    }
	  
	  }
	  bool hadtau = false;
       
	  for(int i=0 ; i < GenElectrons->size(); i++)
	    {
	      if((*GenElectrons)[i].Pt()!=0)
		{
		 
		  nGenEle1++;
		  genEle1 = ((*GenElectrons)[i]);
		  v_genEle2.push_back(genEle1);
		  v_genEle1.push_back(genEle1);
		  v_genLep2.push_back(genEle1);
		  // if((*GenElectrons_fromTau)[i])
		  //   nGenEle_tau1++;
		}
	      
	    }
	  // if(o>0)
	  //   cout<<jentry<<" : np. of Gen e : "<<nGenEle1<<endl;
	  for(int i=0 ; i < GenMuons->size(); i++)
	    {
	      if((*GenMuons)[i].Pt()!=0)
		{
		  nGenMu1++;
		  genMu1 = ((*GenMuons)[i]);
		  v_genMu2.push_back(genMu1);
		  v_genLep2.push_back(genMu1);
		  // if((*GenMuons_fromTau)[i])
		  //   nGenMu_tau1++;
		}
	    }
       
	  for(int i=0 ; i < GenTaus->size(); i++)
	    {
	      if((*GenTaus)[i].Pt()!=0)
		{
		  nGenTau1++;
		  genTau1 = ((*GenTaus)[i]);
		  v_genTau2.push_back(genTau1);
		  //v_genLep2.push_back(genTau1);
		  if((*GenTaus_had)[i])
		    nGentau_had1++;
		}
	    }

	  for(int i=0;i<v_genPho1.size();i++)
	    {h_mindr_ph_lep->Fill(MinDr(v_genPho1[i],v_genEle2),wt);
	      //  h_mindr_genph_had->Fill(MinDr(v_genPho1[i], v_genHad1),wt);

	    }
	  double gendRLepPho = getGendRLepPho();
	  h_madminphotonDR->Fill(madMinPhotonDeltaR,wt);
	  //	  h_mindr_goodph_had->Fill(MinDr(bestPhoton, v_genHad1),wt);
	  //	  h_mindr_goodph_ph->Fill(MinDr(bestPhoton,v_genPho1),wt);
	  h_mindr_goodph_lep->Fill(MinDr(bestPhoton,v_genEle2),wt);
	  /////////////// prompt photon check //////////////////
	  genphomatch_before++;
	  //	  if(MinDr(bestPhoton,v_genLep2) <1) continue;	  
 	  if(s_data=="genprompt" || s_data.Contains("TTG") ){
	    if(!hasGenPromptPhoton){
	      if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	    }
	    else if(hasGenPromptPhoton){
	      if(!(madMinPhotonDeltaR >= 0.5 && MinDr(bestPhoton,v_genLep2) >=0.5 ))continue;	   
	    }
	  }//Gen prompt       
	  if(s_data=="genprompt" || s_data.Contains("WG")){
	    if(!hasGenPromptPhoton){
	      if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	    }
	    else if(hasGenPromptPhoton){
	      if(!(madMinPhotonDeltaR >= 0.5 && MinDr(bestPhoton,v_genLep2) >=0.5 ))continue;
	    }
	  }//Gen prompt                                                                                                                         
     	
	  if(s_data.Contains("WJets")){
	    if(!hasGenPromptPhoton){
	      if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	    }
	    else if(hasGenPromptPhoton){
	      if(!(madMinPhotonDeltaR < 0.5 || MinDr(bestPhoton,v_genLep2) < 0.5)) continue;
	    }
	  }

	  if(s_data.Contains("TTJets") || s_data.Contains("TTJets_v17") || s_data.Contains("TTJets2_v17"))
	    {
	      //	      cout<<"======== 1 =====>"<<endl;
	      if(!hasGenPromptPhoton){
	  	if(jentry==0)cout<<"**********processing "<<s_data<<" with non-prompt Gen photon"<<endl;
	      }
	      else if(hasGenPromptPhoton){
	  	if(!(madMinPhotonDeltaR < 0.5 || MinDr(bestPhoton,v_genLep2) < 0.5)) continue;
	      }	     

	    }//Gen non-prompt
	
	  genphomatch_after++;
         
	  h_mindr_ph_ele->Fill(MinDr(bestPhoton,v_genEle2),wt);
	  h_mindr_ph_mu->Fill(MinDr(bestPhoton,v_genMu2),wt);
	  h_mindr_ph_tau->Fill(MinDr(bestPhoton,v_genTau2),wt);

	  //	  if(madMinPhotonDeltaR < 1.0 || MinDr(bestPhoton,v_genLep2) < 1.0) continue;	  
	  // if(MinDr(bestPhoton,v_genLep2) < 1.0) continue; 
	  /*
	   if(NElectrons==1)
	    {
	      if(v_genEle2.size()==1 && (*Electrons)[e_index].DeltaR(v_genEle2[0])<0.2) recoelec1++; 
	      else if(v_genEle1.size()>1 && ((*Electrons)[e_index].DeltaR(v_genEle2[0])<0.2) || ((*Electrons)[e_index].DeltaR(v_genEle2[1])<0.2)) recoelec2++;
	      else cout<<" No reco good electron !!! "<<endl;
	    
	    }
	  */
	  ////////// SR region ///////////////////
	  if((NElectrons==0 && elec)){
	    if(elec)
	      {	     	     
		//if(nGenMu1==0 && nGenEle1==0 && v_genTau2.size()==0) continue;//to reject W->qq' type of events
		if(nGenMu1==0 && nGenEle1==0 && v_genTau2.size()==0) continue;//to reject W->qq' type of events                                                    
		if(nGentau_had1>1) continue;                                                                                                   
		survived_vetohad++;
		if(nGenMu1>0) continue;
		if(nGenEle1==0) continue;
		survived_elecge1++;
		if(v_genEle2.size()==0) {TLorentzVector v1;v_genEle2.push_back(v1);}

		sortTLorVec(&v_genEle2);
		//		v_genEle1=v_genEle1;
	      }
	    if(v_genEle2.size()==0) continue;
	    if(v_genMu2.size()>0) continue;
            if(isoElectronTracks!=0 || isoMuonTracks!=0 || isoPionTracks!=0) continue;
	    elec_reco0++;
            total++;
	    //////////////////////////////////////////////////////////////                                                    

           if(v_genEle2.size()==1 && bestPhoton.DeltaR(v_genEle2[0])<0.2 && v_genEle2[0].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[0].Pt()/bestPhoton.Pt()>0.79)
              {
		ratio=v_genEle2[0].Pt()/bestPhoton.Pt();
                //if(v_genEle2.size()==1) cout<<jentry<<"   ==> Failed : 1 gen e "<<bestPhoton.DeltaR(v_genEle2[0])<<" : "<<v_genEle2[0].Pt()/bestPhoton.Pt()<<endl;
                fail_realphoton++;
                h_pass_events->Fill(2,wt);
                continue;
              } 
            else if(v_genEle2.size()>1 && ((bestPhoton.DeltaR(v_genEle2[0])<0.2 && v_genEle2[0].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[0].Pt()/bestPhoton.Pt()>0.79) || (bestPhoton.DeltaR(v_genEle2[1])<0.2 && v_genEle2[1].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[1].Pt()/bestPhoton.Pt()>0.79)))
              {
                ratio=v_genEle2[0].Pt()/bestPhoton.Pt();
                //if(v_genEle2.size()==2) cout<<jentry<<"   ==> Failed : 2 gen e "<<bestPhoton.DeltaR(v_genEle2[0])<<" : "<<bestPhoton.DeltaR(v_genEle2[1])<<" : "<<v_genEle2[0].Pt()/bestPhoton.Pt()<<" : "<<v_genEle2[1].Pt()/bestPhoton.Pt()<<endl;
                fail_realphoton++;
                h_pass_events->Fill(2,wt);
                continue;
              }

            else
              {
		/*
                if(v_genEle2.size()>0 && MinDr(bestPhoton,v_genEle2)<0.1){ cout<<jentry<<" : v_genEle2 size = "<<v_genEle2.size()<<" , MinDr(bestPhoton,v_genEle2) : "<<MinDr(bestPhoton,v_genEle2)<<endl;
                  if(v_genEle2.size()==1) cout<<"gen e pt = "<<v_genEle2[0].Pt()<<" , photon pt = "<<bestPhoton.Pt()<<" , ratio = "<<v_genEle2[0].Pt()/bestPhoton.Pt()<<endl;
                  if(v_genEle2.size()>1) cout<<"gen e pt = "<<v_genEle2[0].Pt()<<" , photon pt = "<<bestPhoton.Pt()<<" , ratio = "<<v_genEle2[0].Pt()/bestPhoton.Pt()<<"gen e pt = "<<v_genEle2[1].Pt()<<" , photon pt = "<<bestPhoton.Pt()<<" , ratio = "<<v_genEle2[1].Pt()/bestPhoton.Pt()<<endl;
		}
		*/
               // h_mindr_lep_goodph->Fill(MinDr(bestPhoton,v_genEle2),wt);
                if(v_genEle2.size()==1)
		  {
                    if(!(bestPhoton.DeltaR(v_genEle2[0])<0.2 && v_genEle2[0].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[0].Pt()/bestPhoton.Pt()>0.79)) {ratio=v_genEle2[0].Pt()/bestPhoton.Pt(); mindr_=bestPhoton.DeltaR(v_genEle2[0]);}
		  }
		if(v_genEle2.size()>1)
		  {
		    if(!(bestPhoton.DeltaR(v_genEle2[0])<0.2 && v_genEle2[0].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[0].Pt()/bestPhoton.Pt()>0.79)) {ratio=v_genEle2[0].Pt()/bestPhoton.Pt();  mindr_=bestPhoton.DeltaR(v_genEle2[0]);}
		    else if(!(bestPhoton.DeltaR(v_genEle2[1])<0.2 && v_genEle2[1].Pt()/bestPhoton.Pt()<1.21 && v_genEle2[1].Pt()/bestPhoton.Pt()>0.79)) {ratio=v_genEle2[1].Pt()/bestPhoton.Pt();  mindr_=bestPhoton.DeltaR(v_genEle2[0]);}
		  }
		pass_realphoton++;
                h_pass_events->Fill(1,wt);
              }
	   h_hasGenPromptPhoton_elec0->Fill(hasGenPromptPhoton,wt);

	   //	    if() h2_mindr_lep_goodph_ph->Fill(bestPhoton.DeltaR(v_genEle2[0]),bestPhoton.Pt()/v_genEle2[0].Pt(),wt);
	   //	   if(!s_data.Contains("data"))h2_mindr_lep_goodph_ph->Fill(mindr_,ratio,wt);
	    if(elec)
	      {	 
		if(v_genEle1.size() == 0) elec_gen++;
		if(v_genEle1.size() == 1) elec_gen3++;
		if(v_genEle1.size() == 2) elec_gen4++;
		if(nGenTau1 > 0) elec_gen2++;
		if(nGentau_had1 > 0) gentauhad2++; 
	      }


	    int n=0,l=0,m=0,o=0;
	    elec_reco0_before++;
	    cr_el=0,m=0;
	    int q=0,u=0;
	    bool acceptance=true,id=true,iso=true,cr=true,sr=true;  
	    for(int i=0; i<v_genEle1.size(); i++){

	      elec_reco0_genel++;
	      q++;
	      if(elec) h_selectBaselineYields_->Fill("SR : Electrons = 0",wt);
	      if(muon) h_selectBaselineYields_->Fill("SR : Muons = 0",wt);
	      int sBin6 = getBinNoV7_le(nbjets,nHadJets);
	      int sBin7_SP_elec0 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	      int sBin6_SP_elec0 = getBinNoV6(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	      h_SBins_v6_CD_SP_elec0->Fill(sBin6_SP_elec0,wt);
	      int sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	      h2_njetnbjet_phopt_vBin_elec0->Fill(sBin7_SP_elec0,bestPhoton.Pt(),wt);
	      h2_njetnbjet_phopt_elec0->Fill(sBin7_SP_elec0,bestPhoton.Pt(),wt);
	      
	      sBin7_SP_elec0 = getBinNoV7(nbjets,nHadJets);
	      h_SBins_v7_CD_SP_tmp_elec0->Fill(sBin7_SP_elec0,wt);
	      if(!s_data.Contains("data"))
		{
		  if(v_genEle2.size()==1) h2_mindr_lep_goodph_ph_elec0->Fill(bestPhoton.DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/bestPhoton.Pt(),wt);
		  else if(v_genEle2.size()>1){
		    if(bestPhoton.DeltaR(v_genEle2[0])<bestPhoton.DeltaR(v_genEle2[1])) h2_mindr_lep_goodph_ph_elec0->Fill(bestPhoton.DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/bestPhoton.Pt(),wt);
		    else if(bestPhoton.DeltaR(v_genEle2[0])>bestPhoton.DeltaR(v_genEle2[1])) h2_mindr_lep_goodph_ph_elec0->Fill(bestPhoton.DeltaR(v_genEle2[1]),v_genEle2[1].Pt(),wt);
		  }
		}
	      int nbjets_org=nbjets;
	      if(applybTagSFs  && s_data.Contains("v17")){
		nbjets=0;
		sBin6 = getBinNoV7_le(nbjets,nHadJets);
		h_SBins_v6_CD_elec0->Fill(sBin6,wt*prob0);
		sBin7_SP_elec0 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v7_CD_SP_elec0->Fill(sBin7_SP_elec0,wt*prob0);
		sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v6_CD_EW_50bin_elec0->Fill(sBin6_50bin,wt*prob0);
		h_MET_elec0->Fill(MET,wt*prob0);
		h_METvBin2_elec0->Fill(MET,wt*prob0);
		h_nJets_elec0->Fill(nHadJets,wt*prob0);
		h_ST_elec0->Fill(ST,wt*prob0);
		if(savePDFscaleUnc){
		  for(int si=0;si<ScaleWeights->size();si++)
		    h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt*prob0*(*ScaleWeights)[si]);
		  for(int si=0;si<PDFweights->size();si++)
		    h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt*prob0*(*PDFweights)[si]);
		}
		else
		  {
		    for(int si=0;si<ScaleWeights->size();si++)
		      h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt*prob0);
		    for(int si=0;si<PDFweights->size();si++)
		      h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt*prob0);
		  }
		nbjets=1;
		sBin6 = getBinNoV7_le(nbjets,nHadJets);
		h_SBins_v6_CD_elec0->Fill(sBin6,wt*prob1);
		sBin7_SP_elec0 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v7_CD_SP_elec0->Fill(sBin7_SP_elec0,wt*prob1);
		sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v6_CD_EW_50bin_elec0->Fill(sBin6_50bin,wt*prob1);
		if(!s_data.Contains("data")) {h_mindr_genph_lep_elec0->Fill(MinDr(bestPhoton,v_genLep2),wt);
		h_mindr_lep_goodph_elec0->Fill(MinDr(bestPhoton,v_genEle2),wt);	
		}
		h_MET_elec0->Fill(MET,wt*prob1);
		h_METvBin2_elec0->Fill(MET,wt*prob1);
		h_nJets_elec0->Fill(nHadJets,wt*prob1);
		h_ST_elec0->Fill(ST,wt*prob1);
		if(savePDFscaleUnc){
		  for(int si=0;si<ScaleWeights->size();si++)
		    h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt*prob1*(*ScaleWeights)[si]);
		  for(int si=0;si<PDFweights->size();si++)
		    h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt*prob1*(*PDFweights)[si]);
		}
                else
                  {
                    for(int si=0;si<ScaleWeights->size();si++)
                      h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt*prob1);
                    for(int si=0;si<PDFweights->size();si++)
                      h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt*prob1);
                  }

		h_BTags_elec0->Fill(0.0,wt*prob[0]);
		h_BTags_elec0->Fill(1.0,wt*prob[1]);
		h_BTags_elec0->Fill(2.0,wt*prob[2]);
		h_BTags_elec0->Fill(3.0,wt*prob[3]);
		nbjets=nbjets_org;
	      }
	      else 
		{
		  sBin6 = getBinNoV7_le(nbjets,nHadJets);
		  h_SBins_v6_CD_elec0->Fill(sBin6,wt);
		  sBin7_SP_elec0 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		  h_SBins_v7_CD_SP_elec0->Fill(sBin7_SP_elec0,wt);
		  sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		  h_SBins_v6_CD_EW_50bin_elec0->Fill(sBin6_50bin,wt);
		  h_MET_elec0->Fill(MET,wt);
		  h_METvBin2_elec0->Fill(MET,wt);
		  h_nJets_elec0->Fill(nHadJets,wt);
		  h_ST_elec0->Fill(ST,wt);
		  h_BTags_elec0->Fill(nbjets,wt);
		  if(savePDFscaleUnc){
		    for(int si=0;si<ScaleWeights->size();si++)
		      h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt*(*ScaleWeights)[si]);
		    for(int si=0;si<PDFweights->size();si++)
		      h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt*(*PDFweights)[si]);
		  }
		  else
		    {
		      for(int si=0;si<ScaleWeights->size();si++)
			h_SBins_v7_CD_SP_scale_elec0->Fill(sBin7_SP_elec0,si,wt);
		      for(int si=0;si<PDFweights->size();si++)
			h_SBins_v7_CD_SP_pdf_elec0->Fill(sBin7_SP_elec0,si,wt);
		    }
		}


	      h2_MET_nJets_elec0->Fill(nHadJets,MET,wt);
	      h2_METvBin2_nJets_elec0->Fill(nHadJets,MET,wt);
	      h2_nbjets_nJets_elec0->Fill(nHadJets,nbjets,wt);	
	      h_DBTags_elec0->Fill(abs(nbjets-BTags),wt);
	      h_minDr_bestphoEle_elec0->Fill(MinDr(bestPhoton,*Electrons),wt);
	      h_minDr_bestphoJets_elec0->Fill(MinDr(bestPhoton,hadJets),wt);
	      h_BestPhotonPt_vBin_elec0->Fill(bestPhoton.Pt(),wt);    
	      h_BestPhotonPt_elec0->Fill(bestPhoton.Pt(),wt);    
	      h_BestPhotonPhi_elec0->Fill(bestPhoton.Phi(),wt);
	      h_BestPhotonEta_elec0->Fill(bestPhoton.Eta(),wt);
	      if(nbjets == 0)
		{
		  h_BestPhotonPt_0b_elec0->Fill(bestPhoton.Pt(),wt);    
		  h_BestPhotonPt_0b_vBin_elec0->Fill(bestPhoton.Pt(),wt);    
		}
	      if(nbjets > 0)
		{
		  h_BestPhotonPt_ge1b_elec0->Fill(bestPhoton.Pt(),wt);    
		  h_BestPhotonPt_ge1b_vBin_elec0->Fill(bestPhoton.Pt(),wt);    
		}
		
	      if(elec)
		{
		  for(int j=0; j<Electrons->size();j++)
		    {
		      h_ElectronPt_elec0->Fill((*Electrons)[j].Pt(),wt);
		      h_ElectronEta_elec0->Fill(abs((*Electrons)[j].Eta()),wt);
		      h_ElectronPhi_elec0->Fill(abs((*Electrons)[j].Phi()),wt);
		    }
		}
	      if(muon)
		{
                  for(int j=0; j<Muons->size();j++)
		    {
		      h_ElectronPt_elec0->Fill((*Muons)[j].Pt(),wt);
		      h_ElectronEta_elec0->Fill((*Muons)[j].Eta(),wt);
		      h_ElectronPhi_elec0->Fill((*Muons)[j].Phi(),wt);
		    }		  
		}

	      for(int j=0; j<hadJets.size();j++)
		{ 
		  h_JetPt_elec0->Fill(hadJets[j].Pt(),wt);
		  h_JetEta_elec0->Fill(abs(hadJets[j].Eta()),wt);
		  h_JetPhi_elec0->Fill(abs(hadJets[j].Phi()),wt);
		}
	      h_mTPhoMET_elec0->Fill(mTPhoMET,wt); 
	      h_dPhi_phoMET_elec0->Fill(dPhi_phoMET,wt);	
	      h_hadAk8Mass_elec0->Fill(Ak8Mass,wt);
	      if(hadAK8Jets.size() > 0)
		h_hadAk8jetPt_elec0->Fill(hadAK8Jets[0].Pt(),wt);
	      if(hadJets.size() > 0)
		{
		  dPhi_METjet1 = (DeltaPhi(METPhi,(hadJets)[0].Phi()));
		  dPhi_phojet1 = (DeltaPhi(bestPhoton.Phi(),hadJets[0].Phi()));
		  h_dPhi_phojet1_elec0->Fill(dPhi_phojet1,wt);
		  h_dPhi_METjet1_elec0->Fill(dPhi_METjet1,wt);
		}

	      if(hadJets.size() > 1)
              {
                dPhi_METjet2 = (DeltaPhi(METPhi,(hadJets)[1].Phi()));
                dPhi_phojet2 = (DeltaPhi(bestPhoton.Phi(),hadJets[1].Phi()));
                h_dPhi_phojet2_elec0->Fill(dPhi_phojet2,wt);
                h_dPhi_METjet2_elec0->Fill(dPhi_METjet2,wt);
              }
	      
	      if(Electrons->size()>0 && elec)
		h2_leadElectronEta_Phi_elec0->Fill((*Electrons)[0].Eta(),(*Electrons)[0].Phi(),wt);
	      if(Muons->size()>0 && muon)
		h2_leadElectronEta_Phi_elec0->Fill((*Muons)[0].Eta(),(*Muons)[0].Phi(),wt);

	      if(hadJets.size()>0){
		h2_leadJetEta_Phi_elec0->Fill(hadJets[0].Eta(),hadJets[0].Phi(),wt);
		h_leadJetPhi_elec0->Fill(abs(hadJets[0].Phi()),wt);
		h_leadJetEta_elec0->Fill(abs(hadJets[0].Eta()),wt);
		h_leadJetPt_elec0->Fill(hadJets[0].Pt(),wt);
	      }	  
	      
	    }
	  }// gen electron loop
	}  //MC for SR

	//CR region for MC and data
	//	if((elec && NElectrons==1 && cr_el < 1 && e_index >=0))
	if((elec && NElectrons==1 && cr_el < 1 && e_index >=0 && nlep==1))
	  {
	    h_mTlepMET->Fill(mt_ele,wt);
	    if(mt_ele>100) continue;
	    h_mTlepMET_elec0->Fill(mt_ele,wt);

	    elec_reco++;
            double dr2=bestPhoton.DeltaR((*Electrons)[e_index]);
            if(dr2<=0.2) continue;
	    elec_reco1++;

	    
	    //	    if(v_genEle2.size()==0) continue;//cout<<jentry<<" No reco good electron !!! "<<endl; 
	    //if(v_genEle2.size()>0 && MinDr((*Electrons)[e_index],v_genEle2)>0.2) continue;

	    double eSF_wt=1.0,egammaSF_wt=1.0, pt=0,eta=0;

	    if(!applysys){
	      if(applyE_SF==true && !s_data.Contains("data"))
		{
		  pt=(*Electrons)[e_index].Pt();
		  eta=(*Electrons)[e_index].Eta();
		  if((*Electrons)[e_index].Pt()>499.9) pt=499;
		  eSF_wt=e_SF->GetBinContent(e_SF->GetXaxis()->FindBin(eta),e_SF->GetYaxis()->FindBin(pt));
                  if((*Electrons)[e_index].Pt()<20 && !s_data.Contains("2018")) pt=21;
		  egammaSF_wt=e_recoSF->GetBinContent(e_recoSF->GetXaxis()->FindBin(eta),e_recoSF->GetYaxis()->FindBin(pt));
		}
	      else
		{
		  eSF_wt=1.0;
		  egammaSF_wt=1.0;
		}
	    }
	    if(applysys){
	      if(applyE_SF==true && !s_data.Contains("data"))
		{
		  pt=(*Electrons)[e_index].Pt();
		  eta=(*Electrons)[e_index].Eta();
		  if((*Electrons)[e_index].Pt()>499.9) pt=499;
		  if((*Electrons)[e_index].Pt()<20) pt=21;
		  
		  eSF_wt=e_SF->GetBinContent(e_SF->GetXaxis()->FindBin(eta),e_SF->GetYaxis()->FindBin(pt)) + e_SF->GetBinError(e_SF->GetXaxis()->FindBin(eta),e_SF->GetYaxis()->FindBin(pt));
		  /*
		    if(e_SF->GetYaxis()->FindBin(pt) > e_SF->GetNbinsY())
		    eSF_wt=e_SF->GetBinContent(e_SF->GetXaxis()->FindBin(eta),e_SF->GetYaxis()->FindBin(pt)-1) + e_SF->GetBinError(e_SF->GetXaxis()->FindBin(eta),e_SF->GetYaxis()->FindBin(pt)-1);
		  */
                  if((*Electrons)[e_index].Pt()<20 && !s_data.Contains("2018")) pt=21;

		  egammaSF_wt=e_recoSF->GetBinContent(e_recoSF->GetXaxis()->FindBin(eta),e_recoSF->GetYaxis()->FindBin(pt)) + e_recoSF->GetBinError(e_recoSF->GetXaxis()->FindBin(eta),e_recoSF->GetYaxis()->FindBin(pt));
		  /*
		    if(e_recoSF->GetYaxis()->FindBin(pt) > e_recoSF->GetNbinsY())
		    egammaSF_wt=e_recoSF->GetBinContent(e_recoSF->GetXaxis()->FindBin(eta),e_recoSF->GetYaxis()->FindBin(pt)-1) + e_recoSF->GetBinError(e_recoSF->GetXaxis()->FindBin(eta),e_recoSF->GetYaxis()->FindBin(pt)-1);
		  */
		}
	      else
		{
		  eSF_wt=1.0;
		  egammaSF_wt=1.0;
		}
	    }
	    /*
	    cout<<"2 ===> "<<jentry<<endl;
	    cout<<"eSF_wt : "<<eSF_wt<<endl;
            cout<<"egammaSF_wt : "<<egammaSF_wt<<endl;
	    cout<<"<==================>"<<endl;
	    */
	    wt=eSF_wt*egammaSF_wt*wt;  
	    events_cr = events_cr+ 1 ; 
	    cr_el++;

	    if(elec) h_selectBaselineYields_->Fill("CR : Electrons = 1",wt);
            if(muon) h_selectBaselineYields_->Fill("CR : Muons = 1",wt);

	    if(!s_data.Contains("data"))
	      {
		//		if(v_genEle2.size()>0 && MinDr(bestPhoton,v_genEle2) > 0.2 ) continue;
		h_hasGenPromptPhoton->Fill(hasGenPromptPhoton,wt);

		if(v_genEle2.size()==1) {
		  h2_mindr_lep_goodph_ph->Fill(bestPhoton.DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/bestPhoton.Pt(),wt);
                  h2_mindr_lep_goodele_ele->Fill((*Electrons)[e_index].DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/(*Electrons)[e_index].Pt(),wt);
                  h_mindr_goodph_ph->Fill((*Electrons)[e_index].DeltaR(v_genEle2[0]),wt);
		  //		  cout<<jentry<<" : dR(gen e, good photon) = "<<bestPhoton.DeltaR(v_genEle2[0])<<" : dR(gen e, good e) = "<<(*Electrons)[e_index].DeltaR(v_genEle2[0])<<endl;
		  h2_mindr_lep->Fill(bestPhoton.DeltaR(v_genEle2[0]),(*Electrons)[e_index].DeltaR(v_genEle2[0]), wt);
		}
		else if(v_genEle2.size()>1){
		  if(v_genEle2.size()>2) cout<<jentry<<" : "<<v_genEle2.size()<<endl;
		  if(bestPhoton.DeltaR(v_genEle2[0])<bestPhoton.DeltaR(v_genEle2[1]))
		    {
		      h2_mindr_lep_goodph_ph->Fill(bestPhoton.DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/bestPhoton.Pt(),wt);
		      h2_mindr_lep_goodele_ele->Fill((*Electrons)[e_index].DeltaR(v_genEle2[0]),v_genEle2[0].Pt()/(*Electrons)[e_index].Pt(),wt);
		      h_mindr_goodph_ph->Fill((*Electrons)[e_index].DeltaR(v_genEle2[0]),wt);
		      h2_mindr_lep->Fill(bestPhoton.DeltaR(v_genEle2[0]),(*Electrons)[e_index].DeltaR(v_genEle2[0]), wt);
		    }
		  else if(bestPhoton.DeltaR(v_genEle2[0])>bestPhoton.DeltaR(v_genEle2[1])) 
		    {
		      h2_mindr_lep_goodph_ph->Fill(bestPhoton.DeltaR(v_genEle2[1]),v_genEle2[1].Pt(),wt);
		      h2_mindr_lep_goodele_ele->Fill((*Electrons)[e_index].DeltaR(v_genEle2[1]),v_genEle2[1].Pt()/(*Electrons)[e_index].Pt(),wt);
		      h_mindr_goodph_ph->Fill((*Electrons)[e_index].DeltaR(v_genEle2[1]),wt);
		      h2_mindr_lep->Fill(bestPhoton.DeltaR(v_genEle2[1]),(*Electrons)[e_index].DeltaR(v_genEle2[1]), wt);
		    }
		}
	      }


	    int sBin6 = getBinNoV7_le(nbjets,nHadJets);
	    //	    h_SBins_v6_CD_elec1->Fill(sBin6,wt);	
	    int sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	    //	    h_SBins_v7_CD_SP_elec1->Fill(sBin7_SP_elec1,wt);
	    int sBin6_SP_elec1 = getBinNoV6(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	    h_SBins_v6_CD_SP_elec1->Fill(sBin6_SP_elec1,wt);
	    int sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	    sBin7_SP_elec1 = getBinNoV7(nbjets,nHadJets);
	    h_SBins_v7_CD_SP_tmp_elec1->Fill(sBin7_SP_elec1,wt);

	    h2_njetnbjet_phopt_vBin->Fill(sBin7_SP_elec1,bestPhoton.Pt(),wt);
	    h2_njetnbjet_phopt->Fill(sBin7_SP_elec1,bestPhoton.Pt(),wt);
	    h2_MET_nJets->Fill(nHadJets,MET,wt);
	    h2_MET_METPhi->Fill(METPhi,MET,wt);
	    h2_MET_elepT->Fill((*Electrons)[e_index].Pt(),MET,wt);
	    h2_METvBin2_nJets->Fill(nHadJets,MET,wt);
	    h2_nbjets_nJets->Fill(nHadJets,nbjets,wt);
	    h_METPhi->Fill(METPhi,wt);

	    int nbjets_org=nbjets;
	    if(applybTagSFs  && s_data.Contains("v17")){
	      nbjets=0;
	      sBin6 = getBinNoV7_le(nbjets,nHadJets);
	      h_SBins_v6_CD_elec1->Fill(sBin6,wt*prob0);
	      sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	      h_SBins_v7_CD_SP_elec1->Fill(sBin7_SP_elec1,wt*prob0);
	      sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	      h_SBins_v6_CD_EW_50bin_elec1->Fill(sBin6_50bin,wt*prob0);
	      h_MET->Fill(MET,wt*prob0);
	      h_METvBin2->Fill(MET,wt*prob0);
	      h_nJets->Fill(nHadJets,wt*prob0);
	      h_ST->Fill(ST,wt*prob0);
	      if(savePDFscaleUnc){
		for(int si=0;si<ScaleWeights->size();si++)
		  h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt*prob0*(*ScaleWeights)[si]);
		for(int si=0;si<PDFweights->size();si++)
                  h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt*prob0*(*PDFweights)[si]);
	      }
	      else
		{
		  for(int si=0;si<11;si++)
		    h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt*prob0);
		  for(int si=0;si<111;si++)
		    h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt*prob0);
		}

              nbjets=1;
              sBin6 = getBinNoV7_le(nbjets,nHadJets);
              h_SBins_v6_CD_elec1->Fill(sBin6,wt*prob1);
	      sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v7_CD_SP_elec1->Fill(sBin7_SP_elec1,wt*prob1);
              sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v6_CD_EW_50bin_elec1->Fill(sBin6_50bin,wt*prob1);
              h_MET->Fill(MET,wt*prob1);
              h_METvBin2->Fill(MET,wt*prob1);
              h_nJets->Fill(nHadJets,wt*prob1);
              h_ST->Fill(ST,wt*prob1);
              if(savePDFscaleUnc){
                for(int si=0;si<ScaleWeights->size();si++)
                  h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt*prob1*(*ScaleWeights)[si]);
		for(int si=0;si<PDFweights->size();si++)
                  h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt*prob1*(*PDFweights)[si]);
              }
              else
                {
                  for(int si=0;si<11;si++)
                    h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt*prob1);
                  for(int si=0;si<111;si++)
                    h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt*prob1);
                }

	      h_BTags->Fill(0.0,wt*prob[0]);
	      h_BTags->Fill(1.0,wt*prob[1]);
	      h_BTags->Fill(2.0,wt*prob[2]);
	      h_BTags->Fill(3.0,wt*prob[3]);
	      nbjets=nbjets_org;
	    }
	    else 
	      {
		sBin6 = getBinNoV7_le(nbjets,nHadJets);
		h_SBins_v6_CD_elec1->Fill(sBin6,wt);
		sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v7_CD_SP_elec1->Fill(sBin7_SP_elec1,wt);
		sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
		h_SBins_v6_CD_EW_50bin_elec1->Fill(sBin6_50bin,wt);
		h_MET->Fill(MET,wt);
		h_METvBin2->Fill(MET,wt);
		h_nJets->Fill(nHadJets,wt);
		h_ST->Fill(ST,wt);
		h_BTags->Fill(nbjets,wt);
		if(savePDFscaleUnc){
		  for(int si=0;si<11;si++)
		    h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt*(*ScaleWeights)[si]);
		  for(int si=0;si<111;si++)
		    h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt*(*PDFweights)[si]);
		}
		else
		  {
		    for(int si=0;si<11;si++)
		      h_SBins_v7_CD_SP_scale_elec1->Fill(sBin7_SP_elec1,si,wt);
		    for(int si=0;si<111;si++)
		      h_SBins_v7_CD_SP_pdf_elec1->Fill(sBin7_SP_elec1,si,wt);
		  }
	      }
            h_DBTags->Fill(abs(nbjets-BTags),wt);
	    h_minDr_bestphoEle->Fill(bestPhoton.DeltaR((*Electrons)[e_index]),wt);
	    h_minDr_bestphoJets->Fill(MinDr(bestPhoton,hadJets),wt);
	    h_mTPhoMET->Fill(mTPhoMET,wt); 
            h_minDr_EleJets->Fill(MinDr((*Electrons)[e_index],hadJets),wt);
	    if(!s_data.Contains("data")) {h_mindr_genph_lep->Fill(MinDr(bestPhoton,v_genLep2),wt);
                h_mindr_lep_goodph->Fill(MinDr(bestPhoton,v_genEle2),wt);}		
            dPhi_phoMET = abs(DeltaPhi(bestPhoton.Phi(),METPhi));
            h2_MET_dPhiMETj->Fill(MET,mindphi,wt);
            h2_MET_dPhiMETj1->Fill(MET,dPhi_METjet1,wt);
            h2_MET_dPhiMETj2->Fill(MET,dPhi_METjet2,wt);


            if(hadJets.size() > 0)
              {
                dPhi_METjet1 = (DeltaPhi(METPhi,(hadJets)[0].Phi()));
                dPhi_phojet1 = (DeltaPhi(bestPhoton.Phi(),hadJets[0].Phi()));
                h_dPhi_phojet1->Fill(dPhi_phojet1,wt);
                h_dPhi_METjet1->Fill(dPhi_METjet1,wt);
                h_minDr_Elejet1->Fill((*Electrons)[e_index].DeltaR(hadJets[0]),wt);
                h2_dPhivseta_jet1->Fill(dPhi_METjet1,hadJets[0].Eta(),wt);
                h2_Phivseta_jet1->Fill(hadJets[0].Phi(),hadJets[0].Eta(),wt);
              }

            if(hadJets.size() > 1)
              {
                dPhi_METjet2 = (DeltaPhi(METPhi,(hadJets)[1].Phi()));
                dPhi_phojet2 = (DeltaPhi(bestPhoton.Phi(),hadJets[1].Phi()));
                h_dPhi_phojet2->Fill(dPhi_phojet2,wt);
                h_dPhi_METjet2->Fill(dPhi_METjet2,wt);
                h_minDr_Elejet2->Fill((*Electrons)[e_index].DeltaR(hadJets[1]),wt);
                h2_dPhivseta_jet2->Fill(dPhi_METjet2,hadJets[1].Eta(),wt);
                h2_Phivseta_jet2->Fill(hadJets[1].Phi(),hadJets[1].Eta(),wt);
              }
            if(hadJets.size() > 2)
              {
                dPhi_METjet3 = (DeltaPhi(METPhi,(hadJets)[2].Phi()));
                dPhi_phojet3 = (DeltaPhi(bestPhoton.Phi(),hadJets[2].Phi()));

                h_dPhi_phojet3->Fill(dPhi_phojet3,wt);
                h_dPhi_METjet3->Fill(dPhi_METjet3,wt);
                h_minDr_Elejet3->Fill((*Electrons)[e_index].DeltaR(hadJets[2]),wt);
                h2_dPhivseta_jet3->Fill(dPhi_METjet3,hadJets[2].Eta(),wt);
                h2_Phivseta_jet3->Fill(hadJets[2].Phi(),hadJets[2].Eta(),wt);
              }
            if(hadJets.size() > 3)
              {
                dPhi_METjet4 = (DeltaPhi(METPhi,(hadJets)[3].Phi()));
                dPhi_phojet4 = (DeltaPhi(bestPhoton.Phi(),hadJets[3].Phi()));

                h_dPhi_phojet4->Fill(dPhi_phojet4,wt);
                h_dPhi_METjet4->Fill(dPhi_METjet4,wt);
                h_minDr_Elejet4->Fill((*Electrons)[e_index].DeltaR(hadJets[3]),wt);
                h2_dPhivseta_jet4->Fill(dPhi_METjet4,hadJets[3].Eta(),wt);
                h2_Phivseta_jet4->Fill(hadJets[3].Phi(),hadJets[3].Eta(),wt);
              }

	    h_dPhi_phoMET->Fill(dPhi_phoMET,wt);

	    h_BestPhotonPt_vBin->Fill(bestPhoton.Pt(),wt);    
	    h_BestPhotonPt->Fill(bestPhoton.Pt(),wt);    
	    h_BestPhotonPhi->Fill(bestPhoton.Phi(),wt);
	    h_BestPhotonEta->Fill(bestPhoton.Eta(),wt);
	    if(nbjets == 0)
	      {
		h_BestPhotonPt_0b->Fill(bestPhoton.Pt(),wt);    
		h_BestPhotonPt_0b_vBin->Fill(bestPhoton.Pt(),wt);    
	      }
	    if(nbjets > 0)
	      {
		h_BestPhotonPt_ge1b->Fill(bestPhoton.Pt(),wt);    
		h_BestPhotonPt_ge1b_vBin->Fill(bestPhoton.Pt(),wt);    
	      }
	    
	    if(elec)
	      {
		for(int j=0; j<Electrons->size();j++){
		  h_ElectronPt->Fill((*Electrons)[j].Pt(),wt);
		  h_ElectronEta->Fill((*Electrons)[j].Eta(),wt);
		  h_ElectronPhi->Fill((*Electrons)[j].Phi(),wt);
		  h2_ElectronEta_Phi->Fill((*Electrons)[j].Eta(),(*Electrons)[j].Phi(),wt);
		}
	      }

	    for(int j=0; j<hadJets.size();j++){ 
	      h_JetPt->Fill(hadJets[j].Pt(),wt);
	      h_JetEta->Fill(hadJets[j].Eta(),wt);
	      h_JetPhi->Fill(hadJets[j].Phi(),wt);
              h2_JetEta_Phi->Fill(hadJets[j].Eta(),hadJets[j].Phi(),wt);
	      h2_BestPhotonPt_jetphoratio->Fill(bestPhoton.Pt(),hadJets[j].Pt()/bestPhoton.Pt(),wt);
	    }
	  
	    h2_PtPhotonvsMET->Fill(bestPhoton.Pt(),MET,wt);
	    h_PhovBin->Fill(bestPhoton.Pt(),wt);
	    h_PhovBin1->Fill(bestPhoton.Pt(),wt);
	    h_PhovBin2->Fill(bestPhoton.Pt(),wt);
	    h_hadAk8Mass->Fill(Ak8Mass,wt);
	    if(hadAK8Jets.size() > 0)  h_hadAk8jetPt->Fill(hadAK8Jets[0].Pt(),wt);
	    h_hadAk8Mass_vBin->Fill(Ak8Mass,wt);
	    h_intLumi->Fill(lumiInfb,wt);


      
	    h2_BestPhotonPt_jetmatchphoratio->Fill(bestPhoton.Pt(),(*Jets)[photonMatchingJetIndx].Pt()/bestPhoton.Pt(),wt);
	    if(elec)
	      {
		h_leadElectronPhi->Fill((*Electrons)[e_index].Phi(),wt);
		h_leadElectronEta->Fill((*Electrons)[e_index].Eta(),wt);
		h_leadElectronPt->Fill((*Electrons)[e_index].Pt(),wt);
		h2_leadElectronEta_Phi->Fill((*Electrons)[e_index].Eta(),(*Electrons)[e_index].Phi(),wt);
		//		double dPhi_METlep1 = abs(DeltaPhi(METPhi,(*Electrons)[e_index].Phi()));
		//h_dPhi_METlep1->Fill(dPhi_METlep1,wt);
	      }

	    if(hadJets.size()>0){
	      h2_leadJetEta_Phi->Fill(hadJets[0].Eta(),hadJets[0].Phi(),wt);
	      h_leadJetPhi->Fill(hadJets[0].Phi(),wt);
	      h_leadJetEta->Fill(hadJets[0].Eta(),wt);
	      h_leadJetPt->Fill(hadJets[0].Pt(),wt);
	      h2_leadJetEta_Pt->Fill(hadJets[0].Eta(),hadJets[0].Pt(),wt);

	    }
            h_MET_CaloMET->Fill(MET/CaloMET,wt);
            h_dPhi_MET_CaloMET->Fill(abs(DeltaPhi(METPhi,CaloMETPhi)),wt);
            h_HT5HT->Fill(HT5/HT,wt);
	    
	    if(process && EWselection && (EWselec && EWselec1))
	      {
		EW_evtSurvived++;
		h_BestPhotonPt_EW->Fill(bestPhoton.Pt(),wt);
		h_MET_EW->Fill(MET,wt);
		h_nJets_EW->Fill(nHadJets,wt);
		h_METvBin_EW->Fill(MET,wt);
		h_METvBin_EW_v1->Fill(MET,wt);
		h_METvBin_EW_v2->Fill(MET,wt);
		h_ST_EW->Fill(ST,wt);
		h_BTags_EW->Fill(nbjets,wt);
		h_intLumi_EW->Fill(lumiInfb,wt);
		h_hadAk8Mass_EW->Fill(Ak8Mass,wt);
		h_hadAk8Mass_EW_vBin->Fill(Ak8Mass,wt);
		if(elec) h_minDr_bestphoEle_EW->Fill(MinDr(bestPhoton,*Electrons),wt);
                if(muon) h_minDr_bestphoEle_EW->Fill(MinDr(bestPhoton,*Muons),wt);
		h_minDr_bestphoJets_EW->Fill(MinDr(bestPhoton,hadJets),wt);
	      }
	    if(process && EWselection && !(EWselec && EWselec1))
	      {
		SP_evtSurvived++;
		h_BestPhotonPt_SP->Fill(bestPhoton.Pt(),wt);
		h_MET_SP->Fill(MET,wt);
		h_METvBin_SP->Fill(MET,wt);
		h_METvBin_SP_v1->Fill(MET,wt);
		h_METvBin_SP_v2->Fill(MET,wt);
		h_nJets_SP->Fill(nHadJets,wt);
		h_ST_SP->Fill(ST,wt);
		h_BTags_SP->Fill(nbjets,wt);
		h_intLumi_SP->Fill(lumiInfb,wt);
		h_hadAk8Mass_SP->Fill(Ak8Mass,wt);
		h_hadAk8Mass_SP_vBin->Fill(Ak8Mass,wt);
                if(elec) h_minDr_bestphoEle_SP->Fill(MinDr(bestPhoton,*Electrons),wt);
                if(muon) h_minDr_bestphoEle_SP->Fill(MinDr(bestPhoton,*Muons),wt);
		h_minDr_bestphoJets_SP->Fill(MinDr(bestPhoton,hadJets),wt);
	      }

	    
	    ////////////////////////// for reweighting the CR region events with Transfer factors //////////////////////

	    if(Tf=="sBin6_SP")
	      {
	    	if(!(EWselec && EWselec1)){
	    	  if(nbjets==0){
	    	    if(nHadJets==2)     { wt2=wt*tf_SP->GetBinContent(1);}
	    	    else if(nHadJets==3)     { wt2=wt*tf_SP->GetBinContent(2);}
	    	    else if(nHadJets==4)     { wt2=wt*tf_SP->GetBinContent(3);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP->GetBinContent(4);}
	    	    else if(nHadJets>=7)   { wt2=wt*tf_SP->GetBinContent(5);}
	    	  }
	    	  else{
	    	    if(nHadJets>=2 && nHadJets<=4)      { wt2=wt*tf_SP->GetBinContent(6);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP->GetBinContent(7);}
	    	    else if(nHadJets>=7)   { wt2=wt*tf_SP->GetBinContent(8);}
	    	  }
	    	}
	    	if((EWselec && EWselec1)){
	    	  if(nbjets==0){
	    	    if(nHadJets>=2 && nHadJets<=4)     { wt2=wt*tf_SP->GetBinContent(9);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP->GetBinContent(10);}
	    	  }
	    	  else{
	    	    if(nHadJets>=2 && nHadJets<=4)      { wt2=wt*tf_SP->GetBinContent(11);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP->GetBinContent(12);}
	    	  }

	    	}
	      }
	    if(Tf=="sBin7_SP")
	      {
	    	if(!(EWselec && EWselec1)){
	    	  if(nbjets==0){
	    	    if(nHadJets==2)     { wt2=wt*tf_SP_2->GetBinContent(1);}
	    	    else if(nHadJets==3)     { wt2=wt*tf_SP_2->GetBinContent(2);}
	    	    else if(nHadJets==4)     { wt2=wt*tf_SP_2->GetBinContent(3);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP_2->GetBinContent(4);}
	    	    else if(nHadJets>=7)   { wt2=wt*tf_SP_2->GetBinContent(5);}
	    	  }
	    	  else{
	    	    if(nHadJets>=2 && nHadJets<=4)      { wt2=wt*tf_SP_2->GetBinContent(6);}
	    	    else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf_SP_2->GetBinContent(7);}
	    	    else if(nHadJets>=7)   { wt2=wt*tf_SP_2->GetBinContent(8);}
	    	  }
	    	}
	    	if((EWselec && EWselec1)){
	    	    if(EWselec_Wtag)     { wt2=wt*tf_SP_2->GetBinContent(9);}
	    	    if(EWselec_Htag)      { wt2=wt*tf_SP_2->GetBinContent(10);}
	    	  }
	      }
	    
	    if(Tf=="nHadJets")
	      {
		for(int i=0;i<tf_SP_2->GetXaxis()->GetNbins();i++)
		  if(tf_SP_2->GetBinLowEdge(i)==nHadJets)
		    {
		      //		      cout<<jentry<<" : nHadJets = "<<nHadJets<<" : X bin content = "<<tf_SP_2->GetBinLowEdge(i)<<" : Y bin content = "<<tf_SP_2->GetBinContent(i)<<endl;
		      wt2=wt*tf_SP_2->GetBinContent(i);
		    }
	      }

 	    if(Tf=="MET")
	      {
		for(int i=0;i<tf_SP_2->GetXaxis()->GetNbins();i++)
		  if(MET >= tf_SP_2->GetBinLowEdge(i) && MET < (tf_SP_2->GetBinLowEdge(i)+tf_SP_2->GetBinWidth(i)) )
		    {
		      cout<<jentry<<" : MET = "<<MET<<" : X bin content = "<<tf_SP_2->GetBinLowEdge(i)<<" : Y bin content = "<<tf_SP_2->GetBinContent(i)<<endl;
		      wt2=wt*tf_SP_2->GetBinContent(i);
		    }
	      }

	    if(Tf=="METvBin2")
	      {
		for(int i=1;i<=tf_SP_2->GetXaxis()->GetNbins();i++)
		  if(MET >= tf_SP_2->GetBinLowEdge(i) && MET < (tf_SP_2->GetBinLowEdge(i)+tf_SP_2->GetBinWidth(i)) )
		    {
		      //		      cout<<jentry<<" : MET = "<<MET<<" : X bin content = "<<tf_SP_2->GetBinLowEdge(i)<<" - "<<tf_SP_2->GetBinLowEdge(i)+tf_SP_2->GetBinWidth(i)<<" : Y bin content = "<<tf_SP_2->GetBinContent(i)<<endl;
		      wt2=wt*tf_SP_2->GetBinContent(i);
		    }
	      }
	    
	    
	    
	    if(Tf=="sBin6")
	      {	      
	    	if(nbjets==0){
	    	  if(nHadJets==2)     { wt2=wt*tf->GetBinContent(1); }
	    	  else if(nHadJets==3)     { wt2=wt*tf->GetBinContent(2);}
	    	  else if(nHadJets==4)     { wt2=wt*tf->GetBinContent(3);}
	    	  else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf->GetBinContent(4);}
	    	  else if(nHadJets>=7)   { wt2=wt*tf->GetBinContent(5);}
	    	}
	    	else{
	    	  if(nHadJets>=2 && nHadJets<=4)      { wt2=wt*tf->GetBinContent(6);}
	    	  else if((nHadJets==5 || nHadJets==6)){ wt2=wt*tf->GetBinContent(7);}
	    	  else if(nHadJets>=7)   { wt2=wt*tf->GetBinContent(8);}
	    	}

	      }

	    if(Tf=="sBin7_SP_tmp")
	      {

		if(nHadJets>=2 && nHadJets<=3)
		  {
		    if(nbjets==0) wt2=wt*tf_SP_3->GetBinContent(1);
		    else if(nbjets==1) wt2=wt*tf_SP_3->GetBinContent(2);
		    else wt2=wt*tf_SP_3->GetBinContent(3);
		  }
		else if(nHadJets>=4 && nHadJets<=5)
		  {
		    if(nbjets==0) wt2=wt*tf_SP_3->GetBinContent(4);
		    else if(nbjets==1) wt2=wt*tf_SP_3->GetBinContent(5);
		    else if(nbjets==2) wt2=wt*tf_SP_3->GetBinContent(6);
		    else wt2=wt*tf_SP_3->GetBinContent(7);
		  }
		else if(nHadJets>=6 && nHadJets<=7)
		  {
		    if(nbjets==0) wt2=wt*tf_SP_3->GetBinContent(8);
		    else if(nbjets==1) wt2=wt*tf_SP_3->GetBinContent(9);
		    else if(nbjets==2) wt2=wt*tf_SP_3->GetBinContent(10);
		    else wt2=wt*tf_SP_3->GetBinContent(11);
		  }
		else if(nHadJets>=8 && nHadJets<=9)
		  {
		    if(nbjets==0) wt2=wt*tf_SP_3->GetBinContent(12);
		    else if(nbjets==1) wt2=wt*tf_SP_3->GetBinContent(13);
		    else if(nbjets==2) wt2=wt*tf_SP_3->GetBinContent(14);
		    else wt2=wt*tf_SP_3->GetBinContent(15);
		  }
		else
		  {
		    if(nbjets==0) wt2=wt*tf_SP_3->GetBinContent(16);
		    else if(nbjets==1) wt2=wt*tf_SP_3->GetBinContent(17);
		    else if(nbjets==2) wt2=wt*tf_SP_3->GetBinContent(18);
		    else wt2=wt*tf_SP_3->GetBinContent(19);
		  }		
	      }
	    if(EWKsub)
	      {
		if(!(EWselec && EWselec1)){
		  if(nbjets==0){
		    if(nHadJets>=2 && nHadJets<=4 && MET<=300)     { wt2=wt2*mj_wt->GetBinContent(2);}
		    else if(nHadJets>=2 && nHadJets<=4 && MET>300)     { wt2=wt2*mj_wt->GetBinContent(3);}
		    else if((nHadJets==5 || nHadJets==6) && MET<=300){ wt2=wt2*mj_wt->GetBinContent(9);}
		    else if((nHadJets==5 || nHadJets==6) && MET>300){ wt2=wt2*mj_wt->GetBinContent(10);}
		    else if(nHadJets>=7  && MET<=300)   { wt2=wt2*mj_wt->GetBinContent(15);}
		    else if(nHadJets>=7 && MET>300)   { wt2=wt2*mj_wt->GetBinContent(16);}
		  }
		  else{
		    if(nHadJets>=2 && nHadJets<=4 && MET<=300)      { wt2=wt2*mj_wt->GetBinContent(20);}
		    else if(nHadJets>=2 && nHadJets<=4 && MET>300)      { wt2=wt2*mj_wt->GetBinContent(21);}
		    else if((nHadJets==5 || nHadJets==6) && MET<=300){ wt2=wt2*mj_wt->GetBinContent(25);}
		    else if((nHadJets==5 || nHadJets==6) && MET>300){ wt2=wt2*mj_wt->GetBinContent(26);}
		    else if(nHadJets>=7 && MET<=300)   { wt2=wt2*mj_wt->GetBinContent(30);}
		    else if(nHadJets>=7 && MET>300)   { wt2=wt2*mj_wt->GetBinContent(31);}
		  }
		}
		else if((EWselec && EWselec1)){
		  if(EWselec_Wtag && !EWselec_Htag && MET<=300)     { wt2=wt2*mj_wt->GetBinContent(35);}
		  else if(EWselec_Wtag && !EWselec_Htag && MET>300)     { wt2=wt2*mj_wt->GetBinContent(36);}
		  else if(EWselec_Htag && !EWselec_Wtag  && MET<=300)      { wt2=wt2*mj_wt->GetBinContent(41);}
		  else if(EWselec_Htag && !EWselec_Wtag && MET>300)      { wt2=wt2*mj_wt->GetBinContent(42);}                                                               
		}
	      }

	 
	    int sBin6_closure = getBinNoV7_le(nbjets,nHadJets);
	    // h_SBins_v6_CD_elec1_closure->Fill(sBin6_closure,wt2);
            int sBin6_SP_elec1_closure = getBinNoV6(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
            //h_SBins_v6_CD_SP_elec1_closure->Fill(sBin6_SP_elec1_closure,wt2);
            int sBin7_SP_elec1_closure = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	    // h_SBins_v7_CD_SP_elec1_closure->Fill(sBin7_SP_elec1_closure,wt2);
            int sBin6_50bin_closure= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
	    // h_SBins_v6_CD_EW_50bin_elec1_closure->Fill(sBin6_50bin_closure,wt2);
	    double wtb=wt2;
	    nbjets_org=nbjets;
            if(applybTagSFs  && s_data.Contains("v17") && !s_data.Contains("data")){
              
	      nbjets=0;
	      if(!(EWselec && EWselec1)){	
	      if(nHadJets==	2)     { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(1)*mj_wt->GetBinContent(2);} else {wt2=wt*tf_SP_2->GetBinContent(1)*mj_wt->GetBinContent(3);} }
	      else if(nHadJets==3)  { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(2)*mj_wt->GetBinContent(2);} else {wt2=wt*tf_SP_2->GetBinContent(2)*mj_wt->GetBinContent(3);}}
	      else if(nHadJets==4)  { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(3)*mj_wt->GetBinContent(2);} else {wt2=wt*tf_SP_2->GetBinContent(3)*mj_wt->GetBinContent(3);}}
	      else if((nHadJets==5 || nHadJets==6)){ if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(4)*mj_wt->GetBinContent(9);} else {wt2=wt*tf_SP_2->GetBinContent(4)*mj_wt->GetBinContent(10);}}
	      else if(nHadJets>=7)   { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(5)*mj_wt->GetBinContent(15);} else {wt2=wt*tf_SP_2->GetBinContent(5)*mj_wt->GetBinContent(16);}}
	      }
	      else wt2=wtb;
	      sBin7_SP_elec1_closure = getBinNoV7(nbjets,nHadJets);
	      h_SBins_v7_CD_SP_tmp_elec1_closure->Fill(sBin7_SP_elec1_closure,wt2*prob0);
              sBin6 = getBinNoV7_le(nbjets,nHadJets);
              h_SBins_v6_CD_elec1_closure->Fill(sBin6,wt2*prob0);
              sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v7_CD_SP_elec1_closure->Fill(sBin7_SP_elec1,wt2*prob0);
              sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v6_CD_EW_50bin_elec1_closure->Fill(sBin6_50bin,wt2*prob0);
              h_MET_elec1_closure->Fill(MET,wt2*prob0);
              h_METvBin2_elec1_closure->Fill(MET,wt2*prob0);
              h_nJets_elec1_closure->Fill(nHadJets,wt2*prob0);
	      h_ST_elec1_closure->Fill(ST,wt2*prob0);
            
              nbjets=1;
	      if(!(EWselec && EWselec1)){	
		if(nHadJets>=2 && nHadJets<=4)      { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(6)*mj_wt->GetBinContent(20);} else {wt2=wt*tf_SP_2->GetBinContent(6)*mj_wt->GetBinContent(21);}}
		else if((nHadJets==5 || nHadJets==6)){ if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(7)*mj_wt->GetBinContent(25);} else {wt2=wt*tf_SP_2->GetBinContent(7)*mj_wt->GetBinContent(26);}}
		else if(nHadJets>=7)   { if(MET<=300) {wt2=wt*tf_SP_2->GetBinContent(8)*mj_wt->GetBinContent(30);} else {wt2=wt*tf_SP_2->GetBinContent(8)*mj_wt->GetBinContent(31);}}
	      }
	      else wt2=wtb;
	      sBin7_SP_elec1_closure = getBinNoV7(nbjets,nHadJets);
	      h_SBins_v7_CD_SP_tmp_elec1_closure->Fill(sBin7_SP_elec1_closure,wt2*prob1);
              sBin6 = getBinNoV7_le(nbjets,nHadJets);
              h_SBins_v6_CD_elec1_closure->Fill(sBin6,wt2*prob1);
              sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v7_CD_SP_elec1_closure->Fill(sBin7_SP_elec1,wt2*prob1);
              sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v6_CD_EW_50bin_elec1_closure->Fill(sBin6_50bin,wt2*prob1);
              h_MET_elec1_closure->Fill(MET,wt2*prob1);
              h_METvBin2_elec1_closure->Fill(MET,wt2*prob1);
              h_nJets_elec1_closure->Fill(nHadJets,wt2*prob1);
              h_ST_elec1_closure->Fill(ST,wt2*prob1);
	      nbjets=nbjets_org;

	    }

	    else{
	      sBin7_SP_elec1_closure = getBinNoV7(nbjets,nHadJets);
              h_SBins_v7_CD_SP_tmp_elec1_closure->Fill(sBin7_SP_elec1_closure,wt2);
              sBin6 = getBinNoV7_le(nbjets,nHadJets);
              h_SBins_v6_CD_elec1_closure->Fill(sBin6,wt2);
              sBin7_SP_elec1 = getBinNoV7_le2(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v7_CD_SP_elec1_closure->Fill(sBin7_SP_elec1,wt2);
              sBin6_50bin= getBinNoV6_EWplusSP_CR(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
              h_SBins_v6_CD_EW_50bin_elec1_closure->Fill(sBin6_50bin,wt2);
              h_MET_elec1_closure->Fill(MET,wt2);
              h_METvBin2_elec1_closure->Fill(MET,wt2);
              h_nJets_elec1_closure->Fill(nHadJets,wt2);
              h_ST_elec1_closure->Fill(ST,wt2);
	      nbjets_org=nbjets_org;
	    }

	    h2_njetnbjet_phopt_vBin_elec1_closure->Fill(sBin7_SP_elec1_closure,bestPhoton.Pt(),wt2);
	    h2_njetnbjet_phopt_elec1_closure->Fill(sBin7_SP_elec1_closure,bestPhoton.Pt(),wt2);

	    h2_MET_nJets_elec1_closure->Fill(nHadJets,MET,wt2);
	    h2_METvBin2_nJets_elec1_closure->Fill(nHadJets,MET,wt2);
	    h2_nbjets_nJets_elec1_closure->Fill(nHadJets,nbjets,wt2);
	    /*
	    h_MET_elec1_closure->Fill(MET,wt2);
	    h_METvBin2_elec1_closure->Fill(MET,wt2);
	    h_nJets_elec1_closure->Fill(nHadJets,wt2);
	    h_ST_elec1_closure->Fill(ST,wt2);
	    */
	    h_BTags_elec1_closure->Fill(nbjets,wt2);
            h_DBTags_elec1_closure->Fill(abs(nbjets-BTags),wt2);
	    h_minDr_bestphoEle_elec1_closure->Fill(MinDr(bestPhoton,*Electrons),wt2);
	    h_minDr_bestphoJets_elec1_closure->Fill(MinDr(bestPhoton,hadJets),wt2);

	    h_hadAk8Mass_elec1_closure->Fill(Ak8Mass,wt2);
	    if(hadAK8Jets.size() > 0) h_hadAk8jetPt_elec1_closure->Fill(hadAK8Jets[0].Pt(),wt2);
	    
            if((EWselec && EWselec1)) {
	      h_hadAk8Mass_EW_elec1_closure->Fill(Ak8Mass,wt2);
	      if(hadAK8Jets.size() > 0) h_hadAk8jetPt_EW_elec1_closure->Fill(hadAK8Jets[0].Pt(),wt2);
              h_MET_EW_elec1_closure->Fill(MET,wt2);
              h_nJets_EW_elec1_closure->Fill(nHadJets,wt2);
	      h_ST_EW_elec1_closure->Fill(ST,wt2);
	      h_BestPhotonPt_EW_elec1_closure->Fill(bestPhoton.Pt(),wt2);
	      h_BTags_EW_elec1_closure->Fill(nbjets,wt2);

	    }
	    
	    else
	      {
		h_hadAk8Mass_SP_elec1_closure->Fill(Ak8Mass,wt2);
		if(hadAK8Jets.size() > 0)  h_hadAk8jetPt_SP_elec1_closure->Fill(hadAK8Jets[0].Pt(),wt2);
		h_MET_SP_elec1_closure->Fill(MET,wt2);
		h_nJets_SP_elec1_closure->Fill(nHadJets,wt2);
		h_ST_SP_elec1_closure->Fill(ST,wt2);
		h_BestPhotonPt_SP_elec1_closure->Fill(bestPhoton.Pt(),wt2);
		h_BTags_SP_elec1_closure->Fill(nbjets,wt2);	      
	      }
	   
	    h_BestPhotonPt_vBin_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
	    h_BestPhotonPt_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
	    h_BestPhotonPhi_elec1_closure->Fill(bestPhoton.Phi(),wt2);
	    h_BestPhotonEta_elec1_closure->Fill(bestPhoton.Eta(),wt2);
	    h2_MET_dPhiMETj_elec1_closure->Fill(MET,mindphi,wt2);
	    h2_MET_dPhiMETj1_elec1_closure->Fill(MET,dPhi_METjet1,wt2);
	    h2_MET_dPhiMETj2_elec1_closure->Fill(MET,dPhi_METjet2,wt2);

	    if(nbjets == 0)
	      {
		h_BestPhotonPt_0b_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
		h_BestPhotonPt_0b_vBin_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
	      }
	    if(nbjets > 0)
	      {
		h_BestPhotonPt_ge1b_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
		h_BestPhotonPt_ge1b_vBin_elec1_closure->Fill(bestPhoton.Pt(),wt2);    
	      }
	    if(elec)
	      {
		for(int j=0; j<Electrons->size();j++){
		  h_ElectronPt_elec1_closure->Fill((*Electrons)[j].Pt(),wt2);
		  h_ElectronEta_elec1_closure->Fill(abs((*Electrons)[j].Eta()),wt2);
		  h_ElectronPhi_elec1_closure->Fill(abs((*Electrons)[j].Phi()),wt2);
		}
	      }
	    if(muon)
	      {
		for(int j=0; j<Muons->size();j++){
		  h_ElectronPt_elec1_closure->Fill((*Muons)[j].Pt(),wt2);
		  h_ElectronEta_elec1_closure->Fill((*Muons)[j].Eta(),wt2);
		  h_ElectronPhi_elec1_closure->Fill((*Muons)[j].Phi(),wt2);
		}
	      }
	    for(int j=0; j<hadJets.size();j++){ 
	      h_JetPt_elec1_closure->Fill(hadJets[j].Pt(),wt2);
	      h_JetEta_elec1_closure->Fill(abs(hadJets[j].Eta()),wt2);
	      h_JetPhi_elec1_closure->Fill(abs(hadJets[j].Phi()),wt2);
	    }
	    h_mTPhoMET_elec1_closure->Fill(mTPhoMET,wt2); 
	    h_dPhi_METjet1_elec1_closure->Fill(dPhi_METjet1,wt2);
	    h_dPhi_METjet2_elec1_closure->Fill(dPhi_METjet2,wt2);
	    h_dPhi_phojet1_elec1_closure->Fill(dPhi_phojet1,wt2);
	    h_dPhi_phojet2_elec1_closure->Fill(dPhi_phojet2,wt2);
	    h_dPhi_phoMET_elec1_closure->Fill(dPhi_phoMET,wt2);
	    if(Electrons->size()>0)
	      h2_leadElectronEta_Phi_elec1_closure->Fill((*Electrons)[0].Eta(),(*Electrons)[0].Phi(),wt2);
	    if(hadJets.size()>0){
	      h2_leadJetEta_Phi_elec1_closure->Fill(hadJets[0].Eta(),hadJets[0].Phi(),wt2);
	      h_leadJetPhi_elec1_closure->Fill(abs(hadJets[0].Phi()),wt2);
	      h_leadJetEta_elec1_closure->Fill(abs(hadJets[0].Eta()),wt2);
	      h_leadJetPt_elec1_closure->Fill(hadJets[0].Pt(),wt2);
	    }	  
	    if(elec)
              {
                h_leadElectronPhi_elec1_closure->Fill((*Electrons)[e_index].Phi(),wt);
                h_leadElectronEta_elec1_closure->Fill((*Electrons)[e_index].Eta(),wt);
                h_leadElectronPt_elec1_closure->Fill((*Electrons)[e_index].Pt(),wt);
                h2_leadElectronEta_Phi_elec1_closure->Fill((*Electrons)[e_index].Eta(),(*Electrons)[e_index].Phi(),wt);
		// double dPhi_METlep1 = abs(DeltaPhi(METPhi,(*Electrons)[e_index].Phi()));
		// h_dPhi_METlep1_elec1_closure->Fill(dPhi_METlep1,wt);
              }
            if(muon)
              {
                h_leadElectronPhi_elec1_closure->Fill((*Muons)[e_index].Phi(),wt);
                h_leadElectronEta_elec1_closure->Fill((*Muons)[e_index].Eta(),wt);
                h_leadElectronPt_elec1_closure->Fill((*Muons)[e_index].Pt(),wt);
                h2_leadElectronEta_Phi_elec1_closure->Fill((*Muons)[e_index].Eta(),(*Muons)[e_index].Phi(),wt);
		// double dPhi_METlep1 = abs(DeltaPhi(METPhi,(*Muons)[e_index].Phi()));
		//h_dPhi_METlep1_elec1_closure->Fill(dPhi_METlep1,wt);
              }


	  }
      }

    bool acceptance=true,id=false,id2=false,iso=true,cr=true,sr=true;      
    int idx=-9,id2x=-9;
    int sbin = getBinNoV7_le3(EWselec,EWselec1 ,EWselec_Htag,EWselec_Wtag,nbjets,nHadJets);
    if(Electrons->size()>=0)
      {
	vector<TLorentzVector> v_Electrons;
	//if(NElectrons==1){
	for(int i=0 ; i<Electrons->size() ; i++)
	  {
	    if((*Electrons)[i].Pt()>10 && abs((*Electrons)[i].Eta())<2.5)
	      v_Electrons.push_back((*Electrons)[i]);
	  }
	
	
	h_SBins_v6_CD_elec1_tot->Fill(sbin,wt);
        if(acceptance && ((v_genEle2.size()>0 && v_genEle2[0].Pt()>10 && abs(v_genEle2[0].Eta())<2.5)|| (v_genEle2.size()>1 && v_genEle2[1].Pt()>10 && abs(v_genEle2[1].Eta())<2.5))) {pass_acceptance++;acceptance=true;}
        else {acceptance=false;
          if((nGenMu1==0 && nGenEle1==0  && nGentau_had1 > 0)) {pass_hadtau++; h_SBins_v6_CD_elec0_hadtau->Fill(sbin,wt);}
          else {fail_acceptance++; acceptance=false; h_SBins_v6_CD_elec0_acc->Fill(sbin,wt); }
        }

        if(acceptance){
          h_SBins_v6_CD_elec1_acc->Fill(sbin,wt);
          id=false;
          double mindr_=100;
          if(NElectrons==1 && v_genEle2.size()==1  && MinDr(v_genEle2[0],v_Electrons)<0.2) {id=true; pass_id++; h_SBins_v6_CD_elec1_id->Fill(sbin,wt);}
          else if(NElectrons==1 && v_genEle2.size()==2 && (MinDr(v_genEle2[1],v_Electrons)<0.2|| MinDr(v_genEle2[0],v_Electrons)<0.2)) {id=true; pass_id++; h_SBins_v6_CD_elec1_id->Fill(sbin,wt);}
          else {
            if((nGenMu1==0 && nGenEle1==0  && nGentau_had1 > 0)) {pass_hadtau++; h_SBins_v6_CD_elec0_hadtau->Fill(sbin,wt);}
            else {fail_id++;  h_SBins_v6_CD_elec0_id->Fill(sbin,wt); }
          }
	}
      }
    

    
                                                    
  }  // loop over entries
  cout<<"Cross-section : "<<CrossSection<<endl;
  cout<<"Weight ib pb-1 : "<<Weight<<endl;
    
  cout<<"Events Survived after PreSelection : "<<evtSurvived_preselec<<endl;
  cout<<"Events Survived before genphomatch : "<<genphomatch_before<<endl;
  cout<<"Events Survived after genphomatch : "<<genphomatch_after<<endl;
  cout<<"=========for NElectron = 1 ========"<<endl;
  cout<<"Events having NElectrons=1 : "<<ele<<endl;
  //  cout<<"Events passing reco electron pass id : "<<lep2<<endl;
  cout<<"Events passing having one gen e and matching with reco electron : "<<recoelec1<<endl;
  cout<<"Events passing having one two e and either e matching with reco electron : "<<recoelec2<<endl;
  cout<<"Events passing mt cut : "<<elec_reco<<endl;
  cout<<"Events passing reco electron pass id & iso : "<<elec_reco1<<endl;
  cout<<"=========for NElectron = 0 ========"<<endl;
  cout<<"Events Survived after PreSelection : "<<evtSurvived_preselec<<endl;
  cout<<"Events having NElectrons=1 : "<<ele<<endl;
  cout<<"Events Survived veto had : "<<survived_vetohad<<endl;
  cout<<"total events before isolated tracks --> "<<elec_reco0<<endl;
  cout<<"total events before real photon check --> "<<total<<endl;
  cout<<"pass realphoton --> "<<pass_realphoton<<endl;
  cout<<"fail realphoton --> "<<fail_realphoton<<endl;
  cout<<"no realphoton --> "<<no_realphoton<<endl;
  cout<<"pass realphoton_v2 --> "<<pass_realphoton_v2<<endl;
  cout<<"fail realphoton_v2 --> "<<fail_realphoton_v2<<endl;

  cout<<"Events with electron gen = 0 : "<<elec_gen<<endl;
  cout<<"Events with electron gen = 1 : "<<elec_gen3<<endl;
  cout<<"Events with electron gen = 2 : "<<elec_gen4<<endl;
  cout<<"Events with gen tau > 0  : "<<elec_gen2<<endl;
  // cout<<"Events with gen mu from tau > 0 : "<<elec_gen3<<endl;
  // cout<<"Events with gen ele from tau > 0 : "<<elec_gen4<<endl;
  cout<<"Events with jets from tau > 0 : "<<gentauhad2<<endl;
  cout<<"Events with 0 electron reco before check : "<<elec_reco0_before<<endl;
  cout<<"Events with 0 electron reco & gen e- > 0 before check : "<<elec_reco0_genel<<endl;
  // cout<<"Events with >=2 electron reco before check : "<<elec_reco2<<endl;
  cout<<"Acceptance Check : check gen e in detector accept"<<endl;
  cout<<"pass acceptance --> "<<pass_acceptance<<endl;
  cout<<"fail acceptance --> "<<fail_acceptance<<endl;
  cout<<"ID + iso check : NElectrons = 0 : "<<endl;
  cout<<"pass id + iso --> "<<pass_id<<endl;
  cout<<"fail id + iso --> "<<fail_id<<endl;
  cout<<"hadronic tau --> "<<pass_hadtau<<endl;
  cout<<"=============================================================="<<endl;
  cout<<"Events in SR (fail accept + fail id + fail iso): "<<pass_realphoton<<endl;
  cout<<"Events in CR passing accept x id x iso check : "<<events_cr<<endl;
  cout<<"Events Survived after SP Selections in CR region : "<<SP_evtSurvived<<endl;
  cout<<"Events Survived after EW Selections in CR region : "<<EW_evtSurvived<<endl;
   
}

TLorentzVector Lostlepton::getBestPhoton(){
  vector<TLorentzVector> goodPho;
  vector<int> goodPhoIndx;
  for(int iPho=0;iPho<Photons->size();iPho++){
    if( (*Photons_fullID)[iPho] ) {
      goodPho.push_back( (*Photons)[iPho] );
      goodPhoIndx.push_back(iPho);
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

// int Lostlepton::getBinNoV7(int nbjets, int nHadJets){
//   int sBin=-100,m_i=0;
//   if(nbjets==0){
//     if(nHadJets>=2 && nHadJets<=4)     { sBin=0;}
//     else if(nHadJets==5 || nHadJets==6){ sBin=6;}
//     else if(nHadJets>=7)               { sBin=11;}
//   }
//   else{
//     if(nHadJets>=2 && nHadJets<=4)     { sBin=16;}
//     else if(nHadJets==5 || nHadJets==6){ sBin=21;}
//     else if(nHadJets>=7)               { sBin=26;}
//   }
//   if(sBin==0){
//     for(int i=0;i<METLowEdge1.size()-1;i++){
//       if(METLowEdge1[i]<99.99) continue;
//       m_i++;
//       if(MET >= METLowEdge1[i] && MET < METLowEdge1[i+1]){ sBin = sBin+m_i;break; }
//       else if(MET >= METLowEdge1[METLowEdge1.size()-1])  { sBin = 6         ;break; }
//     }
//   }
//   else{
//     for(int i=0;i<METLowEdge2.size()-1;i++){
//       if(METLowEdge2[i]<99.99) continue;
//       m_i++;
//       if(MET >= METLowEdge2[i] && MET < METLowEdge2[i+1]){ sBin = sBin+m_i;break; }
//       else if(MET >= METLowEdge2[METLowEdge2.size()-1])  { sBin = sBin+5   ;break; }
//     }
//   }
//   return sBin;
// }
int Lostlepton::getBinNoV7(int nbjets, int nHadJets){
  int sBin=-100,m_i=0;

  if(nHadJets>=2 && nHadJets<=3)
    {
      if(nbjets==0) sBin=1;
      else if(nbjets==1) sBin=2;
      else sBin=3;
    }
  else if(nHadJets>=4 && nHadJets<=5)
    {
      if(nbjets==0) sBin=4;
      else if(nbjets==1) sBin=5;
      else if(nbjets==2) sBin=6;
      else sBin=7;
    }
  else if(nHadJets>=6 && nHadJets<=7)
    {
      if(nbjets==0) sBin=8;
      else if(nbjets==1) sBin=9;
      else if(nbjets==2) sBin=10;
      else sBin=11;
    }
  else if(nHadJets>=8 && nHadJets<=9)
    {
      if(nbjets==0) sBin=12;
      else if(nbjets==1) sBin=13;
      else if(nbjets==2) sBin=14;
      else sBin=15;
    }
  else
    {
      if(nbjets==0) sBin=16;
      else if(nbjets==1) sBin=17;
      else if(nbjets==2) sBin=18;
      else sBin=19;
    }

  return sBin;
}

int Lostlepton::getBinNoV7_le(int nbjets, int nHadJets){
  int sBin=-100,m_i=0;
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

int Lostlepton::getBinNoV7_le2(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nbjets, int nHadJets){
  int sBin=-100,m_i=0;
  if(!(EWselec && EWselec1))
    {
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
    }
  else if ((EWselec && EWselec1))
    {
      if(EWselec_Wtag)
	sBin=9;
      if(EWselec_Htag)
	sBin=10;
    }
  
  return sBin;
}
int Lostlepton::getBinNoV7_le3(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nbjets, int nHadJets){
  int sBin=-100,m_i=0;
  if(!(EWselec && EWselec1))
    {
      if(nbjets==0){
        if(nHadJets==2  || nHadJets==4)     { sBin=1;}
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

// int Lostlepton::getBinNoV6(int nbjets, int nHadJets){
//   int sBin=-100,m_i=0;
//   if(nbjets==0){
//     if(nHadJets>=2 && nHadJets<=4)     { sBin=0;}
//     else if(nHadJets==5 || nHadJets==6){ sBin=7;}
//     else if(nHadJets>=7)               { sBin=13;}
//   }
//   else{
//     if(nHadJets>=2 && nHadJets<=4)     { sBin=19;}
//     else if(nHadJets==5 || nHadJets==6){ sBin=25;}
//     else if(nHadJets>=7)               { sBin=31;}
//   }
//   if(sBin==0){
//     for(int i=0;i<METLowEdge_v2.size()-1;i++){
//       if(METLowEdge_v2[i]<249.99) continue;
//       m_i++;
//       if(MET >= METLowEdge_v2[i] && MET < METLowEdge_v2[i+1]){ sBin = sBin+m_i;break; }
//       else if(MET >= METLowEdge_v2[METLowEdge_v2.size()-1])  { sBin = 7         ;break; }
//     }
//   }
//   else{
//     for(int i=0;i<METLowEdge_v2_1.size()-1;i++){
//       if(METLowEdge_v2_1[i]<249.99) continue;
//       m_i++;
//       if(MET >= METLowEdge_v2_1[i] && MET < METLowEdge_v2_1[i+1]){ sBin = sBin+m_i;break; }
//       else if(MET >= METLowEdge_v2_1[METLowEdge_v2_1.size()-1])  { sBin = sBin+6   ;break; }
//     }
//   }
//   return sBin;
// }

int Lostlepton::getBinNoV6(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nbjets, int nHadJets){
  int sBin=-100,m_i=0;
  if(!(EWselec && EWselec1))
    {
      if(nbjets==0) sBin=1;
      else sBin=2;
    }
  else if ((EWselec && EWselec1))
    {
    if(EWselec_Wtag) sBin=3;
    if(EWselec_Htag) sBin=4;
    }
  /*
  if(!(EWselec && EWselec1))
    {
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
    }
  else if ((EWselec && EWselec1))
    {
      if(nbjets==0){
        if(nHadJets>=2 && nHadJets<=4 )     { sBin=9;}
        else if((nHadJets==5 || nHadJets==6)){ sBin=10;}
      }
      else{
        if(nHadJets>=2 && nHadJets<=4)      { sBin=11;}
        else if((nHadJets==5 || nHadJets==6)){ sBin=12;}
      }

    }
  */
  return sBin;
}


int Lostlepton::getBinNoV6_EW(bool EWselec_Htag , bool EWselec_Wtag){
  int sBin=-100,m_i=0;
  if(EWselec_Wtag && !EWselec_Htag){
    sBin=0;
  }
  else if(!EWselec_Wtag && EWselec_Htag){
    sBin=7;
  }
  if(sBin==0){
    for(int i=0;i<METLowEdge_v2.size()-1;i++){
      if(METLowEdge_v2[i]<249.99) continue;
      m_i++;
      if(MET >= METLowEdge_v2[i] && MET < METLowEdge_v2[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v2[METLowEdge_v2.size()-1])  { sBin = 7         ;break; }
    }
  }
  else if(sBin==7){
    for(int i=0;i<METLowEdge_v2.size()-1;i++){
      if(METLowEdge_v2[i]<249.99) continue;
      m_i++;
      if(MET >= METLowEdge_v2[i] && MET < METLowEdge_v2[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v2[METLowEdge_v2.size()-1])  { sBin = sBin+7   ;break; }
    }
  }
  return sBin;
}

int Lostlepton::getBinNoV6_EW1(bool EWselec){
  int sBin=-100,m_i=0;
  if(EWselec){
    sBin=0;
  }
  if(sBin==0){
    for(int i=0;i<METLowEdge_v2.size()-1;i++){
      if(METLowEdge_v2[i]<249.99) continue;
      m_i++;
      if(MET >= METLowEdge_v2[i] && MET < METLowEdge_v2[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v2[METLowEdge_v2.size()-1])  { sBin = 7         ;break; }
    }
  }
 
  return sBin;
}

int Lostlepton::getBinNoV6_EWplusSP_CR(bool EWselec, bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nbjets, int nHadJets){
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
        if(nHadJets>=2 && nHadJets<=4)     { sBin=18;}
	else if(nHadJets==5 || nHadJets==6){ sBin=23;}
        else if(nHadJets>=7)               { sBin=28;}
      }
    }
  if((EWselec_Wtag && !EWselec_Htag) && EWselec1){
    sBin=33;
  }
  else if((!EWselec_Wtag && EWselec_Htag) && EWselec1){
    sBin=39;
  }

  if(sBin==0){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<199.99) continue;
      int sBin1=sBin;
      m_i++;
      if(MET >= METLowEdge_v3[i] && MET < METLowEdge_v3[i+1]){ sBin = sBin+m_i;
	break; }
      else if(MET >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = 7         ;
        break; }
    }
  }
  else if(sBin==7 || sBin==33 || sBin==39){
    int sBin1=sBin;
    for(int i=0;i<METLowEdge_v3_1.size()-1;i++){
      if(METLowEdge_v3_1[i]<199.99) continue;
      m_i++;
      if(MET >= METLowEdge_v3_1[i] && MET < METLowEdge_v3_1[i+1]){ sBin = sBin+m_i;break;}
      else if(MET >= METLowEdge_v3_1[METLowEdge_v3_1.size()-1])  { sBin = sBin+6; break; }
    }
  }

  else 
    {
      for(int i=0;i<METLowEdge_v3_2.size()-1;i++){
	if(METLowEdge_v3_2[i]<199.99) continue;
	m_i++;
	if(MET >= METLowEdge_v3_2[i] && MET < METLowEdge_v3_2[i+1]){ sBin = sBin+m_i;break; }
	else if(MET >= METLowEdge_v3_2[METLowEdge_v3_2.size()-1])  { sBin = sBin+5; break; }
    }
  }


  return sBin;
}

 int Lostlepton::getBinNoV6_EWplusSP_SR(bool EWselec1, bool EWselec_Htag , bool EWselec_Wtag,int nbjets, int nHadJets){

  int sBin=-100,m_i=0;


  if(!(EWselec_Wtag || EWselec_Htag || EWselec1))
    {
      if(nbjets==0){
	if(nHadJets>=2 && nHadJets<=4)     { sBin=0;}
	else if(nHadJets==5 || nHadJets==6){ sBin=6;}
	else if(nHadJets>=7)               { sBin=11;}
      }
      else{
	if(nHadJets>=2 && nHadJets<=4)     { sBin=16;}
	else if(nHadJets==5 || nHadJets==6){ sBin=21;}
	else if(nHadJets>=7)               { sBin=26;}
      }
    }
  if((EWselec_Wtag && !EWselec_Htag) &&  EWselec1){
    sBin=31;
  }
  else if((!EWselec_Wtag && EWselec_Htag) && EWselec1){
    sBin=37;
  }
  if(sBin==0){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<299.99) continue;
      m_i++;
      if(MET >= METLowEdge_v3[i] && MET < METLowEdge_v3[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = 6         ;break; }
    }
  }

  else if(sBin==6 || sBin==11 || sBin ==16 || sBin ==21 || sBin == 26){
    for(int i=0;i<METLowEdge_v3_1.size()-1;i++){
      if(METLowEdge_v3_1[i]<299.99) continue;
      m_i++;
      if(MET >= METLowEdge_v3_1[i] && MET < METLowEdge_v3_1[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v3_1[METLowEdge_v3_1.size()-1])  { sBin = sBin+5   ;break; }
      //   else if(MET >= METLowEdge_v3_1[METLowEdge_v3_1.size()-1])  { sBin = 31   ;break; }

    }
  }


  else if(sBin==31){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<299.99) continue;
      m_i++;
      if(MET >= METLowEdge_v3[i] && MET < METLowEdge_v3[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = sBin+6   ;break; }
      //      else if(MET >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = 37   ;break; }

   }
  }

  else if(sBin==37){
    for(int i=0;i<METLowEdge_v3.size()-1;i++){
      if(METLowEdge_v3[i]<299.99) continue;
      m_i++;
      if(MET >= METLowEdge_v3[i] && MET < METLowEdge_v3[i+1]){ sBin = sBin+m_i;break; }
      else if(MET >= METLowEdge_v3[METLowEdge_v3.size()-1])  { sBin = sBin+6   ;break; }
 
   }
  }
  return sBin;
}





bool Lostlepton::check_eMatchedtoGamma(){
  for(int i=0;i<Electrons->size();i++){
    for(int j=0;j<Photons->size();j++){
      if( (DeltaR( (*Electrons)[i].Eta(),(*Electrons)[i].Phi(),(*Photons)[j].Eta(),(*Photons)[j].Phi()) ) < 0.01){
	//cout<<(*Electrons)[i].Pt()<<" "<<(*Electrons)[i].Eta()<<" "<<(*Electrons)[i].Phi()<<" "<<(*Photons)[i].Pt()<<" "<<(*Photons)[i].Eta()<<" "<<(*Photons)[i].Phi()<<endl;
	//print(0);
	return true;
      }
    }
  }
  return false;
}

double Lostlepton::getGendRLepPho(){//MC only
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
double Lostlepton::getGenLep(TLorentzVector bestPhoton){//MC only
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
