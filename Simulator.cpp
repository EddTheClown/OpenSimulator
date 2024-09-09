#include "Simulator.h"

Simulator::Simulator(){
	HH->HH_File = "SimulationHandHistory.txt";
	SingleSituation = false;
};


int Simulator::start_hand(int _TestDecision, int _index) {
	p[_index].TestDecision = _TestDecision;
	index = _index;
	isSimulation = true;
	realHand = false;
	bHandHistory = true;
	int stackprima = p[_index].StartingStack;
	double beforeprwin = 0;

	

	set_pointers();
	set_Pot();

	Handplay();
	goto_betround();

	int stackdopo = p[_index].mystack;
	int differenza = stackdopo - stackprima;

	p[_index].winner;
	p[_index].TestDecision;
	return stackdopo - stackprima;

	if (p[_index].winner) return 1;
	else return -1;




	

};

int Simulator::CountActionSimulations(int _TestDecision , int _myposition, string Evento) {
	index = _myposition;
	p[_myposition].TestDecision = _TestDecision;
	isSimulation = true;
	realHand = false;
	bHandHistory = false;



	set_pointers();
	set_Pot();
	SetInitialActions();

	Handplay();


	return ContaFrequenzaEventi(Evento);

};

void Simulator::set_PlayerVar(vector<Player> _p, int _myposition) {
	p.resize(nPlayers);

	//set all player var
	for (int i = 0; i < nPlayers; i++) {
		p[i].SimulationLevel = _p[i].SimulationLevel;
		p[i].StartingStack = _p[i].StartingStack;
		p[i].mystate = _p[i].mystate;
		p[i].AnteInvested = _p[i].AnteInvested;
		p[i].PreflopInvested = _p[i].PreflopInvested;
		p[i].FlopInvested = _p[i].FlopInvested;
		p[i].TurnInvested = _p[i].TurnInvested;
		p[i].RiverInvested = _p[i].RiverInvested;
		p[i].TotalInvested = _p[i].TotalInvested;
		p[i].mystack = _p[i].mystack;
		p[i].OpponentsAtTable = _p[i].OpponentsAtTable;
		p[i].myposition = _p[i].myposition;
		p[i].mybet = _p[i].mybet;
		p[i].myraise = _p[i].myraise;
		p[i].HandStrength = _p[i].HandStrength;
		p[i].StackLevel = _p[i].StackLevel;
		p[i].myseat = _p[i].myseat;
		p[i].myprize = _p[i].myprize;
		p[i].inButton = _p[i].inButton;
		p[i].inSmallBlind = _p[i].inSmallBlind;
		p[i].inBigBlind = _p[i].inBigBlind;
		p[i].bprwin = _p[i].bprwin;
		p[i].currentbet = _p[i].currentbet;
		p[i].OpponentsAtTable = _p[i].OpponentsAtTable;
		p[i].AmountToCall = _p[i].AmountToCall;
		p[i].MaxOpponentStackSize = _p[i].MaxOpponentStackSize;
		p[i].MinOpponentStackSize = _p[i].MinOpponentStackSize;
		p[i].MaxBet = _p[i].MaxBet;

		p[i].mycard[0] = _p[i].mycard[0];
		p[i].mycard[1] = _p[i].mycard[1];
		p[i].mycard[2] = _p[i].mycard[2];
		p[i].mycard[3] = _p[i].mycard[3];
		p[i].mycard[4] = _p[i].mycard[4];
		p[i].mycard[5] = _p[i].mycard[5];
		p[i].mycard[6] = _p[i].mycard[6];


		p[i].myname = _p[i].myname;
		p[i].mycards = _p[i].mycards;
		p[i].prwin = _p[i].prwin;

		p[i].winner = false;
		p[i].bprwin = _p[i].bprwin;

		p[i].isSimulation = true;


	};


	BetRound = _p[index].Table->BetRound;
	BBsize = _p[index].Table->BBsize;
	SBsize = _p[index].Table->SBsize;

	SBPosition =_p[index].Table->SBPosition;
	BBPosition =_p[index].Table->BBPosition;

	ANTEsize = _p[index].Table->ANTEsize;
	nPlayers = _p[index].Table->nPlayers;

	bHandHistory = false;


	create_new_deck(_p);
}
void Simulator::create_new_deck(vector<Player> _p) {

	ShuffledDeck[0] = p[0].mycard[0];
	ShuffledDeck[1] = p[0].mycard[1];
	ShuffledDeck[2] = p[0].mycard[2];
	ShuffledDeck[3] = p[0].mycard[3];
	ShuffledDeck[4] = p[0].mycard[4];
	ShuffledDeck[5] = p[0].mycard[5];
	ShuffledDeck[6] = p[0].mycard[6];

	int indice = 2;
	if (p[0].mycard[2] != "") { indice = 5; }
	if (p[0].mycard[5] != "") { indice = 6; }
	if (p[0].mycard[6] != "") { indice = 7; }



	for (int i = indice; i < 52; i++)
	{
		ShuffledDeck[i] = NewDeck[rand() % 52];

		for (int j = 0; j < i; j++) {
			if (ShuffledDeck[i] == ShuffledDeck[j]) { i--; break; }


		}

	}


};


int Simulator::ContaFrequenzaEventi(string Evento) {


	int tempFolds = Folds - initialFolds;
	int tempRaises = Raises - initialRaises;
	int tempCalls = Calls - initialCalls;
	int tempAllins = Allins - initialAllins;
	int tempChecks = Checks - Checks;

	//if testa fold return temp fold

	if (Evento == "FoldAll" && Folds == (nPlayers - 1)) {
			return 1;
		}

	// Controlla se tutti i giocatori hanno fatto call dopo il raise
	if (Evento == "CallAll" && Calls == (nPlayers - 1)) {
		return 1;
	}

	// Controlla se un solo giocatore ha fatto call dopo il raise
	if (Evento == "Call1" && tempCalls == 1) {
		return 1;
	}

	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call2" && tempCalls == 2) {
		return 1;
	}

	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call3" && tempCalls == 3) {
		return 1;
	}
	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call4" && tempCalls == 4) {
		return 1;
	}
	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call5" && tempCalls == 5) {
		return 1;
	}
	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call6" && tempCalls == 6) {
		return 1;
	}
	// Controlla se due giocatori hanno fatto call dopo il raise
	if (Evento == "Call7" && tempCalls == 7) {
		return 1;
	}

	// Controlla se qualcuno ha fatto una 3bet dopo il raise
	if (Evento == "3Bet" && tempRaises > 0) { // Supponiamo che la 3bet sia contata come un raise addizionale
		return 1;
	}
	// Controlla se qualcuno ha fatto una 3bet dopo il raise
	if (Evento == "3Bet2" && tempRaises == 2) { // Supponiamo che la 3bet sia contata come un raise addizionale
		return 1;
	}
	// Controlla se qualcuno ha fatto una 3bet dopo il raise
	if (Evento == "3Bet3" && tempRaises == 3) { // Supponiamo che la 3bet sia contata come un raise addizionale
		return 1;
	}

	// Controlla se un giocatore è andato all-in
	if (Evento == "checkMultiAllIn" && tempAllins == 1) {
		return 1;
	}

	// Controlla se più giocatori sono andati all-in
	if (Evento == "checkMultiAllIn" && tempAllins > 1) {
		return 1;
	}

	return 0;
}

void  Simulator::SetInitialActions() {
	initialFolds = Folds;
	initialCalls = Calls;
	initialRaises = Raises;
	initialChecks = Checks;
	initialAllins = Allins;

};
