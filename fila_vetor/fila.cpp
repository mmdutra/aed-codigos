#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

class FilaInt
{
private:
    int* v;
    int frente, tras;
    int cap, ocup;
public:

    FilaInt(int tam)
    {
        frente = tras = 0;
        cap = tam;
        ocup = 0;
        v = new int[tam];
    }

    FilaInt()
    {
        FilaInt(tam);
    }

    ~FilaInt()
    {
        delete [] v;
    }

    void enfileira(int d)
    {
        if (ocup < cap)
        {
            v[ tras ] = d;
            tras = (tras + 1) % cap;
            ocup++;
        }

        else
            throw range_error("Classe FilaInt :: enfileira: fila cheia");
    }

    void desenfileira()
    {
        if (ocup > 0)
        {
            ocup--;
            frente = (frente + 1) % cap;
        }
        else
            throw out_of_range("Classe FilaInt :: desenfileira - fila vazia");
    }

    int obtemFrente()
    {
        int t=0;
        if (ocup > 0)
            t = v[frente];
        else
            throw out_of_range("Classe FilaInt :: obtemFrente - fila vazia");

        return t;
    }

    bool vazia()
    {
        return ocup == 0;
    }

    friend ostream& operator<<(ostream& is, FilaInt &fila);

    int contaOcorrencias(int valor) {
        int i, cont, contOcorr;
        i = frente;
        cont = 0;
        contOcorr = 0;
        while (cont < ocup) {
            if (v[i] == valor) {
                contOcorr++;
            }
            i = (i + 1) % cap;
            cont++;
        }

        return contOcorr;
    }

};

ostream& operator<<(ostream& os, FilaInt &fila)
{
    int f = fila.frente;
    int r = fila.tras;
    int s = fila.cap;

    for (int i = f; i != r; i = (i+1)%s)
    {
        os << fila.v[i] << "\t";
    }

    return os;
}

int main()
{
    try
    {
        FilaInt f(5);
        f.enfileira(40);
        f.enfileira(30);
        f.enfileira(60);
        f.enfileira(30);

        cout << f;

        cout << "\n\n";

        cout << f.contaOcorrencias(40);
    }
    catch(out_of_range err)
    {
        cout << err.what() << endl;
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }
}
