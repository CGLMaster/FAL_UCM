#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

char fugado(const vector<char>&v, int start, int N, char ini, char fin) {
	if (start + 1 == N) { //comprueba recursivamente si el inicial y el ultimo estan a uno de distancia
		if (v[start] == ini) return v[start] + 1; //si es igual a la primera, entonces se devuelve la siguiente
		else return v[start] - 1; //si es igual a la ultima, se devuelve la anterior
	}
	else {
		if (v[start] != ini) return ini; // si es el primer recluso el fugado
		else if (v[N - 1] != fin) return fin; // si es el segundo recluso fugado
		
		int mitad = (start + N) / 2;

		if (v[mitad] - v[start] == mitad - start) return fugado(v, mitad, N, v[mitad], fin);  // comprueba si la distancia entre las letras del abecedario son las mismas que la distancia entre las posiciones
		else return fugado(v, start, mitad, ini, v[mitad]);
	}
}


void resuelveCaso() {
	char ini, fin;
	cin >> ini >> fin;
	int N = fin - ini;
	vector<char> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << fugado(v, 0, N, ini, fin) << endl;
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
