#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "RecursiveApproach.h"
#include "IterativeApproach.h"

struct Pair {
	int from;
	int to;
};

enum class eFunctionType {
	Iterative,
	Recursive
};

class Program {
	IterativeApproach ia;
	RecursiveApproach ra;
	void printAccessibilityList(vector<List>& country, int numOfCities, int cityIndex, eFunctionType t);
	bool getNumOfCitiesAndConnections(int& numOfCities, vector<Pair>& connections);
	bool getCityIndex(int numOfCities, int& cityIndex);

public:
	void run();
};