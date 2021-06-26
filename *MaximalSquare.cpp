/*
221. Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.

*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max=0;
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        
        
        for(int i=n-1; i>=0; i--){
            if(matrix[i][m-1]=='0'){
                dp[i][m-1]=0;
            }else{
                dp[i][m-1]=1;
                max=1;
            }
        }
        
        for(int i=m-1; i>=0; i--){
            if(matrix[n-1][i]=='0'){
                dp[n-1][i]=0;
            }else{
                dp[n-1][i]=1;
                max=1;
            }
        }
        
        
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(matrix[i][j]=='0'){
                    dp[i][j] = 0;
                    
                }else{
                    dp[i][j] = min(dp[i+1][j+1], min(dp[i+1][j],dp[i][j+1]))+1;
                    if(max<dp[i][j]){
                        max = dp[i][j];
                    }
                }
            }
        }
        return max*max;
        
    }
};
