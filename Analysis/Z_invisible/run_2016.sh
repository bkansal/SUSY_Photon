#!/bin/sh                                                                                                                       

rm *CR.root
rm *CR_v18.root

./z_invisible runlist_DYJetsToLL_2016_v18.txt   DYJetsToLL_2016_CR_v18.root  DYJetsToLL_v17_2016
./z_invisible runlist_ZGToLLG_2016_v18.txt      ZGToLLG_2016_CR_v18.root    ZGToLLG_v17_2016
hadd -f ZJZGToLL_2016_CR_v18.root DYJetsToLL_2016_CR_v18.root ZGToLLG_2016_CR_v18.root
./z_invisible runlist_ZGToNuNuG_2016_v18.txt    ZGToNuNuG_2016_CR_v18.root  ZGToNuNuG_v17_2016
./z_invisible runlist_ZJetsToNuNu_2016_v18.txt  ZJetsToNuNu_2016_CR_v18.root ZJetsToNuNu_v17_2016
hadd -f ZJZGToNuNu_2016_CR_v18.root ZGToNuNuG_2016_CR_v18.root ZJetsToNuNu_2016_CR_v18.root

