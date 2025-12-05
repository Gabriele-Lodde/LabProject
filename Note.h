#ifndef NOTE_H
#define NOTE_H
#include <string>


class Note {
public:
    //Constructor
    Note(const std::string& title, const std::string& text);

    //Getter
    std::string getTitle() const;
    std::string getText() const;
    bool isLocked() const;
    bool isImportant() const;

    //Setter of locked and important
    void setLocked(bool newLocked);
    void setImportant(bool newImportant);

    //Setter of title and text (they return false if the note is blocked)
    bool setTitle(const std::string& newTitle);
    bool setText(const std::string& newText);

private:
    std::string title;
    std::string text;
    bool locked{false};
    bool important{false};
};

#endif //NOTE_H
