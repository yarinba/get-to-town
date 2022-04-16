#pragma once

#include <vector>
#include "AList.h"
#include "List.h"
using std::vector;

class RecursiveApproach {
public:
	void getToTown(vector<List>& country, int cityIndex, vector<bool>& isChecked, AList& accessibilityList);
};