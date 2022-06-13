//NOMBRE y APELLIDOS
//Carlos Gomez Lopez


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<bool>& maq, const vector<bool>& carretera, int cont, int i, const vector<int>& anchuraMaq, const vector<int>& anchuraCar) {
	if (maq[i]) return false;
	if (carretera[cont]) return false;
	return true;
}

void calcularCoste(const vector<vector<int>>& coste, int M, int N, int cont, const vector<int>& anchuraMaq, const vector<int>& anchuraCar, vector<bool>& maq, vector<bool>& carretera, int& costeActual, int& total) {
	for (int i = 0; i < M; i++) {
		if (esValida(maq, carretera, cont, i, anchuraMaq, anchuraCar)) {
			if (anchuraMaq[i] <= anchuraCar[cont]) {
				costeActual += coste[i][cont];
				maq[i] = true;
				carretera[cont] = true;
				if (cont == N - 1) {
					if (costeActual > total) total = costeActual;
				}
				else {
					calcularCoste(coste, M, N, cont + 1, anchuraMaq, anchuraCar, maq, carretera, costeActual, total);
				}
				maq[i] = false;
				carretera[cont] = false;
				costeActual -= coste[i][cont];
			}
			else {
				calcularCoste(coste, M, N, cont + 1, anchuraMaq, anchuraCar, maq, carretera, costeActual, total);
			}
		}
		if (cont == N - 1) {
			if (costeActual > total) total = costeActual;
		}
	}
}
/*void calcularCoste(const vector<vector<int>>& coste, int M, int N, int cont, const vector<int>& anchuraMaq, const vector<int>& anchuraCar, vector<bool>& maq, vector<bool>& carretera, int& costeActual, int& total, const vector<int>& acumulados) {
	for (int i = 0; i < M; i++) {
		if (esValida(maq, carretera, cont, i, anchuraMaq, anchuraCar)) {
			if (anchuraMaq[i] <= anchuraCar[cont]) {
				costeActual += coste[i][cont];
				maq[i] = true;
				carretera[cont] = true;
				if (cont == N - 1) {
					if (costeActual > total) total = costeActual;
				}
				else {
					if(acumulados[i] + costeActual > total) calcularCoste(coste, M, N, cont + 1, anchuraMaq, anchuraCar, maq, carretera, costeActual, total, acumulados);
				}
				maq[i] = false;
				carretera[cont] = false;
				costeActual -= coste[i][cont];
			}
			else {
				if (acumulados[i] + costeActual > total) calcularCoste(coste, M, N, cont + 1, anchuraMaq, anchuraCar, maq, carretera, costeActual, total, acumulados);
			}
		}
		if (cont == N - 1) {
			if (costeActual > total) total = costeActual;
		}
	}
}*/

void resuelveCaso() {
	int M, N;
	cin >> M >> N;
	vector<int> anchuraMaq(M);
	vector<int> anchuraCar(N);
	for (int i = 0; i < M; i++) cin >> anchuraMaq[i];
	for (int i = 0; i < N; i++) cin >> anchuraCar[i];
	vector<vector<int>> coste(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> coste[i][j];
		}
	}
	/*vector<int> maximos(M);
	vector<bool> ocupado(N);
	for (int i = 0; i < M; i++) {
		maximos[i] = 0;
		int pos = 0;
		for (int j = 0; j < N; j++) {
			if (maximos[i] < coste[i][j] && !ocupado[j]) {
				maximos[i] = coste[i][j];
				pos = j;
			}
		}
		ocupado[pos] = true;
	}
	vector<int> acumulados(M);
	for (int i = M - 2; i > -1; i--) acumulados[i] = acumulados[i + 1] + maximos[i];*/
	int total = 0;
	int costeActual = 0;
	vector<bool> maq(M);
	vector<bool> carretera(N);
	//calcularCoste(coste, M, N, 0, anchuraMaq, anchuraCar, maq, carretera, costeActual, total, acumulados);
	calcularCoste(coste, M, N, 0, anchuraMaq, anchuraCar, maq, carretera, costeActual, total);
	cout << total << endl;
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}