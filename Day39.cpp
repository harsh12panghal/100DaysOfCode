/*



Quick Sort Algo implementation is in the code velow 


*/




int partition(vector<int>& arr, int s, int e){
    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot)
            cnt++;
    }

    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quick(vector<int>& arr, int s, int e){
    if (s >= e) {
        return;
    }

    int p = partition(arr, s, e);

    quick(arr, s, p-1);
    quick(arr, p+1, e);
}



vector<int> quickSort(vector<int> arr)
{
    int s = 0;
    int e = arr.size()-1;

    quick(arr, s, e);

    return arr;
}
