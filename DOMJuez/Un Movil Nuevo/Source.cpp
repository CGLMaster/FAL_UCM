// Nombre del alumno: Carlos Gómez López
// Usuario del Juez: F33


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> l;
    for (int i = 0; i < (n1 + n2); i++) {
        int n;
        cin >> n;
        if (!count(l.begin(), l.end(), n)) {
            l.push_back(n);
        }
    }
    sort(l.begin(), l.end());
    if (!l.empty()) {
        cout << l[0];
        for (int i = 1; i < l.size(); i++) cout << " " << l[i];
    }
    cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}