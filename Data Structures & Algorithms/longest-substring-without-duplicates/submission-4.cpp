class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        unordered_map<char,int> mp;
        if(s.size()==0) return 0;
        int ans=1;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()>=j-i+1)
            {
                j++;
            }
            else
            {
                int len=mp.size();
                ans=max(ans,len);
                while(i<n && mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        int len=j-i;
        ans=max(ans,len);
        return ans;
    }
};
