class Solution {
int getTranslateNum(char s) {
    switch(s) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
    return 0;
}
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        int returnValue =getTranslateNum(s[s.length()-1]);
        for(int i=s.length()-2;i>=0;i--)
        {
            if(getTranslateNum(s[i])<getTranslateNum(s[i+1]))
            {
                returnValue-=getTranslateNum(s[i]);
            }
            else
            {
                returnValue+=getTranslateNum(s[i]);
            }
         }
        return returnValue;
    }
};
