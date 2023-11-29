#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

//! Problem Set 27
//! CYCLIC DEPENDENCY REMOVAL

//* Graph

// Suppose we have a directed graph G, consisting of n nodes and m edges. Edges on this graph constitute chains of dependent relationships: 
// for example, (u, v) in the graph signifies that u directly depends on v. Directed paths in this graph define chains of indirect dependency, 
// where some node is dependent on nodes which are in turn dependent on other nodes (they are indirectly dependent on these other nodes)

// An example of such a graph: the graph that determines the prerequisite relationships of college classes. A suitable schedule where every class is 
// taken after its prerequisites would be found through topological sorting.

// A cyclic dependency in such a graph is a cycle, and these prevent topological sorting.

// An example of cyclic dependency: Chicken depends on Egg. Egg depends on Chicken. A topological sorting would put them in order from first to last, 
// and this is not possible because of the cycle.

// Nodes in the graph which are satisfiable have no indirect or direct dependencies that part of a cyclic dependency, and thus by removing all 
// unsatisfiable nodes (nodes which have a cycle in their indirect dependencies), the graph can be topologically ordered.

// Given an input graph G, use DFS to detect and remove unsatisfiable nodes, and provide the number of satisfiable nodes remaining.

//* Expected runtime: O(n+m)

//* Note on input:

// All graphs will be given with nodes numbered from 0 to n-1, and edges will be provided in a list. 
// For the above: n - number of nodes m - number of edges

//! Input Format:
// n
// m 
// [ list of edges, one per line, each line having the form SRC DST ]

//! Output Format:
// The number of satisfiable nodes

//! Input 1
// 10
// 11
// 0 1
// 1 2
// 2 0
// 2 3
// 3 4
// 3 5
// 2 5
// 5 6
// 7 8
// 8 6
// 9 3

//! Output 1
// 7

//? Submission ID: f6912a0e-0120-4692-90be-7fbc9894c553

bool isCyclic(int i, vector<bool> &visitedList, vector<bool> &recStack, vector<bool> &inCycle, vector<list<int> > &graph)
{
    //if the node has not been visited, mark it as visited and in the recursion stack
    if(!visitedList[i])
    {
        visitedList[i] = true;
        recStack[i] = true;

        //for each node adjacent to i, if it has not been visited and is cyclic, mark i as in a cycle and return true
        for(auto it = graph[i].begin(); it != graph[i].end(); it++)
        {
            if(!visitedList[*it] && isCyclic(*it, visitedList, recStack, inCycle, graph))
            {
                inCycle[i] = true;
                return true;
            }

            else if(recStack[*it])
            {
                inCycle[i] = true;
                return true;
            }
        }
    }

    recStack[i] = false;
    return false;
}

int numOfSatisfiableNodes(int numNodes, vector<list<int> > &graph)
{
    //visitedList keeps track of which nodes have been visited
    vector<bool> visitedList(numNodes, false);
    //recStack keeps track of which nodes are currently in the recursion stack
    vector<bool> recStack(numNodes, false);
    //inCycle keeps track of which nodes are in a cycle
    vector<bool> inCycle(numNodes, false);

    //for each node, if it hasn't been visited, run isCyclic
    for(int i = 0; i < numNodes; i++)
    {
        if(!visitedList[i])
        {
            isCyclic(i, visitedList, recStack, inCycle, graph);
        }
    }

    int nonCycleNodes = 0;

    //for each node, if it is not in a cycle, increment nonCycleNodes
    for(int i = 0; i < numNodes; i++)
    {
        if(!inCycle[i])
        {
            nonCycleNodes++;
        }
    }

    return nonCycleNodes;
}

int main(){
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    //adjacency list representation of graph
    vector<list<int> > graph(numNodes);

    //numEdges is the number of remaining lines to read from input
    for(int i = 0; i < numEdges; i++)
    {
        int source, destination;
        cin >> source >> destination;

        graph[source].push_back(destination);
    }

    int result = numOfSatisfiableNodes(numNodes, graph);
    cout << result << endl;
}