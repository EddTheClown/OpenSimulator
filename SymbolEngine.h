#include "Main.h"
class SymbolEngine {

	

	void SetPoketHand(string Card0[0] , string Card1[0],Symbols& symbols ) {
		bool suited = false;
		if (Card0[1] == Card1[1])suited = true;
		if (Card0[0] == Card1[0]) {
			symbols.HavePair = true;
			symbols.PairInHand = true;
			if(Card0[0]=='A')symbols.HaveTopPair = true;

		}

		if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$2 = true;
		if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$3 = true;
		if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$4 = true;
		if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$5 = true;
		if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$6 = true;
		if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$7 = true;
		if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$8 = true;
		if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$9 = true;
		if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$T = true;
		if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$J = true;
		if (Card0[0] == "Q" || Card1[0] == "Q") symbols.hand$Q = true;
		if (Card0[0] == "K" || Card1[0] == "K") symbols.hand$K = true;
		if (Card0[0] == "A" || Card1[0] == "A") symbols.hand$A = true;

		if (Card0[0] == "2" && Card1[0] == "2") symbols.hand$22 = true;
		if (Card0[0] == "3" && Card1[0] == "3") symbols.hand$33 = true;
		if (Card0[0] == "4" && Card1[0] == "4") symbols.hand$44 = true;
		if (Card0[0] == "5" && Card1[0] == "5") symbols.hand$55 = true;
		if (Card0[0] == "6" && Card1[0] == "6") symbols.hand$66 = true;
		if (Card0[0] == "7" && Card1[0] == "7") symbols.hand$77 = true;
		if (Card0[0] == "8" && Card1[0] == "8") symbols.hand$88 = true;
		if (Card0[0] == "9" && Card1[0] == "9") symbols.hand$99 = true;
		if (Card0[0] == "T" && Card1[0] == "T") symbols.hand$TT = true;
		if (Card0[0] == "J" && Card1[0] == "J") symbols.hand$JJ = true;
		if (Card0[0] == "Q" && Card1[0] == "Q") symbols.hand$QQ = true;
		if (Card0[0] == "K" && Card1[0] == "K") symbols.hand$KK = true;
		if (Card0[0] == "A" && Card1[0] == "A") symbols.hand$AA = true;


		//not suited
		if (Card0[0] == "A" || Card1[0] == "A") {
			if (Card0[0] == "K" || Card1[0] == "K") symbols.hand$AK = true;
			else if (Card0[0] == "Q" || Card1[0] == "Q") symbols.hand$AQ = true;
			else if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$AJ = true;
			else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$AT = true;
			else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$A9 = true;
			else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$A8 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$A7 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$A6 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$A5 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$A4 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$A3 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$A2 = true;
		}
		if (Card0[0] == "K" || Card1[0] == "K") {
			if (Card0[0] == "Q" || Card1[0] == "Q") symbols.hand$KQ = true;
			else if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$KJ = true;
			else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$KT = true;
			else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$K9 = true;
			else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$K8 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$K7 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$K6 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$K5 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$K4 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$K3 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$K2 = true;
		}
		if (Card0[0] == "Q" || Card1[0] == "Q") {
			if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$QJ = true;
			else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$QT = true;
			else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$Q9 = true;
			else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$Q8 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$Q7 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$Q6 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$Q5 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$Q4 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$Q3 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$Q2 = true;
		}
		if (Card0[0] == "J" || Card1[0] == "J") {
			if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$JT = true;
			else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$J9 = true;
			else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$J8 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$J7 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$J6 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$J5 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$J4 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$J3 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$J2 = true;
		}
		if (Card0[0] == "T" || Card1[0] == "T") {
			if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$T9 = true;
			else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$T8 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$T7 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$T6 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$T5 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$T4 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$T3 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$T2 = true;
		}
		if (Card0[0] == "9" || Card1[0] == "9") {
			if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$98 = true;
			else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$97 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$96 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$95 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$94 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$93 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$92 = true;
		}
		if (Card0[0] == "8" || Card1[0] == "8") {
			if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$87 = true;
			else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$86 = true;
			else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$85 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$84 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$83 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$82 = true;
		}
		if (Card0[0] == "7" || Card1[0] == "7") {
			if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$75 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$74 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$73 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$72 = true;
		}
		if (Card0[0] == "6" || Card1[0] == "6") {
			if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$65 = true;
			else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$64 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$63 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$62 = true;
		}
		if (Card0[0] == "5" || Card1[0] == "5") {
			if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$54 = true;
			else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$53 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$52 = true;
		}
		if (Card0[0] == "4" || Card1[0] == "4") {
			if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$43 = true;
			else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$42 = true;
		}
		if (Card0[0] == "3" || Card1[0] == "3") {
			if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$32 = true;
		}


		if (suited) {
			if (Card0[0] == "A" || Card1[0] == "A") {
				if (Card0[0] == "K" || Card1[0] == "K") symbols.hand$AKs = true;
				else if (Card0[0] == "Q" || Card1[0] == "Q") symbols.hand$AQs = true;
				else if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$AJs = true;
				else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$ATs = true;
				else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$A9s = true;
				else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$A8s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$A7s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$A6s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$A5s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$A4s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$A3s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$A2s = true;
			}
			if (Card0[0] == "K" || Card1[0] == "K") {
				if (Card0[0] == "Q" || Card1[0] == "Q") symbols.hand$KQs = true;
				else if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$KJs = true;
				else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$KTs = true;
				else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$K9s = true;
				else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$K8s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$K7s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$K6s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$K5s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$K4s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$K3s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$K2s = true;
			}
			if (Card0[0] == "Q" || Card1[0] == "Q") {
				if (Card0[0] == "J" || Card1[0] == "J") symbols.hand$QJs = true;
				else if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$QTs = true;
				else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$Q9s = true;
				else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$Q8s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$Q7s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$Q6s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$Q5s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$Q4s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$Q3s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$Q2s = true;
			}
			if (Card0[0] == "J" || Card1[0] == "J") {
				if (Card0[0] == "T" || Card1[0] == "T") symbols.hand$JTs = true;
				else if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$J9s = true;
				else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$J8s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$J7s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$J6s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$J5s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$J4s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$J3s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$J2s = true;
			}
			if (Card0[0] == "T" || Card1[0] == "T") {
				if (Card0[0] == "9" || Card1[0] == "9") symbols.hand$T9s = true;
				else if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$T8s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$T7s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$T6s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$T5s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$T4s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$T3s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$T2s = true;
			}
			if (Card0[0] == "9" || Card1[0] == "9") {
				if (Card0[0] == "8" || Card1[0] == "8") symbols.hand$98s = true;
				else if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$97s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$96s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$95s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$94s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$93s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$92s = true;
			}
			if (Card0[0] == "8" || Card1[0] == "8") {
				if (Card0[0] == "7" || Card1[0] == "7") symbols.hand$87s = true;
				else if (Card0[0] == "6" || Card1[0] == "6") symbols.hand$86s = true;
				else if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$85s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$84s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$83s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$82s = true;
			}
			if (Card0[0] == "7" || Card1[0] == "7") {
				if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$75s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$74s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$73s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$72s = true;
			}
			if (Card0[0] == "6" || Card1[0] == "6") {
				if (Card0[0] == "5" || Card1[0] == "5") symbols.hand$65s = true;
				else if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$64s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$63s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$62s = true;
			}
			if (Card0[0] == "5" || Card1[0] == "5") {
				if (Card0[0] == "4" || Card1[0] == "4") symbols.hand$54s = true;
				else if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$53s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$52s = true;
			}
			if (Card0[0] == "4" || Card1[0] == "4") {
				if (Card0[0] == "3" || Card1[0] == "3") symbols.hand$43s = true;
				else if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$42s = true;
			}
			if (Card0[0] == "3" || Card1[0] == "3") {
				if (Card0[0] == "2" || Card1[0] == "2") symbols.hand$32s = true;
			}

		}

		hand$KA = hand$AK;
		hand$QA = hand$AQ;
		hand$JA = hand$AJ;
		hand$TA = hand$AT;
		hand$9A = hand$A9;
		hand$8A = hand$A8;
		hand$7A = hand$A7;
		hand$6A = hand$A6;
		hand$5A = hand$A5;
		hand$4A = hand$A4;
		hand$3A = hand$A3;
		hand$2A = hand$A2;

		hand$QK = hand$KQ;
		hand$JK = hand$KJ;
		hand$TK = hand$KT;
		hand$9K = hand$K9;
		hand$8K = hand$K8;
		hand$7K = hand$K7;
		hand$6K = hand$K6;
		hand$5K = hand$K5;
		hand$4K = hand$K4;
		hand$3K = hand$K3;
		hand$2K = hand$K2;

		hand$JQ = hand$QJ;
		hand$TQ = hand$QT;
		hand$9Q = hand$Q9;
		hand$8Q = hand$Q8;
		hand$7Q = hand$Q7;
		hand$6Q = hand$Q6;
		hand$5Q = hand$Q5;
		hand$4Q = hand$Q4;
		hand$3Q = hand$Q3;
		hand$2Q = hand$Q2;

		hand$TJ = hand$JT;
		hand$9J = hand$J9;
		hand$8J = hand$J8;
		hand$7J = hand$J7;
		hand$6J = hand$J6;
		hand$5J = hand$J5;
		hand$4J = hand$J4;
		hand$3J = hand$J3;
		hand$2J = hand$J2;


		hand$9T = hand$T9;
		hand$8T = hand$T8;
		hand$7T = hand$T7;
		hand$6T = hand$T6;
		hand$5T = hand$T5;
		hand$4T = hand$T4;
		hand$3T = hand$T3;
		hand$2T = hand$T2;

		hand$89 = hand$98;
		hand$79 = hand$97;
		hand$69 = hand$96;
		hand$59 = hand$95;
		hand$49 = hand$94;
		hand$39 = hand$93;
		hand$29 = hand$92;


		hand$78 = hand$87;
		hand$68 = hand$86;
		hand$58 = hand$85;
		hand$48 = hand$84;
			hand$38 = hand$83;
			hand$28 = hand$82;


			hand$67 = hand$76;
			hand$57 = hand$75;
			hand$47 = hand$74;
			hand$37 = hand$73;
			hand$27 = hand$72;


			hand$56 = hand$65;
			hand$46 = hand$64;
			hand$36 = hand$63;
			hand$26 = hand$62;



			hand$45 = hand$54;
			hand$35 = hand$53;
			hand$25 = hand$52;

			hand$32 = hand$23;


			hand$KAs = hand$AKs;
			hand$QAs = hand$AQs;
			hand$JAs = hand$AJs;
			hand$TAs = hand$ATs;
			hand$9As = hand$A9s;
			hand$8As = hand$A8s;
			hand$7As = hand$A7s;
			hand$6As = hand$A6s;
			hand$5As = hand$A5s;
			hand$4As = hand$A4s;
			hand$3As = hand$A3s;
			hand$2As = hand$A2s;

			hand$QKs = hand$KQs;
			hand$JKs = hand$KJs;
			hand$TKs = hand$KTs;
			hand$9Ks = hand$K9s;
			hand$8Ks = hand$K8s;
			hand$7Ks = hand$K7s;
			hand$6Ks = hand$K6s;
			hand$5Ks = hand$K5s;
			hand$4Ks = hand$K4s;
			hand$3Ks = hand$K3s;
			hand$2Ks = hand$K2s;

			hand$JQs = hand$QJs;
			hand$TQs = hand$QTs;
			hand$9Qs = hand$Q9s;
			hand$8Qs = hand$Q8s;
			hand$7Qs = hand$Q7s;
			hand$6Qs = hand$Q6s;
			hand$5Qs = hand$Q5s;
			hand$4Qs = hand$Q4s;
			hand$3Qs = hand$Q3s;
			hand$2Qs = hand$Q2s;

			hand$TJs = hand$JTs;
			hand$9Js = hand$J9s;
			hand$8Js = hand$J8s;
			hand$7Js = hand$J7s;
			hand$6Js = hand$J6s;
			hand$5Js = hand$J5s;
			hand$4Js = hand$J4s;
			hand$3Js = hand$J3s;
			hand$2Js = hand$J2s;


			hand$9Ts = hand$T9s;
			hand$8Ts = hand$T8s;
			hand$7Ts = hand$T7s;
			hand$6Ts = hand$T6s;
			hand$5Ts = hand$T5s;
			hand$4Ts = hand$T4s;
			hand$3Ts = hand$T3s;
			hand$2Ts = hand$T2s;

			hand$89s = hand$98s;
			hand$79s = hand$97s;
			hand$69s = hand$96s;
			hand$59s = hand$95s;
			hand$49s = hand$94s;
			hand$39s = hand$93s;
			hand$29s = hand$92s;


			hand$78s = hand$87s;
			hand$68s = hand$86s;
			hand$58s = hand$85s;
			hand$48s = hand$84s;
			hand$38s = hand$83s;
			hand$28s = hand$82s;


			hand$67s = hand$76s;
			hand$57s = hand$75s;
			hand$47s = hand$74s;
			hand$37s = hand$73s;
			hand$27s = hand$72s;


			hand$56s = hand$65s;
			hand$46s = hand$64s;
			hand$36s = hand$63s;
			hand$26s = hand$62s;



			hand$45s = hand$54s;
			hand$35s = hand$53s;
			hand$25s = hand$52s;

			hand$32s = hand$23s;

	
	}


};