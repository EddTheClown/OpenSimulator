#pragma once
#include "Main.h"
#include "Player.h"
#include "prwin_calcolator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "HHWriter.h"



class Ambient {
	
public:
	Ambient();
	Ambient(const Ambient& other) = default; 
	~Ambient();

	const int SeatsMaxNumber = 8;

	int nPlayers = 9;
	vector<Player> p;
	HHWriter* HH;

	string HH_File = "HandHistory.txt";


	string NewDeck[52] = { "Ad", "Kd", "Qd", "Jd","Td", "9d", "8d", "7d", "6d", "5d", "4d", "3d", "2d" ,
				  "Ac", "Kc", "Qc", "Jc","Tc", "9c", "8c", "7c", "6c", "5c", "4c", "3c", "2c" ,
				  "As", "Ks", "Qs", "Js","Ts", "9s", "8s", "7s", "6s", "5s", "4s", "3s", "2s" ,
				  "Ah", "Kh", "Qh", "Jh","Th", "9h", "8h", "7h", "6h", "5h", "4h", "3h", "2h" };

	string ShuffledDeck[52] = { "" };

	Player prwin[10];

	int TotChipsWon = 0;
	int TotPlayers = 50;

	//Manual modify only these variables

	int NumberOfSimulation = 10000;	
	bool bHandHistory = 1;
	bool SingleSituation = 1;

	bool showhandnumber = 1;
	int showhand_frequency = 1;

	bool SaveLastHandNumber = false;
	bool PT_autoimport = 0;

	bool bNeverGoOut = false;
	int PlayerPosition = 0;
	//Tournament Var--------------------------------------
	bool bTournament = 1;

	string LastPlayerHand = "";
	int PlayerLastStack = 0;

	int IncreaseBlindEveryHand = 8; //how many hand beforw increase blind level
	bool doubleBlind = 0;  //event if is not tournament apply the tournament structure

	int BlindLevel = 1; //firs level is 1.

	int TournamentHandCount = 0; //incresead by one every hand, to know while set new blind level
	int HHprize = 0;
	

	int SBPosition = 0;
	int BBPosition = 0;
	int EarlyPosition1 = 0;
	int EarlyPosition2 = 0;
	int MiddlePosition1 = 0;
	int MiddlePosition2 = 0;
	int MiddlePosition3 = 0;
	int COPosition = 0;
	int ButtonPosition = 0;	
	

	int PlayersStartingStack = 50;
	int BBsize = 100;
	int SBsize = 50;
	int ANTEsize = 2;
	int BetRound = 0;


	//table information
	int PotSize = 0;
	int SidePot = 0;
	int SidePot2 = 0;

	
	int BetSize = 0;
	int Handnumber = 0;
	int MaxInvested = 0;
	int MaxInvested2 = 0;

	int maxbet = 0;
	int maxbet2 = 0;

	int RoundRaises = 0;
	int RoundCalls = 0;
	int nMaxBet = 0;

	int index = 0;

	int Calls = 0;
	int Folds = 0;
	int Bets = 0;
	int Raises = 0;
	int Allins = 0;
	int StillToAct = 0;
	int Checks = 0;

	int PlayersInHand = 0;
	int MaxStrenght = 0;
	int MaxStrenght2 = 0;
	int MaxStrenght3 = 0;
	int SidePotWinners = 0;
	int SidePotWinners2 = 0;

	bool isSimulation = false;
	bool realHand = true;

	int NumberOfWinners = 0;
	int Prize = 0;
	int Prize2 = 0;
	int BetRefound = 0;
	int PlayerAtShowdown = 0;
	int ActivePlayer = 0;

	bool PlayersWinner[10] = { false };
	bool bSeats[10] = { false };
	bool newround = false;
	bool bNewOrbit = false;
	bool bVirtualSimulation = false;


	const int* PlayersInvested[10] = { 0 };
	const int* PlayersStack[10] = { 0 };
	const int* PlayersBet[10] = { 0 };
	const int* PlayersPosition[10] = { 0 };
	const int* PlayersStrenght[10] = { 0 };
	const string* PlayersName[10] = { 0 };
	const State* PlayersState[10] = { 0 };

	

	



	void MixDeck(string _pCard1 = "", string _pCard2 = "", string _flop1 = "", string _flop2 = "", string _flop3 = "", string _turn = "", string _river = "");

	void set_Pot();
	void set_BetSize();
	void set_PlayersInHand();
	void set_Winners();
	void set_BlindsPosition();
	void set_Blind_Level();
	void set_game_type();

	bool NewOrbit();
	bool IgnorePlayer(int _index);
	
	void HandReset();


	void set_pointers();
	void set_initial_player_var();

	void Ante();
	void Preflop();
	void Flop();
	void Turn();
	void River();
	void Showdown();
	virtual void Handplay();


	void start_simulation(int _nPlayers = 9 , int _NumberOfSimulation = 0);
	int Play_Tournament(int i, int _TotPlayers = 50, int _MaxSeatNumber = 8, int _NumberOfSimulation = 1000000);
	void Simulate_Tournaments();
	void SimulateCash(int _nPlayers=8, int _NumberOfSimulation=10000);

	void start_hand();
	void players_handreset();

	void players_count_hand_strength();
	void pay_winners();
	void Tournament_Finish();
	void rebuy_options();

	void goto_betround();
	void reset_players_state();


	void calc_player_at_showdown();
	void calc_prize();
	void calc_HHprize();
	void calc_max_handstrength();
	void calc_number_of_winners();

	void set_players_card();
	void set_Preflop_PlayerVar();

	void set_startitng_position();
	void reset_action_counts();
	void simulate_random_nplayers();
	int generateRandomStack();

	void log(string line) {
		ofstream a;
		a.open("LOG.txt",ios::app);
		a << line<<endl;
		a.close();

	}

	void sortPairsByDouble(vector<pair<double, string>>& pairs);
	bool hasDuplicates(const std::vector<std::string>&array);

};
