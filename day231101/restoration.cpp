#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Memento contains the state to be restored.
class Memento {
private:
    string state;

public:
    Memento(string state) {
        this->state = state;
    }

    string getState() {
        return state;
    }
};

// Originator creates and stores the state in Memento
class Originator {
private:
    string state;

public:
    Originator(string state) {
        this->state = state;
    }

    string getState() {
        return state;
    }

    void setState(string state) {
        this->state = state;
    }

    Memento saveStateToMemento() {
        return Memento(state);
    }

    void getStateFromMemento(Memento memento) {
        state = memento.getState();
    }
};

// Caretaker is responsible for restoring state from Memento
class Caretaker {
private:
    vector<Memento> mementoList;

public:
    void add(Memento memento) {
        mementoList.push_back(memento);
    }

    Memento get(int index) {
        return mementoList[index];
    }
};

int main() {
    Originator *originator = new Originator("State#0");
    Caretaker *caretaker = new Caretaker();

    // originator->getStateFromMemento(caretaker->get(0)); // This line will cause an error

    originator->setState("State#1");
    originator->setState("State#2");
    caretaker->add(originator->saveStateToMemento());
    originator->setState("State#3");
    caretaker->add(originator->saveStateToMemento());
    originator->setState("State#4");
    cout << "Current state: " << originator->getState() << endl;
    originator->getStateFromMemento(caretaker->get(0));
    cout << "First saved State: " << originator->getState() << endl;
    originator->getStateFromMemento(caretaker->get(1));
    cout << "Second saved State: " << originator->getState() << endl;

    return 0;
}
