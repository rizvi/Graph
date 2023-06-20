#include <iostream>
#include <queue>

using namespace std;

void BFS(int G[][7],int start,int n, queue queData)
{
    int i=start,j;
    int visited[7]= {0};
    cout << i <<endl;
    visited[i]=1;
    //enqueue(i);
    queData.push(i);
    while(!isEmpty())
    {
       // i=dequeue();
       i= queData.front;
        cout << "After dequeueing value is: "<<i <<endl;
        for(j=1; j<n; j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout << j <<endl;
                visited[j]=1;
                //enqueue(j);
                queData.push(j);
            }
        }
    }
}
int main()
{
    queue<int> queData;
    int G[7][7]= {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    BFS(G,4,7,queData);
    return 0;
}
