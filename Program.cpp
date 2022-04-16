#include "Program.h"

void Program::printAccessibilityList(vector<List>& country, int numOfCities, int cityIndex, eFunctionType t) {
	AList accessibilityList(numOfCities + 1);
	vector<bool> isChecked(numOfCities + 1, false); // "colors" array
	if (t == eFunctionType::Iterative)
		ia.getToTown(country, cityIndex, isChecked, accessibilityList);
	else if (t == eFunctionType::Recursive)
		ra.getToTown(country, cityIndex, isChecked, accessibilityList);

	accessibilityList.print();
}

void Program::run() {
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
	vector<List> countryStructure(numOfCities + 1);


	for (Pair p : connections) {
		countryStructure[p.from].insert(p.to);
	}

	// recursive
	this->printAccessibilityList(countryStructure, numOfCities, cityIndex, eFunctionType::Recursive);
	// iterative
	this->printAccessibilityList(countryStructure, numOfCities, cityIndex, eFunctionType::Iterative);
}