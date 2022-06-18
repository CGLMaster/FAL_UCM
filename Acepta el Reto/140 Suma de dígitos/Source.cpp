#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: { 0 < num <= 10^9}
//Postcondición R: {# p : div = num /10 : p += num - div * 10}
// Análisis de coste:
//	T(n){
//		c0 si 0 <= n < 10
//		T(n/10) + c1 si n >= 10 
//		}
//	Entonces a traves del teorema de la división, si a = 1, b = 10 y k = 1 --> O(N^k) si a < b^k --> O(N)
//	El coste de la función en el peor de los casos es de O(N) donde N es el número de dígitos que tiene el número

void sumandoDigitos(int num, int& suma) {
	if (num != 0) {
		if (num < 10) {
			suma += num;
			cout << num;
		}
		else {
			int div = num / 10;
			int aux = num - div * 10;
			suma += aux;
			sumandoDigitos(div, suma);
			cout << " + " << aux; 
		}
	}
	else {
		cout << num;
	}
}


bool resuelveCaso() {
	int num;
	cin >> num;
	if (num < 0) return false;
	int suma = 0;
	sumandoDigitos(num, suma);
	cout << " = " << suma << endl;
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