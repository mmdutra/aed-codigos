#include<iostream>

using namespace std;

int countA(string word) {
    int result = 0;
    for (unsigned i = 0; i < word.length(); i++) {
        if (::toupper(word.at(i)) == 'A')
        result++;
    }

    return result;
}

int main() {
    string word;

    cout << "Informe a palavra:";
    cin >> word;

    int result = countA(word);

    cout << "resultado: " << result << endl;

    return 0;
}
