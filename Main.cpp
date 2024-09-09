#pragma once
#include "Main.h"
#include "Ambient.h"


int main() {
	srand(time(NULL));
	//srand(1);

		Ambient* simulator = new Ambient;
		//simulator->SimulateCash();
		simulator->Simulate_Tournaments();
		delete simulator;
	

	return 0;




};//main
