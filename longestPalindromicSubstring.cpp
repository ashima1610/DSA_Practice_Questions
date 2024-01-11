#include<iostream>
#include<string.h>

using namespace std;

string expandAroundCenter(string& s, int index1, int index2){
        string ans = "";
        int n = s.length();
        while(index1>=0 && index2<n && s[index1]==s[index2]){
            // if(index1!=index2){
            //    ans = s[index1]+ans+s[index2];
            // }
            // else{
            //     ans = s[index1];
            // }
            
            index1--;
            index2++;
        }

        return s.substr(index1+1, index2-index1-1);
    }

string longestPalindrome(string& s) {
        int n = s.length();

        if(n==1) return s;
        string longestEvenSubstring="", longestOddSubstring="";

        for(int i = 0; i<n; i++){
            string evenPalindrome = expandAroundCenter(s, i, i+1);
            if(evenPalindrome.length()>longestEvenSubstring.length()){
                longestEvenSubstring = evenPalindrome;
            }

            string oddPalindrome = expandAroundCenter(s, i, i);
            if(oddPalindrome.length()>longestOddSubstring.length()){
                longestOddSubstring = oddPalindrome;
            }

        }

        return longestEvenSubstring.length()>longestOddSubstring.length()?longestEvenSubstring:longestOddSubstring;
        
}

int main(){
    string s = "babad";
    cout<<"LONGEST PALINDROMIC SUBSTRING in "<<s<<" is: "<<longestPalindrome(s);
}
       