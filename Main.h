#pragma once

enum class State { Fold, Check, Call, Raise,  Blinds, None, Bet,  Allin, Call_Allin, Forced_Allin, null, Out };
enum class EPosition { Early1, Early2, Early3, Middle1, Middle2, Middle3, CutOff, Button, SB, BB, Middle, Early, null };
struct Symbols {
	//cards
	
		bool hand$A = false;
		bool hand$K = false;
		bool hand$Q = false;
		bool hand$J = false;
		bool hand$T = false;
		bool hand$9 = false;
		bool hand$8 = false;
		bool hand$7 = false;
		bool hand$6 = false;
		bool hand$5 = false;
		bool hand$4 = false;
		bool hand$3 = false;
		bool hand$2 = false;

		bool hand$AA = false;
		bool hand$KK = false;
		bool hand$QQ = false;
		bool hand$JJ = false;
		bool hand$TT = false;
		bool hand$99 = false;
		bool hand$88 = false;
		bool hand$77 = false;
		bool hand$66 = false;
		bool hand$55 = false;
		bool hand$44 = false;
		bool hand$33 = false;
		bool hand$22 = false;

		bool hand$AK = false;
		bool hand$AQ = false;
		bool hand$AJ = false;
		bool hand$AT = false;
		bool hand$A9 = false;
		bool hand$A8 = false;
		bool hand$A7 = false;
		bool hand$A6 = false;
		bool hand$A5 = false;
		bool hand$A4 = false;
		bool hand$A3 = false;
		bool hand$A2 = false;

		bool hand$KQ = false;
		bool hand$KJ = false;
		bool hand$KT = false;
		bool hand$K9 = false;
		bool hand$K8 = false;
		bool hand$K7 = false;
		bool hand$K6 = false;
		bool hand$K5 = false;
		bool hand$K4 = false;
		bool hand$K3 = false;
		bool hand$K2 = false;

		bool hand$QJ = false;
		bool hand$QT = false;
		bool hand$Q9 = false;
		bool hand$Q8 = false;
		bool hand$Q7 = false;
		bool hand$Q6 = false;
		bool hand$Q5 = false;
		bool hand$Q4 = false;
		bool hand$Q3 = false;
		bool hand$Q2 = false;

		bool hand$JT = false;
		bool hand$J9 = false;
		bool hand$J8 = false;
		bool hand$J7 = false;
		bool hand$J6 = false;
		bool hand$J5 = false;
		bool hand$J4 = false;
		bool hand$J3 = false;
		bool hand$J2 = false;


		bool hand$T9 = false;
		bool hand$T8 = false;
		bool hand$T7 = false;
		bool hand$T6 = false;
		bool hand$T5 = false;
		bool hand$T4 = false;
		bool hand$T3 = false;
		bool hand$T2 = false;

		bool hand$98 = false;
		bool hand$97 = false;
		bool hand$96 = false;
		bool hand$95 = false;
		bool hand$94 = false;
		bool hand$93 = false;
		bool hand$92 = false;


		bool hand$87 = false;
		bool hand$86 = false;
		bool hand$85 = false;
		bool hand$84 = false;
		bool hand$83 = false;
		bool hand$82 = false;


		bool hand$76 = false;
		bool hand$75 = false;
		bool hand$74 = false;
		bool hand$73 = false;
		bool hand$72 = false;


		bool hand$65 = false;
		bool hand$64 = false;
		bool hand$63 = false;
		bool hand$62 = false;



		bool hand$54 = false;
		bool hand$53 = false;
		bool hand$52 = false;

		bool hand$23 = false;


		bool hand$AKs = false;
		bool hand$AQs = false;
		bool hand$AJs = false;
		bool hand$ATs = false;
		bool hand$A9s = false;
		bool hand$A8s = false;
		bool hand$A7s = false;
		bool hand$A6s = false;
		bool hand$A5s = false;
		bool hand$A4s = false;
		bool hand$A3s = false;
		bool hand$A2s = false;

		bool hand$KQs = false;
		bool hand$KJs = false;
		bool hand$KTs = false;
		bool hand$K9s = false;
		bool hand$K8s = false;
		bool hand$K7s = false;
		bool hand$K6s = false;
		bool hand$K5s = false;
		bool hand$K4s = false;
		bool hand$K3s = false;
		bool hand$K2s = false;

		bool hand$QJs = false;
		bool hand$QTs = false;
		bool hand$Q9s = false;
		bool hand$Q8s = false;
		bool hand$Q7s = false;
		bool hand$Q6s = false;
		bool hand$Q5s = false;
		bool hand$Q4s = false;
		bool hand$Q3s = false;
		bool hand$Q2s = false;

		bool hand$JTs = false;
		bool hand$J9s = false;
		bool hand$J8s = false;
		bool hand$J7s = false;
		bool hand$J6s = false;
		bool hand$J5s = false;
		bool hand$J4s = false;
		bool hand$J3s = false;
		bool hand$J2s = false;


		bool hand$T9s = false;
		bool hand$T8s = false;
		bool hand$T7s = false;
		bool hand$T6s = false;
		bool hand$T5s = false;
		bool hand$T4s = false;
		bool hand$T3s = false;
		bool hand$T2s = false;

		bool hand$98s = false;
		bool hand$97s = false;
		bool hand$96s = false;
		bool hand$95s = false;
		bool hand$94s = false;
		bool hand$93s = false;
		bool hand$92s = false;


		bool hand$87s = false;
		bool hand$86s = false;
		bool hand$85s = false;
		bool hand$84s = false;
		bool hand$83s = false;
		bool hand$82s = false;


		bool hand$76s = false;
		bool hand$75s = false;
		bool hand$74s = false;
		bool hand$73s = false;
		bool hand$72s = false;


		bool hand$65s = false;
		bool hand$64s = false;
		bool hand$63s = false;
		bool hand$62s = false;



		bool hand$54s = false;
		bool hand$53s = false;
		bool hand$52s = false;

		bool hand$23s = false;


		//----FOR AVOID TYPO
		bool hand$KA = false;
		bool hand$QA = false;
		bool hand$JA = false;
		bool hand$TA = false;
		bool hand$9A = false;
		bool hand$8A = false;
		bool hand$7A = false;
		bool hand$6A = false;
		bool hand$5A = false;
		bool hand$4A = false;
		bool hand$3A = false;
		bool hand$2A = false;

		bool hand$QK = false;
		bool hand$JK = false;
		bool hand$TK = false;
		bool hand$9K = false;
		bool hand$8K = false;
		bool hand$7K = false;
		bool hand$6K = false;
		bool hand$5K = false;
		bool hand$4K = false;
		bool hand$3K = false;
		bool hand$2K = false;

		bool hand$JQ = false;
		bool hand$TQ = false;
		bool hand$9Q = false;
		bool hand$8Q = false;
		bool hand$7Q = false;
		bool hand$6Q = false;
		bool hand$5Q = false;
		bool hand$4Q = false;
		bool hand$3Q = false;
		bool hand$2Q = false;

		bool hand$TJ = false;
		bool hand$9J = false;
		bool hand$8J = false;
		bool hand$7J = false;
		bool hand$6J = false;
		bool hand$5J = false;
		bool hand$4J = false;
		bool hand$3J = false;
		bool hand$2J = false;


		bool hand$9T = false;
		bool hand$8T = false;
		bool hand$7T = false;
		bool hand$6T = false;
		bool hand$5T = false;
		bool hand$4T = false;
		bool hand$3T = false;
		bool hand$2T = false;

		bool hand$89 = false;
		bool hand$79 = false;
		bool hand$69 = false;
		bool hand$59 = false;
		bool hand$49 = false;
		bool hand$39 = false;
		bool hand$29 = false;


		bool hand$78 = false;
		bool hand$68 = false;
		bool hand$58 = false;
		bool hand$48 = false;
		bool hand$38 = false;
		bool hand$28 = false;


		bool hand$67 = false;
		bool hand$57 = false;
		bool hand$47 = false;
		bool hand$37 = false;
		bool hand$27 = false;


		bool hand$56 = false;
		bool hand$46 = false;
		bool hand$36 = false;
		bool hand$26 = false;



		bool hand$45 = false;
		bool hand$35 = false;
		bool hand$25 = false;

		bool hand$32 = false;

		bool hand$KAs = false;
		bool hand$QAs = false;
		bool hand$JAs = false;
		bool hand$TAs = false;
		bool hand$9As = false;
		bool hand$8As = false;
		bool hand$7As = false;
		bool hand$6As = false;
		bool hand$5As = false;
		bool hand$4As = false;
		bool hand$3As = false;
		bool hand$2As = false;

		bool hand$QKs = false;
		bool hand$JKs = false;
		bool hand$TKs = false;
		bool hand$9Ks = false;
		bool hand$8Ks = false;
		bool hand$7Ks = false;
		bool hand$6Ks = false;
		bool hand$5Ks = false;
		bool hand$4Ks = false;
		bool hand$3Ks = false;
		bool hand$2Ks = false;

		bool hand$JQs = false;
		bool hand$TQs = false;
		bool hand$9Qs = false;
		bool hand$8Qs = false;
		bool hand$7Qs = false;
		bool hand$6Qs = false;
		bool hand$5Qs = false;
		bool hand$4Qs = false;
		bool hand$3Qs = false;
		bool hand$2Qs = false;

		bool hand$TJs = false;
		bool hand$9Js = false;
		bool hand$8Js = false;
		bool hand$7Js = false;
		bool hand$6Js = false;
		bool hand$5Js = false;
		bool hand$4Js = false;
		bool hand$3Js = false;
		bool hand$2Js = false;


		bool hand$9Ts = false;
		bool hand$8Ts = false;
		bool hand$7Ts = false;
		bool hand$6Ts = false;
		bool hand$5Ts = false;
		bool hand$4Ts = false;
		bool hand$3Ts = false;
		bool hand$2Ts = false;

		bool hand$89s = false;
		bool hand$79s = false;
		bool hand$69s = false;
		bool hand$59s = false;
		bool hand$49s = false;
		bool hand$39s = false;
		bool hand$29s = false;


		bool hand$78s = false;
		bool hand$68s = false;
		bool hand$58s = false;
		bool hand$48s = false;
		bool hand$38s = false;
		bool hand$28s = false;


		bool hand$67s = false;
		bool hand$57s = false;
		bool hand$47s = false;
		bool hand$37s = false;
		bool hand$27s = false;


		bool hand$56s = false;
		bool hand$46s = false;
		bool hand$36s = false;
		bool hand$26s = false;



		bool hand$45s = false;
		bool hand$35s = false;
		bool hand$25s = false;

		bool hand$32s = false;
	

	bool HavePair = false;
	bool HaveTopPair = false;
	bool PairInHand = false;

	bool HaveTwoPair = false;
	bool HaveTopTwoPair = false;

	bool HaveTrips = false;
	bool HaveTopTrips = false;

	bool HaveFour = false;

	bool HaveFlush = false;
	bool HaveFlushDraw = false;
	bool HaveNutFlush = false;
	bool HaveNutFlushDraw = false;

	bool HaveFullHouse = false;

	bool HaveStraight = false;
	bool HaveStraightDraw = false;
	bool HaveNutStraight = false;
	bool HaveNutStraightDraw = false;

	bool HaveNothing = false;


};
#include <iostream>
#include <time.h>
#include <cassert>

using namespace std;
