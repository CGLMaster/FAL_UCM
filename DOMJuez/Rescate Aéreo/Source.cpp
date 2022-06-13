#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 < i < N && existe t : t < v[i] }
// I { 0 < i <= k < N : sumatorio de v donde ini es el comienzo (i) y fin el final (k) del sumatorio : v[k] >= v[i] > t && cont > contGanador entonces se actualiza el intervalo} donde cont es el tamaño del
// intervalo actual y contGanador del más grande
// C : N - 1
// R { 0 <= ini <= fin < numEdificios }
// El coste de la funcion en el peor de los casos es O(N), donde N es el tamaño del vector
void intervalo(int& ini, int& fin, vector<long unsigned int> v, int t) {
	bool inicial = false;
	int cont = 0, contGanador = 0, final = 0, inic = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > t && !inicial) {
			inic = i;
			cont++;
			inicial = true;
			final = i;
		}
		else if (v[i] > t) {
			final = i;
			cont++;
		}
		else {
			if (cont > contGanador) {
				ini = inic;
				fin = final;
				contGanador = cont;
			}
			inicial = false;
			cont = 0;
		}
	}
	if (cont > contGanador) {
		ini = inic;
		fin = final;
	}
}

void resuelveCaso() {
	int numEdificios, t, ini = 0, fin = 0;
	cin >> numEdificios >> t;
	vector<long unsigned int> v(numEdificios);
	for (int i = 0; i < numEdificios; i++) cin >> v[i];
	intervalo(ini, fin, v, t);
	cout << ini << " " << fin << endl;
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
