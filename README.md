# QuizMaker Project Milestone 1
This is milestone 1 of the [QuizMaker Project](https://docs.google.com/document/d/1kxz9GX_Fm1rGeQZCyvOVQ7Szpre8MZwEgXG5zyMIcI8/edit?usp=sharing).

# Requirements
Develop a menu-based command-line interface (CLI) that repeatedly asks a user to input a question and answer until the option to exit is used. Kindly refer to the sample runs below and follow the output as closely as possible.

```
Welcome to QuizMaker

What would you like to do?
a. Create a question
b. Quit
Choice: a

Please enter your question: Who is the mother of the COBOL programming language?
Please enter the answer: Grace Hopper
Question added!

What would you like to do?
a. Create a question
b. Quit
Choice: x

Invalid option

What would you like to do?
a. Create a question
b. Quit
Choice: b

Thank you for using QuizMaker!
```

Create the `addQuestion` function that will be responsible for asking the user to input a single question and answer pair. For now, your code will not store the questions and their answers. This function is only for producing the interface.

Design your `main` function so that it asks the user to choose between creating a question or exiting the program. It should call the `addQuestion` function when the user asks to create a question and exits otherwise.

# Deadline
September 21, 11:59pm
