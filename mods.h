#pragma once
#include "strategies.h"
#include <windows.h>

//Converts char to enum strategs
strategs initStrToStrat(char input) {
	switch (input) {
	case 'N':
		return strategs::NAIVE;
	case 'E':
		return strategs::EMBEZZLER;
	case 'R':
		return	strategs::RANDOMER;
	case 'S':
		return strategs::SWINGER;
	case 'V':
		return strategs::VINDICTIVE;
	case 'G':
		return strategs::GREEDY;
	case 'I':
		return strategs::IMITATOR;
	case 'D':
		return strategs::DETECTIVE;
	case 'Y':
		return strategs::YOURSTRAT;
	default:
		MessageBoxA(0, ("Wrong command, strategy NAIVE will be chosen"), "ERROR", MB_ICONERROR);
		return strategs::NAIVE;
	}
}

void fastmode() {

	strat* players[3];
	std::vector<char> turn;
	char participants[3] = {};
	int scores[3] = {};
	int finalscores[3] = {};
	int maxturns, currentturn;
	strategs chosenstrat;
	std::string input;

	std::cout << "Choose 3 of 8 strategies:\nNAIVE,\nEMBEZZLER,\nRANDOMER,\nSWINGER,\nVINDICTIVE,\nGREEDY,\nIMITATOR,\nDETECTIVE\nYOURSTRAT (your integrated strategy)\n\n";

	//Initialising game
	for (int i = 0; i < 3; i++)
	{
		std::cin >> input;
		participants[i] = input[0];
		chosenstrat = initStrToStrat(input[0]); //Converting input to strat
		players[i] = strat::make(chosenstrat); //initializing strategies with fabric
		turn.push_back('C');
	}
	std::cout << "Enter how many turns need to be played \n\n";
	std::cin >> maxturns;

	//Turns
	for(currentturn = 1; currentturn <= maxturns; currentturn++)
	{
		//Getting answers from our strategies
		double defcounter = 0.0;
		for (int i = 0; i < 3; i++)
		{
			turn[i] = players[i]->getchoice();
			if (turn[i] == 'D')
				defcounter += 1.0;
		}

		//Scores counting
		for (int i = 0; i < 3; i++)
		{
			if (turn[i] == 'C')
				scores[i] = int(7.0 - 3.5 * defcounter);
			else 
				scores[i] = 13 - int(4.0 * defcounter);
			finalscores[i] += scores[i];
		}
		//std::cout << turn[0] << ' ' << turn[1] << ' ' << turn[2] << " = > " << scores[0] << ' ' << scores[1] << ' ' << scores[2] << '\n';

		//Giving strategies a feedback
		for (int i = 0; i < 3; i++)
		{
			players[i]->getstats(turn, i);
			players[i]->makechoice();
		}
	}

	//Final results
	std::cout << "Final score: \n Strat " << participants[0] << "(" << finalscores[0] << ") \n Strat " << participants[1] << "(" << finalscores[1] << ") \n Strat " << participants[2] << "(" << finalscores[2] << ") \n\n";
}

void detailedmode() {
	std::cout << "In this mode after every turn you need to press Space button to continue \n\n";

	strat* players[3];
	std::vector<char> turn;
	char participants[3]= {};
	int scores[3] = {};
	int finalscores[3] = {};
	int maxturns, currentturn;
	strategs chosenstrat;
	std::string input;

	std::cout << "Choose 3 of 8 strategies:\nNAIVE,\nEMBEZZLER,\nRANDOMER,\nSWINGER,\nVINDICTIVE,\nGREEDY,\nIMITATOR,\nDETECTIVE\nYOURSTRAT (your integrated strategy)\n\n";
	
	//Initialising game
	for (int i = 0; i < 3; i++)
	{
		std::cin >> input;
		participants[i] = input[0];
		chosenstrat = initStrToStrat(input[0]); //Converting input to strat
		players[i] = strat::make(chosenstrat); //initializing strategies with fabric
		turn.push_back('C');
	}
	std::cout << "Enter how many turns need to be played \n";
	std::cin >> maxturns;

	std::wcout << "Players => Scores \n" << participants[0] << ' ' << participants[1] << ' ' << participants[2] << " => " << participants[0] << ' ' << participants[1] << ' ' << participants[2] << " \n";
	
	//Turns
	for (currentturn = 1; currentturn <= maxturns; currentturn++)
	{
		//Getting answers from our strategies
		double defcounter = 0.0;
		for (int i = 0; i < 3; i++)
		{
			turn[i] = players[i]->getchoice();
			if (turn[i] == 'D')
				defcounter += 1.0;
		}

		//Scores counting
		for (int i = 0; i < 3; i++)
		{
			if (turn[i] == 'C')
				scores[i] = int(7.0 - 3.5 * defcounter);
			else
				scores[i] = 13 - int(4.0 * defcounter);
			finalscores[i] += scores[i];
		}
		std::cout << turn[0] << ' ' << turn[1] << ' ' << turn[2] << " => " << scores[0] << ' ' << scores[1] << ' ' << scores[2] << '\n';

		while (true) { //Starting new turn
			if (GetAsyncKeyState(VK_SPACE) == -32767) break;
		}

		//Giving strategies a feedback
		for (int i = 0; i < 3; i++)
		{
			players[i]->getstats(turn, i);
			players[i]->makechoice();
		}
	}

	//Final results
	std::cout << "Final score: \n Strat " << participants[0] << "(" << finalscores[0] << ") \n Strat " << participants[1] << "(" << finalscores[1] << ") \n Strat " << participants[2] << "(" << finalscores[2] << ") \n\n";
}

void tournament() {
	strat* players[3];
	std::vector<char> turn;
	for (size_t i = 0; i < 3; i++) {
		turn.push_back('C');
	}
	char participants[100] = {};
	int scores[3] = {};
	int finalscores[100] = {};
	int maxturns, currentturn, stratquantity;
	strategs chosenstrat;
	std::string input;

	std::cout << "Choose ut to 100 strategies type quantity and names:\nNAIVE,\nEMBEZZLER,\nRANDOMER,\nSWINGER,\nVINDICTIVE,\nGREEDY,\nIMITATOR,\nDETECTIVE\nYOURSTRAT (your integrated strategy)\n\n";

	std::cin >> stratquantity;
	//Checking quantity of participants
	if (stratquantity < 3) {
		MessageBoxA(0, ("Too few participants"), "ERROR", MB_ICONERROR);
		return;
	}
	if (stratquantity > 100) {
		MessageBoxA(0, ("Too many participants"), "ERROR", MB_ICONERROR);
		return;
	}

	//Initialising Tournament
	for (int i = 0; i < stratquantity; i++) {
		std::cin >> input;
		participants[i] = input[0];
	}

	std::cout << "Enter how many turns need to be played in every triple \n\n";
	std::cin >> maxturns;


	//Tournament start
	for (int k = 0; k < (stratquantity - 2); k++)
		for(int l = k + 1; l < (stratquantity - 1); l++)
			for (int m = l + 1; m < (stratquantity); m++) {

				//Initialising triple
				chosenstrat = initStrToStrat(participants[k]); //Converting input to strat
				players[0] = strat::make(chosenstrat); //initializing strategy with fabric
				chosenstrat = initStrToStrat(participants[l]); //Converting input to strat
				players[1] = strat::make(chosenstrat); //initializing strategy with fabric
				chosenstrat = initStrToStrat(participants[m]); //Converting input to strat
				players[2] = strat::make(chosenstrat); //initializing strategy with fabric
				int triplescore[3] = {};

				//Turns
				for (currentturn = 1; currentturn <= maxturns; currentturn++)
				{
					//Getting answers from our strategies
					double defcounter = 0.0;
					for (int i = 0; i < 3; i++)
					{
						turn[i] = players[i]->getchoice();
						if (turn[i] == 'D')
							defcounter += 1.0;
					}

					//Scores counting
					for (int i = 0; i < 3; i++)
					{
						if (turn[i] == 'C')
							scores[i] = int(7.0 - 3.5 * defcounter);
						else
							scores[i] = 13 - int(4.0 * defcounter);
						triplescore[i] += scores[i];
					}
					

					//Giving strategies a feedback
					for (int i = 0; i < 3; i++)
					{
						players[i]->getstats(turn, i);
						players[i]->makechoice();
					}
				}

				//Counting scores for 1 round
				std::cout << "Round score: \n Strat " << participants[k] << "(" << triplescore[0] << ") \n Strat " << participants[l] << "(" << triplescore[1] << ") \n Strat " << participants[m] << "(" << triplescore[2] << ") \n\n";
				finalscores[k] += triplescore[0];
				finalscores[l] += triplescore[1];
				finalscores[m] += triplescore[2];
			}

	//Final results
	std::cout << "Final score: \n";
	for (int i = 0; i < stratquantity; i++)
	{
		std::cout << "Strat " << participants[i] << '(' << finalscores[i] << ")\n";
	}
	std::cout << "\n";
}