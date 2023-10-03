#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int k = 0;
    while (i < numsSize) {
        if(nums[i] == val) {
            nums[i] = nums[numsSize-1];
            numsSize--;
        } else {
            k ++;
            i ++;
        }
    }
    return k;
}

int main(int argc, char const *argv[])
{
    int val = 3;
    int nums[] = {3,1,2,3,6,3,5,3,3,3,7};
    int k = removeElement(nums, 11, val);
    int i;
    for (i = 0; i < 11; i++) {
        printf("%d\n", nums[i]);
    }
    printf("--> k = %d\n", k);
    return 0;
}