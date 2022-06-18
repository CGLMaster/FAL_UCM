#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Precondicion Q : {vector<int> a : 2 <= a.size() <= 300000 && 0 <= k < a.size() : forall k : 1 <= a[k] <= 300000}
// Invariante I : {(end = (a[0] == 1) : vector<int> a : 0 <= p < q < a.size() - 1 && max = (a[p] - a[q] > max)) && (end = (a[0] != 1) : vector<int> a : 1 <= p < q < a.size() && max = (a[q] - a[p] > max))}
// Funcion de cota C : i + 1 || N - i - 1
// Postcondicion R : {max r : (vector<int> a : 0 <= p < q < v.size() : (a[p] - a[q] && a[0] == 1 ) || (a[q] - a[p] && a[0] != 1))}
// El coste de la función en el peor de los casos es O(N) donde N es el número de páginas

int alcance(vector<int> v) {
	int rest = 0, max = -300000;
	//Si empieza en la página 1 el alcance sería -1
	if (v[0] == 1) {
		for (int i = v.size() - 2; i >= 0; i--) {
			rest = v[i] - v[i + 1];
			if (rest > max) {
				max = rest;
			}
		}
	}
	//Si empieza en otra página el alcance sería n - 1
	else {
		for (int i = 1; i < v.size(); i++) {
			rest = v[i] - v[i - 1];
			if (rest > max) {
				max = rest;
			}
		}
	}
	return max;
}

void resuelveCaso() {
	int pag;
	cin >> pag;
	vector<int> v(pag);
	for (int i = 0; i < pag; i++) cin >> v[i];
	cout << alcance(v) << endl;
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