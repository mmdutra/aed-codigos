#include<iostream>
#include<stdexcept>
#include<string>

using namespace std;

class ListaInt
{
private:
    int* v;
    int cap, ult;
public:

    ListaInt(int tam)
    {
        cap = tam;
        ult = 0;
        v = new int[tam];
    }
    ~ListaInt()
    {
        delete [] v;
    }

    ListaInt(ListaInt &l)
    {
        cap = l.cap;
        ult = l.ult;
        v = new int[cap];
        for(int i=0; i<ult; i++)
            v[i] = l.v[i];
    }

    void insere(int dado, int pos)
    {
        if (ult < cap)
        {
            if ( pos>=0 && pos <= ult )
            {
                for (int i=ult; i>pos; i--)
                {
                    v[i] = v[i-1];
                }
                v[ pos ] = dado;
                ult++;
            }
            else throw out_of_range("Class ListaInt::insere -  posição não existente.");
        }
        else
            throw range_error("Classe ListaInt::insere - lista cheia");
    }

    void retira(int pos)
    {
        if (ult > 0)
        {
            for (int i=0; i<ult-1; i++)
            {
                v[i] = v[i+1];
            }
            ult--;
        }
        else
            throw out_of_range("Classe ListaInt :: retira - lista vazia");
    }

    int obtemElemento(int pos)
    {
        int t=0;
        if (ult > 0 && pos >=0 && pos < ult)
            t = v[pos];
        else
            throw out_of_range("Classe ListaInt :: obtemElemento - posição inexistente");
        return t;
    }

    bool vazia()
    {
        return ult == 0;
    }

    int inicio()
    {
        return 0;
    }

    int fim()
    {
        return ult;
    }

    int pesquisa(int elemento)
    {
        for (int i = 0; i <= ult; i++)
        {
            if (elemento == v[i])
                return i + 1;
        }

        return -1;
    }
};

ostream& operator<<(ostream& saida, ListaInt &l)
{
    for(int pos=l.inicio(); pos != l.fim(); pos++)
    {
        saida << l.obtemElemento(pos) << "\t";
    }
    return saida;
}

int main()
{
    try
    {
        ListaInt l(10);

        l.insere(20,l.fim());
        l.insere(30,l.fim());
        l.insere(50,l.fim());
        l.insere(10,l.fim());
        l.insere(50,l.fim());

        cout << l << endl;

        cout << "\n";

        int result = l.pesquisa(50);

        if (result == -1) {
            cout << "Valor não encontrado!";
            return 0;
        }

        cout << "O valor se encontra na posição: " << l.pesquisa(50) << "\t";
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
