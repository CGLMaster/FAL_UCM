#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Apartado 1: todosPares(v,p,q) : { res = { 0 <= p <= k <= q < v.size() : forall i : v[i] % 2 == 0}}

// Apartado 2: funcion(v) : {# m : 0 <= p <= q < v.size() : todosPares(v,p,q) }
 
// Apartado 3:

int segmentosVacios(vector<int> v) {
	int num = 0;
	bool par = false;
	int cont = 0;
	if (v.size() > 0) {
		for (int i = v.size()-1; i >= 0; i--) {
			if (v[i] % 2 == 0 && par) {
				cont++;
				num += cont;
			}
			else if (v[i] % 2 == 0) {
				cont++;
				num++;
				par = true;
			}
			else {
				cont = 0;
				par = false;
			}
		}
	}
	return num;
}

// Apartado 4:
//		Invariante I : {0 < v.size() && 0 <= i <= v.size() - 1  && num += (# cont : v[i]%2 == 0 && par)) && num += (# cont : par = (v[i] % 2 == 0)) }
//		Funcion de cota C : i

// Apartado 5: El coste de la función en el peor de los casos es O(N) donde N es el número de elementos a comprobar del vector

void resuelveCaso() {
	int num;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; i++) cin >> v[i];
	int c = segmentosVacios(v);
	cout << c << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
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
