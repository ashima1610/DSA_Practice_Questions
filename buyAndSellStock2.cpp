#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//Buy and stock sell 2 - leetcode problem medium level - 112
//I start with a variable to track the total profit and another to keep track of the 
//last buying price. As I iterate through each day's price, I compare it with the 
//last buying price. If the current price is lower, it becomes the new buying price. 
//Otherwise, if selling at the current price yields a profit (current price is higher 
//than the last buying price), I add this profit to the total and update the 
//last buying price to the current one. This approach ensures that I am always ready to 
//make the best transaction based on the latest information, thus maximizing the 
//overall profit.

int maxProfit(vector<int>& prices) {
        int maxProfit = 0, n = prices.size(), lastBuyPrice = INT_MAX;
        for(int i=0; i<n; i++){
            if(prices[i]<lastBuyPrice){
                lastBuyPrice = prices[i];
            }
            else{
                //means I have a profit to earn
                maxProfit+=prices[i]-lastBuyPrice;
                lastBuyPrice = prices[i];           
              }
        }

        return maxProfit;
}

int main(){
    vector<int> v1 = {7,1,5,3,6,4};
    cout<<"Maximum profit that can be earned from it is: "<<maxProfit(v1);

    vector<int> v2 = {1, 2, 3, 4, 5};
    cout<<"\nMaximum profit that can be earned from it is: "<<maxProfit(v2);
}