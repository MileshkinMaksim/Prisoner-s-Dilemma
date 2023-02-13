#pragma once
int randomerchance = 50; //For Randomer strat chance in % to defect every turn
int swingerchance = 50; //For Swinger strat chance in % to defect on 1st turn
bool startingdefected = false; //Starting state for Vindictive 
int vindtouchiness = 2; //How many defects need to triger Vinidictive's defect memory
int imittouchiness = 2; //How many defects need to triger Imitators's defect memory
char detectivepattern[4] = {'C','D','C','C'}; //Pattern for Detective's four turns