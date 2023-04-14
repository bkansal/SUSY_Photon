#!/bin/sh

for sample in C D E F G H
do
#    echo "grep $sample inputFiles.txt_main > $sample.txt"
#    grep $sample inputFiles.txt_main > $sample.txt
    echo "$sample"
    grep 'Run2016'$sample'-17Jul2018-v1.SingleMuon*' ../../../SUSY_Photon_using_v17_2017/TriggerStudies_v3/inputlist.txt > Run2016$sample\_SingleMuon_17Jul2018.txt
done
#Run2017B-31Mar2018-v1.SingleElectron_64_RA2AnalysisTree.root
#grep 'Run2016H-17Jul2018-v1.SingleElectron*' ../../../SUSY_Photon_using_v17_2017/TriggerStudies_v3/inputlist.txt > Run2016H_SingleElectron_31Mar2018.txt