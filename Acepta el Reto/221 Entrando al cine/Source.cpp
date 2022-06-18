#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 <= a.size <= 10000}
//Invariante I: {vector<int> a : 0 <= l < k < a.size() : (forall l : v[l] % 2 == 0 ) && (forall k : v[k] % 2 != 0)}
//Función de cota C : i - N
//Postcondición R: {bool b : (true : vector<int> a : 0 <= l < k < a.size() : (forall l : v[l] % 2 == 0 ) && (#p , forall k : v[k] % 2 != 0))}
// El coste de la función en el peor de los casos es O(N) donde N es el número de elementos

bool condicionRamiro(vector<int> v, int& n) {
	bool pares = false;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] % 2 != 0 && !pares) n++;
		else if (v[i] % 2 != 0 && pares) return false;
		else pares = true;
	}
	return true;
}

void resuelveCaso() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	
	int num = 0;
	if (condicionRamiro(v, num)) cout << "SI " << num << endl;
	else cout << "NO" << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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