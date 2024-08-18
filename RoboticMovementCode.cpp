#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<utility>
using namespace std;

class Solution{

public:

    // Function that simulates robotic movement in a grid and collects items
    std::pair<int, int> robotItemCollection(int n, std::vector<std::string>& commands){
        std::vector<std::vector<int> > grid(n, std::vector<int>(n,0));
        std::vector<std::vector<int> > *ptrGrid=&grid;  //Pointer to The Matrix

        // Randomly place items on the grid
        srand(time(0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                (*ptrGrid)[i][j]=rand()%2;
            }
        }

        // Display the grid with randomly placed items
        std::cout<<"Grid with Items:\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                std::cout<<(*ptrGrid)[i][j]<<" ";
            }
            std::cout<<std::endl;
        }

        int i=0, j=0;
        int itemsCollected=0;

        // Traverse the grid based on the commands and collect items
        for (const auto& command : commands){
            if(command=="RIGHT"){
                j=std::min(j+1, n-1);
            } else if(command=="DOWN"){
                i=std::min(i+1, n-1);
            } else if(command=="LEFT"){
                j=std::max(j-1,0);
            } else if(command=="UP"){
                i=std::max(i-1,0);
            }
            if((*ptrGrid)[i][j]==1){
                itemsCollected++;
                (*ptrGrid)[i][j]=0;
            }
        }

        // Return the final position and the number of items collected
        return std::make_pair((*ptrGrid)[i][j], itemsCollected);
    }

};

int main(){
    Solution s1;
    std::vector<std::string> commands;
    commands.push_back("RIGHT");
    commands.push_back("RIGHT");
    commands.push_back("DOWN");
    commands.push_back("LEFT");
    commands.push_back("DOWN");
    commands.push_back("RIGHT");

    // Get the final position and items collected after executing commands
    std::pair<int, int> result = s1.robotItemCollection(5, commands);

    std::cout<<"Final Position Value: "<<result.first<<std::endl;
    std::cout<<"Items Collected: "<<result.second <<std::endl;

    return 0;
}


/* 
************** ALPHA TECH SOLUTIONS (ROBOTIC MOVEMENT TYPE) ****************

INSTRUCTION & ABOUT:

This code is a practical solution simulating the movement of a robotic device in a grid. 
Random values are used to represent items, and the robotic device navigates a 5x5 grid, collecting
items as it moves.

- **Application Example**: You can use this code to simulate and test algorithms for real-world
    robotic devices that need to navigate spaces and interact with objects.
- **Integration Idea**: The grid values could represent the states detected by an IR sensor (1 or 0).
    The commands could be signals sent based on receiver frequencies in a real robotic system.

You are encouraged to modify the code to suit your specific project needs, such as adjusting the 
grid size, changing the item distribution, or integrating it with actual sensor data for robotics
applications.


*/





