class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();                       //length of the string
        int start = 0, count = 0;                   //initialize the start position and the length of current substring
        int max_len = 0;                            //initialize the length of longest substring
        bool not_used[256];                         //define a boolean type array to mark the status of extended ASCII codes
        memset(not_used, true, sizeof(not_used));   //predefine the initial status are true (not used)
        
        if(len <= 1)  return len;                   //if the length of string is less than 1; return the length;
        
        for(int i = 0; i < len; ++i)                //tranverse all the characters in the string
        {
            if(not_used[s[i]] == true)              //if it is not_used
            {
                not_used[s[i]] = false;             //mark it as used
                count++;                            
            } 
            else                                    //when there is duplicate characters in the current substring                            
            {
                if(count > max_len) max_len = count;//if the current length is larger than maximum length, then set the current length as maximum length
                while(true)
                {
                    not_used[s[start]] = true;      //clear the used status of the current substring
                    count--;                        
                    if(s[start] == s[i])  break;    //set the start position stay at the position j (where the duplicate character firstly occurs)           
                    start++;                        
                }                           
                start++;                            //set the start position at (j + 1) 
                not_used[s[i]] = false;             //start new substring from new start
                count++;                            
            }
        }
        if(max_len < count) max_len = count;        //compare the last round length to maximum length
        return max_len;
    }
};
