#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "CHandStrength.h"
#include <vector>

class prwin_calcolator
{
private:

	string ShuffledDeck[52] = { "" };
	string NewDeck[52] = { "Ad", "Kd", "Qd", "Jd","Td", "9d", "8d", "7d", "6d", "5d", "4d", "3d", "2d" ,
			  "Ac", "Kc", "Qc", "Jc","Tc", "9c", "8c", "7c", "6c", "5c", "4c", "3c", "2c" ,
			  "As", "Ks", "Qs", "Js","Ts", "9s", "8s", "7s", "6s", "5s", "4s", "3s", "2s" ,
			  "Ah", "Kh", "Qh", "Jh","Th", "9h", "8h", "7h", "6h", "5h", "4h", "3h", "2h" };

	
	string Rank[13] = { "A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2" };
	string Suits[4] = { "d","h", "c", "s" };
	double prwin = 0;
	float prtie = 0;
	float prlos = 0;

	int Card1 = 0;
	int Card2 = 0;
	int Card3 = 0;
	int Card4 = 0;
	int Card5 = 0;
	int Card6 = 0;
	int Card7 = 0;


	int BetRound = 1;

	int nIterations = 0;
	int nWin = 0;

	int Cards = -1;

	int PreflopNumber = -1;

	string p0card[2] = { "" };
	string p1card[2] = { "" };
	string p2card[2] = { "" };
	string p3card[2] = { "" };
	string p4card[2] = { "" };
	string p5card[2] = { "" };
	string p6card[2] = { "" };
	string p7card[2] = { "" };
	string p8card[2] = { "" };

	string PlayerCards[7] = { "" };

	string pCard1 = "";
	string pCard2 = "";
	string flop1 = "";
	string flop2 = "";
	string flop3 = "";
	string turn = "";
	string river = "";

	int nSuited = 1;
	char preflop_card1 = '-';
	char preflop_card2 = '-';

	int nPlayers = 0;
	int pStrength[9] = { -100000 };



	void set_player_strength();
	void set_players_card();
	void MixDeck(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river);
	bool winner();
	void reset_player_cards();

public:
	double calc_prwin(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river, int _PlayersInHand,int _nIteration);
	double Preflop_precalc_prwin(int PreflopNumber, int nPlayers);
	double Flop_precalc_prwin(int FlopNumber, int nPlayers);
	double Turn_precalc_prwin(int TurnNumber, int nPlayers);
	double River_precalc_prwin(int RiverNumber, int nPlayers);
	int set_preflopnumber(string card1,string card2);
	void set_nSuited(string _pCard1, string _pCard2, string _flop1, string _flop2, string _flop3, string _turn, string _river);

	//tools
	static void GetPrwin();
	static void WritePrwinALL();
	static void WriteAllPot();
	static void WriteAllStack();
	static void MinPrwin();
	static void generateCode();

	void findPrwin();
	static void GetPrwinINVERSO();
	void findPrwinINVERSO();
	void GetPrwinAutoINVERSO(string Cfile = "ManualPrwinC++.txt", string OpplFilestring = "ManualPrwinOppl.txt", string card1 = "", string card2 = "", string card3 = "", string card4 = "", string card5 = "", string card6 = "", string card7 = "");
	
	void getALLprwin();
	void getALLprwinMANUAL();

	void findPrwinAUTO_wins(string wins[], int betround = 1, double targetprwin = 0.5);
	void GetPrwinAuto_wins(string wins[], string card1, string card2, string card3, string card4, string card5, string card6, string card7);


	//prov
	void test();
	void GetPrwinAuto(string Cfile = "ManualPrwinC++.txt", string OpplFilestring = "ManualPrwinOppl.txt",string card1 ="", string card2 = "", string card3 = "", string card4 = "", string card5 = "", string card6 = "", string card7 = "");

	//write code on txt scripts
	void WriteCodeForPreflopNumber();
	void WriteCodeForFlopNumber();

	void WriteTxt();

	static double GetMinPrwinBasedOnStack(int _StackSize);
	static double adjust_prwin(double prwin_single, int num_opponents, double k);


};

