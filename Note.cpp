#include "Note.h"

Note::Note(const std::string &title, const std::string &text) : title(title), text(text) {
}

std::string Note::getTitle() const {
    return title;
}

std::string Note::getText() const {
    return text;
}

std::string Note::getCollectionName() const {
    return collectionName;
}

bool Note::isLocked() const {
    return locked;
}

bool Note::isImportant() const {
    return important;
}

void Note::setTitle(const std::string &newTitle) {
    title = newTitle;
}

void Note::setText(const std::string &newText) {
    text = newText;
}

void Note::setCollectionName(const std::string &newCollectionName) {
    collectionName = newCollectionName;
}

void Note::setLocked(bool newLocked) {
    locked = newLocked;
}

void Note::setImportant(bool newImportant) {
    important = newImportant;
}
