// NOMBRE Y APELLIDOS
// CARLOS GOMEZ LOPEZ

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> hayLlanos(vector<int> v, int& nllanos, int equal, int& tam) {
	vector<int> comienzo;
	int num, cont = 1;
	num = v[(int)v.size()-1];
	for (int i = (int)v.size() - 2; i >= 0; i--) {
		if (v[i] == v[i + 1] && v[i] >= num) {
			cont++;
			if (cont == equal) {
				comienzo.push_back(i + equal - 1);
			}
		}
		else {
			cont = 1;
		}
		if (cont >= equal) {
			tam = cont;
		}
		if (v[i] > num) num = v[i];
	}
	nllanos = comienzo.size();
	return comienzo;
}

bool resuelveCaso() {
	int datos, equal;
	cin >> datos >> equal;
	if (!cin) return false;
	vector<int> v(datos);
	for (int i = 0; i < datos; i++) cin >> v[i];
	int nllanos = 0, tam = 0;
	vector<int> comienzo = hayLlanos(v, nllanos, equal, tam);
	cout << tam << " " << nllanos;
	if (!comienzo.empty()) {
		for (int i = 0; i < (int) comienzo.size(); i++) {
			cout << " " << comienzo[i];
		}
	}
	cout << endl;
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