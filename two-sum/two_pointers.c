#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* res = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int l = 0;
    int r = numbersSize-1;
    while(1) {
        int value = numbers[l] + numbers[r];
        if(value == target) {
            *(res) = l+1;
            *(res+1) = r+1;
            return res;
        } else if (value < target) {
            l++;
        } else if (value > target) {
            r--;
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