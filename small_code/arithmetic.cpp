#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;
    cout << "Adding two numbers together" << endl;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter another number: ";
    cin >> num2;
    int answer = num1 + num2;
    cout << num1 << " + " << num2 << " = " << answer << endl;
    return 0;
}