#include "Collection.h"
#include "Note.h"
#include <iostream>
#include <algorithm>

#include "CollectionSizeObserver.h"

Collection::Collection(const std::string &n) : name(n) {
    initObserver();
}

void Collection::initObserver() {
    sizeObserver = std::make_unique<CollectionSizeObserver>(this);
}

std::string Collection::getName() const {
    return name;
}

int Collection::getSize() const {
    return notes.size();
}

void Collection::addNote(std::shared_ptr<Note>& note) {
    if (note == nullptr) {
        std::cout << "\033[1;31m\nInvalid note.\033[0m\n\n";
    }
    else if (!note->getCollectionName().empty() && note->getCollectionName() != name) {
        std::cout << "\033[1;31m\nNote '" << note->getTitle() << "' is already in '" << name << "' (another) collection!\033[0m\n\n";
    }
    else if (!note->getCollectionName().empty() && note->getCollectionName() == name) {
        std::cout << "\033[1;31m\nNote '" << note->getTitle() << "' is already in '" << name << "' (this) collection!\033[0m\n\n";
    }
    else {
        notes.push_back(note);
        note->setCollectionName(name);
        notifyAll();
        std::cout << "\033[1;32mNote '" << note->getTitle() << "' added to '" << name << "' collection!\033[0m\n" << std::endl;
    }
}

void Collection::removeNote(std::shared_ptr<Note>& note) {
    auto it=std::find(notes.begin(), notes.end(), note);
    if (it == notes.end()) {
        std::cout << "\033[1;31m\nNote '" << note->getTitle() << "' not found in '" << name << "' collection!\033[0m\n\n";
    }
    else if ((*it)->isLocked()) {
        std::cout << "\033[1;31m\nUnable to remove: note '" << note->getTitle() << "' is locked!\033[0m\n\n";
    }
    else {
        notes.erase(it);
        note->setCollectionName("");
        notifyAll();
        std::cout << "\033[1;32mNote '" << note->getTitle() << "' removed from '" << name << "' collection!\033[0m\n" << std::endl;
    }
}

void Collection::printAllNotes() const {
    int i=1;
    for (const auto&  note : notes) {
        std::cout << i << "." << std::endl;
        note->printNote();
        i++;
    }
}

std::shared_ptr<Note> Collection::getNoteAt(int index) const {
    if (index < 1 || index > notes.size())
        return nullptr;
    auto it = notes.begin();
    std::advance(it, index-1);
    return *it;
}

void Collection::addObserver(Observer* o) {
    observers.push_back(o);
}

void Collection::removeObserver(Observer* o) {
    observers.remove(o);
}

void Collection::notifyAll() {
    for (auto observer: observers) {
        observer->update();
    }
}
