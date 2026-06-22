class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        unordered_map<int,int> mp;
        if(nums.size()==0) return 0;
        int mx=1;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        while(st.size()!=0)
        {
            auto p=*st.begin();
            st.erase(p);
            if(mp.count(p-1))
            {
                int count=1+mp[p-1];
                mx=max(mx,count);
                mp[p]=count;
            }
            else
            {
                mp[p]=1;
            }
        }
        return mx;
    }
};
