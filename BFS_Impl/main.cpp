#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;


void enqueue(int val)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = val;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}
int dequeue()
{
    temp = front;
    if (front == NULL)
    {
        cout<<"Underflow"<<endl;
        return -1;
    }
    else if (temp->next != NULL)
    {
        temp = temp->next;
        cout<<"Element deleted from queue is : "<<front->data<<endl;
        free(front);
        front = temp;
        cout<<"Current data is : "<<front->data<<endl;
        return front->data;
    }
    else
    {
        cout<<"Element deleted from queue is : "<<front->data<<endl;
        free(front);
        front = NULL;
        rear = NULL;
        return -1;
    }
}
void Display()
{
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements are: ";
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int isEmpty()
{
    return front==NULL;
}
void BFS(int G[][7],int start,int n)
{
    int i=start,j;
    int visited[7]= {0};
    cout << i <<endl;
    visited[i]=1;
    enqueue(i);
    while(!isEmpty())
    {
        i=dequeue();
        cout << "After dequeueing value is: "<<i <<endl;
        for(j=1; j<n; j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout << j <<endl;
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}
int main()
{
    int G[7][7]= {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    BFS(G,4,7);
    return 0;
}
