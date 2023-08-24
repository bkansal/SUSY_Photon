#!/bin/sh                                                                                                                                                                   

for i in 2016 2017 2018
do
    hadd -f Run${i}_MC.root TTGJets_${i}_v18.root TTJetsHT1_${i}_v18.root TTJetsHT2_2017_v18.root WGJetsToLNuG_${i}_v18.root WJetsToLNu_${i}_v18.root GJetsQCD_${i}_v18.root ZGZJ_NuNuG_${i}_v18.root
done


