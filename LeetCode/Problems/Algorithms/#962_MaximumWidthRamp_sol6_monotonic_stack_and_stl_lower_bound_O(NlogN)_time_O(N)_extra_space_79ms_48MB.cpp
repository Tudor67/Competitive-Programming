class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();

        int maxWidth = 0;
        vector<int> st;

        for(int i = N - 1; i >= 0; --i){
            int j = lower_bound(st.begin(), st.end(), i,
                                [&](int lhs, int rhs){
                                    return (nums[lhs] < nums[rhs]);
                                })
                    - st.begin();
                    
            if(j < (int)st.size()){
                maxWidth = max(maxWidth, st[j] - i);
            }else{
                st.push_back(i);
            }
        }

        return maxWidth;
    }
};