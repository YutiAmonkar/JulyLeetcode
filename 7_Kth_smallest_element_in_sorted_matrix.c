void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for(i=0;i<n1;i++){
        L[i] = arr[l + i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m + 1 + j];
    }
    i=0;
    j=0;
    k = l;
    while(i<n1 && j< n2){
        if(L[i] <= R[j]){
            arr[k]=L[i];
            i++;
        }
        else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i< n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    int m;
    if(l < r) {
        m =  l + (r - l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        
        merge(arr, l, m , r);
    }
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    
    int *arr;//convert 2-D to 1-D
    int i, j;
    int ret;
    int r = matrixSize, c = *matrixColSize;
    
    arr =(int*)malloc(sizeof(int) * r * c);
    
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            arr[c*i + j] = matrix[i][j];
        }
    }
    
    merge_sort(arr, 0, r*c-1);
    ret = arr[k-1];
    free(arr);
    return ret;

}