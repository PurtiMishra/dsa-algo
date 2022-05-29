class Solution {
    public:
    int maxs(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
public:
    int lengthOfLongestSubstring(string s) {
     int max=0;
    set<char>hash;
    int i=0;
    int j=0;
    while(i<s.length() && j<s.length())
    {
      if(hash.count(s[j]))
      {
                hash.erase(s[i]);
                i=i+1;
      }
      else
     {
     hash.insert(s[j]);
     j=j+1;
     max=maxs(j-i,max);   
     }
    }
    return max;    
    }
};