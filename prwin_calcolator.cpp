#include "prwin_calcolator.h"


//calc prwin with montecarlo simulation
double prwin_calcolator::calc_prwin(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river, int _PlayersInHand, int _nIteration) {
	nIterations = _nIteration;
	nPlayers = _PlayersInHand;

	prwin = 0;
	nWin = 0;

	//check if some card are equal
	{if ((_pCard1 == _pCard2 && _pCard2 != "") ||
		(_pCard1 == _flop1 && _flop1 != "") ||
		(_pCard1 == _flop2 && _flop2 != "") ||
		(_pCard1 == _flop3 && _flop3 != "") ||
		(_pCard1 == _turn && _turn != "") ||
		(_pCard1 == _river && _river != "") ||
		(_pCard2 == _flop1 && _flop1 != "") ||
		(_pCard2 == _flop2 && _flop2 != "") ||
		(_pCard2 == _flop3 && _flop3 != "") ||
		(_pCard2 == _turn && _turn != "") ||
		(_pCard2 == _river && _river != "") ||
		(_flop1 == _flop2 && _flop2 != "") ||
		(_flop1 == _flop3 && _flop3 != "") ||
		(_flop1 == _turn && _turn != "") ||
		(_flop1 == _river && _river != "") ||
		(_flop2 == _flop3 && _flop3 != "") ||
		(_flop2 == _turn && _turn != "") ||
		(_flop2 == _river && _river != "") ||
		(_flop3 == _turn && _turn != "") ||
		(_flop3 == _river && _river != "") ||
		(_turn == _river && _river != ""))return 0;
}



	//if is preflop use precalculated prwin
	if (_flop1 == "") {
		PreflopNumber = set_preflopnumber(_pCard1, _pCard2);
		prwin = Preflop_precalc_prwin(PreflopNumber, _PlayersInHand);
		PreflopNumber = 0;
		return prwin;
	}


	for (int i = 0; i < nIterations; i++) {

		MixDeck(_pCard1, _pCard2, _flop1, _flop2, _flop3, _turn, _river);
		set_players_card();
		set_player_strength();
		if (winner() == true) { nWin++; };

		reset_player_cards();
	}

	prwin = (nWin / (double)nIterations);


	return prwin;

}
void prwin_calcolator::set_nSuited(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river) {

	int card1s = 0;
	int card2s = 0;
	if (_pCard1[1] == _pCard2[1]) {
		nSuited = 2;
		if (_pCard1[1] == _flop1[1])nSuited++;
		if (_pCard1[1] == _flop2[1])nSuited++;
		if (_pCard1[1] == _flop3[1])nSuited++;
		if (_pCard1[1] == _turn[1])nSuited++;
		if (_pCard1[1] == _river[1])nSuited++;
	}
	if (_pCard1[1] != _pCard2[1]) {
		nSuited = 1;

		if (_pCard1[1] == _flop1[1])card1s++;
		if (_pCard1[1] == _flop2[1])card1s++;
		if (_pCard1[1] == _flop3[1])card1s++;
		if (_pCard1[1] == _turn[1])card1s++;
		if (_pCard1[1] == _river[1])card1s++;

		if (_pCard2[1] == _flop1[1])card2s++;
		if (_pCard2[1] == _flop2[1])card2s++;
		if (_pCard2[1] == _flop3[1])card2s++;
		if (_pCard2[1] == _turn[1])card2s++;
		if (_pCard2[1] == _river[1])card2s++;

		if (card1s >= card2s)nSuited += card1s;
		if (card2s > card1s)nSuited += card2s;

	}

};


//create new deck keeping only the known cards
void prwin_calcolator::MixDeck(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river)
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
	if (_flop1 != "") { indice = 5; }
	if (_turn != "") { indice = 6; }
	if (_river != "") { indice = 7; };



	for (int i = indice; i < ((nPlayers * 2) + 5); i++)
	{
		Numero = rand() % 52;
		ShuffledDeck[i] = NewDeck[Numero];

		for (int j = 0; j < i; j++) {
			if (ShuffledDeck[i] == ShuffledDeck[j]) { i--; break; }
		}

	}
	pCard1 = ShuffledDeck[0];
	pCard2 = ShuffledDeck[1];
	flop1 = ShuffledDeck[2];
	flop2 = ShuffledDeck[3];
	flop3 = ShuffledDeck[4];
	turn = ShuffledDeck[5];
	river = ShuffledDeck[6];



};
//calc the stength of players
void prwin_calcolator::set_player_strength() {

	CHandStrength* calc = new CHandStrength;
	switch (nPlayers) {
	case 2:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		break;
	case 3:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		break;
	case 4:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		break;
	case 5:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		pStrength[4] = calc->calc_HandStrength(p4card[0], p4card[1], flop1, flop2, flop3, turn, river);

		break;
	case 6:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		pStrength[4] = calc->calc_HandStrength(p4card[0], p4card[1], flop1, flop2, flop3, turn, river);
		pStrength[5] = calc->calc_HandStrength(p5card[0], p5card[1], flop1, flop2, flop3, turn, river);
		break;
	case 7:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		pStrength[4] = calc->calc_HandStrength(p4card[0], p4card[1], flop1, flop2, flop3, turn, river);
		pStrength[5] = calc->calc_HandStrength(p5card[0], p5card[1], flop1, flop2, flop3, turn, river);
		pStrength[6] = calc->calc_HandStrength(p6card[0], p6card[1], flop1, flop2, flop3, turn, river);
		break;
	case 8:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		pStrength[4] = calc->calc_HandStrength(p4card[0], p4card[1], flop1, flop2, flop3, turn, river);
		pStrength[5] = calc->calc_HandStrength(p5card[0], p5card[1], flop1, flop2, flop3, turn, river);
		pStrength[6] = calc->calc_HandStrength(p6card[0], p6card[1], flop1, flop2, flop3, turn, river);
		pStrength[7] = calc->calc_HandStrength(p7card[0], p7card[1], flop1, flop2, flop3, turn, river);
		break;
	case 9:
		pStrength[0] = calc->calc_HandStrength(p0card[0], p0card[1], flop1, flop2, flop3, turn, river);
		pStrength[1] = calc->calc_HandStrength(p1card[0], p1card[1], flop1, flop2, flop3, turn, river);
		pStrength[2] = calc->calc_HandStrength(p2card[0], p2card[1], flop1, flop2, flop3, turn, river);
		pStrength[3] = calc->calc_HandStrength(p3card[0], p3card[1], flop1, flop2, flop3, turn, river);
		pStrength[4] = calc->calc_HandStrength(p4card[0], p4card[1], flop1, flop2, flop3, turn, river);
		pStrength[5] = calc->calc_HandStrength(p5card[0], p5card[1], flop1, flop2, flop3, turn, river);
		pStrength[6] = calc->calc_HandStrength(p6card[0], p6card[1], flop1, flop2, flop3, turn, river);
		pStrength[7] = calc->calc_HandStrength(p7card[0], p7card[1], flop1, flop2, flop3, turn, river);
		pStrength[8] = calc->calc_HandStrength(p8card[0], p8card[1], flop1, flop2, flop3, turn, river);
		break;

	}
    delete calc;


}
//set the players card (0 and 1 is always hero cards , 23456 always post flop) 
void prwin_calcolator::set_players_card() {

	switch (nPlayers) {
	case 2:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		break;
	case 3:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		break;
	case 4:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		break;
	case 5:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		p4card[1] = ShuffledDeck[14];

		break;
	case 6:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		p4card[1] = ShuffledDeck[14];
		p5card[0] = ShuffledDeck[15];
		p5card[1] = ShuffledDeck[16];
		break;
	case 7:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		p4card[1] = ShuffledDeck[14];
		p5card[0] = ShuffledDeck[15];
		p5card[1] = ShuffledDeck[16];
		p6card[0] = ShuffledDeck[17];
		p6card[1] = ShuffledDeck[18];
		break;
	case 8:
		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		p4card[1] = ShuffledDeck[14];
		p5card[0] = ShuffledDeck[15];
		p5card[1] = ShuffledDeck[16];
		p6card[0] = ShuffledDeck[17];
		p6card[1] = ShuffledDeck[18];
		p7card[0] = ShuffledDeck[19];
		p7card[1] = ShuffledDeck[20];
		break;
	case 9:

		p0card[0] = ShuffledDeck[0];
		p0card[1] = ShuffledDeck[1];
		p1card[0] = ShuffledDeck[7];
		p1card[1] = ShuffledDeck[8];
		p2card[0] = ShuffledDeck[9];
		p2card[1] = ShuffledDeck[10];
		p3card[0] = ShuffledDeck[11];
		p3card[1] = ShuffledDeck[12];
		p4card[0] = ShuffledDeck[13];
		p4card[1] = ShuffledDeck[14];
		p5card[0] = ShuffledDeck[15];
		p5card[1] = ShuffledDeck[16];
		p6card[0] = ShuffledDeck[17];
		p6card[1] = ShuffledDeck[18];
		p7card[0] = ShuffledDeck[19];
		p7card[1] = ShuffledDeck[20];
		p8card[0] = ShuffledDeck[21];
		p8card[1] = ShuffledDeck[22];
		break;
	}

}
//compare the hand strength of the players to decide if won
bool prwin_calcolator::winner() {

	int Strength = -1000000;
	for (int i = 0; i < nPlayers; i++) {
		if (pStrength[i] >= Strength) { Strength = pStrength[i]; };

	}
	
	int nWinners = 0;
	for (int i = 0; i < nPlayers; i++) {
		if (pStrength[i] == Strength) { nWinners++; };
	}

	if (pStrength[0] == Strength && nWinners == 1) { return true; }
	//if (pStrength[0] == Strength && nWinners > 1) { prtie++; }
	//if (pStrength[0] != Strength) { prlos++; }
	return false;
};
//reset all player cards
void prwin_calcolator::reset_player_cards() {


	p1card[0] = "";
	p1card[1] = "";
	p2card[0] = "";
	p2card[1] = "";
	p3card[0] = "";
	p3card[1] = "";
	p4card[0] = "";
	p4card[1] = "";
	p5card[0] = "";
	p5card[1] = "";
	p6card[0] = "";
	p6card[1] = "";
	p7card[0] = "";
	p7card[1] = "";
	p8card[0] = "";
	p8card[1] = "";

	


};
//return pre calc prwin preflop without montecarlo simulation (very fast!)
double prwin_calcolator::Preflop_precalc_prwin(int PreflopNumber,int nPlayers) {
	switch (PreflopNumber) {
	case 1:
		switch (nPlayers) {
		case 2:  //AA 2 Players 
			return 0.85132;
			break;
		case 3:  //AA 3 Players 
			return 0.73259;
			break;
		case 4:  //AA 4 Players 
			return 0.63442;
			break;
		case 5:  //AA 5 Players 
			return 0.55664;
			break;
		case 6:  //AA 6 Players 
			return 0.48724;
			break;
		case 7:  //AA 7 Players 
			return 0.43003;
			break;
		case 8:  //AA 8 Players 
			return 0.38569;
			break;
		case 9:  //AA 9 Players 
			return 0.34316;
			break;
		}//switch nPlayers close
	case 2:
		switch (nPlayers) {
		case 2:  //AK 2 Players 
			return 0.64736;
			break;
		case 3:  //AK 3 Players 
			return 0.47161;
			break;
		case 4:  //AK 4 Players 
			return 0.37507;
			break;
		case 5:  //AK 5 Players 
			return 0.31354;
			break;
		case 6:  //AK 6 Players 
			return 0.26999;
			break;
		case 7:  //AK 7 Players 
			return 0.23662;
			break;
		case 8:  //AK 8 Players 
			return 0.20658;
			break;
		case 9:  //AK 9 Players 
			return 0.18322;
			break;
		}//switch nPlayers close
	case 3:
		switch (nPlayers) {
		case 2:  //AKs 2 Players 
			return 0.65842;
			break;
		case 3:  //AKs 3 Players 
			return 0.49781;
			break;
		case 4:  //AKs 4 Players 
			return 0.4032;
			break;
		case 5:  //AKs 5 Players 
			return 0.34643;
			break;
		case 6:  //AKs 6 Players 
			return 0.30002;
			break;
		case 7:  //AKs 7 Players 
			return 0.26885;
			break;
		case 8:  //AKs 8 Players 
			return 0.24205;
			break;
		case 9:  //AKs 9 Players 
			return 0.22129;
			break;
		}//switch nPlayers close
	case 4:
		switch (nPlayers) {
		case 2:  //AQ 2 Players 
			return 0.63499;
			break;
		case 3:  //AQ 3 Players 
			return 0.45832;
			break;
		case 4:  //AQ 4 Players 
			return 0.35718;
			break;
		case 5:  //AQ 5 Players 
			return 0.29301;
			break;
		case 6:  //AQ 6 Players 
			return 0.25006;
			break;
		case 7:  //AQ 7 Players 
			return 0.21547;
			break;
		case 8:  //AQ 8 Players 
			return 0.18642;
			break;
		case 9:  //AQ 9 Players 
			return 0.16227;
			break;
		}//switch nPlayers close
	case 5:
		switch (nPlayers) {
		case 2:  //AQs 2 Players 
			return 0.65324;
			break;
		case 3:  //AQs 3 Players 
			return 0.48497;
			break;
		case 4:  //AQs 4 Players 
			return 0.38875;
			break;
		case 5:  //AQs 5 Players 
			return 0.32713;
			break;
		case 6:  //AQs 6 Players 
			return 0.27994;
			break;
		case 7:  //AQs 7 Players 
			return 0.24878;
			break;
		case 8:  //AQs 8 Players 
			return 0.22526;
			break;
		case 9:  //AQs 9 Players 
			return 0.19996;
			break;
		}//switch nPlayers close
	case 6:
		switch (nPlayers) {
		case 2:  //AJ 2 Players 
			return 0.6264;
			break;
		case 3:  //AJ 3 Players 
			return 0.44733;
			break;
		case 4:  //AJ 4 Players 
			return 0.34065;
			break;
		case 5:  //AJ 5 Players 
			return 0.27629;
			break;
		case 6:  //AJ 6 Players 
			return 0.23309;
			break;
		case 7:  //AJ 7 Players 
			return 0.19746;
			break;
		case 8:  //AJ 8 Players 
			return 0.17085;
			break;
		case 9:  //AJ 9 Players 
			return 0.14901;
			break;
		}//switch nPlayers close
	case 7:

		switch (nPlayers) {
		case 2:  //AJs 2 Players 
			return 0.64434;
			break;
		case 3:  //AJs 3 Players 
			return 0.47321;
			break;
		case 4:  //AJs 4 Players 
			return 0.37102;
			break;
		case 5:  //AJs 5 Players 
			return 0.31074;
			break;
		case 6:  //AJs 6 Players 
			return 0.26948;
			break;
		case 7:  //AJs 7 Players 
			return 0.23413;
			break;
		case 8:  //AJs 8 Players 
			return 0.20933;
			break;
		case 9:  //AJs 9 Players 
			return 0.18653;
			break;
		}//switch nPlayers close
	case 8:
		switch (nPlayers) {
		case 2:  //AT 2 Players 
			return 0.61725;
			break;
		case 3:  //AT 3 Players 
			return 0.43009;
			break;
		case 4:  //AT 4 Players 
			return 0.33103;
			break;
		case 5:  //AT 5 Players 
			return 0.26039;
			break;
		case 6:  //AT 6 Players 
			return 0.21587;
			break;
		case 7:  //AT 7 Players 
			return 0.18374;
			break;
		case 8:  //AT 8 Players 
			return 0.15806;
			break;
		case 9:  //AT 9 Players 
			return 0.13569;
			break;
		}//switch nPlayers close
	case 9:
		switch (nPlayers) {
		case 2:  //ATs 2 Players 
			return 0.63373;
			break;
		case 3:  //ATs 3 Players 
			return 0.46177;
			break;
		case 4:  //ATs 4 Players 
			return 0.35883;
			break;
		case 5:  //ATs 5 Players 
			return 0.29294;
			break;
		case 6:  //ATs 6 Players 
			return 0.25733;
			break;
		case 7:  //ATs 7 Players 
			return 0.22166;
			break;
		case 8:  //ATs 8 Players 
			return 0.19582;
			break;
		case 9:  //ATs 9 Players 
			return 0.17821;
			break;
		}//switch nPlayers close
	case 10:
		switch (nPlayers) {
		case 2:  //A9 2 Players 
			return 0.5954;
			break;
		case 3:  //A9 3 Players 
			return 0.40116;
			break;
		case 4:  //A9 4 Players 
			return 0.29735;
			break;
		case 5:  //A9 5 Players 
			return 0.23062;
			break;
		case 6:  //A9 6 Players 
			return 0.18862;
			break;
		case 7:  //A9 7 Players 
			return 0.15882;
			break;
		case 8:  //A9 8 Players 
			return 0.13141;
			break;
		case 9:  //A9 9 Players 
			return 0.11674;
			break;
		}//switch nPlayers close
	case 11:
		switch (nPlayers) {
		case 2:  //A9s 2 Players 
			return 0.61752;
			break;
		case 3:  //A9s 3 Players 
			return 0.43241;
			break;
		case 4:  //A9s 4 Players 
			return 0.33111;
			break;
		case 5:  //A9s 5 Players 
			return 0.26839;
			break;
		case 6:  //A9s 6 Players 
			return 0.22803;
			break;
		case 7:  //A9s 7 Players 
			return 0.19918;
			break;
		case 8:  //A9s 8 Players 
			return 0.17523;
			break;
		case 9:  //A9s 9 Players 
			return 0.15772;
			break;
		}//switch nPlayers close
	case 12:
		switch (nPlayers) {
		case 2:  //A8 2 Players 
			return 0.58655;
			break;
		case 3:  //A8 3 Players 
			return 0.38953;
			break;
		case 4:  //A8 4 Players 
			return 0.28626;
			break;
		case 5:  //A8 5 Players 
			return 0.21887;
			break;
		case 6:  //A8 6 Players 
			return 0.17722;
			break;
		case 7:  //A8 7 Players 
			return 0.14687;
			break;
		case 8:  //A8 8 Players 
			return 0.1237;
			break;
		case 9:  //A8 9 Players 
			return 0.1067;
			break;
		}//switch nPlayers close
	case 13:
		switch (nPlayers) {
		case 2:  //A8s 2 Players 
			return 0.60636;
			break;
		case 3:  //A8s 3 Players 
			return 0.42128;
			break;
		case 4:  //A8s 4 Players 
			return 0.31898;
			break;
		case 5:  //A8s 5 Players 
			return 0.2565;
			break;
		case 6:  //A8s 6 Players 
			return 0.21577;
			break;
		case 7:  //A8s 7 Players 
			return 0.18941;
			break;
		case 8:  //A8s 8 Players 
			return 0.16663;
			break;
		case 9:  //A8s 9 Players 
			return 0.15021;
			break;
		}//switch nPlayers close
	case 14:
		switch (nPlayers) {
		case 2:  //A7 2 Players 
			return 0.57418;
			break;
		case 3:  //A7 3 Players 
			return 0.37374;
			break;
		case 4:  //A7 4 Players 
			return 0.27019;
			break;
		case 5:  //A7 5 Players 
			return 0.20897;
			break;
		case 6:  //A7 6 Players 
			return 0.16696;
			break;
		case 7:  //A7 7 Players 
			return 0.13717;
			break;
		case 8:  //A7 8 Players 
			return 0.11599;
			break;
		case 9:  //A7 9 Players 
			return 0.09877;
			break;
		}//switch nPlayers close
	case 15:
		switch (nPlayers) {
		case 2:  //A7s 2 Players 
			return 0.59351;
			break;
		case 3:  //A7s 3 Players 
			return 0.40629;
			break;
		case 4:  //A7s 4 Players 
			return 0.30908;
			break;
		case 5:  //A7s 5 Players 
			return 0.24589;
			break;
		case 6:  //A7s 6 Players 
			return 0.2109;
			break;
		case 7:  //A7s 7 Players 
			return 0.18191;
			break;
		case 8:  //A7s 8 Players 
			return 0.15847;
			break;
		case 9:  //A7s 9 Players 
			return 0.14116;
			break;
		}//switch nPlayers close
	case 16:
		switch (nPlayers) {
		case 2:  //A6 2 Players 
			return 0.55951;
			break;
		case 3:  //A6 3 Players 
			return 0.35781;
			break;
		case 4:  //A6 4 Players 
			return 0.2579;
			break;
		case 5:  //A6 5 Players 
			return 0.19614;
			break;
		case 6:  //A6 6 Players 
			return 0.15897;
			break;
		case 7:  //A6 7 Players 
			return 0.12929;
			break;
		case 8:  //A6 8 Players 
			return 0.10797;
			break;
		case 9:  //A6 9 Players 
			return 0.09353;
			break;
		}//switch nPlayers close
	case 17:
		switch (nPlayers) {
		case 2:  //A6s 2 Players 
			return 0.58132;
			break;
		case 3:  //A6s 3 Players 
			return 0.39344;
			break;
		case 4:  //A6s 4 Players 
			return 0.29595;
			break;
		case 5:  //A6s 5 Players 
			return 0.23839;
			break;
		case 6:  //A6s 6 Players 
			return 0.20096;
			break;
		case 7:  //A6s 7 Players 
			return 0.1717;
			break;
		case 8:  //A6s 8 Players 
			return 0.15232;
			break;
		case 9:  //A6s 9 Players 
			return 0.13755;
			break;
		}//switch nPlayers close
	case 18:
		switch (nPlayers) {
		case 2:  //A5 2 Players 
			return 0.55751;
			break;
		case 3:  //A5 3 Players 
			return 0.36131;
			break;
		case 4:  //A5 4 Players 
			return 0.26047;
			break;
		case 5:  //A5 5 Players 
			return 0.20185;
			break;
		case 6:  //A5 6 Players 
			return 0.16443;
			break;
		case 7:  //A5 7 Players 
			return 0.13448;
			break;
		case 8:  //A5 8 Players 
			return 0.11512;
			break;
		case 9:  //A5 9 Players 
			return 0.10072;
			break;
		}//switch nPlayers close
	case 19:
		switch (nPlayers) {
		case 2:  //A5s 2 Players 
			return 0.58129;
			break;
		case 3:  //A5s 3 Players 
			return 0.39346;
			break;
		case 4:  //A5s 4 Players 
			return 0.30072;
			break;
		case 5:  //A5s 5 Players 
			return 0.24355;
			break;
		case 6:  //A5s 6 Players 
			return 0.2068;
			break;
		case 7:  //A5s 7 Players 
			return 0.17828;
			break;
		case 8:  //A5s 8 Players 
			return 0.15798;
			break;
		case 9:  //A5s 9 Players 
			return 0.14429;
			break;
		}//switch nPlayers close
	case 20:
		switch (nPlayers) {
		case 2:  //A4 2 Players 
			return 0.54563;
			break;
		case 3:  //A4 3 Players 
			return 0.35038;
			break;
		case 4:  //A4 4 Players 
			return 0.25093;
			break;
		case 5:  //A4 5 Players 
			return 0.19374;
			break;
		case 6:  //A4 6 Players 
			return 0.15628;
			break;
		case 7:  //A4 7 Players 
			return 0.1317;
			break;
		case 8:  //A4 8 Players 
			return 0.11193;
			break;
		case 9:  //A4 9 Players 
			return 0.09552;
			break;
		}//switch nPlayers close
	case 21:
		switch (nPlayers) {
		case 2:  //A4s 2 Players 
			return 0.57038;
			break;
		case 3:  //A4s 3 Players 
			return 0.3862;
			break;
		case 4:  //A4s 4 Players 
			return 0.29237;
			break;
		case 5:  //A4s 5 Players 
			return 0.23501;
			break;
		case 6:  //A4s 6 Players 
			return 0.20153;
			break;
		case 7:  //A4s 7 Players 
			return 0.17526;
			break;
		case 8:  //A4s 8 Players 
			return 0.15637;
			break;
		case 9:  //A4s 9 Players 
			return 0.14036;
			break;
		}//switch nPlayers close
	case 22:
		switch (nPlayers) {
		case 2:  //A3 2 Players 
			return 0.53581;
			break;
		case 3:  //A3 3 Players 
			return 0.34011;
			break;
		case 4:  //A3 4 Players 
			return 0.2464;
			break;
		case 5:  //A3 5 Players 
			return 0.18907;
			break;
		case 6:  //A3 6 Players 
			return 0.15204;
			break;
		case 7:  //A3 7 Players 
			return 0.12823;
			break;
		case 8:  //A3 8 Players 
			return 0.10663;
			break;
		case 9:  //A3 9 Players 
			return 0.09301;
			break;
		}//switch nPlayers close
	case 23:
		switch (nPlayers) {
		case 2:  //A3s 2 Players 
			return 0.56306;
			break;
		case 3:  //A3s 3 Players 
			return 0.3753;
			break;
		case 4:  //A3s 4 Players 
			return 0.28231;
			break;
		case 5:  //A3s 5 Players 
			return 0.23004;
			break;
		case 6:  //A3s 6 Players 
			return 0.19586;
			break;
		case 7:  //A3s 7 Players 
			return 0.17162;
			break;
		case 8:  //A3s 8 Players 
			return 0.15062;
			break;
		case 9:  //A3s 9 Players 
			return 0.13857;
			break;
		}//switch nPlayers close
	case 24:
		switch (nPlayers) {
		case 2:  //A2 2 Players 
			return 0.52937;
			break;
		case 3:  //A2 3 Players 
			return 0.33405;
			break;
		case 4:  //A2 4 Players 
			return 0.23675;
			break;
		case 5:  //A2 5 Players 
			return 0.18235;
			break;
		case 6:  //A2 6 Players 
			return 0.14608;
			break;
		case 7:  //A2 7 Players 
			return 0.12401;
			break;
		case 8:  //A2 8 Players 
			return 0.10468;
			break;
		case 9:  //A2 9 Players 
			return 0.09129;
			break;
		}//switch nPlayers close
	case 25:
		switch (nPlayers) {
		case 2:  //A2s 2 Players 
			return 0.55396;
			break;
		case 3:  //A2s 3 Players 
			return 0.36866;
			break;
		case 4:  //A2s 4 Players 
			return 0.27822;
			break;
		case 5:  //A2s 5 Players 
			return 0.22332;
			break;
		case 6:  //A2s 6 Players 
			return 0.19106;
			break;
		case 7:  //A2s 7 Players 
			return 0.1683;
			break;
		case 8:  //A2s 8 Players 
			return 0.14818;
			break;
		case 9:  //A2s 9 Players 
			return 0.13479;
			break;
		}//switch nPlayers close
	case 26:
		switch (nPlayers) {
		case 2:  //KK 2 Players 
			return 0.81894;
			break;
		case 3:  //KK 3 Players 
			return 0.68684;
			break;
		case 4:  //KK 4 Players 
			return 0.58095;
			break;
		case 5:  //KK 5 Players 
			return 0.4954;
			break;
		case 6:  //KK 6 Players 
			return 0.42783;
			break;
		case 7:  //KK 7 Players 
			return 0.37408;
			break;
		case 8:  //KK 8 Players 
			return 0.32344;
			break;
		case 9:  //KK 9 Players 
			return 0.28772;
			break;
		}//switch nPlayers close
	case 27:
		switch (nPlayers) {
		case 2:  //KQ 2 Players 
			return 0.60575;
			break;
		case 3:  //KQ 3 Players 
			return 0.43579;
			break;
		case 4:  //KQ 4 Players 
			return 0.34295;
			break;
		case 5:  //KQ 5 Players 
			return 0.28333;
			break;
		case 6:  //KQ 6 Players 
			return 0.24085;
			break;
		case 7:  //KQ 7 Players 
			return 0.20599;
			break;
		case 8:  //KQ 8 Players 
			return 0.18096;
			break;
		case 9:  //KQ 9 Players 
			return 0.15898;
			break;
		}//switch nPlayers close
	case 28:
		switch (nPlayers) {
		case 2:  //KQs 2 Players 
			return 0.6238;
			break;
		case 3:  //KQs 3 Players 
			return 0.46167;
			break;
		case 4:  //KQs 4 Players 
			return 0.3727;
			break;
		case 5:  //KQs 5 Players 
			return 0.31519;
			break;
		case 6:  //KQs 6 Players 
			return 0.27246;
			break;
		case 7:  //KQs 7 Players 
			return 0.24166;
			break;
		case 8:  //KQs 8 Players 
			return 0.21699;
			break;
		case 9:  //KQs 9 Players 
			return 0.19292;
			break;
		}//switch nPlayers close
	case 29:
		switch (nPlayers) {
		case 2:  //KJ 2 Players 
			return 0.59466;
			break;
		case 3:  //KJ 3 Players 
			return 0.41947;
			break;
		case 4:  //KJ 4 Players 
			return 0.3258;
			break;
		case 5:  //KJ 5 Players 
			return 0.26661;
			break;
		case 6:  //KJ 6 Players 
			return 0.22472;
			break;
		case 7:  //KJ 7 Players 
			return 0.19044;
			break;
		case 8:  //KJ 8 Players 
			return 0.16465;
			break;
		case 9:  //KJ 9 Players 
			return 0.14618;
			break;
		}//switch nPlayers close
	case 30:
		switch (nPlayers) {
		case 2:  //KJs 2 Players 
			return 0.61678;
			break;
		case 3:  //KJs 3 Players 
			return 0.44707;
			break;
		case 4:  //KJs 4 Players 
			return 0.35731;
			break;
		case 5:  //KJs 5 Players 
			return 0.30014;
			break;
		case 6:  //KJs 6 Players 
			return 0.25871;
			break;
		case 7:  //KJs 7 Players 
			return 0.22761;
			break;
		case 8:  //KJs 8 Players 
			return 0.20179;
			break;
		case 9:  //KJs 9 Players 
			return 0.18221;
			break;
		}//switch nPlayers close
	case 31:
		switch (nPlayers) {
		case 2:  //KT 2 Players 
			return 0.5874;
			break;
		case 3:  //KT 3 Players 
			return 0.40618;
			break;
		case 4:  //KT 4 Players 
			return 0.31285;
			break;
		case 5:  //KT 5 Players 
			return 0.25189;
			break;
		case 6:  //KT 6 Players 
			return 0.21112;
			break;
		case 7:  //KT 7 Players 
			return 0.17897;
			break;
		case 8:  //KT 8 Players 
			return 0.15391;
			break;
		case 9:  //KT 9 Players 
			return 0.13327;
			break;
		}//switch nPlayers close
	case 32:
		switch (nPlayers) {
		case 2:  //KTs 2 Players 
			return 0.60785;
			break;
		case 3:  //KTs 3 Players 
			return 0.43485;
			break;
		case 4:  //KTs 4 Players 
			return 0.34454;
			break;
		case 5:  //KTs 5 Players 
			return 0.28752;
			break;
		case 6:  //KTs 6 Players 
			return 0.24839;
			break;
		case 7:  //KTs 7 Players 
			return 0.2149;
			break;
		case 8:  //KTs 8 Players 
			return 0.19155;
			break;
		case 9:  //KTs 9 Players 
			return 0.1721;
			break;
		}//switch nPlayers close
	case 33:
		switch (nPlayers) {
		case 2:  //K9 2 Players 
			return 0.56268;
			break;
		case 3:  //K9 3 Players 
			return 0.38052;
			break;
		case 4:  //K9 4 Players 
			return 0.27951;
			break;
		case 5:  //K9 5 Players 
			return 0.22261;
			break;
		case 6:  //K9 6 Players 
			return 0.18379;
			break;
		case 7:  //K9 7 Players 
			return 0.15025;
			break;
		case 8:  //K9 8 Players 
			return 0.12784;
			break;
		case 9:  //K9 9 Players 
			return 0.112;
			break;
		}//switch nPlayers close
	case 34:
		switch (nPlayers) {
		case 2:  //K9s 2 Players 
			return 0.58504;
			break;
		case 3:  //K9s 3 Players 
			return 0.41106;
			break;
		case 4:  //K9s 4 Players 
			return 0.31515;
			break;
		case 5:  //K9s 5 Players 
			return 0.26088;
			break;
		case 6:  //K9s 6 Players 
			return 0.221;
			break;
		case 7:  //K9s 7 Players 
			return 0.19158;
			break;
		case 8:  //K9s 8 Players 
			return 0.17053;
			break;
		case 9:  //K9s 9 Players 
			return 0.15307;
			break;
		}//switch nPlayers close
	case 35:
		switch (nPlayers) {
		case 2:  //K8 2 Players 
			return 0.54385;
			break;
		case 3:  //K8 3 Players 
			return 0.35334;
			break;
		case 4:  //K8 4 Players 
			return 0.25568;
			break;
		case 5:  //K8 5 Players 
			return 0.19822;
			break;
		case 6:  //K8 6 Players 
			return 0.15889;
			break;
		case 7:  //K8 7 Players 
			return 0.13351;
			break;
		case 8:  //K8 8 Players 
			return 0.11069;
			break;
		case 9:  //K8 9 Players 
			return 0.0959;
			break;
		}//switch nPlayers close
	case 36:
		switch (nPlayers) {
		case 2:  //K8s 2 Players 
			return 0.57005;
			break;
		case 3:  //K8s 3 Players 
			return 0.38857;
			break;
		case 4:  //K8s 4 Players 
			return 0.29232;
			break;
		case 5:  //K8s 5 Players 
			return 0.23748;
			break;
		case 6:  //K8s 6 Players 
			return 0.20297;
			break;
		case 7:  //K8s 7 Players 
			return 0.17495;
			break;
		case 8:  //K8s 8 Players 
			return 0.15484;
			break;
		case 9:  //K8s 9 Players 
			return 0.13704;
			break;
		}//switch nPlayers close
	case 37:
		switch (nPlayers) {
		case 2:  //K7 2 Players 
			return 0.53375;
			break;
		case 3:  //K7 3 Players 
			return 0.34082;
			break;
		case 4:  //K7 4 Players 
			return 0.24528;
			break;
		case 5:  //K7 5 Players 
			return 0.18835;
			break;
		case 6:  //K7 6 Players 
			return 0.15337;
			break;
		case 7:  //K7 7 Players 
			return 0.12454;
			break;
		case 8:  //K7 8 Players 
			return 0.10513;
			break;
		case 9:  //K7 9 Players 
			return 0.08898;
			break;
		}//switch nPlayers close
	case 38:
		switch (nPlayers) {
		case 2:  //K7s 2 Players 
			return 0.55806;
			break;
		case 3:  //K7s 3 Players 
			return 0.37658;
			break;
		case 4:  //K7s 4 Players 
			return 0.28249;
			break;
		case 5:  //K7s 5 Players 
			return 0.22926;
			break;
		case 6:  //K7s 6 Players 
			return 0.1913;
			break;
		case 7:  //K7s 7 Players 
			return 0.16686;
			break;
		case 8:  //K7s 8 Players 
			return 0.1463;
			break;
		case 9:  //K7s 9 Players 
			return 0.13226;
			break;
		}//switch nPlayers close
	case 39:
		switch (nPlayers) {
		case 2:  //K6 2 Players 
			return 0.52193;
			break;
		case 3:  //K6 3 Players 
			return 0.32938;
			break;
		case 4:  //K6 4 Players 
			return 0.23692;
			break;
		case 5:  //K6 5 Players 
			return 0.17949;
			break;
		case 6:  //K6 6 Players 
			return 0.14394;
			break;
		case 7:  //K6 7 Players 
			return 0.11841;
			break;
		case 8:  //K6 8 Players 
			return 0.0997;
			break;
		case 9:  //K6 9 Players 
			return 0.08376;
			break;
		}//switch nPlayers close
	case 40:
		switch (nPlayers) {
		case 2:  //K6s 2 Players 
			return 0.54713;
			break;
		case 3:  //K6s 3 Players 
			return 0.36307;
			break;
		case 4:  //K6s 4 Players 
			return 0.27138;
			break;
		case 5:  //K6s 5 Players 
			return 0.21996;
			break;
		case 6:  //K6s 6 Players 
			return 0.1843;
			break;
		case 7:  //K6s 7 Players 
			return 0.15987;
			break;
		case 8:  //K6s 8 Players 
			return 0.14399;
			break;
		case 9:  //K6s 9 Players 
			return 0.12829;
			break;
		}//switch nPlayers close
	case 41:
		switch (nPlayers) {
		case 2:  //K5 2 Players 
			return 0.51355;
			break;
		case 3:  //K5 3 Players 
			return 0.31989;
			break;
		case 4:  //K5 4 Players 
			return 0.22521;
			break;
		case 5:  //K5 5 Players 
			return 0.17206;
			break;
		case 6:  //K5 6 Players 
			return 0.13858;
			break;
		case 7:  //K5 7 Players 
			return 0.11597;
			break;
		case 8:  //K5 8 Players 
			return 0.09441;
			break;
		case 9:  //K5 9 Players 
			return 0.07989;
			break;
		}//switch nPlayers close
	case 42:
		switch (nPlayers) {
		case 2:  //K5s 2 Players 
			return 0.53638;
			break;
		case 3:  //K5s 3 Players 
			return 0.35841;
			break;
		case 4:  //K5s 4 Players 
			return 0.26766;
			break;
		case 5:  //K5s 5 Players 
			return 0.21577;
			break;
		case 6:  //K5s 6 Players 
			return 0.17824;
			break;
		case 7:  //K5s 7 Players 
			return 0.15529;
			break;
		case 8:  //K5s 8 Players 
			return 0.1377;
			break;
		case 9:  //K5s 9 Players 
			return 0.12557;
			break;
		}//switch nPlayers close
	case 43:
		switch (nPlayers) {
		case 2:  //K4 2 Players 
			return 0.50469;
			break;
		case 3:  //K4 3 Players 
			return 0.31025;
			break;
		case 4:  //K4 4 Players 
			return 0.21922;
			break;
		case 5:  //K4 5 Players 
			return 0.16672;
			break;
		case 6:  //K4 6 Players 
			return 0.1338;
			break;
		case 7:  //K4 7 Players 
			return 0.10905;
			break;
		case 8:  //K4 8 Players 
			return 0.09023;
			break;
		case 9:  //K4 9 Players 
			return 0.07808;
			break;
		}//switch nPlayers close
	case 44:
		switch (nPlayers) {
		case 2:  //K4s 2 Players 
			return 0.52711;
			break;
		case 3:  //K4s 3 Players 
			return 0.34767;
			break;
		case 4:  //K4s 4 Players 
			return 0.25935;
			break;
		case 5:  //K4s 5 Players 
			return 0.20702;
			break;
		case 6:  //K4s 6 Players 
			return 0.17563;
			break;
		case 7:  //K4s 7 Players 
			return 0.15348;
			break;
		case 8:  //K4s 8 Players 
			return 0.13254;
			break;
		case 9:  //K4s 9 Players 
			return 0.12233;
			break;
		}//switch nPlayers close
	case 45:
		switch (nPlayers) {
		case 2:  //K3 2 Players 
			return 0.49273;
			break;
		case 3:  //K3 3 Players 
			return 0.30112;
			break;
		case 4:  //K3 4 Players 
			return 0.20946;
			break;
		case 5:  //K3 5 Players 
			return 0.16029;
			break;
		case 6:  //K3 6 Players 
			return 0.12716;
			break;
		case 7:  //K3 7 Players 
			return 0.10667;
			break;
		case 8:  //K3 8 Players 
			return 0.09067;
			break;
		case 9:  //K3 9 Players 
			return 0.077;
			break;
		}//switch nPlayers close
	case 46:
		switch (nPlayers) {
		case 2:  //K3s 2 Players 
			return 0.51971;
			break;
		case 3:  //K3s 3 Players 
			return 0.33897;
			break;
		case 4:  //K3s 4 Players 
			return 0.2511;
			break;
		case 5:  //K3s 5 Players 
			return 0.20311;
			break;
		case 6:  //K3s 6 Players 
			return 0.17173;
			break;
		case 7:  //K3s 7 Players 
			return 0.15088;
			break;
		case 8:  //K3s 8 Players 
			return 0.13361;
			break;
		case 9:  //K3s 9 Players 
			return 0.11953;
			break;
		}//switch nPlayers close
	case 47:
		switch (nPlayers) {
		case 2:  //K2 2 Players 
			return 0.48728;
			break;
		case 3:  //K2 3 Players 
			return 0.29233;
			break;
		case 4:  //K2 4 Players 
			return 0.20387;
			break;
		case 5:  //K2 5 Players 
			return 0.15749;
			break;
		case 6:  //K2 6 Players 
			return 0.12612;
			break;
		case 7:  //K2 7 Players 
			return 0.10374;
			break;
		case 8:  //K2 8 Players 
			return 0.08879;
			break;
		case 9:  //K2 9 Players 
			return 0.07626;
			break;
		}//switch nPlayers close
	case 48:
		switch (nPlayers) {
		case 2:  //K2s 2 Players 
			return 0.51603;
			break;
		case 3:  //K2s 3 Players 
			return 0.33138;
			break;
		case 4:  //K2s 4 Players 
			return 0.24833;
			break;
		case 5:  //K2s 5 Players 
			return 0.19982;
			break;
		case 6:  //K2s 6 Players 
			return 0.16897;
			break;
		case 7:  //K2s 7 Players 
			return 0.14611;
			break;
		case 8:  //K2s 8 Players 
			return 0.13047;
			break;
		case 9:  //K2s 9 Players 
			return 0.12032;
			break;
		}//switch nPlayers close
	case 49:
		switch (nPlayers) {
		case 2:  //QQ 2 Players 
			return 0.79538;
			break;
		case 3:  //QQ 3 Players 
			return 0.64767;
			break;
		case 4:  //QQ 4 Players 
			return 0.53493;
			break;
		case 5:  //QQ 5 Players 
			return 0.44527;
			break;
		case 6:  //QQ 6 Players 
			return 0.37549;
			break;
		case 7:  //QQ 7 Players 
			return 0.32425;
			break;
		case 8:  //QQ 8 Players 
			return 0.27912;
			break;
		case 9:  //QQ 9 Players 
			return 0.24378;
			break;
		}//switch nPlayers close
	case 50:
		switch (nPlayers) {
		case 2:  //QJ 2 Players 
			return 0.57102;
			break;
		case 3:  //QJ 3 Players 
			return 0.40264;
			break;
		case 4:  //QJ 4 Players 
			return 0.31595;
			break;
		case 5:  //QJ 5 Players 
			return 0.25645;
			break;
		case 6:  //QJ 6 Players 
			return 0.21679;
			break;
		case 7:  //QJ 7 Players 
			return 0.18497;
			break;
		case 8:  //QJ 8 Players 
			return 0.16235;
			break;
		case 9:  //QJ 9 Players 
			return 0.14392;
			break;
		}//switch nPlayers close
	case 51:
		switch (nPlayers) {
		case 2:  //QJs 2 Players 
			return 0.59146;
			break;
		case 3:  //QJs 3 Players 
			return 0.43033;
			break;
		case 4:  //QJs 4 Players 
			return 0.34578;
			break;
		case 5:  //QJs 5 Players 
			return 0.29337;
			break;
		case 6:  //QJs 6 Players 
			return 0.25393;
			break;
		case 7:  //QJs 7 Players 
			return 0.22064;
			break;
		case 8:  //QJs 8 Players 
			return 0.19856;
			break;
		case 9:  //QJs 9 Players 
			return 0.17993;
			break;
		}//switch nPlayers close
	case 52:
		switch (nPlayers) {
		case 2:  //QT 2 Players 
			return 0.56279;
			break;
		case 3:  //QT 3 Players 
			return 0.38907;
			break;
		case 4:  //QT 4 Players 
			return 0.30071;
			break;
		case 5:  //QT 5 Players 
			return 0.24492;
			break;
		case 6:  //QT 6 Players 
			return 0.20427;
			break;
		case 7:  //QT 7 Players 
			return 0.17314;
			break;
		case 8:  //QT 8 Players 
			return 0.15096;
			break;
		case 9:  //QT 9 Players 
			return 0.13204;
			break;
		}//switch nPlayers close
	case 53:
		switch (nPlayers) {
		case 2:  //QTs 2 Players 
			return 0.58138;
			break;
		case 3:  //QTs 3 Players 
			return 0.41837;
			break;
		case 4:  //QTs 4 Players 
			return 0.33394;
			break;
		case 5:  //QTs 5 Players 
			return 0.2795;
			break;
		case 6:  //QTs 6 Players 
			return 0.24135;
			break;
		case 7:  //QTs 7 Players 
			return 0.20979;
			break;
		case 8:  //QTs 8 Players 
			return 0.18852;
			break;
		case 9:  //QTs 9 Players 
			return 0.16924;
			break;
		}//switch nPlayers close
	case 54:
		switch (nPlayers) {
		case 2:  //Q9 2 Players 
			return 0.53833;
			break;
		case 3:  //Q9 3 Players 
			return 0.3596;
			break;
		case 4:  //Q9 4 Players 
			return 0.27171;
			break;
		case 5:  //Q9 5 Players 
			return 0.21657;
			break;
		case 6:  //Q9 6 Players 
			return 0.17819;
			break;
		case 7:  //Q9 7 Players 
			return 0.14886;
			break;
		case 8:  //Q9 8 Players 
			return 0.12422;
			break;
		case 9:  //Q9 9 Players 
			return 0.10915;
			break;
		}//switch nPlayers close
	case 55:
		switch (nPlayers) {
		case 2:  //Q9s 2 Players 
			return 0.56199;
			break;
		case 3:  //Q9s 3 Players 
			return 0.39338;
			break;
		case 4:  //Q9s 4 Players 
			return 0.30561;
			break;
		case 5:  //Q9s 5 Players 
			return 0.25127;
			break;
		case 6:  //Q9s 6 Players 
			return 0.21417;
			break;
		case 7:  //Q9s 7 Players 
			return 0.18677;
			break;
		case 8:  //Q9s 8 Players 
			return 0.16608;
			break;
		case 9:  //Q9s 9 Players 
			return 0.15055;
			break;
		}//switch nPlayers close
	case 56:
		switch (nPlayers) {
		case 2:  //Q8 2 Players 
			return 0.51799;
			break;
		case 3:  //Q8 3 Players 
			return 0.33943;
			break;
		case 4:  //Q8 4 Players 
			return 0.24811;
			break;
		case 5:  //Q8 5 Players 
			return 0.1915;
			break;
		case 6:  //Q8 6 Players 
			return 0.15726;
			break;
		case 7:  //Q8 7 Players 
			return 0.13066;
			break;
		case 8:  //Q8 8 Players 
			return 0.10887;
			break;
		case 9:  //Q8 9 Players 
			return 0.09349;
			break;
		}//switch nPlayers close
	case 57:
		switch (nPlayers) {
		case 2:  //Q8s 2 Players 
			return 0.54402;
			break;
		case 3:  //Q8s 3 Players 
			return 0.37336;
			break;
		case 4:  //Q8s 4 Players 
			return 0.28521;
			break;
		case 5:  //Q8s 5 Players 
			return 0.23101;
			break;
		case 6:  //Q8s 6 Players 
			return 0.19409;
			break;
		case 7:  //Q8s 7 Players 
			return 0.17075;
			break;
		case 8:  //Q8s 8 Players 
			return 0.15138;
			break;
		case 9:  //Q8s 9 Players 
			return 0.13493;
			break;
		}//switch nPlayers close
	case 58:
		switch (nPlayers) {
		case 2:  //Q7 2 Players 
			return 0.49767;
			break;
		case 3:  //Q7 3 Players 
			return 0.31499;
			break;
		case 4:  //Q7 4 Players 
			return 0.22731;
			break;
		case 5:  //Q7 5 Players 
			return 0.17275;
			break;
		case 6:  //Q7 6 Players 
			return 0.13556;
			break;
		case 7:  //Q7 7 Players 
			return 0.11159;
			break;
		case 8:  //Q7 8 Players 
			return 0.09537;
			break;
		case 9:  //Q7 9 Players 
			return 0.07923;
			break;
		}//switch nPlayers close
	case 59:
		switch (nPlayers) {
		case 2:  //Q7s 2 Players 
			return 0.52434;
			break;
		case 3:  //Q7s 3 Players 
			return 0.3498;
			break;
		case 4:  //Q7s 4 Players 
			return 0.26274;
			break;
		case 5:  //Q7s 5 Players 
			return 0.21292;
			break;
		case 6:  //Q7s 6 Players 
			return 0.17773;
			break;
		case 7:  //Q7s 7 Players 
			return 0.15367;
			break;
		case 8:  //Q7s 8 Players 
			return 0.13582;
			break;
		case 9:  //Q7s 9 Players 
			return 0.12041;
			break;
		}//switch nPlayers close
	case 60:
		switch (nPlayers) {
		case 2:  //Q6 2 Players 
			return 0.49099;
			break;
		case 3:  //Q6 3 Players 
			return 0.30752;
			break;
		case 4:  //Q6 4 Players 
			return 0.21594;
			break;
		case 5:  //Q6 5 Players 
			return 0.16567;
			break;
		case 6:  //Q6 6 Players 
			return 0.1303;
			break;
		case 7:  //Q6 7 Players 
			return 0.10427;
			break;
		case 8:  //Q6 8 Players 
			return 0.08872;
			break;
		case 9:  //Q6 9 Players 
			return 0.07587;
			break;
		}//switch nPlayers close
	case 61:
		switch (nPlayers) {
		case 2:  //Q6s 2 Players 
			return 0.5172;
			break;
		case 3:  //Q6s 3 Players 
			return 0.33963;
			break;
		case 4:  //Q6s 4 Players 
			return 0.25303;
			break;
		case 5:  //Q6s 5 Players 
			return 0.20653;
			break;
		case 6:  //Q6s 6 Players 
			return 0.17252;
			break;
		case 7:  //Q6s 7 Players 
			return 0.14684;
			break;
		case 8:  //Q6s 8 Players 
			return 0.13103;
			break;
		case 9:  //Q6s 9 Players 
			return 0.11703;
			break;
		}//switch nPlayers close
	case 62:
		switch (nPlayers) {
		case 2:  //Q5 2 Players 
			return 0.47966;
			break;
		case 3:  //Q5 3 Players 
			return 0.29535;
			break;
		case 4:  //Q5 4 Players 
			return 0.20745;
			break;
		case 5:  //Q5 5 Players 
			return 0.15733;
			break;
		case 6:  //Q5 6 Players 
			return 0.12552;
			break;
		case 7:  //Q5 7 Players 
			return 0.10223;
			break;
		case 8:  //Q5 8 Players 
			return 0.08423;
			break;
		case 9:  //Q5 9 Players 
			return 0.07232;
			break;
		}//switch nPlayers close
	case 63:
		switch (nPlayers) {
		case 2:  //Q5s 2 Players 
			return 0.50858;
			break;
		case 3:  //Q5s 3 Players 
			return 0.33098;
			break;
		case 4:  //Q5s 4 Players 
			return 0.24803;
			break;
		case 5:  //Q5s 5 Players 
			return 0.19976;
			break;
		case 6:  //Q5s 6 Players 
			return 0.16532;
			break;
		case 7:  //Q5s 7 Players 
			return 0.14275;
			break;
		case 8:  //Q5s 8 Players 
			return 0.12658;
			break;
		case 9:  //Q5s 9 Players 
			return 0.11446;
			break;
		}//switch nPlayers close
	case 64:
		switch (nPlayers) {
		case 2:  //Q4 2 Players 
			return 0.46896;
			break;
		case 3:  //Q4 3 Players 
			return 0.28568;
			break;
		case 4:  //Q4 4 Players 
			return 0.19987;
			break;
		case 5:  //Q4 5 Players 
			return 0.15117;
			break;
		case 6:  //Q4 6 Players 
			return 0.12102;
			break;
		case 7:  //Q4 7 Players 
			return 0.09785;
			break;
		case 8:  //Q4 8 Players 
			return 0.08158;
			break;
		case 9:  //Q4 9 Players 
			return 0.06945;
			break;
		}//switch nPlayers close
	case 65:
		switch (nPlayers) {
		case 2:  //Q4s 2 Players 
			return 0.49541;
			break;
		case 3:  //Q4s 3 Players 
			return 0.32312;
			break;
		case 4:  //Q4s 4 Players 
			return 0.23976;
			break;
		case 5:  //Q4s 5 Players 
			return 0.19482;
			break;
		case 6:  //Q4s 6 Players 
			return 0.16114;
			break;
		case 7:  //Q4s 7 Players 
			return 0.14104;
			break;
		case 8:  //Q4s 8 Players 
			return 0.12525;
			break;
		case 9:  //Q4s 9 Players 
			return 0.1109;
			break;
		}//switch nPlayers close
	case 66:
		switch (nPlayers) {
		case 2:  //Q3 2 Players 
			return 0.45861;
			break;
		case 3:  //Q3 3 Players 
			return 0.27689;
			break;
		case 4:  //Q3 4 Players 
			return 0.19428;
			break;
		case 5:  //Q3 5 Players 
			return 0.14763;
			break;
		case 6:  //Q3 6 Players 
			return 0.11518;
			break;
		case 7:  //Q3 7 Players 
			return 0.0941;
			break;
		case 8:  //Q3 8 Players 
			return 0.07973;
			break;
		case 9:  //Q3 9 Players 
			return 0.06794;
			break;
		}//switch nPlayers close
	case 67:
		switch (nPlayers) {
		case 2:  //Q3s 2 Players 
			return 0.48946;
			break;
		case 3:  //Q3s 3 Players 
			return 0.31611;
			break;
		case 4:  //Q3s 4 Players 
			return 0.23352;
			break;
		case 5:  //Q3s 5 Players 
			return 0.19133;
			break;
		case 6:  //Q3s 6 Players 
			return 0.16101;
			break;
		case 7:  //Q3s 7 Players 
			return 0.13754;
			break;
		case 8:  //Q3s 8 Players 
			return 0.12498;
			break;
		case 9:  //Q3s 9 Players 
			return 0.11327;
			break;
		}//switch nPlayers close
	case 68:
		switch (nPlayers) {
		case 2:  //Q2 2 Players 
			return 0.45051;
			break;
		case 3:  //Q2 3 Players 
			return 0.2668;
			break;
		case 4:  //Q2 4 Players 
			return 0.18782;
			break;
		case 5:  //Q2 5 Players 
			return 0.14067;
			break;
		case 6:  //Q2 6 Players 
			return 0.1117;
			break;
		case 7:  //Q2 7 Players 
			return 0.09333;
			break;
		case 8:  //Q2 8 Players 
			return 0.07869;
			break;
		case 9:  //Q2 9 Players 
			return 0.06664;
			break;
		}//switch nPlayers close
	case 69:
		switch (nPlayers) {
		case 2:  //Q2s 2 Players 
			return 0.48357;
			break;
		case 3:  //Q2s 3 Players 
			return 0.30949;
			break;
		case 4:  //Q2s 4 Players 
			return 0.22598;
			break;
		case 5:  //Q2s 5 Players 
			return 0.18267;
			break;
		case 6:  //Q2s 6 Players 
			return 0.15516;
			break;
		case 7:  //Q2s 7 Players 
			return 0.13434;
			break;
		case 8:  //Q2s 8 Players 
			return 0.12117;
			break;
		case 9:  //Q2s 9 Players 
			return 0.10804;
			break;
		}//switch nPlayers close
	case 70:
		switch (nPlayers) {
		case 2:  //JJ 2 Players 
			return 0.77008;
			break;
		case 3:  //JJ 3 Players 
			return 0.60746;
			break;
		case 4:  //JJ 4 Players 
			return 0.48533;
			break;
		case 5:  //JJ 5 Players 
			return 0.40044;
			break;
		case 6:  //JJ 6 Players 
			return 0.33314;
			break;
		case 7:  //JJ 7 Players 
			return 0.27823;
			break;
		case 8:  //JJ 8 Players 
			return 0.24185;
			break;
		case 9:  //JJ 9 Players 
			return 0.2133;
			break;
		}//switch nPlayers close
	case 71:
		switch (nPlayers) {
		case 2:  //JT 2 Players 
			return 0.53595;
			break;
		case 3:  //JT 3 Players 
			return 0.37508;
			break;
		case 4:  //JT 4 Players 
			return 0.29407;
			break;
		case 5:  //JT 5 Players 
			return 0.24251;
			break;
		case 6:  //JT 6 Players 
			return 0.20218;
			break;
		case 7:  //JT 7 Players 
			return 0.17309;
			break;
		case 8:  //JT 8 Players 
			return 0.1516;
			break;
		case 9:  //JT 9 Players 
			return 0.13283;
			break;
		}//switch nPlayers close
	case 72:
		switch (nPlayers) {
		case 2:  //JTs 2 Players 
			return 0.56269;
			break;
		case 3:  //JTs 3 Players 
			return 0.40801;
			break;
		case 4:  //JTs 4 Players 
			return 0.32706;
			break;
		case 5:  //JTs 5 Players 
			return 0.27405;
			break;
		case 6:  //JTs 6 Players 
			return 0.23775;
			break;
		case 7:  //JTs 7 Players 
			return 0.20837;
			break;
		case 8:  //JTs 8 Players 
			return 0.18515;
			break;
		case 9:  //JTs 9 Players 
			return 0.16756;
			break;
		}//switch nPlayers close
	case 73:
		switch (nPlayers) {
		case 2:  //J9 2 Players 
			return 0.51802;
			break;
		case 3:  //J9 3 Players 
			return 0.3499;
			break;
		case 4:  //J9 4 Players 
			return 0.26325;
			break;
		case 5:  //J9 5 Players 
			return 0.21454;
			break;
		case 6:  //J9 6 Players 
			return 0.17539;
			break;
		case 7:  //J9 7 Players 
			return 0.14961;
			break;
		case 8:  //J9 8 Players 
			return 0.12744;
			break;
		case 9:  //J9 9 Players 
			return 0.11109;
			break;
		}//switch nPlayers close
	case 74:
		switch (nPlayers) {
		case 2:  //J9s 2 Players 
			return 0.54351;
			break;
		case 3:  //J9s 3 Players 
			return 0.38109;
			break;
		case 4:  //J9s 4 Players 
			return 0.30162;
			break;
		case 5:  //J9s 5 Players 
			return 0.24886;
			break;
		case 6:  //J9s 6 Players 
			return 0.21142;
			break;
		case 7:  //J9s 7 Players 
			return 0.18413;
			break;
		case 8:  //J9s 8 Players 
			return 0.16478;
			break;
		case 9:  //J9s 9 Players 
			return 0.14741;
			break;
		}//switch nPlayers close
	case 75:
		switch (nPlayers) {
		case 2:  //J8 2 Players 
			return 0.49675;
			break;
		case 3:  //J8 3 Players 
			return 0.32771;
			break;
		case 4:  //J8 4 Players 
			return 0.24361;
			break;
		case 5:  //J8 5 Players 
			return 0.18978;
			break;
		case 6:  //J8 6 Players 
			return 0.15551;
			break;
		case 7:  //J8 7 Players 
			return 0.12917;
			break;
		case 8:  //J8 8 Players 
			return 0.11157;
			break;
		case 9:  //J8 9 Players 
			return 0.09611;
			break;
		}//switch nPlayers close
	case 76:
		switch (nPlayers) {
		case 2:  //J8s 2 Players 
			return 0.52512;
			break;
		case 3:  //J8s 3 Players 
			return 0.3579;
			break;
		case 4:  //J8s 4 Players 
			return 0.27749;
			break;
		case 5:  //J8s 5 Players 
			return 0.22745;
			break;
		case 6:  //J8s 6 Players 
			return 0.19381;
			break;
		case 7:  //J8s 7 Players 
			return 0.17017;
			break;
		case 8:  //J8s 8 Players 
			return 0.14936;
			break;
		case 9:  //J8s 9 Players 
			return 0.13322;
			break;
		}//switch nPlayers close
	case 77:
		switch (nPlayers) {
		case 2:  //J7 2 Players 
			return 0.4809;
			break;
		case 3:  //J7 3 Players 
			return 0.30556;
			break;
		case 4:  //J7 4 Players 
			return 0.22055;
			break;
		case 5:  //J7 5 Players 
			return 0.17231;
			break;
		case 6:  //J7 6 Players 
			return 0.13673;
			break;
		case 7:  //J7 7 Players 
			return 0.11292;
			break;
		case 8:  //J7 8 Players 
			return 0.09251;
			break;
		case 9:  //J7 9 Players 
			return 0.07927;
			break;
		}//switch nPlayers close
	case 78:
		switch (nPlayers) {
		case 2:  //J7s 2 Players 
			return 0.50535;
			break;
		case 3:  //J7s 3 Players 
			return 0.33717;
			break;
		case 4:  //J7s 4 Players 
			return 0.25596;
			break;
		case 5:  //J7s 5 Players 
			return 0.20903;
			break;
		case 6:  //J7s 6 Players 
			return 0.17675;
			break;
		case 7:  //J7s 7 Players 
			return 0.15455;
			break;
		case 8:  //J7s 8 Players 
			return 0.13391;
			break;
		case 9:  //J7s 9 Players 
			return 0.12098;
			break;
		}//switch nPlayers close
	case 79:
		switch (nPlayers) {
		case 2:  //J6 2 Players 
			return 0.45442;
			break;
		case 3:  //J6 3 Players 
			return 0.28074;
			break;
		case 4:  //J6 4 Players 
			return 0.20033;
			break;
		case 5:  //J6 5 Players 
			return 0.15073;
			break;
		case 6:  //J6 6 Players 
			return 0.11958;
			break;
		case 7:  //J6 7 Players 
			return 0.09812;
			break;
		case 8:  //J6 8 Players 
			return 0.08084;
			break;
		case 9:  //J6 9 Players 
			return 0.06843;
			break;
		}//switch nPlayers close
	case 80:
		switch (nPlayers) {
		case 2:  //J6s 2 Players 
			return 0.48312;
			break;
		case 3:  //J6s 3 Players 
			return 0.31678;
			break;
		case 4:  //J6s 4 Players 
			return 0.23912;
			break;
		case 5:  //J6s 5 Players 
			return 0.19259;
			break;
		case 6:  //J6s 6 Players 
			return 0.1633;
			break;
		case 7:  //J6s 7 Players 
			return 0.1391;
			break;
		case 8:  //J6s 8 Players 
			return 0.12171;
			break;
		case 9:  //J6s 9 Players 
			return 0.11024;
			break;
		}//switch nPlayers close
	case 81:
		switch (nPlayers) {
		case 2:  //J5 2 Players 
			return 0.44817;
			break;
		case 3:  //J5 3 Players 
			return 0.27313;
			break;
		case 4:  //J5 4 Players 
			return 0.19031;
			break;
		case 5:  //J5 5 Players 
			return 0.14361;
			break;
		case 6:  //J5 6 Players 
			return 0.11459;
			break;
		case 7:  //J5 7 Players 
			return 0.09272;
			break;
		case 8:  //J5 8 Players 
			return 0.07735;
			break;
		case 9:  //J5 9 Players 
			return 0.06451;
			break;
		}//switch nPlayers close
	case 82:
		switch (nPlayers) {
		case 2:  //J5s 2 Players 
			return 0.47894;
			break;
		case 3:  //J5s 3 Players 
			return 0.31216;
			break;
		case 4:  //J5s 4 Players 
			return 0.23249;
			break;
		case 5:  //J5s 5 Players 
			return 0.18655;
			break;
		case 6:  //J5s 6 Players 
			return 0.15625;
			break;
		case 7:  //J5s 7 Players 
			return 0.13476;
			break;
		case 8:  //J5s 8 Players 
			return 0.11788;
			break;
		case 9:  //J5s 9 Players 
			return 0.10603;
			break;
		}//switch nPlayers close
	case 83:
		switch (nPlayers) {
		case 2:  //J4 2 Players 
			return 0.43745;
			break;
		case 3:  //J4 3 Players 
			return 0.26632;
			break;
		case 4:  //J4 4 Players 
			return 0.18572;
			break;
		case 5:  //J4 5 Players 
			return 0.13915;
			break;
		case 6:  //J4 6 Players 
			return 0.11096;
			break;
		case 7:  //J4 7 Players 
			return 0.08798;
			break;
		case 8:  //J4 8 Players 
			return 0.07396;
			break;
		case 9:  //J4 9 Players 
			return 0.06352;
			break;
		}//switch nPlayers close
	case 84:
		switch (nPlayers) {
		case 2:  //J4s 2 Players 
			return 0.46999;
			break;
		case 3:  //J4s 3 Players 
			return 0.30244;
			break;
		case 4:  //J4s 4 Players 
			return 0.22606;
			break;
		case 5:  //J4s 5 Players 
			return 0.18077;
			break;
		case 6:  //J4s 6 Players 
			return 0.15227;
			break;
		case 7:  //J4s 7 Players 
			return 0.1312;
			break;
		case 8:  //J4s 8 Players 
			return 0.11716;
			break;
		case 9:  //J4s 9 Players 
			return 0.10414;
			break;
		}//switch nPlayers close
	case 85:
		switch (nPlayers) {
		case 2:  //J3 2 Players 
			return 0.43369;
			break;
		case 3:  //J3 3 Players 
			return 0.25622;
			break;
		case 4:  //J3 4 Players 
			return 0.17586;
			break;
		case 5:  //J3 5 Players 
			return 0.13524;
			break;
		case 6:  //J3 6 Players 
			return 0.10677;
			break;
		case 7:  //J3 7 Players 
			return 0.08585;
			break;
		case 8:  //J3 8 Players 
			return 0.07241;
			break;
		case 9:  //J3 9 Players 
			return 0.06341;
			break;
		}//switch nPlayers close
	case 86:
		switch (nPlayers) {
		case 2:  //J3s 2 Players 
			return 0.46073;
			break;
		case 3:  //J3s 3 Players 
			return 0.29689;
			break;
		case 4:  //J3s 4 Players 
			return 0.21784;
			break;
		case 5:  //J3s 5 Players 
			return 0.17516;
			break;
		case 6:  //J3s 6 Players 
			return 0.14764;
			break;
		case 7:  //J3s 7 Players 
			return 0.12917;
			break;
		case 8:  //J3s 8 Players 
			return 0.11501;
			break;
		case 9:  //J3s 9 Players 
			return 0.10169;
			break;
		}//switch nPlayers close
	case 87:
		switch (nPlayers) {
		case 2:  //J2 2 Players 
			return 0.42068;
			break;
		case 3:  //J2 3 Players 
			return 0.24648;
			break;
		case 4:  //J2 4 Players 
			return 0.17221;
			break;
		case 5:  //J2 5 Players 
			return 0.13105;
			break;
		case 6:  //J2 6 Players 
			return 0.10316;
			break;
		case 7:  //J2 7 Players 
			return 0.08408;
			break;
		case 8:  //J2 8 Players 
			return 0.07082;
			break;
		case 9:  //J2 9 Players 
			return 0.06173;
			break;
		}//switch nPlayers close
	case 88:
		switch (nPlayers) {
		case 2:  //J2s 2 Players 
			return 0.45294;
			break;
		case 3:  //J2s 3 Players 
			return 0.28835;
			break;
		case 4:  //J2s 4 Players 
			return 0.21224;
			break;
		case 5:  //J2s 5 Players 
			return 0.17257;
			break;
		case 6:  //J2s 6 Players 
			return 0.14338;
			break;
		case 7:  //J2s 7 Players 
			return 0.12832;
			break;
		case 8:  //J2s 8 Players 
			return 0.11292;
			break;
		case 9:  //J2s 9 Players 
			return 0.10101;
			break;
		}//switch nPlayers close
	case 89:
		switch (nPlayers) {
		case 2:  //TT 2 Players 
			return 0.7444;
			break;
		case 3:  //TT 3 Players 
			return 0.57296;
			break;
		case 4:  //TT 4 Players 
			return 0.44957;
			break;
		case 5:  //TT 5 Players 
			return 0.36107;
			break;
		case 6:  //TT 6 Players 
			return 0.29187;
			break;
		case 7:  //TT 7 Players 
			return 0.24731;
			break;
		case 8:  //TT 8 Players 
			return 0.21287;
			break;
		case 9:  //TT 9 Players 
			return 0.18579;
			break;
		}//switch nPlayers close
	case 90:
		switch (nPlayers) {
		case 2:  //T9 2 Players 
			return 0.50007;
			break;
		case 3:  //T9 3 Players 
			return 0.34219;
			break;
		case 4:  //T9 4 Players 
			return 0.26363;
			break;
		case 5:  //T9 5 Players 
			return 0.21352;
			break;
		case 6:  //T9 6 Players 
			return 0.17786;
			break;
		case 7:  //T9 7 Players 
			return 0.14994;
			break;
		case 8:  //T9 8 Players 
			return 0.12935;
			break;
		case 9:  //T9 9 Players 
			return 0.11413;
			break;
		}//switch nPlayers close
	case 91:
		switch (nPlayers) {
		case 2:  //T9s 2 Players 
			return 0.5255;
			break;
		case 3:  //T9s 3 Players 
			return 0.37463;
			break;
		case 4:  //T9s 4 Players 
			return 0.29698;
			break;
		case 5:  //T9s 5 Players 
			return 0.24945;
			break;
		case 6:  //T9s 6 Players 
			return 0.21469;
			break;
		case 7:  //T9s 7 Players 
			return 0.18684;
			break;
		case 8:  //T9s 8 Players 
			return 0.1661;
			break;
		case 9:  //T9s 9 Players 
			return 0.15081;
			break;
		}//switch nPlayers close
	case 92:
		switch (nPlayers) {
		case 2:  //T8 2 Players 
			return 0.4753;
			break;
		case 3:  //T8 3 Players 
			return 0.32092;
			break;
		case 4:  //T8 4 Players 
			return 0.24138;
			break;
		case 5:  //T8 5 Players 
			return 0.191;
			break;
		case 6:  //T8 6 Players 
			return 0.15716;
			break;
		case 7:  //T8 7 Players 
			return 0.13114;
			break;
		case 8:  //T8 8 Players 
			return 0.11411;
			break;
		case 9:  //T8 9 Players 
			return 0.09921;
			break;
		}//switch nPlayers close
	case 93:
		switch (nPlayers) {
		case 2:  //T8s 2 Players 
			return 0.50624;
			break;
		case 3:  //T8s 3 Players 
			return 0.355;
			break;
		case 4:  //T8s 4 Players 
			return 0.27414;
			break;
		case 5:  //T8s 5 Players 
			return 0.22945;
			break;
		case 6:  //T8s 6 Players 
			return 0.19531;
			break;
		case 7:  //T8s 7 Players 
			return 0.17023;
			break;
		case 8:  //T8s 8 Players 
			return 0.15156;
			break;
		case 9:  //T8s 9 Players 
			return 0.13688;
			break;
		}//switch nPlayers close
	case 94:
		switch (nPlayers) {
		case 2:  //T7 2 Players 
			return 0.4584;
			break;
		case 3:  //T7 3 Players 
			return 0.29416;
			break;
		case 4:  //T7 4 Players 
			return 0.21708;
			break;
		case 5:  //T7 5 Players 
			return 0.17236;
			break;
		case 6:  //T7 6 Players 
			return 0.13628;
			break;
		case 7:  //T7 7 Players 
			return 0.11525;
			break;
		case 8:  //T7 8 Players 
			return 0.09746;
			break;
		case 9:  //T7 9 Players 
			return 0.08373;
			break;
		}//switch nPlayers close
	case 95:
		switch (nPlayers) {
		case 2:  //T7s 2 Players 
			return 0.48679;
			break;
		case 3:  //T7s 3 Players 
			return 0.33287;
			break;
		case 4:  //T7s 4 Players 
			return 0.2553;
			break;
		case 5:  //T7s 5 Players 
			return 0.20921;
			break;
		case 6:  //T7s 6 Players 
			return 0.17933;
			break;
		case 7:  //T7s 7 Players 
			return 0.15275;
			break;
		case 8:  //T7s 8 Players 
			return 0.13639;
			break;
		case 9:  //T7s 9 Players 
			return 0.12272;
			break;
		}//switch nPlayers close
	case 96:
		switch (nPlayers) {
		case 2:  //T6 2 Players 
			return 0.43951;
			break;
		case 3:  //T6 3 Players 
			return 0.27204;
			break;
		case 4:  //T6 4 Players 
			return 0.19895;
			break;
		case 5:  //T6 5 Players 
			return 0.1512;
			break;
		case 6:  //T6 6 Players 
			return 0.12219;
			break;
		case 7:  //T6 7 Players 
			return 0.0984;
			break;
		case 8:  //T6 8 Players 
			return 0.08476;
			break;
		case 9:  //T6 9 Players 
			return 0.07111;
			break;
		}//switch nPlayers close
	case 97:
		switch (nPlayers) {
		case 2:  //T6s 2 Players 
			return 0.46778;
			break;
		case 3:  //T6s 3 Players 
			return 0.31285;
			break;
		case 4:  //T6s 4 Players 
			return 0.23583;
			break;
		case 5:  //T6s 5 Players 
			return 0.19199;
			break;
		case 6:  //T6s 6 Players 
			return 0.16076;
			break;
		case 7:  //T6s 7 Players 
			return 0.13886;
			break;
		case 8:  //T6s 8 Players 
			return 0.12428;
			break;
		case 9:  //T6s 9 Players 
			return 0.11144;
			break;
		}//switch nPlayers close
	case 98:
		switch (nPlayers) {
		case 2:  //T5 2 Players 
			return 0.42111;
			break;
		case 3:  //T5 3 Players 
			return 0.25526;
			break;
		case 4:  //T5 4 Players 
			return 0.17749;
			break;
		case 5:  //T5 5 Players 
			return 0.13332;
			break;
		case 6:  //T5 6 Players 
			return 0.10792;
			break;
		case 7:  //T5 7 Players 
			return 0.08637;
			break;
		case 8:  //T5 8 Players 
			return 0.07011;
			break;
		case 9:  //T5 9 Players 
			return 0.06034;
			break;
		}//switch nPlayers close
	case 99:
		switch (nPlayers) {
		case 2:  //T5s 2 Players 
			return 0.4496;
			break;
		case 3:  //T5s 3 Players 
			return 0.28996;
			break;
		case 4:  //T5s 4 Players 
			return 0.21895;
			break;
		case 5:  //T5s 5 Players 
			return 0.17502;
			break;
		case 6:  //T5s 6 Players 
			return 0.14609;
			break;
		case 7:  //T5s 7 Players 
			return 0.127;
			break;
		case 8:  //T5s 8 Players 
			return 0.11408;
			break;
		case 9:  //T5s 9 Players 
			return 0.10039;
			break;
		}//switch nPlayers close
	case 100:
		switch (nPlayers) {
		case 2:  //T4 2 Players 
			return 0.4135;
			break;
		case 3:  //T4 3 Players 
			return 0.24593;
			break;
		case 4:  //T4 4 Players 
			return 0.17278;
			break;
		case 5:  //T4 5 Players 
			return 0.12899;
			break;
		case 6:  //T4 6 Players 
			return 0.10325;
			break;
		case 7:  //T4 7 Players 
			return 0.08368;
			break;
		case 8:  //T4 8 Players 
			return 0.06739;
			break;
		case 9:  //T4 9 Players 
			return 0.05874;
			break;
		}//switch nPlayers close
	case 101:
		switch (nPlayers) {
		case 2:  //T4s 2 Players 
			return 0.4462;
			break;
		case 3:  //T4s 3 Players 
			return 0.28524;
			break;
		case 4:  //T4s 4 Players 
			return 0.21281;
			break;
		case 5:  //T4s 5 Players 
			return 0.16952;
			break;
		case 6:  //T4s 6 Players 
			return 0.14381;
			break;
		case 7:  //T4s 7 Players 
			return 0.12387;
			break;
		case 8:  //T4s 8 Players 
			return 0.11082;
			break;
		case 9:  //T4s 9 Players 
			return 0.10096;
			break;
		}//switch nPlayers close
	case 102:
		switch (nPlayers) {
		case 2:  //T3 2 Players 
			return 0.40195;
			break;
		case 3:  //T3 3 Players 
			return 0.23945;
			break;
		case 4:  //T3 4 Players 
			return 0.16544;
			break;
		case 5:  //T3 5 Players 
			return 0.12262;
			break;
		case 6:  //T3 6 Players 
			return 0.09869;
			break;
		case 7:  //T3 7 Players 
			return 0.07911;
			break;
		case 8:  //T3 8 Players 
			return 0.06793;
			break;
		case 9:  //T3 9 Players 
			return 0.05635;
			break;
		}//switch nPlayers close
	case 103:
		switch (nPlayers) {
		case 2:  //T3s 2 Players 
			return 0.43454;
			break;
		case 3:  //T3s 3 Players 
			return 0.27851;
			break;
		case 4:  //T3s 4 Players 
			return 0.20703;
			break;
		case 5:  //T3s 5 Players 
			return 0.16923;
			break;
		case 6:  //T3s 6 Players 
			return 0.14168;
			break;
		case 7:  //T3s 7 Players 
			return 0.12067;
			break;
		case 8:  //T3s 8 Players 
			return 0.10925;
			break;
		case 9:  //T3s 9 Players 
			return 0.09858;
			break;
		}//switch nPlayers close
	case 104:
		switch (nPlayers) {
		case 2:  //T2 2 Players 
			return 0.39169;
			break;
		case 3:  //T2 3 Players 
			return 0.2306;
			break;
		case 4:  //T2 4 Players 
			return 0.16023;
			break;
		case 5:  //T2 5 Players 
			return 0.11938;
			break;
		case 6:  //T2 6 Players 
			return 0.09527;
			break;
		case 7:  //T2 7 Players 
			return 0.0783;
			break;
		case 8:  //T2 8 Players 
			return 0.06476;
			break;
		case 9:  //T2 9 Players 
			return 0.05631;
			break;
		}//switch nPlayers close
	case 105:
		switch (nPlayers) {
		case 2:  //T2s 2 Players 
			return 0.42398;
			break;
		case 3:  //T2s 3 Players 
			return 0.27178;
			break;
		case 4:  //T2s 4 Players 
			return 0.20224;
			break;
		case 5:  //T2s 5 Players 
			return 0.16112;
			break;
		case 6:  //T2s 6 Players 
			return 0.13615;
			break;
		case 7:  //T2s 7 Players 
			return 0.11985;
			break;
		case 8:  //T2s 8 Players 
			return 0.10615;
			break;
		case 9:  //T2s 9 Players 
			return 0.09689;
			break;
		}//switch nPlayers close
	case 106:
		switch (nPlayers) {
		case 2:  //99 2 Players 
			return 0.71608;
			break;
		case 3:  //99 3 Players 
			return 0.53301;
			break;
		case 4:  //99 4 Players 
			return 0.41092;
			break;
		case 5:  //99 5 Players 
			return 0.32243;
			break;
		case 6:  //99 6 Players 
			return 0.26377;
			break;
		case 7:  //99 7 Players 
			return 0.2196;
			break;
		case 8:  //99 8 Players 
			return 0.19109;
			break;
		case 9:  //99 9 Players 
			return 0.16812;
			break;
		}//switch nPlayers close
	case 107:
		switch (nPlayers) {
		case 2:  //98 2 Players 
			return 0.46173;
			break;
		case 3:  //98 3 Players 
			return 0.31168;
			break;
		case 4:  //98 4 Players 
			return 0.23525;
			break;
		case 5:  //98 5 Players 
			return 0.18793;
			break;
		case 6:  //98 6 Players 
			return 0.15598;
			break;
		case 7:  //98 7 Players 
			return 0.13061;
			break;
		case 8:  //98 8 Players 
			return 0.11499;
			break;
		case 9:  //98 9 Players 
			return 0.09868;
			break;
		}//switch nPlayers close
	case 108:
		switch (nPlayers) {
		case 2:  //98s 2 Players 
			return 0.48991;
			break;
		case 3:  //98s 3 Players 
			return 0.34592;
			break;
		case 4:  //98s 4 Players 
			return 0.27485;
			break;
		case 5:  //98s 5 Players 
			return 0.22475;
			break;
		case 6:  //98s 6 Players 
			return 0.19047;
			break;
		case 7:  //98s 7 Players 
			return 0.16742;
			break;
		case 8:  //98s 8 Players 
			return 0.15033;
			break;
		case 9:  //98s 9 Players 
			return 0.13458;
			break;
		}//switch nPlayers close
	case 109:
		switch (nPlayers) {
		case 2:  //97 2 Players 
			return 0.44051;
			break;
		case 3:  //97 3 Players 
			return 0.29174;
			break;
		case 4:  //97 4 Players 
			return 0.21637;
			break;
		case 5:  //97 5 Players 
			return 0.16811;
			break;
		case 6:  //97 6 Players 
			return 0.13906;
			break;
		case 7:  //97 7 Players 
			return 0.11896;
			break;
		case 8:  //97 8 Players 
			return 0.10291;
			break;
		case 9:  //97 9 Players 
			return 0.08819;
			break;
		}//switch nPlayers close
	case 110:
		switch (nPlayers) {
		case 2:  //97s 2 Players 
			return 0.47109;
			break;
		case 3:  //97s 3 Players 
			return 0.32661;
			break;
		case 4:  //97s 4 Players 
			return 0.25444;
			break;
		case 5:  //97s 5 Players 
			return 0.21033;
			break;
		case 6:  //97s 6 Players 
			return 0.17665;
			break;
		case 7:  //97s 7 Players 
			return 0.15633;
			break;
		case 8:  //97s 8 Players 
			return 0.13822;
			break;
		case 9:  //97s 9 Players 
			return 0.12564;
			break;
		}//switch nPlayers close
	case 111:
		switch (nPlayers) {
		case 2:  //96 2 Players 
			return 0.42275;
			break;
		case 3:  //96 3 Players 
			return 0.26976;
			break;
		case 4:  //96 4 Players 
			return 0.19745;
			break;
		case 5:  //96 5 Players 
			return 0.15565;
			break;
		case 6:  //96 6 Players 
			return 0.1246;
			break;
		case 7:  //96 7 Players 
			return 0.10277;
			break;
		case 8:  //96 8 Players 
			return 0.08899;
			break;
		case 9:  //96 9 Players 
			return 0.07668;
			break;
		}//switch nPlayers close
	case 112:
		switch (nPlayers) {
		case 2:  //96s 2 Players 
			return 0.45112;
			break;
		case 3:  //96s 3 Players 
			return 0.3057;
			break;
		case 4:  //96s 4 Players 
			return 0.23462;
			break;
		case 5:  //96s 5 Players 
			return 0.19225;
			break;
		case 6:  //96s 6 Players 
			return 0.16178;
			break;
		case 7:  //96s 7 Players 
			return 0.14312;
			break;
		case 8:  //96s 8 Players 
			return 0.12678;
			break;
		case 9:  //96s 9 Players 
			return 0.11365;
			break;
		}//switch nPlayers close
	case 113:
		switch (nPlayers) {
		case 2:  //95 2 Players 
			return 0.40374;
			break;
		case 3:  //95 3 Players 
			return 0.24969;
			break;
		case 4:  //95 4 Players 
			return 0.17647;
			break;
		case 5:  //95 5 Players 
			return 0.13413;
			break;
		case 6:  //95 6 Players 
			return 0.107;
			break;
		case 7:  //95 7 Players 
			return 0.08805;
			break;
		case 8:  //95 8 Players 
			return 0.07441;
			break;
		case 9:  //95 9 Players 
			return 0.06392;
			break;
		}//switch nPlayers close
	case 114:
		switch (nPlayers) {
		case 2:  //95s 2 Players 
			return 0.4322;
			break;
		case 3:  //95s 3 Players 
			return 0.28703;
			break;
		case 4:  //95s 4 Players 
			return 0.21743;
			break;
		case 5:  //95s 5 Players 
			return 0.17267;
			break;
		case 6:  //95s 6 Players 
			return 0.14863;
			break;
		case 7:  //95s 7 Players 
			return 0.12781;
			break;
		case 8:  //95s 8 Players 
			return 0.11411;
			break;
		case 9:  //95s 9 Players 
			return 0.10261;
			break;
		}//switch nPlayers close
	case 115:
		switch (nPlayers) {
		case 2:  //94 2 Players 
			return 0.3837;
			break;
		case 3:  //94 3 Players 
			return 0.22866;
			break;
		case 4:  //94 4 Players 
			return 0.15828;
			break;
		case 5:  //94 5 Players 
			return 0.12043;
			break;
		case 6:  //94 6 Players 
			return 0.09303;
			break;
		case 7:  //94 7 Players 
			return 0.07596;
			break;
		case 8:  //94 8 Players 
			return 0.06265;
			break;
		case 9:  //94 9 Players 
			return 0.05362;
			break;
		}//switch nPlayers close
	case 116:
		switch (nPlayers) {
		case 2:  //94s 2 Players 
			return 0.41485;
			break;
		case 3:  //94s 3 Players 
			return 0.26605;
			break;
		case 4:  //94s 4 Players 
			return 0.19994;
			break;
		case 5:  //94s 5 Players 
			return 0.1607;
			break;
		case 6:  //94s 6 Players 
			return 0.13581;
			break;
		case 7:  //94s 7 Players 
			return 0.1177;
			break;
		case 8:  //94s 8 Players 
			return 0.10377;
			break;
		case 9:  //94s 9 Players 
			return 0.0934;
			break;
		}//switch nPlayers close
	case 117:
		switch (nPlayers) {
		case 2:  //93 2 Players 
			return 0.37746;
			break;
		case 3:  //93 3 Players 
			return 0.22273;
			break;
		case 4:  //93 4 Players 
			return 0.15315;
			break;
		case 5:  //93 5 Players 
			return 0.11326;
			break;
		case 6:  //93 6 Players 
			return 0.08943;
			break;
		case 7:  //93 7 Players 
			return 0.07282;
			break;
		case 8:  //93 8 Players 
			return 0.06218;
			break;
		case 9:  //93 9 Players 
			return 0.05269;
			break;
		}//switch nPlayers close
	case 118:
		switch (nPlayers) {
		case 2:  //93s 2 Players 
			return 0.40833;
			break;
		case 3:  //93s 3 Players 
			return 0.26559;
			break;
		case 4:  //93s 4 Players 
			return 0.19644;
			break;
		case 5:  //93s 5 Players 
			return 0.15907;
			break;
		case 6:  //93s 6 Players 
			return 0.13045;
			break;
		case 7:  //93s 7 Players 
			return 0.1147;
			break;
		case 8:  //93s 8 Players 
			return 0.1032;
			break;
		case 9:  //93s 9 Players 
			return 0.09273;
			break;
		}//switch nPlayers close
	case 119:
		switch (nPlayers) {
		case 2:  //92 2 Players 
			return 0.36392;
			break;
		case 3:  //92 3 Players 
			return 0.21604;
			break;
		case 4:  //92 4 Players 
			return 0.14955;
			break;
		case 5:  //92 5 Players 
			return 0.10938;
			break;
		case 6:  //92 6 Players 
			return 0.08698;
			break;
		case 7:  //92 7 Players 
			return 0.07235;
			break;
		case 8:  //92 8 Players 
			return 0.05831;
			break;
		case 9:  //92 9 Players 
			return 0.05178;
			break;
		}//switch nPlayers close
	case 120:
		switch (nPlayers) {
		case 2:  //92s 2 Players 
			return 0.40256;
			break;
		case 3:  //92s 3 Players 
			return 0.25569;
			break;
		case 4:  //92s 4 Players 
			return 0.19004;
			break;
		case 5:  //92s 5 Players 
			return 0.15233;
			break;
		case 6:  //92s 6 Players 
			return 0.13049;
			break;
		case 7:  //92s 7 Players 
			return 0.11339;
			break;
		case 8:  //92s 8 Players 
			return 0.10118;
			break;
		case 9:  //92s 9 Players 
			return 0.09064;
			break;
		}//switch nPlayers close
	case 121:
		switch (nPlayers) {
		case 2:  //88 2 Players 
			return 0.68827;
			break;
		case 3:  //88 3 Players 
			return 0.4938;
			break;
		case 4:  //88 4 Players 
			return 0.37388;
			break;
		case 5:  //88 5 Players 
			return 0.29158;
			break;
		case 6:  //88 6 Players 
			return 0.23742;
			break;
		case 7:  //88 7 Players 
			return 0.2007;
			break;
		case 8:  //88 8 Players 
			return 0.17357;
			break;
		case 9:  //88 9 Players 
			return 0.15528;
			break;
		}//switch nPlayers close
	case 122:
		switch (nPlayers) {
		case 2:  //87 2 Players 
			return 0.42808;
			break;
		case 3:  //87 3 Players 
			return 0.28881;
			break;
		case 4:  //87 4 Players 
			return 0.21693;
			break;
		case 5:  //87 5 Players 
			return 0.17181;
			break;
		case 6:  //87 6 Players 
			return 0.13888;
			break;
		case 7:  //87 7 Players 
			return 0.12013;
			break;
		case 8:  //87 8 Players 
			return 0.10363;
			break;
		case 9:  //87 9 Players 
			return 0.09111;
			break;
		}//switch nPlayers close
	case 123:
		switch (nPlayers) {
		case 2:  //87s 2 Players 
			return 0.45859;
			break;
		case 3:  //87s 3 Players 
			return 0.32323;
			break;
		case 4:  //87s 4 Players 
			return 0.25547;
			break;
		case 5:  //87s 5 Players 
			return 0.20841;
			break;
		case 6:  //87s 6 Players 
			return 0.17921;
			break;
		case 7:  //87s 7 Players 
			return 0.15777;
			break;
		case 8:  //87s 8 Players 
			return 0.144;
			break;
		case 9:  //87s 9 Players 
			return 0.12841;
			break;
		}//switch nPlayers close
	case 124:
		switch (nPlayers) {
		case 2:  //86 2 Players 
			return 0.40668;
			break;
		case 3:  //86 3 Players 
			return 0.26881;
			break;
		case 4:  //86 4 Players 
			return 0.19963;
			break;
		case 5:  //86 5 Players 
			return 0.15513;
			break;
		case 6:  //86 6 Players 
			return 0.1286;
			break;
		case 7:  //86 7 Players 
			return 0.1071;
			break;
		case 8:  //86 8 Players 
			return 0.09133;
			break;
		case 9:  //86 9 Players 
			return 0.08156;
			break;
		}//switch nPlayers close
	case 125:
		switch (nPlayers) {
		case 2:  //86s 2 Players 
			return 0.43947;
			break;
		case 3:  //86s 3 Players 
			return 0.30499;
			break;
		case 4:  //86s 4 Players 
			return 0.23731;
			break;
		case 5:  //86s 5 Players 
			return 0.19371;
			break;
		case 6:  //86s 6 Players 
			return 0.16575;
			break;
		case 7:  //86s 7 Players 
			return 0.14582;
			break;
		case 8:  //86s 8 Players 
			return 0.13323;
			break;
		case 9:  //86s 9 Players 
			return 0.11887;
			break;
		}//switch nPlayers close
	case 126:
		switch (nPlayers) {
		case 2:  //85 2 Players 
			return 0.38956;
			break;
		case 3:  //85 3 Players 
			return 0.24762;
			break;
		case 4:  //85 4 Players 
			return 0.17887;
			break;
		case 5:  //85 5 Players 
			return 0.13968;
			break;
		case 6:  //85 6 Players 
			return 0.11336;
			break;
		case 7:  //85 7 Players 
			return 0.09306;
			break;
		case 8:  //85 8 Players 
			return 0.08062;
			break;
		case 9:  //85 9 Players 
			return 0.07224;
			break;
		}//switch nPlayers close
	case 127:
		switch (nPlayers) {
		case 2:  //85s 2 Players 
			return 0.42172;
			break;
		case 3:  //85s 3 Players 
			return 0.28609;
			break;
		case 4:  //85s 4 Players 
			return 0.21996;
			break;
		case 5:  //85s 5 Players 
			return 0.1783;
			break;
		case 6:  //85s 6 Players 
			return 0.15104;
			break;
		case 7:  //85s 7 Players 
			return 0.13485;
			break;
		case 8:  //85s 8 Players 
			return 0.12048;
			break;
		case 9:  //85s 9 Players 
			return 0.10802;
			break;
		}//switch nPlayers close
	case 128:
		switch (nPlayers) {
		case 2:  //84 2 Players 
			return 0.36683;
			break;
		case 3:  //84 3 Players 
			return 0.22832;
			break;
		case 4:  //84 4 Players 
			return 0.1597;
			break;
		case 5:  //84 5 Players 
			return 0.1223;
			break;
		case 6:  //84 6 Players 
			return 0.09882;
			break;
		case 7:  //84 7 Players 
			return 0.07966;
			break;
		case 8:  //84 8 Players 
			return 0.06896;
			break;
		case 9:  //84 9 Players 
			return 0.05904;
			break;
		}//switch nPlayers close
	case 129:
		switch (nPlayers) {
		case 2:  //84s 2 Players 
			return 0.40205;
			break;
		case 3:  //84s 3 Players 
			return 0.26673;
			break;
		case 4:  //84s 4 Players 
			return 0.20461;
			break;
		case 5:  //84s 5 Players 
			return 0.16433;
			break;
		case 6:  //84s 6 Players 
			return 0.13824;
			break;
		case 7:  //84s 7 Players 
			return 0.12153;
			break;
		case 8:  //84s 8 Players 
			return 0.1108;
			break;
		case 9:  //84s 9 Players 
			return 0.09798;
			break;
		}//switch nPlayers close
	case 130:
		switch (nPlayers) {
		case 2:  //83 2 Players 
			return 0.34675;
			break;
		case 3:  //83 3 Players 
			return 0.20701;
			break;
		case 4:  //83 4 Players 
			return 0.1439;
			break;
		case 5:  //83 5 Players 
			return 0.10909;
			break;
		case 6:  //83 6 Players 
			return 0.08393;
			break;
		case 7:  //83 7 Players 
			return 0.0689;
			break;
		case 8:  //83 8 Players 
			return 0.05755;
			break;
		case 9:  //83 9 Players 
			return 0.04908;
			break;
		}//switch nPlayers close
	case 131:
		switch (nPlayers) {
		case 2:  //83s 2 Players 
			return 0.3842;
			break;
		case 3:  //83s 3 Players 
			return 0.25034;
			break;
		case 4:  //83s 4 Players 
			return 0.18605;
			break;
		case 5:  //83s 5 Players 
			return 0.14967;
			break;
		case 6:  //83s 6 Players 
			return 0.12704;
			break;
		case 7:  //83s 7 Players 
			return 0.11173;
			break;
		case 8:  //83s 8 Players 
			return 0.09848;
			break;
		case 9:  //83s 9 Players 
			return 0.08957;
			break;
		}//switch nPlayers close
	case 132:
		switch (nPlayers) {
		case 2:  //82 2 Players 
			return 0.34143;
			break;
		case 3:  //82 3 Players 
			return 0.2021;
			break;
		case 4:  //82 4 Players 
			return 0.13853;
			break;
		case 5:  //82 5 Players 
			return 0.10313;
			break;
		case 6:  //82 6 Players 
			return 0.08185;
			break;
		case 7:  //82 7 Players 
			return 0.06691;
			break;
		case 8:  //82 8 Players 
			return 0.05652;
			break;
		case 9:  //82 9 Players 
			return 0.04761;
			break;
		}//switch nPlayers close
	case 133:
		switch (nPlayers) {
		case 2:  //82s 2 Players 
			return 0.38043;
			break;
		case 3:  //82s 3 Players 
			return 0.2443;
			break;
		case 4:  //82s 4 Players 
			return 0.18237;
			break;
		case 5:  //82s 5 Players 
			return 0.14965;
			break;
		case 6:  //82s 6 Players 
			return 0.12465;
			break;
		case 7:  //82s 7 Players 
			return 0.10768;
			break;
		case 8:  //82s 8 Players 
			return 0.09836;
			break;
		case 9:  //82s 9 Players 
			return 0.08827;
			break;
		}//switch nPlayers close
	case 134:
		switch (nPlayers) {
		case 2:  //77 2 Players 
			return 0.65437;
			break;
		case 3:  //77 3 Players 
			return 0.46059;
			break;
		case 4:  //77 4 Players 
			return 0.34324;
			break;
		case 5:  //77 5 Players 
			return 0.2638;
			break;
		case 6:  //77 6 Players 
			return 0.21627;
			break;
		case 7:  //77 7 Players 
			return 0.1823;
			break;
		case 8:  //77 8 Players 
			return 0.16181;
			break;
		case 9:  //77 9 Players 
			return 0.14347;
			break;
		}//switch nPlayers close
	case 135:
		switch (nPlayers) {
		case 2:  //76 2 Players 
			return 0.40015;
			break;
		case 3:  //76 3 Players 
			return 0.26948;
			break;
		case 4:  //76 4 Players 
			return 0.20009;
			break;
		case 5:  //76 5 Players 
			return 0.15896;
			break;
		case 6:  //76 6 Players 
			return 0.13046;
			break;
		case 7:  //76 7 Players 
			return 0.11303;
			break;
		case 8:  //76 8 Players 
			return 0.09786;
			break;
		case 9:  //76 9 Players 
			return 0.08615;
			break;
		}//switch nPlayers close
	case 136:
		switch (nPlayers) {
		case 2:  //76s 2 Players 
			return 0.43169;
			break;
		case 3:  //76s 3 Players 
			return 0.3038;
			break;
		case 4:  //76s 4 Players 
			return 0.23943;
			break;
		case 5:  //76s 5 Players 
			return 0.19662;
			break;
		case 6:  //76s 6 Players 
			return 0.16983;
			break;
		case 7:  //76s 7 Players 
			return 0.15122;
			break;
		case 8:  //76s 8 Players 
			return 0.13496;
			break;
		case 9:  //76s 9 Players 
			return 0.12533;
			break;
		}//switch nPlayers close
	case 137:
		switch (nPlayers) {
		case 2:  //75 2 Players 
			return 0.38102;
			break;
		case 3:  //75 3 Players 
			return 0.24985;
			break;
		case 4:  //75 4 Players 
			return 0.18129;
			break;
		case 5:  //75 5 Players 
			return 0.14342;
			break;
		case 6:  //75 6 Players 
			return 0.11866;
			break;
		case 7:  //75 7 Players 
			return 0.1007;
			break;
		case 8:  //75 8 Players 
			return 0.08767;
			break;
		case 9:  //75 9 Players 
			return 0.07767;
			break;
		}//switch nPlayers close
	case 138:
		switch (nPlayers) {
		case 2:  //75s 2 Players 
			return 0.41085;
			break;
		case 3:  //75s 3 Players 
			return 0.28558;
			break;
		case 4:  //75s 4 Players 
			return 0.21931;
			break;
		case 5:  //75s 5 Players 
			return 0.18349;
			break;
		case 6:  //75s 6 Players 
			return 0.15568;
			break;
		case 7:  //75s 7 Players 
			return 0.13847;
			break;
		case 8:  //75s 8 Players 
			return 0.12553;
			break;
		case 9:  //75s 9 Players 
			return 0.11656;
			break;
		}//switch nPlayers close
	case 139:
		switch (nPlayers) {
		case 2:  //74 2 Players 
			return 0.3578;
			break;
		case 3:  //74 3 Players 
			return 0.22886;
			break;
		case 4:  //74 4 Players 
			return 0.16382;
			break;
		case 5:  //74 5 Players 
			return 0.12807;
			break;
		case 6:  //74 6 Players 
			return 0.10436;
			break;
		case 7:  //74 7 Players 
			return 0.08584;
			break;
		case 8:  //74 8 Players 
			return 0.07548;
			break;
		case 9:  //74 9 Players 
			return 0.06694;
			break;
		}//switch nPlayers close
	case 140:
		switch (nPlayers) {
		case 2:  //74s 2 Players 
			return 0.39177;
			break;
		case 3:  //74s 3 Players 
			return 0.26667;
			break;
		case 4:  //74s 4 Players 
			return 0.20297;
			break;
		case 5:  //74s 5 Players 
			return 0.17044;
			break;
		case 6:  //74s 6 Players 
			return 0.14316;
			break;
		case 7:  //74s 7 Players 
			return 0.12518;
			break;
		case 8:  //74s 8 Players 
			return 0.11418;
			break;
		case 9:  //74s 9 Players 
			return 0.10511;
			break;
		}//switch nPlayers close
	case 141:
		switch (nPlayers) {
		case 2:  //73 2 Players 
			return 0.33916;
			break;
		case 3:  //73 3 Players 
			return 0.21014;
			break;
		case 4:  //73 4 Players 
			return 0.14848;
			break;
		case 5:  //73 5 Players 
			return 0.11236;
			break;
		case 6:  //73 6 Players 
			return 0.09002;
			break;
		case 7:  //73 7 Players 
			return 0.07344;
			break;
		case 8:  //73 8 Players 
			return 0.06362;
			break;
		case 9:  //73 9 Players 
			return 0.05521;
			break;
		}//switch nPlayers close
	case 142:
		switch (nPlayers) {
		case 2:  //73s 2 Players 
			return 0.37377;
			break;
		case 3:  //73s 3 Players 
			return 0.24703;
			break;
		case 4:  //73s 4 Players 
			return 0.18718;
			break;
		case 5:  //73s 5 Players 
			return 0.15524;
			break;
		case 6:  //73s 6 Players 
			return 0.13077;
			break;
		case 7:  //73s 7 Players 
			return 0.11382;
			break;
		case 8:  //73s 8 Players 
			return 0.10366;
			break;
		case 9:  //73s 9 Players 
			return 0.09446;
			break;
		}//switch nPlayers close
	case 143:
		switch (nPlayers) {
		case 2:  //72 2 Players 
			return 0.3203;
			break;
		case 3:  //72 3 Players 
			return 0.19101;
			break;
		case 4:  //72 4 Players 
			return 0.12987;
			break;
		case 5:  //72 5 Players 
			return 0.09746;
			break;
		case 6:  //72 6 Players 
			return 0.0771;
			break;
		case 7:  //72 7 Players 
			return 0.0647;
			break;
		case 8:  //72 8 Players 
			return 0.05449;
			break;
		case 9:  //72 9 Players 
			return 0.04707;
			break;
		}//switch nPlayers close
	case 144:
		switch (nPlayers) {
		case 2:  //72s 2 Players 
			return 0.3553;
			break;
		case 3:  //72s 3 Players 
			return 0.22966;
			break;
		case 4:  //72s 4 Players 
			return 0.17347;
			break;
		case 5:  //72s 5 Players 
			return 0.14008;
			break;
		case 6:  //72s 6 Players 
			return 0.12067;
			break;
		case 7:  //72s 7 Players 
			return 0.10442;
			break;
		case 8:  //72s 8 Players 
			return 0.09548;
			break;
		case 9:  //72s 9 Players 
			return 0.08485;
			break;
		}//switch nPlayers close
	case 145:
		switch (nPlayers) {
		case 2:  //66 2 Players 
			return 0.62941;
			break;
		case 3:  //66 3 Players 
			return 0.42535;
			break;
		case 4:  //66 4 Players 
			return 0.3112;
			break;
		case 5:  //66 5 Players 
			return 0.24281;
			break;
		case 6:  //66 6 Players 
			return 0.19714;
			break;
		case 7:  //66 7 Players 
			return 0.16951;
			break;
		case 8:  //66 8 Players 
			return 0.15089;
			break;
		case 9:  //66 9 Players 
			return 0.13625;
			break;
		}//switch nPlayers close
	case 146:
		switch (nPlayers) {
		case 2:  //65 2 Players 
			return 0.37165;
			break;
		case 3:  //65 3 Players 
			return 0.2489;
			break;
		case 4:  //65 4 Players 
			return 0.18597;
			break;
		case 5:  //65 5 Players 
			return 0.14557;
			break;
		case 6:  //65 6 Players 
			return 0.12216;
			break;
		case 7:  //65 7 Players 
			return 0.10293;
			break;
		case 8:  //65 8 Players 
			return 0.09262;
			break;
		case 9:  //65 9 Players 
			return 0.0826;
			break;
		}//switch nPlayers close
	case 147:
		switch (nPlayers) {
		case 2:  //65s 2 Players 
			return 0.4055;
			break;
		case 3:  //65s 3 Players 
			return 0.28442;
			break;
		case 4:  //65s 4 Players 
			return 0.22677;
			break;
		case 5:  //65s 5 Players 
			return 0.18385;
			break;
		case 6:  //65s 6 Players 
			return 0.16095;
			break;
		case 7:  //65s 7 Players 
			return 0.14346;
			break;
		case 8:  //65s 8 Players 
			return 0.12912;
			break;
		case 9:  //65s 9 Players 
			return 0.11875;
			break;
		}//switch nPlayers close
	case 148:
		switch (nPlayers) {
		case 2:  //64 2 Players 
			return 0.35061;
			break;
		case 3:  //64 3 Players 
			return 0.23241;
			break;
		case 4:  //64 4 Players 
			return 0.16937;
			break;
		case 5:  //64 5 Players 
			return 0.13331;
			break;
		case 6:  //64 6 Players 
			return 0.10954;
			break;
		case 7:  //64 7 Players 
			return 0.09365;
			break;
		case 8:  //64 8 Players 
			return 0.08125;
			break;
		case 9:  //64 9 Players 
			return 0.0743;
			break;
		}//switch nPlayers close
	case 149:
		switch (nPlayers) {
		case 2:  //64s 2 Players 
			return 0.38668;
			break;
		case 3:  //64s 3 Players 
			return 0.27016;
			break;
		case 4:  //64s 4 Players 
			return 0.20798;
			break;
		case 5:  //64s 5 Players 
			return 0.17191;
			break;
		case 6:  //64s 6 Players 
			return 0.14924;
			break;
		case 7:  //64s 7 Players 
			return 0.13212;
			break;
		case 8:  //64s 8 Players 
			return 0.12058;
			break;
		case 9:  //64s 9 Players 
			return 0.11014;
			break;
		}//switch nPlayers close
	case 150:
		switch (nPlayers) {
		case 2:  //63 2 Players 
			return 0.33195;
			break;
		case 3:  //63 3 Players 
			return 0.21214;
			break;
		case 4:  //63 4 Players 
			return 0.15306;
			break;
		case 5:  //63 5 Players 
			return 0.11778;
			break;
		case 6:  //63 6 Players 
			return 0.09784;
			break;
		case 7:  //63 7 Players 
			return 0.07992;
			break;
		case 8:  //63 8 Players 
			return 0.07251;
			break;
		case 9:  //63 9 Players 
			return 0.06309;
			break;
		}//switch nPlayers close
	case 151:
		switch (nPlayers) {
		case 2:  //63s 2 Players 
			return 0.36583;
			break;
		case 3:  //63s 3 Players 
			return 0.25274;
			break;
		case 4:  //63s 4 Players 
			return 0.19371;
			break;
		case 5:  //63s 5 Players 
			return 0.16027;
			break;
		case 6:  //63s 6 Players 
			return 0.13744;
			break;
		case 7:  //63s 7 Players 
			return 0.12019;
			break;
		case 8:  //63s 8 Players 
			return 0.11149;
			break;
		case 9:  //63s 9 Players 
			return 0.10029;
			break;
		}//switch nPlayers close
	case 152:
		switch (nPlayers) {
		case 2:  //62 2 Players 
			return 0.31362;
			break;
		case 3:  //62 3 Players 
			return 0.19262;
			break;
		case 4:  //62 4 Players 
			return 0.13512;
			break;
		case 5:  //62 5 Players 
			return 0.10277;
			break;
		case 6:  //62 6 Players 
			return 0.08216;
			break;
		case 7:  //62 7 Players 
			return 0.07004;
			break;
		case 8:  //62 8 Players 
			return 0.06005;
			break;
		case 9:  //62 9 Players 
			return 0.05306;
			break;
		}//switch nPlayers close
	case 153:
		switch (nPlayers) {
		case 2:  //62s 2 Players 
			return 0.35134;
			break;
		case 3:  //62s 3 Players 
			return 0.23445;
			break;
		case 4:  //62s 4 Players 
			return 0.17618;
			break;
		case 5:  //62s 5 Players 
			return 0.14467;
			break;
		case 6:  //62s 6 Players 
			return 0.12627;
			break;
		case 7:  //62s 7 Players 
			return 0.10918;
			break;
		case 8:  //62s 8 Players 
			return 0.09877;
			break;
		case 9:  //62s 9 Players 
			return 0.09131;
			break;
		}//switch nPlayers close
	case 154:
		switch (nPlayers) {
		case 2:  //55 2 Players 
			return 0.59574;
			break;
		case 3:  //55 3 Players 
			return 0.3977;
			break;
		case 4:  //55 4 Players 
			return 0.28559;
			break;
		case 5:  //55 5 Players 
			return 0.2235;
			break;
		case 6:  //55 6 Players 
			return 0.18122;
			break;
		case 7:  //55 7 Players 
			return 0.15645;
			break;
		case 8:  //55 8 Players 
			return 0.13937;
			break;
		case 9:  //55 9 Players 
			return 0.13054;
			break;
		}//switch nPlayers close
	case 155:
		switch (nPlayers) {
		case 2:  //54 2 Players 
			return 0.3502;
			break;
		case 3:  //54 3 Players 
			return 0.23762;
			break;
		case 4:  //54 4 Players 
			return 0.17524;
			break;
		case 5:  //54 5 Players 
			return 0.13891;
			break;
		case 6:  //54 6 Players 
			return 0.1153;
			break;
		case 7:  //54 7 Players 
			return 0.09946;
			break;
		case 8:  //54 8 Players 
			return 0.08737;
			break;
		case 9:  //54 9 Players 
			return 0.07913;
			break;
		}//switch nPlayers close
	case 156:
		switch (nPlayers) {
		case 2:  //54s 2 Players 
			return 0.38715;
			break;
		case 3:  //54s 3 Players 
			return 0.27565;
			break;
		case 4:  //54s 4 Players 
			return 0.21263;
			break;
		case 5:  //54s 5 Players 
			return 0.17881;
			break;
		case 6:  //54s 6 Players 
			return 0.15535;
			break;
		case 7:  //54s 7 Players 
			return 0.13793;
			break;
		case 8:  //54s 8 Players 
			return 0.12576;
			break;
		case 9:  //54s 9 Players 
			return 0.11532;
			break;
		}//switch nPlayers close
	case 157:
		switch (nPlayers) {
		case 2:  //53 2 Players 
			return 0.3336;
			break;
		case 3:  //53 3 Players 
			return 0.21794;
			break;
		case 4:  //53 4 Players 
			return 0.15998;
			break;
		case 5:  //53 5 Players 
			return 0.12667;
			break;
		case 6:  //53 6 Players 
			return 0.10352;
			break;
		case 7:  //53 7 Players 
			return 0.08865;
			break;
		case 8:  //53 8 Players 
			return 0.07848;
			break;
		case 9:  //53 9 Players 
			return 0.07029;
			break;
		}//switch nPlayers close
	case 158:
		switch (nPlayers) {
		case 2:  //53s 2 Players 
			return 0.36811;
			break;
		case 3:  //53s 3 Players 
			return 0.26149;
			break;
		case 4:  //53s 4 Players 
			return 0.20017;
			break;
		case 5:  //53s 5 Players 
			return 0.1655;
			break;
		case 6:  //53s 6 Players 
			return 0.14497;
			break;
		case 7:  //53s 7 Players 
			return 0.12972;
			break;
		case 8:  //53s 8 Players 
			return 0.1179;
			break;
		case 9:  //53s 9 Players 
			return 0.10854;
			break;
		}//switch nPlayers close
	case 159:
		switch (nPlayers) {
		case 2:  //52 2 Players 
			return 0.31541;
			break;
		case 3:  //52 3 Players 
			return 0.19981;
			break;
		case 4:  //52 4 Players 
			return 0.14533;
			break;
		case 5:  //52 5 Players 
			return 0.11016;
			break;
		case 6:  //52 6 Players 
			return 0.09213;
			break;
		case 7:  //52 7 Players 
			return 0.0773;
			break;
		case 8:  //52 8 Players 
			return 0.06904;
			break;
		case 9:  //52 9 Players 
			return 0.06125;
			break;
		}//switch nPlayers close
	case 160:
		switch (nPlayers) {
		case 2:  //52s 2 Players 
			return 0.34656;
			break;
		case 3:  //52s 3 Players 
			return 0.23892;
			break;
		case 4:  //52s 4 Players 
			return 0.18422;
			break;
		case 5:  //52s 5 Players 
			return 0.15296;
			break;
		case 6:  //52s 6 Players 
			return 0.13116;
			break;
		case 7:  //52s 7 Players 
			return 0.11662;
			break;
		case 8:  //52s 8 Players 
			return 0.10854;
			break;
		case 9:  //52s 9 Players 
			return 0.09727;
			break;
		}//switch nPlayers close
	case 161:
		switch (nPlayers) {
		case 2:  //44 2 Players 
			return 0.56202;
			break;
		case 3:  //44 3 Players 
			return 0.3607;
			break;
		case 4:  //44 4 Players 
			return 0.26063;
			break;
		case 5:  //44 5 Players 
			return 0.20379;
			break;
		case 6:  //44 6 Players 
			return 0.16953;
			break;
		case 7:  //44 7 Players 
			return 0.14843;
			break;
		case 8:  //44 8 Players 
			return 0.13356;
			break;
		case 9:  //44 9 Players 
			return 0.12654;
			break;
		}//switch nPlayers close
	case 162:
		switch (nPlayers) {
		case 2:  //43 2 Players 
			return 0.32008;
			break;
		case 3:  //43 3 Players 
			return 0.21218;
			break;
		case 4:  //43 4 Players 
			return 0.15536;
			break;
		case 5:  //43 5 Players 
			return 0.11807;
			break;
		case 6:  //43 6 Players 
			return 0.09955;
			break;
		case 7:  //43 7 Players 
			return 0.0864;
			break;
		case 8:  //43 8 Players 
			return 0.07319;
			break;
		case 9:  //43 9 Players 
			return 0.06788;
			break;
		}//switch nPlayers close
	case 163:
		switch (nPlayers) {
		case 2:  //43s 2 Players 
			return 0.35653;
			break;
		case 3:  //43s 3 Players 
			return 0.24944;
			break;
		case 4:  //43s 4 Players 
			return 0.19307;
			break;
		case 5:  //43s 5 Players 
			return 0.15987;
			break;
		case 6:  //43s 6 Players 
			return 0.13721;
			break;
		case 7:  //43s 7 Players 
			return 0.12193;
			break;
		case 8:  //43s 8 Players 
			return 0.113;
			break;
		case 9:  //43s 9 Players 
			return 0.10386;
			break;
		}//switch nPlayers close
	case 164:
		switch (nPlayers) {
		case 2:  //42 2 Players 
			return 0.30046;
			break;
		case 3:  //42 3 Players 
			return 0.19156;
			break;
		case 4:  //42 4 Players 
			return 0.13676;
			break;
		case 5:  //42 5 Players 
			return 0.10647;
			break;
		case 6:  //42 6 Players 
			return 0.08687;
			break;
		case 7:  //42 7 Players 
			return 0.0752;
			break;
		case 8:  //42 8 Players 
			return 0.06495;
			break;
		case 9:  //42 9 Players 
			return 0.05908;
			break;
		}//switch nPlayers close
	case 165:
		switch (nPlayers) {
		case 2:  //42s 2 Players 
			return 0.33918;
			break;
		case 3:  //42s 3 Players 
			return 0.23281;
			break;
		case 4:  //42s 4 Players 
			return 0.17852;
			break;
		case 5:  //42s 5 Players 
			return 0.14755;
			break;
		case 6:  //42s 6 Players 
			return 0.12743;
			break;
		case 7:  //42s 7 Players 
			return 0.11513;
			break;
		case 8:  //42s 8 Players 
			return 0.10508;
			break;
		case 9:  //42s 9 Players 
			return 0.09567;
			break;
		}//switch nPlayers close
	case 166:
		switch (nPlayers) {
		case 2:  //33 2 Players 
			return 0.53042;
			break;
		case 3:  //33 3 Players 
			return 0.33334;
			break;
		case 4:  //33 4 Players 
			return 0.23584;
			break;
		case 5:  //33 5 Players 
			return 0.18735;
			break;
		case 6:  //33 6 Players 
			return 0.16022;
			break;
		case 7:  //33 7 Players 
			return 0.14196;
			break;
		case 8:  //33 8 Players 
			return 0.13332;
			break;
		case 9:  //33 9 Players 
			return 0.12415;
			break;
		}//switch nPlayers close
	case 167:
		switch (nPlayers) {
		case 2:  //32 2 Players 
			return 0.29418;
			break;
		case 3:  //32 3 Players 
			return 0.18438;
			break;
		case 4:  //32 4 Players 
			return 0.13022;
			break;
		case 5:  //32 5 Players 
			return 0.10027;
			break;
		case 6:  //32 6 Players 
			return 0.0801;
			break;
		case 7:  //32 7 Players 
			return 0.07031;
			break;
		case 8:  //32 8 Players 
			return 0.06176;
			break;
		case 9:  //32 9 Players 
			return 0.05555;
			break;
		}//switch nPlayers close
	case 168:
		switch (nPlayers) {
		case 2:  //32s 2 Players 
			return 0.33208;
			break;
		case 3:  //32s 3 Players 
			return 0.22639;
			break;
		case 4:  //32s 4 Players 
			return 0.17117;
			break;
		case 5:  //32s 5 Players 
			return 0.13996;
			break;
		case 6:  //32s 6 Players 
			return 0.1234;
			break;
		case 7:  //32s 7 Players 
			return 0.11062;
			break;
		case 8:  //32s 8 Players 
			return 0.10089;
			break;
		case 9:  //32s 9 Players 
			return 0.09167;
			break;
		}//switch nPlayers close
	case 169:
		switch (nPlayers) {
		case 2:  //22 2 Players 
			return 0.494;
			break;
		case 3:  //22 3 Players 
			return 0.30328;
			break;
		case 4:  //22 4 Players 
			return 0.21608;
			break;
		case 5:  //22 5 Players 
			return 0.17627;
			break;
		case 6:  //22 6 Players 
			return 0.15414;
			break;
		case 7:  //22 7 Players 
			return 0.14059;
			break;
		case 8:  //22 8 Players 
			return 0.13097;
			break;
		case 9:  //22 9 Players 
			return 0.12492;
			break;
		}//switch nPlayers close
	}//switchPreflopNumber close


	return 0;
}

//incomplete
double prwin_calcolator::Flop_precalc_prwin(int FlopNumber, int nPlayers) {
	

	return 0;
}
double prwin_calcolator::Turn_precalc_prwin(int TurnNumber, int nPlayers) {


	return 0;
}
double prwin_calcolator::River_precalc_prwin(int RiverNumber, int nPlayers) {


	return 0;
}

int prwin_calcolator::set_preflopnumber(string card1, string card2) {
	if (card1[0] == 'A' && card2[0] == 'A') {
		preflop_card1 = 'A';
		preflop_card2 = 'A';
		nSuited = 1;
		return 1;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'K' || card2[0] == 'K')) {
		preflop_card1 = 'A';
		preflop_card2 = 'K';
		nSuited = 1;
		return 2;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'K' || card2[0] == 'K') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = 'K';
		nSuited = 2;
		return 3;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'Q' || card2[0] == 'Q')) {
		preflop_card1 = 'A';
		preflop_card2 = 'Q';
		nSuited = 1;
		return 4;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'Q' || card2[0] == 'Q') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = 'Q';
		nSuited = 2;
		return 5;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'J' || card2[0] == 'J')) {
		preflop_card1 = 'A';
		preflop_card2 = 'J';
		nSuited = 1;
		return 6;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'J' || card2[0] == 'J') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = 'J';
		nSuited = 2;
		return 7;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'T' || card2[0] == 'T')) {
		preflop_card1 = 'A';
		preflop_card2 = 'T';
		nSuited = 1;
		return 8;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == 'T' || card2[0] == 'T') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = 'T';
		nSuited = 2;
		return 9;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '9' || card2[0] == '9')) {
		preflop_card1 = 'A';
		preflop_card2 = '9';
		nSuited = 1;
		return 10;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '9' || card2[0] == '9') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '9';
		nSuited = 2;
		return 11;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = 'A';
		preflop_card2 = '8';
		nSuited = 1;
		return 12;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '8';
		nSuited = 2;
		return 13;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = 'A';
		preflop_card2 = '7';
		nSuited = 1;
		return 14;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '7';
		nSuited = 2;
		return 15;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = 'A';
		preflop_card2 = '6';
		nSuited = 1;
		return 16;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '6';
		nSuited = 2;
		return 17;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = 'A';
		preflop_card2 = '5';
		nSuited = 1;
		return 18;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '5';
		nSuited = 2;
		return 19;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = 'A';
		preflop_card2 = '4';
		nSuited = 1;
		return 20;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '4';
		nSuited = 2;
		return 21;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = 'A';
		preflop_card2 = '3';
		nSuited = 1;
		return 22;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '3';
		nSuited = 2;
		return 23;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = 'A';
		preflop_card2 = '2';
		nSuited = 1;
		return 24;
	}
	if ((card1[0] == 'A' || card2[0] == 'A') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = 'A';
		preflop_card2 = '2';
		nSuited = 2;
		return 25;
	}
	if (card1[0] == 'K' && card2[0] == 'K') {
		preflop_card1 = 'K';
		preflop_card2 = 'K';
		nSuited = 1;
		return 26;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'Q' || card2[0] == 'Q')) {
		preflop_card1 = 'K';
		preflop_card2 = 'Q';
		nSuited = 1;
		return 27;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'Q' || card2[0] == 'Q') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = 'Q';
		nSuited = 2;
		return 28;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'J' || card2[0] == 'J')) {
		preflop_card1 = 'K';
		preflop_card2 = 'J';
		nSuited = 1;
		return 29;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'J' || card2[0] == 'J') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = 'J';
		nSuited = 2;
		return 30;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'T' || card2[0] == 'T')) {
		preflop_card1 = 'K';
		preflop_card2 = 'T';
		nSuited = 1;
		return 31;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == 'T' || card2[0] == 'T') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = 'T';
		nSuited = 2;
		return 32;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '9' || card2[0] == '9')) {
		preflop_card1 = 'K';
		preflop_card2 = '9';
		nSuited = 1;
		return 33;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '9' || card2[0] == '9') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '9';
		nSuited = 2;
		return 34;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = 'K';
		preflop_card2 = '8';
		nSuited = 1;
		return 35;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '8';
		nSuited = 2;
		return 36;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = 'K';
		preflop_card2 = '7';
		nSuited = 1;
		return 37;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '7';
		nSuited = 2;
		return 38;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = 'K';
		preflop_card2 = '6';
		nSuited = 1;
		return 39;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '6';
		nSuited = 2;
		return 40;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = 'K';
		preflop_card2 = '5';
		nSuited = 1;
		return 41;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '5';
		nSuited = 2;
		return 42;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = 'K';
		preflop_card2 = '4';
		nSuited = 1;
		return 43;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '4';
		nSuited = 2;
		return 44;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = 'K';
		preflop_card2 = '3';
		nSuited = 1;
		return 45;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '3';
		nSuited = 2;
		return 46;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = 'K';
		preflop_card2 = '2';
		nSuited = 1;
		return 47;
	}
	if ((card1[0] == 'K' || card2[0] == 'K') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = 'K';
		preflop_card2 = '2';
		nSuited = 2;
		return 48;
	}
	if (card1[0] == 'Q' && card2[0] == 'Q') {
		preflop_card1 = 'Q';
		preflop_card2 = 'Q';
		nSuited = 1;
		return 49;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == 'J' || card2[0] == 'J')) {
		preflop_card1 = 'Q';
		preflop_card2 = 'J';
		nSuited = 1;
		return 50;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == 'J' || card2[0] == 'J') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = 'J';
		nSuited = 2;
		return 51;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == 'T' || card2[0] == 'T')) {
		preflop_card1 = 'Q';
		preflop_card2 = 'T';
		nSuited = 1;
		return 52;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == 'T' || card2[0] == 'T') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = 'T';
		nSuited = 2;
		return 53;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '9' || card2[0] == '9')) {
		preflop_card1 = 'Q';
		preflop_card2 = '9';
		nSuited = 1;
		return 54;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '9' || card2[0] == '9') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '9';
		nSuited = 2;
		return 55;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = 'Q';
		preflop_card2 = '8';
		nSuited = 1;
		return 56;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '8';
		nSuited = 2;
		return 57;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = 'Q';
		preflop_card2 = '7';
		nSuited = 1;
		return 58;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '7';
		nSuited = 2;
		return 59;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = 'Q';
		preflop_card2 = '6';
		nSuited = 1;
		return 60;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '6';
		nSuited = 2;
		return 61;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = 'Q';
		preflop_card2 = '5';
		nSuited = 1;
		return 62;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '5';
		nSuited = 2;
		return 63;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = 'Q';
		preflop_card2 = '4';
		nSuited = 1;
		return 64;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '4';
		nSuited = 2;
		return 65;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = 'Q';
		preflop_card2 = '3';
		nSuited = 1;
		return 66;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '3';
		nSuited = 2;
		return 67;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = 'Q';
		preflop_card2 = '2';
		nSuited = 1;
		return 68;
	}
	if ((card1[0] == 'Q' || card2[0] == 'Q') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = 'Q';
		preflop_card2 = '2';
		nSuited = 2;
		return 69;
	}
	if (card1[0] == 'J' && card2[0] == 'J') {
		preflop_card1 = 'J';
		preflop_card2 = 'J';
		nSuited = 1;
		return 70;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == 'T' || card2[0] == 'T')) {
		preflop_card1 = 'J';
		preflop_card2 = 'T';
		nSuited = 1;
		return 71;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == 'T' || card2[0] == 'T') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = 'T';
		nSuited = 2;
		return 72;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '9' || card2[0] == '9')) {
		preflop_card1 = 'J';
		preflop_card2 = '9';
		nSuited = 1;
		return 73;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '9' || card2[0] == '9') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '9';
		nSuited = 2;
		return 74;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = 'J';
		preflop_card2 = '8';
		nSuited = 1;
		return 75;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '8';
		nSuited = 2;
		return 76;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = 'J';
		preflop_card2 = '7';
		nSuited = 1;
		return 77;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '7';
		nSuited = 2;
		return 78;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = 'J';
		preflop_card2 = '6';
		nSuited = 1;
		return 79;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '6';
		nSuited = 2;
		return 80;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = 'J';
		preflop_card2 = '5';
		nSuited = 1;
		return 81;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '5';
		nSuited = 2;
		return 82;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = 'J';
		preflop_card2 = '4';
		nSuited = 1;
		return 83;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '4';
		nSuited = 2;
		return 84;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = 'J';
		preflop_card2 = '3';
		nSuited = 1;
		return 85;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '3';
		nSuited = 2;
		return 86;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = 'J';
		preflop_card2 = '2';
		nSuited = 1;
		return 87;
	}
	if ((card1[0] == 'J' || card2[0] == 'J') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = 'J';
		preflop_card2 = '2';
		nSuited = 2;
		return 88;
	}
	if (card1[0] == 'T' && card2[0] == 'T') {
		preflop_card1 = 'T';
		preflop_card2 = 'T';
		nSuited = 1;
		return 89;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '9' || card2[0] == '9')) {
		preflop_card1 = 'T';
		preflop_card2 = '9';
		nSuited = 1;
		return 90;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '9' || card2[0] == '9') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '9';
		nSuited = 2;
		return 91;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = 'T';
		preflop_card2 = '8';
		nSuited = 1;
		return 92;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '8';
		nSuited = 2;
		return 93;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = 'T';
		preflop_card2 = '7';
		nSuited = 1;
		return 94;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '7';
		nSuited = 2;
		return 95;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = 'T';
		preflop_card2 = '6';
		nSuited = 1;
		return 96;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '6';
		nSuited = 2;
		return 97;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = 'T';
		preflop_card2 = '5';
		nSuited = 1;
		return 98;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '5';
		nSuited = 2;
		return 99;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = 'T';
		preflop_card2 = '4';
		nSuited = 1;
		return 100;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '4';
		nSuited = 2;
		return 101;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = 'T';
		preflop_card2 = '3';
		nSuited = 1;
		return 102;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '3';
		nSuited = 2;
		return 103;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = 'T';
		preflop_card2 = '2';
		nSuited = 1;
		return 104;
	}
	if ((card1[0] == 'T' || card2[0] == 'T') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = 'T';
		preflop_card2 = '2';
		nSuited = 2;
		return 105;
	}
	if (card1[0] == '9' && card2[0] == '9') {
		preflop_card1 = '9';
		preflop_card2 = '9';
		nSuited = 1;
		return 106;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '8' || card2[0] == '8')) {
		preflop_card1 = '9';
		preflop_card2 = '8';
		nSuited = 1;
		return 107;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '8' || card2[0] == '8') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '8';
		nSuited = 2;
		return 108;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = '9';
		preflop_card2 = '7';
		nSuited = 1;
		return 109;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '7';
		nSuited = 2;
		return 110;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = '9';
		preflop_card2 = '6';
		nSuited = 1;
		return 111;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '6';
		nSuited = 2;
		return 112;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = '9';
		preflop_card2 = '5';
		nSuited = 1;
		return 113;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '5';
		nSuited = 2;
		return 114;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = '9';
		preflop_card2 = '4';
		nSuited = 1;
		return 115;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '4';
		nSuited = 2;
		return 116;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '9';
		preflop_card2 = '3';
		nSuited = 1;
		return 117;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '3';
		nSuited = 2;
		return 118;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '9';
		preflop_card2 = '2';
		nSuited = 1;
		return 119;
	}
	if ((card1[0] == '9' || card2[0] == '9') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '9';
		preflop_card2 = '2';
		nSuited = 2;
		return 120;
	}
	if (card1[0] == '8' && card2[0] == '8') {
		preflop_card1 = '8';
		preflop_card2 = '8';
		nSuited = 1;
		return 121;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '7' || card2[0] == '7')) {
		preflop_card1 = '8';
		preflop_card2 = '7';
		nSuited = 1;
		return 122;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '7' || card2[0] == '7') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '7';
		nSuited = 2;
		return 123;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = '8';
		preflop_card2 = '6';
		nSuited = 1;
		return 124;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '6';
		nSuited = 2;
		return 125;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = '8';
		preflop_card2 = '5';
		nSuited = 1;
		return 126;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '5';
		nSuited = 2;
		return 127;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = '8';
		preflop_card2 = '4';
		nSuited = 1;
		return 128;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '4';
		nSuited = 2;
		return 129;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '8';
		preflop_card2 = '3';
		nSuited = 1;
		return 130;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '3';
		nSuited = 2;
		return 131;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '8';
		preflop_card2 = '2';
		nSuited = 1;
		return 132;
	}
	if ((card1[0] == '8' || card2[0] == '8') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '8';
		preflop_card2 = '2';
		nSuited = 2;
		return 133;
	}
	if (card1[0] == '7' && card2[0] == '7') {
		preflop_card1 = '7';
		preflop_card2 = '7';
		nSuited = 1;
		return 134;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '6' || card2[0] == '6')) {
		preflop_card1 = '7';
		preflop_card2 = '6';
		nSuited = 1;
		return 135;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '6' || card2[0] == '6') && card1[1] == card2[1]) {
		preflop_card1 = '7';
		preflop_card2 = '6';
		nSuited = 2;
		return 136;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = '7';
		preflop_card2 = '5';
		nSuited = 1;
		return 137;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = '7';
		preflop_card2 = '5';
		nSuited = 2;
		return 138;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = '7';
		preflop_card2 = '4';
		nSuited = 1;
		return 139;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = '7';
		preflop_card2 = '4';
		nSuited = 2;
		return 140;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '7';
		preflop_card2 = '3';
		nSuited = 1;
		return 141;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '7';
		preflop_card2 = '3';
		nSuited = 2;
		return 142;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '7';
		preflop_card2 = '2';
		nSuited = 1;
		return 143;
	}
	if ((card1[0] == '7' || card2[0] == '7') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '7';
		preflop_card2 = '2';
		nSuited = 2;
		return 144;
	}
	if (card1[0] == '6' && card2[0] == '6') {
		preflop_card1 = '6';
		preflop_card2 = '6';
		nSuited = 1;
		return 145;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '5' || card2[0] == '5')) {
		preflop_card1 = '6';
		preflop_card2 = '5';
		nSuited = 1;
		return 146;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '5' || card2[0] == '5') && card1[1] == card2[1]) {
		preflop_card1 = '6';
		preflop_card2 = '5';
		nSuited = 2;
		return 147;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = '6';
		preflop_card2 = '4';
		nSuited = 1;
		return 148;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = '6';
		preflop_card2 = '4';
		nSuited = 2;
		return 149;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '6';
		preflop_card2 = '3';
		nSuited = 1;
		return 150;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '6';
		preflop_card2 = '3';
		nSuited = 2;
		return 151;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '6';
		preflop_card2 = '2';
		nSuited = 1;
		return 152;
	}
	if ((card1[0] == '6' || card2[0] == '6') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '6';
		preflop_card2 = '2';
		nSuited = 2;
		return 153;
	}
	if (card1[0] == '5' && card2[0] == '5') {
		preflop_card1 = '5';
		preflop_card2 = '5';
		nSuited = 1;
		return 154;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '4' || card2[0] == '4')) {
		preflop_card1 = '5';
		preflop_card2 = '4';
		nSuited = 1;
		return 155;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '4' || card2[0] == '4') && card1[1] == card2[1]) {
		preflop_card1 = '5';
		preflop_card2 = '4';
		nSuited = 2;
		return 156;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '5';
		preflop_card2 = '3';
		nSuited = 1;
		return 157;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '5';
		preflop_card2 = '3';
		nSuited = 2;
		return 158;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '5';
		preflop_card2 = '2';
		nSuited = 1;
		return 159;
	}
	if ((card1[0] == '5' || card2[0] == '5') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '5';
		preflop_card2 = '2';
		nSuited = 2;
		return 160;
	}
	if (card1[0] == '4' && card2[0] == '4') {
		preflop_card1 = '4';
		preflop_card2 = '4';
		nSuited = 1;
		return 161;
	}
	if ((card1[0] == '4' || card2[0] == '4') && (card1[0] == '3' || card2[0] == '3')) {
		preflop_card1 = '4';
		preflop_card2 = '3';
		nSuited = 1;
		return 162;
	}
	if ((card1[0] == '4' || card2[0] == '4') && (card1[0] == '3' || card2[0] == '3') && card1[1] == card2[1]) {
		preflop_card1 = '4';
		preflop_card2 = '3';
		nSuited = 2;
		return 163;
	}
	if ((card1[0] == '4' || card2[0] == '4') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '4';
		preflop_card2 = '2';
		nSuited = 1;
		return 164;
	}
	if ((card1[0] == '4' || card2[0] == '4') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '4';
		preflop_card2 = '2';
		nSuited = 2;
		return 165;
	}
	if (card1[0] == '3' && card2[0] == '3') {
		preflop_card1 = '3';
		preflop_card2 = '3';
		nSuited = 1;
		return 166;
	}
	if ((card1[0] == '3' || card2[0] == '3') && (card1[0] == '2' || card2[0] == '2')) {
		preflop_card1 = '3';
		preflop_card2 = '2';
		nSuited = 1;
		return 167;
	}
	if ((card1[0] == '3' || card2[0] == '3') && (card1[0] == '2' || card2[0] == '2') && card1[1] == card2[1]) {
		preflop_card1 = '3';
		preflop_card2 = '2';
		nSuited = 2;
		return 168;
	}
	if (card1[0] == '2' && card2[0] == '2') {
		preflop_card1 = '2';
		preflop_card2 = '2';
		nSuited = 1;
		return 169;
	}


	return 0;

};
//tools

void prwin_calcolator::GetPrwinAuto(string Cfile , string OpplFile ,string card1, string card2, string card3, string card4, string card5, string card6, string card7) {
	int iterations = 100000;
		
	if (Cfile == "")Cfile ="ManualPrwinC++.txt";
	if (OpplFile == "")OpplFile = "ManualPrwinOppl.txt";

		ofstream scrivi;
		ofstream scrivi2;

		scrivi.precision(3);
		scrivi2.precision(3);
		cout.precision(3);

		double win;
		scrivi.open(Cfile);
		scrivi2.open(OpplFile);

		scrivi << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;
		scrivi2 << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;

		scrivi << "switch (*ActivePlayer) {\n";



		for (int i = 2; i <= 9; i++) {
			prwin_calcolator* a = new prwin_calcolator;
			scrivi << "   case " << i << ":\n";
			win = a->calc_prwin(card1, card2, card3, card4, card5, card6, card7, i, iterations);
			win -= 0.01;
			delete a;
			//cout << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << " player = " << i << " prwin = " << win << endl << endl;
			scrivi << "       if (prwin >= " << win << ") return true;\n       break;\n";
			scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin >= " << win << " RETURN true FORCE\n";


		}

		scrivi << "}\nreturn false;\n";
		scrivi2 << "	WHEN Others RETURN false FORCE\n";

		scrivi << endl;
		scrivi2 << endl;
		scrivi.close();
		scrivi2.close();

	


};
void prwin_calcolator::GetPrwin() {
	int iterations = 100000;
	
	cout << "Format examples:\npreflop: AcAd\nflop: AcAdKcKdQh\nturn: AcAdKcKdQhQc\nriver: AcAdKcKdQhQcJh\n\n";
	while (1) {

		string cards = "";
		string card1 = "";
		string card2 = "";
		string card3 = "";
		string card4 = "";
		string card5 = "";
		string card6 = "";
		string card7 = "";

		cout << "Enter cards and push enter : \n";
		cin >> cards;
		cout << "\n";
		card1 += cards[0];
		card1 += cards[1];
		card2 += cards[2];
		card2 += cards[3];


		if (cards.length() >= 10) {
			card3 += cards[4];
			card3 += cards[5];
			card4 += cards[6];
			card4 += cards[7];
			card5 += cards[8];
			card5 += cards[9];
		}
		if (cards.length() >= 12) {
			card6 += cards[10];
			card6 += cards[11];

		}
		if (cards.length() >= 14) {
			card7 += cards[12];
			card7 += cards[13];

		}



		ofstream scrivi;
		ofstream scrivi2;
		double win = 0;
		scrivi.open("ManualPrwin.txt");
		scrivi2.open("ManualPrwinOPPL.txt");

		scrivi << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;
		scrivi2 << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;

		scrivi << "switch (*ActivePlayer) {\n";

		cout.precision(3);
		scrivi.precision(3);
		scrivi2.precision(3);

		for (int i = 2; i <= 9; i++) {
			prwin_calcolator* a = new prwin_calcolator;
			scrivi << "   case " << i << ":\n";
			win = a->calc_prwin(card1, card2, card3, card4, card5, card6, card7, i, iterations);
			win -= 0.01;
			delete a;
			cout << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << " player = " << i << " prwin = " << win << endl << endl;
			scrivi << "       if (prwin >= " << win << ") return true;\n       break;\n";
			scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin >= " << win << " RETURN true FORCE\n";
			win = 0;

		}

		scrivi << "}\nreturn false;\n";
		scrivi2 << "	WHEN Others RETURN false FORCE\n";

		scrivi << endl;
		scrivi2 << endl;
		scrivi.close();
		scrivi2.close();

	}


};
void prwin_calcolator::WriteAllPot() {
	

	//call.02 ok
	double win = 0.00;
	double offset = -0.01;
	int pot = 2;
	double incrementoprwin = .01;
	int incrementopot = 1;

	ofstream a;
	a.open("all pot.txt");

	a << "{\n";
	for (int i = 2; i < 32; i++) {
		a << "if (Pot <= " << pot << " ){\n";
		a << " switch (*ActivePlayer){\n";
		for (int j = 2; j <= 9; j++) {
			a << "	case " << j << ":\n";
			a << "	if (prwin >= " << (1.0 / j) + (win + offset) << ") return true;\n";
			a << "	break;\n";
		}
		a << "	}\n";
		a << "}\n";
		win += incrementoprwin;
		pot += incrementopot;
	}

	a << " switch (*ActivePlayer){\n";
	for (int j = 2; j <= 9; j++) {
		a << "	case " << j << ":\n";
		a << "	if (prwin >= " << (1.0 / j) + (win + offset) << ") return true;\n";
		a << "	break;\n";
	}

	a << "}\n";

	a << "return false;\n";
	a << "}\n";


	a.close();
	exit(0);

};
void prwin_calcolator::WriteAllStack() {


	//call.02 ok
	double win = 0.00;
	double offset = 0.1;
	int pot = 1;
	double incrementoprwin = .001;
	int incrementopot = 1;

	double StartPrwin[10];



	ofstream a;
	a.open("all pot.txt");

	a << "{\n";
	for (int i = 0; i < 100; i++) {
		a << "if (StackSize <= " << i << " ){\n";
		a << " switch (*ActivePlayer){\n";
		for (int j = 2; j <= 9; j++) {
			a << "	case " << j << ":\n";
			a << "	if (prwin >= " << (1.0 / j) + (win + offset) << ") return true;\n";
			a << "	break;\n";
		}
		a << "	}\n";
		a << "}\n";
		win -= 0.001;
		pot += incrementopot;
	}

	a.close();
	exit(0);

};

void prwin_calcolator::MinPrwin() {
	//return;
	ofstream a;

	while (1) {
		double minprwin = 0;

		cout << "enter the min prwin:\n";
		cin >> minprwin;
		if (minprwin == 0) minprwin = .5;

		a.open("min prwin.txt");

		a.precision(3);
		cout.precision(3);

		a << " switch (*ActivePlayer){\n";
		for (int j = 2; j <= 9; j++) {
			a << "	case " << j << ":\n";
			a << "	if (prwin >= " << (minprwin / j) * 2 << ") return true; \n";
			a << "	break;\n";
			cout << "player " << j << ": ";
			cout << (minprwin / j) * 2 << endl;

		}
		a << "	}\n";
		a << "return false;\n";
		cout << "\n";
		a.close();
	}

	exit(0);

};

void prwin_calcolator::test() {
	ofstream w;
	ofstream w2;

	int iteration = 1;
	w.open("txt/WriteTxt.txt");
	w2.open("txt/FlopNumber.txt");

	int flopnumber = 0;
	double win = 0.0;

	// Genera tutte le possibili combinazioni di 5 carte, rappresentate come numeri interi da 0 a 51
	vector<vector<int>> allCombos;
	for (int i = 0; i < 48; i++) {
		for (int j = i + 1; j < 49; j++) {
			for (int k = j + 1; k < 50; k++) {
				for (int l = k + 1; l < 51; l++) {
					for (int m = l + 1; m < 52; m++) {
						allCombos.push_back({ i, j, k, l, m });
					}
				}
			}
		}
	}

	// Per ogni combinazione, verifica se è una combinazione isomorfa e se lo è, elaborala
	for (const auto& combo : allCombos) {
		int card1 = combo[0] % 13;
		int card2 = combo[1] % 13;
		int card3 = combo[2] % 13;
		int card4 = combo[3] % 13;
		int card5 = combo[4] % 13;// Verifica se la combinazione è isomorfa
		if (card1 >= card2 || card2 >= card3 || card3 >= card4 || card4 >= card5) {
			continue;
		}
		if (combo[0] / 13 == combo[1] / 13 || combo[0] / 13 == combo[2] / 13 || combo[0] / 13 == combo[3] / 13 || combo[0] / 13 == combo[4] / 13 ||
			combo[1] / 13 == combo[2] / 13 || combo[1] / 13 == combo[3] / 13 || combo[1] / 13 == combo[4] / 13 ||
			combo[2] / 13 == combo[3] / 13 || combo[2] / 13 == combo[4] / 13 ||
			combo[3] / 13 == combo[4] / 13) {
			continue;
		}

		// Elabora la combinazione isomorfa
		for (int suit = 2; suit <= 5; suit++) {
			if (suit == 2) {
				w << "switch (nSuits){\n";
				w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "s" << Rank[card4] << "c" << Rank[card5] << "d\n";
				w << "    switch (nPlayers){\n";
				for (int player = 2; player <= 9; player++) {
					w << "        case " << player << ":\n";
					win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "s", Rank[card4] + "c", Rank[card5] + "d", "", "", player, iteration);
					w << "        return " << win << ";\n";
				}

				w << " }\n}\n";
			}
			else if (suit == 3) {
				w << "switch (nSuits){\n";
				w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "s" << Rank[card5] << "d\n";
				w << "    switch (nPlayers){\n";
				for (int player = 2; player <= 9; player++) {
					w << "        case " << player << ":\n";
					win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "s", Rank[card5] + "d", "", "", player, iteration);
					w << "        return " << win << ";\n";
				}

				w << "    }\n}\n";
			}
			else if (suit == 4) {
				w << "switch (nSuits){\n";
				w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "h" << Rank[card5] << "d\n";
				w << "    switch (nPlayers){\n";
				for (int player = 2; player <= 9; player++) {
					w << "        case " << player << ":\n";
					win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "h", Rank[card5] + "d", "", "", player, iteration);
					w << "        return " << win << ";\n";
				}

				w << "    }\n}\n";
			}
			else {
				w << "switch (nSuits){\n";
				w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "h" << Rank[card5] << "h\n";
				w << "    switch (nPlayers){\n";
				for (int player = 2; player <= 9; player++) {
					w << "        case " << player << ":\n";
					win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "h", Rank[card5] + "h", "", "", player, iteration);
					w << "        return " << win << ";\n";
				}

				w << "    }\n}\n";
			}

			flopnumber++;
			w2 << flopnumber << "\n";
		}
	}

	w.close();
	w2.close();
}



void prwin_calcolator::WritePrwinALL() {
	return;

#define MACRO()	{\
	scrivi << "if (ToCall <= " << ToCall << "){\n";\
	scrivi2 << "WHEN AmountToCall <= " << ToCall << endl;\
	scrivi << "//Min hand "<<cards[0]<< cards[1]<< cards[2]<< cards[3]<< cards[4]<< cards[5]<< cards[6]<<endl;\
	scrivi2 << "//Min hand "<<cards[0]<< cards[1]<< cards[2]<< cards[3]<< cards[4]<< cards[5]<< cards[6]<<endl;\
	scrivi << " switch(*ActivePlayer){\n";\
	for (int i = 2; i <= 9; i++) {\
		prwin_calcolator* a = new prwin_calcolator;\
		scrivi << "   case " << i << ":\n";\
		win = a->calc_prwin(cards[0], cards[1], cards[2], cards[3], cards[4], cards[5], cards[6], i, 100000);\
		delete a;\
		scrivi << "       if (prwin >= " << win << ") return true;\n       break;\n";\
		scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin >= " << win << " RETURN true FORCE\n";\
		}\
		scrivi2 <<"	WHEN Others RETURN false FORCE\n\N";\
		scrivi << "\n}\nreturn false;\n};\n";\
	}

	ofstream scrivi("txt/c++.txt");
	ofstream scrivi2("txt/oppl.txt");

	cout.precision(2);
	scrivi.precision(2);
	scrivi2.precision(2);

	int ToCall = 0;
	double win = 0;
	string cards[7] = { "","","","","","","" };

	cout << "scrivo txt con prwin..\n";


	ToCall = 1;
	cards[0] = "Ac";
	cards[1] = "2c";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();


	ToCall = 3;
	cards[0] = "Ac";
	cards[1] = "5c";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";

	ToCall = 5;
	cards[0] = "Ac";
	cards[1] = "2c";
	cards[2] = "6h";
	cards[3] = "9d";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 10;
	cards[0] = "Ac";
	cards[1] = "8c";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 15;
	cards[0] = "Ac";
	cards[1] = "Tc";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 20;
	cards[0] = "Ac";
	cards[1] = "Jc";
	cards[2] = "8h";
	cards[3] = "Td";
	cards[4] = "6c";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 25;
	cards[0] = "Ac";
	cards[1] = "Qc";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "Jc";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 30;
	cards[0] = "Ac";
	cards[1] = "Kc";
	cards[2] = "8h";
	cards[3] = "9d";
	cards[4] = "Jc";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	cout << "..\n";
	ToCall = 2000;
	cards[0] = "Ac";
	cards[1] = "Kc";
	cards[2] = "Th";
	cards[3] = "9d";
	cards[4] = "Qc";
	cards[5] = "";
	cards[5] = "";
	MACRO();

	/*
	for (int i = 2; i <= 9; i++) {
		prwin_calcolator* a = new prwin_calcolator;
		scrivi << "   case " << i << ":\n";
		win = a->calc_prwin(cards[0], cards[1], cards[2], cards[3], cards[4], cards[5], cards[6], i, 100000);
		delete a;
		scrivi << "       if (prwin >= " << win << ") return true;\n       break;\n";
		scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin >= " << win << " RETURN true FORCE\n";


	}


	scrivi << " }\n";
	scrivi << "}\n";
	*/


	scrivi.close();
	scrivi2.close();


	exit(0);




};
void prwin_calcolator::WriteTxt() {
	ofstream w;
	ofstream w2;

	int iteration = 0;
	w.open("txt/WriteTxt.txt");
	w2.open("txt/FlopNumber.txt");

	int flopnumber = 0;
	double win = 0.0;
	for (int card1 = 0; card1 < 13; card1++) {
		for (int card2 = 0; card2 < 13; card2++) {
			for (int card3 = 0; card3 < 13; card3++) {
				for (int card4 = 0; card4 < 13; card4++) {
					for (int card5 = 0; card5 < 13; card5++) {
						if (card1 > card2 || card2 > card3 || card3 > card4 || card4 > card5)continue;							
						for (int suit = 2; suit <= 5; suit++) {
							if (suit == 2) {
								if (card1 == card2)continue;

								w << "switch (nSuits){\n";
								w << "case " << suit << "://" << Rank[card1] << "h" <<Rank[card2] << "h" <<Rank[card3] << "s"<< Rank[card4] << "c" <<Rank[card5] << "d\n";
								w << "	switch (nPlayers){\n";
								for (int player = 2; player <= 9; player++) {
									w << "		case " << player << ":\n";
									win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "s", Rank[card4] + "c", Rank[card5] + "d", "", "", player, iteration);
									w << "		return " << win<<";\n";									
								}
							
								w << "	}\n";
								flopnumber++;
							}
							else if (suit == 3) {
								if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)continue;
								if (card2 == card3)continue;

								w << "switch (nSuits){\n";
								w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "c" << Rank[card5] << "d\n";
								w << "	switch (nPlayers){\n";
								for (int player = 2; player <= 9; player++) {
									w << "		case " << player << ":\n";
									win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "c", Rank[card5] + "d", "", "", player, iteration);
									w << "		return " << win << ";\n";
								}

								w << "	}\n";
								flopnumber++;
							}
							else if (suit == 4) {
								if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)continue;
								if (card2 == card3 || card2 == card4 || card2 == card5)continue;
								if (card3 == card4)continue;

								w << "switch (nSuits){\n";
								w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "h" << Rank[card5] << "d\n";
								w << "	switch (nPlayers){\n";
								for (int player = 2; player <= 9; player++) {
									w << "		case " << player << ":\n";
									win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "h", Rank[card5] + "d", "", "", player, iteration);
									w << "		return " << win << ";\n";
								}

								w << "	}\n";
								flopnumber++;
							}
							else if (suit == 5) {
								if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 )continue;
								if (card2 == card3 || card2 == card4 || card2 == card5)continue;
								if (card3 == card4 || card3 == card5 )continue;
								if (card4 == card5)continue;



								
								w << "switch (nSuits){\n";
								w << "case " << suit << "://" << Rank[card1] << "h" << Rank[card2] << "h" << Rank[card3] << "h" << Rank[card4] << "h" << Rank[card5] << "h\n";
								w << "	switch (nPlayers){\n";
								for (int player = 2; player <= 9; player++) {
									w << "		case " << player << ":\n";
									win = calc_prwin(Rank[card1] + "h", Rank[card2] + "h", Rank[card3] + "h", Rank[card4] + "h", Rank[card5] + "h", "", "", player, iteration);
									w << "		return " << win << ";\n";
								}

								w << "	}\n";
								flopnumber++;
							};
							

							//w2<<"if (n"<<card1<<

							w << "}\n";
							//cout << flopnumber << endl;
							flopnumber++;
						}

						w.flush();
					
					}
				}
			}
		}
	}
	cout << flopnumber;
	w.close();
	w2.close();
	exit(0);

}
void prwin_calcolator::findPrwin() {
#define resetcard card1 = "";card2 = "";card3 = "";card4 = "";card5 = "";card6 = "";card7 = "";
	string card1 = "";
	string card2 = "";
	string card3 = "";
	string card4 = "";
	string card5 = "";
	string card6 = "";
	string card7 = "";
	double prwin = 0;

	string cards[100] ={""};
	bool fatto[100] = { false };

	double targetprwin = .5;


	int betround = 4;
	int index = 0;
	bool foundcard = true;

	string cfile = "FindPrwinC++.txt";
	string opplfile = "FindOppl.txt";

	cout.precision(3);	


	while (1) {
		if (foundcard) {
			bet:
			cout << "Enter betround:\n";
			cin >> betround;

			if (betround <=0 || betround > 4) {
				cout << "ERROR!\n";
				goto bet;
			}

			target:
			cout << "Enter target prwin:\n";
			cin >> targetprwin;

			if (targetprwin <=0 || targetprwin >= 1) {
				cout << "ERROR!\n";
				goto target;
			}

			foundcard = false;
			cout << "searching cards..\n\n";
		}


		switch (betround) {
			case 1:
				card1 = NewDeck[rand() % 52];
				card2 = NewDeck[rand() % 52];
				if (card1 == card2)continue;

				break;
			case 2:
				card1 = NewDeck[rand() % 52];
				card2 = NewDeck[rand() % 52];
				card3 = NewDeck[rand() % 52];
				card4 = NewDeck[rand() % 52];
				card5 = NewDeck[rand() % 52];
				if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)continue;
				if (card2 == card3 || card2 == card4 || card2 == card5)continue;
				if (card3 == card4 || card3 == card5)continue;
				if (card4 == card5)continue;
				break;


			case 3:
				card1 = NewDeck[rand() % 52];
				card2 = NewDeck[rand() % 52];
				card3 = NewDeck[rand() % 52];
				card4 = NewDeck[rand() % 52];
				card5 = NewDeck[rand() % 52];
				card6 = NewDeck[rand() % 52];
				if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6 )continue;
				if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6)continue;
				if (card3 == card4 || card3 == card5 || card3 == card6)continue;
				if (card4 == card5 || card4 == card6)continue;
				if (card5 == card6 )continue;
				break;
			case 4:
				card1 = NewDeck[rand() % 52];
				card2 = NewDeck[rand() % 52];
				card3 = NewDeck[rand() % 52];
				card4 = NewDeck[rand() % 52];
				card5 = NewDeck[rand() % 52];
				card6 = NewDeck[rand() % 52];
				card7 = NewDeck[rand() % 52];
				if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6 || card1 == card7)continue;
				if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6 || card2 == card7)continue;
				if (card3 == card4 || card3 == card5 || card3 == card6 || card3 == card7)continue;
				if (card4 == card5 || card4 == card6 || card4 == card7)continue;
				if (card5 == card6 || card5 == card7)continue;
				if (card6 == card7)continue;
				break;
			}		
		prwin = calc_prwin(card1, card2, card3, card4, card5, card6, card7, 2, 10000);
					
	
		if (prwin > targetprwin) {
			switch (betround) {
			case 1:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAuto(cfile,opplfile,card1, card2, "", "", "", "", "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			case 2:

				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAuto(cfile, opplfile, card1, card2, card3, card4, card5, "", "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			case 3:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAuto(cfile, opplfile, card1, card2, card3, card4, card5, card6, "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}

				break;
			case 4:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAuto(cfile, opplfile ,card1, card2, card3, card4, card5, card6, card7);
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			}
		}	


		index++;

	}

};

void prwin_calcolator::getALLprwin() {
	return;
	string wins[10] = {""};
	string Cline = "";
	string Oline = "";
	string Cline2 = "";
	string Oline2 = "";
	ofstream Cfile;
	ofstream Ofile;

	int targetpot = 50;
	//clear old txt
	int pot = 5;
	int betround = 2;

	float targetprwin = 0.00;
	int win = 80;
	string round = "";

	for (int bet = 1; bet <= 1; bet++) {
		betround = bet;
		if (betround == 1)round = " preflop ";
		if (betround == 2)round = " flop ";
		if (betround == 3)round = " turn ";
		if (betround == 4)round = " river ";

		if (betround == 1)targetprwin = 0.65;
		if (betround == 2)targetprwin = 0.60;
		if (betround == 3)targetprwin = 0.55;
		if (betround == 4)targetprwin = 0.60;

		Cline += "{\n";
		Cline2 += "{\n";
		while (int(targetprwin*100) <= win) {
			if (int(targetprwin * 100) < win) {
				Cline += "if (Pot <= " + to_string(pot) + "){\n";
				Oline += "WHEN PotSize <= " + to_string(pot) + "\n";
				Cline2 += "if (ToCall <= " + to_string(pot) + "){\n";
				Oline2 += "WHEN AmountToCall <= " + to_string(pot) + "\n";
			}
			else {
				Cline += "if (Pot >= " + to_string(pot) + "){\n";
				Oline += "WHEN PotSize >= " + to_string(pot) + "\n";
				Cline2 += "if (ToCall >= " + to_string(pot) + "){\n";
				Oline2 += "WHEN AmountToCall >= " + to_string(pot) + "\n";
			};


			{
				//ottieni singole prwin per giocatori nell'array
				findPrwinAUTO_wins(wins, betround, targetprwin);
				Cline2 += "linea = __LINE__;\n";
				Cline2 += "switch (*ActivePlayer) {\n";

				Cline += "linea = __LINE__;\n";
				Cline += "switch (*ActivePlayer) {\n";

				//scrivi su txt per c++ e oppl
				for (int i = 2; i <= 9; i++) {
					Cline2 += "	case " + to_string(i) + ":\n";
					Cline2 += "	if (prwin >= " + wins[i] + ") return true;\n	break;\n";
					Oline2 += "WHEN Opponents = " + to_string(i-1) + " AND prwin >= " + wins[i] + " RETURN true FORCE\n";

					Cline += "	case " + to_string(i) + ":\n";
					Cline += "	if (prwin >= " + wins[i] + ") return true;\n	break;\n";
					Oline += "WHEN Opponents = " + to_string(i-1) + " AND prwin >= " + wins[i] + " RETURN true FORCE\n";
					wins[i] = "";
				}
				Cline += "}\nreturn false;\n}\n";
				Oline += "WHEN Others RETURN false FORCE\n\n";

				Cline2 += "}\nreturn false;\n}\n";
				Oline2 += "WHEN Others RETURN false FORCE\n\n";

			}
			pot += 1;
			targetprwin += 0.01;
			cout << "Rimanenti.. " << targetpot - pot << endl;
		}
		Cline += "}\n";
		Cline2 += "}\n";
		
		
		Cfile.open("txt/autopot/raise " + round + " c++.txt");
		Ofile.open("txt/autopot/raise " + round + " oppl.txt");
		Cfile << Cline;
		Ofile << Oline;
		Cline = "";
		Oline = "";
		Cfile.close();
		Ofile.close();

		Cfile.open("txt/autopot/call " + round + " c++.txt");
		Ofile.open("txt/autopot/call " + round + " oppl.txt");
		Cfile << Cline2;
		Ofile << Oline2;
		Cline2 = "";
		Oline2 = "";

		Cfile.close();
		Ofile.close();

		/*
		//call
		pot = 2;
		if (betround == 1)targetprwin = .33;
		if (betround > 1)targetprwin = .45;
		while (pot <= 50) {
			Cline += "if (ToCall <= " + to_string(pot) + "){\n";
			Oline += "WHEN AmountToCall <= " + to_string(pot) + "\n";
			{
				//ottieni singole prwin per giocatori nell'array
				findPrwinAUTO_wins(wins, betround, targetprwin);
				Cline += "linea = __LINE__;\n";
				Cline += "switch (*ActivePlayer) {\n";
				//scrivi su txt per c++ e oppl
				for (int i = 2; i <= 9; i++) {
					Cline += "	case " + to_string(i) + ":\n";
					Cline += "	if (prwin >= " + wins[i] + ") return true;\n	break;\n";
					Oline += "WHEN Opponents = " + to_string(i) + " AND prwin >= " + wins[i] + " RETURN true FORCE;\n";
					wins[i] = "";
				}
				Cline += "}\nreturn false;\n}\n\n";
				Oline += "WHEN Others RETURN false FORCE\n\n";
			}
			pot += 1;
			targetprwin += 0.01;
			cout << "Rimanenti.." << 50 - pot << endl;
		}
		Cfile.open("txt/autopot/call " + round + " c++.txt");
		Ofile.open("txt/autopot/call " + round + " oppl.txt");
		Cfile << Cline;
		Ofile << Oline;
		Cline = "";
		Oline = "";
		Cfile.close();
		Ofile.close();	
	*/
	}

	exit(0);
};
void prwin_calcolator::findPrwinAUTO_wins(string wins[],int betround , double targetprwin) {
	string card1 = "";
	string card2 = "";
	string card3 = "";
	string card4 = "";
	string card5 = "";
	string card6 = "";
	string card7 = "";

	string output = "";

	double prwin = 0;

	string cards[100] = { "" };
	bool fatto[100] = { false };
	int times = 0;
	int index = 0;
	bool foundcard = false;
	double offset = 0.01;
	cout.precision(3);

	cout << "target prwin: " << targetprwin << " betround: " << betround << "\nwait...\n";
	while (!foundcard) {
		times++;

		switch (betround) {
		case 1:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			if (card1 == card2)continue;

			break;
		case 2:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5)continue;
			if (card3 == card4 || card3 == card5)continue;
			if (card4 == card5)continue;
			break;


		case 3:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			card6 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6)continue;
			if (card3 == card4 || card3 == card5 || card3 == card6)continue;
			if (card4 == card5 || card4 == card6)continue;
			if (card5 == card6)continue;
			break;
		case 4:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			card6 = NewDeck[rand() % 52];
			card7 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6 || card1 == card7)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6 || card2 == card7)continue;
			if (card3 == card4 || card3 == card5 || card3 == card6 || card3 == card7)continue;
			if (card4 == card5 || card4 == card6 || card4 == card7)continue;
			if (card5 == card6 || card5 == card7)continue;
			if (card6 == card7)continue;
			break;
		}
		prwin = calc_prwin(card1, card2, card3, card4, card5, card6, card7, 2, 10000);
		
		//avoid infinite loop
		if (times >= 1000) {
			offset += 0.01;
			times = 0;
		}

		if (prwin > targetprwin) {
			switch (betround) {
			case 1:
				if (prwin >= targetprwin && prwin < targetprwin + offset) {
					GetPrwinAuto_wins(wins, card1, card2, "", "", "", "", "");
					foundcard = true;
				}
				break;
			case 2:

				if (prwin >= targetprwin && prwin < targetprwin + offset) {
					GetPrwinAuto_wins(wins, card1, card2, card3, card4, card5, "", "");
					foundcard = true;
				}
				break;
			case 3:
				if (prwin >= targetprwin && prwin < targetprwin + offset) {
					GetPrwinAuto_wins(wins, card1, card2, card3, card4, card5, card6, "");
					foundcard = true;
				}

				break;
			case 4:
				if (prwin >= targetprwin && prwin < targetprwin + offset) {
					GetPrwinAuto_wins(wins, card1, card2, card3, card4, card5, card6, card7);
					foundcard = true;
				}
				break;
			}
		}


		index++;

	}
	cout << "Done\n";

};
void prwin_calcolator::GetPrwinAuto_wins(string wins[], string card1, string card2, string card3, string card4, string card5, string card6, string card7) {
	int iterations = 10000;

	cout.precision(3);
	double offset = 0.01;
	for (int i = 2; i <= 9; i++) {
		prwin_calcolator* a = new prwin_calcolator;
		wins[i] = to_string(a->calc_prwin(card1, card2, card3, card4, card5, card6, card7, i, iterations)-offset);
		delete a;


	}




};

//temp
void prwin_calcolator::getALLprwinMANUAL() {
	return;
	string wins[10] = { "" };
	string Cline = "";
	string Oline = "";
	string Cline2 = "";
	string Oline2 = "";
	ofstream Cfile;
	ofstream Ofile;

	int targetpot = 50;
	//clear old txt
	int pot = 2;
	int betround = 2;

	int minprwin = 0;
	int win = 80;
	string round = "";
	int tempprwin = -1;
	int type = -1;
	int maxprwin = 0;
	int _minprwin = 0;

	cout << "After entering MIN and MAX prwin\n"
		"this program choose cards and writes txt with c ++ and oppl code to paste..\n"
		"(for each BB in the pot or to call , 1 point of prwin is added.)\n";
	while (1) {
ChooseBetround: {
		cout << "\nEnter betround:\n";
		cin >> betround;
		if (betround < 1 || betround > 4) {
			cout << "invalid bet round, retry.";
			goto ChooseBetround;
		}
		if (betround == 1) {
			round = "...preflop ";
			cout << round << endl;
		}
		if (betround == 2) {
			round = "...flop ";
			cout << round << endl;

		}
		if (betround == 3) {
			round = "...turn ";
			cout << round << endl;

		}
		if (betround == 4) {
			round = "...river ";
			cout << round << endl;

		}
		}

ChooseMinPrwin: {
	cout << "\nChoose MIN prwin:\n";
	cin >> tempprwin;
	if (tempprwin <= 0 || tempprwin >= 100) {
		cout << "\nError. retry es 50.\n";
		goto ChooseMinPrwin;
	}
	minprwin = tempprwin;
	_minprwin = tempprwin;
	tempprwin = 0;
	}

ChooseMaxPrwin: {
cout << "\nChoose MAX prwin\n";
cin >> tempprwin;
if (tempprwin <= 0 || tempprwin >= 100) {
	cout << "\nError. retry es 50.\n";
	goto ChooseMaxPrwin;
}
win = tempprwin;
maxprwin = tempprwin;
tempprwin = 0;

}

cout << "\nStarting..\n";

pot = 2;
Cline += "{\n// "+to_string(_minprwin)+" "+ to_string(maxprwin)+" \n";
Cline2 += "\n{// " + to_string(_minprwin) + " " + to_string(maxprwin) + "\n";

while (minprwin <= win) {
	cout << "\nRimanenti.. " << win - minprwin << endl;

	if (minprwin < win) {
		Cline += "if (Pot <= " + to_string(pot) + "){\n";
		Oline += "WHEN PotSize <= " + to_string(pot) + "\n";
		Cline2 += "if (ToCall <= " + to_string(pot) + "){\n";
		Oline2 += "WHEN AmountToCall <= " + to_string(pot) + "\n";
	}
	else {
		Cline += "if (Pot >= " + to_string(pot) + "){\n";
		Oline += "WHEN PotSize >= " + to_string(pot) + "\n";
		Cline2 += "if (ToCall >= " + to_string(pot) + "){\n";
		Oline2 += "WHEN AmountToCall >= " + to_string(pot) + "\n";
	};

	{
		double target = (double(minprwin) / 100);

		//ottieni singole prwin per giocatori nell'array
		findPrwinAUTO_wins(wins, betround, target);
		Cline2 += "linea = __LINE__;\n";
		Cline2 += "switch (*ActivePlayer) {\n";

		Cline += "linea = __LINE__;\n";
		Cline += "switch (*ActivePlayer) {\n";


		//scrivi su txt per c++ e oppl
		for (int i = 2; i <= 9; i++) {
			Cline2 += "	case " + to_string(i) + ":\n";
			Cline2 += "	if (prwin >= " + wins[i] + ") return true;\n	break;\n";
			Oline2 += "WHEN Opponents = " + to_string(i - 1) + " AND prwin >= " + wins[i] + " RETURN true FORCE\n";

			Cline += "	case " + to_string(i) + ":\n";
			Cline += "	if (prwin >= " + wins[i] + ") return true;\n	break;\n";
			Oline += "WHEN Opponents = " + to_string(i - 1) + " AND prwin >= " + wins[i] + " RETURN true FORCE\n";
			wins[i] = "";
		}
		Cline += "}\nreturn false;\n}\n";
		Oline += "WHEN Others RETURN false FORCE\n\n";

		Cline2 += "}\nreturn false;\n}\n";
		Oline2 += "WHEN Others RETURN false FORCE\n\n";

	}
	pot += 1;
	minprwin += 1;
}
Cline += "}\n";
Cline2 += "}\n";




Cfile.open("autopot/" + round + "_Raise_" + to_string(_minprwin) + "_" + to_string(maxprwin) + "_C++.txt");
Ofile.open("autopot/" + round + "_Raise_" + to_string(_minprwin) + "_" + to_string(maxprwin) + "_OPPL.txt");
Cfile << Cline;
Ofile << Oline;
Cline = "";
Oline = "";
cout << "\n" + to_string(_minprwin) + " " + to_string(maxprwin) + " completed.\n";
Cfile.close();
Ofile.close();


Cfile.open("autopot/" + round + "_Call_" + to_string(_minprwin) + "_" + to_string(maxprwin) + "_C++.txt");
Ofile.open("autopot/" + round + "_Call_" + to_string(_minprwin) + "_" + to_string(maxprwin) + "_OPPL.txt");

Cfile << Cline2;
Ofile << Oline2;
Cline2 = "";
Oline2 = "";


Cfile.close();
Ofile.close();

	}

	exit(0);
};



void prwin_calcolator::GetPrwinINVERSO() {
	int iterations = 100000;

	cout << "Format examples:\npreflop: AcAd\nflop: AcAdKcKdQh\nturn: AcAdKcKdQhQc\nriver: AcAdKcKdQhQcJh\n\n";

	while (1) {

		string cards = "";
		string card1 = "";
		string card2 = "";
		string card3 = "";
		string card4 = "";
		string card5 = "";
		string card6 = "";
		string card7 = "";
		cout << "(INVERSO)\n";
		cout << "Enter cards and push enter : \n";
		cin >> cards;
		cout << "\n";
		card1 += cards[0];
		card1 += cards[1];
		card2 += cards[2];
		card2 += cards[3];


		if (cards.length() >= 10) {
			card3 += cards[4];
			card3 += cards[5];
			card4 += cards[6];
			card4 += cards[7];
			card5 += cards[8];
			card5 += cards[9];
		}
		if (cards.length() >= 12) {
			card6 += cards[10];
			card6 += cards[11];

		}
		if (cards.length() >= 14) {
			card7 += cards[12];
			card7 += cards[13];

		}



		ofstream scrivi;
		ofstream scrivi2;
		double win = 0;
		scrivi.open("ManualPrwin.txt");
		scrivi2.open("ManualPrwinOPPL.txt");

		scrivi << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;
		scrivi2 << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;

		scrivi << "switch (*ActivePlayer) {\n";

		cout.precision(2);
		scrivi.precision(2);
		scrivi2.precision(2);

		for (int i = 2; i <= 9; i++) {
			prwin_calcolator* a = new prwin_calcolator;
			scrivi << "   case " << i << ":\n";
			win = a->calc_prwin(card1, card2, card3, card4, card5, card6, card7, i, iterations);
			win -= 0.01;
			delete a;
			cout << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << " player = " << i << " prwin = " << win << endl << endl;
			scrivi << "       if (prwin <= " << win << ") return false;\n       break;\n";
			scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin <= " << win << " RETURN false FORCE\n";
			win = 0;

		}
		scrivi << "}\nreturn false;\n";
		scrivi2 << "	WHEN Others RETURN false FORCE\n";

		scrivi << endl;
		scrivi2 << endl;
		scrivi.close();
		scrivi2.close();

	}


};
void prwin_calcolator::findPrwinINVERSO() {
#define resetcard card1 = "";card2 = "";card3 = "";card4 = "";card5 = "";card6 = "";card7 = "";
	string card1 = "";
	string card2 = "";
	string card3 = "";
	string card4 = "";
	string card5 = "";
	string card6 = "";
	string card7 = "";
	double prwin = 0;

	string cards[100] = { "" };
	bool fatto[100] = { false };

	double targetprwin = .5;


	int betround = 4;
	int index = 0;
	bool foundcard = true;

	string cfile = "FindPrwinC++.txt";
	string opplfile = "FindOppl.txt";

	cout.precision(3);


	while (1) {
		if (foundcard) {
		bet:
			cout << "(INVERSO)\n";
			cout << "Enter betround:\n";
			cin >> betround;

			if (betround <= 0 || betround > 4) {
				cout << "ERROR!\n";
				goto bet;
			}

		target:
			cout << "Enter target prwin:\n";
			cin >> targetprwin;

			if (targetprwin <= 0 || targetprwin >= 1) {
				cout << "ERROR!\n";
				goto target;
			}

			foundcard = false;
			cout << "searching cards..\n\n";
		}


		switch (betround) {
		case 1:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			if (card1 == card2)continue;

			break;
		case 2:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5)continue;
			if (card3 == card4 || card3 == card5)continue;
			if (card4 == card5)continue;
			break;


		case 3:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			card6 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6)continue;
			if (card3 == card4 || card3 == card5 || card3 == card6)continue;
			if (card4 == card5 || card4 == card6)continue;
			if (card5 == card6)continue;
			break;
		case 4:
			card1 = NewDeck[rand() % 52];
			card2 = NewDeck[rand() % 52];
			card3 = NewDeck[rand() % 52];
			card4 = NewDeck[rand() % 52];
			card5 = NewDeck[rand() % 52];
			card6 = NewDeck[rand() % 52];
			card7 = NewDeck[rand() % 52];
			if (card1 == card2 || card1 == card3 || card1 == card4 || card1 == card5 || card1 == card6 || card1 == card7)continue;
			if (card2 == card3 || card2 == card4 || card2 == card5 || card2 == card6 || card2 == card7)continue;
			if (card3 == card4 || card3 == card5 || card3 == card6 || card3 == card7)continue;
			if (card4 == card5 || card4 == card6 || card4 == card7)continue;
			if (card5 == card6 || card5 == card7)continue;
			if (card6 == card7)continue;
			break;
		}
		prwin = calc_prwin(card1, card2, card3, card4, card5, card6, card7, 2, 10000);


		if (prwin > targetprwin) {
			switch (betround) {
			case 1:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAutoINVERSO(cfile, opplfile, card1, card2, "", "", "", "", "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			case 2:

				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAutoINVERSO(cfile, opplfile, card1, card2, card3, card4, card5, "", "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			case 3:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAutoINVERSO(cfile, opplfile, card1, card2, card3, card4, card5, card6, "");
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}

				break;
			case 4:
				if (prwin >= targetprwin && prwin < targetprwin + 0.01) {
					GetPrwinAutoINVERSO(cfile, opplfile, card1, card2, card3, card4, card5, card6, card7);
					foundcard = true;
					targetprwin = 0;
					betround = 0;
					resetcard
				}
				break;
			}
		}


		index++;

	}

};
void prwin_calcolator::GetPrwinAutoINVERSO(string Cfile, string OpplFile, string card1, string card2, string card3, string card4, string card5, string card6, string card7) {
	int iterations = 100000;

	if (Cfile == "")Cfile = "ManualPrwinC++.txt";
	if (OpplFile == "")OpplFile = "ManualPrwinOppl.txt";

	ofstream scrivi;
	ofstream scrivi2;

	scrivi.precision(3);
	scrivi2.precision(3);
	cout.precision(3);

	double win;
	scrivi.open(Cfile);
	scrivi2.open(OpplFile);

	scrivi << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;
	scrivi2 << "//min hand " << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << endl;

	scrivi << "switch (*ActivePlayer) {\n";



	for (int i = 2; i <= 9; i++) {
		prwin_calcolator* a = new prwin_calcolator;
		scrivi << "   case " << i << ":\n";
		win = a->calc_prwin(card1, card2, card3, card4, card5, card6, card7, i, iterations);
		win -= 0.01;
		delete a;
		cout << card1 << card2 << " " << card3 << card4 << card5 << " " << card6 << card7 << " player = " << i << " prwin = " << win << endl << endl;
		scrivi << "       if (prwin <= " << win << ") return false;\n       break;\n";
		scrivi2 << "	WHEN Opponents = " << i - 1 << " AND prwin <= " << win << " RETURN false FORCE\n";


	}

	scrivi << "}\nreturn false;\n";
	scrivi2 << "	WHEN Others RETURN false FORCE\n";

	scrivi << endl;
	scrivi2 << endl;
	scrivi.close();
	scrivi2.close();




};

//write code on txt scripts
void prwin_calcolator::WriteCodeForPreflopNumber() {
	//return;
	int number = 1;
	ofstream write;
	ifstream read;
	write.open("txt/TEST.txt");

	for (int i = 0; i < 13; i++) {
		for (int j = i; j < 13; j++) {

			if (i == j) {
				write << "if (card1[0] == '" << Rank[i] << "' && card2[0] == '" << Rank[j] << "') {\npreflop_card1 = '" << Rank[i] << "';\npreflop_card2 = '" << Rank[j] <<"';\nnSuited = 1;\nreturn " << number << ";\n}\n";
				cout << Rank[i] << Rank[j] << " number " << number << endl;
				number++;
			}
			if (i != j) {
				write << "if ((card1[0] == '" << Rank[i] << "' || card2[0] == '" << Rank[i] << "') && (card1[0] == '" << Rank[j] << "' || card2[0] == '" << Rank[j] << "')) {\npreflop_card1 = '" << Rank[i] << "';\npreflop_card2 = '" << Rank[j] << "';\nnSuited = 1;\nreturn " << number << ";\n}\n";
				number++;
				write << "if ((card1[0] == '" << Rank[i] << "' || card2[0] == '" << Rank[i] << "') && (card1[0] == '" << Rank[j] << "' || card2[0] == '" << Rank[j] << "') && card1[1] == card2[1]) {\npreflop_card1 = '" << Rank[i] << "' ;\npreflop_card2 = '" << Rank[j] << "';\nnSuited = 2;\nreturn " << number << ";\n}\n";
				cout << Rank[i] << Rank[j] << "s number " << number << endl;
				number++;
			}
		}
	}
	write.close();


	exit(0);

};
void prwin_calcolator::WriteCodeForFlopNumber() {

	int number = 1;
	ofstream write;
	ifstream read;
	write.open("txt/TEST.txt");

	for (int i = 0; i < 13; i++) {
		for (int j = i; j < 13; j++) {
			for (int k = j; k < 13; k++) {
				if (i == j && j == k) {
					write << "if (card1[0] == '" << Rank[i] << "' && card2[0] == '" << Rank[j] << "' && card3[0] == '" << Rank[k] << "') {\npreflop_card1 = '" << Rank[i] << "';\npreflop_card2 = '" << Rank[j] << "';\npreflop_card3 = '" << Rank[k] << "';\nnSuited = 1;\nreturn " << number << ";\n}\n";
					cout << Rank[i] << Rank[j] << Rank[k] << " number " << number << endl;
					number++;
				}
				if (i != j && j != k && i != k) {
					write << "if ((card1[0] == '" << Rank[i] << "' || card2[0] == '" << Rank[i] << "' || card3[0] == '" << Rank[i] << "') && (card1[0] == '" << Rank[j] << "' || card2[0] == '" << Rank[j] << "' || card3[0] == '" << Rank[j] << "') && (card1[0] == '" << Rank[k] << "' || card2[0] == '" << Rank[k] << "' || card3[0] == '" << Rank[k] << "')) {\npreflop_card1 = '" << Rank[i] << "';\npreflop_card2 = '" << Rank[j] << "';\npreflop_card3 = '" << Rank[k] << "';\nnSuited = 1;\nreturn " << number << ";\n}\n";
					number++;
					write << "if (((card1[0] == '" << Rank[i] << "' && card2[0] == '" << Rank[j] << "') || (card1[0] == '" << Rank[j] << "' && card2[0] == '" << Rank[i] << "')) && (card3[0] == '" << Rank[k] << "' && card1[1] == card2[1] && card2[1] == card3[1])) {\npreflop_card1 = '" << Rank[i] << "' ;\npreflop_card2 = '" << Rank[j] << "';\npreflop_card3 = '" << Rank[k] << "';\nnSuited = 3;\nreturn " << number << ";\n}\n";
					number++;
					write << "if (((card1[0] == '" << Rank[i] << "' && card2[0] == '" << Rank[j] << "') || (card1[0] == '" << Rank[j] << "' && card2[0] == '" << Rank[i] << "')) && ((card1[0] == '" << Rank[k] << "' && card3[0]== '" << Rank[k] << "') || (card2[0] == '" << Rank[k] << "' && card3[0] == '" << Rank[j] << "') || (card1[0] == '" << Rank[k] << "' && card3[0] == '" << Rank[j] << "')) && card1[1] != card2[1] && card1[1] != card3[1] && card2[1] != card3[1]) {\npreflop_card1 = '" << Rank[i] << "'; \npreflop_card2 = '" << Rank[j] << "'; \npreflop_card3 = '" << Rank[k] << "'; \nnSuited = 2; \nreturn " << number << "; \n}\n";
						number++;
					write << "if (((card1[0] == '" << Rank[i] << "' && card2[0] == '" << Rank[k] << "') || (card1[0] == '" << Rank[k] << "' && card2[0] == '" << Rank[i] << "')) && ((card1[0] == '" << Rank[j] << "' && card3[0] == '" << Rank[j] << "') || (card2[0] == '" << Rank[j] << "' && card3[0] == '" << Rank[j] << "') || (card1[0] == '" << Rank[j] << "' && card3[0] == '" << Rank[k] << "')) && card1[1] != card2[1] && card1[1] != card3[1] && card2[1] != card3[1]) {\npreflop_card1 = '" << Rank[i] << "' ;\npreflop_card2 = '" << Rank[j] << "';\npreflop_card3 = '" << Rank[k] << "';\nnSuited = 2;\nreturn " << number << ";\n}\n";
					number++;
				}
			}
		}
	}
	write.close();

}

double prwin_calcolator::GetMinPrwinBasedOnStack(int _StackSize) {
	if (_StackSize >= 200)return 0.4;

	double diffBB = _StackSize - 100;

	// Calcola la prwin regolata
	double adjusted_prwin = 0.5 - (diffBB * 0.001);

	return adjusted_prwin;

}

double prwin_calcolator::adjust_prwin(double prwin_single, int num_opponents, double k) {
	return prwin_single * exp(-k * (num_opponents - 1));
}

enum BetRound { Preflop = 1, Flop, Turn, River };
enum Action { None, Fold, Check, Call, Raise, Allin };
enum StackSize { BigStack, MediumStack, ShortStack };

void prwin_calcolator::generateCode() {
	ofstream a;
	a.open("generated code.txt");

	auto writeposition = []() ->string {
		string line = "";
		line += "POSIZIONI\n";

		return line;

		};

	a << "Switch(*Betround){\n";
	for (int i = 1; i < 5; i++) {		
		a << "	case " << i << ":\n";










		a << "	break;\n\n";
	}



	a << "};//betround";




	exit(0);
}
