#include <iostream>
#include <string>

using namespace std;

// The addQuestion function will ask the user to input their question and
// answer.
void addQuestion() {
  string str, answer;
  cout << "Please enter your question: ";
  getline(cin, str);
  cout << "Please enter the answer: ";
  getline(cin, answer);
  cout << "Question added!" << endl;
}
/*This program will reapteadly ask the user to input a question or exit. If the
user inputs something other than a or b (capital letters too), they will be
notified with an error message, but will then be asked again what option they
would like to choose.*/
int main() {
  char choice;
  cout << "Welcome to QuizMaker\n";
  cout << endl;
  cout << "What would you like to do?\n";
  cout << "a. Create a question\n";
  cout << "b. Quit\n";
  cout << "Choice: ";
  cin >> choice;
  cin.ignore();

  do {
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
      cin.ignore();
      break;
    case 'b':
    case 'B':
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
      cin.ignore();
    }
  } while (choice != 'b' && choice != 'B');
  cout << endl;
  cout << "Thank you for using QuizMaker!" << endl;
  return 0;
}
