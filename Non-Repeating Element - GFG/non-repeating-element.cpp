//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
      unordered_map<int,int> umap;
      for(int i=0;i<n;i++)
      umap[arr[i]]++;
        
        for(int i=0;i<n;i++){
            int key=arr[i];
            auto temp=umap.find(key);
            if(temp->second==1){
                return key;
            }
        }
        return 0;
    } 
  
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends