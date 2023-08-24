#!/bin/bash


#rm pdf/*
#rm png/*
#rm paper/*
#dir=pdf
#mkdir $dir
#sed -i "" "s#Preliminary#Supplementary#g" codes/*
########## for PAS ################
#sed -i "" "s#Simulation#Simulation Preliminary#g" codes/*
########## for paper #################
sed -i "" "s#Simulation Preliminary#Simulation#g" codes/*   

root -l -q codes/plotclosure_LL.C
root -l -q codes/plotratio_TF.C
root -l -q codes/plotclosure_FR.C
#root -l -q codes/printRK_0pho.C 
#root -l -q 'codes/plotclosure_multi.C("AllSBins_v6_CD_EW_50bin","full_Run2","v18",true,false)'

########## for PAS ################                                                                                                                                        
#sed -i "" "s#Simulation Preliminary#Simulation#g" codes/*
#sed -i "" "s#bf{}#bf{Preliminary}#g" codes/*
########## for paper #################
sed -i "" "s#bf{Preliminary}#bf{}#g" codes/*
###################################
root -l -q codes/printRK_0pho.C
root -l -q 'codes/plotdatavsMC_Zin.C("MET","full_Run2","v18",false,true)'
root -l -q 'codes/plotdatavsMC_Zin.C("invMass","full_Run2","v18",false,true)'
root -l -q 'codes/DataVsPredFit.C("rootoutput/SR_prefitPredictions_Run2_v4.root","CR")'
#root -l -q 'codes/smoothedObsExpLimits.C("rootoutput/signals/T5bbbbZg_sigsys_new3.root")'
#root -l -q 'codes/smoothedObsExpLimits.C("rootoutput/signals/T5qqqqHg_sigsys_new2.root")'
#root -l -q 'codes/smoothedObsExpLimits.C("rootoutput/signals/T5ttttZg_sigsys_new2.root")'
#root -l -q 'codes/smoothedObsExpLimits.C("rootoutput/signals/T6ttZg_sigsys_new2.root")'

########## for PAS ################    
#sed -i "" "s#cmsextralabel.SetTextSize(0)#cmsextralabel.SetTextSize(0.031)#g" codes/limit*
########## for paper #################
sed -i "" "s#cmsextralabel.SetTextSize(0.031)#cmsextralabel.SetTextSize(0)#g" codes/limit*
###################################    
python3.10 codes/limitplotter_TChiNG_combine_50BF.py rootoutput/signals/BF50N50G/ TChiNG
python3.10 codes/limitplotter_TChiNG_combine_100BF.py rootoutput/signals/TChiNG/ TChiNGnn
python3.10 codes/limitplotter_TChiWG_combine.py rootoutput/signals/TChiWG/ TChiWG

cp pdf/* ${dir}/.
