
#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;

    int option = 1;

    while(option != 0) {
        cout << "Informe um valor: ";
        cin >> option;
        if (option != 0)
            l.insert(l.end(), option);
    }

    cout << "\n --- Sequencia informada --- \n";

    for(list<int>::iterator pos=l.begin(); pos != l.end(); pos++)
        cout << *pos << endl;

    cout << "\n --- Sequencia invertida --- \n";

    l.reverse();

    for(list<int>::iterator pos=l.begin(); pos != l.end(); pos++)
        cout << *pos << endl;

}
