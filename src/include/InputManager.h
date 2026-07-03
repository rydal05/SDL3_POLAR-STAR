#ifndef INPUT_MANANGER_H
#define INPUT_MANAGER_H


class Command {
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class InputHandler {
public:
	void handleInput();
private:
	Command *buttonX_;
	Command *buttonY_;
	Command *buttonA_;
	Command *buttonB_;
};

#endif