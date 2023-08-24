#!/bin/bash
rm pdf/*
rm png/*

########### Optimisation
for i in AllSBins_v6_CD_EW_50bin
do
    for j in T5bbbbZg T5ttttZg TChiWg
    do
	root -l -q 'codes/plotoptim.C("'${i}'","'${j}'")'
    done
done


########### Kinematic distribution
for i in nJets_D MET_D hadAk8Mass_D
do
    root -l -q 'codes/plotoptimv2.C("'${i}'")'
	
#    for j in strong EWK
#    do
#        root -l -q 'codes/plotKinStack.C("'${j}'","'${i}'")'
#    done
done


########### Data MC in LL CR
root -l -q 'codes/plotdatavsMC_LL.C("nJets")'
root -l -q 'codes/plotdatavsMC_LL.C("MET")'

########### Closure in FR
root -l -q 'codes/plotclosure_FR.C("nJets")'
root -l -q 'codes/plotclosure_FR.C("MET")'

########### mT distribution in FR CR
root -l -q 'codes/plotmT_FR.C("mTPhoMET")'


########### Zinvisible
dir2=Zin_purity
#Z->nu nu & Z->ll MC comparison   
root -l -q 'codes/plotclosure_Zin.C("MET","full_Run2","v18","'${dir2}'",false,true)'
root -l -q 'codes/plotclosure_Zin.C("nJets","full_Run2","v18","'${dir2}'",false,true)'
root -l -q 'codes/plotclosure_Zin.C("AllSBins_v6_CD","full_Run2","v18","'${dir2}'",false,true)'
#Scale factors
root -l -q 'codes/plotdatavsMC_Zin.C("AllSBins_v6_CD","full_Run2","v18",true,false)'

########## QCD
#K factor
root -l -q 'codes/printRK.C(false,false,true)'
#R factor
root -l -q codes/printRK.C
#closure
#root -l -q 'codes/plotclosure_multi.C("AllSBins_v6_CD_EW_50bin","full_Run2","v18",true,false)'
