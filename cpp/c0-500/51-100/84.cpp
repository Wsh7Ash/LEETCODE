class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st; // Stack to store indices
            int maxArea = 0;
            heights.push_back(0); // Append zero to handle remaining elements
            int n = heights.size();
            
            for (int i = 0; i < n; i++) {
                // Maintain increasing stack, pop when a smaller height is found
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? i : (i - st.top() - 1);
                    maxArea = max(maxArea, h * width);
                }
                st.push(i);
            }
            
            return maxArea;
        }
    };
    