class Solution {
    int MAH(vector<int> &height){
        int n = height.size();
        stack<int> st;
        int maxArea = 0;

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || height[st.top()] >= height[i])){
                int length = height[st.top()];
                st.pop();
                int width;

                if(st.empty()){
                    width = i;
                }
                else{
                    width = i-st.top() -1;
                }

                maxArea= max(maxArea, length*width);
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m);
        for(int i=0; i<m; i++){
            height[i] = (matrix[0][i] == '0')?0:1;
        }

        int maxArea = MAH(height);

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                }
                else{
                    height[j] += 1;
                }
            }
            maxArea = max(maxArea, MAH(height));
        }
        return maxArea;
    }
};