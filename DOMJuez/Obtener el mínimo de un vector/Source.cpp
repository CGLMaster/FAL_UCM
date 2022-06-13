#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// El coste de la funcion en el peor de los casos es O(log(N)), donde N es el número de elementos del vector 
int minimo(vector<int> const v, int ini, int fin) {
	int mitad = 0;
	if (ini + 1 == fin) return v[ini];
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] > v[ini]) return minimo(v, ini, mitad);
		else return minimo(v, mitad, fin);
	}
}

/*
Otra función que había hecho que salía bien el resultado, pero no tiene coste log(N) "creo"

int minimo(vector<int> const v, int ini, int fin) {
	if (v[fin] - v[ini] == 0) {
		if (v[fin] > v[ini]) return v[ini];
		else return v[fin];
	}
	else {
		if (v[ini] > v[fin]) return minimo(v, ini + 1, fin);
		else return minimo(v, ini, fin - 1);
	}
}
*/

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << minimo(v, 0, N) << endl;
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
