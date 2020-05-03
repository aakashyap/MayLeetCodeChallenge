/*
BAD VERSION

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.
*/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
   long int index = LONG_MAX;
public:
    void badversion_util(long int l, long int r) {
        if (l == r) {
          if (index > l) {
              index = l;
          }
          return;
        }
        if (l>r) return;
        int mid = l + (r-l)/2;
        if (isBadVersion(mid)) {
            if (index > mid) {
                index = mid;
            }
           badversion_util(l,mid);
        } else {
           badversion_util(mid+1,r);
        }
    }
    long int firstBadVersion(long int n) {
        if (n == 0) {
            return 0;
        } 
        badversion_util(1,n);
        return index;
    }
};