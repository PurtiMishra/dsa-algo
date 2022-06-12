class Solution {
public:
    int strStr(string haystack, string needle) {
     if(needle.length()==0)
     {
       return 0;
      }
        int m=haystack.length();
        int n= needle.length();
      for(int i=0;i<m-n+1;i++)
      {
          if(haystack[i]==needle[0])
          {
              for(int j=0;j<needle.length();j++)
              {
                  if(haystack[i+j]==needle[j])
                  {
                      if(j==needle.length()-1)
                      {
                          return i;
                       }
                  }
                  else
                  {
                      break;
                  }
              }
          }
      }
        return -1;
    }
};