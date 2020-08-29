
#include <iostream>
#include <queue>
#include <cstring>

struct Aluno {
   int matricula;
   char nome[100];
};

bool operator>(const Aluno& a1, const Aluno& a2) {
    return strcmp(a1.nome, a2.nome) > 0;
}

using namespace std;

int main() {
    priority_queue<Aluno, deque<Aluno>, greater<Aluno>> fp;

    Aluno v [] = { {1234, "Alda"}, {3123, "Mateus"}, {4412, "Bruna"}, {2122, "zelda"} };

    fp.push(v[0]);
    fp.push(v[1]);
    fp.push(v[2]);
    fp.push(v[3]);

    while ( ! fp.empty() ) {
        cout << fp.top().nome << " " << fp.top().matricula << endl;
        fp.pop();
    }
}
