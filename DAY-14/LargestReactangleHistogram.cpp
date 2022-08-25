// O(N),O(N)
int largestRectangleArea(vector<int>& heights) {
           int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        // in stack we are storing till the left min next element so that we won't include left min
  // and we will reach till we find next min element 
  // we are calculating area for previous element as current element is next min for that element.
        for(int i = 0; i <= n; i++){
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while(!st.empty() && currHeight < heights[st.top()]){
                int top = st.top(); 
                 st.pop(); // current element on which we are working
                // now we need width & area
              // if stack is empty that means there is no element that is lesser than this one at the left all were greater
                int width = st.empty() ? i : i - st.top()-1; // width differ if we stack is empty or not empty after we pop the element
                int area = heights[top] * width; // current height * width
                maxArea = max(area, maxArea);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }
        return maxArea;
    }
