// Simple solution: Combine two arrays into the one and sort the elements in increasing order
#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m;
    for (;i < nums1Size; i++){
        nums1[i] = nums2[nums1Size - i - 1];
    }
}

// The complexity is based on the sort algorithm, I will skip the optimization for this ques
void sort(int* nums, int numSize){
    int i, j = 0;
    for (i = 0; i < numSize; i++) {
        for (j = i+1; j < numSize; j++) {
            if (nums[i] > nums[j]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int m = 3, n = 3;
    int nums1[] = {1,2,3,0,0,0},
        nums2[] = {2,5,6};
    merge(nums1, m+n, m, nums2, n, n);
    sort(nums1, n+m);
    int i;
    for (i = 0; i < m+n; i++) {
        printf("%d\n", nums1[i]);
    }
    return 0;
}