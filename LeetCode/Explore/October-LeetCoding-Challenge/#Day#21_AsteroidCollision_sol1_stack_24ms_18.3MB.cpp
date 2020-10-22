class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int val: asteroids){
            bool valExploded = false;
            
            while(!st.empty() && st.top() > 0 && val < 0){
                if(abs(st.top()) == abs(val)){
                    // both st.top() and val will explode
                    st.pop();
                    valExploded = true;
                    break;
                }if(abs(st.top()) > abs(val)){
                    // only val will explode
                    valExploded = true;
                    break;
                }else if(abs(st.top()) < abs(val)){
                    // only st.top() will explode
                    st.pop();
                }
            }
            
            if(!valExploded){
                st.push(val);
            }
        }
        
        vector<int> answer;
        answer.reserve(st.size());
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};