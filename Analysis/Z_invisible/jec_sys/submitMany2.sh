#!/bin/sh                                                                                                                        



dir=Zinvisible/withoutJERC/                                                                                                                                                          
mkdir /eos/uscms/store/user/bkansal/GMSB_skims_TreesV18/for_bkg_estimation/JEC_JER_sys/${dir}

<<E

################ ZGJets to Nu Nu NLO inclusive  ###########################                                                                                                                
    
root -l -q 'splitRunList.C("Summer16v3.ZGTo2NuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.txt",5,"ZGTo2NuG_incl_nlo_v17_2016","'${dir}'")' 
root -l -q 'splitRunList.C("Fall17.ZGTo2NuG_TuneCP5_13TeV-amcatnloFXFX-pythia8_v18.txt",5,"ZGTo2NuG_incl_nlo_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZGTo2NuG_TuneCP5_13TeV-amcatnloFXFX-pythia8_v18.txt",5,"ZGTo2NuG_incl_nlo_v17_2018","'${dir}'")'

################ ZJets ###########################                                                                                                                        
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-1200To2500_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-200To400_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-400To600_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-600To800_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'
root -l -q 'splitRunList.C("Summer16v3.ZJetsToNuNu_HT-800To1200_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2016","'${dir}'")'

root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-1200To2500_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-200To400_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-400To600_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-600To800_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'
root -l -q 'splitRunList.C("Fall17.ZJetsToNuNu_HT-800To1200_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2017","'${dir}'")'

root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-1200To2500_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-200To400_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-2500ToInf_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-400To600_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-600To800_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
root -l -q 'splitRunList.C("Autumn18.ZJetsToNuNu_HT-800To1200_13TeV-madgraph_v18.txt",10,"ZJetsToNuNu_incl_v17_2018","'${dir}'")'
E


for lep in muon elec
do
    dir=Zinvisible/withJEC_${lep}/
    ################ ZGJets LL NLO ptg>130 GeV   ###########################                                                                                   
    root -l -q 'splitRunList.C("Summer16v3.ZGTo2LG_PtG-130_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_v18.txt",5,"ZGToLLG_nlo_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.ZGTo2LG_PtG-130_TuneCP5_13TeV-amcatnloFXFX-pythia8_v18.txt",5,"ZGToLLG_nlo_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.ZGTo2LG_PtG-130_TuneCP5_13TeV-amcatnloFXFX-pythia8_v18.txt",5,"ZGToLLG_nlo_v17_2018_'${lep}'","'${dir}'")'

    ################ DYJets ###########################                                                                                                                    
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-1200to2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-2500toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-600to800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.DYJetsToLL_M-50_HT-800to1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v18.txt",10,"DYJetsToLL_v17_2016_'${lep}'","'${dir}'")'

    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-100to200_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-1200to2500_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-200to400_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-2500toInf_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-400to600_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-600to800_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.DYJetsToLL_M-50_HT-800to1200_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2017_'${lep}'","'${dir}'")'
    
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-100to200_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-1200to2500_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-200to400_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-2500toInf_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-400to600_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-600to800_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.DYJetsToLL_M-50_HT-800to1200_13TeV-madgraph_v18.txt",10,"DYJetsToLL_v17_2018_'${lep}'","'${dir}'")'
    
    ################ TTGJets & WGJets ###########################                                                                                                          
    root -l -q 'splitRunList.C("Summer16v3.TTGJets_TuneCUETP8M1_13TeV-amcatnloFXFX-madspin-pythia8_v18.txt",10,"TTG_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.WGJets_MonoPhoton_PtG-40to130_TuneCUETP8M1_13TeV-madgraph_v18.txt",10,"WG_v17_2016_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Summer16v3.WGJets_MonoPhoton_PtG-130_TuneCUETP8M1_13TeV-madgraph_v18.txt",10,"WG_v17_2016_'${lep}'","'${dir}'")'
    
    root -l -q 'splitRunList.C("Fall17.TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_v18.txt",10,"TTG_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph_v18.txt",10,"WG_v17_2017_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Fall17.WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph_v18.txt",10,"WG_v17_2017_'${lep}'","'${dir}'")'

    root -l -q 'splitRunList.C("Autumn18.TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8_v18.txt",5,"TTG_v17_2018_'${lep}'","'${dir}'")'
    root -l -q 'splitRunList.C("Autumn18.WGJets_MonoPhoton_PtG-130_TuneCP5_13TeV-madgraph_v18.txt",10,"WG_v17_2018_'${lep}'","'${dir}'")'  
    root -l -q 'splitRunList.C("Autumn18.WGJets_MonoPhoton_PtG-40to130_TuneCP5_13TeV-madgraph_v18.txt",10,"WG_v17_2018_'${lep}'","'${dir}'")'
done
