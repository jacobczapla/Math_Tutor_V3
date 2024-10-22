#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits> // for numeric_limits

using namespace std;

// Define an enum for the math type
enum MathType {
    ADD = 1,
    SUB,
    MULT,
    DIV
};

// Define constants
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;

int main() {
    // Declaring variables
    string userName; // Stores the user's full name
    int leftNum = 0;
    int rightNum = 0;
    MathType mathType; // Using enum instead of int
    char mathSymbol = ' ';
    int correctAnswer = 0;
    int userAnswer = 0;
    int temp = 0;
    string userInput;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1; // starts at level one
    int currentRange = LEVEL_RANGE_CHANGE; // range


    // Seed the random number generator for randomness
    srand(static_cast<unsigned int>(time(0)));

    cout << "***********************************************************" << endl;
    cout << "   __  __       _   _       _____      _           " << endl;
    cout << "   |  \\/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __ " << endl;
    cout << "   | |\\/| |/ _` | __| '_ \\    | || | | | __/ _ \\| '__|" << endl;
    cout << "   | |  | | (_| | |_| | | |   | || |_| | || (_) | |   " << endl;
    cout << "   |_|  |_|\\__,_|\\__|_| |_|   |_| \\__,_|\\__\\___/|_|   " << endl;
    cout << "***********************************************************" << endl;
    cout << "*      Welcome to the Silly Simple Math Tutor             *" << endl;
    cout << "***********************************************************" << endl;
    cout << " Fun math facts: " << endl;
    cout << "    * Math teachers have problems." << endl;
    cout << "    * Math is the only subject that counts." << endl;
    cout << "    * If it seems easy, you're doing it wrong." << endl;
    cout << "    * It's all fun and games until someone divides by zero!" << endl;
    cout << "***********************************************************" << endl;

    // Get userName
    cout << "Please enter your full name: ";
    getline(cin, userName);

    do {
        // Generate random numbers and math type based on current range
        leftNum = rand() % currentRange + 1;  // Random number between 1 and current range
        rightNum = rand() % currentRange + 1; // Random number between 1 and current range
        mathType = static_cast<MathType>(rand() % 4 + 1);  // Random math type between 1 and 4

        // Switch based on the enum MathType
        switch (mathType) {
            case ADD:  // Addition
                correctAnswer = leftNum + rightNum;
                mathSymbol = '+';
                break;

            case SUB:  // Subtraction
                // To make sure leftNum is greater than rightNum
                if (leftNum < rightNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAnswer = leftNum - rightNum;
                mathSymbol = '-';
                break;

            case MULT:  // Multiplication
                correctAnswer = leftNum * rightNum;
                mathSymbol = '*';
                break;

            case DIV:  // Division
                correctAnswer = leftNum; // Store leftNum for the answer
                leftNum *= rightNum;     // Ensure division results in a whole number
                mathSymbol = '/';
                break;

            default:
                cout << "Error! Wrong math type: " << mathType << endl;
                cout << "Program ended with a -1 error" << endl;
                cout << "Please contact support for help." << endl;
                return -1;
        }

        // Display the question to the user
        cout << userName << ", What is " << leftNum << " " << mathSymbol << " " << rightNum << " =  ";

        // Track attempts
        int attempts = 0;
        bool isCorrect = false;

        // Loop for MAX_ATTEMPTS
        while (attempts < MAX_ATTEMPTS) {
            // Loop until  the user enters numeric data
            while (!(cin >> userAnswer)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter a number: ";
            }

            // Check if the answer is correct
            if (userAnswer == correctAnswer) {
                cout << "Congrats! Nice job, " << userName << "!" << endl;
                totalCorrect++;
                isCorrect = true;
                break; // Correct answer, exit attempts loop
            } else {
                attempts++;
                if (attempts < MAX_ATTEMPTS) {
                    cout << "Sorry. Try again. Attempts left: " << MAX_ATTEMPTS - attempts << endl;
                }
            }
        }

        // After all attempts
        if (!isCorrect) {
            cout << "The correct answer was " << correctAnswer << ". Better luck next time, " << userName << "." << endl;
            totalIncorrect++;
        }

        // Ask if user wants to continue
        while (true) {
            cout << "Do you want to continue (y-yes | n-no)? ";
            cin >> userInput;
            for (int i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i)); // Convert to lowercase
            }
            if (userInput == "y" || userInput == "yes") {
                break;
            } else if (userInput == "n" || userInput == "no") {
                // Display final statistics
                cout << "Total Correct: " << totalCorrect << endl;
                cout << "Total Incorrect: " << totalIncorrect << endl;
                cout << "Thank you for playing the Silly Simple Math Tutor. Goodbye!" << endl;
                return 0;
            } else {
                cout << "Invalid input, please try again..." << endl;
            }
        }

        // Adjust math level and range
        if (totalCorrect > totalIncorrect) {
            mathLevel++;
            currentRange += LEVEL_RANGE_CHANGE;
            cout << "Nice Job! You've leveled up to level " << mathLevel << "!" << endl;
        } else if (totalIncorrect > totalCorrect) {
            mathLevel = max(1, mathLevel - 1); // Doesn't allow level to drop below 1
            currentRange = max(LEVEL_RANGE_CHANGE, currentRange - LEVEL_RANGE_CHANGE);
            cout << "You've leveled down to level " << mathLevel << ". Keep practicing!" << endl;
        }

    } while (true);
}
