//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Q { 0 <= N <= 1000 && 0 <= i < N : 0 < v[i] < 4000 }
// I { 0 <= i < N : v[i-1] >= v[i] : cont++ && masGrande = max(masGrande, cont) }
// C : N - 1
// R { 1 <= cont < N }
//El coste de la funcion en el peor de los casos es O(N) donde N es el número de alturas de cada pista
int pistaLarga(vector<int> v) {
	int cont = 1, masGrande = 0;
	if (v.size() != 0) {
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] >= v[i]) cont++;
			else {
				cont = 1;
			}
			masGrande = max(masGrande, cont);
		}
		cont = masGrande;
	}
	return cont;
}

void resuelveCaso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << pistaLarga(v) << endl;
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