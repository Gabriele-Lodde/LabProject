#ifndef COLLECTION_H
#define COLLECTION_H
#include <memory>
#include <string>

class Note;
#include "Subject.h"


class Collection : public Subject {
public:
    explicit Collection(const std::string& n);

    std::string getName() const;
    int getSize() const;
    void addNote(std::shared_ptr<Note>& note);
    void removeNote(std::shared_ptr<Note>& note);
    void printAllNotes() const;
    std::shared_ptr<Note> getNoteAt(int index) const;

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyAll() override;

private:
    void initObserver();
    std::string name;
    std::list<std::shared_ptr<Note>> notes;
    std::unique_ptr<Observer> sizeObserver;
};


#endif //COLLECTION_H
