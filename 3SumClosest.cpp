#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int& target) {

        int n = nums.size();
        
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        int diff = INT_MAX; // Initialize the minimum difference to a large value
        int ans; // Variable to store the closest triplet sum
        
        // Step 4: Iterate over each element in the array
        for(int i=0; i<n; i++){
            int j = i+1; // Initialize the left pointer
            int k = n-1; // Initialize the right pointer
            
            // Step 6: Find the closest triplet sum using two pointers
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the current triplet sum
                
                // Step 8: Update the minimum difference and the closest sum if the current sum is closer to the target
                if(abs(sum - target) < diff){
                    diff = abs(sum - target);
                    ans = sum;
                }
                // If equal to sum, end function
                if(sum == target) return sum;

                // Step 9: Adjust the pointers based on the value of the current sum
                if(sum < target) {
                    j++; // Increment the left pointer to consider a larger element
                } else {
                    k--; // Decrement the right pointer to consider a smaller element
                }
            }
        }
        
        // Step 11: Return the closest triplet sum
        return ans;
    }

int main(){
    vector<int> v = {-1, 1, 2, -4};
    int target = 1;
    cout<<"Closest 3-sum to the target in vector v is: "<<threeSumClosest(v, target);
}