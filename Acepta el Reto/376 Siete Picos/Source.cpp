#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 2 <= a.size() <= 1000 && 0 <= k < a.size() : a[k] < 1000}
//Invariante I: {int cont : vector<int> v : 0 <= i < v.size() : primero = v[0] , ultimo = v[v.size()-1] : (i = 0 : primero > ultimo && primero > v[i+1] : cont++)
//				&& (i+1 = v.size() : v[i] > v[i-1] && v[i] > primero : cont++ ) && (v[i] > v[i - 1] && v[i] > v[i + 1] : cont++)}
//Función de cota C : N - i
//Postcondición R: {# p : vector<int> a : 0 < k < a.size() : a[k] > a[k-1] && a[k] > a[k+1]}

int numPicos(vector<int> v) {
	int primero = v[0], ultimo = v[v.size()-1];
	int cont = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			if (primero > ultimo && primero > v[i + 1]) cont++;
		}
		else if (i + 1 == v.size()) {
			if (v[i] > v[i - 1] && v[i] > primero) cont++;
		}
		else if (v[i] > v[i - 1] && v[i] > v[i + 1]) cont++;
	}
	return cont;
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int picos = numPicos(v);
	cout << picos << endl;
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