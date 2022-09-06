#!/bin/sh

hadd -f CR_Run2016B_MET_17Jul2018.root CR_Run2016B_MET_17Jul2018_job*.root
hadd -f CR_Run2016C_MET_17Jul2018.root CR_Run2016C_MET_17Jul2018_job*.root
hadd -f CR_Run2016D_MET_17Jul2018.root CR_Run2016D_MET_17Jul2018_job*.root
hadd -f CR_Run2016E_MET_17Jul2018.root CR_Run2016E_MET_17Jul2018_job*.root
hadd -f CR_Run2016F_MET_17Jul2018.root CR_Run2016F_MET_17Jul2018_job*.root
hadd -f CR_Run2016G_MET_17Jul2018.root CR_Run2016G_MET_17Jul2018_job*.root
hadd -f CR_Run2016H_MET_17Jul2018.root CR_Run2016H_MET_17Jul2018_job*.root

hadd -f CR_Run2017B_MET_31Mar2018.root CR_Run2017B_MET_31Mar2018_job*.root
hadd -f CR_Run2017C_MET_31Mar2018.root CR_Run2017C_MET_31Mar2018_job*.root
hadd -f CR_Run2017D_MET_31Mar2018.root CR_Run2017D_MET_31Mar2018_job*.root
hadd -f CR_Run2017E_MET_31Mar2018.root CR_Run2017E_MET_31Mar2018_job*.root
hadd -f CR_Run2017F_MET_31Mar2018.root CR_Run2017F_MET_31Mar2018_job*.root

hadd -f CR_Run2018A_MET_17Sep2018.root CR_Run2018A_MET_17Sep2018_job*.root
hadd -f CR_Run2018B_MET_17Sep2018.root CR_Run2018A_MET_17Sep2018_job*.root
hadd -f CR_Run2018C_MET_17Sep2018.root CR_Run2018A_MET_17Sep2018_job*.root
hadd -f CR_Run2018D_MET_22Jan2019.root CR_Run2018D_MET_22Jan2019_job*.root

rm CR_Run201*_job*.root
