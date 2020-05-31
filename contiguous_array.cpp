/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> sumleft(size);
        sumleft[0] = nums[0] == 0 ? -1:1;
        int minele = sumleft[0];
        int maxele = sumleft[0];
        for (int i = 1;i<size;++i) {
            sumleft[i] = sumleft[i-1] + ((nums[i] == 0)? -1:1);
            if (sumleft[i] > maxele) maxele = sumleft[i];
            if (sumleft[i]< minele) minele = sumleft[i];
        }
        vector<int> cache(maxele-minele+1,-1);
        int result = 0;
        for(int i =0;i<size;++i) {
            if (sumleft[i] == 0) result = i+1;
            if (cache[sumleft[i]-minele] == -1) {
                cache[sumleft[i]-minele] = i;
            } else {
                if (i - cache[sumleft[i]-minele] > result) {
                    result = i - cache[sumleft[i]-minele];
                }
            }
        }
        return result;
    }
};