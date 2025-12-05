#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "Note.h"
#include "Collection.h"

void printNoteMenu() {
    std::cout << "\033[33;40m" << std::string(60, '=') << "\033[0m" << std::endl;
    std::cout << "=== Note Manager Menu ====" << std::endl;
    std::cout << "1. Create a note" << std::endl;
    std::cout << "2. Create a collection" << std::endl;
    std::cout << "3. Modify the 'locked' option of a note" << std::endl;
    std::cout << "4. Modify the 'important' option of a note" << std::endl;
    std::cout << "5. Modify the title of the note" << std::endl;
    std::cout << "6. Modify the text of the note" << std::endl;
    std::cout << "7. Add a note to a collection" << std::endl;
    std::cout << "8. Remove a note from a collection" << std::endl;
    std::cout << "9. Print all notes of a collection" << std::endl;
    std::cout << "10. Print all important notes" << std::endl;
    std::cout << "11. Print all collections" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "\033[33;40m" << std::string(60, '=') << "\033[0m\n" << std::endl;
    std::cout << "Select an option: ";
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
            std::cout << "\033[1;31mInvalid input! Please enter a number.\033[0m\n\n";
            choice = -1;
            continue; // Restart menu
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice) {
            case 1: {
                std::string title, text;
                std::cout <<"Enter title: ";
                std::getline(std::cin, title);
                std::cout <<"Enter text: ";
                std::getline(std::cin, text);
                Note note(title, text);
                std::cout<<"Title: " << note.getTitle() << std::endl;
                std::cout<<"Text: " << note.getText() << std::endl;
                std::cout << "\033[1;32mNote created!\033[0m\n" << std::endl;
                break;
            }
            case 2: {
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                break;
            }
            case 8:{
                break;
            }
            case 9:{
                break;
            }
            case 10:{
                break;
            }
            case 0:
                std::cout << "\033[1;34mThank you for using this program!\033[0m" << std::endl;
                break;
            default:
                std::cout<<"\033[1;31mPlease enter a valid option!\033[0m\n"<<std::endl;
        }
    } while (choice != 0);
    return 0;
}