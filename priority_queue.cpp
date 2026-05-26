#include<iostream>
using namespace std;

class PriorityQueue{
    public:
        int* heap;
        int size;
        int cap;

        PriorityQueue(int cap){
            this->cap = cap;
            heap = new int[cap+1];
            size = 0;
        }

        int parent(int i){ return i/2;}

        int left(int i){ return 2*i;}

        int right(int i){ return 2*i+1;}

        void heapifyUp(int i){
            int temp=heap[i];
            while(i>1 && heap[i/2]>temp){
                heap[i]=heap[i/2];
                i=i/2;
            }
            heap[i]=temp;
        }

        void push(int value){
            if(size == cap){
                cout<<"Heap is full and cannot push other elements";
                return;
            }
            heap[++size]=value;
            heapifyUp(size);
        }

        void heapifyDown(int i){

            int temp=heap[size];
            size--;

            while(true){
                int l = left(i);
                int r = right(i);

                int child = l;
                if(heap[r]<heap[child] && r<=size) child=r;
                if(child>size || heap[child]>=temp) break;
                heap[i]=heap[child];
                i=child;
            }
            heap[i]=temp;
        }

        void pop(){
            if(size==0){
                cout<<"Heap is empty and we cannot delete any element\n";
                return;
            }
            heapifyDown(1);
        }

        void info(){
            cout<<"\nEnter 1 for inserting an element\n";
            cout<<"Enter 2 for deleting the minimum element\n";
        }

        void display(){
            if(size==0){
                cout<<"Heap is empty\n";
                return;
            }
            for(int i=1; i<=size; i++){
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
    
};

int main(){
    int value, choice;
    char c;
    PriorityQueue* q = new PriorityQueue(100);
    q->info();
    do{
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the value: ";
                cin>>value;
                q->push(value);
                q->display();
                break;
            case 2:
                q->pop();
                q->display();
                break;
            default:
                cout<<"Invalid choice";
        }
        cout<<"Do you want to continue(y/n)? ";
        cin>>c;
    }while(c=='Y' || c=='y');
    return 0;
}