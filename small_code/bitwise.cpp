#include <iostream>
#include <vector>
#include <sstream> 
#include <map>

using namespace std;

unsigned char add_one(unsigned char c) {
    return c + 1;
}

unsigned char shift_left(unsigned char c) {
    return c << 1; 
}

unsigned char shift_right(unsigned char c) {
    return c >> 1; 
}

unsigned char set_rightmost_bit_one(unsigned char c) {
    return c | 0x01;
}

unsigned char set_rightmost_bit_zero(unsigned char c) {
    return c & 0xFE;
}

/**
 * This function changes the value of the byte by applying a bitwise function to the byte
 * @param bitwise_function is a function pointer that points to the bitwise operation function
 * @param for_loop_hi_value is the number of times the bitwise operation function is applied to the byte
 * @param byte is the unsigned 8-bit char
 */
unsigned char bitwise_func(unsigned char(*bitwise_function)(unsigned char), int for_loop_hi_value, unsigned char byte) {
    for (int i = 0; i < for_loop_hi_value; i++) {
        byte = bitwise_function(byte); 
    }
    //cast to integer to retain the char 8-bits and print the value of the 8-bit char
    cout << "Current value of the char byte: " << (int)byte << endl;
    return byte;
}

/**
 * This function takes a string and a delimiter and splits 
 * on the delimiter character into a list.
 * It splits the string on whitespaces by default.
 * @param s is the string that is going to be splitted
 * @param delimiter is the character that is going to be splitted on
 */
vector<string> split(string s, char delimiter=' ') {
    vector<string> words;
    stringstream ss(s);

    string word;
    while (getline(ss, word, delimiter)) {
        words.push_back(word);
    }

    return words;
}

/**
 * The game loop
 */
int main() {
    bool play = true;
    cout << "\nThe Bitwise Game - manipulating a byte" << endl;
    string command;
    string number;
    vector<string> words;
    unsigned char byte = 0;
    while (true) {
        string user_input;
        cout << "\na n - where a is the add command and n is the number that you want to add to the byte\n"; 
        cout << "sl n - where sl is the shift left command and n is the number that you want to shift the byte\n";
        cout << "sr n - where sr is the shift right command and n is the number that you want to shift the byte\n";
        cout << "0 - sets the right-most bit to 0\n";
        cout << "1 - sets the right-most bit to 1\n";
        cout << "q - where q is the quit command\n";
        cout << "Input: ";
        getline(cin, user_input);
        command = split(user_input)[0];
        number = split(user_input)[1]; 
        
        if (command == "a") {
            byte = bitwise_func(add_one, stoi(number), byte);
        }
        else if (command == "sl") {
            byte = bitwise_func(shift_left, stoi(number), byte);
        }
        else if (command == "sr") {
            byte = bitwise_func(shift_right, stoi(number), byte);
        }
        else if (command == "0") {
            byte = bitwise_func(set_rightmost_bit_zero, 1, byte);
        }
        else if (command == "1") {
            byte = bitwise_func(set_rightmost_bit_one, 1, byte);
        }
        else if (command == "q") {
            break;
        }
        else {
            cout << "Not a valid input!" << endl; 
        }
    }
    return 0;
}