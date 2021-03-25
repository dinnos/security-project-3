#include <utility>
#include "iostream"

using namespace std;

string encrypt(string plainText, const string& key);
string decrypt(string encrypted, const string& key);
string xorOperation(string text, string key);
string addition(string text, const string& key);
string subtraction(string text, const string& key);
int getNumberRepresentation(string key);

int main() {
    string key = "hasjhaksa";
    string message = "kylewbanks.com";

    string encrypted = encrypt(message, key);
    string decrypted = decrypt(encrypted, key);

    cout << "Encrypted: " << encrypted << "\nDecrypted: " << decrypted << endl;

    return 0;
}

string encrypt(string plainText, const string& key) {
    string output = move(plainText);
    int rounds = getNumberRepresentation(key);

    for (int i = 0; i < rounds; ++i) {
        output = addition(output, key);
        output = xorOperation(output, key);
        output = addition(output, key);
        output = xorOperation(output, key);
    }

    return output;
}

string decrypt(string encrypted, const string& key) {
    string output = move(encrypted);
    int rounds = getNumberRepresentation(key);

    for (int i = rounds; i > 0; --i) {
        output = xorOperation(output, key);
        output = subtraction(output, key);
        output = xorOperation(output, key);
        output = subtraction(output, key);
    }

    return output;
}

string xorOperation(string text, string key) {
    int textSize = text.size(), keySize = key.size();
    string output = text;

    int aux = 0;
    for (int i = 0; i < textSize; i++) {
        output[i] = text[i] ^ key[aux];
        aux++;
        if (aux == keySize) {
            aux = 0;
        }
    }

    return output;
}

string addition(string text, const string& key) {
    int textSize = text.size(), keySize = key.size();
    string output = text;

    for (int i = 0; i < textSize; i++) {
        output[i] = text[i] + keySize;
    }

    return output;
}

string subtraction(string text, const string& key) {
    int textSize = text.size(), keySize = key.size();
    string output = text;

    for (int i = 0; i < textSize; i++) {
        output[i] = text[i] - keySize;
    }

    return output;
}

int getNumberRepresentation(string key) {
    int size = key.size();
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += int(key[i]);
    }

    return result;
}
