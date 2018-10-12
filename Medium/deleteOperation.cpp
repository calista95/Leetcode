/* Program: Delete Operation for Two Strings
 * Description: Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 * Date: 10/11/2018
 * Difficulty: medium
*/

#include <iostream>
#include <string>
using namespace std;


int max(int a, int b)
{
        if (a>b)
                return a;
        else
                return b;
}


int minDistance(string word1, string word2)
{
        int m=word1.length();
        int n=word2.length();

        int array[m+1][n+1];

        int i,j;


        for (i=0; i<=m; i++)
        {
                for (j=0; j<=n; j++)
                {
                        if ( i ==0 || j ==0)
                                array[i][j] = 0;
                        else if (word1[i-1] == word2[j-1])
                                array[i][j] = array[i-1][j-1]+1;
                        else
                                array[i][j] = max(array[i][j-1], array[i-1][j]);
                }
        }


        /* for testing: display array and lcs length
        for (i=0; i<=m; i++)
        {
                for (j=0; j<=n; j++)
                {
                        cout << array[i][j];
                }
                cout << endl;
        }
        */
        int lcs = array[m][n];
        //cout << "lcs:" << lcs << endl;


        return (m+n)-2*(lcs);
}


int main()
{
        string first = "sea";
        string second = "eat";

        cout << "min steps: " << minDistance(first, second) << endl;
        return 0;
}