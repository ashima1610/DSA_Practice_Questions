//leetcode question no. 1836

//recursion -> include-exclude pattern.

#include<iostream>
#include<vector>

using namespace std;

void findSubsetXorSum(vector<int> nums, int i, int& sum, int& xorSum){
        if(i>=nums.size()){
           //means entire array is traversed
           sum+=xorSum;
           return;
        }

        //include
        xorSum^=nums[i];
        findSubsetXorSum(nums, i+1, sum, xorSum);

        //cancelling the xor taken in the include section
        xorSum^=nums[i];
        //exclude
        findSubsetXorSum(nums, i+1, sum, xorSum); 
}
    
int subsetXORSum(vector<int>& nums) {
        int i = 0, sum = 0, xorSum = 0;
        findSubsetXorSum(nums, i, sum, xorSum);
        
        return sum;
}

int main(){
    vector<int> v = {5, 1, 6};

    cout<<"Sum of XOR Totals of all the subsets is: "<<subsetXORSum(v);
}