//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 <= p < N }
// I { 0 <= i <= p < N AND mayor < menor } donde mayor es el mayor de los números antes de la posición indicada, y menor el número más pequeño después de la posición
// FuncionCota : N - p
// R {boolean dividido: true --> (sumatorio de v de 0 a p < sumatorio de p+1 a N-1)  || (p+1 = N) : false --> sumatorio de v de 0 a p >= sumatorio de p+1 a N-1 }
// El coste de la funcion en el peor de los casos es O(N), donde N es el tamaño del vector
void resuelveCaso() {
	int N, p;
	cin >> N >> p;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	bool dividido = true;
	int menor = 0;
	int mayor = v[0];
	if (p + 1 != N) {
		for (int i = 0; i <= p; i++) {
			if (mayor < v[i]) mayor = v[i];
		}
		menor = v[p + 1];
		for (int i = p + 1; i < N; i++) {
			if (menor > v[i]) menor = v[i];
		}
		if (mayor >= menor) dividido = false;
	}
	if (dividido) cout << "SI" << endl;
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