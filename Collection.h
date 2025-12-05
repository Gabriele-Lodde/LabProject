#ifndef COLLECTION_H
#define COLLECTION_H
#include <memory>
#include <algorithm>
#include <string>

#include "Note.h"
#include "Subject.h"


class Collection : public Subject, std::enable_shared_from_this<Collection> { //Multiple inheritance because I used shared_from_this() in addNote()
public:
    //Constructor
    explicit Collection(const std::string& n);

    //Collection methods
    std::string getName() const;
    int getSize() const;
    void addNote(std::shared_ptr<Note> note);
    void removeNote(std::shared_ptr<Note> note);
    void printAllImportantNotes() const;
    void printAllNotes() const;

    //Subject interface
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyAll() override;

private:
    std::string name;
    std::list<std::shared_ptr<Note>> notes;
};



#endif //COLLECTION_H
