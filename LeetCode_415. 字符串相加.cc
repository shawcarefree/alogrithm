class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int carry = 0;
        string retStr;
        while(end1 >=0 || end2 >= 0)
        {
            int val_1;
            val_1 = end1 >=0 ? num1[end1] - '0' : 0;

            int val_2;
            val_2 = end2 >=0 ? num2[end2] - '0' : 0;
            
            int ret = val_1 + val_2 + carry;
            
            if(ret > 9)
            {
                ret -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            //retStr.insert(retStr.begin(),'0' + ret);
            retStr += ('0'+ ret);
            end1--;
            end2--;
                    
        }

        if(carry == 1)
        {
            retStr += '1';
            //retStr.insert(retStr.begin(),'1');
        }
        reverse(retStr.begin(),retStr.end());
        return retStr;
    }
};