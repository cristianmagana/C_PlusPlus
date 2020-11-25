#include "proj2.hpp"

#include <vector>
#include <iostream>


void countPaths(const std::vector< std::vector<unsigned> > & friends, unsigned start, std::vector<unsigned> & pathLengths, std::vector<unsigned> & numShortestPaths)
{
    LLQueue<unsigned> graphQ; 
    unsigned gSize = (friends.size());
    //std::cout << "Friends Size is: " << gSize << std::endl;

    bool *visited = new bool[gSize];

    // Setting necessary conditions for BFS
    for(int i =0; i < gSize; i++)
    {
        numShortestPaths[i] = 0; 
        pathLengths[i] = INT_MAX; 
        visited[i] = false;
    }

    numShortestPaths[start] = 1; 
    pathLengths[start] = 0;

    visited[start] = true;

    graphQ.enqueue(start);

    while(!graphQ.isEmpty())
    {
        unsigned p = graphQ.front();
        graphQ.dequeue();
       // std::cout << p << std::endl;

        for(auto i : friends[p])
        {
            if(visited[i] == false)
            {
                graphQ.enqueue(i);
                visited[i] = true;
            }
            if(pathLengths[i] == pathLengths[p] +1)
            {
                numShortestPaths[i] += numShortestPaths[p];
            }
            // Checks if another shorter path exists
            else if(pathLengths[i] > pathLengths[p] + 1)
            {
                pathLengths[i] = pathLengths[p] +1;
                numShortestPaths[i] = numShortestPaths[p];
            }
            //else if(pathLengths[i] < pathLengths[p] +1)
            //{
            //          Do nothing 
            //}
        }
    }

}


