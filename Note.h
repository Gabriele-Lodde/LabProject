#ifndef NOTE_H
#define NOTE_H
#include <memory>
#include <string>

class Collection;


class Note {
public:
    Note(const std::string& title, const std::string& text);

    std::string getTitle() const;
    std::string getText() const;
    std::string getCollectionName() const;
    bool isLocked() const;
    bool isImportant() const;
    void printNote() const;

    void setTitle(const std::string& newTitle);
    void setText(const std::string& newText);
    void setCollectionName(const std::string& newCollectionName);
    void setLocked(bool newLocked);
    void setImportant(bool newImportant);

private:
    std::string title;
    std::string text;
    std::string collectionName;
    bool locked{false};
    bool important{false};
};

#endif //NOTE_H
