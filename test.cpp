#include "pch.h"
#include "mods.h"

TEST(Simple1, TestStrats) {
	std::string Greedy = "GREEDY";
	std::string Embezzler = "EMBEZZLER";
	std::string Imitator = "IMITATOR";
	strategs Greedy2 = initStrToStrat(Greedy[0]);
	strategs Embezzler2 = initStrToStrat(Embezzler[0]);
	strategs Imitator2 = initStrToStrat(Imitator[0]);
	strat* players[3];
	std::vector<char> turn;
	for (size_t i = 0; i < 3; i++) {
		turn.push_back('C');
	}
	players[0] = strat::make(Greedy2);
	players[1] = strat::make(Embezzler2);
	players[2] = strat::make(Imitator2);

	double defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 1.0);
	EXPECT_EQ(turn[0],'C');
	EXPECT_EQ(turn[1],'D');
	EXPECT_EQ(turn[2],'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 2.0);
	EXPECT_EQ(turn[0], 'D');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 3.0);
	EXPECT_EQ(turn[0], 'D');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'D');
}

TEST(Simple2, TestStrats) {
	std::string Naive = "NAIVE";
	std::string Swinger = "SWINGER";
	std::string Vindictive = "VINDICTIVE";
	strategs Naive2 = initStrToStrat(Naive[0]);
	strategs Swinger2 = initStrToStrat(Swinger[0]);
	strategs Vindictive2 = initStrToStrat(Vindictive[0]);
	strat* players[3];
	std::vector<char> turn;
	for (size_t i = 0; i < 3; i++) {
		turn.push_back('C');
	}
	players[0] = strat::make(Naive2);
	players[1] = strat::make(Swinger2);
	players[2] = strat::make(Vindictive2);

	double defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 0.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'C');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 1.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 1.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'C');
	EXPECT_EQ(turn[2], 'D');
}

TEST(Complex, TestStrats) {
	std::string Swinger = "SWINGER";
	std::string Embezzler = "EMBEZZLER";
	std::string Detective = "DETECTIVE";
	strategs Swinger2 = initStrToStrat(Swinger[0]);
	strategs Embezzler2 = initStrToStrat(Embezzler[0]);
	strategs Detective2 = initStrToStrat(Detective[0]);
	strat* players[3];
	std::vector<char> turn;
	for (size_t i = 0; i < 3; i++) {
		turn.push_back('C');
	}
	players[0] = strat::make(Swinger2);
	players[1] = strat::make(Embezzler2);
	players[2] = strat::make(Detective2);

	double defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 1.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 3.0);
	EXPECT_EQ(turn[0], 'D');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'D');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 1.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 2.0);
	EXPECT_EQ(turn[0], 'D');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'C');

	for (int i = 0; i < 3; i++)
	{
		players[i]->getstats(turn, i);
		players[i]->makechoice();
	}

	defcounter = 0.0;
	for (int i = 0; i < 3; i++)
	{
		turn[i] = players[i]->getchoice();
		if (turn[i] == 'D')
			defcounter += 1.0;
	}

	EXPECT_EQ(defcounter, 2.0);
	EXPECT_EQ(turn[0], 'C');
	EXPECT_EQ(turn[1], 'D');
	EXPECT_EQ(turn[2], 'D');
}

TEST(Converter, TestModes) {
	char Choice = 'N';
		EXPECT_EQ(initStrToStrat(Choice), strategs::NAIVE);

	Choice = 'E';
		EXPECT_EQ(initStrToStrat(Choice), strategs::EMBEZZLER);
	
	Choice = 'R';
		EXPECT_EQ(initStrToStrat(Choice), strategs::RANDOMER);

	Choice = 'S';
		EXPECT_EQ(initStrToStrat(Choice), strategs::SWINGER);

	Choice = 'V';
		EXPECT_EQ(initStrToStrat(Choice), strategs::VINDICTIVE);

	Choice = 'G';
		EXPECT_EQ(initStrToStrat(Choice), strategs::GREEDY);

	Choice = 'I';
		EXPECT_EQ(initStrToStrat(Choice), strategs::IMITATOR);

	Choice = 'D';
		EXPECT_EQ(initStrToStrat(Choice), strategs::DETECTIVE);

	Choice = 'Y';
		EXPECT_EQ(initStrToStrat(Choice), strategs::YOURSTRAT);

	Choice = 'f';
		EXPECT_EQ(initStrToStrat(Choice), strategs::NAIVE);

	Choice = '3';
		EXPECT_EQ(initStrToStrat(Choice), strategs::NAIVE);

	Choice = '&';
		EXPECT_EQ(initStrToStrat(Choice), strategs::NAIVE);

}