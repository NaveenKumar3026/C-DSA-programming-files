#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;

    Graph(int num){
        V = num;
        adj.assign(V, vector<int>(V, 0));
        visited.assign(V, false);
    }

    void addEdge(bool undir=false){
        int u, v;
        char c;
        do{
            cout<<"Enter the two vertices where the edge exists: ";
            cin>>u>>v;
            if(u<V && v<V){
                adj[u][v] = 1;
                if(undir){
                    adj[v][u] = 1;
                }
            }
            else{
                cout<<"Edge formation is not possible\n";
            }
            cout<<"Do you want to continue(y/n)? ";
            cin>>c;
        }while (c=='Y' || c=='y');
    }

    void display(){
        cout<<"Displaying the adjacency matrix\n";
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                cout<<adj[u][v]<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(int Num){
        queue<int> q;
        visited.assign(V, false);
        q.push(Num);
        visited[Num] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(int i=0; i<V; i++){
                if(adj[temp][i]==1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void DFSHelper(int v){
        visited[v] = true;
        cout<<v<<" ";
        for(int i=0;i<V;i++){
            if(adj[v][i]==1 && !visited[i]){
                DFSHelper(i);
            }
        }
    }
    
    void DFS(int start){
        visited.assign(V, false);
        DFSHelper(start);
    }

};

int main(){
    int Num, choice, start;
    cout<<"Enter the total number of vertices: ";
    cin>>Num;
    Graph* g = new Graph(Num);
    cout<<"If the graph is undirected graph enter 1\n";
    cout<<"If the graph is directed graph enter 2\n";
    cout<<"Enter the choice: ";
    cin>>choice;
    if(choice==1){
        g->addEdge(true);
    }
    else if(choice==2){
        g->addEdge();
    }
    else{
        cout<<"Invalid choice";
        return 0;
    }

    cout<<"Adjacency matrix\n";
    g->display();

    cout<<"For BFS traversal\n";
    cout<<"Enter the start vertex of the graph: ";
    cin>>start;
    cout<<"BFS traversal\n";
    g->BFS(start);
    cout<<endl;

    cout<<"For DFS traversal\n";
    cout<<"Enter the start vertex of the graph: ";
    cin>>start;
    cout<<"DFS traversal\n";
    g->DFS(start);
    cout<<endl;

    return 0;
}

