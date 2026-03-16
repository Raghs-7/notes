#include<iostream>
#include<algorithm>
using namespace std;

// 31st bit is sign bit
// largest --> 2**31-1
// smallest--> -2**30

// -----shift operator------

// right shift  >>
// 13>>1 = 1101>>1 = 110
// right shift by k == num/(2**k)

// left shift operator
// 0000.....01101   (13)
// 0000....011010   (13<<1)
// left shift by k == num*(2**k)


// -------NOT operator--------
// step 1 --> create it's one's complement
// step 2 --> if one's complement is positive then stop and store the one's complement
//        --> else except the sign bit find the 2's complement of one's complement 

string DecimalToBinary(int n){

    if (n==0){
        return "0";
    }
    else if (n>0){
        string result = "0";
        while(n!=1){
            if (n%2){
                result += "1";
            }
            else {
                result += "0";
            }
            n = n/2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    else {
        return "0";
    }
}

int BinaryToDecimal(string binary){
    int result = 0;
    int mul = 1;
    for (int idx=binary.size()-1; idx>=0; idx--){
        result +=  binary[idx]*mul; 
        mul *= 2;
    }
    return result;
}

void OnesComplement(string &binary){
    for (int idx=0; idx<binary.size(); idx++){
        binary[idx] = binary[idx];
    }
    return;
}

void TwosComplement(string &binary){
    OnesComplement(binary);
    // for (int idx=binary.size()-2; idx>=0; idx--){
    //     binary = carry^binary[idx];
    //     carry = carry  binary[idx];
    // }
}

void swapTwoNumber(int &a, int &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

// check if the ith bit is set or not
// 1110001 (indexing starts from right to left and first bit is zero idx bit)
bool checkIthBit(int a, int i){
    // 0000001110
    // 0000001000 (1<<3) their and will true if 3rd bit is 1 and false if it is zero
    return (a&(i<<i)); 
    // return ((a>>i)&1);
}

// set the ith bit to 1
void SetIthBit(int a, int i){
    a = a|(1<<i);
}

// clear the ith bit
void ClearIthBit(int a, int i){
    // ---my appraoch----
    // a = a | (i<<1); // will ensure that ith bit is one
    // a = a ^ (1<<i); // will ensure that ith bit is zero
    
    //----optimal-----
    // 00101010000
    // 11111101111  // make the ith bit zero and other 1 then & of both of them will make ith bit zero
    a = a | ~(a<<i);
}

void ToggleTheIthBit(int a, int i){
    a = a^(1<<i);
}

// remove the last set bit 
void RemoveTheLastSetBit(int a){
    // if you take a number down then every right bit including the right most bit will reverse
    // 16 (10000)
    // 15 (01111)
    if (a==0) return;
    a = a & (a-1);
}

// check if a number is power of two or not 
bool CheckIf2Power(int a){
    // if we remove the right most bit and number become zero then number must be power of two
    if (a&(a-1)==0){
        return true;
    }
    else return false;
}

// count the number of set bits
int CountTheNumberOfSetBits(int a){
    // pure brute force way
    int cnt = 0;
    int mul = 2;
    while (a!=0){
        cnt += a & 1;
        a = a>>1; // n = n/2
    }
    if (a==1) cnt++;
    return cnt;

    //-----approach-2-----
    int cnt = 0;
    while (a!=0){
        cnt++;
        a = a & (a-1);
    }
}

// Total number of subset of a given set of size n is --> 2**n == (1<<n)

int main(){

}