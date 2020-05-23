/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

class Solution {
public:
    int min(int a,int b,int c) {
        return (a > b)? ((b > c)? c:b) : ((a > c)? c:a); 
    }
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i,j,result = 0;
        for (i=0;i<row;++i) {
            result += matrix[i][0];
        }
        for(i=1;i<col;++i) {
            result += matrix[0][i];
        }
        for (i=1;i<row;++i) {
            for(j=1;j<col;++j) {
                matrix[i][j] = (matrix[i][j]) ? min(matrix[i-1][j-1],matrix[i-1][j],matrix[i][j-1]) + 1:0;
                result += matrix[i][j];
            }
        }
        return result;
    }
};