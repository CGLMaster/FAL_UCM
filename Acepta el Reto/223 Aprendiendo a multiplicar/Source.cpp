#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Precondicion Q : {vector<int> a : 0 <= a.size() <= 10000 && forall k: a[k] >= 0}
// Invariante I : {vector<int> a : 0 <= k < a.size() && aprende = (a[k] != 0) && # r : (multiplicatorio(v,p,q) != 0)}
//					fun multiplicatorio (v, p, q) : {int r = (0 <= p <= q < a.size() : q - p && a[p]*a[p+1]*...*a[q-1]*a[q])}
// Funcion de cota C : N - i
// Postcondicion R : {max cont : vector<int> a : 0 <= p <= q < a.size() : q - p && (a[p]*a[p+1]*...*a[q-1]*a[q] != 0)}


bool aprendiendoMult(vector<int> v, int& ini, int& fin, int& cont) {
	int begin = -1, end = 0, c = 0;
	bool inicio = false;
	if (v.size() <= 0) return false;
	else if (v.size() == 1) {
		if (v[0] == 0) return false;
		else return true;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] != 0) {
				if (inicio) {
					end++;
				}
				else {
					begin = i;
					end = i;
					inicio = true;
				}
				c++;
			}
			else {
				if (c > cont) {
					ini = begin;
					fin = end;
					cont = c;
				}
				inicio = false;
				c = 0;
			}
		}
		if (begin == -1) return false;
		else if (c > cont) {
			ini = begin;
			fin = end;
			cont = c;
		}
		return true;
	}
}

void resuelveCaso() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int ini = 0, fin = 0, cont = 1;
	if (aprendiendoMult(v, ini, fin, cont)) cout << cont << " -> [" << ini << "," << fin << "]" << endl;
	else cout << "SIGUE BUSCANDO" << endl;
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