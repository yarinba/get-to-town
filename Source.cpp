#include <iostream>
#include <vector>
#include <list>
#include "AList.h"
#include "List.h"
using namespace std;

AList createAccessibilityList(vector<List> country, int numOfCities, int cityIndex);
void getToTownRec(vector<List> country, int cityIndex, vector<bool> &isChecked, AList &accessibilityList);

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
	vector<List> countryStructure(numOfCities+1);


	for (Pair p : connections) {
		countryStructure[p.from].insert(p.to);
	}

	AList accessList = createAccessibilityList(countryStructure, numOfCities, cityIndex);

	accessList.print();
}

AList createAccessibilityList(vector<List> country, int numOfCities, int cityIndex) {
	AList accessibilityList(numOfCities+1); // what is the size ?
	vector<bool> isChecked(numOfCities + 1, false); // "colors" array
	getToTownRec(country, cityIndex, isChecked, accessibilityList);
	return accessibilityList;
}

void getToTownRec(vector<List> country, int cityIndex, vector<bool> &isChecked, AList &accessibilityList) {
	if (isChecked[cityIndex] == true)
		return;
	isChecked[cityIndex] = true;
	accessibilityList.insert(cityIndex);

	Node* curr = country[cityIndex].getHead();
	// Traverse the list.
	while (curr != NULL) {
		getToTownRec(country, curr->data, isChecked, accessibilityList);
		curr = curr->next;
	}
}