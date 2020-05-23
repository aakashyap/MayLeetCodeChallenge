/*

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_cache(26,0);
        vector<int> s2_cache(26,0);
        int count = 0;
        int s1_size = s1.size();
        int s2_size = s2.size();
        if (s1_size > s2_size) return false;
        for(int i=0;i<s1_size;++i) {
            ++s1_cache[s1[i]-'a'];
            ++s2_cache[s2[i]-'a'];
        }
        for (int i= 0;i<26;++i) {
            if(s1_cache[i] ==s2_cache[i]) ++count;
        }
        for(int i = s1_size;i<s2_size;++i) {
            if (count == 26) return true;
            int right = s2[i]-'a';
            int left = s2[i-s1_size]-'a';
            ++s2_cache[right];
            if (s2_cache[right] == s1_cache[right]) ++count;
            else if (s2_cache[right] == s1_cache[right] + 1) --count;
            --s2_cache[s2[i-s1_size]-'a'];
            if (s2_cache[left] == s1_cache[left]) ++count;
            else if (s2_cache[left] == s1_cache[left] - 1) --count;
        }
        return (count == 26);
    }
};