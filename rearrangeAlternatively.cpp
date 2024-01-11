// Given an array arr of size N containing positive and negative integers.
// Arrange the array alternatively such that every non-negative integer is 
// followed by a negative integer and vice-versa.

// The number of positive integers and negative integers may not be equal. 
// In such cases, add the extra integers at the end.

#include <bits/stdc++.h> 
#include<iostream>
#include<vector>

using namespace std;

void rearrange(vector<int> &arr)
{
	// Write your code here.
	vector<int> positives;
	vector<int> negatives;

	for(int data : arr){
		if(data<0){
			negatives.push_back(data);
		}
		else{
			positives.push_back(data);
		}
	}

	int it = 0; //iterator
	int temp = 0;
	while(it<negatives.size() && it<positives.size()){
		arr[temp++] = negatives[it];

		//edge case
		if(temp==arr.size()) break;

		arr[temp++] = positives[it];
		it++;
	}

	while(it<positives.size()){
		arr[temp++] = positives[it++];
	}

	while(it<negatives.size()){
		arr[temp++] = negatives[it++];
	}

}
