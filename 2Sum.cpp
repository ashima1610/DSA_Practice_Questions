#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<limits.h>

using namespace std;

int find(int& value, vector<pair<int, int>>& v){
    for(auto& temp:v){
        if(temp.first == value){
            temp.first = INT_MIN;
            return temp.second;
        }
    }

    return 0;
} 

vector<int> twoSum(vector<int>& nums, int& target) {

    //brtue force - O(N*2)
    // for(int i=0; i<nums.size()-1; i++){
        //     int value = target-nums[i];
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[j]==value){
        //             return {i, j};
        //         }
        //     }
        // }

        // return {};

        //most optimal approach - O(N).
        // unordered_map<int, int> indexMap;
        // int n = nums.size(), value;

        // for(int i=0; i<n; i++){
        //    value = target - nums[i];
        //    if(indexMap.find(value)!=indexMap.end()){
        //        return {i, indexMap[value]};
        //    }
        //    else{
        //        //means it didn't match
        //        indexMap[nums[i]] = i;
        //    }
        // }

        // return {};

        //approach 2 : using sorting and maintaining indices in a vector/map
        vector<pair<int, int>> v;
        int n = nums.size(), value;

        for(int i=0; i<n; i++){
            v.push_back(make_pair(nums[i], i));
        }

        sort(nums.begin(), nums.end());

        int start = 0, end = n-1;
        while(start<end){
            if(nums[start]+nums[end]==target){
                 return {find(nums[start], v), find(nums[end], v)};
            }
            else if(nums[start]+nums[end]>target){
                end--;
            }
            else{
                start++;
            }
        }

        return {};
}


int main(){
    vector<int> v = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(v, target);
    cout<<ans[0]<<" , "<<ans[1];
}