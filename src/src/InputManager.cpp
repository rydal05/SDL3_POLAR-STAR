#include "InputManager.h"

class Move : public Command {
public:
	void execute() {
        //checks pressed inputs and returns a range from -1 to 1 for the axis (this allows for smaller movements on joysticks that doesn't feel bad). This gets passed on to the acting entity which gets evaluated on command (rather than every microsecond).
	}
};

class Shoot : public Command {
public:
	void execute() {
        //creates a bullet at the position of the caller based on the current weapon identified by the caller. caller has a list of weapons in its arsenal. weapon contains all of its own data and how it interfaces with everyting
	}
};

class Bomb : public Command {
public:
	void execute() {
        //tentative 
	}
};

class L_Wep : public Command {
public:
	void execute() {
        //callee maintains weapon list of which this interfaces with and cycles left.
	}
};

class R_Wep : public Command {
public:
	void execute() {
        //callee maintains weapon list of which this interfaces with and cycles left.
	}
};