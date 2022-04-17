#include "RecursiveApproach.h"

/* This function find the accessibility list of requested city index
   Implemented by recursive function*/
void RecursiveApproach::getToTown(vector<List>& country, int cityIndex, vector<bool>& isChecked, AList& accessibilityList) {
	if (isChecked[cityIndex] == true)
		return;
	isChecked[cityIndex] = true;
	accessibilityList.insert(cityIndex);

	Node* curr = country[cityIndex].getHead();
	// Traverse the list.
	while (curr != NULL) {
		getToTown(country, curr->data, isChecked, accessibilityList);
		curr = curr->next;
	}
}

