#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Class to represent a city map using a graph structure
class CityMap {
    public:
    // Adjacency list to store the connections (roads) between intersections
    vector<vector<int> > adjacenecyList;
    int start; // Start spot for pathfinding
    int end;   // End spot for pathfinding

    // Constructor to initialize the adjacency list with a given number of intersections
    CityMap(int numIntersections) {
        adjacenecyList.resize(numIntersections);
    }

    // Function to add a bidirectional road between two intersections
    void addRoad(int from, int to) {
        adjacenecyList[from].push_back(to);
        adjacenecyList[to].push_back(from); // Since the graph is undirected
    }

    // Function to get user input for the start and end spots for pathfinding
    void getSpots() {
        cout << "Enter The Spots For Paths:" << endl;
        cout << "Start: " << endl;
        cin >> start;
        cout << "End: " << endl;
        cin >> end;
    }

    // Function to display the entire map showing connections between spots
    void showMap() {
        cout << "Total Spots: " << adjacenecyList.size() << "\n";
        for(int i = 0; i < adjacenecyList.size(); ++i) {
            cout << "Spot-" << i << " is connected to Spot-";
            for(int neighbour : adjacenecyList[i]) {
                cout << neighbour << " "; // Display all connected spots
            }
            cout << endl;
        }
        cout << "*******************************" << endl;
    }

    // Function to check if there is a path between the start and end spots using BFS
    bool isConnected(int start, int end) {
        vector<bool> visited(adjacenecyList.size(), false); // To keep track of visited spots
        queue<int> q; // Queue for BFS
        q.push(start);
        visited[start] = true;

        // BFS loop
        while(!q.empty()) {
            int current = q.front();
            q.pop();

            if(current == end) return true; // If end is reached, return true

            // Explore all neighbors
            for(int neighbour : adjacenecyList[current]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return false; // If BFS completes without finding the end spot, return false
    }

    // Function to print all paths between start and end spots using DFS
    void printPaths(int start, int end) {
        vector<bool> visited(adjacenecyList.size(), false); // To track visited spots in DFS
        vector<int> path; // To store the current path
        printAllPathsUtil(start, end, visited, path); // Helper function for DFS
    }

    private:

    // Recursive function to find and print all paths between start and end using DFS
    void printAllPathsUtil(int start, int end, vector<bool>& visited, vector<int>& path) {
        visited[start] = true; // Mark the current spot as visited
        path.push_back(start); // Add current spot to the path
        
        // If end spot is reached, print the path
        if(start == end) {
            for(int i = 0; i < path.size(); i++) {
                if(i != 0) cout << "->";
                cout << "Spot-" << path[i];
            }
            cout << endl;
        } else {
            // Recur for all neighbors
            for(int neighbour : adjacenecyList[start]) {
                if(!visited[neighbour]) {
                    printAllPathsUtil(neighbour, end, visited, path);
                }
            }
        }
        path.pop_back(); // Backtrack: Remove the current spot from path
        visited[start] = false; // Unmark the current spot as visited
    }

};

int main() {
    CityMap CityMap(5); // Create a map with 5 intersections
    cout<<"************** Developed & Coded By Alpha Tech *************"<<endl;

    // Add roads between intersections
    CityMap.addRoad(0, 1);
    CityMap.addRoad(1, 2);
    CityMap.addRoad(2, 3);
    CityMap.addRoad(3, 4);
    CityMap.addRoad(4, 0);

    CityMap.showMap(); // Display the city map

    CityMap.getSpots(); // Get user input for start and end spots

    // Check if there is a path between start and end, and print all paths if any
    if(CityMap.isConnected(CityMap.start, CityMap.end)) {
        cout << "There is a path between " << CityMap.start << " and " << CityMap.end << endl;
        cout << "Paths:" << endl;
        CityMap.printPaths(CityMap.start, CityMap.end);
    } else {
        cout << "There is no path between " << CityMap.start << " and " << CityMap.end << endl;
    }
    return 0;
}


/*
************** ALPHA TECH SOLUTIONS (CITY PATHFINDING SYSTEM) ****************

INSTRUCTION & ABOUT:

This code simulates a city map with various intersections (spots) connected by roads. 
The system allows the user to input start and end points and checks if a path exists 
between them using Breadth-First Search (BFS). It can also print all possible paths 
from the start to the end using Depth-First Search (DFS).

- **Application Example**: This code could be adapted for use in navigation systems, 
    helping to find routes between locations in a city or any network of connected points.
- **Integration Idea**: With slight modifications, this logic can be used in autonomous 
    vehicles or robotic systems to plan and follow routes, where intersections are decision points.

You are encouraged to modify the code to suit your specific project needs, such as adding
real-time updates, integrating GPS data, or applying it to game development for pathfinding in maps.

*/