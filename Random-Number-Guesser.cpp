//Initialise preinstalled libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Initialise functions
int randomNumber;
int guess;
int attempt = 0;
int maxAttempts = 10;
int difficulty;
int chance;
string selection;
string selectionExplained;

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

    return(NULL);
}

int welcome() { //Welcoming text and ruleset for the game & generates random number
    cout << "Welcome to the game!" << endl;
    _sleep(1000);

    cout << endl << "Rules:" << endl;
    cout << "You job as the guesser, is to guess a number between 0 and 100." << endl;
    cout << "Should you correctly guess the number, you win the game." << endl;
    cout << "You have a maximum of 10 attempts." << endl;
    _sleep(3000);

    //starting();

    return (NULL);
}

int selectionRepeat() { //Asks user for difficulty, Used incase improper userinput
    cout << endl << "There are 3 difficulties:" << endl;
    cout << "Easy, Medium, Hard" << endl;

    cout << endl << "Select a difficulty or type 'HELP' for more detail below (Requires specific capitalised and non-capitalised letters):" << endl;
    cin >> selection;
    return (NULL);
}

int difficultySelection() { //Allows the user to select a difficulty
    selectionRepeat(); //First request of difficulty

    while (true) {
        if (selection == "HELP") { //Explanation for difficulties
            cout << endl << "The level of difficulty chooses the probability the computer will lie to you." << endl;
            cout << "For example, if the random number was 47, and the guess was 50." << endl;
            cout << "Instead of saying 'Too high.', the computer will instead say 'Too low.'" << endl;
            _sleep(5000);

            cout << endl << "In the Easy difficulty, the computer will never lie." << endl;
            cout << "In the Medium difficulty, the computer will have a 25% of lying." << endl;;
            cout << "In the Medium difficulty, the computer will have a 50% of lying." << endl;
            _sleep(5000);

            cout << endl << "Select a difficulty below:" << endl;
            cin >> selection;
        }
        else if (selection == "Easy") {
            difficulty = 1;
            starting();
            break;
        }
        else if (selection == "Medium") {
            difficulty = 2;
            starting();
            break;
        }
        else if (selection == "Hard") {
            difficulty = 3;
            starting();
            break;
        }
        else {
            selectionRepeat();
        }
    }
    return (NULL);
}

int guessing() { //Allows the user to guess a number, Keeps track of attempts
    cout << endl << "Guess a number between 0 and 100 below:" << endl;
    cin >> guess;
    attempt = ++attempt;

    return (NULL);
}

int win() { //When win condition met, Prints number of attempts taken
    cout << "You win!" << endl;
    cout << "You took " << attempt << " attempts." << endl;

    return (NULL);
}

int lose() { //When loss condition met, Prints number of attempts taken
    cout << "You have lost." << endl;
    cout << "The random number was " << randomNumber << "." << endl;
    cout << "You took " << attempt << " attempts." << endl;

    return (NULL);
}

int guessComparison() { //Main program of the game, Compares the guess from the user to the random number
    guessing(); //First attempt of the user

    while (true) { //Allows the program to keep running
        if (attempt != maxAttempts) { //Prevents program from stopping when max attempts not reached
            if (guess == randomNumber) { //Win condition
                win();
                break;
            }
            else if (guess < randomNumber) { //Guess is lower than random number
                if (difficulty == 1) {
                    cout << "Too low." << endl;
                }
                if (difficulty == 2) {
                    chance = rand() % 100 + 1;
                    if (chance <= 25) {
                        cout << "Too high." << endl;
                    }
                    else {
                        cout << "Too low." << endl;
                    }
                }
                if (difficulty == 3) {
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
                if (difficulty == 2) {
                    chance = rand() % 100 + 1;
                    if (chance <= 25) {
                        cout << "Too low." << endl;
                    }
                    else {
                        cout << "Too high." << endl;
                    }
                }
                if (difficulty == 3) {
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
            else if (guess < 0) { //Prevents guess attempt being taken due to improper number selection
                cout << "Enter a number higher than 0 below:" << endl;
                attempt = --attempt;
                guessing();
            }
            else if (guess > 100) { //Prevents guess attempt being taken due to improper number selection
                cout << "Enter a number lower than 100 below:" << endl;
                attempt = --attempt;
                guessing();
            }
        }
        else { //Moves to loss screen when max attempts reached
            lose();
            break;
        }
    }

    return (NULL);
}

int userRating () { //Scoring based on attempts to max attempts
    if (attempt < 3) { //Excellent performance within 2 attempts
        cout << "You had an excellent performance!" << endl;
    }
    else if (attempt < 6) { //Good performance within 3-5 attempts
        cout << "You had an good performance!" << endl;
    }
    else if (attempt < 8) { //Okay performance within 6-7 attempts
        cout << "You had an okay performance." << endl;
    }
    else if (attempt < 10) { //Poor performance within 8-9 attempts
        cout << "You had an poor performance." << endl;
    }
    else if (attempt == maxAttempts) { //Bad performance when max attempts needed (10)
        cout << "You had an bad performance." << endl;
    }

    return (NULL);
}

int main() { //Runs the game
    welcome();
    difficultySelection();
    guessComparison();
    userRating();
}