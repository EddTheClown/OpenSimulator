#pragma once
#include "Main.h"
#include "CHandStrength.h"
#include <fstream>

using namespace std;


class Player {



	int nA = 0, nK = 0, nQ = 0, nJ = 0, nT = 0, n9 = 0, n8 = 0, n7 = 0, n6 = 0, n5 = 0, n4 = 0, n3 = 0, n2 = 0,
		nc = 0, nh = 0, ns = 0, nd = 0,
		cA = 0, cK = 0, cQ = 0, cJ = 0, cT = 0, c9 = 0, c8 = 0, c7 = 0, c6 = 0, c5 = 0, c4 = 0, c3 = 0, c2 = 0,
		dA = 0, dK = 0, dQ = 0, dJ = 0, dT = 0, d9 = 0, d8 = 0, d7 = 0, d6 = 0, d5 = 0, d4 = 0, d3 = 0, d2 = 0,
		hA = 0, hK = 0, hQ = 0, hJ = 0, hT = 0, h9 = 0, h8 = 0, h7 = 0, h6 = 0, h5 = 0, h4 = 0, h3 = 0, h2 = 0,
		sA = 0, sK = 0, sQ = 0, sJ = 0, sT = 0, s9 = 0, s8 = 0, s7 = 0, s6 = 0, s5 = 0, s4 = 0, s3 = 0, s2;

	bool kickerA = false, kickerK = false, kickerQ = false, kickerJ = false, kickerT = false, kicker9 = false, kicker8 = false, kicker7 = false, kicker6 = false, kicker5 = false, kicker4 = false, kicker3 = false, kicker2;

public:

	bool hand$A = false;
	bool hand$K = false;
	bool hand$Q = false;
	bool hand$J = false;
	bool hand$T = false;
	bool hand$9 = false;
	bool hand$8 = false;
	bool hand$7 = false;
	bool hand$6 = false;
	bool hand$5 = false;
	bool hand$4 = false;
	bool hand$3 = false;
	bool hand$2 = false;

	bool hand$AA = false;
	bool hand$AK = false;
	bool hand$AQ = false;
	bool hand$AJ = false;
	bool hand$AT = false;
	bool hand$A9 = false;
	bool hand$A8 = false;
	bool hand$A7 = false;
	bool hand$A6 = false;
	bool hand$A5 = false;
	bool hand$A4 = false;
	bool hand$A3 = false;
	bool hand$A2 = false;
	bool hand$KK = false;
	bool hand$KQ = false;
	bool hand$KJ = false;
	bool hand$KT = false;
	bool hand$K9 = false;
	bool hand$K8 = false;
	bool hand$K7 = false;
	bool hand$K6 = false;
	bool hand$K5 = false;
	bool hand$K4 = false;
	bool hand$K3 = false;
	bool hand$K2 = false;
	bool hand$QQ = false;
	bool hand$QJ = false;
	bool hand$QT = false;
	bool hand$Q9 = false;
	bool hand$Q8 = false;
	bool hand$Q7 = false;
	bool hand$Q6 = false;
	bool hand$Q5 = false;
	bool hand$Q4 = false;
	bool hand$Q3 = false;
	bool hand$Q2 = false;
	bool hand$JJ = false;
	bool hand$JT = false;
	bool hand$J9 = false;
	bool hand$J8 = false;
	bool hand$J7 = false;
	bool hand$J6 = false;
	bool hand$J5 = false;
	bool hand$J4 = false;
	bool hand$J3 = false;
	bool hand$J2 = false;
	bool hand$TT = false;
	bool hand$T9 = false;
	bool hand$T8 = false;
	bool hand$T7 = false;
	bool hand$T6 = false;
	bool hand$T5 = false;
	bool hand$T4 = false;
	bool hand$T3 = false;
	bool hand$T2 = false;
	bool hand$99 = false;
	bool hand$98 = false;
	bool hand$97 = false;
	bool hand$96 = false;
	bool hand$95 = false;
	bool hand$94 = false;
	bool hand$93 = false;
	bool hand$92 = false;
	bool hand$88 = false;
	bool hand$87 = false;
	bool hand$86 = false;
	bool hand$85 = false;
	bool hand$84 = false;
	bool hand$83 = false;
	bool hand$82 = false;
	bool hand$77 = false;
	bool hand$76 = false;
	bool hand$75 = false;
	bool hand$74 = false;
	bool hand$73 = false;
	bool hand$72 = false;
	bool hand$66 = false;
	bool hand$65 = false;
	bool hand$64 = false;
	bool hand$63 = false;
	bool hand$62 = false;
	bool hand$55 = false;
	bool hand$54 = false;
	bool hand$53 = false;
	bool hand$52 = false;
	bool hand$44 = false;
	bool hand$43 = false;
	bool hand$42 = false;
	bool hand$33 = false;
	bool hand$32 = false;
	bool hand$22 = false;


	bool hand$AKs = false;
	bool hand$AQs = false;
	bool hand$AJs = false;
	bool hand$ATs = false;
	bool hand$A9s = false;
	bool hand$A8s = false;
	bool hand$A7s = false;
	bool hand$A6s = false;
	bool hand$A5s = false;
	bool hand$A4s = false;
	bool hand$A3s = false;
	bool hand$A2s = false;
	bool hand$KQs = false;
	bool hand$KJs = false;
	bool hand$KTs = false;
	bool hand$K9s = false;
	bool hand$K8s = false;
	bool hand$K7s = false;
	bool hand$K6s = false;
	bool hand$K5s = false;
	bool hand$K4s = false;
	bool hand$K3s = false;
	bool hand$K2s = false;
	bool hand$QJs = false;
	bool hand$QTs = false;
	bool hand$Q9s = false;
	bool hand$Q8s = false;
	bool hand$Q7s = false;
	bool hand$Q6s = false;
	bool hand$Q5s = false;
	bool hand$Q4s = false;
	bool hand$Q3s = false;
	bool hand$Q2s = false;
	bool hand$JTs = false;
	bool hand$J9s = false;
	bool hand$J8s = false;
	bool hand$J7s = false;
	bool hand$J6s = false;
	bool hand$J5s = false;
	bool hand$J4s = false;
	bool hand$J3s = false;
	bool hand$J2s = false;
	bool hand$T9s = false;
	bool hand$T8s = false;
	bool hand$T7s = false;
	bool hand$T6s = false;
	bool hand$T5s = false;
	bool hand$T4s = false;
	bool hand$T3s = false;
	bool hand$T2s = false;
	bool hand$98s = false;
	bool hand$97s = false;
	bool hand$96s = false;
	bool hand$95s = false;
	bool hand$94s = false;
	bool hand$93s = false;
	bool hand$92s = false;
	bool hand$87s = false;
	bool hand$86s = false;
	bool hand$85s = false;
	bool hand$84s = false;
	bool hand$83s = false;
	bool hand$82s = false;
	bool hand$76s = false;
	bool hand$75s = false;
	bool hand$74s = false;
	bool hand$73s = false;
	bool hand$72s = false;
	bool hand$65s = false;
	bool hand$64s = false;
	bool hand$63s = false;
	bool hand$62s = false;
	bool hand$54s = false;
	bool hand$53s = false;
	bool hand$52s = false;
	bool hand$43s = false;
	bool hand$42s = false;
	bool hand$32s = false;

	bool hand$As = false;
	bool hand$Ks = false;
	bool hand$Qs = false;
	bool hand$Js = false;
	bool hand$Ts = false;
	bool hand$9s = false;
	bool hand$8s = false;
	bool hand$7s = false;
	bool hand$6s = false;
	bool hand$5s = false;
	bool hand$4s = false;
	bool hand$3s = false;


	bool s = false;
	int NumberOfSuit = 0;
	int PreflopNumber = -1;
	
	Position Position;

	State mystate;
	State BotLastAction;
	State BotLastPreflopAction;
	State BotLastFlopAction;
	State BotLastTurnAction;
	State BotLastRiverAction;


	//Manual modify only these variables

	bool bDebug = true;
	bool bprwin = 1;
	float prwin_iterations = 10000;

	bool ManualPlay = false;	
	bool opponentprwin = false;
	bool writehand = false;



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


	bool PairInHand = false;
	bool HaveStraightFlush = false;
	bool HaveFourOfAKind = false;
	bool HaveFullHouse = false;
	bool HaveFlush= false;
	bool HaveFlushDraw = false;
	bool HaveStraight= false;
	bool HaveStraightDraw = false;
	bool HaveSet = false;
	bool HaveTrips= false;
	bool HaveTwoPair= false;
	bool HavePair= false;
	bool HaveHighCard = false;
	bool FlushPossible = false;
	bool StraightPossible = false;

	bool CheckKicker = true;
	bool inButton = false;
	bool inSmallBlind = false;
	bool inBigBlind = false;
	bool inCutOff = false;
	bool inMiddlePosition = false;
	bool inEarlyPosition = false;

	bool winner = false;


	string card1 = "";
	string card2 = "";
	string card3 = "";
	string card4 = "";
	string card5 = "";
	string card6 = "";
	string card7 = "";


	int Situation = 0;
	double totvolte[10] = { 0 };
	double volte[10][1000] = {0};
	double needprwin[10][1000] = { 0 };

	//pointers

	const int* ActivePlayer = 0;
	const int* PotSize = 0;
	const int* BBsize = 0;
	const int* SBsize = 0;
	const int* ANTEsize = 0;
	const int* BetSize = 0;
	const int* Handnumber = 0;
	const int* nPlayers = 0;
	const int* Calls = 0;
	const int* Folds = 0;
	const int* Raises = 0;
	const int* Bets = 0;
	const int* BetRound = 0;
	const int* Allins = 0;
	const int* StillToAct = 0;
	const int* Checks = 0;
	const int* PlayersInHand = 0;
	const int* EarlyPosition1 = 0;
	const int* EarlyPosition2 = 0;
	const int* MiddlePosition1 = 0;
	const int* MiddlePosition2 = 0;
	const int* MiddlePosition3 = 0;
	const int* COPosition = 0;
	const int* ButtonPosition = 0;
	const int* SBPosition = 0;
	const int* BBPosition = 0;
	const int* PlayersInvested[10] = { 0 };
	const int* PlayersStack[10] = { 0 };
	const int* PlayersPosition[10] = { 0 };
	const int* PlayersBet[10] = { 0 };

	const string* ShuffledDeck[52] = { 0 };
	const string* PlayersName[10] = { 0 };
	const string* MyCards[7] = { 0 };

	const State* PlayersState[10] = { 0 };


	string get_mycards();

	Player();

	void handreset();


	void set_MaxOpponentStackSize();
	void set_AmountToCall();
	void set_OpponentsAtTable();
	void set_StartingStack();
	void set_Stacklevel();
	int  set_HandStrength();
	int  set_HandRank169();
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


	void MyTurn(const Player _p[]);
	int  set_decision();
	int  set_decision2();
	int	 set_decision3();
	int	 set_decision4();
	int set_situation();

	double calc_prwin();
	void pDebug();



	bool HaveCard(string _Card);

	void Set_Symbols();

	void Set_HavePair();
	void Set_HaveTwoPair();
	void Set_HaveTrips();
	void Set_HaveSet();
	void Set_HaveStraight();
	void Set_HaveFlush();
	void Set_HaveFullHouse();
	void Set_HaveFour();
	void Set_HaveStraightDraw();
	void Set_HaveFlushDraw();
	void Set_FlushPossible();
	void Set_StraightPossible();

	void Set_PreflopNumber();
	void set_MyCardInNumber();
	bool Call_OK();

	bool PotRange(int _min, int _max);
	bool StackRange(int _min, int _max);
	bool PrwinRange(float _min, float _max);


	string State_to_String(State action);
	


	int Set_PreflopSituationNumber();



};