class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> all (nums1.size()+nums2.size());
        int k = 0;
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        
        while(k < (m + n))
        {
            if (i < n && j < m)
            {
                if (nums1[i] < nums2[j])
                {
                    all[k] = nums1[i];
                    i++;                  
                }
                else
                {
                    all[k] = nums2[j];
                    j++;
                }
            }
            else if (i < n)
            {
                all[k] = nums1[i];
                i++;
            }
            else if ( j < m)
            {
                all[k] = nums2[j];
                j++;
            }
            else
            {
                break;
            }
            k++;
        }
        int median_index = (m + n) / 2;
        if ((m + n) %2 == 0)
        {
            return (all[median_index - 1] + all[median_index]) / 2.0;
        }
        else
        {
            return all[median_index];
        }
    }
};