#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* res = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    for (int i = 0; numbers[i] <= target; i++) {
        for (int j = i+1; numbers[j] <= target - numbers[i] ; j++) {
            if (numbers[i]+numbers[j] == target) {
                *res = i+1;
                *(res+1) = j+1;
                return res;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int nums[] = {5,25,75};
    int size = 0;
    int* res;
    res = twoSum(nums, 3, 100, &size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(res+i));
    }
    return 0;
}