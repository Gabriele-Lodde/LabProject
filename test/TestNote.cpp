#include "gtest/gtest.h"
#include "../Note.h"

TEST(TestNote, DefaultState) {
    Note n("Programming", "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");

    EXPECT_EQ(n.getTitle(), "Programming");
    EXPECT_EQ(n.getText(), "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");
    EXPECT_FALSE(n.isLocked());
    EXPECT_FALSE(n.isImportant());
    EXPECT_EQ(n.getCollectionName(), "");
}

TEST(TestNote, LockUnlock) {
    Note n("Test_title", "Test_text");

    EXPECT_FALSE(n.isLocked());
    n.setLocked(!n.isLocked());
    EXPECT_TRUE(n.isLocked());
}

TEST(TestNote, ImportantNotImportant) {
    Note n("Test_title", "Test_text");

    EXPECT_FALSE(n.isImportant());
    n.setImportant(!n.isImportant());
    EXPECT_TRUE(n.isImportant());
}

TEST(TestNote, SetNoteTitle) {
    Note n("Programming", "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");
    EXPECT_EQ(n.getTitle(), "Programming");

    n.setTitle("Object-Oriented Programming");
    EXPECT_EQ(n.getTitle(), "Object-Oriented Programming");

    n.setLocked(!n.isLocked());
    n.setTitle("Programming");
    //EXPECT_EQ(n.getTitle(), "Programming");   //test fail
    EXPECT_EQ(n.getTitle(), "Object-Oriented Programming");
}

TEST(TestNote, SetNoteText) {
    Note n("Programming", "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");
    EXPECT_EQ(n.getText(), "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");

    n.setText("Object-Oriented Analysis is done before Object-Oriented Design");
    EXPECT_EQ(n.getText(), "Object-Oriented Analysis is done before Object-Oriented Design");

    n.setLocked(!n.isLocked());
    n.setText("MVC acronym is Model View Controller");
    //EXPECT_EQ(n.getText(), "MVC acronym is Model View Controller");   //test fail
    EXPECT_EQ(n.getText(), "Object-Oriented Analysis is done before Object-Oriented Design");
}