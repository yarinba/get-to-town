#include <iostream>
#include <vector>
#include <list>
#include "AList.h"
using namespace std;

AList createAccessibilityList(vector<AList> country, int numOfCities, int cityIndex);
void getToTownRec(vector<AList> country, int cityIndex, vector<bool> &isChecked, AList &accessibilityList);

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
	vector<AList> countryStructure (numOfCities + 1, AList(numOfCities + 1));


	for (Pair p : connections) {
		countryStructure[p.from].insert(p.to);
	}

	for (int i = 0; i < numOfCities + 1; i++) {
		cout << "Country Array in index: " << i << endl;
		countryStructure[i].print();
	}




	AList accessList = createAccessibilityList(countryStructure, numOfCities, cityIndex);
	//auto arr2 = getToTown();

	// print access list
	//AList::iterator it;
	//cout << "Accessibility Group:" << endl;
	//for (it = accessList.begin(); it != accessList.end(); ++it)
	//	cout << '\t' << *it;
	//cout << '\n';

	accessList.print();
}

AList createAccessibilityList(vector<AList> country, int numOfCities, int cityIndex) {
	AList accessibilityList(numOfCities+1); // what is the size ?
	vector<bool> isChecked(numOfCities + 1, false); // "colors" array
	getToTownRec(country, cityIndex, isChecked, accessibilityList);
	return accessibilityList;
}

void getToTownRec(vector<AList> country, int cityIndex, vector<bool> &isChecked, AList &accessibilityList) {
	if (isChecked[cityIndex] == true)
		return;
	isChecked[cityIndex] = true;
	accessibilityList.insert(cityIndex);

	int currIndex = country[cityIndex].getHeadListIndex();
	while (currIndex != -1) {
		int temp = country[cityIndex].value(currIndex);
		getToTownRec(country, temp, isChecked, accessibilityList);
		currIndex = country[cityIndex].next(currIndex);
	}
}