#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {true}
//func numDigitos(long long int n) dev c : {c = # i : num/10 > 0}
//Postcondición R: {polidivisible = (p = numDigitos(num) : 0 < i <= p : (num/10^(i-1))%i == 0)}
// Análisis de coste:
//	T(n){
//		c0					si n < 10
//		T(n/10) + c1 * n	si n >= 10
//		}
//	Entonces por el teorema de la división a = 1, b = 10 y k = 1, por lo que a < b^k --> O(N^k) --> O(N^1)
//	El coste de la función en el peor de los casos es de O(N) donde N es el número de dígitos del número

bool polidivisibles(long long int num, int& div) {
	if (num < 10) {
		if (num % div == 0) {
			div++;
			return true;
		}
		else return false;
	}
	else {
		bool poli = polidivisibles(num / 10, div);
		if (num % div != 0) poli = false;
		div++;
		return poli;
	}
}


bool resuelveCaso() {
	long long int num;
	cin >> num;
	if (!cin) return false;
	int div = 1;
	if (polidivisibles(num, div)) cout << "POLIDIVISIBLES" << endl;
	else cout << "NO POLIDIVISIBLES" << endl;
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