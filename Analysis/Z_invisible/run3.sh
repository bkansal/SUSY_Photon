#!/bin/sh

rm *CR.root
rm *CR_v18.root

#./z_invisible runlist_ZGTo2NuG_nlo_2016_v18.txt  ZGTo2NuG_nlo_2016_CR_v18.root    ZGTo2NuG_nlo_v17_2016
./z_invisible runlist_ZGTo2NuG_nlo_2016_v18.txt  ZGTo2NuG_nlo_2016_CR_v18.root    ZGToNuNuG_incl_nlo_v17_2016
./z_invisible runlist_ZJetsToNuNu_2016_v18.txt	ZJetsToNuNu_2016_CR_v18.root ZJetsToNuNu_incl_v17_2016
hadd -f ZJZGTo2Nu_2016_CR_v18.root ZGTo2NuG_nlo_2016_CR_v18.root ZJetsToNuNu_2016_CR_v18.root


#./z_invisible runlist_ZGTo2NuG_nlo_2017_v18.txt  ZGTo2NuG_nlo_2017_CR_v18.root    ZGTo2NuG_nlo_v17_2017
./z_invisible runlist_ZGTo2NuG_nlo_2017_v18.txt  ZGTo2NuG_nlo_2017_CR_v18.root    ZGToNuNuG_incl_nlo_v17_2017
./z_invisible runlist_ZJetsToNuNu_2017_v18.txt	ZJetsToNuNu_2017_CR_v18.root ZJetsToNuNu_incl_v17_2017
hadd -f ZJZGTo2Nu_2017_CR_v18.root ZGTo2NuG_nlo_2017_CR_v18.root ZJetsToNuNu_2017_CR_v18.root


#./z_invisible runlist_ZGTo2NuG_nlo_2018_v18.txt  ZGTo2NuG_nlo_2018_CR_v18.root    ZGTo2NuG_nlo_v17_2018
./z_invisible runlist_ZGTo2NuG_nlo_2018_v18.txt  ZGTo2NuG_nlo_2018_CR_v18.root    ZGToNuNuG_incl_nlo_v17_2018
./z_invisible runlist_ZJetsToNuNu_2018_v18.txt	ZJetsToNuNu_2018_CR_v18.root ZJetsToNuNu_incl_v17_2018
hadd -f ZJZGTo2Nu_2018_CR_v18.root ZGTo2NuG_nlo_2018_CR_v18.root ZJetsToNuNu_2018_CR_v18.root

hadd -f ZJZGTo2Nu_CR_v18.root ZJZGTo2Nu_201*_CR_v18.root
