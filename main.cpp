#include <utility>
#include "iostream"

using namespace std;

string encrypt(string message, string key);
string decrypt(string message, string key);
int getNumberRepresentation(string key);

char* ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char* abc = "abcdefghijklmopqrstuvwxyz";

int main() {
    string key, message, result;
    int option;

    cout << "Give me the key: ";
    getline(cin, key);

    cout << "Give me the message: ";
    getline(cin, message);

    option = -1;
    while (option != 3) {
        cout << "What do you want to do? \n 1) Encrypt\n 2) Decrypt\n 3) Exit\n";
        cin >> option;

        if (option == 1) {
            result = encrypt(message, key);
            cout << "\n Result: " << result << endl;
        } else if (option == 2) {
            result = decrypt(message, key);
            cout << "\n Result: " << result << endl;
        }
    }

    return 0;
}

string encrypt(string message, string key) {
    int numberKey = getNumberRepresentation(key), size = message.length();
    char *point;
    char result[size];

    for (int i = 0; i < size; i++) {
        if (isspace(message[i])) {
            result[i] = message[i];
            continue;
        }

        if ((point = strchr(ABC, message[i]))) {
            result[i] = ABC[(point - ABC + numberKey) % 26];
        }

        if((point = strchr(abc, message[i]))){
            result[i] = abc[(point - abc + numberKey) % 26];
        }
    }

    return result;
}

string decrypt(string message, string key) {
    int numberKey = getNumberRepresentation(key), size = message.length();
    char *point;
    char result[size];

    for (int i = 0; i < size; i++) {
        if (isspace(message[i])) {
            result[i] = message[i];
            continue;
        }

        if ((point = strchr(ABC, message[i]))) {
            result[i] = ABC[(point - ABC - numberKey + 26) % 26];
        }

        if ((point = strchr(abc, message[i]))) {
            result[i] = abc[(point - abc - numberKey + 26) % 26];
        }
    }

    return result;
}

int getNumberRepresentation(string key) {
    int size = key.length();
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += int(key[i]);
    }

    return result;
}



