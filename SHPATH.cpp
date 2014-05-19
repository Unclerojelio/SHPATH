// You are given a list of cities. Each direct connection between two cities has its
// transportation cost (an integer bigger than 0). The goal is to find the paths of
// minimum cost between pairs of cities. Assume that the cost of each path (which is
// the sum of costs of all direct connections belongning to this path) is at most 200000.
// The name of a city is a string containing characters a,...,z and is at most 10
// characters long.
// 
// Input
// 
// s [the number of tests <= 10]
// n [the number of cities <= 10000]
// NAME [city name]
// p [the number of neighbours of city NAME]
// nr cost [nr - index of a city connected to NAME (the index of the first city is 1)]
//            [cost - the transportation cost]
// r [the number of paths to find <= 100]
// NAME1 NAME2 [NAME1 - source, NAME2 - destination]
// [empty line separating the tests]
// Output
// 
// cost [the minimum transportation cost from city NAME1 to city NAME2 (one per line)]

// http://www.spoj.com/problems/SHPATH/

// Implementation:
// http://en.wikipedia.org/wiki/Dijkstra's_algorithm

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

const int MAX_CITIES = 10000;

class City
{
		string name;
		bool visited;
		int cost;
		vector<pair<int, int> > neighbors;
	public:
		City();
		City(string s);
		~City();
		inline string getName() { return name; }
		inline bool getVisited(){ return visited; }
		inline int getCost() { return cost; }
		inline void setName(string s) { name = s; }
		inline void setVisited(bool v) { visited = v; }
		inline void setCost(int n) {cost = n; }
		void addNeighbor(int n, int cost);
		void showNeighbors();
		void showCity();
		void visitNeighbor(int n, int cost);
		int findCheapestNeighbor();
};

City::City()
{
	name = "";
	visited = false;
	cost = 0;
}

City::City(string s)
{
	name = s;
	visited = false;
	cost = 0;
}

City::~City()
{
}

void City::addNeighbor(int n, int cost)
{
	pair<int,int> neighbor(n, cost);
	neighbors.push_back(neighbor);
}

void City::showNeighbors()
{
	for(int i = 0; i < neighbors.size(); i++)
	{
		cout << "Neighbor: " << neighbors[i].first << " Cost: " << neighbors[i].second;
		cout << endl;
	}
}

void City::showCity()
{
	cout << "Name :" << name << endl;
	if(visited)
		cout << "Visited";
	else cout << "Not Visited";
	cout << endl;
	cout << "Cost: " << cost << endl;
	for(int i = 0; i < neighbors.size(); i++)
	{
		cout << "\tNeighbor: " << neighbors[i].first << " Cost: " << neighbors[i].second;
		cout << endl;
	}
}

City* cities[MAX_CITIES];

int main(void)
{
	int numTests = 0;
	cin >> numTests;
	cout << "Number of Tests: " << numTests << endl;
	while(numTests--)
	{
		int numCities = 0;
		cin >> numCities;
		cout << "Number of Cities: " << numCities << endl;
		int cityCount = 0;
		while(numCities--)
		{
			cityCount++;
			string cityName;
			int numNeighbors = 0;
			cin >> cityName;
			cin >> numNeighbors;
			City *theCity = new City(cityName);
			cities[cityCount] = theCity;
			while(numNeighbors--)
			{
				int neighbor = 0;
				int cost = 0;
				cin >> neighbor >> cost;
				theCity->addNeighbor(neighbor, cost);
			}
			theCity->showCity();
		}
	}
	int numPaths = 0;
	cin >> numPaths;
	while(numPaths--)
	{
		string startCity;
		string endCity;
		cin >> startCity >> endCity;
	}
	return 0;
}