class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
             unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i =0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!= mp.end())
                mp[nums[i]]++;
            else
                mp[nums[i]]=1;
        }
       for(auto it : mp)
       {
           if(pq.size()==k && pq.top().first<it.second)
           {
               pq.pop();
               pq.push(make_pair(it.second,it.first));
           }
           else if(pq.size()==k)
               continue;
           else
               pq.push(make_pair(it.second,it.first));
       }
        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};
