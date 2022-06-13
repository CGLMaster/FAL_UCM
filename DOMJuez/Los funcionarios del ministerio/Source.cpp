#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<bool>& joob, const vector<bool>& func, int cont, int i) {
	if (cont > 0) {
		//El trabajo ya esta ocupado
		if (joob[cont]) return false;
		//El funcionario ya tiene trabajo
		if (func[i]) return false;
	}
	return true;
}

void calcularTiempo(const vector<vector<int>>& tiempos, int N, int cont, vector<bool>& joob, vector<bool>& func, int& total, int& tiempoActual, const vector<int>& acumulados){
	for (int i = 0; i < N; i++) {
		tiempoActual += tiempos[i][cont];
		if (esValida(joob, func, cont, i)) {
			joob[cont] = true;
			func[i] = true;
			if (cont == N - 1) {
				if (tiempoActual < total) total = tiempoActual;
			}
			else {
				if(acumulados[cont + 1] + tiempoActual < total) calcularTiempo(tiempos, N, cont + 1, joob, func, total, tiempoActual, acumulados);
			}
			joob[cont] = false;
			func[i] = false;
		}
		tiempoActual -= tiempos[i][cont];
	}
}

bool resuelveCaso() {
	int N;
	cin >> N;
	if (N == 0) return false;
	vector<vector<int>> tiempos(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tiempos[i][j];
		}
	}
	vector<bool>joob(N);
	vector<bool>func(N);
	int total = 1000000;
	int tiempoActual = 0;
	vector<int> minimos(N);
	for (int i = 0; i < N; i++) {
		minimos[i] = tiempos[0][i];
		for (int j = 0; j < N; j++) {
			if (minimos[i] > tiempos[j][i]) minimos[i] = tiempos[j][i];
		}
	}
	vector<int> acumulados(N);
	for (int i = N - 2; i > -1; i--) acumulados[i] = acumulados[i + 1] + minimos[i];
	calcularTiempo(tiempos, N, 0, joob, func, total, tiempoActual, acumulados);
	cout << total << endl;
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
