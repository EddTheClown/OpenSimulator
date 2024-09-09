#pragma once
#include <string>
#include "Player.h"
#include <fstream>
#include <iostream>
//enum class State { Fold, Check, Call, Raise, Blinds, None, Bet, Allin, Call_Allin, Forced_Allin, null, Out };

using namespace std;
class HHWriter
{
public:
	string HHline = "";
	string HH_File = "HandHistory.txt";


	//add line to ram for hand hystory (it will be written on txt at the end of the hand)
	void HandHistory(string _text, bool bHandHistory) {
		//add line to ram for hand hystory (it will be written on txt at the end of the hand)
		if (bHandHistory) {
			HHline += _text + "\n";
		}
	}
	//add on HH the player action
	void handhistory_player_action(int i , vector<Player> p, bool bTournament , int SBPosition , int PlayersInHand, bool bHandHistory) {
		switch (p[i].mystate)
		{
		case State::Blinds:
			if (bTournament) {

				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [" + to_string(p[i].mybet) + "]", bHandHistory); }
				if (p[i].inBigBlind) {
					if (p[SBPosition].mystack == 0 && PlayersInHand == 0) {
						p[i].mybet = p[SBPosition].mybet;
						p[i].UpdateMyStack();
					}
					HandHistory(p[i].myname + " posts big blind [" + to_string(p[i].mybet) + "]", bHandHistory);
					HandHistory("** Dealing down cards **", bHandHistory);
					HandHistory("Dealt to " + p[0].myname + " [ " + *p[0].MyCards[0] + ", " + *p[0].MyCards[1] + " ]", bHandHistory);

				}
			}
			else {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [€" + to_string(p[i].mybet) + "]", bHandHistory); }
				if (p[i].inBigBlind) {
					if (p[SBPosition].mystack == 0 && PlayersInHand == 0) {
						p[i].mybet = p[SBPosition].mybet;
						p[i].UpdateMyStack();
					}
					HandHistory(p[i].myname + " posts big blind [€" + to_string(p[i].mybet) + "]", bHandHistory);
					HandHistory("** Dealing down cards **", bHandHistory);
					HandHistory("Dealt to " + p[0].myname + " [ " + *p[0].MyCards[0] + ", " + *p[0].MyCards[1] + " ]", bHandHistory);


				}
			}
			break;

		case State::Forced_Allin:
			if (bTournament) {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [" + to_string(p[i].mybet) + "]", bHandHistory); }
				else if (p[i].inBigBlind) { HandHistory(p[i].myname + " posts big blind [" + to_string(p[i].mybet) + "]", bHandHistory); }
			}
			else {
				if (p[i].inSmallBlind) { HandHistory(p[i].myname + " posts small blind [€" + to_string(p[i].mybet) + "]", bHandHistory); }
				else if (p[i].inBigBlind) { HandHistory(p[i].myname + " posts big blind [€" + to_string(p[i].mybet) + "]", bHandHistory); }

			};
			break;
		case State::Fold:
			HandHistory(p[i].myname + " folds", bHandHistory);
			break;

		case State::Call_Allin:
			if (bTournament) {
				HandHistory(p[i].myname + " calls [" + to_string(p[i].AmountToCall) + "]", bHandHistory);
			}
			else {
				HandHistory(p[i].myname + " calls [€" + to_string(p[i].AmountToCall) + "]", bHandHistory);
			};

			break;
		case State::Call:
			if (bTournament) {
				HandHistory(p[i].myname + " calls [" + to_string(p[i].AmountToCall) + "]", bHandHistory);
			}
			else {
				HandHistory(p[i].myname + " calls [€" + to_string(p[i].AmountToCall) + "]", bHandHistory);
			}
			break;
		case State::Bet:
			if (bTournament) {
				HandHistory(p[i].myname + " bets [" + to_string(p[i].myraise) + "]", bHandHistory);
			}
			else {
				HandHistory(p[i].myname + " bets [€" + to_string(p[i].myraise) + "]", bHandHistory);

			}
			break;
		case State::Raise:
			if (bTournament) {
				HandHistory(p[i].myname + " raises [" + to_string(p[i].myraise) + "]", bHandHistory);
			}
			else {
				HandHistory(p[i].myname + " raises [€" + to_string(p[i].myraise) + "]", bHandHistory);

			}
			break;
		case State::Allin:
			if (bTournament) {
				HandHistory(p[i].myname + " raises [" + to_string(p[i].myraise) + "]", bHandHistory);
			}
			else {
				HandHistory(p[i].myname + " raises [€" + to_string(p[i].myraise) + "]", bHandHistory);

			}

			break;
		case State::Check:
			HandHistory(p[i].myname + " checks", bHandHistory);
			break;

		}

	};
	//add on HH the begin of new hand
	void handhistory_new_hand(int nPlayers,int Handnumber , bool bTournament , int SBsize , int BBsize , vector<Player> p, bool bHandHistory) {
		int Table = 0;
		if (nPlayers > 9)nPlayers = 9;
		if (nPlayers == 2) { Table = 2; };
		if (nPlayers > 2) { Table = 6; };
		if (nPlayers > 6) { Table = 8; };

		if (bTournament == true) {
			HandHistory("#Game No : " + to_string(Handnumber), bHandHistory);
			HandHistory("***** 888.it Hand History for Game " + to_string(Handnumber) + " *****", bHandHistory);
			HandHistory(to_string(SBsize) + "/" + to_string(BBsize) + " Blinds No Limit Holdem - *** 04 06 2018 22:42:38", bHandHistory);
			HandHistory("Tournament #0 Free - Table #0 " + to_string(Table) + " Max (Real Money)", bHandHistory);
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].inButton) {
					HandHistory("Seat " + to_string(p[i].myseat) + " is the button", bHandHistory);
					break;
				}
			}
			HandHistory("Total number of players : " + to_string(nPlayers), bHandHistory);
			for (int i = 0; i < nPlayers; i++) {
				HandHistory("Seat " + to_string(p[i].myseat) + ": " + p[i].myname + " ( " + to_string(p[i].mystack) + " )", bHandHistory);
			}
		}
		if (bTournament == false) {
			HandHistory("#Game No : " + to_string(Handnumber), bHandHistory);
			HandHistory("***** 888.it Hand History for Game " + to_string(Handnumber) + " *****", bHandHistory);
			HandHistory("€" + to_string(SBsize) + "/€" + to_string(BBsize) + " Blinds No Limit Holdem - *** 01 01 2021 00:00:00", bHandHistory);
			HandHistory("Table EDD " + to_string(Table) + " Max(Real Money)", bHandHistory);
			for (int i = 0; i < nPlayers; i++) {
				if (p[i].inButton) {
					HandHistory("Seat " + to_string(p[i].myseat) + " is the button", bHandHistory);
					break;
				}
			}
			HandHistory("Total number of players : " + to_string(nPlayers), bHandHistory);
			for (int i = 0; i < nPlayers; i++) {
				HandHistory("Seat " + to_string(p[i].myseat) + ": " + p[i].myname + " ( €" + to_string(p[i].mystack) + " )", bHandHistory);
			}
		}
	};
	//write HH on txt and clean ram
	void handhistory_finish(int NumberOfWinners, bool SingleSituation, vector<Player> p,bool bHandHistory) {
		HandHistory("\n", bHandHistory);
		//for avoid multi pot rare problems
		if (NumberOfWinners != 1) {
			HHline = "";
			return;
		}
		//if single situation is active in ambient.h 
		//only hands specified by player 0 will be written
		if (!SingleSituation) {
			ofstream hand;
			hand.open(HH_File, ios::app);
			hand << HHline;
			hand.close();
			HHline = "";
			return;
		}
		else {
			if (p[0].writehand) {
				p[0].writehand = false;
				ofstream hand;
				hand.open(HH_File, ios::app);
				hand << HHline;
				hand.close();
				HHline = "";
			}


		}
		HHline = "";


	};
	//save last hand number if active in ambient.h for not duplicate pt hand
	void save_last_handumber(bool SaveLastHandNumber , int Handnumber) {
		if (!SaveLastHandNumber) {
			Handnumber = 0;
		}
		ofstream handN;
		handN.open("HandNumber.txt");
		handN << Handnumber;
		handN.close();
	}

	//load last hand number if active in ambient.h for not duplicate pt hand
	void load_last_handumber(int& Handnumber, bool SingleSituation,bool bHandHistory)const {
		if (!bHandHistory)return;
		string nHand;
		ofstream write;
		ifstream hand;

		hand.open("HandNumber.txt");

		if (hand) {
			getline(hand, nHand);
		}
		else
		{
			write.open("HandNumber.txt");
			write << 0;
			write.close();
			hand.open("HandNumber.txt");
			getline(hand, nHand);
		}

		Handnumber = stoi(nHand);
		hand.close();

		//clear old handlog file	
		ResetTxtFiles(SingleSituation);
		

	};
	//reset all used txt files
	void ResetTxtFiles(bool SingleSituation)const {

		ofstream hand2;
		hand2.open(HH_File);
		hand2.close();

		hand2.open("Player0_LOG.txt");
		hand2.close();

		hand2.open("SimulationHandHistory.txt");
		hand2.close();

		hand2.open("prize.txt");
		hand2.close();

		hand2.open("txt/Writehand.txt");
		hand2.close();
		if (SingleSituation) {
			hand2.open("SingleSituation.txt");
			hand2.close();
		}
	

	}
};

