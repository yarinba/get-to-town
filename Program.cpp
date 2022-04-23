#include "Program.h"

/* This function print the accessibility list*/
void Program::printAccessibilityList(vector<List>& country, int numOfCities, int cityIndex, eFunctionType t) {
	AList accessibilityList(numOfCities + 1);
	vector<bool> isChecked(numOfCities + 1, false); // "colors" array


	if (t == eFunctionType::Iterative)
	{
		cout << "Cities accessible from city source city " << cityIndex;
		ia.getToTown(country, cityIndex, isChecked, accessibilityList);
		cout << " (iterative algorithm): ";
	}
	else if (t == eFunctionType::Recursive)
	{
		cout << "Cities accessible from source city " << cityIndex;
		ra.getToTown(country, cityIndex, isChecked, accessibilityList);
		cout << " (recursive algorithm): ";
	}

	accessibilityList.print();
}

/* This function run the recursive and iterative to find the accessibility list*/
void Program::run() {
	int numOfCities, cityIndex;
	vector<Pair> connections;
	bool validCitiesAndConnections, validCityIndex;

	validCitiesAndConnections = getNumOfCitiesAndConnections(numOfCities, connections);
	validCityIndex = getCityIndex(numOfCities, cityIndex);

	if ((!validCitiesAndConnections) || (!validCityIndex))
		cout << "Invalid input";
	else
	{
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
}

/* This function get the num of cities in the country and the num of connections and validate them*/
bool Program::getNumOfCitiesAndConnections(int& numOfCities, vector<Pair>& connections)
{
	int numOfConnections, count = 0;
	string strConnections;
	Pair p;

	cin >> numOfCities >> numOfConnections;

	// Eat the new line
	getchar();

	// Get the connections
	getline(cin, strConnections);
	std::istringstream is(strConnections);

	// Check validation of connections and add them to connections vector
	while (count < numOfConnections)
	{
		if ((is >> p.from) && (is >> p.to))
		{
			if ((p.from < 1) || (p.from > numOfCities) || (p.to < 1) || (p.to > numOfCities))
				return false;
			connections.push_back(p);
		}
		else
			return false;
		count++;
	}

	// Check validations
	if ((count < numOfConnections) || (numOfCities < 1) || (numOfConnections < 0) || (is >> p.from))
		return false;

	return true;
}

/* This function get the city index and check validatio*/
bool Program::getCityIndex(int numOfCities, int& cityIndex)
{
	cin >> cityIndex;
	if (cityIndex > numOfCities || cityIndex < 0)
		return false;
	return true;
}
