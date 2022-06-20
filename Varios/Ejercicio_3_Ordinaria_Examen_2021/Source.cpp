#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Código de beleen3103

typedef struct {
	vector<vector<double>> distancia;
	vector<vector<int>> allegados;
}tDatos;

bool esValido(tDatos const& datos, vector<int> const& solProv, int& parejasProv, const int& parejas, const int& etapa, const int& m, int& parejasNuevas, vector<int>const& poda) {
	int i = 0;
	bool correcto = true;
	for(int i = 0; i < etapa ; i++){
		if (datos.distancia[solProv[etapa]][solProv[i]] < 2 && datos.allegados[etapa][i] == 1) {//si son allegados y estan a menos de dos metros
			parejasNuevas++;
		}
		else if (datos.distancia[solProv[etapa]][solProv[i]] < 2 && datos.allegados[etapa][i] == 0) { // si la distancia es menor que 2 y no son allegados
			correcto = false;
		}
	}
	if (etapa != m - 1) {
		if (poda[etapa] + parejasProv + parejasNuevas <= parejas) correcto = false; //si las posibles parejas que quedan + las que tenemos no son mayores que el maximo, no es solucion
	}
	else if (parejasProv + parejasNuevas <= parejas) correcto = false;

	return correcto;
}

void esSolucion(const int& parejasProv, int& parejas) {
	parejas = parejasProv;
}

void resolver(tDatos const& datos, //distancias y allegados
	const int& n, //sitios
	const int& m, //comensales
	vector<bool> ocupados, // asientos ya ocupados
	vector<int>solProv, //posicion = comensal, contenido = plaza
	int parejasProv, //solucion provisional
	int& parejas, //solucion
	const int& etapa,//comensales
	vector<int> const& poda //el comensal m tiene parAlleg[m] allegados
) {
	int nuevas;
	for(int i = 0; i < n; i++) //recorremos todos los comensales;
	{
		if (!ocupados[i]) {//comprobamos que la plaza no esta ocupada
			solProv[etapa] = i; //el comensal se sienta en la plaza i
			nuevas = 0; //nuevas parejas allegadas
			if (esValido(datos, solProv, parejasProv, parejas, etapa, m, nuevas, poda)) { //devolvemos si es valido y las nuevas parejas allegadas
				ocupados[i] = true;
				parejasProv += nuevas;
				if (etapa == m - 1) esSolucion(parejasProv, parejas); //actualizamos el numero de parejas maximo
				else resolver(datos, n, m, ocupados, solProv, parejasProv, parejas, etapa + 1, poda);
				parejasProv -= nuevas;
				ocupados[i] = false;
			}
		}

	}
}
void resuelveCaso() {
	//resuelve aqui tu caso
	int n, m, aux;
	tDatos datos;
	//Lee los datos

	cin >> n >> m;
	vector<vector<double>> auxdist(n, vector<double>(n));
	vector<vector<int>> auxAlleg(m, vector<int>(m));
	vector<int> parAlleg(m, 0); //comensal pos tiene parAlleg[pos] allegados

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> auxdist[i][j];

		}
	}
	datos.distancia = auxdist;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> auxAlleg[i][j];
			if (auxAlleg[i][j] == 1) parAlleg[i]++;
		}
	}
	vector<int> poda(m, 0);
	for (int i = parAlleg.size() - 2; i >= 0; i--) {
		poda[i] = parAlleg[i + 1] + poda[i + 1];
	}
	datos.allegados = auxAlleg;
	//Calcula el resultado
	int parejasProv = 0, parejas = -1;
	vector<int> solProv(m);
	vector<bool> ocupados(n, 0);
	if (m > 1) resolver(datos, n, m, ocupados, solProv, parejasProv, parejas, 0, poda);
	else if (m == 1) parejas = 0;
	if (parejas == -1) cout << "CANCELA\n";
	else cout << "PAREJAS " << parejas << "\n";
	//Escribe el resultado
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