// Simple solution: Combine two arrays into the one and sort the elements in increasing order
#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
    int position = 0;
    int posibleJump = nums[0];
    while (position <= posibleJump) {
        if (posibleJump >= numsSize - 1) {
            return true;
        }
        if (position+nums[position] > posibleJump) {
            posibleJump = position+nums[position];
        }
        position++;
    }
    return posibleJump >= numsSize - 1;
}
int main(int argc, char const *argv[])
{
    int nums[] = {3,0,2,0,4};
    int res = canJump(nums, 5);
    printf("%d\n", res);
    return 0;
}