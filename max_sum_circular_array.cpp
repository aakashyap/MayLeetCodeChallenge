/*

Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

*/
class Solution {
public:
    /*int maxSubarraySumCircular(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int size = A.size();
        int i,j,x,y;
        int sum,max = A[0];
        for (i = 1;i<=size;++i) {
            sum = 0;
            for (j = 0;j<i;++j) {
                sum += A[j];
                if (sum > max) max = sum;
            }
            if (i == size) {
                if (sum > max) {
                    max = sum;
                }
                return max;
            }
            for (x=0,y=i;x<size-1;++x,++y) {
                if (y>=size) y -= size;
                sum += A[y] - A[x];
                if (sum > max) max = sum;
            }
        }
        return -1;
    }*/
    int maxSubarraySumCircular(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_sum = INT_MIN;
        int min_sum = INT_MAX;
        int max_curr = 0;
        int min_curr = 0;
        int total = 0;
        for (auto& x:A) {
            max_curr = max(max_curr+x,x);
            max_sum = max(max_sum,max_curr);
            min_curr = min(min_curr+x,x);
            min_sum = min(min_sum,min_curr);
            total += x;
        }
        if (max_curr >0) return max(max_sum,total - min_sum);
        return max_sum;
    }
};