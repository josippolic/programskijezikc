#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const string FILE_NAME = "passwords.txt";
const string CHARACTERS = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@Ł!&#$/<>*ł?£&{}[]€;:-_÷^";

unordered_map<string, int> readPasswords() {
    unordered_map<string, int> passwords;
    ifstream file(FILE_NAME);
    if (file.is_open()) {
        string password;
        int count;
        while (file >> password >> count) {
            passwords[password] = count;
        }
        file.close();
    }
    return passwords;
}

void writePasswords(const unordered_map<string, int>& passwords) {
    ofstream file(FILE_NAME);
    if (file.is_open()) {
        for (const auto& entry : passwords) {
            file << entry.first << " " << entry.second << "\n";
        }
        file.close();
    }
}

string generatePassword(int length) {
    string password;
    for (int i = 0; i < length; i++) {
        password += CHARACTERS[rand() % CHARACTERS.length()];
    }
    return password;
}

void passwordGenerator() {
    srand(time(0));
    unordered_map<string, int> passwords = readPasswords();
    
    while (true) {
        cout << "\n================== Password Generator App ==================\n\n";
        
        int passlen;
        cout << "Enter the length of password (8-15): ";
        cin >> passlen;

        if (cin.fail() || passlen < 8 || passlen > 15) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nPassword length should be between 8 and 15 characters.\n";
            continue;
        }
        
        string password = generatePassword(passlen);

        if (passwords.find(password) != passwords.end()) {
            passwords[password]++;
            cout << "\n\nYour password is: " << password;
            cout << "\nThis password has been generated " << passwords[password] << " times.";
        } else {
            passwords[password] = 1;
            cout << "\n\nYour password is: " << password;
        }

        writePasswords(passwords);

        if (passlen == 15) {
            cout << "\nWarning: Password should not have 15 or more characters.\n";
        }

        string opt;
        cout << "\nDo you want to try again? (da/ne): ";
        cin >> opt;

        if (opt == "ne") {
            cout << "Exiting program....\n";
            break;
        } else if (opt != "da") {
            cout << "Please enter da/ne:\n";
        }
    }
}

int main() {
    passwordGenerator();
    return 0;
}
