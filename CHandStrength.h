#pragma once
#include <string>
using namespace std;


class CHandStrength
{
private:
	int HandStrength = 0;
	string NewDeck[52] = { "Ad", "Kd", "Qd", "Jd","Td", "9d", "8d", "7d", "6d", "5d", "4d", "3d", "2d" ,
							  "Ac", "Kc", "Qc", "Jc","Tc", "9c", "8c", "7c", "6c", "5c", "4c", "3c", "2c" ,
							  "As", "Ks", "Qs", "Js","Ts", "9s", "8s", "7s", "6s", "5s", "4s", "3s", "2s" ,
							  "Ah", "Kh", "Qh", "Jh","Th", "9h", "8h", "7h", "6h", "5h", "4h", "3h", "2h" };

	int nA = 0, nK = 0, nQ = 0, nJ = 0, nT = 0, n9 = 0, n8 = 0, n7 = 0, n6 = 0, n5 = 0, n4 = 0, n3 = 0, n2 = 0,
		nc = 0, nh = 0, ns = 0, nd = 0,
		cA = 0, cK = 0, cQ = 0, cJ = 0, cT = 0, c9 = 0, c8 = 0, c7 = 0, c6 = 0, c5 = 0, c4 = 0, c3 = 0, c2 = 0,
		dA = 0, dK = 0, dQ = 0, dJ = 0, dT = 0, d9 = 0, d8 = 0, d7 = 0, d6 = 0, d5 = 0, d4 = 0, d3 = 0, d2 = 0,
		hA = 0, hK = 0, hQ = 0, hJ = 0, hT = 0, h9 = 0, h8 = 0, h7 = 0, h6 = 0, h5 = 0, h4 = 0, h3 = 0, h2 = 0,
		sA = 0, sK = 0, sQ = 0, sJ = 0, sT = 0, s9 = 0, s8 = 0, s7 = 0, s6 = 0, s5 = 0, s4 = 0, s3 = 0, s2;
	
	
	int index = 0;
	int TotCard[13] = { 0 };
	string card[7] = { "" };

	enum class cards{
		cA, hA ,dA, As,
		cK, hK, dK, sK,
		cQ, hQ, dQ, sQ,
		cJ, hJ, dJ, sJ,
		cT, hT, dT, sT,
		c9, h9, d9, s9,
		c8, h8, d8, s8,
		c7, h7, d7, s7,
		c6, h6, d6, s6,		
		c5, h5, d5, s5,
		c4, h4, d4, s4,
		c3, h3, d3, s3,
		c2, h2, d2, s2
	};
	cards E_cards[7];
	bool CheckKicker = true;

	void CountCard();
	void Reset_CountCard();

	

public:
	int calc_HandStrength(string card1, string card2, string card3, string card4, string card5, string card6, string card7 );

};

