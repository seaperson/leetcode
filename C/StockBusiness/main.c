#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0 || prices == NULL) {
        return 0;
    }
    int sum = 0;
    int j= 0;
    int balance = 0;
    for(int i = 1;i < pricesSize;i++){
        if(prices[j] < prices[i]) {
            balance = prices[i] - prices[j];
            sum += balance;
            j = i;
        }else {
            j++;
        }
    }
    return sum;
}

int main()
{
    int prices[] = {7};
    int size = sizeof(prices)/sizeof(prices[0]);
    int sum = maxProfit(prices,size);
    printf("股票买卖最大利润为:%d\n",sum);
    return 0;
}
