//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        int count[26]={0};
     if(a.size()!= b.size()) return false;
      for(int i=0; i<a.size(); i++){
	        count[a[i]-'a']++;//here we are increasing the count of each alpahbet in the count array by 1
	        count[b[i]-'a']--;//here we are decresing the count of each alphabet in the same count array by 1
	    }
	  for(int i=0; i<26; i++){
	        if(count[i]>0){//if our strings where anagram then the count array for each charecter will store 0 value..if not then it is not anagram so return false
	           return false;
	        }
	    }
return true;
}
        
    

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
