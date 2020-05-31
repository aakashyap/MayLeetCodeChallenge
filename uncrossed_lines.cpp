/*

We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000


*/

class Solution {
public:
    int sizea,sizeb;
    vector<vector<int>> result;
    
    /*int util(const vector<int> &A,const vector<int> &B,int a,int b) {
        if (a >= sizea || b >= sizeb) return 0;
        for (int j = b;j< sizeb;++j) {
            if (A[a] == B[j]) {
                return max(1+util(A,B,a+1,j+1),util(A,B,a+1,b));
            }
        }
        return util(A,B,a+1,b);
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        sizea = A.size();
        sizeb = B.size();
        return util(A,B,0,0);
    }*/
    
    //solution 2 
    
    int util(const vector<int> &A,const vector<int> &B,int a,int b) {
        if (a == sizea || b == sizeb) return 0;
        if (result[a][b] != -1) {
            return result[a][b];
        }
        int maxsofar = 0;
        maxsofar = max(util(A,B,a+1,b),util(A,B,a,b+1));
        if (A[a] == B[b]) {
            maxsofar = max(1+util(A,B,a+1,b+1),maxsofar);
        }
        result[a][b] = maxsofar;
        return result[a][b];
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        sizea = A.size();
        sizeb = B.size();
        result.resize(sizea);
        for (int i=0;i<sizea;++i) {
            result[i].resize(sizeb,-1);
        }
        return util(A,B,0,0);
    }
};