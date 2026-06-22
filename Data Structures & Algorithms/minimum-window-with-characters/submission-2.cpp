class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j=0;
        int mx=INT_MAX;
        string ans="";
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }
        int n=s.size();
        int count=mp.size();
        while(j<n)
        {
            if(mp.count(s[j]))
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
            if(count>0) j++;
            else
            {
                while(i<=j && count==0)
                {
                    if(mp.count(s[i])!=0)
                    {
                        int len=j-i+1;
                        if(len<mx)
                        {
                            mx=min(mx,len);
                            ans=s.substr(i,len);
                        }
                        mp[s[i]]++;
                        if(mp[s[i]]>0) count++;
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                }
                j++;
            }
        }
        return ans;
    }
};
