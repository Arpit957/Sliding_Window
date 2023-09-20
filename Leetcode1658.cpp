class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum<x)
        {
            return -1;
        }
        if(sum==x)
        {
            return n;
        }
        int k=sum-x;
        int i=0;
        int j=0;
        int su=0;
        while(j<n)
        {
            su+=nums[j];
            if(su==k)
            {
                maxi=max(maxi,j-i+1);
            }
            else if(su>k)
            {
                while(su>k)
                {
                    su-=nums[i];
                    i++;
                }
                if(su==k)
                {
                    maxi=max(maxi,j-i+1);
                }
            }
            j++;
        }
        if(maxi==INT_MIN)
        {
            return -1;
        }
        return n-maxi;
    }
};
