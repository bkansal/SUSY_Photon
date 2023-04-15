#Trigger efficiency files

### Triggers 
We need to check the HLT triggers available for data. We need to use un-prescaled triggers, which means effective luminosity should be equal to the actual luminosity. List of the triggers available at Ra2b twiki: https://twiki.cern.ch/twiki/bin/viewauth/CMS/RA2b13TeVProduction#Triggers

### Trigger efficiency
The trigger efficiency is the ratio of the events passing desired triggers and total events.
To calculate the trigger efficiency using data, there is a need to have different dataset (like for calculating MET trigger eff, single e or mu dataset can be used). Now, Trigger efficiency is the ratio of the events passing desired triggers + triggers related to other datasets and total events passing triggers related to other datasets.
After finding desired triggers and corresponding trigger efficiency, 

MC events are reweighted by trigger efficiency and desired triggers are applied on the data.

## Trigger efficiency code :
You will need ```Single_elec.cc``` code and text files inside ```text_files``` directory. To run code interactively:
```
make
./single_elec text_files/Run2016B_SingleElectron_17Jul2018.txt Run2016B_SingleElectron_17Jul2018.root trg
```

There is a best way to submit condor jobs using ```splitRunList.C``` script.
```
root -l -q 'splitRunList.C("Run2016B_SingleElectron_17Jul2018.txt",10)'
```
Using above command, 10 condor jobs will be submitted. For example, if there are 400 files in a text file then 40 files/ job will run.