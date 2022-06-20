#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool palindromo(const vector<char>& v, const int& m, int ini, int fin) {
	if (ini == m && fin == m) return true;
	else {
		bool pali = false;
		if (v[ini] == v[fin]) pali = palindromo(v, m, ini + 1, fin - 1);
		return pali;
	}
}


bool resuelveCaso() {
	string s;
	vector<char> v;
	getline(cin,s);
	if (s == "XXX") return false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') v.push_back(tolower(s[i]));
	}
	int mitad = v.size() / 2;
	if (palindromo(v, mitad, 0, v.size() - 1)) cout << "SI" << endl;
	else cout << "NO" << endl;
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