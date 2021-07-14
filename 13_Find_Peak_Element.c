
int findpeak(int arr[], int l, int h, int n)
{
    int mid;
    
    mid = l + (h-l)/2;
    
    if(((mid == 0) || (arr[mid-1] <= arr[mid])) &&((mid == n-1) || (arr[mid+1] <= arr[mid])))
        return mid;
    
    if(mid > 0 && (arr[mid-1] > arr[mid]))
        return findpeak(arr, 0, mid-1, n);
    else
        return findpeak(arr, mid+1, h, n);
}

int findPeakElement(int* nums, int numsSize){
    //int n = sizeof(num) / sizeof(num[0]);    
    
    return findpeak(nums, 0, numsSize-1, numsSize);
}