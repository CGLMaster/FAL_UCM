// NOMBRE Y APELLIDOS
// CARLOS GOMEZ LOPEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// T(c){ O(1) if n == 1
//		 O(1) if n == 2
//		 O(N) if n > 2
// }
// El coste de la función en el peor de los casos es O(N) donde N es el tamaño del vector
// Q :{ (ParaTodo k : 0 <= k < v.size()) && (0 <= x : col == 2^x) }
// R :{
bool degradado(const vector<int>& v, int ini, int fin, int& total) {
	if (ini == fin - 1) return true;
	else if (ini + 2 == fin) {
		total = v[ini] + v[fin - 1];
		return v[ini] < v[fin - 1];
	}
	else {
		int mitad = (ini + fin) / 2;
		bool der, izq;
		int totalDer = 0, totalIzq = 0;
		der = degradado(v, ini, mitad, totalDer);
		izq = degradado(v, mitad, fin, totalIzq);
		total = totalDer + totalIzq;
		return der && izq && totalDer < totalIzq;
	}
}

bool esUnDegradado(const vector<vector<int>>& v) {
	int i = 0, total = 0;
	bool deg = true;
	while (i < v.size() && deg) {
		deg = degradado(v[i], 0, v[i].size(), total);
		total = 0;
		i++;
	}
	return deg;
}

bool resuelveCaso() {
	int N, M;
	cin >> N >> M;
	if (!cin) return false;
	vector<vector<int>> v(N);
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			v[i].push_back(num);
		}
	}

	if (esUnDegradado(v)) cout << "SI\n";
	else cout << "NO\n";
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