class Solution {
private:
    struct Component{
        int maxValue;
        int left;
        int right;
    };

public:
    vector<int> maxValue(vector<int>& nums) {
        const int N = nums.size();

        stack<Component> st;
        for(int i = 0; i < N; ++i){
            Component curr = {nums[i], i, i};

            while(!st.empty() && st.top().maxValue > nums[i]){
                curr.maxValue = max(curr.maxValue, st.top().maxValue);
                curr.left = st.top().left;
                st.pop();
            }

            st.push(curr);
        }

        vector<int> res(N);
        while(!st.empty()){
            for(int i = st.top().left; i <= st.top().right; ++i){
                res[i] = st.top().maxValue;
            }
            st.pop();
        }

        return res;
    }
};