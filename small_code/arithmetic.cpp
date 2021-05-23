#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;
    char try_again = 'y'; //char must be declared with single quotes
    while (try_again != 'n') {
        cout << "Adding two numbers together" << endl; //strings must be declared with double quotes
        cout << "Enter a number: ";
        cin >> num1;
        cout << "Enter another number: ";
        cin >> num2;
        int answer = num1 + num2;
        cout << num1 << " + " << num2 << " = " << answer << endl;
        cout << "Would you like to try again (y/n)? ";
        cin >> try_again;
    }
    return 0;
}