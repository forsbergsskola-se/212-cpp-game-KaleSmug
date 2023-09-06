#include "Observer.h"

void ISushiSubject::addObserver(ISushiObserver* observer) {
    observers.push_back(observer);
}

void ISushiSubject::removeObserver(ISushiObserver* observer) {
    
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void ISushiSubject::raiseSushiChanged(int newScore) {

    for (ISushiObserver* observer : observers) {
        observer->onSushiChange(newScore);
    }
}
