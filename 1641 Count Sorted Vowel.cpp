// Here we can see that for a string ending with char 'a' the next char can be anything from 'a' to 'u'
// Similarly for ending with 'e', the next char can be 'e' to 'u'
// Same till we can only call 'u' for a string ending with 'u'
class Solution {
public:
    //recursive function that accepts the length left, the last char and the DP array
    int count(int n, char lc, int dp[][5])
    {
        if(n==0)
            return 1;
        
        //for indexing purposes.
        int k;
        if(lc == 'a')
            k = 0;
        else if(lc == 'e')
            k = 1;
        else if(lc == 'i')
            k = 2;
        else if(lc == 'o')
            k = 3;
        else if(lc == 'u')
            k = 4;
        
        if(dp[n][k] != -1)
            return dp[n][k];
        
        //if the last char was 'a' and the length remaining is n-1 then all the vowels can be placed after a
        if(lc == 'a')
            return dp[n][0] = count(n-1,'a',dp) + count(n-1,'e',dp) + count(n-1,'i',dp) + count(n-1,'o',dp) + count(n-1,'u',dp);
        
        if(lc == 'e')
        {
            return dp[n][1] = count(n-1,'e',dp) + count(n-1,'i',dp) + count(n-1,'o',dp) + count(n-1,'u',dp);
        }
        
        if(lc == 'i')
            return dp[n][2] =  count(n-1,'i',dp) + count(n-1,'o',dp) + count(n-1,'u',dp);
        if(lc == 'o')
            return dp[n][3] =  count(n-1,'o',dp) + count(n-1,'u',dp);
        if(lc == 'u')
            return dp[n][4] =  count(n-1,'u',dp);
        
        return 0;
    }
    int countVowelStrings(int n) 
    {
        int ans = 0;
        int dp[n+1][5];
        memset(dp,-1,sizeof dp);
        ans = count(n,'a',dp) ;
        return ans;
        
    }
};
