
// O(N) -> all elements are pushed and popped in stack only once
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>ans(A.size(),-1);
    stack<int>st;
    for(int i=0;i<A.size();i++)
    {
      // keep track of smaller element and if not small then remove them for rest elements also they will be greater if this element is greater for upcoming elements
        while(!st.empty() && (st.top() >= A[i]))
        {
            st.pop();
        }
        if(!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}
