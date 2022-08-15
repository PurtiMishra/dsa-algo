class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       //Here we are using 2 pointer technique
        if(nums.size()==0)
        {
            return 0;
        }
        else
        {
            int i=0;
            for(int j=1;j<nums.size();j++)
            {
                if(nums[i]!=nums[j])
                {
                    nums[++i]=nums[j];
                }
            }
            return i+1;
        }
    }
};