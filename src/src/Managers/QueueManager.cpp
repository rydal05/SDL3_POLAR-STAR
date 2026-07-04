#include "Managers/QueueManager.h"

Queue::Queue(){}

Queue::Queue(Queue const &){}

Queue Queue::operator=(Queue const &rhs){
    return *this;
}

Queue &Queue::getInstance(){
    static Queue *queue_instance = new Queue;
    return *queue_instance;
}