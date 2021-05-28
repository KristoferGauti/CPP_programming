#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void partA() {
    /*
        Write a program that writes each word that the user types to the terminal into a text file.
        Add to the program functionality to read the text back from
        the file, word for word, and print it to the terminal.
    */

   ofstream fout;
   fout.open("./lab_assignments/terminal_input.txt");

    cout << "Welcome to user input to a text file" << endl;
    string user_input = "";
    while (true) {
        cout << "\nForm a sentence and press Enter \nor type \"q\" to quit the application\nand see the results in terminal_input.txt: ";
        getline(cin, user_input);
        if (user_input == "q") {
            break;
        }
        else {
            user_input = user_input + "\n";
            fout << user_input;
        }
    }
    fout.close();

    ifstream fin;
    string file_text;
    fin.open("./lab_assignments/terminal_input.txt");
    cout << "\nThe text read from terminal_input.txt file:\n\n"; 
    string results;
    while (getline(fin, results)) {
        cout << results << "\n";
    }
    fin.close();
}

void partB() {
    /*
        Write a program that writes into a binary file and reads from it. Use the write() and read()
        operations when working with binary files rather than the << and >> stream operators.
        Allow the user to choose whether the program will write new values to the file or read from it.
        The file should include information on how many strings are in the file. Each string should have
        information on how long it is, followed by the string characters themselves.
    */

}


int main() {

    partA();
    partB();

    return 0;
}