#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 <= k < a.size() <= 100000 : 0 < v[k] <= 10^9}
//Invariante I: {vector<int> a : 0 <= k < a.size()-1 : a[k] == sumatorio (k+1 <= l < a.size() : a[l]) : int pos = k}
//Función de cota C : i - N + 1
//Postcondición R: {bool b = (int p = k : vector<int> a : 0 <= k < a.size() : a[k] == sumatorio (k+1 <= l < a.size() : a[l]) && max(a[k]))}

void tapon(vector<int> v, int& pos) {
	int sum = v[v.size() - 1];
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] == sum) {
			if (pos == v.size() - 1) pos = i;
			else if (v[i] > v[pos]) pos = i;
		}
		sum += v[i];
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int pos = N -1;
	tapon(v, pos);
	if (pos != N - 1) cout << "SI " << pos + 1 << endl;
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