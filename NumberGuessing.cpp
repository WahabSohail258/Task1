#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessingGame {
    int maxnumber;
    int maxtries;
    int numberoftries;
    int randomnumber;

public:
    GuessingGame() {
        srand(time(nullptr));
        maxnumber = 100;
        maxtries = 10;
        numberoftries = 0;
        randomnumber = rand() % maxnumber + 1;
    }

    void setdifficulty() {
        int choice;
        cout << "Select the difficulty level:\n";
        cout << "1. Easy (Unlimited Tries)\n";
        cout << "2. Medium (10 Tries)\n";
        cout << "3. Difficult (5 Tries)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            maxtries = -1;
            break;
        case 2:
            maxtries = 10;
            break;
        case 3:
            maxtries = 5;
            break;
        default:
            cout << "Invalid choice! Setting to Medium (10 Tries).\n";
            maxtries = 10;
            break;
        }
    }

    void play() {
        int guess;
        cout << "Welcome to the Number Guessing Game!\n";
        cout << "I have selected a number between 1 and " << maxnumber << ".\n";

        while (true) {
            cout << "Enter your guess: ";
            cin >> guess;
            numberoftries++;

            if (guess > randomnumber) {
                cout << "The number is less than " << guess << ".\n";
                cout << "Kindly try again!\n";
            }
            else if (guess < randomnumber) {
                cout << "The number is greater than " << guess << ".\n";
                cout << "Kindly try again!\n";
            }
            else {
                cout << "Congratulations! You have guessed the number in " << numberoftries << " tries.\n";
                return;
            }

            if (maxtries != -1 && numberoftries >= maxtries) {
                cout << "You have reached the maximum number of tries!\n";
                cout << "The number was: " << randomnumber << ".\n";
                return;
            }
        }
    }
};

int main() {
    GuessingGame game;
    game.setdifficulty();
    game.play();
    return 0;
}
