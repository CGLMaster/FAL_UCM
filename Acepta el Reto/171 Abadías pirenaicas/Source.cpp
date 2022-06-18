#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 < a.size() < 100000}
//Invariante I: { vector<int> a : 0 <= k < l < a.size()-2 : v[k] > v[l]}
//Función de cota C : i - N - 1
//Postcondición R: {#p : vector<int> a : 0 <= k < l < a.size() : forall k : v[k] > v[l]}
//El coste de la función en el peor de los casos es O(N) donde N es el número de picos


int abadias(vector<int> v) {
	int cont = 1, max = v[v.size() - 1];
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] > max) {
			cont++;
			max = v[i];
		}
	}
	return cont;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0)return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int n = abadias(v);
	cout << n << endl;
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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