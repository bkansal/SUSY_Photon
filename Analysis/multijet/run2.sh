#!/bin/sh


rm *_v18.root

./mulijet runlist_GJets_DR_2016_v18.txt GJets_DR_2016_CR_v18.root GJetsDR_v17_2016
#./mulijet runlist_GJets_HT_2016_v18.txt GJets_HT_2016_CR_v18.root GJetsHT_v17_2016
./mulijet runlist_QCD_2016_v18.txt QCD_2016_CR_v18.root QCD_v17_2016
hadd -f GJetsQCD_new_2016_v18.root GJets_DR_2016_CR_v18.root QCD_2016_CR_v18.root
#hadd -f GJetsHTQCD_new_2016_v18.root GJets_HT_2016_CR_v18.root QCD_2016_CR_v18.root

./mulijet runlist_GJets_DR_2017_v18.txt GJets_DR_2017_CR_v18.root GJetsDR_v17_2017
#./mulijet runlist_GJets_HT_2017_v18.txt GJets_HT_2017_CR_v18.root GJetsHT_v17_2017
./mulijet runlist_QCD_2017_v18.txt QCD_2017_CR_v18.root QCD_v17_2017
hadd -f GJetsQCD_new_2017_v18.root GJets_DR_2017_CR_v18.root QCD_2017_CR_v18.root
#hadd -f GJetsHTQCD_new_2017_v18.root GJets_HT_2017_CR_v18.root QCD_2017_CR_v18.root

./mulijet runlist_GJets_DR_2018_v18.txt GJets_DR_2018_CR_v18.root GJetsDR_v17_2018
#./mulijet runlist_GJets_HT_2018_v18.txt GJets_HT_2018_CR_v18.root GJetsHT_v17_2018
./mulijet runlist_QCD_2018_v18.txt QCD_2018_CR_v18.root QCD_v17_2018
hadd -f GJetsQCD_new_2018_v18.root GJets_DR_2018_CR_v18.root  QCD_2018_CR_v18.root
#hadd -f GJetsHTQCD_new_2018_v18.root GJets_HT_2018_CR_v18.root QCD_2018_CR_v18.root


hadd -f GJetsQCD_new_v18.root GJetsQCD_new_201*_v18.root
#hadd -f GJetsHTQCD_new_v18.root GJetsHTQCD_new_201*_v18.root

#./mulijet Run2016_SingleJetHT_data.txt Run2016_METdata_CR_v18.root data_2016
./mulijet Run2016_MET_data.txt Run2016_METdata_CR_v18.root data_2016                 
./mulijet Run2017_MET_data.txt Run2017_METdata_CR_v18.root data_2017
./mulijet Run2018_MET_data.txt Run2018_METdata_CR_v18.root data_2018
hadd -f Run2_METdata_CR_v18.root Run201*_METdata_CR_v18.root


