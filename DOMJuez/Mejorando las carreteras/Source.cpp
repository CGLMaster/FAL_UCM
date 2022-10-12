// Nombre del alumno: Carlos Gómez López
// Usuario del Juez: F33


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm> //Para introducir la función sort()
using namespace std;

// función que resuelve el problema

// El coste de la función en el peor de los casos es O(N^2), donde N es el número de elementos del vector. Esto se debe a que el coste en ordenar un vector es N^2.

// P : {0 < N < 2^31 && forall i: 0 <= i < N : 0 < v[i] < 2^31} donde N = v.size()

// I : {1 <= i < v.size() && max sol : (#s = (forall p,q : 1 <= p <= i <= q < v.size() : v[p] == v[q]))}
// C : N - 1

// Q : {v[z] : (max m : 0 <= p <= z <= q < v.size() : v[p] == v[q] : q - p)}

int resolver(vector<int> const& v) {
    int repMax = v[0], contMax = 1, cont = 1, num = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == num) cont++;
        else {
            if (contMax < cont) {
                repMax = num;
                contMax = cont;
            }
            num = v[i];
            cont = 1;
        }
    }
    if (contMax < cont) {
        repMax = num;
        contMax = cont;
    }
    return repMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
    int N;

    cin >> N;

    if (N == -1) return false;

    vector<int> v(N);

    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end()); // O(N^2)


    int sol = resolver(v);

    // escribir sol

    cout << sol << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
