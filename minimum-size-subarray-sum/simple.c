#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int minLen = numsSize+1;
    for (int i = 0; i < numsSize; i++) {
        int len = 0;
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            len = j-i+1;
            sum += nums[j];
            if (sum >= target) {
                if (minLen > len) {
                    minLen = len;
                }
            }
        }
    }
    if (minLen==numsSize+1) {
        return 0;
    }
    return minLen;
}

int main(int argc, char const *argv[])
{
    int nums[] = {1,4,4};
    int min = minSubArrayLen(4, nums, 3);
    printf("--> k = %d\n", min);
    return 0;
}