#include <iostream>
#include <vector>
#include <sstream> 

using namespace std;

vector<string> split(string s, char delimiter=' ') {
    vector<string> words;
    stringstream ss(s);

    string word;
    while (getline(ss, word, delimiter)) {
        words.push_back(word);
    }

    return words;
}

void game_loop() {
    bool play = true;
    cout << "\nThe Bitwise Game - manipulating a byte" << endl;
    string command = "n";
    int number = -1;
    vector<string> words;
    while (true) {
        string user_input;
        cout << "\na n - where a is the add command and n is the number that you want to add to the byte\n"; 
        cout << "sl n - where sl is the shift left command and n is the number that you want to shift the byte\n";
        cout << "sr n - where sr is the shift right command and n is the number that you want to shift the byte\n";
        cout << "q - where q is the quit command\n";
        cout << "Input: ";
        getline(cin, user_input);
        string command = split(user_input)[0];
        string number = split(user_input)[1]; 
        if (command == "q") {
            break;
        }
        
        
        cout << command << " and " << typeid(number).name();
        
        
        
    }
}

/**
 * 
 */
void bitwise_test_func(unsigned char(*bitwise_function)(unsigned char), int for_loop_hi_value, unsigned char byte) {
    for (int i = 0; i < for_loop_hi_value; i++) {
        byte = bitwise_function(byte); 
    }
    //cast to integer to retain the char 8-bits and print the value of the 8-bit char
    cout << "Current value of the char byte: " << (int)byte << endl;
}


unsigned char add_one(unsigned char c) {
    return c + 1;
}

unsigned char shift_left(unsigned char c) {
    return c << 1; 
}

unsigned char shift_right(unsigned char c) {
    return c >> 1; 
}

int main() {
    //increment an 8-bit char c by 10 with the initial char = 0000-0000
    //bitwise_test_func(add_one, 10, 0);

    //shift an 8-bit char by 8 with the initial char = 0000-0001
    //This should overflow to 0 whereas char is only 8 bits
    //bitwise_test_func(shift_left, 8, 1);
    game_loop();



    return 0;
}