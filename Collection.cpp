#include "Collection.h"

Collection::Collection(const std::string &n) : Collection(n) {
}

std::string Collection::getName() const {
    return name;
}

int Collection::size() const {
    return notes.size();
}

bool Collection::addNote(std::shared_ptr<Note> note) {
    if (note != nullptr) {
        notes.push_back(note);
        notifyAll();
        return true;
    }
    return false;
}

bool Collection::removeNote(std::shared_ptr<Note> note) {
    auto it=std::find(notes.begin(), notes.end(), note);
    if (it == notes.end())
        return false;
    if ((*it)->isLocked()) //Don't remove the note if it's locked
        return false;
    notes.erase(it);
    notifyAll();
    return true;
}

void Collection::addObserver(Observer *o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer *o) {
    observers.remove(o);
}

void Collection::notifyAll() {
    for (auto observer: observers)
        observer->update();
}
