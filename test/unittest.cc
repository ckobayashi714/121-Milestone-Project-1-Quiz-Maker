#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include "gtest_ext.h"
using ::testing::HasSubstr;
using ::testing::StartsWith;
using ::testing::ContainsRegex;

TEST(Milestone1, FiniteChoiceLoop) {
  srand (time(NULL));
  ASSERT_TIMED_BLOCK_START("Choice", 10000);
  main_output("quizgen", "a\nX\nX\nb");
  ASSERT_TIMED_BLOCK_END();
}

TEST(Milestone1, CreateQuestionChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nPlease enter your question: Please enter the "
                         "answer: Question added!\n";
  ASSERT_MAIN_OUTPUT_THAT("quizgen", "a\nX\nX\nb", StartsWith(expected));
}

TEST(Milestone1, QuitChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nThank you for using QuizMaker!\n";
  ASSERT_MAIN_OUTPUT_EQ("quizgen", "b", expected);
}

TEST(Milestone1, InvalidOptionChoice) {
  std::string expected = "Welcome to QuizMaker\n\nWhat would you like to do?\n"
                         "a. Create a question\nb. Quit\nChoice: "
                         "\nInvalid option";
  ASSERT_MAIN_OUTPUT_THAT("quizgen", "x\nb", StartsWith(expected));
}

TEST(Milestone1, ChoiceLoopLowercase) {
  int repetitions = rand() % 10 + 1;
  for (int i = 0; i < repetitions; i++) {
    std::string input = "";
    std::string expected = "Welcome to QuizMaker\n\n";
    char choice;
    do {
      choice = rand() % 3 + 97;
      expected += "What would you like to do?\na. Create a question\nb. Quit\n"
                  "Choice: \n";
      std::string s_choice(1, choice);
      input += s_choice + "\\n";
      switch (choice) {
        case 'a':
          expected += "Please enter your question: Please enter the answer: "
                      "Question added!\n\n";
          input += "q\\na\\n";
          break;
        case 'b':
          expected += "Thank you for using QuizMaker!\n";
          break;
        default:
          expected += "Invalid option\n\n";
      }
    } while(choice!= 'b');
    ASSERT_MAIN_OUTPUT_EQ("quizgen", input, expected);
  }
}

TEST(Milestone1, ChoiceLoopUppercase) {
  int repetitions = rand() % 10 + 1;
  for (int i = 0; i < repetitions; i++) {
    std::string input = "";
    std::string expected = "Welcome to QuizMaker\n\n";
    char choice;
    do {
      choice = rand() % 3 + 65;
      expected += "What would you like to do?\na. Create a question\nb. Quit\n"
                  "Choice: \n";
      std::string s_choice(1, choice);
      input += s_choice + "\\n";
      switch (choice) {
        case 'A':
          expected += "Please enter your question: Please enter the answer: "
                      "Question added!\n\n";
          input += "q\\na\\n";
          break;
        case 'B':
          expected += "Thank you for using QuizMaker!\n";
          break;
        default:
          expected += "Invalid option\n\n";
      }
    } while(choice!= 'B');
    ASSERT_MAIN_OUTPUT_EQ("quizgen", input, expected);
  }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
