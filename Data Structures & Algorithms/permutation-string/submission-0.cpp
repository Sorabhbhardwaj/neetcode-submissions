class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i=0;
        int j=0;
        int n=s1.size();
        int k=n;
        unordered_map<char,int> cp;
        unordered_map<char,int> mp;
        for(int i=0;i<s1.size();i++)
        {
            cp[s1[i]]++;
        }
        while(j<s2.size())
        {
            mp[s2[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else
            {
                if(mp==cp) return true;
                else
                {
                    while(i<j && j-i+1>=k){
                        mp[s2[i]]--;
                        if(mp[s2[i]]==0) mp.erase(s2[i]);
                        i++;
                    }
                }
                j++;
            }
        }
        return false;

    }
};
