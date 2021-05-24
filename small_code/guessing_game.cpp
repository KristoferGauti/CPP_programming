#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int lives = 5;

/**
 * Generates a random number by setting a 
 * random seed each time the code is executed
 */
int get_rand_num_between_0_100() {
    srand(time(NULL)); 
    return (rand() % 100);
}

bool logic(int guess, int random_number) {
    if (lives == 0) {
        cout << "You have" << lives << "lifes left" << endl;
        cout << "You lose!" << endl;
        cout << "The computer generated number was: " << random_number << endl;
        cout << "Better luck next time!" << endl;
        return true;
    }
    if (guess < random_number) {
        lives--;
        cout << "The number that you have guessed is less than the computer generated number" << endl;
        cout << "You have " << lives << " lives left, " << "Guess again!" << endl;
        return false;
    }
    else if (guess > random_number) {
        lives--;
        cout << "The number that you have guessed is greater than the computer generated number" << endl;
        cout << "You have " << lives << " lives left, " << "Guess again!" << endl;
        return false;
    }
    else {
        cout << "That is correct!" << endl;
        cout << "The number was: " << random_number << endl;
        return true;
    }
}

void game_loop(int random_number) {
    bool guessed_correctly = false;
    cout << "Guessing game" << endl;
    int guess;
    while (!guessed_correctly) {
        cout << "You have a total of " << lives << " lifes left" << endl;
        cout << "Enter your number guess between 0-100: ";
        cin >> guess;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "You have entered wrong input" << endl;
        }
        else {
            guessed_correctly = logic(guess, random_number);
        }
    }
}

int main() {
    int rand_num = get_rand_num_between_0_100();
    game_loop(rand_num);
    return 0;
}