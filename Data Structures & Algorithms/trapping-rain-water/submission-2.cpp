class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> a(n,0);
        stack<int> st;
        st.push(height[0]);
        for(int i=1;i<n;i++)
        {
            int x=height[i];
            if(x<=st.top())
            {
                a[i]=st.top();
            }
            else
            {
                while(st.size()!=0 && x>st.top())
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    a[i]=-1;
                }
                else
                {
                    a[i]=st.top();
                }
                st.push(x);
            }
        }
        vector<int> b(n,0);
        stack<int> pt;
        b[n-1]=-1;
        pt.push(height[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            int x=height[i];
            if(x<=pt.top())
            {
                b[i]=pt.top();
            }
            else
            {
                while(pt.size()!=0 && x>pt.top())
                {
                    pt.pop();
                }
                if(pt.size()==0)
                {
                    b[i]=-1;
                }
                else
                {
                    b[i]=pt.top();
                }
                pt.push(x);
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(height[i]<a[i] && height[i]<b[i])
            {
                ans[i]=min(a[i],b[i])-height[i];
            }
        }
        int aa=0;
        for(int i=0;i<n;i++)
        {
           aa+=ans[i];
        }
        return aa;
    }
};
