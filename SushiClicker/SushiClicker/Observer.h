#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

class ISushiObserver {
public:
    virtual void onSushiChange(int newSushi) = 0;
};

class ISushiSubject {
private:
    std::vector<ISushiObserver*> observers;

public:
    ISushiSubject(){}

    void addObserver(ISushiObserver* observer);
    void removeObserver(ISushiObserver* observer);
    void raiseSushiChanged(int newScore);
};

#endif