#!/bin/sh
###################### Used to calculate TF which is N(Z->nu nugamma : MC)/N(Z->llgamma : MC)
rm *CR.root
rm *CR_v18.root

./z_invisible runlist_DYJetsToLL_2016_v18.txt   DYJetsToLL_2016_CR_v18.root  DYJetsToLL_v17_2016
#./z_invisible runlist_ZGToLLG_2016_v18.txt  ZGToLLG_lo_2016_CR_v18.root    ZGToLLG_lo_v17_2016
./z_invisible runlist_ZGToLLG_nlo_2016_v18.txt  ZGToLLG_nlo_2016_CR_v18.root    ZGToLLG_nlo_v17_2016
hadd -f ZJZGToLL_2016_CR_v18.root DYJetsToLL_2016_CR_v18.root ZGToLLG_nlo_2016_CR_v18.root
./z_invisible runlist_ZGToNuNuG_nlo_2016_v18.txt  ZGToNuNuG_nlo_2016_CR_v18.root    ZGToNuNuG_nlo_v17_2016
./z_invisible runlist_ZJetsToNuNu_2016_v18.txt	ZJetsToNuNu_2016_CR_v18.root ZJetsToNuNu_v17_2016
hadd -f ZJZGToNuNu_2016_CR_v18.root ZGToNuNuG_nlo_2016_CR_v18.root ZJetsToNuNu_2016_CR_v18.root

#<<com
./z_invisible runlist_DYJetsToLL_2017_v18.txt   DYJetsToLL_2017_CR_v18.root  DYJetsToLL_v17_2017
#./z_invisible runlist_ZGToLLG_2017_v18.txt  ZGToLLG_lo_2017_CR_v18.root    ZGToLLG_lo_v17_2017
./z_invisible runlist_ZGToLLG_nlo_2017_v18.txt  ZGToLLG_nlo_2017_CR_v18.root    ZGToLLG_nlo_v17_2017
hadd -f ZJZGToLL_2017_CR_v18.root DYJetsToLL_2017_CR_v18.root ZGToLLG_nlo_2017_CR_v18.root 
./z_invisible runlist_ZGToNuNuG_nlo_2017_v18.txt  ZGToNuNuG_nlo_2017_CR_v18.root    ZGToNuNuG_nlo_v17_2017
./z_invisible runlist_ZJetsToNuNu_2017_v18.txt	ZJetsToNuNu_2017_CR_v18.root ZJetsToNuNu_v17_2017
hadd -f ZJZGToNuNu_2017_CR_v18.root ZGToNuNuG_nlo_2017_CR_v18.root ZJetsToNuNu_2017_CR_v18.root

./z_invisible runlist_DYJetsToLL_2018_v18.txt   DYJetsToLL_2018_CR_v18.root  DYJetsToLL_v17_2018
#./z_invisible runlist_ZGToLLG_2018_v18.txt  ZGToLLG_lo_2018_CR_v18.root    ZGToLLG_lo_v17_2018
./z_invisible runlist_ZGToLLG_nlo_2018_v18.txt  ZGToLLG_nlo_2018_CR_v18.root    ZGToLLG_nlo_v17_2018
hadd -f ZJZGToLL_2018_CR_v18.root DYJetsToLL_2018_CR_v18.root ZGToLLG_nlo_2018_CR_v18.root 
./z_invisible runlist_ZGToNuNuG_nlo_2018_v18.txt  ZGToNuNuG_nlo_2018_CR_v18.root    ZGToNuNuG_nlo_v17_2018
./z_invisible runlist_ZJetsToNuNu_2018_v18.txt	ZJetsToNuNu_2018_CR_v18.root ZJetsToNuNu_v17_2018
hadd -f ZJZGToNuNu_2018_CR_v18.root ZGToNuNuG_nlo_2018_CR_v18.root ZJetsToNuNu_2018_CR_v18.root

hadd -f ZJZGToNuNu_CR_v18.root ZJZGToNuNu_201*_CR_v18.root
hadd -f ZJZGToLL_CR_v18.root ZJZGToLL_201*_CR_v18.root
hadd -f DYJetsToLL_CR_v18.root DYJetsToLL_201*_CR_v18.root
hadd -f ZGToLLG_CR_v18.root ZGToLLG_nlo_201*_CR_v18.root
hadd -f ZGToNuNuG_CR_v18.root ZGToNuNuG_nlo_201*_CR_v18.root

#com
