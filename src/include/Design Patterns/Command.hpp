/*
Interface with a single method that doesn't return anything
typically it's a Command pattern.
*/
class Command{
    public:
    virtual ~Command() {}
    virtual void execute(GameActor &actor) = 0;
};

class JumpCommand : public Command {
    public:
    virtual void execute(GameActor &actor) { actor.jump(); }
};

class FireCommand : public Command{
    public:
    virtual void execute(GameActor &actor) { actor.fireGun(); }
};

//etc


//NULL Object
class NullCommand : public Command{
    public:
    virtual void execute() { /*do nothing*/ }
};

//avoid having a bunch of different command classes
//it's easier to implement those but defining a concrete base class which convienient high level methods to operate with
// exeucte() -> Subclass Sandbox