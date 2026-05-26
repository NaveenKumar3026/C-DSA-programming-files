#include<iostream>
using namespace std;

void heapifyUp(int arr[], int i){
    int temp = arr[i];
    while(i>1 && arr[i/2]>temp){
        arr[i] = arr[i/2];
        i=i/2;
    }
    arr[i] = temp;
}

void heapifyDown(int arr[],int size, int i){

    int temp=arr[i];

    while(true){
        int l = 2*i;
        int r = 2*i+1;

        if(l>size) break;
        int child = l;
        if(r<=size && arr[r]<arr[child]) child=r;
        if(child>size || arr[child]>=temp) break;
        arr[i]=arr[child];
        i=child;
    }
    arr[i]=temp;
}

void heapSort(int arr[], int size){
    for(int i=size; i>1; i--){
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapifyDown(arr, i-1, 1);
    }
    for(int l=1, r=size; l<r; l++, r--){
        int temp = arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
    }
}

int main(){
    int size;
    cout<<"Enter the total no. of elements: ";
    cin>>size;
    int* arr = new int[size+1];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=1;i<=size;i++){
        cin>>arr[i];
        heapifyUp(arr, i);
    }
    heapSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}