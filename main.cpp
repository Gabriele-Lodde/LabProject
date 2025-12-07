#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "Note.h"
#include "Collection.h"

void printNoteMenu() {
    std::cout << "\033[1;33m" << std::string(50, '=') << "\033[0m\n";
    std::cout << "\033[1;36m                NOTE MANAGER MENU                 \033[0m\n";
    std::cout << "\033[1;33m" << std::string(50, '=') << "\033[0m\n\n";

    std::cout << "\033[1;32m1\033[0m. Create a note\n";
    std::cout << "\033[1;32m2\033[0m. Create a collection\n";
    std::cout << "\033[1;32m3\033[0m. Add a note to a collection\n";
    std::cout << "\033[1;32m4\033[0m. Remove a note from a collection\n";
    std::cout << "\033[1;32m5\033[0m. Toggle 'locked' option of a note\n";
    std::cout << "\033[1;32m6\033[0m. Toggle 'important' option of a note\n";
    std::cout << "\033[1;32m7\033[0m. Modify the title of a note\n";
    std::cout << "\033[1;32m8\033[0m. Modify the text of a note\n";
    std::cout << "\033[1;32m9\033[0m. Print all notes in a collection\n";
    std::cout << "\033[1;32m10\033[0m. Print all important notes\n";
    std::cout << "\033[1;32m11\033[0m. Print all collections\n";
    std::cout << "\033[1;32m0\033[0m. Exit\n\n";

    std::cout << "\033[1;36mSelect an option: \033[0m";

}

int selectNote(const std::vector<std::shared_ptr<Note>>& notes) {
    if (notes.empty()) {
        std::cout << "\033[1;31m\nNo notes available!\033[0m\n" << std::endl;
        return -1;
    }
    std::cout << "\n--Notes-- " << std::endl;
    for (int i = 0; i < notes.size(); i++) {
        std::cout << i+1 << "." << " Note title: " << notes[i]->getTitle()
                  << (notes[i]->isLocked() ? "  [LOCKED]" : "")
                  << (notes[i]->isImportant() ? " [IMPORTANT]" : "")
                  << "\n";
        std::cout << "   Note text: " << notes[i]->getText() << "\n" << std::endl;
    }
    std::cout << "Select note number: ";
    int index;
    if (!(std::cin >> index)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31m\nInvalid input! Please enter a number.\033[0m\n" << std::endl;
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (index < 1 || index > notes.size()) {
        std::cout << "\033[1;31m\nInvalid selection.\033[0m\n" << std::endl;
        return -1;
    }
    return index - 1;
}


int selectCollection(const std::vector<std::shared_ptr<Collection>>& collections) {
    if (collections.empty()) {
        std::cout << "\033[1;31m\nNo collections available!\033[0m\n" << std::endl;
        return -1;
    }
    std::cout << "\n--Collections-- " << std::endl;
    for (int i = 0; i < collections.size(); ++i) {
        std::cout << i+1 << ". Collection name: " << collections[i]->getName() << "\n" << std::endl;
    }
    std::cout << "\nSelect collection number: ";
    int index;
    if (!(std::cin >> index)) { //check numeric input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[1;31m\nInvalid input! Please enter a number.\033[0m\n" << std::endl;
        return -1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (index < 1 || index > collections.size()) {
        std::cout << "\033[1;31m\nInvalid selection.\033[0m\n" << std::endl;
        return -1;
    }
    return index-1;
}

int main() {
    int choice;
    std::vector<std::shared_ptr<Note>> allNotes; //vector with all notes created
    std::vector<std::shared_ptr<Collection>> allCollections; //vector with all collections created
    do {
        printNoteMenu();
        std::cin >> choice;
        //Input validation
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31m\nInvalid input! Please enter a number.\033[0m\n" << std::endl;
            choice = -1;
            continue; // Restart menu
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1: { //Note creation
                std::string title, text;
                std::cout <<"Enter title: ";
                std::getline(std::cin, title);
                std::cout <<"Enter text: ";
                std::getline(std::cin, text);
                auto note = std::make_shared<Note>(title, text);
                allNotes.push_back(note);
                std::cout << "\033[1;32m\nNote created!\033[0m\n" << std::endl;
                break;
            }
            case 2: { //Collection creation
                std::string name;
                std::cout <<"Enter collection name: ";
                std::getline(std::cin, name);
                auto collection = std::make_shared<Collection>(name);
                allCollections.push_back(collection);
                std::cout << "\033[1;32m\nCollection created!\033[0m\n" << std::endl;
                break;
            }
            case 3: { //Adding a note to a collection
                if (allCollections.empty()) {
                    std::cout << "\033[1;31m\nNo collections available.\033[0m\n" << std::endl;
                    break;
                }
                int n = selectNote(allNotes);
                if (n == -1)
                    break;
                int num_collection = selectCollection(allCollections);
                if (num_collection == -1)
                    break;
                allCollections[num_collection]->addNote(allNotes[n]);
                break;
            }
            case 4: { //Removing a note from a collection
                int num_collection = selectCollection(allCollections);
                if (num_collection == -1) break;
                const auto& coll = allCollections[num_collection];
                if (coll->getSize() == 0) {
                    std::cout << "\033[1;31m\nThis collection is empty!\033[0m\n" << std::endl;
                    break;
                }
                coll->printAllNotes();
                std::cout << "Select note number to remove: ";
                int index;
                std::cin >> index;
                if (std::cin.fail() || index < 1 || index > coll->getSize()) {
                    std::cout << "\033[1;31m\nInvalid number!\033[0m\n" << std::endl;
                    break;
                }
                auto note = coll->getNoteAt(index);
                allCollections[num_collection]->removeNote(note);
                break;
            }
            case 5: { //Toggle the 'locked' option of a note
                int n=selectNote(allNotes);
                if (n==-1)
                    break;
                allNotes[n]->setLocked(!allNotes[n]->isLocked());
                std::cout << "\033[1;32m\nLock toggled!\033[0m\n" << std::endl;
                break;
            }
            case 6: { //Toggle the 'important' option of a note
                int n=selectNote(allNotes);
                if (n==-1)
                    break;
                allNotes[n]->setImportant(!allNotes[n]->isImportant());
                std::cout << "\033[1;32m\nImportant flag toggled!\033[0m\n" << std::endl;
                break;
            }
            case 7: { //Changing the title of a note
                int n=selectNote(allNotes);
                if (n==-1)
                    break;
                if (allNotes[n]->isLocked()) {
                    std::cout << "\033[1;31m\nUnable to edit title: note locked!\033[0m\n" << std::endl;
                    break;
                }
                std::string newTitle;
                std::cout <<"Enter new title: ";
                std::getline(std::cin, newTitle);
                allNotes[n]->setTitle(newTitle);
                std::cout << "\033[1;32m\nTitle changed!\033[0m\n" << std::endl;
                break;
            }
            case 8: { //Changing the text of a note
                int n=selectNote(allNotes);
                if (n==-1)
                    break;
                if (allNotes[n]->isLocked()) {
                    std::cout << "\033[1;31m\nUnable to edit text: note locked!\033[0m\n" << std::endl;
                    break;
                }
                std::string newText;
                std::cout <<"Enter new text: ";
                std::getline(std::cin, newText);
                allNotes[n]->setText(newText);
                std::cout<<"\033[1;32m\nText changed!\033[0m\n" << std::endl;
                break;
            }
            case 9: { //Print all notes in a collection
                int num_collection = selectCollection(allCollections);
                if (num_collection == -1)
                    break;
                if (allCollections[num_collection]->getSize() == 0) {
                    std::cout << "\033[1;34m" << allCollections[num_collection]->getName() << " is empty!\033[0m\n" << std::endl;
                    break;
                }
                std::cout<<"\nCollection name: "<<allCollections[num_collection]->getName() << std::endl;
                allCollections[num_collection]->printAllNotes();
                break;
            }
            case 10: { //Print all important notes
                if (allCollections.empty()) {
                    std::cout << "\033[1;31m\nNo collections available.\033[0m\n" << std::endl;
                    break;
                }
                bool foundImportant = false;
                for (const auto& collection : allCollections) {
                    foundImportant=collection->printAllImportantNotes();
                }
                if (!foundImportant)
                    std::cout << "\033[1;31m\nNo important notes found in any collection.\033[0m\n" << std::endl;
                break;
            }
            case 11: { //Print all collections
                if (allCollections.empty()) {
                    std::cout << "\033[1;31m\nNo collections available!\033[0m\n" << std::endl;
                    break;
                }
                for (const auto& collection : allCollections) {
                    std::cout<<"\nCollection name: " << collection->getName() <<std::endl;
                    if (collection->getSize() == 0)
                        std::cout << "\033[1;34m" << collection->getName() << " is empty!\033[0m\n" << std::endl;
                    else {
                        collection->printAllNotes();
                    }
                }
                break;
            }
            case 0:
                std::cout << "\033[1;34m\nThank you for using this program!\033[0m" << std::endl;
                break;
            default:
                std::cout<<"\033[1;31m\nPlease enter a valid option!\033[0m\n" << std::endl;
        }
    } while (choice != 0);
    return 0;
}