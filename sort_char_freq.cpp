/*

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/

class Solution {
public:
    
    string frequencySort(string s) {
        //Solution 1
        
        /*unordered_map<char,int> cache;
        vector<pair<char,int>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            vec.push_back(make_pair(it->first,it->second));
        }
        sort(vec.begin(),vec.end(),
             [](const pair<char,int> &a,const pair<char,int> &b) {
                 return a.second > b.second;
             });
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.second;
            char c = ele.first;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;*/
       
        //solution2 
        /*unordered_map<char,int> cache;
        vector<pair<int,char>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(auto it=cache.begin();it!=cache.end();++it) {
            vec.push_back(make_pair(it->second,it->first));
        }
        sort(vec.rbegin(),vec.rend());
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.first;
            char c = ele.second;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;*/
        
        //Solution 3
        vector<int> cache(256,0);
        vector<pair<int,char>> vec;
        for(auto &ele:s) {
            ++cache[ele];
        }
        for(int i=0;i<256;++i) {
            if (cache[i]) vec.push_back({cache[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        string result = "";
        for(auto &ele:vec) {
            int no_of_char = ele.first;
            char c = ele.second;
            while (no_of_char > 0) {
                result += c;
                --no_of_char;
            }
        }
        return result;
    }
};