#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0) {
        return 0;
    }
    if(numsSize == 1) {
        return 1;
    }
    int j = 0;
    for(int i = 1;i < numsSize;i++) {
        if(nums[j] != nums[i]){
            nums[++j] = nums[i];
        }
    }
    return ++j;
}

int main()
{
    int sortArr[] = {1,1,2};
    int *p;
    p = sortArr;
    int length = sizeof(sortArr)/sizeof(sortArr[0]);
    printf("处理前数组长度:%d\n",length);
    int len = removeDuplicates(p,length);
    printf("处理后数组长度:%d\n",len);
    return 0;
}