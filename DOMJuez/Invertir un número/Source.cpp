#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// Q { num > 0 }
// R { invertido() > 0 } donde invertido() es una funcion que invierte el numero introducido
// El coste de la funcion en el peor de los casos es O(N) donde N es el número de cifras del numero
int invertido(int num) {
	int inver = 0, cont = 0, aux = num;
	bool acabo = false;
	while (!acabo) {
		if (aux > 0) cont++;
		else acabo = true;
		aux = aux / 10;
	}
	int j = 0, aux2 = 0;
	for (int i = cont - 1; i >= 0; i--) {
		aux = (num - aux2)/(pow(10,i));
		inver += (aux * pow(10, j));
		aux2 += (aux*pow(10,i));
		j++;
	}
	return inver;
}


bool resuelveCaso() {
	int num;
	cin >> num;
	if (num == 0) return false;
	cout << invertido(num) << endl;
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
