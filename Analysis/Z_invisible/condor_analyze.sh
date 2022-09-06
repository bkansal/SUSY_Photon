#!/bin/sh
input_Scan=$1
anaExe="fakerate"
exeAtWorker="worker.sh"
#hist="FR_using_PhoPtQmulti_csv_cut_EMObjeta_qmulti"
#hist="FR_using_PhoPtQmulti_csv_cut_EMObjPt_eta"
#hist="FR_using_PhoPtQmulti_csv_cut_Qmultibin1_phoptbin2"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede_EMetage0pt1"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede"
hist="FR_using_PhoPtQmulti_csv_cut_EMObjeta_qmulti_METCaloMET_tmp"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede_HTHT5_METCaloMET"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede_HEM_HTHT5_METCaloMET_pucenter"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede_HEM_METCaloMET_pucenter"
#hist="FR_using_PhoPtQmulti_usingtrg_reject_notmatchede_HEM_pucenter_v2"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_reject_notmatchede_dphiMETjet1cut"
#hist="FR_using_PhoPtQmulti_csv_cut_usingtrg_HEM_HTHT5_METCaloMET_pucenter"
#hist="FR_using_PhoPtQmulti_csv_cut_nb_nj_cut"
#rm -rf /eos/uscms//store/user/bkansal/myProduction/fake_rate/rootoutput/${hist}
rm -rf /eos/uscms//store/user/bkansal/myProduction/Analysis/bkg_estimation/fakerate/${hist}
file="hadd.sh"
filesToTransfer="${anaExe},,PileupHistograms_2016_69mb_pm5.root,PileupHistograms_2017_69mb_pm5.root,PileupHistograms_2018_69mb_pm5.root,fake_rate_2016.root,fake_rate_2016_v2.root,fake_rate_2017.root,fake_rate_2017_v2.root,fake_rate_2018.root,fake_rate_2018_v2.root,runlist_TTG_2016_CR_v18.txt,runlist_TTG_2017_CR_v18.txt,runlist_TTG_2018_CR_v18.txt,runlist_TTJets-HT_2016_CR_v18.txt,runlist_TTJets-HT_2017_CR_v18.txt,runlist_TTJets-HT_2018_CR_v18.txt,runlist_TTJets-inc_2016_CR_v18.txt,runlist_TTJets-inc_2017_CR_v18.txt,runlist_TTJets-inc_2018_CR_v18.txt,runlist_WG_2016_CR_v18.txt,runlist_WG_2017_CR_v18.txt,runlist_WG_2018_CR_v18.txt,runlist_WJets_2016_CR_v18.txt,runlist_WJets_2017_CR_v18.txt,runlist_WJets_2018_CR_v18.txt,hadd.sh,Run2016_METdata.txt,Run2017_METdata.txt,Run2018_METdata.txt,Run2017B_METdata.txt,Run2017C_METdata.txt,Run2017D_METdata.txt,Run2017E_METdata.txt,Run2017F_METdata.txt,Run2018A_METdata.txt,Run2018B_METdata.txt,Run2018C_METdata.txt,Run2018D_METdata.txt"
mkdir /eos/uscms//store/user/bkansal/myProduction/Analysis/bkg_estimation/fakerate/${hist}
#mkdir /eos/uscms//store/user/bkansal/myProduction/fake_rate/rootoutput/${hist}
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
    echo "Arguments = ${anaExe} ${massP[0]} ${massP[1]} ${massP[2]} ${hist} ${file}">>$jdl_file
    echo "Queue">>$jdl_file
    condor_submit $jdl_file
done < $input_Scan

