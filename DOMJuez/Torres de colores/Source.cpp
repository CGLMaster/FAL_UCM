#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//El coste de la funcion en el peor de los casos es O(N^H), donde H es la altura de la torre y N el número de colores, en este caso siempre son 3 colores
bool esValida(const vector<string>& torre, int cont, int numAzul, int numVerde) {
	//Caso en el que haya dos verdes seguidos
	if (torre[cont] == "verde" && torre[cont - 1] == "verde") return false;
	//Caso en el que la cantidad de bloques verdes sea mayor que la de azules
	else if (numVerde > numAzul) return false;
	return true;
}

void construir(int h, vector<int>& colores, vector<string>& torre, int cont, int& numAzul, int& numRojo, int& numVerde, bool& sePuede) {
	for (int i = 0; i < colores.size(); i++) {
		if (colores[i] > 0) {
			switch (i) {
				case 0: {
					torre[cont] = "azul";
					numAzul++;
				}break;
				case 1: {
					torre[cont] = "rojo";
					numRojo++;
				}break;
				case 2: {
					torre[cont] = "verde";
					numVerde++;
				}break;
			}
			if (esValida(torre, cont, numAzul, numVerde)) {
				colores[i]--;
				//Caso base
				if (cont == h - 1) {
					//Caso en el que la cantidad de bloques rojos es superior a la de los otros dos juntos
					if (numRojo > (numAzul + numVerde)) {
						for (int j = 0; j < torre.size(); j++) cout << torre[j] << " ";
						cout << endl;
						sePuede = true;
					}
				}
				//Si no se continúa construyendo la torre recursivamente, y se devuelve el color que se había disminuido
				else construir(h, colores, torre, cont + 1, numAzul, numRojo, numVerde, sePuede);
				colores[i]++;
			}
			switch (i) {
			case 0: {
				numAzul--;
			}break;
			case 1: {
				numRojo--;
			}break;
			case 2: {
				numVerde--;
			}break;
			}
		}
	}
}

bool resuelveCaso() {
	int h, a, r, v;
	cin >> h >> a >> r >> v;
	if (h == 0 && a == 0 && r == 0 && v == 0) return false;
	vector<int> colores(3);
	colores[0] = a;
	colores[1] = r;
	colores[2] = v;
	vector<string> torre(h);
	torre[0] = "rojo";
	colores[1]--;
	bool sePuede = false;
	int numAzul = 0, numRojo = 1, numVerde = 0;
	construir(h, colores, torre, 1, numAzul, numRojo, numVerde, sePuede);
	if (!sePuede) cout << "SIN SOLUCION\n";
	cout << endl;
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
