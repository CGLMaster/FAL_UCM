// NOMBRE Y APELLIDOS 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool juego(vector<vector<int>> v, int k, int l, int num) {
	for (int i = 0; i < 3; i++) {
		if (num + v[k][i] < 31) return true;
	}
	for (int i = 0; i < 3; i++) {
		if (num + v[i][l] < 31) return true;
	}
	return false;
}

void resuelveCaso() {
	int num, ult;
	cin >> num >> ult;
	vector<vector<int>> v(3, vector<int>(3));
	vector<vector<bool>> puede(3, vector<bool>(3));
	int n = 9;
	int k, l;
	for (int i = 0; i < 3; i++) {
		for (int j = 2; j >= 0; j--) {
			if (ult == n) {
				k = i;
				l = j;
			}
			v[i][j] = n;
			n--;
		}
	}

	bool seGana = juego(v, k, l, num);

	if (seGana) cout << "GANA" << endl;
	else cout << "PIERDE" << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos = 0;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif


	return 0;
}