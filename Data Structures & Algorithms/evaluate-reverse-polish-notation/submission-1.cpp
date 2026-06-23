class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
                int x=stoi(tokens[i]);
                st.push(x);
            }
            else
            {
                if(tokens[i]=="+")
                {
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    int ans=a+b;
                    st.push(ans);

                }
                 else if(tokens[i]=="-")
                {
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    int ans=a-b;
                    st.push(ans);

                }
                 else if(tokens[i]=="*")
                {
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    int ans=a*b;
                    st.push(ans);

                }
                 else if(tokens[i]=="/")
                {
                    int b=st.top();
                    st.pop();
                    int a=st.top();
                    st.pop();
                    int ans=a/b;
                    st.push(ans);

                }
            }
        }
        return st.top();
    }
};
