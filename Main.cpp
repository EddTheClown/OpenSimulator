#pragma once
#include "Main.h"

int main() {
	srand(time(NULL));

	Ambient* simulator = new Ambient;
	simulator->start_simulation(6);
	delete simulator;
	


	return 0;




};//main
