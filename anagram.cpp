/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        /*unordered_map<char,int> cache,temp;
        vector<int> result;
        if (s_size == 0) return result;
        bool flag = false;
        for(auto& x:p) {
            ++cache[x];
        }
        int i = 0;
        while (i<s_size-p_size+1) {
            temp = cache;
            flag = false;
            for (int j = i;j<i+p_size;++j) {
                if (temp.find(s[j]) != temp.end() && temp[s[j]] > 0) {
                    --temp[s[j]];
                } else {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                result.push_back(i);
                i += p_size;
            } else {
                ++i;
            }
        }
        return result;*/
        
        /*solution 2 
        
        vector<int> p_cache(26,0);
        vector<int> s_cache(26,0);
        int i;
        vector<int> result;
        if (s_size < p_size) return result;
        for(i=0;i<p_size;++i) {
            ++p_cache[p[i]-'a'];
            ++s_cache[s[i]-'a'];
        }
        for(i=p_size;i<s_size;++i) {
            cout<<"before if:"<<endl;
            if(isEqual(s_cache,p_cache)) {
                result.push_back(i-p_size);
            }
            cout<<"here2"<<endl;
            ++s_cache[s[i]-'a'];
            --s_cache[s[i-p_size]-'a'];
        }
        if(isEqual(s_cache,p_cache)) result.push_back(i-p_size);
        return result;
        
        solution 2*/
        
        vector<int> p_cache(26,0);
        vector<int> s_cache(26,0);
        int i;
        vector<int> result;
        if (s_size < p_size) return result;
        for(i=0;i<p_size;++i) {
            ++p_cache[p[i]-'a'];
            ++s_cache[s[i]-'a'];
        }
        for(i=p_size;i<s_size;++i) {
            cout<<"before if:"<<endl;
            if(s_cache == p_cache) {
                result.push_back(i-p_size);
            }
            cout<<"here2"<<endl;
            ++s_cache[s[i]-'a'];
            --s_cache[s[i-p_size]-'a'];
        }
        if(s_cache == p_cache) result.push_back(i-p_size);
        return result;
    }
};