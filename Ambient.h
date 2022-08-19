#pragma once
#include "Main.h"
#include "Player.h"
#include "prwin_calcolator.h"
#include <iostream>
#include <fstream>






using namespace std;

class Ambient {

public:
	const int SeatsMaxNumber = 9;

	int nPlayers = 9;

	Player* p = new Player[nPlayers];
	string NewDeck[52] = { "Ad", "Kd", "Qd", "Jd","Td", "9d", "8d", "7d", "6d", "5d", "4d", "3d", "2d" ,
				  "Ac", "Kc", "Qc", "Jc","Tc", "9c", "8c", "7c", "6c", "5c", "4c", "3c", "2c" ,
				  "As", "Ks", "Qs", "Js","Ts", "9s", "8s", "7s", "6s", "5s", "4s", "3s", "2s" ,
				  "Ah", "Kh", "Qh", "Jh","Th", "9h", "8h", "7h", "6h", "5h", "4h", "3h", "2h" };

	string ShuffledDeck[52] = { "" };

	Player prwin[10];

	//Manual modify only these variables

	int NumberOfSimulation = 10000;	
	bool bHandHistory = 1;
	bool SingleSituation = 0;

	bool showhandnumber = 1;
	bool bTournament = false;
	bool SaveLastHandNumber = false;
	bool PT_autoimport = 1;

	//--------------------------------------
	int IncreaseBlindEveryHand = 10;
	int TournamentSpeed = 0;

	int PlayersStartingStack = 3000;	

	int SBPosition = 0;
	int BBPosition = 0;
	int EarlyPosition1 = 0;
	int EarlyPosition2 = 0;
	int MiddlePosition1 = 0;
	int MiddlePosition2 = 0;
	int MiddlePosition3 = 0;
	int COPosition = 0;
	int ButtonPosition = 0;	
	


	int BBsize = 10;
	int SBsize = 5;
	int ANTEsize = 2;
	int BetRound = 0;

	string HHline = "";

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

	const int* PlayersInvested[10] = { 0 };
	const int* PlayersStack[10] = { 0 };
	const int* PlayersBet[10] = { 0 };
	const int* PlayersPosition[10] = { 0 };
	const int* PlayersStrenght[10] = { 0 };
	const string* PlayersName[10] = { 0 };
	const State* PlayersState[10] = { 0 };



	ifstream hand;
	ofstream handN;
	string HH_File = "HandHistory.txt";



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
	void remove_from_pot();
	
	void HandReset();
	void HandHistory(string _text);


	void set_pointers();
	void set_initial_player_var();

	void Ante();
	void Preflop();
	void Flop();
	void Turn();
	void River();
	void Showdown();
	void Handplay();


	void start_simulation(int _nPlayers = 9 , int _NumberOfSimulation = 0);
	void start_hand();
	void players_handreset();

	void players_count_hand_strength();
	void pay_winners();
	void Tournament_Finish();
	void rebuy_options();

	void handhistory_new_hand();
	void handhistory_player_action(int i);

	void handhistory_finish();
	void goto_betround();

	void reset_players_state();
	void load_last_handumber();
	void save_last_handumber();

	void calc_player_at_showdown();
	void calc_prize();
	void calc_max_handstrength();
	void calc_number_of_winners();

	void set_players_card();
	void set_Preflop_PlayerVar();

	void set_HandHistory(bool _bool, string _file = "HandHistory.txt");
	void set_startitng_position();
	void reset_action_counts();
};
