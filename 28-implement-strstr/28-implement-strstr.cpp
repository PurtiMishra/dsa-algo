class Solution {
public:
    int strStr(string haystack, string needle) {
     if(needle.length()==0)
     {
       return 0;
      }
        int m=haystack.length();
        int n= needle.length();
      for(int i=0;i<m;i++)//here we can even do m but in order to optimise the code we are doing this. Here we are checking if the length of haystack is not less than that of needle
      {
          if(haystack[i]==needle[0])
          {
              for(int j=0;j<n;j++)
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