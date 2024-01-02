// very important
// basically find union of two arrays
// they may contain duplicate elements - important point to note

//union vector should have every element exactly once - no duplicate values allowed

// Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, 
// return the union of the arrays.

// The union of two sorted arrays can be defined as an array consisting of 
// the common and the distinct elements of the two arrays. 
// The final array should be sorted in ascending order.

#include<iostream>
#include<map>
#include<vector>

using namespace std;

//brute force - this question can be done using sets/maps also
//complexity - O(logm+n) -> n,m size of input vectors 
//because we will have to sort the union vector at last to get all elements in sorted order.

vector < int > sortedArray(vector < int > a, vector < int > b) {
    //To solve the problem in linear complexity - O(N), we can 
    //use a TWO-POINTER APPROACH.

    vector<int> unionArr;
    //taking two iterators for both the vectors starting from 0.
    int i = 0, j = 0;

    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            if(unionArr.size()==0 || a[i]!=unionArr.back()){
                // the a[i]!=unionArr.back() condition is to make sure we dont add duplicate values.
                unionArr.push_back(a[i++]);
            }
            else{
                i++;
            }
        }
        else if(a[i]==b[j]){
            //common element to both vectors - push once.
            if(unionArr.size()==0 || a[i]!=unionArr.back()) unionArr.push_back(a[i]);
            i++;
            j++;
        }
        else{
            //means a[i]>b[j]
            if(unionArr.size()==0 || b[j]!=unionArr.back()){
                unionArr.push_back(b[j++]);
            }
            else{
                j++;
            }
        }
    }
    
    //pushing remaining elements, if any.
    while(i<a.size()){
        if(unionArr.size()==0 || a[i]!=unionArr.back()){
                unionArr.push_back(a[i++]);
            }
            else{
                i++;
            }
    }

    while(j<b.size()){
        if(unionArr.size()==0 || b[j]!=unionArr.back()){
                unionArr.push_back(b[j++]);
            }
            else{
                j++;
            }
    }

    return unionArr;
}

