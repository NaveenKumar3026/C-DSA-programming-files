void search(int key, int a[], int n){
    int low = 0, high = n-1;

    while(low<=high){
        int mid =(low+high)/2;
        if(a[mid]==key) return mid;
        
        if(a[low]<=a[mid]){
            if(a[low]<=key && key<a[mid]) high = mid-1;
            else low = mid+1;
        }
        else{
            if(key>a[mid] && key<=a[high]) low = mid+1;
            else high = mid-1;
        }
    }
    return -1;
}