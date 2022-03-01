#include "CHandStrength.h"
int CHandStrength::calc_HandStrength(string card1, string card2, string card3, string card4, string card5, string card6, string card7) {

	Reset_CountCard();
	card[0] = card1;
	card[1] = card2;
	card[2] = card3;
	card[3] = card4;
	card[4] = card5;
	card[5] = card6;
	card[6] = card7;	

	CountCard();


	int nFour = 0;
	int nTrips = 0;
	int nPairs = 0;
	//count hand
	for (int i = 0; i < 13; i++) {
		if (TotCard[i] == 4) { nFour++; }
		if (TotCard[i] == 3) { nTrips++; }
		if (TotCard[i] == 2) { nPairs++; }
	}

	//straight flush
	if (nc >= 5 || nd >= 5 || ns >= 5 || nh >= 5) {
		HandStrength = 11000;
		if (cA == 1 && cK == 1 && cQ == 1 && cJ == 1 && cT == 1) { return HandStrength; };
		if (hA == 1 && hK == 1 && hQ == 1 && hJ == 1 && hT == 1) { return HandStrength; };
		if (sA == 1 && sK == 1 && sQ == 1 && sJ == 1 && sT == 1) { return HandStrength; };
		if (dA == 1 && dK == 1 && dQ == 1 && dJ == 1 && dT == 1) { return HandStrength; };

		HandStrength -= 1;

		if (cK == 1 && cQ == 1 && cJ == 1 && cT == 1 && c9 == 1) { return HandStrength; };
		if (hK == 1 && hQ == 1 && hJ == 1 && hT == 1 && h9 == 1) { return HandStrength; };
		if (sK == 1 && sQ == 1 && sJ == 1 && sT == 1 && s9 == 1) { return HandStrength; };
		if (dK == 1 && dQ == 1 && dJ == 1 && dT == 1 && d9 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (cQ == 1 && cJ == 1 && cT == 1 && c9 == 1 && c8 == 1) { return HandStrength; };
		if (hQ == 1 && hJ == 1 && hT == 1 && h9 == 1 && h8 == 1) { return HandStrength; };
		if (sQ == 1 && sJ == 1 && sT == 1 && s9 == 1 && s8 == 1) { return HandStrength; };
		if (dQ == 1 && dJ == 1 && dT == 1 && d9 == 1 && d8 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (cJ == 1 && cT == 1 && c9 == 1 && c8 == 1 && c7 == 1) { return HandStrength; };
		if (hJ == 1 && hT == 1 && h9 == 1 && h8 == 1 && h7 == 1) { return HandStrength; };
		if (sJ == 1 && sT == 1 && s9 == 1 && s8 == 1 && s7 == 1) { return HandStrength; };
		if (dJ == 1 && dT == 1 && d9 == 1 && d8 == 1 && d7 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (cT == 1 && c9 == 1 && c8 == 1 && c7 == 1 && c6 == 1) { return HandStrength; };
		if (hT == 1 && h9 == 1 && h8 == 1 && h7 == 1 && h6 == 1) { return HandStrength; };
		if (sT == 1 && s9 == 1 && s8 == 1 && s7 == 1 && s6 == 1) { return HandStrength; };
		if (dT == 1 && d9 == 1 && d8 == 1 && d7 == 1 && d6 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (c9 == 1 && c8 == 1 && c7 == 1 && c6 == 1 && c5 == 1) { return HandStrength; };
		if (h9 == 1 && h8 == 1 && h7 == 1 && h6 == 1 && h5 == 1) { return HandStrength; };
		if (s9 == 1 && s8 == 1 && s7 == 1 && s6 == 1 && s5 == 1) { return HandStrength; };
		if (d9 == 1 && d8 == 1 && d7 == 1 && d6 == 1 && d5 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (c8 == 1 && c7 == 1 && c6 == 1 && c5 == 1 && c7 == 1) { return HandStrength; };
		if (h8 == 1 && h7 == 1 && h6 == 1 && h5 == 1 && h7 == 1) { return HandStrength; };
		if (s8 == 1 && s7 == 1 && s6 == 1 && s5 == 1 && s7 == 1) { return HandStrength; };
		if (d8 == 1 && d7 == 1 && d6 == 1 && d5 == 1 && d7 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (c7 == 1 && c6 == 1 && c5 == 1 && c4 == 1 && c3 == 1) { return HandStrength; };
		if (h7 == 1 && h6 == 1 && h5 == 1 && h4 == 1 && h3 == 1) { return HandStrength; };
		if (s7 == 1 && s6 == 1 && s5 == 1 && s4 == 1 && s3 == 1) { return HandStrength; };
		if (d7 == 1 && d6 == 1 && d5 == 1 && d4 == 1 && d3 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (c6 == 1 && c5 == 1 && c4 == 1 && c3 == 1 && c2 == 1) { return HandStrength; };
		if (h6 == 1 && h5 == 1 && h4 == 1 && h3 == 1 && h2 == 1) { return HandStrength; };
		if (s6 == 1 && s5 == 1 && s4 == 1 && s3 == 1 && s2 == 1) { return HandStrength; };
		if (d6 == 1 && d5 == 1 && d4 == 1 && d3 == 1 && d2 == 1) { return HandStrength; };
		HandStrength -= 1;

		if (c5 == 1 && c4 == 1 && c3 == 1 && c2 == 1 && cA == 1) { return HandStrength; };
		if (h5 == 1 && h4 == 1 && h3 == 1 && h2 == 1 && hA == 1) { return HandStrength; };
		if (s5 == 1 && s4 == 1 && s3 == 1 && s2 == 1 && sA == 1) { return HandStrength; };
		if (d5 == 1 && d4 == 1 && d3 == 1 && d2 == 1 && dA == 1) { return HandStrength; }
		HandStrength -= 1;
	}

	//FourOfAKind
	if (nFour >= 1) {
		HandStrength = 10000;
		if (CheckKicker == false) { return HandStrength; };

		if (nA == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (nK == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (nQ == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (nJ == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (nT == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n9 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n8 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n7 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n6 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n5 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n4 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n3 == 4) { return HandStrength; }
		else { HandStrength -= 1; }
		if (n2 == 4) { return HandStrength; }
		else { HandStrength -= 1; }

	}

	//FullHouse
	if ((nTrips >= 1 && nPairs >= 1) || 
		nTrips == 2) {
		HandStrength = 9000;
		if (CheckKicker == false) { return HandStrength; };
		if (nA == 3) {
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}		
		else if (nK == 3) {
			HandStrength -= 12;
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (nQ == 3) {
			HandStrength -= (12*2);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (nJ == 3) {
			HandStrength -= (12 * 3);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (nT == 3) {
			HandStrength -= (12 * 4);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n9 == 3) {
			HandStrength -= (12 * 5);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n8 == 3) {
			HandStrength -= (12 * 6);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n7 == 3) {
			HandStrength -= (12 * 7);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n6 == 3) {
			HandStrength -= (12 * 8);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n5 == 3) {
			HandStrength -= (12 * 9);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n4 == 3) {
			HandStrength -= (12 * 10);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n3 == 3) {
			HandStrength -= (12 * 11);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n2 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		}
		else if (n2 == 3) {
			HandStrength -= (12 * 12);
			if (nA >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nK >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nQ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nJ >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (nT >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n9 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n8 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n7 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n6 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n5 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n4 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
			if (n3 >= 2) { return HandStrength; }
			else { HandStrength -= 1; }
		};
	}

	//Flush
	if (nc >= 5 || nd >= 5 || ns >= 5 || nh >= 5) {
		HandStrength = 8000;
		if (CheckKicker == false) { return HandStrength; };

		if (nc >= 5 && (card[0] == "Ac" || card[1] == "Ac")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "Ah" || card[1] == "Ah")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "As" || card[1] == "As")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "Ad" || card[1] == "Ad")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "Kc" || card[1] == "Kc")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "Kh" || card[1] == "Kh")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "Ks" || card[1] == "Ks")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "Kd" || card[1] == "Kd")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "Qc" || card[1] == "Qc")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "Qh" || card[1] == "Qh")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "Qs" || card[1] == "Qs")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "Qd" || card[1] == "Qd")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "Jc" || card[1] == "Jc")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "Jh" || card[1] == "Jh")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "Js" || card[1] == "Js")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "Jd" || card[1] == "Jd")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "Tc" || card[1] == "Tc")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "Th" || card[1] == "Th")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "Ts" || card[1] == "Ts")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "Td" || card[1] == "Td")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "9c" || card[1] == "9c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "9h" || card[1] == "9h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "9s" || card[1] == "9s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "9d" || card[1] == "9d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "8c" || card[1] == "8c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "8h" || card[1] == "8h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "8s" || card[1] == "8s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "8d" || card[1] == "8d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "7c" || card[1] == "7c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "7h" || card[1] == "7h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "7s" || card[1] == "7s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "7d" || card[1] == "7d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "6c" || card[1] == "6c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "6h" || card[1] == "6h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "6s" || card[1] == "6s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "6d" || card[1] == "6d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "5c" || card[1] == "5c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "5h" || card[1] == "5h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "5s" || card[1] == "5s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "5d" || card[1] == "5d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "4c" || card[1] == "4c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "4h" || card[1] == "4h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "4s" || card[1] == "4s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "4d" || card[1] == "4d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "3c" || card[1] == "3c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "3h" || card[1] == "3h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "3s" || card[1] == "3s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "3d" || card[1] == "3d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5 && (card[0] == "2c" || card[1] == "2c")) { return HandStrength; };
		if (nh >= 5 && (card[0] == "2h" || card[1] == "2h")) { return HandStrength; };
		if (ns >= 5 && (card[0] == "2s" || card[1] == "2s")) { return HandStrength; };
		if (nd >= 5 && (card[0] == "2d" || card[1] == "2d")) { return HandStrength; };
		HandStrength -= 1;

		if (nc >= 5) { return HandStrength; };
		if (nh >= 5) { return HandStrength; };
		if (ns >= 5) { return HandStrength; };
		if (nd >= 5) { return HandStrength; }

	}


	HandStrength = 7000;
	//Straight
	if (nA >= 1 && nK >= 1 && nQ >= 1 && nJ >= 1 && nT >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (nK >= 1 && nQ >= 1 && nJ >= 1 && nT >= 1 && n9 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (nQ >= 1 && nJ >= 1 && nT >= 1 && n9 >= 1 && n8 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (nJ >= 1 && nT >= 1 && n9 >= 1 && n8 >= 1 && n7 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (nT >= 1 && n9 >= 1 && n8 >= 1 && n7 >= 1 && n6 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (n9 >= 1 && n8 >= 1 && n7 >= 1 && n6 >= 1 && n5 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (n8 >= 1 && n7 >= 1 && n6 >= 1 && n5 >= 1 && n4 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (n7 >= 1 && n6 >= 1 && n5 >= 1 && n4 >= 1 && n3 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (n6 >= 1 && n5 >= 1 && n4 >= 1 && n3 >= 1 && n2 >= 1) { return HandStrength; }
	else { HandStrength -= 1; };
	if (n5 >= 1 && n4 >= 1 && n3 >= 1 && n2 >= 1 && nA >= 1) { return HandStrength; }
	else { HandStrength -= 1; };


	//ThreeOfAKind
	if (nTrips >= 1) {
		HandStrength = 6000;
		if (CheckKicker == false) { return HandStrength; };
		if (nA == 3) {
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 6000; return HandStrength; }
					if (nT == 1) { HandStrength = 5999; return HandStrength; }
					if (n9 == 1) { HandStrength = 5998; return HandStrength; }
					if (n8 == 1) { HandStrength = 5997; return HandStrength; }
					if (n7 == 1) { HandStrength = 5996; return HandStrength; }
					if (n6 == 1) { HandStrength = 5995; return HandStrength; }
					if (n5 == 1) { HandStrength = 5994; return HandStrength; }
					if (n4 == 1) { HandStrength = 5993; return HandStrength; }
					if (n3 == 1) { HandStrength = 5992; return HandStrength; }
					if (n2 == 1) { HandStrength = 5991; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5990; return HandStrength; }
					if (n9 == 1) { HandStrength = 5989; return HandStrength; }
					if (n8 == 1) { HandStrength = 5988; return HandStrength; }
					if (n7 == 1) { HandStrength = 5987; return HandStrength; }
					if (n6 == 1) { HandStrength = 5986; return HandStrength; }
					if (n5 == 1) { HandStrength = 5985; return HandStrength; }
					if (n4 == 1) { HandStrength = 5984; return HandStrength; }
					if (n3 == 1) { HandStrength = 5983; return HandStrength; }
					if (n2 == 1) { HandStrength = 5982; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5981; return HandStrength; }
					if (n8 == 1) { HandStrength = 5980; return HandStrength; }
					if (n7 == 1) { HandStrength = 5979; return HandStrength; }
					if (n6 == 1) { HandStrength = 5978; return HandStrength; }
					if (n5 == 1) { HandStrength = 5977; return HandStrength; }
					if (n4 == 1) { HandStrength = 5976; return HandStrength; }
					if (n3 == 1) { HandStrength = 5975; return HandStrength; }
					if (n2 == 1) { HandStrength = 5974; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5973; return HandStrength; }
					if (n7 == 1) { HandStrength = 5972; return HandStrength; }
					if (n6 == 1) { HandStrength = 5971; return HandStrength; }
					if (n5 == 1) { HandStrength = 5970; return HandStrength; }
					if (n4 == 1) { HandStrength = 5969; return HandStrength; }
					if (n3 == 1) { HandStrength = 5968; return HandStrength; }
					if (n2 == 1) { HandStrength = 5967; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5966; return HandStrength; }
					if (n6 == 1) { HandStrength = 5965; return HandStrength; }
					if (n5 == 1) { HandStrength = 5964; return HandStrength; }
					if (n4 == 1) { HandStrength = 5963; return HandStrength; }
					if (n3 == 1) { HandStrength = 5962; return HandStrength; }
					if (n2 == 1) { HandStrength = 5961; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5960; return HandStrength; }
					if (n5 == 1) { HandStrength = 5959; return HandStrength; }
					if (n4 == 1) { HandStrength = 5958; return HandStrength; }
					if (n3 == 1) { HandStrength = 5957; return HandStrength; }
					if (n2 == 1) { HandStrength = 5956; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5955; return HandStrength; }
					if (n4 == 1) { HandStrength = 5954; return HandStrength; }
					if (n3 == 1) { HandStrength = 5953; return HandStrength; }
					if (n2 == 1) { HandStrength = 5952; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5951; return HandStrength; }
					if (n3 == 1) { HandStrength = 5950; return HandStrength; }
					if (n2 == 1) { HandStrength = 5949; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5948; return HandStrength; }
					if (n2 == 1) { HandStrength = 5947; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5946; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5945; return HandStrength; }
					if (n9 == 1) { HandStrength = 5944; return HandStrength; }
					if (n8 == 1) { HandStrength = 5943; return HandStrength; }
					if (n7 == 1) { HandStrength = 5942; return HandStrength; }
					if (n6 == 1) { HandStrength = 5941; return HandStrength; }
					if (n5 == 1) { HandStrength = 5940; return HandStrength; }
					if (n4 == 1) { HandStrength = 5939; return HandStrength; }
					if (n3 == 1) { HandStrength = 5938; return HandStrength; }
					if (n2 == 1) { HandStrength = 5937; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5936; return HandStrength; }
					if (n8 == 1) { HandStrength = 5935; return HandStrength; }
					if (n7 == 1) { HandStrength = 5934; return HandStrength; }
					if (n6 == 1) { HandStrength = 5933; return HandStrength; }
					if (n5 == 1) { HandStrength = 5932; return HandStrength; }
					if (n4 == 1) { HandStrength = 5931; return HandStrength; }
					if (n3 == 1) { HandStrength = 5930; return HandStrength; }
					if (n2 == 1) { HandStrength = 5929; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5928; return HandStrength; }
					if (n7 == 1) { HandStrength = 5927; return HandStrength; }
					if (n6 == 1) { HandStrength = 5926; return HandStrength; }
					if (n5 == 1) { HandStrength = 5925; return HandStrength; }
					if (n4 == 1) { HandStrength = 5924; return HandStrength; }
					if (n3 == 1) { HandStrength = 5923; return HandStrength; }
					if (n2 == 1) { HandStrength = 5922; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5921; return HandStrength; }
					if (n6 == 1) { HandStrength = 5920; return HandStrength; }
					if (n5 == 1) { HandStrength = 5919; return HandStrength; }
					if (n4 == 1) { HandStrength = 5918; return HandStrength; }
					if (n3 == 1) { HandStrength = 5917; return HandStrength; }
					if (n2 == 1) { HandStrength = 5916; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5915; return HandStrength; }
					if (n5 == 1) { HandStrength = 5914; return HandStrength; }
					if (n4 == 1) { HandStrength = 5913; return HandStrength; }
					if (n3 == 1) { HandStrength = 5912; return HandStrength; }
					if (n2 == 1) { HandStrength = 5911; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5910; return HandStrength; }
					if (n4 == 1) { HandStrength = 5909; return HandStrength; }
					if (n3 == 1) { HandStrength = 5908; return HandStrength; }
					if (n2 == 1) { HandStrength = 5907; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5906; return HandStrength; }
					if (n3 == 1) { HandStrength = 5905; return HandStrength; }
					if (n2 == 1) { HandStrength = 5904; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5903; return HandStrength; }
					if (n2 == 1) { HandStrength = 5902; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5901; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5900; return HandStrength; }
					if (n8 == 1) { HandStrength = 5899; return HandStrength; }
					if (n7 == 1) { HandStrength = 5898; return HandStrength; }
					if (n6 == 1) { HandStrength = 5897; return HandStrength; }
					if (n5 == 1) { HandStrength = 5896; return HandStrength; }
					if (n4 == 1) { HandStrength = 5895; return HandStrength; }
					if (n3 == 1) { HandStrength = 5894; return HandStrength; }
					if (n2 == 1) { HandStrength = 5893; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5892; return HandStrength; }
					if (n7 == 1) { HandStrength = 5891; return HandStrength; }
					if (n6 == 1) { HandStrength = 5890; return HandStrength; }
					if (n5 == 1) { HandStrength = 5889; return HandStrength; }
					if (n4 == 1) { HandStrength = 5888; return HandStrength; }
					if (n3 == 1) { HandStrength = 5887; return HandStrength; }
					if (n2 == 1) { HandStrength = 5886; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5885; return HandStrength; }
					if (n6 == 1) { HandStrength = 5884; return HandStrength; }
					if (n5 == 1) { HandStrength = 5883; return HandStrength; }
					if (n4 == 1) { HandStrength = 5882; return HandStrength; }
					if (n3 == 1) { HandStrength = 5881; return HandStrength; }
					if (n2 == 1) { HandStrength = 5880; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5879; return HandStrength; }
					if (n5 == 1) { HandStrength = 5878; return HandStrength; }
					if (n4 == 1) { HandStrength = 5877; return HandStrength; }
					if (n3 == 1) { HandStrength = 5876; return HandStrength; }
					if (n2 == 1) { HandStrength = 5875; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5874; return HandStrength; }
					if (n4 == 1) { HandStrength = 5873; return HandStrength; }
					if (n3 == 1) { HandStrength = 5872; return HandStrength; }
					if (n2 == 1) { HandStrength = 5871; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5870; return HandStrength; }
					if (n3 == 1) { HandStrength = 5869; return HandStrength; }
					if (n2 == 1) { HandStrength = 5868; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5867; return HandStrength; }
					if (n2 == 1) { HandStrength = 5866; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5865; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5864; return HandStrength; }
					if (n7 == 1) { HandStrength = 5863; return HandStrength; }
					if (n6 == 1) { HandStrength = 5862; return HandStrength; }
					if (n5 == 1) { HandStrength = 5861; return HandStrength; }
					if (n4 == 1) { HandStrength = 5860; return HandStrength; }
					if (n3 == 1) { HandStrength = 5859; return HandStrength; }
					if (n2 == 1) { HandStrength = 5858; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5857; return HandStrength; }
					if (n6 == 1) { HandStrength = 5856; return HandStrength; }
					if (n5 == 1) { HandStrength = 5855; return HandStrength; }
					if (n4 == 1) { HandStrength = 5854; return HandStrength; }
					if (n3 == 1) { HandStrength = 5853; return HandStrength; }
					if (n2 == 1) { HandStrength = 5852; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5851; return HandStrength; }
					if (n5 == 1) { HandStrength = 5850; return HandStrength; }
					if (n4 == 1) { HandStrength = 5849; return HandStrength; }
					if (n3 == 1) { HandStrength = 5848; return HandStrength; }
					if (n2 == 1) { HandStrength = 5847; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5846; return HandStrength; }
					if (n4 == 1) { HandStrength = 5845; return HandStrength; }
					if (n3 == 1) { HandStrength = 5844; return HandStrength; }
					if (n2 == 1) { HandStrength = 5843; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5842; return HandStrength; }
					if (n3 == 1) { HandStrength = 5841; return HandStrength; }
					if (n2 == 1) { HandStrength = 5840; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5839; return HandStrength; }
					if (n2 == 1) { HandStrength = 5838; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5837; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5836; return HandStrength; }
					if (n6 == 1) { HandStrength = 5835; return HandStrength; }
					if (n5 == 1) { HandStrength = 5834; return HandStrength; }
					if (n4 == 1) { HandStrength = 5833; return HandStrength; }
					if (n3 == 1) { HandStrength = 5832; return HandStrength; }
					if (n2 == 1) { HandStrength = 5831; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5830; return HandStrength; }
					if (n5 == 1) { HandStrength = 5829; return HandStrength; }
					if (n4 == 1) { HandStrength = 5828; return HandStrength; }
					if (n3 == 1) { HandStrength = 5827; return HandStrength; }
					if (n2 == 1) { HandStrength = 5826; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5825; return HandStrength; }
					if (n4 == 1) { HandStrength = 5824; return HandStrength; }
					if (n3 == 1) { HandStrength = 5823; return HandStrength; }
					if (n2 == 1) { HandStrength = 5822; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5821; return HandStrength; }
					if (n3 == 1) { HandStrength = 5820; return HandStrength; }
					if (n2 == 1) { HandStrength = 5819; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5818; return HandStrength; }
					if (n2 == 1) { HandStrength = 5817; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5816; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5815; return HandStrength; }
					if (n5 == 1) { HandStrength = 5814; return HandStrength; }
					if (n4 == 1) { HandStrength = 5813; return HandStrength; }
					if (n3 == 1) { HandStrength = 5812; return HandStrength; }
					if (n2 == 1) { HandStrength = 5811; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5810; return HandStrength; }
					if (n4 == 1) { HandStrength = 5809; return HandStrength; }
					if (n3 == 1) { HandStrength = 5808; return HandStrength; }
					if (n2 == 1) { HandStrength = 5807; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5806; return HandStrength; }
					if (n3 == 1) { HandStrength = 5805; return HandStrength; }
					if (n2 == 1) { HandStrength = 5804; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5803; return HandStrength; }
					if (n2 == 1) { HandStrength = 5802; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5801; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5800; return HandStrength; }
					if (n4 == 1) { HandStrength = 5799; return HandStrength; }
					if (n3 == 1) { HandStrength = 5798; return HandStrength; }
					if (n2 == 1) { HandStrength = 5797; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5796; return HandStrength; }
					if (n3 == 1) { HandStrength = 5795; return HandStrength; }
					if (n2 == 1) { HandStrength = 5794; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5793; return HandStrength; }
					if (n2 == 1) { HandStrength = 5792; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5791; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5790; return HandStrength; }
					if (n3 == 1) { HandStrength = 5789; return HandStrength; }
					if (n2 == 1) { HandStrength = 5788; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5787; return HandStrength; }
					if (n2 == 1) { HandStrength = 5786; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5785; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5784; return HandStrength; }
					if (n2 == 1) { HandStrength = 5783; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5782; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5781; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nK == 3) {
			if (nA == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 5780; return HandStrength; }
					if (nT == 1) { HandStrength = 5779; return HandStrength; }
					if (n9 == 1) { HandStrength = 5778; return HandStrength; }
					if (n8 == 1) { HandStrength = 5777; return HandStrength; }
					if (n7 == 1) { HandStrength = 5776; return HandStrength; }
					if (n6 == 1) { HandStrength = 5775; return HandStrength; }
					if (n5 == 1) { HandStrength = 5774; return HandStrength; }
					if (n4 == 1) { HandStrength = 5773; return HandStrength; }
					if (n3 == 1) { HandStrength = 5772; return HandStrength; }
					if (n2 == 1) { HandStrength = 5771; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5770; return HandStrength; }
					if (n9 == 1) { HandStrength = 5769; return HandStrength; }
					if (n8 == 1) { HandStrength = 5768; return HandStrength; }
					if (n7 == 1) { HandStrength = 5767; return HandStrength; }
					if (n6 == 1) { HandStrength = 5766; return HandStrength; }
					if (n5 == 1) { HandStrength = 5765; return HandStrength; }
					if (n4 == 1) { HandStrength = 5764; return HandStrength; }
					if (n3 == 1) { HandStrength = 5763; return HandStrength; }
					if (n2 == 1) { HandStrength = 5762; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5761; return HandStrength; }
					if (n8 == 1) { HandStrength = 5760; return HandStrength; }
					if (n7 == 1) { HandStrength = 5759; return HandStrength; }
					if (n6 == 1) { HandStrength = 5758; return HandStrength; }
					if (n5 == 1) { HandStrength = 5757; return HandStrength; }
					if (n4 == 1) { HandStrength = 5756; return HandStrength; }
					if (n3 == 1) { HandStrength = 5755; return HandStrength; }
					if (n2 == 1) { HandStrength = 5754; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5753; return HandStrength; }
					if (n7 == 1) { HandStrength = 5752; return HandStrength; }
					if (n6 == 1) { HandStrength = 5751; return HandStrength; }
					if (n5 == 1) { HandStrength = 5750; return HandStrength; }
					if (n4 == 1) { HandStrength = 5749; return HandStrength; }
					if (n3 == 1) { HandStrength = 5748; return HandStrength; }
					if (n2 == 1) { HandStrength = 5747; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5746; return HandStrength; }
					if (n6 == 1) { HandStrength = 5745; return HandStrength; }
					if (n5 == 1) { HandStrength = 5744; return HandStrength; }
					if (n4 == 1) { HandStrength = 5743; return HandStrength; }
					if (n3 == 1) { HandStrength = 5742; return HandStrength; }
					if (n2 == 1) { HandStrength = 5741; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5740; return HandStrength; }
					if (n5 == 1) { HandStrength = 5739; return HandStrength; }
					if (n4 == 1) { HandStrength = 5738; return HandStrength; }
					if (n3 == 1) { HandStrength = 5737; return HandStrength; }
					if (n2 == 1) { HandStrength = 5736; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5735; return HandStrength; }
					if (n4 == 1) { HandStrength = 5734; return HandStrength; }
					if (n3 == 1) { HandStrength = 5733; return HandStrength; }
					if (n2 == 1) { HandStrength = 5732; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5731; return HandStrength; }
					if (n3 == 1) { HandStrength = 5730; return HandStrength; }
					if (n2 == 1) { HandStrength = 5729; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5728; return HandStrength; }
					if (n2 == 1) { HandStrength = 5727; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5726; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5725; return HandStrength; }
					if (n9 == 1) { HandStrength = 5724; return HandStrength; }
					if (n8 == 1) { HandStrength = 5723; return HandStrength; }
					if (n7 == 1) { HandStrength = 5722; return HandStrength; }
					if (n6 == 1) { HandStrength = 5721; return HandStrength; }
					if (n5 == 1) { HandStrength = 5720; return HandStrength; }
					if (n4 == 1) { HandStrength = 5719; return HandStrength; }
					if (n3 == 1) { HandStrength = 5718; return HandStrength; }
					if (n2 == 1) { HandStrength = 5717; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5716; return HandStrength; }
					if (n8 == 1) { HandStrength = 5715; return HandStrength; }
					if (n7 == 1) { HandStrength = 5714; return HandStrength; }
					if (n6 == 1) { HandStrength = 5713; return HandStrength; }
					if (n5 == 1) { HandStrength = 5712; return HandStrength; }
					if (n4 == 1) { HandStrength = 5711; return HandStrength; }
					if (n3 == 1) { HandStrength = 5710; return HandStrength; }
					if (n2 == 1) { HandStrength = 5709; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5708; return HandStrength; }
					if (n7 == 1) { HandStrength = 5707; return HandStrength; }
					if (n6 == 1) { HandStrength = 5706; return HandStrength; }
					if (n5 == 1) { HandStrength = 5705; return HandStrength; }
					if (n4 == 1) { HandStrength = 5704; return HandStrength; }
					if (n3 == 1) { HandStrength = 5703; return HandStrength; }
					if (n2 == 1) { HandStrength = 5702; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5701; return HandStrength; }
					if (n6 == 1) { HandStrength = 5700; return HandStrength; }
					if (n5 == 1) { HandStrength = 5699; return HandStrength; }
					if (n4 == 1) { HandStrength = 5698; return HandStrength; }
					if (n3 == 1) { HandStrength = 5697; return HandStrength; }
					if (n2 == 1) { HandStrength = 5696; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5695; return HandStrength; }
					if (n5 == 1) { HandStrength = 5694; return HandStrength; }
					if (n4 == 1) { HandStrength = 5693; return HandStrength; }
					if (n3 == 1) { HandStrength = 5692; return HandStrength; }
					if (n2 == 1) { HandStrength = 5691; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5690; return HandStrength; }
					if (n4 == 1) { HandStrength = 5689; return HandStrength; }
					if (n3 == 1) { HandStrength = 5688; return HandStrength; }
					if (n2 == 1) { HandStrength = 5687; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5686; return HandStrength; }
					if (n3 == 1) { HandStrength = 5685; return HandStrength; }
					if (n2 == 1) { HandStrength = 5684; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5683; return HandStrength; }
					if (n2 == 1) { HandStrength = 5682; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5681; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5680; return HandStrength; }
					if (n8 == 1) { HandStrength = 5679; return HandStrength; }
					if (n7 == 1) { HandStrength = 5678; return HandStrength; }
					if (n6 == 1) { HandStrength = 5677; return HandStrength; }
					if (n5 == 1) { HandStrength = 5676; return HandStrength; }
					if (n4 == 1) { HandStrength = 5675; return HandStrength; }
					if (n3 == 1) { HandStrength = 5674; return HandStrength; }
					if (n2 == 1) { HandStrength = 5673; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5672; return HandStrength; }
					if (n7 == 1) { HandStrength = 5671; return HandStrength; }
					if (n6 == 1) { HandStrength = 5670; return HandStrength; }
					if (n5 == 1) { HandStrength = 5669; return HandStrength; }
					if (n4 == 1) { HandStrength = 5668; return HandStrength; }
					if (n3 == 1) { HandStrength = 5667; return HandStrength; }
					if (n2 == 1) { HandStrength = 5666; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5665; return HandStrength; }
					if (n6 == 1) { HandStrength = 5664; return HandStrength; }
					if (n5 == 1) { HandStrength = 5663; return HandStrength; }
					if (n4 == 1) { HandStrength = 5662; return HandStrength; }
					if (n3 == 1) { HandStrength = 5661; return HandStrength; }
					if (n2 == 1) { HandStrength = 5660; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5659; return HandStrength; }
					if (n5 == 1) { HandStrength = 5658; return HandStrength; }
					if (n4 == 1) { HandStrength = 5657; return HandStrength; }
					if (n3 == 1) { HandStrength = 5656; return HandStrength; }
					if (n2 == 1) { HandStrength = 5655; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5654; return HandStrength; }
					if (n4 == 1) { HandStrength = 5653; return HandStrength; }
					if (n3 == 1) { HandStrength = 5652; return HandStrength; }
					if (n2 == 1) { HandStrength = 5651; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5650; return HandStrength; }
					if (n3 == 1) { HandStrength = 5649; return HandStrength; }
					if (n2 == 1) { HandStrength = 5648; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5647; return HandStrength; }
					if (n2 == 1) { HandStrength = 5646; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5645; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5644; return HandStrength; }
					if (n7 == 1) { HandStrength = 5643; return HandStrength; }
					if (n6 == 1) { HandStrength = 5642; return HandStrength; }
					if (n5 == 1) { HandStrength = 5641; return HandStrength; }
					if (n4 == 1) { HandStrength = 5640; return HandStrength; }
					if (n3 == 1) { HandStrength = 5639; return HandStrength; }
					if (n2 == 1) { HandStrength = 5638; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5637; return HandStrength; }
					if (n6 == 1) { HandStrength = 5636; return HandStrength; }
					if (n5 == 1) { HandStrength = 5635; return HandStrength; }
					if (n4 == 1) { HandStrength = 5634; return HandStrength; }
					if (n3 == 1) { HandStrength = 5633; return HandStrength; }
					if (n2 == 1) { HandStrength = 5632; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5631; return HandStrength; }
					if (n5 == 1) { HandStrength = 5630; return HandStrength; }
					if (n4 == 1) { HandStrength = 5629; return HandStrength; }
					if (n3 == 1) { HandStrength = 5628; return HandStrength; }
					if (n2 == 1) { HandStrength = 5627; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5626; return HandStrength; }
					if (n4 == 1) { HandStrength = 5625; return HandStrength; }
					if (n3 == 1) { HandStrength = 5624; return HandStrength; }
					if (n2 == 1) { HandStrength = 5623; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5622; return HandStrength; }
					if (n3 == 1) { HandStrength = 5621; return HandStrength; }
					if (n2 == 1) { HandStrength = 5620; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5619; return HandStrength; }
					if (n2 == 1) { HandStrength = 5618; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5617; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5616; return HandStrength; }
					if (n6 == 1) { HandStrength = 5615; return HandStrength; }
					if (n5 == 1) { HandStrength = 5614; return HandStrength; }
					if (n4 == 1) { HandStrength = 5613; return HandStrength; }
					if (n3 == 1) { HandStrength = 5612; return HandStrength; }
					if (n2 == 1) { HandStrength = 5611; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5610; return HandStrength; }
					if (n5 == 1) { HandStrength = 5609; return HandStrength; }
					if (n4 == 1) { HandStrength = 5608; return HandStrength; }
					if (n3 == 1) { HandStrength = 5607; return HandStrength; }
					if (n2 == 1) { HandStrength = 5606; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5605; return HandStrength; }
					if (n4 == 1) { HandStrength = 5604; return HandStrength; }
					if (n3 == 1) { HandStrength = 5603; return HandStrength; }
					if (n2 == 1) { HandStrength = 5602; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5601; return HandStrength; }
					if (n3 == 1) { HandStrength = 5600; return HandStrength; }
					if (n2 == 1) { HandStrength = 5599; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5598; return HandStrength; }
					if (n2 == 1) { HandStrength = 5597; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5596; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5595; return HandStrength; }
					if (n5 == 1) { HandStrength = 5594; return HandStrength; }
					if (n4 == 1) { HandStrength = 5593; return HandStrength; }
					if (n3 == 1) { HandStrength = 5592; return HandStrength; }
					if (n2 == 1) { HandStrength = 5591; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5590; return HandStrength; }
					if (n4 == 1) { HandStrength = 5589; return HandStrength; }
					if (n3 == 1) { HandStrength = 5588; return HandStrength; }
					if (n2 == 1) { HandStrength = 5587; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5586; return HandStrength; }
					if (n3 == 1) { HandStrength = 5585; return HandStrength; }
					if (n2 == 1) { HandStrength = 5584; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5583; return HandStrength; }
					if (n2 == 1) { HandStrength = 5582; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5581; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5580; return HandStrength; }
					if (n4 == 1) { HandStrength = 5579; return HandStrength; }
					if (n3 == 1) { HandStrength = 5578; return HandStrength; }
					if (n2 == 1) { HandStrength = 5577; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5576; return HandStrength; }
					if (n3 == 1) { HandStrength = 5575; return HandStrength; }
					if (n2 == 1) { HandStrength = 5574; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5573; return HandStrength; }
					if (n2 == 1) { HandStrength = 5572; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5571; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5570; return HandStrength; }
					if (n3 == 1) { HandStrength = 5569; return HandStrength; }
					if (n2 == 1) { HandStrength = 5568; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5567; return HandStrength; }
					if (n2 == 1) { HandStrength = 5566; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5565; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5564; return HandStrength; }
					if (n2 == 1) { HandStrength = 5563; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5562; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5561; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nQ == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nJ == 1) { HandStrength = 5560; return HandStrength; }
					if (nT == 1) { HandStrength = 5559; return HandStrength; }
					if (n9 == 1) { HandStrength = 5558; return HandStrength; }
					if (n8 == 1) { HandStrength = 5557; return HandStrength; }
					if (n7 == 1) { HandStrength = 5556; return HandStrength; }
					if (n6 == 1) { HandStrength = 5555; return HandStrength; }
					if (n5 == 1) { HandStrength = 5554; return HandStrength; }
					if (n4 == 1) { HandStrength = 5553; return HandStrength; }
					if (n3 == 1) { HandStrength = 5552; return HandStrength; }
					if (n2 == 1) { HandStrength = 5551; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5550; return HandStrength; }
					if (n9 == 1) { HandStrength = 5549; return HandStrength; }
					if (n8 == 1) { HandStrength = 5548; return HandStrength; }
					if (n7 == 1) { HandStrength = 5547; return HandStrength; }
					if (n6 == 1) { HandStrength = 5546; return HandStrength; }
					if (n5 == 1) { HandStrength = 5545; return HandStrength; }
					if (n4 == 1) { HandStrength = 5544; return HandStrength; }
					if (n3 == 1) { HandStrength = 5543; return HandStrength; }
					if (n2 == 1) { HandStrength = 5542; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5541; return HandStrength; }
					if (n8 == 1) { HandStrength = 5540; return HandStrength; }
					if (n7 == 1) { HandStrength = 5539; return HandStrength; }
					if (n6 == 1) { HandStrength = 5538; return HandStrength; }
					if (n5 == 1) { HandStrength = 5537; return HandStrength; }
					if (n4 == 1) { HandStrength = 5536; return HandStrength; }
					if (n3 == 1) { HandStrength = 5535; return HandStrength; }
					if (n2 == 1) { HandStrength = 5534; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5533; return HandStrength; }
					if (n7 == 1) { HandStrength = 5532; return HandStrength; }
					if (n6 == 1) { HandStrength = 5531; return HandStrength; }
					if (n5 == 1) { HandStrength = 5530; return HandStrength; }
					if (n4 == 1) { HandStrength = 5529; return HandStrength; }
					if (n3 == 1) { HandStrength = 5528; return HandStrength; }
					if (n2 == 1) { HandStrength = 5527; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5526; return HandStrength; }
					if (n6 == 1) { HandStrength = 5525; return HandStrength; }
					if (n5 == 1) { HandStrength = 5524; return HandStrength; }
					if (n4 == 1) { HandStrength = 5523; return HandStrength; }
					if (n3 == 1) { HandStrength = 5522; return HandStrength; }
					if (n2 == 1) { HandStrength = 5521; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5520; return HandStrength; }
					if (n5 == 1) { HandStrength = 5519; return HandStrength; }
					if (n4 == 1) { HandStrength = 5518; return HandStrength; }
					if (n3 == 1) { HandStrength = 5517; return HandStrength; }
					if (n2 == 1) { HandStrength = 5516; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5515; return HandStrength; }
					if (n4 == 1) { HandStrength = 5514; return HandStrength; }
					if (n3 == 1) { HandStrength = 5513; return HandStrength; }
					if (n2 == 1) { HandStrength = 5512; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5511; return HandStrength; }
					if (n3 == 1) { HandStrength = 5510; return HandStrength; }
					if (n2 == 1) { HandStrength = 5509; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5508; return HandStrength; }
					if (n2 == 1) { HandStrength = 5507; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5506; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 5505; return HandStrength; }
					if (n9 == 1) { HandStrength = 5504; return HandStrength; }
					if (n8 == 1) { HandStrength = 5503; return HandStrength; }
					if (n7 == 1) { HandStrength = 5502; return HandStrength; }
					if (n6 == 1) { HandStrength = 5501; return HandStrength; }
					if (n5 == 1) { HandStrength = 5500; return HandStrength; }
					if (n4 == 1) { HandStrength = 5499; return HandStrength; }
					if (n3 == 1) { HandStrength = 5498; return HandStrength; }
					if (n2 == 1) { HandStrength = 5497; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5496; return HandStrength; }
					if (n8 == 1) { HandStrength = 5495; return HandStrength; }
					if (n7 == 1) { HandStrength = 5494; return HandStrength; }
					if (n6 == 1) { HandStrength = 5493; return HandStrength; }
					if (n5 == 1) { HandStrength = 5492; return HandStrength; }
					if (n4 == 1) { HandStrength = 5491; return HandStrength; }
					if (n3 == 1) { HandStrength = 5490; return HandStrength; }
					if (n2 == 1) { HandStrength = 5489; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5488; return HandStrength; }
					if (n7 == 1) { HandStrength = 5487; return HandStrength; }
					if (n6 == 1) { HandStrength = 5486; return HandStrength; }
					if (n5 == 1) { HandStrength = 5485; return HandStrength; }
					if (n4 == 1) { HandStrength = 5484; return HandStrength; }
					if (n3 == 1) { HandStrength = 5483; return HandStrength; }
					if (n2 == 1) { HandStrength = 5482; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5481; return HandStrength; }
					if (n6 == 1) { HandStrength = 5480; return HandStrength; }
					if (n5 == 1) { HandStrength = 5479; return HandStrength; }
					if (n4 == 1) { HandStrength = 5478; return HandStrength; }
					if (n3 == 1) { HandStrength = 5477; return HandStrength; }
					if (n2 == 1) { HandStrength = 5476; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5475; return HandStrength; }
					if (n5 == 1) { HandStrength = 5474; return HandStrength; }
					if (n4 == 1) { HandStrength = 5473; return HandStrength; }
					if (n3 == 1) { HandStrength = 5472; return HandStrength; }
					if (n2 == 1) { HandStrength = 5471; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5470; return HandStrength; }
					if (n4 == 1) { HandStrength = 5469; return HandStrength; }
					if (n3 == 1) { HandStrength = 5468; return HandStrength; }
					if (n2 == 1) { HandStrength = 5467; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5466; return HandStrength; }
					if (n3 == 1) { HandStrength = 5465; return HandStrength; }
					if (n2 == 1) { HandStrength = 5464; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5463; return HandStrength; }
					if (n2 == 1) { HandStrength = 5462; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5461; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5460; return HandStrength; }
					if (n8 == 1) { HandStrength = 5459; return HandStrength; }
					if (n7 == 1) { HandStrength = 5458; return HandStrength; }
					if (n6 == 1) { HandStrength = 5457; return HandStrength; }
					if (n5 == 1) { HandStrength = 5456; return HandStrength; }
					if (n4 == 1) { HandStrength = 5455; return HandStrength; }
					if (n3 == 1) { HandStrength = 5454; return HandStrength; }
					if (n2 == 1) { HandStrength = 5453; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5452; return HandStrength; }
					if (n7 == 1) { HandStrength = 5451; return HandStrength; }
					if (n6 == 1) { HandStrength = 5450; return HandStrength; }
					if (n5 == 1) { HandStrength = 5449; return HandStrength; }
					if (n4 == 1) { HandStrength = 5448; return HandStrength; }
					if (n3 == 1) { HandStrength = 5447; return HandStrength; }
					if (n2 == 1) { HandStrength = 5446; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5445; return HandStrength; }
					if (n6 == 1) { HandStrength = 5444; return HandStrength; }
					if (n5 == 1) { HandStrength = 5443; return HandStrength; }
					if (n4 == 1) { HandStrength = 5442; return HandStrength; }
					if (n3 == 1) { HandStrength = 5441; return HandStrength; }
					if (n2 == 1) { HandStrength = 5440; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5439; return HandStrength; }
					if (n5 == 1) { HandStrength = 5438; return HandStrength; }
					if (n4 == 1) { HandStrength = 5437; return HandStrength; }
					if (n3 == 1) { HandStrength = 5436; return HandStrength; }
					if (n2 == 1) { HandStrength = 5435; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5434; return HandStrength; }
					if (n4 == 1) { HandStrength = 5433; return HandStrength; }
					if (n3 == 1) { HandStrength = 5432; return HandStrength; }
					if (n2 == 1) { HandStrength = 5431; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5430; return HandStrength; }
					if (n3 == 1) { HandStrength = 5429; return HandStrength; }
					if (n2 == 1) { HandStrength = 5428; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5427; return HandStrength; }
					if (n2 == 1) { HandStrength = 5426; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5425; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5424; return HandStrength; }
					if (n7 == 1) { HandStrength = 5423; return HandStrength; }
					if (n6 == 1) { HandStrength = 5422; return HandStrength; }
					if (n5 == 1) { HandStrength = 5421; return HandStrength; }
					if (n4 == 1) { HandStrength = 5420; return HandStrength; }
					if (n3 == 1) { HandStrength = 5419; return HandStrength; }
					if (n2 == 1) { HandStrength = 5418; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5417; return HandStrength; }
					if (n6 == 1) { HandStrength = 5416; return HandStrength; }
					if (n5 == 1) { HandStrength = 5415; return HandStrength; }
					if (n4 == 1) { HandStrength = 5414; return HandStrength; }
					if (n3 == 1) { HandStrength = 5413; return HandStrength; }
					if (n2 == 1) { HandStrength = 5412; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5411; return HandStrength; }
					if (n5 == 1) { HandStrength = 5410; return HandStrength; }
					if (n4 == 1) { HandStrength = 5409; return HandStrength; }
					if (n3 == 1) { HandStrength = 5408; return HandStrength; }
					if (n2 == 1) { HandStrength = 5407; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5406; return HandStrength; }
					if (n4 == 1) { HandStrength = 5405; return HandStrength; }
					if (n3 == 1) { HandStrength = 5404; return HandStrength; }
					if (n2 == 1) { HandStrength = 5403; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5402; return HandStrength; }
					if (n3 == 1) { HandStrength = 5401; return HandStrength; }
					if (n2 == 1) { HandStrength = 5400; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5399; return HandStrength; }
					if (n2 == 1) { HandStrength = 5398; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5397; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5396; return HandStrength; }
					if (n6 == 1) { HandStrength = 5395; return HandStrength; }
					if (n5 == 1) { HandStrength = 5394; return HandStrength; }
					if (n4 == 1) { HandStrength = 5393; return HandStrength; }
					if (n3 == 1) { HandStrength = 5392; return HandStrength; }
					if (n2 == 1) { HandStrength = 5391; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5390; return HandStrength; }
					if (n5 == 1) { HandStrength = 5389; return HandStrength; }
					if (n4 == 1) { HandStrength = 5388; return HandStrength; }
					if (n3 == 1) { HandStrength = 5387; return HandStrength; }
					if (n2 == 1) { HandStrength = 5386; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5385; return HandStrength; }
					if (n4 == 1) { HandStrength = 5384; return HandStrength; }
					if (n3 == 1) { HandStrength = 5383; return HandStrength; }
					if (n2 == 1) { HandStrength = 5382; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5381; return HandStrength; }
					if (n3 == 1) { HandStrength = 5380; return HandStrength; }
					if (n2 == 1) { HandStrength = 5379; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5378; return HandStrength; }
					if (n2 == 1) { HandStrength = 5377; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5376; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5375; return HandStrength; }
					if (n5 == 1) { HandStrength = 5374; return HandStrength; }
					if (n4 == 1) { HandStrength = 5373; return HandStrength; }
					if (n3 == 1) { HandStrength = 5372; return HandStrength; }
					if (n2 == 1) { HandStrength = 5371; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5370; return HandStrength; }
					if (n4 == 1) { HandStrength = 5369; return HandStrength; }
					if (n3 == 1) { HandStrength = 5368; return HandStrength; }
					if (n2 == 1) { HandStrength = 5367; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5366; return HandStrength; }
					if (n3 == 1) { HandStrength = 5365; return HandStrength; }
					if (n2 == 1) { HandStrength = 5364; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5363; return HandStrength; }
					if (n2 == 1) { HandStrength = 5362; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5361; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5360; return HandStrength; }
					if (n4 == 1) { HandStrength = 5359; return HandStrength; }
					if (n3 == 1) { HandStrength = 5358; return HandStrength; }
					if (n2 == 1) { HandStrength = 5357; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5356; return HandStrength; }
					if (n3 == 1) { HandStrength = 5355; return HandStrength; }
					if (n2 == 1) { HandStrength = 5354; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5353; return HandStrength; }
					if (n2 == 1) { HandStrength = 5352; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5351; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5350; return HandStrength; }
					if (n3 == 1) { HandStrength = 5349; return HandStrength; }
					if (n2 == 1) { HandStrength = 5348; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5347; return HandStrength; }
					if (n2 == 1) { HandStrength = 5346; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5345; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5344; return HandStrength; }
					if (n2 == 1) { HandStrength = 5343; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5342; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5341; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nJ == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 5340; return HandStrength; }
					if (nT == 1) { HandStrength = 5339; return HandStrength; }
					if (n9 == 1) { HandStrength = 5338; return HandStrength; }
					if (n8 == 1) { HandStrength = 5337; return HandStrength; }
					if (n7 == 1) { HandStrength = 5336; return HandStrength; }
					if (n6 == 1) { HandStrength = 5335; return HandStrength; }
					if (n5 == 1) { HandStrength = 5334; return HandStrength; }
					if (n4 == 1) { HandStrength = 5333; return HandStrength; }
					if (n3 == 1) { HandStrength = 5332; return HandStrength; }
					if (n2 == 1) { HandStrength = 5331; return HandStrength; }
				};
				if (nQ == 1) {
					if (nT == 1) { HandStrength = 5330; return HandStrength; }
					if (n9 == 1) { HandStrength = 5329; return HandStrength; }
					if (n8 == 1) { HandStrength = 5328; return HandStrength; }
					if (n7 == 1) { HandStrength = 5327; return HandStrength; }
					if (n6 == 1) { HandStrength = 5326; return HandStrength; }
					if (n5 == 1) { HandStrength = 5325; return HandStrength; }
					if (n4 == 1) { HandStrength = 5324; return HandStrength; }
					if (n3 == 1) { HandStrength = 5323; return HandStrength; }
					if (n2 == 1) { HandStrength = 5322; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5321; return HandStrength; }
					if (n8 == 1) { HandStrength = 5320; return HandStrength; }
					if (n7 == 1) { HandStrength = 5319; return HandStrength; }
					if (n6 == 1) { HandStrength = 5318; return HandStrength; }
					if (n5 == 1) { HandStrength = 5317; return HandStrength; }
					if (n4 == 1) { HandStrength = 5316; return HandStrength; }
					if (n3 == 1) { HandStrength = 5315; return HandStrength; }
					if (n2 == 1) { HandStrength = 5314; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5313; return HandStrength; }
					if (n7 == 1) { HandStrength = 5312; return HandStrength; }
					if (n6 == 1) { HandStrength = 5311; return HandStrength; }
					if (n5 == 1) { HandStrength = 5310; return HandStrength; }
					if (n4 == 1) { HandStrength = 5309; return HandStrength; }
					if (n3 == 1) { HandStrength = 5308; return HandStrength; }
					if (n2 == 1) { HandStrength = 5307; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5306; return HandStrength; }
					if (n6 == 1) { HandStrength = 5305; return HandStrength; }
					if (n5 == 1) { HandStrength = 5304; return HandStrength; }
					if (n4 == 1) { HandStrength = 5303; return HandStrength; }
					if (n3 == 1) { HandStrength = 5302; return HandStrength; }
					if (n2 == 1) { HandStrength = 5301; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5300; return HandStrength; }
					if (n5 == 1) { HandStrength = 5299; return HandStrength; }
					if (n4 == 1) { HandStrength = 5298; return HandStrength; }
					if (n3 == 1) { HandStrength = 5297; return HandStrength; }
					if (n2 == 1) { HandStrength = 5296; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5295; return HandStrength; }
					if (n4 == 1) { HandStrength = 5294; return HandStrength; }
					if (n3 == 1) { HandStrength = 5293; return HandStrength; }
					if (n2 == 1) { HandStrength = 5292; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5291; return HandStrength; }
					if (n3 == 1) { HandStrength = 5290; return HandStrength; }
					if (n2 == 1) { HandStrength = 5289; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5288; return HandStrength; }
					if (n2 == 1) { HandStrength = 5287; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5286; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nT == 1) { HandStrength = 5285; return HandStrength; }
					if (n9 == 1) { HandStrength = 5284; return HandStrength; }
					if (n8 == 1) { HandStrength = 5283; return HandStrength; }
					if (n7 == 1) { HandStrength = 5282; return HandStrength; }
					if (n6 == 1) { HandStrength = 5281; return HandStrength; }
					if (n5 == 1) { HandStrength = 5280; return HandStrength; }
					if (n4 == 1) { HandStrength = 5279; return HandStrength; }
					if (n3 == 1) { HandStrength = 5278; return HandStrength; }
					if (n2 == 1) { HandStrength = 5277; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5276; return HandStrength; }
					if (n8 == 1) { HandStrength = 5275; return HandStrength; }
					if (n7 == 1) { HandStrength = 5274; return HandStrength; }
					if (n6 == 1) { HandStrength = 5273; return HandStrength; }
					if (n5 == 1) { HandStrength = 5272; return HandStrength; }
					if (n4 == 1) { HandStrength = 5271; return HandStrength; }
					if (n3 == 1) { HandStrength = 5270; return HandStrength; }
					if (n2 == 1) { HandStrength = 5269; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5268; return HandStrength; }
					if (n7 == 1) { HandStrength = 5267; return HandStrength; }
					if (n6 == 1) { HandStrength = 5266; return HandStrength; }
					if (n5 == 1) { HandStrength = 5265; return HandStrength; }
					if (n4 == 1) { HandStrength = 5264; return HandStrength; }
					if (n3 == 1) { HandStrength = 5263; return HandStrength; }
					if (n2 == 1) { HandStrength = 5262; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5261; return HandStrength; }
					if (n6 == 1) { HandStrength = 5260; return HandStrength; }
					if (n5 == 1) { HandStrength = 5259; return HandStrength; }
					if (n4 == 1) { HandStrength = 5258; return HandStrength; }
					if (n3 == 1) { HandStrength = 5257; return HandStrength; }
					if (n2 == 1) { HandStrength = 5256; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5255; return HandStrength; }
					if (n5 == 1) { HandStrength = 5254; return HandStrength; }
					if (n4 == 1) { HandStrength = 5253; return HandStrength; }
					if (n3 == 1) { HandStrength = 5252; return HandStrength; }
					if (n2 == 1) { HandStrength = 5251; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5250; return HandStrength; }
					if (n4 == 1) { HandStrength = 5249; return HandStrength; }
					if (n3 == 1) { HandStrength = 5248; return HandStrength; }
					if (n2 == 1) { HandStrength = 5247; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5246; return HandStrength; }
					if (n3 == 1) { HandStrength = 5245; return HandStrength; }
					if (n2 == 1) { HandStrength = 5244; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5243; return HandStrength; }
					if (n2 == 1) { HandStrength = 5242; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5241; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 5240; return HandStrength; }
					if (n8 == 1) { HandStrength = 5239; return HandStrength; }
					if (n7 == 1) { HandStrength = 5238; return HandStrength; }
					if (n6 == 1) { HandStrength = 5237; return HandStrength; }
					if (n5 == 1) { HandStrength = 5236; return HandStrength; }
					if (n4 == 1) { HandStrength = 5235; return HandStrength; }
					if (n3 == 1) { HandStrength = 5234; return HandStrength; }
					if (n2 == 1) { HandStrength = 5233; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5232; return HandStrength; }
					if (n7 == 1) { HandStrength = 5231; return HandStrength; }
					if (n6 == 1) { HandStrength = 5230; return HandStrength; }
					if (n5 == 1) { HandStrength = 5229; return HandStrength; }
					if (n4 == 1) { HandStrength = 5228; return HandStrength; }
					if (n3 == 1) { HandStrength = 5227; return HandStrength; }
					if (n2 == 1) { HandStrength = 5226; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5225; return HandStrength; }
					if (n6 == 1) { HandStrength = 5224; return HandStrength; }
					if (n5 == 1) { HandStrength = 5223; return HandStrength; }
					if (n4 == 1) { HandStrength = 5222; return HandStrength; }
					if (n3 == 1) { HandStrength = 5221; return HandStrength; }
					if (n2 == 1) { HandStrength = 5220; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5219; return HandStrength; }
					if (n5 == 1) { HandStrength = 5218; return HandStrength; }
					if (n4 == 1) { HandStrength = 5217; return HandStrength; }
					if (n3 == 1) { HandStrength = 5216; return HandStrength; }
					if (n2 == 1) { HandStrength = 5215; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5214; return HandStrength; }
					if (n4 == 1) { HandStrength = 5213; return HandStrength; }
					if (n3 == 1) { HandStrength = 5212; return HandStrength; }
					if (n2 == 1) { HandStrength = 5211; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5210; return HandStrength; }
					if (n3 == 1) { HandStrength = 5209; return HandStrength; }
					if (n2 == 1) { HandStrength = 5208; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5207; return HandStrength; }
					if (n2 == 1) { HandStrength = 5206; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5205; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5204; return HandStrength; }
					if (n7 == 1) { HandStrength = 5203; return HandStrength; }
					if (n6 == 1) { HandStrength = 5202; return HandStrength; }
					if (n5 == 1) { HandStrength = 5201; return HandStrength; }
					if (n4 == 1) { HandStrength = 5200; return HandStrength; }
					if (n3 == 1) { HandStrength = 5199; return HandStrength; }
					if (n2 == 1) { HandStrength = 5198; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5197; return HandStrength; }
					if (n6 == 1) { HandStrength = 5196; return HandStrength; }
					if (n5 == 1) { HandStrength = 5195; return HandStrength; }
					if (n4 == 1) { HandStrength = 5194; return HandStrength; }
					if (n3 == 1) { HandStrength = 5193; return HandStrength; }
					if (n2 == 1) { HandStrength = 5192; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5191; return HandStrength; }
					if (n5 == 1) { HandStrength = 5190; return HandStrength; }
					if (n4 == 1) { HandStrength = 5189; return HandStrength; }
					if (n3 == 1) { HandStrength = 5188; return HandStrength; }
					if (n2 == 1) { HandStrength = 5187; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5186; return HandStrength; }
					if (n4 == 1) { HandStrength = 5185; return HandStrength; }
					if (n3 == 1) { HandStrength = 5184; return HandStrength; }
					if (n2 == 1) { HandStrength = 5183; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5182; return HandStrength; }
					if (n3 == 1) { HandStrength = 5181; return HandStrength; }
					if (n2 == 1) { HandStrength = 5180; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5179; return HandStrength; }
					if (n2 == 1) { HandStrength = 5178; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5177; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5176; return HandStrength; }
					if (n6 == 1) { HandStrength = 5175; return HandStrength; }
					if (n5 == 1) { HandStrength = 5174; return HandStrength; }
					if (n4 == 1) { HandStrength = 5173; return HandStrength; }
					if (n3 == 1) { HandStrength = 5172; return HandStrength; }
					if (n2 == 1) { HandStrength = 5171; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5170; return HandStrength; }
					if (n5 == 1) { HandStrength = 5169; return HandStrength; }
					if (n4 == 1) { HandStrength = 5168; return HandStrength; }
					if (n3 == 1) { HandStrength = 5167; return HandStrength; }
					if (n2 == 1) { HandStrength = 5166; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5165; return HandStrength; }
					if (n4 == 1) { HandStrength = 5164; return HandStrength; }
					if (n3 == 1) { HandStrength = 5163; return HandStrength; }
					if (n2 == 1) { HandStrength = 5162; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5161; return HandStrength; }
					if (n3 == 1) { HandStrength = 5160; return HandStrength; }
					if (n2 == 1) { HandStrength = 5159; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5158; return HandStrength; }
					if (n2 == 1) { HandStrength = 5157; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5156; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5155; return HandStrength; }
					if (n5 == 1) { HandStrength = 5154; return HandStrength; }
					if (n4 == 1) { HandStrength = 5153; return HandStrength; }
					if (n3 == 1) { HandStrength = 5152; return HandStrength; }
					if (n2 == 1) { HandStrength = 5151; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5150; return HandStrength; }
					if (n4 == 1) { HandStrength = 5149; return HandStrength; }
					if (n3 == 1) { HandStrength = 5148; return HandStrength; }
					if (n2 == 1) { HandStrength = 5147; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5146; return HandStrength; }
					if (n3 == 1) { HandStrength = 5145; return HandStrength; }
					if (n2 == 1) { HandStrength = 5144; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5143; return HandStrength; }
					if (n2 == 1) { HandStrength = 5142; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5141; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5140; return HandStrength; }
					if (n4 == 1) { HandStrength = 5139; return HandStrength; }
					if (n3 == 1) { HandStrength = 5138; return HandStrength; }
					if (n2 == 1) { HandStrength = 5137; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5136; return HandStrength; }
					if (n3 == 1) { HandStrength = 5135; return HandStrength; }
					if (n2 == 1) { HandStrength = 5134; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5133; return HandStrength; }
					if (n2 == 1) { HandStrength = 5132; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5131; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5130; return HandStrength; }
					if (n3 == 1) { HandStrength = 5129; return HandStrength; }
					if (n2 == 1) { HandStrength = 5128; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5127; return HandStrength; }
					if (n2 == 1) { HandStrength = 5126; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5125; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5124; return HandStrength; }
					if (n2 == 1) { HandStrength = 5123; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5122; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5121; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nT == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 5120; return HandStrength; }
					if (nJ == 1) { HandStrength = 5119; return HandStrength; }
					if (n9 == 1) { HandStrength = 5118; return HandStrength; }
					if (n8 == 1) { HandStrength = 5117; return HandStrength; }
					if (n7 == 1) { HandStrength = 5116; return HandStrength; }
					if (n6 == 1) { HandStrength = 5115; return HandStrength; }
					if (n5 == 1) { HandStrength = 5114; return HandStrength; }
					if (n4 == 1) { HandStrength = 5113; return HandStrength; }
					if (n3 == 1) { HandStrength = 5112; return HandStrength; }
					if (n2 == 1) { HandStrength = 5111; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 5110; return HandStrength; }
					if (n9 == 1) { HandStrength = 5109; return HandStrength; }
					if (n8 == 1) { HandStrength = 5108; return HandStrength; }
					if (n7 == 1) { HandStrength = 5107; return HandStrength; }
					if (n6 == 1) { HandStrength = 5106; return HandStrength; }
					if (n5 == 1) { HandStrength = 5105; return HandStrength; }
					if (n4 == 1) { HandStrength = 5104; return HandStrength; }
					if (n3 == 1) { HandStrength = 5103; return HandStrength; }
					if (n2 == 1) { HandStrength = 5102; return HandStrength; }
				};
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 5101; return HandStrength; }
					if (n8 == 1) { HandStrength = 5100; return HandStrength; }
					if (n7 == 1) { HandStrength = 5099; return HandStrength; }
					if (n6 == 1) { HandStrength = 5098; return HandStrength; }
					if (n5 == 1) { HandStrength = 5097; return HandStrength; }
					if (n4 == 1) { HandStrength = 5096; return HandStrength; }
					if (n3 == 1) { HandStrength = 5095; return HandStrength; }
					if (n2 == 1) { HandStrength = 5094; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5093; return HandStrength; }
					if (n7 == 1) { HandStrength = 5092; return HandStrength; }
					if (n6 == 1) { HandStrength = 5091; return HandStrength; }
					if (n5 == 1) { HandStrength = 5090; return HandStrength; }
					if (n4 == 1) { HandStrength = 5089; return HandStrength; }
					if (n3 == 1) { HandStrength = 5088; return HandStrength; }
					if (n2 == 1) { HandStrength = 5087; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5086; return HandStrength; }
					if (n6 == 1) { HandStrength = 5085; return HandStrength; }
					if (n5 == 1) { HandStrength = 5084; return HandStrength; }
					if (n4 == 1) { HandStrength = 5083; return HandStrength; }
					if (n3 == 1) { HandStrength = 5082; return HandStrength; }
					if (n2 == 1) { HandStrength = 5081; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5080; return HandStrength; }
					if (n5 == 1) { HandStrength = 5079; return HandStrength; }
					if (n4 == 1) { HandStrength = 5078; return HandStrength; }
					if (n3 == 1) { HandStrength = 5077; return HandStrength; }
					if (n2 == 1) { HandStrength = 5076; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5075; return HandStrength; }
					if (n4 == 1) { HandStrength = 5074; return HandStrength; }
					if (n3 == 1) { HandStrength = 5073; return HandStrength; }
					if (n2 == 1) { HandStrength = 5072; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5071; return HandStrength; }
					if (n3 == 1) { HandStrength = 5070; return HandStrength; }
					if (n2 == 1) { HandStrength = 5069; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5068; return HandStrength; }
					if (n2 == 1) { HandStrength = 5067; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5066; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 5065; return HandStrength; }
					if (n9 == 1) { HandStrength = 5064; return HandStrength; }
					if (n8 == 1) { HandStrength = 5063; return HandStrength; }
					if (n7 == 1) { HandStrength = 5062; return HandStrength; }
					if (n6 == 1) { HandStrength = 5061; return HandStrength; }
					if (n5 == 1) { HandStrength = 5060; return HandStrength; }
					if (n4 == 1) { HandStrength = 5059; return HandStrength; }
					if (n3 == 1) { HandStrength = 5058; return HandStrength; }
					if (n2 == 1) { HandStrength = 5057; return HandStrength; }
				};
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 5056; return HandStrength; }
					if (n8 == 1) { HandStrength = 5055; return HandStrength; }
					if (n7 == 1) { HandStrength = 5054; return HandStrength; }
					if (n6 == 1) { HandStrength = 5053; return HandStrength; }
					if (n5 == 1) { HandStrength = 5052; return HandStrength; }
					if (n4 == 1) { HandStrength = 5051; return HandStrength; }
					if (n3 == 1) { HandStrength = 5050; return HandStrength; }
					if (n2 == 1) { HandStrength = 5049; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5048; return HandStrength; }
					if (n7 == 1) { HandStrength = 5047; return HandStrength; }
					if (n6 == 1) { HandStrength = 5046; return HandStrength; }
					if (n5 == 1) { HandStrength = 5045; return HandStrength; }
					if (n4 == 1) { HandStrength = 5044; return HandStrength; }
					if (n3 == 1) { HandStrength = 5043; return HandStrength; }
					if (n2 == 1) { HandStrength = 5042; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5041; return HandStrength; }
					if (n6 == 1) { HandStrength = 5040; return HandStrength; }
					if (n5 == 1) { HandStrength = 5039; return HandStrength; }
					if (n4 == 1) { HandStrength = 5038; return HandStrength; }
					if (n3 == 1) { HandStrength = 5037; return HandStrength; }
					if (n2 == 1) { HandStrength = 5036; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 5035; return HandStrength; }
					if (n5 == 1) { HandStrength = 5034; return HandStrength; }
					if (n4 == 1) { HandStrength = 5033; return HandStrength; }
					if (n3 == 1) { HandStrength = 5032; return HandStrength; }
					if (n2 == 1) { HandStrength = 5031; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 5030; return HandStrength; }
					if (n4 == 1) { HandStrength = 5029; return HandStrength; }
					if (n3 == 1) { HandStrength = 5028; return HandStrength; }
					if (n2 == 1) { HandStrength = 5027; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 5026; return HandStrength; }
					if (n3 == 1) { HandStrength = 5025; return HandStrength; }
					if (n2 == 1) { HandStrength = 5024; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 5023; return HandStrength; }
					if (n2 == 1) { HandStrength = 5022; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 5021; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 5020; return HandStrength; }
					if (n8 == 1) { HandStrength = 5019; return HandStrength; }
					if (n7 == 1) { HandStrength = 5018; return HandStrength; }
					if (n6 == 1) { HandStrength = 5017; return HandStrength; }
					if (n5 == 1) { HandStrength = 5016; return HandStrength; }
					if (n4 == 1) { HandStrength = 5015; return HandStrength; }
					if (n3 == 1) { HandStrength = 5014; return HandStrength; }
					if (n2 == 1) { HandStrength = 5013; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 5012; return HandStrength; }
					if (n7 == 1) { HandStrength = 5011; return HandStrength; }
					if (n6 == 1) { HandStrength = 5010; return HandStrength; }
					if (n5 == 1) { HandStrength = 5009; return HandStrength; }
					if (n4 == 1) { HandStrength = 5008; return HandStrength; }
					if (n3 == 1) { HandStrength = 5007; return HandStrength; }
					if (n2 == 1) { HandStrength = 5006; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 5005; return HandStrength; }
					if (n6 == 1) { HandStrength = 5004; return HandStrength; }
					if (n5 == 1) { HandStrength = 5003; return HandStrength; }
					if (n4 == 1) { HandStrength = 5002; return HandStrength; }
					if (n3 == 1) { HandStrength = 5001; return HandStrength; }
					if (n2 == 1) { HandStrength = 5000; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4999; return HandStrength; }
					if (n5 == 1) { HandStrength = 4998; return HandStrength; }
					if (n4 == 1) { HandStrength = 4997; return HandStrength; }
					if (n3 == 1) { HandStrength = 4996; return HandStrength; }
					if (n2 == 1) { HandStrength = 4995; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4994; return HandStrength; }
					if (n4 == 1) { HandStrength = 4993; return HandStrength; }
					if (n3 == 1) { HandStrength = 4992; return HandStrength; }
					if (n2 == 1) { HandStrength = 4991; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4990; return HandStrength; }
					if (n3 == 1) { HandStrength = 4989; return HandStrength; }
					if (n2 == 1) { HandStrength = 4988; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4987; return HandStrength; }
					if (n2 == 1) { HandStrength = 4986; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4985; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4984; return HandStrength; }
					if (n7 == 1) { HandStrength = 4983; return HandStrength; }
					if (n6 == 1) { HandStrength = 4982; return HandStrength; }
					if (n5 == 1) { HandStrength = 4981; return HandStrength; }
					if (n4 == 1) { HandStrength = 4980; return HandStrength; }
					if (n3 == 1) { HandStrength = 4979; return HandStrength; }
					if (n2 == 1) { HandStrength = 4978; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4977; return HandStrength; }
					if (n6 == 1) { HandStrength = 4976; return HandStrength; }
					if (n5 == 1) { HandStrength = 4975; return HandStrength; }
					if (n4 == 1) { HandStrength = 4974; return HandStrength; }
					if (n3 == 1) { HandStrength = 4973; return HandStrength; }
					if (n2 == 1) { HandStrength = 4972; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4971; return HandStrength; }
					if (n5 == 1) { HandStrength = 4970; return HandStrength; }
					if (n4 == 1) { HandStrength = 4969; return HandStrength; }
					if (n3 == 1) { HandStrength = 4968; return HandStrength; }
					if (n2 == 1) { HandStrength = 4967; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4966; return HandStrength; }
					if (n4 == 1) { HandStrength = 4965; return HandStrength; }
					if (n3 == 1) { HandStrength = 4964; return HandStrength; }
					if (n2 == 1) { HandStrength = 4963; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4962; return HandStrength; }
					if (n3 == 1) { HandStrength = 4961; return HandStrength; }
					if (n2 == 1) { HandStrength = 4960; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4959; return HandStrength; }
					if (n2 == 1) { HandStrength = 4958; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4957; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4956; return HandStrength; }
					if (n6 == 1) { HandStrength = 4955; return HandStrength; }
					if (n5 == 1) { HandStrength = 4954; return HandStrength; }
					if (n4 == 1) { HandStrength = 4953; return HandStrength; }
					if (n3 == 1) { HandStrength = 4952; return HandStrength; }
					if (n2 == 1) { HandStrength = 4951; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4950; return HandStrength; }
					if (n5 == 1) { HandStrength = 4949; return HandStrength; }
					if (n4 == 1) { HandStrength = 4948; return HandStrength; }
					if (n3 == 1) { HandStrength = 4947; return HandStrength; }
					if (n2 == 1) { HandStrength = 4946; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4945; return HandStrength; }
					if (n4 == 1) { HandStrength = 4944; return HandStrength; }
					if (n3 == 1) { HandStrength = 4943; return HandStrength; }
					if (n2 == 1) { HandStrength = 4942; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4941; return HandStrength; }
					if (n3 == 1) { HandStrength = 4940; return HandStrength; }
					if (n2 == 1) { HandStrength = 4939; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4938; return HandStrength; }
					if (n2 == 1) { HandStrength = 4937; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4936; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4935; return HandStrength; }
					if (n5 == 1) { HandStrength = 4934; return HandStrength; }
					if (n4 == 1) { HandStrength = 4933; return HandStrength; }
					if (n3 == 1) { HandStrength = 4932; return HandStrength; }
					if (n2 == 1) { HandStrength = 4931; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4930; return HandStrength; }
					if (n4 == 1) { HandStrength = 4929; return HandStrength; }
					if (n3 == 1) { HandStrength = 4928; return HandStrength; }
					if (n2 == 1) { HandStrength = 4927; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4926; return HandStrength; }
					if (n3 == 1) { HandStrength = 4925; return HandStrength; }
					if (n2 == 1) { HandStrength = 4924; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4923; return HandStrength; }
					if (n2 == 1) { HandStrength = 4922; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4921; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4920; return HandStrength; }
					if (n4 == 1) { HandStrength = 4919; return HandStrength; }
					if (n3 == 1) { HandStrength = 4918; return HandStrength; }
					if (n2 == 1) { HandStrength = 4917; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4916; return HandStrength; }
					if (n3 == 1) { HandStrength = 4915; return HandStrength; }
					if (n2 == 1) { HandStrength = 4914; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4913; return HandStrength; }
					if (n2 == 1) { HandStrength = 4912; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4911; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4910; return HandStrength; }
					if (n3 == 1) { HandStrength = 4909; return HandStrength; }
					if (n2 == 1) { HandStrength = 4908; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4907; return HandStrength; }
					if (n2 == 1) { HandStrength = 4906; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4905; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4904; return HandStrength; }
					if (n2 == 1) { HandStrength = 4903; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4902; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4901; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 4900; return HandStrength; }
					if (nJ == 1) { HandStrength = 4899; return HandStrength; }
					if (nT == 1) { HandStrength = 4898; return HandStrength; }
					if (n8 == 1) { HandStrength = 4897; return HandStrength; }
					if (n7 == 1) { HandStrength = 4896; return HandStrength; }
					if (n6 == 1) { HandStrength = 4895; return HandStrength; }
					if (n5 == 1) { HandStrength = 4894; return HandStrength; }
					if (n4 == 1) { HandStrength = 4893; return HandStrength; }
					if (n3 == 1) { HandStrength = 4892; return HandStrength; }
					if (n2 == 1) { HandStrength = 4891; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4890; return HandStrength; }
					if (nT == 1) { HandStrength = 4889; return HandStrength; }
					if (n8 == 1) { HandStrength = 4888; return HandStrength; }
					if (n7 == 1) { HandStrength = 4887; return HandStrength; }
					if (n6 == 1) { HandStrength = 4886; return HandStrength; }
					if (n5 == 1) { HandStrength = 4885; return HandStrength; }
					if (n4 == 1) { HandStrength = 4884; return HandStrength; }
					if (n3 == 1) { HandStrength = 4883; return HandStrength; }
					if (n2 == 1) { HandStrength = 4882; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4881; return HandStrength; }
					if (n8 == 1) { HandStrength = 4880; return HandStrength; }
					if (n7 == 1) { HandStrength = 4879; return HandStrength; }
					if (n6 == 1) { HandStrength = 4878; return HandStrength; }
					if (n5 == 1) { HandStrength = 4877; return HandStrength; }
					if (n4 == 1) { HandStrength = 4876; return HandStrength; }
					if (n3 == 1) { HandStrength = 4875; return HandStrength; }
					if (n2 == 1) { HandStrength = 4874; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 4873; return HandStrength; }
					if (n7 == 1) { HandStrength = 4872; return HandStrength; }
					if (n6 == 1) { HandStrength = 4871; return HandStrength; }
					if (n5 == 1) { HandStrength = 4870; return HandStrength; }
					if (n4 == 1) { HandStrength = 4869; return HandStrength; }
					if (n3 == 1) { HandStrength = 4868; return HandStrength; }
					if (n2 == 1) { HandStrength = 4867; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4866; return HandStrength; }
					if (n6 == 1) { HandStrength = 4865; return HandStrength; }
					if (n5 == 1) { HandStrength = 4864; return HandStrength; }
					if (n4 == 1) { HandStrength = 4863; return HandStrength; }
					if (n3 == 1) { HandStrength = 4862; return HandStrength; }
					if (n2 == 1) { HandStrength = 4861; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4860; return HandStrength; }
					if (n5 == 1) { HandStrength = 4859; return HandStrength; }
					if (n4 == 1) { HandStrength = 4858; return HandStrength; }
					if (n3 == 1) { HandStrength = 4857; return HandStrength; }
					if (n2 == 1) { HandStrength = 4856; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4855; return HandStrength; }
					if (n4 == 1) { HandStrength = 4854; return HandStrength; }
					if (n3 == 1) { HandStrength = 4853; return HandStrength; }
					if (n2 == 1) { HandStrength = 4852; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4851; return HandStrength; }
					if (n3 == 1) { HandStrength = 4850; return HandStrength; }
					if (n2 == 1) { HandStrength = 4849; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4848; return HandStrength; }
					if (n2 == 1) { HandStrength = 4847; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4846; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4845; return HandStrength; }
					if (nT == 1) { HandStrength = 4844; return HandStrength; }
					if (n8 == 1) { HandStrength = 4843; return HandStrength; }
					if (n7 == 1) { HandStrength = 4842; return HandStrength; }
					if (n6 == 1) { HandStrength = 4841; return HandStrength; }
					if (n5 == 1) { HandStrength = 4840; return HandStrength; }
					if (n4 == 1) { HandStrength = 4839; return HandStrength; }
					if (n3 == 1) { HandStrength = 4838; return HandStrength; }
					if (n2 == 1) { HandStrength = 4837; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4836; return HandStrength; }
					if (n8 == 1) { HandStrength = 4835; return HandStrength; }
					if (n7 == 1) { HandStrength = 4834; return HandStrength; }
					if (n6 == 1) { HandStrength = 4833; return HandStrength; }
					if (n5 == 1) { HandStrength = 4832; return HandStrength; }
					if (n4 == 1) { HandStrength = 4831; return HandStrength; }
					if (n3 == 1) { HandStrength = 4830; return HandStrength; }
					if (n2 == 1) { HandStrength = 4829; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 4828; return HandStrength; }
					if (n7 == 1) { HandStrength = 4827; return HandStrength; }
					if (n6 == 1) { HandStrength = 4826; return HandStrength; }
					if (n5 == 1) { HandStrength = 4825; return HandStrength; }
					if (n4 == 1) { HandStrength = 4824; return HandStrength; }
					if (n3 == 1) { HandStrength = 4823; return HandStrength; }
					if (n2 == 1) { HandStrength = 4822; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4821; return HandStrength; }
					if (n6 == 1) { HandStrength = 4820; return HandStrength; }
					if (n5 == 1) { HandStrength = 4819; return HandStrength; }
					if (n4 == 1) { HandStrength = 4818; return HandStrength; }
					if (n3 == 1) { HandStrength = 4817; return HandStrength; }
					if (n2 == 1) { HandStrength = 4816; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4815; return HandStrength; }
					if (n5 == 1) { HandStrength = 4814; return HandStrength; }
					if (n4 == 1) { HandStrength = 4813; return HandStrength; }
					if (n3 == 1) { HandStrength = 4812; return HandStrength; }
					if (n2 == 1) { HandStrength = 4811; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4810; return HandStrength; }
					if (n4 == 1) { HandStrength = 4809; return HandStrength; }
					if (n3 == 1) { HandStrength = 4808; return HandStrength; }
					if (n2 == 1) { HandStrength = 4807; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4806; return HandStrength; }
					if (n3 == 1) { HandStrength = 4805; return HandStrength; }
					if (n2 == 1) { HandStrength = 4804; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4803; return HandStrength; }
					if (n2 == 1) { HandStrength = 4802; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4801; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4800; return HandStrength; }
					if (n8 == 1) { HandStrength = 4799; return HandStrength; }
					if (n7 == 1) { HandStrength = 4798; return HandStrength; }
					if (n6 == 1) { HandStrength = 4797; return HandStrength; }
					if (n5 == 1) { HandStrength = 4796; return HandStrength; }
					if (n4 == 1) { HandStrength = 4795; return HandStrength; }
					if (n3 == 1) { HandStrength = 4794; return HandStrength; }
					if (n2 == 1) { HandStrength = 4793; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 4792; return HandStrength; }
					if (n7 == 1) { HandStrength = 4791; return HandStrength; }
					if (n6 == 1) { HandStrength = 4790; return HandStrength; }
					if (n5 == 1) { HandStrength = 4789; return HandStrength; }
					if (n4 == 1) { HandStrength = 4788; return HandStrength; }
					if (n3 == 1) { HandStrength = 4787; return HandStrength; }
					if (n2 == 1) { HandStrength = 4786; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4785; return HandStrength; }
					if (n6 == 1) { HandStrength = 4784; return HandStrength; }
					if (n5 == 1) { HandStrength = 4783; return HandStrength; }
					if (n4 == 1) { HandStrength = 4782; return HandStrength; }
					if (n3 == 1) { HandStrength = 4781; return HandStrength; }
					if (n2 == 1) { HandStrength = 4780; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4779; return HandStrength; }
					if (n5 == 1) { HandStrength = 4778; return HandStrength; }
					if (n4 == 1) { HandStrength = 4777; return HandStrength; }
					if (n3 == 1) { HandStrength = 4776; return HandStrength; }
					if (n2 == 1) { HandStrength = 4775; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4774; return HandStrength; }
					if (n4 == 1) { HandStrength = 4773; return HandStrength; }
					if (n3 == 1) { HandStrength = 4772; return HandStrength; }
					if (n2 == 1) { HandStrength = 4771; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4770; return HandStrength; }
					if (n3 == 1) { HandStrength = 4769; return HandStrength; }
					if (n2 == 1) { HandStrength = 4768; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4767; return HandStrength; }
					if (n2 == 1) { HandStrength = 4766; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4765; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 4764; return HandStrength; }
					if (n7 == 1) { HandStrength = 4763; return HandStrength; }
					if (n6 == 1) { HandStrength = 4762; return HandStrength; }
					if (n5 == 1) { HandStrength = 4761; return HandStrength; }
					if (n4 == 1) { HandStrength = 4760; return HandStrength; }
					if (n3 == 1) { HandStrength = 4759; return HandStrength; }
					if (n2 == 1) { HandStrength = 4758; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4757; return HandStrength; }
					if (n6 == 1) { HandStrength = 4756; return HandStrength; }
					if (n5 == 1) { HandStrength = 4755; return HandStrength; }
					if (n4 == 1) { HandStrength = 4754; return HandStrength; }
					if (n3 == 1) { HandStrength = 4753; return HandStrength; }
					if (n2 == 1) { HandStrength = 4752; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4751; return HandStrength; }
					if (n5 == 1) { HandStrength = 4750; return HandStrength; }
					if (n4 == 1) { HandStrength = 4749; return HandStrength; }
					if (n3 == 1) { HandStrength = 4748; return HandStrength; }
					if (n2 == 1) { HandStrength = 4747; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4746; return HandStrength; }
					if (n4 == 1) { HandStrength = 4745; return HandStrength; }
					if (n3 == 1) { HandStrength = 4744; return HandStrength; }
					if (n2 == 1) { HandStrength = 4743; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4742; return HandStrength; }
					if (n3 == 1) { HandStrength = 4741; return HandStrength; }
					if (n2 == 1) { HandStrength = 4740; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4739; return HandStrength; }
					if (n2 == 1) { HandStrength = 4738; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4737; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4736; return HandStrength; }
					if (n6 == 1) { HandStrength = 4735; return HandStrength; }
					if (n5 == 1) { HandStrength = 4734; return HandStrength; }
					if (n4 == 1) { HandStrength = 4733; return HandStrength; }
					if (n3 == 1) { HandStrength = 4732; return HandStrength; }
					if (n2 == 1) { HandStrength = 4731; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4730; return HandStrength; }
					if (n5 == 1) { HandStrength = 4729; return HandStrength; }
					if (n4 == 1) { HandStrength = 4728; return HandStrength; }
					if (n3 == 1) { HandStrength = 4727; return HandStrength; }
					if (n2 == 1) { HandStrength = 4726; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4725; return HandStrength; }
					if (n4 == 1) { HandStrength = 4724; return HandStrength; }
					if (n3 == 1) { HandStrength = 4723; return HandStrength; }
					if (n2 == 1) { HandStrength = 4722; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4721; return HandStrength; }
					if (n3 == 1) { HandStrength = 4720; return HandStrength; }
					if (n2 == 1) { HandStrength = 4719; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4718; return HandStrength; }
					if (n2 == 1) { HandStrength = 4717; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4716; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4715; return HandStrength; }
					if (n5 == 1) { HandStrength = 4714; return HandStrength; }
					if (n4 == 1) { HandStrength = 4713; return HandStrength; }
					if (n3 == 1) { HandStrength = 4712; return HandStrength; }
					if (n2 == 1) { HandStrength = 4711; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4710; return HandStrength; }
					if (n4 == 1) { HandStrength = 4709; return HandStrength; }
					if (n3 == 1) { HandStrength = 4708; return HandStrength; }
					if (n2 == 1) { HandStrength = 4707; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4706; return HandStrength; }
					if (n3 == 1) { HandStrength = 4705; return HandStrength; }
					if (n2 == 1) { HandStrength = 4704; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4703; return HandStrength; }
					if (n2 == 1) { HandStrength = 4702; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4701; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4700; return HandStrength; }
					if (n4 == 1) { HandStrength = 4699; return HandStrength; }
					if (n3 == 1) { HandStrength = 4698; return HandStrength; }
					if (n2 == 1) { HandStrength = 4697; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4696; return HandStrength; }
					if (n3 == 1) { HandStrength = 4695; return HandStrength; }
					if (n2 == 1) { HandStrength = 4694; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4693; return HandStrength; }
					if (n2 == 1) { HandStrength = 4692; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4691; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4690; return HandStrength; }
					if (n3 == 1) { HandStrength = 4689; return HandStrength; }
					if (n2 == 1) { HandStrength = 4688; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4687; return HandStrength; }
					if (n2 == 1) { HandStrength = 4686; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4685; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4684; return HandStrength; }
					if (n2 == 1) { HandStrength = 4683; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4682; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4681; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 4680; return HandStrength; }
					if (nJ == 1) { HandStrength = 4679; return HandStrength; }
					if (nT == 1) { HandStrength = 4678; return HandStrength; }
					if (n9 == 1) { HandStrength = 4677; return HandStrength; }
					if (n7 == 1) { HandStrength = 4676; return HandStrength; }
					if (n6 == 1) { HandStrength = 4675; return HandStrength; }
					if (n5 == 1) { HandStrength = 4674; return HandStrength; }
					if (n4 == 1) { HandStrength = 4673; return HandStrength; }
					if (n3 == 1) { HandStrength = 4672; return HandStrength; }
					if (n2 == 1) { HandStrength = 4671; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4670; return HandStrength; }
					if (nT == 1) { HandStrength = 4669; return HandStrength; }
					if (n9 == 1) { HandStrength = 4668; return HandStrength; }
					if (n7 == 1) { HandStrength = 4667; return HandStrength; }
					if (n6 == 1) { HandStrength = 4666; return HandStrength; }
					if (n5 == 1) { HandStrength = 4665; return HandStrength; }
					if (n4 == 1) { HandStrength = 4664; return HandStrength; }
					if (n3 == 1) { HandStrength = 4663; return HandStrength; }
					if (n2 == 1) { HandStrength = 4662; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4661; return HandStrength; }
					if (n9 == 1) { HandStrength = 4660; return HandStrength; }
					if (n7 == 1) { HandStrength = 4659; return HandStrength; }
					if (n6 == 1) { HandStrength = 4658; return HandStrength; }
					if (n5 == 1) { HandStrength = 4657; return HandStrength; }
					if (n4 == 1) { HandStrength = 4656; return HandStrength; }
					if (n3 == 1) { HandStrength = 4655; return HandStrength; }
					if (n2 == 1) { HandStrength = 4654; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4653; return HandStrength; }
					if (n7 == 1) { HandStrength = 4652; return HandStrength; }
					if (n6 == 1) { HandStrength = 4651; return HandStrength; }
					if (n5 == 1) { HandStrength = 4650; return HandStrength; }
					if (n4 == 1) { HandStrength = 4649; return HandStrength; }
					if (n3 == 1) { HandStrength = 4648; return HandStrength; }
					if (n2 == 1) { HandStrength = 4647; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 4646; return HandStrength; }
					if (n6 == 1) { HandStrength = 4645; return HandStrength; }
					if (n5 == 1) { HandStrength = 4644; return HandStrength; }
					if (n4 == 1) { HandStrength = 4643; return HandStrength; }
					if (n3 == 1) { HandStrength = 4642; return HandStrength; }
					if (n2 == 1) { HandStrength = 4641; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4640; return HandStrength; }
					if (n5 == 1) { HandStrength = 4639; return HandStrength; }
					if (n4 == 1) { HandStrength = 4638; return HandStrength; }
					if (n3 == 1) { HandStrength = 4637; return HandStrength; }
					if (n2 == 1) { HandStrength = 4636; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4635; return HandStrength; }
					if (n4 == 1) { HandStrength = 4634; return HandStrength; }
					if (n3 == 1) { HandStrength = 4633; return HandStrength; }
					if (n2 == 1) { HandStrength = 4632; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4631; return HandStrength; }
					if (n3 == 1) { HandStrength = 4630; return HandStrength; }
					if (n2 == 1) { HandStrength = 4629; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4628; return HandStrength; }
					if (n2 == 1) { HandStrength = 4627; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4626; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4625; return HandStrength; }
					if (nT == 1) { HandStrength = 4624; return HandStrength; }
					if (n9 == 1) { HandStrength = 4623; return HandStrength; }
					if (n7 == 1) { HandStrength = 4622; return HandStrength; }
					if (n6 == 1) { HandStrength = 4621; return HandStrength; }
					if (n5 == 1) { HandStrength = 4620; return HandStrength; }
					if (n4 == 1) { HandStrength = 4619; return HandStrength; }
					if (n3 == 1) { HandStrength = 4618; return HandStrength; }
					if (n2 == 1) { HandStrength = 4617; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4616; return HandStrength; }
					if (n9 == 1) { HandStrength = 4615; return HandStrength; }
					if (n7 == 1) { HandStrength = 4614; return HandStrength; }
					if (n6 == 1) { HandStrength = 4613; return HandStrength; }
					if (n5 == 1) { HandStrength = 4612; return HandStrength; }
					if (n4 == 1) { HandStrength = 4611; return HandStrength; }
					if (n3 == 1) { HandStrength = 4610; return HandStrength; }
					if (n2 == 1) { HandStrength = 4609; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4608; return HandStrength; }
					if (n7 == 1) { HandStrength = 4607; return HandStrength; }
					if (n6 == 1) { HandStrength = 4606; return HandStrength; }
					if (n5 == 1) { HandStrength = 4605; return HandStrength; }
					if (n4 == 1) { HandStrength = 4604; return HandStrength; }
					if (n3 == 1) { HandStrength = 4603; return HandStrength; }
					if (n2 == 1) { HandStrength = 4602; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 4601; return HandStrength; }
					if (n6 == 1) { HandStrength = 4600; return HandStrength; }
					if (n5 == 1) { HandStrength = 4599; return HandStrength; }
					if (n4 == 1) { HandStrength = 4598; return HandStrength; }
					if (n3 == 1) { HandStrength = 4597; return HandStrength; }
					if (n2 == 1) { HandStrength = 4596; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4595; return HandStrength; }
					if (n5 == 1) { HandStrength = 4594; return HandStrength; }
					if (n4 == 1) { HandStrength = 4593; return HandStrength; }
					if (n3 == 1) { HandStrength = 4592; return HandStrength; }
					if (n2 == 1) { HandStrength = 4591; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4590; return HandStrength; }
					if (n4 == 1) { HandStrength = 4589; return HandStrength; }
					if (n3 == 1) { HandStrength = 4588; return HandStrength; }
					if (n2 == 1) { HandStrength = 4587; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4586; return HandStrength; }
					if (n3 == 1) { HandStrength = 4585; return HandStrength; }
					if (n2 == 1) { HandStrength = 4584; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4583; return HandStrength; }
					if (n2 == 1) { HandStrength = 4582; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4581; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4580; return HandStrength; }
					if (n9 == 1) { HandStrength = 4579; return HandStrength; }
					if (n7 == 1) { HandStrength = 4578; return HandStrength; }
					if (n6 == 1) { HandStrength = 4577; return HandStrength; }
					if (n5 == 1) { HandStrength = 4576; return HandStrength; }
					if (n4 == 1) { HandStrength = 4575; return HandStrength; }
					if (n3 == 1) { HandStrength = 4574; return HandStrength; }
					if (n2 == 1) { HandStrength = 4573; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4572; return HandStrength; }
					if (n7 == 1) { HandStrength = 4571; return HandStrength; }
					if (n6 == 1) { HandStrength = 4570; return HandStrength; }
					if (n5 == 1) { HandStrength = 4569; return HandStrength; }
					if (n4 == 1) { HandStrength = 4568; return HandStrength; }
					if (n3 == 1) { HandStrength = 4567; return HandStrength; }
					if (n2 == 1) { HandStrength = 4566; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 4565; return HandStrength; }
					if (n6 == 1) { HandStrength = 4564; return HandStrength; }
					if (n5 == 1) { HandStrength = 4563; return HandStrength; }
					if (n4 == 1) { HandStrength = 4562; return HandStrength; }
					if (n3 == 1) { HandStrength = 4561; return HandStrength; }
					if (n2 == 1) { HandStrength = 4560; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4559; return HandStrength; }
					if (n5 == 1) { HandStrength = 4558; return HandStrength; }
					if (n4 == 1) { HandStrength = 4557; return HandStrength; }
					if (n3 == 1) { HandStrength = 4556; return HandStrength; }
					if (n2 == 1) { HandStrength = 4555; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4554; return HandStrength; }
					if (n4 == 1) { HandStrength = 4553; return HandStrength; }
					if (n3 == 1) { HandStrength = 4552; return HandStrength; }
					if (n2 == 1) { HandStrength = 4551; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4550; return HandStrength; }
					if (n3 == 1) { HandStrength = 4549; return HandStrength; }
					if (n2 == 1) { HandStrength = 4548; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4547; return HandStrength; }
					if (n2 == 1) { HandStrength = 4546; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4545; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4544; return HandStrength; }
					if (n7 == 1) { HandStrength = 4543; return HandStrength; }
					if (n6 == 1) { HandStrength = 4542; return HandStrength; }
					if (n5 == 1) { HandStrength = 4541; return HandStrength; }
					if (n4 == 1) { HandStrength = 4540; return HandStrength; }
					if (n3 == 1) { HandStrength = 4539; return HandStrength; }
					if (n2 == 1) { HandStrength = 4538; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 4537; return HandStrength; }
					if (n6 == 1) { HandStrength = 4536; return HandStrength; }
					if (n5 == 1) { HandStrength = 4535; return HandStrength; }
					if (n4 == 1) { HandStrength = 4534; return HandStrength; }
					if (n3 == 1) { HandStrength = 4533; return HandStrength; }
					if (n2 == 1) { HandStrength = 4532; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4531; return HandStrength; }
					if (n5 == 1) { HandStrength = 4530; return HandStrength; }
					if (n4 == 1) { HandStrength = 4529; return HandStrength; }
					if (n3 == 1) { HandStrength = 4528; return HandStrength; }
					if (n2 == 1) { HandStrength = 4527; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4526; return HandStrength; }
					if (n4 == 1) { HandStrength = 4525; return HandStrength; }
					if (n3 == 1) { HandStrength = 4524; return HandStrength; }
					if (n2 == 1) { HandStrength = 4523; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4522; return HandStrength; }
					if (n3 == 1) { HandStrength = 4521; return HandStrength; }
					if (n2 == 1) { HandStrength = 4520; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4519; return HandStrength; }
					if (n2 == 1) { HandStrength = 4518; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4517; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 4516; return HandStrength; }
					if (n6 == 1) { HandStrength = 4515; return HandStrength; }
					if (n5 == 1) { HandStrength = 4514; return HandStrength; }
					if (n4 == 1) { HandStrength = 4513; return HandStrength; }
					if (n3 == 1) { HandStrength = 4512; return HandStrength; }
					if (n2 == 1) { HandStrength = 4511; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4510; return HandStrength; }
					if (n5 == 1) { HandStrength = 4509; return HandStrength; }
					if (n4 == 1) { HandStrength = 4508; return HandStrength; }
					if (n3 == 1) { HandStrength = 4507; return HandStrength; }
					if (n2 == 1) { HandStrength = 4506; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4505; return HandStrength; }
					if (n4 == 1) { HandStrength = 4504; return HandStrength; }
					if (n3 == 1) { HandStrength = 4503; return HandStrength; }
					if (n2 == 1) { HandStrength = 4502; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4501; return HandStrength; }
					if (n3 == 1) { HandStrength = 4500; return HandStrength; }
					if (n2 == 1) { HandStrength = 4499; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4498; return HandStrength; }
					if (n2 == 1) { HandStrength = 4497; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4496; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 4495; return HandStrength; }
					if (n5 == 1) { HandStrength = 4494; return HandStrength; }
					if (n4 == 1) { HandStrength = 4493; return HandStrength; }
					if (n3 == 1) { HandStrength = 4492; return HandStrength; }
					if (n2 == 1) { HandStrength = 4491; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4490; return HandStrength; }
					if (n4 == 1) { HandStrength = 4489; return HandStrength; }
					if (n3 == 1) { HandStrength = 4488; return HandStrength; }
					if (n2 == 1) { HandStrength = 4487; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4486; return HandStrength; }
					if (n3 == 1) { HandStrength = 4485; return HandStrength; }
					if (n2 == 1) { HandStrength = 4484; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4483; return HandStrength; }
					if (n2 == 1) { HandStrength = 4482; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4481; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4480; return HandStrength; }
					if (n4 == 1) { HandStrength = 4479; return HandStrength; }
					if (n3 == 1) { HandStrength = 4478; return HandStrength; }
					if (n2 == 1) { HandStrength = 4477; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4476; return HandStrength; }
					if (n3 == 1) { HandStrength = 4475; return HandStrength; }
					if (n2 == 1) { HandStrength = 4474; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4473; return HandStrength; }
					if (n2 == 1) { HandStrength = 4472; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4471; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4470; return HandStrength; }
					if (n3 == 1) { HandStrength = 4469; return HandStrength; }
					if (n2 == 1) { HandStrength = 4468; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4467; return HandStrength; }
					if (n2 == 1) { HandStrength = 4466; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4465; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4464; return HandStrength; }
					if (n2 == 1) { HandStrength = 4463; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4462; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4461; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 4460; return HandStrength; }
					if (nJ == 1) { HandStrength = 4459; return HandStrength; }
					if (nT == 1) { HandStrength = 4458; return HandStrength; }
					if (n9 == 1) { HandStrength = 4457; return HandStrength; }
					if (n8 == 1) { HandStrength = 4456; return HandStrength; }
					if (n6 == 1) { HandStrength = 4455; return HandStrength; }
					if (n5 == 1) { HandStrength = 4454; return HandStrength; }
					if (n4 == 1) { HandStrength = 4453; return HandStrength; }
					if (n3 == 1) { HandStrength = 4452; return HandStrength; }
					if (n2 == 1) { HandStrength = 4451; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4450; return HandStrength; }
					if (nT == 1) { HandStrength = 4449; return HandStrength; }
					if (n9 == 1) { HandStrength = 4448; return HandStrength; }
					if (n8 == 1) { HandStrength = 4447; return HandStrength; }
					if (n6 == 1) { HandStrength = 4446; return HandStrength; }
					if (n5 == 1) { HandStrength = 4445; return HandStrength; }
					if (n4 == 1) { HandStrength = 4444; return HandStrength; }
					if (n3 == 1) { HandStrength = 4443; return HandStrength; }
					if (n2 == 1) { HandStrength = 4442; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4441; return HandStrength; }
					if (n9 == 1) { HandStrength = 4440; return HandStrength; }
					if (n8 == 1) { HandStrength = 4439; return HandStrength; }
					if (n6 == 1) { HandStrength = 4438; return HandStrength; }
					if (n5 == 1) { HandStrength = 4437; return HandStrength; }
					if (n4 == 1) { HandStrength = 4436; return HandStrength; }
					if (n3 == 1) { HandStrength = 4435; return HandStrength; }
					if (n2 == 1) { HandStrength = 4434; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4433; return HandStrength; }
					if (n8 == 1) { HandStrength = 4432; return HandStrength; }
					if (n6 == 1) { HandStrength = 4431; return HandStrength; }
					if (n5 == 1) { HandStrength = 4430; return HandStrength; }
					if (n4 == 1) { HandStrength = 4429; return HandStrength; }
					if (n3 == 1) { HandStrength = 4428; return HandStrength; }
					if (n2 == 1) { HandStrength = 4427; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4426; return HandStrength; }
					if (n6 == 1) { HandStrength = 4425; return HandStrength; }
					if (n5 == 1) { HandStrength = 4424; return HandStrength; }
					if (n4 == 1) { HandStrength = 4423; return HandStrength; }
					if (n3 == 1) { HandStrength = 4422; return HandStrength; }
					if (n2 == 1) { HandStrength = 4421; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4420; return HandStrength; }
					if (n5 == 1) { HandStrength = 4419; return HandStrength; }
					if (n4 == 1) { HandStrength = 4418; return HandStrength; }
					if (n3 == 1) { HandStrength = 4417; return HandStrength; }
					if (n2 == 1) { HandStrength = 4416; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4415; return HandStrength; }
					if (n4 == 1) { HandStrength = 4414; return HandStrength; }
					if (n3 == 1) { HandStrength = 4413; return HandStrength; }
					if (n2 == 1) { HandStrength = 4412; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4411; return HandStrength; }
					if (n3 == 1) { HandStrength = 4410; return HandStrength; }
					if (n2 == 1) { HandStrength = 4409; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4408; return HandStrength; }
					if (n2 == 1) { HandStrength = 4407; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4406; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4405; return HandStrength; }
					if (nT == 1) { HandStrength = 4404; return HandStrength; }
					if (n9 == 1) { HandStrength = 4403; return HandStrength; }
					if (n8 == 1) { HandStrength = 4402; return HandStrength; }
					if (n6 == 1) { HandStrength = 4401; return HandStrength; }
					if (n5 == 1) { HandStrength = 4400; return HandStrength; }
					if (n4 == 1) { HandStrength = 4399; return HandStrength; }
					if (n3 == 1) { HandStrength = 4398; return HandStrength; }
					if (n2 == 1) { HandStrength = 4397; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4396; return HandStrength; }
					if (n9 == 1) { HandStrength = 4395; return HandStrength; }
					if (n8 == 1) { HandStrength = 4394; return HandStrength; }
					if (n6 == 1) { HandStrength = 4393; return HandStrength; }
					if (n5 == 1) { HandStrength = 4392; return HandStrength; }
					if (n4 == 1) { HandStrength = 4391; return HandStrength; }
					if (n3 == 1) { HandStrength = 4390; return HandStrength; }
					if (n2 == 1) { HandStrength = 4389; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4388; return HandStrength; }
					if (n8 == 1) { HandStrength = 4387; return HandStrength; }
					if (n6 == 1) { HandStrength = 4386; return HandStrength; }
					if (n5 == 1) { HandStrength = 4385; return HandStrength; }
					if (n4 == 1) { HandStrength = 4384; return HandStrength; }
					if (n3 == 1) { HandStrength = 4383; return HandStrength; }
					if (n2 == 1) { HandStrength = 4382; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4381; return HandStrength; }
					if (n6 == 1) { HandStrength = 4380; return HandStrength; }
					if (n5 == 1) { HandStrength = 4379; return HandStrength; }
					if (n4 == 1) { HandStrength = 4378; return HandStrength; }
					if (n3 == 1) { HandStrength = 4377; return HandStrength; }
					if (n2 == 1) { HandStrength = 4376; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4375; return HandStrength; }
					if (n5 == 1) { HandStrength = 4374; return HandStrength; }
					if (n4 == 1) { HandStrength = 4373; return HandStrength; }
					if (n3 == 1) { HandStrength = 4372; return HandStrength; }
					if (n2 == 1) { HandStrength = 4371; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4370; return HandStrength; }
					if (n4 == 1) { HandStrength = 4369; return HandStrength; }
					if (n3 == 1) { HandStrength = 4368; return HandStrength; }
					if (n2 == 1) { HandStrength = 4367; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4366; return HandStrength; }
					if (n3 == 1) { HandStrength = 4365; return HandStrength; }
					if (n2 == 1) { HandStrength = 4364; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4363; return HandStrength; }
					if (n2 == 1) { HandStrength = 4362; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4361; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4360; return HandStrength; }
					if (n9 == 1) { HandStrength = 4359; return HandStrength; }
					if (n8 == 1) { HandStrength = 4358; return HandStrength; }
					if (n6 == 1) { HandStrength = 4357; return HandStrength; }
					if (n5 == 1) { HandStrength = 4356; return HandStrength; }
					if (n4 == 1) { HandStrength = 4355; return HandStrength; }
					if (n3 == 1) { HandStrength = 4354; return HandStrength; }
					if (n2 == 1) { HandStrength = 4353; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4352; return HandStrength; }
					if (n8 == 1) { HandStrength = 4351; return HandStrength; }
					if (n6 == 1) { HandStrength = 4350; return HandStrength; }
					if (n5 == 1) { HandStrength = 4349; return HandStrength; }
					if (n4 == 1) { HandStrength = 4348; return HandStrength; }
					if (n3 == 1) { HandStrength = 4347; return HandStrength; }
					if (n2 == 1) { HandStrength = 4346; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4345; return HandStrength; }
					if (n6 == 1) { HandStrength = 4344; return HandStrength; }
					if (n5 == 1) { HandStrength = 4343; return HandStrength; }
					if (n4 == 1) { HandStrength = 4342; return HandStrength; }
					if (n3 == 1) { HandStrength = 4341; return HandStrength; }
					if (n2 == 1) { HandStrength = 4340; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4339; return HandStrength; }
					if (n5 == 1) { HandStrength = 4338; return HandStrength; }
					if (n4 == 1) { HandStrength = 4337; return HandStrength; }
					if (n3 == 1) { HandStrength = 4336; return HandStrength; }
					if (n2 == 1) { HandStrength = 4335; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4334; return HandStrength; }
					if (n4 == 1) { HandStrength = 4333; return HandStrength; }
					if (n3 == 1) { HandStrength = 4332; return HandStrength; }
					if (n2 == 1) { HandStrength = 4331; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4330; return HandStrength; }
					if (n3 == 1) { HandStrength = 4329; return HandStrength; }
					if (n2 == 1) { HandStrength = 4328; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4327; return HandStrength; }
					if (n2 == 1) { HandStrength = 4326; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4325; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4324; return HandStrength; }
					if (n8 == 1) { HandStrength = 4323; return HandStrength; }
					if (n6 == 1) { HandStrength = 4322; return HandStrength; }
					if (n5 == 1) { HandStrength = 4321; return HandStrength; }
					if (n4 == 1) { HandStrength = 4320; return HandStrength; }
					if (n3 == 1) { HandStrength = 4319; return HandStrength; }
					if (n2 == 1) { HandStrength = 4318; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4317; return HandStrength; }
					if (n6 == 1) { HandStrength = 4316; return HandStrength; }
					if (n5 == 1) { HandStrength = 4315; return HandStrength; }
					if (n4 == 1) { HandStrength = 4314; return HandStrength; }
					if (n3 == 1) { HandStrength = 4313; return HandStrength; }
					if (n2 == 1) { HandStrength = 4312; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4311; return HandStrength; }
					if (n5 == 1) { HandStrength = 4310; return HandStrength; }
					if (n4 == 1) { HandStrength = 4309; return HandStrength; }
					if (n3 == 1) { HandStrength = 4308; return HandStrength; }
					if (n2 == 1) { HandStrength = 4307; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4306; return HandStrength; }
					if (n4 == 1) { HandStrength = 4305; return HandStrength; }
					if (n3 == 1) { HandStrength = 4304; return HandStrength; }
					if (n2 == 1) { HandStrength = 4303; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4302; return HandStrength; }
					if (n3 == 1) { HandStrength = 4301; return HandStrength; }
					if (n2 == 1) { HandStrength = 4300; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4299; return HandStrength; }
					if (n2 == 1) { HandStrength = 4298; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4297; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4296; return HandStrength; }
					if (n6 == 1) { HandStrength = 4295; return HandStrength; }
					if (n5 == 1) { HandStrength = 4294; return HandStrength; }
					if (n4 == 1) { HandStrength = 4293; return HandStrength; }
					if (n3 == 1) { HandStrength = 4292; return HandStrength; }
					if (n2 == 1) { HandStrength = 4291; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4290; return HandStrength; }
					if (n5 == 1) { HandStrength = 4289; return HandStrength; }
					if (n4 == 1) { HandStrength = 4288; return HandStrength; }
					if (n3 == 1) { HandStrength = 4287; return HandStrength; }
					if (n2 == 1) { HandStrength = 4286; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4285; return HandStrength; }
					if (n4 == 1) { HandStrength = 4284; return HandStrength; }
					if (n3 == 1) { HandStrength = 4283; return HandStrength; }
					if (n2 == 1) { HandStrength = 4282; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4281; return HandStrength; }
					if (n3 == 1) { HandStrength = 4280; return HandStrength; }
					if (n2 == 1) { HandStrength = 4279; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4278; return HandStrength; }
					if (n2 == 1) { HandStrength = 4277; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4276; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 4275; return HandStrength; }
					if (n5 == 1) { HandStrength = 4274; return HandStrength; }
					if (n4 == 1) { HandStrength = 4273; return HandStrength; }
					if (n3 == 1) { HandStrength = 4272; return HandStrength; }
					if (n2 == 1) { HandStrength = 4271; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4270; return HandStrength; }
					if (n4 == 1) { HandStrength = 4269; return HandStrength; }
					if (n3 == 1) { HandStrength = 4268; return HandStrength; }
					if (n2 == 1) { HandStrength = 4267; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4266; return HandStrength; }
					if (n3 == 1) { HandStrength = 4265; return HandStrength; }
					if (n2 == 1) { HandStrength = 4264; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4263; return HandStrength; }
					if (n2 == 1) { HandStrength = 4262; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4261; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 4260; return HandStrength; }
					if (n4 == 1) { HandStrength = 4259; return HandStrength; }
					if (n3 == 1) { HandStrength = 4258; return HandStrength; }
					if (n2 == 1) { HandStrength = 4257; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4256; return HandStrength; }
					if (n3 == 1) { HandStrength = 4255; return HandStrength; }
					if (n2 == 1) { HandStrength = 4254; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4253; return HandStrength; }
					if (n2 == 1) { HandStrength = 4252; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4251; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4250; return HandStrength; }
					if (n3 == 1) { HandStrength = 4249; return HandStrength; }
					if (n2 == 1) { HandStrength = 4248; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4247; return HandStrength; }
					if (n2 == 1) { HandStrength = 4246; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4245; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4244; return HandStrength; }
					if (n2 == 1) { HandStrength = 4243; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4242; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4241; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 4240; return HandStrength; }
					if (nJ == 1) { HandStrength = 4239; return HandStrength; }
					if (nT == 1) { HandStrength = 4238; return HandStrength; }
					if (n9 == 1) { HandStrength = 4237; return HandStrength; }
					if (n8 == 1) { HandStrength = 4236; return HandStrength; }
					if (n7 == 1) { HandStrength = 4235; return HandStrength; }
					if (n5 == 1) { HandStrength = 4234; return HandStrength; }
					if (n4 == 1) { HandStrength = 4233; return HandStrength; }
					if (n3 == 1) { HandStrength = 4232; return HandStrength; }
					if (n2 == 1) { HandStrength = 4231; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4230; return HandStrength; }
					if (nT == 1) { HandStrength = 4229; return HandStrength; }
					if (n9 == 1) { HandStrength = 4228; return HandStrength; }
					if (n8 == 1) { HandStrength = 4227; return HandStrength; }
					if (n7 == 1) { HandStrength = 4226; return HandStrength; }
					if (n5 == 1) { HandStrength = 4225; return HandStrength; }
					if (n4 == 1) { HandStrength = 4224; return HandStrength; }
					if (n3 == 1) { HandStrength = 4223; return HandStrength; }
					if (n2 == 1) { HandStrength = 4222; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4221; return HandStrength; }
					if (n9 == 1) { HandStrength = 4220; return HandStrength; }
					if (n8 == 1) { HandStrength = 4219; return HandStrength; }
					if (n7 == 1) { HandStrength = 4218; return HandStrength; }
					if (n5 == 1) { HandStrength = 4217; return HandStrength; }
					if (n4 == 1) { HandStrength = 4216; return HandStrength; }
					if (n3 == 1) { HandStrength = 4215; return HandStrength; }
					if (n2 == 1) { HandStrength = 4214; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4213; return HandStrength; }
					if (n8 == 1) { HandStrength = 4212; return HandStrength; }
					if (n7 == 1) { HandStrength = 4211; return HandStrength; }
					if (n5 == 1) { HandStrength = 4210; return HandStrength; }
					if (n4 == 1) { HandStrength = 4209; return HandStrength; }
					if (n3 == 1) { HandStrength = 4208; return HandStrength; }
					if (n2 == 1) { HandStrength = 4207; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4206; return HandStrength; }
					if (n7 == 1) { HandStrength = 4205; return HandStrength; }
					if (n5 == 1) { HandStrength = 4204; return HandStrength; }
					if (n4 == 1) { HandStrength = 4203; return HandStrength; }
					if (n3 == 1) { HandStrength = 4202; return HandStrength; }
					if (n2 == 1) { HandStrength = 4201; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4200; return HandStrength; }
					if (n5 == 1) { HandStrength = 4199; return HandStrength; }
					if (n4 == 1) { HandStrength = 4198; return HandStrength; }
					if (n3 == 1) { HandStrength = 4197; return HandStrength; }
					if (n2 == 1) { HandStrength = 4196; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4195; return HandStrength; }
					if (n4 == 1) { HandStrength = 4194; return HandStrength; }
					if (n3 == 1) { HandStrength = 4193; return HandStrength; }
					if (n2 == 1) { HandStrength = 4192; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4191; return HandStrength; }
					if (n3 == 1) { HandStrength = 4190; return HandStrength; }
					if (n2 == 1) { HandStrength = 4189; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4188; return HandStrength; }
					if (n2 == 1) { HandStrength = 4187; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4186; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4185; return HandStrength; }
					if (nT == 1) { HandStrength = 4184; return HandStrength; }
					if (n9 == 1) { HandStrength = 4183; return HandStrength; }
					if (n8 == 1) { HandStrength = 4182; return HandStrength; }
					if (n7 == 1) { HandStrength = 4181; return HandStrength; }
					if (n5 == 1) { HandStrength = 4180; return HandStrength; }
					if (n4 == 1) { HandStrength = 4179; return HandStrength; }
					if (n3 == 1) { HandStrength = 4178; return HandStrength; }
					if (n2 == 1) { HandStrength = 4177; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4176; return HandStrength; }
					if (n9 == 1) { HandStrength = 4175; return HandStrength; }
					if (n8 == 1) { HandStrength = 4174; return HandStrength; }
					if (n7 == 1) { HandStrength = 4173; return HandStrength; }
					if (n5 == 1) { HandStrength = 4172; return HandStrength; }
					if (n4 == 1) { HandStrength = 4171; return HandStrength; }
					if (n3 == 1) { HandStrength = 4170; return HandStrength; }
					if (n2 == 1) { HandStrength = 4169; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4168; return HandStrength; }
					if (n8 == 1) { HandStrength = 4167; return HandStrength; }
					if (n7 == 1) { HandStrength = 4166; return HandStrength; }
					if (n5 == 1) { HandStrength = 4165; return HandStrength; }
					if (n4 == 1) { HandStrength = 4164; return HandStrength; }
					if (n3 == 1) { HandStrength = 4163; return HandStrength; }
					if (n2 == 1) { HandStrength = 4162; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4161; return HandStrength; }
					if (n7 == 1) { HandStrength = 4160; return HandStrength; }
					if (n5 == 1) { HandStrength = 4159; return HandStrength; }
					if (n4 == 1) { HandStrength = 4158; return HandStrength; }
					if (n3 == 1) { HandStrength = 4157; return HandStrength; }
					if (n2 == 1) { HandStrength = 4156; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4155; return HandStrength; }
					if (n5 == 1) { HandStrength = 4154; return HandStrength; }
					if (n4 == 1) { HandStrength = 4153; return HandStrength; }
					if (n3 == 1) { HandStrength = 4152; return HandStrength; }
					if (n2 == 1) { HandStrength = 4151; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4150; return HandStrength; }
					if (n4 == 1) { HandStrength = 4149; return HandStrength; }
					if (n3 == 1) { HandStrength = 4148; return HandStrength; }
					if (n2 == 1) { HandStrength = 4147; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4146; return HandStrength; }
					if (n3 == 1) { HandStrength = 4145; return HandStrength; }
					if (n2 == 1) { HandStrength = 4144; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4143; return HandStrength; }
					if (n2 == 1) { HandStrength = 4142; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4141; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4140; return HandStrength; }
					if (n9 == 1) { HandStrength = 4139; return HandStrength; }
					if (n8 == 1) { HandStrength = 4138; return HandStrength; }
					if (n7 == 1) { HandStrength = 4137; return HandStrength; }
					if (n5 == 1) { HandStrength = 4136; return HandStrength; }
					if (n4 == 1) { HandStrength = 4135; return HandStrength; }
					if (n3 == 1) { HandStrength = 4134; return HandStrength; }
					if (n2 == 1) { HandStrength = 4133; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4132; return HandStrength; }
					if (n8 == 1) { HandStrength = 4131; return HandStrength; }
					if (n7 == 1) { HandStrength = 4130; return HandStrength; }
					if (n5 == 1) { HandStrength = 4129; return HandStrength; }
					if (n4 == 1) { HandStrength = 4128; return HandStrength; }
					if (n3 == 1) { HandStrength = 4127; return HandStrength; }
					if (n2 == 1) { HandStrength = 4126; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4125; return HandStrength; }
					if (n7 == 1) { HandStrength = 4124; return HandStrength; }
					if (n5 == 1) { HandStrength = 4123; return HandStrength; }
					if (n4 == 1) { HandStrength = 4122; return HandStrength; }
					if (n3 == 1) { HandStrength = 4121; return HandStrength; }
					if (n2 == 1) { HandStrength = 4120; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4119; return HandStrength; }
					if (n5 == 1) { HandStrength = 4118; return HandStrength; }
					if (n4 == 1) { HandStrength = 4117; return HandStrength; }
					if (n3 == 1) { HandStrength = 4116; return HandStrength; }
					if (n2 == 1) { HandStrength = 4115; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4114; return HandStrength; }
					if (n4 == 1) { HandStrength = 4113; return HandStrength; }
					if (n3 == 1) { HandStrength = 4112; return HandStrength; }
					if (n2 == 1) { HandStrength = 4111; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4110; return HandStrength; }
					if (n3 == 1) { HandStrength = 4109; return HandStrength; }
					if (n2 == 1) { HandStrength = 4108; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4107; return HandStrength; }
					if (n2 == 1) { HandStrength = 4106; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4105; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 4104; return HandStrength; }
					if (n8 == 1) { HandStrength = 4103; return HandStrength; }
					if (n7 == 1) { HandStrength = 4102; return HandStrength; }
					if (n5 == 1) { HandStrength = 4101; return HandStrength; }
					if (n4 == 1) { HandStrength = 4100; return HandStrength; }
					if (n3 == 1) { HandStrength = 4099; return HandStrength; }
					if (n2 == 1) { HandStrength = 4098; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4097; return HandStrength; }
					if (n7 == 1) { HandStrength = 4096; return HandStrength; }
					if (n5 == 1) { HandStrength = 4095; return HandStrength; }
					if (n4 == 1) { HandStrength = 4094; return HandStrength; }
					if (n3 == 1) { HandStrength = 4093; return HandStrength; }
					if (n2 == 1) { HandStrength = 4092; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4091; return HandStrength; }
					if (n5 == 1) { HandStrength = 4090; return HandStrength; }
					if (n4 == 1) { HandStrength = 4089; return HandStrength; }
					if (n3 == 1) { HandStrength = 4088; return HandStrength; }
					if (n2 == 1) { HandStrength = 4087; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4086; return HandStrength; }
					if (n4 == 1) { HandStrength = 4085; return HandStrength; }
					if (n3 == 1) { HandStrength = 4084; return HandStrength; }
					if (n2 == 1) { HandStrength = 4083; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4082; return HandStrength; }
					if (n3 == 1) { HandStrength = 4081; return HandStrength; }
					if (n2 == 1) { HandStrength = 4080; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4079; return HandStrength; }
					if (n2 == 1) { HandStrength = 4078; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4077; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 4076; return HandStrength; }
					if (n7 == 1) { HandStrength = 4075; return HandStrength; }
					if (n5 == 1) { HandStrength = 4074; return HandStrength; }
					if (n4 == 1) { HandStrength = 4073; return HandStrength; }
					if (n3 == 1) { HandStrength = 4072; return HandStrength; }
					if (n2 == 1) { HandStrength = 4071; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4070; return HandStrength; }
					if (n5 == 1) { HandStrength = 4069; return HandStrength; }
					if (n4 == 1) { HandStrength = 4068; return HandStrength; }
					if (n3 == 1) { HandStrength = 4067; return HandStrength; }
					if (n2 == 1) { HandStrength = 4066; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4065; return HandStrength; }
					if (n4 == 1) { HandStrength = 4064; return HandStrength; }
					if (n3 == 1) { HandStrength = 4063; return HandStrength; }
					if (n2 == 1) { HandStrength = 4062; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4061; return HandStrength; }
					if (n3 == 1) { HandStrength = 4060; return HandStrength; }
					if (n2 == 1) { HandStrength = 4059; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4058; return HandStrength; }
					if (n2 == 1) { HandStrength = 4057; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4056; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 4055; return HandStrength; }
					if (n5 == 1) { HandStrength = 4054; return HandStrength; }
					if (n4 == 1) { HandStrength = 4053; return HandStrength; }
					if (n3 == 1) { HandStrength = 4052; return HandStrength; }
					if (n2 == 1) { HandStrength = 4051; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4050; return HandStrength; }
					if (n4 == 1) { HandStrength = 4049; return HandStrength; }
					if (n3 == 1) { HandStrength = 4048; return HandStrength; }
					if (n2 == 1) { HandStrength = 4047; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4046; return HandStrength; }
					if (n3 == 1) { HandStrength = 4045; return HandStrength; }
					if (n2 == 1) { HandStrength = 4044; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4043; return HandStrength; }
					if (n2 == 1) { HandStrength = 4042; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4041; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 4040; return HandStrength; }
					if (n4 == 1) { HandStrength = 4039; return HandStrength; }
					if (n3 == 1) { HandStrength = 4038; return HandStrength; }
					if (n2 == 1) { HandStrength = 4037; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4036; return HandStrength; }
					if (n3 == 1) { HandStrength = 4035; return HandStrength; }
					if (n2 == 1) { HandStrength = 4034; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4033; return HandStrength; }
					if (n2 == 1) { HandStrength = 4032; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4031; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 4030; return HandStrength; }
					if (n3 == 1) { HandStrength = 4029; return HandStrength; }
					if (n2 == 1) { HandStrength = 4028; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4027; return HandStrength; }
					if (n2 == 1) { HandStrength = 4026; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4025; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 4024; return HandStrength; }
					if (n2 == 1) { HandStrength = 4023; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4022; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 4021; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 4020; return HandStrength; }
					if (nJ == 1) { HandStrength = 4019; return HandStrength; }
					if (nT == 1) { HandStrength = 4018; return HandStrength; }
					if (n9 == 1) { HandStrength = 4017; return HandStrength; }
					if (n8 == 1) { HandStrength = 4016; return HandStrength; }
					if (n7 == 1) { HandStrength = 4015; return HandStrength; }
					if (n6 == 1) { HandStrength = 4014; return HandStrength; }
					if (n4 == 1) { HandStrength = 4013; return HandStrength; }
					if (n3 == 1) { HandStrength = 4012; return HandStrength; }
					if (n2 == 1) { HandStrength = 4011; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 4010; return HandStrength; }
					if (nT == 1) { HandStrength = 4009; return HandStrength; }
					if (n9 == 1) { HandStrength = 4008; return HandStrength; }
					if (n8 == 1) { HandStrength = 4007; return HandStrength; }
					if (n7 == 1) { HandStrength = 4006; return HandStrength; }
					if (n6 == 1) { HandStrength = 4005; return HandStrength; }
					if (n4 == 1) { HandStrength = 4004; return HandStrength; }
					if (n3 == 1) { HandStrength = 4003; return HandStrength; }
					if (n2 == 1) { HandStrength = 4002; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 4001; return HandStrength; }
					if (n9 == 1) { HandStrength = 4000; return HandStrength; }
					if (n8 == 1) { HandStrength = 3999; return HandStrength; }
					if (n7 == 1) { HandStrength = 3998; return HandStrength; }
					if (n6 == 1) { HandStrength = 3997; return HandStrength; }
					if (n4 == 1) { HandStrength = 3996; return HandStrength; }
					if (n3 == 1) { HandStrength = 3995; return HandStrength; }
					if (n2 == 1) { HandStrength = 3994; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3993; return HandStrength; }
					if (n8 == 1) { HandStrength = 3992; return HandStrength; }
					if (n7 == 1) { HandStrength = 3991; return HandStrength; }
					if (n6 == 1) { HandStrength = 3990; return HandStrength; }
					if (n4 == 1) { HandStrength = 3989; return HandStrength; }
					if (n3 == 1) { HandStrength = 3988; return HandStrength; }
					if (n2 == 1) { HandStrength = 3987; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3986; return HandStrength; }
					if (n7 == 1) { HandStrength = 3985; return HandStrength; }
					if (n6 == 1) { HandStrength = 3984; return HandStrength; }
					if (n4 == 1) { HandStrength = 3983; return HandStrength; }
					if (n3 == 1) { HandStrength = 3982; return HandStrength; }
					if (n2 == 1) { HandStrength = 3981; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3980; return HandStrength; }
					if (n6 == 1) { HandStrength = 3979; return HandStrength; }
					if (n4 == 1) { HandStrength = 3978; return HandStrength; }
					if (n3 == 1) { HandStrength = 3977; return HandStrength; }
					if (n2 == 1) { HandStrength = 3976; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3975; return HandStrength; }
					if (n4 == 1) { HandStrength = 3974; return HandStrength; }
					if (n3 == 1) { HandStrength = 3973; return HandStrength; }
					if (n2 == 1) { HandStrength = 3972; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3971; return HandStrength; }
					if (n3 == 1) { HandStrength = 3970; return HandStrength; }
					if (n2 == 1) { HandStrength = 3969; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3968; return HandStrength; }
					if (n2 == 1) { HandStrength = 3967; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3966; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3965; return HandStrength; }
					if (nT == 1) { HandStrength = 3964; return HandStrength; }
					if (n9 == 1) { HandStrength = 3963; return HandStrength; }
					if (n8 == 1) { HandStrength = 3962; return HandStrength; }
					if (n7 == 1) { HandStrength = 3961; return HandStrength; }
					if (n6 == 1) { HandStrength = 3960; return HandStrength; }
					if (n4 == 1) { HandStrength = 3959; return HandStrength; }
					if (n3 == 1) { HandStrength = 3958; return HandStrength; }
					if (n2 == 1) { HandStrength = 3957; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3956; return HandStrength; }
					if (n9 == 1) { HandStrength = 3955; return HandStrength; }
					if (n8 == 1) { HandStrength = 3954; return HandStrength; }
					if (n7 == 1) { HandStrength = 3953; return HandStrength; }
					if (n6 == 1) { HandStrength = 3952; return HandStrength; }
					if (n4 == 1) { HandStrength = 3951; return HandStrength; }
					if (n3 == 1) { HandStrength = 3950; return HandStrength; }
					if (n2 == 1) { HandStrength = 3949; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3948; return HandStrength; }
					if (n8 == 1) { HandStrength = 3947; return HandStrength; }
					if (n7 == 1) { HandStrength = 3946; return HandStrength; }
					if (n6 == 1) { HandStrength = 3945; return HandStrength; }
					if (n4 == 1) { HandStrength = 3944; return HandStrength; }
					if (n3 == 1) { HandStrength = 3943; return HandStrength; }
					if (n2 == 1) { HandStrength = 3942; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3941; return HandStrength; }
					if (n7 == 1) { HandStrength = 3940; return HandStrength; }
					if (n6 == 1) { HandStrength = 3939; return HandStrength; }
					if (n4 == 1) { HandStrength = 3938; return HandStrength; }
					if (n3 == 1) { HandStrength = 3937; return HandStrength; }
					if (n2 == 1) { HandStrength = 3936; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3935; return HandStrength; }
					if (n6 == 1) { HandStrength = 3934; return HandStrength; }
					if (n4 == 1) { HandStrength = 3933; return HandStrength; }
					if (n3 == 1) { HandStrength = 3932; return HandStrength; }
					if (n2 == 1) { HandStrength = 3931; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3930; return HandStrength; }
					if (n4 == 1) { HandStrength = 3929; return HandStrength; }
					if (n3 == 1) { HandStrength = 3928; return HandStrength; }
					if (n2 == 1) { HandStrength = 3927; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3926; return HandStrength; }
					if (n3 == 1) { HandStrength = 3925; return HandStrength; }
					if (n2 == 1) { HandStrength = 3924; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3923; return HandStrength; }
					if (n2 == 1) { HandStrength = 3922; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3921; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3920; return HandStrength; }
					if (n9 == 1) { HandStrength = 3919; return HandStrength; }
					if (n8 == 1) { HandStrength = 3918; return HandStrength; }
					if (n7 == 1) { HandStrength = 3917; return HandStrength; }
					if (n6 == 1) { HandStrength = 3916; return HandStrength; }
					if (n4 == 1) { HandStrength = 3915; return HandStrength; }
					if (n3 == 1) { HandStrength = 3914; return HandStrength; }
					if (n2 == 1) { HandStrength = 3913; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3912; return HandStrength; }
					if (n8 == 1) { HandStrength = 3911; return HandStrength; }
					if (n7 == 1) { HandStrength = 3910; return HandStrength; }
					if (n6 == 1) { HandStrength = 3909; return HandStrength; }
					if (n4 == 1) { HandStrength = 3908; return HandStrength; }
					if (n3 == 1) { HandStrength = 3907; return HandStrength; }
					if (n2 == 1) { HandStrength = 3906; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3905; return HandStrength; }
					if (n7 == 1) { HandStrength = 3904; return HandStrength; }
					if (n6 == 1) { HandStrength = 3903; return HandStrength; }
					if (n4 == 1) { HandStrength = 3902; return HandStrength; }
					if (n3 == 1) { HandStrength = 3901; return HandStrength; }
					if (n2 == 1) { HandStrength = 3900; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3899; return HandStrength; }
					if (n6 == 1) { HandStrength = 3898; return HandStrength; }
					if (n4 == 1) { HandStrength = 3897; return HandStrength; }
					if (n3 == 1) { HandStrength = 3896; return HandStrength; }
					if (n2 == 1) { HandStrength = 3895; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3894; return HandStrength; }
					if (n4 == 1) { HandStrength = 3893; return HandStrength; }
					if (n3 == 1) { HandStrength = 3892; return HandStrength; }
					if (n2 == 1) { HandStrength = 3891; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3890; return HandStrength; }
					if (n3 == 1) { HandStrength = 3889; return HandStrength; }
					if (n2 == 1) { HandStrength = 3888; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3887; return HandStrength; }
					if (n2 == 1) { HandStrength = 3886; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3885; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3884; return HandStrength; }
					if (n8 == 1) { HandStrength = 3883; return HandStrength; }
					if (n7 == 1) { HandStrength = 3882; return HandStrength; }
					if (n6 == 1) { HandStrength = 3881; return HandStrength; }
					if (n4 == 1) { HandStrength = 3880; return HandStrength; }
					if (n3 == 1) { HandStrength = 3879; return HandStrength; }
					if (n2 == 1) { HandStrength = 3878; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3877; return HandStrength; }
					if (n7 == 1) { HandStrength = 3876; return HandStrength; }
					if (n6 == 1) { HandStrength = 3875; return HandStrength; }
					if (n4 == 1) { HandStrength = 3874; return HandStrength; }
					if (n3 == 1) { HandStrength = 3873; return HandStrength; }
					if (n2 == 1) { HandStrength = 3872; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3871; return HandStrength; }
					if (n6 == 1) { HandStrength = 3870; return HandStrength; }
					if (n4 == 1) { HandStrength = 3869; return HandStrength; }
					if (n3 == 1) { HandStrength = 3868; return HandStrength; }
					if (n2 == 1) { HandStrength = 3867; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3866; return HandStrength; }
					if (n4 == 1) { HandStrength = 3865; return HandStrength; }
					if (n3 == 1) { HandStrength = 3864; return HandStrength; }
					if (n2 == 1) { HandStrength = 3863; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3862; return HandStrength; }
					if (n3 == 1) { HandStrength = 3861; return HandStrength; }
					if (n2 == 1) { HandStrength = 3860; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3859; return HandStrength; }
					if (n2 == 1) { HandStrength = 3858; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3857; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3856; return HandStrength; }
					if (n7 == 1) { HandStrength = 3855; return HandStrength; }
					if (n6 == 1) { HandStrength = 3854; return HandStrength; }
					if (n4 == 1) { HandStrength = 3853; return HandStrength; }
					if (n3 == 1) { HandStrength = 3852; return HandStrength; }
					if (n2 == 1) { HandStrength = 3851; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3850; return HandStrength; }
					if (n6 == 1) { HandStrength = 3849; return HandStrength; }
					if (n4 == 1) { HandStrength = 3848; return HandStrength; }
					if (n3 == 1) { HandStrength = 3847; return HandStrength; }
					if (n2 == 1) { HandStrength = 3846; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3845; return HandStrength; }
					if (n4 == 1) { HandStrength = 3844; return HandStrength; }
					if (n3 == 1) { HandStrength = 3843; return HandStrength; }
					if (n2 == 1) { HandStrength = 3842; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3841; return HandStrength; }
					if (n3 == 1) { HandStrength = 3840; return HandStrength; }
					if (n2 == 1) { HandStrength = 3839; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3838; return HandStrength; }
					if (n2 == 1) { HandStrength = 3837; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3836; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3835; return HandStrength; }
					if (n6 == 1) { HandStrength = 3834; return HandStrength; }
					if (n4 == 1) { HandStrength = 3833; return HandStrength; }
					if (n3 == 1) { HandStrength = 3832; return HandStrength; }
					if (n2 == 1) { HandStrength = 3831; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3830; return HandStrength; }
					if (n4 == 1) { HandStrength = 3829; return HandStrength; }
					if (n3 == 1) { HandStrength = 3828; return HandStrength; }
					if (n2 == 1) { HandStrength = 3827; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3826; return HandStrength; }
					if (n3 == 1) { HandStrength = 3825; return HandStrength; }
					if (n2 == 1) { HandStrength = 3824; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3823; return HandStrength; }
					if (n2 == 1) { HandStrength = 3822; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3821; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3820; return HandStrength; }
					if (n4 == 1) { HandStrength = 3819; return HandStrength; }
					if (n3 == 1) { HandStrength = 3818; return HandStrength; }
					if (n2 == 1) { HandStrength = 3817; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3816; return HandStrength; }
					if (n3 == 1) { HandStrength = 3815; return HandStrength; }
					if (n2 == 1) { HandStrength = 3814; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3813; return HandStrength; }
					if (n2 == 1) { HandStrength = 3812; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3811; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = 3810; return HandStrength; }
					if (n3 == 1) { HandStrength = 3809; return HandStrength; }
					if (n2 == 1) { HandStrength = 3808; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3807; return HandStrength; }
					if (n2 == 1) { HandStrength = 3806; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3805; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3804; return HandStrength; }
					if (n2 == 1) { HandStrength = 3803; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3802; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3801; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 3800; return HandStrength; }
					if (nJ == 1) { HandStrength = 3799; return HandStrength; }
					if (nT == 1) { HandStrength = 3798; return HandStrength; }
					if (n9 == 1) { HandStrength = 3797; return HandStrength; }
					if (n8 == 1) { HandStrength = 3796; return HandStrength; }
					if (n7 == 1) { HandStrength = 3795; return HandStrength; }
					if (n6 == 1) { HandStrength = 3794; return HandStrength; }
					if (n5 == 1) { HandStrength = 3793; return HandStrength; }
					if (n3 == 1) { HandStrength = 3792; return HandStrength; }
					if (n2 == 1) { HandStrength = 3791; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3790; return HandStrength; }
					if (nT == 1) { HandStrength = 3789; return HandStrength; }
					if (n9 == 1) { HandStrength = 3788; return HandStrength; }
					if (n8 == 1) { HandStrength = 3787; return HandStrength; }
					if (n7 == 1) { HandStrength = 3786; return HandStrength; }
					if (n6 == 1) { HandStrength = 3785; return HandStrength; }
					if (n5 == 1) { HandStrength = 3784; return HandStrength; }
					if (n3 == 1) { HandStrength = 3783; return HandStrength; }
					if (n2 == 1) { HandStrength = 3782; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3781; return HandStrength; }
					if (n9 == 1) { HandStrength = 3780; return HandStrength; }
					if (n8 == 1) { HandStrength = 3779; return HandStrength; }
					if (n7 == 1) { HandStrength = 3778; return HandStrength; }
					if (n6 == 1) { HandStrength = 3777; return HandStrength; }
					if (n5 == 1) { HandStrength = 3776; return HandStrength; }
					if (n3 == 1) { HandStrength = 3775; return HandStrength; }
					if (n2 == 1) { HandStrength = 3774; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3773; return HandStrength; }
					if (n8 == 1) { HandStrength = 3772; return HandStrength; }
					if (n7 == 1) { HandStrength = 3771; return HandStrength; }
					if (n6 == 1) { HandStrength = 3770; return HandStrength; }
					if (n5 == 1) { HandStrength = 3769; return HandStrength; }
					if (n3 == 1) { HandStrength = 3768; return HandStrength; }
					if (n2 == 1) { HandStrength = 3767; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3766; return HandStrength; }
					if (n7 == 1) { HandStrength = 3765; return HandStrength; }
					if (n6 == 1) { HandStrength = 3764; return HandStrength; }
					if (n5 == 1) { HandStrength = 3763; return HandStrength; }
					if (n3 == 1) { HandStrength = 3762; return HandStrength; }
					if (n2 == 1) { HandStrength = 3761; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3760; return HandStrength; }
					if (n6 == 1) { HandStrength = 3759; return HandStrength; }
					if (n5 == 1) { HandStrength = 3758; return HandStrength; }
					if (n3 == 1) { HandStrength = 3757; return HandStrength; }
					if (n2 == 1) { HandStrength = 3756; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3755; return HandStrength; }
					if (n5 == 1) { HandStrength = 3754; return HandStrength; }
					if (n3 == 1) { HandStrength = 3753; return HandStrength; }
					if (n2 == 1) { HandStrength = 3752; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3751; return HandStrength; }
					if (n3 == 1) { HandStrength = 3750; return HandStrength; }
					if (n2 == 1) { HandStrength = 3749; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3748; return HandStrength; }
					if (n2 == 1) { HandStrength = 3747; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3746; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3745; return HandStrength; }
					if (nT == 1) { HandStrength = 3744; return HandStrength; }
					if (n9 == 1) { HandStrength = 3743; return HandStrength; }
					if (n8 == 1) { HandStrength = 3742; return HandStrength; }
					if (n7 == 1) { HandStrength = 3741; return HandStrength; }
					if (n6 == 1) { HandStrength = 3740; return HandStrength; }
					if (n5 == 1) { HandStrength = 3739; return HandStrength; }
					if (n3 == 1) { HandStrength = 3738; return HandStrength; }
					if (n2 == 1) { HandStrength = 3737; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3736; return HandStrength; }
					if (n9 == 1) { HandStrength = 3735; return HandStrength; }
					if (n8 == 1) { HandStrength = 3734; return HandStrength; }
					if (n7 == 1) { HandStrength = 3733; return HandStrength; }
					if (n6 == 1) { HandStrength = 3732; return HandStrength; }
					if (n5 == 1) { HandStrength = 3731; return HandStrength; }
					if (n3 == 1) { HandStrength = 3730; return HandStrength; }
					if (n2 == 1) { HandStrength = 3729; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3728; return HandStrength; }
					if (n8 == 1) { HandStrength = 3727; return HandStrength; }
					if (n7 == 1) { HandStrength = 3726; return HandStrength; }
					if (n6 == 1) { HandStrength = 3725; return HandStrength; }
					if (n5 == 1) { HandStrength = 3724; return HandStrength; }
					if (n3 == 1) { HandStrength = 3723; return HandStrength; }
					if (n2 == 1) { HandStrength = 3722; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3721; return HandStrength; }
					if (n7 == 1) { HandStrength = 3720; return HandStrength; }
					if (n6 == 1) { HandStrength = 3719; return HandStrength; }
					if (n5 == 1) { HandStrength = 3718; return HandStrength; }
					if (n3 == 1) { HandStrength = 3717; return HandStrength; }
					if (n2 == 1) { HandStrength = 3716; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3715; return HandStrength; }
					if (n6 == 1) { HandStrength = 3714; return HandStrength; }
					if (n5 == 1) { HandStrength = 3713; return HandStrength; }
					if (n3 == 1) { HandStrength = 3712; return HandStrength; }
					if (n2 == 1) { HandStrength = 3711; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3710; return HandStrength; }
					if (n5 == 1) { HandStrength = 3709; return HandStrength; }
					if (n3 == 1) { HandStrength = 3708; return HandStrength; }
					if (n2 == 1) { HandStrength = 3707; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3706; return HandStrength; }
					if (n3 == 1) { HandStrength = 3705; return HandStrength; }
					if (n2 == 1) { HandStrength = 3704; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3703; return HandStrength; }
					if (n2 == 1) { HandStrength = 3702; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3701; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3700; return HandStrength; }
					if (n9 == 1) { HandStrength = 3699; return HandStrength; }
					if (n8 == 1) { HandStrength = 3698; return HandStrength; }
					if (n7 == 1) { HandStrength = 3697; return HandStrength; }
					if (n6 == 1) { HandStrength = 3696; return HandStrength; }
					if (n5 == 1) { HandStrength = 3695; return HandStrength; }
					if (n3 == 1) { HandStrength = 3694; return HandStrength; }
					if (n2 == 1) { HandStrength = 3693; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3692; return HandStrength; }
					if (n8 == 1) { HandStrength = 3691; return HandStrength; }
					if (n7 == 1) { HandStrength = 3690; return HandStrength; }
					if (n6 == 1) { HandStrength = 3689; return HandStrength; }
					if (n5 == 1) { HandStrength = 3688; return HandStrength; }
					if (n3 == 1) { HandStrength = 3687; return HandStrength; }
					if (n2 == 1) { HandStrength = 3686; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3685; return HandStrength; }
					if (n7 == 1) { HandStrength = 3684; return HandStrength; }
					if (n6 == 1) { HandStrength = 3683; return HandStrength; }
					if (n5 == 1) { HandStrength = 3682; return HandStrength; }
					if (n3 == 1) { HandStrength = 3681; return HandStrength; }
					if (n2 == 1) { HandStrength = 3680; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3679; return HandStrength; }
					if (n6 == 1) { HandStrength = 3678; return HandStrength; }
					if (n5 == 1) { HandStrength = 3677; return HandStrength; }
					if (n3 == 1) { HandStrength = 3676; return HandStrength; }
					if (n2 == 1) { HandStrength = 3675; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3674; return HandStrength; }
					if (n5 == 1) { HandStrength = 3673; return HandStrength; }
					if (n3 == 1) { HandStrength = 3672; return HandStrength; }
					if (n2 == 1) { HandStrength = 3671; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3670; return HandStrength; }
					if (n3 == 1) { HandStrength = 3669; return HandStrength; }
					if (n2 == 1) { HandStrength = 3668; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3667; return HandStrength; }
					if (n2 == 1) { HandStrength = 3666; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3665; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3664; return HandStrength; }
					if (n8 == 1) { HandStrength = 3663; return HandStrength; }
					if (n7 == 1) { HandStrength = 3662; return HandStrength; }
					if (n6 == 1) { HandStrength = 3661; return HandStrength; }
					if (n5 == 1) { HandStrength = 3660; return HandStrength; }
					if (n3 == 1) { HandStrength = 3659; return HandStrength; }
					if (n2 == 1) { HandStrength = 3658; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3657; return HandStrength; }
					if (n7 == 1) { HandStrength = 3656; return HandStrength; }
					if (n6 == 1) { HandStrength = 3655; return HandStrength; }
					if (n5 == 1) { HandStrength = 3654; return HandStrength; }
					if (n3 == 1) { HandStrength = 3653; return HandStrength; }
					if (n2 == 1) { HandStrength = 3652; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3651; return HandStrength; }
					if (n6 == 1) { HandStrength = 3650; return HandStrength; }
					if (n5 == 1) { HandStrength = 3649; return HandStrength; }
					if (n3 == 1) { HandStrength = 3648; return HandStrength; }
					if (n2 == 1) { HandStrength = 3647; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3646; return HandStrength; }
					if (n5 == 1) { HandStrength = 3645; return HandStrength; }
					if (n3 == 1) { HandStrength = 3644; return HandStrength; }
					if (n2 == 1) { HandStrength = 3643; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3642; return HandStrength; }
					if (n3 == 1) { HandStrength = 3641; return HandStrength; }
					if (n2 == 1) { HandStrength = 3640; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3639; return HandStrength; }
					if (n2 == 1) { HandStrength = 3638; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3637; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3636; return HandStrength; }
					if (n7 == 1) { HandStrength = 3635; return HandStrength; }
					if (n6 == 1) { HandStrength = 3634; return HandStrength; }
					if (n5 == 1) { HandStrength = 3633; return HandStrength; }
					if (n3 == 1) { HandStrength = 3632; return HandStrength; }
					if (n2 == 1) { HandStrength = 3631; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3630; return HandStrength; }
					if (n6 == 1) { HandStrength = 3629; return HandStrength; }
					if (n5 == 1) { HandStrength = 3628; return HandStrength; }
					if (n3 == 1) { HandStrength = 3627; return HandStrength; }
					if (n2 == 1) { HandStrength = 3626; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3625; return HandStrength; }
					if (n5 == 1) { HandStrength = 3624; return HandStrength; }
					if (n3 == 1) { HandStrength = 3623; return HandStrength; }
					if (n2 == 1) { HandStrength = 3622; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3621; return HandStrength; }
					if (n3 == 1) { HandStrength = 3620; return HandStrength; }
					if (n2 == 1) { HandStrength = 3619; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3618; return HandStrength; }
					if (n2 == 1) { HandStrength = 3617; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3616; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3615; return HandStrength; }
					if (n6 == 1) { HandStrength = 3614; return HandStrength; }
					if (n5 == 1) { HandStrength = 3613; return HandStrength; }
					if (n3 == 1) { HandStrength = 3612; return HandStrength; }
					if (n2 == 1) { HandStrength = 3611; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3610; return HandStrength; }
					if (n5 == 1) { HandStrength = 3609; return HandStrength; }
					if (n3 == 1) { HandStrength = 3608; return HandStrength; }
					if (n2 == 1) { HandStrength = 3607; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3606; return HandStrength; }
					if (n3 == 1) { HandStrength = 3605; return HandStrength; }
					if (n2 == 1) { HandStrength = 3604; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3603; return HandStrength; }
					if (n2 == 1) { HandStrength = 3602; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3601; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3600; return HandStrength; }
					if (n5 == 1) { HandStrength = 3599; return HandStrength; }
					if (n3 == 1) { HandStrength = 3598; return HandStrength; }
					if (n2 == 1) { HandStrength = 3597; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3596; return HandStrength; }
					if (n3 == 1) { HandStrength = 3595; return HandStrength; }
					if (n2 == 1) { HandStrength = 3594; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3593; return HandStrength; }
					if (n2 == 1) { HandStrength = 3592; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3591; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3590; return HandStrength; }
					if (n3 == 1) { HandStrength = 3589; return HandStrength; }
					if (n2 == 1) { HandStrength = 3588; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3587; return HandStrength; }
					if (n2 == 1) { HandStrength = 3586; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3585; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = 3584; return HandStrength; }
					if (n2 == 1) { HandStrength = 3583; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3582; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 3581; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 3580; return HandStrength; }
					if (nJ == 1) { HandStrength = 3579; return HandStrength; }
					if (nT == 1) { HandStrength = 3578; return HandStrength; }
					if (n9 == 1) { HandStrength = 3577; return HandStrength; }
					if (n8 == 1) { HandStrength = 3576; return HandStrength; }
					if (n7 == 1) { HandStrength = 3575; return HandStrength; }
					if (n6 == 1) { HandStrength = 3574; return HandStrength; }
					if (n5 == 1) { HandStrength = 3573; return HandStrength; }
					if (n4 == 1) { HandStrength = 3572; return HandStrength; }
					if (n2 == 1) { HandStrength = 3571; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3570; return HandStrength; }
					if (nT == 1) { HandStrength = 3569; return HandStrength; }
					if (n9 == 1) { HandStrength = 3568; return HandStrength; }
					if (n8 == 1) { HandStrength = 3567; return HandStrength; }
					if (n7 == 1) { HandStrength = 3566; return HandStrength; }
					if (n6 == 1) { HandStrength = 3565; return HandStrength; }
					if (n5 == 1) { HandStrength = 3564; return HandStrength; }
					if (n4 == 1) { HandStrength = 3563; return HandStrength; }
					if (n2 == 1) { HandStrength = 3562; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3561; return HandStrength; }
					if (n9 == 1) { HandStrength = 3560; return HandStrength; }
					if (n8 == 1) { HandStrength = 3559; return HandStrength; }
					if (n7 == 1) { HandStrength = 3558; return HandStrength; }
					if (n6 == 1) { HandStrength = 3557; return HandStrength; }
					if (n5 == 1) { HandStrength = 3556; return HandStrength; }
					if (n4 == 1) { HandStrength = 3555; return HandStrength; }
					if (n2 == 1) { HandStrength = 3554; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3553; return HandStrength; }
					if (n8 == 1) { HandStrength = 3552; return HandStrength; }
					if (n7 == 1) { HandStrength = 3551; return HandStrength; }
					if (n6 == 1) { HandStrength = 3550; return HandStrength; }
					if (n5 == 1) { HandStrength = 3549; return HandStrength; }
					if (n4 == 1) { HandStrength = 3548; return HandStrength; }
					if (n2 == 1) { HandStrength = 3547; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3546; return HandStrength; }
					if (n7 == 1) { HandStrength = 3545; return HandStrength; }
					if (n6 == 1) { HandStrength = 3544; return HandStrength; }
					if (n5 == 1) { HandStrength = 3543; return HandStrength; }
					if (n4 == 1) { HandStrength = 3542; return HandStrength; }
					if (n2 == 1) { HandStrength = 3541; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3540; return HandStrength; }
					if (n6 == 1) { HandStrength = 3539; return HandStrength; }
					if (n5 == 1) { HandStrength = 3538; return HandStrength; }
					if (n4 == 1) { HandStrength = 3537; return HandStrength; }
					if (n2 == 1) { HandStrength = 3536; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3535; return HandStrength; }
					if (n5 == 1) { HandStrength = 3534; return HandStrength; }
					if (n4 == 1) { HandStrength = 3533; return HandStrength; }
					if (n2 == 1) { HandStrength = 3532; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3531; return HandStrength; }
					if (n4 == 1) { HandStrength = 3530; return HandStrength; }
					if (n2 == 1) { HandStrength = 3529; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3528; return HandStrength; }
					if (n2 == 1) { HandStrength = 3527; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3526; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3525; return HandStrength; }
					if (nT == 1) { HandStrength = 3524; return HandStrength; }
					if (n9 == 1) { HandStrength = 3523; return HandStrength; }
					if (n8 == 1) { HandStrength = 3522; return HandStrength; }
					if (n7 == 1) { HandStrength = 3521; return HandStrength; }
					if (n6 == 1) { HandStrength = 3520; return HandStrength; }
					if (n5 == 1) { HandStrength = 3519; return HandStrength; }
					if (n4 == 1) { HandStrength = 3518; return HandStrength; }
					if (n2 == 1) { HandStrength = 3517; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3516; return HandStrength; }
					if (n9 == 1) { HandStrength = 3515; return HandStrength; }
					if (n8 == 1) { HandStrength = 3514; return HandStrength; }
					if (n7 == 1) { HandStrength = 3513; return HandStrength; }
					if (n6 == 1) { HandStrength = 3512; return HandStrength; }
					if (n5 == 1) { HandStrength = 3511; return HandStrength; }
					if (n4 == 1) { HandStrength = 3510; return HandStrength; }
					if (n2 == 1) { HandStrength = 3509; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3508; return HandStrength; }
					if (n8 == 1) { HandStrength = 3507; return HandStrength; }
					if (n7 == 1) { HandStrength = 3506; return HandStrength; }
					if (n6 == 1) { HandStrength = 3505; return HandStrength; }
					if (n5 == 1) { HandStrength = 3504; return HandStrength; }
					if (n4 == 1) { HandStrength = 3503; return HandStrength; }
					if (n2 == 1) { HandStrength = 3502; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3501; return HandStrength; }
					if (n7 == 1) { HandStrength = 3500; return HandStrength; }
					if (n6 == 1) { HandStrength = 3499; return HandStrength; }
					if (n5 == 1) { HandStrength = 3498; return HandStrength; }
					if (n4 == 1) { HandStrength = 3497; return HandStrength; }
					if (n2 == 1) { HandStrength = 3496; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3495; return HandStrength; }
					if (n6 == 1) { HandStrength = 3494; return HandStrength; }
					if (n5 == 1) { HandStrength = 3493; return HandStrength; }
					if (n4 == 1) { HandStrength = 3492; return HandStrength; }
					if (n2 == 1) { HandStrength = 3491; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3490; return HandStrength; }
					if (n5 == 1) { HandStrength = 3489; return HandStrength; }
					if (n4 == 1) { HandStrength = 3488; return HandStrength; }
					if (n2 == 1) { HandStrength = 3487; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3486; return HandStrength; }
					if (n4 == 1) { HandStrength = 3485; return HandStrength; }
					if (n2 == 1) { HandStrength = 3484; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3483; return HandStrength; }
					if (n2 == 1) { HandStrength = 3482; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3481; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3480; return HandStrength; }
					if (n9 == 1) { HandStrength = 3479; return HandStrength; }
					if (n8 == 1) { HandStrength = 3478; return HandStrength; }
					if (n7 == 1) { HandStrength = 3477; return HandStrength; }
					if (n6 == 1) { HandStrength = 3476; return HandStrength; }
					if (n5 == 1) { HandStrength = 3475; return HandStrength; }
					if (n4 == 1) { HandStrength = 3474; return HandStrength; }
					if (n2 == 1) { HandStrength = 3473; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3472; return HandStrength; }
					if (n8 == 1) { HandStrength = 3471; return HandStrength; }
					if (n7 == 1) { HandStrength = 3470; return HandStrength; }
					if (n6 == 1) { HandStrength = 3469; return HandStrength; }
					if (n5 == 1) { HandStrength = 3468; return HandStrength; }
					if (n4 == 1) { HandStrength = 3467; return HandStrength; }
					if (n2 == 1) { HandStrength = 3466; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3465; return HandStrength; }
					if (n7 == 1) { HandStrength = 3464; return HandStrength; }
					if (n6 == 1) { HandStrength = 3463; return HandStrength; }
					if (n5 == 1) { HandStrength = 3462; return HandStrength; }
					if (n4 == 1) { HandStrength = 3461; return HandStrength; }
					if (n2 == 1) { HandStrength = 3460; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3459; return HandStrength; }
					if (n6 == 1) { HandStrength = 3458; return HandStrength; }
					if (n5 == 1) { HandStrength = 3457; return HandStrength; }
					if (n4 == 1) { HandStrength = 3456; return HandStrength; }
					if (n2 == 1) { HandStrength = 3455; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3454; return HandStrength; }
					if (n5 == 1) { HandStrength = 3453; return HandStrength; }
					if (n4 == 1) { HandStrength = 3452; return HandStrength; }
					if (n2 == 1) { HandStrength = 3451; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3450; return HandStrength; }
					if (n4 == 1) { HandStrength = 3449; return HandStrength; }
					if (n2 == 1) { HandStrength = 3448; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3447; return HandStrength; }
					if (n2 == 1) { HandStrength = 3446; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3445; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3444; return HandStrength; }
					if (n8 == 1) { HandStrength = 3443; return HandStrength; }
					if (n7 == 1) { HandStrength = 3442; return HandStrength; }
					if (n6 == 1) { HandStrength = 3441; return HandStrength; }
					if (n5 == 1) { HandStrength = 3440; return HandStrength; }
					if (n4 == 1) { HandStrength = 3439; return HandStrength; }
					if (n2 == 1) { HandStrength = 3438; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3437; return HandStrength; }
					if (n7 == 1) { HandStrength = 3436; return HandStrength; }
					if (n6 == 1) { HandStrength = 3435; return HandStrength; }
					if (n5 == 1) { HandStrength = 3434; return HandStrength; }
					if (n4 == 1) { HandStrength = 3433; return HandStrength; }
					if (n2 == 1) { HandStrength = 3432; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3431; return HandStrength; }
					if (n6 == 1) { HandStrength = 3430; return HandStrength; }
					if (n5 == 1) { HandStrength = 3429; return HandStrength; }
					if (n4 == 1) { HandStrength = 3428; return HandStrength; }
					if (n2 == 1) { HandStrength = 3427; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3426; return HandStrength; }
					if (n5 == 1) { HandStrength = 3425; return HandStrength; }
					if (n4 == 1) { HandStrength = 3424; return HandStrength; }
					if (n2 == 1) { HandStrength = 3423; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3422; return HandStrength; }
					if (n4 == 1) { HandStrength = 3421; return HandStrength; }
					if (n2 == 1) { HandStrength = 3420; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3419; return HandStrength; }
					if (n2 == 1) { HandStrength = 3418; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3417; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3416; return HandStrength; }
					if (n7 == 1) { HandStrength = 3415; return HandStrength; }
					if (n6 == 1) { HandStrength = 3414; return HandStrength; }
					if (n5 == 1) { HandStrength = 3413; return HandStrength; }
					if (n4 == 1) { HandStrength = 3412; return HandStrength; }
					if (n2 == 1) { HandStrength = 3411; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3410; return HandStrength; }
					if (n6 == 1) { HandStrength = 3409; return HandStrength; }
					if (n5 == 1) { HandStrength = 3408; return HandStrength; }
					if (n4 == 1) { HandStrength = 3407; return HandStrength; }
					if (n2 == 1) { HandStrength = 3406; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3405; return HandStrength; }
					if (n5 == 1) { HandStrength = 3404; return HandStrength; }
					if (n4 == 1) { HandStrength = 3403; return HandStrength; }
					if (n2 == 1) { HandStrength = 3402; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3401; return HandStrength; }
					if (n4 == 1) { HandStrength = 3400; return HandStrength; }
					if (n2 == 1) { HandStrength = 3399; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3398; return HandStrength; }
					if (n2 == 1) { HandStrength = 3397; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3396; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3395; return HandStrength; }
					if (n6 == 1) { HandStrength = 3394; return HandStrength; }
					if (n5 == 1) { HandStrength = 3393; return HandStrength; }
					if (n4 == 1) { HandStrength = 3392; return HandStrength; }
					if (n2 == 1) { HandStrength = 3391; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3390; return HandStrength; }
					if (n5 == 1) { HandStrength = 3389; return HandStrength; }
					if (n4 == 1) { HandStrength = 3388; return HandStrength; }
					if (n2 == 1) { HandStrength = 3387; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3386; return HandStrength; }
					if (n4 == 1) { HandStrength = 3385; return HandStrength; }
					if (n2 == 1) { HandStrength = 3384; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3383; return HandStrength; }
					if (n2 == 1) { HandStrength = 3382; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3381; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3380; return HandStrength; }
					if (n5 == 1) { HandStrength = 3379; return HandStrength; }
					if (n4 == 1) { HandStrength = 3378; return HandStrength; }
					if (n2 == 1) { HandStrength = 3377; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3376; return HandStrength; }
					if (n4 == 1) { HandStrength = 3375; return HandStrength; }
					if (n2 == 1) { HandStrength = 3374; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3373; return HandStrength; }
					if (n2 == 1) { HandStrength = 3372; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3371; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3370; return HandStrength; }
					if (n4 == 1) { HandStrength = 3369; return HandStrength; }
					if (n2 == 1) { HandStrength = 3368; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3367; return HandStrength; }
					if (n2 == 1) { HandStrength = 3366; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3365; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3364; return HandStrength; }
					if (n2 == 1) { HandStrength = 3363; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3362; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = 3361; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n2 == 3) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 3360; return HandStrength; }
					if (nJ == 1) { HandStrength = 3359; return HandStrength; }
					if (nT == 1) { HandStrength = 3358; return HandStrength; }
					if (n9 == 1) { HandStrength = 3357; return HandStrength; }
					if (n8 == 1) { HandStrength = 3356; return HandStrength; }
					if (n7 == 1) { HandStrength = 3355; return HandStrength; }
					if (n6 == 1) { HandStrength = 3354; return HandStrength; }
					if (n5 == 1) { HandStrength = 3353; return HandStrength; }
					if (n4 == 1) { HandStrength = 3352; return HandStrength; }
					if (n3 == 1) { HandStrength = 3351; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3350; return HandStrength; }
					if (nT == 1) { HandStrength = 3349; return HandStrength; }
					if (n9 == 1) { HandStrength = 3348; return HandStrength; }
					if (n8 == 1) { HandStrength = 3347; return HandStrength; }
					if (n7 == 1) { HandStrength = 3346; return HandStrength; }
					if (n6 == 1) { HandStrength = 3345; return HandStrength; }
					if (n5 == 1) { HandStrength = 3344; return HandStrength; }
					if (n4 == 1) { HandStrength = 3343; return HandStrength; }
					if (n3 == 1) { HandStrength = 3342; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3341; return HandStrength; }
					if (n9 == 1) { HandStrength = 3340; return HandStrength; }
					if (n8 == 1) { HandStrength = 3339; return HandStrength; }
					if (n7 == 1) { HandStrength = 3338; return HandStrength; }
					if (n6 == 1) { HandStrength = 3337; return HandStrength; }
					if (n5 == 1) { HandStrength = 3336; return HandStrength; }
					if (n4 == 1) { HandStrength = 3335; return HandStrength; }
					if (n3 == 1) { HandStrength = 3334; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3333; return HandStrength; }
					if (n8 == 1) { HandStrength = 3332; return HandStrength; }
					if (n7 == 1) { HandStrength = 3331; return HandStrength; }
					if (n6 == 1) { HandStrength = 3330; return HandStrength; }
					if (n5 == 1) { HandStrength = 3329; return HandStrength; }
					if (n4 == 1) { HandStrength = 3328; return HandStrength; }
					if (n3 == 1) { HandStrength = 3327; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3326; return HandStrength; }
					if (n7 == 1) { HandStrength = 3325; return HandStrength; }
					if (n6 == 1) { HandStrength = 3324; return HandStrength; }
					if (n5 == 1) { HandStrength = 3323; return HandStrength; }
					if (n4 == 1) { HandStrength = 3322; return HandStrength; }
					if (n3 == 1) { HandStrength = 3321; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3320; return HandStrength; }
					if (n6 == 1) { HandStrength = 3319; return HandStrength; }
					if (n5 == 1) { HandStrength = 3318; return HandStrength; }
					if (n4 == 1) { HandStrength = 3317; return HandStrength; }
					if (n3 == 1) { HandStrength = 3316; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3315; return HandStrength; }
					if (n5 == 1) { HandStrength = 3314; return HandStrength; }
					if (n4 == 1) { HandStrength = 3313; return HandStrength; }
					if (n3 == 1) { HandStrength = 3312; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3311; return HandStrength; }
					if (n4 == 1) { HandStrength = 3310; return HandStrength; }
					if (n3 == 1) { HandStrength = 3309; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3308; return HandStrength; }
					if (n3 == 1) { HandStrength = 3307; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3306; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 3305; return HandStrength; }
					if (nT == 1) { HandStrength = 3304; return HandStrength; }
					if (n9 == 1) { HandStrength = 3303; return HandStrength; }
					if (n8 == 1) { HandStrength = 3302; return HandStrength; }
					if (n7 == 1) { HandStrength = 3301; return HandStrength; }
					if (n6 == 1) { HandStrength = 3300; return HandStrength; }
					if (n5 == 1) { HandStrength = 3299; return HandStrength; }
					if (n4 == 1) { HandStrength = 3298; return HandStrength; }
					if (n3 == 1) { HandStrength = 3297; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3296; return HandStrength; }
					if (n9 == 1) { HandStrength = 3295; return HandStrength; }
					if (n8 == 1) { HandStrength = 3294; return HandStrength; }
					if (n7 == 1) { HandStrength = 3293; return HandStrength; }
					if (n6 == 1) { HandStrength = 3292; return HandStrength; }
					if (n5 == 1) { HandStrength = 3291; return HandStrength; }
					if (n4 == 1) { HandStrength = 3290; return HandStrength; }
					if (n3 == 1) { HandStrength = 3289; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3288; return HandStrength; }
					if (n8 == 1) { HandStrength = 3287; return HandStrength; }
					if (n7 == 1) { HandStrength = 3286; return HandStrength; }
					if (n6 == 1) { HandStrength = 3285; return HandStrength; }
					if (n5 == 1) { HandStrength = 3284; return HandStrength; }
					if (n4 == 1) { HandStrength = 3283; return HandStrength; }
					if (n3 == 1) { HandStrength = 3282; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3281; return HandStrength; }
					if (n7 == 1) { HandStrength = 3280; return HandStrength; }
					if (n6 == 1) { HandStrength = 3279; return HandStrength; }
					if (n5 == 1) { HandStrength = 3278; return HandStrength; }
					if (n4 == 1) { HandStrength = 3277; return HandStrength; }
					if (n3 == 1) { HandStrength = 3276; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3275; return HandStrength; }
					if (n6 == 1) { HandStrength = 3274; return HandStrength; }
					if (n5 == 1) { HandStrength = 3273; return HandStrength; }
					if (n4 == 1) { HandStrength = 3272; return HandStrength; }
					if (n3 == 1) { HandStrength = 3271; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3270; return HandStrength; }
					if (n5 == 1) { HandStrength = 3269; return HandStrength; }
					if (n4 == 1) { HandStrength = 3268; return HandStrength; }
					if (n3 == 1) { HandStrength = 3267; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3266; return HandStrength; }
					if (n4 == 1) { HandStrength = 3265; return HandStrength; }
					if (n3 == 1) { HandStrength = 3264; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3263; return HandStrength; }
					if (n3 == 1) { HandStrength = 3262; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3261; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 3260; return HandStrength; }
					if (n9 == 1) { HandStrength = 3259; return HandStrength; }
					if (n8 == 1) { HandStrength = 3258; return HandStrength; }
					if (n7 == 1) { HandStrength = 3257; return HandStrength; }
					if (n6 == 1) { HandStrength = 3256; return HandStrength; }
					if (n5 == 1) { HandStrength = 3255; return HandStrength; }
					if (n4 == 1) { HandStrength = 3254; return HandStrength; }
					if (n3 == 1) { HandStrength = 3253; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3252; return HandStrength; }
					if (n8 == 1) { HandStrength = 3251; return HandStrength; }
					if (n7 == 1) { HandStrength = 3250; return HandStrength; }
					if (n6 == 1) { HandStrength = 3249; return HandStrength; }
					if (n5 == 1) { HandStrength = 3248; return HandStrength; }
					if (n4 == 1) { HandStrength = 3247; return HandStrength; }
					if (n3 == 1) { HandStrength = 3246; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3245; return HandStrength; }
					if (n7 == 1) { HandStrength = 3244; return HandStrength; }
					if (n6 == 1) { HandStrength = 3243; return HandStrength; }
					if (n5 == 1) { HandStrength = 3242; return HandStrength; }
					if (n4 == 1) { HandStrength = 3241; return HandStrength; }
					if (n3 == 1) { HandStrength = 3240; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3239; return HandStrength; }
					if (n6 == 1) { HandStrength = 3238; return HandStrength; }
					if (n5 == 1) { HandStrength = 3237; return HandStrength; }
					if (n4 == 1) { HandStrength = 3236; return HandStrength; }
					if (n3 == 1) { HandStrength = 3235; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3234; return HandStrength; }
					if (n5 == 1) { HandStrength = 3233; return HandStrength; }
					if (n4 == 1) { HandStrength = 3232; return HandStrength; }
					if (n3 == 1) { HandStrength = 3231; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3230; return HandStrength; }
					if (n4 == 1) { HandStrength = 3229; return HandStrength; }
					if (n3 == 1) { HandStrength = 3228; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3227; return HandStrength; }
					if (n3 == 1) { HandStrength = 3226; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3225; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 3224; return HandStrength; }
					if (n8 == 1) { HandStrength = 3223; return HandStrength; }
					if (n7 == 1) { HandStrength = 3222; return HandStrength; }
					if (n6 == 1) { HandStrength = 3221; return HandStrength; }
					if (n5 == 1) { HandStrength = 3220; return HandStrength; }
					if (n4 == 1) { HandStrength = 3219; return HandStrength; }
					if (n3 == 1) { HandStrength = 3218; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3217; return HandStrength; }
					if (n7 == 1) { HandStrength = 3216; return HandStrength; }
					if (n6 == 1) { HandStrength = 3215; return HandStrength; }
					if (n5 == 1) { HandStrength = 3214; return HandStrength; }
					if (n4 == 1) { HandStrength = 3213; return HandStrength; }
					if (n3 == 1) { HandStrength = 3212; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3211; return HandStrength; }
					if (n6 == 1) { HandStrength = 3210; return HandStrength; }
					if (n5 == 1) { HandStrength = 3209; return HandStrength; }
					if (n4 == 1) { HandStrength = 3208; return HandStrength; }
					if (n3 == 1) { HandStrength = 3207; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3206; return HandStrength; }
					if (n5 == 1) { HandStrength = 3205; return HandStrength; }
					if (n4 == 1) { HandStrength = 3204; return HandStrength; }
					if (n3 == 1) { HandStrength = 3203; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3202; return HandStrength; }
					if (n4 == 1) { HandStrength = 3201; return HandStrength; }
					if (n3 == 1) { HandStrength = 3200; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3199; return HandStrength; }
					if (n3 == 1) { HandStrength = 3198; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3197; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 3196; return HandStrength; }
					if (n7 == 1) { HandStrength = 3195; return HandStrength; }
					if (n6 == 1) { HandStrength = 3194; return HandStrength; }
					if (n5 == 1) { HandStrength = 3193; return HandStrength; }
					if (n4 == 1) { HandStrength = 3192; return HandStrength; }
					if (n3 == 1) { HandStrength = 3191; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3190; return HandStrength; }
					if (n6 == 1) { HandStrength = 3189; return HandStrength; }
					if (n5 == 1) { HandStrength = 3188; return HandStrength; }
					if (n4 == 1) { HandStrength = 3187; return HandStrength; }
					if (n3 == 1) { HandStrength = 3186; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3185; return HandStrength; }
					if (n5 == 1) { HandStrength = 3184; return HandStrength; }
					if (n4 == 1) { HandStrength = 3183; return HandStrength; }
					if (n3 == 1) { HandStrength = 3182; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3181; return HandStrength; }
					if (n4 == 1) { HandStrength = 3180; return HandStrength; }
					if (n3 == 1) { HandStrength = 3179; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3178; return HandStrength; }
					if (n3 == 1) { HandStrength = 3177; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3176; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 3175; return HandStrength; }
					if (n6 == 1) { HandStrength = 3174; return HandStrength; }
					if (n5 == 1) { HandStrength = 3173; return HandStrength; }
					if (n4 == 1) { HandStrength = 3172; return HandStrength; }
					if (n3 == 1) { HandStrength = 3171; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3170; return HandStrength; }
					if (n5 == 1) { HandStrength = 3169; return HandStrength; }
					if (n4 == 1) { HandStrength = 3168; return HandStrength; }
					if (n3 == 1) { HandStrength = 3167; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3166; return HandStrength; }
					if (n4 == 1) { HandStrength = 3165; return HandStrength; }
					if (n3 == 1) { HandStrength = 3164; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3163; return HandStrength; }
					if (n3 == 1) { HandStrength = 3162; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3161; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 3160; return HandStrength; }
					if (n5 == 1) { HandStrength = 3159; return HandStrength; }
					if (n4 == 1) { HandStrength = 3158; return HandStrength; }
					if (n3 == 1) { HandStrength = 3157; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3156; return HandStrength; }
					if (n4 == 1) { HandStrength = 3155; return HandStrength; }
					if (n3 == 1) { HandStrength = 3154; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3153; return HandStrength; }
					if (n3 == 1) { HandStrength = 3152; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3151; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 3150; return HandStrength; }
					if (n4 == 1) { HandStrength = 3149; return HandStrength; }
					if (n3 == 1) { HandStrength = 3148; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3147; return HandStrength; }
					if (n3 == 1) { HandStrength = 3146; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3145; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 3144; return HandStrength; }
					if (n3 == 1) { HandStrength = 3143; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3142; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 3141; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
				};
			};
			if (n3 == 1) {
			};
		};


	};
	//TwoPair
	if (nPairs >= 2) {
		HandStrength = 3000;
		if (CheckKicker == false) { return HandStrength; };

		if (nA == 2) {
			if (nK == 2) {
				if (nQ == 1) { HandStrength = 3000; return HandStrength; }
				if (nJ == 1) { HandStrength = 2999; return HandStrength; }
				if (nT == 1) { HandStrength = 2998; return HandStrength; }
				if (n9 == 1) { HandStrength = 2997; return HandStrength; }
				if (n8 == 1) { HandStrength = 2996; return HandStrength; }
				if (n7 == 1) { HandStrength = 2995; return HandStrength; }
				if (n6 == 1) { HandStrength = 2994; return HandStrength; }
				if (n5 == 1) { HandStrength = 2993; return HandStrength; }
				if (n4 == 1) { HandStrength = 2992; return HandStrength; }
				if (n3 == 1) { HandStrength = 2991; return HandStrength; }
				if (n2 == 1) { HandStrength = 2990; return HandStrength; }
			};
			if (nQ == 2) {
				if (nK == 1) { HandStrength = 2989; return HandStrength; }
				if (nJ == 1) { HandStrength = 2988; return HandStrength; }
				if (nT == 1) { HandStrength = 2987; return HandStrength; }
				if (n9 == 1) { HandStrength = 2986; return HandStrength; }
				if (n8 == 1) { HandStrength = 2985; return HandStrength; }
				if (n7 == 1) { HandStrength = 2984; return HandStrength; }
				if (n6 == 1) { HandStrength = 2983; return HandStrength; }
				if (n5 == 1) { HandStrength = 2982; return HandStrength; }
				if (n4 == 1) { HandStrength = 2981; return HandStrength; }
				if (n3 == 1) { HandStrength = 2980; return HandStrength; }
				if (n2 == 1) { HandStrength = 2979; return HandStrength; }
			};
			if (nJ == 2) {
				if (nK == 1) { HandStrength = 2978; return HandStrength; }
				if (nQ == 1) { HandStrength = 2977; return HandStrength; }
				if (nT == 1) { HandStrength = 2976; return HandStrength; }
				if (n9 == 1) { HandStrength = 2975; return HandStrength; }
				if (n8 == 1) { HandStrength = 2974; return HandStrength; }
				if (n7 == 1) { HandStrength = 2973; return HandStrength; }
				if (n6 == 1) { HandStrength = 2972; return HandStrength; }
				if (n5 == 1) { HandStrength = 2971; return HandStrength; }
				if (n4 == 1) { HandStrength = 2970; return HandStrength; }
				if (n3 == 1) { HandStrength = 2969; return HandStrength; }
				if (n2 == 1) { HandStrength = 2968; return HandStrength; }
			};
			if (nT == 2) {
				if (nK == 1) { HandStrength = 2967; return HandStrength; }
				if (nQ == 1) { HandStrength = 2966; return HandStrength; }
				if (nJ == 1) { HandStrength = 2965; return HandStrength; }
				if (n9 == 1) { HandStrength = 2964; return HandStrength; }
				if (n8 == 1) { HandStrength = 2963; return HandStrength; }
				if (n7 == 1) { HandStrength = 2962; return HandStrength; }
				if (n6 == 1) { HandStrength = 2961; return HandStrength; }
				if (n5 == 1) { HandStrength = 2960; return HandStrength; }
				if (n4 == 1) { HandStrength = 2959; return HandStrength; }
				if (n3 == 1) { HandStrength = 2958; return HandStrength; }
				if (n2 == 1) { HandStrength = 2957; return HandStrength; }
			};
			if (n9 == 2) {
				if (nK == 1) { HandStrength = 2956; return HandStrength; }
				if (nQ == 1) { HandStrength = 2955; return HandStrength; }
				if (nJ == 1) { HandStrength = 2954; return HandStrength; }
				if (nT == 1) { HandStrength = 2953; return HandStrength; }
				if (n8 == 1) { HandStrength = 2952; return HandStrength; }
				if (n7 == 1) { HandStrength = 2951; return HandStrength; }
				if (n6 == 1) { HandStrength = 2950; return HandStrength; }
				if (n5 == 1) { HandStrength = 2949; return HandStrength; }
				if (n4 == 1) { HandStrength = 2948; return HandStrength; }
				if (n3 == 1) { HandStrength = 2947; return HandStrength; }
				if (n2 == 1) { HandStrength = 2946; return HandStrength; }
			};
			if (n8 == 2) {
				if (nK == 1) { HandStrength = 2945; return HandStrength; }
				if (nQ == 1) { HandStrength = 2944; return HandStrength; }
				if (nJ == 1) { HandStrength = 2943; return HandStrength; }
				if (nT == 1) { HandStrength = 2942; return HandStrength; }
				if (n9 == 1) { HandStrength = 2941; return HandStrength; }
				if (n7 == 1) { HandStrength = 2940; return HandStrength; }
				if (n6 == 1) { HandStrength = 2939; return HandStrength; }
				if (n5 == 1) { HandStrength = 2938; return HandStrength; }
				if (n4 == 1) { HandStrength = 2937; return HandStrength; }
				if (n3 == 1) { HandStrength = 2936; return HandStrength; }
				if (n2 == 1) { HandStrength = 2935; return HandStrength; }
			};
			if (n7 == 2) {
				if (nK == 1) { HandStrength = 2934; return HandStrength; }
				if (nQ == 1) { HandStrength = 2933; return HandStrength; }
				if (nJ == 1) { HandStrength = 2932; return HandStrength; }
				if (nT == 1) { HandStrength = 2931; return HandStrength; }
				if (n9 == 1) { HandStrength = 2930; return HandStrength; }
				if (n8 == 1) { HandStrength = 2929; return HandStrength; }
				if (n6 == 1) { HandStrength = 2928; return HandStrength; }
				if (n5 == 1) { HandStrength = 2927; return HandStrength; }
				if (n4 == 1) { HandStrength = 2926; return HandStrength; }
				if (n3 == 1) { HandStrength = 2925; return HandStrength; }
				if (n2 == 1) { HandStrength = 2924; return HandStrength; }
			};
			if (n6 == 2) {
				if (nK == 1) { HandStrength = 2923; return HandStrength; }
				if (nQ == 1) { HandStrength = 2922; return HandStrength; }
				if (nJ == 1) { HandStrength = 2921; return HandStrength; }
				if (nT == 1) { HandStrength = 2920; return HandStrength; }
				if (n9 == 1) { HandStrength = 2919; return HandStrength; }
				if (n8 == 1) { HandStrength = 2918; return HandStrength; }
				if (n7 == 1) { HandStrength = 2917; return HandStrength; }
				if (n5 == 1) { HandStrength = 2916; return HandStrength; }
				if (n4 == 1) { HandStrength = 2915; return HandStrength; }
				if (n3 == 1) { HandStrength = 2914; return HandStrength; }
				if (n2 == 1) { HandStrength = 2913; return HandStrength; }
			};
			if (n5 == 2) {
				if (nK == 1) { HandStrength = 2912; return HandStrength; }
				if (nQ == 1) { HandStrength = 2911; return HandStrength; }
				if (nJ == 1) { HandStrength = 2910; return HandStrength; }
				if (nT == 1) { HandStrength = 2909; return HandStrength; }
				if (n9 == 1) { HandStrength = 2908; return HandStrength; }
				if (n8 == 1) { HandStrength = 2907; return HandStrength; }
				if (n7 == 1) { HandStrength = 2906; return HandStrength; }
				if (n6 == 1) { HandStrength = 2905; return HandStrength; }
				if (n4 == 1) { HandStrength = 2904; return HandStrength; }
				if (n3 == 1) { HandStrength = 2903; return HandStrength; }
				if (n2 == 1) { HandStrength = 2902; return HandStrength; }
			};
			if (n4 == 2) {
				if (nK == 1) { HandStrength = 2901; return HandStrength; }
				if (nQ == 1) { HandStrength = 2900; return HandStrength; }
				if (nJ == 1) { HandStrength = 2899; return HandStrength; }
				if (nT == 1) { HandStrength = 2898; return HandStrength; }
				if (n9 == 1) { HandStrength = 2897; return HandStrength; }
				if (n8 == 1) { HandStrength = 2896; return HandStrength; }
				if (n7 == 1) { HandStrength = 2895; return HandStrength; }
				if (n6 == 1) { HandStrength = 2894; return HandStrength; }
				if (n5 == 1) { HandStrength = 2893; return HandStrength; }
				if (n3 == 1) { HandStrength = 2892; return HandStrength; }
				if (n2 == 1) { HandStrength = 2891; return HandStrength; }
			};
			if (n3 == 2) {
				if (nK == 1) { HandStrength = 2890; return HandStrength; }
				if (nQ == 1) { HandStrength = 2889; return HandStrength; }
				if (nJ == 1) { HandStrength = 2888; return HandStrength; }
				if (nT == 1) { HandStrength = 2887; return HandStrength; }
				if (n9 == 1) { HandStrength = 2886; return HandStrength; }
				if (n8 == 1) { HandStrength = 2885; return HandStrength; }
				if (n7 == 1) { HandStrength = 2884; return HandStrength; }
				if (n6 == 1) { HandStrength = 2883; return HandStrength; }
				if (n5 == 1) { HandStrength = 2882; return HandStrength; }
				if (n4 == 1) { HandStrength = 2881; return HandStrength; }
				if (n2 == 1) { HandStrength = 2880; return HandStrength; }
			};
			if (n2 == 2) {
				if (nK == 1) { HandStrength = 2879; return HandStrength; }
				if (nQ == 1) { HandStrength = 2878; return HandStrength; }
				if (nJ == 1) { HandStrength = 2877; return HandStrength; }
				if (nT == 1) { HandStrength = 2876; return HandStrength; }
				if (n9 == 1) { HandStrength = 2875; return HandStrength; }
				if (n8 == 1) { HandStrength = 2874; return HandStrength; }
				if (n7 == 1) { HandStrength = 2873; return HandStrength; }
				if (n6 == 1) { HandStrength = 2872; return HandStrength; }
				if (n5 == 1) { HandStrength = 2871; return HandStrength; }
				if (n4 == 1) { HandStrength = 2870; return HandStrength; }
				if (n3 == 1) { HandStrength = 2869; return HandStrength; }
			};
		};
		if (nK == 2) {
			if (nQ == 2) {
				if (nA == 1) { HandStrength = 2868; return HandStrength; }
				if (nJ == 1) { HandStrength = 2867; return HandStrength; }
				if (nT == 1) { HandStrength = 2866; return HandStrength; }
				if (n9 == 1) { HandStrength = 2865; return HandStrength; }
				if (n8 == 1) { HandStrength = 2864; return HandStrength; }
				if (n7 == 1) { HandStrength = 2863; return HandStrength; }
				if (n6 == 1) { HandStrength = 2862; return HandStrength; }
				if (n5 == 1) { HandStrength = 2861; return HandStrength; }
				if (n4 == 1) { HandStrength = 2860; return HandStrength; }
				if (n3 == 1) { HandStrength = 2859; return HandStrength; }
				if (n2 == 1) { HandStrength = 2858; return HandStrength; }
			};
			if (nJ == 2) {
				if (nA == 1) { HandStrength = 2857; return HandStrength; }
				if (nQ == 1) { HandStrength = 2856; return HandStrength; }
				if (nT == 1) { HandStrength = 2855; return HandStrength; }
				if (n9 == 1) { HandStrength = 2854; return HandStrength; }
				if (n8 == 1) { HandStrength = 2853; return HandStrength; }
				if (n7 == 1) { HandStrength = 2852; return HandStrength; }
				if (n6 == 1) { HandStrength = 2851; return HandStrength; }
				if (n5 == 1) { HandStrength = 2850; return HandStrength; }
				if (n4 == 1) { HandStrength = 2849; return HandStrength; }
				if (n3 == 1) { HandStrength = 2848; return HandStrength; }
				if (n2 == 1) { HandStrength = 2847; return HandStrength; }
			};
			if (nT == 2) {
				if (nA == 1) { HandStrength = 2846; return HandStrength; }
				if (nQ == 1) { HandStrength = 2845; return HandStrength; }
				if (nJ == 1) { HandStrength = 2844; return HandStrength; }
				if (n9 == 1) { HandStrength = 2843; return HandStrength; }
				if (n8 == 1) { HandStrength = 2842; return HandStrength; }
				if (n7 == 1) { HandStrength = 2841; return HandStrength; }
				if (n6 == 1) { HandStrength = 2840; return HandStrength; }
				if (n5 == 1) { HandStrength = 2839; return HandStrength; }
				if (n4 == 1) { HandStrength = 2838; return HandStrength; }
				if (n3 == 1) { HandStrength = 2837; return HandStrength; }
				if (n2 == 1) { HandStrength = 2836; return HandStrength; }
			};
			if (n9 == 2) {
				if (nA == 1) { HandStrength = 2835; return HandStrength; }
				if (nQ == 1) { HandStrength = 2834; return HandStrength; }
				if (nJ == 1) { HandStrength = 2833; return HandStrength; }
				if (nT == 1) { HandStrength = 2832; return HandStrength; }
				if (n8 == 1) { HandStrength = 2831; return HandStrength; }
				if (n7 == 1) { HandStrength = 2830; return HandStrength; }
				if (n6 == 1) { HandStrength = 2829; return HandStrength; }
				if (n5 == 1) { HandStrength = 2828; return HandStrength; }
				if (n4 == 1) { HandStrength = 2827; return HandStrength; }
				if (n3 == 1) { HandStrength = 2826; return HandStrength; }
				if (n2 == 1) { HandStrength = 2825; return HandStrength; }
			};
			if (n8 == 2) {
				if (nA == 1) { HandStrength = 2824; return HandStrength; }
				if (nQ == 1) { HandStrength = 2823; return HandStrength; }
				if (nJ == 1) { HandStrength = 2822; return HandStrength; }
				if (nT == 1) { HandStrength = 2821; return HandStrength; }
				if (n9 == 1) { HandStrength = 2820; return HandStrength; }
				if (n7 == 1) { HandStrength = 2819; return HandStrength; }
				if (n6 == 1) { HandStrength = 2818; return HandStrength; }
				if (n5 == 1) { HandStrength = 2817; return HandStrength; }
				if (n4 == 1) { HandStrength = 2816; return HandStrength; }
				if (n3 == 1) { HandStrength = 2815; return HandStrength; }
				if (n2 == 1) { HandStrength = 2814; return HandStrength; }
			};
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2813; return HandStrength; }
				if (nQ == 1) { HandStrength = 2812; return HandStrength; }
				if (nJ == 1) { HandStrength = 2811; return HandStrength; }
				if (nT == 1) { HandStrength = 2810; return HandStrength; }
				if (n9 == 1) { HandStrength = 2809; return HandStrength; }
				if (n8 == 1) { HandStrength = 2808; return HandStrength; }
				if (n6 == 1) { HandStrength = 2807; return HandStrength; }
				if (n5 == 1) { HandStrength = 2806; return HandStrength; }
				if (n4 == 1) { HandStrength = 2805; return HandStrength; }
				if (n3 == 1) { HandStrength = 2804; return HandStrength; }
				if (n2 == 1) { HandStrength = 2803; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2802; return HandStrength; }
				if (nQ == 1) { HandStrength = 2801; return HandStrength; }
				if (nJ == 1) { HandStrength = 2800; return HandStrength; }
				if (nT == 1) { HandStrength = 2799; return HandStrength; }
				if (n9 == 1) { HandStrength = 2798; return HandStrength; }
				if (n8 == 1) { HandStrength = 2797; return HandStrength; }
				if (n7 == 1) { HandStrength = 2796; return HandStrength; }
				if (n5 == 1) { HandStrength = 2795; return HandStrength; }
				if (n4 == 1) { HandStrength = 2794; return HandStrength; }
				if (n3 == 1) { HandStrength = 2793; return HandStrength; }
				if (n2 == 1) { HandStrength = 2792; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2791; return HandStrength; }
				if (nQ == 1) { HandStrength = 2790; return HandStrength; }
				if (nJ == 1) { HandStrength = 2789; return HandStrength; }
				if (nT == 1) { HandStrength = 2788; return HandStrength; }
				if (n9 == 1) { HandStrength = 2787; return HandStrength; }
				if (n8 == 1) { HandStrength = 2786; return HandStrength; }
				if (n7 == 1) { HandStrength = 2785; return HandStrength; }
				if (n6 == 1) { HandStrength = 2784; return HandStrength; }
				if (n4 == 1) { HandStrength = 2783; return HandStrength; }
				if (n3 == 1) { HandStrength = 2782; return HandStrength; }
				if (n2 == 1) { HandStrength = 2781; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2780; return HandStrength; }
				if (nQ == 1) { HandStrength = 2779; return HandStrength; }
				if (nJ == 1) { HandStrength = 2778; return HandStrength; }
				if (nT == 1) { HandStrength = 2777; return HandStrength; }
				if (n9 == 1) { HandStrength = 2776; return HandStrength; }
				if (n8 == 1) { HandStrength = 2775; return HandStrength; }
				if (n7 == 1) { HandStrength = 2774; return HandStrength; }
				if (n6 == 1) { HandStrength = 2773; return HandStrength; }
				if (n5 == 1) { HandStrength = 2772; return HandStrength; }
				if (n3 == 1) { HandStrength = 2771; return HandStrength; }
				if (n2 == 1) { HandStrength = 2770; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2769; return HandStrength; }
				if (nQ == 1) { HandStrength = 2768; return HandStrength; }
				if (nJ == 1) { HandStrength = 2767; return HandStrength; }
				if (nT == 1) { HandStrength = 2766; return HandStrength; }
				if (n9 == 1) { HandStrength = 2765; return HandStrength; }
				if (n8 == 1) { HandStrength = 2764; return HandStrength; }
				if (n7 == 1) { HandStrength = 2763; return HandStrength; }
				if (n6 == 1) { HandStrength = 2762; return HandStrength; }
				if (n5 == 1) { HandStrength = 2761; return HandStrength; }
				if (n4 == 1) { HandStrength = 2760; return HandStrength; }
				if (n2 == 1) { HandStrength = 2759; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2758; return HandStrength; }
				if (nQ == 1) { HandStrength = 2757; return HandStrength; }
				if (nJ == 1) { HandStrength = 2756; return HandStrength; }
				if (nT == 1) { HandStrength = 2755; return HandStrength; }
				if (n9 == 1) { HandStrength = 2754; return HandStrength; }
				if (n8 == 1) { HandStrength = 2753; return HandStrength; }
				if (n7 == 1) { HandStrength = 2752; return HandStrength; }
				if (n6 == 1) { HandStrength = 2751; return HandStrength; }
				if (n5 == 1) { HandStrength = 2750; return HandStrength; }
				if (n4 == 1) { HandStrength = 2749; return HandStrength; }
				if (n3 == 1) { HandStrength = 2748; return HandStrength; }
			};
		};
		if (nQ == 2) {
			if (nJ == 2) {
				if (nA == 1) { HandStrength = 2747; return HandStrength; }
				if (nK == 1) { HandStrength = 2746; return HandStrength; }
				if (nT == 1) { HandStrength = 2745; return HandStrength; }
				if (n9 == 1) { HandStrength = 2744; return HandStrength; }
				if (n8 == 1) { HandStrength = 2743; return HandStrength; }
				if (n7 == 1) { HandStrength = 2742; return HandStrength; }
				if (n6 == 1) { HandStrength = 2741; return HandStrength; }
				if (n5 == 1) { HandStrength = 2740; return HandStrength; }
				if (n4 == 1) { HandStrength = 2739; return HandStrength; }
				if (n3 == 1) { HandStrength = 2738; return HandStrength; }
				if (n2 == 1) { HandStrength = 2737; return HandStrength; }
			};
			if (nT == 2) {
				if (nA == 1) { HandStrength = 2736; return HandStrength; }
				if (nK == 1) { HandStrength = 2735; return HandStrength; }
				if (nJ == 1) { HandStrength = 2734; return HandStrength; }
				if (n9 == 1) { HandStrength = 2733; return HandStrength; }
				if (n8 == 1) { HandStrength = 2732; return HandStrength; }
				if (n7 == 1) { HandStrength = 2731; return HandStrength; }
				if (n6 == 1) { HandStrength = 2730; return HandStrength; }
				if (n5 == 1) { HandStrength = 2729; return HandStrength; }
				if (n4 == 1) { HandStrength = 2728; return HandStrength; }
				if (n3 == 1) { HandStrength = 2727; return HandStrength; }
				if (n2 == 1) { HandStrength = 2726; return HandStrength; }
			};
			if (n9 == 2) {
				if (nA == 1) { HandStrength = 2725; return HandStrength; }
				if (nK == 1) { HandStrength = 2724; return HandStrength; }
				if (nJ == 1) { HandStrength = 2723; return HandStrength; }
				if (nT == 1) { HandStrength = 2722; return HandStrength; }
				if (n8 == 1) { HandStrength = 2721; return HandStrength; }
				if (n7 == 1) { HandStrength = 2720; return HandStrength; }
				if (n6 == 1) { HandStrength = 2719; return HandStrength; }
				if (n5 == 1) { HandStrength = 2718; return HandStrength; }
				if (n4 == 1) { HandStrength = 2717; return HandStrength; }
				if (n3 == 1) { HandStrength = 2716; return HandStrength; }
				if (n2 == 1) { HandStrength = 2715; return HandStrength; }
			};
			if (n8 == 2) {
				if (nA == 1) { HandStrength = 2714; return HandStrength; }
				if (nK == 1) { HandStrength = 2713; return HandStrength; }
				if (nJ == 1) { HandStrength = 2712; return HandStrength; }
				if (nT == 1) { HandStrength = 2711; return HandStrength; }
				if (n9 == 1) { HandStrength = 2710; return HandStrength; }
				if (n7 == 1) { HandStrength = 2709; return HandStrength; }
				if (n6 == 1) { HandStrength = 2708; return HandStrength; }
				if (n5 == 1) { HandStrength = 2707; return HandStrength; }
				if (n4 == 1) { HandStrength = 2706; return HandStrength; }
				if (n3 == 1) { HandStrength = 2705; return HandStrength; }
				if (n2 == 1) { HandStrength = 2704; return HandStrength; }
			};
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2703; return HandStrength; }
				if (nK == 1) { HandStrength = 2702; return HandStrength; }
				if (nJ == 1) { HandStrength = 2701; return HandStrength; }
				if (nT == 1) { HandStrength = 2700; return HandStrength; }
				if (n9 == 1) { HandStrength = 2699; return HandStrength; }
				if (n8 == 1) { HandStrength = 2698; return HandStrength; }
				if (n6 == 1) { HandStrength = 2697; return HandStrength; }
				if (n5 == 1) { HandStrength = 2696; return HandStrength; }
				if (n4 == 1) { HandStrength = 2695; return HandStrength; }
				if (n3 == 1) { HandStrength = 2694; return HandStrength; }
				if (n2 == 1) { HandStrength = 2693; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2692; return HandStrength; }
				if (nK == 1) { HandStrength = 2691; return HandStrength; }
				if (nJ == 1) { HandStrength = 2690; return HandStrength; }
				if (nT == 1) { HandStrength = 2689; return HandStrength; }
				if (n9 == 1) { HandStrength = 2688; return HandStrength; }
				if (n8 == 1) { HandStrength = 2687; return HandStrength; }
				if (n7 == 1) { HandStrength = 2686; return HandStrength; }
				if (n5 == 1) { HandStrength = 2685; return HandStrength; }
				if (n4 == 1) { HandStrength = 2684; return HandStrength; }
				if (n3 == 1) { HandStrength = 2683; return HandStrength; }
				if (n2 == 1) { HandStrength = 2682; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2681; return HandStrength; }
				if (nK == 1) { HandStrength = 2680; return HandStrength; }
				if (nJ == 1) { HandStrength = 2679; return HandStrength; }
				if (nT == 1) { HandStrength = 2678; return HandStrength; }
				if (n9 == 1) { HandStrength = 2677; return HandStrength; }
				if (n8 == 1) { HandStrength = 2676; return HandStrength; }
				if (n7 == 1) { HandStrength = 2675; return HandStrength; }
				if (n6 == 1) { HandStrength = 2674; return HandStrength; }
				if (n4 == 1) { HandStrength = 2673; return HandStrength; }
				if (n3 == 1) { HandStrength = 2672; return HandStrength; }
				if (n2 == 1) { HandStrength = 2671; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2670; return HandStrength; }
				if (nK == 1) { HandStrength = 2669; return HandStrength; }
				if (nJ == 1) { HandStrength = 2668; return HandStrength; }
				if (nT == 1) { HandStrength = 2667; return HandStrength; }
				if (n9 == 1) { HandStrength = 2666; return HandStrength; }
				if (n8 == 1) { HandStrength = 2665; return HandStrength; }
				if (n7 == 1) { HandStrength = 2664; return HandStrength; }
				if (n6 == 1) { HandStrength = 2663; return HandStrength; }
				if (n5 == 1) { HandStrength = 2662; return HandStrength; }
				if (n3 == 1) { HandStrength = 2661; return HandStrength; }
				if (n2 == 1) { HandStrength = 2660; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2659; return HandStrength; }
				if (nK == 1) { HandStrength = 2658; return HandStrength; }
				if (nJ == 1) { HandStrength = 2657; return HandStrength; }
				if (nT == 1) { HandStrength = 2656; return HandStrength; }
				if (n9 == 1) { HandStrength = 2655; return HandStrength; }
				if (n8 == 1) { HandStrength = 2654; return HandStrength; }
				if (n7 == 1) { HandStrength = 2653; return HandStrength; }
				if (n6 == 1) { HandStrength = 2652; return HandStrength; }
				if (n5 == 1) { HandStrength = 2651; return HandStrength; }
				if (n4 == 1) { HandStrength = 2650; return HandStrength; }
				if (n2 == 1) { HandStrength = 2649; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2648; return HandStrength; }
				if (nK == 1) { HandStrength = 2647; return HandStrength; }
				if (nJ == 1) { HandStrength = 2646; return HandStrength; }
				if (nT == 1) { HandStrength = 2645; return HandStrength; }
				if (n9 == 1) { HandStrength = 2644; return HandStrength; }
				if (n8 == 1) { HandStrength = 2643; return HandStrength; }
				if (n7 == 1) { HandStrength = 2642; return HandStrength; }
				if (n6 == 1) { HandStrength = 2641; return HandStrength; }
				if (n5 == 1) { HandStrength = 2640; return HandStrength; }
				if (n4 == 1) { HandStrength = 2639; return HandStrength; }
				if (n3 == 1) { HandStrength = 2638; return HandStrength; }
			};
		};
		if (nJ == 2) {
			if (nT == 2) {
				if (nA == 1) { HandStrength = 2637; return HandStrength; }
				if (nK == 1) { HandStrength = 2636; return HandStrength; }
				if (nQ == 1) { HandStrength = 2635; return HandStrength; }
				if (n9 == 1) { HandStrength = 2634; return HandStrength; }
				if (n8 == 1) { HandStrength = 2633; return HandStrength; }
				if (n7 == 1) { HandStrength = 2632; return HandStrength; }
				if (n6 == 1) { HandStrength = 2631; return HandStrength; }
				if (n5 == 1) { HandStrength = 2630; return HandStrength; }
				if (n4 == 1) { HandStrength = 2629; return HandStrength; }
				if (n3 == 1) { HandStrength = 2628; return HandStrength; }
				if (n2 == 1) { HandStrength = 2627; return HandStrength; }
			};
			if (n9 == 2) {
				if (nA == 1) { HandStrength = 2626; return HandStrength; }
				if (nK == 1) { HandStrength = 2625; return HandStrength; }
				if (nQ == 1) { HandStrength = 2624; return HandStrength; }
				if (nT == 1) { HandStrength = 2623; return HandStrength; }
				if (n8 == 1) { HandStrength = 2622; return HandStrength; }
				if (n7 == 1) { HandStrength = 2621; return HandStrength; }
				if (n6 == 1) { HandStrength = 2620; return HandStrength; }
				if (n5 == 1) { HandStrength = 2619; return HandStrength; }
				if (n4 == 1) { HandStrength = 2618; return HandStrength; }
				if (n3 == 1) { HandStrength = 2617; return HandStrength; }
				if (n2 == 1) { HandStrength = 2616; return HandStrength; }
			};
			if (n8 == 2) {
				if (nA == 1) { HandStrength = 2615; return HandStrength; }
				if (nK == 1) { HandStrength = 2614; return HandStrength; }
				if (nQ == 1) { HandStrength = 2613; return HandStrength; }
				if (nT == 1) { HandStrength = 2612; return HandStrength; }
				if (n9 == 1) { HandStrength = 2611; return HandStrength; }
				if (n7 == 1) { HandStrength = 2610; return HandStrength; }
				if (n6 == 1) { HandStrength = 2609; return HandStrength; }
				if (n5 == 1) { HandStrength = 2608; return HandStrength; }
				if (n4 == 1) { HandStrength = 2607; return HandStrength; }
				if (n3 == 1) { HandStrength = 2606; return HandStrength; }
				if (n2 == 1) { HandStrength = 2605; return HandStrength; }
			};
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2604; return HandStrength; }
				if (nK == 1) { HandStrength = 2603; return HandStrength; }
				if (nQ == 1) { HandStrength = 2602; return HandStrength; }
				if (nT == 1) { HandStrength = 2601; return HandStrength; }
				if (n9 == 1) { HandStrength = 2600; return HandStrength; }
				if (n8 == 1) { HandStrength = 2599; return HandStrength; }
				if (n6 == 1) { HandStrength = 2598; return HandStrength; }
				if (n5 == 1) { HandStrength = 2597; return HandStrength; }
				if (n4 == 1) { HandStrength = 2596; return HandStrength; }
				if (n3 == 1) { HandStrength = 2595; return HandStrength; }
				if (n2 == 1) { HandStrength = 2594; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2593; return HandStrength; }
				if (nK == 1) { HandStrength = 2592; return HandStrength; }
				if (nQ == 1) { HandStrength = 2591; return HandStrength; }
				if (nT == 1) { HandStrength = 2590; return HandStrength; }
				if (n9 == 1) { HandStrength = 2589; return HandStrength; }
				if (n8 == 1) { HandStrength = 2588; return HandStrength; }
				if (n7 == 1) { HandStrength = 2587; return HandStrength; }
				if (n5 == 1) { HandStrength = 2586; return HandStrength; }
				if (n4 == 1) { HandStrength = 2585; return HandStrength; }
				if (n3 == 1) { HandStrength = 2584; return HandStrength; }
				if (n2 == 1) { HandStrength = 2583; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2582; return HandStrength; }
				if (nK == 1) { HandStrength = 2581; return HandStrength; }
				if (nQ == 1) { HandStrength = 2580; return HandStrength; }
				if (nT == 1) { HandStrength = 2579; return HandStrength; }
				if (n9 == 1) { HandStrength = 2578; return HandStrength; }
				if (n8 == 1) { HandStrength = 2577; return HandStrength; }
				if (n7 == 1) { HandStrength = 2576; return HandStrength; }
				if (n6 == 1) { HandStrength = 2575; return HandStrength; }
				if (n4 == 1) { HandStrength = 2574; return HandStrength; }
				if (n3 == 1) { HandStrength = 2573; return HandStrength; }
				if (n2 == 1) { HandStrength = 2572; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2571; return HandStrength; }
				if (nK == 1) { HandStrength = 2570; return HandStrength; }
				if (nQ == 1) { HandStrength = 2569; return HandStrength; }
				if (nT == 1) { HandStrength = 2568; return HandStrength; }
				if (n9 == 1) { HandStrength = 2567; return HandStrength; }
				if (n8 == 1) { HandStrength = 2566; return HandStrength; }
				if (n7 == 1) { HandStrength = 2565; return HandStrength; }
				if (n6 == 1) { HandStrength = 2564; return HandStrength; }
				if (n5 == 1) { HandStrength = 2563; return HandStrength; }
				if (n3 == 1) { HandStrength = 2562; return HandStrength; }
				if (n2 == 1) { HandStrength = 2561; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2560; return HandStrength; }
				if (nK == 1) { HandStrength = 2559; return HandStrength; }
				if (nQ == 1) { HandStrength = 2558; return HandStrength; }
				if (nT == 1) { HandStrength = 2557; return HandStrength; }
				if (n9 == 1) { HandStrength = 2556; return HandStrength; }
				if (n8 == 1) { HandStrength = 2555; return HandStrength; }
				if (n7 == 1) { HandStrength = 2554; return HandStrength; }
				if (n6 == 1) { HandStrength = 2553; return HandStrength; }
				if (n5 == 1) { HandStrength = 2552; return HandStrength; }
				if (n4 == 1) { HandStrength = 2551; return HandStrength; }
				if (n2 == 1) { HandStrength = 2550; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2549; return HandStrength; }
				if (nK == 1) { HandStrength = 2548; return HandStrength; }
				if (nQ == 1) { HandStrength = 2547; return HandStrength; }
				if (nT == 1) { HandStrength = 2546; return HandStrength; }
				if (n9 == 1) { HandStrength = 2545; return HandStrength; }
				if (n8 == 1) { HandStrength = 2544; return HandStrength; }
				if (n7 == 1) { HandStrength = 2543; return HandStrength; }
				if (n6 == 1) { HandStrength = 2542; return HandStrength; }
				if (n5 == 1) { HandStrength = 2541; return HandStrength; }
				if (n4 == 1) { HandStrength = 2540; return HandStrength; }
				if (n3 == 1) { HandStrength = 2539; return HandStrength; }
			};
		};
		if (nT == 2) {
			if (n9 == 2) {
				if (nA == 1) { HandStrength = 2538; return HandStrength; }
				if (nK == 1) { HandStrength = 2537; return HandStrength; }
				if (nQ == 1) { HandStrength = 2536; return HandStrength; }
				if (nJ == 1) { HandStrength = 2535; return HandStrength; }
				if (n8 == 1) { HandStrength = 2534; return HandStrength; }
				if (n7 == 1) { HandStrength = 2533; return HandStrength; }
				if (n6 == 1) { HandStrength = 2532; return HandStrength; }
				if (n5 == 1) { HandStrength = 2531; return HandStrength; }
				if (n4 == 1) { HandStrength = 2530; return HandStrength; }
				if (n3 == 1) { HandStrength = 2529; return HandStrength; }
				if (n2 == 1) { HandStrength = 2528; return HandStrength; }
			};
			if (n8 == 2) {
				if (nA == 1) { HandStrength = 2527; return HandStrength; }
				if (nK == 1) { HandStrength = 2526; return HandStrength; }
				if (nQ == 1) { HandStrength = 2525; return HandStrength; }
				if (nJ == 1) { HandStrength = 2524; return HandStrength; }
				if (n9 == 1) { HandStrength = 2523; return HandStrength; }
				if (n7 == 1) { HandStrength = 2522; return HandStrength; }
				if (n6 == 1) { HandStrength = 2521; return HandStrength; }
				if (n5 == 1) { HandStrength = 2520; return HandStrength; }
				if (n4 == 1) { HandStrength = 2519; return HandStrength; }
				if (n3 == 1) { HandStrength = 2518; return HandStrength; }
				if (n2 == 1) { HandStrength = 2517; return HandStrength; }
			};
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2516; return HandStrength; }
				if (nK == 1) { HandStrength = 2515; return HandStrength; }
				if (nQ == 1) { HandStrength = 2514; return HandStrength; }
				if (nJ == 1) { HandStrength = 2513; return HandStrength; }
				if (n9 == 1) { HandStrength = 2512; return HandStrength; }
				if (n8 == 1) { HandStrength = 2511; return HandStrength; }
				if (n6 == 1) { HandStrength = 2510; return HandStrength; }
				if (n5 == 1) { HandStrength = 2509; return HandStrength; }
				if (n4 == 1) { HandStrength = 2508; return HandStrength; }
				if (n3 == 1) { HandStrength = 2507; return HandStrength; }
				if (n2 == 1) { HandStrength = 2506; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2505; return HandStrength; }
				if (nK == 1) { HandStrength = 2504; return HandStrength; }
				if (nQ == 1) { HandStrength = 2503; return HandStrength; }
				if (nJ == 1) { HandStrength = 2502; return HandStrength; }
				if (n9 == 1) { HandStrength = 2501; return HandStrength; }
				if (n8 == 1) { HandStrength = 2500; return HandStrength; }
				if (n7 == 1) { HandStrength = 2499; return HandStrength; }
				if (n5 == 1) { HandStrength = 2498; return HandStrength; }
				if (n4 == 1) { HandStrength = 2497; return HandStrength; }
				if (n3 == 1) { HandStrength = 2496; return HandStrength; }
				if (n2 == 1) { HandStrength = 2495; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2494; return HandStrength; }
				if (nK == 1) { HandStrength = 2493; return HandStrength; }
				if (nQ == 1) { HandStrength = 2492; return HandStrength; }
				if (nJ == 1) { HandStrength = 2491; return HandStrength; }
				if (n9 == 1) { HandStrength = 2490; return HandStrength; }
				if (n8 == 1) { HandStrength = 2489; return HandStrength; }
				if (n7 == 1) { HandStrength = 2488; return HandStrength; }
				if (n6 == 1) { HandStrength = 2487; return HandStrength; }
				if (n4 == 1) { HandStrength = 2486; return HandStrength; }
				if (n3 == 1) { HandStrength = 2485; return HandStrength; }
				if (n2 == 1) { HandStrength = 2484; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2483; return HandStrength; }
				if (nK == 1) { HandStrength = 2482; return HandStrength; }
				if (nQ == 1) { HandStrength = 2481; return HandStrength; }
				if (nJ == 1) { HandStrength = 2480; return HandStrength; }
				if (n9 == 1) { HandStrength = 2479; return HandStrength; }
				if (n8 == 1) { HandStrength = 2478; return HandStrength; }
				if (n7 == 1) { HandStrength = 2477; return HandStrength; }
				if (n6 == 1) { HandStrength = 2476; return HandStrength; }
				if (n5 == 1) { HandStrength = 2475; return HandStrength; }
				if (n3 == 1) { HandStrength = 2474; return HandStrength; }
				if (n2 == 1) { HandStrength = 2473; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2472; return HandStrength; }
				if (nK == 1) { HandStrength = 2471; return HandStrength; }
				if (nQ == 1) { HandStrength = 2470; return HandStrength; }
				if (nJ == 1) { HandStrength = 2469; return HandStrength; }
				if (n9 == 1) { HandStrength = 2468; return HandStrength; }
				if (n8 == 1) { HandStrength = 2467; return HandStrength; }
				if (n7 == 1) { HandStrength = 2466; return HandStrength; }
				if (n6 == 1) { HandStrength = 2465; return HandStrength; }
				if (n5 == 1) { HandStrength = 2464; return HandStrength; }
				if (n4 == 1) { HandStrength = 2463; return HandStrength; }
				if (n2 == 1) { HandStrength = 2462; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2461; return HandStrength; }
				if (nK == 1) { HandStrength = 2460; return HandStrength; }
				if (nQ == 1) { HandStrength = 2459; return HandStrength; }
				if (nJ == 1) { HandStrength = 2458; return HandStrength; }
				if (n9 == 1) { HandStrength = 2457; return HandStrength; }
				if (n8 == 1) { HandStrength = 2456; return HandStrength; }
				if (n7 == 1) { HandStrength = 2455; return HandStrength; }
				if (n6 == 1) { HandStrength = 2454; return HandStrength; }
				if (n5 == 1) { HandStrength = 2453; return HandStrength; }
				if (n4 == 1) { HandStrength = 2452; return HandStrength; }
				if (n3 == 1) { HandStrength = 2451; return HandStrength; }
			};
		};
		if (n9 == 2) {
			if (n8 == 2) {
				if (nA == 1) { HandStrength = 2450; return HandStrength; }
				if (nK == 1) { HandStrength = 2449; return HandStrength; }
				if (nQ == 1) { HandStrength = 2448; return HandStrength; }
				if (nJ == 1) { HandStrength = 2447; return HandStrength; }
				if (nT == 1) { HandStrength = 2446; return HandStrength; }
				if (n7 == 1) { HandStrength = 2445; return HandStrength; }
				if (n6 == 1) { HandStrength = 2444; return HandStrength; }
				if (n5 == 1) { HandStrength = 2443; return HandStrength; }
				if (n4 == 1) { HandStrength = 2442; return HandStrength; }
				if (n3 == 1) { HandStrength = 2441; return HandStrength; }
				if (n2 == 1) { HandStrength = 2440; return HandStrength; }
			};
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2439; return HandStrength; }
				if (nK == 1) { HandStrength = 2438; return HandStrength; }
				if (nQ == 1) { HandStrength = 2437; return HandStrength; }
				if (nJ == 1) { HandStrength = 2436; return HandStrength; }
				if (nT == 1) { HandStrength = 2435; return HandStrength; }
				if (n8 == 1) { HandStrength = 2434; return HandStrength; }
				if (n6 == 1) { HandStrength = 2433; return HandStrength; }
				if (n5 == 1) { HandStrength = 2432; return HandStrength; }
				if (n4 == 1) { HandStrength = 2431; return HandStrength; }
				if (n3 == 1) { HandStrength = 2430; return HandStrength; }
				if (n2 == 1) { HandStrength = 2429; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2428; return HandStrength; }
				if (nK == 1) { HandStrength = 2427; return HandStrength; }
				if (nQ == 1) { HandStrength = 2426; return HandStrength; }
				if (nJ == 1) { HandStrength = 2425; return HandStrength; }
				if (nT == 1) { HandStrength = 2424; return HandStrength; }
				if (n8 == 1) { HandStrength = 2423; return HandStrength; }
				if (n7 == 1) { HandStrength = 2422; return HandStrength; }
				if (n5 == 1) { HandStrength = 2421; return HandStrength; }
				if (n4 == 1) { HandStrength = 2420; return HandStrength; }
				if (n3 == 1) { HandStrength = 2419; return HandStrength; }
				if (n2 == 1) { HandStrength = 2418; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2417; return HandStrength; }
				if (nK == 1) { HandStrength = 2416; return HandStrength; }
				if (nQ == 1) { HandStrength = 2415; return HandStrength; }
				if (nJ == 1) { HandStrength = 2414; return HandStrength; }
				if (nT == 1) { HandStrength = 2413; return HandStrength; }
				if (n8 == 1) { HandStrength = 2412; return HandStrength; }
				if (n7 == 1) { HandStrength = 2411; return HandStrength; }
				if (n6 == 1) { HandStrength = 2410; return HandStrength; }
				if (n4 == 1) { HandStrength = 2409; return HandStrength; }
				if (n3 == 1) { HandStrength = 2408; return HandStrength; }
				if (n2 == 1) { HandStrength = 2407; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2406; return HandStrength; }
				if (nK == 1) { HandStrength = 2405; return HandStrength; }
				if (nQ == 1) { HandStrength = 2404; return HandStrength; }
				if (nJ == 1) { HandStrength = 2403; return HandStrength; }
				if (nT == 1) { HandStrength = 2402; return HandStrength; }
				if (n8 == 1) { HandStrength = 2401; return HandStrength; }
				if (n7 == 1) { HandStrength = 2400; return HandStrength; }
				if (n6 == 1) { HandStrength = 2399; return HandStrength; }
				if (n5 == 1) { HandStrength = 2398; return HandStrength; }
				if (n3 == 1) { HandStrength = 2397; return HandStrength; }
				if (n2 == 1) { HandStrength = 2396; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2395; return HandStrength; }
				if (nK == 1) { HandStrength = 2394; return HandStrength; }
				if (nQ == 1) { HandStrength = 2393; return HandStrength; }
				if (nJ == 1) { HandStrength = 2392; return HandStrength; }
				if (nT == 1) { HandStrength = 2391; return HandStrength; }
				if (n8 == 1) { HandStrength = 2390; return HandStrength; }
				if (n7 == 1) { HandStrength = 2389; return HandStrength; }
				if (n6 == 1) { HandStrength = 2388; return HandStrength; }
				if (n5 == 1) { HandStrength = 2387; return HandStrength; }
				if (n4 == 1) { HandStrength = 2386; return HandStrength; }
				if (n2 == 1) { HandStrength = 2385; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2384; return HandStrength; }
				if (nK == 1) { HandStrength = 2383; return HandStrength; }
				if (nQ == 1) { HandStrength = 2382; return HandStrength; }
				if (nJ == 1) { HandStrength = 2381; return HandStrength; }
				if (nT == 1) { HandStrength = 2380; return HandStrength; }
				if (n8 == 1) { HandStrength = 2379; return HandStrength; }
				if (n7 == 1) { HandStrength = 2378; return HandStrength; }
				if (n6 == 1) { HandStrength = 2377; return HandStrength; }
				if (n5 == 1) { HandStrength = 2376; return HandStrength; }
				if (n4 == 1) { HandStrength = 2375; return HandStrength; }
				if (n3 == 1) { HandStrength = 2374; return HandStrength; }
			};
		};
		if (n8 == 2) {
			if (n7 == 2) {
				if (nA == 1) { HandStrength = 2373; return HandStrength; }
				if (nK == 1) { HandStrength = 2372; return HandStrength; }
				if (nQ == 1) { HandStrength = 2371; return HandStrength; }
				if (nJ == 1) { HandStrength = 2370; return HandStrength; }
				if (nT == 1) { HandStrength = 2369; return HandStrength; }
				if (n9 == 1) { HandStrength = 2368; return HandStrength; }
				if (n6 == 1) { HandStrength = 2367; return HandStrength; }
				if (n5 == 1) { HandStrength = 2366; return HandStrength; }
				if (n4 == 1) { HandStrength = 2365; return HandStrength; }
				if (n3 == 1) { HandStrength = 2364; return HandStrength; }
				if (n2 == 1) { HandStrength = 2363; return HandStrength; }
			};
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2362; return HandStrength; }
				if (nK == 1) { HandStrength = 2361; return HandStrength; }
				if (nQ == 1) { HandStrength = 2360; return HandStrength; }
				if (nJ == 1) { HandStrength = 2359; return HandStrength; }
				if (nT == 1) { HandStrength = 2358; return HandStrength; }
				if (n9 == 1) { HandStrength = 2357; return HandStrength; }
				if (n7 == 1) { HandStrength = 2356; return HandStrength; }
				if (n5 == 1) { HandStrength = 2355; return HandStrength; }
				if (n4 == 1) { HandStrength = 2354; return HandStrength; }
				if (n3 == 1) { HandStrength = 2353; return HandStrength; }
				if (n2 == 1) { HandStrength = 2352; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2351; return HandStrength; }
				if (nK == 1) { HandStrength = 2350; return HandStrength; }
				if (nQ == 1) { HandStrength = 2349; return HandStrength; }
				if (nJ == 1) { HandStrength = 2348; return HandStrength; }
				if (nT == 1) { HandStrength = 2347; return HandStrength; }
				if (n9 == 1) { HandStrength = 2346; return HandStrength; }
				if (n7 == 1) { HandStrength = 2345; return HandStrength; }
				if (n6 == 1) { HandStrength = 2344; return HandStrength; }
				if (n4 == 1) { HandStrength = 2343; return HandStrength; }
				if (n3 == 1) { HandStrength = 2342; return HandStrength; }
				if (n2 == 1) { HandStrength = 2341; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2340; return HandStrength; }
				if (nK == 1) { HandStrength = 2339; return HandStrength; }
				if (nQ == 1) { HandStrength = 2338; return HandStrength; }
				if (nJ == 1) { HandStrength = 2337; return HandStrength; }
				if (nT == 1) { HandStrength = 2336; return HandStrength; }
				if (n9 == 1) { HandStrength = 2335; return HandStrength; }
				if (n7 == 1) { HandStrength = 2334; return HandStrength; }
				if (n6 == 1) { HandStrength = 2333; return HandStrength; }
				if (n5 == 1) { HandStrength = 2332; return HandStrength; }
				if (n3 == 1) { HandStrength = 2331; return HandStrength; }
				if (n2 == 1) { HandStrength = 2330; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2329; return HandStrength; }
				if (nK == 1) { HandStrength = 2328; return HandStrength; }
				if (nQ == 1) { HandStrength = 2327; return HandStrength; }
				if (nJ == 1) { HandStrength = 2326; return HandStrength; }
				if (nT == 1) { HandStrength = 2325; return HandStrength; }
				if (n9 == 1) { HandStrength = 2324; return HandStrength; }
				if (n7 == 1) { HandStrength = 2323; return HandStrength; }
				if (n6 == 1) { HandStrength = 2322; return HandStrength; }
				if (n5 == 1) { HandStrength = 2321; return HandStrength; }
				if (n4 == 1) { HandStrength = 2320; return HandStrength; }
				if (n2 == 1) { HandStrength = 2319; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2318; return HandStrength; }
				if (nK == 1) { HandStrength = 2317; return HandStrength; }
				if (nQ == 1) { HandStrength = 2316; return HandStrength; }
				if (nJ == 1) { HandStrength = 2315; return HandStrength; }
				if (nT == 1) { HandStrength = 2314; return HandStrength; }
				if (n9 == 1) { HandStrength = 2313; return HandStrength; }
				if (n7 == 1) { HandStrength = 2312; return HandStrength; }
				if (n6 == 1) { HandStrength = 2311; return HandStrength; }
				if (n5 == 1) { HandStrength = 2310; return HandStrength; }
				if (n4 == 1) { HandStrength = 2309; return HandStrength; }
				if (n3 == 1) { HandStrength = 2308; return HandStrength; }
			};
		};
		if (n7 == 2) {
			if (n6 == 2) {
				if (nA == 1) { HandStrength = 2307; return HandStrength; }
				if (nK == 1) { HandStrength = 2306; return HandStrength; }
				if (nQ == 1) { HandStrength = 2305; return HandStrength; }
				if (nJ == 1) { HandStrength = 2304; return HandStrength; }
				if (nT == 1) { HandStrength = 2303; return HandStrength; }
				if (n9 == 1) { HandStrength = 2302; return HandStrength; }
				if (n8 == 1) { HandStrength = 2301; return HandStrength; }
				if (n5 == 1) { HandStrength = 2300; return HandStrength; }
				if (n4 == 1) { HandStrength = 2299; return HandStrength; }
				if (n3 == 1) { HandStrength = 2298; return HandStrength; }
				if (n2 == 1) { HandStrength = 2297; return HandStrength; }
			};
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2296; return HandStrength; }
				if (nK == 1) { HandStrength = 2295; return HandStrength; }
				if (nQ == 1) { HandStrength = 2294; return HandStrength; }
				if (nJ == 1) { HandStrength = 2293; return HandStrength; }
				if (nT == 1) { HandStrength = 2292; return HandStrength; }
				if (n9 == 1) { HandStrength = 2291; return HandStrength; }
				if (n8 == 1) { HandStrength = 2290; return HandStrength; }
				if (n6 == 1) { HandStrength = 2289; return HandStrength; }
				if (n4 == 1) { HandStrength = 2288; return HandStrength; }
				if (n3 == 1) { HandStrength = 2287; return HandStrength; }
				if (n2 == 1) { HandStrength = 2286; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2285; return HandStrength; }
				if (nK == 1) { HandStrength = 2284; return HandStrength; }
				if (nQ == 1) { HandStrength = 2283; return HandStrength; }
				if (nJ == 1) { HandStrength = 2282; return HandStrength; }
				if (nT == 1) { HandStrength = 2281; return HandStrength; }
				if (n9 == 1) { HandStrength = 2280; return HandStrength; }
				if (n8 == 1) { HandStrength = 2279; return HandStrength; }
				if (n6 == 1) { HandStrength = 2278; return HandStrength; }
				if (n5 == 1) { HandStrength = 2277; return HandStrength; }
				if (n3 == 1) { HandStrength = 2276; return HandStrength; }
				if (n2 == 1) { HandStrength = 2275; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2274; return HandStrength; }
				if (nK == 1) { HandStrength = 2273; return HandStrength; }
				if (nQ == 1) { HandStrength = 2272; return HandStrength; }
				if (nJ == 1) { HandStrength = 2271; return HandStrength; }
				if (nT == 1) { HandStrength = 2270; return HandStrength; }
				if (n9 == 1) { HandStrength = 2269; return HandStrength; }
				if (n8 == 1) { HandStrength = 2268; return HandStrength; }
				if (n6 == 1) { HandStrength = 2267; return HandStrength; }
				if (n5 == 1) { HandStrength = 2266; return HandStrength; }
				if (n4 == 1) { HandStrength = 2265; return HandStrength; }
				if (n2 == 1) { HandStrength = 2264; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2263; return HandStrength; }
				if (nK == 1) { HandStrength = 2262; return HandStrength; }
				if (nQ == 1) { HandStrength = 2261; return HandStrength; }
				if (nJ == 1) { HandStrength = 2260; return HandStrength; }
				if (nT == 1) { HandStrength = 2259; return HandStrength; }
				if (n9 == 1) { HandStrength = 2258; return HandStrength; }
				if (n8 == 1) { HandStrength = 2257; return HandStrength; }
				if (n6 == 1) { HandStrength = 2256; return HandStrength; }
				if (n5 == 1) { HandStrength = 2255; return HandStrength; }
				if (n4 == 1) { HandStrength = 2254; return HandStrength; }
				if (n3 == 1) { HandStrength = 2253; return HandStrength; }
			};
		};
		if (n6 == 2) {
			if (n5 == 2) {
				if (nA == 1) { HandStrength = 2252; return HandStrength; }
				if (nK == 1) { HandStrength = 2251; return HandStrength; }
				if (nQ == 1) { HandStrength = 2250; return HandStrength; }
				if (nJ == 1) { HandStrength = 2249; return HandStrength; }
				if (nT == 1) { HandStrength = 2248; return HandStrength; }
				if (n9 == 1) { HandStrength = 2247; return HandStrength; }
				if (n8 == 1) { HandStrength = 2246; return HandStrength; }
				if (n7 == 1) { HandStrength = 2245; return HandStrength; }
				if (n4 == 1) { HandStrength = 2244; return HandStrength; }
				if (n3 == 1) { HandStrength = 2243; return HandStrength; }
				if (n2 == 1) { HandStrength = 2242; return HandStrength; }
			};
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2241; return HandStrength; }
				if (nK == 1) { HandStrength = 2240; return HandStrength; }
				if (nQ == 1) { HandStrength = 2239; return HandStrength; }
				if (nJ == 1) { HandStrength = 2238; return HandStrength; }
				if (nT == 1) { HandStrength = 2237; return HandStrength; }
				if (n9 == 1) { HandStrength = 2236; return HandStrength; }
				if (n8 == 1) { HandStrength = 2235; return HandStrength; }
				if (n7 == 1) { HandStrength = 2234; return HandStrength; }
				if (n5 == 1) { HandStrength = 2233; return HandStrength; }
				if (n3 == 1) { HandStrength = 2232; return HandStrength; }
				if (n2 == 1) { HandStrength = 2231; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2230; return HandStrength; }
				if (nK == 1) { HandStrength = 2229; return HandStrength; }
				if (nQ == 1) { HandStrength = 2228; return HandStrength; }
				if (nJ == 1) { HandStrength = 2227; return HandStrength; }
				if (nT == 1) { HandStrength = 2226; return HandStrength; }
				if (n9 == 1) { HandStrength = 2225; return HandStrength; }
				if (n8 == 1) { HandStrength = 2224; return HandStrength; }
				if (n7 == 1) { HandStrength = 2223; return HandStrength; }
				if (n5 == 1) { HandStrength = 2222; return HandStrength; }
				if (n4 == 1) { HandStrength = 2221; return HandStrength; }
				if (n2 == 1) { HandStrength = 2220; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2219; return HandStrength; }
				if (nK == 1) { HandStrength = 2218; return HandStrength; }
				if (nQ == 1) { HandStrength = 2217; return HandStrength; }
				if (nJ == 1) { HandStrength = 2216; return HandStrength; }
				if (nT == 1) { HandStrength = 2215; return HandStrength; }
				if (n9 == 1) { HandStrength = 2214; return HandStrength; }
				if (n8 == 1) { HandStrength = 2213; return HandStrength; }
				if (n7 == 1) { HandStrength = 2212; return HandStrength; }
				if (n5 == 1) { HandStrength = 2211; return HandStrength; }
				if (n4 == 1) { HandStrength = 2210; return HandStrength; }
				if (n3 == 1) { HandStrength = 2209; return HandStrength; }
			};
		};
		if (n5 == 2) {
			if (n4 == 2) {
				if (nA == 1) { HandStrength = 2208; return HandStrength; }
				if (nK == 1) { HandStrength = 2207; return HandStrength; }
				if (nQ == 1) { HandStrength = 2206; return HandStrength; }
				if (nJ == 1) { HandStrength = 2205; return HandStrength; }
				if (nT == 1) { HandStrength = 2204; return HandStrength; }
				if (n9 == 1) { HandStrength = 2203; return HandStrength; }
				if (n8 == 1) { HandStrength = 2202; return HandStrength; }
				if (n7 == 1) { HandStrength = 2201; return HandStrength; }
				if (n6 == 1) { HandStrength = 2200; return HandStrength; }
				if (n3 == 1) { HandStrength = 2199; return HandStrength; }
				if (n2 == 1) { HandStrength = 2198; return HandStrength; }
			};
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2197; return HandStrength; }
				if (nK == 1) { HandStrength = 2196; return HandStrength; }
				if (nQ == 1) { HandStrength = 2195; return HandStrength; }
				if (nJ == 1) { HandStrength = 2194; return HandStrength; }
				if (nT == 1) { HandStrength = 2193; return HandStrength; }
				if (n9 == 1) { HandStrength = 2192; return HandStrength; }
				if (n8 == 1) { HandStrength = 2191; return HandStrength; }
				if (n7 == 1) { HandStrength = 2190; return HandStrength; }
				if (n6 == 1) { HandStrength = 2189; return HandStrength; }
				if (n4 == 1) { HandStrength = 2188; return HandStrength; }
				if (n2 == 1) { HandStrength = 2187; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2186; return HandStrength; }
				if (nK == 1) { HandStrength = 2185; return HandStrength; }
				if (nQ == 1) { HandStrength = 2184; return HandStrength; }
				if (nJ == 1) { HandStrength = 2183; return HandStrength; }
				if (nT == 1) { HandStrength = 2182; return HandStrength; }
				if (n9 == 1) { HandStrength = 2181; return HandStrength; }
				if (n8 == 1) { HandStrength = 2180; return HandStrength; }
				if (n7 == 1) { HandStrength = 2179; return HandStrength; }
				if (n6 == 1) { HandStrength = 2178; return HandStrength; }
				if (n4 == 1) { HandStrength = 2177; return HandStrength; }
				if (n3 == 1) { HandStrength = 2176; return HandStrength; }
			};
		};
		if (n4 == 2) {
			if (n3 == 2) {
				if (nA == 1) { HandStrength = 2175; return HandStrength; }
				if (nK == 1) { HandStrength = 2174; return HandStrength; }
				if (nQ == 1) { HandStrength = 2173; return HandStrength; }
				if (nJ == 1) { HandStrength = 2172; return HandStrength; }
				if (nT == 1) { HandStrength = 2171; return HandStrength; }
				if (n9 == 1) { HandStrength = 2170; return HandStrength; }
				if (n8 == 1) { HandStrength = 2169; return HandStrength; }
				if (n7 == 1) { HandStrength = 2168; return HandStrength; }
				if (n6 == 1) { HandStrength = 2167; return HandStrength; }
				if (n5 == 1) { HandStrength = 2166; return HandStrength; }
				if (n2 == 1) { HandStrength = 2165; return HandStrength; }
			};
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2164; return HandStrength; }
				if (nK == 1) { HandStrength = 2163; return HandStrength; }
				if (nQ == 1) { HandStrength = 2162; return HandStrength; }
				if (nJ == 1) { HandStrength = 2161; return HandStrength; }
				if (nT == 1) { HandStrength = 2160; return HandStrength; }
				if (n9 == 1) { HandStrength = 2159; return HandStrength; }
				if (n8 == 1) { HandStrength = 2158; return HandStrength; }
				if (n7 == 1) { HandStrength = 2157; return HandStrength; }
				if (n6 == 1) { HandStrength = 2156; return HandStrength; }
				if (n5 == 1) { HandStrength = 2155; return HandStrength; }
				if (n3 == 1) { HandStrength = 2154; return HandStrength; }
			};
		};
		if (n3 == 2) {
			if (n2 == 2) {
				if (nA == 1) { HandStrength = 2153; return HandStrength; }
				if (nK == 1) { HandStrength = 2152; return HandStrength; }
				if (nQ == 1) { HandStrength = 2151; return HandStrength; }
				if (nJ == 1) { HandStrength = 2150; return HandStrength; }
				if (nT == 1) { HandStrength = 2149; return HandStrength; }
				if (n9 == 1) { HandStrength = 2148; return HandStrength; }
				if (n8 == 1) { HandStrength = 2147; return HandStrength; }
				if (n7 == 1) { HandStrength = 2146; return HandStrength; }
				if (n6 == 1) { HandStrength = 2145; return HandStrength; }
				if (n5 == 1) { HandStrength = 2144; return HandStrength; }
				if (n4 == 1) { HandStrength = 2143; return HandStrength; }
			};
		};
		if (n2 == 2) {
		};
	};
	//Pair
	if (nPairs == 1) {
		HandStrength = 2000;
		if (CheckKicker == false) {
			if (nA == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (nK == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (nQ == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (nJ == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (nT == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n9 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n8 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n7 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n6 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n5 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n4 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n3 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
			if (n2 == 2) { return HandStrength; }
			else { HandStrength -= 1; };
		}
		if (nA == 2) {
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 2000; return HandStrength; }
					if (nT == 1) { HandStrength = 1999; return HandStrength; }
					if (n9 == 1) { HandStrength = 1998; return HandStrength; }
					if (n8 == 1) { HandStrength = 1997; return HandStrength; }
					if (n7 == 1) { HandStrength = 1996; return HandStrength; }
					if (n6 == 1) { HandStrength = 1995; return HandStrength; }
					if (n5 == 1) { HandStrength = 1994; return HandStrength; }
					if (n4 == 1) { HandStrength = 1993; return HandStrength; }
					if (n3 == 1) { HandStrength = 1992; return HandStrength; }
					if (n2 == 1) { HandStrength = 1991; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1990; return HandStrength; }
					if (n9 == 1) { HandStrength = 1989; return HandStrength; }
					if (n8 == 1) { HandStrength = 1988; return HandStrength; }
					if (n7 == 1) { HandStrength = 1987; return HandStrength; }
					if (n6 == 1) { HandStrength = 1986; return HandStrength; }
					if (n5 == 1) { HandStrength = 1985; return HandStrength; }
					if (n4 == 1) { HandStrength = 1984; return HandStrength; }
					if (n3 == 1) { HandStrength = 1983; return HandStrength; }
					if (n2 == 1) { HandStrength = 1982; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1981; return HandStrength; }
					if (n8 == 1) { HandStrength = 1980; return HandStrength; }
					if (n7 == 1) { HandStrength = 1979; return HandStrength; }
					if (n6 == 1) { HandStrength = 1978; return HandStrength; }
					if (n5 == 1) { HandStrength = 1977; return HandStrength; }
					if (n4 == 1) { HandStrength = 1976; return HandStrength; }
					if (n3 == 1) { HandStrength = 1975; return HandStrength; }
					if (n2 == 1) { HandStrength = 1974; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1973; return HandStrength; }
					if (n7 == 1) { HandStrength = 1972; return HandStrength; }
					if (n6 == 1) { HandStrength = 1971; return HandStrength; }
					if (n5 == 1) { HandStrength = 1970; return HandStrength; }
					if (n4 == 1) { HandStrength = 1969; return HandStrength; }
					if (n3 == 1) { HandStrength = 1968; return HandStrength; }
					if (n2 == 1) { HandStrength = 1967; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1966; return HandStrength; }
					if (n6 == 1) { HandStrength = 1965; return HandStrength; }
					if (n5 == 1) { HandStrength = 1964; return HandStrength; }
					if (n4 == 1) { HandStrength = 1963; return HandStrength; }
					if (n3 == 1) { HandStrength = 1962; return HandStrength; }
					if (n2 == 1) { HandStrength = 1961; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1960; return HandStrength; }
					if (n5 == 1) { HandStrength = 1959; return HandStrength; }
					if (n4 == 1) { HandStrength = 1958; return HandStrength; }
					if (n3 == 1) { HandStrength = 1957; return HandStrength; }
					if (n2 == 1) { HandStrength = 1956; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1955; return HandStrength; }
					if (n4 == 1) { HandStrength = 1954; return HandStrength; }
					if (n3 == 1) { HandStrength = 1953; return HandStrength; }
					if (n2 == 1) { HandStrength = 1952; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1951; return HandStrength; }
					if (n3 == 1) { HandStrength = 1950; return HandStrength; }
					if (n2 == 1) { HandStrength = 1949; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1948; return HandStrength; }
					if (n2 == 1) { HandStrength = 1947; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1946; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1945; return HandStrength; }
					if (n9 == 1) { HandStrength = 1944; return HandStrength; }
					if (n8 == 1) { HandStrength = 1943; return HandStrength; }
					if (n7 == 1) { HandStrength = 1942; return HandStrength; }
					if (n6 == 1) { HandStrength = 1941; return HandStrength; }
					if (n5 == 1) { HandStrength = 1940; return HandStrength; }
					if (n4 == 1) { HandStrength = 1939; return HandStrength; }
					if (n3 == 1) { HandStrength = 1938; return HandStrength; }
					if (n2 == 1) { HandStrength = 1937; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1936; return HandStrength; }
					if (n8 == 1) { HandStrength = 1935; return HandStrength; }
					if (n7 == 1) { HandStrength = 1934; return HandStrength; }
					if (n6 == 1) { HandStrength = 1933; return HandStrength; }
					if (n5 == 1) { HandStrength = 1932; return HandStrength; }
					if (n4 == 1) { HandStrength = 1931; return HandStrength; }
					if (n3 == 1) { HandStrength = 1930; return HandStrength; }
					if (n2 == 1) { HandStrength = 1929; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1928; return HandStrength; }
					if (n7 == 1) { HandStrength = 1927; return HandStrength; }
					if (n6 == 1) { HandStrength = 1926; return HandStrength; }
					if (n5 == 1) { HandStrength = 1925; return HandStrength; }
					if (n4 == 1) { HandStrength = 1924; return HandStrength; }
					if (n3 == 1) { HandStrength = 1923; return HandStrength; }
					if (n2 == 1) { HandStrength = 1922; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1921; return HandStrength; }
					if (n6 == 1) { HandStrength = 1920; return HandStrength; }
					if (n5 == 1) { HandStrength = 1919; return HandStrength; }
					if (n4 == 1) { HandStrength = 1918; return HandStrength; }
					if (n3 == 1) { HandStrength = 1917; return HandStrength; }
					if (n2 == 1) { HandStrength = 1916; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1915; return HandStrength; }
					if (n5 == 1) { HandStrength = 1914; return HandStrength; }
					if (n4 == 1) { HandStrength = 1913; return HandStrength; }
					if (n3 == 1) { HandStrength = 1912; return HandStrength; }
					if (n2 == 1) { HandStrength = 1911; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1910; return HandStrength; }
					if (n4 == 1) { HandStrength = 1909; return HandStrength; }
					if (n3 == 1) { HandStrength = 1908; return HandStrength; }
					if (n2 == 1) { HandStrength = 1907; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1906; return HandStrength; }
					if (n3 == 1) { HandStrength = 1905; return HandStrength; }
					if (n2 == 1) { HandStrength = 1904; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1903; return HandStrength; }
					if (n2 == 1) { HandStrength = 1902; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1901; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1900; return HandStrength; }
					if (n8 == 1) { HandStrength = 1899; return HandStrength; }
					if (n7 == 1) { HandStrength = 1898; return HandStrength; }
					if (n6 == 1) { HandStrength = 1897; return HandStrength; }
					if (n5 == 1) { HandStrength = 1896; return HandStrength; }
					if (n4 == 1) { HandStrength = 1895; return HandStrength; }
					if (n3 == 1) { HandStrength = 1894; return HandStrength; }
					if (n2 == 1) { HandStrength = 1893; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1892; return HandStrength; }
					if (n7 == 1) { HandStrength = 1891; return HandStrength; }
					if (n6 == 1) { HandStrength = 1890; return HandStrength; }
					if (n5 == 1) { HandStrength = 1889; return HandStrength; }
					if (n4 == 1) { HandStrength = 1888; return HandStrength; }
					if (n3 == 1) { HandStrength = 1887; return HandStrength; }
					if (n2 == 1) { HandStrength = 1886; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1885; return HandStrength; }
					if (n6 == 1) { HandStrength = 1884; return HandStrength; }
					if (n5 == 1) { HandStrength = 1883; return HandStrength; }
					if (n4 == 1) { HandStrength = 1882; return HandStrength; }
					if (n3 == 1) { HandStrength = 1881; return HandStrength; }
					if (n2 == 1) { HandStrength = 1880; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1879; return HandStrength; }
					if (n5 == 1) { HandStrength = 1878; return HandStrength; }
					if (n4 == 1) { HandStrength = 1877; return HandStrength; }
					if (n3 == 1) { HandStrength = 1876; return HandStrength; }
					if (n2 == 1) { HandStrength = 1875; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1874; return HandStrength; }
					if (n4 == 1) { HandStrength = 1873; return HandStrength; }
					if (n3 == 1) { HandStrength = 1872; return HandStrength; }
					if (n2 == 1) { HandStrength = 1871; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1870; return HandStrength; }
					if (n3 == 1) { HandStrength = 1869; return HandStrength; }
					if (n2 == 1) { HandStrength = 1868; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1867; return HandStrength; }
					if (n2 == 1) { HandStrength = 1866; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1865; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1864; return HandStrength; }
					if (n7 == 1) { HandStrength = 1863; return HandStrength; }
					if (n6 == 1) { HandStrength = 1862; return HandStrength; }
					if (n5 == 1) { HandStrength = 1861; return HandStrength; }
					if (n4 == 1) { HandStrength = 1860; return HandStrength; }
					if (n3 == 1) { HandStrength = 1859; return HandStrength; }
					if (n2 == 1) { HandStrength = 1858; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1857; return HandStrength; }
					if (n6 == 1) { HandStrength = 1856; return HandStrength; }
					if (n5 == 1) { HandStrength = 1855; return HandStrength; }
					if (n4 == 1) { HandStrength = 1854; return HandStrength; }
					if (n3 == 1) { HandStrength = 1853; return HandStrength; }
					if (n2 == 1) { HandStrength = 1852; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1851; return HandStrength; }
					if (n5 == 1) { HandStrength = 1850; return HandStrength; }
					if (n4 == 1) { HandStrength = 1849; return HandStrength; }
					if (n3 == 1) { HandStrength = 1848; return HandStrength; }
					if (n2 == 1) { HandStrength = 1847; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1846; return HandStrength; }
					if (n4 == 1) { HandStrength = 1845; return HandStrength; }
					if (n3 == 1) { HandStrength = 1844; return HandStrength; }
					if (n2 == 1) { HandStrength = 1843; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1842; return HandStrength; }
					if (n3 == 1) { HandStrength = 1841; return HandStrength; }
					if (n2 == 1) { HandStrength = 1840; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1839; return HandStrength; }
					if (n2 == 1) { HandStrength = 1838; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1837; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1836; return HandStrength; }
					if (n6 == 1) { HandStrength = 1835; return HandStrength; }
					if (n5 == 1) { HandStrength = 1834; return HandStrength; }
					if (n4 == 1) { HandStrength = 1833; return HandStrength; }
					if (n3 == 1) { HandStrength = 1832; return HandStrength; }
					if (n2 == 1) { HandStrength = 1831; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1830; return HandStrength; }
					if (n5 == 1) { HandStrength = 1829; return HandStrength; }
					if (n4 == 1) { HandStrength = 1828; return HandStrength; }
					if (n3 == 1) { HandStrength = 1827; return HandStrength; }
					if (n2 == 1) { HandStrength = 1826; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1825; return HandStrength; }
					if (n4 == 1) { HandStrength = 1824; return HandStrength; }
					if (n3 == 1) { HandStrength = 1823; return HandStrength; }
					if (n2 == 1) { HandStrength = 1822; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1821; return HandStrength; }
					if (n3 == 1) { HandStrength = 1820; return HandStrength; }
					if (n2 == 1) { HandStrength = 1819; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1818; return HandStrength; }
					if (n2 == 1) { HandStrength = 1817; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1816; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1815; return HandStrength; }
					if (n5 == 1) { HandStrength = 1814; return HandStrength; }
					if (n4 == 1) { HandStrength = 1813; return HandStrength; }
					if (n3 == 1) { HandStrength = 1812; return HandStrength; }
					if (n2 == 1) { HandStrength = 1811; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1810; return HandStrength; }
					if (n4 == 1) { HandStrength = 1809; return HandStrength; }
					if (n3 == 1) { HandStrength = 1808; return HandStrength; }
					if (n2 == 1) { HandStrength = 1807; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1806; return HandStrength; }
					if (n3 == 1) { HandStrength = 1805; return HandStrength; }
					if (n2 == 1) { HandStrength = 1804; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1803; return HandStrength; }
					if (n2 == 1) { HandStrength = 1802; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1801; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1800; return HandStrength; }
					if (n4 == 1) { HandStrength = 1799; return HandStrength; }
					if (n3 == 1) { HandStrength = 1798; return HandStrength; }
					if (n2 == 1) { HandStrength = 1797; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1796; return HandStrength; }
					if (n3 == 1) { HandStrength = 1795; return HandStrength; }
					if (n2 == 1) { HandStrength = 1794; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1793; return HandStrength; }
					if (n2 == 1) { HandStrength = 1792; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1791; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1790; return HandStrength; }
					if (n3 == 1) { HandStrength = 1789; return HandStrength; }
					if (n2 == 1) { HandStrength = 1788; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1787; return HandStrength; }
					if (n2 == 1) { HandStrength = 1786; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1785; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1784; return HandStrength; }
					if (n2 == 1) { HandStrength = 1783; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1782; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1781; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nK == 2) {
			if (nA == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 1780; return HandStrength; }
					if (nT == 1) { HandStrength = 1779; return HandStrength; }
					if (n9 == 1) { HandStrength = 1778; return HandStrength; }
					if (n8 == 1) { HandStrength = 1777; return HandStrength; }
					if (n7 == 1) { HandStrength = 1776; return HandStrength; }
					if (n6 == 1) { HandStrength = 1775; return HandStrength; }
					if (n5 == 1) { HandStrength = 1774; return HandStrength; }
					if (n4 == 1) { HandStrength = 1773; return HandStrength; }
					if (n3 == 1) { HandStrength = 1772; return HandStrength; }
					if (n2 == 1) { HandStrength = 1771; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1770; return HandStrength; }
					if (n9 == 1) { HandStrength = 1769; return HandStrength; }
					if (n8 == 1) { HandStrength = 1768; return HandStrength; }
					if (n7 == 1) { HandStrength = 1767; return HandStrength; }
					if (n6 == 1) { HandStrength = 1766; return HandStrength; }
					if (n5 == 1) { HandStrength = 1765; return HandStrength; }
					if (n4 == 1) { HandStrength = 1764; return HandStrength; }
					if (n3 == 1) { HandStrength = 1763; return HandStrength; }
					if (n2 == 1) { HandStrength = 1762; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1761; return HandStrength; }
					if (n8 == 1) { HandStrength = 1760; return HandStrength; }
					if (n7 == 1) { HandStrength = 1759; return HandStrength; }
					if (n6 == 1) { HandStrength = 1758; return HandStrength; }
					if (n5 == 1) { HandStrength = 1757; return HandStrength; }
					if (n4 == 1) { HandStrength = 1756; return HandStrength; }
					if (n3 == 1) { HandStrength = 1755; return HandStrength; }
					if (n2 == 1) { HandStrength = 1754; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1753; return HandStrength; }
					if (n7 == 1) { HandStrength = 1752; return HandStrength; }
					if (n6 == 1) { HandStrength = 1751; return HandStrength; }
					if (n5 == 1) { HandStrength = 1750; return HandStrength; }
					if (n4 == 1) { HandStrength = 1749; return HandStrength; }
					if (n3 == 1) { HandStrength = 1748; return HandStrength; }
					if (n2 == 1) { HandStrength = 1747; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1746; return HandStrength; }
					if (n6 == 1) { HandStrength = 1745; return HandStrength; }
					if (n5 == 1) { HandStrength = 1744; return HandStrength; }
					if (n4 == 1) { HandStrength = 1743; return HandStrength; }
					if (n3 == 1) { HandStrength = 1742; return HandStrength; }
					if (n2 == 1) { HandStrength = 1741; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1740; return HandStrength; }
					if (n5 == 1) { HandStrength = 1739; return HandStrength; }
					if (n4 == 1) { HandStrength = 1738; return HandStrength; }
					if (n3 == 1) { HandStrength = 1737; return HandStrength; }
					if (n2 == 1) { HandStrength = 1736; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1735; return HandStrength; }
					if (n4 == 1) { HandStrength = 1734; return HandStrength; }
					if (n3 == 1) { HandStrength = 1733; return HandStrength; }
					if (n2 == 1) { HandStrength = 1732; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1731; return HandStrength; }
					if (n3 == 1) { HandStrength = 1730; return HandStrength; }
					if (n2 == 1) { HandStrength = 1729; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1728; return HandStrength; }
					if (n2 == 1) { HandStrength = 1727; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1726; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1725; return HandStrength; }
					if (n9 == 1) { HandStrength = 1724; return HandStrength; }
					if (n8 == 1) { HandStrength = 1723; return HandStrength; }
					if (n7 == 1) { HandStrength = 1722; return HandStrength; }
					if (n6 == 1) { HandStrength = 1721; return HandStrength; }
					if (n5 == 1) { HandStrength = 1720; return HandStrength; }
					if (n4 == 1) { HandStrength = 1719; return HandStrength; }
					if (n3 == 1) { HandStrength = 1718; return HandStrength; }
					if (n2 == 1) { HandStrength = 1717; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1716; return HandStrength; }
					if (n8 == 1) { HandStrength = 1715; return HandStrength; }
					if (n7 == 1) { HandStrength = 1714; return HandStrength; }
					if (n6 == 1) { HandStrength = 1713; return HandStrength; }
					if (n5 == 1) { HandStrength = 1712; return HandStrength; }
					if (n4 == 1) { HandStrength = 1711; return HandStrength; }
					if (n3 == 1) { HandStrength = 1710; return HandStrength; }
					if (n2 == 1) { HandStrength = 1709; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1708; return HandStrength; }
					if (n7 == 1) { HandStrength = 1707; return HandStrength; }
					if (n6 == 1) { HandStrength = 1706; return HandStrength; }
					if (n5 == 1) { HandStrength = 1705; return HandStrength; }
					if (n4 == 1) { HandStrength = 1704; return HandStrength; }
					if (n3 == 1) { HandStrength = 1703; return HandStrength; }
					if (n2 == 1) { HandStrength = 1702; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1701; return HandStrength; }
					if (n6 == 1) { HandStrength = 1700; return HandStrength; }
					if (n5 == 1) { HandStrength = 1699; return HandStrength; }
					if (n4 == 1) { HandStrength = 1698; return HandStrength; }
					if (n3 == 1) { HandStrength = 1697; return HandStrength; }
					if (n2 == 1) { HandStrength = 1696; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1695; return HandStrength; }
					if (n5 == 1) { HandStrength = 1694; return HandStrength; }
					if (n4 == 1) { HandStrength = 1693; return HandStrength; }
					if (n3 == 1) { HandStrength = 1692; return HandStrength; }
					if (n2 == 1) { HandStrength = 1691; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1690; return HandStrength; }
					if (n4 == 1) { HandStrength = 1689; return HandStrength; }
					if (n3 == 1) { HandStrength = 1688; return HandStrength; }
					if (n2 == 1) { HandStrength = 1687; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1686; return HandStrength; }
					if (n3 == 1) { HandStrength = 1685; return HandStrength; }
					if (n2 == 1) { HandStrength = 1684; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1683; return HandStrength; }
					if (n2 == 1) { HandStrength = 1682; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1681; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1680; return HandStrength; }
					if (n8 == 1) { HandStrength = 1679; return HandStrength; }
					if (n7 == 1) { HandStrength = 1678; return HandStrength; }
					if (n6 == 1) { HandStrength = 1677; return HandStrength; }
					if (n5 == 1) { HandStrength = 1676; return HandStrength; }
					if (n4 == 1) { HandStrength = 1675; return HandStrength; }
					if (n3 == 1) { HandStrength = 1674; return HandStrength; }
					if (n2 == 1) { HandStrength = 1673; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1672; return HandStrength; }
					if (n7 == 1) { HandStrength = 1671; return HandStrength; }
					if (n6 == 1) { HandStrength = 1670; return HandStrength; }
					if (n5 == 1) { HandStrength = 1669; return HandStrength; }
					if (n4 == 1) { HandStrength = 1668; return HandStrength; }
					if (n3 == 1) { HandStrength = 1667; return HandStrength; }
					if (n2 == 1) { HandStrength = 1666; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1665; return HandStrength; }
					if (n6 == 1) { HandStrength = 1664; return HandStrength; }
					if (n5 == 1) { HandStrength = 1663; return HandStrength; }
					if (n4 == 1) { HandStrength = 1662; return HandStrength; }
					if (n3 == 1) { HandStrength = 1661; return HandStrength; }
					if (n2 == 1) { HandStrength = 1660; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1659; return HandStrength; }
					if (n5 == 1) { HandStrength = 1658; return HandStrength; }
					if (n4 == 1) { HandStrength = 1657; return HandStrength; }
					if (n3 == 1) { HandStrength = 1656; return HandStrength; }
					if (n2 == 1) { HandStrength = 1655; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1654; return HandStrength; }
					if (n4 == 1) { HandStrength = 1653; return HandStrength; }
					if (n3 == 1) { HandStrength = 1652; return HandStrength; }
					if (n2 == 1) { HandStrength = 1651; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1650; return HandStrength; }
					if (n3 == 1) { HandStrength = 1649; return HandStrength; }
					if (n2 == 1) { HandStrength = 1648; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1647; return HandStrength; }
					if (n2 == 1) { HandStrength = 1646; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1645; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1644; return HandStrength; }
					if (n7 == 1) { HandStrength = 1643; return HandStrength; }
					if (n6 == 1) { HandStrength = 1642; return HandStrength; }
					if (n5 == 1) { HandStrength = 1641; return HandStrength; }
					if (n4 == 1) { HandStrength = 1640; return HandStrength; }
					if (n3 == 1) { HandStrength = 1639; return HandStrength; }
					if (n2 == 1) { HandStrength = 1638; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1637; return HandStrength; }
					if (n6 == 1) { HandStrength = 1636; return HandStrength; }
					if (n5 == 1) { HandStrength = 1635; return HandStrength; }
					if (n4 == 1) { HandStrength = 1634; return HandStrength; }
					if (n3 == 1) { HandStrength = 1633; return HandStrength; }
					if (n2 == 1) { HandStrength = 1632; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1631; return HandStrength; }
					if (n5 == 1) { HandStrength = 1630; return HandStrength; }
					if (n4 == 1) { HandStrength = 1629; return HandStrength; }
					if (n3 == 1) { HandStrength = 1628; return HandStrength; }
					if (n2 == 1) { HandStrength = 1627; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1626; return HandStrength; }
					if (n4 == 1) { HandStrength = 1625; return HandStrength; }
					if (n3 == 1) { HandStrength = 1624; return HandStrength; }
					if (n2 == 1) { HandStrength = 1623; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1622; return HandStrength; }
					if (n3 == 1) { HandStrength = 1621; return HandStrength; }
					if (n2 == 1) { HandStrength = 1620; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1619; return HandStrength; }
					if (n2 == 1) { HandStrength = 1618; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1617; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1616; return HandStrength; }
					if (n6 == 1) { HandStrength = 1615; return HandStrength; }
					if (n5 == 1) { HandStrength = 1614; return HandStrength; }
					if (n4 == 1) { HandStrength = 1613; return HandStrength; }
					if (n3 == 1) { HandStrength = 1612; return HandStrength; }
					if (n2 == 1) { HandStrength = 1611; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1610; return HandStrength; }
					if (n5 == 1) { HandStrength = 1609; return HandStrength; }
					if (n4 == 1) { HandStrength = 1608; return HandStrength; }
					if (n3 == 1) { HandStrength = 1607; return HandStrength; }
					if (n2 == 1) { HandStrength = 1606; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1605; return HandStrength; }
					if (n4 == 1) { HandStrength = 1604; return HandStrength; }
					if (n3 == 1) { HandStrength = 1603; return HandStrength; }
					if (n2 == 1) { HandStrength = 1602; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1601; return HandStrength; }
					if (n3 == 1) { HandStrength = 1600; return HandStrength; }
					if (n2 == 1) { HandStrength = 1599; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1598; return HandStrength; }
					if (n2 == 1) { HandStrength = 1597; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1596; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1595; return HandStrength; }
					if (n5 == 1) { HandStrength = 1594; return HandStrength; }
					if (n4 == 1) { HandStrength = 1593; return HandStrength; }
					if (n3 == 1) { HandStrength = 1592; return HandStrength; }
					if (n2 == 1) { HandStrength = 1591; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1590; return HandStrength; }
					if (n4 == 1) { HandStrength = 1589; return HandStrength; }
					if (n3 == 1) { HandStrength = 1588; return HandStrength; }
					if (n2 == 1) { HandStrength = 1587; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1586; return HandStrength; }
					if (n3 == 1) { HandStrength = 1585; return HandStrength; }
					if (n2 == 1) { HandStrength = 1584; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1583; return HandStrength; }
					if (n2 == 1) { HandStrength = 1582; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1581; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1580; return HandStrength; }
					if (n4 == 1) { HandStrength = 1579; return HandStrength; }
					if (n3 == 1) { HandStrength = 1578; return HandStrength; }
					if (n2 == 1) { HandStrength = 1577; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1576; return HandStrength; }
					if (n3 == 1) { HandStrength = 1575; return HandStrength; }
					if (n2 == 1) { HandStrength = 1574; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1573; return HandStrength; }
					if (n2 == 1) { HandStrength = 1572; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1571; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1570; return HandStrength; }
					if (n3 == 1) { HandStrength = 1569; return HandStrength; }
					if (n2 == 1) { HandStrength = 1568; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1567; return HandStrength; }
					if (n2 == 1) { HandStrength = 1566; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1565; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1564; return HandStrength; }
					if (n2 == 1) { HandStrength = 1563; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1562; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1561; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nQ == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nJ == 1) { HandStrength = 1560; return HandStrength; }
					if (nT == 1) { HandStrength = 1559; return HandStrength; }
					if (n9 == 1) { HandStrength = 1558; return HandStrength; }
					if (n8 == 1) { HandStrength = 1557; return HandStrength; }
					if (n7 == 1) { HandStrength = 1556; return HandStrength; }
					if (n6 == 1) { HandStrength = 1555; return HandStrength; }
					if (n5 == 1) { HandStrength = 1554; return HandStrength; }
					if (n4 == 1) { HandStrength = 1553; return HandStrength; }
					if (n3 == 1) { HandStrength = 1552; return HandStrength; }
					if (n2 == 1) { HandStrength = 1551; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1550; return HandStrength; }
					if (n9 == 1) { HandStrength = 1549; return HandStrength; }
					if (n8 == 1) { HandStrength = 1548; return HandStrength; }
					if (n7 == 1) { HandStrength = 1547; return HandStrength; }
					if (n6 == 1) { HandStrength = 1546; return HandStrength; }
					if (n5 == 1) { HandStrength = 1545; return HandStrength; }
					if (n4 == 1) { HandStrength = 1544; return HandStrength; }
					if (n3 == 1) { HandStrength = 1543; return HandStrength; }
					if (n2 == 1) { HandStrength = 1542; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1541; return HandStrength; }
					if (n8 == 1) { HandStrength = 1540; return HandStrength; }
					if (n7 == 1) { HandStrength = 1539; return HandStrength; }
					if (n6 == 1) { HandStrength = 1538; return HandStrength; }
					if (n5 == 1) { HandStrength = 1537; return HandStrength; }
					if (n4 == 1) { HandStrength = 1536; return HandStrength; }
					if (n3 == 1) { HandStrength = 1535; return HandStrength; }
					if (n2 == 1) { HandStrength = 1534; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1533; return HandStrength; }
					if (n7 == 1) { HandStrength = 1532; return HandStrength; }
					if (n6 == 1) { HandStrength = 1531; return HandStrength; }
					if (n5 == 1) { HandStrength = 1530; return HandStrength; }
					if (n4 == 1) { HandStrength = 1529; return HandStrength; }
					if (n3 == 1) { HandStrength = 1528; return HandStrength; }
					if (n2 == 1) { HandStrength = 1527; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1526; return HandStrength; }
					if (n6 == 1) { HandStrength = 1525; return HandStrength; }
					if (n5 == 1) { HandStrength = 1524; return HandStrength; }
					if (n4 == 1) { HandStrength = 1523; return HandStrength; }
					if (n3 == 1) { HandStrength = 1522; return HandStrength; }
					if (n2 == 1) { HandStrength = 1521; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1520; return HandStrength; }
					if (n5 == 1) { HandStrength = 1519; return HandStrength; }
					if (n4 == 1) { HandStrength = 1518; return HandStrength; }
					if (n3 == 1) { HandStrength = 1517; return HandStrength; }
					if (n2 == 1) { HandStrength = 1516; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1515; return HandStrength; }
					if (n4 == 1) { HandStrength = 1514; return HandStrength; }
					if (n3 == 1) { HandStrength = 1513; return HandStrength; }
					if (n2 == 1) { HandStrength = 1512; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1511; return HandStrength; }
					if (n3 == 1) { HandStrength = 1510; return HandStrength; }
					if (n2 == 1) { HandStrength = 1509; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1508; return HandStrength; }
					if (n2 == 1) { HandStrength = 1507; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1506; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1505; return HandStrength; }
					if (n9 == 1) { HandStrength = 1504; return HandStrength; }
					if (n8 == 1) { HandStrength = 1503; return HandStrength; }
					if (n7 == 1) { HandStrength = 1502; return HandStrength; }
					if (n6 == 1) { HandStrength = 1501; return HandStrength; }
					if (n5 == 1) { HandStrength = 1500; return HandStrength; }
					if (n4 == 1) { HandStrength = 1499; return HandStrength; }
					if (n3 == 1) { HandStrength = 1498; return HandStrength; }
					if (n2 == 1) { HandStrength = 1497; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1496; return HandStrength; }
					if (n8 == 1) { HandStrength = 1495; return HandStrength; }
					if (n7 == 1) { HandStrength = 1494; return HandStrength; }
					if (n6 == 1) { HandStrength = 1493; return HandStrength; }
					if (n5 == 1) { HandStrength = 1492; return HandStrength; }
					if (n4 == 1) { HandStrength = 1491; return HandStrength; }
					if (n3 == 1) { HandStrength = 1490; return HandStrength; }
					if (n2 == 1) { HandStrength = 1489; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1488; return HandStrength; }
					if (n7 == 1) { HandStrength = 1487; return HandStrength; }
					if (n6 == 1) { HandStrength = 1486; return HandStrength; }
					if (n5 == 1) { HandStrength = 1485; return HandStrength; }
					if (n4 == 1) { HandStrength = 1484; return HandStrength; }
					if (n3 == 1) { HandStrength = 1483; return HandStrength; }
					if (n2 == 1) { HandStrength = 1482; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1481; return HandStrength; }
					if (n6 == 1) { HandStrength = 1480; return HandStrength; }
					if (n5 == 1) { HandStrength = 1479; return HandStrength; }
					if (n4 == 1) { HandStrength = 1478; return HandStrength; }
					if (n3 == 1) { HandStrength = 1477; return HandStrength; }
					if (n2 == 1) { HandStrength = 1476; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1475; return HandStrength; }
					if (n5 == 1) { HandStrength = 1474; return HandStrength; }
					if (n4 == 1) { HandStrength = 1473; return HandStrength; }
					if (n3 == 1) { HandStrength = 1472; return HandStrength; }
					if (n2 == 1) { HandStrength = 1471; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1470; return HandStrength; }
					if (n4 == 1) { HandStrength = 1469; return HandStrength; }
					if (n3 == 1) { HandStrength = 1468; return HandStrength; }
					if (n2 == 1) { HandStrength = 1467; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1466; return HandStrength; }
					if (n3 == 1) { HandStrength = 1465; return HandStrength; }
					if (n2 == 1) { HandStrength = 1464; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1463; return HandStrength; }
					if (n2 == 1) { HandStrength = 1462; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1461; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1460; return HandStrength; }
					if (n8 == 1) { HandStrength = 1459; return HandStrength; }
					if (n7 == 1) { HandStrength = 1458; return HandStrength; }
					if (n6 == 1) { HandStrength = 1457; return HandStrength; }
					if (n5 == 1) { HandStrength = 1456; return HandStrength; }
					if (n4 == 1) { HandStrength = 1455; return HandStrength; }
					if (n3 == 1) { HandStrength = 1454; return HandStrength; }
					if (n2 == 1) { HandStrength = 1453; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1452; return HandStrength; }
					if (n7 == 1) { HandStrength = 1451; return HandStrength; }
					if (n6 == 1) { HandStrength = 1450; return HandStrength; }
					if (n5 == 1) { HandStrength = 1449; return HandStrength; }
					if (n4 == 1) { HandStrength = 1448; return HandStrength; }
					if (n3 == 1) { HandStrength = 1447; return HandStrength; }
					if (n2 == 1) { HandStrength = 1446; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1445; return HandStrength; }
					if (n6 == 1) { HandStrength = 1444; return HandStrength; }
					if (n5 == 1) { HandStrength = 1443; return HandStrength; }
					if (n4 == 1) { HandStrength = 1442; return HandStrength; }
					if (n3 == 1) { HandStrength = 1441; return HandStrength; }
					if (n2 == 1) { HandStrength = 1440; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1439; return HandStrength; }
					if (n5 == 1) { HandStrength = 1438; return HandStrength; }
					if (n4 == 1) { HandStrength = 1437; return HandStrength; }
					if (n3 == 1) { HandStrength = 1436; return HandStrength; }
					if (n2 == 1) { HandStrength = 1435; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1434; return HandStrength; }
					if (n4 == 1) { HandStrength = 1433; return HandStrength; }
					if (n3 == 1) { HandStrength = 1432; return HandStrength; }
					if (n2 == 1) { HandStrength = 1431; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1430; return HandStrength; }
					if (n3 == 1) { HandStrength = 1429; return HandStrength; }
					if (n2 == 1) { HandStrength = 1428; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1427; return HandStrength; }
					if (n2 == 1) { HandStrength = 1426; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1425; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1424; return HandStrength; }
					if (n7 == 1) { HandStrength = 1423; return HandStrength; }
					if (n6 == 1) { HandStrength = 1422; return HandStrength; }
					if (n5 == 1) { HandStrength = 1421; return HandStrength; }
					if (n4 == 1) { HandStrength = 1420; return HandStrength; }
					if (n3 == 1) { HandStrength = 1419; return HandStrength; }
					if (n2 == 1) { HandStrength = 1418; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1417; return HandStrength; }
					if (n6 == 1) { HandStrength = 1416; return HandStrength; }
					if (n5 == 1) { HandStrength = 1415; return HandStrength; }
					if (n4 == 1) { HandStrength = 1414; return HandStrength; }
					if (n3 == 1) { HandStrength = 1413; return HandStrength; }
					if (n2 == 1) { HandStrength = 1412; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1411; return HandStrength; }
					if (n5 == 1) { HandStrength = 1410; return HandStrength; }
					if (n4 == 1) { HandStrength = 1409; return HandStrength; }
					if (n3 == 1) { HandStrength = 1408; return HandStrength; }
					if (n2 == 1) { HandStrength = 1407; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1406; return HandStrength; }
					if (n4 == 1) { HandStrength = 1405; return HandStrength; }
					if (n3 == 1) { HandStrength = 1404; return HandStrength; }
					if (n2 == 1) { HandStrength = 1403; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1402; return HandStrength; }
					if (n3 == 1) { HandStrength = 1401; return HandStrength; }
					if (n2 == 1) { HandStrength = 1400; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1399; return HandStrength; }
					if (n2 == 1) { HandStrength = 1398; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1397; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1396; return HandStrength; }
					if (n6 == 1) { HandStrength = 1395; return HandStrength; }
					if (n5 == 1) { HandStrength = 1394; return HandStrength; }
					if (n4 == 1) { HandStrength = 1393; return HandStrength; }
					if (n3 == 1) { HandStrength = 1392; return HandStrength; }
					if (n2 == 1) { HandStrength = 1391; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1390; return HandStrength; }
					if (n5 == 1) { HandStrength = 1389; return HandStrength; }
					if (n4 == 1) { HandStrength = 1388; return HandStrength; }
					if (n3 == 1) { HandStrength = 1387; return HandStrength; }
					if (n2 == 1) { HandStrength = 1386; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1385; return HandStrength; }
					if (n4 == 1) { HandStrength = 1384; return HandStrength; }
					if (n3 == 1) { HandStrength = 1383; return HandStrength; }
					if (n2 == 1) { HandStrength = 1382; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1381; return HandStrength; }
					if (n3 == 1) { HandStrength = 1380; return HandStrength; }
					if (n2 == 1) { HandStrength = 1379; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1378; return HandStrength; }
					if (n2 == 1) { HandStrength = 1377; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1376; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1375; return HandStrength; }
					if (n5 == 1) { HandStrength = 1374; return HandStrength; }
					if (n4 == 1) { HandStrength = 1373; return HandStrength; }
					if (n3 == 1) { HandStrength = 1372; return HandStrength; }
					if (n2 == 1) { HandStrength = 1371; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1370; return HandStrength; }
					if (n4 == 1) { HandStrength = 1369; return HandStrength; }
					if (n3 == 1) { HandStrength = 1368; return HandStrength; }
					if (n2 == 1) { HandStrength = 1367; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1366; return HandStrength; }
					if (n3 == 1) { HandStrength = 1365; return HandStrength; }
					if (n2 == 1) { HandStrength = 1364; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1363; return HandStrength; }
					if (n2 == 1) { HandStrength = 1362; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1361; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1360; return HandStrength; }
					if (n4 == 1) { HandStrength = 1359; return HandStrength; }
					if (n3 == 1) { HandStrength = 1358; return HandStrength; }
					if (n2 == 1) { HandStrength = 1357; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1356; return HandStrength; }
					if (n3 == 1) { HandStrength = 1355; return HandStrength; }
					if (n2 == 1) { HandStrength = 1354; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1353; return HandStrength; }
					if (n2 == 1) { HandStrength = 1352; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1351; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1350; return HandStrength; }
					if (n3 == 1) { HandStrength = 1349; return HandStrength; }
					if (n2 == 1) { HandStrength = 1348; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1347; return HandStrength; }
					if (n2 == 1) { HandStrength = 1346; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1345; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1344; return HandStrength; }
					if (n2 == 1) { HandStrength = 1343; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1342; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1341; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nJ == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 1340; return HandStrength; }
					if (nT == 1) { HandStrength = 1339; return HandStrength; }
					if (n9 == 1) { HandStrength = 1338; return HandStrength; }
					if (n8 == 1) { HandStrength = 1337; return HandStrength; }
					if (n7 == 1) { HandStrength = 1336; return HandStrength; }
					if (n6 == 1) { HandStrength = 1335; return HandStrength; }
					if (n5 == 1) { HandStrength = 1334; return HandStrength; }
					if (n4 == 1) { HandStrength = 1333; return HandStrength; }
					if (n3 == 1) { HandStrength = 1332; return HandStrength; }
					if (n2 == 1) { HandStrength = 1331; return HandStrength; }
				};
				if (nQ == 1) {
					if (nT == 1) { HandStrength = 1330; return HandStrength; }
					if (n9 == 1) { HandStrength = 1329; return HandStrength; }
					if (n8 == 1) { HandStrength = 1328; return HandStrength; }
					if (n7 == 1) { HandStrength = 1327; return HandStrength; }
					if (n6 == 1) { HandStrength = 1326; return HandStrength; }
					if (n5 == 1) { HandStrength = 1325; return HandStrength; }
					if (n4 == 1) { HandStrength = 1324; return HandStrength; }
					if (n3 == 1) { HandStrength = 1323; return HandStrength; }
					if (n2 == 1) { HandStrength = 1322; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1321; return HandStrength; }
					if (n8 == 1) { HandStrength = 1320; return HandStrength; }
					if (n7 == 1) { HandStrength = 1319; return HandStrength; }
					if (n6 == 1) { HandStrength = 1318; return HandStrength; }
					if (n5 == 1) { HandStrength = 1317; return HandStrength; }
					if (n4 == 1) { HandStrength = 1316; return HandStrength; }
					if (n3 == 1) { HandStrength = 1315; return HandStrength; }
					if (n2 == 1) { HandStrength = 1314; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1313; return HandStrength; }
					if (n7 == 1) { HandStrength = 1312; return HandStrength; }
					if (n6 == 1) { HandStrength = 1311; return HandStrength; }
					if (n5 == 1) { HandStrength = 1310; return HandStrength; }
					if (n4 == 1) { HandStrength = 1309; return HandStrength; }
					if (n3 == 1) { HandStrength = 1308; return HandStrength; }
					if (n2 == 1) { HandStrength = 1307; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1306; return HandStrength; }
					if (n6 == 1) { HandStrength = 1305; return HandStrength; }
					if (n5 == 1) { HandStrength = 1304; return HandStrength; }
					if (n4 == 1) { HandStrength = 1303; return HandStrength; }
					if (n3 == 1) { HandStrength = 1302; return HandStrength; }
					if (n2 == 1) { HandStrength = 1301; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1300; return HandStrength; }
					if (n5 == 1) { HandStrength = 1299; return HandStrength; }
					if (n4 == 1) { HandStrength = 1298; return HandStrength; }
					if (n3 == 1) { HandStrength = 1297; return HandStrength; }
					if (n2 == 1) { HandStrength = 1296; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1295; return HandStrength; }
					if (n4 == 1) { HandStrength = 1294; return HandStrength; }
					if (n3 == 1) { HandStrength = 1293; return HandStrength; }
					if (n2 == 1) { HandStrength = 1292; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1291; return HandStrength; }
					if (n3 == 1) { HandStrength = 1290; return HandStrength; }
					if (n2 == 1) { HandStrength = 1289; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1288; return HandStrength; }
					if (n2 == 1) { HandStrength = 1287; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1286; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nT == 1) { HandStrength = 1285; return HandStrength; }
					if (n9 == 1) { HandStrength = 1284; return HandStrength; }
					if (n8 == 1) { HandStrength = 1283; return HandStrength; }
					if (n7 == 1) { HandStrength = 1282; return HandStrength; }
					if (n6 == 1) { HandStrength = 1281; return HandStrength; }
					if (n5 == 1) { HandStrength = 1280; return HandStrength; }
					if (n4 == 1) { HandStrength = 1279; return HandStrength; }
					if (n3 == 1) { HandStrength = 1278; return HandStrength; }
					if (n2 == 1) { HandStrength = 1277; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1276; return HandStrength; }
					if (n8 == 1) { HandStrength = 1275; return HandStrength; }
					if (n7 == 1) { HandStrength = 1274; return HandStrength; }
					if (n6 == 1) { HandStrength = 1273; return HandStrength; }
					if (n5 == 1) { HandStrength = 1272; return HandStrength; }
					if (n4 == 1) { HandStrength = 1271; return HandStrength; }
					if (n3 == 1) { HandStrength = 1270; return HandStrength; }
					if (n2 == 1) { HandStrength = 1269; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1268; return HandStrength; }
					if (n7 == 1) { HandStrength = 1267; return HandStrength; }
					if (n6 == 1) { HandStrength = 1266; return HandStrength; }
					if (n5 == 1) { HandStrength = 1265; return HandStrength; }
					if (n4 == 1) { HandStrength = 1264; return HandStrength; }
					if (n3 == 1) { HandStrength = 1263; return HandStrength; }
					if (n2 == 1) { HandStrength = 1262; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1261; return HandStrength; }
					if (n6 == 1) { HandStrength = 1260; return HandStrength; }
					if (n5 == 1) { HandStrength = 1259; return HandStrength; }
					if (n4 == 1) { HandStrength = 1258; return HandStrength; }
					if (n3 == 1) { HandStrength = 1257; return HandStrength; }
					if (n2 == 1) { HandStrength = 1256; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1255; return HandStrength; }
					if (n5 == 1) { HandStrength = 1254; return HandStrength; }
					if (n4 == 1) { HandStrength = 1253; return HandStrength; }
					if (n3 == 1) { HandStrength = 1252; return HandStrength; }
					if (n2 == 1) { HandStrength = 1251; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1250; return HandStrength; }
					if (n4 == 1) { HandStrength = 1249; return HandStrength; }
					if (n3 == 1) { HandStrength = 1248; return HandStrength; }
					if (n2 == 1) { HandStrength = 1247; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1246; return HandStrength; }
					if (n3 == 1) { HandStrength = 1245; return HandStrength; }
					if (n2 == 1) { HandStrength = 1244; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1243; return HandStrength; }
					if (n2 == 1) { HandStrength = 1242; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1241; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 1240; return HandStrength; }
					if (n8 == 1) { HandStrength = 1239; return HandStrength; }
					if (n7 == 1) { HandStrength = 1238; return HandStrength; }
					if (n6 == 1) { HandStrength = 1237; return HandStrength; }
					if (n5 == 1) { HandStrength = 1236; return HandStrength; }
					if (n4 == 1) { HandStrength = 1235; return HandStrength; }
					if (n3 == 1) { HandStrength = 1234; return HandStrength; }
					if (n2 == 1) { HandStrength = 1233; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1232; return HandStrength; }
					if (n7 == 1) { HandStrength = 1231; return HandStrength; }
					if (n6 == 1) { HandStrength = 1230; return HandStrength; }
					if (n5 == 1) { HandStrength = 1229; return HandStrength; }
					if (n4 == 1) { HandStrength = 1228; return HandStrength; }
					if (n3 == 1) { HandStrength = 1227; return HandStrength; }
					if (n2 == 1) { HandStrength = 1226; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1225; return HandStrength; }
					if (n6 == 1) { HandStrength = 1224; return HandStrength; }
					if (n5 == 1) { HandStrength = 1223; return HandStrength; }
					if (n4 == 1) { HandStrength = 1222; return HandStrength; }
					if (n3 == 1) { HandStrength = 1221; return HandStrength; }
					if (n2 == 1) { HandStrength = 1220; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1219; return HandStrength; }
					if (n5 == 1) { HandStrength = 1218; return HandStrength; }
					if (n4 == 1) { HandStrength = 1217; return HandStrength; }
					if (n3 == 1) { HandStrength = 1216; return HandStrength; }
					if (n2 == 1) { HandStrength = 1215; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1214; return HandStrength; }
					if (n4 == 1) { HandStrength = 1213; return HandStrength; }
					if (n3 == 1) { HandStrength = 1212; return HandStrength; }
					if (n2 == 1) { HandStrength = 1211; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1210; return HandStrength; }
					if (n3 == 1) { HandStrength = 1209; return HandStrength; }
					if (n2 == 1) { HandStrength = 1208; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1207; return HandStrength; }
					if (n2 == 1) { HandStrength = 1206; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1205; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1204; return HandStrength; }
					if (n7 == 1) { HandStrength = 1203; return HandStrength; }
					if (n6 == 1) { HandStrength = 1202; return HandStrength; }
					if (n5 == 1) { HandStrength = 1201; return HandStrength; }
					if (n4 == 1) { HandStrength = 1200; return HandStrength; }
					if (n3 == 1) { HandStrength = 1199; return HandStrength; }
					if (n2 == 1) { HandStrength = 1198; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1197; return HandStrength; }
					if (n6 == 1) { HandStrength = 1196; return HandStrength; }
					if (n5 == 1) { HandStrength = 1195; return HandStrength; }
					if (n4 == 1) { HandStrength = 1194; return HandStrength; }
					if (n3 == 1) { HandStrength = 1193; return HandStrength; }
					if (n2 == 1) { HandStrength = 1192; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1191; return HandStrength; }
					if (n5 == 1) { HandStrength = 1190; return HandStrength; }
					if (n4 == 1) { HandStrength = 1189; return HandStrength; }
					if (n3 == 1) { HandStrength = 1188; return HandStrength; }
					if (n2 == 1) { HandStrength = 1187; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1186; return HandStrength; }
					if (n4 == 1) { HandStrength = 1185; return HandStrength; }
					if (n3 == 1) { HandStrength = 1184; return HandStrength; }
					if (n2 == 1) { HandStrength = 1183; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1182; return HandStrength; }
					if (n3 == 1) { HandStrength = 1181; return HandStrength; }
					if (n2 == 1) { HandStrength = 1180; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1179; return HandStrength; }
					if (n2 == 1) { HandStrength = 1178; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1177; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1176; return HandStrength; }
					if (n6 == 1) { HandStrength = 1175; return HandStrength; }
					if (n5 == 1) { HandStrength = 1174; return HandStrength; }
					if (n4 == 1) { HandStrength = 1173; return HandStrength; }
					if (n3 == 1) { HandStrength = 1172; return HandStrength; }
					if (n2 == 1) { HandStrength = 1171; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1170; return HandStrength; }
					if (n5 == 1) { HandStrength = 1169; return HandStrength; }
					if (n4 == 1) { HandStrength = 1168; return HandStrength; }
					if (n3 == 1) { HandStrength = 1167; return HandStrength; }
					if (n2 == 1) { HandStrength = 1166; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1165; return HandStrength; }
					if (n4 == 1) { HandStrength = 1164; return HandStrength; }
					if (n3 == 1) { HandStrength = 1163; return HandStrength; }
					if (n2 == 1) { HandStrength = 1162; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1161; return HandStrength; }
					if (n3 == 1) { HandStrength = 1160; return HandStrength; }
					if (n2 == 1) { HandStrength = 1159; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1158; return HandStrength; }
					if (n2 == 1) { HandStrength = 1157; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1156; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1155; return HandStrength; }
					if (n5 == 1) { HandStrength = 1154; return HandStrength; }
					if (n4 == 1) { HandStrength = 1153; return HandStrength; }
					if (n3 == 1) { HandStrength = 1152; return HandStrength; }
					if (n2 == 1) { HandStrength = 1151; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1150; return HandStrength; }
					if (n4 == 1) { HandStrength = 1149; return HandStrength; }
					if (n3 == 1) { HandStrength = 1148; return HandStrength; }
					if (n2 == 1) { HandStrength = 1147; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1146; return HandStrength; }
					if (n3 == 1) { HandStrength = 1145; return HandStrength; }
					if (n2 == 1) { HandStrength = 1144; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1143; return HandStrength; }
					if (n2 == 1) { HandStrength = 1142; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1141; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1140; return HandStrength; }
					if (n4 == 1) { HandStrength = 1139; return HandStrength; }
					if (n3 == 1) { HandStrength = 1138; return HandStrength; }
					if (n2 == 1) { HandStrength = 1137; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1136; return HandStrength; }
					if (n3 == 1) { HandStrength = 1135; return HandStrength; }
					if (n2 == 1) { HandStrength = 1134; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1133; return HandStrength; }
					if (n2 == 1) { HandStrength = 1132; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1131; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1130; return HandStrength; }
					if (n3 == 1) { HandStrength = 1129; return HandStrength; }
					if (n2 == 1) { HandStrength = 1128; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1127; return HandStrength; }
					if (n2 == 1) { HandStrength = 1126; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1125; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1124; return HandStrength; }
					if (n2 == 1) { HandStrength = 1123; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1122; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1121; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nT == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 1120; return HandStrength; }
					if (nJ == 1) { HandStrength = 1119; return HandStrength; }
					if (n9 == 1) { HandStrength = 1118; return HandStrength; }
					if (n8 == 1) { HandStrength = 1117; return HandStrength; }
					if (n7 == 1) { HandStrength = 1116; return HandStrength; }
					if (n6 == 1) { HandStrength = 1115; return HandStrength; }
					if (n5 == 1) { HandStrength = 1114; return HandStrength; }
					if (n4 == 1) { HandStrength = 1113; return HandStrength; }
					if (n3 == 1) { HandStrength = 1112; return HandStrength; }
					if (n2 == 1) { HandStrength = 1111; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 1110; return HandStrength; }
					if (n9 == 1) { HandStrength = 1109; return HandStrength; }
					if (n8 == 1) { HandStrength = 1108; return HandStrength; }
					if (n7 == 1) { HandStrength = 1107; return HandStrength; }
					if (n6 == 1) { HandStrength = 1106; return HandStrength; }
					if (n5 == 1) { HandStrength = 1105; return HandStrength; }
					if (n4 == 1) { HandStrength = 1104; return HandStrength; }
					if (n3 == 1) { HandStrength = 1103; return HandStrength; }
					if (n2 == 1) { HandStrength = 1102; return HandStrength; }
				};
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 1101; return HandStrength; }
					if (n8 == 1) { HandStrength = 1100; return HandStrength; }
					if (n7 == 1) { HandStrength = 1099; return HandStrength; }
					if (n6 == 1) { HandStrength = 1098; return HandStrength; }
					if (n5 == 1) { HandStrength = 1097; return HandStrength; }
					if (n4 == 1) { HandStrength = 1096; return HandStrength; }
					if (n3 == 1) { HandStrength = 1095; return HandStrength; }
					if (n2 == 1) { HandStrength = 1094; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1093; return HandStrength; }
					if (n7 == 1) { HandStrength = 1092; return HandStrength; }
					if (n6 == 1) { HandStrength = 1091; return HandStrength; }
					if (n5 == 1) { HandStrength = 1090; return HandStrength; }
					if (n4 == 1) { HandStrength = 1089; return HandStrength; }
					if (n3 == 1) { HandStrength = 1088; return HandStrength; }
					if (n2 == 1) { HandStrength = 1087; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1086; return HandStrength; }
					if (n6 == 1) { HandStrength = 1085; return HandStrength; }
					if (n5 == 1) { HandStrength = 1084; return HandStrength; }
					if (n4 == 1) { HandStrength = 1083; return HandStrength; }
					if (n3 == 1) { HandStrength = 1082; return HandStrength; }
					if (n2 == 1) { HandStrength = 1081; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1080; return HandStrength; }
					if (n5 == 1) { HandStrength = 1079; return HandStrength; }
					if (n4 == 1) { HandStrength = 1078; return HandStrength; }
					if (n3 == 1) { HandStrength = 1077; return HandStrength; }
					if (n2 == 1) { HandStrength = 1076; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1075; return HandStrength; }
					if (n4 == 1) { HandStrength = 1074; return HandStrength; }
					if (n3 == 1) { HandStrength = 1073; return HandStrength; }
					if (n2 == 1) { HandStrength = 1072; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1071; return HandStrength; }
					if (n3 == 1) { HandStrength = 1070; return HandStrength; }
					if (n2 == 1) { HandStrength = 1069; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1068; return HandStrength; }
					if (n2 == 1) { HandStrength = 1067; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1066; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 1065; return HandStrength; }
					if (n9 == 1) { HandStrength = 1064; return HandStrength; }
					if (n8 == 1) { HandStrength = 1063; return HandStrength; }
					if (n7 == 1) { HandStrength = 1062; return HandStrength; }
					if (n6 == 1) { HandStrength = 1061; return HandStrength; }
					if (n5 == 1) { HandStrength = 1060; return HandStrength; }
					if (n4 == 1) { HandStrength = 1059; return HandStrength; }
					if (n3 == 1) { HandStrength = 1058; return HandStrength; }
					if (n2 == 1) { HandStrength = 1057; return HandStrength; }
				};
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 1056; return HandStrength; }
					if (n8 == 1) { HandStrength = 1055; return HandStrength; }
					if (n7 == 1) { HandStrength = 1054; return HandStrength; }
					if (n6 == 1) { HandStrength = 1053; return HandStrength; }
					if (n5 == 1) { HandStrength = 1052; return HandStrength; }
					if (n4 == 1) { HandStrength = 1051; return HandStrength; }
					if (n3 == 1) { HandStrength = 1050; return HandStrength; }
					if (n2 == 1) { HandStrength = 1049; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1048; return HandStrength; }
					if (n7 == 1) { HandStrength = 1047; return HandStrength; }
					if (n6 == 1) { HandStrength = 1046; return HandStrength; }
					if (n5 == 1) { HandStrength = 1045; return HandStrength; }
					if (n4 == 1) { HandStrength = 1044; return HandStrength; }
					if (n3 == 1) { HandStrength = 1043; return HandStrength; }
					if (n2 == 1) { HandStrength = 1042; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1041; return HandStrength; }
					if (n6 == 1) { HandStrength = 1040; return HandStrength; }
					if (n5 == 1) { HandStrength = 1039; return HandStrength; }
					if (n4 == 1) { HandStrength = 1038; return HandStrength; }
					if (n3 == 1) { HandStrength = 1037; return HandStrength; }
					if (n2 == 1) { HandStrength = 1036; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 1035; return HandStrength; }
					if (n5 == 1) { HandStrength = 1034; return HandStrength; }
					if (n4 == 1) { HandStrength = 1033; return HandStrength; }
					if (n3 == 1) { HandStrength = 1032; return HandStrength; }
					if (n2 == 1) { HandStrength = 1031; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 1030; return HandStrength; }
					if (n4 == 1) { HandStrength = 1029; return HandStrength; }
					if (n3 == 1) { HandStrength = 1028; return HandStrength; }
					if (n2 == 1) { HandStrength = 1027; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 1026; return HandStrength; }
					if (n3 == 1) { HandStrength = 1025; return HandStrength; }
					if (n2 == 1) { HandStrength = 1024; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 1023; return HandStrength; }
					if (n2 == 1) { HandStrength = 1022; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 1021; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (n9 == 1) { HandStrength = 1020; return HandStrength; }
					if (n8 == 1) { HandStrength = 1019; return HandStrength; }
					if (n7 == 1) { HandStrength = 1018; return HandStrength; }
					if (n6 == 1) { HandStrength = 1017; return HandStrength; }
					if (n5 == 1) { HandStrength = 1016; return HandStrength; }
					if (n4 == 1) { HandStrength = 1015; return HandStrength; }
					if (n3 == 1) { HandStrength = 1014; return HandStrength; }
					if (n2 == 1) { HandStrength = 1013; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 1012; return HandStrength; }
					if (n7 == 1) { HandStrength = 1011; return HandStrength; }
					if (n6 == 1) { HandStrength = 1010; return HandStrength; }
					if (n5 == 1) { HandStrength = 1009; return HandStrength; }
					if (n4 == 1) { HandStrength = 1008; return HandStrength; }
					if (n3 == 1) { HandStrength = 1007; return HandStrength; }
					if (n2 == 1) { HandStrength = 1006; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 1005; return HandStrength; }
					if (n6 == 1) { HandStrength = 1004; return HandStrength; }
					if (n5 == 1) { HandStrength = 1003; return HandStrength; }
					if (n4 == 1) { HandStrength = 1002; return HandStrength; }
					if (n3 == 1) { HandStrength = 1001; return HandStrength; }
					if (n2 == 1) { HandStrength = 1000; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 999; return HandStrength; }
					if (n5 == 1) { HandStrength = 998; return HandStrength; }
					if (n4 == 1) { HandStrength = 997; return HandStrength; }
					if (n3 == 1) { HandStrength = 996; return HandStrength; }
					if (n2 == 1) { HandStrength = 995; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 994; return HandStrength; }
					if (n4 == 1) { HandStrength = 993; return HandStrength; }
					if (n3 == 1) { HandStrength = 992; return HandStrength; }
					if (n2 == 1) { HandStrength = 991; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 990; return HandStrength; }
					if (n3 == 1) { HandStrength = 989; return HandStrength; }
					if (n2 == 1) { HandStrength = 988; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 987; return HandStrength; }
					if (n2 == 1) { HandStrength = 986; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 985; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 984; return HandStrength; }
					if (n7 == 1) { HandStrength = 983; return HandStrength; }
					if (n6 == 1) { HandStrength = 982; return HandStrength; }
					if (n5 == 1) { HandStrength = 981; return HandStrength; }
					if (n4 == 1) { HandStrength = 980; return HandStrength; }
					if (n3 == 1) { HandStrength = 979; return HandStrength; }
					if (n2 == 1) { HandStrength = 978; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 977; return HandStrength; }
					if (n6 == 1) { HandStrength = 976; return HandStrength; }
					if (n5 == 1) { HandStrength = 975; return HandStrength; }
					if (n4 == 1) { HandStrength = 974; return HandStrength; }
					if (n3 == 1) { HandStrength = 973; return HandStrength; }
					if (n2 == 1) { HandStrength = 972; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 971; return HandStrength; }
					if (n5 == 1) { HandStrength = 970; return HandStrength; }
					if (n4 == 1) { HandStrength = 969; return HandStrength; }
					if (n3 == 1) { HandStrength = 968; return HandStrength; }
					if (n2 == 1) { HandStrength = 967; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 966; return HandStrength; }
					if (n4 == 1) { HandStrength = 965; return HandStrength; }
					if (n3 == 1) { HandStrength = 964; return HandStrength; }
					if (n2 == 1) { HandStrength = 963; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 962; return HandStrength; }
					if (n3 == 1) { HandStrength = 961; return HandStrength; }
					if (n2 == 1) { HandStrength = 960; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 959; return HandStrength; }
					if (n2 == 1) { HandStrength = 958; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 957; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 956; return HandStrength; }
					if (n6 == 1) { HandStrength = 955; return HandStrength; }
					if (n5 == 1) { HandStrength = 954; return HandStrength; }
					if (n4 == 1) { HandStrength = 953; return HandStrength; }
					if (n3 == 1) { HandStrength = 952; return HandStrength; }
					if (n2 == 1) { HandStrength = 951; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 950; return HandStrength; }
					if (n5 == 1) { HandStrength = 949; return HandStrength; }
					if (n4 == 1) { HandStrength = 948; return HandStrength; }
					if (n3 == 1) { HandStrength = 947; return HandStrength; }
					if (n2 == 1) { HandStrength = 946; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 945; return HandStrength; }
					if (n4 == 1) { HandStrength = 944; return HandStrength; }
					if (n3 == 1) { HandStrength = 943; return HandStrength; }
					if (n2 == 1) { HandStrength = 942; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 941; return HandStrength; }
					if (n3 == 1) { HandStrength = 940; return HandStrength; }
					if (n2 == 1) { HandStrength = 939; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 938; return HandStrength; }
					if (n2 == 1) { HandStrength = 937; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 936; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 935; return HandStrength; }
					if (n5 == 1) { HandStrength = 934; return HandStrength; }
					if (n4 == 1) { HandStrength = 933; return HandStrength; }
					if (n3 == 1) { HandStrength = 932; return HandStrength; }
					if (n2 == 1) { HandStrength = 931; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 930; return HandStrength; }
					if (n4 == 1) { HandStrength = 929; return HandStrength; }
					if (n3 == 1) { HandStrength = 928; return HandStrength; }
					if (n2 == 1) { HandStrength = 927; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 926; return HandStrength; }
					if (n3 == 1) { HandStrength = 925; return HandStrength; }
					if (n2 == 1) { HandStrength = 924; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 923; return HandStrength; }
					if (n2 == 1) { HandStrength = 922; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 921; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 920; return HandStrength; }
					if (n4 == 1) { HandStrength = 919; return HandStrength; }
					if (n3 == 1) { HandStrength = 918; return HandStrength; }
					if (n2 == 1) { HandStrength = 917; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 916; return HandStrength; }
					if (n3 == 1) { HandStrength = 915; return HandStrength; }
					if (n2 == 1) { HandStrength = 914; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 913; return HandStrength; }
					if (n2 == 1) { HandStrength = 912; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 911; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 910; return HandStrength; }
					if (n3 == 1) { HandStrength = 909; return HandStrength; }
					if (n2 == 1) { HandStrength = 908; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 907; return HandStrength; }
					if (n2 == 1) { HandStrength = 906; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 905; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 904; return HandStrength; }
					if (n2 == 1) { HandStrength = 903; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 902; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 901; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 900; return HandStrength; }
					if (nJ == 1) { HandStrength = 899; return HandStrength; }
					if (nT == 1) { HandStrength = 898; return HandStrength; }
					if (n8 == 1) { HandStrength = 897; return HandStrength; }
					if (n7 == 1) { HandStrength = 896; return HandStrength; }
					if (n6 == 1) { HandStrength = 895; return HandStrength; }
					if (n5 == 1) { HandStrength = 894; return HandStrength; }
					if (n4 == 1) { HandStrength = 893; return HandStrength; }
					if (n3 == 1) { HandStrength = 892; return HandStrength; }
					if (n2 == 1) { HandStrength = 891; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 890; return HandStrength; }
					if (nT == 1) { HandStrength = 889; return HandStrength; }
					if (n8 == 1) { HandStrength = 888; return HandStrength; }
					if (n7 == 1) { HandStrength = 887; return HandStrength; }
					if (n6 == 1) { HandStrength = 886; return HandStrength; }
					if (n5 == 1) { HandStrength = 885; return HandStrength; }
					if (n4 == 1) { HandStrength = 884; return HandStrength; }
					if (n3 == 1) { HandStrength = 883; return HandStrength; }
					if (n2 == 1) { HandStrength = 882; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 881; return HandStrength; }
					if (n8 == 1) { HandStrength = 880; return HandStrength; }
					if (n7 == 1) { HandStrength = 879; return HandStrength; }
					if (n6 == 1) { HandStrength = 878; return HandStrength; }
					if (n5 == 1) { HandStrength = 877; return HandStrength; }
					if (n4 == 1) { HandStrength = 876; return HandStrength; }
					if (n3 == 1) { HandStrength = 875; return HandStrength; }
					if (n2 == 1) { HandStrength = 874; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 873; return HandStrength; }
					if (n7 == 1) { HandStrength = 872; return HandStrength; }
					if (n6 == 1) { HandStrength = 871; return HandStrength; }
					if (n5 == 1) { HandStrength = 870; return HandStrength; }
					if (n4 == 1) { HandStrength = 869; return HandStrength; }
					if (n3 == 1) { HandStrength = 868; return HandStrength; }
					if (n2 == 1) { HandStrength = 867; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 866; return HandStrength; }
					if (n6 == 1) { HandStrength = 865; return HandStrength; }
					if (n5 == 1) { HandStrength = 864; return HandStrength; }
					if (n4 == 1) { HandStrength = 863; return HandStrength; }
					if (n3 == 1) { HandStrength = 862; return HandStrength; }
					if (n2 == 1) { HandStrength = 861; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 860; return HandStrength; }
					if (n5 == 1) { HandStrength = 859; return HandStrength; }
					if (n4 == 1) { HandStrength = 858; return HandStrength; }
					if (n3 == 1) { HandStrength = 857; return HandStrength; }
					if (n2 == 1) { HandStrength = 856; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 855; return HandStrength; }
					if (n4 == 1) { HandStrength = 854; return HandStrength; }
					if (n3 == 1) { HandStrength = 853; return HandStrength; }
					if (n2 == 1) { HandStrength = 852; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 851; return HandStrength; }
					if (n3 == 1) { HandStrength = 850; return HandStrength; }
					if (n2 == 1) { HandStrength = 849; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 848; return HandStrength; }
					if (n2 == 1) { HandStrength = 847; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 846; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 845; return HandStrength; }
					if (nT == 1) { HandStrength = 844; return HandStrength; }
					if (n8 == 1) { HandStrength = 843; return HandStrength; }
					if (n7 == 1) { HandStrength = 842; return HandStrength; }
					if (n6 == 1) { HandStrength = 841; return HandStrength; }
					if (n5 == 1) { HandStrength = 840; return HandStrength; }
					if (n4 == 1) { HandStrength = 839; return HandStrength; }
					if (n3 == 1) { HandStrength = 838; return HandStrength; }
					if (n2 == 1) { HandStrength = 837; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 836; return HandStrength; }
					if (n8 == 1) { HandStrength = 835; return HandStrength; }
					if (n7 == 1) { HandStrength = 834; return HandStrength; }
					if (n6 == 1) { HandStrength = 833; return HandStrength; }
					if (n5 == 1) { HandStrength = 832; return HandStrength; }
					if (n4 == 1) { HandStrength = 831; return HandStrength; }
					if (n3 == 1) { HandStrength = 830; return HandStrength; }
					if (n2 == 1) { HandStrength = 829; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 828; return HandStrength; }
					if (n7 == 1) { HandStrength = 827; return HandStrength; }
					if (n6 == 1) { HandStrength = 826; return HandStrength; }
					if (n5 == 1) { HandStrength = 825; return HandStrength; }
					if (n4 == 1) { HandStrength = 824; return HandStrength; }
					if (n3 == 1) { HandStrength = 823; return HandStrength; }
					if (n2 == 1) { HandStrength = 822; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 821; return HandStrength; }
					if (n6 == 1) { HandStrength = 820; return HandStrength; }
					if (n5 == 1) { HandStrength = 819; return HandStrength; }
					if (n4 == 1) { HandStrength = 818; return HandStrength; }
					if (n3 == 1) { HandStrength = 817; return HandStrength; }
					if (n2 == 1) { HandStrength = 816; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 815; return HandStrength; }
					if (n5 == 1) { HandStrength = 814; return HandStrength; }
					if (n4 == 1) { HandStrength = 813; return HandStrength; }
					if (n3 == 1) { HandStrength = 812; return HandStrength; }
					if (n2 == 1) { HandStrength = 811; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 810; return HandStrength; }
					if (n4 == 1) { HandStrength = 809; return HandStrength; }
					if (n3 == 1) { HandStrength = 808; return HandStrength; }
					if (n2 == 1) { HandStrength = 807; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 806; return HandStrength; }
					if (n3 == 1) { HandStrength = 805; return HandStrength; }
					if (n2 == 1) { HandStrength = 804; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 803; return HandStrength; }
					if (n2 == 1) { HandStrength = 802; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 801; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 800; return HandStrength; }
					if (n8 == 1) { HandStrength = 799; return HandStrength; }
					if (n7 == 1) { HandStrength = 798; return HandStrength; }
					if (n6 == 1) { HandStrength = 797; return HandStrength; }
					if (n5 == 1) { HandStrength = 796; return HandStrength; }
					if (n4 == 1) { HandStrength = 795; return HandStrength; }
					if (n3 == 1) { HandStrength = 794; return HandStrength; }
					if (n2 == 1) { HandStrength = 793; return HandStrength; }
				};
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 792; return HandStrength; }
					if (n7 == 1) { HandStrength = 791; return HandStrength; }
					if (n6 == 1) { HandStrength = 790; return HandStrength; }
					if (n5 == 1) { HandStrength = 789; return HandStrength; }
					if (n4 == 1) { HandStrength = 788; return HandStrength; }
					if (n3 == 1) { HandStrength = 787; return HandStrength; }
					if (n2 == 1) { HandStrength = 786; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 785; return HandStrength; }
					if (n6 == 1) { HandStrength = 784; return HandStrength; }
					if (n5 == 1) { HandStrength = 783; return HandStrength; }
					if (n4 == 1) { HandStrength = 782; return HandStrength; }
					if (n3 == 1) { HandStrength = 781; return HandStrength; }
					if (n2 == 1) { HandStrength = 780; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 779; return HandStrength; }
					if (n5 == 1) { HandStrength = 778; return HandStrength; }
					if (n4 == 1) { HandStrength = 777; return HandStrength; }
					if (n3 == 1) { HandStrength = 776; return HandStrength; }
					if (n2 == 1) { HandStrength = 775; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 774; return HandStrength; }
					if (n4 == 1) { HandStrength = 773; return HandStrength; }
					if (n3 == 1) { HandStrength = 772; return HandStrength; }
					if (n2 == 1) { HandStrength = 771; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 770; return HandStrength; }
					if (n3 == 1) { HandStrength = 769; return HandStrength; }
					if (n2 == 1) { HandStrength = 768; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 767; return HandStrength; }
					if (n2 == 1) { HandStrength = 766; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 765; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n8 == 1) { HandStrength = 764; return HandStrength; }
					if (n7 == 1) { HandStrength = 763; return HandStrength; }
					if (n6 == 1) { HandStrength = 762; return HandStrength; }
					if (n5 == 1) { HandStrength = 761; return HandStrength; }
					if (n4 == 1) { HandStrength = 760; return HandStrength; }
					if (n3 == 1) { HandStrength = 759; return HandStrength; }
					if (n2 == 1) { HandStrength = 758; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 757; return HandStrength; }
					if (n6 == 1) { HandStrength = 756; return HandStrength; }
					if (n5 == 1) { HandStrength = 755; return HandStrength; }
					if (n4 == 1) { HandStrength = 754; return HandStrength; }
					if (n3 == 1) { HandStrength = 753; return HandStrength; }
					if (n2 == 1) { HandStrength = 752; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 751; return HandStrength; }
					if (n5 == 1) { HandStrength = 750; return HandStrength; }
					if (n4 == 1) { HandStrength = 749; return HandStrength; }
					if (n3 == 1) { HandStrength = 748; return HandStrength; }
					if (n2 == 1) { HandStrength = 747; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 746; return HandStrength; }
					if (n4 == 1) { HandStrength = 745; return HandStrength; }
					if (n3 == 1) { HandStrength = 744; return HandStrength; }
					if (n2 == 1) { HandStrength = 743; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 742; return HandStrength; }
					if (n3 == 1) { HandStrength = 741; return HandStrength; }
					if (n2 == 1) { HandStrength = 740; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 739; return HandStrength; }
					if (n2 == 1) { HandStrength = 738; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 737; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 736; return HandStrength; }
					if (n6 == 1) { HandStrength = 735; return HandStrength; }
					if (n5 == 1) { HandStrength = 734; return HandStrength; }
					if (n4 == 1) { HandStrength = 733; return HandStrength; }
					if (n3 == 1) { HandStrength = 732; return HandStrength; }
					if (n2 == 1) { HandStrength = 731; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 730; return HandStrength; }
					if (n5 == 1) { HandStrength = 729; return HandStrength; }
					if (n4 == 1) { HandStrength = 728; return HandStrength; }
					if (n3 == 1) { HandStrength = 727; return HandStrength; }
					if (n2 == 1) { HandStrength = 726; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 725; return HandStrength; }
					if (n4 == 1) { HandStrength = 724; return HandStrength; }
					if (n3 == 1) { HandStrength = 723; return HandStrength; }
					if (n2 == 1) { HandStrength = 722; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 721; return HandStrength; }
					if (n3 == 1) { HandStrength = 720; return HandStrength; }
					if (n2 == 1) { HandStrength = 719; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 718; return HandStrength; }
					if (n2 == 1) { HandStrength = 717; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 716; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 715; return HandStrength; }
					if (n5 == 1) { HandStrength = 714; return HandStrength; }
					if (n4 == 1) { HandStrength = 713; return HandStrength; }
					if (n3 == 1) { HandStrength = 712; return HandStrength; }
					if (n2 == 1) { HandStrength = 711; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 710; return HandStrength; }
					if (n4 == 1) { HandStrength = 709; return HandStrength; }
					if (n3 == 1) { HandStrength = 708; return HandStrength; }
					if (n2 == 1) { HandStrength = 707; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 706; return HandStrength; }
					if (n3 == 1) { HandStrength = 705; return HandStrength; }
					if (n2 == 1) { HandStrength = 704; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 703; return HandStrength; }
					if (n2 == 1) { HandStrength = 702; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 701; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 700; return HandStrength; }
					if (n4 == 1) { HandStrength = 699; return HandStrength; }
					if (n3 == 1) { HandStrength = 698; return HandStrength; }
					if (n2 == 1) { HandStrength = 697; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 696; return HandStrength; }
					if (n3 == 1) { HandStrength = 695; return HandStrength; }
					if (n2 == 1) { HandStrength = 694; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 693; return HandStrength; }
					if (n2 == 1) { HandStrength = 692; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 691; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 690; return HandStrength; }
					if (n3 == 1) { HandStrength = 689; return HandStrength; }
					if (n2 == 1) { HandStrength = 688; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 687; return HandStrength; }
					if (n2 == 1) { HandStrength = 686; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 685; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 684; return HandStrength; }
					if (n2 == 1) { HandStrength = 683; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 682; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 681; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 680; return HandStrength; }
					if (nJ == 1) { HandStrength = 679; return HandStrength; }
					if (nT == 1) { HandStrength = 678; return HandStrength; }
					if (n9 == 1) { HandStrength = 677; return HandStrength; }
					if (n7 == 1) { HandStrength = 676; return HandStrength; }
					if (n6 == 1) { HandStrength = 675; return HandStrength; }
					if (n5 == 1) { HandStrength = 674; return HandStrength; }
					if (n4 == 1) { HandStrength = 673; return HandStrength; }
					if (n3 == 1) { HandStrength = 672; return HandStrength; }
					if (n2 == 1) { HandStrength = 671; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 670; return HandStrength; }
					if (nT == 1) { HandStrength = 669; return HandStrength; }
					if (n9 == 1) { HandStrength = 668; return HandStrength; }
					if (n7 == 1) { HandStrength = 667; return HandStrength; }
					if (n6 == 1) { HandStrength = 666; return HandStrength; }
					if (n5 == 1) { HandStrength = 665; return HandStrength; }
					if (n4 == 1) { HandStrength = 664; return HandStrength; }
					if (n3 == 1) { HandStrength = 663; return HandStrength; }
					if (n2 == 1) { HandStrength = 662; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 661; return HandStrength; }
					if (n9 == 1) { HandStrength = 660; return HandStrength; }
					if (n7 == 1) { HandStrength = 659; return HandStrength; }
					if (n6 == 1) { HandStrength = 658; return HandStrength; }
					if (n5 == 1) { HandStrength = 657; return HandStrength; }
					if (n4 == 1) { HandStrength = 656; return HandStrength; }
					if (n3 == 1) { HandStrength = 655; return HandStrength; }
					if (n2 == 1) { HandStrength = 654; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 653; return HandStrength; }
					if (n7 == 1) { HandStrength = 652; return HandStrength; }
					if (n6 == 1) { HandStrength = 651; return HandStrength; }
					if (n5 == 1) { HandStrength = 650; return HandStrength; }
					if (n4 == 1) { HandStrength = 649; return HandStrength; }
					if (n3 == 1) { HandStrength = 648; return HandStrength; }
					if (n2 == 1) { HandStrength = 647; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 646; return HandStrength; }
					if (n6 == 1) { HandStrength = 645; return HandStrength; }
					if (n5 == 1) { HandStrength = 644; return HandStrength; }
					if (n4 == 1) { HandStrength = 643; return HandStrength; }
					if (n3 == 1) { HandStrength = 642; return HandStrength; }
					if (n2 == 1) { HandStrength = 641; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 640; return HandStrength; }
					if (n5 == 1) { HandStrength = 639; return HandStrength; }
					if (n4 == 1) { HandStrength = 638; return HandStrength; }
					if (n3 == 1) { HandStrength = 637; return HandStrength; }
					if (n2 == 1) { HandStrength = 636; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 635; return HandStrength; }
					if (n4 == 1) { HandStrength = 634; return HandStrength; }
					if (n3 == 1) { HandStrength = 633; return HandStrength; }
					if (n2 == 1) { HandStrength = 632; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 631; return HandStrength; }
					if (n3 == 1) { HandStrength = 630; return HandStrength; }
					if (n2 == 1) { HandStrength = 629; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 628; return HandStrength; }
					if (n2 == 1) { HandStrength = 627; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 626; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 625; return HandStrength; }
					if (nT == 1) { HandStrength = 624; return HandStrength; }
					if (n9 == 1) { HandStrength = 623; return HandStrength; }
					if (n7 == 1) { HandStrength = 622; return HandStrength; }
					if (n6 == 1) { HandStrength = 621; return HandStrength; }
					if (n5 == 1) { HandStrength = 620; return HandStrength; }
					if (n4 == 1) { HandStrength = 619; return HandStrength; }
					if (n3 == 1) { HandStrength = 618; return HandStrength; }
					if (n2 == 1) { HandStrength = 617; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 616; return HandStrength; }
					if (n9 == 1) { HandStrength = 615; return HandStrength; }
					if (n7 == 1) { HandStrength = 614; return HandStrength; }
					if (n6 == 1) { HandStrength = 613; return HandStrength; }
					if (n5 == 1) { HandStrength = 612; return HandStrength; }
					if (n4 == 1) { HandStrength = 611; return HandStrength; }
					if (n3 == 1) { HandStrength = 610; return HandStrength; }
					if (n2 == 1) { HandStrength = 609; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 608; return HandStrength; }
					if (n7 == 1) { HandStrength = 607; return HandStrength; }
					if (n6 == 1) { HandStrength = 606; return HandStrength; }
					if (n5 == 1) { HandStrength = 605; return HandStrength; }
					if (n4 == 1) { HandStrength = 604; return HandStrength; }
					if (n3 == 1) { HandStrength = 603; return HandStrength; }
					if (n2 == 1) { HandStrength = 602; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 601; return HandStrength; }
					if (n6 == 1) { HandStrength = 600; return HandStrength; }
					if (n5 == 1) { HandStrength = 599; return HandStrength; }
					if (n4 == 1) { HandStrength = 598; return HandStrength; }
					if (n3 == 1) { HandStrength = 597; return HandStrength; }
					if (n2 == 1) { HandStrength = 596; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 595; return HandStrength; }
					if (n5 == 1) { HandStrength = 594; return HandStrength; }
					if (n4 == 1) { HandStrength = 593; return HandStrength; }
					if (n3 == 1) { HandStrength = 592; return HandStrength; }
					if (n2 == 1) { HandStrength = 591; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 590; return HandStrength; }
					if (n4 == 1) { HandStrength = 589; return HandStrength; }
					if (n3 == 1) { HandStrength = 588; return HandStrength; }
					if (n2 == 1) { HandStrength = 587; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 586; return HandStrength; }
					if (n3 == 1) { HandStrength = 585; return HandStrength; }
					if (n2 == 1) { HandStrength = 584; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 583; return HandStrength; }
					if (n2 == 1) { HandStrength = 582; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 581; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 580; return HandStrength; }
					if (n9 == 1) { HandStrength = 579; return HandStrength; }
					if (n7 == 1) { HandStrength = 578; return HandStrength; }
					if (n6 == 1) { HandStrength = 577; return HandStrength; }
					if (n5 == 1) { HandStrength = 576; return HandStrength; }
					if (n4 == 1) { HandStrength = 575; return HandStrength; }
					if (n3 == 1) { HandStrength = 574; return HandStrength; }
					if (n2 == 1) { HandStrength = 573; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 572; return HandStrength; }
					if (n7 == 1) { HandStrength = 571; return HandStrength; }
					if (n6 == 1) { HandStrength = 570; return HandStrength; }
					if (n5 == 1) { HandStrength = 569; return HandStrength; }
					if (n4 == 1) { HandStrength = 568; return HandStrength; }
					if (n3 == 1) { HandStrength = 567; return HandStrength; }
					if (n2 == 1) { HandStrength = 566; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 565; return HandStrength; }
					if (n6 == 1) { HandStrength = 564; return HandStrength; }
					if (n5 == 1) { HandStrength = 563; return HandStrength; }
					if (n4 == 1) { HandStrength = 562; return HandStrength; }
					if (n3 == 1) { HandStrength = 561; return HandStrength; }
					if (n2 == 1) { HandStrength = 560; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 559; return HandStrength; }
					if (n5 == 1) { HandStrength = 558; return HandStrength; }
					if (n4 == 1) { HandStrength = 557; return HandStrength; }
					if (n3 == 1) { HandStrength = 556; return HandStrength; }
					if (n2 == 1) { HandStrength = 555; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 554; return HandStrength; }
					if (n4 == 1) { HandStrength = 553; return HandStrength; }
					if (n3 == 1) { HandStrength = 552; return HandStrength; }
					if (n2 == 1) { HandStrength = 551; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 550; return HandStrength; }
					if (n3 == 1) { HandStrength = 549; return HandStrength; }
					if (n2 == 1) { HandStrength = 548; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 547; return HandStrength; }
					if (n2 == 1) { HandStrength = 546; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 545; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 544; return HandStrength; }
					if (n7 == 1) { HandStrength = 543; return HandStrength; }
					if (n6 == 1) { HandStrength = 542; return HandStrength; }
					if (n5 == 1) { HandStrength = 541; return HandStrength; }
					if (n4 == 1) { HandStrength = 540; return HandStrength; }
					if (n3 == 1) { HandStrength = 539; return HandStrength; }
					if (n2 == 1) { HandStrength = 538; return HandStrength; }
				};
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 537; return HandStrength; }
					if (n6 == 1) { HandStrength = 536; return HandStrength; }
					if (n5 == 1) { HandStrength = 535; return HandStrength; }
					if (n4 == 1) { HandStrength = 534; return HandStrength; }
					if (n3 == 1) { HandStrength = 533; return HandStrength; }
					if (n2 == 1) { HandStrength = 532; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 531; return HandStrength; }
					if (n5 == 1) { HandStrength = 530; return HandStrength; }
					if (n4 == 1) { HandStrength = 529; return HandStrength; }
					if (n3 == 1) { HandStrength = 528; return HandStrength; }
					if (n2 == 1) { HandStrength = 527; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 526; return HandStrength; }
					if (n4 == 1) { HandStrength = 525; return HandStrength; }
					if (n3 == 1) { HandStrength = 524; return HandStrength; }
					if (n2 == 1) { HandStrength = 523; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 522; return HandStrength; }
					if (n3 == 1) { HandStrength = 521; return HandStrength; }
					if (n2 == 1) { HandStrength = 520; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 519; return HandStrength; }
					if (n2 == 1) { HandStrength = 518; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 517; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n7 == 1) { HandStrength = 516; return HandStrength; }
					if (n6 == 1) { HandStrength = 515; return HandStrength; }
					if (n5 == 1) { HandStrength = 514; return HandStrength; }
					if (n4 == 1) { HandStrength = 513; return HandStrength; }
					if (n3 == 1) { HandStrength = 512; return HandStrength; }
					if (n2 == 1) { HandStrength = 511; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 510; return HandStrength; }
					if (n5 == 1) { HandStrength = 509; return HandStrength; }
					if (n4 == 1) { HandStrength = 508; return HandStrength; }
					if (n3 == 1) { HandStrength = 507; return HandStrength; }
					if (n2 == 1) { HandStrength = 506; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 505; return HandStrength; }
					if (n4 == 1) { HandStrength = 504; return HandStrength; }
					if (n3 == 1) { HandStrength = 503; return HandStrength; }
					if (n2 == 1) { HandStrength = 502; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 501; return HandStrength; }
					if (n3 == 1) { HandStrength = 500; return HandStrength; }
					if (n2 == 1) { HandStrength = 499; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 498; return HandStrength; }
					if (n2 == 1) { HandStrength = 497; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 496; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = 495; return HandStrength; }
					if (n5 == 1) { HandStrength = 494; return HandStrength; }
					if (n4 == 1) { HandStrength = 493; return HandStrength; }
					if (n3 == 1) { HandStrength = 492; return HandStrength; }
					if (n2 == 1) { HandStrength = 491; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 490; return HandStrength; }
					if (n4 == 1) { HandStrength = 489; return HandStrength; }
					if (n3 == 1) { HandStrength = 488; return HandStrength; }
					if (n2 == 1) { HandStrength = 487; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 486; return HandStrength; }
					if (n3 == 1) { HandStrength = 485; return HandStrength; }
					if (n2 == 1) { HandStrength = 484; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 483; return HandStrength; }
					if (n2 == 1) { HandStrength = 482; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 481; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 480; return HandStrength; }
					if (n4 == 1) { HandStrength = 479; return HandStrength; }
					if (n3 == 1) { HandStrength = 478; return HandStrength; }
					if (n2 == 1) { HandStrength = 477; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 476; return HandStrength; }
					if (n3 == 1) { HandStrength = 475; return HandStrength; }
					if (n2 == 1) { HandStrength = 474; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 473; return HandStrength; }
					if (n2 == 1) { HandStrength = 472; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 471; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 470; return HandStrength; }
					if (n3 == 1) { HandStrength = 469; return HandStrength; }
					if (n2 == 1) { HandStrength = 468; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 467; return HandStrength; }
					if (n2 == 1) { HandStrength = 466; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 465; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 464; return HandStrength; }
					if (n2 == 1) { HandStrength = 463; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 462; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 461; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 460; return HandStrength; }
					if (nJ == 1) { HandStrength = 459; return HandStrength; }
					if (nT == 1) { HandStrength = 458; return HandStrength; }
					if (n9 == 1) { HandStrength = 457; return HandStrength; }
					if (n8 == 1) { HandStrength = 456; return HandStrength; }
					if (n6 == 1) { HandStrength = 455; return HandStrength; }
					if (n5 == 1) { HandStrength = 454; return HandStrength; }
					if (n4 == 1) { HandStrength = 453; return HandStrength; }
					if (n3 == 1) { HandStrength = 452; return HandStrength; }
					if (n2 == 1) { HandStrength = 451; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 450; return HandStrength; }
					if (nT == 1) { HandStrength = 449; return HandStrength; }
					if (n9 == 1) { HandStrength = 448; return HandStrength; }
					if (n8 == 1) { HandStrength = 447; return HandStrength; }
					if (n6 == 1) { HandStrength = 446; return HandStrength; }
					if (n5 == 1) { HandStrength = 445; return HandStrength; }
					if (n4 == 1) { HandStrength = 444; return HandStrength; }
					if (n3 == 1) { HandStrength = 443; return HandStrength; }
					if (n2 == 1) { HandStrength = 442; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 441; return HandStrength; }
					if (n9 == 1) { HandStrength = 440; return HandStrength; }
					if (n8 == 1) { HandStrength = 439; return HandStrength; }
					if (n6 == 1) { HandStrength = 438; return HandStrength; }
					if (n5 == 1) { HandStrength = 437; return HandStrength; }
					if (n4 == 1) { HandStrength = 436; return HandStrength; }
					if (n3 == 1) { HandStrength = 435; return HandStrength; }
					if (n2 == 1) { HandStrength = 434; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 433; return HandStrength; }
					if (n8 == 1) { HandStrength = 432; return HandStrength; }
					if (n6 == 1) { HandStrength = 431; return HandStrength; }
					if (n5 == 1) { HandStrength = 430; return HandStrength; }
					if (n4 == 1) { HandStrength = 429; return HandStrength; }
					if (n3 == 1) { HandStrength = 428; return HandStrength; }
					if (n2 == 1) { HandStrength = 427; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 426; return HandStrength; }
					if (n6 == 1) { HandStrength = 425; return HandStrength; }
					if (n5 == 1) { HandStrength = 424; return HandStrength; }
					if (n4 == 1) { HandStrength = 423; return HandStrength; }
					if (n3 == 1) { HandStrength = 422; return HandStrength; }
					if (n2 == 1) { HandStrength = 421; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 420; return HandStrength; }
					if (n5 == 1) { HandStrength = 419; return HandStrength; }
					if (n4 == 1) { HandStrength = 418; return HandStrength; }
					if (n3 == 1) { HandStrength = 417; return HandStrength; }
					if (n2 == 1) { HandStrength = 416; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 415; return HandStrength; }
					if (n4 == 1) { HandStrength = 414; return HandStrength; }
					if (n3 == 1) { HandStrength = 413; return HandStrength; }
					if (n2 == 1) { HandStrength = 412; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 411; return HandStrength; }
					if (n3 == 1) { HandStrength = 410; return HandStrength; }
					if (n2 == 1) { HandStrength = 409; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 408; return HandStrength; }
					if (n2 == 1) { HandStrength = 407; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 406; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 405; return HandStrength; }
					if (nT == 1) { HandStrength = 404; return HandStrength; }
					if (n9 == 1) { HandStrength = 403; return HandStrength; }
					if (n8 == 1) { HandStrength = 402; return HandStrength; }
					if (n6 == 1) { HandStrength = 401; return HandStrength; }
					if (n5 == 1) { HandStrength = 400; return HandStrength; }
					if (n4 == 1) { HandStrength = 399; return HandStrength; }
					if (n3 == 1) { HandStrength = 398; return HandStrength; }
					if (n2 == 1) { HandStrength = 397; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 396; return HandStrength; }
					if (n9 == 1) { HandStrength = 395; return HandStrength; }
					if (n8 == 1) { HandStrength = 394; return HandStrength; }
					if (n6 == 1) { HandStrength = 393; return HandStrength; }
					if (n5 == 1) { HandStrength = 392; return HandStrength; }
					if (n4 == 1) { HandStrength = 391; return HandStrength; }
					if (n3 == 1) { HandStrength = 390; return HandStrength; }
					if (n2 == 1) { HandStrength = 389; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 388; return HandStrength; }
					if (n8 == 1) { HandStrength = 387; return HandStrength; }
					if (n6 == 1) { HandStrength = 386; return HandStrength; }
					if (n5 == 1) { HandStrength = 385; return HandStrength; }
					if (n4 == 1) { HandStrength = 384; return HandStrength; }
					if (n3 == 1) { HandStrength = 383; return HandStrength; }
					if (n2 == 1) { HandStrength = 382; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 381; return HandStrength; }
					if (n6 == 1) { HandStrength = 380; return HandStrength; }
					if (n5 == 1) { HandStrength = 379; return HandStrength; }
					if (n4 == 1) { HandStrength = 378; return HandStrength; }
					if (n3 == 1) { HandStrength = 377; return HandStrength; }
					if (n2 == 1) { HandStrength = 376; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 375; return HandStrength; }
					if (n5 == 1) { HandStrength = 374; return HandStrength; }
					if (n4 == 1) { HandStrength = 373; return HandStrength; }
					if (n3 == 1) { HandStrength = 372; return HandStrength; }
					if (n2 == 1) { HandStrength = 371; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 370; return HandStrength; }
					if (n4 == 1) { HandStrength = 369; return HandStrength; }
					if (n3 == 1) { HandStrength = 368; return HandStrength; }
					if (n2 == 1) { HandStrength = 367; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 366; return HandStrength; }
					if (n3 == 1) { HandStrength = 365; return HandStrength; }
					if (n2 == 1) { HandStrength = 364; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 363; return HandStrength; }
					if (n2 == 1) { HandStrength = 362; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 361; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 360; return HandStrength; }
					if (n9 == 1) { HandStrength = 359; return HandStrength; }
					if (n8 == 1) { HandStrength = 358; return HandStrength; }
					if (n6 == 1) { HandStrength = 357; return HandStrength; }
					if (n5 == 1) { HandStrength = 356; return HandStrength; }
					if (n4 == 1) { HandStrength = 355; return HandStrength; }
					if (n3 == 1) { HandStrength = 354; return HandStrength; }
					if (n2 == 1) { HandStrength = 353; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 352; return HandStrength; }
					if (n8 == 1) { HandStrength = 351; return HandStrength; }
					if (n6 == 1) { HandStrength = 350; return HandStrength; }
					if (n5 == 1) { HandStrength = 349; return HandStrength; }
					if (n4 == 1) { HandStrength = 348; return HandStrength; }
					if (n3 == 1) { HandStrength = 347; return HandStrength; }
					if (n2 == 1) { HandStrength = 346; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 345; return HandStrength; }
					if (n6 == 1) { HandStrength = 344; return HandStrength; }
					if (n5 == 1) { HandStrength = 343; return HandStrength; }
					if (n4 == 1) { HandStrength = 342; return HandStrength; }
					if (n3 == 1) { HandStrength = 341; return HandStrength; }
					if (n2 == 1) { HandStrength = 340; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 339; return HandStrength; }
					if (n5 == 1) { HandStrength = 338; return HandStrength; }
					if (n4 == 1) { HandStrength = 337; return HandStrength; }
					if (n3 == 1) { HandStrength = 336; return HandStrength; }
					if (n2 == 1) { HandStrength = 335; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 334; return HandStrength; }
					if (n4 == 1) { HandStrength = 333; return HandStrength; }
					if (n3 == 1) { HandStrength = 332; return HandStrength; }
					if (n2 == 1) { HandStrength = 331; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 330; return HandStrength; }
					if (n3 == 1) { HandStrength = 329; return HandStrength; }
					if (n2 == 1) { HandStrength = 328; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 327; return HandStrength; }
					if (n2 == 1) { HandStrength = 326; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 325; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 324; return HandStrength; }
					if (n8 == 1) { HandStrength = 323; return HandStrength; }
					if (n6 == 1) { HandStrength = 322; return HandStrength; }
					if (n5 == 1) { HandStrength = 321; return HandStrength; }
					if (n4 == 1) { HandStrength = 320; return HandStrength; }
					if (n3 == 1) { HandStrength = 319; return HandStrength; }
					if (n2 == 1) { HandStrength = 318; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 317; return HandStrength; }
					if (n6 == 1) { HandStrength = 316; return HandStrength; }
					if (n5 == 1) { HandStrength = 315; return HandStrength; }
					if (n4 == 1) { HandStrength = 314; return HandStrength; }
					if (n3 == 1) { HandStrength = 313; return HandStrength; }
					if (n2 == 1) { HandStrength = 312; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 311; return HandStrength; }
					if (n5 == 1) { HandStrength = 310; return HandStrength; }
					if (n4 == 1) { HandStrength = 309; return HandStrength; }
					if (n3 == 1) { HandStrength = 308; return HandStrength; }
					if (n2 == 1) { HandStrength = 307; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 306; return HandStrength; }
					if (n4 == 1) { HandStrength = 305; return HandStrength; }
					if (n3 == 1) { HandStrength = 304; return HandStrength; }
					if (n2 == 1) { HandStrength = 303; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 302; return HandStrength; }
					if (n3 == 1) { HandStrength = 301; return HandStrength; }
					if (n2 == 1) { HandStrength = 300; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 299; return HandStrength; }
					if (n2 == 1) { HandStrength = 298; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 297; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 296; return HandStrength; }
					if (n6 == 1) { HandStrength = 295; return HandStrength; }
					if (n5 == 1) { HandStrength = 294; return HandStrength; }
					if (n4 == 1) { HandStrength = 293; return HandStrength; }
					if (n3 == 1) { HandStrength = 292; return HandStrength; }
					if (n2 == 1) { HandStrength = 291; return HandStrength; }
				};
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 290; return HandStrength; }
					if (n5 == 1) { HandStrength = 289; return HandStrength; }
					if (n4 == 1) { HandStrength = 288; return HandStrength; }
					if (n3 == 1) { HandStrength = 287; return HandStrength; }
					if (n2 == 1) { HandStrength = 286; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 285; return HandStrength; }
					if (n4 == 1) { HandStrength = 284; return HandStrength; }
					if (n3 == 1) { HandStrength = 283; return HandStrength; }
					if (n2 == 1) { HandStrength = 282; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 281; return HandStrength; }
					if (n3 == 1) { HandStrength = 280; return HandStrength; }
					if (n2 == 1) { HandStrength = 279; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 278; return HandStrength; }
					if (n2 == 1) { HandStrength = 277; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 276; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n6 == 1) { HandStrength = 275; return HandStrength; }
					if (n5 == 1) { HandStrength = 274; return HandStrength; }
					if (n4 == 1) { HandStrength = 273; return HandStrength; }
					if (n3 == 1) { HandStrength = 272; return HandStrength; }
					if (n2 == 1) { HandStrength = 271; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 270; return HandStrength; }
					if (n4 == 1) { HandStrength = 269; return HandStrength; }
					if (n3 == 1) { HandStrength = 268; return HandStrength; }
					if (n2 == 1) { HandStrength = 267; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 266; return HandStrength; }
					if (n3 == 1) { HandStrength = 265; return HandStrength; }
					if (n2 == 1) { HandStrength = 264; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 263; return HandStrength; }
					if (n2 == 1) { HandStrength = 262; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 261; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = 260; return HandStrength; }
					if (n4 == 1) { HandStrength = 259; return HandStrength; }
					if (n3 == 1) { HandStrength = 258; return HandStrength; }
					if (n2 == 1) { HandStrength = 257; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 256; return HandStrength; }
					if (n3 == 1) { HandStrength = 255; return HandStrength; }
					if (n2 == 1) { HandStrength = 254; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 253; return HandStrength; }
					if (n2 == 1) { HandStrength = 252; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 251; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 250; return HandStrength; }
					if (n3 == 1) { HandStrength = 249; return HandStrength; }
					if (n2 == 1) { HandStrength = 248; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 247; return HandStrength; }
					if (n2 == 1) { HandStrength = 246; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 245; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 244; return HandStrength; }
					if (n2 == 1) { HandStrength = 243; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 242; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 241; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 240; return HandStrength; }
					if (nJ == 1) { HandStrength = 239; return HandStrength; }
					if (nT == 1) { HandStrength = 238; return HandStrength; }
					if (n9 == 1) { HandStrength = 237; return HandStrength; }
					if (n8 == 1) { HandStrength = 236; return HandStrength; }
					if (n7 == 1) { HandStrength = 235; return HandStrength; }
					if (n5 == 1) { HandStrength = 234; return HandStrength; }
					if (n4 == 1) { HandStrength = 233; return HandStrength; }
					if (n3 == 1) { HandStrength = 232; return HandStrength; }
					if (n2 == 1) { HandStrength = 231; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 230; return HandStrength; }
					if (nT == 1) { HandStrength = 229; return HandStrength; }
					if (n9 == 1) { HandStrength = 228; return HandStrength; }
					if (n8 == 1) { HandStrength = 227; return HandStrength; }
					if (n7 == 1) { HandStrength = 226; return HandStrength; }
					if (n5 == 1) { HandStrength = 225; return HandStrength; }
					if (n4 == 1) { HandStrength = 224; return HandStrength; }
					if (n3 == 1) { HandStrength = 223; return HandStrength; }
					if (n2 == 1) { HandStrength = 222; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 221; return HandStrength; }
					if (n9 == 1) { HandStrength = 220; return HandStrength; }
					if (n8 == 1) { HandStrength = 219; return HandStrength; }
					if (n7 == 1) { HandStrength = 218; return HandStrength; }
					if (n5 == 1) { HandStrength = 217; return HandStrength; }
					if (n4 == 1) { HandStrength = 216; return HandStrength; }
					if (n3 == 1) { HandStrength = 215; return HandStrength; }
					if (n2 == 1) { HandStrength = 214; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 213; return HandStrength; }
					if (n8 == 1) { HandStrength = 212; return HandStrength; }
					if (n7 == 1) { HandStrength = 211; return HandStrength; }
					if (n5 == 1) { HandStrength = 210; return HandStrength; }
					if (n4 == 1) { HandStrength = 209; return HandStrength; }
					if (n3 == 1) { HandStrength = 208; return HandStrength; }
					if (n2 == 1) { HandStrength = 207; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 206; return HandStrength; }
					if (n7 == 1) { HandStrength = 205; return HandStrength; }
					if (n5 == 1) { HandStrength = 204; return HandStrength; }
					if (n4 == 1) { HandStrength = 203; return HandStrength; }
					if (n3 == 1) { HandStrength = 202; return HandStrength; }
					if (n2 == 1) { HandStrength = 201; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 200; return HandStrength; }
					if (n5 == 1) { HandStrength = 199; return HandStrength; }
					if (n4 == 1) { HandStrength = 198; return HandStrength; }
					if (n3 == 1) { HandStrength = 197; return HandStrength; }
					if (n2 == 1) { HandStrength = 196; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 195; return HandStrength; }
					if (n4 == 1) { HandStrength = 194; return HandStrength; }
					if (n3 == 1) { HandStrength = 193; return HandStrength; }
					if (n2 == 1) { HandStrength = 192; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 191; return HandStrength; }
					if (n3 == 1) { HandStrength = 190; return HandStrength; }
					if (n2 == 1) { HandStrength = 189; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 188; return HandStrength; }
					if (n2 == 1) { HandStrength = 187; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 186; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 185; return HandStrength; }
					if (nT == 1) { HandStrength = 184; return HandStrength; }
					if (n9 == 1) { HandStrength = 183; return HandStrength; }
					if (n8 == 1) { HandStrength = 182; return HandStrength; }
					if (n7 == 1) { HandStrength = 181; return HandStrength; }
					if (n5 == 1) { HandStrength = 180; return HandStrength; }
					if (n4 == 1) { HandStrength = 179; return HandStrength; }
					if (n3 == 1) { HandStrength = 178; return HandStrength; }
					if (n2 == 1) { HandStrength = 177; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 176; return HandStrength; }
					if (n9 == 1) { HandStrength = 175; return HandStrength; }
					if (n8 == 1) { HandStrength = 174; return HandStrength; }
					if (n7 == 1) { HandStrength = 173; return HandStrength; }
					if (n5 == 1) { HandStrength = 172; return HandStrength; }
					if (n4 == 1) { HandStrength = 171; return HandStrength; }
					if (n3 == 1) { HandStrength = 170; return HandStrength; }
					if (n2 == 1) { HandStrength = 169; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 168; return HandStrength; }
					if (n8 == 1) { HandStrength = 167; return HandStrength; }
					if (n7 == 1) { HandStrength = 166; return HandStrength; }
					if (n5 == 1) { HandStrength = 165; return HandStrength; }
					if (n4 == 1) { HandStrength = 164; return HandStrength; }
					if (n3 == 1) { HandStrength = 163; return HandStrength; }
					if (n2 == 1) { HandStrength = 162; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 161; return HandStrength; }
					if (n7 == 1) { HandStrength = 160; return HandStrength; }
					if (n5 == 1) { HandStrength = 159; return HandStrength; }
					if (n4 == 1) { HandStrength = 158; return HandStrength; }
					if (n3 == 1) { HandStrength = 157; return HandStrength; }
					if (n2 == 1) { HandStrength = 156; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 155; return HandStrength; }
					if (n5 == 1) { HandStrength = 154; return HandStrength; }
					if (n4 == 1) { HandStrength = 153; return HandStrength; }
					if (n3 == 1) { HandStrength = 152; return HandStrength; }
					if (n2 == 1) { HandStrength = 151; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 150; return HandStrength; }
					if (n4 == 1) { HandStrength = 149; return HandStrength; }
					if (n3 == 1) { HandStrength = 148; return HandStrength; }
					if (n2 == 1) { HandStrength = 147; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 146; return HandStrength; }
					if (n3 == 1) { HandStrength = 145; return HandStrength; }
					if (n2 == 1) { HandStrength = 144; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 143; return HandStrength; }
					if (n2 == 1) { HandStrength = 142; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 141; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 140; return HandStrength; }
					if (n9 == 1) { HandStrength = 139; return HandStrength; }
					if (n8 == 1) { HandStrength = 138; return HandStrength; }
					if (n7 == 1) { HandStrength = 137; return HandStrength; }
					if (n5 == 1) { HandStrength = 136; return HandStrength; }
					if (n4 == 1) { HandStrength = 135; return HandStrength; }
					if (n3 == 1) { HandStrength = 134; return HandStrength; }
					if (n2 == 1) { HandStrength = 133; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 132; return HandStrength; }
					if (n8 == 1) { HandStrength = 131; return HandStrength; }
					if (n7 == 1) { HandStrength = 130; return HandStrength; }
					if (n5 == 1) { HandStrength = 129; return HandStrength; }
					if (n4 == 1) { HandStrength = 128; return HandStrength; }
					if (n3 == 1) { HandStrength = 127; return HandStrength; }
					if (n2 == 1) { HandStrength = 126; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 125; return HandStrength; }
					if (n7 == 1) { HandStrength = 124; return HandStrength; }
					if (n5 == 1) { HandStrength = 123; return HandStrength; }
					if (n4 == 1) { HandStrength = 122; return HandStrength; }
					if (n3 == 1) { HandStrength = 121; return HandStrength; }
					if (n2 == 1) { HandStrength = 120; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 119; return HandStrength; }
					if (n5 == 1) { HandStrength = 118; return HandStrength; }
					if (n4 == 1) { HandStrength = 117; return HandStrength; }
					if (n3 == 1) { HandStrength = 116; return HandStrength; }
					if (n2 == 1) { HandStrength = 115; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 114; return HandStrength; }
					if (n4 == 1) { HandStrength = 113; return HandStrength; }
					if (n3 == 1) { HandStrength = 112; return HandStrength; }
					if (n2 == 1) { HandStrength = 111; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 110; return HandStrength; }
					if (n3 == 1) { HandStrength = 109; return HandStrength; }
					if (n2 == 1) { HandStrength = 108; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 107; return HandStrength; }
					if (n2 == 1) { HandStrength = 106; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 105; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = 104; return HandStrength; }
					if (n8 == 1) { HandStrength = 103; return HandStrength; }
					if (n7 == 1) { HandStrength = 102; return HandStrength; }
					if (n5 == 1) { HandStrength = 101; return HandStrength; }
					if (n4 == 1) { HandStrength = 100; return HandStrength; }
					if (n3 == 1) { HandStrength = 99; return HandStrength; }
					if (n2 == 1) { HandStrength = 98; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 97; return HandStrength; }
					if (n7 == 1) { HandStrength = 96; return HandStrength; }
					if (n5 == 1) { HandStrength = 95; return HandStrength; }
					if (n4 == 1) { HandStrength = 94; return HandStrength; }
					if (n3 == 1) { HandStrength = 93; return HandStrength; }
					if (n2 == 1) { HandStrength = 92; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 91; return HandStrength; }
					if (n5 == 1) { HandStrength = 90; return HandStrength; }
					if (n4 == 1) { HandStrength = 89; return HandStrength; }
					if (n3 == 1) { HandStrength = 88; return HandStrength; }
					if (n2 == 1) { HandStrength = 87; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 86; return HandStrength; }
					if (n4 == 1) { HandStrength = 85; return HandStrength; }
					if (n3 == 1) { HandStrength = 84; return HandStrength; }
					if (n2 == 1) { HandStrength = 83; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 82; return HandStrength; }
					if (n3 == 1) { HandStrength = 81; return HandStrength; }
					if (n2 == 1) { HandStrength = 80; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 79; return HandStrength; }
					if (n2 == 1) { HandStrength = 78; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 77; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = 76; return HandStrength; }
					if (n7 == 1) { HandStrength = 75; return HandStrength; }
					if (n5 == 1) { HandStrength = 74; return HandStrength; }
					if (n4 == 1) { HandStrength = 73; return HandStrength; }
					if (n3 == 1) { HandStrength = 72; return HandStrength; }
					if (n2 == 1) { HandStrength = 71; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 70; return HandStrength; }
					if (n5 == 1) { HandStrength = 69; return HandStrength; }
					if (n4 == 1) { HandStrength = 68; return HandStrength; }
					if (n3 == 1) { HandStrength = 67; return HandStrength; }
					if (n2 == 1) { HandStrength = 66; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 65; return HandStrength; }
					if (n4 == 1) { HandStrength = 64; return HandStrength; }
					if (n3 == 1) { HandStrength = 63; return HandStrength; }
					if (n2 == 1) { HandStrength = 62; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 61; return HandStrength; }
					if (n3 == 1) { HandStrength = 60; return HandStrength; }
					if (n2 == 1) { HandStrength = 59; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 58; return HandStrength; }
					if (n2 == 1) { HandStrength = 57; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 56; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = 55; return HandStrength; }
					if (n5 == 1) { HandStrength = 54; return HandStrength; }
					if (n4 == 1) { HandStrength = 53; return HandStrength; }
					if (n3 == 1) { HandStrength = 52; return HandStrength; }
					if (n2 == 1) { HandStrength = 51; return HandStrength; }
				};
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 50; return HandStrength; }
					if (n4 == 1) { HandStrength = 49; return HandStrength; }
					if (n3 == 1) { HandStrength = 48; return HandStrength; }
					if (n2 == 1) { HandStrength = 47; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 46; return HandStrength; }
					if (n3 == 1) { HandStrength = 45; return HandStrength; }
					if (n2 == 1) { HandStrength = 44; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 43; return HandStrength; }
					if (n2 == 1) { HandStrength = 42; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 41; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n5 == 1) { HandStrength = 40; return HandStrength; }
					if (n4 == 1) { HandStrength = 39; return HandStrength; }
					if (n3 == 1) { HandStrength = 38; return HandStrength; }
					if (n2 == 1) { HandStrength = 37; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 36; return HandStrength; }
					if (n3 == 1) { HandStrength = 35; return HandStrength; }
					if (n2 == 1) { HandStrength = 34; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 33; return HandStrength; }
					if (n2 == 1) { HandStrength = 32; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 31; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = 30; return HandStrength; }
					if (n3 == 1) { HandStrength = 29; return HandStrength; }
					if (n2 == 1) { HandStrength = 28; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 27; return HandStrength; }
					if (n2 == 1) { HandStrength = 26; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 25; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = 24; return HandStrength; }
					if (n2 == 1) { HandStrength = 23; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 22; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = 21; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = 20; return HandStrength; }
					if (nJ == 1) { HandStrength = 19; return HandStrength; }
					if (nT == 1) { HandStrength = 18; return HandStrength; }
					if (n9 == 1) { HandStrength = 17; return HandStrength; }
					if (n8 == 1) { HandStrength = 16; return HandStrength; }
					if (n7 == 1) { HandStrength = 15; return HandStrength; }
					if (n6 == 1) { HandStrength = 14; return HandStrength; }
					if (n4 == 1) { HandStrength = 13; return HandStrength; }
					if (n3 == 1) { HandStrength = 12; return HandStrength; }
					if (n2 == 1) { HandStrength = 11; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = 10; return HandStrength; }
					if (nT == 1) { HandStrength = 9; return HandStrength; }
					if (n9 == 1) { HandStrength = 8; return HandStrength; }
					if (n8 == 1) { HandStrength = 7; return HandStrength; }
					if (n7 == 1) { HandStrength = 6; return HandStrength; }
					if (n6 == 1) { HandStrength = 5; return HandStrength; }
					if (n4 == 1) { HandStrength = 4; return HandStrength; }
					if (n3 == 1) { HandStrength = 3; return HandStrength; }
					if (n2 == 1) { HandStrength = 2; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = 1; return HandStrength; }
					if (n9 == 1) { HandStrength = 0; return HandStrength; }
					if (n8 == 1) { HandStrength = -1; return HandStrength; }
					if (n7 == 1) { HandStrength = -2; return HandStrength; }
					if (n6 == 1) { HandStrength = -3; return HandStrength; }
					if (n4 == 1) { HandStrength = -4; return HandStrength; }
					if (n3 == 1) { HandStrength = -5; return HandStrength; }
					if (n2 == 1) { HandStrength = -6; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -7; return HandStrength; }
					if (n8 == 1) { HandStrength = -8; return HandStrength; }
					if (n7 == 1) { HandStrength = -9; return HandStrength; }
					if (n6 == 1) { HandStrength = -10; return HandStrength; }
					if (n4 == 1) { HandStrength = -11; return HandStrength; }
					if (n3 == 1) { HandStrength = -12; return HandStrength; }
					if (n2 == 1) { HandStrength = -13; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -14; return HandStrength; }
					if (n7 == 1) { HandStrength = -15; return HandStrength; }
					if (n6 == 1) { HandStrength = -16; return HandStrength; }
					if (n4 == 1) { HandStrength = -17; return HandStrength; }
					if (n3 == 1) { HandStrength = -18; return HandStrength; }
					if (n2 == 1) { HandStrength = -19; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -20; return HandStrength; }
					if (n6 == 1) { HandStrength = -21; return HandStrength; }
					if (n4 == 1) { HandStrength = -22; return HandStrength; }
					if (n3 == 1) { HandStrength = -23; return HandStrength; }
					if (n2 == 1) { HandStrength = -24; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -25; return HandStrength; }
					if (n4 == 1) { HandStrength = -26; return HandStrength; }
					if (n3 == 1) { HandStrength = -27; return HandStrength; }
					if (n2 == 1) { HandStrength = -28; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -29; return HandStrength; }
					if (n3 == 1) { HandStrength = -30; return HandStrength; }
					if (n2 == 1) { HandStrength = -31; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -32; return HandStrength; }
					if (n2 == 1) { HandStrength = -33; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -34; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -35; return HandStrength; }
					if (nT == 1) { HandStrength = -36; return HandStrength; }
					if (n9 == 1) { HandStrength = -37; return HandStrength; }
					if (n8 == 1) { HandStrength = -38; return HandStrength; }
					if (n7 == 1) { HandStrength = -39; return HandStrength; }
					if (n6 == 1) { HandStrength = -40; return HandStrength; }
					if (n4 == 1) { HandStrength = -41; return HandStrength; }
					if (n3 == 1) { HandStrength = -42; return HandStrength; }
					if (n2 == 1) { HandStrength = -43; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -44; return HandStrength; }
					if (n9 == 1) { HandStrength = -45; return HandStrength; }
					if (n8 == 1) { HandStrength = -46; return HandStrength; }
					if (n7 == 1) { HandStrength = -47; return HandStrength; }
					if (n6 == 1) { HandStrength = -48; return HandStrength; }
					if (n4 == 1) { HandStrength = -49; return HandStrength; }
					if (n3 == 1) { HandStrength = -50; return HandStrength; }
					if (n2 == 1) { HandStrength = -51; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -52; return HandStrength; }
					if (n8 == 1) { HandStrength = -53; return HandStrength; }
					if (n7 == 1) { HandStrength = -54; return HandStrength; }
					if (n6 == 1) { HandStrength = -55; return HandStrength; }
					if (n4 == 1) { HandStrength = -56; return HandStrength; }
					if (n3 == 1) { HandStrength = -57; return HandStrength; }
					if (n2 == 1) { HandStrength = -58; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -59; return HandStrength; }
					if (n7 == 1) { HandStrength = -60; return HandStrength; }
					if (n6 == 1) { HandStrength = -61; return HandStrength; }
					if (n4 == 1) { HandStrength = -62; return HandStrength; }
					if (n3 == 1) { HandStrength = -63; return HandStrength; }
					if (n2 == 1) { HandStrength = -64; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -65; return HandStrength; }
					if (n6 == 1) { HandStrength = -66; return HandStrength; }
					if (n4 == 1) { HandStrength = -67; return HandStrength; }
					if (n3 == 1) { HandStrength = -68; return HandStrength; }
					if (n2 == 1) { HandStrength = -69; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -70; return HandStrength; }
					if (n4 == 1) { HandStrength = -71; return HandStrength; }
					if (n3 == 1) { HandStrength = -72; return HandStrength; }
					if (n2 == 1) { HandStrength = -73; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -74; return HandStrength; }
					if (n3 == 1) { HandStrength = -75; return HandStrength; }
					if (n2 == 1) { HandStrength = -76; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -77; return HandStrength; }
					if (n2 == 1) { HandStrength = -78; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -79; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -80; return HandStrength; }
					if (n9 == 1) { HandStrength = -81; return HandStrength; }
					if (n8 == 1) { HandStrength = -82; return HandStrength; }
					if (n7 == 1) { HandStrength = -83; return HandStrength; }
					if (n6 == 1) { HandStrength = -84; return HandStrength; }
					if (n4 == 1) { HandStrength = -85; return HandStrength; }
					if (n3 == 1) { HandStrength = -86; return HandStrength; }
					if (n2 == 1) { HandStrength = -87; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -88; return HandStrength; }
					if (n8 == 1) { HandStrength = -89; return HandStrength; }
					if (n7 == 1) { HandStrength = -90; return HandStrength; }
					if (n6 == 1) { HandStrength = -91; return HandStrength; }
					if (n4 == 1) { HandStrength = -92; return HandStrength; }
					if (n3 == 1) { HandStrength = -93; return HandStrength; }
					if (n2 == 1) { HandStrength = -94; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -95; return HandStrength; }
					if (n7 == 1) { HandStrength = -96; return HandStrength; }
					if (n6 == 1) { HandStrength = -97; return HandStrength; }
					if (n4 == 1) { HandStrength = -98; return HandStrength; }
					if (n3 == 1) { HandStrength = -99; return HandStrength; }
					if (n2 == 1) { HandStrength = -100; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -101; return HandStrength; }
					if (n6 == 1) { HandStrength = -102; return HandStrength; }
					if (n4 == 1) { HandStrength = -103; return HandStrength; }
					if (n3 == 1) { HandStrength = -104; return HandStrength; }
					if (n2 == 1) { HandStrength = -105; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -106; return HandStrength; }
					if (n4 == 1) { HandStrength = -107; return HandStrength; }
					if (n3 == 1) { HandStrength = -108; return HandStrength; }
					if (n2 == 1) { HandStrength = -109; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -110; return HandStrength; }
					if (n3 == 1) { HandStrength = -111; return HandStrength; }
					if (n2 == 1) { HandStrength = -112; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -113; return HandStrength; }
					if (n2 == 1) { HandStrength = -114; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -115; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -116; return HandStrength; }
					if (n8 == 1) { HandStrength = -117; return HandStrength; }
					if (n7 == 1) { HandStrength = -118; return HandStrength; }
					if (n6 == 1) { HandStrength = -119; return HandStrength; }
					if (n4 == 1) { HandStrength = -120; return HandStrength; }
					if (n3 == 1) { HandStrength = -121; return HandStrength; }
					if (n2 == 1) { HandStrength = -122; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -123; return HandStrength; }
					if (n7 == 1) { HandStrength = -124; return HandStrength; }
					if (n6 == 1) { HandStrength = -125; return HandStrength; }
					if (n4 == 1) { HandStrength = -126; return HandStrength; }
					if (n3 == 1) { HandStrength = -127; return HandStrength; }
					if (n2 == 1) { HandStrength = -128; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -129; return HandStrength; }
					if (n6 == 1) { HandStrength = -130; return HandStrength; }
					if (n4 == 1) { HandStrength = -131; return HandStrength; }
					if (n3 == 1) { HandStrength = -132; return HandStrength; }
					if (n2 == 1) { HandStrength = -133; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -134; return HandStrength; }
					if (n4 == 1) { HandStrength = -135; return HandStrength; }
					if (n3 == 1) { HandStrength = -136; return HandStrength; }
					if (n2 == 1) { HandStrength = -137; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -138; return HandStrength; }
					if (n3 == 1) { HandStrength = -139; return HandStrength; }
					if (n2 == 1) { HandStrength = -140; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -141; return HandStrength; }
					if (n2 == 1) { HandStrength = -142; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -143; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -144; return HandStrength; }
					if (n7 == 1) { HandStrength = -145; return HandStrength; }
					if (n6 == 1) { HandStrength = -146; return HandStrength; }
					if (n4 == 1) { HandStrength = -147; return HandStrength; }
					if (n3 == 1) { HandStrength = -148; return HandStrength; }
					if (n2 == 1) { HandStrength = -149; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -150; return HandStrength; }
					if (n6 == 1) { HandStrength = -151; return HandStrength; }
					if (n4 == 1) { HandStrength = -152; return HandStrength; }
					if (n3 == 1) { HandStrength = -153; return HandStrength; }
					if (n2 == 1) { HandStrength = -154; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -155; return HandStrength; }
					if (n4 == 1) { HandStrength = -156; return HandStrength; }
					if (n3 == 1) { HandStrength = -157; return HandStrength; }
					if (n2 == 1) { HandStrength = -158; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -159; return HandStrength; }
					if (n3 == 1) { HandStrength = -160; return HandStrength; }
					if (n2 == 1) { HandStrength = -161; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -162; return HandStrength; }
					if (n2 == 1) { HandStrength = -163; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -164; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -165; return HandStrength; }
					if (n6 == 1) { HandStrength = -166; return HandStrength; }
					if (n4 == 1) { HandStrength = -167; return HandStrength; }
					if (n3 == 1) { HandStrength = -168; return HandStrength; }
					if (n2 == 1) { HandStrength = -169; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -170; return HandStrength; }
					if (n4 == 1) { HandStrength = -171; return HandStrength; }
					if (n3 == 1) { HandStrength = -172; return HandStrength; }
					if (n2 == 1) { HandStrength = -173; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -174; return HandStrength; }
					if (n3 == 1) { HandStrength = -175; return HandStrength; }
					if (n2 == 1) { HandStrength = -176; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -177; return HandStrength; }
					if (n2 == 1) { HandStrength = -178; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -179; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -180; return HandStrength; }
					if (n4 == 1) { HandStrength = -181; return HandStrength; }
					if (n3 == 1) { HandStrength = -182; return HandStrength; }
					if (n2 == 1) { HandStrength = -183; return HandStrength; }
				};
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -184; return HandStrength; }
					if (n3 == 1) { HandStrength = -185; return HandStrength; }
					if (n2 == 1) { HandStrength = -186; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -187; return HandStrength; }
					if (n2 == 1) { HandStrength = -188; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -189; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n4 == 1) { HandStrength = -190; return HandStrength; }
					if (n3 == 1) { HandStrength = -191; return HandStrength; }
					if (n2 == 1) { HandStrength = -192; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -193; return HandStrength; }
					if (n2 == 1) { HandStrength = -194; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -195; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -196; return HandStrength; }
					if (n2 == 1) { HandStrength = -197; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -198; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -199; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = -200; return HandStrength; }
					if (nJ == 1) { HandStrength = -201; return HandStrength; }
					if (nT == 1) { HandStrength = -202; return HandStrength; }
					if (n9 == 1) { HandStrength = -203; return HandStrength; }
					if (n8 == 1) { HandStrength = -204; return HandStrength; }
					if (n7 == 1) { HandStrength = -205; return HandStrength; }
					if (n6 == 1) { HandStrength = -206; return HandStrength; }
					if (n5 == 1) { HandStrength = -207; return HandStrength; }
					if (n3 == 1) { HandStrength = -208; return HandStrength; }
					if (n2 == 1) { HandStrength = -209; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -210; return HandStrength; }
					if (nT == 1) { HandStrength = -211; return HandStrength; }
					if (n9 == 1) { HandStrength = -212; return HandStrength; }
					if (n8 == 1) { HandStrength = -213; return HandStrength; }
					if (n7 == 1) { HandStrength = -214; return HandStrength; }
					if (n6 == 1) { HandStrength = -215; return HandStrength; }
					if (n5 == 1) { HandStrength = -216; return HandStrength; }
					if (n3 == 1) { HandStrength = -217; return HandStrength; }
					if (n2 == 1) { HandStrength = -218; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -219; return HandStrength; }
					if (n9 == 1) { HandStrength = -220; return HandStrength; }
					if (n8 == 1) { HandStrength = -221; return HandStrength; }
					if (n7 == 1) { HandStrength = -222; return HandStrength; }
					if (n6 == 1) { HandStrength = -223; return HandStrength; }
					if (n5 == 1) { HandStrength = -224; return HandStrength; }
					if (n3 == 1) { HandStrength = -225; return HandStrength; }
					if (n2 == 1) { HandStrength = -226; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -227; return HandStrength; }
					if (n8 == 1) { HandStrength = -228; return HandStrength; }
					if (n7 == 1) { HandStrength = -229; return HandStrength; }
					if (n6 == 1) { HandStrength = -230; return HandStrength; }
					if (n5 == 1) { HandStrength = -231; return HandStrength; }
					if (n3 == 1) { HandStrength = -232; return HandStrength; }
					if (n2 == 1) { HandStrength = -233; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -234; return HandStrength; }
					if (n7 == 1) { HandStrength = -235; return HandStrength; }
					if (n6 == 1) { HandStrength = -236; return HandStrength; }
					if (n5 == 1) { HandStrength = -237; return HandStrength; }
					if (n3 == 1) { HandStrength = -238; return HandStrength; }
					if (n2 == 1) { HandStrength = -239; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -240; return HandStrength; }
					if (n6 == 1) { HandStrength = -241; return HandStrength; }
					if (n5 == 1) { HandStrength = -242; return HandStrength; }
					if (n3 == 1) { HandStrength = -243; return HandStrength; }
					if (n2 == 1) { HandStrength = -244; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -245; return HandStrength; }
					if (n5 == 1) { HandStrength = -246; return HandStrength; }
					if (n3 == 1) { HandStrength = -247; return HandStrength; }
					if (n2 == 1) { HandStrength = -248; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -249; return HandStrength; }
					if (n3 == 1) { HandStrength = -250; return HandStrength; }
					if (n2 == 1) { HandStrength = -251; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -252; return HandStrength; }
					if (n2 == 1) { HandStrength = -253; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -254; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -255; return HandStrength; }
					if (nT == 1) { HandStrength = -256; return HandStrength; }
					if (n9 == 1) { HandStrength = -257; return HandStrength; }
					if (n8 == 1) { HandStrength = -258; return HandStrength; }
					if (n7 == 1) { HandStrength = -259; return HandStrength; }
					if (n6 == 1) { HandStrength = -260; return HandStrength; }
					if (n5 == 1) { HandStrength = -261; return HandStrength; }
					if (n3 == 1) { HandStrength = -262; return HandStrength; }
					if (n2 == 1) { HandStrength = -263; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -264; return HandStrength; }
					if (n9 == 1) { HandStrength = -265; return HandStrength; }
					if (n8 == 1) { HandStrength = -266; return HandStrength; }
					if (n7 == 1) { HandStrength = -267; return HandStrength; }
					if (n6 == 1) { HandStrength = -268; return HandStrength; }
					if (n5 == 1) { HandStrength = -269; return HandStrength; }
					if (n3 == 1) { HandStrength = -270; return HandStrength; }
					if (n2 == 1) { HandStrength = -271; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -272; return HandStrength; }
					if (n8 == 1) { HandStrength = -273; return HandStrength; }
					if (n7 == 1) { HandStrength = -274; return HandStrength; }
					if (n6 == 1) { HandStrength = -275; return HandStrength; }
					if (n5 == 1) { HandStrength = -276; return HandStrength; }
					if (n3 == 1) { HandStrength = -277; return HandStrength; }
					if (n2 == 1) { HandStrength = -278; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -279; return HandStrength; }
					if (n7 == 1) { HandStrength = -280; return HandStrength; }
					if (n6 == 1) { HandStrength = -281; return HandStrength; }
					if (n5 == 1) { HandStrength = -282; return HandStrength; }
					if (n3 == 1) { HandStrength = -283; return HandStrength; }
					if (n2 == 1) { HandStrength = -284; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -285; return HandStrength; }
					if (n6 == 1) { HandStrength = -286; return HandStrength; }
					if (n5 == 1) { HandStrength = -287; return HandStrength; }
					if (n3 == 1) { HandStrength = -288; return HandStrength; }
					if (n2 == 1) { HandStrength = -289; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -290; return HandStrength; }
					if (n5 == 1) { HandStrength = -291; return HandStrength; }
					if (n3 == 1) { HandStrength = -292; return HandStrength; }
					if (n2 == 1) { HandStrength = -293; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -294; return HandStrength; }
					if (n3 == 1) { HandStrength = -295; return HandStrength; }
					if (n2 == 1) { HandStrength = -296; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -297; return HandStrength; }
					if (n2 == 1) { HandStrength = -298; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -299; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -300; return HandStrength; }
					if (n9 == 1) { HandStrength = -301; return HandStrength; }
					if (n8 == 1) { HandStrength = -302; return HandStrength; }
					if (n7 == 1) { HandStrength = -303; return HandStrength; }
					if (n6 == 1) { HandStrength = -304; return HandStrength; }
					if (n5 == 1) { HandStrength = -305; return HandStrength; }
					if (n3 == 1) { HandStrength = -306; return HandStrength; }
					if (n2 == 1) { HandStrength = -307; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -308; return HandStrength; }
					if (n8 == 1) { HandStrength = -309; return HandStrength; }
					if (n7 == 1) { HandStrength = -310; return HandStrength; }
					if (n6 == 1) { HandStrength = -311; return HandStrength; }
					if (n5 == 1) { HandStrength = -312; return HandStrength; }
					if (n3 == 1) { HandStrength = -313; return HandStrength; }
					if (n2 == 1) { HandStrength = -314; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -315; return HandStrength; }
					if (n7 == 1) { HandStrength = -316; return HandStrength; }
					if (n6 == 1) { HandStrength = -317; return HandStrength; }
					if (n5 == 1) { HandStrength = -318; return HandStrength; }
					if (n3 == 1) { HandStrength = -319; return HandStrength; }
					if (n2 == 1) { HandStrength = -320; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -321; return HandStrength; }
					if (n6 == 1) { HandStrength = -322; return HandStrength; }
					if (n5 == 1) { HandStrength = -323; return HandStrength; }
					if (n3 == 1) { HandStrength = -324; return HandStrength; }
					if (n2 == 1) { HandStrength = -325; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -326; return HandStrength; }
					if (n5 == 1) { HandStrength = -327; return HandStrength; }
					if (n3 == 1) { HandStrength = -328; return HandStrength; }
					if (n2 == 1) { HandStrength = -329; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -330; return HandStrength; }
					if (n3 == 1) { HandStrength = -331; return HandStrength; }
					if (n2 == 1) { HandStrength = -332; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -333; return HandStrength; }
					if (n2 == 1) { HandStrength = -334; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -335; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -336; return HandStrength; }
					if (n8 == 1) { HandStrength = -337; return HandStrength; }
					if (n7 == 1) { HandStrength = -338; return HandStrength; }
					if (n6 == 1) { HandStrength = -339; return HandStrength; }
					if (n5 == 1) { HandStrength = -340; return HandStrength; }
					if (n3 == 1) { HandStrength = -341; return HandStrength; }
					if (n2 == 1) { HandStrength = -342; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -343; return HandStrength; }
					if (n7 == 1) { HandStrength = -344; return HandStrength; }
					if (n6 == 1) { HandStrength = -345; return HandStrength; }
					if (n5 == 1) { HandStrength = -346; return HandStrength; }
					if (n3 == 1) { HandStrength = -347; return HandStrength; }
					if (n2 == 1) { HandStrength = -348; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -349; return HandStrength; }
					if (n6 == 1) { HandStrength = -350; return HandStrength; }
					if (n5 == 1) { HandStrength = -351; return HandStrength; }
					if (n3 == 1) { HandStrength = -352; return HandStrength; }
					if (n2 == 1) { HandStrength = -353; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -354; return HandStrength; }
					if (n5 == 1) { HandStrength = -355; return HandStrength; }
					if (n3 == 1) { HandStrength = -356; return HandStrength; }
					if (n2 == 1) { HandStrength = -357; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -358; return HandStrength; }
					if (n3 == 1) { HandStrength = -359; return HandStrength; }
					if (n2 == 1) { HandStrength = -360; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -361; return HandStrength; }
					if (n2 == 1) { HandStrength = -362; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -363; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -364; return HandStrength; }
					if (n7 == 1) { HandStrength = -365; return HandStrength; }
					if (n6 == 1) { HandStrength = -366; return HandStrength; }
					if (n5 == 1) { HandStrength = -367; return HandStrength; }
					if (n3 == 1) { HandStrength = -368; return HandStrength; }
					if (n2 == 1) { HandStrength = -369; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -370; return HandStrength; }
					if (n6 == 1) { HandStrength = -371; return HandStrength; }
					if (n5 == 1) { HandStrength = -372; return HandStrength; }
					if (n3 == 1) { HandStrength = -373; return HandStrength; }
					if (n2 == 1) { HandStrength = -374; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -375; return HandStrength; }
					if (n5 == 1) { HandStrength = -376; return HandStrength; }
					if (n3 == 1) { HandStrength = -377; return HandStrength; }
					if (n2 == 1) { HandStrength = -378; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -379; return HandStrength; }
					if (n3 == 1) { HandStrength = -380; return HandStrength; }
					if (n2 == 1) { HandStrength = -381; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -382; return HandStrength; }
					if (n2 == 1) { HandStrength = -383; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -384; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -385; return HandStrength; }
					if (n6 == 1) { HandStrength = -386; return HandStrength; }
					if (n5 == 1) { HandStrength = -387; return HandStrength; }
					if (n3 == 1) { HandStrength = -388; return HandStrength; }
					if (n2 == 1) { HandStrength = -389; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -390; return HandStrength; }
					if (n5 == 1) { HandStrength = -391; return HandStrength; }
					if (n3 == 1) { HandStrength = -392; return HandStrength; }
					if (n2 == 1) { HandStrength = -393; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -394; return HandStrength; }
					if (n3 == 1) { HandStrength = -395; return HandStrength; }
					if (n2 == 1) { HandStrength = -396; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -397; return HandStrength; }
					if (n2 == 1) { HandStrength = -398; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -399; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -400; return HandStrength; }
					if (n5 == 1) { HandStrength = -401; return HandStrength; }
					if (n3 == 1) { HandStrength = -402; return HandStrength; }
					if (n2 == 1) { HandStrength = -403; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -404; return HandStrength; }
					if (n3 == 1) { HandStrength = -405; return HandStrength; }
					if (n2 == 1) { HandStrength = -406; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -407; return HandStrength; }
					if (n2 == 1) { HandStrength = -408; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -409; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -410; return HandStrength; }
					if (n3 == 1) { HandStrength = -411; return HandStrength; }
					if (n2 == 1) { HandStrength = -412; return HandStrength; }
				};
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -413; return HandStrength; }
					if (n2 == 1) { HandStrength = -414; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -415; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n3 == 1) { HandStrength = -416; return HandStrength; }
					if (n2 == 1) { HandStrength = -417; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -418; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -419; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = -420; return HandStrength; }
					if (nJ == 1) { HandStrength = -421; return HandStrength; }
					if (nT == 1) { HandStrength = -422; return HandStrength; }
					if (n9 == 1) { HandStrength = -423; return HandStrength; }
					if (n8 == 1) { HandStrength = -424; return HandStrength; }
					if (n7 == 1) { HandStrength = -425; return HandStrength; }
					if (n6 == 1) { HandStrength = -426; return HandStrength; }
					if (n5 == 1) { HandStrength = -427; return HandStrength; }
					if (n4 == 1) { HandStrength = -428; return HandStrength; }
					if (n2 == 1) { HandStrength = -429; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -430; return HandStrength; }
					if (nT == 1) { HandStrength = -431; return HandStrength; }
					if (n9 == 1) { HandStrength = -432; return HandStrength; }
					if (n8 == 1) { HandStrength = -433; return HandStrength; }
					if (n7 == 1) { HandStrength = -434; return HandStrength; }
					if (n6 == 1) { HandStrength = -435; return HandStrength; }
					if (n5 == 1) { HandStrength = -436; return HandStrength; }
					if (n4 == 1) { HandStrength = -437; return HandStrength; }
					if (n2 == 1) { HandStrength = -438; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -439; return HandStrength; }
					if (n9 == 1) { HandStrength = -440; return HandStrength; }
					if (n8 == 1) { HandStrength = -441; return HandStrength; }
					if (n7 == 1) { HandStrength = -442; return HandStrength; }
					if (n6 == 1) { HandStrength = -443; return HandStrength; }
					if (n5 == 1) { HandStrength = -444; return HandStrength; }
					if (n4 == 1) { HandStrength = -445; return HandStrength; }
					if (n2 == 1) { HandStrength = -446; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -447; return HandStrength; }
					if (n8 == 1) { HandStrength = -448; return HandStrength; }
					if (n7 == 1) { HandStrength = -449; return HandStrength; }
					if (n6 == 1) { HandStrength = -450; return HandStrength; }
					if (n5 == 1) { HandStrength = -451; return HandStrength; }
					if (n4 == 1) { HandStrength = -452; return HandStrength; }
					if (n2 == 1) { HandStrength = -453; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -454; return HandStrength; }
					if (n7 == 1) { HandStrength = -455; return HandStrength; }
					if (n6 == 1) { HandStrength = -456; return HandStrength; }
					if (n5 == 1) { HandStrength = -457; return HandStrength; }
					if (n4 == 1) { HandStrength = -458; return HandStrength; }
					if (n2 == 1) { HandStrength = -459; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -460; return HandStrength; }
					if (n6 == 1) { HandStrength = -461; return HandStrength; }
					if (n5 == 1) { HandStrength = -462; return HandStrength; }
					if (n4 == 1) { HandStrength = -463; return HandStrength; }
					if (n2 == 1) { HandStrength = -464; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -465; return HandStrength; }
					if (n5 == 1) { HandStrength = -466; return HandStrength; }
					if (n4 == 1) { HandStrength = -467; return HandStrength; }
					if (n2 == 1) { HandStrength = -468; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -469; return HandStrength; }
					if (n4 == 1) { HandStrength = -470; return HandStrength; }
					if (n2 == 1) { HandStrength = -471; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -472; return HandStrength; }
					if (n2 == 1) { HandStrength = -473; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -474; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -475; return HandStrength; }
					if (nT == 1) { HandStrength = -476; return HandStrength; }
					if (n9 == 1) { HandStrength = -477; return HandStrength; }
					if (n8 == 1) { HandStrength = -478; return HandStrength; }
					if (n7 == 1) { HandStrength = -479; return HandStrength; }
					if (n6 == 1) { HandStrength = -480; return HandStrength; }
					if (n5 == 1) { HandStrength = -481; return HandStrength; }
					if (n4 == 1) { HandStrength = -482; return HandStrength; }
					if (n2 == 1) { HandStrength = -483; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -484; return HandStrength; }
					if (n9 == 1) { HandStrength = -485; return HandStrength; }
					if (n8 == 1) { HandStrength = -486; return HandStrength; }
					if (n7 == 1) { HandStrength = -487; return HandStrength; }
					if (n6 == 1) { HandStrength = -488; return HandStrength; }
					if (n5 == 1) { HandStrength = -489; return HandStrength; }
					if (n4 == 1) { HandStrength = -490; return HandStrength; }
					if (n2 == 1) { HandStrength = -491; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -492; return HandStrength; }
					if (n8 == 1) { HandStrength = -493; return HandStrength; }
					if (n7 == 1) { HandStrength = -494; return HandStrength; }
					if (n6 == 1) { HandStrength = -495; return HandStrength; }
					if (n5 == 1) { HandStrength = -496; return HandStrength; }
					if (n4 == 1) { HandStrength = -497; return HandStrength; }
					if (n2 == 1) { HandStrength = -498; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -499; return HandStrength; }
					if (n7 == 1) { HandStrength = -500; return HandStrength; }
					if (n6 == 1) { HandStrength = -501; return HandStrength; }
					if (n5 == 1) { HandStrength = -502; return HandStrength; }
					if (n4 == 1) { HandStrength = -503; return HandStrength; }
					if (n2 == 1) { HandStrength = -504; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -505; return HandStrength; }
					if (n6 == 1) { HandStrength = -506; return HandStrength; }
					if (n5 == 1) { HandStrength = -507; return HandStrength; }
					if (n4 == 1) { HandStrength = -508; return HandStrength; }
					if (n2 == 1) { HandStrength = -509; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -510; return HandStrength; }
					if (n5 == 1) { HandStrength = -511; return HandStrength; }
					if (n4 == 1) { HandStrength = -512; return HandStrength; }
					if (n2 == 1) { HandStrength = -513; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -514; return HandStrength; }
					if (n4 == 1) { HandStrength = -515; return HandStrength; }
					if (n2 == 1) { HandStrength = -516; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -517; return HandStrength; }
					if (n2 == 1) { HandStrength = -518; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -519; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -520; return HandStrength; }
					if (n9 == 1) { HandStrength = -521; return HandStrength; }
					if (n8 == 1) { HandStrength = -522; return HandStrength; }
					if (n7 == 1) { HandStrength = -523; return HandStrength; }
					if (n6 == 1) { HandStrength = -524; return HandStrength; }
					if (n5 == 1) { HandStrength = -525; return HandStrength; }
					if (n4 == 1) { HandStrength = -526; return HandStrength; }
					if (n2 == 1) { HandStrength = -527; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -528; return HandStrength; }
					if (n8 == 1) { HandStrength = -529; return HandStrength; }
					if (n7 == 1) { HandStrength = -530; return HandStrength; }
					if (n6 == 1) { HandStrength = -531; return HandStrength; }
					if (n5 == 1) { HandStrength = -532; return HandStrength; }
					if (n4 == 1) { HandStrength = -533; return HandStrength; }
					if (n2 == 1) { HandStrength = -534; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -535; return HandStrength; }
					if (n7 == 1) { HandStrength = -536; return HandStrength; }
					if (n6 == 1) { HandStrength = -537; return HandStrength; }
					if (n5 == 1) { HandStrength = -538; return HandStrength; }
					if (n4 == 1) { HandStrength = -539; return HandStrength; }
					if (n2 == 1) { HandStrength = -540; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -541; return HandStrength; }
					if (n6 == 1) { HandStrength = -542; return HandStrength; }
					if (n5 == 1) { HandStrength = -543; return HandStrength; }
					if (n4 == 1) { HandStrength = -544; return HandStrength; }
					if (n2 == 1) { HandStrength = -545; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -546; return HandStrength; }
					if (n5 == 1) { HandStrength = -547; return HandStrength; }
					if (n4 == 1) { HandStrength = -548; return HandStrength; }
					if (n2 == 1) { HandStrength = -549; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -550; return HandStrength; }
					if (n4 == 1) { HandStrength = -551; return HandStrength; }
					if (n2 == 1) { HandStrength = -552; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -553; return HandStrength; }
					if (n2 == 1) { HandStrength = -554; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -555; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -556; return HandStrength; }
					if (n8 == 1) { HandStrength = -557; return HandStrength; }
					if (n7 == 1) { HandStrength = -558; return HandStrength; }
					if (n6 == 1) { HandStrength = -559; return HandStrength; }
					if (n5 == 1) { HandStrength = -560; return HandStrength; }
					if (n4 == 1) { HandStrength = -561; return HandStrength; }
					if (n2 == 1) { HandStrength = -562; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -563; return HandStrength; }
					if (n7 == 1) { HandStrength = -564; return HandStrength; }
					if (n6 == 1) { HandStrength = -565; return HandStrength; }
					if (n5 == 1) { HandStrength = -566; return HandStrength; }
					if (n4 == 1) { HandStrength = -567; return HandStrength; }
					if (n2 == 1) { HandStrength = -568; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -569; return HandStrength; }
					if (n6 == 1) { HandStrength = -570; return HandStrength; }
					if (n5 == 1) { HandStrength = -571; return HandStrength; }
					if (n4 == 1) { HandStrength = -572; return HandStrength; }
					if (n2 == 1) { HandStrength = -573; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -574; return HandStrength; }
					if (n5 == 1) { HandStrength = -575; return HandStrength; }
					if (n4 == 1) { HandStrength = -576; return HandStrength; }
					if (n2 == 1) { HandStrength = -577; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -578; return HandStrength; }
					if (n4 == 1) { HandStrength = -579; return HandStrength; }
					if (n2 == 1) { HandStrength = -580; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -581; return HandStrength; }
					if (n2 == 1) { HandStrength = -582; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -583; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -584; return HandStrength; }
					if (n7 == 1) { HandStrength = -585; return HandStrength; }
					if (n6 == 1) { HandStrength = -586; return HandStrength; }
					if (n5 == 1) { HandStrength = -587; return HandStrength; }
					if (n4 == 1) { HandStrength = -588; return HandStrength; }
					if (n2 == 1) { HandStrength = -589; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -590; return HandStrength; }
					if (n6 == 1) { HandStrength = -591; return HandStrength; }
					if (n5 == 1) { HandStrength = -592; return HandStrength; }
					if (n4 == 1) { HandStrength = -593; return HandStrength; }
					if (n2 == 1) { HandStrength = -594; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -595; return HandStrength; }
					if (n5 == 1) { HandStrength = -596; return HandStrength; }
					if (n4 == 1) { HandStrength = -597; return HandStrength; }
					if (n2 == 1) { HandStrength = -598; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -599; return HandStrength; }
					if (n4 == 1) { HandStrength = -600; return HandStrength; }
					if (n2 == 1) { HandStrength = -601; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -602; return HandStrength; }
					if (n2 == 1) { HandStrength = -603; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -604; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -605; return HandStrength; }
					if (n6 == 1) { HandStrength = -606; return HandStrength; }
					if (n5 == 1) { HandStrength = -607; return HandStrength; }
					if (n4 == 1) { HandStrength = -608; return HandStrength; }
					if (n2 == 1) { HandStrength = -609; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -610; return HandStrength; }
					if (n5 == 1) { HandStrength = -611; return HandStrength; }
					if (n4 == 1) { HandStrength = -612; return HandStrength; }
					if (n2 == 1) { HandStrength = -613; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -614; return HandStrength; }
					if (n4 == 1) { HandStrength = -615; return HandStrength; }
					if (n2 == 1) { HandStrength = -616; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -617; return HandStrength; }
					if (n2 == 1) { HandStrength = -618; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -619; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -620; return HandStrength; }
					if (n5 == 1) { HandStrength = -621; return HandStrength; }
					if (n4 == 1) { HandStrength = -622; return HandStrength; }
					if (n2 == 1) { HandStrength = -623; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -624; return HandStrength; }
					if (n4 == 1) { HandStrength = -625; return HandStrength; }
					if (n2 == 1) { HandStrength = -626; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -627; return HandStrength; }
					if (n2 == 1) { HandStrength = -628; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -629; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -630; return HandStrength; }
					if (n4 == 1) { HandStrength = -631; return HandStrength; }
					if (n2 == 1) { HandStrength = -632; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -633; return HandStrength; }
					if (n2 == 1) { HandStrength = -634; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -635; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -636; return HandStrength; }
					if (n2 == 1) { HandStrength = -637; return HandStrength; }
				};
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -638; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n2 == 1) { HandStrength = -639; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n2 == 2) {
			if (nA == 1) {
				if (nK == 1) {
					if (nQ == 1) { HandStrength = -640; return HandStrength; }
					if (nJ == 1) { HandStrength = -641; return HandStrength; }
					if (nT == 1) { HandStrength = -642; return HandStrength; }
					if (n9 == 1) { HandStrength = -643; return HandStrength; }
					if (n8 == 1) { HandStrength = -644; return HandStrength; }
					if (n7 == 1) { HandStrength = -645; return HandStrength; }
					if (n6 == 1) { HandStrength = -646; return HandStrength; }
					if (n5 == 1) { HandStrength = -647; return HandStrength; }
					if (n4 == 1) { HandStrength = -648; return HandStrength; }
					if (n3 == 1) { HandStrength = -649; return HandStrength; }
				};
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -650; return HandStrength; }
					if (nT == 1) { HandStrength = -651; return HandStrength; }
					if (n9 == 1) { HandStrength = -652; return HandStrength; }
					if (n8 == 1) { HandStrength = -653; return HandStrength; }
					if (n7 == 1) { HandStrength = -654; return HandStrength; }
					if (n6 == 1) { HandStrength = -655; return HandStrength; }
					if (n5 == 1) { HandStrength = -656; return HandStrength; }
					if (n4 == 1) { HandStrength = -657; return HandStrength; }
					if (n3 == 1) { HandStrength = -658; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -659; return HandStrength; }
					if (n9 == 1) { HandStrength = -660; return HandStrength; }
					if (n8 == 1) { HandStrength = -661; return HandStrength; }
					if (n7 == 1) { HandStrength = -662; return HandStrength; }
					if (n6 == 1) { HandStrength = -663; return HandStrength; }
					if (n5 == 1) { HandStrength = -664; return HandStrength; }
					if (n4 == 1) { HandStrength = -665; return HandStrength; }
					if (n3 == 1) { HandStrength = -666; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -667; return HandStrength; }
					if (n8 == 1) { HandStrength = -668; return HandStrength; }
					if (n7 == 1) { HandStrength = -669; return HandStrength; }
					if (n6 == 1) { HandStrength = -670; return HandStrength; }
					if (n5 == 1) { HandStrength = -671; return HandStrength; }
					if (n4 == 1) { HandStrength = -672; return HandStrength; }
					if (n3 == 1) { HandStrength = -673; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -674; return HandStrength; }
					if (n7 == 1) { HandStrength = -675; return HandStrength; }
					if (n6 == 1) { HandStrength = -676; return HandStrength; }
					if (n5 == 1) { HandStrength = -677; return HandStrength; }
					if (n4 == 1) { HandStrength = -678; return HandStrength; }
					if (n3 == 1) { HandStrength = -679; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -680; return HandStrength; }
					if (n6 == 1) { HandStrength = -681; return HandStrength; }
					if (n5 == 1) { HandStrength = -682; return HandStrength; }
					if (n4 == 1) { HandStrength = -683; return HandStrength; }
					if (n3 == 1) { HandStrength = -684; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -685; return HandStrength; }
					if (n5 == 1) { HandStrength = -686; return HandStrength; }
					if (n4 == 1) { HandStrength = -687; return HandStrength; }
					if (n3 == 1) { HandStrength = -688; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -689; return HandStrength; }
					if (n4 == 1) { HandStrength = -690; return HandStrength; }
					if (n3 == 1) { HandStrength = -691; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -692; return HandStrength; }
					if (n3 == 1) { HandStrength = -693; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -694; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nK == 1) {
				if (nQ == 1) {
					if (nJ == 1) { HandStrength = -695; return HandStrength; }
					if (nT == 1) { HandStrength = -696; return HandStrength; }
					if (n9 == 1) { HandStrength = -697; return HandStrength; }
					if (n8 == 1) { HandStrength = -698; return HandStrength; }
					if (n7 == 1) { HandStrength = -699; return HandStrength; }
					if (n6 == 1) { HandStrength = -700; return HandStrength; }
					if (n5 == 1) { HandStrength = -701; return HandStrength; }
					if (n4 == 1) { HandStrength = -702; return HandStrength; }
					if (n3 == 1) { HandStrength = -703; return HandStrength; }
				};
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -704; return HandStrength; }
					if (n9 == 1) { HandStrength = -705; return HandStrength; }
					if (n8 == 1) { HandStrength = -706; return HandStrength; }
					if (n7 == 1) { HandStrength = -707; return HandStrength; }
					if (n6 == 1) { HandStrength = -708; return HandStrength; }
					if (n5 == 1) { HandStrength = -709; return HandStrength; }
					if (n4 == 1) { HandStrength = -710; return HandStrength; }
					if (n3 == 1) { HandStrength = -711; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -712; return HandStrength; }
					if (n8 == 1) { HandStrength = -713; return HandStrength; }
					if (n7 == 1) { HandStrength = -714; return HandStrength; }
					if (n6 == 1) { HandStrength = -715; return HandStrength; }
					if (n5 == 1) { HandStrength = -716; return HandStrength; }
					if (n4 == 1) { HandStrength = -717; return HandStrength; }
					if (n3 == 1) { HandStrength = -718; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -719; return HandStrength; }
					if (n7 == 1) { HandStrength = -720; return HandStrength; }
					if (n6 == 1) { HandStrength = -721; return HandStrength; }
					if (n5 == 1) { HandStrength = -722; return HandStrength; }
					if (n4 == 1) { HandStrength = -723; return HandStrength; }
					if (n3 == 1) { HandStrength = -724; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -725; return HandStrength; }
					if (n6 == 1) { HandStrength = -726; return HandStrength; }
					if (n5 == 1) { HandStrength = -727; return HandStrength; }
					if (n4 == 1) { HandStrength = -728; return HandStrength; }
					if (n3 == 1) { HandStrength = -729; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -730; return HandStrength; }
					if (n5 == 1) { HandStrength = -731; return HandStrength; }
					if (n4 == 1) { HandStrength = -732; return HandStrength; }
					if (n3 == 1) { HandStrength = -733; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -734; return HandStrength; }
					if (n4 == 1) { HandStrength = -735; return HandStrength; }
					if (n3 == 1) { HandStrength = -736; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -737; return HandStrength; }
					if (n3 == 1) { HandStrength = -738; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -739; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -740; return HandStrength; }
					if (n9 == 1) { HandStrength = -741; return HandStrength; }
					if (n8 == 1) { HandStrength = -742; return HandStrength; }
					if (n7 == 1) { HandStrength = -743; return HandStrength; }
					if (n6 == 1) { HandStrength = -744; return HandStrength; }
					if (n5 == 1) { HandStrength = -745; return HandStrength; }
					if (n4 == 1) { HandStrength = -746; return HandStrength; }
					if (n3 == 1) { HandStrength = -747; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -748; return HandStrength; }
					if (n8 == 1) { HandStrength = -749; return HandStrength; }
					if (n7 == 1) { HandStrength = -750; return HandStrength; }
					if (n6 == 1) { HandStrength = -751; return HandStrength; }
					if (n5 == 1) { HandStrength = -752; return HandStrength; }
					if (n4 == 1) { HandStrength = -753; return HandStrength; }
					if (n3 == 1) { HandStrength = -754; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -755; return HandStrength; }
					if (n7 == 1) { HandStrength = -756; return HandStrength; }
					if (n6 == 1) { HandStrength = -757; return HandStrength; }
					if (n5 == 1) { HandStrength = -758; return HandStrength; }
					if (n4 == 1) { HandStrength = -759; return HandStrength; }
					if (n3 == 1) { HandStrength = -760; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -761; return HandStrength; }
					if (n6 == 1) { HandStrength = -762; return HandStrength; }
					if (n5 == 1) { HandStrength = -763; return HandStrength; }
					if (n4 == 1) { HandStrength = -764; return HandStrength; }
					if (n3 == 1) { HandStrength = -765; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -766; return HandStrength; }
					if (n5 == 1) { HandStrength = -767; return HandStrength; }
					if (n4 == 1) { HandStrength = -768; return HandStrength; }
					if (n3 == 1) { HandStrength = -769; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -770; return HandStrength; }
					if (n4 == 1) { HandStrength = -771; return HandStrength; }
					if (n3 == 1) { HandStrength = -772; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -773; return HandStrength; }
					if (n3 == 1) { HandStrength = -774; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -775; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -776; return HandStrength; }
					if (n8 == 1) { HandStrength = -777; return HandStrength; }
					if (n7 == 1) { HandStrength = -778; return HandStrength; }
					if (n6 == 1) { HandStrength = -779; return HandStrength; }
					if (n5 == 1) { HandStrength = -780; return HandStrength; }
					if (n4 == 1) { HandStrength = -781; return HandStrength; }
					if (n3 == 1) { HandStrength = -782; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -783; return HandStrength; }
					if (n7 == 1) { HandStrength = -784; return HandStrength; }
					if (n6 == 1) { HandStrength = -785; return HandStrength; }
					if (n5 == 1) { HandStrength = -786; return HandStrength; }
					if (n4 == 1) { HandStrength = -787; return HandStrength; }
					if (n3 == 1) { HandStrength = -788; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -789; return HandStrength; }
					if (n6 == 1) { HandStrength = -790; return HandStrength; }
					if (n5 == 1) { HandStrength = -791; return HandStrength; }
					if (n4 == 1) { HandStrength = -792; return HandStrength; }
					if (n3 == 1) { HandStrength = -793; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -794; return HandStrength; }
					if (n5 == 1) { HandStrength = -795; return HandStrength; }
					if (n4 == 1) { HandStrength = -796; return HandStrength; }
					if (n3 == 1) { HandStrength = -797; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -798; return HandStrength; }
					if (n4 == 1) { HandStrength = -799; return HandStrength; }
					if (n3 == 1) { HandStrength = -800; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -801; return HandStrength; }
					if (n3 == 1) { HandStrength = -802; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -803; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -804; return HandStrength; }
					if (n7 == 1) { HandStrength = -805; return HandStrength; }
					if (n6 == 1) { HandStrength = -806; return HandStrength; }
					if (n5 == 1) { HandStrength = -807; return HandStrength; }
					if (n4 == 1) { HandStrength = -808; return HandStrength; }
					if (n3 == 1) { HandStrength = -809; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -810; return HandStrength; }
					if (n6 == 1) { HandStrength = -811; return HandStrength; }
					if (n5 == 1) { HandStrength = -812; return HandStrength; }
					if (n4 == 1) { HandStrength = -813; return HandStrength; }
					if (n3 == 1) { HandStrength = -814; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -815; return HandStrength; }
					if (n5 == 1) { HandStrength = -816; return HandStrength; }
					if (n4 == 1) { HandStrength = -817; return HandStrength; }
					if (n3 == 1) { HandStrength = -818; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -819; return HandStrength; }
					if (n4 == 1) { HandStrength = -820; return HandStrength; }
					if (n3 == 1) { HandStrength = -821; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -822; return HandStrength; }
					if (n3 == 1) { HandStrength = -823; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -824; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -825; return HandStrength; }
					if (n6 == 1) { HandStrength = -826; return HandStrength; }
					if (n5 == 1) { HandStrength = -827; return HandStrength; }
					if (n4 == 1) { HandStrength = -828; return HandStrength; }
					if (n3 == 1) { HandStrength = -829; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -830; return HandStrength; }
					if (n5 == 1) { HandStrength = -831; return HandStrength; }
					if (n4 == 1) { HandStrength = -832; return HandStrength; }
					if (n3 == 1) { HandStrength = -833; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -834; return HandStrength; }
					if (n4 == 1) { HandStrength = -835; return HandStrength; }
					if (n3 == 1) { HandStrength = -836; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -837; return HandStrength; }
					if (n3 == 1) { HandStrength = -838; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -839; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -840; return HandStrength; }
					if (n5 == 1) { HandStrength = -841; return HandStrength; }
					if (n4 == 1) { HandStrength = -842; return HandStrength; }
					if (n3 == 1) { HandStrength = -843; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -844; return HandStrength; }
					if (n4 == 1) { HandStrength = -845; return HandStrength; }
					if (n3 == 1) { HandStrength = -846; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -847; return HandStrength; }
					if (n3 == 1) { HandStrength = -848; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -849; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -850; return HandStrength; }
					if (n4 == 1) { HandStrength = -851; return HandStrength; }
					if (n3 == 1) { HandStrength = -852; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -853; return HandStrength; }
					if (n3 == 1) { HandStrength = -854; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -855; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -856; return HandStrength; }
					if (n3 == 1) { HandStrength = -857; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -858; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -859; return HandStrength; }
				};
				if (n3 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
				};
			};
			if (n3 == 1) {
			};
		};
	};

	HandStrength = -1000;
	//high card
	if (CheckKicker == false) {
		if (nA == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (nK == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (nQ == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (nJ == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (nT == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n9 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n8 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n7 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n6 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n5 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n4 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n3 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
		if (n2 == 1) { return HandStrength; }
		else { HandStrength -= 1; };
	}

	if (nA == 1) {
		if (nK == 1) {
			if (nQ == 1) {
				if (nJ == 1) {
					if (nT == 1) { HandStrength = -1000; return HandStrength; }
					if (n9 == 1) { HandStrength = -1001; return HandStrength; }
					if (n8 == 1) { HandStrength = -1002; return HandStrength; }
					if (n7 == 1) { HandStrength = -1003; return HandStrength; }
					if (n6 == 1) { HandStrength = -1004; return HandStrength; }
					if (n5 == 1) { HandStrength = -1005; return HandStrength; }
					if (n4 == 1) { HandStrength = -1006; return HandStrength; }
					if (n3 == 1) { HandStrength = -1007; return HandStrength; }
					if (n2 == 1) { HandStrength = -1008; return HandStrength; }
				};
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -1009; return HandStrength; }
					if (n8 == 1) { HandStrength = -1010; return HandStrength; }
					if (n7 == 1) { HandStrength = -1011; return HandStrength; }
					if (n6 == 1) { HandStrength = -1012; return HandStrength; }
					if (n5 == 1) { HandStrength = -1013; return HandStrength; }
					if (n4 == 1) { HandStrength = -1014; return HandStrength; }
					if (n3 == 1) { HandStrength = -1015; return HandStrength; }
					if (n2 == 1) { HandStrength = -1016; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1017; return HandStrength; }
					if (n7 == 1) { HandStrength = -1018; return HandStrength; }
					if (n6 == 1) { HandStrength = -1019; return HandStrength; }
					if (n5 == 1) { HandStrength = -1020; return HandStrength; }
					if (n4 == 1) { HandStrength = -1021; return HandStrength; }
					if (n3 == 1) { HandStrength = -1022; return HandStrength; }
					if (n2 == 1) { HandStrength = -1023; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1024; return HandStrength; }
					if (n6 == 1) { HandStrength = -1025; return HandStrength; }
					if (n5 == 1) { HandStrength = -1026; return HandStrength; }
					if (n4 == 1) { HandStrength = -1027; return HandStrength; }
					if (n3 == 1) { HandStrength = -1028; return HandStrength; }
					if (n2 == 1) { HandStrength = -1029; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1030; return HandStrength; }
					if (n5 == 1) { HandStrength = -1031; return HandStrength; }
					if (n4 == 1) { HandStrength = -1032; return HandStrength; }
					if (n3 == 1) { HandStrength = -1033; return HandStrength; }
					if (n2 == 1) { HandStrength = -1034; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1035; return HandStrength; }
					if (n4 == 1) { HandStrength = -1036; return HandStrength; }
					if (n3 == 1) { HandStrength = -1037; return HandStrength; }
					if (n2 == 1) { HandStrength = -1038; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1039; return HandStrength; }
					if (n3 == 1) { HandStrength = -1040; return HandStrength; }
					if (n2 == 1) { HandStrength = -1041; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1042; return HandStrength; }
					if (n2 == 1) { HandStrength = -1043; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1044; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -1045; return HandStrength; }
					if (n8 == 1) { HandStrength = -1046; return HandStrength; }
					if (n7 == 1) { HandStrength = -1047; return HandStrength; }
					if (n6 == 1) { HandStrength = -1048; return HandStrength; }
					if (n5 == 1) { HandStrength = -1049; return HandStrength; }
					if (n4 == 1) { HandStrength = -1050; return HandStrength; }
					if (n3 == 1) { HandStrength = -1051; return HandStrength; }
					if (n2 == 1) { HandStrength = -1052; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1053; return HandStrength; }
					if (n7 == 1) { HandStrength = -1054; return HandStrength; }
					if (n6 == 1) { HandStrength = -1055; return HandStrength; }
					if (n5 == 1) { HandStrength = -1056; return HandStrength; }
					if (n4 == 1) { HandStrength = -1057; return HandStrength; }
					if (n3 == 1) { HandStrength = -1058; return HandStrength; }
					if (n2 == 1) { HandStrength = -1059; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1060; return HandStrength; }
					if (n6 == 1) { HandStrength = -1061; return HandStrength; }
					if (n5 == 1) { HandStrength = -1062; return HandStrength; }
					if (n4 == 1) { HandStrength = -1063; return HandStrength; }
					if (n3 == 1) { HandStrength = -1064; return HandStrength; }
					if (n2 == 1) { HandStrength = -1065; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1066; return HandStrength; }
					if (n5 == 1) { HandStrength = -1067; return HandStrength; }
					if (n4 == 1) { HandStrength = -1068; return HandStrength; }
					if (n3 == 1) { HandStrength = -1069; return HandStrength; }
					if (n2 == 1) { HandStrength = -1070; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1071; return HandStrength; }
					if (n4 == 1) { HandStrength = -1072; return HandStrength; }
					if (n3 == 1) { HandStrength = -1073; return HandStrength; }
					if (n2 == 1) { HandStrength = -1074; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1075; return HandStrength; }
					if (n3 == 1) { HandStrength = -1076; return HandStrength; }
					if (n2 == 1) { HandStrength = -1077; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1078; return HandStrength; }
					if (n2 == 1) { HandStrength = -1079; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1080; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1081; return HandStrength; }
					if (n7 == 1) { HandStrength = -1082; return HandStrength; }
					if (n6 == 1) { HandStrength = -1083; return HandStrength; }
					if (n5 == 1) { HandStrength = -1084; return HandStrength; }
					if (n4 == 1) { HandStrength = -1085; return HandStrength; }
					if (n3 == 1) { HandStrength = -1086; return HandStrength; }
					if (n2 == 1) { HandStrength = -1087; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1088; return HandStrength; }
					if (n6 == 1) { HandStrength = -1089; return HandStrength; }
					if (n5 == 1) { HandStrength = -1090; return HandStrength; }
					if (n4 == 1) { HandStrength = -1091; return HandStrength; }
					if (n3 == 1) { HandStrength = -1092; return HandStrength; }
					if (n2 == 1) { HandStrength = -1093; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1094; return HandStrength; }
					if (n5 == 1) { HandStrength = -1095; return HandStrength; }
					if (n4 == 1) { HandStrength = -1096; return HandStrength; }
					if (n3 == 1) { HandStrength = -1097; return HandStrength; }
					if (n2 == 1) { HandStrength = -1098; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1099; return HandStrength; }
					if (n4 == 1) { HandStrength = -1100; return HandStrength; }
					if (n3 == 1) { HandStrength = -1101; return HandStrength; }
					if (n2 == 1) { HandStrength = -1102; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1103; return HandStrength; }
					if (n3 == 1) { HandStrength = -1104; return HandStrength; }
					if (n2 == 1) { HandStrength = -1105; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1106; return HandStrength; }
					if (n2 == 1) { HandStrength = -1107; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1108; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1109; return HandStrength; }
					if (n6 == 1) { HandStrength = -1110; return HandStrength; }
					if (n5 == 1) { HandStrength = -1111; return HandStrength; }
					if (n4 == 1) { HandStrength = -1112; return HandStrength; }
					if (n3 == 1) { HandStrength = -1113; return HandStrength; }
					if (n2 == 1) { HandStrength = -1114; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1115; return HandStrength; }
					if (n5 == 1) { HandStrength = -1116; return HandStrength; }
					if (n4 == 1) { HandStrength = -1117; return HandStrength; }
					if (n3 == 1) { HandStrength = -1118; return HandStrength; }
					if (n2 == 1) { HandStrength = -1119; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1120; return HandStrength; }
					if (n4 == 1) { HandStrength = -1121; return HandStrength; }
					if (n3 == 1) { HandStrength = -1122; return HandStrength; }
					if (n2 == 1) { HandStrength = -1123; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1124; return HandStrength; }
					if (n3 == 1) { HandStrength = -1125; return HandStrength; }
					if (n2 == 1) { HandStrength = -1126; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1127; return HandStrength; }
					if (n2 == 1) { HandStrength = -1128; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1129; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1130; return HandStrength; }
					if (n5 == 1) { HandStrength = -1131; return HandStrength; }
					if (n4 == 1) { HandStrength = -1132; return HandStrength; }
					if (n3 == 1) { HandStrength = -1133; return HandStrength; }
					if (n2 == 1) { HandStrength = -1134; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1135; return HandStrength; }
					if (n4 == 1) { HandStrength = -1136; return HandStrength; }
					if (n3 == 1) { HandStrength = -1137; return HandStrength; }
					if (n2 == 1) { HandStrength = -1138; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1139; return HandStrength; }
					if (n3 == 1) { HandStrength = -1140; return HandStrength; }
					if (n2 == 1) { HandStrength = -1141; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1142; return HandStrength; }
					if (n2 == 1) { HandStrength = -1143; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1144; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1145; return HandStrength; }
					if (n4 == 1) { HandStrength = -1146; return HandStrength; }
					if (n3 == 1) { HandStrength = -1147; return HandStrength; }
					if (n2 == 1) { HandStrength = -1148; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1149; return HandStrength; }
					if (n3 == 1) { HandStrength = -1150; return HandStrength; }
					if (n2 == 1) { HandStrength = -1151; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1152; return HandStrength; }
					if (n2 == 1) { HandStrength = -1153; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1154; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1155; return HandStrength; }
					if (n3 == 1) { HandStrength = -1156; return HandStrength; }
					if (n2 == 1) { HandStrength = -1157; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1158; return HandStrength; }
					if (n2 == 1) { HandStrength = -1159; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1160; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1161; return HandStrength; }
					if (n2 == 1) { HandStrength = -1162; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1163; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1164; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nQ == 1) {
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -1165; return HandStrength; }
					if (n8 == 1) { HandStrength = -1166; return HandStrength; }
					if (n7 == 1) { HandStrength = -1167; return HandStrength; }
					if (n6 == 1) { HandStrength = -1168; return HandStrength; }
					if (n5 == 1) { HandStrength = -1169; return HandStrength; }
					if (n4 == 1) { HandStrength = -1170; return HandStrength; }
					if (n3 == 1) { HandStrength = -1171; return HandStrength; }
					if (n2 == 1) { HandStrength = -1172; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1173; return HandStrength; }
					if (n7 == 1) { HandStrength = -1174; return HandStrength; }
					if (n6 == 1) { HandStrength = -1175; return HandStrength; }
					if (n5 == 1) { HandStrength = -1176; return HandStrength; }
					if (n4 == 1) { HandStrength = -1177; return HandStrength; }
					if (n3 == 1) { HandStrength = -1178; return HandStrength; }
					if (n2 == 1) { HandStrength = -1179; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1180; return HandStrength; }
					if (n6 == 1) { HandStrength = -1181; return HandStrength; }
					if (n5 == 1) { HandStrength = -1182; return HandStrength; }
					if (n4 == 1) { HandStrength = -1183; return HandStrength; }
					if (n3 == 1) { HandStrength = -1184; return HandStrength; }
					if (n2 == 1) { HandStrength = -1185; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1186; return HandStrength; }
					if (n5 == 1) { HandStrength = -1187; return HandStrength; }
					if (n4 == 1) { HandStrength = -1188; return HandStrength; }
					if (n3 == 1) { HandStrength = -1189; return HandStrength; }
					if (n2 == 1) { HandStrength = -1190; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1191; return HandStrength; }
					if (n4 == 1) { HandStrength = -1192; return HandStrength; }
					if (n3 == 1) { HandStrength = -1193; return HandStrength; }
					if (n2 == 1) { HandStrength = -1194; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1195; return HandStrength; }
					if (n3 == 1) { HandStrength = -1196; return HandStrength; }
					if (n2 == 1) { HandStrength = -1197; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1198; return HandStrength; }
					if (n2 == 1) { HandStrength = -1199; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1200; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1201; return HandStrength; }
					if (n7 == 1) { HandStrength = -1202; return HandStrength; }
					if (n6 == 1) { HandStrength = -1203; return HandStrength; }
					if (n5 == 1) { HandStrength = -1204; return HandStrength; }
					if (n4 == 1) { HandStrength = -1205; return HandStrength; }
					if (n3 == 1) { HandStrength = -1206; return HandStrength; }
					if (n2 == 1) { HandStrength = -1207; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1208; return HandStrength; }
					if (n6 == 1) { HandStrength = -1209; return HandStrength; }
					if (n5 == 1) { HandStrength = -1210; return HandStrength; }
					if (n4 == 1) { HandStrength = -1211; return HandStrength; }
					if (n3 == 1) { HandStrength = -1212; return HandStrength; }
					if (n2 == 1) { HandStrength = -1213; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1214; return HandStrength; }
					if (n5 == 1) { HandStrength = -1215; return HandStrength; }
					if (n4 == 1) { HandStrength = -1216; return HandStrength; }
					if (n3 == 1) { HandStrength = -1217; return HandStrength; }
					if (n2 == 1) { HandStrength = -1218; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1219; return HandStrength; }
					if (n4 == 1) { HandStrength = -1220; return HandStrength; }
					if (n3 == 1) { HandStrength = -1221; return HandStrength; }
					if (n2 == 1) { HandStrength = -1222; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1223; return HandStrength; }
					if (n3 == 1) { HandStrength = -1224; return HandStrength; }
					if (n2 == 1) { HandStrength = -1225; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1226; return HandStrength; }
					if (n2 == 1) { HandStrength = -1227; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1228; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1229; return HandStrength; }
					if (n6 == 1) { HandStrength = -1230; return HandStrength; }
					if (n5 == 1) { HandStrength = -1231; return HandStrength; }
					if (n4 == 1) { HandStrength = -1232; return HandStrength; }
					if (n3 == 1) { HandStrength = -1233; return HandStrength; }
					if (n2 == 1) { HandStrength = -1234; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1235; return HandStrength; }
					if (n5 == 1) { HandStrength = -1236; return HandStrength; }
					if (n4 == 1) { HandStrength = -1237; return HandStrength; }
					if (n3 == 1) { HandStrength = -1238; return HandStrength; }
					if (n2 == 1) { HandStrength = -1239; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1240; return HandStrength; }
					if (n4 == 1) { HandStrength = -1241; return HandStrength; }
					if (n3 == 1) { HandStrength = -1242; return HandStrength; }
					if (n2 == 1) { HandStrength = -1243; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1244; return HandStrength; }
					if (n3 == 1) { HandStrength = -1245; return HandStrength; }
					if (n2 == 1) { HandStrength = -1246; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1247; return HandStrength; }
					if (n2 == 1) { HandStrength = -1248; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1249; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1250; return HandStrength; }
					if (n5 == 1) { HandStrength = -1251; return HandStrength; }
					if (n4 == 1) { HandStrength = -1252; return HandStrength; }
					if (n3 == 1) { HandStrength = -1253; return HandStrength; }
					if (n2 == 1) { HandStrength = -1254; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1255; return HandStrength; }
					if (n4 == 1) { HandStrength = -1256; return HandStrength; }
					if (n3 == 1) { HandStrength = -1257; return HandStrength; }
					if (n2 == 1) { HandStrength = -1258; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1259; return HandStrength; }
					if (n3 == 1) { HandStrength = -1260; return HandStrength; }
					if (n2 == 1) { HandStrength = -1261; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1262; return HandStrength; }
					if (n2 == 1) { HandStrength = -1263; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1264; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1265; return HandStrength; }
					if (n4 == 1) { HandStrength = -1266; return HandStrength; }
					if (n3 == 1) { HandStrength = -1267; return HandStrength; }
					if (n2 == 1) { HandStrength = -1268; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1269; return HandStrength; }
					if (n3 == 1) { HandStrength = -1270; return HandStrength; }
					if (n2 == 1) { HandStrength = -1271; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1272; return HandStrength; }
					if (n2 == 1) { HandStrength = -1273; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1274; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1275; return HandStrength; }
					if (n3 == 1) { HandStrength = -1276; return HandStrength; }
					if (n2 == 1) { HandStrength = -1277; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1278; return HandStrength; }
					if (n2 == 1) { HandStrength = -1279; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1280; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1281; return HandStrength; }
					if (n2 == 1) { HandStrength = -1282; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1283; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1284; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nJ == 1) {
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1285; return HandStrength; }
					if (n7 == 1) { HandStrength = -1286; return HandStrength; }
					if (n6 == 1) { HandStrength = -1287; return HandStrength; }
					if (n5 == 1) { HandStrength = -1288; return HandStrength; }
					if (n4 == 1) { HandStrength = -1289; return HandStrength; }
					if (n3 == 1) { HandStrength = -1290; return HandStrength; }
					if (n2 == 1) { HandStrength = -1291; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1292; return HandStrength; }
					if (n6 == 1) { HandStrength = -1293; return HandStrength; }
					if (n5 == 1) { HandStrength = -1294; return HandStrength; }
					if (n4 == 1) { HandStrength = -1295; return HandStrength; }
					if (n3 == 1) { HandStrength = -1296; return HandStrength; }
					if (n2 == 1) { HandStrength = -1297; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1298; return HandStrength; }
					if (n5 == 1) { HandStrength = -1299; return HandStrength; }
					if (n4 == 1) { HandStrength = -1300; return HandStrength; }
					if (n3 == 1) { HandStrength = -1301; return HandStrength; }
					if (n2 == 1) { HandStrength = -1302; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1303; return HandStrength; }
					if (n4 == 1) { HandStrength = -1304; return HandStrength; }
					if (n3 == 1) { HandStrength = -1305; return HandStrength; }
					if (n2 == 1) { HandStrength = -1306; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1307; return HandStrength; }
					if (n3 == 1) { HandStrength = -1308; return HandStrength; }
					if (n2 == 1) { HandStrength = -1309; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1310; return HandStrength; }
					if (n2 == 1) { HandStrength = -1311; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1312; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1313; return HandStrength; }
					if (n6 == 1) { HandStrength = -1314; return HandStrength; }
					if (n5 == 1) { HandStrength = -1315; return HandStrength; }
					if (n4 == 1) { HandStrength = -1316; return HandStrength; }
					if (n3 == 1) { HandStrength = -1317; return HandStrength; }
					if (n2 == 1) { HandStrength = -1318; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1319; return HandStrength; }
					if (n5 == 1) { HandStrength = -1320; return HandStrength; }
					if (n4 == 1) { HandStrength = -1321; return HandStrength; }
					if (n3 == 1) { HandStrength = -1322; return HandStrength; }
					if (n2 == 1) { HandStrength = -1323; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1324; return HandStrength; }
					if (n4 == 1) { HandStrength = -1325; return HandStrength; }
					if (n3 == 1) { HandStrength = -1326; return HandStrength; }
					if (n2 == 1) { HandStrength = -1327; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1328; return HandStrength; }
					if (n3 == 1) { HandStrength = -1329; return HandStrength; }
					if (n2 == 1) { HandStrength = -1330; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1331; return HandStrength; }
					if (n2 == 1) { HandStrength = -1332; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1333; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1334; return HandStrength; }
					if (n5 == 1) { HandStrength = -1335; return HandStrength; }
					if (n4 == 1) { HandStrength = -1336; return HandStrength; }
					if (n3 == 1) { HandStrength = -1337; return HandStrength; }
					if (n2 == 1) { HandStrength = -1338; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1339; return HandStrength; }
					if (n4 == 1) { HandStrength = -1340; return HandStrength; }
					if (n3 == 1) { HandStrength = -1341; return HandStrength; }
					if (n2 == 1) { HandStrength = -1342; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1343; return HandStrength; }
					if (n3 == 1) { HandStrength = -1344; return HandStrength; }
					if (n2 == 1) { HandStrength = -1345; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1346; return HandStrength; }
					if (n2 == 1) { HandStrength = -1347; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1348; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1349; return HandStrength; }
					if (n4 == 1) { HandStrength = -1350; return HandStrength; }
					if (n3 == 1) { HandStrength = -1351; return HandStrength; }
					if (n2 == 1) { HandStrength = -1352; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1353; return HandStrength; }
					if (n3 == 1) { HandStrength = -1354; return HandStrength; }
					if (n2 == 1) { HandStrength = -1355; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1356; return HandStrength; }
					if (n2 == 1) { HandStrength = -1357; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1358; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1359; return HandStrength; }
					if (n3 == 1) { HandStrength = -1360; return HandStrength; }
					if (n2 == 1) { HandStrength = -1361; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1362; return HandStrength; }
					if (n2 == 1) { HandStrength = -1363; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1364; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1365; return HandStrength; }
					if (n2 == 1) { HandStrength = -1366; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1367; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1368; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nT == 1) {
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1369; return HandStrength; }
					if (n6 == 1) { HandStrength = -1370; return HandStrength; }
					if (n5 == 1) { HandStrength = -1371; return HandStrength; }
					if (n4 == 1) { HandStrength = -1372; return HandStrength; }
					if (n3 == 1) { HandStrength = -1373; return HandStrength; }
					if (n2 == 1) { HandStrength = -1374; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1375; return HandStrength; }
					if (n5 == 1) { HandStrength = -1376; return HandStrength; }
					if (n4 == 1) { HandStrength = -1377; return HandStrength; }
					if (n3 == 1) { HandStrength = -1378; return HandStrength; }
					if (n2 == 1) { HandStrength = -1379; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1380; return HandStrength; }
					if (n4 == 1) { HandStrength = -1381; return HandStrength; }
					if (n3 == 1) { HandStrength = -1382; return HandStrength; }
					if (n2 == 1) { HandStrength = -1383; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1384; return HandStrength; }
					if (n3 == 1) { HandStrength = -1385; return HandStrength; }
					if (n2 == 1) { HandStrength = -1386; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1387; return HandStrength; }
					if (n2 == 1) { HandStrength = -1388; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1389; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1390; return HandStrength; }
					if (n5 == 1) { HandStrength = -1391; return HandStrength; }
					if (n4 == 1) { HandStrength = -1392; return HandStrength; }
					if (n3 == 1) { HandStrength = -1393; return HandStrength; }
					if (n2 == 1) { HandStrength = -1394; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1395; return HandStrength; }
					if (n4 == 1) { HandStrength = -1396; return HandStrength; }
					if (n3 == 1) { HandStrength = -1397; return HandStrength; }
					if (n2 == 1) { HandStrength = -1398; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1399; return HandStrength; }
					if (n3 == 1) { HandStrength = -1400; return HandStrength; }
					if (n2 == 1) { HandStrength = -1401; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1402; return HandStrength; }
					if (n2 == 1) { HandStrength = -1403; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1404; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1405; return HandStrength; }
					if (n4 == 1) { HandStrength = -1406; return HandStrength; }
					if (n3 == 1) { HandStrength = -1407; return HandStrength; }
					if (n2 == 1) { HandStrength = -1408; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1409; return HandStrength; }
					if (n3 == 1) { HandStrength = -1410; return HandStrength; }
					if (n2 == 1) { HandStrength = -1411; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1412; return HandStrength; }
					if (n2 == 1) { HandStrength = -1413; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1414; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1415; return HandStrength; }
					if (n3 == 1) { HandStrength = -1416; return HandStrength; }
					if (n2 == 1) { HandStrength = -1417; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1418; return HandStrength; }
					if (n2 == 1) { HandStrength = -1419; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1420; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1421; return HandStrength; }
					if (n2 == 1) { HandStrength = -1422; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1423; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1424; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 1) {
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1425; return HandStrength; }
					if (n5 == 1) { HandStrength = -1426; return HandStrength; }
					if (n4 == 1) { HandStrength = -1427; return HandStrength; }
					if (n3 == 1) { HandStrength = -1428; return HandStrength; }
					if (n2 == 1) { HandStrength = -1429; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1430; return HandStrength; }
					if (n4 == 1) { HandStrength = -1431; return HandStrength; }
					if (n3 == 1) { HandStrength = -1432; return HandStrength; }
					if (n2 == 1) { HandStrength = -1433; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1434; return HandStrength; }
					if (n3 == 1) { HandStrength = -1435; return HandStrength; }
					if (n2 == 1) { HandStrength = -1436; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1437; return HandStrength; }
					if (n2 == 1) { HandStrength = -1438; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1439; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1440; return HandStrength; }
					if (n4 == 1) { HandStrength = -1441; return HandStrength; }
					if (n3 == 1) { HandStrength = -1442; return HandStrength; }
					if (n2 == 1) { HandStrength = -1443; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1444; return HandStrength; }
					if (n3 == 1) { HandStrength = -1445; return HandStrength; }
					if (n2 == 1) { HandStrength = -1446; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1447; return HandStrength; }
					if (n2 == 1) { HandStrength = -1448; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1449; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1450; return HandStrength; }
					if (n3 == 1) { HandStrength = -1451; return HandStrength; }
					if (n2 == 1) { HandStrength = -1452; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1453; return HandStrength; }
					if (n2 == 1) { HandStrength = -1454; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1455; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1456; return HandStrength; }
					if (n2 == 1) { HandStrength = -1457; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1458; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1459; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1460; return HandStrength; }
					if (n4 == 1) { HandStrength = -1461; return HandStrength; }
					if (n3 == 1) { HandStrength = -1462; return HandStrength; }
					if (n2 == 1) { HandStrength = -1463; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1464; return HandStrength; }
					if (n3 == 1) { HandStrength = -1465; return HandStrength; }
					if (n2 == 1) { HandStrength = -1466; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1467; return HandStrength; }
					if (n2 == 1) { HandStrength = -1468; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1469; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1470; return HandStrength; }
					if (n3 == 1) { HandStrength = -1471; return HandStrength; }
					if (n2 == 1) { HandStrength = -1472; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1473; return HandStrength; }
					if (n2 == 1) { HandStrength = -1474; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1475; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1476; return HandStrength; }
					if (n2 == 1) { HandStrength = -1477; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1478; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1479; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1480; return HandStrength; }
					if (n3 == 1) { HandStrength = -1481; return HandStrength; }
					if (n2 == 1) { HandStrength = -1482; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1483; return HandStrength; }
					if (n2 == 1) { HandStrength = -1484; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1485; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1486; return HandStrength; }
					if (n2 == 1) { HandStrength = -1487; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1488; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1489; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1490; return HandStrength; }
					if (n2 == 1) { HandStrength = -1491; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1492; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1493; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1494; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (nK == 1) {
		if (nQ == 1) {
			if (nJ == 1) {
				if (nT == 1) {
					if (n9 == 1) { HandStrength = -1495; return HandStrength; }
					if (n8 == 1) { HandStrength = -1496; return HandStrength; }
					if (n7 == 1) { HandStrength = -1497; return HandStrength; }
					if (n6 == 1) { HandStrength = -1498; return HandStrength; }
					if (n5 == 1) { HandStrength = -1499; return HandStrength; }
					if (n4 == 1) { HandStrength = -1500; return HandStrength; }
					if (n3 == 1) { HandStrength = -1501; return HandStrength; }
					if (n2 == 1) { HandStrength = -1502; return HandStrength; }
				};
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1503; return HandStrength; }
					if (n7 == 1) { HandStrength = -1504; return HandStrength; }
					if (n6 == 1) { HandStrength = -1505; return HandStrength; }
					if (n5 == 1) { HandStrength = -1506; return HandStrength; }
					if (n4 == 1) { HandStrength = -1507; return HandStrength; }
					if (n3 == 1) { HandStrength = -1508; return HandStrength; }
					if (n2 == 1) { HandStrength = -1509; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1510; return HandStrength; }
					if (n6 == 1) { HandStrength = -1511; return HandStrength; }
					if (n5 == 1) { HandStrength = -1512; return HandStrength; }
					if (n4 == 1) { HandStrength = -1513; return HandStrength; }
					if (n3 == 1) { HandStrength = -1514; return HandStrength; }
					if (n2 == 1) { HandStrength = -1515; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1516; return HandStrength; }
					if (n5 == 1) { HandStrength = -1517; return HandStrength; }
					if (n4 == 1) { HandStrength = -1518; return HandStrength; }
					if (n3 == 1) { HandStrength = -1519; return HandStrength; }
					if (n2 == 1) { HandStrength = -1520; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1521; return HandStrength; }
					if (n4 == 1) { HandStrength = -1522; return HandStrength; }
					if (n3 == 1) { HandStrength = -1523; return HandStrength; }
					if (n2 == 1) { HandStrength = -1524; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1525; return HandStrength; }
					if (n3 == 1) { HandStrength = -1526; return HandStrength; }
					if (n2 == 1) { HandStrength = -1527; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1528; return HandStrength; }
					if (n2 == 1) { HandStrength = -1529; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1530; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1531; return HandStrength; }
					if (n7 == 1) { HandStrength = -1532; return HandStrength; }
					if (n6 == 1) { HandStrength = -1533; return HandStrength; }
					if (n5 == 1) { HandStrength = -1534; return HandStrength; }
					if (n4 == 1) { HandStrength = -1535; return HandStrength; }
					if (n3 == 1) { HandStrength = -1536; return HandStrength; }
					if (n2 == 1) { HandStrength = -1537; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1538; return HandStrength; }
					if (n6 == 1) { HandStrength = -1539; return HandStrength; }
					if (n5 == 1) { HandStrength = -1540; return HandStrength; }
					if (n4 == 1) { HandStrength = -1541; return HandStrength; }
					if (n3 == 1) { HandStrength = -1542; return HandStrength; }
					if (n2 == 1) { HandStrength = -1543; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1544; return HandStrength; }
					if (n5 == 1) { HandStrength = -1545; return HandStrength; }
					if (n4 == 1) { HandStrength = -1546; return HandStrength; }
					if (n3 == 1) { HandStrength = -1547; return HandStrength; }
					if (n2 == 1) { HandStrength = -1548; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1549; return HandStrength; }
					if (n4 == 1) { HandStrength = -1550; return HandStrength; }
					if (n3 == 1) { HandStrength = -1551; return HandStrength; }
					if (n2 == 1) { HandStrength = -1552; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1553; return HandStrength; }
					if (n3 == 1) { HandStrength = -1554; return HandStrength; }
					if (n2 == 1) { HandStrength = -1555; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1556; return HandStrength; }
					if (n2 == 1) { HandStrength = -1557; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1558; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1559; return HandStrength; }
					if (n6 == 1) { HandStrength = -1560; return HandStrength; }
					if (n5 == 1) { HandStrength = -1561; return HandStrength; }
					if (n4 == 1) { HandStrength = -1562; return HandStrength; }
					if (n3 == 1) { HandStrength = -1563; return HandStrength; }
					if (n2 == 1) { HandStrength = -1564; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1565; return HandStrength; }
					if (n5 == 1) { HandStrength = -1566; return HandStrength; }
					if (n4 == 1) { HandStrength = -1567; return HandStrength; }
					if (n3 == 1) { HandStrength = -1568; return HandStrength; }
					if (n2 == 1) { HandStrength = -1569; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1570; return HandStrength; }
					if (n4 == 1) { HandStrength = -1571; return HandStrength; }
					if (n3 == 1) { HandStrength = -1572; return HandStrength; }
					if (n2 == 1) { HandStrength = -1573; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1574; return HandStrength; }
					if (n3 == 1) { HandStrength = -1575; return HandStrength; }
					if (n2 == 1) { HandStrength = -1576; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1577; return HandStrength; }
					if (n2 == 1) { HandStrength = -1578; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1579; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1580; return HandStrength; }
					if (n5 == 1) { HandStrength = -1581; return HandStrength; }
					if (n4 == 1) { HandStrength = -1582; return HandStrength; }
					if (n3 == 1) { HandStrength = -1583; return HandStrength; }
					if (n2 == 1) { HandStrength = -1584; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1585; return HandStrength; }
					if (n4 == 1) { HandStrength = -1586; return HandStrength; }
					if (n3 == 1) { HandStrength = -1587; return HandStrength; }
					if (n2 == 1) { HandStrength = -1588; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1589; return HandStrength; }
					if (n3 == 1) { HandStrength = -1590; return HandStrength; }
					if (n2 == 1) { HandStrength = -1591; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1592; return HandStrength; }
					if (n2 == 1) { HandStrength = -1593; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1594; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1595; return HandStrength; }
					if (n4 == 1) { HandStrength = -1596; return HandStrength; }
					if (n3 == 1) { HandStrength = -1597; return HandStrength; }
					if (n2 == 1) { HandStrength = -1598; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1599; return HandStrength; }
					if (n3 == 1) { HandStrength = -1600; return HandStrength; }
					if (n2 == 1) { HandStrength = -1601; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1602; return HandStrength; }
					if (n2 == 1) { HandStrength = -1603; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1604; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1605; return HandStrength; }
					if (n3 == 1) { HandStrength = -1606; return HandStrength; }
					if (n2 == 1) { HandStrength = -1607; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1608; return HandStrength; }
					if (n2 == 1) { HandStrength = -1609; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1610; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1611; return HandStrength; }
					if (n2 == 1) { HandStrength = -1612; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1613; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1614; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nJ == 1) {
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1615; return HandStrength; }
					if (n7 == 1) { HandStrength = -1616; return HandStrength; }
					if (n6 == 1) { HandStrength = -1617; return HandStrength; }
					if (n5 == 1) { HandStrength = -1618; return HandStrength; }
					if (n4 == 1) { HandStrength = -1619; return HandStrength; }
					if (n3 == 1) { HandStrength = -1620; return HandStrength; }
					if (n2 == 1) { HandStrength = -1621; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1622; return HandStrength; }
					if (n6 == 1) { HandStrength = -1623; return HandStrength; }
					if (n5 == 1) { HandStrength = -1624; return HandStrength; }
					if (n4 == 1) { HandStrength = -1625; return HandStrength; }
					if (n3 == 1) { HandStrength = -1626; return HandStrength; }
					if (n2 == 1) { HandStrength = -1627; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1628; return HandStrength; }
					if (n5 == 1) { HandStrength = -1629; return HandStrength; }
					if (n4 == 1) { HandStrength = -1630; return HandStrength; }
					if (n3 == 1) { HandStrength = -1631; return HandStrength; }
					if (n2 == 1) { HandStrength = -1632; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1633; return HandStrength; }
					if (n4 == 1) { HandStrength = -1634; return HandStrength; }
					if (n3 == 1) { HandStrength = -1635; return HandStrength; }
					if (n2 == 1) { HandStrength = -1636; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1637; return HandStrength; }
					if (n3 == 1) { HandStrength = -1638; return HandStrength; }
					if (n2 == 1) { HandStrength = -1639; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1640; return HandStrength; }
					if (n2 == 1) { HandStrength = -1641; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1642; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1643; return HandStrength; }
					if (n6 == 1) { HandStrength = -1644; return HandStrength; }
					if (n5 == 1) { HandStrength = -1645; return HandStrength; }
					if (n4 == 1) { HandStrength = -1646; return HandStrength; }
					if (n3 == 1) { HandStrength = -1647; return HandStrength; }
					if (n2 == 1) { HandStrength = -1648; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1649; return HandStrength; }
					if (n5 == 1) { HandStrength = -1650; return HandStrength; }
					if (n4 == 1) { HandStrength = -1651; return HandStrength; }
					if (n3 == 1) { HandStrength = -1652; return HandStrength; }
					if (n2 == 1) { HandStrength = -1653; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1654; return HandStrength; }
					if (n4 == 1) { HandStrength = -1655; return HandStrength; }
					if (n3 == 1) { HandStrength = -1656; return HandStrength; }
					if (n2 == 1) { HandStrength = -1657; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1658; return HandStrength; }
					if (n3 == 1) { HandStrength = -1659; return HandStrength; }
					if (n2 == 1) { HandStrength = -1660; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1661; return HandStrength; }
					if (n2 == 1) { HandStrength = -1662; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1663; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1664; return HandStrength; }
					if (n5 == 1) { HandStrength = -1665; return HandStrength; }
					if (n4 == 1) { HandStrength = -1666; return HandStrength; }
					if (n3 == 1) { HandStrength = -1667; return HandStrength; }
					if (n2 == 1) { HandStrength = -1668; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1669; return HandStrength; }
					if (n4 == 1) { HandStrength = -1670; return HandStrength; }
					if (n3 == 1) { HandStrength = -1671; return HandStrength; }
					if (n2 == 1) { HandStrength = -1672; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1673; return HandStrength; }
					if (n3 == 1) { HandStrength = -1674; return HandStrength; }
					if (n2 == 1) { HandStrength = -1675; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1676; return HandStrength; }
					if (n2 == 1) { HandStrength = -1677; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1678; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1679; return HandStrength; }
					if (n4 == 1) { HandStrength = -1680; return HandStrength; }
					if (n3 == 1) { HandStrength = -1681; return HandStrength; }
					if (n2 == 1) { HandStrength = -1682; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1683; return HandStrength; }
					if (n3 == 1) { HandStrength = -1684; return HandStrength; }
					if (n2 == 1) { HandStrength = -1685; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1686; return HandStrength; }
					if (n2 == 1) { HandStrength = -1687; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1688; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1689; return HandStrength; }
					if (n3 == 1) { HandStrength = -1690; return HandStrength; }
					if (n2 == 1) { HandStrength = -1691; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1692; return HandStrength; }
					if (n2 == 1) { HandStrength = -1693; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1694; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1695; return HandStrength; }
					if (n2 == 1) { HandStrength = -1696; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1697; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1698; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nT == 1) {
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1699; return HandStrength; }
					if (n6 == 1) { HandStrength = -1700; return HandStrength; }
					if (n5 == 1) { HandStrength = -1701; return HandStrength; }
					if (n4 == 1) { HandStrength = -1702; return HandStrength; }
					if (n3 == 1) { HandStrength = -1703; return HandStrength; }
					if (n2 == 1) { HandStrength = -1704; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1705; return HandStrength; }
					if (n5 == 1) { HandStrength = -1706; return HandStrength; }
					if (n4 == 1) { HandStrength = -1707; return HandStrength; }
					if (n3 == 1) { HandStrength = -1708; return HandStrength; }
					if (n2 == 1) { HandStrength = -1709; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1710; return HandStrength; }
					if (n4 == 1) { HandStrength = -1711; return HandStrength; }
					if (n3 == 1) { HandStrength = -1712; return HandStrength; }
					if (n2 == 1) { HandStrength = -1713; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1714; return HandStrength; }
					if (n3 == 1) { HandStrength = -1715; return HandStrength; }
					if (n2 == 1) { HandStrength = -1716; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1717; return HandStrength; }
					if (n2 == 1) { HandStrength = -1718; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1719; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1720; return HandStrength; }
					if (n5 == 1) { HandStrength = -1721; return HandStrength; }
					if (n4 == 1) { HandStrength = -1722; return HandStrength; }
					if (n3 == 1) { HandStrength = -1723; return HandStrength; }
					if (n2 == 1) { HandStrength = -1724; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1725; return HandStrength; }
					if (n4 == 1) { HandStrength = -1726; return HandStrength; }
					if (n3 == 1) { HandStrength = -1727; return HandStrength; }
					if (n2 == 1) { HandStrength = -1728; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1729; return HandStrength; }
					if (n3 == 1) { HandStrength = -1730; return HandStrength; }
					if (n2 == 1) { HandStrength = -1731; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1732; return HandStrength; }
					if (n2 == 1) { HandStrength = -1733; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1734; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1735; return HandStrength; }
					if (n4 == 1) { HandStrength = -1736; return HandStrength; }
					if (n3 == 1) { HandStrength = -1737; return HandStrength; }
					if (n2 == 1) { HandStrength = -1738; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1739; return HandStrength; }
					if (n3 == 1) { HandStrength = -1740; return HandStrength; }
					if (n2 == 1) { HandStrength = -1741; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1742; return HandStrength; }
					if (n2 == 1) { HandStrength = -1743; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1744; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1745; return HandStrength; }
					if (n3 == 1) { HandStrength = -1746; return HandStrength; }
					if (n2 == 1) { HandStrength = -1747; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1748; return HandStrength; }
					if (n2 == 1) { HandStrength = -1749; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1750; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1751; return HandStrength; }
					if (n2 == 1) { HandStrength = -1752; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1753; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1754; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 1) {
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1755; return HandStrength; }
					if (n5 == 1) { HandStrength = -1756; return HandStrength; }
					if (n4 == 1) { HandStrength = -1757; return HandStrength; }
					if (n3 == 1) { HandStrength = -1758; return HandStrength; }
					if (n2 == 1) { HandStrength = -1759; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1760; return HandStrength; }
					if (n4 == 1) { HandStrength = -1761; return HandStrength; }
					if (n3 == 1) { HandStrength = -1762; return HandStrength; }
					if (n2 == 1) { HandStrength = -1763; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1764; return HandStrength; }
					if (n3 == 1) { HandStrength = -1765; return HandStrength; }
					if (n2 == 1) { HandStrength = -1766; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1767; return HandStrength; }
					if (n2 == 1) { HandStrength = -1768; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1769; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1770; return HandStrength; }
					if (n4 == 1) { HandStrength = -1771; return HandStrength; }
					if (n3 == 1) { HandStrength = -1772; return HandStrength; }
					if (n2 == 1) { HandStrength = -1773; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1774; return HandStrength; }
					if (n3 == 1) { HandStrength = -1775; return HandStrength; }
					if (n2 == 1) { HandStrength = -1776; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1777; return HandStrength; }
					if (n2 == 1) { HandStrength = -1778; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1779; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1780; return HandStrength; }
					if (n3 == 1) { HandStrength = -1781; return HandStrength; }
					if (n2 == 1) { HandStrength = -1782; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1783; return HandStrength; }
					if (n2 == 1) { HandStrength = -1784; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1785; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1786; return HandStrength; }
					if (n2 == 1) { HandStrength = -1787; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1788; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1789; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1790; return HandStrength; }
					if (n4 == 1) { HandStrength = -1791; return HandStrength; }
					if (n3 == 1) { HandStrength = -1792; return HandStrength; }
					if (n2 == 1) { HandStrength = -1793; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1794; return HandStrength; }
					if (n3 == 1) { HandStrength = -1795; return HandStrength; }
					if (n2 == 1) { HandStrength = -1796; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1797; return HandStrength; }
					if (n2 == 1) { HandStrength = -1798; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1799; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1800; return HandStrength; }
					if (n3 == 1) { HandStrength = -1801; return HandStrength; }
					if (n2 == 1) { HandStrength = -1802; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1803; return HandStrength; }
					if (n2 == 1) { HandStrength = -1804; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1805; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1806; return HandStrength; }
					if (n2 == 1) { HandStrength = -1807; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1808; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1809; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1810; return HandStrength; }
					if (n3 == 1) { HandStrength = -1811; return HandStrength; }
					if (n2 == 1) { HandStrength = -1812; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1813; return HandStrength; }
					if (n2 == 1) { HandStrength = -1814; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1815; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1816; return HandStrength; }
					if (n2 == 1) { HandStrength = -1817; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1818; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1819; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1820; return HandStrength; }
					if (n2 == 1) { HandStrength = -1821; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1822; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1823; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1824; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (nQ == 1) {
		if (nJ == 1) {
			if (nT == 1) {
				if (n9 == 1) {
					if (n8 == 1) { HandStrength = -1825; return HandStrength; }
					if (n7 == 1) { HandStrength = -1826; return HandStrength; }
					if (n6 == 1) { HandStrength = -1827; return HandStrength; }
					if (n5 == 1) { HandStrength = -1828; return HandStrength; }
					if (n4 == 1) { HandStrength = -1829; return HandStrength; }
					if (n3 == 1) { HandStrength = -1830; return HandStrength; }
					if (n2 == 1) { HandStrength = -1831; return HandStrength; }
				};
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1832; return HandStrength; }
					if (n6 == 1) { HandStrength = -1833; return HandStrength; }
					if (n5 == 1) { HandStrength = -1834; return HandStrength; }
					if (n4 == 1) { HandStrength = -1835; return HandStrength; }
					if (n3 == 1) { HandStrength = -1836; return HandStrength; }
					if (n2 == 1) { HandStrength = -1837; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1838; return HandStrength; }
					if (n5 == 1) { HandStrength = -1839; return HandStrength; }
					if (n4 == 1) { HandStrength = -1840; return HandStrength; }
					if (n3 == 1) { HandStrength = -1841; return HandStrength; }
					if (n2 == 1) { HandStrength = -1842; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1843; return HandStrength; }
					if (n4 == 1) { HandStrength = -1844; return HandStrength; }
					if (n3 == 1) { HandStrength = -1845; return HandStrength; }
					if (n2 == 1) { HandStrength = -1846; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1847; return HandStrength; }
					if (n3 == 1) { HandStrength = -1848; return HandStrength; }
					if (n2 == 1) { HandStrength = -1849; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1850; return HandStrength; }
					if (n2 == 1) { HandStrength = -1851; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1852; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1853; return HandStrength; }
					if (n6 == 1) { HandStrength = -1854; return HandStrength; }
					if (n5 == 1) { HandStrength = -1855; return HandStrength; }
					if (n4 == 1) { HandStrength = -1856; return HandStrength; }
					if (n3 == 1) { HandStrength = -1857; return HandStrength; }
					if (n2 == 1) { HandStrength = -1858; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1859; return HandStrength; }
					if (n5 == 1) { HandStrength = -1860; return HandStrength; }
					if (n4 == 1) { HandStrength = -1861; return HandStrength; }
					if (n3 == 1) { HandStrength = -1862; return HandStrength; }
					if (n2 == 1) { HandStrength = -1863; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1864; return HandStrength; }
					if (n4 == 1) { HandStrength = -1865; return HandStrength; }
					if (n3 == 1) { HandStrength = -1866; return HandStrength; }
					if (n2 == 1) { HandStrength = -1867; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1868; return HandStrength; }
					if (n3 == 1) { HandStrength = -1869; return HandStrength; }
					if (n2 == 1) { HandStrength = -1870; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1871; return HandStrength; }
					if (n2 == 1) { HandStrength = -1872; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1873; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1874; return HandStrength; }
					if (n5 == 1) { HandStrength = -1875; return HandStrength; }
					if (n4 == 1) { HandStrength = -1876; return HandStrength; }
					if (n3 == 1) { HandStrength = -1877; return HandStrength; }
					if (n2 == 1) { HandStrength = -1878; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1879; return HandStrength; }
					if (n4 == 1) { HandStrength = -1880; return HandStrength; }
					if (n3 == 1) { HandStrength = -1881; return HandStrength; }
					if (n2 == 1) { HandStrength = -1882; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1883; return HandStrength; }
					if (n3 == 1) { HandStrength = -1884; return HandStrength; }
					if (n2 == 1) { HandStrength = -1885; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1886; return HandStrength; }
					if (n2 == 1) { HandStrength = -1887; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1888; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1889; return HandStrength; }
					if (n4 == 1) { HandStrength = -1890; return HandStrength; }
					if (n3 == 1) { HandStrength = -1891; return HandStrength; }
					if (n2 == 1) { HandStrength = -1892; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1893; return HandStrength; }
					if (n3 == 1) { HandStrength = -1894; return HandStrength; }
					if (n2 == 1) { HandStrength = -1895; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1896; return HandStrength; }
					if (n2 == 1) { HandStrength = -1897; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1898; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1899; return HandStrength; }
					if (n3 == 1) { HandStrength = -1900; return HandStrength; }
					if (n2 == 1) { HandStrength = -1901; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1902; return HandStrength; }
					if (n2 == 1) { HandStrength = -1903; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1904; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1905; return HandStrength; }
					if (n2 == 1) { HandStrength = -1906; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1907; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1908; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (nT == 1) {
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -1909; return HandStrength; }
					if (n6 == 1) { HandStrength = -1910; return HandStrength; }
					if (n5 == 1) { HandStrength = -1911; return HandStrength; }
					if (n4 == 1) { HandStrength = -1912; return HandStrength; }
					if (n3 == 1) { HandStrength = -1913; return HandStrength; }
					if (n2 == 1) { HandStrength = -1914; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1915; return HandStrength; }
					if (n5 == 1) { HandStrength = -1916; return HandStrength; }
					if (n4 == 1) { HandStrength = -1917; return HandStrength; }
					if (n3 == 1) { HandStrength = -1918; return HandStrength; }
					if (n2 == 1) { HandStrength = -1919; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1920; return HandStrength; }
					if (n4 == 1) { HandStrength = -1921; return HandStrength; }
					if (n3 == 1) { HandStrength = -1922; return HandStrength; }
					if (n2 == 1) { HandStrength = -1923; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1924; return HandStrength; }
					if (n3 == 1) { HandStrength = -1925; return HandStrength; }
					if (n2 == 1) { HandStrength = -1926; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1927; return HandStrength; }
					if (n2 == 1) { HandStrength = -1928; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1929; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1930; return HandStrength; }
					if (n5 == 1) { HandStrength = -1931; return HandStrength; }
					if (n4 == 1) { HandStrength = -1932; return HandStrength; }
					if (n3 == 1) { HandStrength = -1933; return HandStrength; }
					if (n2 == 1) { HandStrength = -1934; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1935; return HandStrength; }
					if (n4 == 1) { HandStrength = -1936; return HandStrength; }
					if (n3 == 1) { HandStrength = -1937; return HandStrength; }
					if (n2 == 1) { HandStrength = -1938; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1939; return HandStrength; }
					if (n3 == 1) { HandStrength = -1940; return HandStrength; }
					if (n2 == 1) { HandStrength = -1941; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1942; return HandStrength; }
					if (n2 == 1) { HandStrength = -1943; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1944; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1945; return HandStrength; }
					if (n4 == 1) { HandStrength = -1946; return HandStrength; }
					if (n3 == 1) { HandStrength = -1947; return HandStrength; }
					if (n2 == 1) { HandStrength = -1948; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1949; return HandStrength; }
					if (n3 == 1) { HandStrength = -1950; return HandStrength; }
					if (n2 == 1) { HandStrength = -1951; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1952; return HandStrength; }
					if (n2 == 1) { HandStrength = -1953; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1954; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1955; return HandStrength; }
					if (n3 == 1) { HandStrength = -1956; return HandStrength; }
					if (n2 == 1) { HandStrength = -1957; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1958; return HandStrength; }
					if (n2 == 1) { HandStrength = -1959; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1960; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1961; return HandStrength; }
					if (n2 == 1) { HandStrength = -1962; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1963; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1964; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 1) {
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -1965; return HandStrength; }
					if (n5 == 1) { HandStrength = -1966; return HandStrength; }
					if (n4 == 1) { HandStrength = -1967; return HandStrength; }
					if (n3 == 1) { HandStrength = -1968; return HandStrength; }
					if (n2 == 1) { HandStrength = -1969; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1970; return HandStrength; }
					if (n4 == 1) { HandStrength = -1971; return HandStrength; }
					if (n3 == 1) { HandStrength = -1972; return HandStrength; }
					if (n2 == 1) { HandStrength = -1973; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1974; return HandStrength; }
					if (n3 == 1) { HandStrength = -1975; return HandStrength; }
					if (n2 == 1) { HandStrength = -1976; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1977; return HandStrength; }
					if (n2 == 1) { HandStrength = -1978; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1979; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -1980; return HandStrength; }
					if (n4 == 1) { HandStrength = -1981; return HandStrength; }
					if (n3 == 1) { HandStrength = -1982; return HandStrength; }
					if (n2 == 1) { HandStrength = -1983; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1984; return HandStrength; }
					if (n3 == 1) { HandStrength = -1985; return HandStrength; }
					if (n2 == 1) { HandStrength = -1986; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1987; return HandStrength; }
					if (n2 == 1) { HandStrength = -1988; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1989; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -1990; return HandStrength; }
					if (n3 == 1) { HandStrength = -1991; return HandStrength; }
					if (n2 == 1) { HandStrength = -1992; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1993; return HandStrength; }
					if (n2 == 1) { HandStrength = -1994; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1995; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -1996; return HandStrength; }
					if (n2 == 1) { HandStrength = -1997; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1998; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -1999; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2000; return HandStrength; }
					if (n4 == 1) { HandStrength = -2001; return HandStrength; }
					if (n3 == 1) { HandStrength = -2002; return HandStrength; }
					if (n2 == 1) { HandStrength = -2003; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2004; return HandStrength; }
					if (n3 == 1) { HandStrength = -2005; return HandStrength; }
					if (n2 == 1) { HandStrength = -2006; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2007; return HandStrength; }
					if (n2 == 1) { HandStrength = -2008; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2009; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2010; return HandStrength; }
					if (n3 == 1) { HandStrength = -2011; return HandStrength; }
					if (n2 == 1) { HandStrength = -2012; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2013; return HandStrength; }
					if (n2 == 1) { HandStrength = -2014; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2015; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2016; return HandStrength; }
					if (n2 == 1) { HandStrength = -2017; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2018; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2019; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2020; return HandStrength; }
					if (n3 == 1) { HandStrength = -2021; return HandStrength; }
					if (n2 == 1) { HandStrength = -2022; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2023; return HandStrength; }
					if (n2 == 1) { HandStrength = -2024; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2025; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2026; return HandStrength; }
					if (n2 == 1) { HandStrength = -2027; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2028; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2029; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2030; return HandStrength; }
					if (n2 == 1) { HandStrength = -2031; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2032; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2033; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2034; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (nJ == 1) {
		if (nT == 1) {
			if (n9 == 1) {
				if (n8 == 1) {
					if (n7 == 1) { HandStrength = -2035; return HandStrength; }
					if (n6 == 1) { HandStrength = -2036; return HandStrength; }
					if (n5 == 1) { HandStrength = -2037; return HandStrength; }
					if (n4 == 1) { HandStrength = -2038; return HandStrength; }
					if (n3 == 1) { HandStrength = -2039; return HandStrength; }
					if (n2 == 1) { HandStrength = -2040; return HandStrength; }
				};
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -2041; return HandStrength; }
					if (n5 == 1) { HandStrength = -2042; return HandStrength; }
					if (n4 == 1) { HandStrength = -2043; return HandStrength; }
					if (n3 == 1) { HandStrength = -2044; return HandStrength; }
					if (n2 == 1) { HandStrength = -2045; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2046; return HandStrength; }
					if (n4 == 1) { HandStrength = -2047; return HandStrength; }
					if (n3 == 1) { HandStrength = -2048; return HandStrength; }
					if (n2 == 1) { HandStrength = -2049; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2050; return HandStrength; }
					if (n3 == 1) { HandStrength = -2051; return HandStrength; }
					if (n2 == 1) { HandStrength = -2052; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2053; return HandStrength; }
					if (n2 == 1) { HandStrength = -2054; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2055; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -2056; return HandStrength; }
					if (n5 == 1) { HandStrength = -2057; return HandStrength; }
					if (n4 == 1) { HandStrength = -2058; return HandStrength; }
					if (n3 == 1) { HandStrength = -2059; return HandStrength; }
					if (n2 == 1) { HandStrength = -2060; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2061; return HandStrength; }
					if (n4 == 1) { HandStrength = -2062; return HandStrength; }
					if (n3 == 1) { HandStrength = -2063; return HandStrength; }
					if (n2 == 1) { HandStrength = -2064; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2065; return HandStrength; }
					if (n3 == 1) { HandStrength = -2066; return HandStrength; }
					if (n2 == 1) { HandStrength = -2067; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2068; return HandStrength; }
					if (n2 == 1) { HandStrength = -2069; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2070; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2071; return HandStrength; }
					if (n4 == 1) { HandStrength = -2072; return HandStrength; }
					if (n3 == 1) { HandStrength = -2073; return HandStrength; }
					if (n2 == 1) { HandStrength = -2074; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2075; return HandStrength; }
					if (n3 == 1) { HandStrength = -2076; return HandStrength; }
					if (n2 == 1) { HandStrength = -2077; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2078; return HandStrength; }
					if (n2 == 1) { HandStrength = -2079; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2080; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2081; return HandStrength; }
					if (n3 == 1) { HandStrength = -2082; return HandStrength; }
					if (n2 == 1) { HandStrength = -2083; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2084; return HandStrength; }
					if (n2 == 1) { HandStrength = -2085; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2086; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2087; return HandStrength; }
					if (n2 == 1) { HandStrength = -2088; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2089; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2090; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n9 == 1) {
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -2091; return HandStrength; }
					if (n5 == 1) { HandStrength = -2092; return HandStrength; }
					if (n4 == 1) { HandStrength = -2093; return HandStrength; }
					if (n3 == 1) { HandStrength = -2094; return HandStrength; }
					if (n2 == 1) { HandStrength = -2095; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2096; return HandStrength; }
					if (n4 == 1) { HandStrength = -2097; return HandStrength; }
					if (n3 == 1) { HandStrength = -2098; return HandStrength; }
					if (n2 == 1) { HandStrength = -2099; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2100; return HandStrength; }
					if (n3 == 1) { HandStrength = -2101; return HandStrength; }
					if (n2 == 1) { HandStrength = -2102; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2103; return HandStrength; }
					if (n2 == 1) { HandStrength = -2104; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2105; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2106; return HandStrength; }
					if (n4 == 1) { HandStrength = -2107; return HandStrength; }
					if (n3 == 1) { HandStrength = -2108; return HandStrength; }
					if (n2 == 1) { HandStrength = -2109; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2110; return HandStrength; }
					if (n3 == 1) { HandStrength = -2111; return HandStrength; }
					if (n2 == 1) { HandStrength = -2112; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2113; return HandStrength; }
					if (n2 == 1) { HandStrength = -2114; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2115; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2116; return HandStrength; }
					if (n3 == 1) { HandStrength = -2117; return HandStrength; }
					if (n2 == 1) { HandStrength = -2118; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2119; return HandStrength; }
					if (n2 == 1) { HandStrength = -2120; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2121; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2122; return HandStrength; }
					if (n2 == 1) { HandStrength = -2123; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2124; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2125; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2126; return HandStrength; }
					if (n4 == 1) { HandStrength = -2127; return HandStrength; }
					if (n3 == 1) { HandStrength = -2128; return HandStrength; }
					if (n2 == 1) { HandStrength = -2129; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2130; return HandStrength; }
					if (n3 == 1) { HandStrength = -2131; return HandStrength; }
					if (n2 == 1) { HandStrength = -2132; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2133; return HandStrength; }
					if (n2 == 1) { HandStrength = -2134; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2135; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2136; return HandStrength; }
					if (n3 == 1) { HandStrength = -2137; return HandStrength; }
					if (n2 == 1) { HandStrength = -2138; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2139; return HandStrength; }
					if (n2 == 1) { HandStrength = -2140; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2141; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2142; return HandStrength; }
					if (n2 == 1) { HandStrength = -2143; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2144; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2145; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2146; return HandStrength; }
					if (n3 == 1) { HandStrength = -2147; return HandStrength; }
					if (n2 == 1) { HandStrength = -2148; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2149; return HandStrength; }
					if (n2 == 1) { HandStrength = -2150; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2151; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2152; return HandStrength; }
					if (n2 == 1) { HandStrength = -2153; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2154; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2155; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2156; return HandStrength; }
					if (n2 == 1) { HandStrength = -2157; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2158; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2159; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2160; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (nT == 1) {
		if (n9 == 1) {
			if (n8 == 1) {
				if (n7 == 1) {
					if (n6 == 1) { HandStrength = -2161; return HandStrength; }
					if (n5 == 1) { HandStrength = -2162; return HandStrength; }
					if (n4 == 1) { HandStrength = -2163; return HandStrength; }
					if (n3 == 1) { HandStrength = -2164; return HandStrength; }
					if (n2 == 1) { HandStrength = -2165; return HandStrength; }
				};
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2166; return HandStrength; }
					if (n4 == 1) { HandStrength = -2167; return HandStrength; }
					if (n3 == 1) { HandStrength = -2168; return HandStrength; }
					if (n2 == 1) { HandStrength = -2169; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2170; return HandStrength; }
					if (n3 == 1) { HandStrength = -2171; return HandStrength; }
					if (n2 == 1) { HandStrength = -2172; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2173; return HandStrength; }
					if (n2 == 1) { HandStrength = -2174; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2175; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2176; return HandStrength; }
					if (n4 == 1) { HandStrength = -2177; return HandStrength; }
					if (n3 == 1) { HandStrength = -2178; return HandStrength; }
					if (n2 == 1) { HandStrength = -2179; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2180; return HandStrength; }
					if (n3 == 1) { HandStrength = -2181; return HandStrength; }
					if (n2 == 1) { HandStrength = -2182; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2183; return HandStrength; }
					if (n2 == 1) { HandStrength = -2184; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2185; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2186; return HandStrength; }
					if (n3 == 1) { HandStrength = -2187; return HandStrength; }
					if (n2 == 1) { HandStrength = -2188; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2189; return HandStrength; }
					if (n2 == 1) { HandStrength = -2190; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2191; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2192; return HandStrength; }
					if (n2 == 1) { HandStrength = -2193; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2194; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2195; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2196; return HandStrength; }
					if (n4 == 1) { HandStrength = -2197; return HandStrength; }
					if (n3 == 1) { HandStrength = -2198; return HandStrength; }
					if (n2 == 1) { HandStrength = -2199; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2200; return HandStrength; }
					if (n3 == 1) { HandStrength = -2201; return HandStrength; }
					if (n2 == 1) { HandStrength = -2202; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2203; return HandStrength; }
					if (n2 == 1) { HandStrength = -2204; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2205; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2206; return HandStrength; }
					if (n3 == 1) { HandStrength = -2207; return HandStrength; }
					if (n2 == 1) { HandStrength = -2208; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2209; return HandStrength; }
					if (n2 == 1) { HandStrength = -2210; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2211; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2212; return HandStrength; }
					if (n2 == 1) { HandStrength = -2213; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2214; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2215; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2216; return HandStrength; }
					if (n3 == 1) { HandStrength = -2217; return HandStrength; }
					if (n2 == 1) { HandStrength = -2218; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2219; return HandStrength; }
					if (n2 == 1) { HandStrength = -2220; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2221; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2222; return HandStrength; }
					if (n2 == 1) { HandStrength = -2223; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2224; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2225; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2226; return HandStrength; }
					if (n2 == 1) { HandStrength = -2227; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2228; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2229; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2230; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (n9 == 1) {
		if (n8 == 1) {
			if (n7 == 1) {
				if (n6 == 1) {
					if (n5 == 1) { HandStrength = -2231; return HandStrength; }
					if (n4 == 1) { HandStrength = -2232; return HandStrength; }
					if (n3 == 1) { HandStrength = -2233; return HandStrength; }
					if (n2 == 1) { HandStrength = -2234; return HandStrength; }
				};
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2235; return HandStrength; }
					if (n3 == 1) { HandStrength = -2236; return HandStrength; }
					if (n2 == 1) { HandStrength = -2237; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2238; return HandStrength; }
					if (n2 == 1) { HandStrength = -2239; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2240; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2241; return HandStrength; }
					if (n3 == 1) { HandStrength = -2242; return HandStrength; }
					if (n2 == 1) { HandStrength = -2243; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2244; return HandStrength; }
					if (n2 == 1) { HandStrength = -2245; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2246; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2247; return HandStrength; }
					if (n2 == 1) { HandStrength = -2248; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2249; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2250; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2251; return HandStrength; }
					if (n3 == 1) { HandStrength = -2252; return HandStrength; }
					if (n2 == 1) { HandStrength = -2253; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2254; return HandStrength; }
					if (n2 == 1) { HandStrength = -2255; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2256; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2257; return HandStrength; }
					if (n2 == 1) { HandStrength = -2258; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2259; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2260; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2261; return HandStrength; }
					if (n2 == 1) { HandStrength = -2262; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2263; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2264; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2265; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (n8 == 1) {
		if (n7 == 1) {
			if (n6 == 1) {
				if (n5 == 1) {
					if (n4 == 1) { HandStrength = -2266; return HandStrength; }
					if (n3 == 1) { HandStrength = -2267; return HandStrength; }
					if (n2 == 1) { HandStrength = -2268; return HandStrength; }
				};
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2269; return HandStrength; }
					if (n2 == 1) { HandStrength = -2270; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2271; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2272; return HandStrength; }
					if (n2 == 1) { HandStrength = -2273; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2274; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2275; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2276; return HandStrength; }
					if (n2 == 1) { HandStrength = -2277; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2278; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2279; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2280; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (n7 == 1) {
		if (n6 == 1) {
			if (n5 == 1) {
				if (n4 == 1) {
					if (n3 == 1) { HandStrength = -2281; return HandStrength; }
					if (n2 == 1) { HandStrength = -2282; return HandStrength; }
				};
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2283; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2284; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2285; return HandStrength; }
				};
				if (n2 == 1) {
				};
			};
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n4 == 1) {
			if (n3 == 1) {
				if (n2 == 1) {
				};
			};
			if (n2 == 1) {
			};
		};
		if (n3 == 1) {
			if (n2 == 1) {
			};
		};
		if (n2 == 1) {
		};
	};
	if (n6 == 1) {
		if (n5 == 1) {
			if (n4 == 1) {
				if (n3 == 1) {
					if (n2 == 1) { HandStrength = -2286; return HandStrength; }
				};
			};
		};
	};





	return HandStrength;



}
void CHandStrength::CountCard() {
	string line ="";

	for (int i = 0; i < 7; i++) {
		if (card[i] == "") { break; }
		switch (card[i][1]) {
		case 'c':
			switch (card[i][0]) {
			case 'A':  cA = 1; nA += 1; nc += 1; TotCard[0] += 1; continue;
			case 'K':  cK = 1; nK += 1; nc += 1; TotCard[1] += 1; continue;
			case 'Q':  cQ = 1; nQ += 1; nc += 1; TotCard[2] += 1; continue;
			case 'J':  cJ = 1; nJ += 1; nc += 1; TotCard[3] += 1; continue;
			case 'T':  cT = 1; nT += 1; nc += 1; TotCard[4] += 1; continue;
			case '9':  c9 = 1; n9 += 1; nc += 1; TotCard[5] += 1; continue;
			case '8':  c8 = 1; n8 += 1; nc += 1; TotCard[6] += 1; continue;
			case '7':  c7 = 1; n7 += 1; nc += 1; TotCard[7] += 1; continue;
			case '6':  c6 = 1; n6 += 1; nc += 1; TotCard[8] += 1; continue;
			case '5':  c5 = 1; n5 += 1; nc += 1; TotCard[9] += 1; continue;
			case '4':  c4 = 1; n4 += 1; nc += 1; TotCard[10] += 1; continue;
			case '3':  c3 = 1; n3 += 1; nc += 1; TotCard[11] += 1; continue;
			case '2':  c2 = 1; n2 += 1; nc += 1; TotCard[12] += 1; continue;
				break;
			}
		case 'd':
			switch (card[i][0]) {
			case 'A':  dA = 1; nA += 1; nd += 1; TotCard[0] += 1; continue;
			case 'K':  dK = 1; nK += 1; nd += 1; TotCard[1] += 1; continue;
			case 'Q':  dQ = 1; nQ += 1; nd += 1; TotCard[2] += 1; continue;
			case 'J':  dJ = 1; nJ += 1; nd += 1; TotCard[3] += 1; continue;
			case 'T':  dT = 1; nT += 1; nd += 1; TotCard[4] += 1; continue;
			case '9':  d9 = 1; n9 += 1; nd += 1; TotCard[5] += 1; continue;
			case '8':  d8 = 1; n8 += 1; nd += 1; TotCard[6] += 1; continue;
			case '7': d7 = 1; n7 += 1; nd += 1; TotCard[7] += 1; continue;
			case '6': d6 = 1; n6 += 1; nd += 1; TotCard[8] += 1; continue;
			case '5': d5 = 1; n5 += 1; nd += 1; TotCard[9] += 1; continue;
			case '4': d4 = 1; n4 += 1; nd += 1; TotCard[10] += 1; continue;
			case '3': d3 = 1; n3 += 1; nd += 1; TotCard[11] += 1; continue;
			case '2':  d2 = 1; n2 += 1; nd += 1; TotCard[12] += 1; continue;
				break;
			}
		case 's':
			switch (card[i][0]) {
			case 'A':  sA = 1; nA += 1; ns += 1; TotCard[0] += 1; continue;
			case 'K':  sK = 1; nK += 1; ns += 1; TotCard[1] += 1; continue;
			case 'Q':  sQ = 1; nQ += 1; ns += 1; TotCard[2] += 1; continue;
			case 'J':  sJ = 1; nJ += 1; ns += 1; TotCard[3] += 1; continue;
			case 'T':  sT = 1; nT += 1; ns += 1; TotCard[4] += 1; continue;
			case '9':  s9 = 1; n9 += 1; ns += 1; TotCard[5] += 1; continue;
			case '8':  s8 = 1; n8 += 1; ns += 1; TotCard[6] += 1; continue;
			case '7':  s7 = 1; n7 += 1; ns += 1; TotCard[7] += 1; continue;
			case '6':  s6 = 1; n6 += 1; ns += 1; TotCard[8] += 1; continue;
			case '5':  s5 = 1; n5 += 1; ns += 1; TotCard[9] += 1; continue;
			case '4':  s4 = 1; n4 += 1; ns += 1; TotCard[10] += 1; continue;
			case '3':  s3 = 1; n3 += 1; ns += 1; TotCard[11] += 1; continue;
			case '2':  s2 = 1; n2 += 1; ns += 1; TotCard[12] += 1; continue;
			}
		case 'h':
			switch (card[i][0]) {
			case 'A': hA = 1; nA += 1; nh += 1; TotCard[0] += 1; continue;
			case 'K': hK = 1; nK += 1; nh += 1; TotCard[1] += 1; continue;
			case 'Q': hQ = 1; nQ += 1; nh += 1; TotCard[2] += 1; continue;
			case 'J': hJ = 1; nJ += 1; nh += 1; TotCard[3] += 1; continue;
			case 'T': hT = 1; nT += 1; nh += 1; TotCard[4] += 1; continue;
			case '9': h9 = 1; n9 += 1; nh += 1; TotCard[5] += 1; continue;
			case '8': h8 = 1; n8 += 1; nh += 1; TotCard[6] += 1; continue;
			case '7': h7 = 1; n7 += 1; nh += 1; TotCard[7] += 1; continue;
			case '6': h6 = 1; n6 += 1; nh += 1; TotCard[8] += 1; continue;
			case '5': h5 = 1; n5 += 1; nh += 1; TotCard[9] += 1; continue;
			case '4': h4 = 1; n4 += 1; nh += 1; TotCard[10] += 1; continue;
			case '3': h3 = 1; n3 += 1; nh += 1; TotCard[11] += 1; continue;
			case '2': h2 = 1; n2 += 1; nh += 1; TotCard[12] += 1; continue;
			}
			break;
		}

	};



};
void CHandStrength::Reset_CountCard() {


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

	HandStrength = -100000;


	TotCard[0] = 0;
	TotCard[1] = 0;
	TotCard[2] = 0;
	TotCard[3] = 0;
	TotCard[4] = 0;
	TotCard[5] = 0;
	TotCard[6] = 0;
	TotCard[7] = 0;
	TotCard[8] = 0;
	TotCard[9] = 0;
	TotCard[10] = 0;
	TotCard[11] = 0;
	TotCard[12] = 0;

}
