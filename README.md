# OpenSimulator

#include "Main.h"
#include <iostream>

int main() {
	srand(time(NULL));

	Ambient* simulator = new Ambient;
  
	simulator->start_simulation(6);
	delete simulator;
	

};//main
