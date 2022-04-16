#pragma once

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
public:
	void run();
};