class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i =0;
        int count = 0;
        int indx = 0;

        while(i<n){
            char curr_char = chars[i];
            int count = 0;

            while(i<n && chars[i] == curr_char){
                count++;
                i++;
            }
            chars[indx++] = curr_char;

            if(count > 1){
                string count_str = to_string(count);
                for(char ch: count_str){
                    chars[indx++] = ch;
                }
            }
        }
        return indx;
    }
};