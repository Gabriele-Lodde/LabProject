#ifndef COLLECTION_H
#define COLLECTION_H
#include <memory>
#include <algorithm>
#include <string>

#include "Note.h"
#include "Subject.h"


class Collection : public Subject {
public:
    //Constructor
    explicit Collection(const std::string& n);

    //Collection methods
    std::string getName() const;
    int getSize() const;
    bool addNote(const std::shared_ptr<Note>& note);
    bool removeNote(const std::shared_ptr<Note>& note);

    //Subject interface
    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyAll() override;

private:
    std::string name;
    std::list<std::shared_ptr<Note>> notes;
};



#endif //COLLECTION_H
