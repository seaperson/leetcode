#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a,const void* b)
{
   return (*(int*)a)-(*(int*)b);
}

bool containsDuplicate(int* nums,int numsSize)
{
    if(numsSize == 0) return false;
    qsort(nums,numsSize,sizeof(int),compare);

    for(int i = 1;i < numsSize;i++)
    {
        if(nums[i-1] == nums[i]){
            return true;
        }
    }
    return false;
}

int main()
{
    int values[] = {1,2,3};
    int len = sizeof(values)/sizeof(values[0]);
    bool exists = containsDuplicate(values,len);
    if(exists){
        printf("存在重复元素");
    }else{
        printf("不存在重复元素");
    }
    return 0;
}
