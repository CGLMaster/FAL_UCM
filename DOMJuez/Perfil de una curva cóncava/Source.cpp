// NOMBRE Y APELLIDOS
// CARLOS GOMEZ LOPEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// El coste de la funcion en el peor de los casos es O(log(N)), donde N es el n�mero de elementos de la curva
int menor(vector<int> const v, int ini, int fin) {
	int mitad = 0;
	if (ini + 1 == fin) return v[ini];
	else {
		mitad = (ini + fin) / 2;
		if (v[mitad] > v[mitad - 1]) return menor(v, ini, mitad); //Si de la curva el valor es m�s peque�o el de delante de la mitad, entonces la mitad no es el m�nimo
		else return menor(v, mitad, fin); //Si de la curva el valor de la mitad es m�s peque�o, entonces significa que sigue decreciendo o es el m�nimo
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!cin) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << menor(v, 0, N) << endl;
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