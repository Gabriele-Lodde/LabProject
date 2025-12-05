#include "Note.h"

Note::Note(const std::string &title, const std::string &text, bool locked, bool important) : title(title), text(text), locked(locked), important(important) {
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
