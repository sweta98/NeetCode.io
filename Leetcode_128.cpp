class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          set<int> mp;
        if(nums.size()==0)
            return 0;
        for(int i =0;i<nums.size();i++)
        {
            mp.insert(nums[i]);
        }
        int currnum=0;
        int currstreak=0;
        int longstreak=1;
        for(int i =0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-1)!= mp.end())
            {
                currnum = nums[i];
                currstreak=1;
                while(mp.find(currnum)!= mp.end())
                {
                    currnum++;
                    currstreak++;
                }
                longstreak = max(longstreak,currstreak);
            }
        }
        return longstreak;
    }
};
