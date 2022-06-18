#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {0 < desMax < 1000000 && vector<int> a : 1 < a < 200000 && 0 <= k < a.size() : forall k : 0 < a[k] < 1000000}
//Invariante I: {(vector<int> a : 0 < k < a.size()) && ((a[k-1] >= a[k] : m = a[k]) || (noApto = a[k] - m > desMax))}
//Función de cota C : N - i - 1
//Postcondición R: {apta = (vector<int> a : 0 <= k < a.size() : (min m : a[k]) : a[k] - m > desMax)}
// El coste de la función en el peor de los casos es O(N) donde N es el número de cotas

bool esApta(vector<int> v, int desMax) {
	int min = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] >= v[i]) min = v[i];
		if (v[i] - min > desMax) return false;
	}
	return true;
}


bool resuelveCaso() {
	int desMax, N;
	cin >> desMax;
	if (!cin) return false;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (esApta(v, desMax)) cout << "APTA" << endl;
	else cout << "NO APTA" << endl;
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