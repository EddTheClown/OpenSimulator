#pragma once
#include "Ambient.h"
#include "Player.h"


class Simulator :
    public Ambient
{
    void create_new_deck(vector<Player> _p);
public:
    Simulator();
    ~Simulator() {
    }
    void set_PlayerVar(vector<Player> _p, int _myposition);
    int start_hand(int _TestDecision, int _index);
    int EVActions[100] = {0};

    int CountActionSimulations(int _TestDecision, int _myposition, string Evento);
    int ContaFrequenzaEventi(string Evento);

    bool bPlayerAct = false;
    int initialFolds = 0;
    int initialCalls = 0;
    int initialRaises = 0;
    int initialChecks = 0;
    int initialAllins = 0;
    void SetInitialActions();
};

