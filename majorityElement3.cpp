// You are given an array ‘ARR’ and another integer number ‘K’.
// Your task is to find the all elements of ‘ARR’ which occur
// more than or equals to ‘N/K’ times in ‘ARR’ and ‘N’ is the length of array ‘ARR’.

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> countTheNumber(vector<int> &arr, int n, int k) {
	unordered_map<int, int> freq;

	for(int data : arr){
		freq[data]++;
	}

	int minOccurences = n/k;
	vector<int> majorityElements;

	for(auto temp : freq){
		if(temp.second>=minOccurences){
			majorityElements.push_back(temp.first);
		}
	}
    
	return majorityElements;

}