#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 <= k < a.size() <= 10000 : 0 <= a[k] <= 99999}
//Invariante I: {vector<int> a : 0 <= k < a.size() : a[i] % 2 == 0}
//Función de cota C : N - i
//Postcondición R: {#p : vector<int> a : 0 <= k < a.size : a[k]%2 == 0}

int numPares(vector<int> v) {
	int cont = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) cont++;
	}
	return cont;
}

void resuelveCaso() {
	int N; 
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int n = numPares(v);
	cout << n << endl;
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