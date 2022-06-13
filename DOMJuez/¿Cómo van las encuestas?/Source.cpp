#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 < N < 1000 }
// I { 0 <= i < N : v[i] != menor && 0 <= i < N : sum += mayores[i]} donde menor es el número más pequeño del vector y maypres es un vector donde se guardan los valores más grandes
// C : N - 1
// R { sum = sumatorio() && 0 <= cont < N }
// El coste de la funcion en el peor de los casos es O(N), donde N es el tamaño del vector
long long int sumatorio(vector<long long int> v, int& cont, long long int menor) {
	long long int sum = 0;
	vector<long long int> mayores;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != menor) {
			mayores.push_back(v[i]);
			cont++;
		}
	}
	for (int i = 0; i < mayores.size(); i++) {
		sum += mayores[i];
	}
	return sum;
}



void resuelveCaso() {
	int N, cont = 0;
	long long int menor = 2147483647;
	cin >> N;
	vector<long long int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (menor > v[i]) menor = v[i];
	}
	long long int sum = sumatorio(v, cont, menor);
	cout << sum << " " << cont << endl;
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
