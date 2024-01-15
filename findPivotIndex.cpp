#include<iostream>
#include<vector>

using namespace std;
// The pivot index is the index where the sum of all the numbers strictly 
// to the left of the index is equal to the sum of all the numbers strictly 
// to the index's right.

//Your goal is to find the pivot index of the array.

int pivotIndex(vector<int>& nums) {
        int n = nums.size(), leftSum = 0, rightSum = 0;
        for(int i = 1; i<n; i++){
           rightSum+=nums[i];
        }

        if(leftSum==rightSum){
            return 0;
        }

        for(int i = 1; i<n; i++){
            leftSum+=nums[i-1];
            rightSum-=nums[i];
            if(leftSum==rightSum){
                return i;
            }
        }

        return -1;
}

int main(){
    vector<int> v = {1, 7, 3, 6, 5, 6};
    cout<<"Pivot index is: "<<pivotIndex(v);
}