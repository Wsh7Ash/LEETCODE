class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int> st;
            int maxArea = 0;
            heights.push_back(0); // Add a sentinel value to process all bars
            int n = heights.size();
    
            for (int i = 0; i < n; i++) {
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
    
        int maximalRectangle(vector<vector<char>>& matrix) {
            if (matrix.empty()) return 0;
            int rows = matrix.size(), cols = matrix[0].size();
            vector<int> heights(cols, 0);
            int maxRectangle = 0;
    
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
                }
                maxRectangle = max(maxRectangle, largestRectangleArea(heights));
            }
    
            return maxRectangle;
        }
    };
    