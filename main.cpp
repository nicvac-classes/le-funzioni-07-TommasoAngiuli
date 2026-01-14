#include <iostream>
using namespace std;
int massimo(int n, int v[]);
void ordina(int n, int v[]);
void riempi(int n, int v[]);
void visualizza(int n, int v[], bool posizione);
int main() 
{
    int n, i, max;
    bool posizione;
    cout << "inserisci la dimensione dei vettori" << endl;
    cin >> n;
    int v[n], w[n];
    riempi(n, v);
    riempi(n, w);
    max = massimo(n, v);
    cout << "il valore massimo di V è " << v[max] << " e la sua posizione è " << max << endl;
    cout << "V" << endl;
    posizione = false;
    visualizza(n, v, posizione);
    ordina(n, v);
    cout << "V ordinato" << endl;
    visualizza(n, v, posizione);
    max = massimo(n, w);
    cout << "il valore massimo di W è " << w[max] << " e la sua posizione è " << max << endl;
    cout << "W" << endl;
    posizione = true;
    visualizza(n, w, posizione);
    ordina(n, w);
    cout << "W ordinato" << endl;
    visualizza(n, w, posizione);
    return 0;
}

int massimo(int n, int v[]) 
{
    int i, max, p;
    max = v[0];
    i = 1;
    p = 0;
    while (i <= n - 1) 
    {
        if (max < v[i]) 
        {
            max = v[i];
            p = i;
        }
        i = i + 1;
    }
    
    return p;
}

void ordina(int n, int v[]) 
{
    int i, j, t;
    bool scambio;
    i = 0;
    scambio = true;
    while (i <= n - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= n - 2 - i) 
        {
            if (v[j] > v[j + 1]) 
            {
                t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

void riempi(int n, int v[]) 
{
    int i;
    i = 0;
    while (i <= n - 1) 
    {
        v[i] = rand() % (n * 10);
        i = i + 1;
    }
}

void visualizza(int n, int v[], bool posizione) 
{
    int i;
    i = 0;
    while (i <= n - 1) 
    {
        cout << v[i] << endl;
        if (posizione) 
        {
            cout << "la posizione dell'elemento è " << i << endl;
        }
        i = i + 1;
    }
}
