#include "Collection.h"

#include <iostream>

Collection::Collection(const std::string &n) : name(n) {
}

std::string Collection::getName() const {
    return name;
}

int Collection::getSize() const {
    return notes.size();
}

void Collection::addNote(std::shared_ptr<Note> note) {
    if (note == nullptr) {
        //.......stampa errore
    }

    else if (note->getCollection() != nullptr && note->getCollection() != shared_from_this()) {
        //......stampa errore
    }
    else {
        notes.push_back(note);
        note->setCollection(this);
        notifyAll();
        //......stampa tutto ok
    }
}

void Collection::removeNote(std::shared_ptr<Note> note) {
    auto it=std::find(notes.begin(), notes.end(), note);
    if (it == notes.end()) {
        //.......stampa errore
    }
    else if ((*it)->isLocked()) { //Don't remove if it's locked
        //...stampa errore
    }
    else {
        notes.erase(it);
        note->setCollection(nullptr);
        notifyAll();
        //....stampa tutto ok
    }
}

void Collection::printAllImportantNotes() const {
    for (auto note: notes) {
        if (note->isImportant()) {
            std::cout<<"Note title: " << note->getTitle()<<std::endl;
            std::cout<<"Note text: \n" << note->getText()<<std::endl;
        }
    }
}

void Collection::printAllNotes() const {
    for (auto note: notes) {
        std::cout<<"Note title: " << note->getTitle()<<std::endl;
        std::cout<<"Note text: \n" << note->getText()<<std::endl;
    }
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
