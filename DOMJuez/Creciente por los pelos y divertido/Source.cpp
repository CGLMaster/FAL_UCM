//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 0 <= N <= 1000 && div > 0 }
// I { 0 <= i < N && boolean resultado : (True --> v[i] - v[i-1] = 1 && v[i] > v[i-1] && sumatorio todos los numeros iguales (cont) <= div) || False: resto de casos }
// C : N - i
// R { Boolean esDiverYporPelos() : True --> SI || False --> NO }
//El coste de la funcion en el peor de los casos es de O(N), donde N es el número de elementos del vector
bool esDiverYporPelos(vector<int> v, int diver) {
	bool resultado = true;
	int i = 1, cont = 1;
	while (i < v.size() && resultado) {
		if (v[i - 1] == v[i]) cont++;
		else { cont = 1; }
		if (v[i - 1] > v[i] || v[i] - v[i - 1] > 1 || cont > diver) {
			resultado = false;
		}
		i++;
	}
	return resultado;
}

void resuelveCaso() {
	int div, N;
	cin >> div >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	if (esDiverYporPelos(v, div)) cout << "SI" << endl;
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