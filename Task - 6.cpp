/*
Suppose there is a circle. There are N petrol pumps in that circle. Petrol pumps are numbered 0 to (N−1) (both
inclusive). You have two pieces of information corresponding to each of the petrol pumps: (1) the amount of petrol
that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.
Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps.
Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at
each of the petrol pumps. The truck will move one kilometer for each liter of petrol.
Input
• The first line will contain the value of N.
• The next N lines will contain a pair of integers each, i.e. the amount of petrol that the petrol pump will give
and the distance between that petrol pump and the next petrol pump.
Output
• An integer which will be the smallest index of the petrol pump from which we can start the tour.
Constraints
• 1 ≤ N ≤ 1000001.
• 1 ≤ Amount of petrol, Distance ≤ 1000000000

Input      Output
3          1
1 5
10 3
3 4

Input      Output
8          0
10 1
10 1
10 1
6 6
6 6
6 15
10 5
6 12


*/

#include <iostream> 
#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

bool canFinishTour( queue<int> amounts, queue<int> distances) {

	int reservoir = 0;
	while (amounts.size()) {
		reservoir += amounts.front(); 

		int distanceToNext = distances.front();
		
		if (reservoir >= distanceToNext) {
			reservoir -= distanceToNext; 
		}
		else {
			return false;
		}
		distances.pop(); 
		amounts.pop();
	}
	return true;
}

int main() {
	queue<int> distances;
	queue<int> amounts;   
	int numberOfStations;
	 
	cin >> numberOfStations; 

	for (int i = 0; i < numberOfStations;i++) {
		int buf;
		cin >> buf;
		amounts.push(buf);
		cin >> buf;
		distances.push(buf);
	}
	int curStationStart; 
	for (curStationStart = 0; curStationStart < numberOfStations;curStationStart++) { 
		if (canFinishTour(amounts, distances)) 
			break;
		int distance = distances.front();  
		int amount = amounts.front();  
		distances.pop(); amounts.pop(); 
		distances.push(distance); 
		amounts.push(amount); 
	}
	cout << curStationStart << endl; 
	
	return 0;
}
