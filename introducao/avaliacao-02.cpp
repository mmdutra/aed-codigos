#include<iostream>

using namespace std;

float avg(float items[], int length) {
    float sum = 0.0;

    for (unsigned i = 0; i < length; ++i)
        sum += items[i];

    return sum / length;
}

int main() {
    int i;
    float values[2];

    for(i = 0; i < 2; ++i) {
        cout << "Informe o " << (i + 1) << "º valor: ";
        cin >> values[i];
    }

    int length = sizeof(values) / sizeof(values[0]);

    cout << "A média dos valores é " << avg(values, length);

    return 0;
}
