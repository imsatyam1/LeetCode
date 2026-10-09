class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for(int asteroid: asteroids){
            bool collide = false;

            while(!st.empty() && (st.top() > 0 && asteroid < 0)){
                if(abs(st.top()) == abs(asteroid)){
                    st.pop();
                    collide = true;
                    break;
                }
                else if(abs(st.top()) > abs(asteroid)){
                    collide = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!collide){
                st.push(asteroid);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};