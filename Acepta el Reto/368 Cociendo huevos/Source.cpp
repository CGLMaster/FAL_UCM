#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {int m : 1 <= m <= 10000 && int l : 1 <= l <= 1000}
//Invariante I: {}
//Función de cota C : N - i
//Postcondición R: {}
// El coste de la función en el peor de los casos es O(N) donde N es el número de tiempos

int tiempoCocion(int h, int c) {
	int t = 0;
	while (h > c) {
		t += 10;
		h -= c;
	}
	t += 10;
	return t;
}

bool resuelveCaso() {
	int h, c;
	cin >> h >> c;
	if (h == 0 && c == 0) return false;
	int n = tiempoCocion(h, c);
	cout << n << endl;
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