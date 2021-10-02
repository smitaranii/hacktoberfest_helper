//link to question:https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
    int result=0;   //Stores and returns the integer converted value for str
    int i=0;    //just a current character pointer for string
    int sign = 1;   //multiplied at the end to result to determine if the string is +ve or -ve
    while(str[i]==' ') i++;//to ignore the starting blank spaces
     //Check the sign of string (+ or -)
     if (str[i] == '-' || str[i] == '+') {
                sign = (str[i++] == '-') ? -1 : 1; 
            }
    //Now traverse the entire string and convert it into integer
    while(str[i] >= '0' && str[i] <= '9')
    {
        if (result >  INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                result  = 10 * result + (str[i] - '0');
        i++;
    }
    return result*sign;
    }
};