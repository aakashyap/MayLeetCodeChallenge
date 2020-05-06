/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/


//solution 1
class Solution {
public:
    /*list<char> li;
    unordered_map<char,list<char>::iterator> cache;
    void add_ele(char c) {
        li.push_back(c);
        auto it = li.end();
        --it;
        cache[c] = it;
    }
    void remove_ele(char c) {
        li.erase(cache[c]);
        cache[c] = li.end();
    }
    int firstUniqChar(string s) {
        for ( auto x : s) {
            if (cache.find(x) != cache.end()) {
                if (cache[x] != li.end()) {
                    remove_ele(x);
                }
            } else {
                add_ele(x);
            }
        }
        char result = li.front();
        cout<<"result:"<<"."<<result<<"."<<endl;
        if (result == ' ') {
            return -1;
        }
        for (int i=0;i<s.size();++i) {
            if (s[i] == result) {
                return i;
            }
        }
        return -1;
    }*/
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> cache(26,0);
        
        for (auto x:s) {
            ++cache[x-'a'];
        }
        for (int i =0; i<s.size();++i) {
            if (cache[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};



