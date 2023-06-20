#include <iostream>

using namespace std;

int adj[100][100];
int main()
{
    freopen("input.txt", "r", stdin);
    int node, edge;
    cin >> node;
    cin >> edge;

    cout << "Number of Nodes: "<< node <<endl;
    cout << "Number of edges: "<<edge<<endl;

    int startPoint, endPoint;
    for(int i =0; i< edge; ++i) {
        cin >> startPoint;
        cin >> endPoint;
        adj[startPoint][endPoint] = 1;
        adj[endPoint][startPoint] = 1;
    }

    cout << "Adjacent Matrix Representation: " <<endl;
    for(int i=0; i<node; i++) {
        for(int j=0; j<node; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "" <<endl;
    }
    int value = 0;
    cout << "Adjacent Matrix of your given value. Please input: " <<endl;
    cin >> value;
    for(int i=0; i<node; i++) {
        if(adj[value][i] == 1) {
            cout << value << "  "<< i << endl;
        }
    }
    return 0;
}
 /* Construct the following tree
               0
             /   \
            /     \
           2 _ _ _ 1
                  / \
                 /   \
                3 _ _ 4

Number of Nodes= 5
Number of Edges = 6

Nodes Edges
----------
5 - 6
----------
0 - 1
0 - 2
1 - 2
1 - 3
1 - 4
3 - 4
---------
We will find adjacent matrix of 1:

Output:
Number of Nodes: 5
Number of edges: 6
Adjacent Matrix Representation:
0 1 1 0 0
1 0 1 1 1
1 1 0 0 0
0 1 0 0 1
0 1 0 1 0
Adjacent Matrix of your given value. Please input:
1  0
1  2
1  3
1  4

    */



