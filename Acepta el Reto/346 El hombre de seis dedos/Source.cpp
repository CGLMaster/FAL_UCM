#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Precondicion Q : {vector<int> a : 1 < a.size() < 200000 && A > 0}
// Invariante I : {(vector<int> a : 0 <= k <= a.size() - 1) && (end = (0 <= k <= fin < a.size() : abs(a[k] - a[fin]) >= A) : fin--) && int mayor = (end = (fin + 1 - k > mayor) : mayor = fin + 1 - k)}
// Funcion de cota C : i
// Postcondicion R : {max p : (vector<int> a : 0 <= k < fin < a.size() : fin - i && a[k] - a[fin] >= A)}

int personas6D(vector<int>& v, int A) {
	int mayor = 0, fin = v.size()-1;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (abs(v[i] - v[fin]) >= A) {
			fin--;
		}
		if (fin + 1 - i > mayor) {
			mayor = (fin + 1 - i);
		}
	}
	return mayor;
}

bool resuelveCaso() {
	int N, A;
	cin >> N >> A;
	if (N == 0 && A == 0) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << personas6D(v, A) << endl;
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