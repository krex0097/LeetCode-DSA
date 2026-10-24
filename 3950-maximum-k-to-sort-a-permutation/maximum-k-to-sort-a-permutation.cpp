class Solution {
public:
    
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int ans=-1;
        for(int i=0;i<n;i++)
            if(nums[i]!=sorted[i])
                if(ans==-1)ans=nums[i]&sorted[i];
                else ans&=nums[i]&sorted[i];
            
        
        return (ans==-1?0:ans);
       
    }
};