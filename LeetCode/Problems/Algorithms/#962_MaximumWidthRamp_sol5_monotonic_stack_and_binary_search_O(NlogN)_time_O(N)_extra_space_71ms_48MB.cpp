class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        const int N = nums.size();

        int maxWidth = 0;
        vector<int> st;
        
        for(int i = N - 1; i >= 0; --i){
            int l = 0;
            int r = (int)st.size();
            while(l != r){
                int mid = (l + r) / 2;
                if(nums[i] <= nums[st[mid]]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }

            int j = r;
            if(j < (int)st.size()){
                maxWidth = max(maxWidth, st[j] - i);
            }else{
                st.push_back(i);
            }
        }

        return maxWidth;
    }
};