#include <iostream>
#include <vector>
#include <list>
#include "AList.h"
using namespace std;

list<int> createAccessibilityList(vector<list<int>> country, int numOfCities, int cityIndex);
void getToTownRec(vector<list<int>> country, int cityIndex, vector<bool> &isChecked, list<int> &accessibilityList);

struct Pair {
	int from;
	int to;
};

void main() {
	int numOfCities, numOfConnections;
	vector<Pair> connections;
	cin >> numOfCities >> numOfConnections;

	// get input from user
	for (int i = 0; i < numOfConnections; i++) {
		Pair p;
		int from, to;
		cin >> p.from >> p.to;
		connections.push_back(p);
	}

	int cityIndex;
	do {
		cin >> cityIndex;
	} while (cityIndex > numOfCities || cityIndex < 0);

	// create country structure
	vector<list<int>> countryStructure (numOfCities + 1, list<int>());
	for (Pair p : connections) {
		countryStructure[p.from].push_back(p.to);
	}




	list<int> accessList = createAccessibilityList(countryStructure, numOfCities, cityIndex);
	//auto arr2 = getToTown();

	// print access list
	list<int>::iterator it;
	cout << "Accessibility Group:" << endl;
	for (it = accessList.begin(); it != accessList.end(); ++it)
		cout << '\t' << *it;
	cout << '\n';
}

list<int> createAccessibilityList(vector<list<int>> country, int numOfCities, int cityIndex) {
	list<int> accessibilityList; // what is the size ?
	vector<bool> isChecked(numOfCities + 1, false); // "colors" array
	getToTownRec(country, cityIndex, isChecked, accessibilityList);
	return accessibilityList;
}

void getToTownRec(vector<list<int>> country, int cityIndex, vector<bool> &isChecked, list<int> &accessibilityList) {
	if (isChecked[cityIndex] == true)
		return;
	isChecked[cityIndex] = true;
	accessibilityList.push_back(cityIndex);

	list<int>::iterator it;
	for (it = country[cityIndex].begin(); it != country[cityIndex].end(); ++it) {
		getToTownRec(country, *it, isChecked, accessibilityList);
	}
}