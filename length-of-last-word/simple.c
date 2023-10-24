#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s){
    int len = strlen(s);
    int wordCount = 0;
    int SPACE = 32;
    int endOfWord = 0;
    int startOfWord = 0;
    for (int i = len-1; i >=0; i-- ){
        if (s[i] == SPACE && wordCount > 0) {
            break;
        }
        if (s[i] != SPACE) {
            wordCount++;
        }
        if (wordCount == 1) {
            endOfWord = i+1;
        }
        if (wordCount > 0) {
            startOfWord = i+1;
        }
    }
    return endOfWord-startOfWord+1;
}

int main(int argc, char const *argv[])
{
    char s[12] = "day world";
    int res = lengthOfLastWord(s);
    printf("len: %d\n", res);
    return 0;
}