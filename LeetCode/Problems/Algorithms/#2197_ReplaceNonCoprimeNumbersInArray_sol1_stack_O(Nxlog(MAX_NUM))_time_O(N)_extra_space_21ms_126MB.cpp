class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int num: nums){
            st.push_back(num);
            while((int)st.size() >= 2 && gcd(st[st.size() - 2], st[st.size() - 1]) > 1){
                st[st.size() - 2] = lcm(st[st.size() - 2], st[st.size() - 1]);
                st.pop_back();
            }
        }
        return st;
    }
};