#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondici�n Q: {0 <= p <= 200000 && 0 <= n <= 100000 && forall k : 0 <= k < n : 0 < v[k] <= 1000}
//Postcondici�n R: { \(;-;)/ }
// An�lisis de coste:
//	T(n){
//		c0				si n = 1
//		2T(n/2) + c1*(n^k)  si n > 1
//		}
//	Entonces a traves del teorema de la divisi�n, a = 2, b = 2, k = 1, entonces a = b^k --> O((N^k) * log(N)) --> O((N^1) * log(N))
//	El coste de la funci�n en el peor de los casos es de O(N*log(K)) donde N es el n�mero de instrumentos y K el n�mero de partituras


int reparto(const vector<int>& v, int p, int n, int ini, int fin, int& numMusicos) {
	int izq, der;
	if (ini == fin) {
		izq = v[ini];
	}
	else {
		int m = (ini + fin) / 2;
		// Busco por el lado izquierdo de la partici�n
		izq = reparto(v, p, n, ini, m, numMusicos);
		// Busco por el lado derecho de la partici�n
		der = reparto(v, p, n, m + 1, fin, numMusicos);
		// Me guardo el lado que contiene el valor m�s grande
		if (izq < der) izq = der;
		// Realizo una b�squeda binaria sobre la cantidad de partituras para obtener el valor de un atril m�ximo en concreto
		if ((fin - ini) == (n - 1)) {
			numMusicos = izq;
			int aux = 1, max, need;
			while (aux <= izq) {
				max = (izq + aux) / 2;
				need = 0;
				for(int i = 0; i < n; i++) need += (v[i] + max - 1) / max;
				// En el caso de que el atril se pueda obtener disminuimos izq y guardamos esa cantidad m�xima del atril
				if (need <= p) {
					izq = max - 1;
					numMusicos = max;
				}
				// Si se pasa de partituras no se puede conseguir ese atril y se prueba con otro
				else aux = max + 1;
			}
		}
	}
	return izq;
}

bool resuelveCaso() {
	int p, n;
	cin >> p >> n;
	if (!cin) return false;
	vector<int> instrumentos(n);
	int numMusicos = 0;
	if (p == n) {
		for (int i = 0; i < n; i++) {
			cin >> instrumentos[i];
			if (instrumentos[i] > numMusicos) numMusicos = instrumentos[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) cin >> instrumentos[i];
		int r = reparto(instrumentos, p, n, 0, n - 1, numMusicos);
	}
	cout << numMusicos << endl;
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