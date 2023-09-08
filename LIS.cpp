int lengthOfLIS(vector<int>& nums) { // O(nlogn)
        vector<int> ans = {nums[0]};
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > ans.back())ans.push_back(nums[i]);
            else ans[lower_bound(begin(ans), end(ans), nums[i]) - begin(ans)] = nums[i];                        
        }
        return ans.size();
    }