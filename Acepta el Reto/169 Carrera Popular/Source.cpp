#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Si se tuviese que decir cuantos hermanos entonces este método no sirve, pero como solo pide corredores que tengan un hermano más en la carrera el método es válido
//Precondición Q: {vector<string> s : 0 < s.size() <= 40}
//Invariante I: {(vector<string> s : 0 < k < s.size()) && cont = ((# p : 0 < k < s.size() : s[k-1] == s[k]) || (# p : 0 < k < s.size() : s[k] == s[k + 1]))}
//Función de cota C : N - i - 1
//Postcondición R: {cont = (# p : vector<string> s : 0 <= k < s.size() : s[k-1] == s[k] || s[k] == s[k+1]) && s.size()}
//Coste de la función en el peor de los casos: O(N*M) donde N es el número de corredores y M el número de caracteres del apellido de cada corredor

int numHermanos(vector<string> v) {
	int cont = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] == v[i]) cont += 2;
	}
	return cont;
}

void resuelveCaso() {
	string apellido, nombre;
	cin >> apellido;
	vector<string> v;
	while (apellido != "====") {
		cin >> nombre;
		apellido = apellido.erase(apellido.find(","));
		for (int i = 0; i < apellido.size(); i++) apellido[i] = tolower(apellido[i]);
		v.push_back(apellido);
		cin >> apellido;
	}
	int cont = numHermanos(v);
	cout << v.size() << " " << cont << endl;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}