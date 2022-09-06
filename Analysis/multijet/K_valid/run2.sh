#!/bin/bash

rm rootoutput/*.root

./mulijet Run2016_MET_data.txt rootoutput/Run2016_METdata.root data_2016
./mulijet Run2017_MET_data.txt rootoutput/Run2017_METdata.root data_2017
./mulijet Run2018_MET_data.txt rootoutput/Run2018_METdata.root data_2018
hadd -f rootoutput/Run2_METdata.root rootoutput/Run201*_METdata.root

./mulijet runlist_ZJetsToNuNu_2016_v18.txt rootoutput/ZJetsToNuNu_2016_v18.root ZJets_v17_2016
./mulijet runlist_ZJetsToNuNu_2017_v18.txt rootoutput/ZJetsToNuNu_2017_v18.root ZJets_v17_2017
./mulijet runlist_ZJetsToNuNu_2018_v18.txt rootoutput/ZJetsToNuNu_2018_v18.root ZJets_v17_2018

#runlist_ZGToNuNuG_2016_v18
./mulijet runlist_QCD_2016_v18.txt rootoutput/QCD_2016_v18.root QCD_v17_2016
./mulijet runlist_QCD_2017_v18.txt rootoutput/QCD_2017_v18.root QCD_v17_2017
./mulijet runlist_QCD_2018_v18.txt rootoutput/QCD_2018_v18.root QCD_v17_2018
./mulijet runlist_GJets_DR_2016_v18.txt rootoutput/GJets_2016_v18.root GJetsDR_v17_2016
./mulijet runlist_GJets_DR_2017_v18.txt rootoutput/GJets_2017_v18.root GJetsDR_v17_2017
./mulijet runlist_GJets_DR_2018_v18.txt rootoutput/GJets_2018_v18.root GJetsDR_v17_2018
hadd -f rootoutput/GJetsQCD_2016_v18.root rootoutput/QCD_2016_v18.root rootoutput/GJets_2016_v18.root
hadd -f rootoutput/GJetsQCD_2017_v18.root rootoutput/QCD_2017_v18.root rootoutput/GJets_2017_v18.root
hadd -f rootoutput/GJetsQCD_2018_v18.root rootoutput/QCD_2018_v18.root rootoutput/GJets_2018_v18.root
hadd -f rootoutput/GJetsQCD_new_v18.root rootoutput/GJetsQCD_201*_v18.root 

./mulijet runlist_WJets_2016_v18.txt rootoutput/WJetsToLNu_2016_v18.root WJets_v17_2016
./mulijet runlist_WJets_2017_v18.txt rootoutput/WJetsToLNu_2017_v18.root WJets_v17_2017
./mulijet runlist_WJets_2018_v18.txt rootoutput/WJetsToLNu_2018_v18.root WJets_v17_2018
hadd -f rootoutput/WJetsToLNu_v18.root rootoutput/WJetsToLNu_*_v18.root


./mulijet runlist_TTJets_HT_2016_v18.txt rootoutput/TTJetsHT1_2016_v18.root TTJets_v17_2016
./mulijet runlist_TTJets_HT_2017_v18.txt rootoutput/TTJetsHT1_2017_v18.root TTJets_v17_2017
./mulijet runlist_TTJets_HT_2018_v18.txt rootoutput/TTJetsHT1_2018_v18.root TTJets_v17_2018
./mulijet runlist_TTJets_inc_2016_v18.txt rootoutput/TTJetsHT2_2016_v18.root TTJets2_v17_2016
./mulijet runlist_TTJets_inc_2017_v18.txt rootoutput/TTJetsHT2_2017_v18.root TTJets2_v17_2017
./mulijet runlist_TTJets_inc_2018_v18.txt rootoutput/TTJetsHT2_2018_v18.root TTJets2_v17_2018
hadd -f rootoutput/TTJetsHT_2016_v18.root rootoutput/TTJetsHT1_2016_v18.root rootoutput/TTJetsHT2_2016_v18.root
hadd -f rootoutput/TTJetsHT_2017_v18.root rootoutput/TTJetsHT1_2017_v18.root rootoutput/TTJetsHT2_2017_v18.root
hadd -f rootoutput/TTJetsHT_2018_v18.root rootoutput/TTJetsHT1_2018_v18.root rootoutput/TTJetsHT2_2018_v18.root
hadd -f rootoutput/TTJetsHT_v18.root rootoutput/TTJetsHT_201*_v18.root

./mulijet runList_ST_2016_CR_v18.txt rootoutput/ST_2016_CR_v18.root ST_v17_2016
./mulijet runList_ST_2017_CR_v18.txt rootoutput/ST_2017_CR_v18.root ST_v17_2017
./mulijet runList_ST_2018_CR_v18.txt rootoutput/ST_2018_CR_v18.root ST_v17_2018
hadd -f rootoutput/ST_CR_v18.root rootoutput/ST_201*_CR_v18.root
 

hadd -f rootoutput/Run2016_MC.root rootoutput/TTGJets_2016_v18.root rootoutput/TTJetsHT1_2016_v18.root rootoutput/TTJetsHT2_2017_v18.root rootoutput/WGJetsToLNuG_2016_v18.root rootoutput/WJetsToLNu_2016_v18.root rootoutput/GJetsQCD_2016_v18.root rootoutput/ZGZJ_NuNuG_2016_v18.root
hadd -f rootoutput/Run2017_MC.root rootoutput/TTGJets_2017_v18.root rootoutput/TTJetsHT1_2017_v18.root rootoutput/TTJetsHT2_2017_v18.root rootoutput/WGJetsToLNuG_2017_v18.root rootoutput/WJetsToLNu_2017_v18.root rootoutput/GJetsQCD_2017_v18.root rootoutput/ZGZJ_NuNuG_2017_v18.root
hadd -f rootoutput/Run2018_MC.root rootoutput/TTGJets_2018_v18.root rootoutput/TTJetsHT1_2018_v18.root rootoutput/TTJetsHT2_2018_v18.root rootoutput/WGJetsToLNuG_2018_v18.root rootoutput/WJetsToLNu_2018_v18.root rootoutput/GJetsQCD_2018_v18.root rootoutput/ZGZJ_NuNuG_2018_v18.root
hadd -f rootoutput/Run2_MC.root rootoutput/TTGJets_v18.root rootoutput/TTJetsHT_v18.root rootoutput/WGJetsToLNuG_v18.root rootoutput/WJetsToLNu_v18.root rootoutput/GJetsQCD_new_v18.root rootoutput/ZGZJ_NuNuG_v18.root

hadd -f rootoutput/EWK.root rootoutput/TTGJets_v18.root rootoutput/TTJetsHT_v18.root rootoutput/WJetsToLNu_v18.root rootoutput/WGJetsToLNuG_v18.root rootoutput/ZGZJ_NuNuG_v18.root 
