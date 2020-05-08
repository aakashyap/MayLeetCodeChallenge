/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int majele;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                majele = num;
                count = 1;
            } else {
                if (num == majele) {
                    ++count;
                } else {
                    --count;
                }
            }
        }
        return majele;
    }
};