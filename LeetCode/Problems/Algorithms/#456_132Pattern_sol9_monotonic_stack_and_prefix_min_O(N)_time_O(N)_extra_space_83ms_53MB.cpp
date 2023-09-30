class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();

        vector<int> prevGreater(N, -1);
        stack<int> st;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && nums[i] > nums[st.top()]){
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> prefMin(N);
        prefMin[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMin[i] = min(prefMin[i - 1], nums[i]);
        }

        for(int k = 2; k < N; ++k){
            int j = prevGreater[k];
            if(j >= 1 && prefMin[j - 1] < nums[k]){
                return true;
            }
        }

        return false;
    }
};