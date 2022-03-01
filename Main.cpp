#pragma once
#include "Main.h"
#include <iostream>

int main() {
	//srand(time(NULL));
	srand(3);
	//std::cout.setstate(std::ios_base::failbit);



	Ambient* simulator = new Ambient;
	simulator->start_simulation(6);
	delete simulator;
	





};//main
