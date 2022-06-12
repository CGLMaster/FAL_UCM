#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Precondición Q: {vector<int> a : 0 <= k < a.size() : forall k: 0 < a[k] < 10^18}
//Invariante I: {}
//Función de cota C : N - i + 1
//Postcondición R: {min mn, max mx : vector<int> a : 0 <= k < a.size() : a[k] && (#p : mn == a[k]) && (#q : mx == a[k])}

void calculoTemperatura(vector<long long int> v, long long int& mini, int& contmin, long long int& maxi, int& contmax) {
	for (int i = 1; i < v.size(); i++) {
		if (mini > v[i]) {
			mini = v[i];
			contmin = 1;
		}
		else if (mini == v[i]) contmin++;
		if (maxi < v[i]) {
			maxi = v[i];
			contmax = 1;
		}
		else if (maxi == v[i]) contmax++;
	}
}

void resuelveCaso() {
	long long int num;
	vector<long long int> v;
	cin >> num;
	while (num != 0) {
		v.push_back(num);
		cin >> num;
	}
	long long int mini = v[0], maxi = v[0];
	int contmin = 1, contmax = 1;
	calculoTemperatura(v, mini, contmin, maxi, contmax);
	cout << mini << " " << contmin << " " << maxi << " " << contmax << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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