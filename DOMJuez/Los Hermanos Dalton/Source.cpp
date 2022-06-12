// NOMBRE Y APELLIDOS
// CARLOS GOMEZ LOPEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Q { 2 <= N <= 100000 and 1 <= v[i] <= 10^6 }
// I {existe i: 1 <= i <= n : |v[i] - v[i-1]| = 1 }
// FuncionCota : N-i 
// R {Boolean dalton : True --> v[i-1] > v[i] || v[i-1] < v[i] : False --> v[i-1] <= v[i] || v[i-1] >= v[i]}
// El coste de la funcion en el peor de los casos es O(N), donde N es el número de alturas que hay en una fila
bool resuelveCaso() {
	int N;
	cin >> N;
	if (N <= 0) return false;
	vector<int> v(N);
	bool dalton = true, creciente = false, decreciente = false;
	int i = 1;
	for (int j = 0; j < N; j++) {
		cin >> v[j];
	}
	if (v[i - 1] > v[i]) decreciente = true;
	else if (v[i - 1] < v[i]) creciente = true;
	else dalton = false;
	while (i < N && dalton) {
		if (decreciente) {
			if (v[i - 1] <= v[i]) dalton = false;
		}
		else if (creciente) {
			if (v[i - 1] >= v[i]) dalton = false;
		}
		i++;
	}
	if (dalton && N >= 2) cout << "DALTON" << endl;
	else cout << "DESCONOCIDOS" << endl;
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