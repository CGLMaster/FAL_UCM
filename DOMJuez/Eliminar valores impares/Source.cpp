#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Q { true }
// I {vector<int> v : 0 <= pos <= i < v.size() : v[i] % 2 == 0 --> v[pos] = v[i]}
// C : N - 1
// R { vector<int> v : 0 <= i < N : v[i] % 2 == 0 }
// El coste de la función en el peor de los casos es O(N), donde N es el número de elementos del vector
void eliminaImpares(vector<int>& v) {
	int pos = 0;
	for (long long int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			v[pos] = v[i];
			pos++;
		}
	}
	v.resize(pos);
}

void resuelveCaso() {
	long long int N;
	cin >> N;
	vector<int> v(N);
	for (long long int i = 0; i < N; i++) cin >> v[i];
	eliminaImpares(v);
	if(!v.empty()) 	cout << v[0];
	for (long long int i = 1; i < v.size(); i++) cout << " " << v[i];
	cout << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();



#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
