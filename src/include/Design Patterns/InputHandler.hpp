class InputHandler {
public:
	void handleInput();

private:
	Command *buttonX_;
	Command *buttonY_;
	command *buttonA_;
    Command *buttonB_;
};

InputHandler::handleInput(){
    if(isPressed(BUTTON_X)) buttonX_>execute();
    else if(isPressed(BUTTON_Y)) buttonY_->execute();
    else if(isPressed(BUTTON_A)) buttonA_->execute();
    else if(isPressed(BUTTON_B)) buttonB_->execute();

    // nothing pressed, do nothing
    return NULL;
}