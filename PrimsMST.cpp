#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet, int V){
    int min = INT_MAX, min_index;
    for(int i=0; i<V;i++){
        if(!mstSet[i] && key[i]<min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void inputGraph(vector<vector<int>> &graph, int V) {
    cout << "Enter the weight for each edge (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "Edge (" << i << "," << j << "): ";
            cin >> graph[i][j];
        }
    }
}

void primMST(vector<vector<int>> &graph, int V){
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0]=0;
    parent[0] = -1;

    for(int count=0; count<V-1; count++){
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n"; 
}
int main() 
{ 
    int V; 
    vector<vector<int>> graph ;
    cout<<"Enter the total number of vertices: ";
    cin>>V;
    graph.assign(V, vector<int>(V, 0));
    inputGraph(graph, V);
    primMST(graph, V); 
    return 0;
}

