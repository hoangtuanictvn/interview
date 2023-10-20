#include <stdio.h>

int minSubArrayLen(int target, int* nums, size_t numsSize) {
    int cursor = 0; 
    int sum = 0; 
    int minLength = numsSize+1; 

    for (int windowSize = 0; windowSize < numsSize; windowSize++) { 
        sum += nums[windowSize]; 

        while (sum >= target) { 
            minLength = (minLength < windowSize - cursor + 1) ? minLength : (windowSize - cursor + 1);

            sum -= nums[cursor]; 
            cursor++;
        }
    }
    return (minLength == numsSize+1) ? 0 : minLength; 
}

int main(int argc, char const *argv[])
{
    int nums[] = {2,3,1,1,1,1,1};
    int size = sizeof(nums)/sizeof(int);
    int min = minSubArrayLen(5, nums, size);
    printf("size: %d --> min = %d\n", size, min);
    return 0;
}