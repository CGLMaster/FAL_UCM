#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void resuelveCaso() {
	vector<string> v(2);
	for (int i = 0; i < 2; i++) {
		cin >> v[i];
	}
	cout << "Hola, " << v[1] << "." << endl;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}