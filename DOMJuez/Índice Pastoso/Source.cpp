// NOMBRE Y APELLIDOS
// CARLOS GOMEZ LOPEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 <= i < N && 0 <= v[i] <= 100000 }
// I { N > i >= 0 && v[i] = sum } donde sum es el sumatorio de todos los números que hay en las siguientes posiciones de v[i]
// C : N - i
// R { esPastoso && 0 <= pos < N }
// esPastoso { true --> 0 <= i < N : sum = v[i] ||false --> i = N-1}
// El coste de la funcion en el peor de los casos es O(N), donde N es el tamaño del vector
bool esPastoso(vector<int> v, int& pos) {
	int sum = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] == sum) {
			pos = i;
			return true;
		}
		sum += v[i];
	}
	return false;
}


void resuelveCaso() {
	int N, pos = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (esPastoso(v, pos)) cout << "Si " << pos << endl;
	else cout << "No" << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}