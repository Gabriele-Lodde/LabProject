#include "gtest/gtest.h"
#include "../Collection.h"
#include "../Note.h"

TEST(TestCollection, DefaultState) {
    Collection c("University");

    EXPECT_EQ(c.getName(), "University");

}

TEST(TestCollection, AddNote) {
    Collection c("University");
    auto n = std::make_shared<Note>("Programming", "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");

    c.addNote(n);
    EXPECT_EQ(c.getSize(), 1);
    EXPECT_EQ(n->getCollectionName(), "University");
}

TEST(TestCollection, RemoveNote) {
    Collection c("University");
    auto n = std::make_shared<Note>("Programming", "If there is at least one virtual method in a c++ class, then the destructor must be virtual!");

    c.addNote(n);
    EXPECT_EQ(c.getSize(), 1);
    EXPECT_EQ(n->getCollectionName(), "University");

    c.removeNote(n);
    EXPECT_EQ(c.getSize(), 0);
    EXPECT_EQ(n->getCollectionName(), "");
}

TEST(TestCollection, CannotAddNoteInAnotherCollection) {
    Collection c1("A");
    Collection c2("B");
    auto n = std::make_shared<Note>("Test_title", "Test_text");

    c1.addNote(n);
    testing::internal::CaptureStdout();
    c2.addNote(n);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(c2.getSize(), 0);
    EXPECT_NE(output.find("is already in"), std::string::npos);   //if the output of c2.addNote(n) contains "is already in",
                                                                                        //then the test passes, otherwise it fails
}

TEST(TestCollection, CannotRemoveNoteIfItIsLocked) {
    Collection c("A");
    auto n = std::make_shared<Note>("Test_title", "Test_text");
    c.addNote(n);
    EXPECT_EQ(c.getSize(), 1);

    n->setLocked(!n->isLocked());
    testing::internal::CaptureStdout();
    c.removeNote(n);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(c.getSize(), 1);
    EXPECT_NE(output.find("Unable to remove"), std::string::npos);   //if the output of c.removeNote(n) contains "Unable to remove",
                                                                       //then the test passes, otherwise it fails
}

TEST(TestCollection, CannotRemoveNoteIfItIsNotInTheCollection) {
    Collection c("A");
    auto n = std::make_shared<Note>("Test_title", "Test_text");
    EXPECT_EQ(c.getSize(), 0);

    testing::internal::CaptureStdout();
    c.removeNote(n);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(c.getSize(), 0);
    EXPECT_NE(output.find("not found in"), std::string::npos);   //if the output of c.removeNote(n) contains "not found in",
                                                                                    //then the test passes, otherwise it fails
}