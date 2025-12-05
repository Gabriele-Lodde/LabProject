#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyAll() = 0;
protected:
    std::list <Observer*> observers;
};

#endif //SUBJECT_H
