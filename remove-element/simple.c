#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int k = 0;
    while (i < numsSize) {
        if(nums[i] == val) {
            int j = i;
            while (j < numsSize - 1) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                j++;
            }
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
    int nums[] = {1,2,3,6,3,5};
    int k = removeElement(nums, 6, val);
    int i;
    for (i = 0; i < 6; i++) {
        printf("%d\n", nums[i]);
    }
    printf("--> k = %d\n", k);
    return 0;
}