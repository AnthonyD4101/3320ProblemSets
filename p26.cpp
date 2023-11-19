#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

//! Problem Set 26
//! WELL-C0NNECTED TOWNS

//* Graph

//* Suppose we have an undirected graph G representing m roads (edges) connecting n towns (nodes), with edge weights describing the distances along the road in miles. Some of these towns have a bus station (call the number of towns with bus stations b). Each town with a bus station has buses that travel from that town along the roads, and have a one-way range of d miles: every town within d miles of road travel from this town through any number of other towns is reachable. A town is well-connected if it is reachable by bus from at least k towns (including itself, if it has a bus station) for some fixed number k. Given G, the list of b towns with bus stations, d, and k, determine the number of well-connected towns.

//* Expected runtime: O(b(n+m log m))

//* Hint: Consider the different variants of WhateverFirstSearch mentioned in the Graph Algorithms slides. Which one is most suitable?

//* Note on input:

//* All graphs will be given with nodes numbered from 0 to n-1, and edges will be provided in a list. For the above:

//* n - number of towns in the graph (integer)

//* m - number of roads in the graph (integer)

//* d - distance a bus can travel one-way (integer)

//* k - number of towns in order to consider well-connected (integer)

//* b - number of towns with bus stations (integer)

//* You may assume that all edge weights are greater than 0. The graph may not be connected.

//* n > b >= k

//* Format:

//* n

//* d

//* k

//* b

//* m

//* [ list of nodes with bus stations in a single line ]

//* [ list of edges, each line having the form SRC DST WEIGHT describing a single undirected edge between SRC and DST having weight WEIGHT ]

//* Output:

//* The number of towns which are well-connected


//! Example Inputs

//! Input 1
// 7
// 5
// 2
// 2
// 10
// 0 6
// 0 1 2
// 0 2 2
// 0 3 1
// 0 4 6
// 0 5 2
// 1 2 2
// 1 5 3
// 1 6 5
// 4 5 4
// 5 6 2

//! Output 1
// 5

//? Submission ID: 724dbd26-5d54-417b-bb67-7400fc8294c9

vector<int> dijkstraAlgorithm(int sourceNode, vector<vector<pair<int, int> > > &busGraph, int busRange)
{
    int numNodes = busGraph.size();
    vector<int> distances(numNodes, 1e9);
    distances[sourceNode] = 0;

    //TODO: Implement priority queue
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > prioQueue;
    prioQueue.push(make_pair(0, sourceNode));

    while(!prioQueue.empty())
    {
        int currNode = prioQueue.top().second;
        int currDist = prioQueue.top().first;

        prioQueue.pop();
 
        if(currDist > distances[currNode])
            continue;

        for(int i = 0; i < busGraph[currNode].size(); i++)
        {
            int nextNode = busGraph[currNode][i].first;
            int nextDist = busGraph[currNode][i].second;

            if(currDist + nextDist <= busRange && currDist + nextDist < distances[nextNode])
            {
                distances[nextNode] = currDist + nextDist;
                prioQueue.push(make_pair(distances[nextNode], nextNode));
            }
        
        }
    }

    return distances;
}

int main()
{
    //TODO: Read in Input
    //Format: n, d, k, b, m
    int numTowns, busRange, numWellConnected, townsWithBusStations, numRoads;
    cin >> numTowns >> busRange >> numWellConnected >> townsWithBusStations >> numRoads;

    vector<int> busStations(townsWithBusStations);

    //Read in bus stations
    for(int i = 0; i < townsWithBusStations; i++)
        cin >> busStations[i];

    vector<vector<pair<int, int> > > busGraph(numTowns);

    for(int i = 0; i < numRoads; i++)
    {
        int src, dst, weight;
        cin >> src >> dst >> weight;

        busGraph[src].push_back(make_pair(dst, weight));
        busGraph[dst].push_back(make_pair(src, weight));
    }

    vector<int> busStationReachableTownCount(numTowns, 0);

    for(int i = 0; i < busStations.size(); i++)
    {
        int station = busStations[i];
        vector<int> distances = dijkstraAlgorithm(station, busGraph, busRange);

        for(int j = 0; j < numTowns; j++)
        {
            if(distances[j] <= busRange)
                busStationReachableTownCount[j]++;
        }
    }

    int numWellConnectedTowns = 0;
    for(int i = 0; i < numTowns; i++)
    {
        if(busStationReachableTownCount[i] >= numWellConnected)
            numWellConnectedTowns++;
    }

    cout << numWellConnectedTowns << endl;
}