class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int num = 0, sign = 1;
        int i = 0;
        //skip all whitespaces in the front
        while(str[i] == ' ')
            i++;
        //if the first non-whitespace is '-', then set the sign be -1, and move to the next one
        //if the first non-whitespace is '+', then set the sign be 1, and move to the next one
        if(str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(str[i] == '+')
        {
            sign = 1;
            i++;
        }
        //if the first non-whitespace is a number, continue with default sign = 1
        //if the next char after '+' or '-' is a numer, continue, else, break
        for(; i < len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                //set for overflow cases, INT_MAX % 10
                if((num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0' > INT_MAX % 10))) && sign == 1)
                    return INT_MAX;
                if((num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0' > INT_MAX % 10))) && sign == -1)
                    return INT_MIN;
                num = num * 10 + (str[i] - '0'); 
            } else 
                break;
        }
        
        return sign * num;
    }
};
