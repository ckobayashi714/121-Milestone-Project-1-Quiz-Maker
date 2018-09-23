#include <iostream>
#include <string>

using namespace std;

// Here the addQuestion function will ask the user to input their information.
void addQuestion() {
  cout << "Please enter your question: ";
  cout << "Please enter the answer: ";
  cout << "Question added!" << endl;
}

int main() {
  char choice;
  cout << "Welcome to QuizMaker\n";
  cout << endl;
  cout << "What would you like to do?\n";
  cout << "a. Create a question\n";
  cout << "b. Quit\n";
  cout << "Choice: ";
  cin >> choice;

  while (choice != 'b' && choice != 'B') {
    switch (choice) {
    case 'a':
    case 'A':
      cout << endl;
      addQuestion();
      cout << endl;
      cout << "What would you like to do?" << endl;
      cout << "a. Create a question" << endl;
      cout << "b. Quit" << endl;
      cout << "Choice: ";
      cin >> choice;
      break;
    default:
      cout << endl;
      cout << "Invalid option\n";
      cout << endl;
      cout << "What would you like to do?" << endl;
      cout << "a. Create a question" << endl;
      cout << "b. Quit" << endl;
      cout << "Choice: ";
      cin >> choice;
    }
  }
  cout << endl;
  cout << "Thank you for using QuizMaker!" << endl;
  return 0;
}
