/* Math Tutor Verison 3
* Verison 3
 * Jacob Czapla and Elise Ruterbories
 * Section 1
 * https://github.com/Hassiakollo/math_tutor_version_2
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Define an enum for the math type
enum MathType {
    ADD = 1,
    SUB,
    MULT,
    DIV
};

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
        // Generate random numbers and math type
        leftNum = rand() % 10 + 1;  // Random number between 1 and 10
        rightNum = rand() % 10 + 1; // Random number between 1 and 10
        mathType = static_cast<MathType>(rand() % 4 + 1);  // Random math type between 1 and 4

        // testing default


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
                correctAnswer = leftNum;
            leftNum *= rightNum;
            mathSymbol = '/';
            break;

            default:
                cout << "Error! Wrong math type: " << mathType << endl;
            cout << "Program ended with a -1 error" << endl;
            cout << "Please contact support for help." << endl;
            return -1;
        }

        // Displays a question to the user
        cout << userName << " What is " << leftNum << " " << mathSymbol << " " << rightNum << " =  ";
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
        } else {
            cout << "Sorry. The correct answer was " << correctAnswer << ". Better luck next time, " << userName << "." << endl;
            // breaker before do-while
            // validates y, yes, n, no
            while (true) {
                cout << "Do you want to continue (y-yes | n-no)? ";
                getline(cin, userInput);
                for (int i = 0; i < userInput.size(); i++) {
                    userInput.at(i) = toupper(userInput.at(i)); //include ctype library for tolower
                }
                if (userInput == "y" || userInput == "yes" ||
                    userInput == "n" || userInput == "no") {
                    break;
                    } else {
                        cout << "Invalid input, please try again..." << endl;
                        cout << endl;
                    } while(userInput == "yes" || userInput == "y");


                // Closing message
                cout << "Thank you for playing the Silly Simple Math Tutor. Goodbye!" << endl;

                return 0;
            }
        }
    }while(userAnswer != correctAnswer);
}
