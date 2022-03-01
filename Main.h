#pragma once

enum class State { Blinds, Fold, Check, Call, Bet, Raise, Allin, Call_Allin, Forced_Allin, null, None, Out };
enum class Position { Early1, Early2, Early3, Middle1, Middle2, Middle3, CutOff, Button, SB, BB, Middle, Early, null };

#include <iostream>
#include <time.h>
#include "Ambient.h"

using namespace std;
