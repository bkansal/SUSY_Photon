#!/bin/sh

############################## 1 st run this shell file to get Purity factor ##################################  
rm *CR.root
rm *CR_v18.root
path=muon

############ PF from MC events 
for path in muon elec
do
    rm *CR_v18.root
    mkdir ${path}
    ./z_invisible runlist_TTG_2016_v18.txt TTG_2016_CR_v18.root TTG_v17_2016_${path}
    ./z_invisible runlist_WG_2016_v18.txt WG_2016_CR_v18.root  WG_v17_2016_${path}
    ./z_invisible runlist_DYJetsToLL_2016_v18.txt   DYJetsToLL_2016_CR_v18.root  DYJetsToLL_v17_2016_${path}
    ./z_invisible runlist_ZGToLLG_nlo_2016_v18.txt	ZGToLLG_nlo_2016_CR_v18.root    ZGToLLG_nlo_v17_2016_${path}
    hadd -f ZJZGToLL_2016_CR_v18.root DYJetsToLL_2016_CR_v18.root ZGToLLG_nlo_2016_CR_v18.root 
    hadd -f TTWZJZGToLL_2016_CR_v18.root  ZJZGToLL_2016_CR_v18.root TTG_2016_CR_v18.root WG_2016_CR_v18.root
    
    ./z_invisible runlist_TTG_2017_v18.txt TTG_2017_CR_v18.root TTG_v17_2017_${path}
    ./z_invisible runlist_WG_2017_v18.txt WG_2017_CR_v18.root  WG_v17_2017_${path}
    ./z_invisible runlist_DYJetsToLL_2017_v18.txt   DYJetsToLL_2017_CR_v18.root  DYJetsToLL_v17_2017_${path}
    ./z_invisible runlist_ZGToLLG_nlo_2017_v18.txt  ZGToLLG_nlo_2017_CR_v18.root    ZGToLLG_v17_2017_${path}
    hadd -f ZJZGToLL_2017_CR_v18.root DYJetsToLL_2017_CR_v18.root ZGToLLG_nlo_2017_CR_v18.root
    hadd -f TTWZJZGToLL_2017_CR_v18.root  ZJZGToLL_2017_CR_v18.root TTG_2017_CR_v18.root WG_2017_CR_v18.root

    ./z_invisible runlist_TTG_2018_v18.txt TTG_2018_CR_v18.root TTG_v17_2018_${path}
    ./z_invisible runlist_WG_2018_v18.txt WG_2018_CR_v18.root  WG_v17_2018_${path}
    ./z_invisible runlist_DYJetsToLL_2018_v18.txt   DYJetsToLL_2018_CR_v18.root  DYJetsToLL_v17_2018_${path}
    ./z_invisible runlist_ZGToLLG_nlo_2018_v18.txt  ZGToLLG_nlo_2018_CR_v18.root    ZGToLLG_v17_2018_${path}
    hadd -f ZJZGToLL_2018_CR_v18.root DYJetsToLL_2018_CR_v18.root ZGToLLG_nlo_2018_CR_v18.root
    hadd -f TTWZJZGToLL_2018_CR_v18.root  ZJZGToLL_2018_CR_v18.root TTG_2018_CR_v18.root WG_2018_CR_v18.root
    
    hadd -f TTG_CR_v18.root TTG_201*_CR_v18.root
    hadd -f WG_CR_v18.root WG_201*_CR_v18.root
    hadd -f DYJetsToLL_CR_v18.root DYJetsToLL_201*_CR_v18.root
    hadd -f ZGToLLG_CR_v18.root ZGToLLG_nlo_201*_CR_v18.root
    hadd -f ZJZGToLL_CR_v18.root ZJZGToLL_201*_CR_v18.root
    hadd -f TTWZJZGToLL_CR_v18.root TTWZJZGToLL_201*_CR_v18.root
    cp *v18.root ${path}/.
done

############ Make sure applyPF=false in Z_invisible.cc ###################### 
############ PF from data events 
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

rm -rf *v18.root
path=elemu
./z_invisible Run2016_SingleMuon_data.txt Run2016_Muondata_CR_v18.root ${path}_data_2016
./z_invisible Run2017_SingleMuon_data.txt Run2017_Muondata_CR_v18.root ${path}_data_2017
./z_invisible Run2018_SingleMuon_data.txt Run2018_Muondata_CR_v18.root ${path}_data_2018
hadd -f Run2_Muondata_CR_v18.root Run201*_Muondata_CR_v18.root
cp *v18.root ${path}/.

mkdir data
mkdir elec_muon_data
hadd -f data/ZJZGToLL_CR_v18.root elec/ZJZGToLL_CR_v18.root muon/ZJZGToLL_CR_v18.root
hadd -f data/TTWZJZGToLL_CR_v18.root elec/TTWZJZGToLL_CR_v18.root muon/TTWZJZGToLL_CR_v18.root
hadd -f data/Run2_METdata_CR_v18.root elec/Run2_elecdata_CR_v18.root muon/Run2_Muondata_CR_v18.root
hadd -f elec_muon_data/Run2_METdata_CR_v18.root elec/Run2_elecdata_CR_v18.root muon/Run2_Muondata_CR_v18.root elemu/Run2_Muondata_CR_v18.root
root -l -q 'codes/getpurity.C("./")'

<<EOF
#######After using getPurity.C script, we will get PF ###########################
############################## 2nd run this shell file to get PF*N(Z->llgamma : data)/N(Z->llgamma : MC) ##################################  
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
root -l -q 'codes/plotclosure.C("AllSBins_v6_CD","full_Run2","v17","./",false,true)'
EOF

