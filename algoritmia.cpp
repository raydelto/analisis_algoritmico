#include <iostream>
#include <vector>

using namespace std;

// Búsqueda binaria
//  O(Log(N))

//.<izquierda>      <puntoMedio>            <derecha>
bool busquedaBinaria(const vector<int> &numeros, int numero)
{
    int izquierda = 0;
    int derecha = numeros.size() - 1;
    int puntoMedio;

    size_t vueltas = 0;

    while (izquierda <= derecha)
    {
        vueltas++;
        puntoMedio = (izquierda + derecha) / 2;

        if (numeros[puntoMedio] < numero)
        {
            izquierda = puntoMedio + 1;
        }
        else if (numeros[puntoMedio] > numero)
        {
            derecha = puntoMedio - 1;
        }
        else
        {
            cout << "Busqueda binaria dio " << vueltas << " vueltas" << endl;
            return true;
        }
    }
    cout << "Busqueda binaria dio " << vueltas << " vueltas" << endl;
    return false;
}

// Búsqueda lineal
//  O(N)
bool buscar(const vector<int> &numeros, int numero)
{
    size_t vueltas = 0;
    for (const int &n : numeros)
    {
        vueltas++;
        if (n == numero)
        {
            cout << "Busqueda lineal dio " << vueltas << " vueltas" << endl;
            return true;
        }
    }
    cout << "Busqueda lineal dio " << vueltas << " vueltas" << endl;
    return false;
}

vector<int> generarNumeros()
{
    vector<int> numeros;

    for(size_t i = 0; i < 1000000; i++)
    {
        numeros.emplace_back(i);
    }
    return numeros;
}

int main()
{
    vector<int> numeros = generarNumeros();
    // {1, 4, 6, 9, 10, 11, 12, 34, 83, 101, 125, 127};
    int numero = 1000000;
    cout << ((busquedaBinaria(numeros, numero)) ? "Numero encontrado" : "Numero no encontrado") << endl;
    cout << ((buscar(numeros, numero)) ? "Numero encontrado" : "Numero no encontrado") << endl;
    return 0;
}