class Solution {
public:
    int countOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOff, int colOff){
        int n = img1.size();
        int count = 0;

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(row+rowOff < 0 || row+rowOff >= n || col + colOff < 0 || col+ colOff >= n) continue;

                count += img1[row][col] * img2[row+rowOff][col+colOff];
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;

        for(int rowOff = -n+1; rowOff<n; rowOff++){
            for(int colOff = -n+1; colOff <n; colOff++){
                maxOverlap = max(maxOverlap, countOverlap(img1, img2, rowOff, colOff));
            }
        }
        return maxOverlap;
    }
};