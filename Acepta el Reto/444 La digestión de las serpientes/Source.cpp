#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondici�n Q: {k >= 0 && vector<int> a : 1 <= a.size() <= 100000}
//Invariante I: {(vector<int> a : 0 <= l < a.size()) && max contMax :(# cont : 0 <= p <= q < a.size() : q - p : a[p] == 1 && a[q] == 1 && k >= # contUmbral (p < l < q : a[l] == 0)}
//Funci�n de cota C : N - i
//Postcondici�n R: {# m : vector<int> a : 0 <= p <= q < a.size() : q - p : a[p] == 1 && a[q] == 1 && k >= # m (p < l < q : a[l] == 0)}
// El coste de la funci�n en el peor de los casos es O(N) donde N es el n�mero de umbrales

int longitudUmbral(vector<int> v, int k) {
	int cont = 0, contMax = 0, contUmbral = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 1 && contUmbral <= k) {
			cont++;
			contUmbral = 0;
		}
		else if (contUmbral < k) {
			contUmbral++;
			cont++;
		}
		else {
			if (cont > contMax) contMax = cont;
			cont = 0;
			contUmbral = 0;
		}
	}
	if (cont > contMax) contMax = cont;
	return contMax;
}


bool resuelveCaso() {
	int N, k;
	cin >> N >> k;
	if (N == 0 && k == 0) return false;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cout << longitudUmbral(v, k) << endl;
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