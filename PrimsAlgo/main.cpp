// Prim's Algorithm in C++
#include <iostream>
#include <cstring>

using namespace std;

#define INF 9999999
#define V 5 // number of vertices in graph

int G[V][V] =
{
    {0, 10, 82, 0, 0},
    {10, 0, 95, 19, 45},
    {82, 95, 0, 53, 67},
    {0, 19, 53, 0, 37},
    {0, 45, 67, 37, 0}
};

int main()
{
    int no_of_edges = 0;
    int row;
    int column;

    int selected[V];
    // set selected false initially
    memset(selected, false, sizeof(selected));
    // choose 0th vertex and make it true
    selected[0] = true;

    // print for edge and weight
    cout << "Edge to Edge : Weight"<< endl;
    int min_cost = 0;
    while (no_of_edges < V - 1)
    {
        //For every vertex in the set S, find the all adjacent vertices
        // , calculate the distance from the vertex selected at step 1.
        // if the vertex is already in the set S, discard it otherwise
        //choose another vertex nearest to selected vertex  at step 1.

        int min = INF;
        row = 0;
        column = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])    // not in selected and there is an edge
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            row = i;
                            column = j;
                        }
                    }
                }
            }
        }
        cout << row << " ------- " << column << " :  " << G[row][column] <<endl;
        min_cost = min_cost + G[row][column];
        selected[column] = true;
        no_of_edges++;
    }
    cout << "Minimum Cost: "<<min_cost<<endl;
    cout << "Total Number of Edges: "<<no_of_edges<<endl;
    return 0;
}
