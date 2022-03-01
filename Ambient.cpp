#include "Main.h"

#include "prwin_calcolator.h"

using namespace std;


void Ambient::start_simulation(int _nPlayers, int _NumberOfSimulation) {
	_NumberOfSimulation == 0 ? NumberOfSimulation = 10000000 : NumberOfSimulation = _NumberOfSimulation;

	nPlayers = _nPlayers;

	if (nPlayers > SeatsMaxNumber) { nPlayers = SeatsMaxNumber; }
	if (nPlayers < 2) { nPlayers = 2; }



	set_startitng_position();
	load_last_handumber();
	set_pointers();


	set_game_type();
	set_initial_player_var();



	for (int i = 0; i < NumberOfSimulation; i++) {
		//if(Handnumber%1000 == 0) cout << Handnumber << endl;
		cout << Handnumber << endl;
		rebuy_options();

		start_hand();

		if (nPlayers == 1) { Tournament_Finish(); break; };
		



	};

	save_last_handumber();


};
void Ambient::start_hand() {

	HandReset();
	players_handreset();


	if (nPlayers == 1) { return; }
	handhistory_new_hand();

	if (bTournament) { Ante(); }
	Preflop();
	Handplay();
	goto_betround();

}

void Ambient::MixDeck(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river)
{	

	int Numero = 0;

	ShuffledDeck[0] = _pCard1;
	ShuffledDeck[1] = _pCard2;
	ShuffledDeck[2] = _flop1;
	ShuffledDeck[3] = _flop2;
	ShuffledDeck[4] = _flop3;
	ShuffledDeck[5] = _turn;
	ShuffledDeck[6] = _river;



	int indice = 2;
	if (_pCard1 == "") { indice = 0; }
	else if (_flop1 != "") { indice = 5; }
	else if (_turn != "") { indice = 6; }
	else if (_river != "") { indice = 7; };



	for (int i = indice; i < ((nPlayers * 2) + 5); i++)
	{
		Numero = rand() % 52;
		ShuffledDeck[i] = NewDeck[Numero];

		for (int j = 0; j < i; j++) {
			if (ShuffledDeck[i] == ShuffledDeck[j]) { i--; break; }
		}

	}


};


void Ambient::HandReset() {
	if (bTournament == true) { TournamentSpeed++; };

	Handnumber++;
	BetRound = 0;
	PotSize = 0;
	BetSize = 0;
	MaxInvested = 0;
	Calls = 0;
	Folds = 0;
	Raises = 0;
	Bets = 0;
	Allins = 0;
	StillToAct = 0;
	Checks = 0;
	PlayersInHand = 0;
	MaxStrenght = 0;
	NumberOfWinners = 0;
	Prize = 0;
	BetRefound = 0;

	SBPosition++;
	BBPosition++;
	MiddlePosition2++;
	MiddlePosition3++;
	COPosition++;
	ButtonPosition++;

	if (nPlayers > 6) {
		EarlyPosition1++,
		EarlyPosition2++;
		MiddlePosition1++;
	}
	isSimulation = false;

	HHline = "";
	MixDeck();

	set_BlindsPosition();

};
void Ambient::players_handreset() {

	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Out || p[i].mystack == 0) { nPlayers--; continue; }
		p[i].handreset();
		p[i].myposition = i;
		p[i].set_position();
	};

}
bool Ambient::NewOrbit() {
	set_PlayersInHand();

	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] != BetSize && PlayersInHand <= 1 && *PlayersState[i] == State::Check) { return true; }
		if (*PlayersState[i] == State::null) { return true; };
		if (*PlayersState[i] == State::None) { return true; };
		if (*PlayersBet[i] != BetSize && (*PlayersState[i] == State::Check || *PlayersState[i] == State::Call || *PlayersState[i] == State::Raise || *PlayersState[i] == State::Bet || *PlayersState[i] == State::Blinds)) {return true;}
		
		

	};


	BetRound++;
	return false;

};
bool Ambient::IgnorePlayer(int _index) {
	if (*PlayersState[_index] == State::null) { return false; };


	if (*PlayersStack[_index] == 0) { return true; };

	if (*PlayersState[_index] == State::Fold || 
		*PlayersState[_index] == State::Allin ||
		*PlayersState[_index] == State::Call_Allin ||
		*PlayersState[_index] == State::Forced_Allin) { return true; };







	if (*PlayersBet[_index] == BetSize) {
		if (*PlayersState[_index] == State::Call  ||
			*PlayersState[_index] == State::Check ||
			*PlayersState[_index] == State::Raise ||
			*PlayersState[_index] == State::Bet ) { return true; };
		if (*PlayersPosition[_index] == BBPosition && PlayersInHand <= 1) { return true; }
	};





	

	return false;

};

void Ambient::set_startitng_position() {

	if (nPlayers > 6) {

		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = 2;
		EarlyPosition2 = 3;
		MiddlePosition1 = 4;
		MiddlePosition2 = 5;
		MiddlePosition3 = 6;
		COPosition = 7;
		ButtonPosition = 8;
	}
	else {
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = 2;
		MiddlePosition3 = 3;
		COPosition = 4;
		ButtonPosition = 5;


	}


};
void Ambient::set_BlindsPosition() {

	if (SBPosition == nPlayers) { SBPosition = 0; }
	if (BBPosition == nPlayers) { BBPosition = 0; }
	if (EarlyPosition1 == nPlayers) { EarlyPosition1 = 0; }
	if (EarlyPosition2 == nPlayers) { EarlyPosition2 = 0; }
	if (MiddlePosition1 == nPlayers) { MiddlePosition1 = 0; }
	if (MiddlePosition2 == nPlayers) { MiddlePosition2 = 0; }
	if (MiddlePosition3 == nPlayers) { MiddlePosition3 = 0; }
	if (COPosition == nPlayers) { COPosition = 0; }
	if (ButtonPosition == nPlayers) { ButtonPosition = 0; }
	

	if (nPlayers == 2) { ButtonPosition = SBPosition; };

	

};
void Ambient::set_PlayersInHand() {
	Calls = 0;
	Folds = 0;
	Raises = 0;
	Checks = 0;
	Allins = 0;
	Bets = 0;
	StillToAct = -1;
	PlayersInHand = 0;
	MaxInvested = 0;
	ActivePlayer = 0;

	for (int i = 0; i < nPlayers; i++) {

		if (*PlayersState[i] == State::None) { StillToAct++; PlayersInHand++; ActivePlayer++; };
		if (*PlayersState[i] == State::Blinds) { StillToAct++; PlayersInHand++; ActivePlayer++;	};
		if (*PlayersState[i] == State::null) { ActivePlayer++; PlayersInHand++; };
		if (*PlayersState[i] == State::Fold) { Folds++; };
		if (*PlayersState[i] == State::Check) { ActivePlayer++; Checks++; PlayersInHand++; };
		if (*PlayersState[i] == State::Call) { ActivePlayer++; Calls++; PlayersInHand++; };
		if (*PlayersState[i] == State::Bet)  { ActivePlayer++; Raises++; PlayersInHand++; };
		if (*PlayersState[i] == State::Raise) { ActivePlayer++; Raises++; PlayersInHand++; };
		if (*PlayersState[i] == State::Allin) { ActivePlayer++; Raises++; Allins++; };
		if (*PlayersState[i] == State::Call_Allin) { ActivePlayer++; Allins++; PlayersInHand--; };
		if (*PlayersState[i] == State::Forced_Allin) { ActivePlayer++; Allins++; PlayersInHand--; };
		if (*PlayersInvested[i] > MaxInvested) { MaxInvested = *PlayersInvested[i]; };
	}



}
void Ambient::set_Blind_Level() {
	//double blinds
	if (TournamentSpeed == IncreaseBlindEveryHand) {
		BBsize = BBsize * 2;
		SBsize = SBsize * 2;
		ANTEsize = ANTEsize * 2;
		TournamentSpeed = 0;
	}


}
void Ambient::set_Pot() {
	set_PlayersInHand();

	PotSize = 0;
	for (int i = 0; i < nPlayers; i++) {

		PotSize += *PlayersInvested[i];

	};



	set_BetSize();


};
void Ambient::set_BetSize() {
	if (PlayersInHand == 2 && *PlayersBet[SBPosition] > SBsize && *PlayersBet[SBPosition] < BBsize) { BetSize = *PlayersBet[SBPosition]; return; }

	BetSize = 0;

	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] >= BetSize) { BetSize = *PlayersBet[i]; }

	};


};
void Ambient::set_game_type() {
	if (bTournament == true) {
		ANTEsize = 2;
		SBsize = 5;
		BBsize = 10;
		IncreaseBlindEveryHand = 10;
		PlayersStartingStack = 3000;
	}
	else
	{
		ANTEsize = 0;
		SBsize = 1;
		BBsize = 2;

		PlayersStartingStack = 200;
	}
}
void Ambient::set_pointers() {

	for (int i = 0; i - nPlayers; i++) {
		
		p[i].BetRound = &BetRound;
		p[i].PotSize = &PotSize;
		p[i].BBsize = &BBsize;
		p[i].SBsize = &SBsize;
		p[i].ANTEsize = &ANTEsize;
		p[i].BetSize = &BetSize;
		p[i].Handnumber = &Handnumber;
		p[i].nPlayers = &nPlayers;
		p[i].ActivePlayer = &ActivePlayer;

		p[i].ButtonPosition = &ButtonPosition;
		p[i].SBPosition = &SBPosition;
		p[i].BBPosition = &BBPosition;
		p[i].EarlyPosition1 = &EarlyPosition1;
		p[i].EarlyPosition2 = &EarlyPosition2;
		p[i].MiddlePosition1 = &MiddlePosition1;
		p[i].MiddlePosition2 = &MiddlePosition2;
		p[i].MiddlePosition3 = &MiddlePosition3;
		p[i].COPosition = &COPosition;



		p[i].Calls = &Calls;
		p[i].Folds = &Folds;
		p[i].Raises = &Raises;
		p[i].Bets = &Bets;
		p[i].Allins = &Allins;
		p[i].Checks = &Checks;
		p[i].PlayersInHand = &PlayersInHand;
		p[i].StillToAct = &StillToAct;

	}

	for (int i = 0; i - nPlayers; i++) {
		PlayersStack[i] = &p[i].mystack;
		PlayersPosition[i] = &p[i].myposition;
		PlayersBet[i] = &p[i].mybet;
		PlayersName[i] = &p[i].myname;
		PlayersState[i] = &p[i].mystate;
		PlayersInvested[i] = &p[i].TotalInvested;
		PlayersStrenght[i] = &p[i].HandStrength;

		for (int j = 0; j - nPlayers; j++) {
			p[j].PlayersStack[i] = &p[i].mystack;
			p[j].PlayersPosition[i] = &p[i].myposition;
			p[j].PlayersBet[i] = &p[i].mybet;
			p[j].PlayersName[i] = &p[i].myname;
			p[j].PlayersState[i] = &p[i].mystate;
			p[j].PlayersInvested[i] = &p[i].TotalInvested;
		}

	}

	int indicemazzo = 0;
	for (int i = 0; i - nPlayers; i++) {
		p[i].MyCards[0] = &ShuffledDeck[indicemazzo];
		indicemazzo++;
		p[i].MyCards[1] = &ShuffledDeck[indicemazzo];
		indicemazzo++;
	}
	//player postflop card
	for (int i = 0; i - nPlayers; i++) {
		p[i].MyCards[2] = &ShuffledDeck[indicemazzo];
		p[i].MyCards[3] = &ShuffledDeck[(indicemazzo + 1)];
		p[i].MyCards[4] = &ShuffledDeck[(indicemazzo + 2)];
		p[i].MyCards[5] = &ShuffledDeck[(indicemazzo + 3)];
		p[i].MyCards[6] = &ShuffledDeck[(indicemazzo + 4)];
	}
	indicemazzo = 0;

	for (int i = 0; i - nPlayers; i++) {
		for (int j = 0; j - 52; j++) {
			p[i].ShuffledDeck[j] = &ShuffledDeck[j];
		}
	}
};
void Ambient::set_initial_player_var() {


	for (int i = 0; i < nPlayers; i++) {
		p[i].myseat = (i + 1);
		p[i].myposition = (i - 1);
		p[i].myname = "Player" + to_string(i);
		p[i].mystate = State::null;
		p[i].mystack = PlayersStartingStack;

	}

};



void Ambient::HandHistory(string _text) {
	if (bHandHistory) {
		HHline += _text + "\n";
	}
}
void Ambient::handhistory_player_action(int i) {

	
	switch (p[i].mystate)
	{
		case State::Blinds:
			if (bTournament) {

				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [" + to_string(p[i].mybet) + "]"); }
				if (p[i].inBigBlind) {
					if (p[SBPosition].mystack == 0 && PlayersInHand == 0) {
						p[i].mybet = p[SBPosition].mybet;
						p[i].UpdateMyStack();
					}
					HandHistory(p[i].myname + " posts big blind [" + to_string(p[i].mybet) + "]");
					HandHistory("** Dealing down cards **");
					HandHistory("Dealt to " + p[0].myname + " [ " + *p[0].MyCards[0] + ", " + *p[0].MyCards[1] + " ]");

				}
			}
			else {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [€" + to_string(p[i].mybet) + "]"); }
				if (p[i].inBigBlind) {
					if (p[SBPosition].mystack == 0 && PlayersInHand == 0) {
						p[i].mybet = p[SBPosition].mybet;
						p[i].UpdateMyStack();
					}
					HandHistory(p[i].myname + " posts big blind [€" + to_string(p[i].mybet) + "]");
					HandHistory("** Dealing down cards **");
					HandHistory("Dealt to " + p[0].myname + " [ " + *p[0].MyCards[0] + ", " + *p[0].MyCards[1] + " ]");


				}
			}
			break;

		case State::Forced_Allin:
			if (bTournament) {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [" + to_string(p[i].mybet) + "]"); }
				else if (p[i].inBigBlind) { HandHistory(p[i].myname + " posts big blind [" + to_string(p[i].mybet) + "]"); }
			}
			else {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [€" + to_string(p[i].mybet) + "]"); }
				else if (p[i].inBigBlind) { HandHistory(p[i].myname + " posts big blind [€" + to_string(p[i].mybet) + "]"); }

			};			
			break;
		case State::Fold:
			HandHistory(p[i].myname + " folds");
			break;

		case State::Call_Allin:
			if (bTournament) {
				HandHistory(p[i].myname + " calls [" + to_string(p[i].AmountToCall) + "]");
			}
			else {
				HandHistory(p[i].myname + " calls [€" + to_string(p[i].AmountToCall) + "]");
			};

			break;
		case State::Call:
			if (bTournament) {
				HandHistory(p[i].myname + " calls [" + to_string(p[i].AmountToCall) + "]");
			}
			else {
				HandHistory(p[i].myname + " calls [€" + to_string(p[i].AmountToCall) + "]");
			}
			break;
		case State::Bet:
			if (bTournament) {
				HandHistory(p[i].myname + " bets [" + to_string(p[i].myraise) + "]");
			}
			else {
				HandHistory(p[i].myname + " bets [€" + to_string(p[i].myraise) + "]");

			}
			break;
		case State::Raise:
			if (bTournament) {
				HandHistory(p[i].myname + " raises [" + to_string(p[i].myraise) + "]");
			}
			else {
				HandHistory(p[i].myname + " raises [€" + to_string(p[i].myraise) + "]");

			}
			break;
		case State::Allin:
			if (bTournament) {
				HandHistory(p[i].myname + " raises [" + to_string(p[i].myraise) + "]");
			}
			else {
				HandHistory(p[i].myname + " raises [€" + to_string(p[i].myraise) + "]");

			}

			break;
		case State::Check:
			HandHistory(p[i].myname + " checks");
			break;

	}

};
void Ambient::handhistory_new_hand() {
	int Table = 0;

	if (nPlayers == 2) { Table = 2; };
	if (nPlayers > 2) { Table = 6; };
	if (nPlayers > 6) { Table = 9; };
	

	if (bTournament == true) {
		HandHistory("#Game No : " + to_string(Handnumber));
		HandHistory("***** 888.it Hand History for Game " + to_string(Handnumber) + " *****");
		HandHistory(to_string(SBsize) + "/" + to_string(BBsize) + " Blinds No Limit Holdem - *** 04 06 2018 22:42:38");
		HandHistory("Tournament #0 Free - Table #0 " + to_string(Table) + " Max (Real Money)");
		for (int i = 0; i < nPlayers; i++) {
			if (p[i].inButton) { HandHistory("Seat " + to_string(p[i].myseat) + " is the button"); 
			break;
			}
		}
		HandHistory("Total number of players : " + to_string(nPlayers));
		for (int i = 0; i < nPlayers; i++) {
			HandHistory("Seat " + to_string(p[i].myseat) + ": " + p[i].myname + " ( " + to_string(p[i].mystack) + " )");
		}
	}
	if (bTournament == false) {
		HandHistory("#Game No : " + to_string(Handnumber));
		HandHistory("***** 888.it Hand History for Game " + to_string(Handnumber) + " *****");
		HandHistory("€" + to_string(SBsize) + "/€" + to_string(BBsize) + " Blinds No Limit Holdem - *** 01 01 2021 00:00:00");
		HandHistory("Table EDD " + to_string(Table) + " Max(Real Money)");
		for (int i = 0; i < nPlayers; i++) {
			if (p[i].inButton) { 
				HandHistory("Seat " + to_string(p[i].myseat) + " is the button"); 
				break; 
			}
		}
		HandHistory("Total number of players : " + to_string(nPlayers));
		for (int i = 0; i < nPlayers; i++) {
			HandHistory("Seat " + to_string(p[i].myseat) + ": " + p[i].myname + " ( €" + to_string(p[i].mystack) + " )");
		}
	}
};
void Ambient::handhistory_finish() {
	HandHistory("\n");
	if (!SingleSituation) {			
		ofstream hand;
		hand.open(HH_File, ios::app);
		hand << HHline;
		hand.close();		
		return;}
	else {

		if (p[0].writehand) {
			p[0].writehand = false;

			ofstream hand;
			hand.open(HH_File, ios::app);
			hand << HHline;
			hand.close();
		
		}


	}
		

		
};


void Ambient::create_players(int _nPlayers) {

	//Player* p = new Player[_nPlayers];


}

void Ambient::load_last_handumber() {
	string nHand;
	ofstream write;

	hand.open("HandNumber.txt");

	if (hand) {
		getline(hand, nHand);
	}else
	{	write.open("HandNumber.txt");
		write << 0;
		write.close();
		hand.open("HandNumber.txt");
		getline(hand, nHand);
	}

	Handnumber = stoi(nHand);
	hand.close();

	//clear old handlog file
	if (bHandHistory) {
		ofstream hand2;
		hand2.open(HH_File);
		hand2.close();

		hand2.open("Player0_LOG.txt");
		hand2.close();

		if (SingleSituation) {
			hand2.open("SingleSituation.txt");
			hand2.close();
		}
	}

};
void Ambient::save_last_handumber() {
	if (!SaveLastHandNumber) {
		Handnumber = 0;
	}
	
	handN.open("HandNumber.txt");
	handN << Handnumber;
	handN.close();
}



void Ambient::Ante() {
	BetRound = 0;
	for (int i = 0; i < nPlayers; i++) {
		p[i].post_ANTE();
		HandHistory(p[i].myname + " posts ante [" + to_string(p[i].mybet) + "]");
	}
	set_Pot();

};
void Ambient::Preflop() {
	if (!isSimulation)set_Preflop_PlayerVar();
	Handplay();
	goto_betround();
};
void Ambient::Flop() {
	BetRound = 2;
	HandHistory("** Dealing flop ** [ " + *p[0].MyCards[2] + ", " + *p[0].MyCards[3] + ", " + *p[0].MyCards[4] + " ]");
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(), Turn(); return; };
	if (!isSimulation)reset_players_state();
	Handplay();
	goto_betround();


};
void Ambient::Turn() {
	BetRound = 3;

	HandHistory("** Dealing turn ** [ " + *p[0].MyCards[5] + " ]");
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(), River(); return; };
	if (!isSimulation)reset_players_state();
	Handplay();
	goto_betround();

};
void Ambient::River() {
	BetRound = 4;
	HandHistory("** Dealing river ** [ " + *p[0].MyCards[6] + " ]");
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(); Showdown(); return; };
	if (!isSimulation) reset_players_state();
	if (PlayersInHand > 1) {
		Handplay();
		goto_betround();
	}

};
void Ambient::Showdown() {
	HandHistory("** Summary **");
	BetRound = 5;

	remove_from_pot();
	set_Winners();
	handhistory_finish();

};
void Ambient::Handplay() {
	int i = 0;
	
	if (isSimulation) {i = index; isSimulation = false;}
	else { i = SBPosition; }

	for (i ; i <= nPlayers; i++) {
		if (i == nPlayers) { i = 0; }
		if (i == SBPosition && !NewOrbit()) { break; }
		if (IgnorePlayer(i)) { continue; }

		p[i].MyTurn(p);


		handhistory_player_action(i);
		set_Pot();


	}



};

void Ambient::remove_from_pot() {


	BetRefound = 0;
	nMaxBet = 0;
	maxbet = 0;
	maxbet2 = 0;

	//find max bet
	for (int i = 0; i < nPlayers; i++) {

		if (*PlayersBet[i] > maxbet) { maxbet = *PlayersBet[i]; };
	}
	// find second max bet
	for (int i = 0; i < nPlayers; i++) {

		if (*PlayersBet[i] > maxbet2 && *PlayersBet[i] < maxbet) { maxbet2 = *PlayersBet[i]; };
	}

	//remove refoun from pot
	
	for (int i = 0; i < nPlayers; i++) {

			if (*PlayersBet[i] == maxbet) { nMaxBet++; };
		}
		
	if (nMaxBet == 1) { BetRefound = maxbet - maxbet2; }


	//PotSize -= BetRefound;
	

};
void Ambient::calc_prize() {
	

	if (NumberOfWinners == 1) {
		for (int i = 0; i < nPlayers; i++) {
			if (p[i].HandStrength == MaxStrenght) { p[i].myprize = (PotSize - BetRefound); }
			if (p[i].HandStrength == MaxStrenght && p[i].mybet == maxbet && maxbet2 == 0 && PlayerAtShowdown == 1) { p[i].myprize = (PotSize - p[i].mybet); }
		}
	}


	if (NumberOfWinners > 1) {
		for (int i = 0; i < nPlayers; i++) {
			if (p[i].HandStrength == MaxStrenght) { p[i].myprize = (PotSize / NumberOfWinners); }
		}
	}




	/*
		//calc side winner
		SidePotWinners = 0;
		SidePotWinners2 = 0;


		//get max side pot winner
		for (int i = 0; i < nPlayers; i++) {

			if (p[i].mystack == 0 && p[i].HandStrength == MaxStrenght && p[i].TotalInvested < MaxInvested) {

				SidePotWinners++;
			}
		}
		if (SidePotWinners > 0) {
			//get second max side pot winner
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].mystack == 0 && p[i].HandStrength == MaxStrenght2 && p[i].TotalInvested < MaxInvested) {

					SidePotWinners2++;
				}
			}
		}


		//calc prize for strenght 1
		if (SidePotWinners > 0) {
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].mystate != State::Fold) {
					if (p[i].mystack == 0 && p[i].HandStrength == MaxStrenght && p[i].TotalInvested < MaxInvested && SidePotWinners > 0) { p[i].myprize = ((p[i].TotalInvested * PlayerAtShowdown) / SidePotWinners); }
					SidePot = p[i].myprize;
				};
			}


			//get max invested2
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].TotalInvested > MaxInvested2 && p[i].TotalInvested < MaxInvested) { MaxInvested2 = p[i].TotalInvested; }


			}
		}

		//calc prize for strenght 2
		if (SidePotWinners2 > 0) {
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].mystate != State::Fold) {
					if (p[i].HandStrength == MaxStrenght2 && p[i].TotalInvested < MaxInvested2) { p[i].myprize = ((p[i].TotalInvested * PlayerAtShowdown) / SidePotWinners2); }
				}
			}
		}

		if (SidePotWinners > 0 && SidePotWinners2 == 0) {
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].HandStrength == MaxStrenght2) { p[i].myprize = ((PotSize - SidePot) / NumberOfWinners); }
			}


		}

		if (SidePotWinners == 0 && SidePotWinners2 == 0) {
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].HandStrength == MaxStrenght) { p[i].myprize = (PotSize / NumberOfWinners); };

			}

		}
		*/
};

void Ambient::set_Winners() {

	MaxStrenght = 0;
	NumberOfWinners = 0;
	Prize = 0;
	SidePot = 0;
	SidePotWinners = 0;
	PlayerAtShowdown = 0;

	calc_player_at_showdown();
	players_count_hand_strength();
	calc_max_handstrength();
	calc_number_of_winners();
	calc_prize();
	pay_winners();

}
void Ambient::pay_winners() {

	//hand hystory
	for (int i = 0; i < nPlayers; i++) {
		HandHistory(p[i].myname + " shows [ " + *p[i].MyCards[0] + ", " + *p[i].MyCards[1] + " ]");
	};

	
	//pay winners
	for (int i = 0; i < nPlayers; i++) {
				if (p[i].HandStrength == MaxStrenght && p[i].mystate != State::Fold) {
					p[i].mystack += p[i].myprize;
					p[i].winner = true;
					if (bTournament == true) { HandHistory(p[i].myname + " collected [ " + to_string(p[i].myprize) + " ]"); }
					else { HandHistory(p[i].myname + " collected [ €" + to_string(p[i].myprize) + " ]"); };
			}
		}

	

	//go out loose players
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystack == 0) { p[i].mystate = State::Out;}

	}
}

void Ambient::Tournament_Finish() {


}

void Ambient::calc_player_at_showdown() {

	for (int i = 0; i < nPlayers; i++) {
	
		if (p[i].mystate != State::Fold) { PlayerAtShowdown++; };
	
	
	}


};
void Ambient::calc_number_of_winners() {
	//calc number of winners
	for (int i = 0; i < nPlayers; i++) {
		
		if (*PlayersStrenght[i] == MaxStrenght) { NumberOfWinners++; };
	}


}
void Ambient::calc_max_handstrength() {
	MaxStrenght = -100000;
	MaxStrenght2 = -100000;
	MaxStrenght3 = -100000;

	//calc max strenght
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersStrenght[i] >= MaxStrenght) { MaxStrenght = *PlayersStrenght[i]; };
	};

	//calc second max strenght
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersStrenght[i] < MaxStrenght && *PlayersStrenght[i] > MaxStrenght2) { MaxStrenght2 = *PlayersStrenght[i]; };
	};

	//calc third max strenght
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersStrenght[i] < MaxStrenght2 && *PlayersStrenght[i] > MaxStrenght3) { MaxStrenght3 = *PlayersStrenght[i]; };
	};

};



void Ambient::reset_players_state() {

	for (int i = 0; i < nPlayers; i++) {
		p[i].reset_mybet();
		p[i].reset_mystate();
		p[i].set_mycard();
	};
	set_Pot();

};
void Ambient::goto_betround() {

	switch (BetRound)
	{
	case 1:
		if (PlayersInHand <= 1 && !isSimulation ) { BetRound = 2; goto_betround(); return;	};
		Preflop();
		break;
	case 2:
		Flop(); return;
		break;
	case 3:
		Turn(); return;
		break;
	case 4:
		River(); return;
		break;
	case 5:
		Showdown();  return;
		break;
	default:
		break;
	}


};
void Ambient::set_players_card() {
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Fold) { continue; }
		p[i].set_mycard();

}


};
void Ambient::players_count_hand_strength() {

	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate != State::Fold) {
			p[i].set_HandStrength();
		}

	}

};
void Ambient::set_Preflop_PlayerVar() {


	BetRound = 1;
	//Post Blinds
	for (int i = 0; i < nPlayers; i++) {
		p[i].set_mycard();
		p[i].reset_mybet();
		p[i].set_OpponentsAtTable();

	};

};

void Ambient::rebuy_options() {
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Out) { p[i].mystack = 200; p[i].mystate = State::Fold; };
		if (p[i].mystack <= BBsize*2) { p[i].mystack = 200; p[i].mystate = State::Fold; };
	}


};
void Ambient::set_HandHistory(bool _bool,string _file) {

	HH_File = _file;
	bHandHistory = _bool;

};
