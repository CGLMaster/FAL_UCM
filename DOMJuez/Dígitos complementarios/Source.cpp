#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

// Q { num >= 0 }
// R { complemetario() >= 0 && invertido() >= 0 } donde invertido() es una funcion que invierte el numero introducido y complementario() el número complementario al introducido
// El coste de la funcion en el peor de los casos es O(N) donde N es el número de cifras del numero
int complementario(int num, int cont) {
	int comp = 0, aux = 0, aux2 = 0, resta = 0;
	for (int i = cont - 1; i >= 0; i--) {
		aux = (num - aux2) / (pow(10, i));
		resta = 9 - aux;
		comp += (resta * pow(10, i));
		aux2 += (aux * pow(10, i));
	}
	return comp;
}

int invertido(int num, int cont) {
	int inver = 0, aux = num;
	int j = 0, aux2 = 0;
	for (int i = cont - 1; i >= 0; i--) {
		aux = (num - aux2) / (pow(10, i));
		inver += (aux * pow(10, j));
		aux2 += (aux * pow(10, i));
		j++;
	}
	return inver;
}


void resuelveCaso() {
	int num;
	cin >> num;
	bool acabo = false;
	int aux = num, cont = 0;
	while (!acabo) {
		if (aux > 0) cont++;
		else acabo = true;
		aux = aux / 10;
	}
	if (num == 0) cont++;
	int comp = complementario(num, cont);
	cout << comp << " " << invertido(comp, cont) << endl;
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
