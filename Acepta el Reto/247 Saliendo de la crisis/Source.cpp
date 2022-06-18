#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 < k < a.size() <= 100 : forall k : 1 <= k <= 10000000}
//Invariante I: {vector<int> a : 1 <= k : a.size() : forall k : v[k - 1] < v[k]}
//Función de cota C : N - i + 1
//Postcondición R: {bool p  = (vector<int> a : 1 <= k : a.size() : forall k : v[k - 1] < v[k])}
// El coste de la función en el peor de los casos es O(N) donde N es el número de valores económicos medidos

bool razonAbeja(vector<int> v) {
	if (v.size() > 1) {
		for (int i = 1; i < v.size(); i++) {
			if (v[i - 1] >= v[i]) return false;
		}
	}
	return true;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (razonAbeja(v)) cout << "SI" << endl;
	else cout << "NO" << endl;
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