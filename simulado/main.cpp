#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

struct Celula
{
    int dado;
    struct Celula * baixo;
};


class PilhaEncadeada
{
private:
    Celula* topo;

    bool valorExiste(int valor, Celula* celula) {

        if (valor == celula -> dado)
            return true;

        if (celula -> baixo != NULL)
            return valorExiste(valor, celula -> baixo);

        return false;
    }

public:

    PilhaEncadeada()
    {
        topo = NULL;
    }
    ~PilhaEncadeada()
    {
        Celula *aux;
        while ( topo != NULL )
        {
            aux = topo;
            topo = topo -> baixo;
            delete aux;
        }
    }
    void empilha(int d)
    {
        Celula *aux = new Celula;
        aux -> dado = d;
        aux -> baixo = topo;
        topo = aux;
    }
    void desempilha()
    {
        if (topo != NULL)
        {
            Celula *aux = topo -> baixo;
            delete topo;
            topo = aux;
        }
        else
            throw out_of_range("Classe PilhaEncadeada :: desempilha - Pilha vazia");
    }
    int obtemTopo()
    {
        int t=0;
        if (topo != NULL)
            t = topo -> dado;
        else
            throw out_of_range("Classe PilhaEncadeada :: obtemTopo - Pilha vazia");
        return t;
    }
    bool vazia()
    {
        return topo == NULL;
    }



    bool contem(int valor) {
        return valorExiste(valor, topo);
    }
};


int main()
{
    try
    {
        PilhaEncadeada p;

        p.empilha(3);
        p.empilha(1);
        p.empilha(5);
        p.empilha(4);
        p.empilha(2);

        cout << p.contem(2);
    }
    catch(out_of_range err)
    {
        cout << err.what() << endl;
    }
}
