#pragma once
#include "Main.h"
#include "CHandStrength.h"
#include <fstream>
#include <algorithm>
#include <vector>

class Simulator;
class Ambient;

class Player {
private:



public:
	Simulator* test;
	


	int nA = 0, nK = 0, nQ = 0, nJ = 0, nT = 0, n9 = 0, n8 = 0, n7 = 0, n6 = 0, n5 = 0, n4 = 0, n3 = 0, n2 = 0,
		nc = 0, nh = 0, ns = 0, nd = 0,
		cA = 0, cK = 0, cQ = 0, cJ = 0, cT = 0, c9 = 0, c8 = 0, c7 = 0, c6 = 0, c5 = 0, c4 = 0, c3 = 0, c2 = 0,
		dA = 0, dK = 0, dQ = 0, dJ = 0, dT = 0, d9 = 0, d8 = 0, d7 = 0, d6 = 0, d5 = 0, d4 = 0, d3 = 0, d2 = 0,
		hA = 0, hK = 0, hQ = 0, hJ = 0, hT = 0, h9 = 0, h8 = 0, h7 = 0, h6 = 0, h5 = 0, h4 = 0, h3 = 0, h2 = 0,
		sA = 0, sK = 0, sQ = 0, sJ = 0, sT = 0, s9 = 0, s8 = 0, s7 = 0, s6 = 0, s5 = 0, s4 = 0, s3 = 0, s2;



	int NumberOfSuit = 0;
	int PreflopNumber = -1;
	
	EPosition Position;

	State mystate;
	State BotLastAction;
	State BotLastPreflopAction;
	State BotLastFlopAction;
	State BotLastTurnAction;
	State BotLastRiverAction;

	//Manual modify only these variables
	string HHline;
	int SimulateHands = 1;
	bool bDebug = 1;
	bool bprwin = 1;
	bool opponentprwin = 1;
	bool writehand = true;
	bool isSimulation = false;
	bool bWriteAllHand = false;

	float prwin_iterations = 10000;
	double prwin_opponents = 10000;

	bool ManualPlay = false;
	int linea = 0;
	bool opponentraise = 1;
	int numhand = 100;
	//prov var


	//specific situation
	int num_hand = 0;
	bool need_more_hand = false;
	bool onlyneedhands = 0;
	//--------------------------

	int SimulationLevel = 0;
	int TestDecision = 0;
	int BestDecision = 0;
	int prize[5] = { 0 };
	int win = 0;
	int SituationNumber = -1;
	bool ActionTested = false;

	//player var
	int currentbet = 0;
	int OpponentsAtTable = 0;
	int AmountToCall = 0;
	int MaxOpponentStackSize = 0;
	int MinOpponentStackSize = 0;
	int MaxBet = 0;
	int TotalInvested = 0;
	int AnteInvested = 0;
	int PreflopInvested = 0;
	int FlopInvested = 0;
	int TurnInvested = 0;
	int RiverInvested = 0;
	int mystack = 3000;
	int StartingStack = 0;
	int EffectiveStack = 3000;
	int handstrength = 0;
	int myposition = 0;
	int mybet = 0;
	int myraise = 0;
	int HandStrength = -100000;
	int StackLevel = 0;
	int myseat = 0;
	int myprize = 0;
	int decision = 0;
	int Opponents = 0;
	int mycardInNumber[7] = { -2 };
	int Pot = 0;
	double prwin = 0;
	float prlos = 0;

	string mycard[7] = {"","", "", "", "", "", "" };
	string myname = "";
	string mycards = "";

	int LastRaiserPosition = 0;
	int FirstRaiserPosition = 0;
	
	bool CheckKicker = true;
	bool inButton = false;
	bool inSmallBlind = false;
	bool inBigBlind = false;
	bool inCutOff = false;
	bool inMiddlePosition = false;
	bool inEarlyPosition = false;

	bool winner = false;



	//prov var
	string temp_cards = "";
	double temp_prwin = 1;
	double fold_prwin = 0;
	int hands = 0;


	double volteSituazione = 0;
	double volteAzione = 0;

	string card1 = "";
	string card2 = "";
	string card3 = "";
	string card4 = "";
	string card5 = "";
	string card6 = "";
	string card7 = "";

	//freq var
	int Situation = 0;
	double totvolte[10] = { 0 };
	double volte[10][1000] = {0};
	double needprwin[10][1000] = { 0 };
	double EVFold = 0;
	double EVCall1 = 0;
	double EVCall2 = 0;
	double EVCall3 = 0;
	double EVRaise = 0;

	double pFold = 0.1;  // Probabilità che tutti facciano fold
	double pCall1 = 0.2; // Probabilità che solo 1 faccia call
	double pCall2 = 0.3; // Probabilità che 2 facciano call
	double pCall3 = 0.2; // Probabilità che 3 facciano call
	double pRaise = 0.2; // Probabilità di un raise

	double TotEV = 0;
	double targetfreq = 0;
	bool freqcalc = false;


	//pointers
	Ambient* Table=nullptr;
	int* PlayersStack[10] = { 0 };
	int* PlayersPosition[10] = { 0 };
	int* PlayersBet[10] = { 0 };
	int* PlayersInvested[10] = { 0 };
		

	const string* ShuffledDeck[52] = { 0 };
	const string* PlayersName[10] = { 0 };
	const string* MyCards[7] = { 0 };

	const State* PlayersState[10] = { 0 };
	vector<pair<double,string>>WriteHandString;

	string get_mycards();

	Player();

	void handreset();


	void set_MaxOpponentStackSize();
	void set_AmountToCall();
	void set_OpponentsAtTable();
	void set_StartingStack();
	void set_Stacklevel();
	int  set_HandStrength();
	void set_position();
	void set_mycard();
	void set_effective_stack();


	void UpdateMyStack();
	void Update_TableInformation();
	void CountCard();
	void ResetCountCard();
	void TakePrize(int _price);

	void post_ANTE();
	void post_Blinds();
	void do_Fold();
	void do_Check();
	void do_Call();
	void do_Raise();
	void do_Allin();

	void reset_mybet();
	void reset_mystate();


	void MyTurn(vector<Player> _p);
	int  set_decision();
	int  set_decision2();
	int	 set_decision3();
	int	 set_decision4();
	int	 set_decision5();
	int set_situation();
	int choose_decision(vector<Player> _p);

	double calc_prwin();
	void pDebug(int _decision =0,string filename= "Player0_LOG.txt");



	bool HaveCard(string _Card);


	void set_MyCardInNumber();

	bool PotRange(int _min, int _max);
	bool StackRange(int _min, int _max);
	bool PrwinRange(float _min, float _max);



	bool Allin_OK();

	bool preflop_Raise();
	bool preflop_Call();

	bool flop_Raise();
	bool flop_Call();

	bool turn_Raise();
	bool turn_Call();

	bool river_Raise();
	bool river_Call();


	string State_to_String(State action);
	string Position_to_String(EPosition _Position);

	void set_writehand(int numhand = 0, bool bShowCards = false);

	void Manual_Prwin(double lastprwin = 0);
	void set_need_minhand(int numhand = 0);
	void updateGameNumber(std::string& line, int newGameNumber);

	double minPriwn = 0;
	double Calc_EventProbability(vector<Player> _p, string Evento);
	void ContaAzione(int _pot, double _prwin, int nPLayers);

	void freq_calc(double _targetfreq);

	int GetBestDecision();
};