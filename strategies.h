#pragma once
#include "Config.h"
#include <iostream>
#include <math.h>
#include <map>
#include <random>
#include <time.h>
#include <vector>
#include <string>

enum strategs //Choose your destiny
{
	NAIVE,
	EMBEZZLER,
	RANDOMER,
	SWINGER,
	VINDICTIVE,
	GREEDY,
	IMITATOR,
	DETECTIVE,
	YOURSTRAT
};

class strat  //A class of strategies
{
public:
	char choice;

	char getchoice() {
		if (this->choice == 'D' || this->choice == 'C') //In case of errors we return D (defect)
			return this->choice;
		else
			return 'D';
	}

	virtual void getstats(std::vector<char> turn, int place) {} //For use in different classes in different ways
	
	virtual void makechoice() {}						  //Same ^

	static strat* make(strategs chosenstrat);
};

class naive : public strat //Always chooses C (cooperate) 
{

public:
	naive()
	{
		choice = 'C';
	}

	void getstats(std::vector<char>, int place) {}
	void makechoice() {
		choice = 'C';
	}
};

class embezzler : public strat //Always chooses D (defect)
{
public:
	embezzler() {
		choice = 'D';
	}

	void getstats(std::vector<char>, int place) {}
	void makechoice() {
		choice = 'D';
	}
};

class randomer : public strat //Chooses to defect with defined chance
{
private:
	int chance;
public:

	randomer() {
		chance = randomerchance;
		choice = 'C';
	}

	void getstats(std::vector<char>, int place) {}

	void makechoice() {
		if (rand() % 100 + 1 <= chance)
			choice = 'D';
		else
			choice = 'C';
	}
};

class swinger : public strat //Remembers his own last answer and changes it to opposite every turn
{
private:
	int place;
	char lastchoice;
public:
	swinger() {
		if (rand() % 100 + 1 <= swingerchance) {
			choice = 'D';
			lastchoice = 'C';
		}
		else {
			choice = 'C';
			lastchoice = 'D';
		}
		place = 0;
	}

	void getstats(std::vector<char> turn, int place) {
		lastchoice = turn[place];
	}

	void makechoice() {
		switch (lastchoice)
		{
		case 'D':
			choice = 'C';
			break;
		case 'C':
			choice = 'D';
			break;
		}
	}
};

class vindictive : public strat //Plays like naive until someone defects than starts playing like embezzler
{
private:
	bool defect_memory;
public:
	vindictive() {
		choice = 'C';
		defect_memory = startingdefected;
	}
	

	void getstats(std::vector<char> turn, int place) {
		if (defect_memory)
			return;

		int defpopularity = 0;
		for (int i = 0; i < 3; i++) 
			if (turn[i] == 'D') 
				defpopularity++;
			
		if (defpopularity >= vindtouchiness)
			defect_memory = true;

	}

	void makechoice() {
		switch (defect_memory)
		{
		case false:
			choice = 'C';
			break;
		case true:
			choice = 'D';
			break;
		}
	}
};

class greedy : public strat //begins with cooperate, than chooses answer gathered most points in previous turn
{
private:
	char valuedchoice = 'C';
public:
	greedy() {
		valuedchoice = 'C';
		choice = 'C';
	}

	void getstats(std::vector<char> turn, int place) {
		for (int i = 0; i < 3; i++) {
			if (turn[i] == 'D') {
				valuedchoice = 'D';
				break;
			}
			else
				valuedchoice = 'C';
		}
	}

	void makechoice() {
		choice = valuedchoice;
	}
};

class imitator : public strat  //Imitator begins with cooperate, than chooses most chosen answer in previous turn
{
private:
	char popularchoice = 'C';
public:
	imitator(){
		choice = 'C';
		popularchoice = 'C';
	}


	void getstats(std::vector<char> turn, int place) {
		int defpopularity = 0;
		for (int i = 0; i < 3; i++)
			if (turn[i] == 'D')
				defpopularity++;
		if (defpopularity >= imittouchiness)
			popularchoice = 'D';
		else
			popularchoice = 'C';
	}

	void makechoice() {
		choice = popularchoice;
	}
};

class detective : public strat //Begins Coop, Def, Coop, Coop. If defect will dominate at least one turn it will play like Imitator, else will play like Embezzler
{
private:
	char popularchoice;
	bool defect_memory;
	int turnnum;
public:
	detective() {
		choice = 'C';
		popularchoice = 'C';
		defect_memory = false;
		turnnum = 1;
	}


	void getstats(std::vector<char> turn, int place) {
		turnnum++;
		int defpopularity = 0;
		for (int i = 0; i < 3; i++)
			if (turn[i] == 'D')
				defpopularity++;
		if (defpopularity >= 2) {
			popularchoice = 'D';
			defect_memory = true;
		}
		else
			popularchoice = 'C';
	}

	void makechoice() {
		switch (turnnum)
		{
		case 1:
			choice = detectivepattern[0];
			break;
		case 2:
			choice = detectivepattern[1];
			break;
		case 3:
			choice = detectivepattern[2];
			break;
		case 4:
			choice = detectivepattern[3];
			break;
		default:
			if (defect_memory)
				choice = popularchoice;
			else
				choice = 'D';
			break;
		}
	}
};

class yourstrat : public strat //Empty strategy for integration
{
private:
public:
	yourstrat() {
		choice = 'C';
	}

	void getstats(std::vector<char> turn, int place)
	{

	}

	void makechoice() 
	{

	}
};

strat* strat::make(strategs chosenstrat) {
	switch (chosenstrat) {
	case strategs::NAIVE:
		return new naive;
	case strategs::EMBEZZLER:
		return new embezzler;
	case strategs::RANDOMER:
		return new randomer;
	case strategs::SWINGER:
		return new swinger;
	case strategs::VINDICTIVE:
		return new vindictive;
	case strategs::GREEDY:
		return new greedy;
	case strategs::IMITATOR:
		return new imitator;
	case strategs::DETECTIVE:
		return new detective;
	case strategs::YOURSTRAT:
		return new yourstrat;
	}
}