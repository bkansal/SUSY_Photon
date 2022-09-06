#!/bin/sh                                                                                                             
                                                      
#./cleaUpBatchFiles.sh                                                                                                                                                                       
currdir=${pwd}                                                                                                                                                                             


#####-=]=========== hadd =============                                                                                                                                     

dir=withoutJERC
path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/Zinvisible/${dir}          
cd ${path}
hadd -f ZGTo2NuG_nlo_2016_CR_v18.root Summer16v3.ZGTo2NuG*  
hadd -f ZJetsToNuNu_2016_CR_v18.root Summer16v3.ZJetsToNuNu*
hadd -f ZJZGTo2Nu_2016_CR_v18.root ZGTo2NuG_nlo_2016_CR_v18.root ZJetsToNuNu_2016_CR_v18.root

hadd -f ZGTo2NuG_nlo_2017_CR_v18.root  Fall17.ZGTo2NuG* 
hadd -f ZJetsToNuNu_2017_CR_v18.root Fall17.ZJetsToNuNu*
hadd -f ZJZGTo2Nu_2017_CR_v18.root ZGTo2NuG_nlo_2017_CR_v18.root ZJetsToNuNu_2017_CR_v18.root

hadd -f ZGTo2NuG_nlo_2018_CR_v18.root Autumn18.ZGTo2NuG*
hadd -f ZJetsToNuNu_2018_CR_v18.root Autumn18.ZJetsToNuNu*
hadd -f ZJZGTo2Nu_2018_CR_v18.root ZGTo2NuG_nlo_2018_CR_v18.root ZJetsToNuNu_2018_CR_v18.root

hadd -f ZJZGTo2Nu_CR_v18.root ZJZGTo2Nu_201*_CR_v18.root

rm -rf Summer16v3*
rm -rf Fall17.*.root                                                                                                                                                                       
rm -rf Autumn18.*.root        
cd ${currdir}



<<EOF 

dir=withJEC
path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/Zinvisible/${dir}_muon
./z_invisible Run2016_SingleMuon_data.txt Run2016_Muondata_CR_v18.root muon_data_2016
./z_invisible Run2017_SingleMuon_data.txt Run2017_Muondata_CR_v18.root muon_data_2017
./z_invisible Run2018_SingleMuon_data.txt Run2018_Muondata_CR_v18.root muon_data_2018
hadd -f Run2_Muondata_CR_v18.root Run201*_Muondata_CR_v18.root
cp Run2*_Muondata_CR_v18.root ${path}/.

path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/Zinvisible/${dir}_elec
./z_invisible Run2016_SingleElectron_data.txt Run2016_elecdata_CR_v18.root elec_data_2016
./z_invisible Run2017_SingleElectron_data.txt Run2017_elecdata_CR_v18.root elec_data_2017
./z_invisible Run2018_SingleElectron_data.txt Run2018_elecdata_CR_v18.root elec_data_2018
hadd -f Run2_elecdata_CR_v18.root Run201*_elecdata_CR_v18.root
cp Run2*_elecdata_CR_v18.root ${path}/.

<<EOF 


path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/Zinvisible/${dir}_muon
cd ${path}
hadd -f TTG_2016_CR_v18.root Summer16v3.TTGJets*.root
hadd -f WG_2016_CR_v18.root Summer16v3.WGJets*.root
hadd -f ZGToLLG_nlo_2016_CR_v18.root Summer16v3.ZGTo2LG*.root
hadd -f DYJetsToLL_2016_CR_v18.root Summer16v3.DY*.root
hadd -f ZJZGToLL_2016_CR_v18.root ZGToLLG_nlo_2016_CR_v18.root DYJetsToLL_2016_CR_v18.root
hadd -f TTWZJZGToLL_2016_CR_v18.root  ZJZGToLL_2016_CR_v18.root TTG_2016_CR_v18.root  WG_2016_CR_v18.root

hadd -f TTG_2017_CR_v18.root Fall17.TTGJets*.root
hadd -f WG_2017_CR_v18.root Fall17.WGJets*.root
hadd -f ZGToLLG_nlo_2017_CR_v18.root Fall17.ZGTo2LG*.root
hadd -f DYJetsToLL_2017_CR_v18.root Fall17.DY*.root
hadd -f ZJZGToLL_2017_CR_v18.root ZGToLLG_nlo_2017_CR_v18.root DYJetsToLL_2017_CR_v18.root
hadd -f TTWZJZGToLL_2017_CR_v18.root  ZJZGToLL_2017_CR_v18.root TTG_2017_CR_v18.root  WG_2017_CR_v18.root

hadd -f TTG_2018_CR_v18.root Autumn18.TTGJets*.root
hadd -f WG_2018_CR_v18.root Autumn18.WGJets*.root
hadd -f ZGToLLG_nlo_2018_CR_v18.root Autumn18.ZGTo2LG*.root
hadd -f DYJetsToLL_2018_CR_v18.root Autumn18.DY*.root
hadd -f ZJZGToLL_2018_CR_v18.root ZGToLLG_nlo_2018_CR_v18.root DYJetsToLL_2018_CR_v18.root
hadd -f TTWZJZGToLL_2018_CR_v18.root  ZJZGToLL_2018_CR_v18.root TTG_2018_CR_v18.root  WG_2018_CR_v18.root

hadd -f TTG_CR_v18.root TTG_201*_CR_v18.root
hadd -f WG_CR_v18.root WG_201*_CR_v18.root
hadd -f DYJetsToLL_CR_v18.root DYJetsToLL_201*_CR_v18.root
hadd -f ZGToLLG_CR_v18.root ZGToLLG_nlo_201*_CR_v18.root
hadd -f ZJZGToLL_CR_v18.root ZJZGToLL_201*_CR_v18.root
hadd -f TTWZJZGToLL_CR_v18.root TTWZJZGToLL_201*_CR_v18.root

rm -rf Summer16v3.*.root
rm -rf Fall17.*.root
rm -rf Autumn18.*.root

cd ${currdir}

path=/eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/Zinvisible/${dir}_elec
cd ${path}
hadd -f TTG_2016_CR_v18.root Summer16v3.TTGJets*.root
hadd -f WG_2016_CR_v18.root Summer16v3.WGJets*.root
hadd -f ZGToLLG_nlo_2016_CR_v18.root Summer16v3.ZGTo2LG*.root
hadd -f DYJetsToLL_2016_CR_v18.root Summer16v3.DY*.root
hadd -f ZJZGToLL_2016_CR_v18.root ZGToLLG_nlo_2016_CR_v18.root DYJetsToLL_2016_CR_v18.root
hadd -f TTWZJZGToLL_2016_CR_v18.root  ZJZGToLL_2016_CR_v18.root TTG_2016_CR_v18.root  WG_2016_CR_v18.root

hadd -f TTG_2017_CR_v18.root Fall17.TTGJets*.root
hadd -f WG_2017_CR_v18.root Fall17.WGJets*.root
hadd -f ZGToLLG_nlo_2017_CR_v18.root Fall17.ZGTo2LG*.root
hadd -f DYJetsToLL_2017_CR_v18.root Fall17.DY*.root
hadd -f ZJZGToLL_2017_CR_v18.root ZGToLLG_nlo_2017_CR_v18.root DYJetsToLL_2017_CR_v18.root
hadd -f TTWZJZGToLL_2017_CR_v18.root  ZJZGToLL_2017_CR_v18.root TTG_2017_CR_v18.root  WG_2017_CR_v18.root

hadd -f TTG_2018_CR_v18.root Autumn18.TTGJets*.root
hadd -f WG_2018_CR_v18.root Autumn18.WGJets*.root
hadd -f ZGToLLG_nlo_2018_CR_v18.root Autumn18.ZGTo2LG*.root
hadd -f DYJetsToLL_2018_CR_v18.root Autumn18.DY*.root
hadd -f ZJZGToLL_2018_CR_v18.root ZGToLLG_nlo_2018_CR_v18.root DYJetsToLL_2018_CR_v18.root
hadd -f TTWZJZGToLL_2018_CR_v18.root  ZJZGToLL_2018_CR_v18.root TTG_2018_CR_v18.root  WG_2018_CR_v18.root

hadd -f TTG_CR_v18.root TTG_201*_CR_v18.root
hadd -f WG_CR_v18.root WG_201*_CR_v18.root
hadd -f DYJetsToLL_CR_v18.root DYJetsToLL_201*_CR_v18.root
hadd -f ZGToLLG_CR_v18.root ZGToLLG_nlo_201*_CR_v18.root
hadd -f ZJZGToLL_CR_v18.root ZJZGToLL_201*_CR_v18.root
hadd -f TTWZJZGToLL_CR_v18.root TTWZJZGToLL_201*_CR_v18.root

rm -rf Summer16v3.*.root
rm -rf Fall17.*.root
rm -rf Autumn18.*.root

cd ${currdir}
