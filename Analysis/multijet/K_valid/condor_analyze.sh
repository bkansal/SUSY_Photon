#!/bin/sh
input_Scan=$1
#anaExe="mulijet_bSF"
anaExe="mulijet"
exeAtWorker="worker.sh"
#hist="K_valid"
#anaExe="mulijet_bSF"
hist="Kvalid_v2"
cp text_files/* .

rm -rf /eos/uscms/store/user/bkansal/myProduction/Analysis/rootoutput/${hist}
mkdir /eos/uscms/store/user/bkansal/myProduction/Analysis/rootoutput/${hist}

filesToTransfer="${anaExe},PileupHistograms_2016_69mb_pm5.root,PileupHistograms_2017_69mb_pm5.root,PileupHistograms_2018_69mb_pm5.root,Run2016_MET_data.txt,runlist_GJets_HT_2016_v18.txt,runList_ST_2016_CR_v18.txt,  runlist_TTJets_HT_2016_v18.txt,   runlist_WG_2016_v18.txt,     runlist_ZGToNuNuG_2016_v18.txt,Run2017_MET_data.txt,           runlist_GJets_HT_2017_v18.txt,  runList_ST_2017_CR_v18.txt,  runlist_TTJets_HT_2017_v18.txt,   runlist_WG_2017_v18.txt,     runlist_ZGToNuNuG_2017_v18.txt,Run2018_MET_data.txt,           runlist_GJets_HT_2018_v18.txt,  runList_ST_2018_CR_v18.txt,  runlist_TTJets_HT_2018_v18.txt,   runlist_WG_2018_v18.txt,     runlist_ZGToNuNuG_2018_v18.txt,runlist_GJets_DR_2016_v18.txt,  runlist_QCD_2016_v18.txt,       runlist_TTG_2016_v18.txt,    runlist_TTJets_inc_2016_v18.txt,  runlist_WJets_2016_v18.txt,  runlist_ZJetsToNuNu_2016_v18.txt,runlist_GJets_DR_2017_v18.txt,  runlist_QCD_2017_v18.txt,       runlist_TTG_2017_v18.txt,    runlist_TTJets_inc_2017_v18.txt,  runlist_WJets_2017_v18.txt,  runlist_ZJetsToNuNu_2017_v18.txt,runlist_GJets_DR_2018_v18.txt,  runlist_QCD_2018_v18.txt,       runlist_TTG_2018_v18.txt,    runlist_TTJets_inc_2018_v18.txt,  runlist_WJets_2018_v18.txt,  runlist_ZJetsToNuNu_2018_v18.txt, hadd.sh, btag.tar, Makefile, tmp2.txt, NtupleVariables.cc,NtupleVariables.h,Mulijet.cc,Mulijet.h, K_validation.root"

while read -a massP
do 
    echo ${massP[0]} ${massP[1]} ${massP[2]}
    jdl_file="condor_${massP[1]}_job.jdl"
    log_prefix="condor_${massP[1]}_job"
    echo "universe = vanilla">$jdl_file
    echo "Executable = ${exeAtWorker}">>$jdl_file
    echo "Should_Transfer_Files = YES">>$jdl_file
    echo "WhenToTransferOutput = ON_EXIT_OR_EVICT">>$jdl_file
    echo "Transfer_Input_Files = ${filesToTransfer}">>$jdl_file
    echo "Output = ${log_prefix}.stdout">>$jdl_file
    echo "Error = ${log_prefix}.stderr">>$jdl_file
    echo "Log = ${log_prefix}.condor">>$jdl_file
    echo "notification = never">>$jdl_file
    echo "Arguments = ${anaExe} ${massP[0]} ${massP[1]} ${massP[2]} ${hist}">>$jdl_file
    echo "Queue">>$jdl_file
    condor_submit $jdl_file
done < $input_Scan

