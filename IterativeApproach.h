#pragma once

#include <vector>
#include "AList.h"
#include "List.h"
#include "Stack.h"
using std::vector;

struct ItemType {
    Node* currTown;
    int cityIndex;
};

class IterativeApproach {
public:
	void getToTown(vector<List>& country, int cityIndex, vector<bool>& isChecked, AList& accessibilityList);
};