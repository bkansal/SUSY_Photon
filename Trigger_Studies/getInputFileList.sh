#!/bin/sh

for sample in B C D E F G H
do 
    echo "$sample"
    grep 'Run2016'$sample'-17Jul2018.*SingleElectron*' inputfiles_v18.txt > inputlist_v18/Run2016$sample\_SingleElectron_17Jul2018.txt 
done

for sample in B C D E F
do
    echo "$sample"
    grep 'Run2017'$sample'-31Mar2018-v1.*SingleElectron*' inputfiles_v18.txt > inputlist_v18/Run2017$sample\_SingleElectron_17Jul2018.txt
done


for sample in A B C 
do

    echo "$sample"
#    grep 'Run2016'$sample'-17Jul2018.*SingleElectron*' inputfiles_v18.txt > inputlist_v18/Run2017$sample\_SingleElectron_17Jul2018.txt
#    grep 'Run2017'$sample'-31Mar2018-v1.*SingleElectron*' inputfiles_v18.txt > inputlist_v18/Run2017$sample\_SingleElectron_17Jul2018.txt
    grep 'Run2018'$sample'-17Sep2018-v1.EGamma*' inputfiles_v18.txt > inputlist_v18/Run2018$sample\_SingleElectron_17Jul2018.txt

done

sample=D
grep 'Run2018'$sample'-22Jan2019-v2.EGamma*' inputfiles_v18.txt > inputlist_v18/Run2018$sample\_SingleElectron_17Jul2018.txt
sed -i "s#Run201#root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Run2ProductionV18/Run201#" inputlist_v18/*.txt
