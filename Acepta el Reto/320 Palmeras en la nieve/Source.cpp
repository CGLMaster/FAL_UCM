#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Precondicion Q : {peso >= 0 && vector<int> a : 1 <= a.size() <= 100000 && forall k : a[k] >= 0}
// Invariante I : {vector<int> a : 0 <= k < a.size() && r = ((0 <= k < a.size() : a[k] <= peso && primero) && ((0 <= l < a.size() : a[l] <= peso))}
// Funcion de cota C : N - i
// Postcondicion R : {max c : vector<int> a : 0 <= p <= q < a.size() : q - p : a[p] <= peso && a[q] <= peso}

int mayorTramo(vector<int> v, int peso) {
	int ini = 0, last = 0, contMax = 0, contPalmeras = 0;
	bool primero = false;
	for (int i = 0; i < v.size(); i++) {
		if (peso >= v[i] && !primero) {
			ini = i;
			contPalmeras++;
			primero = true;
		}
		else if (peso >= v[i]) {
			last = i;
			contPalmeras++;
			contMax = last - ini + 1;
		}
	}
	return contMax;
}

void resuelveCaso() {
	int peso, numPalmeras;
	cin >> peso >> numPalmeras;
	vector<int> v(numPalmeras);
	for (int i = 0; i < numPalmeras; i++) cin >> v[i];
	int m = mayorTramo(v, peso);
	cout << m << endl;
}



int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}