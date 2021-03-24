#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string encrypt(const string& plainText, const string& key);
string dencrypt(const string& encrypted, string key);
int getNumberRepresentation(string key);

char* A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\?¿'+´*¨{}][;:,.^";

int main() {
    string key, message, result;
    int option;

    cout << "Give me the message: ";
    getline(cin, message);

    cout << "Give me the key: ";
    getline(cin, key);

    do {
        cout << "What do you want to do? \n 1) Encrypt\n 2) Decrypt\n";
        cin >> option;

        switch(option){
            case 1: result = encrypt(message, key);
                    cout << "Result: " << result << endl;
                    break;

            case 2: result = dencrypt(message, key);
                    break;
        }

    } while (option != 3);



}

string encrypt(const string& plainText, const string& key) {
    int numKey = getNumberRepresentation(key), numPlainText = getNumberRepresentation(plainText);
    stringstream result;

    for (int i = 0; i < numKey; i++) {
        numPlainText += i;
        numPlainText = numPlainText << 2; //circular -> confución
        numPlainText ^= numKey; //XOR -> difusión
    }

    result << hex << numPlainText; //representación hexa de numPlainText

    return result.str();
}

string dencrypt(const string& encrypted, string key) {
    char *aux;
    long number = strtoul(encrypted.c_str(), &aux, 16);
    int input;

    if (*aux != 0) {
        cout << "encrypted is not a number" << endl;
        exit(-1);
    }

    input = (int) number;
    int numKey = getNumberRepresentation(key);

    for (int i = numKey; i > 0; i--) {
        number += i;
        number = number << 2;//circular -> confución
        number ^= numKey;//XOR ->difusión
    }

    return "";
}

int getNumberRepresentation(string key) {
    int size = key.length();
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += int(key[i]);
    }

    return result;
}
