void printall(bool lowdphi=false,bool syst=false, TString year="full_Run2",int nbin=52, int xmin=0, int xmax=52)
{
  TFile *f1, *f2,*f3,*TF,*f4,*f5,*f6,*f7,*f8;
  TString filename,filename1,filename2,filename3,filename4,filename5,filename6,filename7;
  TH2D *cr_fr,*crdata_fr,*pred_sr_fr;
  TH1D *cr,*sr,*pred_sr, *crdata_sf,*pred_fr,*esf,*bsf,*nobsf,*pred_sr_esf,*pred_sr_bsf,*pred_sr_jec,*pred_sr_jer,*pred_sr_nojerc,*pred_sr_nosys;
  TH1D *tf;
  double tf_51[55],tf_err[55], cr_51[55], crdata_51[55], fr_mjb[55],sr_51[55],frerr_mjb[55],sf_mjb[55],esf_mjb[55],bsf_mjb[55];
  bool Tf=true, sys=true;
  TString path,path1,path_esf,path_bsf,path_jerc,path_jec,path_jer;
  if(lowdphi) {
    path1="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
    path="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_lowdphi_newBin2/";
    path_esf="rootoutput/eSFcheck/LL_eSFup/";
    path_bsf="rootoutput/eSFcheck/LL_bSFup/";
    path_jec="rootoutput/JERCsys_LL/withJECup/";
    path_jer="rootoutput/JERCsys_LL/withJECup/";
    path_jerc="rootoutput/JERCsys_LL/withoutJERC/";
    sys=false;
  }
  if(!lowdphi) {
    path1="rootoutput/newselec_LL_noISRjet_METfilters_EW_hadjetID_newPU_v18/TF_v7_usingfullRun2_BTagSF_SF_newBin2/";
    path1="rootoutput/new/nominal_fr/LL/";
    path="rootoutput/new/nominal_fr/LL/";
    path_esf="rootoutput/new/esfup/LL/";
    path_bsf="rootoutput/new/bsfup/LL/";
    path_jec="rootoutput/new/withJEC/LL/";
    path_jer="rootoutput/new/withJER/LL/";
    path_jerc="rootoutput/new/withoutjerc/LL/";
    sys=true;
  }
  
  int n=10;
  bool print=true;
  TFile *f_syserr= new TFile("factors/LL_sys_v1.root");
  
  if(!lowdphi && year=="full_Run2")    TF = TFile::Open("factors/lostlepton_highdphi.root","READ");
  if(lowdphi && year=="full_Run2")    TF = TFile::Open("factors/lostlepton_lowdphi.root","READ");
  tf=(TH1D*)TF->Get("tf_SP_2");
  
  filename  = path+"TTWGJ_CR_v18.root";
  filename1  = path+"Run2_METdata_CR_v18.root";
  filename2  = path1+"Run2_METdata_CR_v18.root";
  f1 = new TFile(filename);
  f2 = new TFile(filename1);
  f3 = new TFile(filename2);
  if(sys)
    {
      filename3  = path_esf+"Run2_METdata_CR_v18.root";
      filename4  = path_bsf+"Run2_METdata_CR_v18.root";
      /*
      filename5  = path_jec+"Run2_METdata_CR_v18.root";
      filename6  = path_jer+"Run2_METdata_CR_v18.root";
      */
      filename5  = "factors/LL_JECup_v2.root";
      filename6  = "factors/LL_JERup_v2.root";

  filename7  = path_jerc+"Run2_METdata_CR_v18.root";

      f4 = new TFile(filename3);
      f5 = new TFile(filename4); //bsfup
      f6 = new TFile(filename5); //jecup
      f7 = new TFile(filename6); //jerup
      f8 = new TFile(filename7); //nojerc                                                                                                                                   
    }
  TFile *fout;

  if(!lowdphi) fout=new TFile("Lostlepton_highdphi.root","recreate");
  if(lowdphi)  fout=new TFile("Lostlepton_lowdphi.root","recreate");
  if(!lowdphi && syst) fout=new TFile("Lostlepton_highdphi_sys.root","recreate");

  fout->cd();

  
  TH1D *h_fr= new TH1D("fr","FR in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_esfsys= new TH1D("esfsys","e SF sys in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_bsfsys= new TH1D("bsfsys","b SF sys in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_jecsys= new TH1D("jecsys","JEC sys in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_jersys= new TH1D("jersys","JER sys in 51 SR bins",nbin,xmin,xmax);

  TH1D *h_preddata= new TH1D("Preddata","Predicted events in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_preddata_err= new TH1D("Preddata_err","Error in Predicted events in 51 SR bins",nbin,xmin,xmax);
  TH1D *AllSBins_v6_CD_EW_50bin_elec1_closure = new TH1D("AllSBins_v6_CD_EW_50bin_elec1_closure","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  TH1D *AllSBins_v6_CD_EW_50bin_elec1 = new TH1D("AllSBins_v6_CD_EW_50bin_elec1","search bins v6:[(WTag : [65,105]),(HTag : [105,140])]",52,0,52);
  TH1D *h_SRmc= new TH1D("SRmc","Expected events in 51 SR bins",nbin,xmin,xmax);
  TH1D *h_ST=new TH1D("ST","ST",400,0,4000);
  TH1D *h_MET=new TH1D("MET","MET",200,0,2000);
  TH1D *h_BTags=new TH1D("nBTags","no. of B tags",10,0,10);
  TH1D *h_BestPhotonPt=new TH1D("BestPhotonPt","Pt of the Best Photon",150,0,1500);
  TH1D *h_hadAk8Mass=new TH1D("hadAk8Mass","Soft dropped Mass of AK8 Jet",1000,0,300);
  TH1D *h_nJets=new TH1D("nJets","no. of hadronic jets",10,0,10);

  
  char* sname = new char[200];
  ///////////////// FR error calculation //////////
  TH1D *crdata  = (TH1D*)f1->Get("AllSBins_v7_CD_SP_elec1");

  cr     = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec1");
  pred_sr     = (TH1D*)f2->Get("AllSBins_v6_CD_EW_50bin_elec1_closure"); //SF x FR x N(Data:CR)
  h_ST  = (TH1D*)f2->Get("ST_elec1_closure");
  h_MET  = (TH1D*)f2->Get("MET_elec1_closure");
  h_nJets  = (TH1D*)f2->Get("nJets_elec1_closure");
  h_BTags  = (TH1D*)f2->Get("nBTags_elec1_closure");
  h_BestPhotonPt  = (TH1D*)f2->Get("BestPhotonPt_elec1_closure");
  h_hadAk8Mass  = (TH1D*)f2->Get("hadAk8Mass_elec1_closure");

  sr     = (TH1D*)f1->Get("AllSBins_v6_CD_EW_50bin_elec0");
  pred_sr_nosys     = (TH1D*)f3->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
  TH1D *syserr = (TH1D*)f_syserr->Get("JERC");
  if(sys){
    pred_sr_esf     = (TH1D*)f4->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
    pred_sr_bsf     = (TH1D*)f5->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
    /*
    pred_sr_jec     = (TH1D*)f6->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
    pred_sr_jer     = (TH1D*)f7->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
    */
    pred_sr_jec     = (TH1D*)f6->Get("JERC");
    pred_sr_jer     = (TH1D*)f7->Get("JERC");
    pred_sr_nojerc     = (TH1D*)f8->Get("AllSBins_v6_CD_EW_50bin_elec1_closure");
  }
  for(int q=0; q<=46; q++)
    {
      cout<<tf->GetBinContent(q)<<endl;      
      if(q>=1 && q<=7)  {   tf_51[q]=(tf->GetBinContent(1)*crdata->GetBinContent(1) + tf->GetBinContent(2)*crdata->GetBinContent(2) +  tf->GetBinContent(3)*crdata->GetBinContent(3))/(crdata->GetBinContent(1) + crdata->GetBinContent(2) + crdata->GetBinContent(3)); }
      else if(q>7 && q<=13) tf_51[q]=tf->GetBinContent(4);
      else if(q>13 && q<=18) tf_51[q]=tf->GetBinContent(5);
      else if(q>18 && q<=23) tf_51[q]=tf->GetBinContent(6);
      else if(q>23 && q<=28) tf_51[q]=tf->GetBinContent(7);
      else if(q>28 && q<=33) tf_51[q]=tf->GetBinContent(8);
      else if(q>33 && q<=39) tf_51[q]=tf->GetBinContent(9);
      else if(q>39 && q<=45) tf_51[q]=tf->GetBinContent(10);

      if(q>=1 && q<=7)  {   tf_err[q]=pow((tf->GetBinError(1)*tf->GetBinError(1)*crdata->GetBinContent(1) + tf->GetBinError(2)*tf->GetBinError(2)*crdata->GetBinContent(2) +  tf->GetBinError(3)*tf->GetBinError(3)*crdata->GetBinContent(3))/(crdata->GetBinContent(1) + crdata->GetBinContent(2) + crdata->GetBinContent(3)),0.5); }
      else if(q>7 && q<=13) tf_err[q]=tf->GetBinError(4);
      else if(q>13 && q<=18) tf_err[q]=tf->GetBinError(5);
      else if(q>18 && q<=23) tf_err[q]=tf->GetBinError(6);
      else if(q>23 && q<=28) tf_err[q]=tf->GetBinError(7);
      else if(q>28 && q<=33) tf_err[q]=tf->GetBinError(8);
      else if(q>33 && q<=39) tf_err[q]=tf->GetBinError(9);
      else if(q>39 && q<=45) tf_err[q]=tf->GetBinError(10);
			       
      if(q>=1 && q<=7) {int i=q+1 ; tf_51[q]= pred_sr->GetBinContent(i)/cr->GetBinContent(i);  }
      fr_mjb[q]=tf_51[q];
      frerr_mjb[q]=tf_err[q];

    }
  
  n=46;
  print=false;

  cout<<"Fr(MET, nj, nb) : "<<endl;
  for(int i=1;i<n;i++)
    cout<<fr_mjb[i]<<endl;//" : "<<pred_sr->GetBinContent(i+1)/cr->GetBinContent(i+1)<<endl;

  cout<<"dFr(MET, nj, nb) : "<<endl;
  for(int i=1;i<n;i++)
    cout<<frerr_mjb[i]<<endl;
  // if(print){
  for(int i=1;i<n;i++)
    h_fr->SetBinContent(i+1,fr_mjb[i]);
  for(int i=1;i<n;i++)
    h_fr->SetBinError(i+1,frerr_mjb[i]);	     

  cout<<"Ndata in CR region"<<endl;
  for(int i=1;i<n;i++)
    {
      cout<<cr->GetBinContent(i+1)<<endl;
      AllSBins_v6_CD_EW_50bin_elec1->Fill(i,cr->GetBinContent(i+1));
      AllSBins_v6_CD_EW_50bin_elec1->SetBinContent(i+1,cr->GetBinContent(i+1));
	    
    }
  cout<<"dNdata in CR region"<<endl;
  for(int i=1;i<n;i++)
    {
      cout<<cr->GetBinError(i+1)<<endl;
      AllSBins_v6_CD_EW_50bin_elec1->SetBinError(i+1,cr->GetBinError(i+1));  
    }
	
  cout<<"NPredicted in SR region"<<endl;
  for(int i=0;i<n;i++)
    {
      h_preddata->Fill(i,cr->GetBinContent(i+1)*fr_mjb[i]);
      h_preddata->SetBinContent(i+1,pred_sr->GetBinContent(i+1));
      //      h_preddata->Fill(i,pred_sr->GetBinContent(i+1));
      cout<<h_preddata->GetBinContent(i+1)<<endl;
    }
  cout<<"dNPredicted in SR region"<<endl;

  for(int i=1;i<n;i++)
    {
      //      cout<<i<<" : "<<cr->GetBinContent(i+1)<<" : "<<syserr->GetBinError(i)<<endl;
           cout<<pow((pow(cr->GetBinContent(i+1)*frerr_mjb[i],2) + pow(cr->GetBinError(i+1)*fr_mjb[i],2)),0.5)<<endl;
      h_preddata_err->Fill(i,pow((pow(cr->GetBinContent(i+1)*frerr_mjb[i],2) + pow(cr->GetBinError(i+1)*fr_mjb[i],2)),0.5));
      h_preddata->SetBinError(i+1,pow((pow(cr->GetBinContent(i+1)*frerr_mjb[i],2) + pow(cr->GetBinError(i+1)*fr_mjb[i],2)),0.5));
      if(!lowdphi && syst) h_preddata->SetBinError(i+1,pred_sr->GetBinContent(i+1)*pow((pow(cr->GetBinError(i+1)/cr->GetBinContent(i+1),2)+pow(frerr_mjb[i]/fr_mjb[i],2)+ pow(syserr->GetBinError(i),2)),0.5));
      else h_preddata->SetBinError(i+1,pow((pow(cr->GetBinContent(i+1)*frerr_mjb[i],2) + pow(cr->GetBinError(i+1)*fr_mjb[i],2)),0.5));
      
    }
      
  cout<<"N exp. using MC in SR region"<<endl;
  for(int i=1;i<n;i++)
    h_SRmc->Fill(i,sr->GetBinContent(i+1));
      
  for(int i=1;i<n;i++)
    {
      cout<<i<<" & "<<setprecision(5)<<cr->GetBinContent(i+1)<<" &  "<<setprecision(3)<<h_fr->GetBinContent(i+1)<<" $\pm$  "<<setprecision(3)<<h_fr->GetBinError(i+1)<<" & "<<setprecision(3)<<h_preddata->GetBinContent(i+1)<<" $\pm$  "<<setprecision(3)<<h_preddata->GetBinError(i+1)<<" \\ "<<endl;  
    }
  //      }
  if(sys)
    {
      for(int i=1;i<=n;i++)
	{
	  /*
          h_esfsys->SetBinContent(i+1,pow(pow(h_preddata->GetBinError(i+1),2)+pow(pred_sr_esf->GetBinContent(i+1)-h_preddata->GetBinContent(i+1),2),0.5)/h_preddata->GetBinContent(i+1));
          h_bsfsys->SetBinContent(i+1,pow(pow(h_preddata->GetBinError(i+1),2)+pow(pred_sr_bsf->GetBinContent(i+1)-h_preddata->GetBinContent(i+1),2),0.5)/h_preddata->GetBinContent(i+1));
          h_jecsys->SetBinContent(i+1,(pow(pow(h_preddata->GetBinError(i+1),2)+pow(pred_sr_jec->GetBinContent(i+1)-h_preddata->GetBinContent(i+1),2),0.5))/h_preddata->GetBinContent(i+1));
         h_jersys->SetBinContent(i+1,(pow(pow(h_preddata->GetBinError(i+1),2)+pow(pred_sr_jer->GetBinContent(i+1)-h_preddata->GetBinContent(i+1),2),0.5))/h_preddata->GetB\
inContent(i+1));
	  */

	  h_esfsys->SetBinContent(i+1,abs(h_preddata->GetBinContent(i+1)-pred_sr_esf->GetBinContent(i+1))/h_preddata->GetBinContent(i+1));
	  h_bsfsys->SetBinContent(i+1,abs(h_preddata->GetBinContent(i+1)-pred_sr_bsf->GetBinContent(i+1))/h_preddata->GetBinContent(i+1));
	  h_jecsys->SetBinContent(i+1,abs(pred_sr_jec->GetBinError(i+1)));
          h_jersys->SetBinContent(i+1,abs(pred_sr_jer->GetBinError(i+1)));
	 
	}
      cout<<"systematics : "<<sys<<endl;
      cout<<"///////  ======= Systematics for electron SF ==============//"<<endl;
      for(int i=1;i<=n;i++)
	//	cout<<setprecision(6)<<pred_sr_bsf->GetBinContent(i+1)<<endl;  
		cout<<setprecision(6)<<h_esfsys->GetBinContent(i+1)<<endl;
      //cout<<setprecision(6)<<pred_sr_nosys->GetBinContent(i+1)<<" : "<<pred_sr_esf->GetBinContent(i+1)<<" : "<<h_esfsys->GetBinContent(i+1)<<endl;

      cout<<"///////  ======= Systematics for bTag SF ==============//"<<endl;
      for(int i=1;i<=n;i++)
	cout<<setprecision(6)<<h_bsfsys->GetBinContent(i+1)<<endl;
	//cout<<setprecision(6)<<pred_sr_nosys->GetBinContent(i+1)<<" : "<<pred_sr_bsf->GetBinContent(i+1)<<" : "<<h_bsfsys->GetBinContent(i+1)<<endl;
      cout<<"///////  ======= Systematics for JEC up ==============//"<<endl;
      vector<double> max;
      for(int i=1;i<n;i++)
        cout<<setprecision(6)<<h_jecsys->GetBinContent(i+1)<<endl;

      cout<<"///////  ======= Systematics for JER up ==============//"<<endl;
      for(int i=1;i<n;i++)
	cout<<setprecision(6)<<h_jersys->GetBinContent(i+1)<<endl;
      
      /*      
      float average = accumulate( max.begin(), max.end(), 0.0)/max.size();
      cout<<" Maximum uncertainty = "<<*max_element(max.begin(), max.end())<<endl;
      cout<<" Average uncertainty = "<<average<<endl;
      */
      
    }  
    

  h_preddata->Write();
  h_preddata_err->Write();
  h_SRmc->Write();
  h_fr->Write();
  h_esfsys->Write();
  h_bsfsys->Write();
  h_jecsys->Write();
  h_jersys->Write();
  h_MET->Write("MET");
  h_nJets->Write("nJets");
  h_ST->Write("ST");
  h_BTags->Write("nBTags");
  h_BestPhotonPt->Write("BestPhotonPt");
  h_hadAk8Mass->Write("hadAk8Mass");


  AllSBins_v6_CD_EW_50bin_elec1->Write();
  AllSBins_v6_CD_EW_50bin_elec1_closure = (TH1D*)h_preddata->Clone("AllSBins_v6_CD_EW_50bin_elec1_closure");
  AllSBins_v6_CD_EW_50bin_elec1_closure->Write();
      
  TString METbin[7]={"200 - 300","300 - 370","370 - 450","450 - 600","600 - 750","750 - 900"," $\\ge$900 "};
  TString METbin2[6]={"200 - 300","300 - 370","370 - 450","450 - 600","600 - 750"," $\\ge$750 "};
  TString METbin3[5]={"200 - 300","300 - 370","370 - 450","450 - 600"," $\\ge$600 "};

  TString Nbj[8]={ "2 $\\leq N_{jets} \\leq$ 4 , $N_{b-jets}$ = 0 ","5 $\\leq N_{jets} \\leq$ 6 , $N_{b-jets}$ = 0 "," $ N_{jets} \\geq$ 7 , $N_{b-jets}$ = 0 ", "2 $\\leq N_{jets} \\leq$ 4 , $N_{b-jets} > $ 0 ","5 $\\leq N_{jets} \\leq$ 6 , $N_{b-jets} > $ 0 "," $ N_{jets} \\geq$ 7 , $N_{b-jets} > $  0 ","EW : W tag"," EW : H tag"};
  int k=1;
  for(int i=0;i<8;i++)
    {
      if(i==0){
	cout<<"\\hline"<<endl;
	cout<<"\\multirow{7}{*}{"<<Nbj[i]<<"}"<<endl;
	for(int j=0 ; j<7 ; j++)
	  {
	    k=k+1;
	    
	    cout<<" & "<<setprecision(3)<<METbin[j]<<" & "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(k)<<" & "<<h_fr->GetBinContent(k)<<" $\\pm$ "<<h_fr->GetBinError(k)<<" & "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(k)<<" $\\pm$ "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(k)<<" \\ "<<endl;
	  }
      }
      else if(i==1){
        cout<<"\\multirow{6}{*}{"<<Nbj[i]<<"}"<<endl;
        for(int j=0 ; j<6 ; j++)
	  {
            k=k+1;
            cout<<" & "<<setprecision(3)<<METbin2[j]<<" & "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(k)<<" & "<<h_fr->GetBinContent(k)<<" $\\pm$ "<<h_fr->GetBinError(k)<<" & "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(k)<<" $\\pm$ "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(k)<<" \\ "<<endl;

	  }
      }
      else if(i<6){
        cout<<"\\multirow{5}{*}{"<<Nbj[i]<<"}"<<endl;
        for(int j=0 ; j<5 ; j++)
          {
            k=k+1;
            cout<<" & "<<setprecision(3)<<METbin3[j]<<" & "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(k)<<" & "<<h_fr->GetBinContent(k)<<" $\\pm$ "<<h_fr->GetBinError(k)<<" & "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(k)<<" $\\pm$ "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(k)<<" \\ "<<endl;
	  }
      }
      else{
        cout<<"\\multirow{6}{*}{"<<Nbj[i]<<"}"<<endl;
        for(int j=0 ; j<6 ; j++)
          {
            k=k+1;
            cout<<" & "<<setprecision(3)<<METbin2[j]<<" & "<<AllSBins_v6_CD_EW_50bin_elec1->GetBinContent(k)<<" & "<<h_fr->GetBinContent(k)<<" $\\pm$ "<<h_fr->GetBinError(k)<<" & "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinContent(k)<<" $\\pm$ "<<AllSBins_v6_CD_EW_50bin_elec1_closure->GetBinError(k)<<" \\ "<<endl;

	  }
      }
      cout<<"\\hline"<<endl;
    }

  TFile *TF1 = TFile::Open("factors/lostlepton_highdphi_2016.root","READ");  
  TFile *TF2 = TFile::Open("factors/lostlepton_highdphi_2017.root","READ");
  TFile *TF3 = TFile::Open("factors/lostlepton_highdphi_2018.root","READ");
  TH1D *  tf1=(TH1D*)TF1->Get("tf_SP_2");
  TH1D *  tf2=(TH1D*)TF2->Get("tf_SP_2");
  TH1D *  tf3=(TH1D*)TF3->Get("tf_SP_2");
  TString Nbj_[11]={" 0 & 2 "," 0 & 3 "," 0 & 4 "," 0 & 5-6 "," 0 & $\\geq$7 & $>$200"," $\\geq$ 1 & 2-4 "," $\\geq$ 1 & 5-6 "," $\\geq$ 1 & $\\geq$7 "," \\multicolumn{2}{c}{\\Wtag} "," \\multicolumn{2}{c}{\\Htag} "};
  for(int j=1 ; j<11 ; j++)
    {
      if(j<9)      cout<<setprecision(3)<<" & "<<Nbj_[j-1]<<" & "<<tf1->GetBinContent(j)<<" $\\pm$ "<<tf1->GetBinError(j)<<" & "<<tf2->GetBinContent(j)<<" $\\pm$ "<<tf2->GetBinError(j)<<" & "<<tf3->GetBinContent(j)<<" $\\pm$ "<<tf3->GetBinError(j)<<" & "<<tf->GetBinContent(j)<<" $\\pm$ "<<tf->GetBinError(j)<<" \\ "<<endl;
      else    cout<<setprecision(4)<<" & "<<Nbj_[j-1]<<" & "<<tf1->GetBinContent(j)<<" $\\pm$ "<<tf1->GetBinError(j)<<" & "<<tf2->GetBinContent(j)<<" $\\pm$ "<<tf2->G\
etBinError(j)<<" & "<<tf3->GetBinContent(j)<<" $\\pm$ "<<tf3->GetBinError(j)<<" & "<<tf->GetBinContent(j)<<" $\\pm$ "<<tf->GetBinError(j)<<" \\ "<<endl;
    }
}
