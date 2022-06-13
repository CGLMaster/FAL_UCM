//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Q { true }
//R { boolean movil() : TRUE (pi*di == pd*dd && izq && der)} Donde pi, di, pd, dd es el peso y la distancia de la parte de arriba del movil, e izq es el booleano que indica si el lado izquierdo esta equilibrado
// y der el booleano que indica si el lado derecho está equilibrado

//El coste de la funcion en el peor de los casos es O(log(N)) donde N es el número de zonas a comprobar del móvil 
bool movil(int pi, int di, int pd, int dd, int&total) {
	//Comprueba si se cumple que pi*di = pd*dd
	if (pi != 0 && pd != 0) {
		if (pi * di == pd * dd) {
			total = pi + pd;
			return true;
		}
		else return false;
	}
	bool izq = true, der = true;
	//Se comprueba el lado izquierdo
	if (pi == 0) {
		int p1, d1, p2, d2;
		cin >> p1 >> d1 >> p2 >> d2;
		izq = movil(p1, d1, p2, d2, total);
		pi = total; // Se guarda el total de ese lado como el peso de ese lado
	}
	//Lo mismo para el lado derecho
	if (pd == 0) {
		int p1, d1, p2, d2;
		cin >> p1 >> d1 >> p2 >> d2;
		der = movil(p1, d1, p2, d2, total);
		pd = total;
	}
	total = pi + pd;
	return (izq && der && (pi * di == pd * dd));//Tiene que haberse cumplido el equilibrio del lado izquierdo y derecho, y con los pesos ya calculados, el actual
}

void resuelveCaso() {
	int pi, di, pd, dd, total = 0;
	cin >> pi >> di >> pd >> dd;
	if (movil(pi, di, pd, dd, total)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
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