class Solution {
public:
static bool cmp(int &a,int &b)
{
    return a>b;
}
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mp;
        int n=position.size();
        for(int i=0;i<speed.size();i++)
        {
            mp[position[i]]=speed[i];
        }
        sort(position.begin(),position.end(),cmp);stack<double> st;
        for(int i=0;i<n;i++)
        {
            double time=1.0*(target-position[i])/mp[position[i]];
            if(st.size()==0 || time>st.top())
            {
                st.push(time);
            }
        }
        return st.size();
    }
};
