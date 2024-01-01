// You are given an array ‘ARR’ of size ‘N’ containing each number
// between 1 and ‘N’ - 1 at least once. There is a single integer value
// that is present in the array twice. Your task is to find the
// duplicate integer value present in the array.

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findDuplicate(vector<int> &arr) 
{
    int n = arr.size();

    //APPROACH 1 : Using hashmap

    // unordered_map<int, int> frequency;
    // for(int i=0; i<n; i++){
    //     if(frequency[arr[i]]){
    //         //means element already exists
    //         return arr[i];
    //     }

    //     frequency[arr[i]]++;
    // }

    //APPROACH 2 : XOR-based approach
    int duplicate = 0;
    
    for(int i=1; i<n; i++){
        duplicate^=i;
    }

    for(int nums : arr){
        duplicate^=nums;
    }

    return duplicate;
	
}

int main(){
    vector<int> arr = {6,3,1,5,4,3,2};
    cout<<findDuplicate(arr);
}



