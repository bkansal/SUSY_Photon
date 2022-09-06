#define Fakerate_cxx
#include "Fakerate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

bool applISRWtsTottbar=true;
bool full_Run2=false;
bool applyE_SF=false;
bool apply_METfilters=true;
bool apply_L1=true;
bool apply_HEMveto=true;
bool apply_pixelveto=false;
bool do_prediction=true;
bool genefromZ=false;
bool applytrg=true;
bool highdphi=false;
bool oldfake=true;
TString trial = "v1";
int main(int argc, char* argv[])
{

  if (argc < 2) {
    cerr << "Please give 3 arguments " << "runList " << " " << "outputFileName" << " " << "dataset" << endl;
    return -1;
  }
  const char *inputFileList = argv[1];
  const char *outFileName   = argv[2];
  const char *data          = argv[3];

  Fakerate ana(inputFileList, outFileName, data);

  cout << "dataset " << data << " " << endl;
 
  ana.EventLoop(data,inputFileList);

  return 0;
}

void Fakerate::EventLoop(const char *data,const char *inputFileList) {
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  cout << "nentries " << nentries << endl;
  cout << "Analyzing dataset " << data << " " << endl;

  Long64_t nbytes = 0, nb = 0;
  int decade = 0;
  //---------- deactivate unwanted branches ---------------
  // fChain->SetBranchStatus("*AK8*",0);
  // fChain->SetBranchStatus("*clean*",0);
  // fChain->SetBranchStatus("*Clean*",0);
  // fChain->SetBranchStatus("*DeltaPhi*",0);

  //  TTree *newtree = fChain->CloneTree(0);
  TString s_data = data;
  float xsec1;
  cout<<"Key words for if dataset is special: TTJets_DiLept, TTJets_SingleLeptFromT, V12"<<endl;

  int evtSurvived=0;
  int EW_evtSurvived=0;
  int EW_evtSurvived_SB=0;
  int EW_evtSurvived_htag=0;
  int EW_evtSurvived_wtag=0;
  int SP_evtSurvived=0;
  int EW_noSB_evtSurvived=0;

  // Pileup histograms
  TFile *pufile,*TF,*E_SF,*Egamma_SF;
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
  TH1* puhist;

  if(!s_data.Contains("data_v18")) 
    puhist = (TH1*)pufile->Get("pu_weights_up");


  Long64_t nSurvived = 0,phopt_rej=0,MET_rej=0,nocut=0;
  double wt = 1.0;
  int fail_realphoton=0;
  int pass_realphoton=0;
  int lep=0,nele=0,npho=0,npho_px=0,nele_px=0,remain=0,tag_ele=0,probe_ele=0,elec_reco=0,before_eletrig=0,after_eletrig=0,met=0,st=0,iso=0,mt=0,one_e2=0,two_e2=0,one_e=0,two_e=0,two_e3=0, genphomatch_before=0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {

    // ==============print number of events done == == == == == == == =
    double progress = 10.0 * jentry / (1.0 * nentries);
    int k = int (progress);
    if (k > decade)
      cout << 10 * k << " %" <<endl;
    decade = k;
    // ===============read this entry == == == == == == == == == == == 
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
  
    NumEvents = nentries;


    h_selectBaselineYields_->Fill("No cuts, evt in 1/fb",wt);
    nocut++;

    int qmulti=0;
    double leadbjet_tag=-1;

    if(!s_data.Contains("data"))
      {
        if(s_data.Contains("2016")) {lumiInfb=35.922;deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017")) {lumiInfb=41.9;deepCSVvalue = 0.4941;}
	if(s_data.Contains("2018")) {lumiInfb=58.703;deepCSVvalue = 0.4184;}

      }
    if(s_data.Contains("data"))
      {
        if(s_data.Contains("2016")) {deepCSVvalue = 0.6321;}
        if(s_data.Contains("2017")) {deepCSVvalue = 0.4941;}
	if(s_data.Contains("2018")) {deepCSVvalue = 0.4184;}
      }


    if(s_data.Contains("data_v18"))
      wt=1;
    ///////=======  L1 Prefiring issue ===========/////////                                                                            
    if((s_data.Contains("v17_2016") || s_data.Contains("v17_2017") ) && apply_L1){
    wt=Weight*1000.0*NonPrefiringProb*lumiInfb*(puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1)))));
    h_nEvts->Fill(1,wt);
   }

   if(s_data.Contains("v17_2018")){
     wt=Weight*1000.0*lumiInfb*(puhist->GetBinContent(puhist->GetXaxis()->FindBin(min(TrueNumInteractions,puhist->GetBinLowEdge(puhist->GetNbinsX()+1)))));
     h_nEvts->Fill(1,wt);
   }

   bool HEMaffected = false;
   //////-======== HEM issue ==================//////////////                                                                    
   if(s_data.Contains("2018") && apply_HEMveto){
     for(int i=0; i<Electrons->size();i++)
       if((*Electrons)[i].Pt() >30 && (*Electrons)[i].Eta() > -3.0 && (*Electrons)[i].Eta() < -1.4 && (*Electrons)[i].Phi() > -1.57 && (*Electrons)[i].Phi() < -0.87) {HEMaffected = true; break;}
     for(int i=0; i<Jets->size();i++)
       if((*Jets)[i].Pt() > 30 && (*Jets)[i].Eta() > -3.2 && (*Jets)[i].Eta() < -1.2 && (*Jets)[i].Phi() > -1.77 && (*Jets)[i].Phi() < -0.67 && DeltaPhi((*Jets)[i].Pt(),METPhi)<0.5) {HEMaffected = true; break;}
     if(HEMaffected == true) continue;
   }


   if(s_data.Contains("TTJets2"))
     {//cout<<" correct "<<endl;                                                                                                                             
       if ( madHT>600) continue;
     }
  
   //MET filters
   if(!s_data.Contains("FastSim") && apply_METfilters==true){

     if(trial=="v2")
       {
	 if(s_data.Contains("data"))
	   if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedExtraFilter && eeBadScFilter==1 && NVtx>0 && eeBadScFilter && JetID && JetIDAK8)) continue;
	 
	 if(s_data.Contains("v17"))
	   if(!(PrimaryVertexFilter==1 && globalSuperTightHalo2016Filter == 1 && HBHENoiseFilter==1 && HBHEIsoNoiseFilter==1 && EcalDeadCellTriggerPrimitiveFilter == 1 && BadPFMuonFilter && ecalBadCalibReducedExtraFilter && NVtx>0 && eeBadScFilter && JetID && JetIDAK8)) continue;
	 
       }
   

     if(PFCaloMETRatio >=  5) continue;
     if(MET/CaloMET > 2.0) continue;
   }
   MET_rej++;

   TLorentzVector bestPhoton=getBestPhoton();
    bool bestPhoHasPxlSeed=true;

    ///ISR reweighting
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

   //// Stitching TTJets & TTGamma samples. Similarly WJets & WGamma samples 
   if(!s_data.Contains("data"))
     {
       double mindr_Pho_genlep=getGenLep(bestPhoton);
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


       if(hasGenPromptPhoton && (s_data.Contains("ZGJets")))
	 {
	   if(!(madMinPhotonDeltaR>0.5 && mindr_Pho_genlep>0.5)) continue;
	 }

       if(hasGenPromptPhoton && (s_data.Contains("DYJets")))
         {
	   if(!(madMinPhotonDeltaR<=0.5 || mindr_Pho_genlep<=0.5) ) continue;

	 }
       //Gen non-prompt
       h_madminphotonDR->Fill(madMinPhotonDeltaR,wt);
       h_mindr_ph_lep->Fill(mindr_Pho_genlep,wt);
       //       h_mindr_genph_lep->Fill(mindr_genPho_genlep,wt);
 
     }	  
   

   // genphomatch_after++;
   before_eletrig++;
   bool tighte_trgpass=true;
   if(s_data.Contains("data") && applytrg)
     {
       if(TriggerPass->size()!=148) continue;
       if((*TriggerPass)[36]==1 && s_data.Contains("2016"))
	 tighte_trgpass=true;
       else if((*TriggerPass)[40]==1 && !s_data.Contains("2016"))
	 {
	   if((*TriggerPrescales)[40]!=1)     cout<<jentry<<" :  TriggerPrescales = "<<(*TriggerPrescales)[40]<<endl;
	   tighte_trgpass=true;
	 } 
      else tighte_trgpass=false;            
       if(tighte_trgpass==false)  continue;
     }
   after_eletrig++;
 
   
    if(NMuons==0) h_selectBaselineYields_->Fill("0 #mu",wt);
    else continue;


   // //apply iso track veto                                                                                                                
    if(isoMuonTracks ==0 && isoPionTracks==0)
      {
        h_selectBaselineYields_->Fill("Iso #mu & pion track",wt);
      }
    else continue;

    lep++;

    
    //about photons
    int hasEle=0,hasEle2=0, hasPho=0, hasPho_px=0,hastagEle=0,hasprobeEle=0;
    bool eMatchedG=check_eMatchedtoGamma(bestPhoton);
    if(bestPhotonIndxAmongPhotons>=0){
      if((*Photons_hasPixelSeed)[bestPhotonIndxAmongPhotons]<0.001) bestPhoHasPxlSeed=false;
      if(!bestPhoHasPxlSeed && bestPhoton.Pt()>100)
	{
	  hasPho=1;hasPho_px=0;
	}//npho++;}
      else if(bestPhoHasPxlSeed && bestPhoton.Pt()>100) {hasPho_px=1;hasPho=0;}// npho_px++;}
      else
	{
	  hasPho_px=0;
	  hasPho=0;
	}
    }

    //about Electrons
    int nlep=0, e_index=-1, e_index2=-1;
    TLorentzVector v_lep1,v_lep2;
    TLorentzVector tmp,tmp2;
    double mt_ele=0;
    vector<TLorentzVector> reco_e;
    if(NElectrons==2 || NElectrons==1)
      {
	for(int i=0 ; i<Electrons->size() ; i++)
	  {
	    if((*Electrons_passIso)[i]==1 )   
	      {	    
		nlep++;

		if(nlep==1)
		  { 
		    e_index=i;
		    tmp=(*Electrons)[e_index]; //1st electron
		    one_e++;
		  }
		if(nlep==2) 
		  {
		    e_index2=i;
		    tmp2=(*Electrons)[e_index2]; // 2nd electron
		    two_e++;
		  }
	      }
	  }
      }


     if(nlep>0) reco_e.push_back(tmp);
     else if(nlep > 1) reco_e.push_back(tmp2);
     else if(nlep>2) continue;
     //     if(tmp2.DeltaR(tmp)<0.2)continue;
     h_selectBaselineYields_->Fill("NElectrons = 1 or 2 ",wt);

     int minDR3indx=-100, minDR4indx=-100 , minDR5indx=-100, minDR6indx=-100; 
     double minDR3=9999, minDR4=9999 , minDR5=9999, minDR6=9999;
     int par=0;
     vector<TLorentzVector> v_genz,v_hlt;
     TLorentzVector v_genz_,v_hlt_;
     if(!s_data.Contains("data") )//&& s_data.Contains("DYJets"))
       {
	 //	 cout<<jentry<<" : "<<GenElectrons->size()<<endl;
         for(int i=0;i<GenElectrons->size();i++){
	   v_genz.push_back((*GenElectrons)[i]);
	 }
	 //if(GenElectrons->size()>2) cout<<jentry<<" : "<<GenElectrons->size();
	 /*
	 for(int i=0;i<GenParticles->size();i++){
	   if((abs((*GenParticles_ParentId)[i])==23 || abs((*GenParticles_ParentId)[i])==24) && (*GenParticles_Status)[i]==1  && abs((*GenParticles_PdgId)[i])==11 )
	     {
	       double dR=tmp.DeltaR((*GenParticles)[i]);
	       if(dR<minDR3){minDR3=dR;minDR3indx=i;}
	       if(nlep==2){
		 double dR2=tmp2.DeltaR((*GenParticles)[i]);
		 if(dR2<minDR4){minDR4=dR2;minDR4indx=i;}
	       }
	       if(nlep==1){
		 double dR2=bestPhoton.DeltaR((*GenParticles)[i]);
		 if(dR2<minDR4){minDR4=dR2;minDR4indx=i;}
	       }
	     }
	 }
	 if((abs((*GenParticles_ParentId)[minDR4indx])==23 || abs((*GenParticles_ParentId)[minDR4indx])==24) && (*GenParticles_Status)[minDR4indx]==1 && abs((*GenParticles_PdgId)[minDR4indx])==11 )
	   minDR5=tmp.DeltaR((*GenParticles)[minDR4indx]);
	 if(nlep==2 && (abs((*GenParticles_ParentId)[minDR3indx])==23 || abs((*GenParticles_ParentId)[minDR3indx])==24) && (*GenParticles_Status)[minDR3indx]==1 && abs((*GenParticles_PdgId)[minDR3indx])==11 )
	   { 
	     if(nlep==2) minDR6=tmp2.DeltaR((*GenParticles)[minDR3indx]);
	     if(nlep==1) minDR6=bestPhoton.DeltaR((*GenParticles)[minDR3indx]);
	   }
	 
	 //	     if(hasPho==2) minDR6=bestPhoton.DeltaR((*GenParticles)[minDR3indx]);

	     if(minDR3indx==minDR4indx)
	       {
		 double minDR3_=minDR3, minDR4_=minDR4;
		 if(minDR3_>minDR4_)
		   {
		     minDR3=9999, minDR3indx=-100;
		     for(int i=0;i<GenParticles->size();i++)
		       {//tag matching                                                                                                                                    
			 if((abs((*GenParticles_ParentId)[i])==23 || abs((*GenParticles_ParentId)[i])==24) && (*GenParticles_Status)[i]==1 && abs((*GenParticles_PdgId)[i])==11  && i!=minDR4indx){
			   double dR=tmp.DeltaR((*GenParticles)[i]);
			   if(dR<minDR3){minDR3=dR;minDR3indx=i;}
			 }
		       }
		     if((abs((*GenParticles_ParentId)[minDR4indx])==23 || abs((*GenParticles_ParentId)[minDR4indx])==24) && (*GenParticles_Status)[minDR4indx]==1 && abs((*GenParticles_PdgId)[minDR4indx])==11 )
		       minDR5=tmp.DeltaR((*GenParticles)[minDR4indx]);
                     if(nlep==2 && (abs((*GenParticles_ParentId)[minDR3indx])==23 || abs((*GenParticles_ParentId)[minDR3indx])==24) && (*GenParticles_Status)[minDR3indx]==1 && abs((*GenParticles_PdgId)[minDR3indx])==11 )
		       minDR6=tmp2.DeltaR((*GenParticles)[minDR3indx]);
                     if(nlep==1 && (abs((*GenParticles_ParentId)[minDR3indx])==23 || abs((*GenParticles_ParentId)[minDR3indx])==24) && (*GenParticles_Status)[minDR3indx]==1 && abs((*GenParticles_PdgId)[minDR3indx])==11 )
		       minDR6=bestPhoton.DeltaR((*GenParticles)[minDR3indx]);

		   }
		 if(minDR4_>minDR3_)
		   {
		     minDR4=9999, minDR4indx=-100;
		     for(int i=0;i<GenParticles->size();i++)
		       {//tag matching                                                                                                                                       
			 if((abs((*GenParticles_ParentId)[i])==23 || abs((*GenParticles_ParentId)[i])==24) && (*GenParticles_Status)[i]==1 && abs((*GenParticles_PdgId)[i])==11 && i!=minDR3indx){
			   if(nlep==2){
			     double dR=tmp2.DeltaR((*GenParticles)[i]);
			     if(dR<minDR4){minDR4=dR;minDR4indx=i;}
			   }
			   if(nlep==1){
			    double dR2=bestPhoton.DeltaR((*GenParticles)[i]);
			    if(dR2<minDR4){minDR4=dR2;minDR4indx=i;}
			   }
			 }
		       }
                     if((abs((*GenParticles_ParentId)[minDR4indx])==23 || abs((*GenParticles_ParentId)[minDR4indx])==24) && (*GenParticles_Status)[minDR4indx]==1 && abs((*GenParticles_PdgId)[minDR4indx])==11 )
		       minDR5=tmp.DeltaR((*GenParticles)[minDR4indx]);
		     if((abs((*GenParticles_ParentId)[minDR3indx])==23 || abs((*GenParticles_ParentId)[minDR3indx])==24) && (*GenParticles_Status)[minDR3indx]==1 && abs((*GenParticles_PdgId)[minDR3indx])==11 )
		       {
			 if(nlep==2) minDR6=tmp2.DeltaR((*GenParticles)[minDR3indx]);
			 if(nlep==1) minDR6=bestPhoton.DeltaR((*GenParticles)[minDR3indx]);
		       }
		   }

	       }
	     
	     if(minDR3indx!=minDR4indx){
	       if(minDR3>=0) v_genz.push_back((*GenParticles)[minDR3indx]);
	       if(minDR4>=0) v_genz.push_back((*GenParticles)[minDR4indx]);
	       //  cout<<jentry<<" : "<<hasPho<<" , "<<minDR3<<" , "<<minDR4<<endl;
	       }
	     if(tmp2.DeltaR(tmp)<0.2)continue;
	     if(minDR3indx==minDR4indx && minDR3indx!=-100)
	       cout<<"3        "<<jentry<<" : "<<minDR3<<" , "<<minDR4<<" , "<<minDR5<<" , "<<minDR6<<endl;
	 */
	     if(v_genz.size()==0 || nlep==0) continue;
	     
       }	     

   
     if(s_data.Contains("data"))//  && !s_data.Contains("2018"))//_v18_2016") && s_data.Contains("data_v18_2017") )
       {

	   for(int i=0;i<HLTElectronObjects->size();i++)
	     {//tag matching
	       double dR=tmp.DeltaR((*HLTElectronObjects)[i]);
	       if(dR<minDR3){minDR3=dR;minDR3indx=i;}
	       double dR2=tmp2.DeltaR((*HLTElectronObjects)[i]);
	       if(dR2<minDR4){minDR4=dR2;minDR4indx=i;}
	     }
	   minDR5=tmp.DeltaR((*HLTElectronObjects)[minDR4indx]);
	   minDR6=tmp2.DeltaR((*HLTElectronObjects)[minDR3indx]);
	   if(minDR3>=0) v_hlt.push_back((*HLTElectronObjects)[minDR3indx]);
	   if(minDR4>=0) v_hlt.push_back((*HLTElectronObjects)[minDR4indx]);
	   //	   cout<<"        "<<jentry<<" : "<<minDR3<<" , "<<minDR4<<" , "<<minDR5<<" , "<<minDR6<<endl;
	   if(v_hlt.size()==0 || nlep==0) continue;

       }
  
     // 0 index for tag object and 1 index for probe
    if(nlep==1)
      {
     	double mindr=100;	
        double mindr2=100;
	//        if(!s_data.Contains("data")) { mindr=MinDr(tmp,GenParticles); mindr2=0.1; mindr2=MinDr(bestPhoton,GenParticles);}
	if(!s_data.Contains("data")) { mindr=tmp.DeltaR(v_genz[0]); mindr2=0.1; mindr2=bestPhoton.DeltaR(v_genz[1]);}
	if(s_data.Contains("data")) 
	  {
	    //    mindr=MinDr(tmp,*HLTElectronObjects);
	    mindr=tmp.DeltaR(v_hlt[0]);
	    mindr2=0.1;
	  }

	if(tmp.Pt()>40 && mindr<0.2 && (*Electrons_tightID)[e_index] && mindr2<0.2 && hasPho==1)
	  {
            hasEle=1;
            v_lep2=tmp; //tag                                                                                                                                             
            if(hasPho==1)v_lep1=bestPhoton; //probe                                                                           
                                           
	    if(!s_data.Contains("data")) v_genz_=v_genz[0];
	    if(s_data.Contains("data")) v_hlt_=v_hlt[0];
            one_e2++;
          }

	if(s_data.Contains("data"))h_minDr_bestphoremEle->Fill(mindr,wt);
        if(!s_data.Contains("data"))
	  {
	    h_minDr_bestphoremEle->Fill(mindr,wt);
	    //	    h_minDr_bestphoJets->Fill(MinDr(bestPhoton,v_genz),wt);
	  }
      }
   
    if(nlep==2)
      {
	int a=0;
        double mindr=100;
        double mindr2=100;
        double mindr3=100;
        double mindr4=100;

        if(!s_data.Contains("data"))
	  {
	    mindr=tmp2.DeltaR(v_genz[1]);
	    mindr2=tmp.DeltaR(v_genz[0]);
	    mindr3=0.1;
            mindr4=0.1;
	    // mindr3=tmp2.DeltaR(v_genz[1]);
	    // mindr4=tmp.DeltaR(v_genz[0]);

            //mindr3=-1;
	    h_minDr_bestphoremEle->Fill(mindr2,wt);
	  }
        if(s_data.Contains("data"))
          {
            //mindr=MinDr(tmp2,*HLTElectronObjects);
	    // mindr2=MinDr(tmp,*HLTElectronObjects);
	    mindr2=tmp.DeltaR(v_hlt[0]);
	    mindr=tmp2.DeltaR(v_hlt[1]);
	    mindr3=0.1;
	    mindr4=0.1;
	    h_minDr_bestphoremEle->Fill(mindr2,wt);
	  }
	if(tmp.Pt()>100 && tmp2.Pt()>100 && a==0 && mindr<0.2 && mindr2<0.2 && (*Electrons_tightID)[e_index] && (*Electrons_tightID)[e_index2])
	  {
	    //	    v_lep1=tmp; v_lep2=tmp2; hasEle=2;wt=2*wt;a++;
	    if(jentry%2==0){v_lep1=tmp; v_lep2=tmp2; hasEle=2;wt=2*wt; if(s_data.Contains("data")) v_hlt_=v_hlt[1]; if(!s_data.Contains("data"))  v_genz_=v_genz[1];a++;}
	    else{v_lep2=tmp; v_lep1=tmp2; hasEle=2;wt=2*wt; if(s_data.Contains("data")) v_hlt_=v_hlt[0]; if(!s_data.Contains("data"))  v_genz_=v_genz[0]; a++; }
	    two_e2++;
	    //            two_e3++;
	    //if(jentry==18163)
	    //cout<<jentry<<" : "<<v_lep2.DeltaR(v_genz[0])<<" , "<<v_lep1.DeltaR(v_genz[1])<<endl;

	  }
        if(tmp.Pt()>100 && tmp2.Pt()>40 && a==0 && mindr<0.2 && (*Electrons_tightID)[e_index2] && mindr4<0.2)
          {
            hasEle=2; v_lep2=tmp2; v_lep1=tmp;
            a++;
            if(!s_data.Contains("data")) v_genz_=v_genz[1];
            if(s_data.Contains("data")) v_hlt_=v_hlt[1];
            two_e2++;
	    // two_e3++;
            // cout<<jentry<<" : "<<v_lep1.DeltaR(v_genz[1])<<endl;                                                                                                         
          }
	
	if(tmp2.Pt()>100 && tmp.Pt()>40 && a==0 && mindr2<0.2 && (*Electrons_tightID)[e_index] && mindr3<0.2) 
	  {
	    hasEle=2; v_lep2=tmp; v_lep1=tmp2;
	    a++;
            if(!s_data.Contains("data")) v_genz_=v_genz[0];
            if(s_data.Contains("data")) v_hlt_=v_hlt[0];
            two_e3++;
	    two_e2++;
	  }


      }
    //    cout<<"2"<<endl;

    bool bestEMObjIsEle=false, bestEMObjIsEle_px=false,bestEMobj=false;
    TLorentzVector bestEMObj,tagEMObj;



    if(hasEle==2 || hasEle==1){ hastagEle=1;}    
    if (hasEle==2 && hasPho==0 && hastagEle==1) {bestEMObjIsEle=true; bestEMObjIsEle_px=false;hasprobeEle=1; tagEMObj = v_lep2; bestEMObj = v_lep1; bestEMobj=true; probe_ele++;}
    if(hasEle==1 &&  hasPho==1 && hastagEle==1) {bestEMObjIsEle=false;  bestEMObjIsEle_px=false; hasprobeEle=1; tagEMObj = v_lep2; bestEMObj = bestPhoton; bestEMobj=true; probe_ele++;}
    if(hasprobeEle==0) continue;
    else
      tag_ele++;


    if(!bestEMobj) continue;
    //    if(!tagEMObj) continue;
    h_selectBaselineYields_->Fill("1 tag e & 1 probe e/pho",wt);

    /////======Pixel Power supply issue ===============//////////////                                                              
    if(apply_pixelveto){
      if(s_data.Contains("2017") && ((bestEMObj.Eta() > 0.0 && bestEMObj.Eta() < 1.5 && bestEMObj.Phi() > 2.7) || (tagEMObj.Eta() > 0.0 && tagEMObj.Eta() < 1.5 && tagEMObj.Phi() > 2.7))) continue;
      if(s_data.Contains("2018") && ((bestEMObj.Eta() > 0.0 && bestEMObj.Eta() < 1.5 && bestEMObj.Phi() > 0.4 && bestEMObj.Phi() < 0.8) || (tagEMObj.Eta() > 0 && tagEMObj.Eta() < 1.5 && tagEMObj.Phi() > 0.4 && tagEMObj.Phi() < 0.8))) continue;
    }


    //    if(bestEMObjIsEle && bestEMobj ) cout<<jentry<<" : "<<(*Photons_passElectronVeto)[bestPhotonIndxAmongPhotons]<<endl;

    if(bestEMObjIsEle &&  bestEMobj)
      {
	mt_ele=sqrt(2*bestEMObj.Pt()*MET*(1-cos(DeltaPhi(METPhi,bestEMObj.Phi()))));
	//	if(mt_ele>100 ) continue;
	elec_reco++;
      }
    mt++;


    bool fakePhoton=0,showEnt=0;
    //    oldfake=true;
    double minDr=99999;
    bool notrack=true;
    int ntracks=0, minDrindx=-100, track_idx=-100;
    for(int i=0;i<TAPElectronTracks->size();i++){
      if((*TAPElectronTracks)[i].Pt()>5)
        {
	  double dR2=tagEMObj.DeltaR((*TAPElectronTracks)[i]);
	  if(dR2<minDr){minDr=dR2;minDrindx=i;}
	  if(dR2<0.2) ntracks++;
        }
    }
    if(minDr<0.2)
      {
	notrack=false;
	track_idx=minDrindx;
      }
    if(notrack || ntracks==0) continue;

    if(apply_pixelveto){
      if(s_data.Contains("2017") && ((*TAPElectronTracks)[track_idx].Eta() > 0.0 && (*TAPElectronTracks)[track_idx].Eta() < 1.5 && (*TAPElectronTracks)[track_idx].Phi() > 2.7)) continue;
      if(s_data.Contains("2018") && ((*TAPElectronTracks)[track_idx].Eta() > 0 && (*TAPElectronTracks)[track_idx].Eta() < 1.5 && (*TAPElectronTracks)[track_idx].Phi() > 0.4 && (*TAPElectronTracks)[track_idx].Phi() < 0.8)) continue;
    }

    if(!bestEMObjIsEle && bestEMobj && !oldfake)
      {
        if(!s_data.Contains("data"))
          {
            bool fakePhoton=false;
	    /*
	    for(int i=0;i<GenParticles->size();i++){
	      if((*GenParticles)[i].Pt()!=0){
		double dr1=bestPhoton.DeltaR((*GenParticles)[i]);
		if(dr1 < 0.2 && (abs((*GenParticles_PdgId)[i])==11) && (abs((*GenParticles_ParentId)[i])<=24) ){
		  fakePhoton=true;
		}}}
	    */
	    double xmin=0.8,xmax=1.2;
	    if(v_genz.size()==1 && bestPhoton.DeltaR(v_genz[0])<0.2 && bestPhoton.Pt()/v_genz[0].Pt()>xmin && bestPhoton.Pt()/v_genz[0].Pt()<xmax)
	      {
		fail_realphoton++;
		fakePhoton=true;
	      }
	    else if(v_genz.size()>1 && ((bestPhoton.DeltaR(v_genz[0])<0.2 && bestPhoton.Pt()/v_genz[0].Pt()>xmin && bestPhoton.Pt()/v_genz[0].Pt()<xmax) || (bestPhoton.DeltaR(v_genz[1])<0.2 && bestPhoton.Pt()/v_genz[1].Pt()>xmin && bestPhoton.Pt()/v_genz[1].Pt()<xmax)))
	      {
		fail_realphoton++;
		fakePhoton=true;
	      }

	    else
	      {
		pass_realphoton++;
		fakePhoton=false;
	      }


	      if(!fakePhoton) continue;
	  }
	if(ntracks>1) continue;

	
      }
    //    oldfake=false;
    if(bestEMobj && !bestEMObjIsEle && oldfake)
      {
        if(!s_data.Contains("data"))
	  {
	    bool realPho=true;
	    int matche=0,matchp=0;
	    double minDR_Pho_GenObj=1000,matchgenElePt=0,matchgenPhoPt=0;
	    for(int i=0;i<GenParticles->size();i++){
	      if((*GenParticles)[i].Pt()!=0){
		double dr1=bestPhoton.DeltaR((*GenParticles)[i]);
		if(dr1 < 0.2 && (abs((*GenParticles_PdgId)[i])==11) && (abs((*GenParticles_ParentId)[i])<=24) ) {
		  matche=1;
		  matchgenElePt = (*GenParticles)[i].Pt();
		}
		//  if(minDR_Pho_GenObj > dr1) minDR_Pho_GenObj=dr1;
	      }
	    }
	    //h_minDR_Pho_GenObj->Fill(minDR_Pho_GenObj,wt);
	    for(int i=0;i<GenParticles->size();i++){
	      if((*GenParticles)[i].Pt()!=0){
		double dr1=bestPhoton.DeltaR((*GenParticles)[i]);
		if( dr1 < 0.2 && (abs((*GenParticles_PdgId)[i])==22) ){
		  matchp=1;
		  matchgenPhoPt = (*GenParticles)[i].Pt();
		}
	      }
	    }
	    if(matche==0) realPho=true;
	    else if(matche==1 && matchp==0) realPho=false;
	    else if(matche==1 && matchp==1){
	      if( abs(bestPhoton.Pt() - matchgenElePt) < abs(bestPhoton.Pt() - matchgenPhoPt)) realPho=false;
	      else realPho=true;
	    }
	    else cout<<"Logic issue in gen e/gamma matching with reco gamma"<<endl;
	    if(realPho) {pass_realphoton++; continue;}
	    if(!realPho) {fail_realphoton++;}
	  }
	if(ntracks>1) continue;

      }

    h_selectBaselineYields_->Fill("fake pho probe",wt);


    //if(MinDr(tagEMObj,TAPElectronTracks)>0.2) continue;
    if(bestEMObj.DeltaR(tagEMObj) < 0.2) continue;
    iso++;
    h_selectBaselineYields_->Fill("dR(tag,probe)>0.2",wt);

    //========= hadjet -> removing jets which are matched with photon within mindr 0.3 =====//                                                                
    bool hadJetID=false;

    double nbjets=0;
    int bJet1Idx = -1;

    vector<TLorentzVector> nonbjets,bjets;
    int minDRindx=-100,minDR2indx=-100,photonMatchingJetIndx=-100,nHadJets=0;
    double minDR=99999,ST=0,remJetPt=0,minDR2=99999;
    vector<TLorentzVector> hadJets, remJets;

    for(int i=0;i<Jets->size();i++){
      if( ((*Jets)[i].Pt() > 30.0) && (abs((*Jets)[i].Eta()) <= 2.4) )
        {
	  {
	    double dR=bestEMObj.DeltaR((*Jets)[i]);
            double dR2=tagEMObj.DeltaR((*Jets)[i]);
	    if(dR<minDR){minDR=dR;minDRindx=i;}
            if(dR2<minDR2){minDR2=dR2;minDR2indx=i;}

	  }
        }
    }
    if( minDR > 0.3 )  minDRindx   = -100;
    if( minDR2 > 0.3 )  minDR2indx   = -100;
    for(int i=0;i<Jets->size();i++){
      if( ((*Jets)[i].Pt() > 30.0) && (abs((*Jets)[i].Eta()) <= 2.4) ){
	//        if( !(minDR < 0.3 && i==minDRindx) ){
	if((i!=minDRindx) && (i!=minDR2indx) ){
          hadJetID=(*Jets_ID)[i];
          if(hadJetID)
	    {
	      hadJets.push_back((*Jets)[i]);
	      if((*Jets_bJetTagDeepCSVBvsAll)[i] > deepCSVvalue){
		bjets.push_back((*Jets)[i]); bJet1Idx = i;}

	    }
        }
      }
    }

    if( minDR<0.3 ) photonMatchingJetIndx=minDRindx;
    //now hadJets contains all jets except the one matched to emObject. check whether there is energy near emObj or not. If yes then add it as a jet.                                                                                                            
   if( photonMatchingJetIndx>=0 ){
    if( ((*Jets)[photonMatchingJetIndx].Pt()) > 1.1*(bestEMObj.Pt()) ){
      if( (((*Jets)[photonMatchingJetIndx] - bestEMObj).Pt())>30){
	hadJets.push_back( (*Jets)[photonMatchingJetIndx] - bestEMObj );
	remJetPt=((*Jets)[photonMatchingJetIndx] - bestEMObj).Pt();
	remJets.push_back( (*Jets)[photonMatchingJetIndx] - bestEMObj );
      }
    }
   }
   if( minDR<0.3 )
      {
        photonMatchingJetIndx=minDRindx;
        qmulti=(*Jets_chargedMultiplicity)[photonMatchingJetIndx];
	//	if(bestEMObjIsEle && qmulti ==0) continue;
	leadbjet_tag=(*Jets_bJetTagDeepCSVBvsAll)[photonMatchingJetIndx];
      }

    for(int i=0;i<hadJets.size();i++)
      {
        if( (abs(hadJets[i].Eta()) < 2.4) ){ST=ST+(hadJets[i].Pt());}
        if( (abs(hadJets[i].Eta()) < 2.4) ){nHadJets++;}
      }
    for(int i=0;i<bjets.size();i++)
      if( (abs(bjets[i].Eta()) < 2.4) ){nbjets++;}

    if( minDR<0.3 ){
      ST=ST+bestEMObj.Pt();
    }

 
    //Minimum MET                                                                                                                                             
    if( MET<200)
      {
        h_selectBaselineYields_->Fill("MET<200",wt);
      }
    else continue;
    met++;

    if( (ST <= 200) ) continue;
    h_selectBaselineYields_->Fill("ST > 200",wt);
    st++;
    // Minimum 2 jets (photon is not counted as jet)                                                                                                                       
    if( nHadJets >= 2 )
      {
        h_selectBaselineYields_->Fill("nJets >= 2",wt);
      }

    else
      continue;
    sortTLorVec(&hadJets);

    //end of select skimming parameters
    nSurvived++;

    //    newtree->Fill();

    //    cout<<jentry<<" : Tag Ele Pt : "<<tagEMObj.Pt()<<" , Probe EM obj Pt : "<<bestEMObj.Pt()<<" , invariant Mass : "<<invariantmass<<" , wt : "<<wt<<endl;
    TLorentzVector Met;
    double mT=0, dPhi_METjet1=10,dPhi_METjet2=10, dPhi_phojet1=10, dPhi_phojet2=10, dPhi_phoMET=10;
    double dPhi_METjet3=10,dPhi_METjet4=10, dPhi_phojet3=10, dPhi_phojet4=10;
    Met.SetPtEtaPhiE(MET,0,METPhi,0);
    if(hadJets.size() > 0)    dPhi_phojet1 = abs(bestPhoton.DeltaPhi(hadJets[0]));
    if(hadJets.size() > 1)    dPhi_phojet2 = abs(bestPhoton.DeltaPhi(hadJets[1]));
    dPhi_phoMET = abs(bestPhoton.DeltaPhi(Met));

    double mindphi=1000;
    if(hadJets.size() > 0) {   dPhi_METjet1 = abs(Met.DeltaPhi(hadJets[0]));mindphi=dPhi_METjet1;}
    if(hadJets.size() > 1)  {  dPhi_METjet2 = abs(Met.DeltaPhi(hadJets[1])); if(dPhi_METjet2<mindphi) mindphi=dPhi_METjet2;}

    double mTPhoMET=sqrt(2*(bestEMObj.Pt())*MET*(1-cos(DeltaPhi(METPhi,bestEMObj.Phi()))));

    //Minimum dPhi cut between MET and leading two jets                                                                                                                     
    if(highdphi)
      {
        if(dPhi_METjet1 > 0.3 && dPhi_METjet2 > 0.3 )
          {
            h_selectBaselineYields_->Fill("dPhi1 & dPhi2 >= 0.3",wt);
          }
        else continue;
      }

    TLorentzVector zvec;  
    zvec=(bestEMObj + tagEMObj);
    invariantmass = (bestEMObj + tagEMObj).M();   
    //
    if(!(invariantmass>=80 && invariantmass<=100) )continue;
    //    if(zvec.Pt()>600) continue;
    //    if(!(invariantmass>=60 && invariantmass<=120) )continue;
    remain++;
    h_HT->Fill(HT,wt);
    h_MHT->Fill(MHT,wt);
    h_selectBaselineYields_->Fill("80<M(e,e/pho)<100",wt);

   if(bestEMObjIsEle && bestEMobj) 
     {
       nele++;
       h_deepcsv->Fill(leadbjet_tag,wt);
       h2_QMultlleadbJet->Fill(qmulti,leadbjet_tag,wt);
       if(s_data.Contains("data") && !s_data.Contains("2018"))
	 {
	   h_minDr_bestphoEle->Fill(tagEMObj.DeltaR(v_hlt_),wt);
	   h2_minDr_tagEle_pt->Fill(tagEMObj.Pt(),tagEMObj.DeltaR(v_hlt_),wt);
           h_hlt_pT->Fill(v_hlt_.Pt(),wt);
	 }
       if(!s_data.Contains("data"))
         {
	   if(tagEMObj.DeltaR(v_genz[0])>0.2 && tagEMObj.DeltaR(v_genz[1])>0.2)
	     cout<<jentry<<" : "<<tagEMObj.DeltaR(v_genz[0])<<" , "<<tagEMObj.DeltaR(v_genz[1])<<endl;
	   
           h_minDr_bestphoEle->Fill(tagEMObj.DeltaR(v_genz_),wt);

           h2_minDr_tagEle_pt->Fill(tagEMObj.Pt(),tagEMObj.DeltaR(v_genz_),wt);
           h_hlt_pT->Fill(v_genz_.Pt(),wt);
         }

       h_invMass->Fill(invariantmass,wt);
	 {
	   h2_BestPhoEta_Pt->Fill(bestEMObj.Eta(),bestEMObj.Pt(),wt);
	   h_MET->Fill(MET,wt);
	   h_METvBin2->Fill(MET,wt);
	   h_nJets->Fill(nHadJets,wt);
	   h_ST->Fill(ST,wt);
	   h_DBTags->Fill(abs(nbjets-BTags),wt);
	   h_BTags->Fill(nbjets,wt);
	   h_CM_Ele->Fill(qmulti,wt);
	   h_EMObj_pT->Fill(bestEMObj.Pt(),wt);
	   h_tagObj_pT->Fill(tagEMObj.Pt(),wt);
	   //	   h_hltObjpT->Fill(v_hlt[0].Pt(),wt);
	   h_nvtx->Fill(NVtx,wt);
	   //nAllVertices
           h_nvtx_all->Fill(nAllVertices,wt);
	   h_BestPhotonPhi->Fill(bestEMObj.Phi(),wt);
	   h_BestPhotonEta->Fill(bestEMObj.Eta(),wt);
	   h_leadElectronPt->Fill(zvec.Pt(),wt);
           h2_ElectronEta_Phi->Fill(bestEMObj.Eta(),bestEMObj.Phi(),wt);
	   h2_leadElectronEta_Phi->Fill(tagEMObj.Eta(),tagEMObj.Phi(),wt);
	   h_ElectronEta->Fill(tagEMObj.Eta(),wt);
	   h_ElectronPhi->Fill(tagEMObj.Phi(),wt);
	   h_trackElectronPt->Fill((*TAPElectronTracks)[track_idx].Pt(),wt);
           h_trackElectronEta->Fill((*TAPElectronTracks)[track_idx].Eta(),wt);
           h_trackElectronPhi->Fill((*TAPElectronTracks)[track_idx].Phi(),wt);
	   h2_trackElectronEta_Phi->Fill((*TAPElectronTracks)[minDrindx].Eta(),(*TAPElectronTracks)[minDrindx].Phi(),wt);
	   //	   h_HT->Fill(HT,wt);
	   //           h_MHT->Fill(MHT,wt);
	 }
     }
   else if(!bestEMObjIsEle && bestEMobj) 
     {
       npho++;
       if(s_data.Contains("data")&& !s_data.Contains("2018"))  h_minDr_bestphoEle->Fill(tagEMObj.DeltaR(v_hlt[0]),wt);
       h_invMass_elec0->Fill(invariantmass,wt);
       //       if(invariantmass>=60 && invariantmass<=120) 
	 {
	   h2_BestPhoEta_Pt_elec0->Fill(bestEMObj.Eta(),bestEMObj.Pt(),wt);
	   h_MET_elec0->Fill(MET,wt);
	   h_METvBin2_elec0->Fill(MET,wt);
	   h_nJets_elec0->Fill(nHadJets,wt);
	   h_ST_elec0->Fill(ST,wt);
	   h_BTags_elec0->Fill(nbjets,wt);
	   h_CM_Pho->Fill(qmulti,wt);
	   h_EMObj_pT_elec0->Fill(bestEMObj.Pt(),wt);
	   h_tagObj_pT_elec0->Fill(tagEMObj.Pt(),wt);
	   h_nvtx_elec0->Fill(NVtx,wt);
           h_nvtx_all_elec0->Fill(nAllVertices,wt);
	   //           h_nvtx->Fill(NVtx,wt);
	   h_BestPhotonPhi_elec0->Fill(bestEMObj.Phi(),wt);
	   h_BestPhotonEta_elec0->Fill(bestEMObj.Eta(),wt);
           h_leadElectronPt_elec0->Fill(zvec.Pt(),wt);
           h2_ElectronEta_Phi_elec0->Fill(bestEMObj.Eta(),bestEMObj.Phi(),wt);
	   h2_trackElectronEta_Phi_elec0->Fill((*TAPElectronTracks)[minDrindx].Eta(),(*TAPElectronTracks)[minDrindx].Phi(),wt);
           h2_leadElectronEta_Phi_elec0->Fill(tagEMObj.Eta(),tagEMObj.Phi(),wt);
           h_ElectronEta_elec0->Fill(tagEMObj.Eta(),wt);
           h_ElectronPhi_elec0->Fill(tagEMObj.Phi(),wt);
           h_trackElectronPt_elec0->Fill((*TAPElectronTracks)[track_idx].Pt(),wt);
           h_trackElectronEta_elec0->Fill((*TAPElectronTracks)[track_idx].Eta(),wt);
           h_trackElectronPhi_elec0->Fill((*TAPElectronTracks)[track_idx].Phi(),wt);

	 }
     }
   //   else remain++;

  } // loop over entries
  //  newtree->AutoSave();
  // cout<<"No. of events rejected by Photon Pt > 100 : "<<phopt_rej<<endl;
  // cout<<"No. of events rejected by MET > 100 : "<<MET_rej<<endl;


  cout<<"No. of events passed by METfilters : "<<MET_rej<<endl;
  cout<<"No. of events before overlapping veto selections : "<<before_eletrig<<endl;
  //  cout<<"No. of events before triggers : "<<before_eletrig<<endl;
  cout<<"No. of events after triggers : "<<after_eletrig<<endl;
  cout<<"No. of events passed by Muon veto and iso muon and pion track veto : "<<lep<<endl;
  cout<<"No. of events with 1 electron : "<<one_e<<endl;
  cout<<"No. of events with 2 electrons : "<<two_e<<endl;
  cout<<"No. of events with 1 electron with tight id and gen e match: "<<one_e2<<endl;
  cout<<"No. of events with 1 tag e and 1 probe e: "<<two_e2<<endl;
  cout<<"No. of events with 1st e = tag e and 2nd e = probe e: "<<two_e3<<endl;
  cout<<"EM object is tag electron : "<<tag_ele<<endl;
  cout<<"EM object is probe EM object : "<<probe_ele<<endl;
  cout<<"No. of events after mt cut : "<<mt<<endl;
  cout<<"No. of events after dR(tag,probe)>0.2 : "<<iso<<endl;
  cout<<"No. of events after MET<200 cut : "<<met<<endl;
  cout<<"No. of events after ST>300 cut : "<<st<<endl;
  cout<<"No. of events after nJets>=2: "<<nSurvived<<endl;
  cout<<"EM object is photon : "<<npho<<endl;
  cout<<"EM object is electron : "<<nele<<endl;
  cout<<"Remaining EM object : "<<remain<<endl;
  cout<<"========================================"<<endl;
  cout<<"Cross-section : "<<CrossSection<<endl;
  cout<<"Weight ib pb-1 : "<<Weight<<endl;
   }


TLorentzVector Fakerate::getBestPhoton(){
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

bool Fakerate::check_eMatchedtoGamma(TLorentzVector bestPhoton){
  for(int i=0;i<Electrons->size();i++)
    {
      if( bestPhoton.DeltaR((*Electrons)[i]) < 0.1)
        return true;
    }
  return false;
}

double Fakerate::getGenLep(TLorentzVector bestPhoton){//MC only
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
