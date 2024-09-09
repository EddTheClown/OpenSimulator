#pragma once
#include "Main.h"
#include "Simulator.h"
#include "Ambient.h"
#include "map"


#define Random (rand()%100)
#define ToCall (AmountToCall / Table->BBsize)
#define StackSize (mystack / Table->BBsize)

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
	Position = EPosition::null;

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


	winner = false;
	SituationNumber = -1;
	SimulationLevel = 0;
	Situation = 0;
	opponentraise = false;


	set_StartingStack();



};

//update all the necessary var to make a decision
void Player::Update_TableInformation() {
	
	CountCard();
	Situation = set_situation();

	Opponents = (Table->ActivePlayer - 1);
	Pot = (Table->PotSize / Table->BBsize );

	set_AmountToCall();


	set_MaxOpponentStackSize();
	set_effective_stack();
	set_mycard();
	set_Stacklevel();
	set_position();

	//choose if opponent have to calc prwin whit opponentprwin in player.h
	if (myname != "Player0") bprwin = opponentprwin;

	if (bprwin) {
		prwin = calc_prwin();
		prlos = 1.0 - prwin; 
	}
	


};

//check the betsize and calc the difference from mybet and betsize for call
void Player::set_AmountToCall() {
	currentbet = mybet;
	AmountToCall = Table->BetSize - currentbet;
	if (AmountToCall >= mystack) { AmountToCall = mystack; };

};

//count the max and the min stack of opponents
void Player::set_MaxOpponentStackSize() {
	MaxBet = 0;
	MaxOpponentStackSize = 0;
	MinOpponentStackSize = 999999999;

	//set max e min stacks
	for (int i = (Table->nPlayers - 1); i >= 0; i--) {
		//if (*PlayersStack[i] == mystack) { continue; }
		if (*Table->PlayersStack[i] >= MaxOpponentStackSize && *Table->PlayersState[i] != State::Fold) {
			MaxOpponentStackSize = *Table->PlayersStack[i]; MaxBet = *Table->PlayersStack[i];
		};
		if (*Table->PlayersStack[i] <= MinOpponentStackSize && *Table->PlayersState[i] != State::Fold) { MinOpponentStackSize = *Table->PlayersStack[i]; };
	}
};

//set opponents at the table (incomplete)
void Player::set_OpponentsAtTable() {

	OpponentsAtTable = (Table->nPlayers - 1);


};

//save the starting stack at the begin of hand
void Player::set_StartingStack() {

	StartingStack = mystack;


};

//calc my hand strength at the end of hand
int  Player::set_HandStrength() {
	if (mystate == State::Fold) { HandStrength = -100000; return HandStrength; }

	CHandStrength* calc = new CHandStrength;
	HandStrength = calc->calc_HandStrength(mycard[0], mycard[1], mycard[2], mycard[3], mycard[4], mycard[5], mycard[6]);
	delete calc;


	return HandStrength;

};

//set the stack level in BB
void Player::set_Stacklevel() {

	if (mystack <= (5 * Table->BBsize)) { StackLevel = 1; return; };
	if (mystack <= (10 * Table->BBsize)) { StackLevel = 2; return; };
	if (mystack <= (15 * Table->BBsize)) { StackLevel = 3; return; };
	if (mystack <= (20 * Table->BBsize)) { StackLevel = 4; return; };
	if (mystack <= (30 * Table->BBsize)) { StackLevel = 5; return; };
	if (mystack <= (40 * Table->BBsize)) { StackLevel = 6; return; };
	if (mystack <= (50 * Table->BBsize)) { StackLevel = 7; return; };
	if (mystack <= (60 * Table->BBsize)) { StackLevel = 8; return; };
	if (mystack <= (70 * Table->BBsize)) { StackLevel = 9; return; };
	if (mystack <= (80 * Table->BBsize)) { StackLevel = 10; return; };
	if (mystack <= (90 * Table->BBsize)) { StackLevel = 11; return; };
	if (mystack <= (100 * Table->BBsize)) { StackLevel = 12; return; };
	if (mystack > (100 * Table->BBsize)) { StackLevel = 13; return; };
};

//update the knowing card based on bet round
void Player::set_mycard() {

	switch (Table->BetRound) {

	case 1:
		mycard[0] = *MyCards[0];
		mycard[1] = *MyCards[1];
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

	if (myposition == Table->SBPosition) { inSmallBlind = true; Position = EPosition::SB; return; };
	if (myposition == Table->BBPosition) { inBigBlind = true;  Position = EPosition::BB; return; };
	if (myposition == Table->ButtonPosition) { inButton = true; Position = EPosition::Button;  return; };
	if (myposition == Table->COPosition) { inCutOff = true; Position = EPosition::CutOff;  return; };
	if (myposition == Table->MiddlePosition3) { inMiddlePosition = true; Position = EPosition::Middle3;  return; };
	if (myposition == Table->MiddlePosition2) { inMiddlePosition = true; Position = EPosition::Middle2;  return; };
	if (myposition == Table->MiddlePosition1) { inMiddlePosition = true; Position = EPosition::Middle1;  return; };
	if (myposition == Table->EarlyPosition2) { inEarlyPosition = true; Position = EPosition::Early2;  return; };
	if (myposition == Table->EarlyPosition1) { inEarlyPosition = true; Position = EPosition::Early1;  return; };


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
			case 'A':  cA = 1; nA += 1; nc += 1;  continue;
			case 'K':  cK = 1; nK += 1; nc += 1; continue;
			case 'Q':  cQ = 1; nQ += 1; nc += 1;  continue;
			case 'J':  cJ = 1; nJ += 1; nc += 1; continue;
			case 'T':  cT = 1; nT += 1; nc += 1;  continue;
			case '9':  c9 = 1; n9 += 1; nc += 1; continue;
			case '8':  c8 = 1; n8 += 1; nc += 1;  continue;
			case '7':  c7 = 1; n7 += 1; nc += 1;  continue;
			case '6':  c6 = 1; n6 += 1; nc += 1;  continue;
			case '5':  c5 = 1; n5 += 1; nc += 1;  continue;
			case '4':  c4 = 1; n4 += 1; nc += 1;  continue;
			case '3':  c3 = 1; n3 += 1; nc += 1; continue;
			case '2':  c2 = 1; n2 += 1; nc += 1;  continue;
				break;
			}
		case 'd':
			switch (mycard[i][0]) {
			case 'A':  dA = 1; nA += 1; nd += 1; continue;
			case 'K':  dK = 1; nK += 1; nd += 1;continue;
			case 'Q':  dQ = 1; nQ += 1; nd += 1; continue;
			case 'J':  dJ = 1; nJ += 1; nd += 1; continue;
			case 'T':  dT = 1; nT += 1; nd += 1; continue;
			case '9':  d9 = 1; n9 += 1; nd += 1; continue;
			case '8':  d8 = 1; n8 += 1; nd += 1; continue;
			case '7': d7 = 1; n7 += 1; nd += 1;  continue;
			case '6': d6 = 1; n6 += 1; nd += 1;  continue;
			case '5': d5 = 1; n5 += 1; nd += 1;  continue;
			case '4': d4 = 1; n4 += 1; nd += 1;  continue;
			case '3': d3 = 1; n3 += 1; nd += 1;  continue;
			case '2':  d2 = 1; n2 += 1; nd += 1; continue;
				break;
			}
		case 's':
			switch (mycard[i][0]) {
			case 'A':  sA = 1; nA += 1; ns += 1;continue;
			case 'K':  sK = 1; nK += 1; ns += 1;continue;

			case 'Q':  sQ = 1; nQ += 1; ns += 1;continue;
			case 'J':  sJ = 1; nJ += 1; ns += 1;continue;
			case 'T':  sT = 1; nT += 1; ns += 1;continue;
			case '9':  s9 = 1; n9 += 1; ns += 1;continue;
			case '8':  s8 = 1; n8 += 1; ns += 1;continue;
			case '7':  s7 = 1; n7 += 1; ns += 1;continue;
			case '6':  s6 = 1; n6 += 1; ns += 1;continue;
			case '5':  s5 = 1; n5 += 1; ns += 1;continue;
			case '4':  s4 = 1; n4 += 1; ns += 1;continue;
			case '3':  s3 = 1; n3 += 1; ns += 1;continue;
			case '2':  s2 = 1; n2 += 1; ns += 1;continue;
			}
		case 'h':
			switch (mycard[i][0]) {
			case 'A': hA = 1; nA += 1; nh += 1;continue;
			case 'K': hK = 1; nK += 1; nh += 1;continue;
			case 'Q': hQ = 1; nQ += 1; nh += 1;continue;
			case 'J': hJ = 1; nJ += 1; nh += 1;continue;
			case 'T': hT = 1; nT += 1; nh += 1;continue;
			case '9': h9 = 1; n9 += 1; nh += 1;continue;
			case '8': h8 = 1; n8 += 1; nh += 1;continue;
			case '7': h7 = 1; n7 += 1; nh += 1;continue;
			case '6': h6 = 1; n6 += 1; nh += 1;continue;
			case '5': h5 = 1; n5 += 1; nh += 1;continue;
			case '4': h4 = 1; n4 += 1; nh += 1;continue;
			case '3': h3 = 1; n3 += 1; nh += 1;continue;
			case '2': h2 = 1; n2 += 1; nh += 1;continue;
			}
			break;
		}

	};

	
	if (nh >= nc || nh >= nd || nh >= ns ) { NumberOfSuit = nh; }
	else if (nc >= nd || nc >= ns || nc >= nh) { NumberOfSuit = nc; }
	else if (nd >= ns || nd >= nc || nd >= nh) { NumberOfSuit = nd; }
	else if (ns >= nc || ns >= nd || ns >= nh) { NumberOfSuit = ns; }

	set_MyCardInNumber();


	

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

	switch (Table->BetRound) {
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
	if (AmountToCall == 0 && Table->BetRound == 1 && inBigBlind) { linea = __LINE__; do_Check(); return; };
	if (AmountToCall == 0 && Table->BetRound > 1) { linea = __LINE__; do_Check(); return; };


	HandStrength = -100000;
	mystate = State::Fold;
	BotLastAction = State::Fold;


};
//perform check action
void Player::do_Check() {
	if (AmountToCall > 0) { do_Fold(); return; }

	mystate = State::Check;
	BotLastAction = State::Check;




};
//perform call action
void Player::do_Call() {
	if (AmountToCall == 0) { ; do_Check(); return; };
	if (AmountToCall >= mystack || StackSize-ToCall <= 10) { do_Allin(); return; }
	mybet += AmountToCall;
	mystate = State::Call;
	BotLastAction = State::Call;

};
//perform raise action
void Player::do_Raise() {
	int RandomNumber = rand() % 6;

	if (Table->BetRound == 1 && Pot >= 40) { do_Allin(); return; }
	if (Table->BetRound == 2 && Pot >= 48) { do_Allin(); return; }
	if (Table->BetRound == 3 && Pot >= 38) { do_Allin(); return; }
	if (Table->BetRound == 4 && Pot >= 38) { do_Allin(); return; }

	if(Table->BetRound == 2 && StackSize <20) { do_Allin(); return; }
	if(StackSize <=13) { do_Allin(); return; }

	if (Table->PlayersInHand == 1) { do_Call(); return; }
	if (mystack <= 15 * Table->BBsize) { do_Allin(); return; }
	if (AmountToCall >= mystack) { do_Allin(); return; }

	if (AmountToCall > 0 && AmountToCall < Table->SBsize) { do_Call(); return; }

	
		if (Table->BetRound == 1) {

			myraise = Table->BetSize * 3;

			if ((AmountToCall / Table->BBsize) <= 1 && Table->Calls == 0) { myraise = Table->BBsize * 3; }
			if ((AmountToCall / Table->BBsize) <= 1 && Table->Calls > 0) { myraise = (Table->BBsize * 3) + (Table->BBsize * Table->Calls); }
			if (OpponentsAtTable == 1 && Pot <= 2) myraise = Table->BBsize * (1 + rand() % 3);

		}
		else {
			if (Table->BetSize == 0) {
				switch (RandomNumber) {
				case 0:
					myraise = 0.75 * Table->PotSize;
					break;
				case 1:
					myraise = 0.80 * Table->PotSize;
					break;
				case 2:
					myraise = 0.85 * Table->PotSize;
					break;
				case 3:
					myraise = 0.90 * Table->PotSize;
					break;
				case 4:
					myraise = 0.95 * Table->PotSize;
					break;
				case 5:
					myraise = Table->PotSize;
					break;
				};
			}
			else { myraise = Table->BetSize * 3; };
		}
	

	//custom raise for opponents
	if (myname != "Player0" && opponentraise) {
		int number = rand() % 10;
		switch (number) {
		case 0:
			myraise = 1 * Table->BBsize;
		case 1:
			myraise = 1 * Table->BBsize;
		case 2:
			myraise = 2 * Table->BBsize;
		case 3:
			myraise = 2 * Table->BBsize;
		case 4:
			myraise = 0.5 * Table->PotSize;
		case 5:
			myraise = 0.6 * Table->PotSize;
		case 6:
			myraise = 0.7 * Table->PotSize;
		case 7:
			myraise = 0.8 * Table->PotSize;
		case 8:
			myraise = 0.9 * Table->PotSize;
		case 9:
			myraise = Table->PotSize;
		}
		number = 0;
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

	
	if (MaxBet == 0) {  do_Call(); return; }

	if (myraise < AmountToCall) { do_Fold(); return; };


	if (myraise == AmountToCall && AmountToCall == 0) { do_Check(); return; }
	if (myraise == AmountToCall && AmountToCall > 0) {  do_Call(); return; }

	if (myraise >= 0.8 * mystack && mystack <= MaxOpponentStackSize) { do_Allin(); return; }

	while (myraise % Table->BBsize) { myraise++; }
	if (myraise >= MaxOpponentStackSize && MaxOpponentStackSize > Table->BetSize) { myraise = MaxOpponentStackSize; }
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
	mybet = Table->ANTEsize;

	if (mybet >= mystack) { mystate = State::Forced_Allin; mybet = mystack; }

	UpdateMyStack();

};
//put blinds in the pot
void Player::post_Blinds() {


	if (inBigBlind) { mystate = State::Blinds; mybet = Table->BBsize; }
	if (inSmallBlind) { mystate = State::Blinds; mybet = Table->SBsize; }

	if (mybet >= mystack) { mystate = State::Forced_Allin; mybet = mystack; }

	UpdateMyStack();
};

//if true in player.h calc the prwin 
double Player::calc_prwin() {
	
	prwin_calcolator* calc = new prwin_calcolator;	
	prwin = calc->calc_prwin(mycard[0], mycard[1], mycard[2], mycard[3], mycard[4], mycard[5], mycard[6], Table->ActivePlayer, prwin_iterations);
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
string Player::Position_to_String(EPosition _Position) {

	switch (Position) {

	case EPosition::Early1:
		return "EPosition::Early1";
	case EPosition::Early2:
		return "EPosition::Early2";
	case EPosition::Early3:
		return "EPosition::Early3";
	case EPosition::Middle1:
		return "EPosition::Middle1";
	case EPosition::Middle2:
		return "EPosition::Middle2";
	case EPosition::Middle3:
		return "EPosition::Middle3";
	case EPosition::CutOff:
		return "EPosition::CutOff";
	case EPosition::Button:
		return "EPosition::Button";
	case EPosition::SB:
		return "EPosition::SB";
	case EPosition::BB:
		return "EPosition::BB";

	}

	return "error";
};

//if true in player.h write the log in txt 
void Player::pDebug(int _decision , string filename) {
	if (myname != "Player0")return;

	if (bDebug) {
		ofstream scrivi;
		string pos = "";
		string line = "";
		Table->PlayerLastStack = StackSize;
		if (inMiddlePosition)pos = "InMiddlePosition";
		if (inCutOff)pos = "InCutOff";
		if (inButton)pos = "InButton";
		if (inSmallBlind)pos = "InSmallBlind";
		if (inBigBlind)pos = "InBigBlind";

		line += "\nHANDNUMBER: " + to_string(Table->Handnumber )+ " (decision " +to_string(_decision)+")";
		line += "\nbetround: " + to_string(Table->BetRound);
		line += "\nprwin: " + to_string(prwin) + " ";
		line += get_mycards() + "\n";
		line += "\nStack: " + to_string(mystack / Table->BBsize);
		line += "\nBBSize: " + to_string(Table->BBsize);
		line += "\nPot(bb): " + to_string(Pot);
		line += "\nAmountToCall: " + to_string(ToCall);
		line += "\nActivePlayers= " + to_string(Table->ActivePlayer);
		line += "\n BotLastAction: " + State_to_String(BotLastAction);
		line += "\n BotLastPreflopAction: " + State_to_String(BotLastPreflopAction);
		line += "\n BotLastFlopAction: " + State_to_String(BotLastFlopAction);
		line += "\n BotLastTurnAction: " + State_to_String(BotLastTurnAction);
		line += "\n Table->StillToAct: " + to_string(Table->StillToAct);

		Table->LastPlayerHand = line;

		linea = 0;
		;
		line += "\n\n---PER RAISE---\n";
		line += "if(";
		line += "Pot <= " + to_string(Pot);
		line+= "&& prwin >= " + to_string(prwin);
		line += "&& Table->ActivePlayer == " + to_string(Table->ActivePlayer);

		//line += "Position == " + Position_to_String(Position) + " && ";
		//line += "BotLastAction == State::" + State_to_String(BotLastAction) + " && ";
		if (Table->BetRound >= 1)line += " && BotLastPreflopAction == State::" + State_to_String(BotLastPreflopAction);
		if (Table->BetRound >= 2)line += " && BotLastFlopAction == State::" + State_to_String(BotLastFlopAction);
		if (Table->BetRound >= 3)line += " && BotLastTurnAction == State::" + State_to_String(BotLastTurnAction);
		//line += "StackSize >= " + to_string(StackSize)+")return true;";
		line += ")return true;\n\n";


		line += "---PER ALLIN---\n";
		line += "if(prwin >= " + to_string(prwin) + " && ";
		line += "Position == " + Position_to_String(Position) + " && ";
		line += "BotLastAction == State::" + State_to_String(BotLastAction) + " && ";
		if (Table->BetRound >= 1)line += "BotLastPreflopAction == State::" + State_to_String(BotLastPreflopAction) + " && ";
		if (Table->BetRound >= 2)line += "BotLastFlopAction == State::" + State_to_String(BotLastFlopAction) + " && ";
		if (Table->BetRound >= 3)line += "BotLastTurnAction == State::" + State_to_String(BotLastTurnAction) + " && ";
		line += "*nPlayers == " + to_string(Table->ActivePlayer) + " && ";
		line += "Pot <= " + to_string(Pot) + " && ";
		line += "StackSize <= " + to_string(StackSize) + ")return true;";
		line += "\n\n";

		line += "---PER CALL---\n";
		line += "if(prwin >= " + to_string(prwin) + " && ";
		line += "Position == " + Position_to_String(Position) + " && ";
		line += "BotLastAction == State::" + State_to_String(BotLastAction) + " && ";
		if (Table->BetRound >= 1)line += "BotLastPreflopAction == State::" + State_to_String(BotLastPreflopAction) + " && ";
		if (Table->BetRound >= 2)line += "BotLastFlopAction == State::" + State_to_String(BotLastFlopAction) + " && ";
		if (Table->BetRound >= 3)line += "BotLastTurnAction == State::" + State_to_String(BotLastTurnAction) + " && ";
		line += "*nPlayers == " + to_string(Table->ActivePlayer) + " && ";
		line += "ToCall <= " + to_string(ToCall) + " && ";
		line += "StackSize >= " + to_string(StackSize) + ")return true;";
		line += "\n\n";

		line += "---PER FOLD---\n";
		line += "if(prwin <= " + to_string(prwin) + " && ";
		line += "Position == " + Position_to_String(Position) + " && ";
		line += "BotLastAction == State::" + State_to_String(BotLastAction) + " && ";
		if (Table->BetRound >= 1)line += "BotLastPreflopAction == State::" + State_to_String(BotLastPreflopAction) + " && ";
		if (Table->BetRound >= 2)line += "BotLastFlopAction == State::" + State_to_String(BotLastFlopAction) + " && ";
		if (Table->BetRound >= 3)line += "BotLastTurnAction == State::" + State_to_String(BotLastTurnAction) + " && ";
		line += "*nPlayers == " + to_string(Table->ActivePlayer) + " && ";
		line += "ToCall >= " + to_string(ToCall) + " && ";
		line += "StackSize <= " + to_string(StackSize) + ")return true;";
		line += "\n\n";



		line += "\n\n";
		/*
		line += "Action Taken: " + to_string(_decision) + "\n";
		line += "Linea eseguita: " + to_string(linea) + "\n\n";



		//per individuare facilmente
		line += "\nprwin: " + to_string(prwin);

		if (Table->BetRound == 1) line += " preflop ";
		if (Table->BetRound == 2) line += " Flop ";
		if (Table->BetRound == 3) line += " Turn ";
		if (Table->BetRound == 4) line += " River ";
		line += "\n OpponentsAtTable: " + to_string(OpponentsAtTable)+"\n";
		if (inMiddlePosition)line += " inMiddlePosition ";
		if (inCutOff)line += " inCutOff ";
		if (inButton)line += " inButton ";
		if (inSmallBlind)line += " inSmallBlind ";
		if (inBigBlind)line += " inBigBlind ";
		line += "\n Pot " + to_string(Pot)+"\n";


		line += "\n" + myname + " (" + State_to_String(mystate) + " " + to_string(mybet) + ") " + " " + get_mycards();
		line += "\nprwin: " + to_string(prwin);

		line += "\nStack: " + to_string(mystack / Table->BBsize);
		line += "\nPot(bb): " + to_string(Pot);
		line += "\nAmountToCall: " + to_string(ToCall);
		line += "\nTotalInvested: " + to_string(TotalInvested / Table->BBsize) + "\n";
		line += "\nPlayersInHand= " + to_string(Table->PlayersInHand);
		line += "\nActivePlayers= " + to_string(Table->ActivePlayer);
		line += "\nOpponentsAtTable: " + to_string(OpponentsAtTable);

		line += "\nPosition: " + to_string((int)Position);
		line += "\n inBigBlind: " + to_string(inBigBlind);
		line += "\n inSmallBlind: " + to_string(inSmallBlind);
		line += "\n inButton: " + to_string(inButton);
		line += "\n inCutOff: " + to_string(inCutOff);
		line += "\n inMiddlePosition: " + to_string(inMiddlePosition);
		line += "\n inEarlyPosition: " + to_string(inEarlyPosition) + "\n";

		line += "\nbetround: " + to_string(Table->BetRound);
		line += "\n BotLastAction: " + State_to_String(BotLastAction);
		line += "\n BotLastPreflopAction: " + State_to_String(BotLastPreflopAction);
		line += "\n BotLastFlopAction: " + State_to_String(BotLastFlopAction);
		line += "\n BotLastTurnAction: " + State_to_String(BotLastTurnAction);
		line += "\n BotLastRiverAction: " + State_to_String(BotLastRiverAction) + "\n";
		


		line += "\nMaxStackSize: " + to_string(MaxOpponentStackSize);
		line += "\nMinStackSize: " + to_string(MinOpponentStackSize);
		line += "\nMaxBet: " + to_string(MaxBet);
		line += "\nMyraise: " + to_string(myraise / Table->BBsize);
		line += "\nBetSize: " + to_string(*BetSize / Table->BBsize);
		line += "\nTotalInvested: " + to_string(TotalInvested / Table->BBsize) + "\n";

		line += "\nFolds: " + to_string(*Folds);
		line += "\nChecks: " + to_string(*Checks);
		line += "\nCalls: " + to_string(*Calls);
		line += "\nRaises: " + to_string(*Raises);
		line += "\nAllins: " + to_string(*Allins);
		line += "\nTable->StillToAct: " + to_string(*Table->StillToAct);
		*/
		line += "\n#####################################\n" ;
		
		scrivi.open(filename, ios::app);
		scrivi << line;
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

//make decision to action at my turn
void Player::MyTurn(vector<Player> _p) {

	//for put breakpoint debug example
	//if (myname == "Player0" && Table->Handnumber == 15)getchar();


	//in this case hero is player0
	decision = 0;

	Update_TableInformation();

	if (myname == "Player0") {
		// cout << "!";

	}

	//post blinds
	if (myposition == Table->BBPosition && mystate == State::null) { post_Blinds(); return; }
	if (myposition == Table->SBPosition && mystate == State::null) { post_Blinds(); return; }



	if (myname == "Player0" && ManualPlay) {
		cout << "Not avaible, Work in progress.. any key to continue in automatic.\n";
		ManualPlay = false;

		//cout << "\nEnter your decision: 0= Fold , 1= Check , 2=Call , 3=Raise , 4= Allin\n"; 
	}

		
	
	/*
	//in this way get sensible action, but require a lot of time and other simulation levels.
	if (myname == "Player0" && !isSimulation)decision = set_decision();
	else if (!isSimulation) decision = choose_decision(_p);
	else {
		if (SimulationLevel == 1)decision = TestDecision;
		else decision = rand()%4;
	}*/

	/*
	if (!isSimulation)decision = set_decision4();
	if (isSimulation){
		if (SimulationLevel == 1)decision = TestDecision;
		else decision = set_decision4();
	}
	*/
	
	decision = set_decision4();
	


	




	//write log if actcive in player.h
	if (bDebug && writehand) { pDebug(decision); }

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
	


	//set bot last actions
	switch (Table->BetRound) {
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

	if (mystack == 0)mystate = State::Allin;


};
int Player::choose_decision(vector<Player> _p) {
	//questa funzione viene chiamata quando è il momento di fare l'azione vera, lo scopo è quello di ottenere l'azione migliore utilizzando le simulazioni
	SimulationLevel++;
		BestDecision = 0;
		int scores[5] = { 0 };
		win = -100000000;
		isSimulation = true;
		for (int ind = 2; ind <= 3; ind++) {
			
			for (int i = 0; i < 1000; i++) {


				Simulator* sim = new Simulator;
				sim->nPlayers = Table->nPlayers;
				sim->HH->HHline = HHline;
				updateGameNumber(sim->HH->HHline, SimulateHands);


				//setta le variabili di tutti i giocatori al fine di riprodurre esattamente lo stato attuale del tavolo (carte, stack , bet ecc)
				sim->set_PlayerVar(_p, myposition);

				//ind rappresenta la decisione di test 0-fold 1-check 2-call 3-raise 4-allin, start_hand simula una mano e ritorna +1 in caso di vittoria e -1 in caso di sconfitta
				scores[ind] += sim->start_hand(ind, myposition);
				SimulateHands++;
				delete sim;
				
			}

			//scores[ind] /= 100;
			
		}
		
			//trova l'azione col miglior punteggio
		for (int i = 2; i <= 3; i++) {
			if (scores[i] >= win && scores[i]>0) {
				win = scores[i];					
				BestDecision = i;
			}
		}
		
		isSimulation = false;
		SimulationLevel=0;
		pDebug(BestDecision, "test.txt");
		return BestDecision;

}
double Player::Calc_EventProbability(vector<Player> _p, string Evento) {
	int nSimulation = 100;
	double percentuale = 0;
	double volte = 0;

	for (int i = 0; i < nSimulation; i++) {
		Simulator *Sim = new Simulator;

		Sim->set_PlayerVar(_p, myposition);
		volte += Sim->CountActionSimulations(3,myposition, Evento);
		delete Sim;

	}
	// varie operazioni di confronto

	return volte/nSimulation;
}



int Player::set_decision() {
	prwin = calc_prwin();
	return decision = choose_decision(Table->p);


	return 0;


};
int Player::set_decision2() {
	//opponentraise = true;
	int numero = rand() % 100;
	if (numero >= 80) return 2;
	if (numero >= 60) return 3;
	return rand() % 4;
};

//this have PT leak tracker exatly at center of green area
int Player::set_decision3() {
	Situation = set_situation();
	switch (Situation) {
	case 0:
		set_writehand(100);
		/*
		//raise
		if (Pot <= 2) {
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.583) return 3;
				break;
			case 3:
				if (prwin >= 0.4) return 3;
				break;
			case 4:
				if (prwin >= 0.32) return 3;
				break;
			case 5:
				if (prwin >= 0.259) return 3;
				break;
			case 6:
				if (prwin >= 0.24) return 3;
				break;
			case 7:
				if (prwin >= 0.19) return 3;
				break;
			case 8:
				if (prwin >= 0.18) return 3;
				break;
			case 9:
				if (prwin >= 0.16) return 3;
				break;
			}

			return 0;
		}
		if (Pot <= 5) {

			//min hand AcKd  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.633) return 3;
				break;
			case 3:
				if (prwin >= 0.467) return 3;
				break;
			case 4:
				if (prwin >= 0.368) return 3;
				break;
			case 5:
				if (prwin >= 0.304) return 3;
				break;
			case 6:
				if (prwin >= 0.255) return 3;
				break;
			case 7:
				if (prwin >= 0.225) return 3;
				break;
			case 8:
				if (prwin >= 0.199) return 3;
				break;
			case 9:
				if (prwin >= 0.172) return 3;
				break;
			}
			return 0;


		}
		if (Pot <= 10) {
			//min hand QcQd  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.784) return 3;
				break;
			case 3:
				if (prwin >= 0.636) return 3;
				break;
			case 4:
				if (prwin >= 0.522) return 3;
				break;
			case 5:
				if (prwin >= 0.433) return 3;
				break;
			case 6:
				if (prwin >= 0.367) return 3;
				break;
			case 7:
				if (prwin >= 0.312) return 3;
				break;
			case 8:
				if (prwin >= 0.268) return 3;
				break;
			case 9:
				if (prwin >= 0.236) return 3;
				break;
			}
			return 0;



		}

		//call
		if (Pot <= 2) {

			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.572) return 2;
				break;
			case 3:
				if (prwin >= 0.386) return 2;
				break;
			case 4:
				if (prwin >= 0.296) return 2;
				break;
			case 5:
				if (prwin >= 0.25) return 2;
				break;
			case 6:
				if (prwin >= 0.22) return 2;
				break;
			case 7:
				if (prwin >= 0.212) return 2;
				break;
			case 8:
				if (prwin >= 0.197) return 2;
				break;
			case 9:
				if (prwin >= 0.19) return 2;
				break;
			}
			return false;

		}
		if (Pot <= 5) {
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.583) return 2;
				break;
			case 3:
				if (prwin >= 0.409) return 2;
				break;
			case 4:
				if (prwin >= 0.32) return 2;
				break;
			case 5:
				if (prwin >= 0.259) return 2;
				break;
			case 6:
				if (prwin >= 0.23) return 2;
				break;
			case 7:
				if (prwin >= 0.21) return 2;
				break;
			case 8:
				if (prwin >= 0.18) return 2;
				break;
			case 9:
				if (prwin >= 0.2) return 2;
				break;
			}
			return false;



		}
		if (Pot <= 15) {
			//min hand AcKd  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.6) return 2;
				break;
			case 3:
				if (prwin >= 0.44) return 2;
				break;
			case 4:
				if (prwin >= 0.369) return 2;
				break;
			case 5:
				if (prwin >= 0.304) return 2;
				break;
			case 6:
				if (prwin >= 0.259) return 2;
				break;
			case 7:
				if (prwin >= 0.226) return 2;
				break;
			case 8:
				if (prwin >= 0.193) return 2;
				break;
			case 9:
				if (prwin >= 0.173) return 2;
				break;
			}
			return false;





		}


		
		//min hand KcKd  raise
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.81) return 3;
			break;
		case 3:
			if (prwin >= 0.677) return 3;
			break;
		case 4:
			if (prwin >= 0.568) return 3;
			break;
		case 5:
			if (prwin >= 0.482) return 3;
			break;
		case 6:
			if (prwin >= 0.418) return 3;
			break;
		case 7:
			if (prwin >= 0.363) return 3;
			break;
		case 8:
			if (prwin >= 0.316) return 3;
			break;
		case 9:
			if (prwin >= 0.28) return 3;
			break;
		}

		//min hand QcQd  call
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.784) return 2;
			break;
		case 3:
			if (prwin >= 0.636) return 2;
			break;
		case 4:
			if (prwin >= 0.522) return 2;
			break;
		case 5:
			if (prwin >= 0.433) return 2;
			break;
		case 6:
			if (prwin >= 0.367) return 2;
			break;
		case 7:
			if (prwin >= 0.312) return 2;
			break;
		case 8:
			if (prwin >= 0.268) return 2;
			break;
		case 9:
			if (prwin >= 0.236) return 2;
			break;
		}
		set_writehand(100);
		*/
		return 0;		
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	case 26:
		break;
	case 27:
		break;
	case 28:
		break;
	case 29:
		break;
	case 30:
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 34:
		break;
	case 35:
		break;
	case 36:
		break;
	case 37:
		break;
	case 38:
		break;
	case 39:
		break;
	case 40:
		break;
	case 41:
		break;
	case 42:
		break;
	case 43:
		break;
	case 44:
		break;
	case 45:
		break;
	case 46:
		break;
	case 47:
		break;
	case 48:
		break;
	case 49:
		break;
	case 50:
		break;
	case 51:
		break;
	case 52:
		break;
	case 53:
		break;
	case 54:
		break;
	case 55:
		break;
	case 56:
		break;
	case 57:
		break;
	case 58:
		break;
	case 59:
		break;
	case 60:
		break;
	case 61:
		break;
	case 62:
		break;
	case 63:
		break;
	case 64:
		break;
	case 65:
		break;
	case 66:
		break;
	case 67:
		break;
	case 68:
		break;
	case 69:
		break;
	case 70:
		break;
	case 71:
		break;
	case 72:
		break;
	case 73:
		break;
	case 74:
		break;
	case 75:
		break;
	case 76:
		break;
	case 77:
		break;
	case 78:
		break;
	case 79:
		break;
	case 80:
		break;
	case 81:
		break;
	case 82:
		break;
	case 83:
		break;
	case 84:
		break;
	case 85:
		break;
	case 86:
		break;
	case 87:
		break;
	case 88:
		break;
	case 89:
		break;
	case 90:
		break;
	case 91:
		break;
	case 92:
		break;
	case 93:
		break;
	case 94:
		break;
	case 95:
		break;
	case 96:
		break;
	case 97:
		break;
	case 98:
		break;
	case 99:
		break;
	case 100:
		break;
	case 101:
		break;
	case 102:
		break;
	case 103:
		break;
	case 104:
		break;
	case 105:
		break;
	case 106:
		break;
	case 107:
		break;
	case 108:
		break;
	case 109:
		break;
	case 110:
		break;
	case 111:
		break;
	case 112:
		break;
	case 113:
		break;
	case 114:
		break;
	case 115:
		break;
	case 116:
		break;
	case 117:
		break;
	case 118:
		break;
	case 119:
		break;
	case 120:
		break;
	case 121:
		break;
	case 122:
		break;
	case 123:
		break;
	case 124:
		break;
	case 125:
		break;
	case 126:
		break;
	case 127:
		break;
	case 128:
		break;
	case 129:
		break;
	case 130:
		break;
	case 131:
		break;
	case 132:
		break;
	case 133:
		break;
	case 134:
		break;
	case 135:
		break;
	case 136:
		break;
	case 137:
		break;
	case 138:
		break;
	case 139:
		break;
	case 140:
		break;
	case 141:
		break;
	case 142:
		break;
	case 143:
		break;
	case 144:
		break;
	case 145:
		break;
	case 146:
		break;
	case 147:
		break;
	case 148:
		break;
	case 149:
		break;
	case 150:
		break;
	case 151:
		break;
	case 152:
		break;
	case 153:
		break;
	case 154:
		break;
	case 155:
		break;
	case 156:
		break;
	case 157:
		break;
	case 158:
		break;
	}


	return 0;
};


int Player::set_decision5() {
	writehand = true;
	int situation = set_situation();

	return 0;

}
//set situation based on bot actions
int Player::set_situation() {

	if (Table->BetRound == 1) {
		if (BotLastAction == State::None) return 0;
		if (BotLastAction == State::Call) return 1;
		if (BotLastAction == State::Raise) return 2;
	}	
	if (Table->BetRound == 2) {
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
	if (Table->BetRound == 3) {
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
	if (Table->BetRound == 4) {
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::None) return 51;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 52;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 53;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 54;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 55;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 56;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 57;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 58;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::None) return 59;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 60;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 61;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 62;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::None) return 63;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 64;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 65;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 66;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 67;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 68;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 69;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 70;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::None) return 71;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 72;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 73;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 74;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::None) return 75;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 76;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 77;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 78;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 79;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 80;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 81;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 82;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::None) return 83;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 84;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 85;
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 86;

		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::None) return 87;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 88;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 89;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 90;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 91;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 92;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 93;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 94;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::None) return 95;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 96;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 97;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 98;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::None) return 99;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 100;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 101;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 102;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 103;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 104;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 105;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 106;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::None) return 107;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 108;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 109;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 110;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::None) return 111;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 112;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 113;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 114;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 115;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 116;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 117;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 118;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::None) return 119;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 120;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 121;
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 122;

		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::None) return 123;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 124;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 125;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 126;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 127;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 128;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 129;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 130;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::None) return 131;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 132;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 133;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Call && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 134;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::None) return 135;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 136;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 137;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 138;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 139;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 140;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 141;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 142;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::None) return 143;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 144;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 145;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Raise && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 146;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::None) return 147;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Call) return 148;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Raise) return 149;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Call && BotLastAction == State::Check) return 150;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::None) return 151;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Call) return 152;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Raise) return 153;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise && BotLastAction == State::Check) return 154;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::None) return 155;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Call) return 156;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Raise) return 157;
		if (BotLastPreflopAction == State::Check && BotLastFlopAction == State::Check && BotLastTurnAction == State::Check && BotLastAction == State::Check) return 158;

	}
	return 0;
}

//set symbols (incomplete)
bool Player::HaveCard(string _Card) {

	if (mycard[1] == _Card || mycard[2] == _Card) { return true; }

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


int Player::set_decision4() {
	assert(prwin < 1);

	writehand = true;
	//set_writehand(1000, true);

	switch (Table->BetRound) {
	case 1:
		if (preflop_Raise()) return 3;
		if (preflop_Call()) return 2;

		break;
	case 2:

		if (flop_Raise()) return 3;
		if (flop_Call()) return 2;
		break;
	case 3:

		if (turn_Raise()) return 3;
		if (turn_Call()) return 2;

		break;
	case 4:
		if (river_Raise()) return 3;
		if (river_Call()) return 2;

		break;
	}


	return 0;

};

//He finished first in one and almost always in the money in the other $1 tournaments, but probably too tight.
bool Player::preflop_Raise() {
		if (StackSize <= 25) {
			if (ToCall <= 2) {
				if (StackSize <= 5) {//min hand Ac4c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.564) return true;
						break;
					case 3:
						if (prwin >= 0.375) return true;
						break;
					case 4:
						if (prwin >= 0.282) return true;
						break;
					case 5:
						if (prwin >= 0.226) return true;
						break;
					case 6:
						if (prwin >= 0.189) return true;
						break;
					case 7:
						if (prwin >= 0.163) return true;
						break;
					case 8:
						if (prwin >= 0.146) return true;
						break;
					case 9:
						if (prwin >= 0.131) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 6) {
					//min hand Ac5c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.57) return true;
						break;
					case 3:
						if (prwin >= 0.389) return true;
						break;
					case 4:
						if (prwin >= 0.289) return true;
						break;
					case 5:
						if (prwin >= 0.231) return true;
						break;
					case 6:
						if (prwin >= 0.195) return true;
						break;
					case 7:
						if (prwin >= 0.17) return true;
						break;
					case 8:
						if (prwin >= 0.147) return true;
						break;
					case 9:
						if (prwin >= 0.133) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 7) {//min hand 7cQc  
					//min hand Ac6c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.571) return true;
						break;
					case 3:
						if (prwin >= 0.384) return true;
						break;
					case 4:
						if (prwin >= 0.287) return true;
						break;
					case 5:
						if (prwin >= 0.226) return true;
						break;
					case 6:
						if (prwin >= 0.189) return true;
						break;
					case 7:
						if (prwin >= 0.163) return true;
						break;
					case 8:
						if (prwin >= 0.142) return true;
						break;
					case 9:
						if (prwin >= 0.129) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 8) {//min hand 7dKh  
					//min hand Ac7c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.585) return true;
						break;
					case 3:
						if (prwin >= 0.398) return true;
						break;
					case 4:
						if (prwin >= 0.297) return true;
						break;
					case 5:
						if (prwin >= 0.236) return true;
						break;
					case 6:
						if (prwin >= 0.199) return true;
						break;
					case 7:
						if (prwin >= 0.169) return true;
						break;
					case 8:
						if (prwin >= 0.151) return true;
						break;
					case 9:
						if (prwin >= 0.132) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 9) {
					//min hand Ac8c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.595) return true;
						break;
					case 3:
						if (prwin >= 0.409) return true;
						break;
					case 4:
						if (prwin >= 0.312) return true;
						break;
					case 5:
						if (prwin >= 0.248) return true;
						break;
					case 6:
						if (prwin >= 0.208) return true;
						break;
					case 7:
						if (prwin >= 0.179) return true;
						break;
					case 8:
						if (prwin >= 0.156) return true;
						break;
					case 9:
						if (prwin >= 0.14) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 10) {
					//min hand Ac9c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.604) return true;
						break;
					case 3:
						if (prwin >= 0.42) return true;
						break;
					case 4:
						if (prwin >= 0.32) return true;
						break;
					case 5:
						if (prwin >= 0.3) return true;
						break;
					case 6:
						if (prwin >= 0.219) return true;
						break;
					case 7:
						if (prwin >= 0.21) return true;
						break;
					case 8:
						if (prwin >= 0.166) return true;
						break;
					case 9:
						if (prwin >= 0.149) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 15) {
					//min hand AcTc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.626) return true;
						break;
					case 3:
						if (prwin >= 0.449) return true;
						break;
					case 4:
						if (prwin >= 0.348) return true;
						break;
					case 5:
						if (prwin >= 0.287) return true;
						break;
					case 6:
						if (prwin >= 0.246) return true;
						break;
					case 7:
						if (prwin >= 0.213) return true;
						break;
					case 8:
						if (prwin >= 0.185) return true;
						break;
					case 9:
						if (prwin >= 0.167) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 16) {//min hand AcJc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.633) return true;
						break;
					case 3:
						if (prwin >= 0.459) return true;
						break;
					case 4:
						if (prwin >= 0.363) return true;
						break;
					case 5:
						if (prwin >= 0.298) return true;
						break;
					case 6:
						if (prwin >= 0.257) return true;
						break;
					case 7:
						if (prwin >= 0.224) return true;
						break;
					case 8:
						if (prwin >= 0.199) return true;
						break;
					case 9:
						if (prwin >= 0.178) return true;
						break;
					}
					return false;

				}
				if (StackSize <= 17) {//min hand AcQc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.643) return true;
						break;
					case 3:
						if (prwin >= 0.474) return true;
						break;
					case 4:
						if (prwin >= 0.379) return true;
						break;
					case 5:
						if (prwin >= 0.316) return true;
						break;
					case 6:
						if (prwin >= 0.272) return true;
						break;
					case 7:
						if (prwin >= 0.238) return true;
						break;
					case 8:
						if (prwin >= 0.214) return true;
						break;
					case 9:
						if (prwin >= 0.191) return true;
						break;
					}
					return false;

				}
				if (StackSize <= 20) {
					//min hand AcKc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.652) return true;
						break;
					case 3:
						if (prwin >= 0.489) return true;
						break;
					case 4:
						if (prwin >= 0.396) return true;
						break;
					case 5:
						if (prwin >= 0.332) return true;
						break;
					case 6:
						if (prwin >= 0.291) return true;
						break;
					case 7:
						if (prwin >= 0.256) return true;
						break;
					case 8:
						if (prwin >= 0.231) return true;
						break;
					case 9:
						if (prwin >= 0.206) return true;
						break;
					}
					return false;




				}
				if (StackSize <= 25) {
					//min hand JcJd  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.762) return true;
						break;
					case 3:
						if (prwin >= 0.598) return true;
						break;
					case 4:
						if (prwin >= 0.475) return true;
						break;
					case 5:
						if (prwin >= 0.39) return true;
						break;
					case 6:
						if (prwin >= 0.323) return true;
						break;
					case 7:
						if (prwin >= 0.273) return true;
						break;
					case 8:
						if (prwin >= 0.233) return true;
						break;
					case 9:
						if (prwin >= 0.201) return true;
						break;
					}
					return false;




				}
			}
			if (ToCall <= 5) {
				if (StackSize <= 5) {
					//min hand Ac5c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.57) return true;
						break;
					case 3:
						if (prwin >= 0.389) return true;
						break;
					case 4:
						if (prwin >= 0.289) return true;
						break;
					case 5:
						if (prwin >= 0.231) return true;
						break;
					case 6:
						if (prwin >= 0.195) return true;
						break;
					case 7:
						if (prwin >= 0.17) return true;
						break;
					case 8:
						if (prwin >= 0.147) return true;
						break;
					case 9:
						if (prwin >= 0.133) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 6) {//min hand 7cQc  
					//min hand Ac6c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.571) return true;
						break;
					case 3:
						if (prwin >= 0.384) return true;
						break;
					case 4:
						if (prwin >= 0.287) return true;
						break;
					case 5:
						if (prwin >= 0.226) return true;
						break;
					case 6:
						if (prwin >= 0.189) return true;
						break;
					case 7:
						if (prwin >= 0.163) return true;
						break;
					case 8:
						if (prwin >= 0.142) return true;
						break;
					case 9:
						if (prwin >= 0.129) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 7) {
					//min hand Ac7c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.585) return true;
						break;
					case 3:
						if (prwin >= 0.398) return true;
						break;
					case 4:
						if (prwin >= 0.297) return true;
						break;
					case 5:
						if (prwin >= 0.236) return true;
						break;
					case 6:
						if (prwin >= 0.199) return true;
						break;
					case 7:
						if (prwin >= 0.169) return true;
						break;
					case 8:
						if (prwin >= 0.151) return true;
						break;
					case 9:
						if (prwin >= 0.132) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 8) {
					//min hand Ac8c  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.595) return true;
						break;
					case 3:
						if (prwin >= 0.409) return true;
						break;
					case 4:
						if (prwin >= 0.312) return true;
						break;
					case 5:
						if (prwin >= 0.248) return true;
						break;
					case 6:
						if (prwin >= 0.208) return true;
						break;
					case 7:
						if (prwin >= 0.179) return true;
						break;
					case 8:
						if (prwin >= 0.156) return true;
						break;
					case 9:
						if (prwin >= 0.14) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 9) {
					//min hand AcTc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.626) return true;
						break;
					case 3:
						if (prwin >= 0.449) return true;
						break;
					case 4:
						if (prwin >= 0.348) return true;
						break;
					case 5:
						if (prwin >= 0.287) return true;
						break;
					case 6:
						if (prwin >= 0.246) return true;
						break;
					case 7:
						if (prwin >= 0.213) return true;
						break;
					case 8:
						if (prwin >= 0.185) return true;
						break;
					case 9:
						if (prwin >= 0.167) return true;
						break;
					}
					return false;



				}
				if (StackSize <= 10) {//min hand AcJc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.633) return true;
						break;
					case 3:
						if (prwin >= 0.459) return true;
						break;
					case 4:
						if (prwin >= 0.363) return true;
						break;
					case 5:
						if (prwin >= 0.298) return true;
						break;
					case 6:
						if (prwin >= 0.257) return true;
						break;
					case 7:
						if (prwin >= 0.224) return true;
						break;
					case 8:
						if (prwin >= 0.199) return true;
						break;
					case 9:
						if (prwin >= 0.178) return true;
						break;
					}
					return false;

				}
				if (StackSize <= 15) {//min hand AcQc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.643) return true;
						break;
					case 3:
						if (prwin >= 0.474) return true;
						break;
					case 4:
						if (prwin >= 0.379) return true;
						break;
					case 5:
						if (prwin >= 0.316) return true;
						break;
					case 6:
						if (prwin >= 0.272) return true;
						break;
					case 7:
						if (prwin >= 0.238) return true;
						break;
					case 8:
						if (prwin >= 0.214) return true;
						break;
					case 9:
						if (prwin >= 0.191) return true;
						break;
					}
					return false;

				}
				if (StackSize <= 20) {
					//min hand AcKc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.652) return true;
						break;
					case 3:
						if (prwin >= 0.489) return true;
						break;
					case 4:
						if (prwin >= 0.396) return true;
						break;
					case 5:
						if (prwin >= 0.332) return true;
						break;
					case 6:
						if (prwin >= 0.291) return true;
						break;
					case 7:
						if (prwin >= 0.256) return true;
						break;
					case 8:
						if (prwin >= 0.231) return true;
						break;
					case 9:
						if (prwin >= 0.206) return true;
						break;
					}
					return false;




				}				
				if (StackSize <= 25) {
					//min hand JcJd  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.762) return true;
						break;
					case 3:
						if (prwin >= 0.598) return true;
						break;
					case 4:
						if (prwin >= 0.475) return true;
						break;
					case 5:
						if (prwin >= 0.39) return true;
						break;
					case 6:
						if (prwin >= 0.323) return true;
						break;
					case 7:
						if (prwin >= 0.273) return true;
						break;
					case 8:
						if (prwin >= 0.233) return true;
						break;
					case 9:
						if (prwin >= 0.201) return true;
						break;
					}
					return false;




				}
			}
			if (ToCall <= 10) {
				if (StackSize <= 20) {
					//min hand AcKc  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.652) return true;
						break;
					case 3:
						if (prwin >= 0.489) return true;
						break;
					case 4:
						if (prwin >= 0.396) return true;
						break;
					case 5:
						if (prwin >= 0.332) return true;
						break;
					case 6:
						if (prwin >= 0.291) return true;
						break;
					case 7:
						if (prwin >= 0.256) return true;
						break;
					case 8:
						if (prwin >= 0.231) return true;
						break;
					case 9:
						if (prwin >= 0.206) return true;
						break;
					}
					return false;




				}
				if (StackSize <= 25) {
					//min hand JcJd  
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.762) return true;
						break;
					case 3:
						if (prwin >= 0.598) return true;
						break;
					case 4:
						if (prwin >= 0.475) return true;
						break;
					case 5:
						if (prwin >= 0.39) return true;
						break;
					case 6:
						if (prwin >= 0.323) return true;
						break;
					case 7:
						if (prwin >= 0.273) return true;
						break;
					case 8:
						if (prwin >= 0.233) return true;
						break;
					case 9:
						if (prwin >= 0.201) return true;
						break;
					}
					return false;




				}



			}


			if (StackSize <= 10) {
				//min hand AcKh  
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.635) return true;
					break;
				case 3:
					if (prwin >= 0.463) return true;
					break;
				case 4:
					if (prwin >= 0.365) return true;
					break;
				case 5:
					if (prwin >= 0.302) return true;
					break;
				case 6:
					if (prwin >= 0.257) return true;
					break;
				case 7:
					if (prwin >= 0.225) return true;
					break;
				case 8:
					if (prwin >= 0.196) return true;
					break;
				case 9:
					if (prwin >= 0.173) return true;
					break;
				}
				return false;


			}
			if (StackSize <= 15) {
				//min hand AcKc  
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.651) return true;
					break;
				case 3:
					if (prwin >= 0.487) return true;
					break;
				case 4:
					if (prwin >= 0.393) return true;
					break;
				case 5:
					if (prwin >= 0.334) return true;
					break;
				case 6:
					if (prwin >= 0.292) return true;
					break;
				case 7:
					if (prwin >= 0.26) return true;
					break;
				case 8:
					if (prwin >= 0.231) return true;
					break;
				case 9:
					if (prwin >= 0.209) return true;
					break;
				}
				return false;



			}
			if (StackSize <= 20) {
				//min hand TcTd  
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.736) return true;
					break;
				case 3:
					if (prwin >= 0.56) return true;
					break;
				case 4:
					if (prwin >= 0.437) return true;
					break;
				case 5:
					if (prwin >= 0.347) return true;
					break;
				case 6:
					if (prwin >= 0.286) return true;
					break;
				case 7:
					if (prwin >= 0.236) return true;
					break;
				case 8:
					if (prwin >= 0.207) return true;
					break;
				case 9:
					if (prwin >= 0.176) return true;
					break;
				}
				return false;




			}
			if (StackSize <= 25) {
				//min hand JcJd  
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.762) return true;
					break;
				case 3:
					if (prwin >= 0.598) return true;
					break;
				case 4:
					if (prwin >= 0.477) return true;
					break;
				case 5:
					if (prwin >= 0.387) return true;
					break;
				case 6:
					if (prwin >= 0.321) return true;
					break;
				case 7:
					if (prwin >= 0.27) return true;
					break;
				case 8:
					if (prwin >= 0.233) return true;
					break;
				case 9:
					if (prwin >= 0.204) return true;
					break;
				}
				return false;






			}



	}
		if (OpponentsAtTable == 1) {
			if (inSmallBlind) {
				if (Pot <= 2 && prwin >= 0.5)return true;
				if (Pot <= 3 && prwin >= 0.55)return true;
				if (Pot <= 5 && prwin >= 0.6)return true;
				if (Pot <= 10 && prwin >= 0.65)return true;
				if (Pot <= 20 && prwin >= 0.7)return true;
			}
			if (inBigBlind) {
				if (Pot <= 5 && prwin >= 0.55) return true;
				if (Pot <= 10 && prwin >= 0.6) return true;
				if (Pot <= 20 && prwin >= 0.7) return true;

			}

			if (prwin >= 0.75)return true;
			return false;

		}



		if (Pot <= 2) {

			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.583) return true;
				break;
			case 3:
				if (prwin >= 0.38) return true;
				break;
			case 4:
				if (prwin >= 0.30) return true;
				break;
			case 5:
				if (prwin >= 0.25) return true;
				break;
			case 6:
				if (prwin >= 0.23) return true;
				break;
			case 7:
				if (prwin >= 0.21) return true;
				break;
			case 8:
				if (prwin >= 0.21) return true;
				break;
			case 9:
				if (prwin >= 0.15)	return true;
				break;
			}

			return false;
		}
		if (Pot <= 3) {
			//min hand 9h9d  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.705) return true;
				break;
			case 3:
				if (prwin >= 0.522) return true;
				break;
			case 4:
				if (prwin >= 0.4) return true;
				break;
			case 5:
				if (prwin >= 0.312) return true;
				break;
			case 6:
				if (prwin >= 0.255) return true;
				break;
			case 7:
				if (prwin >= 0.214) return true;
				break;
			case 8:
				if (prwin >= 0.181) return true;
				break;
			case 9:
				if (prwin >= 0.16) return true;
				break;
			}
			return false;




		}
		if (Pot <= 5) {
			//min hand JcJd  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.759) return true;
				break;
			case 3:
				if (prwin >= 0.6) return true;
				break;
			case 4:
				if (prwin >= 0.478) return true;
				break;
			case 5:
				if (prwin >= 0.39) return true;
				break;
			case 6:
				if (prwin >= 0.32) return true;
				break;
			case 7:
				if (prwin >= 0.27) return true;
				break;
			case 8:
				if (prwin >= 0.237) return true;
				break;
			case 9:
				if (prwin >= 0.2) return true;
				break;
			}
			return false;





		}

		if (Pot <= 7 && prwin >= 0.47 && Table->ActivePlayer == 3 && BotLastPreflopAction == State::None)return true;

		if (Pot <= 10) {
			//min hand QcQd  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.784) return true;
				break;
			case 3:
				if (prwin >= 0.636) return true;
				break;
			case 4:
				if (prwin >= 0.522) return true;
				break;
			case 5:
				if (prwin >= 0.433) return true;
				break;
			case 6:
				if (prwin >= 0.367) return true;
				break;
			case 7:
				if (prwin >= 0.312) return true;
				break;
			case 8:
				if (prwin >= 0.268) return true;
				break;
			case 9:
				if (prwin >= 0.236) return true;
				break;
			}
			return false;


		}

		//min hand KcKd  
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.81) return true;
			break;
		case 3:
			if (prwin >= 0.677) return true;
			break;
		case 4:
			if (prwin >= 0.568) return true;
			break;
		case 5:
			if (prwin >= 0.482) return true;
			break;
		case 6:
			if (prwin >= 0.418) return true;
			break;
		case 7:
			if (prwin >= 0.363) return true;
			break;
		case 8:
			if (prwin >= 0.316) return true;
			break;
		case 9:
			if (prwin >= 0.28) return true;
			break;
		}
		return false;
	
}
bool Player::preflop_Call() {
	if (OpponentsAtTable == 1) {
		if (inSmallBlind) {
			if (Pot <= 5 && prwin >= 0.43)return true;
			if (Pot <= 10 && prwin >= 0.53)return true;
			if (Pot <= 20 && prwin >= 0.63)return true;
		}
		if (inBigBlind) {
			if (Pot <= 5 && prwin >= .47) return true;
			if (Pot <= 10 && prwin >= .57) return true;
			if (Pot <= 15 && prwin >= .67) return true;
		}


		if (prwin >= 0.7)return true;
		return false;
	}
	if (StackSize <= 15) {
		if (BotLastPreflopAction == State::Call) {
			//min hand JhAh  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.634) return true;
				break;
			case 3:
				if (prwin >= 0.459) return true;
				break;
			case 4:
				if (prwin >= 0.363) return true;
				break;
			case 5:
				if (prwin >= 0.3) return true;
				break;
			case 6:
				if (prwin >= 0.26) return true;
				break;
			case 7:
				if (prwin >= 0.224) return true;
				break;
			case 8:
				if (prwin >= 0.198) return true;
				break;
			case 9:
				if (prwin >= 0.178) return true;
				break;
			}
			return false;



		}


	}
	if (StackSize <= 20) {
		//min hand AcKh  
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.634) return true;
			break;
		case 3:
			if (prwin >= 0.46) return true;
			break;
		case 4:
			if (prwin >= 0.366) return true;
			break;
		case 5:
			if (prwin >= 0.302) return true;
			break;
		case 6:
			if (prwin >= 0.255) return true;
			break;
		case 7:
			if (prwin >= 0.225) return true;
			break;
		case 8:
			if (prwin >= 0.198) return true;
			break;
		case 9:
			if (prwin >= 0.174) return true;
			break;
		}
		return false;




	}
	if (StackSize <= 25) {
		//min hand TcTd  
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.734) return true;
			break;
		case 3:
			if (prwin >= 0.561) return true;
			break;
		case 4:
			if (prwin >= 0.438) return true;
			break;
		case 5:
			if (prwin >= 0.349) return true;
			break;
		case 6:
			if (prwin >= 0.283) return true;
			break;
		case 7:
			if (prwin >= 0.238) return true;
			break;
		case 8:
			if (prwin >= 0.202) return true;
			break;
		case 9:
			if (prwin >= 0.177) return true;
			break;
		}
		return false;






	}

	if (Pot <= 2) {
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.572) return true;
			break;
		case 3:
			if (prwin >= 0.386) return true;
			break;
		case 4:
			if (prwin >= 0.296) return true;
			break;
		case 5:
			if (prwin >= 0.25) return true;
			break;
		case 6:
			if (prwin >= 0.22) return true;
			break;
		case 7:
			if (prwin >= 0.212) return true;
			break;
		case 8:
			if (prwin >= 0.197) return true;
			break;
		case 9:
			if (prwin >= 0.19) return true;
			break;
		}
		return false;

	}
	if (Pot <= 5) {
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.583) return true;
			break;
		case 3:
			if (prwin >= 0.409) return true;
			break;
		case 4:
			if (prwin >= 0.29) return true;
			break;
		case 5:
			if (prwin >= 0.259) return true;
			break;
		case 6:
			if (prwin >= 0.23) return true;
			break;
		case 7:
			if (prwin >= 0.21) return true;
			break;
		case 8:
			if (prwin >= 0.18) return true;
			break;
		case 9:
			if (prwin >= 0.2) return true;
			break;
		}
		return false;



	}
	if (Pot <= 7) {
		if (StackSize < 25) {
			//min hand JhAh  
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.634) return true;
				break;
			case 3:
				if (prwin >= 0.459) return true;
				break;
			case 4:
				if (prwin >= 0.363) return true;
				break;
			case 5:
				if (prwin >= 0.3) return true;
				break;
			case 6:
				if (prwin >= 0.26) return true;
				break;
			case 7:
				if (prwin >= 0.224) return true;
				break;
			case 8:
				if (prwin >= 0.198) return true;
				break;
			case 9:
				if (prwin >= 0.178) return true;
				break;
			}
			return false;



		}
		if (prwin >= 0.357 && Table->ActivePlayer == 4 && BotLastPreflopAction == State::None)return true;
		if (prwin >= 0.406 && Table->ActivePlayer == 3 && BotLastPreflopAction == State::None)return true;
		if (prwin >= 0.26 && Table->ActivePlayer == 5 && BotLastPreflopAction == State::None)return true;
		if (prwin >= 0.59 && Table->ActivePlayer == 2 && BotLastPreflopAction == State::Call)return true;

	}
	if (Pot <= 15) {
		//min hand AcKd  
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.6) return true;
			break;
		case 3:
			if (prwin >= 0.44) return true;
			break;
		case 4:
			if (prwin >= 0.369) return true;
			break;
		case 5:
			if (prwin >= 0.304) return true;
			break;
		case 6:
			if (prwin >= 0.259) return true;
			break;
		case 7:
			if (prwin >= 0.226) return true;
			break;
		case 8:
			if (prwin >= 0.193) return true;
			break;
		case 9:
			if (prwin >= 0.173) return true;
			break;
		}
		return false;





	}
	if (Pot <= 16) {
		if (prwin < 0.5 && Table->ActivePlayer == 3 && BotLastPreflopAction == State::Raise)return false;

		if (prwin >= 0.47 && Table->ActivePlayer == 3 && BotLastPreflopAction == State::Raise)return true;
		if (prwin >= 0.64 && Table->ActivePlayer == 2 && BotLastPreflopAction == State::Call)return true;
	}
	if (Pot <= 20 && prwin >= 0.37 && Table->ActivePlayer == 4 && BotLastPreflopAction == State::Raise)return true;
	if (Pot <= 22 && prwin >= 0.43 && Table->ActivePlayer == 3 && BotLastPreflopAction == State::Raise)return true;
	if (Pot <= 40 && prwin >= 0.77 && Table->ActivePlayer == 2 && BotLastPreflopAction == State::Raise)return true;


	//min hand QcQd  
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.784) return true;
		break;
	case 3:
		if (prwin >= 0.636) return true;
		break;
	case 4:
		if (prwin >= 0.522) return true;
		break;
	case 5:
		if (prwin >= 0.433) return true;
		break;
	case 6:
		if (prwin >= 0.367) return true;
		break;
	case 7:
		if (prwin >= 0.312) return true;
		break;
	case 8:
		if (prwin >= 0.268) return true;
		break;
	case 9:
		if (prwin >= 0.236) return true;
		break;
	}
	return false;
};


bool Player::flop_Raise() {
	if (StackSize <= 20) {
		//min hand AhJh 7cJs3h 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.834) return true;
			break;
		case 3:
			if (prwin >= 0.706) return true;
			break;
		case 4:
			if (prwin >= 0.607) return true;
			break;
		case 5:
			if (prwin >= 0.521) return true;
			break;
		case 6:
			if (prwin >= 0.451) return true;
			break;
		case 7:
			if (prwin >= 0.392) return true;
			break;
		case 8:
			if (prwin >= 0.344) return true;
			break;
		case 9:
			if (prwin >= 0.305) return true;
			break;
		}
		return false;

	}
	if (StackSize <= 30) {
		//min hand KcKs 8c5h8d 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.831) return true;
			break;
		case 3:
			if (prwin >= 0.703) return true;
			break;
		case 4:
			if (prwin >= 0.592) return true;
			break;
		case 5:
			if (prwin >= 0.502) return true;
			break;
		case 6:
			if (prwin >= 0.426) return true;
			break;
		case 7:
			if (prwin >= 0.368) return true;
			break;
		case 8:
			if (prwin >= 0.312) return true;
			break;
		case 9:
			if (prwin >= 0.27) return true;
			break;
		}
		return false;






	}
	if (StackSize <= 40) {
		if (Pot <= 7 && prwin >= 0.412300 && Table->ActivePlayer == 2 && BotLastPreflopAction == State::Raise && BotLastFlopAction == State::None)return true;

		if (Pot <= 10) {
			//min hand QcQh Jd6h6d 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.806) return true;
				break;
			case 3:
				if (prwin >= 0.662) return true;
				break;
			case 4:
				if (prwin >= 0.552) return true;
				break;
			case 5:
				if (prwin >= 0.461) return true;
				break;
			case 6:
				if (prwin >= 0.387) return true;
				break;
			case 7:
				if (prwin >= 0.324) return true;
				break;
			case 8:
				if (prwin >= 0.276) return true;
				break;
			case 9:
				if (prwin >= 0.236) return true;
				break;
			}
			return false;



		}
		if (Pot <= 20) {
			//min hand QcTc 8cJsQd 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.804) return true;
				break;
			case 3:
				if (prwin >= 0.661) return true;
				break;
			case 4:
				if (prwin >= 0.549) return true;
				break;
			case 5:
				if (prwin >= 0.455) return true;
				break;
			case 6:
				if (prwin >= 0.379) return true;
				break;
			case 7:
				if (prwin >= 0.313) return true;
				break;
			case 8:
				if (prwin >= 0.263) return true;
				break;
			case 9:
				if (prwin >= 0.222) return true;
				break;
			}
			return false;




		}


	}
	if (StackSize <= 50) {
		//min hand KsKh 6cJd2s 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.846) return true;
			break;
		case 3:
			if (prwin >= 0.724) return true;
			break;
		case 4:
			if (prwin >= 0.622) return true;
			break;
		case 5:
			if (prwin >= 0.529) return true;
			break;
		case 6:
			if (prwin >= 0.458) return true;
			break;
		case 7:
			if (prwin >= 0.392) return true;
			break;
		case 8:
			if (prwin >= 0.335) return true;
			break;
		case 9:
			if (prwin >= 0.288) return true;
			break;
		}
		return false;



	}

	if (BotLastFlopAction == State::None) {
		if (BotLastPreflopAction == State::Raise) {
			if (Pot <= 15 && prwin >= 0.9 && StackSize > 20 && Table->ActivePlayer == 2)return false;//slow
			if (Pot <= 10) {
				//min hand 2s4s 2c5sKd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.549) return true;
					break;
				case 3:
					if (prwin >= 0.341) return true;
					break;
				case 4:
					if (prwin >= 0.241) return true;
					break;
				case 5:
					if (prwin >= 0.181) return true;
					break;
				case 6:
					if (prwin >= 0.15) return true;
					break;
				case 7:
					if (prwin >= 0.129) return true;
					break;
				case 8:
					if (prwin >= 0.113) return true;
					break;
				case 9:
					if (prwin >= 0.101) return true;
					break;
				}
				return false;


			}
			if (Pot <= 15) {
				//min hand As7s 3sQsQh 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.691) return true;
					break;
				case 3:
					if (prwin >= 0.531) return true;
					break;
				case 4:
					if (prwin >= 0.434) return true;
					break;
				case 5:
					if (prwin >= 0.373) return true;
					break;
				case 6:
					if (prwin >= 0.331) return true;
					break;
				case 7:
					if (prwin >= 0.298) return true;
					break;
				case 8:
					if (prwin >= 0.275) return true;
					break;
				case 9:
					if (prwin >= 0.256) return true;
					break;
				}
				return false;




			}
			if (Pot <= 20) {

				if (StackSize <= 50) {
					//min hand AsJh AdTdQc 
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.803) return true;
						break;
					case 3:
						if (prwin >= 0.664) return true;
						break;
					case 4:
						if (prwin >= 0.548) return true;
						break;
					case 5:
						if (prwin >= 0.454) return true;
						break;
					case 6:
						if (prwin >= 0.379) return true;
						break;
					case 7:
						if (prwin >= 0.311) return true;
						break;
					case 8:
						if (prwin >= 0.261) return true;
						break;
					case 9:
						if (prwin >= 0.216) return true;
						break;
					}
					return false;






				}
				//min hand 7c7h Tc2d8d 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.593) return true;
					break;
				case 3:
					if (prwin >= 0.364) return true;
					break;
				case 4:
					if (prwin >= 0.229) return true;
					break;
				case 5:
					if (prwin >= 0.149) return true;
					break;
				case 6:
					if (prwin >= 0.101) return true;
					break;
				case 7:
					if (prwin >= 0.0766) return true;
					break;
				case 8:
					if (prwin >= 0.0558) return true;
					break;
				case 9:
					if (prwin >= 0.0444) return true;
					break;
				}
				return false;






			}
			if (Pot <= 30) {
				//min hand 9h7s 4d7c8s 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.645) return true;
					break;
				case 3:
					if (prwin >= 0.429) return true;
					break;
				case 4:
					if (prwin >= 0.297) return true;
					break;
				case 5:
					if (prwin >= 0.215) return true;
					break;
				case 6:
					if (prwin >= 0.164) return true;
					break;
				case 7:
					if (prwin >= 0.127) return true;
					break;
				case 8:
					if (prwin >= 0.103) return true;
					break;
				case 9:
					if (prwin >= 0.0843) return true;
					break;
				}
				return false;




			}

			if (StackSize < 30) {
				//min hand Ah8c 3s5sAc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.755) return true;
					break;
				case 3:
					if (prwin >= 0.59) return true;
					break;
				case 4:
					if (prwin >= 0.467) return true;
					break;
				case 5:
					if (prwin >= 0.374) return true;
					break;
				case 6:
					if (prwin >= 0.303) return true;
					break;
				case 7:
					if (prwin >= 0.245) return true;
					break;
				case 8:
					if (prwin >= 0.2) return true;
					break;
				case 9:
					if (prwin >= 0.167) return true;
					break;
				}
				return false;



			}
			//min hand 3hAd 9hKsAs 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.8) return true;
				break;
			case 3:
				if (prwin >= 0.649) return true;
				break;
			case 4:
				if (prwin >= 0.529) return true;
				break;
			case 5:
				if (prwin >= 0.432) return true;
				break;
			case 6:
				if (prwin >= 0.354) return true;
				break;
			case 7:
				if (prwin >= 0.289) return true;
				break;
			case 8:
				if (prwin >= 0.24) return true;
				break;
			case 9:
				if (prwin >= 0.197) return true;
				break;
			}
			return false;









		}
		if (BotLastPreflopAction == State::Call) {
			if (Pot <= 20 && prwin > 0.9)return false;//slow
			if (Pot <= 10) {
				//min hand 7cTh JcTdAc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.596) return true;
					break;
				case 3:
					if (prwin >= 0.384) return true;
					break;
				case 4:
					if (prwin >= 0.257) return true;
					break;
				case 5:
					if (prwin >= 0.179) return true;
					break;
				case 6:
					if (prwin >= 0.131) return true;
					break;
				case 7:
					if (prwin >= 0.0979) return true;
					break;
				case 8:
					if (prwin >= 0.0756) return true;
					break;
				case 9:
					if (prwin >= 0.0613) return true;
					break;
				}
				return false;
			}
			if (Pot <= 20) {
				if (StackSize <= 60) {
					//min hand KdAh 5d6sKh 
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.839) return true;
						break;
					case 3:
						if (prwin >= 0.722) return true;
						break;
					case 4:
						if (prwin >= 0.616) return true;
						break;
					case 5:
						if (prwin >= 0.535) return true;
						break;
					case 6:
						if (prwin >= 0.462) return true;
						break;
					case 7:
						if (prwin >= 0.404) return true;
						break;
					case 8:
						if (prwin >= 0.351) return true;
						break;
					case 9:
						if (prwin >= 0.306) return true;
						break;
					}
					return false;



				}


			}
			if (Pot <= 60) {
				//min hand QhQs 9cTcQc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.744) return true;
					break;
				case 3:
					if (prwin >= 0.63) return true;
					break;
				case 4:
					if (prwin >= 0.553) return true;
					break;
				case 5:
					if (prwin >= 0.498) return true;
					break;
				case 6:
					if (prwin >= 0.464) return true;
					break;
				case 7:
					if (prwin >= 0.431) return true;
					break;
				case 8:
					if (prwin >= 0.411) return true;
					break;
				case 9:
					if (prwin >= 0.394) return true;
					break;
				}
				return false;



			}

			//min hand JcQh JhQc3h 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.895) return true;
				break;
			case 3:
				if (prwin >= 0.815) return true;
				break;
			case 4:
				if (prwin >= 0.746) return true;
				break;
			case 5:
				if (prwin >= 0.685) return true;
				break;
			case 6:
				if (prwin >= 0.633) return true;
				break;
			case 7:
				if (prwin >= 0.588) return true;
				break;
			case 8:
				if (prwin >= 0.548) return true;
				break;
			case 9:
				if (prwin >= 0.511) return true;
				break;
			}
			return false;




			

		}
		if (BotLastPreflopAction == State::Check) {

			if (Pot <= 10) {
				//min hand 7c7h Tc2d8d 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.593) return true;
					break;
				case 3:
					if (prwin >= 0.364) return true;
					break;
				case 4:
					if (prwin >= 0.229) return true;
					break;
				case 5:
					if (prwin >= 0.149) return true;
					break;
				case 6:
					if (prwin >= 0.101) return true;
					break;
				case 7:
					if (prwin >= 0.0766) return true;
					break;
				case 8:
					if (prwin >= 0.0558) return true;
					break;
				case 9:
					if (prwin >= 0.0444) return true;
					break;
				}
				return false;
			}
		}

		//min hand KhQd 6hKd3c 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.841) return true;
			break;
		case 3:
			if (prwin >= 0.718) return true;
			break;
		case 4:
			if (prwin >= 0.613) return true;
			break;
		case 5:
			if (prwin >= 0.527) return true;
			break;
		case 6:
			if (prwin >= 0.454) return true;
			break;
		case 7:
			if (prwin >= 0.393) return true;
			break;
		case 8:
			if (prwin >= 0.342) return true;
			break;
		case 9:
			if (prwin >= 0.297) return true;
			break;
		}
		return false;



	}
	if (BotLastFlopAction == State::Raise) {
		if (BotLastPreflopAction == State::Call) {
			if (Pot <= 35) {
				//min hand TsTd 6c3s9c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.743) return true;
					break;
				case 3:
					if (prwin >= 0.562) return true;
					break;
				case 4:
					if (prwin >= 0.432) return true;
					break;
				case 5:
					if (prwin >= 0.335) return true;
					break;
				case 6:
					if (prwin >= 0.261) return true;
					break;
				case 7:
					if (prwin >= 0.204) return true;
					break;
				case 8:
					if (prwin >= 0.161) return true;
					break;
				case 9:
					if (prwin >= 0.127) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {
				//min hand QdQc 7d4cTh 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.794) return true;
					break;
				case 3:
					if (prwin >= 0.64) return true;
					break;
				case 4:
					if (prwin >= 0.521) return true;
					break;
				case 5:
					if (prwin >= 0.429) return true;
					break;
				case 6:
					if (prwin >= 0.35) return true;
					break;
				case 7:
					if (prwin >= 0.29) return true;
					break;
				case 8:
					if (prwin >= 0.242) return true;
					break;
				case 9:
					if (prwin >= 0.197) return true;
					break;
				}
				return false;
			}
		
			//min hand AdAc 6dKc6h 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.875) return true;
				break;
			case 3:
				if (prwin >= 0.774) return true;
				break;
			case 4:
				if (prwin >= 0.684) return true;
				break;
			case 5:
				if (prwin >= 0.601) return true;
				break;
			case 6:
				if (prwin >= 0.527) return true;
				break;
			case 7:
				if (prwin >= 0.461) return true;
				break;
			case 8:
				if (prwin >= 0.405) return true;
				break;
			case 9:
				if (prwin >= 0.352) return true;
				break;
			}
			return false;






		}
		if (BotLastPreflopAction == State::Raise) {
			if (StackSize <= 50) {
				//min hand 5c9s Qc9d9c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.89) return true;
					break;
				case 3:
					if (prwin >= 0.806) return true;
					break;
				case 4:
					if (prwin >= 0.728) return true;
					break;
				case 5:
					if (prwin >= 0.661) return true;
					break;
				case 6:
					if (prwin >= 0.602) return true;
					break;
				case 7:
					if (prwin >= 0.553) return true;
					break;
				case 8:
					if (prwin >= 0.504) return true;
					break;
				case 9:
					if (prwin >= 0.462) return true;
					break;
				}
				return false;







			}
		
			if (Pot <= 35) {
				//min hand KhQd 2s4sKc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.814) return true;
					break;
				case 3:
					if (prwin >= 0.679) return true;
					break;
				case 4:
					if (prwin >= 0.571) return true;
					break;
				case 5:
					if (prwin >= 0.481) return true;
					break;
				case 6:
					if (prwin >= 0.406) return true;
					break;
				case 7:
					if (prwin >= 0.35) return true;
					break;
				case 8:
					if (prwin >= 0.298) return true;
					break;
				case 9:
					if (prwin >= 0.253) return true;
					break;
				}
				return false;



			}
			if (Pot <= 60) {
				//min hand TcTd TsQdJd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.817) return true;
					break;
				case 3:
					if (prwin >= 0.719) return true;
					break;
				case 4:
					if (prwin >= 0.638) return true;
					break;
				case 5:
					if (prwin >= 0.579) return true;
					break;
				case 6:
					if (prwin >= 0.527) return true;
					break;
				case 7:
					if (prwin >= 0.493) return true;
					break;
				case 8:
					if (prwin >= 0.461) return true;
					break;
				case 9:
					if (prwin >= 0.434) return true;
					break;
				}
				return false;




			}
			//min hand AdAc 4hKhKd 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.854) return true;
				break;
			case 3:
				if (prwin >= 0.741) return true;
				break;
			case 4:
				if (prwin >= 0.645) return true;
				break;
			case 5:
				if (prwin >= 0.56) return true;
				break;
			case 6:
				if (prwin >= 0.488) return true;
				break;
			case 7:
				if (prwin >= 0.426) return true;
				break;
			case 8:
				if (prwin >= 0.373) return true;
				break;
			case 9:
				if (prwin >= 0.328) return true;
				break;
			}
			return false;












		}
		if (BotLastPreflopAction == State::Check) {
			if (Pot <= 2) {
				//min hand 4c7c Qd6c3c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.532) return true;
					break;
				case 3:
					if (prwin >= 0.461) return true;
					break;
				case 4:
					if (prwin >= 0.416) return true;
					break;
				case 5:
					if (prwin >= 0.389) return true;
					break;
				case 6:
					if (prwin >= 0.363) return true;
					break;
				case 7:
					if (prwin >= 0.344) return true;
					break;
				case 8:
					if (prwin >= 0.327) return true;
					break;
				case 9:
					if (prwin >= 0.314) return true;
					break;
				}
				return false;

			}
			//min hand 9c8d 9s8s2d 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.845) return true;
				break;
			case 3:
				if (prwin >= 0.734) return true;
				break;
			case 4:
				if (prwin >= 0.648) return true;
				break;
			case 5:
				if (prwin >= 0.576) return true;
				break;
			case 6:
				if (prwin >= 0.518) return true;
				break;
			case 7:
				if (prwin >= 0.47) return true;
				break;
			case 8:
				if (prwin >= 0.43) return true;
				break;
			case 9:
				if (prwin >= 0.397) return true;
				break;
			}
			return false;
		}

		if (Pot <= 20) {
			//min hand 9s5d 6h5s8c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.588) return true;
				break;
			case 3:
				if (prwin >= 0.38) return true;
				break;
			case 4:
				if (prwin >= 0.261) return true;
				break;
			case 5:
				if (prwin >= 0.191) return true;
				break;
			case 6:
				if (prwin >= 0.145) return true;
				break;
			case 7:
				if (prwin >= 0.114) return true;
				break;
			case 8:
				if (prwin >= 0.0914) return true;
				break;
			case 9:
				if (prwin >= 0.0719) return true;
				break;
			}
			return false;




		}
		if (Pot <= 30) {
			//min hand QhAs Ad3d5d 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.643) return true;
				break;
			case 3:
				if (prwin >= 0.462) return true;
				break;
			case 4:
				if (prwin >= 0.344) return true;
				break;
			case 5:
				if (prwin >= 0.262) return true;
				break;
			case 6:
				if (prwin >= 0.203) return true;
				break;
			case 7:
				if (prwin >= 0.166) return true;
				break;
			case 8:
				if (prwin >= 0.13) return true;
				break;
			case 9:
				if (prwin >= 0.107) return true;
				break;
			}
			return false;




		}
		//min hand ThTs 2d7h4c 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.767) return true;
			break;
		case 3:
			if (prwin >= 0.601) return true;
			break;
		case 4:
			if (prwin >= 0.476) return true;
			break;
		case 5:
			if (prwin >= 0.377) return true;
			break;
		case 6:
			if (prwin >= 0.303) return true;
			break;
		case 7:
			if (prwin >= 0.244) return true;
			break;
		case 8:
			if (prwin >= 0.199) return true;
			break;
		case 9:
			if (prwin >= 0.161) return true;
			break;
		}
		return false;





	}
	if (BotLastFlopAction == State::Check) {
		if (BotLastPreflopAction == State::Raise) {

			//min hand 6cJs 3s6d5d 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.596) return true;
				break;
			case 3:
				if (prwin >= 0.382) return true;
				break;
			case 4:
				if (prwin >= 0.263) return true;
				break;
			case 5:
				if (prwin >= 0.186) return true;
				break;
			case 6:
				if (prwin >= 0.14) return true;
				break;
			case 7:
				if (prwin >= 0.109) return true;
				break;
			case 8:
				if (prwin >= 0.0892) return true;
				break;
			case 9:
				if (prwin >= 0.0751) return true;
				break;
			}
			return false;



		}

	}
	if (BotLastFlopAction == State::Call) {



	
	
	}


	//min hand TsQh AcJcKs 
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.892) return true;
		break;
	case 3:
		if (prwin >= 0.819) return true;
		break;
	case 4:
		if (prwin >= 0.752) return true;
		break;
	case 5:
		if (prwin >= 0.703) return true;
		break;
	case 6:
		if (prwin >= 0.655) return true;
		break;
	case 7:
		if (prwin >= 0.611) return true;
		break;
	case 8:
		if (prwin >= 0.576) return true;
		break;
	case 9:
		if (prwin >= 0.538) return true;
		break;
	}
	return false;

}
bool Player::flop_Call() {
	if (Pot <= 3) {//min hand 5dQh 6d4h8d 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.397) return true;
			break;
		case 3:
			if (prwin >= 0.23) return true;
			break;
		case 4:
			if (prwin >= 0.159) return true;
			break;
		case 5:
			if (prwin >= 0.117) return true;
			break;
		case 6:
			if (prwin >= 0.0893) return true;
			break;
		case 7:
			if (prwin >= 0.0656) return true;
			break;
		case 8:
			if (prwin >= 0.0492) return true;
			break;
		case 9:
			if (prwin >= 0.0365) return true;
			break;
		}
		return false;

	}	

	if (BotLastFlopAction == State::None) {

		if (BotLastPreflopAction == State::Raise) {
			if (Pot <= 10) {
				//min hand QdAh 5cJd6s 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.496) return true;
					break;
				case 3:
					if (prwin >= 0.294) return true;
					break;
				case 4:
					if (prwin >= 0.203) return true;
					break;
				case 5:
					if (prwin >= 0.153) return true;
					break;
				case 6:
					if (prwin >= 0.122) return true;
					break;
				case 7:
					if (prwin >= 0.103) return true;
					break;
				case 8:
					if (prwin >= 0.087) return true;
					break;
				case 9:
					if (prwin >= 0.0742) return true;
					break;
				}
				return false;




			}
			if (Pot <= 15) {
				//min hand 3s8d 3dQd6c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.55) return true;
					break;
				case 3:
					if (prwin >= 0.338) return true;
					break;
				case 4:
					if (prwin >= 0.232) return true;
					break;
				case 5:
					if (prwin >= 0.173) return true;
					break;
				case 6:
					if (prwin >= 0.141) return true;
					break;
				case 7:
					if (prwin >= 0.119) return true;
					break;
				case 8:
					if (prwin >= 0.102) return true;
					break;
				case 9:
					if (prwin >= 0.0894) return true;
					break;
				}
				return false;



			}
			if (Pot <= 20) {
				//min hand 3s6c 7s3h2d 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.601) return true;
					break;
				case 3:
					if (prwin >= 0.38) return true;
					break;
				case 4:
					if (prwin >= 0.257) return true;
					break;
				case 5:
					if (prwin >= 0.184) return true;
					break;
				case 6:
					if (prwin >= 0.145) return true;
					break;
				case 7:
					if (prwin >= 0.115) return true;
					break;
				case 8:
					if (prwin >= 0.0969) return true;
					break;
				case 9:
					if (prwin >= 0.0844) return true;
					break;
				}
				return false;
			}
			if (Pot <= 30) {
				//min hand QsQd 9s3h9h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.808) return true;
					break;
				case 3:
					if (prwin >= 0.665) return true;
					break;
				case 4:
					if (prwin >= 0.55) return true;
					break;
				case 5:
					if (prwin >= 0.457) return true;
					break;
				case 6:
					if (prwin >= 0.383) return true;
					break;
				case 7:
					if (prwin >= 0.329) return true;
					break;
				case 8:
					if (prwin >= 0.274) return true;
					break;
				case 9:
					if (prwin >= 0.236) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {

				//min hand ThQc 5d2dTs 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.769) return true;
					break;
				case 3:
					if (prwin >= 0.603) return true;
					break;
				case 4:
					if (prwin >= 0.482) return true;
					break;
				case 5:
					if (prwin >= 0.386) return true;
					break;
				case 6:
					if (prwin >= 0.317) return true;
					break;
				case 7:
					if (prwin >= 0.261) return true;
					break;
				case 8:
					if (prwin >= 0.212) return true;
					break;
				case 9:
					if (prwin >= 0.181) return true;
					break;
				}
				return false;



			}

			//min hand Qh9h 8h4h9c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.845) return true;
				break;
			case 3:
				if (prwin >= 0.733) return true;
				break;
			case 4:
				if (prwin >= 0.647) return true;
				break;
			case 5:
				if (prwin >= 0.58) return true;
				break;
			case 6:
				if (prwin >= 0.527) return true;
				break;
			case 7:
				if (prwin >= 0.484) return true;
				break;
			case 8:
				if (prwin >= 0.447) return true;
				break;
			case 9:
				if (prwin >= 0.419) return true;
				break;
			}

			return false;


		}
		if (BotLastPreflopAction == State::Call) {
			if (StackSize <= 15 && StackSize >= 10) {
				//min hand 3sAh 7sAdKc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.823) return true;
					break;
				case 3:
					if (prwin >= 0.684) return true;
					break;
				case 4:
					if (prwin >= 0.567) return true;
					break;
				case 5:
					if (prwin >= 0.471) return true;
					break;
				case 6:
					if (prwin >= 0.393) return true;
					break;
				case 7:
					if (prwin >= 0.324) return true;
					break;
				case 8:
					if (prwin >= 0.269) return true;
					break;
				case 9:
					if (prwin >= 0.223) return true;
					break;
				}
				return false;




			}
			if (StackSize <= 25) {
				//min hand JhQd Qh8d9c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.794) return true;
					break;
				case 3:
					if (prwin >= 0.642) return true;
					break;
				case 4:
					if (prwin >= 0.521) return true;
					break;
				case 5:
					if (prwin >= 0.427) return true;
					break;
				case 6:
					if (prwin >= 0.346) return true;
					break;
				case 7:
					if (prwin >= 0.281) return true;
					break;
				case 8:
					if (prwin >= 0.227) return true;
					break;
				case 9:
					if (prwin >= 0.187) return true;
					break;
				}
				return false;



			}

			if (Pot <= 7) {
				//min hand 4dAc 3dKc8h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.447) return true;
					break;
				case 3:
					if (prwin >= 0.231) return true;
					break;
				case 4:
					if (prwin >= 0.14) return true;
					break;
				case 5:
					if (prwin >= 0.0934) return true;
					break;
				case 6:
					if (prwin >= 0.0694) return true;
					break;
				case 7:
					if (prwin >= 0.0518) return true;
					break;
				case 8:
					if (prwin >= 0.0412) return true;
					break;
				case 9:
					if (prwin >= 0.0342) return true;
					break;
				}
				return false;



			}
			if (Pot <= 10) {
				//min hand 5dKc 5h7h3h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.49) return true;
					break;
				case 3:
					if (prwin >= 0.284) return true;
					break;
				case 4:
					if (prwin >= 0.177) return true;
					break;
				case 5:
					if (prwin >= 0.12) return true;
					break;
				case 6:
					if (prwin >= 0.0886) return true;
					break;
				case 7:
					if (prwin >= 0.069) return true;
					break;
				case 8:
					if (prwin >= 0.0553) return true;
					break;
				case 9:
					if (prwin >= 0.046) return true;
					break;
				}
				return false;




			}
			if (Pot <= 13) {
				//min hand ThQs 8s9c9s 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.514) return true;
					break;
				case 3:
					if (prwin >= 0.34) return true;
					break;
				case 4:
					if (prwin >= 0.255) return true;
					break;
				case 5:
					if (prwin >= 0.209) return true;
					break;
				case 6:
					if (prwin >= 0.173) return true;
					break;
				case 7:
					if (prwin >= 0.148) return true;
					break;
				case 8:
					if (prwin >= 0.128) return true;
					break;
				case 9:
					if (prwin >= 0.111) return true;
					break;
				}
				return false;



			}
			if (Pot <= 15) {
				//min hand QcKd TsAc3h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.57) return true;
					break;
				case 3:
					if (prwin >= 0.38) return true;
					break;
				case 4:
					if (prwin >= 0.286) return true;
					break;
				case 5:
					if (prwin >= 0.229) return true;
					break;
				case 6:
					if (prwin >= 0.196) return true;
					break;
				case 7:
					if (prwin >= 0.172) return true;
					break;
				case 8:
					if (prwin >= 0.154) return true;
					break;
				case 9:
					if (prwin >= 0.141) return true;
					break;
				}
				return false;






			}
			if (Pot <= 20) {
				//min hand 3d6c 5hKs6h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.592) return true;
					break;
				case 3:
					if (prwin >= 0.375) return true;
					break;
				case 4:
					if (prwin >= 0.247) return true;
					break;
				case 5:
					if (prwin >= 0.172) return true;
					break;
				case 6:
					if (prwin >= 0.127) return true;
					break;
				case 7:
					if (prwin >= 0.0987) return true;
					break;
				case 8:
					if (prwin >= 0.0784) return true;
					break;
				case 9:
					if (prwin >= 0.0628) return true;
					break;
				}
				return false;






			}
			if (Pot <= 30) {
				//min hand Js8h 9dJcTs 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.698) return true;
					break;
				case 3:
					if (prwin >= 0.517) return true;
					break;
				case 4:
					if (prwin >= 0.385) return true;
					break;
				case 5:
					if (prwin >= 0.288) return true;
					break;
				case 6:
					if (prwin >= 0.22) return true;
					break;
				case 7:
					if (prwin >= 0.168) return true;
					break;
				case 8:
					if (prwin >= 0.131) return true;
					break;
				case 9:
					if (prwin >= 0.0986) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {
				//min hand Ah4h Ac2cKs 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.796) return true;
					break;
				case 3:
					if (prwin >= 0.646) return true;
					break;
				case 4:
					if (prwin >= 0.522) return true;
					break;
				case 5:
					if (prwin >= 0.424) return true;
					break;
				case 6:
					if (prwin >= 0.345) return true;
					break;
				case 7:
					if (prwin >= 0.282) return true;
					break;
				case 8:
					if (prwin >= 0.23) return true;
					break;
				case 9:
					if (prwin >= 0.187) return true;
					break;
				}
				return false;



			}
			//min hand 6s3h 7s4d5h 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.869) return true;
				break;
			case 3:
				if (prwin >= 0.783) return true;
				break;
			case 4:
				if (prwin >= 0.711) return true;
				break;
			case 5:
				if (prwin >= 0.643) return true;
				break;
			case 6:
				if (prwin >= 0.591) return true;
				break;
			case 7:
				if (prwin >= 0.547) return true;
				break;
			case 8:
				if (prwin >= 0.506) return true;
				break;
			case 9:
				if (prwin >= 0.468) return true;
				break;
			}
			return false;



		}
		if (BotLastPreflopAction == State::Check) {
			if (Pot <= 5) {
				//min hand Kh7h TdTsAh 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.504) return true;
					break;
				case 3:
					if (prwin >= 0.284) return true;
					break;
				case 4:
					if (prwin >= 0.17) return true;
					break;
				case 5:
					if (prwin >= 0.104) return true;
					break;
				case 6:
					if (prwin >= 0.0722) return true;
					break;
				case 7:
					if (prwin >= 0.0502) return true;
					break;
				case 8:
					if (prwin >= 0.0377) return true;
					break;
				case 9:
					if (prwin >= 0.0283) return true;
					break;
				}
				return false;



			}
			if (Pot <= 10) {
				//min hand ThQd Jd2sKd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.593) return true;
					break;
				case 3:
					if (prwin >= 0.439) return true;
					break;
				case 4:
					if (prwin >= 0.363) return true;
					break;
				case 5:
					if (prwin >= 0.318) return true;
					break;
				case 6:
					if (prwin >= 0.292) return true;
					break;
				case 7:
					if (prwin >= 0.27) return true;
					break;
				case 8:
					if (prwin >= 0.25) return true;
					break;
				case 9:
					if (prwin >= 0.235) return true;
					break;
				}
				return false;




			}
			//min hand Qh9h 8h4h9c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.845) return true;
				break;
			case 3:
				if (prwin >= 0.733) return true;
				break;
			case 4:
				if (prwin >= 0.647) return true;
				break;
			case 5:
				if (prwin >= 0.58) return true;
				break;
			case 6:
				if (prwin >= 0.527) return true;
				break;
			case 7:
				if (prwin >= 0.484) return true;
				break;
			case 8:
				if (prwin >= 0.447) return true;
				break;
			case 9:
				if (prwin >= 0.419) return true;
				break;
			}
			return false;
		}

	}
	if (BotLastFlopAction == State::Raise) {
		if (BotLastPreflopAction == State::Raise) {
			if (Pot <= 10){//min hand 8s8d 9hJc7c 
				//min hand 7sJc 9cJdKd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.65) return true;
					break;
				case 3:
					if (prwin >= 0.443) return true;
					break;
				case 4:
					if (prwin >= 0.315) return true;
					break;
				case 5:
					if (prwin >= 0.227) return true;
					break;
				case 6:
					if (prwin >= 0.168) return true;
					break;
				case 7:
					if (prwin >= 0.128) return true;
					break;
				case 8:
					if (prwin >= 0.0987) return true;
					break;
				case 9:
					if (prwin >= 0.0784) return true;
					break;
				}
				return false;



			}
			if (Pot <= 20){
				//min hand 9c8d 4d8cKd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.699) return true;
					break;
				case 3:
					if (prwin >= 0.499) return true;
					break;
				case 4:
					if (prwin >= 0.369) return true;
					break;
				case 5:
					if (prwin >= 0.277) return true;
					break;
				case 6:
					if (prwin >= 0.216) return true;
					break;
				case 7:
					if (prwin >= 0.172) return true;
					break;
				case 8:
					if (prwin >= 0.142) return true;
					break;
				case 9:
					if (prwin >= 0.119) return true;
					break;
				}
				return false;



		}			
			if (Pot <= 30) {
				//min hand 6dJd AdKdJs 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.757) return true;
					break;
				case 3:
					if (prwin >= 0.617) return true;
					break;
				case 4:
					if (prwin >= 0.531) return true;
					break;
				case 5:
					if (prwin >= 0.468) return true;
					break;
				case 6:
					if (prwin >= 0.433) return true;
					break;
				case 7:
					if (prwin >= 0.402) return true;
					break;
				case 8:
					if (prwin >= 0.382) return true;
					break;
				case 9:
					if (prwin >= 0.366) return true;
					break;
				}
				return false;



			}
			if (Pot <= 35) {
				//min hand ThKs QhAhKd 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.77) return true;
					break;
				case 3:
					if (prwin >= 0.604) return true;
					break;
				case 4:
					if (prwin >= 0.478) return true;
					break;
				case 5:
					if (prwin >= 0.375) return true;
					break;
				case 6:
					if (prwin >= 0.295) return true;
					break;
				case 7:
					if (prwin >= 0.233) return true;
					break;
				case 8:
					if (prwin >= 0.184) return true;
					break;
				case 9:
					if (prwin >= 0.148) return true;
					break;
				}
				return false;




			}
			if (Pot <= 40){
				//min hand TcAs 9d5cTs 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.789) return true;
					break;
				case 3:
					if (prwin >= 0.639) return true;
					break;
				case 4:
					if (prwin >= 0.525) return true;
					break;
				case 5:
					if (prwin >= 0.436) return true;
					break;
				case 6:
					if (prwin >= 0.367) return true;
					break;
				case 7:
					if (prwin >= 0.31) return true;
					break;
				case 8:
					if (prwin >= 0.265) return true;
					break;
				case 9:
					if (prwin >= 0.23) return true;
					break;
				}
				return false;



		}
			//min hand AdKh ThAh7s 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.855) return true;
				break;
			case 3:
				if (prwin >= 0.740) return true;
				break;
			case 4:
				if (prwin >= 0.646) return true;
				break;
			case 5:
				if (prwin >= 0.562) return true;
				break;
			case 6:
				if (prwin >= 0.494) return true;
				break;
			case 7:
				if (prwin >= 0.436) return true;
				break;
			case 8:
				if (prwin >= 0.381) return true;
				break;
			case 9:
				if (prwin >= 0.335) return true;
				break;
			}
			return false;




		}
		if (BotLastPreflopAction == State::Call) {
			if (Pot <= 20){
				//min hand 7h4c 9s7s9c 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.601) return true;
					break;
				case 3:
					if (prwin >= 0.387) return true;
					break;
				case 4:
					if (prwin >= 0.252) return true;
					break;
				case 5:
					if (prwin >= 0.169) return true;
					break;
				case 6:
					if (prwin >= 0.114) return true;
					break;
				case 7:
					if (prwin >= 0.0773) return true;
					break;
				case 8:
					if (prwin >= 0.0512) return true;
					break;
				case 9:
					if (prwin >= 0.0344) return true;
					break;
				}
				return false;


			
			}
			if (Pot <= 30) {
				//min hand Ks9c Jc9dQc 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.68) return true;
					break;
				case 3:
					if (prwin >= 0.49) return true;
					break;
				case 4:
					if (prwin >= 0.359) return true;
					break;
				case 5:
					if (prwin >= 0.268) return true;
					break;
				case 6:
					if (prwin >= 0.206) return true;
					break;
				case 7:
					if (prwin >= 0.157) return true;
					break;
				case 8:
					if (prwin >= 0.123) return true;
					break;
				case 9:
					if (prwin >= 0.0973) return true;
					break;
				}
				return false;





			}
			if (Pot <= 40) {
				//min hand KdJc 8s3hJh 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.792) return true;
					break;
				case 3:
					if (prwin >= 0.645) return true;
					break;
				case 4:
					if (prwin >= 0.526) return true;
					break;
				case 5:
					if (prwin >= 0.438) return true;
					break;
				case 6:
					if (prwin >= 0.365) return true;
					break;
				case 7:
					if (prwin >= 0.308) return true;
					break;
				case 8:
					if (prwin >= 0.261) return true;
					break;
				case 9:
					if (prwin >= 0.222) return true;
					break;
				}
				return false;



			}
			//min hand Ts3h 6s3cTc 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.842) return true;
				break;
			case 3:
				if (prwin >= 0.728) return true;
				break;
			case 4:
				if (prwin >= 0.635) return true;
				break;
			case 5:
				if (prwin >= 0.559) return true;
				break;
			case 6:
				if (prwin >= 0.495) return true;
				break;
			case 7:
				if (prwin >= 0.446) return true;
				break;
			case 8:
				if (prwin >= 0.404) return true;
				break;
			case 9:
				if (prwin >= 0.37) return true;
				break;
			}
			return false;






		}
		if (Pot <= 10) {
			//min hand 7d2d Qh2c9h 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.495) return true;
				break;
			case 3:
				if (prwin >= 0.279) return true;
				break;
			case 4:
				if (prwin >= 0.179) return true;
				break;
			case 5:
				if (prwin >= 0.127) return true;
				break;
			case 6:
				if (prwin >= 0.0998) return true;
				break;
			case 7:
				if (prwin >= 0.0838) return true;
				break;
			case 8:
				if (prwin >= 0.0728) return true;
				break;
			case 9:
				if (prwin >= 0.061) return true;
				break;
			}
			return false;




		}
		if (Pot <= 20) {
			//min hand 8c5d 5hTsAh 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.548) return true;
				break;
			case 3:
				if (prwin >= 0.327) return true;
				break;
			case 4:
				if (prwin >= 0.214) return true;
				break;
			case 5:
				if (prwin >= 0.152) return true;
				break;
			case 6:
				if (prwin >= 0.116) return true;
				break;
			case 7:
				if (prwin >= 0.0941) return true;
				break;
			case 8:
				if (prwin >= 0.0799) return true;
				break;
			case 9:
				if (prwin >= 0.0689) return true;
				break;
			}
			return false;




		}
		if (Pot <= 30) {
			//min hand Jh9d 6sJc4c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.746) return true;
				break;
			case 3:
				if (prwin >= 0.572) return true;
				break;
			case 4:
				if (prwin >= 0.451) return true;
				break;
			case 5:
				if (prwin >= 0.35) return true;
				break;
			case 6:
				if (prwin >= 0.286) return true;
				break;
			case 7:
				if (prwin >= 0.23) return true;
				break;
			case 8:
				if (prwin >= 0.19) return true;
				break;
			case 9:
				if (prwin >= 0.156) return true;
				break;
			}
			return false;





		}
		if (Pot <= 50) { //min hand AcTd 5h2dAd 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.797) return true;
				break;
			case 3:
				if (prwin >= 0.654) return true;
				break;
			case 4:
				if (prwin >= 0.536) return true;
				break;
			case 5:
				if (prwin >= 0.448) return true;
				break;
			case 6:
				if (prwin >= 0.374) return true;
				break;
			case 7:
				if (prwin >= 0.313) return true;
				break;
			case 8:
				if (prwin >= 0.262) return true;
				break;
			case 9:
				if (prwin >= 0.224) return true;
				break;
			}
			return false;

		}
		//min hand Qh9h 8h4h9c 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.845) return true;
			break;
		case 3:
			if (prwin >= 0.733) return true;
			break;
		case 4:
			if (prwin >= 0.647) return true;
			break;
		case 5:
			if (prwin >= 0.58) return true;
			break;
		case 6:
			if (prwin >= 0.527) return true;
			break;
		case 7:
			if (prwin >= 0.484) return true;
			break;
		case 8:
			if (prwin >= 0.447) return true;
			break;
		case 9:
			if (prwin >= 0.419) return true;
			break;
		}
		return false;
	}
	if (BotLastFlopAction == State::Check) {
		if (StackSize <= 20) {
			//min hand Kd2h QsKh3c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.798) return true;
				break;
			case 3:
				if (prwin >= 0.643) return true;
				break;
			case 4:
				if (prwin >= 0.525) return true;
				break;
			case 5:
				if (prwin >= 0.426) return true;
				break;
			case 6:
				if (prwin >= 0.346) return true;
				break;
			case 7:
				if (prwin >= 0.287) return true;
				break;
			case 8:
				if (prwin >= 0.234) return true;
				break;
			case 9:
				if (prwin >= 0.192) return true;
				break;
			}
			return false;




		}
		if (BotLastPreflopAction == State::Call) {
			if (Pot <= 15) {
				//min hand 7h5s JdKs7s 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.581) return true;
					break;
				case 3:
					if (prwin >= 0.365) return true;
					break;
				case 4:
					if (prwin >= 0.251) return true;
					break;
				case 5:
					if (prwin >= 0.184) return true;
					break;
				case 6:
					if (prwin >= 0.137) return true;
					break;
				case 7:
					if (prwin >= 0.111) return true;
					break;
				case 8:
					if (prwin >= 0.0922) return true;
					break;
				case 9:
					if (prwin >= 0.0767) return true;
					break;
				}
				return false;



			}
			if (Pot <= 30) {
				//min hand 8cJd 4c8h9d 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.7) return true;
					break;
				case 3:
					if (prwin >= 0.508) return true;
					break;
				case 4:
					if (prwin >= 0.375) return true;
					break;
				case 5:
					if (prwin >= 0.284) return true;
					break;
				case 6:
					if (prwin >= 0.22) return true;
					break;
				case 7:
					if (prwin >= 0.177) return true;
					break;
				case 8:
					if (prwin >= 0.143) return true;
					break;
				case 9:
					if (prwin >= 0.122) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {
				//min hand Jh3d 4sJd4h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.74) return true;
					break;
				case 3:
					if (prwin >= 0.56) return true;
					break;
				case 4:
					if (prwin >= 0.419) return true;
					break;
				case 5:
					if (prwin >= 0.317) return true;
					break;
				case 6:
					if (prwin >= 0.241) return true;
					break;
				case 7:
					if (prwin >= 0.183) return true;
					break;
				case 8:
					if (prwin >= 0.142) return true;
					break;
				case 9:
					if (prwin >= 0.107) return true;
					break;
				}
				return false;



			}
		}
		if (BotLastPreflopAction == State::Raise) {
			if (Pot <= 15) {
				//min hand 3c8h Ac3s5h 
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.501) return true;
					break;
				case 3:
					if (prwin >= 0.285) return true;
					break;
				case 4:
					if (prwin >= 0.19) return true;
					break;
				case 5:
					if (prwin >= 0.137) return true;
					break;
				case 6:
					if (prwin >= 0.11) return true;
					break;
				case 7:
					if (prwin >= 0.089) return true;
					break;
				case 8:
					if (prwin >= 0.0783) return true;
					break;
				case 9:
					if (prwin >= 0.0681) return true;
					break;
				}
				return false;



			}
			if (Pot <= 20) {
				if (StackSize < 40) {
					//min hand QcTc 8cJsQd 
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.804) return true;
						break;
					case 3:
						if (prwin >= 0.661) return true;
						break;
					case 4:
						if (prwin >= 0.549) return true;
						break;
					case 5:
						if (prwin >= 0.455) return true;
						break;
					case 6:
						if (prwin >= 0.379) return true;
						break;
					case 7:
						if (prwin >= 0.313) return true;
						break;
					case 8:
						if (prwin >= 0.263) return true;
						break;
					case 9:
						if (prwin >= 0.222) return true;
						break;
					}
					return false;




				}


			}
		}
		if (Pot <= 10) {//min hand 2c7c 8dTs2s 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.501) return true;
				break;
			case 3:
				if (prwin >= 0.284) return true;
				break;
			case 4:
				if (prwin >= 0.181) return true;
				break;
			case 5:
				if (prwin >= 0.131) return true;
				break;
			case 6:
				if (prwin >= 0.102) return true;
				break;
			case 7:
				if (prwin >= 0.0819) return true;
				break;
			case 8:
				if (prwin >= 0.068) return true;
				break;
			case 9:
				if (prwin >= 0.0579) return true;
				break;
			}
			return false;

		}
		if (Pot <= 15) {
			//min hand AdKh 7s6s7c 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.542) return true;
				break;
			case 3:
				if (prwin >= 0.325) return true;
				break;
			case 4:
				if (prwin >= 0.209) return true;
				break;
			case 5:
				if (prwin >= 0.143) return true;
				break;
			case 6:
				if (prwin >= 0.105) return true;
				break;
			case 7:
				if (prwin >= 0.0804) return true;
				break;
			case 8:
				if (prwin >= 0.0592) return true;
				break;
			case 9:
				if (prwin >= 0.045) return true;
				break;
			}
			return false;



		}
		if (Pot <= 30) {
			//min hand Qs3c Jc9h3s 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.581) return true;
				break;
			case 3:
				if (prwin >= 0.367) return true;
				break;
			case 4:
				if (prwin >= 0.253) return true;
				break;
			case 5:
				if (prwin >= 0.19) return true;
				break;
			case 6:
				if (prwin >= 0.15) return true;
				break;
			case 7:
				if (prwin >= 0.124) return true;
				break;
			case 8:
				if (prwin >= 0.109) return true;
				break;
			case 9:
				if (prwin >= 0.0977) return true;
				break;
			}
			return false;




		}
		if (Pot <= 40) {
			//min hand JdJc 7h7dKc 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.733) return true;
				break;
			case 3:
				if (prwin >= 0.55) return true;
				break;
			case 4:
				if (prwin >= 0.412) return true;
				break;
			case 5:
				if (prwin >= 0.311) return true;
				break;
			case 6:
				if (prwin >= 0.239) return true;
				break;
			case 7:
				if (prwin >= 0.186) return true;
				break;
			case 8:
				if (prwin >= 0.149) return true;
				break;
			case 9:
				if (prwin >= 0.123) return true;
				break;
			}
			return false;



		}
		if (Pot <= 60) {
			//min hand Qc8s 6s8hKs 
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.694) return true;
				break;
			case 3:
				if (prwin >= 0.5) return true;
				break;
			case 4:
				if (prwin >= 0.371) return true;
				break;
			case 5:
				if (prwin >= 0.282) return true;
				break;
			case 6:
				if (prwin >= 0.22) return true;
				break;
			case 7:
				if (prwin >= 0.176) return true;
				break;
			case 8:
				if (prwin >= 0.146) return true;
				break;
			case 9:
				if (prwin >= 0.124) return true;
				break;
			}
			return false;





		}
		//min hand Qh9h 8h4h9c 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.845) return true;
			break;
		case 3:
			if (prwin >= 0.733) return true;
			break;
		case 4:
			if (prwin >= 0.647) return true;
			break;
		case 5:
			if (prwin >= 0.58) return true;
			break;
		case 6:
			if (prwin >= 0.527) return true;
			break;
		case 7:
			if (prwin >= 0.484) return true;
			break;
		case 8:
			if (prwin >= 0.447) return true;
			break;
		case 9:
			if (prwin >= 0.419) return true;
			break;
		}
		return false;
	}
	if (BotLastFlopAction == State::Call) {
		//min hand AcAs Jc7s4c 
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.844) return true;
			break;
		case 3:
			if (prwin >= 0.723) return true;
			break;
		case 4:
			if (prwin >= 0.619) return true;
			break;
		case 5:
			if (prwin >= 0.535) return true;
			break;
		case 6:
			if (prwin >= 0.464) return true;
			break;
		case 7:
			if (prwin >= 0.401) return true;
			break;
		case 8:
			if (prwin >= 0.352) return true;
			break;
		case 9:
			if (prwin >= 0.307) return true;
			break;
		}
		return false;



	}

	return false;
};


bool Player::turn_Raise() {
	if (StackSize <= 30) {
		//min hand KsJs Kc3d7c 6d
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.8) return true;
			break;
		case 3:
			if (prwin >= 0.651) return true;
			break;
		case 4:
			if (prwin >= 0.531) return true;
			break;
		case 5:
			if (prwin >= 0.437) return true;
			break;
		case 6:
			if (prwin >= 0.357) return true;
			break;
		case 7:
			if (prwin >= 0.293) return true;
			break;
		case 8:
			if (prwin >= 0.24) return true;
			break;
		case 9:
			if (prwin >= 0.202) return true;
			break;
		}
		return false;



	}
	if (StackSize <= 40) {
		//min hand JdJh Tc2c8h 4s
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.82) return true;
			break;
		case 3:
			if (prwin >= 0.677) return true;
			break;
		case 4:
			if (prwin >= 0.558) return true;
			break;
		case 5:
			if (prwin >= 0.462) return true;
			break;
		case 6:
			if (prwin >= 0.38) return true;
			break;
		case 7:
			if (prwin >= 0.309) return true;
			break;
		case 8:
			if (prwin >= 0.258) return true;
			break;
		case 9:
			if (prwin >= 0.211) return true;
			break;
		}
		return false;




	}
	if (StackSize <= 50) {
		//min hand AdKc 3h8h7d As
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.867) return true;
			break;
		case 3:
			if (prwin >= 0.759) return true;
			break;
		case 4:
			if (prwin >= 0.665) return true;
			break;
		case 5:
			if (prwin >= 0.584) return true;
			break;
		case 6:
			if (prwin >= 0.509) return true;
			break;
		case 7:
			if (prwin >= 0.445) return true;
			break;
		case 8:
			if (prwin >= 0.385) return true;
			break;
		case 9:
			if (prwin >= 0.336) return true;
			break;
		}
		return false;




	}

	if (BotLastTurnAction == State::None) {
		if (BotLastFlopAction == State::Raise) {
			if (BotLastPreflopAction == State::Raise) {

				if (Pot <= 30) {
					//min hand 6dQc Th8dQd 7s
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.746) return true;
						break;
					case 3:
						if (prwin >= 0.561) return true;
						break;
					case 4:
						if (prwin >= 0.415) return true;
						break;
					case 5:
						if (prwin >= 0.308) return true;
						break;
					case 6:
						if (prwin >= 0.23) return true;
						break;
					case 7:
						if (prwin >= 0.168) return true;
						break;
					case 8:
						if (prwin >= 0.122) return true;
						break;
					case 9:
						if (prwin >= 0.0894) return true;
						break;
					}
					return false;



			}
				
				if (ToCall <= 5) {
					//min hand 8hKc 6h7s4d 5s
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.789) return true;
						break;
					case 3:
						if (prwin >= 0.666) return true;
						break;
					case 4:
						if (prwin >= 0.558) return true;
						break;
					case 5:
						if (prwin >= 0.466) return true;
						break;
					case 6:
						if (prwin >= 0.383) return true;
						break;
					case 7:
						if (prwin >= 0.314) return true;
						break;
					case 8:
						if (prwin >= 0.25) return true;
						break;
					case 9:
						if (prwin >= 0.201) return true;
						break;
					}
					return false;



				}
				//min hand 3sQd Jd3hQc 6c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.905) return true;
					break;
				case 3:
					if (prwin >= 0.827) return true;
					break;
				case 4:
					if (prwin >= 0.759) return true;
					break;
				case 5:
					if (prwin >= 0.698) return true;
					break;
				case 6:
					if (prwin >= 0.64) return true;
					break;
				case 7:
					if (prwin >= 0.59) return true;
					break;
				case 8:
					if (prwin >= 0.546) return true;
					break;
				case 9:
					if (prwin >= 0.502) return true;
					break;
				}
				return false;


			}
			if (BotLastPreflopAction == State::Call) {
				if (Pot <= 45) {
					//min hand TcQs Ts5c8h 9s
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.757) return true;
						break;
					case 3:
						if (prwin >= 0.585) return true;
						break;
					case 4:
						if (prwin >= 0.455) return true;
						break;
					case 5:
						if (prwin >= 0.354) return true;
						break;
					case 6:
						if (prwin >= 0.275) return true;
						break;
					case 7:
						if (prwin >= 0.213) return true;
						break;
					case 8:
						if (prwin >= 0.166) return true;
						break;
					case 9:
						if (prwin >= 0.13) return true;
						break;
					}
					return false;






				}
				//min hand KhKc Ac2hTh 6h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.801) return true;
					break;
				case 3:
					if (prwin >= 0.651) return true;
					break;
				case 4:
					if (prwin >= 0.531) return true;
					break;
				case 5:
					if (prwin >= 0.437) return true;
					break;
				case 6:
					if (prwin >= 0.358) return true;
					break;
				case 7:
					if (prwin >= 0.299) return true;
					break;
				case 8:
					if (prwin >= 0.252) return true;
					break;
				case 9:
					if (prwin >= 0.215) return true;
					break;
				}
				return false;




			}

			if (Pot <= 20) {
				//min hand Js8h 5sJdKc 2s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.739) return true;
					break;
				case 3:
					if (prwin >= 0.548) return true;
					break;
				case 4:
					if (prwin >= 0.415) return true;
					break;
				case 5:
					if (prwin >= 0.31) return true;
					break;
				case 6:
					if (prwin >= 0.233) return true;
					break;
				case 7:
					if (prwin >= 0.183) return true;
					break;
				case 8:
					if (prwin >= 0.144) return true;
					break;
				case 9:
					if (prwin >= 0.114) return true;
					break;
				}
				return false;
			}
			if (Pot <= 30) {
				//min hand JcAs 5cJh2c 4c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.792) return true;
					break;
				case 3:
					if (prwin >= 0.635) return true;
					break;
				case 4:
					if (prwin >= 0.508) return true;
					break;
				case 5:
					if (prwin >= 0.404) return true;
					break;
				case 6:
					if (prwin >= 0.322) return true;
					break;
				case 7:
					if (prwin >= 0.255) return true;
					break;
				case 8:
					if (prwin >= 0.205) return true;
					break;
				case 9:
					if (prwin >= 0.16) return true;
					break;
				}
				return false;








			}
			if (Pot <= 40) {

				//min hand KcKh 5s2cTd 2s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.855) return true;
					break;
				case 3:
					if (prwin >= 0.738) return true;
					break;
				case 4:
					if (prwin >= 0.633) return true;
					break;
				case 5:
					if (prwin >= 0.542) return true;
					break;
				case 6:
					if (prwin >= 0.467) return true;
					break;
				case 7:
					if (prwin >= 0.399) return true;
					break;
				case 8:
					if (prwin >= 0.338) return true;
					break;
				case 9:
					if (prwin >= 0.288) return true;
					break;
				}
				return false;




			}
			//min hand Qc7d 3h7cQh Th
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.826) return true;
				break;
			case 3:
				if (prwin >= 0.702) return true;
				break;
			case 4:
				if (prwin >= 0.606) return true;
				break;
			case 5:
				if (prwin >= 0.534) return true;
				break;
			case 6:
				if (prwin >= 0.471) return true;
				break;
			case 7:
				if (prwin >= 0.42) return true;
				break;
			case 8:
				if (prwin >= 0.376) return true;
				break;
			case 9:
				if (prwin >= 0.341) return true;
				break;
			}
			return false;




		}
		if (BotLastFlopAction == State::Call) {
			if (BotLastPreflopAction == State::Call) {
				if (Pot >= 20 && prwin > 0.95 && StackSize > 20 && Table->ActivePlayer == 2)return false;


				if (Pot <= 15) {
					//min hand AcQd JdTh2c 3d
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.496) return true;
						break;
					case 3:
						if (prwin >= 0.288) return true;
						break;
					case 4:
						if (prwin >= 0.199) return true;
						break;
					case 5:
						if (prwin >= 0.156) return true;
						break;
					case 6:
						if (prwin >= 0.134) return true;
						break;
					case 7:
						if (prwin >= 0.119) return true;
						break;
					case 8:
						if (prwin >= 0.108) return true;
						break;
					case 9:
						if (prwin >= 0.0994) return true;
						break;
					}
					return false;


				
				
				}
				if (Pot <= 40) {
					//min hand TcQd KsQhAc Jc
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.789) return true;
						break;
					case 3:
						if (prwin >= 0.669) return true;
						break;
					case 4:
						if (prwin >= 0.563) return true;
						break;
					case 5:
						if (prwin >= 0.47) return true;
						break;
					case 6:
						if (prwin >= 0.387) return true;
						break;
					case 7:
						if (prwin >= 0.315) return true;
						break;
					case 8:
						if (prwin >= 0.253) return true;
						break;
					case 9:
						if (prwin >= 0.204) return true;
						break;
					}
					return false;


				
				}
				//min hand 6h4h 5s4c7d 4d
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.892) return true;
					break;
				case 3:
					if (prwin >= 0.803) return true;
					break;
				case 4:
					if (prwin >= 0.725) return true;
					break;
				case 5:
					if (prwin >= 0.649) return true;
					break;
				case 6:
					if (prwin >= 0.583) return true;
					break;
				case 7:
					if (prwin >= 0.523) return true;
					break;
				case 8:
					if (prwin >= 0.469) return true;
					break;
				case 9:
					if (prwin >= 0.423) return true;
					break;
				}
				return false;



			}
			if (BotLastPreflopAction == State::Raise) {
				if (Pot <= 50) {
					//min hand TsTh 9h7s8d 2s
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.792) return true;
						break;
					case 3:
						if (prwin >= 0.635) return true;
						break;
					case 4:
						if (prwin >= 0.511) return true;
						break;
					case 5:
						if (prwin >= 0.411) return true;
						break;
					case 6:
						if (prwin >= 0.331) return true;
						break;
					case 7:
						if (prwin >= 0.266) return true;
						break;
					case 8:
						if (prwin >= 0.213) return true;
						break;
					case 9:
						if (prwin >= 0.169) return true;
						break;
					}
					return false;



				}
				//min hand 6hTc 3d6cTd As
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.892) return true;
					break;
				case 3:
					if (prwin >= 0.803) return true;
					break;
				case 4:
					if (prwin >= 0.73) return true;
					break;
				case 5:
					if (prwin >= 0.659) return true;
					break;
				case 6:
					if (prwin >= 0.602) return true;
					break;
				case 7:
					if (prwin >= 0.546) return true;
					break;
				case 8:
					if (prwin >= 0.5) return true;
					break;
				case 9:
					if (prwin >= 0.454) return true;
					break;
				}
				return false;





			}
			if (Pot <= 20) {
				//min hand QsQd 8hAc5h 4s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.7) return true;
					break;
				case 3:
					if (prwin >= 0.495) return true;
					break;
				case 4:
					if (prwin >= 0.353) return true;
					break;
				case 5:
					if (prwin >= 0.251) return true;
					break;
				case 6:
					if (prwin >= 0.182) return true;
					break;
				case 7:
					if (prwin >= 0.129) return true;
					break;
				case 8:
					if (prwin >= 0.0951) return true;
					break;
				case 9:
					if (prwin >= 0.0694) return true;
					break;
				}
				return false;


			}
			if (Pot <= 30) {
				//min hand Jd7d 4hJhKs 7h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.796) return true;
					break;
				case 3:
					if (prwin >= 0.657) return true;
					break;
				case 4:
					if (prwin >= 0.553) return true;
					break;
				case 5:
					if (prwin >= 0.471) return true;
					break;
				case 6:
					if (prwin >= 0.408) return true;
					break;
				case 7:
					if (prwin >= 0.358) return true;
					break;
				case 8:
					if (prwin >= 0.319) return true;
					break;
				case 9:
					if (prwin >= 0.279) return true;
					break;
				}
				return false;





			}
			if (Pot <= 40) {
				//min hand 7s6c Qh8d5h 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.844) return true;
					break;
				case 3:
					if (prwin >= 0.734) return true;
					break;
				case 4:
					if (prwin >= 0.651) return true;
					break;
				case 5:
					if (prwin >= 0.58) return true;
					break;
				case 6:
					if (prwin >= 0.526) return true;
					break;
				case 7:
					if (prwin >= 0.475) return true;
					break;
				case 8:
					if (prwin >= 0.433) return true;
					break;
				case 9:
					if (prwin >= 0.399) return true;
					break;
				}
				return false;






			}
			//min hand AdQc Jd4d7h Qh
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.844) return true;
				break;
			case 3:
				if (prwin >= 0.721) return true;
				break;
			case 4:
				if (prwin >= 0.614) return true;
				break;
			case 5:
				if (prwin >= 0.53) return true;
				break;
			case 6:
				if (prwin >= 0.45) return true;
				break;
			case 7:
				if (prwin >= 0.387) return true;
				break;
			case 8:
				if (prwin >= 0.329) return true;
				break;
			case 9:
				if (prwin >= 0.285) return true;
				break;
			}
			return false;


		}
		if (BotLastFlopAction == State::Check) {
			if (BotLastPreflopAction == State::Raise) {
				if (Pot <= 7) {
					//min hand 2c8d 7dQhTc 9h
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.243) return true;
						break;
					case 3:
						if (prwin >= 0.116) return true;
						break;
					case 4:
						if (prwin >= 0.0759) return true;
						break;
					case 5:
						if (prwin >= 0.0517) return true;
						break;
					case 6:
						if (prwin >= 0.0367) return true;
						break;
					case 7:
						if (prwin >= 0.0259) return true;
						break;
					case 8:
						if (prwin >= 0.0169) return true;
						break;
					case 9:
						if (prwin >= 0.0104) return true;
						break;
					}
					return false;




				}
				if (Pot <= 20) {
					//min hand AhJd 3d7hTd 4h
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.403) return true;
						break;
					case 3:
						if (prwin >= 0.192) return true;
						break;
					case 4:
						if (prwin >= 0.105) return true;
						break;
					case 5:
						if (prwin >= 0.0688) return true;
						break;
					case 6:
						if (prwin >= 0.05) return true;
						break;
					case 7:
						if (prwin >= 0.0363) return true;
						break;
					case 8:
						if (prwin >= 0.0286) return true;
						break;
					case 9:
						if (prwin >= 0.0209) return true;
						break;
					}
					return false;


				
				}
				//min hand AcTs 8cQh8h As
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.811) return true;
					break;
				case 3:
					if (prwin >= 0.658) return true;
					break;
				case 4:
					if (prwin >= 0.529) return true;
					break;
				case 5:
					if (prwin >= 0.424) return true;
					break;
				case 6:
					if (prwin >= 0.333) return true;
					break;
				case 7:
					if (prwin >= 0.262) return true;
					break;
				case 8:
					if (prwin >= 0.202) return true;
					break;
				case 9:
					if (prwin >= 0.153) return true;
					break;
				}
				return false;



			}
			if (BotLastPreflopAction == State::Call) {
				if (Pot <= 10){//min hand Qs7c 9sKd2d Ks
					switch (Table->ActivePlayer) {
					case 2:
						if (prwin >= 0.405) return true;
						break;
					case 3:
						if (prwin >= 0.178) return true;
						break;
					case 4:
						if (prwin >= 0.0862) return true;
						break;
					case 5:
						if (prwin >= 0.045) return true;
						break;
					case 6:
						if (prwin >= 0.0244) return true;
						break;
					case 7:
						if (prwin >= 0.0132) return true;
						break;
					case 8:
						if (prwin >= 0.00609) return true;
						break;
					case 9:
						if (prwin >= 0.00014) return true;
						break;
					}
					return false;

				}

			}
			if (Pot <= 10) {
				//min hand 7hAs Th3dKc Td
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.493) return true;
					break;
				case 3:
					if (prwin >= 0.253) return true;
					break;
				case 4:
					if (prwin >= 0.135) return true;
					break;
				case 5:
					if (prwin >= 0.0738) return true;
					break;
				case 6:
					if (prwin >= 0.0405) return true;
					break;
				case 7:
					if (prwin >= 0.0221) return true;
					break;
				case 8:
					if (prwin >= 0.0108) return true;
					break;
				case 9:
					if (prwin >= 0.00362) return true;
					break;
				}
				return false;


			}
			if (Pot <= 20) {
				//min hand 9hTc 5c5s5d 9c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.776) return true;
					break;
				case 3:
					if (prwin >= 0.618) return true;
					break;
				case 4:
					if (prwin >= 0.494) return true;
					break;
				case 5:
					if (prwin >= 0.387) return true;
					break;
				case 6:
					if (prwin >= 0.304) return true;
					break;
				case 7:
					if (prwin >= 0.238) return true;
					break;
				case 8:
					if (prwin >= 0.183) return true;
					break;
				case 9:
					if (prwin >= 0.139) return true;
					break;
				}
				return false;




			}
			//min hand QcQd 3h8c5s Tc
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.833) return true;
				break;
			case 3:
				if (prwin >= 0.699) return true;
				break;
			case 4:
				if (prwin >= 0.587) return true;
				break;
			case 5:
				if (prwin >= 0.493) return true;
				break;
			case 6:
				if (prwin >= 0.414) return true;
				break;
			case 7:
				if (prwin >= 0.346) return true;
				break;
			case 8:
				if (prwin >= 0.289) return true;
				break;
			case 9:
				if (prwin >= 0.244) return true;
				break;
			}
			return false;


		}
	}
	if (BotLastTurnAction == State::Raise) {
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise) {
			if (ToCall < 5) {

				//min hand 3d4d 6dQc3h 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.794) return true;
					break;
				case 3:
					if (prwin >= 0.65) return true;
					break;
				case 4:
					if (prwin >= 0.539) return true;
					break;
				case 5:
					if (prwin >= 0.455) return true;
					break;
				case 6:
					if (prwin >= 0.389) return true;
					break;
				case 7:
					if (prwin >= 0.337) return true;
					break;
				case 8:
					if (prwin >= 0.294) return true;
					break;
				case 9:
					if (prwin >= 0.259) return true;
					break;
				}
				return false;
			}
			//min hand KcQs Qh3c8d 6d
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.846) return true;
				break;
			case 3:
				if (prwin >= 0.721) return true;
				break;
			case 4:
				if (prwin >= 0.617) return true;
				break;
			case 5:
				if (prwin >= 0.525) return true;
				break;
			case 6:
				if (prwin >= 0.448) return true;
				break;
			case 7:
				if (prwin >= 0.385) return true;
				break;
			case 8:
				if (prwin >= 0.327) return true;
				break;
			case 9:
				if (prwin >= 0.281) return true;
				break;
			}
			return false;



		}
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Raise ) {
			//min hand 9h2d 5s3h2c 9s
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.835) return true;
				break;
			case 3:
				if (prwin >= 0.707) return true;
				break;
			case 4:
				if (prwin >= 0.609) return true;
				break;
			case 5:
				if (prwin >= 0.528) return true;
				break;
			case 6:
				if (prwin >= 0.46) return true;
				break;
			case 7:
				if (prwin >= 0.408) return true;
				break;
			case 8:
				if (prwin >= 0.361) return true;
				break;
			case 9:
				if (prwin >= 0.322) return true;
				break;
			}

			return false;



		}
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call) {
			
			//min hand 5cJs 9dJh5h 3d
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.895) return true;
				break;
			case 3:
				if (prwin >= 0.81) return true;
				break;
			case 4:
				if (prwin >= 0.733) return true;
				break;
			case 5:
				if (prwin >= 0.662) return true;
				break;
			case 6:
				if (prwin >= 0.6) return true;
				break;
			case 7:
				if (prwin >= 0.547) return true;
				break;
			case 8:
				if (prwin >= 0.498) return true;
				break;
			case 9:
				if (prwin >= 0.453) return true;
				break;
			}
			return false;





		}
		
		
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Check && BotLastTurnAction == State::Raise) {
		
			if (Pot <= 40) {
				//min hand QcKs Kd2hTc 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.852) return true;
					break;
				case 3:
					if (prwin >= 0.736) return true;
					break;
				case 4:
					if (prwin >= 0.637) return true;
					break;
				case 5:
					if (prwin >= 0.549) return true;
					break;
				case 6:
					if (prwin >= 0.472) return true;
					break;
				case 7:
					if (prwin >= 0.406) return true;
					break;
				case 8:
					if (prwin >= 0.346) return true;
					break;
				case 9:
					if (prwin >= 0.294) return true;
					break;
				}
				return false;




			}

		}

		//min hand Th9h Tc5s9c Ad
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.889) return true;
			break;
		case 3:
			if (prwin >= 0.801) return true;
			break;
		case 4:
			if (prwin >= 0.723) return true;
			break;
		case 5:
			if (prwin >= 0.652) return true;
			break;
		case 6:
			if (prwin >= 0.593) return true;
			break;
		case 7:
			if (prwin >= 0.54) return true;
			break;
		case 8:
			if (prwin >= 0.491) return true;
			break;
		case 9:
			if (prwin >= 0.448) return true;
			break;
		}
		return false;






	}
	if (BotLastTurnAction == State::Check) {
		//min hand Th9h Tc5s9c Ad
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.889) return true;
			break;
		case 3:
			if (prwin >= 0.801) return true;
			break;
		case 4:
			if (prwin >= 0.723) return true;
			break;
		case 5:
			if (prwin >= 0.652) return true;
			break;
		case 6:
			if (prwin >= 0.593) return true;
			break;
		case 7:
			if (prwin >= 0.54) return true;
			break;
		case 8:
			if (prwin >= 0.491) return true;
			break;
		case 9:
			if (prwin >= 0.448) return true;
			break;
		}
		return false;



	}

	//min hand 3sQd Jd3hQc 6c
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.905) return true;
		break;
	case 3:
		if (prwin >= 0.827) return true;
		break;
	case 4:
		if (prwin >= 0.759) return true;
		break;
	case 5:
		if (prwin >= 0.698) return true;
		break;
	case 6:
		if (prwin >= 0.64) return true;
		break;
	case 7:
		if (prwin >= 0.59) return true;
		break;
	case 8:
		if (prwin >= 0.546) return true;
		break;
	case 9:
		if (prwin >= 0.502) return true;
		break;
	}
	return false;











};
bool Player::turn_Call() {
	

	if (BotLastTurnAction == State::None) {
		if (StackSize < 40) {
			//min hand AcAs 5dTdQh Jh
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.793) return true;
				break;
			case 3:
				if (prwin >= 0.64) return true;
				break;
			case 4:
				if (prwin >= 0.516) return true;
				break;
			case 5:
				if (prwin >= 0.42) return true;
				break;
			case 6:
				if (prwin >= 0.34) return true;
				break;
			case 7:
				if (prwin >= 0.278) return true;
				break;
			case 8:
				if (prwin >= 0.225) return true;
				break;
			case 9:
				if (prwin >= 0.183) return true;
				break;
			}
			return false;




		}
		if (BotLastFlopAction == State::Raise) {
			if (Pot <= 20) {//min hand 7c7s 6d6h9s Jc
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.59) return true;
					break;
				case 3:
					if (prwin >= 0.36) return true;
					break;
				case 4:
					if (prwin >= 0.22) return true;
					break;
				case 5:
					if (prwin >= 0.139) return true;
					break;
				case 6:
					if (prwin >= 0.0921) return true;
					break;
				case 7:
					if (prwin >= 0.0648) return true;
					break;
				case 8:
					if (prwin >= 0.0492) return true;
					break;
				case 9:
					if (prwin >= 0.0405) return true;
					break;
				}

				return false;

			}
			if (Pot <= 30) {
				//min hand QsQd 5c9dKc 7c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.64) return true;
					break;
				case 3:
					if (prwin >= 0.427) return true;
					break;
				case 4:
					if (prwin >= 0.287) return true;
					break;
				case 5:
					if (prwin >= 0.195) return true;
					break;
				case 6:
					if (prwin >= 0.133) return true;
					break;
				case 7:
					if (prwin >= 0.0893) return true;
					break;
				case 8:
					if (prwin >= 0.0616) return true;
					break;
				case 9:
					if (prwin >= 0.0416) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {

				//min hand Th3c 9c7sTs 4c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.69) return true;
					break;
				case 3:
					if (prwin >= 0.489) return true;
					break;
				case 4:
					if (prwin >= 0.35) return true;
					break;
				case 5:
					if (prwin >= 0.252) return true;
					break;
				case 6:
					if (prwin >= 0.186) return true;
					break;
				case 7:
					if (prwin >= 0.138) return true;
					break;
				case 8:
					if (prwin >= 0.101) return true;
					break;
				case 9:
					if (prwin >= 0.0762) return true;
					break;
				}
				return false;



			}
			if (Pot <= 50) {
				//min hand KcAh 6dAd9d 6s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.764) return true;
					break;
				case 3:
					if (prwin >= 0.6) return true;
					break;
				case 4:
					if (prwin >= 0.479) return true;
					break;
				case 5:
					if (prwin >= 0.384) return true;
					break;
				case 6:
					if (prwin >= 0.306) return true;
					break;
				case 7:
					if (prwin >= 0.248) return true;
					break;
				case 8:
					if (prwin >= 0.201) return true;
					break;
				case 9:
					if (prwin >= 0.16) return true;
					break;
				}
				return false;




			}
			if (Pot <= 60) {
				//min hand AsKs Ad5hQh 3s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.837) return true;
					break;
				case 3:
					if (prwin >= 0.712) return true;
					break;
				case 4:
					if (prwin >= 0.604) return true;
					break;
				case 5:
					if (prwin >= 0.516) return true;
					break;
				case 6:
					if (prwin >= 0.442) return true;
					break;
				case 7:
					if (prwin >= 0.38) return true;
					break;
				case 8:
					if (prwin >= 0.323) return true;
					break;
				case 9:
					if (prwin >= 0.275) return true;
					break;
				}
				return false;




			}


		}
		if (BotLastFlopAction == State::Call) {
			if(BotLastPreflopAction == State::Raise ){
			
			
			}
			
			
			if (Pot <= 10) {
				//min hand 2s3c 9d9c2d 7d
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.443) return true;
					break;
				case 3:
					if (prwin >= 0.219) return true;
					break;
				case 4:
					if (prwin >= 0.113) return true;
					break;
				case 5:
					if (prwin >= 0.0592) return true;
					break;
				case 6:
					if (prwin >= 0.0323) return true;
					break;
				case 7:
					if (prwin >= 0.0176) return true;
					break;
				case 8:
					if (prwin >= 0.00858) return true;
					break;
				case 9:
					if (prwin >= 0.00323) return true;
					break;
				}
				return false;



			}
			if (Pot <= 15) {
				//min hand AdTh 4dJs3c Kc
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.475) return true;
					break;
				case 3:
					if (prwin >= 0.258) return true;
					break;
				case 4:
					if (prwin >= 0.171) return true;
					break;
				case 5:
					if (prwin >= 0.13) return true;
					break;
				case 6:
					if (prwin >= 0.109) return true;
					break;
				case 7:
					if (prwin >= 0.0987) return true;
					break;
				case 8:
					if (prwin >= 0.0901) return true;
					break;
				case 9:
					if (prwin >= 0.083) return true;
					break;
				}
				return false;



			}
			if (Pot <= 20) {


				//min hand JsAc Th3h3s Qh
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.489) return true;
					break;
				case 3:
					if (prwin >= 0.26) return true;
					break;
				case 4:
					if (prwin >= 0.148) return true;
					break;
				case 5:
					if (prwin >= 0.0919) return true;
					break;
				case 6:
					if (prwin >= 0.0628) return true;
					break;
				case 7:
					if (prwin >= 0.0454) return true;
					break;
				case 8:
					if (prwin >= 0.0355) return true;
					break;
				case 9:
					if (prwin >= 0.0279) return true;
					break;
				}

				return false;




			}
			if (Pot <= 25) {
				//min hand Ah6d 2d4d3h 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.493) return true;
					break;
				case 3:
					if (prwin >= 0.256) return true;
					break;
				case 4:
					if (prwin >= 0.142) return true;
					break;
				case 5:
					if (prwin >= 0.0823) return true;
					break;
				case 6:
					if (prwin >= 0.0489) return true;
					break;
				case 7:
					if (prwin >= 0.0311) return true;
					break;
				case 8:
					if (prwin >= 0.0168) return true;
					break;
				case 9:
					if (prwin >= 0.00876) return true;
					break;
				}
				return false;




			}
			if (Pot <= 30) {
				//min hand AcKd Qh9sJc Qd
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.569) return true;
					break;
				case 3:
					if (prwin >= 0.347) return true;
					break;
				case 4:
					if (prwin >= 0.232) return true;
					break;
				case 5:
					if (prwin >= 0.165) return true;
					break;
				case 6:
					if (prwin >= 0.127) return true;
					break;
				case 7:
					if (prwin >= 0.104) return true;
					break;
				case 8:
					if (prwin >= 0.0898) return true;
					break;
				case 9:
					if (prwin >= 0.0794) return true;
					break;
				}
				return false;



			}
			if (Pot <= 50) {
				//min hand AdQd 2c3sQc 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.811) return true;
					break;
				case 3:
					if (prwin >= 0.664) return true;
					break;
				case 4:
					if (prwin >= 0.546) return true;
					break;
				case 5:
					if (prwin >= 0.448) return true;
					break;
				case 6:
					if (prwin >= 0.368) return true;
					break;
				case 7:
					if (prwin >= 0.299) return true;
					break;
				case 8:
					if (prwin >= 0.245) return true;
					break;
				case 9:
					if (prwin >= 0.202) return true;
					break;
				}
				return false;


			}

			//min hand Kc6d KhKsTd As
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.892) return true;
				break;
			case 3:
				if (prwin >= 0.806) return true;
				break;
			case 4:
				if (prwin >= 0.73) return true;
				break;
			case 5:
				if (prwin >= 0.665) return true;
				break;
			case 6:
				if (prwin >= 0.601) return true;
				break;
			case 7:
				if (prwin >= 0.549) return true;
				break;
			case 8:
				if (prwin >= 0.502) return true;
				break;
			case 9:
				if (prwin >= 0.457) return true;
				break;
			}
			return false;



		}
		if (BotLastFlopAction == State::Check) {

			if (Pot <= 5) {
				//min hand 3dKc Ah5c6d 4h
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.397) return true;
					break;
				case 3:
					if (prwin >= 0.192) return true;
					break;
				case 4:
					if (prwin >= 0.111) return true;
					break;
				case 5:
					if (prwin >= 0.0713) return true;
					break;
				case 6:
					if (prwin >= 0.0476) return true;
					break;
				case 7:
					if (prwin >= 0.0336) return true;
					break;
				case 8:
					if (prwin >= 0.0201) return true;
					break;
				case 9:
					if (prwin >= 0.0135) return true;
					break;
				}
				return false;
			}
			if (Pot <= 20) {
				//min hand 8s3h 3d4dAs 4s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.49) return true;
					break;
				case 3:
					if (prwin >= 0.268) return true;
					break;
				case 4:
					if (prwin >= 0.142) return true;
					break;
				case 5:
					if (prwin >= 0.0768) return true;
					break;
				case 6:
					if (prwin >= 0.0411) return true;
					break;
				case 7:
					if (prwin >= 0.0221) return true;
					break;
				case 8:
					if (prwin >= 0.0115) return true;
					break;
				case 9:
					if (prwin >= 0.00439) return true;
					break;
				}
				return false;




			}
			if (Pot <= 30) {
				
				//min hand 7s8d 4s7h3s 5c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.59) return true;
					break;
				case 3:
					if (prwin >= 0.356) return true;
					break;
				case 4:
					if (prwin >= 0.224) return true;
					break;
				case 5:
					if (prwin >= 0.143) return true;
					break;
				case 6:
					if (prwin >= 0.0904) return true;
					break;
				case 7:
					if (prwin >= 0.0593) return true;
					break;
				case 8:
					if (prwin >= 0.0402) return true;
					break;
				case 9:
					if (prwin >= 0.0256) return true;
					break;
				}
				return false;


			}
			if (Pot <= 40) {
				//min hand 7d6s 7c5h5s 2c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.695) return true;
					break;
				case 3:
					if (prwin >= 0.487) return true;
					break;
				case 4:
					if (prwin >= 0.345) return true;
					break;
				case 5:
					if (prwin >= 0.241) return true;
					break;
				case 6:
					if (prwin >= 0.173) return true;
					break;
				case 7:
					if (prwin >= 0.122) return true;
					break;
				case 8:
					if (prwin >= 0.0884) return true;
					break;
				case 9:
					if (prwin >= 0.0634) return true;
					break;
				}
				return false;



			}
			if (Pot <= 60) {
				//min hand Jh3h 9cKdTc Qh
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.785) return true;
					break;
				case 3:
					if (prwin >= 0.667) return true;
					break;
				case 4:
					if (prwin >= 0.559) return true;
					break;
				case 5:
					if (prwin >= 0.465) return true;
					break;
				case 6:
					if (prwin >= 0.385) return true;
					break;
				case 7:
					if (prwin >= 0.313) return true;
					break;
				case 8:
					if (prwin >= 0.254) return true;
					break;
				case 9:
					if (prwin >= 0.2) return true;
					break;
				}
				return false;


			}



		}
	}
	if (BotLastTurnAction == State::Call) {
		//min hand 9cAc Ks9h9s Td
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.899) return true;
			break;
		case 3:
			if (prwin >= 0.821) return true;
			break;
		case 4:
			if (prwin >= 0.748) return true;
			break;
		case 5:
			if (prwin >= 0.688) return true;
			break;
		case 6:
			if (prwin >= 0.625) return true;
			break;
		case 7:
			if (prwin >= 0.58) return true;
			break;
		case 8:
			if (prwin >= 0.534) return true;
			break;
		case 9:
			if (prwin >= 0.499) return true;
			break;
		}
		return false;





	}
	if (BotLastTurnAction == State::Raise) {
		if (Pot <= 10) {
			//min hand Qs2d 5hQh7c 9c
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.742) return true;
				break;
			case 3:
				if (prwin >= 0.558) return true;
				break;
			case 4:
				if (prwin >= 0.425) return true;
				break;
			case 5:
				if (prwin >= 0.32) return true;
				break;
			case 6:
				if (prwin >= 0.243) return true;
				break;
			case 7:
				if (prwin >= 0.184) return true;
				break;
			case 8:
				if (prwin >= 0.141) return true;
				break;
			case 9:
				if (prwin >= 0.11) return true;
				break;
			}
			return false;



		}
		if (Pot <= 35) {
			//min hand AcQc Ts9s4h Qs
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.699) return true;
				break;
			case 3:
				if (prwin >= 0.514) return true;
				break;
			case 4:
				if (prwin >= 0.39) return true;
				break;
			case 5:
				if (prwin >= 0.296) return true;
				break;
			case 6:
				if (prwin >= 0.232) return true;
				break;
			case 7:
				if (prwin >= 0.184) return true;
				break;
			case 8:
				if (prwin >= 0.146) return true;
				break;
			case 9:
				if (prwin >= 0.115) return true;
				break;
			}
			return false;




		}
		if (Pot <= 40) {
			//min hand TcKd 9s2cQc Ks
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.823) return true;
				break;
			case 3:
				if (prwin >= 0.685) return true;
				break;
			case 4:
				if (prwin >= 0.567) return true;
				break;
			case 5:
				if (prwin >= 0.467) return true;
				break;
			case 6:
				if (prwin >= 0.387) return true;
				break;
			case 7:
				if (prwin >= 0.314) return true;
				break;
			case 8:
				if (prwin >= 0.258) return true;
				break;
			case 9:
				if (prwin >= 0.21) return true;
				break;
			}
			return false;



		}
		//min hand Jd2s 2d5d9d Qd
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.899) return true;
			break;
		case 3:
			if (prwin >= 0.811) return true;
			break;
		case 4:
			if (prwin >= 0.731) return true;
			break;
		case 5:
			if (prwin >= 0.653) return true;
			break;
		case 6:
			if (prwin >= 0.578) return true;
			break;
		case 7:
			if (prwin >= 0.513) return true;
			break;
		case 8:
			if (prwin >= 0.444) return true;
			break;
		case 9:
			if (prwin >= 0.39) return true;
			break;
		}
		return false;



	}
	if (BotLastTurnAction == State::Check) {
		if (Pot <= 4) {
			//min hand Td8s AsJcQd Th
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.435) return true;
				break;
			case 3:
				if (prwin >= 0.211) return true;
				break;
			case 4:
				if (prwin >= 0.102) return true;
				break;
			case 5:
				if (prwin >= 0.0496) return true;
				break;
			case 6:
				if (prwin >= 0.0224) return true;
				break;
			case 7:
				if (prwin >= 0.00992) return true;
				break;
			case 8:
				if (prwin >= 0.00203) return true;
				break;
			case 9:
				if (prwin >= -0.00273) return true;
				break;
			}
			return false;		
		}
		if (Pot <= 20) {
			//min hand 5s4c 5d4sTs Ad
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.814) return true;
				break;
			case 3:
				if (prwin >= 0.676) return true;
				break;
			case 4:
				if (prwin >= 0.569) return true;
				break;
			case 5:
				if (prwin >= 0.484) return true;
				break;
			case 6:
				if (prwin >= 0.413) return true;
				break;
			case 7:
				if (prwin >= 0.355) return true;
				break;
			case 8:
				if (prwin >= 0.308) return true;
				break;
			case 9:
				if (prwin >= 0.268) return true;
				break;
			}
			return false;



		}


	}
	
	//min hand Qs8d AhQd5h 8s
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.895) return true;
		break;
	case 3:
		if (prwin >= 0.809) return true;
		break;
	case 4:
		if (prwin >= 0.731) return true;
		break;
	case 5:
		if (prwin >= 0.666) return true;
		break;
	case 6:
		if (prwin >= 0.607) return true;
		break;
	case 7:
		if (prwin >= 0.55) return true;
		break;
	case 8:
		if (prwin >= 0.502) return true;
		break;
	case 9:
		if (prwin >= 0.459) return true;
		break;
	}
	return false;









};


bool Player::river_Raise() {
		

	if (BotLastTurnAction == State::Check) {

		if (Pot <= 20) {
			//min hand JsQd 6c7dQs 6d8c
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.8) return true;
				break;
			case 3:
				if (prwin >= 0.643) return true;
				break;
			case 4:
				if (prwin >= 0.51) return true;
				break;
			case 5:
				if (prwin >= 0.406) return true;
				break;
			case 6:
				if (prwin >= 0.319) return true;
				break;
			case 7:
				if (prwin >= 0.251) return true;
				break;
			case 8:
				if (prwin >= 0.19) return true;
				break;
			case 9:
				if (prwin >= 0.145) return true;
				break;
			}
			return false;


		}
		if (Pot <= 25) {
			//min hand QcAh 4d3c9d 8cQd
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.824) return true;
				break;
			case 3:
				if (prwin >= 0.683) return true;
				break;
			case 4:
				if (prwin >= 0.565) return true;
				break;
			case 5:
				if (prwin >= 0.465) return true;
				break;
			case 6:
				if (prwin >= 0.382) return true;
				break;
			case 7:
				if (prwin >= 0.315) return true;
				break;
			case 8:
				if (prwin >= 0.254) return true;
				break;
			case 9:
				if (prwin >= 0.206) return true;
				break;
			}
			return false;


		}
		if (Pot <= 30) {
			//min hand 3d8s 3cQcTs 8hAc
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.836) return true;
				break;
			case 3:
				if (prwin >= 0.704) return true;
				break;
			case 4:
				if (prwin >= 0.592) return true;
				break;
			case 5:
				if (prwin >= 0.497) return true;
				break;
			case 6:
				if (prwin >= 0.416) return true;
				break;
			case 7:
				if (prwin >= 0.342) return true;
				break;
			case 8:
				if (prwin >= 0.287) return true;
				break;
			case 9:
				if (prwin >= 0.236) return true;
				break;
			}
			return false;


		}
		if (Pot <= 40) {
			//min hand Qc9s 4c9d7c 5c2c
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.9) return true;
				break;
			case 3:
				if (prwin >= 0.813) return true;
				break;
			case 4:
				if (prwin >= 0.734) return true;
				break;
			case 5:
				if (prwin >= 0.658) return true;
				break;
			case 6:
				if (prwin >= 0.586) return true;
				break;
			case 7:
				if (prwin >= 0.516) return true;
				break;
			case 8:
				if (prwin >= 0.455) return true;
				break;
			case 9:
				if (prwin >= 0.394) return true;
				break;
			}
			return false;


		}
		//min hand 8h5h Jd7s6d 9h6s
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.941) return true;
			break;
		case 3:
			if (prwin >= 0.892) return true;
			break;
		case 4:
			if (prwin >= 0.849) return true;
			break;
		case 5:
			if (prwin >= 0.804) return true;
			break;
		case 6:
			if (prwin >= 0.765) return true;
			break;
		case 7:
			if (prwin >= 0.723) return true;
			break;
		case 8:
			if (prwin >= 0.686) return true;
			break;
		case 9:
			if (prwin >= 0.649) return true;
			break;
		}
		return false;



	}
	if (BotLastTurnAction == State::Raise) {
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise) {
			//min hand Ad8h TcAc2d 7s8c
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.894) return true;
				break;
			case 3:
				if (prwin >= 0.804) return true;
				break;
			case 4:
				if (prwin >= 0.725) return true;
				break;
			case 5:
				if (prwin >= 0.65) return true;
				break;
			case 6:
				if (prwin >= 0.587) return true;
				break;
			case 7:
				if (prwin >= 0.524) return true;
				break;
			case 8:
				if (prwin >= 0.472) return true;
				break;
			case 9:
				if (prwin >= 0.418) return true;
				break;
			}
			return false;

		
		}
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Call && BotLastTurnAction == State::Raise) {
			if (StackSize > 50) {
				//min hand AdJc AsAh3h Qd5c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.947) return true;
					break;
				case 3:
					if (prwin >= 0.909) return true;
					break;
				case 4:
					if (prwin >= 0.87) return true;
					break;
				case 5:
					if (prwin >= 0.832) return true;
					break;
				case 6:
					if (prwin >= 0.798) return true;
					break;
				case 7:
					if (prwin >= 0.76) return true;
					break;
				case 8:
					if (prwin >= 0.727) return true;
					break;
				case 9:
					if (prwin >= 0.696) return true;
					break;
				}
				return false;




			}



		}
		if (Pot <= 55){
			//min hand 8s6h JsTc5d 7c9c
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.806) return true;
				break;
			case 3:
				if (prwin >= 0.653) return true;
				break;
			case 4:
				if (prwin >= 0.526) return true;
				break;
			case 5:
				if (prwin >= 0.419) return true;
				break;
			case 6:
				if (prwin >= 0.325) return true;
				break;
			case 7:
				if (prwin >= 0.253) return true;
				break;
			case 8:
				if (prwin >= 0.19) return true;
				break;
			case 9:
				if (prwin >= 0.143) return true;
				break;
			}
			return false;



		}
		if (Pot <= 60) {
			//min hand 3s9d 2h8sJd TsQh
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.844) return true;
				break;
			case 3:
				if (prwin >= 0.716) return true;
				break;
			case 4:
				if (prwin >= 0.6) return true;
				break;
			case 5:
				if (prwin >= 0.498) return true;
				break;
			case 6:
				if (prwin >= 0.411) return true;
				break;
			case 7:
				if (prwin >= 0.336) return true;
				break;
			case 8:
				if (prwin >= 0.266) return true;
				break;
			case 9:
				if (prwin >= 0.21) return true;
				break;
			}
			return false;



		}
		//min hand 4sKc 9h8dAd KdKh
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.89) return true;
			break;
		case 3:
			if (prwin >= 0.799) return true;
			break;
		case 4:
			if (prwin >= 0.714) return true;
			break;
		case 5:
			if (prwin >= 0.638) return true;
			break;
		case 6:
			if (prwin >= 0.566) return true;
			break;
		case 7:
			if (prwin >= 0.499) return true;
			break;
		case 8:
			if (prwin >= 0.436) return true;
			break;
		case 9:
			if (prwin >= 0.386) return true;
			break;
		}
		return false;



	}
	if (BotLastTurnAction == State::Call) {
		if (Pot <= 40) {
			//min hand AdQd 8d6c3s 3dAh
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.868) return true;
				break;
			case 3:
				if (prwin >= 0.758) return true;
				break;
			case 4:
				if (prwin >= 0.658) return true;
				break;
			case 5:
				if (prwin >= 0.565) return true;
				break;
			case 6:
				if (prwin >= 0.486) return true;
				break;
			case 7:
				if (prwin >= 0.415) return true;
				break;
			case 8:
				if (prwin >= 0.347) return true;
				break;
			case 9:
				if (prwin >= 0.291) return true;
				break;
			}
			return false;






		}

		//min hand 4sKc 9h8dAd KdKh
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.89) return true;
			break;
		case 3:
			if (prwin >= 0.799) return true;
			break;
		case 4:
			if (prwin >= 0.714) return true;
			break;
		case 5:
			if (prwin >= 0.638) return true;
			break;
		case 6:
			if (prwin >= 0.566) return true;
			break;
		case 7:
			if (prwin >= 0.499) return true;
			break;
		case 8:
			if (prwin >= 0.436) return true;
			break;
		case 9:
			if (prwin >= 0.386) return true;
			break;
		}
		return false;



	}
	if (Pot <= 10) {
		//min hand 9h6d 6sJcKd Qd2h
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.499) return true;
			break;
		case 3:
			if (prwin >= 0.238) return true;
			break;
		case 4:
			if (prwin >= 0.109) return true;
			break;
		case 5:
			if (prwin >= 0.0451) return true;
			break;
		case 6:
			if (prwin >= 0.0134) return true;
			break;
		case 7:
			if (prwin >= -0.00023) return true;
			break;
		case 8:
			if (prwin >= -0.00645) return true;
			break;
		case 9:
			if (prwin >= -0.00859) return true;
			break;
		}
		return false;




	}
	if (Pot <= 20) {
		//min hand 4dJc JsTs3s 7h6c
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.747) return true;
			break;
		case 3:
			if (prwin >= 0.559) return true;
			break;
		case 4:
			if (prwin >= 0.417) return true;
			break;
		case 5:
			if (prwin >= 0.304) return true;
			break;
		case 6:
			if (prwin >= 0.222) return true;
			break;
		case 7:
			if (prwin >= 0.159) return true;
			break;
		case 8:
			if (prwin >= 0.114) return true;
			break;
		case 9:
			if (prwin >= 0.0757) return true;
			break;
		}
		return false;




	}
	if (Pot <= 30) {
		//min hand 9sQd 9h5s4s 6h5c
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.79) return true;
			break;
		case 3:
			if (prwin >= 0.627) return true;
			break;
		case 4:
			if (prwin >= 0.497) return true;
			break;
		case 5:
			if (prwin >= 0.389) return true;
			break;
		case 6:
			if (prwin >= 0.299) return true;
			break;
		case 7:
			if (prwin >= 0.232) return true;
			break;
		case 8:
			if (prwin >= 0.176) return true;
			break;
		case 9:
			if (prwin >= 0.133) return true;
			break;
		}
		return false;



	}
	if (Pot <= 40) {
		//min hand KdQs 4s5h8h JcQc
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.844) return true;
			break;
		case 3:
			if (prwin >= 0.715) return true;
			break;
		case 4:
			if (prwin >= 0.607) return true;
			break;
		case 5:
			if (prwin >= 0.511) return true;
			break;
		case 6:
			if (prwin >= 0.432) return true;
			break;
		case 7:
			if (prwin >= 0.36) return true;
			break;
		case 8:
			if (prwin >= 0.304) return true;
			break;
		case 9:
			if (prwin >= 0.253) return true;
			break;
		}
		return false;




	}
	//min hand 6dQc Qd9sQs 3c4d
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.944) return true;
		break;
	case 3:
		if (prwin >= 0.899) return true;
		break;
	case 4:
		if (prwin >= 0.856) return true;
		break;
	case 5:
		if (prwin >= 0.811) return true;
		break;
	case 6:
		if (prwin >= 0.771) return true;
		break;
	case 7:
		if (prwin >= 0.727) return true;
		break;
	case 8:
		if (prwin >= 0.686) return true;
		break;
	case 9:
		if (prwin >= 0.648) return true;
		break;
	}
	return false;

};
bool Player::river_Call() {	



	if (BotLastTurnAction == State::Check) {
		if (BotLastPreflopAction == State::Raise && BotLastFlopAction == State::Raise && Pot >= 30) {
			//min hand AdAs Ks2cKh Qs6d
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.893) return true;
				break;
			case 3:
				if (prwin >= 0.799) return true;
				break;
			case 4:
				if (prwin >= 0.715) return true;
				break;
			case 5:
				if (prwin >= 0.633) return true;
				break;
			case 6:
				if (prwin >= 0.556) return true;
				break;
			case 7:
				if (prwin >= 0.489) return true;
				break;
			case 8:
				if (prwin >= 0.424) return true;
				break;
			case 9:
				if (prwin >= 0.364) return true;
				break;
			}
			return false;


		
		}
		if (BotLastPreflopAction == State::Call && BotLastFlopAction == State::Call) {
			//min hand QdAd AhTc4s Ks7h
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.88) return true;
				break;
			case 3:
				if (prwin >= 0.781) return true;
				break;
			case 4:
				if (prwin >= 0.691) return true;
				break;
			case 5:
				if (prwin >= 0.606) return true;
				break;
			case 6:
				if (prwin >= 0.536) return true;
				break;
			case 7:
				if (prwin >= 0.47) return true;
				break;
			case 8:
				if (prwin >= 0.41) return true;
				break;
			case 9:
				if (prwin >= 0.355) return true;
				break;
			}
			return false;






		}

		if (BotLastFlopAction == State::Check) {

			if (Pot <= 7) {
				//min hand 9c7h 2s9s6s AsAc
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.505) return true;
					break;
				case 3:
					if (prwin >= 0.244) return true;
					break;
				case 4:
					if (prwin >= 0.111) return true;
					break;
				case 5:
					if (prwin >= 0.0452) return true;
					break;
				case 6:
					if (prwin >= 0.015) return true;
					break;
				case 7:
					if (prwin >= -3e-05) return true;
					break;
				case 8:
					if (prwin >= -0.00642) return true;
					break;
				case 9:
					if (prwin >= -0.00872) return true;
					break;
				}
				return false;


			
			}
			if (Pot <= 10) {
				//min hand 9d8h 3h5s9c KhQc
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.646) return true;
					break;
				case 3:
					if (prwin >= 0.411) return true;
					break;
				case 4:
					if (prwin >= 0.254) return true;
					break;
				case 5:
					if (prwin >= 0.157) return true;
					break;
				case 6:
					if (prwin >= 0.0892) return true;
					break;
				case 7:
					if (prwin >= 0.0488) return true;
					break;
				case 8:
					if (prwin >= 0.0233) return true;
					break;
				case 9:
					if (prwin >= 0.00779) return true;
					break;
				}
				return false;



			}
			if (Pot <= 40) {
				//min hand KcQc Ts2h8h Qd5c
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.86) return true;
					break;
				case 3:
					if (prwin >= 0.744) return true;
					break;
				case 4:
					if (prwin >= 0.64) return true;
					break;
				case 5:
					if (prwin >= 0.553) return true;
					break;
				case 6:
					if (prwin >= 0.472) return true;
					break;
				case 7:
					if (prwin >= 0.406) return true;
					break;
				case 8:
					if (prwin >= 0.345) return true;
					break;
				case 9:
					if (prwin >= 0.293) return true;
					break;
				}
				return false;




			}

			//min hand Kc9h 7s8cKh JsQc
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.841) return true;
				break;
			case 3:
				if (prwin >= 0.712) return true;
				break;
			case 4:
				if (prwin >= 0.602) return true;
				break;
			case 5:
				if (prwin >= 0.506) return true;
				break;
			case 6:
				if (prwin >= 0.424) return true;
				break;
			case 7:
				if (prwin >= 0.353) return true;
				break;
			case 8:
				if (prwin >= 0.293) return true;
				break;
			case 9:
				if (prwin >= 0.245) return true;
				break;
			}
			return false;



}
		if (BotLastFlopAction == State::Raise) {
			if (Pot <= 15) {

				//min hand 9dAs 6c5h9h 7d2s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.676) return true;
					break;
				case 3:
					if (prwin >= 0.454) return true;
					break;
				case 4:
					if (prwin >= 0.302) return true;
					break;
				case 5:
					if (prwin >= 0.198) return true;
					break;
				case 6:
					if (prwin >= 0.127) return true;
					break;
				case 7:
					if (prwin >= 0.077) return true;
					break;
				case 8:
					if (prwin >= 0.0448) return true;
					break;
				case 9:
					if (prwin >= 0.0237) return true;
					break;
				}
				return false;


			}
			if (Pot <= 20) {

				//min hand JdAh 5hQh4h 9cJs
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.721) return true;
					break;
				case 3:
					if (prwin >= 0.523) return true;
					break;
				case 4:
					if (prwin >= 0.374) return true;
					break;
				case 5:
					if (prwin >= 0.264) return true;
					break;
				case 6:
					if (prwin >= 0.182) return true;
					break;
				case 7:
					if (prwin >= 0.122) return true;
					break;
				case 8:
					if (prwin >= 0.083) return true;
					break;
				case 9:
					if (prwin >= 0.0533) return true;
					break;
				}
				return false;



			}
			if (Pot <= 45) {
				//min hand 4cAs Ac9h8s 9d5s
				switch (Table->ActivePlayer) {
				case 2:
					if (prwin >= 0.801) return true;
					break;
				case 3:
					if (prwin >= 0.644) return true;
					break;
				case 4:
					if (prwin >= 0.51) return true;
					break;
				case 5:
					if (prwin >= 0.4) return true;
					break;
				case 6:
					if (prwin >= 0.311) return true;
					break;
				case 7:
					if (prwin >= 0.236) return true;
					break;
				case 8:
					if (prwin >= 0.178) return true;
					break;
				case 9:
					if (prwin >= 0.129) return true;
					break;
				}
				return false;



			}
			//min hand Kc9h 7s8cKh JsQc
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.841) return true;
				break;
			case 3:
				if (prwin >= 0.712) return true;
				break;
			case 4:
				if (prwin >= 0.602) return true;
				break;
			case 5:
				if (prwin >= 0.506) return true;
				break;
			case 6:
				if (prwin >= 0.424) return true;
				break;
			case 7:
				if (prwin >= 0.353) return true;
				break;
			case 8:
				if (prwin >= 0.293) return true;
				break;
			case 9:
				if (prwin >= 0.245) return true;
				break;
			}
			return false;


		}
		if (BotLastFlopAction == State::Call) {
			//min hand AhAs 2hKc8s 2c4d
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.892) return true;
				break;
			case 3:
				if (prwin >= 0.801) return true;
				break;
			case 4:
				if (prwin >= 0.715) return true;
				break;
			case 5:
				if (prwin >= 0.631) return true;
				break;
			case 6:
				if (prwin >= 0.558) return true;
				break;
			case 7:
				if (prwin >= 0.489) return true;
				break;
			case 8:
				if (prwin >= 0.425) return true;
				break;
			case 9:
				if (prwin >= 0.362) return true;
				break;
			}
			return false;


		}
	}
	if (BotLastTurnAction == State::Call){
		if (Pot <= 25) {
			//min hand TsTc 5d3d7d 5h9s
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.795) return true;
				break;
			case 3:
				if (prwin >= 0.633) return true;
				break;
			case 4:
				if (prwin >= 0.499) return true;
				break;
			case 5:
				if (prwin >= 0.389) return true;
				break;
			case 6:
				if (prwin >= 0.303) return true;
				break;
			case 7:
				if (prwin >= 0.232) return true;
				break;
			case 8:
				if (prwin >= 0.177) return true;
				break;
			case 9:
				if (prwin >= 0.13) return true;
				break;
			}
			return false;





		}
		if (Pot <= 45) {
			//min hand Qd9c 6cTd7h TsQh
			switch (Table->ActivePlayer) {
			case 2:
				if (prwin >= 0.84) return true;
				break;
			case 3:
				if (prwin >= 0.71) return true;
				break;
			case 4:
				if (prwin >= 0.597) return true;
				break;
			case 5:
				if (prwin >= 0.493) return true;
				break;
			case 6:
				if (prwin >= 0.411) return true;
				break;
			case 7:
				if (prwin >= 0.337) return true;
				break;
			case 8:
				if (prwin >= 0.274) return true;
				break;
			case 9:
				if (prwin >= 0.221) return true;
				break;
			}
			return false;




		}
		//min hand AhAs 2hKc8s 2c4d
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.892) return true;
			break;
		case 3:
			if (prwin >= 0.801) return true;
			break;
		case 4:
			if (prwin >= 0.715) return true;
			break;
		case 5:
			if (prwin >= 0.631) return true;
			break;
		case 6:
			if (prwin >= 0.558) return true;
			break;
		case 7:
			if (prwin >= 0.489) return true;
			break;
		case 8:
			if (prwin >= 0.425) return true;
			break;
		case 9:
			if (prwin >= 0.362) return true;
			break;
		}
		return false;




	}
	if (Pot <= 20) {
		//min hand 9d9s QhJdTs 3s4c
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.567) return true;
			break;
		case 3:
			if (prwin >= 0.313) return true;
			break;
		case 4:
			if (prwin >= 0.168) return true;
			break;
		case 5:
			if (prwin >= 0.084) return true;
			break;
		case 6:
			if (prwin >= 0.0375) return true;
			break;
		case 7:
			if (prwin >= 0.0128) return true;
			break;
		case 8:
			if (prwin >= 0.00101) return true;
			break;
		case 9:
			if (prwin >= -0.00511) return true;
			break;
		}
		return false;




	}
	if (Pot <= 30) {
		//min hand 4dJc JsTs3s 7h6c
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.747) return true;
			break;
		case 3:
			if (prwin >= 0.559) return true;
			break;
		case 4:
			if (prwin >= 0.417) return true;
			break;
		case 5:
			if (prwin >= 0.304) return true;
			break;
		case 6:
			if (prwin >= 0.222) return true;
			break;
		case 7:
			if (prwin >= 0.159) return true;
			break;
		case 8:
			if (prwin >= 0.114) return true;
			break;
		case 9:
			if (prwin >= 0.0757) return true;
			break;
		}
		return false;




	}
	if (Pot <= 40) {
		//min hand 9sQd 9h5s4s 6h5c
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.79) return true;
			break;
		case 3:
			if (prwin >= 0.627) return true;
			break;
		case 4:
			if (prwin >= 0.497) return true;
			break;
		case 5:
			if (prwin >= 0.389) return true;
			break;
		case 6:
			if (prwin >= 0.299) return true;
			break;
		case 7:
			if (prwin >= 0.232) return true;
			break;
		case 8:
			if (prwin >= 0.176) return true;
			break;
		case 9:
			if (prwin >= 0.133) return true;
			break;
		}
		return false;



	}
	if (Pot <= 50) {
		//min hand AhKs Ad6d6s QdKh
		switch (Table->ActivePlayer) {
		case 2:
			if (prwin >= 0.832) return true;
			break;
		case 3:
			if (prwin >= 0.698) return true;
			break;
		case 4:
			if (prwin >= 0.572) return true;
			break;
		case 5:
			if (prwin >= 0.478) return true;
			break;
		case 6:
			if (prwin >= 0.387) return true;
			break;
		case 7:
			if (prwin >= 0.315) return true;
			break;
		case 8:
			if (prwin >= 0.251) return true;
			break;
		case 9:
			if (prwin >= 0.2) return true;
			break;
		}
		return false;




	}

	//min hand KdJs JcAdTh Qs9c
	switch (Table->ActivePlayer) {
	case 2:
		if (prwin >= 0.862) return true;
		break;
	case 3:
		if (prwin >= 0.744) return true;
		break;
	case 4:
		if (prwin >= 0.636) return true;
		break;
	case 5:
		if (prwin >= 0.536) return true;
		break;
	case 6:
		if (prwin >= 0.451) return true;
		break;
	case 7:
		if (prwin >= 0.373) return true;
		break;
	case 8:
		if (prwin >= 0.306) return true;
		break;
	case 9:
		if (prwin >= 0.247) return true;
		break;
	}
	return false;

};






bool Player::Allin_OK(){ 
	if (mystack <= 0.2 * Table->PotSize && prwin >= .7)return true;

	return false; 

};
void Player::set_writehand(int numhand,bool bShowCards) {
	if (myname != "Player0")return;
	writehand = true;
	Table->showhandnumber = false;
	Table->NumberOfSimulation = 100000000;
	if (numhand > 0) {
		bDebug = true;
		onlyneedhands = true;
		num_hand++;
		num_hand < numhand? need_more_hand = true: need_more_hand = false;

		if (bShowCards) {
			ofstream a;
			a.open("txt/Writehand.txt", ios::app);
			mycards.insert(4, " ");
			string line = to_string(Table->Handnumber) + ", " + mycards + ", " + to_string(Pot) + ", " + to_string(prwin) + " , preflop: " + State_to_String(BotLastPreflopAction) + " , flop: " + State_to_String(BotLastFlopAction) + " , turn: " + State_to_String(BotLastTurnAction);
			if(volteSituazione>0)line+= " (" + to_string(volteSituazione) + " - " + to_string(volteAzione) + " % " + to_string(volteAzione / volteSituazione)+ ")";

			/*
			line += "\n    ";
			line += "if(";
			line += "Pot <= " + to_string(Pot);
			line += " && prwin >= " + to_string(prwin);
			line += " && Table->ActivePlayer == " + to_string(Table->ActivePlayer);

			//line += "Position == " + Position_to_String(Position) + " && ";
			//line += "BotLastAction == State::" + State_to_String(BotLastAction) + " && ";
			if (Table->BetRound >= 1)line += " && BotLastPreflopAction == State::" + State_to_String(BotLastPreflopAction);
			if (Table->BetRound >= 2)line += " && BotLastFlopAction == State::" + State_to_String(BotLastFlopAction);
			if (Table->BetRound >= 3)line += " && BotLastTurnAction == State::" + State_to_String(BotLastTurnAction);
			//line += "StackSize >= " + to_string(StackSize)+")return true;";
			line += ")return true;//"+ mycards+"\n\n";
			*/
			WriteHandString.push_back({ prwin,line });
			
			a << line << endl;
			a.close();

		}

	}

}
void Player::Manual_Prwin(double lastprwin) {	
	//reset txt
	if (hands == 0) {
		ofstream a;
		a.open("prvPRWIN.txt");
		a.close();


	}
	//count opportunity
	hands++;	

	if (hands >= 100 || Table->Handnumber >=10000)
	{
		cout << "100 hands raggiunte, FINITO!\nmin prwin >= " << temp_prwin<<endl;
		prwin_calcolator* calc = new prwin_calcolator;
		calc->GetPrwinAuto("txt/MINprwinC++.txt", "txt/MINprwinOPPL.txt", card1, card2, card3, card4, card5, card6, card7);
		delete calc;
		exit(0);
	}
	if (prwin > temp_prwin) return;
	if (prwin < fold_prwin) return;
	if (Table->ActivePlayer != 2) return;
	//ignore if

	if (lastprwin != 0 && prwin > lastprwin)return;





	cout << "\n---------\nhands " << hands<<endl;
	cout << "min prwin >= " << temp_prwin << endl << endl;
	cout << "\nbetround: " << Table->BetRound;
	cout << "\n BotLastPreflopAction: " << State_to_String(BotLastPreflopAction);
	cout << "\n BotLastFlopAction: " << State_to_String(BotLastFlopAction);
	cout << "\n BotLastTurnAction: " << State_to_String(BotLastTurnAction);
	cout << "\n BotLastRiverAction: " << State_to_String(BotLastRiverAction) << endl;

	cout <<"NumberOfSuit: "<< NumberOfSuit<< endl;
	cout << "\nToCall: " << ToCall;
	cout << "\nprwin: " << prwin;
	cout << "\nPot: " << Pot;
	cout <<endl<< get_mycards()<<endl;


	ofstream a;
	a.open("prvPRWIN.txt", ios::app);
		

		int decision = 10;

		if (prwin < temp_prwin)cin >> decision;
		if (decision == 1) {
			a << prwin << endl;
			a << get_mycards() << endl;
			a << "min prwin >= " << temp_prwin << endl;
			card1 = mycard[0];
			card2 = mycard[1];
			card3 = mycard[2];
			card4 = mycard[3];
			card5 = mycard[4];
			card6 = mycard[5];
			card7 = mycard[6];

			temp_prwin = prwin;


		}
		else {
			fold_prwin = prwin;
		} 




		a.close();
};
void Player::set_need_minhand(int numhand){
	if (numhand > 0) {
		onlyneedhands = true;
		num_hand++;
		num_hand <= numhand ? need_more_hand = true : need_more_hand = false;
	}

}
void Player::updateGameNumber(std::string& line, int newGameNumber) {
	std::string gameNumberStr = std::to_string(newGameNumber);

	// Trovare la posizione della stringa "#Game No : "
	std::string gameNoPrefix = "#Game No : ";
	size_t pos = line.find(gameNoPrefix);
	if (pos != std::string::npos) {
		// Trova la fine del prefisso "#Game No : "
		size_t start = pos + gameNoPrefix.length();

		// Trova la lunghezza del numero esistente
		size_t end = line.find_first_not_of("0123456789", start);
		if (end == std::string::npos) {
			end = line.length();
		}

		// Sostituisci il vecchio numero con il nuovo numero
		line.replace(start, end - start, gameNumberStr);
	}

	// Trovare la posizione della stringa "#Game No : "
	gameNoPrefix = "for Game ";
	pos = line.find(gameNoPrefix);
	if (pos != std::string::npos) {
		// Trova la fine del prefisso "#Game No : "
		size_t start = pos + gameNoPrefix.length();

		// Trova la lunghezza del numero esistente
		size_t end = line.find_first_not_of("0123456789", start);
		if (end == std::string::npos) {
			end = line.length();
		}

		// Sostituisci il vecchio numero con il nuovo numero
		line.replace(start, end - start, gameNumberStr);
	}

}
bool Player::PotRange(int _min, int _max) {

	if (Pot >= _min && Pot <= _max) return true;
	return false;
};
bool Player::StackRange(int _min, int _max) {

	//if (mystack >= _min && mystack <= _max) return true;
	return false;

};
bool Player::PrwinRange(float _min, float _max) {
	if (prwin >= _min && prwin <= _max) return true;
	return false;

};

void Player::ContaAzione(int _pot, double _prwin, int nPLayers) {





};

void sortDescending(double arr[], int size) {
	// Utilizza std::sort con una funzione lambda per l'ordinamento decrescente
	std::sort(arr, arr + size, [](int a, int b) {
		return a > b; // Ordina in ordine decrescente
		});
}
void Player::freq_calc(double _targetfreq) {
	if (myname != "Player0") return;
#define macro(players)	{totvolte[players]++;\
	double test = 0.00;\
	for (int i = 0; i < 1000; i++) {\
		needprwin[players][i] = test;\
		if (prwin >= test)volte[players][i]++;\
		test += 0.001;\
	}\
	}


	if (_targetfreq > 0)targetfreq = _targetfreq;
	freqcalc = true;
	switch (Table->ActivePlayer) {
	case 2:
		macro(2);
		break;
	case 3:
		macro(3);
		break;
	case 4:
		macro(4);
		break;
	case 5:
		macro(5);
		break;
	case 6:
		macro(6);
		break;
	case 7:
		macro(7);
		break;
	case 8:
		macro(8);
		break;
	case 9:
		macro(9);
		break;
	}


};
int Player::GetBestDecision() {
	return choose_decision(Table->p);


}
