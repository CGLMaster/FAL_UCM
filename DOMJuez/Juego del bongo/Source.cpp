#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Creciente(vec) = {forall i: 0 <= i < vec.size()-1 : vec[i] < vec[i+1]}
//noConsecutivo(vec) = {forall i: 0 <= i < vec.size()-1 : vec[i] != vec[i+1] + 1}
//Precondicion: {forall k: 0 < k < vec.size() && creciente(vec) && noConsecutivo(vec)}
//func bongo(vector<int> vec, int i, int f, int x) dev int
//Postcondicion:{n = E k: ( 0 <= k < vec.size() : vec[i] == x+i)

/*Analisis del coste:
	T(n){
		T(n) = c0 si n = 0
		T(n) = T(n/2) + c1 si n >= 1
	}

	T(n) es del orden de O(log(n)) por el teorema de la division
*/

int bongo(vector<int> const &v, const int c, int ini, int fin) {
	int mitad = -1;
	if (ini + 1 == fin) {
		if (ini + c == v[ini]) return v[ini];
		else return -1;
	}
	else {
		mitad = (ini + fin) / 2;
		if (v[mitad] == c + mitad) return v[mitad];
		else if (v[mitad] < c + mitad) return bongo(v, c, mitad, fin);
		else return bongo(v, c, ini, mitad);
	}
}

void resuelveCaso() {
	int N, cantado;
	cin >> N >> cantado;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	int num = bongo(v, cantado, 0, N);
	if (num != -1) cout << num << endl;
	else cout << "NO" << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}