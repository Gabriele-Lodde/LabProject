#include "Note.h"

Note::Note(const std::string &title, const std::string &text) : title(title), text(text) {
}

std::string Note::getTitle() const {
    return title;
}

std::string Note::getText() const {
    return text;
}

bool Note::isLocked() const {
    return locked;
}

bool Note::isImportant() const {
    return important;
}

std::shared_ptr<Collection> Note::getCollection() const {
    return collection;
}

void Note::setLocked(bool newLocked) {
    locked = newLocked;
}

void Note::setImportant(bool newImportant) {
    important = newImportant;
}

bool Note::setTitle(const std::string &newTitle) {
    if (locked)
        return false;
    title = newTitle;
    return true;
}

bool Note::setText(const std::string &newText) {
    if (locked)
        return false;
    text = newText;
    return true;
}

void Note::setCollection(const std::shared_ptr<Collection>& newCollection) {
    collection = newCollection;
}
