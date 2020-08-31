class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int N = nums.size();
        stack<int> st;
        
        int l = N + 1;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] > nums[i]){
                l = min((int)st.top(), l);
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        int r = 0;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] > nums[st.top()]){
                r = max((int)st.top(), r);
                st.pop();
            }
            st.push(i);
        }
        
        int answer = r - l + 1;
        if(answer <= 1){
            answer = 0;
        }
        
        return answer;
    }
};