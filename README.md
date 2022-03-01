# OpenSimulator

#include "Main.h"
#include <iostream>	
	
int main() {
	
	srand(time(NULL));

	Ambient* simulator = new Ambient;
  
	simulator->start_simulation(6);
	delete simulator;
	

};//main

	topic: 
	http://www.maxinmontreal.com/forums/viewtopic.php?f=174&t=23376&p=167074#p167074
