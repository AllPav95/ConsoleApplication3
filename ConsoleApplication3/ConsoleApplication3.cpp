#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const char uppercaseLetter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lowercaseLetter[] = "abcdefghijklmnopqrstuvwxyz";
const char numbers[] = "123456789";
const char specialChars[] = "!@#$%^&*()_+{}[]<>?";
const char chars[] = "ღ↑→↓√▲★☆☉☐♫✈❤Ⓐ❀✓Ⓒ❆";

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const char* charSets[] = { uppercaseLetter, lowercaseLetter, numbers, specialChars, chars };
    const int numCharSets = sizeof(charSets) / sizeof(charSets[0]);

    string password;

    vector<int> usedCharSets(numCharSets, 0);

    char lastChar = '\0';

    while (password.length() < 12) {
        int charSetIndex = rand() % numCharSets;
        if (usedCharSets[charSetIndex] < strlen(charSets[charSetIndex])) {
            int charIndex;
            do {
                charIndex = rand() % strlen(charSets[charSetIndex]);
            } while (charSets[charSetIndex][charIndex] == lastChar);

            char randomChar = charSets[charSetIndex][charIndex];
            password += randomChar;
            lastChar = randomChar;
            usedCharSets[charSetIndex]++;
        }
        else {
            
            fill(usedCharSets.begin(), usedCharSets.end(), 0);
        }
    }
    cout << "password: " << password << endl;

    return 0;
}