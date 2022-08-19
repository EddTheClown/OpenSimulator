#pragma once
#include "Main.h"
using namespace std;

#define Random (rand()%100)
#define ToCall (AmountToCall / *BBsize)

#define StackSize (mystack / *BBsize)

//constructor
Player::Player() {


};

//reset all var at the begin of hand
void Player::handreset() {
	ResetCountCard();

	OpponentsAtTable = 0;
	AmountToCall = 0;

	MaxOpponentStackSize = 0;
	MinOpponentStackSize = 1000000;

	TotalInvested = 0;
	PreflopInvested = 0;
	FlopInvested = 0;
	TurnInvested = 0;
	RiverInvested = 0;

	inButton = false;
	inBigBlind = false;
	inSmallBlind = false;
	inCutOff = false;
	inMiddlePosition = false;
	inEarlyPosition = false;

	mycard[0] = "";
	mycard[1] = "";
	mycard[2] = "";
	mycard[3] = "";
	mycard[4] = "";
	mycard[5] = "";
	mycard[6] = "";
	mycards = "";

	for (int i = 0; i < 7; i++) {
		mycardInNumber[i] = -2;
	}

	mystate = State::null;
	Position = Position::null;

	BotLastAction = State::None;
	BotLastPreflopAction = State::None;
	BotLastFlopAction = State::None;
	BotLastTurnAction = State::None;
	BotLastRiverAction = State::None;

	mybet = 0;
	myraise = 0;
	HandStrength = -100000;
	StackLevel = 0;
	StartingStack = 0;
	currentbet = 0;
	myprize = 0;
	prwin = 0;
	prlos = 0;
	Opponents = 0;
	NumberOfSuit = 0;
	PreflopNumber = 0;
	Pot = 0;

	PairInHand = false;
	HaveStraightFlush = false;
	HaveFourOfAKind = false;
	HaveFullHouse = false;
	HaveFlush = false;
	HaveFlushDraw = false;
	HaveStraight = false;

	HaveStraightDraw = false;
	HaveSet = false;
	HaveTrips = false;
	HaveTwoPair = false;
	HavePair = false;
	HaveHighCard = false;
	FlushPossible = false;
	StraightPossible = false;

	winner = false;

	Situation = 0;
	s = false;





	set_StartingStack();



};

//update all the necessary var to make a decision
void Player::Update_TableInformation() {
	//count the cards
	CountCard();
	//set situation based on bot actions
	Situation = set_situation();

	//prov var (put in a function later)
	Opponents = (*ActivePlayer - 1);
	Pot = (*PotSize / *BBsize );

	//set stack and bets var
	set_AmountToCall();
	set_MaxOpponentStackSize();
	set_effective_stack();
	set_Stacklevel();

	//set cards and position
	set_mycard();
	set_position();

	//choose if opponent have to calc prwin whth bool opponentprwin in player.h
	if (myname != "Player0") bprwin = opponentprwin;

	//calc prwin if active in player.h
	if (bprwin) {
		prwin = calc_prwin();
		prlos = 1 - prwin; 
	}
	


};

//check the betsize and calc the difference from mybet and betsize for call
void Player::set_AmountToCall() {
	currentbet = mybet;
	AmountToCall = *BetSize - currentbet;
	if (AmountToCall >= mystack) { AmountToCall = mystack; };

};

//count the max and the min stack of opponents
void Player::set_MaxOpponentStackSize() {
	MaxBet = 0;
	MaxOpponentStackSize = 0;
	MinOpponentStackSize = 999999999;

	//set max e min stacks
	for (int i = (*nPlayers - 1); i >= 0; i--) {
		//if (*PlayersStack[i] == mystack) { continue; }
		if (*PlayersStack[i] >= MaxOpponentStackSize && *PlayersState[i] != State::Fold) {
			MaxOpponentStackSize = *PlayersStack[i]; MaxBet = *PlayersStack[i];
		};
		if (*PlayersStack[i] <= MinOpponentStackSize && *PlayersState[i] != State::Fold) { MinOpponentStackSize = *PlayersStack[i]; };
	}
};

//set opponents at the table (incomplete)
void Player::set_OpponentsAtTable() {

	OpponentsAtTable = (*nPlayers - 1);


};

//save the starting stack at the begin of hand
void Player::set_StartingStack() {

	StartingStack = mystack;


};

//calc my hand strength at the end of hand
int  Player::set_HandStrength() {
	if (mystate == State::Fold) { HandStrength = -100000; return HandStrength; }
	/*
		HandEvaluator* eval = new HandEvaluator;

		int card[7] = { 0 };

		for (int i = 0; i < 7; i++) {card[i] = set_cards_in_number(mycard[i]);}

		Hand h = Hand::empty();
		h += Hand(card[0]) + Hand(card[0]) + Hand(card[1]) + Hand(card[2]) + Hand(card[3]) + Hand(card[4]) + Hand(card[5]) + Hand(card[6]);
		HandStrength = eval->evaluate(h);
		//cout << eval->evaluate(h) << std::endl; // 28684 = 7 * 4096 + 12
		delete eval;

	*/


	CHandStrength* calc = new CHandStrength;

	HandStrength = calc->calc_HandStrength(mycard[0], mycard[1], mycard[2], mycard[3], mycard[4], mycard[5], mycard[6]);

	delete calc;


	return HandStrength;



};

//set the stack level in BB
void Player::set_Stacklevel() {

	if (mystack <= (5 * *BBsize)) { StackLevel = 1; return; };
	if (mystack <= (10 * *BBsize)) { StackLevel = 2; return; };
	if (mystack <= (15 * *BBsize)) { StackLevel = 3; return; };
	if (mystack <= (20 * *BBsize)) { StackLevel = 4; return; };
	if (mystack <= (30 * *BBsize)) { StackLevel = 5; return; };
	if (mystack <= (40 * *BBsize)) { StackLevel = 6; return; };
	if (mystack <= (50 * *BBsize)) { StackLevel = 7; return; };
	if (mystack <= (60 * *BBsize)) { StackLevel = 8; return; };
	if (mystack <= (70 * *BBsize)) { StackLevel = 9; return; };
	if (mystack <= (80 * *BBsize)) { StackLevel = 10; return; };
	if (mystack <= (90 * *BBsize)) { StackLevel = 11; return; };
	if (mystack <= (100 * *BBsize)) { StackLevel = 12; return; };
	if (mystack > (100 * *BBsize)) { StackLevel = 13; return; };
};

//update the knowing card based on bet round
void Player::set_mycard() {

	switch (*BetRound) {

	case 1:
		mycard[0] = *MyCards[0];
		mycard[1] = *MyCards[1];
		if (bprwin) Set_PreflopNumber();
		mycards = mycard[0] + mycard[1];
		break;
	case 2:
		mycard[2] = *MyCards[2];
		mycard[3] = *MyCards[3];
		mycard[4] = *MyCards[4];
		mycards = mycard[0] + mycard[1] + mycard[2] + mycard[3] + mycard[4] ;
		break;
	case 3:
		mycard[5] = *MyCards[5];
		mycards = mycard[0] + mycard[1] + mycard[2] + mycard[3] + mycard[4] +mycard[5];

		break;
	case 4:
		mycard[6] = *MyCards[6];
		mycards = mycard[0] + mycard[1]+ mycard[2] + mycard[3] + mycard[4] + mycard[5] + mycard[6];
		break;
	case 5:
		mycard[6] = *MyCards[6];
		mycards = mycard[0] + mycard[1] + mycard[2] + mycard[3] + mycard[4] + mycard[5] + mycard[6];
		break;
	}

};

//set positional var
void Player::set_position() {

	if (myposition == *SBPosition) { inSmallBlind = true; Position = Position::SB; return; };
	if (myposition == *BBPosition) { inBigBlind = true;  Position = Position::BB; return; };
	if (myposition == *ButtonPosition) { inButton = true; Position = Position::Button;  return; };
	if (myposition == *COPosition) { inCutOff = true; Position = Position::CutOff;  return; };
	if (myposition == *MiddlePosition3) { inMiddlePosition = true; Position = Position::Middle3;  return; };
	if (myposition == *MiddlePosition2) { inMiddlePosition = true; Position = Position::Middle2;  return; };
	if (myposition == *MiddlePosition1) { inMiddlePosition = true; Position = Position::Middle1;  return; };
	if (myposition == *EarlyPosition1) { inEarlyPosition = true; Position = Position::Early1;  return; };
	if (myposition == *EarlyPosition2) { inEarlyPosition = true; Position = Position::Early2;  return; };


};
//reset my bets var
void Player::reset_mybet() {

 	mybet = 0;
	currentbet = 0;

};
//reset status var
void Player::reset_mystate() {

	if (mystate != State::Allin && mystate != State::Call_Allin && mystate != State::Fold && mystate != State::Forced_Allin) {
		mystate = State::None;
	};
};
//reset all cards var
void Player::ResetCountCard() {
	nA = 0;
	nK = 0;
	nQ = 0;
	nJ = 0;
	nT = 0;
	n9 = 0;
	n8 = 0;
	n7 = 0;
	n6 = 0;
	n5 = 0;
	n4 = 0;
	n3 = 0;
	n2 = 0;

	nc = 0;
	ns = 0;
	nh = 0;
	nd = 0;

	cA = 0;
	cK = 0;
	cQ = 0;
	cJ = 0;
	cT = 0;
	c9 = 0;
	c8 = 0;
	c7 = 0;
	c6 = 0;
	c5 = 0;
	c4 = 0;
	c3 = 0;
	c2 = 0;

	hA = 0;
	hK = 0;
	hQ = 0;
	hJ = 0;
	hT = 0;
	h9 = 0;
	h8 = 0;
	h7 = 0;
	h6 = 0;
	h5 = 0;
	h4 = 0;
	h3 = 0;
	h2 = 0;

	sA = 0;
	sK = 0;
	sQ = 0;
	sJ = 0;
	sT = 0;
	s9 = 0;
	s8 = 0;
	s7 = 0;
	s6 = 0;
	s5 = 0;
	s4 = 0;
	s3 = 0;
	s2 = 0;

	dA = 0;
	dK = 0;
	dQ = 0;
	dJ = 0;
	dT = 0;
	d9 = 0;
	d8 = 0;
	d7 = 0;
	d6 = 0;
	d5 = 0;
	d4 = 0;
	d3 = 0;
	d2 = 0;

	kickerA = false;
	kickerK = false;
	kickerQ = false;
	kickerJ = false;
	kickerT = false;
	kicker9 = false;
	kicker8 = false;
	kicker7 = false;
	kicker6 = false;
	kicker5 = false;
	kicker4 = false;
	kicker3 = false;
	kicker2 = false;




	hand$A = false;
	hand$K = false;
	hand$Q = false;
	hand$J = false;
	hand$T = false;
	hand$9 = false;
	hand$8 = false;
	hand$7 = false;
	hand$6 = false;
	hand$5 = false;
	hand$4 = false;
	hand$3 = false;
	hand$2 = false;

	hand$As = false;
	hand$Ks = false;
	hand$Qs = false;
	hand$Js = false;
	hand$Ts = false;
	hand$9s = false;
	hand$8s = false;
	hand$7s = false;
	hand$6s = false;
	hand$5s = false;
	hand$4s = false;
	hand$3s = false;

	hand$AA = false;
	hand$AK = false;
	hand$AQ = false;
	hand$AJ = false;
	hand$AT = false;
	hand$A9 = false;
	hand$A8 = false;
	hand$A7 = false;
	hand$A6 = false;
	hand$A5 = false;
	hand$A4 = false;
	hand$A3 = false;
	hand$A2 = false;
	hand$KK = false;
	hand$KQ = false;
	hand$KJ = false;
	hand$KT = false;
	hand$K9 = false;
	hand$K8 = false;
	hand$K7 = false;
	hand$K6 = false;
	hand$K5 = false;
	hand$K4 = false;
	hand$K3 = false;
	hand$K2 = false;
	hand$QQ = false;
	hand$QJ = false;
	hand$QT = false;
	hand$Q9 = false;
	hand$Q8 = false;
	hand$Q7 = false;
	hand$Q6 = false;
	hand$Q5 = false;
	hand$Q4 = false;
	hand$Q3 = false;
	hand$Q2 = false;
	hand$JJ = false;
	hand$JT = false;
	hand$J9 = false;
	hand$J8 = false;
	hand$J7 = false;
	hand$J6 = false;
	hand$J5 = false;
	hand$J4 = false;
	hand$J3 = false;
	hand$J2 = false;
	hand$TT = false;
	hand$T9 = false;
	hand$T8 = false;
	hand$T7 = false;
	hand$T6 = false;
	hand$T5 = false;
	hand$T4 = false;
	hand$T3 = false;
	hand$T2 = false;
	hand$99 = false;
	hand$98 = false;
	hand$97 = false;
	hand$96 = false;
	hand$95 = false;
	hand$94 = false;
	hand$93 = false;
	hand$92 = false;
	hand$88 = false;
	hand$87 = false;
	hand$86 = false;
	hand$85 = false;
	hand$84 = false;
	hand$83 = false;
	hand$82 = false;
	hand$77 = false;
	hand$76 = false;
	hand$75 = false;
	hand$74 = false;
	hand$73 = false;
	hand$72 = false;
	hand$66 = false;
	hand$65 = false;
	hand$64 = false;
	hand$63 = false;
	hand$62 = false;
	hand$55 = false;
	hand$54 = false;
	hand$53 = false;
	hand$52 = false;
	hand$44 = false;
	hand$43 = false;
	hand$42 = false;
	hand$33 = false;
	hand$32 = false;
	hand$22 = false;

	hand$AA = false;
	hand$AKs = false;
	hand$AQs = false;
	hand$AJs = false;
	hand$ATs = false;
	hand$A9s = false;
	hand$A8s = false;
	hand$A7s = false;
	hand$A6s = false;
	hand$A5s = false;
	hand$A4s = false;
	hand$A3s = false;
	hand$A2s = false;
	hand$KK = false;
	hand$KQs = false;
	hand$KJs = false;
	hand$KTs = false;
	hand$K9s = false;
	hand$K8s = false;
	hand$K7s = false;
	hand$K6s = false;
	hand$K5s = false;
	hand$K4s = false;
	hand$K3s = false;
	hand$K2s = false;
	hand$QQ = false;
	hand$QJs = false;
	hand$QTs = false;
	hand$Q9s = false;
	hand$Q8s = false;
	hand$Q7s = false;
	hand$Q6s = false;
	hand$Q5s = false;
	hand$Q4s = false;
	hand$Q3s = false;
	hand$Q2s = false;
	hand$JJ = false;
	hand$JTs = false;
	hand$J9s = false;
	hand$J8s = false;
	hand$J7s = false;
	hand$J6s = false;
	hand$J5s = false;
	hand$J4s = false;
	hand$J3s = false;
	hand$J2s = false;
	hand$TT = false;
	hand$T9s = false;
	hand$T8s = false;
	hand$T7s = false;
	hand$T6s = false;
	hand$T5s = false;
	hand$T4s = false;
	hand$T3s = false;
	hand$T2s = false;
	hand$99 = false;
	hand$98s = false;
	hand$97s = false;
	hand$96s = false;
	hand$95s = false;
	hand$94s = false;
	hand$93s = false;
	hand$92s = false;
	hand$88 = false;
	hand$87s = false;
	hand$86s = false;
	hand$85s = false;
	hand$84s = false;
	hand$83s = false;
	hand$82s = false;
	hand$77 = false;
	hand$76s = false;
	hand$75s = false;
	hand$74s = false;
	hand$73s = false;
	hand$72s = false;
	hand$66 = false;
	hand$65s = false;
	hand$64s = false;
	hand$63s = false;
	hand$62s = false;
	hand$55 = false;
	hand$54s = false;
	hand$53s = false;
	hand$52s = false;
	hand$44 = false;
	hand$43s = false;
	hand$42s = false;
	hand$33 = false;
	hand$32s = false;
	hand$22 = false;

};
//count cards and symbols
void Player::CountCard() {
	ResetCountCard();
	int number = -1;
	string Card0 = "";
	string Card1 = "";


	for (int i = 0; i < 7; i++) {
		if (mycard[i] == "") { break; }

		switch (mycard[i][1]) {
		case 'c':
			switch (mycard[i][0]) {
			case 'A':  cA = 1; nA += 1; nc += 1; kickerA = true; hand$A = true; continue;
			case 'K':  cK = 1; nK += 1; nc += 1; kickerK = true; hand$K = true; continue;
			case 'Q':  cQ = 1; nQ += 1; nc += 1; kickerQ = true; hand$Q = true; continue;
			case 'J':  cJ = 1; nJ += 1; nc += 1; kickerJ = true; hand$J = true; continue;
			case 'T':  cT = 1; nT += 1; nc += 1; kickerT = true; hand$T = true; continue;
			case '9':  c9 = 1; n9 += 1; nc += 1; kicker9 = true; hand$9 = true; continue;
			case '8':  c8 = 1; n8 += 1; nc += 1; kicker8 = true; hand$8 = true; continue;
			case '7':  c7 = 1; n7 += 1; nc += 1; kicker7 = true; hand$7 = true; continue;
			case '6':  c6 = 1; n6 += 1; nc += 1; kicker6 = true; hand$6 = true; continue;
			case '5':  c5 = 1; n5 += 1; nc += 1; kicker5 = true; hand$5 = true; continue;
			case '4':  c4 = 1; n4 += 1; nc += 1; kicker4 = true; hand$4 = true; continue;
			case '3':  c3 = 1; n3 += 1; nc += 1; kicker3 = true; hand$3 = true; continue;
			case '2':  c2 = 1; n2 += 1; nc += 1; kicker2 = true; hand$2 = true; continue;
				break;
			}
		case 'd':
			switch (mycard[i][0]) {
			case 'A':  dA = 1; nA += 1; nd += 1; kickerA = true; hand$A = true; continue;
			case 'K':  dK = 1; nK += 1; nd += 1; kickerK = true; hand$K = true; continue;
			case 'Q':  dQ = 1; nQ += 1; nd += 1; kickerQ = true; hand$Q = true; continue;
			case 'J':  dJ = 1; nJ += 1; nd += 1; kickerJ = true; hand$J = true; continue;
			case 'T':  dT = 1; nT += 1; nd += 1; kickerT = true; hand$T = true; continue;
			case '9':  d9 = 1; n9 += 1; nd += 1; kicker9 = true; hand$9 = true; continue;
			case '8':  d8 = 1; n8 += 1; nd += 1; kicker8 = true; hand$8 = true; continue;
			case '7': d7 = 1; n7 += 1; nd += 1; kicker7 = true; hand$7 = true; continue;
			case '6': d6 = 1; n6 += 1; nd += 1; kicker6 = true; hand$6 = true; continue;
			case '5': d5 = 1; n5 += 1; nd += 1; kicker5 = true; hand$5 = true; continue;
			case '4': d4 = 1; n4 += 1; nd += 1; kicker4 = true; hand$4 = true; continue;
			case '3': d3 = 1; n3 += 1; nd += 1; kicker3 = true; hand$3 = true; continue;
			case '2':  d2 = 1; n2 += 1; nd += 1; kicker2 = true; hand$2 = true; continue;
				break;
			}
		case 's':
			switch (mycard[i][0]) {
			case 'A':  sA = 1; nA += 1; ns += 1; kickerA = true; hand$A = true; continue;
			case 'K':  sK = 1; nK += 1; ns += 1; kickerK = true; hand$K = true; continue;

			case 'Q':  sQ = 1; nQ += 1; ns += 1; kickerQ = true; hand$Q = true; continue;
			case 'J':  sJ = 1; nJ += 1; ns += 1; kickerJ = true; hand$J = true; continue;
			case 'T':  sT = 1; nT += 1; ns += 1; kickerT = true; hand$T = true; continue;
			case '9':  s9 = 1; n9 += 1; ns += 1; kicker9 = true; hand$9 = true; continue;
			case '8':  s8 = 1; n8 += 1; ns += 1; kicker8 = true; hand$8 = true; continue;
			case '7':  s7 = 1; n7 += 1; ns += 1; kicker7 = true; hand$7 = true; continue;
			case '6':  s6 = 1; n6 += 1; ns += 1; kicker6 = true; hand$6 = true; continue;
			case '5':  s5 = 1; n5 += 1; ns += 1; kicker5 = true; hand$5 = true; continue;
			case '4':  s4 = 1; n4 += 1; ns += 1; kicker4 = true; hand$4 = true; continue;
			case '3':  s3 = 1; n3 += 1; ns += 1; kicker3 = true; hand$3 = true; continue;
			case '2':  s2 = 1; n2 += 1; ns += 1; kicker2 = true; hand$2 = true; continue;
			}
		case 'h':
			switch (mycard[i][0]) {
			case 'A': hA = 1; nA += 1; nh += 1; kickerA = true; hand$A = true; continue;
			case 'K': hK = 1; nK += 1; nh += 1; kickerK = true; hand$K = true; continue;
			case 'Q': hQ = 1; nQ += 1; nh += 1; kickerQ = true; hand$Q = true; continue;
			case 'J': hJ = 1; nJ += 1; nh += 1; kickerJ = true; hand$J = true; continue;
			case 'T': hT = 1; nT += 1; nh += 1; kickerT = true; hand$T = true; continue;
			case '9': h9 = 1; n9 += 1; nh += 1; kicker9 = true; hand$9 = true; continue;
			case '8': h8 = 1; n8 += 1; nh += 1; kicker8 = true; hand$8 = true; continue;
			case '7': h7 = 1; n7 += 1; nh += 1; kicker7 = true; hand$7 = true; continue;
			case '6': h6 = 1; n6 += 1; nh += 1; kicker6 = true; hand$6 = true; continue;
			case '5': h5 = 1; n5 += 1; nh += 1; kicker5 = true; hand$5 = true; continue;
			case '4': h4 = 1; n4 += 1; nh += 1; kicker4 = true; hand$4 = true; continue;
			case '3': h3 = 1; n3 += 1; nh += 1; kicker3 = true; hand$3 = true; continue;
			case '2': h2 = 1; n2 += 1; nh += 1; kicker2 = true; hand$2 = true; continue;
			}
			break;
		}

	};

	
	if (nh >= nc || nh >= nd || nh >= ns ) { NumberOfSuit = nh; }
	else if (nc >= nd || nc >= ns || nc >= nh) { NumberOfSuit = nc; }
	else if (nd >= ns || nd >= nc || nd >= nh) { NumberOfSuit = nd; }
	else if (ns >= nc || ns >= nd || ns >= nh) { NumberOfSuit = ns; }

	set_MyCardInNumber();
	//set poket hand
	if (*BetRound == 1) {
		if (nh == 2 || nc == 2 || nd == 2 || ns == 2) { s = true; };


		if (nA == 2) {
			hand$AA = true; PairInHand = true;
		}
		else if (nK == 2) {
			hand$KK = true; PairInHand = true;
		}
		else if (nQ == 2) {
			hand$QQ = true; PairInHand = true;
		}
		else if (nJ == 2) {
			hand$JJ = true; PairInHand = true;
		}
		else if (nT == 2) {
			hand$TT = true; PairInHand = true;
		}
		else if (n9 == 2) {
			hand$99 = true; PairInHand = true;
		}
		else if (n8 == 2) {
			hand$88 = true; PairInHand = true;
		}
		else if (n7 == 2) {
			hand$77 = true; PairInHand = true;
		}
		else if (n6 == 2) {
			hand$66 = true; PairInHand = true;
		}
		else if (n5 == 2) {
			hand$55 = true; PairInHand = true;
		}
		else if (n4 == 2) {
			hand$44 = true; PairInHand = true;
		}
		else if (n3 == 2) {
			hand$33 = true; PairInHand = true;
		}
		else if (n2 == 2) {
			hand$22 = true; PairInHand = true;
		}


		else if (hand$A) {
			if (s) {hand$As = true;}
			if (hand$K) {
				hand$AK = true;
				if (s) { hand$AKs = true; }
			}
			else if (hand$Q) {
				hand$AQ = true;
				if (s) { hand$AQs = true; }
			}
			else if (hand$J) {
				hand$AJ = true;
				if (s) { hand$AJs = true; }
			}
			else if (hand$T) {
				hand$AT = true;
				if (s) { hand$ATs = true; }
			}
			else if (hand$9) {
				hand$A9 = true;
				if (s) { hand$A9s = true; }
			}
			else if (hand$8) {
				hand$A8 = true;
				if (s) { hand$A8s = true; }
			}
			else if (hand$7) {
				hand$A7 = true;
				if (s) { hand$A7s = true; }
			}
			else if (hand$6) {
				hand$A6 = true;
				if (s) { hand$A6s = true; }
			}
			else if (hand$5) {
				hand$A5 = true;
				if (s) { hand$A5s = true; }
			}
			else if (hand$4) {
				hand$A4 = true;
				if (s) { hand$A4s = true; }
			}
			else if (hand$3) {
				hand$A3 = true;
				if (s) { hand$A3s = true; }
			}
			else if (hand$2) {
				hand$A2 = true;
				if (s) { hand$A2s = true; }
			};
		}
		else if (hand$K) {
			if (s) { hand$Ks = true; }
		if (hand$Q) {
			hand$KQ = true;
			if (s) { hand$KQs = true; }
		}
		else if (hand$J) {
			hand$KJ = true;
			if (s) { hand$KJs = true; }
		}
		else if (hand$T) {
			hand$KT = true;
			if (s) { hand$KTs = true; }
		}
		else if (hand$9) {
			hand$K9 = true;
			if (s) { hand$K9s = true; }
		}
		else if (hand$8) {
			hand$K8 = true;
			if (s) { hand$K8s = true; }
		}
		else if (hand$7) {
			hand$K7 = true;
			if (s) { hand$K7s = true; }
		}
		else if (hand$6) {
			hand$K6 = true;
			if (s) { hand$K6s = true; }
		}
		else if (hand$5) {
			hand$K5 = true;
			if (s) { hand$K5s = true; }
		}
		else if (hand$4) {
			hand$K4 = true;

			if (s) { hand$K4s = true; }
		}
		else if (hand$3) {
			hand$K3 = true;
			if (s) { hand$K3s = true; }
		}
		else if (hand$2) {
			hand$K2 = true;
			if (s) { hand$K2s = true; }
		}
		}
		else if (hand$Q) {
		if (s) { hand$Qs = true; }
		if (hand$J) {
			hand$QJ = true;
			if (s) { hand$QJs = true; }
		}
		else if (hand$T) {
			hand$QT = true;
			if (s) { hand$QTs = true; }
		}
		else if (hand$9) {
			hand$Q9 = true;
			if (s) { hand$Q9s = true; }
		}
		else if (hand$8) {
			hand$Q8 = true;
			if (s) { hand$Q8s = true; }
		}
		else if (hand$7) {
			hand$Q7 = true;
			if (s) { hand$Q7s = true; }
		}
		else if (hand$6) {
			hand$Q6 = true; if (s) { hand$Q6s = true; }
		}
		else if (hand$5) {
			hand$Q5 = true; if (s) { hand$Q5s = true; }
		}
		else if (hand$4) {
			hand$Q4 = true; if (s) { hand$Q4s = true; }
		}
		else if (hand$3) {
			hand$Q3 = true; if (s) { hand$Q3s = true; }
		}
		else if (hand$2) {
			hand$Q2 = true; if (s) { hand$Q2s = true; }
		}
		}
		else if (hand$J) {
		if (s) { hand$Js = true; }
		if (hand$T) {
			hand$JT = true; if (s) { hand$JTs = true; }
		}
		else if (hand$9) {
			hand$J9 = true; if (s) { hand$J9s = true; }
		}
		else if (hand$8) {
			hand$J8 = true; if (s) { hand$J8s = true; }
		}
		else if (hand$7) {
			hand$J7 = true; if (s) { hand$J7s = true; }
		}
		else if (hand$6) {
			hand$J6 = true; if (s) { hand$J6s = true; }
		}
		else if (hand$5) {
			hand$J5 = true; if (s) { hand$J5s = true; }
		}
		else if (hand$4) {
			hand$J4 = true; if (s) { hand$J4s = true; }
		}
		else if (hand$3) {
			hand$J3 = true; if (s) { hand$J3s = true; }
		}
		else if (hand$2) {
			hand$J2 = true; if (s) { hand$J2s = true; }
		}
		}
		else if (hand$T) {
		if (s) { hand$Ts = true; }
		if (hand$9) {
			hand$T9 = true; if (s) { hand$T9s = true; }
		}
		else if (hand$8) {
			hand$T8 = true; if (s) { hand$T8s = true; }
		}
		else if (hand$7) {
			hand$T7 = true; if (s) { hand$T7s = true; }
		}
		else if (hand$6) {
			hand$T6 = true; if (s) { hand$T6s = true; }
		}
		else if (hand$5) {
			hand$T5 = true; if (s) { hand$T5s = true; }
		}
		else if (hand$4) {
			hand$T4 = true; if (s) { hand$T4s = true; }
		}
		else if (hand$3) {
			hand$T3 = true; if (s) { hand$T3s = true; }
		}
		else if (hand$2) {
			hand$T2 = true; if (s) { hand$T2s = true; }
		}
		}
		else if (hand$9) {
		if (s) { hand$9s = true; }
		if (hand$8) {
			hand$98 = true; if (s) { hand$98s = true; }
		}
		else if (hand$7) {
			hand$97 = true; if (s) { hand$97s = true; }
		}
		else if (hand$6) {
			hand$96 = true; if (s) { hand$96s = true; }
		}
		else if (hand$5) {
			hand$95 = true; if (s) { hand$95s = true; }
		}
		else if (hand$4) {
			hand$94 = true; if (s) { hand$94s = true; }
		}
		else if (hand$3) {
			hand$93 = true; if (s) { hand$93s = true; }
		}
		else if (hand$2) {
			hand$92 = true; if (s) { hand$92s = true; }
		}
		}
		else if (hand$8) {
		if (s) { hand$8s = true; }
		if (hand$7) {
			hand$87 = true; if (s) { hand$87s = true; }
		}
		else if (hand$6) {
			hand$86 = true; if (s) { hand$86s = true; }
		}
		else if (hand$5) {
			hand$85 = true; if (s) { hand$85s = true; }
		}
		else if (hand$4) {
			hand$84 = true; if (s) { hand$84s = true; }
		}
		else if (hand$3) {
			hand$83 = true; if (s) { hand$83s = true; }
		}
		else if (hand$2) {
			hand$82 = true; if (s) { hand$82s = true; }
		}
		}
		else if (hand$7) {
		if (s) { hand$7s = true; }
		if (hand$6) {
			hand$76 = true; if (s) { hand$76s = true; }
		}
		else if (hand$5) {
			hand$75 = true; if (s) { hand$75s = true; }
		}
		else if (hand$4) {
			hand$74 = true; if (s) { hand$74s = true; }
		}
		else if (hand$3) {
			hand$73 = true; if (s) { hand$73s = true; }
		}
		else if (hand$2) {
			hand$72 = true; if (s) { hand$72s = true; }
		}
		else if (hand$6 && hand$5) {
			hand$65 = true; if (s) { hand$65s = true; }
		}
		}
		else if (hand$6) {
		if (s) { hand$6s = true; }
		if (hand$4) {
			hand$64 = true; if (s) { hand$64s = true; }
		}
		else if (hand$3) {
			hand$63 = true; if (s) { hand$63s = true; }
		}
		else if (hand$2) {
			hand$62 = true; if (s) { hand$62s = true; }
		}
		}
		else if (hand$5) {
		if (s) { hand$5s = true; }
		if (hand$4) {
			hand$54 = true; if (s) { hand$54s = true; }
		}
		else if (hand$3) {
			hand$53 = true; if (s) { hand$53s = true; }
		}
		else if (hand$2) {
			hand$52 = true; if (s) { hand$52s = true; }
		}
		}
		else if (hand$4) {
		if (s) { hand$4s = true; }
		if (hand$3) {
			hand$43 = true; if (s) { hand$43s = true; }
		}
		else if (hand$2) {
			hand$42 = true; if (s) { hand$42s = true; }
		}
		}
		else if (hand$3 && hand$2 ) {
		if (s) { hand$3s = true; }
			hand$32 = true; if (s) { hand$32s = true; }
		};
		
	};




	//set symbols
	Set_Symbols();
	//HavePair

	




};
//take the prize at the end of hand and add to the stack
void Player::TakePrize(int _prize) {

	mystack += _prize;
};



//get al know card to string
string Player::get_mycards() {	


	return mycards;
};

//update stack var (also invested)
void Player::UpdateMyStack() {

	switch (*BetRound) {
	case 0:
		AnteInvested = mybet;
		break;
	case 1:
		PreflopInvested = mybet;
		break;
	case 2:
		FlopInvested = mybet;
		break;
	case 3:
		TurnInvested = mybet;
		break;
	case 4:
		RiverInvested = mybet;
		break;


	}


	TotalInvested = AnteInvested + PreflopInvested + FlopInvested + TurnInvested + RiverInvested;
	mystack = StartingStack - TotalInvested;
};

//perform fold action
void Player::do_Fold() {
	if (AmountToCall == 0 && *BetRound == 1 && inBigBlind) { do_Check(); return; };
	if (AmountToCall == 0 && *BetRound > 1) { do_Check(); return; };

	HandStrength = -100000;
	mystate = State::Fold;
	


};
//perform check action
void Player::do_Check() {
	if (AmountToCall > 0) { do_Fold(); return; }

	mystate = State::Check;
	BotLastAction = State::Check;




};
//perform call action
void Player::do_Call() {
	if (AmountToCall == 0) { do_Check(); return; };
	if (AmountToCall >= mystack) { do_Allin(); return; }

	mybet += AmountToCall;
	mystate = State::Call;
	BotLastAction = State::Call;

};
//perform raise action
void Player::do_Raise() {
	int RandomNumber = rand() % 6;

	if (*PlayersInHand == 1) { do_Call(); return; }
	if (mystack <= 15 * *BBsize) { do_Allin(); return; }
	if (AmountToCall >= mystack) { do_Allin(); return; }
	//if (*BetRound == 1 && BotLastAction == State::Raise && ToCall >= 10) { do_Allin(); return; }

	if (AmountToCall > 0 && AmountToCall < *SBsize) { do_Call(); return; }

	if (*BetRound == 1) {

		myraise = *BetSize * 3;

		if ((AmountToCall / *BBsize) <= 1 && *Calls == 0) { myraise = *BBsize * 3; }
		if ((AmountToCall / *BBsize) <= 1 && *Calls > 0) { myraise = (*BBsize * 3) + (*BBsize * *Calls); }

		
	}
	else {
		if (*BetSize == 0) {
			switch (RandomNumber) {
			case 0:
				myraise = 0.75 * *PotSize;
				break;
			case 1:
				myraise = 0.80 * *PotSize;
				break;
			case 2:
				myraise = 0.85 * *PotSize;
				break;
			case 3:
				myraise = 0.90 * *PotSize;
				break;
			case 4:
				myraise = 0.95 * *PotSize;
				break;
			case 5:
				myraise = *PotSize;
				break;
			};
		}
		else { myraise = *BetSize * 3; };
	}

	if (myname == "Player0" && *Handnumber == 1) {

		cout << "";
	}


	/*
	if (myname == "Player0" && ManualPlay) { cout << "\nEnter your raise\n"; cin >> myraise; }
	else {
		//betsize logic
		if (Random) { myraise = 0.5 * *Pot; }
		else {
			if (Random) { myraise = *Pot; }
			else { myraise = 0.75 * *Pot; }
		};


	};
	*/

	
	if (MaxBet == 0) { do_Call(); return; }

	if (myraise < AmountToCall) { do_Fold(); return; };


	if (myraise == AmountToCall && AmountToCall == 0) { do_Check(); return; }
	if (myraise == AmountToCall && AmountToCall > 0) { do_Call(); return; }

	if (myraise >= 0.8 * mystack && mystack <= MaxOpponentStackSize) { do_Allin(); return; }
	while (myraise % *BBsize) { myraise++; }

	if (myraise >= MaxOpponentStackSize && MaxOpponentStackSize > *BetSize) { myraise = MaxOpponentStackSize; }
	if (myraise > MaxBet && MaxBet > 0 && AmountToCall < MaxBet) { myraise = MaxBet; }





	mybet += myraise;




	if (AmountToCall == 0) { mystate = State::Bet; BotLastAction = State::Raise; };
	if (AmountToCall > 0) { mystate = State::Raise; BotLastAction = State::Raise; };


};
//perform allin action
void Player::do_Allin() {



	myraise = mystack;
	mystate = State::Allin;
	BotLastAction = State::Raise;
	mybet += myraise;



	if (AmountToCall >= mystack) { mystate = State::Call_Allin; BotLastAction = State::Call; }

};
//put ante in the pot
void Player::post_ANTE() {
	mybet = *ANTEsize;

	if (mybet >= mystack) { mystate = State::Forced_Allin; mybet = mystack; }

	UpdateMyStack();

};
//put blinds in the pot
void Player::post_Blinds() {


	if (inBigBlind) { mystate = State::Blinds; mybet = *BBsize; }
	if (inSmallBlind) { mystate = State::Blinds; mybet = *SBsize; }

	if (mybet >= mystack) { mystate = State::Forced_Allin; mybet = mystack; }

	UpdateMyStack();
};

//if true in player.h calc the prwin 
double Player::calc_prwin() {

	prwin_calcolator* calc = new prwin_calcolator;

	switch(*BetRound){
		case 1:
			prwin = calc->Preflop_precalc_prwin(PreflopNumber, *ActivePlayer);
			prlos = 1 - prwin;
			delete calc;
			return prwin;
		}
	
	prwin = calc->calc_prwin(mycard[0], mycard[1], mycard[2], mycard[3], mycard[4], mycard[5], mycard[6], *ActivePlayer, prwin_iterations);
	delete calc;
	return prwin;
};

//convert enumeration State in string
string Player::State_to_String(State action) {

	switch (action) {

	case State::Fold:
		return "Fold";
	case State::Check:
		return "Check";
	case State::Call:
		return "Call";
	case State::Raise:
		return "Raise";
	case State::Blinds:
		return "Blinds";
	case State::None:
		return "None";
	case State::Bet:
		return "Bet";
	case State::Allin:
		return "Allin";
	case State::Call_Allin:
		return "Call_Allin";
	case State::Forced_Allin:
		return "Forced_Allin";
	case State::null:
		return "null";
	case State::Out:
		return "Out";


	}

	return "error";
};
//if true in player.h write player the log in txt 
void Player::pDebug() {

	if (bDebug && myname == "Player0" && writehand == true) {
		ofstream scrivi;
		scrivi.precision(2);

		scrivi.open("Player0_LOG.txt", ios::app);
		scrivi << "\nHANDNUMBER: " << *Handnumber;
		scrivi << "\nbetround: " << *BetRound<<endl;

		scrivi << "if (*BetRound == " << *BetRound << " && ";
		scrivi << "AmountToCall == " << ToCall << " && ";
		scrivi << "*ActivePlayer == " << *ActivePlayer<< " && ";
		scrivi << "BotLastAction == State::" << State_to_String(BotLastAction) << " && ";
		scrivi << "prwin >= " << prwin;
		scrivi << ")return true;\n";

		scrivi << "\n" << myname << " (" << State_to_String(mystate) << " " << mybet << ") " << " " << get_mycards();
		scrivi << "\nprwin: " << prwin;


		scrivi << "\nStack: " << mystack / *BBsize;
		scrivi << "\nPot(bb): " << Pot;
		scrivi << "\nAmountToCall: " << ToCall;
		scrivi << "\nTotalInvested: " << TotalInvested / *BBsize << endl;
		scrivi << "\nPlayersInHand= " << *PlayersInHand;
		scrivi << "\nActivePlayers= " << *ActivePlayer;

		scrivi << "\nPosition: " << (int)Position;
		scrivi << "\n inBigBlind: " << inBigBlind;
		scrivi << "\n inSmallBlind: " << inSmallBlind;
		scrivi << "\n inButton: " << inButton;
		scrivi << "\n inCutOff: " << inCutOff;
		scrivi << "\n inMiddlePosition: " << inMiddlePosition;
		scrivi << "\n inEarlyPosition: " << inEarlyPosition << endl;

		scrivi << "\nbetround: " << *BetRound;
		scrivi << "\n BotLastAction: " << State_to_String(BotLastAction);
		scrivi << "\n BotLastPreflopAction: " << State_to_String(BotLastPreflopAction);
		scrivi << "\n BotLastFlopAction: " << State_to_String(BotLastFlopAction);
		scrivi << "\n BotLastTurnAction: " << State_to_String(BotLastTurnAction);
		scrivi << "\n BotLastRiverAction: " << State_to_String(BotLastRiverAction) << endl;
		


		scrivi << "\nOpponentsAtTable: " << OpponentsAtTable;
		scrivi << "\nMaxStackSize: " << MaxOpponentStackSize;
		scrivi << "\nMinStackSize: " << MinOpponentStackSize;
		scrivi << "\nMaxBet: " << MaxBet;
		scrivi << "\nMyraise: " << myraise / *BBsize;
		scrivi << "\nBetSize: " << *BetSize / *BBsize;
		scrivi << "\nTotalInvested: " << TotalInvested / *BBsize << endl;

		scrivi << "\nFolds: " << *Folds;
		scrivi << "\nChecks: " << *Checks;
		scrivi << "\nCalls: " << *Calls;
		scrivi << "\nRaises: " << *Raises;
		scrivi << "\nAllins: " << *Allins;
		scrivi << "\nStillToAct: " << *StillToAct;
		scrivi << "\n#####################################" << endl;

		scrivi.close();

	}
};

//set effective stack
void Player::set_effective_stack() {

	if (mystack > MaxOpponentStackSize) {
		EffectiveStack = MaxOpponentStackSize;
	}
	else (EffectiveStack = mystack);



};

//make decision  at my turn
void Player::MyTurn(const Player _p[]) {
	//in this case hero is player0
		decision = 0;

	Update_TableInformation();



	//post blinds
	if (myposition == *BBPosition && mystate == State::null) { post_Blinds(); return; }
	if (myposition == *SBPosition && mystate == State::null) { post_Blinds(); return; }
	if (TotalInvested > mystack) { do_Allin(); UpdateMyStack();; return; }



	if (myname == "Player0" && ManualPlay) {
		cout << "Not avaible, Work in progress.. any key to continue in automatic.\n";
		ManualPlay = false;

		//cout << "\nEnter your decision: 0= Fold , 1= Check , 2=Call , 3=Raise , 4= Allin\n"; 
	}
	//myname == "Player0"
	
	//read in set_decision() for more information
	if (myname == "Player0") decision = set_decision3();
	else

	{
		//choose here the opponents logic exaples:
		//if (myname == "Player1") decision = myfunction();
		//if (myname == "Player2") decision = fish();
		//if (myname == "Player3") if rand() decision = solid();

		decision = rand() % 4;
	}


	//perform decision
	switch (decision) {

	case 0:
		do_Fold();
		break;
	case 1:
		do_Check();
		break;
	case 2:
		do_Call();
		break;
	case 3:
		do_Raise();
		break;
	case 4:
		do_Allin();
		break;

	}
	
	//write log if accive in player.h
	if (bDebug) { pDebug(); }

	//set bot last actions
	switch (*BetRound) {
	case 1:
		BotLastPreflopAction = BotLastAction;
		break;
	case 2:
		BotLastFlopAction = BotLastAction;
		break;
	case 3:
		BotLastTurnAction = BotLastAction;
		break;
	case 4:
		BotLastRiverAction = BotLastAction;
		break;

	}

	
	//update stack and invested var
	UpdateMyStack();



};

//some example to write logic
int Player::set_decision() {
	/*
	I write here some additional information and examples:
	------------------------------------------------------------------
	if (this) {
	return 0; // fold
	return 1; // check
	return 2; // call
	return 3; // raise
	return 4; // allin
	}
	------------------------------------------------------------------
	all var in player.h at this point are update and can be used to make a decision
	if you usa a pointer var like BetRound, you have to put a '*' before. (*BetRound)
	------------------------------------------------------------------
	*BetRound
	*Raises
	*Calls 
	TotalInvested
	prwin
	ecc..
	------------------------------------------------------------------
	you can make your macro like this (look at the top first lines of player.cpp)

	ToCall is a macro, it mean AmountToCall
	Random is a macro ,a number from 0 to 100
	StackSize is a macro , it mean StackSize
	------------------------------------------------------------------
	if you set writehand false in player.h and single simulation true in ambient.h
	setting writehand true in a condition here it will only write those hands in the hh. (the others do not)

	if (*BetRound == 1 && ToCall <=5 ) {writehand = true; ...} 
	------------------------------------------------------------------
	bot last actions are enumeration , you can use in this way

	if (BotLastAction == State::Call){..}

	of with switch if you prefer (faster). 
	switch (BotLastAction)
		case State::Call:
		...
		break;

	------------------------------------------------------------------
	if bdebug is active in player.h a log is written in player0log.txt
	------------------------------------------------------------------
	at the moment the betsize is random, from 70 to 100 of pot. you can modify in do_raise() function.
	I have not implemented this better because if it will be read then the ohf profile will not be necessary.
	------------------------------------------------------------------
	the oppl symbols are not all and they are not even tested, the internal var instead work at 100%.
	------------------------------------------------------------------
	if you use prwin the speed will be slow for postflop, at least 10k of iterations are needed for some accuracy.
	------------------------------------------------------------------
	for maximum speed disable prwin in player.h and writeHH in ambient.h.

	*/

	return 0;

};
int Player::set_decision2() {
	return 0;
};

//example
int Player::set_decision3() {
	//6max

	switch (*BetRound) {
	case 1:




		if (hand$AA || hand$KK) { return 3; }
		switch (Position) {
			if (BotLastAction == State::None) {
		case Position::Middle:
			if (prwin > 0.22 && ToCall <= 5) { return 3; }
			if (prwin > 0.20 && ToCall <= 1) { return 3; }
			if (prwin > 0.22 && ToCall <= 5) { return 2; }
			break;
		case Position::CutOff:
			if (prwin > 0.29 && ToCall <= 5) { return 3; }
			if (prwin > 0.28 && ToCall <= 1) { return 3; }
			if (prwin > 0.27 && ToCall <= 5) { return 2; }
			break;
		case Position::Button:
			if (prwin > 0.36 && ToCall <= 5) { return 3; }
			if (prwin > 0.34 && ToCall <= 1) { return 3; }
			if (prwin > 0.32 && ToCall <= 5) { return 2; }
			break;
		case Position::SB:
			if (prwin > 0.44 && ToCall <= 5 && ToCall > 1) { return 3; }
			if (prwin > 0.54 && ToCall <= 1) { return 3; }
			if (prwin > 0.42 && ToCall <= 5) { return 2; }
			break;
		case Position::BB:
			if (prwin > 0.63 && ToCall <= 5) { return 3; }
			if (prwin > 0.60 && ToCall <= 1) { return 3; }
			if (prwin > 0.56 && ToCall <= 5) { return 2; }
			break;

			}
		}


		if (prwin > 0.9) { return 3; }
		if (Call_OK()) { return 2; }
		return 0;
		break;

		//Flop
	case 2:

		switch (Position) {
		case Position::Middle:
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None && prwin > 0.5 && Call_OK()) { return 3; } //cbet
			if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None && Call_OK() && prwin < 0.65) { return 0; }
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && prwin < 0.85) { return 0; } //fold to 3bet 

			if (prwin > 0.70) { return 3; }
			if (Call_OK() && prwin > 0.5) { return 2; }
			return 0;
		case Position::CutOff:
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None && prwin > 0.51 && Call_OK()) { return 3; } //cbet
			if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None && Call_OK() && prwin < 0.59) { return 0; }
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.60) { return 3; }
			if (Call_OK() && prwin > 0.5) { return 2; }
			return 0;
		case Position::Button:
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None && prwin > 0.50 && Call_OK()) { return 3; } //cbet
			if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None && Call_OK() && prwin < 0.55) { return 0; }
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.59) { return 3; }
			if (Call_OK() && prwin > 0.5) { return 2; }
			return 0;
		case Position::SB:
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None && prwin > 0.60 && Call_OK()) { return 3; } //do cbet
			if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None && Call_OK() && prwin < 0.82) { return 0; } //fold to cbet
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.57) { return 3; }
			if (Call_OK() && prwin > 0.54) { return 2; }
			return 0;
		case Position::BB:
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None && prwin > 0.80 && Call_OK()) { return 3; } //cbet
			if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None && Call_OK() && prwin < 0.6) { return 0; }
			if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.60) { return 3; }
			if (Call_OK() && prwin > 0.5) { return 2; }
			return 0;
			break;

		}


		if (prwin > 0.9) { return 3; }
		if (Call_OK()) { return 2; }
		return 0;
		break;

		//turn
	case 3:
		switch (Position) {
		case Position::Middle:
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::None && prwin > 0.8 && Call_OK()) { return 3; } //cbet
			if (BotLastFlopAction == State::Call && BotLastTurnAction == State::None && Call_OK() && prwin < 0.7) { return 0; } //fold to cbet
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.8) { return 3; }
			if (Call_OK() && prwin > 0.60) { return 2; }
			return 0;

		case Position::CutOff:
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::None && prwin > 0.74 && Call_OK()) { return 3; } //cbet
			if (BotLastFlopAction == State::Call && BotLastTurnAction == State::None && Call_OK() && prwin < 0.7) { return 0; } //fold to cbet
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.8) { return 3; }
			if (Call_OK() && prwin > 0.60) { return 2; }
			return 0;

		case Position::Button:
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::None && prwin > 0.72 && Call_OK()) { return 3; } //cbet
			if (BotLastFlopAction == State::Call && BotLastTurnAction == State::None && Call_OK() && prwin < 0.55) { return 0; }
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && prwin < 0.82) { return 0; } //fold to 3bet 

			if (prwin > 0.8) { return 3; }
			if (Call_OK() && prwin > 0.55) { return 2; }
			return 0;

		case Position::SB:
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::None && prwin > 0.8 && Call_OK()) { return 3; } //cbet
			if (BotLastFlopAction == State::Call && BotLastTurnAction == State::None && Call_OK() && prwin < 0.8) { return 0; }
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && prwin < 0.8) { return 0; } //fold to 3bet 

			if (prwin > 0.85) { return 3; }
			if (Call_OK() && prwin > 0.62) { return 2; }
			return 0;

		case Position::BB:
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::None && prwin > 0.80 && Call_OK()) { return 3; } //cbet
			if (BotLastFlopAction == State::Call && BotLastTurnAction == State::None && Call_OK() && prwin < 0.6) { return 0; }
			if (BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && prwin < 0.8) { return 0; } //fold to 3bet 

			if (prwin > 0.85) { return 3; }
			if (Call_OK() && prwin > 0.6) { return 2; }
			return 0;
		}


		return 0;
		//river
	case 4:
		return 0;
		break;
	}
	return 0;

	return 0;
};
int Player::set_decision4() {

	return 0;	

};

bool Player::Call_OK() {

	if (prwin > ((float)AmountToCall / (float)(*PotSize + AmountToCall))) { return true; }
	return false;
};

//set situation based on bot actions
int Player::set_situation() {

	if (*BetRound == 1) {
		if (BotLastAction == State::None) return 0;
		if (BotLastAction == State::Call) return 1;
		if (BotLastAction == State::Raise) return 2;
	}	
	if (*BetRound == 2) {
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::None) return 3;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call) return 4;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise) return 5;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check) return 6;

		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None) return 7;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call) return 8;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise) return 9;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check) return 10;

		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::None) return 11;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call) return 12;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise) return 13;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check) return 14;
	}
	if (*BetRound == 3) {
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::None) return 15;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call) return 16;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise) return 17;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check) return 18;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::None) return 19;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call) return 20;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise) return 21;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check) return 22;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::None) return 23;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call) return 24;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise) return 25;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check) return 26;

		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::None) return 27;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call) return 28;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise) return 29;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check) return 30;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::None) return 31;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call) return 32;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise) return 33;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check) return 34;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::None) return 35;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call) return 36;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise) return 37;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check) return 38;

		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::None) return 39;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call) return 40;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise) return 41;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check) return 42;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::None) return 43;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call) return 44;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise) return 45;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check) return 46;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::None) return 47;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call) return 48;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise) return 49;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check) return 50;

	}
	if (*BetRound == 4) {
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 51;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 52;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 53;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 54;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 55;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 56;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 57;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 58;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 59;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 60;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 61;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 62;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 63;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 64;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 65;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 66;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 67;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 68;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 69;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 70;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 71;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 72;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 73;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 74;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 75;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 76;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 77;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 78;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 79;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 80;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 81;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 82;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 83;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 84;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 85;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 86;

		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 87;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 88;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 89;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 90;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 91;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 92;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 93;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 94;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 95;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 96;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 97;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 98;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 99;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 100;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 101;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 102;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 103;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 104;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 105;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 106;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 107;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 108;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 109;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 110;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 111;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 112;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 113;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 114;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 115;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 116;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 117;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 118;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 119;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 120;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 121;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 122;

		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 123;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 124;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 125;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 126;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 127;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 128;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 129;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 130;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 131;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 132;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 133;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 134;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 135;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 136;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 137;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 138;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 139;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 140;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 141;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 142;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 143;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 144;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 145;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 146;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::None) return 147;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Call) return 148;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Raise) return 149;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastRiverAction == State::Check) return 150;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::None) return 151;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Call) return 152;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Raise) return 153;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastRiverAction == State::Check) return 154;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::None) return 155;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Call) return 156;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Raise) return 157;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastRiverAction == State::Check) return 158;

	}
	return 0;
}

//set symbols (incomplete)
void Player::Set_HavePair(){

	if (nA == 2 ||
		nK == 2 ||
		nQ == 2 ||
		nT == 2 ||
		n9 == 2 ||
		n8 == 2 ||
		n7 == 2 ||
		n6 == 2 ||
		n5 == 2 ||
		n4 == 2 ||
		n3 == 2 ||
		n2 == 2) {
		HavePair = true;}


};
void Player::Set_HaveTwoPair() {

	if (nA == 2) {
		if (nK == 2) { HaveTwoPair = true; return; }
		if (nQ == 2) { HaveTwoPair = true; return; }
		if (nJ == 2) { HaveTwoPair = true; return; }
		if (nT == 2) { HaveTwoPair = true; return; }
		if (n9 == 2) { HaveTwoPair = true; return; }
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (nK == 2) {
		if (nQ == 2) { HaveTwoPair = true; return; }
		if (nJ == 2) { HaveTwoPair = true; return; }
		if (nT == 2) { HaveTwoPair = true; return; }
		if (n9 == 2) { HaveTwoPair = true; return; }
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (nQ == 2) {
		if (nJ == 2) { HaveTwoPair = true; return; }
		if (nT == 2) { HaveTwoPair = true; return; }
		if (n9 == 2) { HaveTwoPair = true; return; }
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (nJ == 2) {
		if (nT == 2) { HaveTwoPair = true; return; }
		if (n9 == 2) { HaveTwoPair = true; return; }
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (nT == 2) {
		if (n9 == 2) { HaveTwoPair = true; return; }
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n9 == 2) {
		if (n8 == 2) { HaveTwoPair = true; return; }
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n8 == 2) {
		if (n7 == 2) { HaveTwoPair = true; return; }
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n7 == 2) {
		if (n6 == 2) { HaveTwoPair = true; return; }
		if (n5 == 2) { HaveTwoPair = true; return; }
		if (n4 == 2) { HaveTwoPair = true; return; }
		if (n3 == 2) { HaveTwoPair = true; return; }
		if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n6 == 2) {
	if (n5 == 2) { HaveTwoPair = true; return; }
	if (n4 == 2) { HaveTwoPair = true; return; }
	if (n3 == 2) { HaveTwoPair = true; return; }
	if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n5 == 2) {
	if (n4 == 2) { HaveTwoPair = true; return; }
	if (n3 == 2) { HaveTwoPair = true; return; }
	if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n4 == 2) {
	if (n3 == 2) { HaveTwoPair = true; return; }
	if (n2 == 2) { HaveTwoPair = true; return; }
	}
	else if (n3 == 2) {
	if (n2 == 2) { HaveTwoPair = true; return; }
	};

};
void Player::Set_HaveTrips() {
	//HaveSet
	if (PairInHand) {
		if (nA == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (nK == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (nQ == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (nT == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n9 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n8 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n7 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n6 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n5 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n4 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n3 == 3) { HaveSet = true; HaveTrips = true; return; }
		else if (n2 == 3) { HaveSet = true; HaveTrips = true; return; }
	}
	//HaveTrips
	else {
		if (nA == 3) { HaveTrips = true; return; }
		else if (nK == 3) { HaveTrips = true; return; }
		else if (nQ == 3) { HaveTrips = true; return; }
		else if (nT == 3) { HaveTrips = true; return; }
		else if (n9 == 3) { HaveTrips = true; return; }
		else if (n8 == 3) { HaveTrips = true; return; }
		else if (n7 == 3) { HaveTrips = true; return; }
		else if (n6 == 3) { HaveTrips = true; return; }
		else if (n5 == 3) { HaveTrips = true; return; }
		else if (n4 == 3) { HaveTrips = true; return; }
		else if (n3 == 3) { HaveTrips = true; return; }
		else if (n2 == 3) { HaveTrips = true; return; }
	};



};
void Player::Set_HaveSet() {};
void Player::Set_HaveStraight() {

	if (nA >= 1 && nK >= 1 && nQ >= 1 && nJ >= 1 && nT >= 1 ||
		nK >= 1 && nQ >= 1 && nJ >= 1 && nT >= 1 && n9 >= 1 ||
		nQ >= 1 && nJ >= 1 && nT >= 1 && n9 >= 1 && n8 >= 1 ||
		nJ >= 1 && nT >= 1 && n9 >= 1 && n8 >= 1 && n7 >= 1 ||
		nT >= 1 && n9 >= 1 && n8 >= 1 && n7 >= 1 && n6 >= 1 ||
		n9 >= 1 && n8 >= 1 && n7 >= 1 && n6 >= 1 && n5 >= 1 ||
		n8 >= 1 && n7 >= 1 && n6 >= 1 && n5 >= 1 && n4 >= 1 ||
		n7 >= 1 && n6 >= 1 && n5 >= 1 && n4 >= 1 && n3 >= 1 ||
		n6 >= 1 && n5 >= 1 && n4 >= 1 && n3 >= 1 && n2 >= 1 ||
		n5 >= 1 && n4 >= 1 && n3 >= 1 && n2 >= 1 && nA >= 1 ) { HaveStraight = true; return; }

};
void Player::Set_HaveFlush() {
	if (nc >= 5 || nd >= 5 || ns >= 5 || nh >= 5) { HaveFlush = true; return; }
	if (nc >= 3 || nd >= 3 || ns >= 3 || nh >= 3) { HaveFlushDraw = true; return; }
};
void Player::Set_HaveFullHouse() {};
void Player::Set_HaveFour() {

	if (nA == 4 || 
		nK == 4 || 
		nQ == 4 || 
		nJ == 4 || 
		nT == 4 || 
		n9 == 4 || 
		n8 == 4 || 
		n7 == 4 || 
		n6 == 4 || 
		n5 == 4 || 
		n4 == 4 || 
		n3 == 4 || 
		n2 == 4) {
		HaveFourOfAKind = true; return;
	}


};
void Player::Set_HaveStraightDraw() {};
void Player::Set_HaveFlushDraw() {

	if (nc >= 3 || ns == 3 || nh == 3 || nd == 3) {	HaveFlushDraw = true; }

};
bool Player::HaveCard(string _Card) {

	if (mycard[1] == _Card || mycard[2] == _Card) { return true; }

	return 0;
};
void Player::Set_FlushPossible(){

	if (nc >= 3 || ns >= 3 || nd >= 3 || nh >= 3) { FlushPossible = true; }



};
void Player::Set_StraightPossible(){

	if (nA >= 1 && nK >= 1 && nQ >= 1) { StraightPossible = true; }
	if (nA >= 1 && nK >= 1 && nJ >= 1) { StraightPossible = true; }
	if (nA >= 1 && nK >= 1 && nJ >= 1) { StraightPossible = true; }

	if (nA >= 1 && nK >= 1 && nQ >= 1) { StraightPossible = true; }
	if (nA >= 1 && nK >= 1 && nJ >= 1) { StraightPossible = true; }
	if (nA >= 1 && nK >= 1 && nJ >= 1) { StraightPossible = true; }


};
int Player::set_HandRank169() {

	if (hand$AA) { return 1; }

	if (hand$KK) { return 2; }

	if (hand$QQ) { return 3; }

	if (hand$AKs) { return 4; }

	if (hand$JJ) { return 5; }

	if (hand$AQs) { return 6; }

	if (hand$KQs) { return 7; }

	if (hand$AJs) { return 8; }

	if (hand$TT) { return 9; }

	if (hand$KJs) { return 10; }

	if (hand$AK) { return 11; }

	if (hand$ATs) { return 12; }

	if (hand$QJs) { return 13; }

	if (hand$KTs) { return 14; }

	if (hand$QTs) { return 15; }

	if (hand$JTs) { return 16; }

	if (hand$99) { return 17; }

	if (hand$AQ) { return 18; }

	if (hand$A9s) { return 19; }

	if (hand$KQ) { return 20; }

	if (hand$88) { return 21; }

	if (hand$K9s) { return 22; }

	if (hand$T9s) { return 23; }

	if (hand$A8s) { return 24; }

	if (hand$J9s) { return 25; }

	if (hand$Q9s) { return 26; }

	if (hand$77) { return 27; }

	if (hand$AJ) { return 28; }

	if (hand$A4s) { return 29; }

	if (hand$KJ) { return 30; }

	if (hand$A3s) { return 31; }

	if (hand$66) { return 32; }

	if (hand$A6s) { return 33; }

	if (hand$QJ) { return 34; }

	if (hand$K8s) { return 35; }

	if (hand$A2s) { return 36; }

	if (hand$T8s) { return 37; }

	if (hand$98s) { return 38; }

	if (hand$J8s) { return 39; }

	if (hand$AT) { return 40; }

	if (hand$Q8s) { return 41; }

	if (hand$55) { return 42; }

	if (hand$K7s) { return 43; }

	if (hand$JT) { return 44; }

	if (hand$KT) { return 45; }

	if (hand$44) { return 46; }

	if (hand$33) { return 47; }

	if (hand$22) { return 48; }

	if (hand$QT) { return 49; }

	if (hand$87s) { return 50; }

	if (hand$K6s) { return 51; }

	if (hand$97s) { return 52; }

	if (hand$K5s) { return 53; }

	if (hand$76s) { return 54; }

	if (hand$T7s) { return 55; }

	if (hand$K4s) { return 56; }

	if (hand$K3s) { return 57; }

	if (hand$Q7s) { return 58; }

	if (hand$K2s) { return 59; }

	if (hand$J7s) { return 60; }

	if (hand$86s) { return 61; }

	if (hand$65s) { return 62; }

	if (hand$54s) { return 63; }

	if (hand$Q6s) { return 64; }

	if (hand$75s) { return 65; }

	if (hand$Q5s) { return 66; }

	if (hand$96s) { return 67; }

	if (hand$Q4s) { return 68; }

	if (hand$Q3s) { return 69; }

	if (hand$64s) { return 70; }

	if (hand$T9) { return 71; }

	if (hand$Q2s) { return 72; }

	if (hand$A9) { return 73; }

	if (hand$T6s) { return 74; }

	if (hand$53s) { return 75; }

	if (hand$J6s) { return 76; }

	if (hand$85s) { return 77; }

	if (hand$J9) { return 78; }

	if (hand$K9) { return 79; }

	if (hand$43s) { return 80; }

	if (hand$J5s) { return 81; }

	if (hand$Q9) { return 82; }

	if (hand$74s) { return 83; }

	if (hand$J4s) { return 84; }

	if (hand$J3s) { return 85; }

	if (hand$J2s) { return 86; }

	if (hand$95s) { return 87; }

	if (hand$63s) { return 88; }

	if (hand$A8) { return 89; }

	if (hand$T5s) { return 90; }

	if (hand$52s) { return 91; }

	if (hand$42s) { return 92; }

	if (hand$T4s) { return 93; }

	if (hand$T3s) { return 94; }

	if (hand$84s) { return 95; }

	if (hand$98) { return 96; }

	if (hand$T2s) { return 97; }

	if (hand$A5) { return 98; }

	if (hand$T8) { return 99; }

	if (hand$A7) { return 100; }

	if (hand$73s) { return 101; }

	if (hand$32s) { return 102; }

	if (hand$A4) { return 103; }

	if (hand$94s) { return 104; }

	if (hand$93s) { return 105; }

	if (hand$62s) { return 106; }

	if (hand$A3) { return 107; }

	if (hand$K8) { return 108; }

	if (hand$J8) { return 109; }

	if (hand$92s) { return 110; }

	if (hand$A6) { return 111; }

	if (hand$87) { return 112; }

	if (hand$Q8) { return 113; }

	if (hand$83s) { return 114; }

	if (hand$A2) { return 115; }

	if (hand$82s) { return 116; }

	if (hand$97) { return 117; }

	if (hand$72s) { return 118; }

	if (hand$K7) { return 119; }

	if (hand$76) { return 120; }

	if (hand$T7) { return 121; }

	if (hand$65) { return 122; }

	if (hand$K6) { return 123; }

	if (hand$54) { return 124; }

	if (hand$K5) { return 125; }

	if (hand$J7) { return 126; }

	if (hand$Q7) { return 127; }

	if (hand$75) { return 128; }

	if (hand$K4) { return 129; }

	if (hand$K3) { return 130; }

	if (hand$96) { return 131; }

	if (hand$64) { return 132; }

	if (hand$K2) { return 133; }

	if (hand$53) { return 134; }

	if (hand$Q6) { return 135; }

	if (hand$85) { return 136; }

	if (hand$T6) { return 137; }

	if (hand$Q5) { return 138; }

	if (hand$43) { return 139; }

	if (hand$Q4) { return 140; }

	if (hand$Q3) { return 141; }

	if (hand$74) { return 142; }

	if (hand$Q2) { return 143; }

	if (hand$J6) { return 144; }

	if (hand$63) { return 145; }

	if (hand$J5) { return 146; }

	if (hand$95) { return 147; }

	if (hand$52) { return 148; }

	if (hand$J4) { return 149; }

	if (hand$42) { return 150; }

	if (hand$J3) { return 151; }

	if (hand$J2) { return 152; }

	if (hand$84) { return 153; }

	if (hand$T5) { return 154; }

	if (hand$32) { return 155; }

	if (hand$T4) { return 156; }

	if (hand$T3) { return 157; }

	if (hand$73) { return 158; }

	if (hand$72) { return 159; }

	if (hand$62) { return 160; }

	if (hand$94) { return 161; }

	if (hand$93) { return 162; }

	if (hand$92) { return 163; }

	if (hand$83) { return 164; }

	if (hand$82) { return 165; }

	if (hand$72) { return 166; }
	return 0;
};


void Player::set_MyCardInNumber(){
	int temp;

	for (int i = 0; i < 7; i++) {
		if (mycard[i] == "") { break; }
		switch (mycard[i][0]) {
		case 'A': { mycardInNumber[i] = 0; continue; }
		case 'K': { mycardInNumber[i] = 1; continue; }
		case 'Q': { mycardInNumber[i] = 2; continue; }
		case 'J': { mycardInNumber[i] = 3; continue; }
		case 'T': { mycardInNumber[i] = 4; continue; }
		case '9': { mycardInNumber[i] = 5; continue; }
		case '8': { mycardInNumber[i] = 6; continue; }
		case '7': { mycardInNumber[i] = 7; continue; }
		case '6': { mycardInNumber[i] = 8; continue; }
		case '5': { mycardInNumber[i] = 9; continue; }
		case '4': { mycardInNumber[i] = 10; continue; }
		case '3': { mycardInNumber[i] = 11; continue; }
		case '2': { mycardInNumber[i] = 12; continue; };
		}
	}
	//reorder array
	for (int i = 0; i < 7; i++)
	{
		if (mycardInNumber[i] == -2) { break; }
		for (int j = i + 1; j < 7; j++)
		{
			if (mycardInNumber[j] == -2) { break; }

			if (mycardInNumber[i] > mycardInNumber[j])
			{
				temp = mycardInNumber[i];
				mycardInNumber[i] = mycardInNumber[j];
				mycardInNumber[j] = temp;
			}
		}
	}


	
};
void Player::Set_PreflopNumber() {

	if (hand$AA) { PreflopNumber = 1; return; }
	if (hand$AK) {
		PreflopNumber = 2;
		if (hand$AKs) { PreflopNumber = 3; } return;
	}
	if (hand$AQ) {
		PreflopNumber = 4;
		if (hand$AQs) { PreflopNumber = 5; }return;
	}
	if (hand$AJ) {
		PreflopNumber = 6;
		if (hand$AJs) { PreflopNumber = 7; }return;
	}
	if (hand$AT) {
		PreflopNumber = 8;
		if (hand$ATs) { PreflopNumber = 9; }return;
	}
	if (hand$A9) {
		PreflopNumber = 10;
		if (hand$A9s) { PreflopNumber = 11; }return;
	}
	if (hand$A8) {
		PreflopNumber = 12;
		if (hand$A8s) { PreflopNumber = 13; }return;
	}
	if (hand$A7) {
		PreflopNumber = 14;
		if (hand$A7s) { PreflopNumber = 15; }return;
	}
	if (hand$A6) {
		PreflopNumber = 16;
		if (hand$A6s) { PreflopNumber = 17; }return;
	}
	if (hand$A5) {
		PreflopNumber = 18;
		if (hand$A5s) { PreflopNumber = 19; }return;
	}
	if (hand$A4) {
		PreflopNumber = 20;
		if (hand$A4s) { PreflopNumber = 21; }return;
	}
	if (hand$A3) {
		PreflopNumber = 22;
		if (hand$A3s) { PreflopNumber = 23; }return;
	}
	if (hand$A2) {
		PreflopNumber = 24;
		if (hand$A2s) { PreflopNumber = 25; }return;
	}
	if (hand$KK) { PreflopNumber = 26; return; }
	if (hand$KQ) {
		PreflopNumber = 27;
		if (hand$KQs) { PreflopNumber = 28; }return;
	}
	if (hand$KJ) {
		PreflopNumber = 29;
		if (hand$KJs) { PreflopNumber = 30; }return;
	}
	if (hand$KT) {
		PreflopNumber = 31;
		if (hand$KTs) { PreflopNumber = 32; }return;
	}
	if (hand$K9) {
		PreflopNumber = 33;
		if (hand$K9s) { PreflopNumber = 34; }return;
	}
	if (hand$K8) {
		PreflopNumber = 35;
		if (hand$K8s) { PreflopNumber = 36; }return;
	}
	if (hand$K7) {
		PreflopNumber = 37;
		if (hand$K7s) { PreflopNumber = 38; }return;
	}
	if (hand$K6) {
		PreflopNumber = 39;
		if (hand$K6s) { PreflopNumber = 40; }return;
	}
	if (hand$K5) {
		PreflopNumber = 41;
		if (hand$K5s) { PreflopNumber = 42; }return;
	}
	if (hand$K4) {
		PreflopNumber = 43;
		if (hand$K4s) { PreflopNumber = 44; }return;
	}
	if (hand$K3) {
		PreflopNumber = 45;
		if (hand$K3s) { PreflopNumber = 46; }return;
	}
	if (hand$K2) {
		PreflopNumber = 47;
		if (hand$K2s) { PreflopNumber = 48; }return;
	}
	if (hand$QQ) { PreflopNumber = 49; return; }
	if (hand$QJ) {
		PreflopNumber = 50;
		if (hand$QJs) { PreflopNumber = 51; }return;
	}
	if (hand$QT) {
		PreflopNumber = 52;
		if (hand$QTs) { PreflopNumber = 53; }return;
	}
	if (hand$Q9) {
		PreflopNumber = 54;
		if (hand$Q9s) { PreflopNumber = 55; }return;
	}
	if (hand$Q8) {
		PreflopNumber = 56;
		if (hand$Q8s) { PreflopNumber = 57; }return;
	}
	if (hand$Q7) {
		PreflopNumber = 58;
		if (hand$Q7s) { PreflopNumber = 59; }return;
	}
	if (hand$Q6) {
		PreflopNumber = 60;
		if (hand$Q6s) { PreflopNumber = 61; }return;
	}
	if (hand$Q5) {
		PreflopNumber = 62;
		if (hand$Q5s) { PreflopNumber = 63; }return;
	}
	if (hand$Q4) {
		PreflopNumber = 64;
		if (hand$Q4s) { PreflopNumber = 65; }return;
	}
	if (hand$Q3) {
		PreflopNumber = 66;
		if (hand$Q3s) { PreflopNumber = 67; }return;
	}
	if (hand$Q2) {
		PreflopNumber = 68;
		if (hand$Q2s) { PreflopNumber = 69; }return;
	}
	if (hand$JJ) { PreflopNumber = 70; return; }
	if (hand$JT) {
		PreflopNumber = 71;
		if (hand$JTs) { PreflopNumber = 72; }return;
	}
	if (hand$J9) {
		PreflopNumber = 73;
		if (hand$J9s) { PreflopNumber = 74; }return;
	}
	if (hand$J8) {
		PreflopNumber = 75;
		if (hand$J8s) { PreflopNumber = 76; }return;
	}
	if (hand$J7) {
		PreflopNumber = 77;
		if (hand$J7s) { PreflopNumber = 78; }return;
	}
	if (hand$J6) {
		PreflopNumber = 79;
		if (hand$J6s) { PreflopNumber = 80; }return;
	}
	if (hand$J5) {
		PreflopNumber = 81;
		if (hand$J5s) { PreflopNumber = 82; }return;
	}
	if (hand$J4) {
		PreflopNumber = 83;
		if (hand$J4s) { PreflopNumber = 84; }return;
	}
	if (hand$J3) {
		PreflopNumber = 85;
		if (hand$J3s) { PreflopNumber = 86; }return;
	}
	if (hand$J2) {
		PreflopNumber = 87;
		if (hand$J2s) { PreflopNumber = 88; }return;
	}
	if (hand$TT) { PreflopNumber = 89; return; }
	if (hand$T9) {
		PreflopNumber = 90;
		if (hand$T9s) { PreflopNumber = 91; }return;
	}
	if (hand$T8) {
		PreflopNumber = 92;
		if (hand$T8s) { PreflopNumber = 93; }return;
	}
	if (hand$T7) {
		PreflopNumber = 94;
		if (hand$T7s) { PreflopNumber = 95; }return;
	}
	if (hand$T6) {
		PreflopNumber = 96;
		if (hand$T6s) { PreflopNumber = 97; }return;
	}
	if (hand$T5) {
		PreflopNumber = 98;
		if (hand$T5s) { PreflopNumber = 99; }return;
	}
	if (hand$T4) {
		PreflopNumber = 100;
		if (hand$T4s) { PreflopNumber = 101; }return;
	}
	if (hand$T3) {
		PreflopNumber = 102;
		if (hand$T3s) { PreflopNumber = 103; }return;
	}
	if (hand$T2) {
		PreflopNumber = 104;
		if (hand$T2s) { PreflopNumber = 105; }return;
	}
	if (hand$99) { PreflopNumber = 106; return; }
	if (hand$98) {
		PreflopNumber = 107;
		if (hand$98s) { PreflopNumber = 108; }return;
	}
	if (hand$97) {
		PreflopNumber = 109;
		if (hand$97s) { PreflopNumber = 110; }return;
	}
	if (hand$96) {
		PreflopNumber = 111;
		if (hand$96s) { PreflopNumber = 112; }return;
	}
	if (hand$95) {
		PreflopNumber = 113;
		if (hand$95s) { PreflopNumber = 114; }return;
	}
	if (hand$94) {
		PreflopNumber = 115;
		if (hand$94s) { PreflopNumber = 116; }return;
	}
	if (hand$93) {
		PreflopNumber = 117;
		if (hand$93s) { PreflopNumber = 118; }return;
	}
	if (hand$92) {
		PreflopNumber = 119;
		if (hand$92s) { PreflopNumber = 120; }return;
	}
	if (hand$88) { PreflopNumber = 121; return; }
	if (hand$87) {
		PreflopNumber = 122;
		if (hand$87s) { PreflopNumber = 123; }return;
	}
	if (hand$86) {
		PreflopNumber = 124;
		if (hand$86s) { PreflopNumber = 125; }return;
	}
	if (hand$85) {
		PreflopNumber = 126;
		if (hand$85s) { PreflopNumber = 127; }return;
	}
	if (hand$84) {
		PreflopNumber = 128;
		if (hand$84s) { PreflopNumber = 129; }return;
	}
	if (hand$83) {
		PreflopNumber = 130;
		if (hand$83s) { PreflopNumber = 131; }return;
	}
	if (hand$82) {
		PreflopNumber = 132;
		if (hand$82s) { PreflopNumber = 133; }return;
	}
	if (hand$77) { PreflopNumber = 134; return; }
	if (hand$76) {
		PreflopNumber = 135;
		if (hand$76s) { PreflopNumber = 136; }return;
	}
	if (hand$75) {
		PreflopNumber = 137;
		if (hand$75s) { PreflopNumber = 138; }return;
	}
	if (hand$74) {
		PreflopNumber = 139;
		if (hand$74s) { PreflopNumber = 140; }return;
	}
	if (hand$73) {
		PreflopNumber = 141;
		if (hand$73s) { PreflopNumber = 142; }return;
	}
	if (hand$72) {
		PreflopNumber = 143;
		if (hand$72s) { PreflopNumber = 144; }return;
	}
	if (hand$66) { PreflopNumber = 145; return; }
	if (hand$65) {
		PreflopNumber = 146;
		if (hand$65s) { PreflopNumber = 147; }return;
	}
	if (hand$64) {
		PreflopNumber = 148;
		if (hand$64s) { PreflopNumber = 149; }return;
	}
	if (hand$63) {
		PreflopNumber = 150;
		if (hand$63s) { PreflopNumber = 151; }return;
	}
	if (hand$62) {
		PreflopNumber = 152;
		if (hand$62s) { PreflopNumber = 153; }return;
	}
	if (hand$55) { PreflopNumber = 154; return; }
	if (hand$54) {
		PreflopNumber = 155;
		if (hand$54s) { PreflopNumber = 156; }return;
	}
	if (hand$53) {
		PreflopNumber = 157;
		if (hand$53s) { PreflopNumber = 158; }return;
	}
	if (hand$52) {
		PreflopNumber = 159;
		if (hand$52s) { PreflopNumber = 160; }return;
	}
	if (hand$44) { PreflopNumber = 161; return; }
	if (hand$43) {
		PreflopNumber = 162;
		if (hand$43s) { PreflopNumber = 163; }return;
	}
	if (hand$42) {
		PreflopNumber = 164;
		if (hand$42s) { PreflopNumber = 165; }return;
	}
	if (hand$33) { PreflopNumber = 166; return; }
	if (hand$32) {
		PreflopNumber = 167;
		if (hand$32s) { PreflopNumber = 168; }return;
	}
	if (hand$22) { PreflopNumber = 169; return; }





};
void Player::Set_Symbols() {

	Set_HavePair();
	Set_HaveTwoPair();
	Set_HaveTrips();
	Set_HaveSet();
	Set_HaveStraight();
	Set_HaveFlush();
	Set_HaveFullHouse();
	Set_HaveFour();
	Set_HaveStraightDraw();
	Set_HaveFlushDraw();


};

bool Player::PotRange(int _min, int _max) {

	if (Pot >= _min && Pot <= _max) return true;
	return false;
};
bool Player::StackRange(int _min, int _max){

	//if (mystack >= _min && mystack <= _max) return true;
	return false;

};
bool Player::PrwinRange(float _min, float _max){
	if (prwin >= _min && prwin <= _max) return true;
	return false;

};
int Player::Set_PreflopSituationNumber() {

	
	return 0;
};



