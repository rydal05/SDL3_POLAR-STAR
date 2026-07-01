#include "InputHandler.hpp"
#include "Command.hpp"

Command* command = InputHandler.handleInput();
if(command){
    command->execute(actor);
}