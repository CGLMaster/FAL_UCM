#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 <= D <= 1000000 && 1 <= N <= 200000 && 0 <= i < N : 0 <= v[i] <= 1000000 }
// I { 0 <= i < N && apto : (true --> v[i] - menor <= D : v[i] < v[i-1] = menor : v[i] > v[i-1] = mayor) || false --> v[i] - menor > D }
// C : N - i
// R { esApta() : True --> APTA || False --> NO APTA }
bool esApta(vector<int> v, int D) {
	int menor, mayor;
	bool apto = true;
	int i = 1;
	menor = v[0];
	while (i < v.size() && apto) {
		if (v[i - 1] >= v[i]) {
			menor = v[i];
		}
		else mayor = v[i];
		if (v[i] - menor > D) apto = false;
		i++;
	}
	return apto;
}


bool resuelveCaso() {
	int D, N;
	cin >> D >> N;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (esApta(v, D)) cout << "APTA" << endl;
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
