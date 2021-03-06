/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
*/

#include<bits/stdc++.h>
using namespace std;

int getMedian(vector<int>nums1, vector<int>nums2){
    if(nums2.size() < nums1.size())
        return getMedian(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0;
    int high = n1;

    while(low <= high){
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n1 + n2) % 2 == 0){
                return (max(left1, left2) + min(right1, right2)) / 2.00;
            }
            else{
                return max(left1, left2);
            }
        }

        else if(left1 > right2){
            high = cut1 - 1;
        }

        else{
            low = cut1 + 1;
        }
    }

    return 0.00;
}

int main(){
    vector<int>nums1 = {-5, 3, 6, 12, 15};
    vector<int>nums2 = {-12, -10, -6, -3, 4, 10};

    cout<<getMedian(nums1, nums2);
    return 0;
}