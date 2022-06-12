#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Precondición Q: {vector<int> a : 0 <= k < a.size() : forall k : 0 < v[k] <= 10^9}
//Invariante I: {int l : vector<int> a : 0 <= k < a.size() : l = max(l,v[k])}
//Función de cota C : N - i
//Postcondición R: {max l : vector<int> a : 0 <= k < a.size() : v[k]}

int maxVelocidad(vector<int> v) {
	int maxi = 0;
	for (int i = 0; i < v.size(); i++) {
		maxi = max(maxi, v[i]);
	}
	return maxi;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int max = maxVelocidad(v);
	cout << max << endl;
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while(resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}