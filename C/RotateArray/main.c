#include <stdio.h>
#include <stdlib.h>

//学习自:https://blog.csdn.net/qq_28584889/article/details/83655019

//拔萝卜法
void rotate(int* nums, int numsSize, int k){
    int temp1,temp2,index,count=0;
    k %= numsSize;
    if(k ==  0) {
        return;
    }
    for(int i=0;i < k;i++){
        if(count >= numsSize){  //表示每个坑都移动好了
            break;
        }
        index = i;
        temp1 = nums[i];
        while((index + k) % numsSize != i){
            temp2 = nums[(index+k) % numsSize];  //先把移动到的坑空出来
            nums[(index+k)%numsSize] = temp1;    //放到空出来的坑
            index = (index + k) % numsSize;
            temp1 = temp2;          //记录拔出来的萝卜,继续移动
            count++;  //每移动成功一次加1
        }
        //回到原点,直接把拔出来的放到坑里
        nums[i] = temp1;
        count++;
    }
}

//三转法
void rotateArray(int *nums,int start,int end)
{
    if(end < start) {
        return;
    }
    int temp,temp_end = end;
    for(int i = start;i <= (start + end)/2;i++) {
        temp = nums[i];
        nums[i] = nums[temp_end];
        nums[temp_end] = temp;
        temp_end--;
    }
}

int main()
{
    int nums[] = {1,2,3,4,5,6};
    int k;
    printf("请输入旋转个数:");
    scanf("%d",&k);
    int size = sizeof(nums)/sizeof(nums[0]);
    //rotate(nums,size,k);

    rotateArray(nums,0,size - k - 1);
    rotateArray(nums,size - k,size - 1);
    rotateArray(nums,0,size - 1);

    //使用C++自带的反转函数
    /*reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());*/

    for(int i=0;i<size;i++) {
        printf("%d ",nums[i]);
    }
    return 0;
}