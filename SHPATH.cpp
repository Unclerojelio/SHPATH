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
			cout << "City Name: " << cityName << endl;
			cin >> numNeighbors;
			City *theCity = new City(cityName);
			cities[cityCount] = theCity;
			while(numNeighbors--)
			{
				int neighbor = 0;
				int cost = 0;
				cin >> neighbor >> cost;
			}
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