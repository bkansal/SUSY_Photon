#!/bin/sh

#################################
#######After using getPurity.C script, we will get PF ###########################                                                                                          
############################## 2nd run this shell file to get PF*N(Z->llgamma : data ##################################                                
############ Make sure applyPF=true in Z_invisible.cc ######################                                                                                               

rm -rf *v18.root
path=muon
./z_invisible Run2016_SingleMuon_data.txt Run2016_Muondata_CR_v18.root ${path}_data_2016
./z_invisible Run2017_SingleMuon_data.txt Run2017_Muondata_CR_v18.root ${path}_data_2017
./z_invisible Run2018_SingleMuon_data.txt Run2018_Muondata_CR_v18.root ${path}_data_2018
hadd -f Run2_Muondata_CR_v18.root Run201*_Muondata_CR_v18.root
cp *v18.root ${path}/.


rm -rf *v18.root
path=elec
./z_invisible Run2016_SingleElectron_data.txt Run2016_elecdata_CR_v18.root ${path}_data_2016
./z_invisible Run2017_SingleElectron_data.txt Run2017_elecdata_CR_v18.root ${path}_data_2017
./z_invisible Run2018_SingleElectron_data.txt Run2018_elecdata_CR_v18.root ${path}_data_2018
hadd -f Run2_elecdata_CR_v18.root Run201*_elecdata_CR_v18.root
cp *v18.root ${path}/.

mkdir data_PF
hadd -f data_PF/Run2_METdata_CR_v18.root elec/Run2_elecdata_CR_v18.root muon/Run2_Muondata_CR_v18.root

################################# 
#### To calculate SF = PF*N(Z->llgamma : data)/N(Z->llgamma : MC), run following code :
################################# 
root -l -q 'codes/plotclosure.C("AllSBins_v6_CD","full_Run2","v17","./",false,true)'
#com
