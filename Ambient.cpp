#include "Main.h"
#include "prwin_calcolator.h"
#include "Ambient.h"
#include <random>
#include <set>
#include <unordered_set>
#include <sstream>
using namespace std;
//costruttore
Ambient::Ambient() {
	HH = new HHWriter;
	HH->HH_File = HH_File;

}
//distruttore
Ambient::~Ambient() { 

	delete HH; 
};


void Ambient::simulate_random_nplayers() {
	
	HH->load_last_handumber(Handnumber,SingleSituation, bHandHistory);
	for (int i = 0; i < NumberOfSimulation/100; i++) {
		nPlayers = 2 + rand() % 5;
		if (Handnumber % 1000 == 0)cout << Handnumber<<endl;

		set_startitng_position();		
		set_pointers();
		set_game_type();
		set_initial_player_var();

		for (int j = 0; j < 100; j++) {
				

			//choose if you want to rebuy (incomplete)
			rebuy_options();

			//start effective simulation
			start_hand();

			//break simulation if some conditions
			if (nPlayers == 1) { Tournament_Finish(); break; };
			if (p[0].need_more_hand == false && p[0].onlyneedhands)break;

		};

	}
	cout << "VIP " << p[0].totvolte[0];


};

// Funzione per ordinare un vettore di pair<double, string> in base al double
void Ambient::sortPairsByDouble(vector<pair<double, string>>& pairs) {
	sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
		return a.first < b.first; // Cambia < in > per ordinamento decrescente
		});
}


void Ambient::start_simulation(int _nPlayers, int _NumberOfSimulation) {
	//initialize basic var of simulation
	if (_NumberOfSimulation != 0) NumberOfSimulation = _NumberOfSimulation;
	
	if (TotPlayers <= SeatsMaxNumber)nPlayers = TotPlayers;

	if (nPlayers <= SeatsMaxNumber)nPlayers = SeatsMaxNumber;
	else nPlayers = _nPlayers;
	p.resize(nPlayers);
	


	//check if args is correct
	if (nPlayers < 2) { nPlayers = 2; }

	//initialize blind position
	set_startitng_position();

	//load the last saved hand number, for not duplicate pt hands
	HH->load_last_handumber(Handnumber, SingleSituation, bHandHistory);

	//set pointers to let player and ambient know their status at any time
	set_pointers();

	//set whether tournament or cash from ambient.h var(incomplete)
	set_game_type();

	//initialize players var
	set_initial_player_var();

	
	//play hand for all number of simulations
	for (int i = 0; i < NumberOfSimulation; i++) {
		if (showhandnumber && Handnumber % showhand_frequency == 0) {
			cout << Handnumber<<endl;

		}
		if (p[0].need_more_hand) {
			NumberOfSimulation = 10000000;
			p[0].writehand = false;
		}
		//p[0].need_more_hand ? cout << " mani trovate " << p[0].num_hand << endl : cout << endl;

		//start effective simulation
		start_hand();

		//choose if you want to rebuy (incomplete)
		rebuy_options();


		//break simulation if some conditions
		if (nPlayers <= 1 || p[0].mystate==State::Out) { Tournament_Finish(); break; };
		if (!p[0].need_more_hand && p[0].onlyneedhands)break;

	};
	
	//save the last hand numer if is true in ambient.h
	HH->save_last_handumber(SaveLastHandNumber,Handnumber);

	////////////////////////////////////////////////////////////////////////
	//at the end of simulation temp
	sortPairsByDouble(p[0].WriteHandString);
	ofstream a;
	a.open("txt/Writehand.txt");
	for (const auto& p : p[0].WriteHandString) {
		a << p.second << std::endl;
	}
	a.close();
	//cout << "volte situaizone = " << p[0].volteSituazione << " volte azione = " << p[0].volteAzione << " percenruale = " << p[0].volteAzione / p[0].volteSituazione;
};

void Ambient::SimulateCash(int _nPlayers, int _NumberOfSimulation) {
	PlayersStartingStack = 200;
	doubleBlind = false;
	bTournament = false;
	bNeverGoOut = true;

	start_simulation(_nPlayers, _NumberOfSimulation);

}
int Ambient::Play_Tournament(int i, int _TotPlayers, int _MaxSeatNumber,int _NumberOfSimulation) {
	TotPlayers = _TotPlayers;
	showhandnumber =0;
	bTournament = false;
	doubleBlind = true;
	PlayersStartingStack = 10000;

	cout << "\nStaring tournament n " << i << endl;
	start_simulation(_MaxSeatNumber, _NumberOfSimulation);

	return PlayerPosition;

}

void Ambient::Simulate_Tournaments(){
	double totSimulation = 100;

	double inTheMoney = 0;
	double tothands = 0;
	double VolteResistito = 0;
	ofstream a("tornei.txt");
	for (int i = 0; i < totSimulation; i++) {
		Ambient* simulator = new Ambient;
		if (simulator->Play_Tournament(i, 20) <= 3)inTheMoney++;
		tothands = simulator->Handnumber;
		if (tothands >= 100)VolteResistito++;
		cout << endl<<simulator->LastPlayerHand << endl;

		a << simulator->LastPlayerHand;
		delete simulator;
		//cout << "\nany key to continue.....\n"; getchar();
		}
	a.close();
	cout << "tra i primi 3: "<<inTheMoney / totSimulation << endl;
	cout << "resistito 100 mani: " << VolteResistito / totSimulation << endl;

	exit(0);
}

//play hands for each number of simulations
void Ambient::start_hand() {
	//if remain only one player the game is end
	if (nPlayers == 1) { cout << "Game End!\n"; return; }

	//reset all vars
	HandReset();
	players_handreset();
	if (bTournament || doubleBlind)set_Blind_Level();


	//use here condition like this for simulate only specific hands
	//if (p[0].Position != EPosition::CutOff)return;
	//cout << p[0].Position_to_String(p[0].Position) << endl;


	//start new hand in hand history
	
	HH->handhistory_new_hand(nPlayers,Handnumber,bTournament,SBsize,BBsize,p, bHandHistory);
	
	//put ante in the pot if is tournament
	if (bTournament) { Ante(); }

	//play preflop
	Preflop();

	//play hand
	Handplay();
	goto_betround();

}

//create new deck
void Ambient::MixDeck(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river)
{	
	//create new random deck
	//player 0 always have card 0 and 1
	//postflop card is aways card 2 3 4 5 6 
	//all other cards to other players
	int Numero = 0;

	ShuffledDeck[0] = _pCard1;
	ShuffledDeck[1] = _pCard2;
	ShuffledDeck[2] = _flop1;
	ShuffledDeck[3] = _flop2;
	ShuffledDeck[4] = _flop3;
	ShuffledDeck[5] = _turn;
	ShuffledDeck[6] = _river;

	//ShuffledDeck[0] = "Ac";
	//ShuffledDeck[1] = "Kd";

	//ShuffledDeck[2] = "9c";
	//ShuffledDeck[3] = "Jh";
	//ShuffledDeck[4] = "Ac";


	int indice = 2;
	if (ShuffledDeck[0] == "") { indice = 0; }
	if (ShuffledDeck[2] != "") { indice = 5; }
	if (ShuffledDeck[5] != "") { indice = 6; }
	if (ShuffledDeck[6] != "") { indice = 7; };



	for (int i = indice; i < ((nPlayers * 2) + 5); i++)
	{
		Numero = rand() % 52;
		ShuffledDeck[i] = NewDeck[Numero];

		for (int j = 0; j < i; j++) {
			if (ShuffledDeck[i] == ShuffledDeck[j]) { i--; break; }
		}

	}
	
};

//reset all ambient var
void Ambient::HandReset() {
	//reset all ambient var
	if (bTournament || doubleBlind) { TournamentHandCount++; };
	HHprize = 0;
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
	LastPlayerHand = "";
	PlayerLastStack = 0;
	HH->HHline = "";
	switch (nPlayers) {
	case 2:
		SBPosition++;
		BBPosition++;

		break;
	case 3:
		SBPosition++;
		BBPosition++;
		ButtonPosition++;

		break;
	case 4:
		SBPosition++;
		BBPosition++;
		COPosition++;
		ButtonPosition++;
		break;
	case 5:
		SBPosition++;
		BBPosition++;
		MiddlePosition3++;
		COPosition++;
		ButtonPosition++;
		break;
	case 6:
		SBPosition++;
		BBPosition++;
		MiddlePosition2++;
		MiddlePosition3++;
		COPosition++;
		ButtonPosition++;


		break;
	case 7:
		SBPosition++;
		BBPosition++;
		MiddlePosition1++;
		MiddlePosition2++;
		MiddlePosition3++;
		COPosition++;
		ButtonPosition++;
		break;
	case 8:
		SBPosition++;
		BBPosition++;
		EarlyPosition2++;
		MiddlePosition1++;
		MiddlePosition2++;
		MiddlePosition3++;
		COPosition++;
		ButtonPosition++;
		break;
	case 9:
		SBPosition++;
		BBPosition++;
		EarlyPosition1++;
		EarlyPosition2++;
		MiddlePosition1++;
		MiddlePosition2++;
		MiddlePosition3++;
		COPosition++;
		ButtonPosition++;
		break;


	}
		
	
	MixDeck();

	set_BlindsPosition();

};

//reset all player var
void Ambient::players_handreset() {
	//reset all player var
 	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Out || p[i].mystack == 0)continue;
		p[i].handreset();
		p[i].myposition = i;
		p[i].set_position();
	};

}

//check if some player have to act to make new orbit in hand
bool Ambient::NewOrbit() {
	//check if some player have to act to make new orbit in hand
	set_PlayersInHand();


	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersStack[i] == 0)continue;
		if (*PlayersBet[i] != BetSize && PlayersInHand == 1 && *PlayersState[i] == State::Check) { return true; }
		if (*PlayersState[i] == State::null) { return true; };
		if (*PlayersState[i] == State::None) { return true; };
		if (*PlayersBet[i] != BetSize && (*PlayersState[i] == State::Check || *PlayersState[i] == State::Call || *PlayersState[i] == State::Raise || *PlayersState[i] == State::Bet || *PlayersState[i] == State::Blinds)) {return true;}
		
		

	};


	RoundRaises = 0;
	RoundCalls = 0;
	BetRound++;
	return false;

};
//check if some player shoul be ignored (es allin)
bool Ambient::IgnorePlayer(int _index) {
	//check conditions if have to ignore player
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

//initialize var of position
void Ambient::set_startitng_position() {


	switch (nPlayers){
	case 2:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = -10;
		MiddlePosition3 = -10;
		COPosition = -10;
		ButtonPosition = -10;
		break;
	case 3:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = -10;
		MiddlePosition3 = -10;
		COPosition = -10;
		ButtonPosition = 2;
			break;
	case 4:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = -10;
		MiddlePosition3 = -10;
		COPosition = 2;
		ButtonPosition = 3;
		break;
	case 5:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = -10;
		MiddlePosition3 = 2;
		COPosition = 3;
		ButtonPosition = 4;
		break;
	case 6:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = -10;
		MiddlePosition2 = 2;
		MiddlePosition3 = 3;
		COPosition = 4;
		ButtonPosition = 5;
		break;
	case 7:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = -10;
		MiddlePosition1 = 2;
		MiddlePosition2 = 3;
		MiddlePosition3 = 4;
		COPosition = 5;
		ButtonPosition = 6;
		break;
	case 8:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = -10;
		EarlyPosition2 = 2;
		MiddlePosition1 = 3;
		MiddlePosition2 = 4;
		MiddlePosition3 = 5;
		COPosition = 6;
		ButtonPosition = 7;
		break;
	case 9:
		SBPosition = 0;
		BBPosition = 1;
		EarlyPosition1 = 2;
		EarlyPosition2 = 3;
		MiddlePosition1 = 4;
		MiddlePosition2 = 5;
		MiddlePosition3 = 6;
		COPosition = 7;
		ButtonPosition = 8;
		break;
	
	
	
	
	}
	

};

//set blind position, the first of act is 0
void Ambient::set_BlindsPosition() {
	//set blind position, the first of act is 0

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

//check table state: raises,calls ecc (incomplete)
void Ambient::set_PlayersInHand() {
	reset_action_counts();
	//check table state: raises, calls ecc(incomplete)
	for (int i = 0; i < nPlayers; i++) {

		if (*PlayersState[i] == State::None) { StillToAct++; PlayersInHand++; ActivePlayer++; };
		if (*PlayersState[i] == State::Blinds) { StillToAct++; PlayersInHand++; ActivePlayer++;	};
		if (*PlayersState[i] == State::null) { StillToAct++; ActivePlayer++; PlayersInHand++; };
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

//only for tournament set the blind level
void Ambient::set_Blind_Level() {
	//double blinds
	if (TournamentHandCount == IncreaseBlindEveryHand) {
		BlindLevel++;
		TournamentHandCount = 0;

	//default tournament structure
	//TODO use a realistic formula intesead of switch
		switch (BlindLevel)
		{
		case 1:
			ANTEsize = 3;
			SBsize = 15;
			break;
		case 2:
			ANTEsize = 4;
			SBsize = 30;
			break;
		case 3:
			ANTEsize = 6;
			SBsize = 40;
			break;
		case 4:
			ANTEsize = 8;
			SBsize = 50;
			break;
		case 5:
			ANTEsize = 10;
			SBsize = 60;
			break;
		case 6:
			ANTEsize = 12;
			SBsize = 75;
			break;
		case 7:
			ANTEsize = 20;
			SBsize = 100;
			break;
		case 8:
			ANTEsize = 25;
			SBsize = 125;
			break;
		case 9:
			ANTEsize = 30;
			SBsize = 125;
			break;
		case 10:
			ANTEsize = 40;
			SBsize = 150;
			break;
		case 11:
			ANTEsize = 50;
			SBsize = 200;
			break;
		case 12:
			ANTEsize = 60;
			SBsize = 300;
			break;
		case 13:
			ANTEsize = 70;
			SBsize = 350;
			break;
		case 14:
			ANTEsize = 85;
			SBsize = 400;
			break;
		case 15:
			ANTEsize = 100;
			SBsize = 500;
			break;
		case 16:
			ANTEsize = 125;
			SBsize = 600;
			break;
		case 17:
			ANTEsize = 150;
			SBsize = 700;
			break;
		case 18:
			ANTEsize = 175;
			SBsize = 800;
			break;
		case 19:
			ANTEsize = 200;
			SBsize = 1000;
			break;
		case 20:
			ANTEsize = 250;
			SBsize = 1250;
			break;
		case 21:
			ANTEsize = 300;
			SBsize = 1500;
			break;
		case 22:
			ANTEsize = 375;
			SBsize = 1750;
			break;
		case 23:
			ANTEsize = 425;
			SBsize = 2000;
			break;
		case 24:
			ANTEsize = 500;
			SBsize = 2500;
			break;
		case 25:
			ANTEsize = 625;
			SBsize = 3000;
			break;
		case 26:
			ANTEsize = 750;
			SBsize = 3500;
			break;
		case 27:
			ANTEsize = 875;
			SBsize = 4000;
			break;
		case 28:
			ANTEsize = 1000;
			SBsize = 5000;
			break;
		case 29:
			ANTEsize = 1250;
			SBsize = 6000;
			break;
		case 30:
			ANTEsize = 1500;
			SBsize = 8000;
			break;
		case 31:
			ANTEsize = 2000;
			SBsize = 10000;
			break;
		case 32:
			ANTEsize = 2500;
			SBsize = 12500;
			break;
		case 33:
			ANTEsize = 3125;
			SBsize = 15000;
			break;
		case 34:
			ANTEsize = 3750;
			SBsize = 17500;
			break;
		case 35:
			ANTEsize = 4375;
			SBsize = 20000;
			break;
		case 36:
			ANTEsize = 5000;
			SBsize = 22500;
			break;
		case 37:
			ANTEsize = 6250;
			SBsize = 25000;
			break;
		case 38:
			ANTEsize = 7500;
			SBsize = 30000;
			break;
		case 39:
			ANTEsize = 8750;
			SBsize = 35000;
			break;
		case 40:
			ANTEsize = 10000;
			SBsize = 40000;
			break;
		case 41:
			ANTEsize = 12500;
			SBsize = 50000;
			break;
		case 42:
			ANTEsize = 15000;
			SBsize = 60000;
			break;
		case 43:
			ANTEsize = 17500;
			SBsize = 70000;
			break;
		case 44:
			ANTEsize = 20000;
			SBsize = 80000;
			break;
		case 45:
			ANTEsize = 25000;
			SBsize = 100000;
			break;
		case 46:
			ANTEsize = 31250;
			SBsize = 125000;
			break;
		default:
			SBsize *= 2;
			break;
		}
		BBsize = SBsize * 2;
	}

	


}

//calculate the pot on table (sum of all bets and antes)
void Ambient::set_Pot() {
	
	set_PlayersInHand();

	//reset pot and recalc
	PotSize = 0;
	for (int i = 0; i < nPlayers; i++) {

		PotSize += *PlayersInvested[i];

	};



	set_BetSize();


};

//calc the size of the betsize
void Ambient::set_BetSize() {
	if (PlayersInHand == 2 && *PlayersBet[SBPosition] > SBsize && *PlayersBet[SBPosition] < BBsize) { BetSize = *PlayersBet[SBPosition]; return; }

	//reset betsize and recalc the size of the betsize
	BetSize = 0;

	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] >= BetSize) { BetSize = *PlayersBet[i]; }

	};


};

//set if is tournament o cash for ante or blind manage (incomplete)
void Ambient::set_game_type() {
	if (bTournament == true) {
		ANTEsize = 3;
		SBsize = 30;
		BBsize = 15;
	}
	else
	{
		ANTEsize = 0;
		SBsize = 1;
		BBsize = 2;
	}
}

//set pointer for comunicate players and ambient at any time
void Ambient::set_pointers() {

	//set player to ambient pointers
	for (int i = 0; i < nPlayers; i++) {
		p[i].Table = this;
	}

	//set ambient from player pointers
	for (int i = 0; i < nPlayers; i++) {
		PlayersStack[i] = &p[i].mystack;
		PlayersPosition[i] = &p[i].myposition;
		PlayersBet[i] = &p[i].mybet;
		PlayersName[i] = &p[i].myname;
		PlayersState[i] = &p[i].mystate;
		PlayersInvested[i] = &p[i].TotalInvested;
		PlayersStrenght[i] = &p[i].HandStrength;

		for (int j = 0; j < nPlayers; j++) {
			p[j].PlayersStack[i] = &p[i].mystack;
			p[j].PlayersPosition[i] = &p[i].myposition;
			p[j].PlayersBet[i] = &p[i].mybet;
			p[j].PlayersName[i] = &p[i].myname;
			p[j].PlayersState[i] = &p[i].mystate;
			p[j].PlayersInvested[i] = &p[i].TotalInvested;
		}

	}

	//set player cards pointers from ambient deck

	p[0].MyCards[0] = &ShuffledDeck[0];	
	p[0].MyCards[1] = &ShuffledDeck[1];
	

	//player postflop card
	for (int i = 0; i <nPlayers; i++) {
		p[i].MyCards[2] = &ShuffledDeck[2];
		p[i].MyCards[3] = &ShuffledDeck[3];
		p[i].MyCards[4] = &ShuffledDeck[4];
		p[i].MyCards[5] = &ShuffledDeck[5];
		p[i].MyCards[6] = &ShuffledDeck[6];
	}

	int index = 7;
	
	for (int i = 1; i <nPlayers; i++) {
		p[i].MyCards[0] = &ShuffledDeck[index];
		index++;
		p[i].MyCards[1] = &ShuffledDeck[index];
		index++;
	}

	for (int i = 0; i < nPlayers; i++) {
		for (int j = 0; j - 52; j++) {
			p[i].ShuffledDeck[j] = &ShuffledDeck[j];
		}
	}

};

//initialize players var
void Ambient::set_initial_player_var() {



	//set the initial players var
	for (int i = 0; i < nPlayers; i++) {
		p[i].myseat = (i + 1);
		p[i].myposition = (i - 1);
		p[i].myname = "Player" + to_string(i);
		p[i].mystate = State::null;
		p[i].mystack = PlayersStartingStack;
		p[i].Table = this;

	}

};


//reset action on table var (raises , calls ecc)
void Ambient::reset_action_counts() {
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

}

//choose bet round to play
void Ambient::goto_betround() {
	switch (BetRound)
	{
	case 1:
		if (PlayersInHand <= 1 && !isSimulation) { BetRound = 2; goto_betround(); return; };
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

//put ante in the pot 
void Ambient::Ante() {
	BetRound = 0;
	for (int i = 0; i < nPlayers; i++) {
		p[i].post_ANTE();
		HH->HandHistory(p[i].myname + " posts ante [" + to_string(p[i].mybet) + "]", bHandHistory);
	}
	set_Pot();

};

//play preflop 
void Ambient::Preflop() {
	if (!isSimulation)set_Preflop_PlayerVar();
	Handplay();

	goto_betround();
};
//play flop 

void Ambient::Flop() {
	BetRound = 2;
	HH->HandHistory("** Dealing flop ** [ " + *p[0].MyCards[2] + ", " + *p[0].MyCards[3] + ", " + *p[0].MyCards[4] + " ]", bHandHistory);
	
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(), Turn(); return; };
	if (!isSimulation)reset_players_state();
	Handplay();
	goto_betround();


};
//play turn
void Ambient::Turn() {
	BetRound = 3;

	HH->HandHistory("** Dealing turn ** [ " + *p[0].MyCards[5] + " ]", bHandHistory);
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(), River(); return; };
	if (!isSimulation)reset_players_state();
	Handplay();
	goto_betround();

};
//play river
void Ambient::River() {
	BetRound = 4;
	HH->HandHistory("** Dealing river ** [ " + *p[0].MyCards[6] + " ]", bHandHistory);
	if (PlayersInHand <= 1 && !isSimulation) { set_players_card(); Showdown(); return; };
	if (!isSimulation) reset_players_state();
	if (PlayersInHand > 1) {
		Handplay();
		goto_betround();
	}

};

//the end of hand
void Ambient::Showdown() {
	HH->HandHistory("** Summary **", bHandHistory);
	BetRound = 5;

	calc_HHprize();
	set_Winners();
	HH->handhistory_finish(NumberOfWinners,SingleSituation,p, bHandHistory);

};

//play the hand
void Ambient::Handplay() {
	int i = 0;
	//for simulation into simulation only
	if (isSimulation) {i = index; isSimulation = false;}
	else { i = SBPosition; }

	//make players decision as long as necessary
	for (i ; i <= nPlayers; i++) {

		//ignore player that not have to act
		if (i == nPlayers) { i = 0; }
 		if (i == SBPosition && !NewOrbit()) { break; }
		if (IgnorePlayer(i)) { continue; }


		p[i].HHline = HH->HHline;
		//let player decide action
		p[i].MyTurn(p);
		//count tot raises for orbit
		if (p[i].BotLastAction == State::Raise) RoundRaises++;
		if (p[i].BotLastAction == State::Call) RoundCalls++;

		//write in hand hystory player action
		HH->handhistory_player_action(i,p,bTournament,SBPosition,PlayersInHand, bHandHistory);

		//calculate new pot
		set_Pot();


	}

};

//calc the prize for winners
void Ambient::calc_prize() {
	

	if (NumberOfWinners == 1) {
		for (int i = 0; i < nPlayers; i++) {
			if (p[i].HandStrength == MaxStrenght)p[i].myprize = PotSize;
			if (p[i].HandStrength == MaxStrenght)HHprize = (PotSize - BetRefound);
			if (p[i].HandStrength == MaxStrenght && p[i].mybet == maxbet && maxbet2 == 0 && PlayerAtShowdown == 1)HHprize = (PotSize - p[i].mybet);
		
		
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
void Ambient::calc_HHprize() {
	BetRefound = 0;
	nMaxBet = 0;
	maxbet = 0;
	maxbet2 = 0;

	// Trova la puntata massima
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] > maxbet) {
			maxbet = *PlayersBet[i];
		}
	}

	// Trova la seconda puntata massima
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] > maxbet2 && *PlayersBet[i] < maxbet) {
			maxbet2 = *PlayersBet[i];
		}
	}

	// Rimuovi il rimborso dal piatto
	for (int i = 0; i < nPlayers; i++) {
		if (*PlayersBet[i] == maxbet) {
			nMaxBet++;
		}
	}

	if (nMaxBet == 1) {
		BetRefound = maxbet - maxbet2;
	}

}
//set the winners
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

//add the prize at the stack of winners
void Ambient::pay_winners() {

	//hand hystory
	for (int i = 0; i < nPlayers; i++) {
		HH->HandHistory(p[i].myname + " shows [ " + *p[i].MyCards[0] + ", " + *p[i].MyCards[1] + " ]", bHandHistory);
	};

	
	//pay winners
	for (int i = 0; i < nPlayers; i++) {
				if (p[i].HandStrength == MaxStrenght && p[i].mystate != State::Fold) {					
					p[i].TakePrize(p[i].myprize);
					if (bTournament == true) { HH->HandHistory(p[i].myname + " collected [ " + to_string(HHprize) + " ]", bHandHistory); }
					else { HH->HandHistory(p[i].myname + " collected [ €" + to_string(HHprize) + " ]", bHandHistory); };
			}
		}

	
	//go out loose players
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystack <= 0) {
			p[i].mystate = State::Out;
		}		
	}

	
}

//at the end of tournament (incomplete=
void Ambient::Tournament_Finish() {
	PlayerPosition = TotPlayers - 1;
	if(p[0].mystate == State::Out)cout << "player eliminato! player rimanenti = "<< PlayerPosition <<endl;
	else if(nPlayers == 1 && p[0].mystate != State::Out)cout << "Torneo Finito! Player arrivato primo.\n";

}

//check of many player are in showdown
void Ambient::calc_player_at_showdown() {

	for (int i = 0; i < nPlayers; i++) {
	
		if (p[i].mystate != State::Fold) { PlayerAtShowdown++; };
	
	
	}


};
//check of many playes have win
void Ambient::calc_number_of_winners() {
	//calc number of winners
	for (int i = 0; i < nPlayers; i++) {
		
		if (*PlayersStrenght[i] == MaxStrenght) { NumberOfWinners++; };
	}


}
//calc the strenth of all player in the showdown
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

//reset the state players at the end of orbit
void Ambient::reset_players_state() {

	for (int i = 0; i < nPlayers; i++) {
		p[i].reset_mybet();
		p[i].reset_mystate();
		p[i].set_mycard();
	};
	set_Pot();

};

//update the card known of player based on betround
void Ambient::set_players_card() {
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Fold) { continue; }
		p[i].set_mycard();

}


};

//get the player handstrength
void Ambient::players_count_hand_strength() {

	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate != State::Fold) {
			p[i].set_HandStrength();
		}

	}

};

//set the initial var of player at preflop
void Ambient::set_Preflop_PlayerVar() {
	BetRound = 1;

	//Post Blinds
	for (int i = 0; i < nPlayers; i++) {
		p[i].set_mycard();
		p[i].reset_mybet();
		p[i].set_OpponentsAtTable();

	};

};

//manage rebuy options (at the moment is automatic never go out)
void Ambient::rebuy_options() {
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystate == State::Out || p[i].mystack == 0) {
			if(bNeverGoOut){
			p[i].mystack = PlayersStartingStack;
			p[i].mystate = State::Fold;	
			continue;
			}

			
			if (i == 0)return;//player out game end
			if (TotPlayers <= SeatsMaxNumber) {
				//al momento ad ogni eleminizaione il player 0 ritorna sullo SB, TODO mantere la stessa posizione e spostare le altre
				p.erase(p.begin() + i);
				set_startitng_position();
				nPlayers--;
				TotPlayers--;
			}
			else {

				p[i].mystate = State::Fold;
				p[i].myname = "Playern" + to_string(TotPlayers);
				p[i].mystack = generateRandomStack();
				TotPlayers--;
			}

		}
	}



};

int Ambient::generateRandomStack() {
	int BiggestStack = -10000;
	for (int i = 0; i < nPlayers; i++) {
		if (p[i].mystack >= BiggestStack)BiggestStack = p[i].mystack;
	}


	std::random_device rd; // Semina
	std::mt19937 gen(rd()); // Generatore
	std::uniform_int_distribution<> distr(BiggestStack/2, BiggestStack); // Distribuzione uniforme
	return distr(gen);
}
bool Ambient::hasDuplicates(const std::vector<std::string>& array) {
	std::unordered_set<std::string> seen;
	for (const auto& str : array) {
		if (seen.find(str) != seen.end()) {
			return true;  // Elemento duplicato trovato
		}
		seen.insert(str);
	}
	return false;  // Nessun duplicato trovato
}