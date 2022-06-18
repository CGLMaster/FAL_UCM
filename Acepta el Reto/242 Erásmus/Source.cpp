#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> n : 1 <= n.size() <= 100000 && int m : 1 <= m < n.size() : v[m] < 10^9}
//Invariante I: {}
//Función de cota C : i + 1
//Postcondición R: {#p : vector<int> n : 0 <= k < n.size() : v[k]*sumatorio(v[k+1])}
// El coste de la función en el peor de los casos es O(N) donde N es el número de personas

long long int numeroParejas(vector<int> v) {
	int cont = 0;
	if (v.size() != 0) {
		long long int sum = v[v.size() - 1];
		for (int i = v.size() - 2; i >= 0; i--) {
			cont += v[i] * sum;
			sum += v[i];
		}
	}
	return cont;
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) return false;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long int p = numeroParejas(v);
	cout << p << endl;
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