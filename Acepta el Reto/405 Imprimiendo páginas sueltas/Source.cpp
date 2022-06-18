#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Precondicion Q : {vector<int> a : 0 < a.size() <= 10^9}
// Invariante I : {(vector<int> a : 1 <= k < a.size()) && ini, fin : (begin = (a[k-1] + 1 == a[k] && !primero) : ini = a[k-1] && fin = a[k] && primero = true)
//					&& (end = (a[k-1] + 1 == a[k] && primero) : fin = a[k]) && other = ((only = (ini == fin) : ini) && (more = (ini != fin) : ini, fin) && ini = a[k] && fin = a[k] && primero = false)}
// Funcion de cota C : N - i - 1
// Postcondicion R : { a[p], a[q] : 0 <= p <= q < a.size() : forall p,q : a[p] + 1 == a[q]}
// El coste de la funcion en el peor de los casos es O(N) donde N es el número de páginas

void mostrarPaginas(vector<int> v) {
	int ini = v[0], fin = v[0];
	bool primero = false;
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] + 1 == v[i] && !primero) {
			ini = v[i - 1];
			fin = v[i];
			primero = true;
		}
		else if (v[i - 1] + 1 == v[i] && primero) {
			fin = v[i];
		}
		else {
			if (ini == fin) cout << ini;
			else cout << ini << "-" << fin;
			cout << ",";
			ini = v[i];
			fin = v[i];
			primero = false;
		}
	}
	if (ini == fin) cout << ini;
	else cout << ini << "-" << fin;
	cout << endl;
}

bool resuelveCaso() {
	int num;
	vector<int> v;
	cin >> num;
	if (num == 0) return false;
	while (num != 0) {
		v.push_back(num);
		cin >> num;
	}
	mostrarPaginas(v);
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