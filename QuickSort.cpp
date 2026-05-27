#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int medianOfThree(int arr[], int left, int right){
    int mid = (left+right)/2;
    if(arr[left]>arr[mid]) swap(arr, left, mid);
    if(arr[left]>arr[right]) swap(arr, left, right);
    if(arr[mid]>arr[right]) swap(arr, mid, right);
    swap(arr, mid, right-1);
    return arr[right-1];
}

int partition(int arr[], int left, int right){
    int pivot = medianOfThree(arr, left, right);
    int i = left, j = right-2;
    while(true){
        while(arr[++i]<pivot){}
        while(arr[--j]>pivot){}
        if(i<j) swap(arr, i, j);
        else break;
    }
    swap(arr, i, right-1);
    return i;
}

void quickSort(int arr[], int left, int right){
    if(left<right){
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex-1);
        quickSort(arr, pivotIndex+1, right);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    cout<<"\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}