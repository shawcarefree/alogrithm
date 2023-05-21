class Solution {

public:
    bool isLetter(char c)
{
    if(c>='A'&& c<='Z')
    {
        return true;
    }
    else if(c>='a'&&c<='z')
    {
        return true;
    }
    else
    {
        return false;
    }
}
    string reverseOnlyLetters(string s)
     {
         string::iterator leftIt = s.begin();
         string::iterator rightIt = s.end()-1;
         while(leftIt < rightIt)
         {
             while(leftIt < rightIt && !isLetter(*leftIt))
             leftIt++;
             while(leftIt < rightIt && !isLetter(*rightIt))
             rightIt--;
             swap(*leftIt,*rightIt);
             leftIt++;
             rightIt--;
         }
        return s;     
    }
};