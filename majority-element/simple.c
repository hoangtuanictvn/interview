#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int count = 1;
    int majority = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            majority = nums[i];
        }
        if (nums[i] == majority) {
            count ++;
        } else {
            count --;
        }
    }
    return majority;
}

int main(int argc, char const *argv[])
{
    int nums[] = {6,5,5};
    int k = majorityElement(nums, 3);
    printf("--> majority = %d\n", k);
    return 0;
}