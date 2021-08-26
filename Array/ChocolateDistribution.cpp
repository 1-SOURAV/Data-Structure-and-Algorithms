/*
Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

Example 1:

Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.

Approach:
-->Sort the array.
    1 3 4 7 9 9 12 56
-->Check for min diff of arr[i+m-1] - arr[i] in the range 0 to n-m
*/

#include<bits/stdc++.h>
using namespace std;

long long minDiff(vector<long long>arr, long long m){
    sort(arr.begin(), arr.end());
    long long n = arr.size();
    long long ans = INT_MAX;
    
    for(int i = 0; i<=n-m; i++){
        ans = min(arr[i+m-1] - arr[i], ans);
    }
    return ans;
}

int main(){
    vector<long long>arr = {3, 4, 1, 9, 56, 7, 9, 12};
    long long m = 5;
    cout<<minDiff(arr, m);
}