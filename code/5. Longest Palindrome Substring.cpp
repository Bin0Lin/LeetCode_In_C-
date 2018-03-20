class Solution {
private:
    int lengthOfPalindrome(string s, int left, int right)
    {
        int L = left, R = right;                        //set Left and Right index
        while(L >= 0 && R < s.length())                 //when L and R are within string
        {
            if(s[L] == s[R])                            
            {
                L--;
                R++;
            }
            else 
                break;
        }
        return (R - 1) - (L + 1) + 1;                   //step back for L and R, then calculate the length
    }
    
public:
    string longestPalindrome(string s) {
        string slp;                                     //define the longest palindrome string
        int max_len = 0;                                //the largest length
        int start = 0;                                  //the start index of palindrome string
        int len = s.length();                           //length of string s
        int leni;                                       //the longest palindrome length for s[i] 
        int len1;                                       //the palindrome length when s[i] = s[i + 1]
        int len2;                                       //the palindrome length when s[i - 1] = s[i + 1]
        
        if(len <= 1) return s;
        
        for(int i = 0; i < len - 1; ++i)
        {
            len1 = lengthOfPalindrome(s, i, i + 1);
            len2 = lengthOfPalindrome(s, i, i);
            leni = max(len1, len2);
            if(max_len < leni)
            {
                max_len = leni;
                start = i - (max_len - 1) / 2;
            }
        }
        slp = s.substr(start, max_len);
        return  slp;
    }
};
