//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<int>& super, const vector<bool>& prods, int pos, int i) {
	if (prods[pos]) return false; //Si dicho producto ya se ha cogido en otro supermercado, se devuelve false
	if (super[i] >= 3) return false; //Si has cogida ya 3 productos en un supermercado, no puedes coger más de él
	return true;
}

void hacerCompra(const vector<vector<int>>& compra, int numSuper, int numProds, int cont, int& total, int& precioActual, vector<int>& super, vector<bool>& prods, const vector<int>& acumulados, bool& sePuede) {
	for (int i = 0; i < numSuper; i++) {
		if (esValida(super, prods, cont, i)) {
			precioActual += compra[i][cont];
			prods[cont] = true;
			super[i]++;
			if (cont == numProds - 1) {
				if (precioActual < total) {
					total = precioActual;
					sePuede = true;
				}
			}
			else {
				//Si el precio que se lleva hasta entonces + lo posible más pequeño a partir de ahí es menor que el guardado en total entonces se llama recursivamente, si no, se mantiene dicho total, y ahorras recursion
				if(acumulados[cont+1]+precioActual < total) hacerCompra(compra, numSuper, numProds, cont + 1, total, precioActual, super, prods, acumulados, sePuede);
			}
			precioActual -= compra[i][cont];
			prods[cont] = false;
			super[i]--;
		}
	}
}

void resuelveCaso() {
	int super, prod;
	cin >> super >> prod;
	vector<vector<int>> compra(super, vector<int>(prod));
	for (int i = 0; i < super; i++) {
		for (int j = 0; j < prod; j++) {
			cin >> compra[i][j];
		}
	}
	vector<int> supermercado(super);
	vector<bool> productos(prod);
	vector<int> minimos(prod);
	
	//Obtienes los mínimos de cada producto
	for (int i = 0; i < prod; i++) {
		minimos[i] = compra[0][i];
		for (int j = 0; j < super; j++) {
			if (minimos[i] > compra[j][i]) minimos[i] = compra[j][i];
		}
	}
	//Con acumulados voy a obtener la acumulacion del más pequeño posible en cada una de las columnas, de la última a la primera
	vector<int> acumulados(prod);
	acumulados = minimos;
	for (int i = minimos.size() - 2; i > -1; i--) acumulados[i] = acumulados[i + 1] + minimos[i];
	int total = 1000000;
	int precioActual = 0;
	bool sePuede = false;
	hacerCompra(compra, super, prod, 0, total, precioActual, supermercado, productos, acumulados, sePuede);
	if (!sePuede) cout << "Sin solucion factible\n";
	else cout << total << endl;
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