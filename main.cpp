#include <utility>
#include "iostream"

using namespace std;

string encrypt(string plainText, const string& key);
string decrypt(string encrypted, const string& key);
string xorOperation(string text, string key);
string addition(string text, const string& key);
string subtraction(string text, const string& key);

int main() {
    string encrypted = encrypt("kylewbanks.com", "hasjhaksa");
    cout << "Encrypted: " << encrypted << "\n";

    string decrypted = decrypt(encrypted, "hasjhaksa");
    cout << "Decrypted: " << decrypted << "\n";

    return 0;
}

string encrypt(string plainText, const string& key) {
    string output = move(plainText);

    for (int i = 0; i < 16; ++i) {
        output = addition(output, key);
        output = xorOperation(output, key);
        output = addition(output, key);
        output = xorOperation(output, key);
    }

    return output;
}

string decrypt(string encrypted, const string& key) {
    string output = move(encrypted);

    for (int i = 16; i > 0; --i) {
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

