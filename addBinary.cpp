#include<iostream>
#include<string.h>

using namespace std;

string addBinary(string a, string b) {

        string ans = "";
        int bitA, bitB, sum = 0, carry = 0;

        while(!a.empty() && !b.empty()){
            bitA = a.back()-'0';
            bitB = b.back()-'0';

            sum = bitA + bitB + carry;
            ans = (char)((sum%2)+'0')  + ans;
            carry = sum/2;

            a.pop_back();
            b.pop_back();
        }

        while(!a.empty()){
            bitA = a.back()-'0';

            sum = bitA + carry;
            ans = (char)((sum%2)+'0')  + ans;
            carry = sum/2;

            a.pop_back();
        }

        while(!b.empty()){
            bitB = b.back()-'0';

            sum = bitB + carry;
            ans = (char)((sum%2)+'0') + ans;
            carry = sum/2;

            b.pop_back();
        }

        if(carry){
            ans = "1"+ans;
        }
        
        return ans;
}

int main(){
    string a = "1010";
    string b = "1011001";
    cout<<"Binary add of "<<a<<" and "<<b<<" gives "<<addBinary(a, b);
}
