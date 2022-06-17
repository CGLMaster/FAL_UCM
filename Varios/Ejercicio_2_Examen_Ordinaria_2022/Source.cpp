#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// El coste de la función en el peor de los casos es O(N), donde N es el número de dígitos del número

int multiplicativos(int& num, int& mult) {
	if (num != 0) {
		if (num > 10) {
			int div = num / 10;
			int n = num - div * 10;
			int m = multiplicativos(div, mult);
			if (mult % 10 == n) m++;
			mult *= n;
			return m;
		}
		else {
			if (mult % 10 == num) {
				return 1;
			}
			mult *= num;
		}
	}
	mult *= num; //Si hubiese el caso de que el primero es cero
	return 0;
}


void resuelveCaso() {
	int num;
	cin >> num;
	int mult = 1;
	int sum = multiplicativos(num, mult);
	cout << sum << endl;
}

/*
int multiplicativos(int& num, int& mult, int pos, int& cont) {
	if (cont == 0) {
		int aux = num / pow(10, cont);
		if (mult % 10 == aux) return 1;
	}
	else {
		if (num == 0) return 0;
		int aux = num / pow(10, cont);
		if (mult % 10 == aux) {
			num -= aux * pow(10, cont);
			return 1 + multiplicativos(num, mult *= aux, pos + 1, cont -= 1);
		}
		else {
			num -= aux * pow(10, cont);
			return multiplicativos(num, mult *= aux, pos + 1, cont -= 1);
		}
	}
}
*/

/*
int multiplicativos(const vector<int> v, int& mult, int pos) {
	if (pos + 1 == v.size()) {
		if (mult % 10 == v[pos]) return 1;
	}
	else {
		if (mult % 10 == v[pos]) return 1 + multiplicativos(v, mult *= v[pos], pos+1);
		else return multiplicativos(v, mult *= v[pos], pos+1);
	}
}


void resuelveCaso() {
	string s;
	cin >> s;
	vector<int> v(s.size());
	for (int i = 0; i < s.size(); i++) v[i] = s[i] - '0';
	int mult = 1;
	int cont = multiplicativos(v, mult, 0);
	cout << cont << endl;
}
*/

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