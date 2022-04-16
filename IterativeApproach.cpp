#include "IterativeApproach.h"

void IterativeApproach::getToTown(vector<List>& country, int cityIndex, vector<bool>& isChecked, AList& accessibilityList) {
	Stack <ItemType> s;
	s.makeEmpty();

	ItemType item = { country[cityIndex].getHead(), cityIndex };
	s.push(item);
	
	while (!s.isEmpty()) {
		ItemType temp = s.pop();

		if (!isChecked[temp.cityIndex]) {
			isChecked[temp.cityIndex] = true;
			accessibilityList.insert(temp.cityIndex);
		}

		Node* curr = temp.currTown;
		while (curr != NULL) {
			if (!isChecked[curr->data]) {
				if (curr->next)
					s.push({ curr->next, temp.cityIndex });

				int newCityIndex = temp.currTown->data;
				Node* newTownCurr = country[newCityIndex].getHead();
				item = { newTownCurr, newCityIndex };
				s.push(item);
				break;
			}
			curr = curr->next;
		}
	}
}
