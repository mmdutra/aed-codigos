#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

class PilhaInt {
    private:
        int* v;
        int topo;
        int cap;
    public:
        PilhaInt(int tam) {
            topo = 0;
            cap = tam;
            v = new int[tam];
        }

        PilhaInt() {
            PilhaInt(tam);
        }

        ~PilhaInt() {
         delete [] v;
        }

        void empilha(int d) {
          if (topo < cap)
              v[topo++] = d;
          else
              throw range_error("Classe PilhaInt :: empilha - Pilha cheia");
        }

        void desempilha() {
          if (topo > 0)
              topo--;
          else
              throw out_of_range("Classe PilhaInt :: desempilha - Pilha vazia");
        }

        int obtemTopo() {
           int t=0;
          if (topo > 0)
              t = v[topo-1];
          else
              throw out_of_range("Classe PilhaInt :: topo - Pilha vazia");
          return t;
        }

        bool vazia() {
          return topo == 0;
        }

        void print() {
            int topoAtual = topo;
            while(topoAtual > 0) {
                topoAtual--;
                cout << v[topoAtual] << "\n";
            }
        }
};


int main() {
    try    {
        PilhaInt p(5);

        p.empilha(3);
        p.empilha(1);
        p.empilha(5);
        p.empilha(4);
        p.empilha(2);

        p.print();
    } catch(out_of_range err) {
       cout << err.what() << endl;
    } catch(range_error err) {
       cout << err.what() << endl;
    }
}

