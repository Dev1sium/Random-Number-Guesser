//Initialise preinstalled libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
using namespace std;

//Initialise variables
int randomNumber;
int guess;
int attempt = 0;
int maxAttempts = 10; //Default max attempts of 10
int difficulty;
int chance;
string selection;

int starting() { //Setup for program to show "Starting in 3... 2... 1..."
    cout << endl << "Good luck!" << endl;
    _sleep(1000);

    cout << endl << "Starting in 3...";
    _sleep(1000);
    cout << " 2...";
    _sleep(1000);
    cout << " 1..." << endl;
    _sleep(1000);

    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    return 0;
}

int welcome() { //Welcoming text and ruleset for the game & generates random number
    cout << "Welcome to the game!" << endl;
    _sleep(1000);

    cout << endl << "Rules:" << endl;
    cout << "Your job as the guesser, is to guess a number between 1 and 100." << endl;
    cout << "Should you correctly guess the number, you win the game." << endl;
    cout << "You have a maximum of " << maxAttempts << " attempts." << endl;
    _sleep(3000);

    return 0;
}

int selectionRepeat() { //Asks user for difficulty, Used incase improper userinput
    cout << endl << "There are 3 difficulties:" << endl;
    cout << "Easy, Medium, Hard" << endl;

    cout << endl << "Select a difficulty or type 'HELP' for more detail below:" << endl;
    cin >> selection;
	
    transform(selection.begin(), selection.end(), selection.begin(), ::tolower); //Convert to lowercase
    
    return 0;
}

int difficultySelection() { //Allows the user to select a difficulty
    selectionRepeat(); //First request of difficulty

    while (true) {
        if (selection == "help") { //Explanation for difficulties
            cout << endl << "The level of difficulty chooses the probability the computer will lie to you." << endl;
            cout << "For example, if the random number was 47, and the guess was 50." << endl;
            cout << "Instead of saying 'Too high.', the computer will instead say 'Too low.'" << endl;
            _sleep(5000);

            cout << endl << "In the Easy difficulty, the computer will never lie." << endl;
            cout << "In the Medium difficulty, the computer will have a 25% chance of lying." << endl;
            cout << "In the Hard difficulty, the computer will have a 50% chance of lying." << endl;
			
            _sleep(5000);

            cout << endl << "Select a difficulty below:" << endl;
            cin >> selection;
			
            transform(selection.begin(), selection.end(), selection.begin(), ::tolower); //Converts input to lowercase for easier comparison
        }
        else if (selection == "easy") {
            difficulty = 1;
            starting();
            break;
        }
        else if (selection == "medium") {
            difficulty = 2;
            starting();
            break;
        }
        else if (selection == "hard") {
            difficulty = 3;
            starting();
            break;
        }
        else {
            cout << "Invalid selection. Please try again." << endl;
            selectionRepeat();
        }
    }
    return 0;
}

int guessing() { //Allows the user to guess a number, Keeps track of attempts
    cout << endl << "Guess a number between 1 and 100 below:" << endl;
    
    while (!(cin >> guess)) { //Checks if the input is valid
        cout << "Invalid input! Please enter a number:" << endl;
        cin.clear(); //Clears the error flag
        cin.ignore(10000, '\n'); //Discards invalid input
    }
    attempt = ++attempt;
	
    return 0;
}

int win() { //When win condition met, Prints number of attempts taken
    cout << "You win!" << endl;
    cout << "You took " << attempt << " attempts." << endl;

    return 0;
}

int lose() { //When loss condition met, Prints number of attempts taken
    cout << "You have lost." << endl;
    cout << "The random number was " << randomNumber << "." << endl;
    cout << "You took " << attempt << " attempts." << endl;

    return 0;
}

int guessComparison() { //Main program of the game, Compares the guess from the user to the random number
    guessing(); //First attempt of the user

    while (true) { //Allows the program to keep running
        if (guess == randomNumber) { //Win condition
            win();
            break;
        }
        
        if (attempt >= maxAttempts) { //Loss condition - ran out of attempts
            lose();
            break;
        }
        
        if (guess < 1 || guess > 100) { //Checks if input is out of range
            if (guess < 1) {
                cout << "Enter a number higher than 0:" << endl;
            } else {
                cout << "Enter a number lower than or equal to 100:" << endl;
            }
            attempt = --attempt; //Doesn't count invalid attempts
            guessing();
            continue;
        }
        
        if (guess < randomNumber) { //Guess is lower than random number
            if (difficulty == 1) {
                cout << "Too low." << endl;
            }
            else if (difficulty == 2) {
                chance = rand() % 100 + 1;
                if (chance <= 25) {
                    cout << "Too high." << endl;
                }
                else {
                    cout << "Too low." << endl;
                }
            }
            else if (difficulty == 3) {
                chance = rand() % 100 + 1;
                if (chance <= 50) {
                    cout << "Too high." << endl;
                }
                else {
                    cout << "Too low." << endl;
                }
            }
            guessing();
        }
        else if (guess > randomNumber) { //Guess is higher than random number
            if (difficulty == 1) {
                cout << "Too high." << endl;
            }
            else if (difficulty == 2) {
                chance = rand() % 100 + 1;
                if (chance <= 25) {
                    cout << "Too low." << endl;
                }
                else {
                    cout << "Too high." << endl;
                }
            }
            else if (difficulty == 3) {
                chance = rand() % 100 + 1;
                if (chance <= 50) {
                    cout << "Too low." << endl;
                }
                else {
                    cout << "Too high." << endl;
                }
            }
            guessing();
        }
    }

    return 0;
}

int userRating() { //Scoring based on attempts to max attempts
    if (attempt <= 2) { //Excellent performance within 2 attempts
        cout << "You had an excellent performance!" << endl;
    }
    else if (attempt <= maxAttempts * 0.49) { //Good performance within 2 attempts to 49% of maxAttempts
        cout << "You had a good performance!" << endl;
    }
    else if (attempt <= maxAttempts * 0.69) { //Okay performance within 50-69% of maxAttempts
        cout << "You had an okay performance." << endl;
    }
    else if (attempt < maxAttempts) { //Poor performance within 70% to less than maxAttempts
        cout << "You had a poor performance." << endl;
    }
    else { //Bad performance when maxAttempts reached
        cout << "You had a bad performance." << endl;
    }

    return 0;
}

int main() { //Runs the game
    welcome();
    difficultySelection();
    guessComparison();
    userRating();
    
    return 0;
}
