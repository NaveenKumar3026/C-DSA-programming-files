#include<iostream>
using namespace std;

int main(){
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *a = new int[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the max value of the elements: ";
    cin>>k;
    int *c = new int[k+1];
    for(int i=0;i<k+1;i++){
        c[i] = 0;
    }
    int *b = new int[n];
    for(int i=0;i<n;i++){
        c[a[i]]++;
    }
    for(int i=1;i<k+1;i++){
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }
    cout<<"\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;

}