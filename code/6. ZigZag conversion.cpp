//   row 1   0          ... lag...    2n-2
//   row 2   1(first term)         2n-3(second term)
//   row 3   2(first term)      2n-4(second term)
//   row n-1 n-2(first term)  n(second term)
//   row n   n-1

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();                     //length of the string
        int first = 0;                          //first term in row 2 ~ n-1
        int second = 0;                         //second term in row 2 ~ n-1
        int i = 0;                              //index for conversion string
        int lag = 2 * (numRows - 1);            //lag between terms
        string s_conv(len,' ');                 //initialize conversion string as empty
        
        if(numRows <= 1 || len <= numRows) return s;  //special cases
        
        for(int j = 0; j < len; j += lag)       //for row 1
            s_conv[i++] = s[j];
        
        for(int row = 1; row < numRows - 1; row++)  //for row 2 ~ n-1
        {
            first = row;                            //initial value of first term in each rows
            second = 2 * (numRows - 1) - row;       //initial value of second term in each rows
            while(first < len) 
            {
                s_conv[i++] = s[first];
                first += lag;
                if(second < len)
                {   s_conv[i++] = s[second];
                    second += lag;
                } else
                    break;
            }
        }
        
        for(int j = numRows - 1; j < len; j += lag) //for row n
            s_conv[i++] = s[j];
        
        return s_conv;
    }
};
