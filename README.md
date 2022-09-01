to use just create new empty project console and add all files.

the open simulator is a c ++ class that can be used in any project by simply creating a simulator object and using its functions and variables.

the actual entry point is start_simulation (nplayer), but any personal function can be created as an entry point, so you can use it as a dll for a bot or any project.

what it does is simulate the game of poker very quickly, so after writing the logic that decides the simulation, it writes HH to import into poker track or similar to analyze what happened, (works fine with pt 4.15.28)

so the current state of the is that it perfectly simulates and writes to HH every hand very quickly. (negligible error rate of 0.02% on multiple pot)

the real potential comes from manipulating simulations programmatically, so you can simulate anything with a little bit of code.

the best way to understand it is to insert a break point at the beginning in visual studio, then run a few hands and study the code, which however is only very simple native c ++ code (it's my first "serious" project with c ++)

things to do in the future:
- read oppl or ohf profiles
- create gui for manual game
- speed up even more

on a personal level it is something I do in my spare time for fun, so it may take many years to complete, however anyone who wants to participate is welcome.

# OpenSimulator
	
	srand(time(NULL));

	Ambient* simulator = new Ambient;
  
	simulator->start_simulation(6);
	delete simulator;
	


	for more details read here:
	http://www.maxinmontreal.com/forums/viewtopic.php?f=174&t=23376&p=167074#p167074
