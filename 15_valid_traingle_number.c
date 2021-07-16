/*Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.*

//Refer Pepcoding Video

void merge(int *arr, int l, int m, int r)
{
    int i;// Left array counter
    int j; // right array counter
    int k; // merge array counter
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for(i=0;i<n1;i++){
        L[i] = arr[i + l]; 
    }
    
    for(j=0;j<n2;j++){
        R[j] = arr[m+j+1];
    }
    
    i = 0;
    j = 0;
    k = l;
    while((i < n1) && (j < n2)){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i< n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j< n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

void merge_sort(int *arr, int l, int r)
{
    int m;
    if(l < r) {
        m =  l + (r - l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        
        merge(arr, l, m , r);
    }
}

int triangleNumber(int* nums, int numsSize){
    int l, r, i, count = 0;
    merge_sort(nums, 0, numsSize-1);
    
    for(i=numsSize-1;i>=2;i--){
        l = 0;
        r = i - 1;
        
        while(l<r){
            if((nums[l] + nums[r]) > nums[i]){
                count += r-l;
                r--;
            }
            else{
                l++;
            }
        }
    }
    
    return count;
    
    
}
