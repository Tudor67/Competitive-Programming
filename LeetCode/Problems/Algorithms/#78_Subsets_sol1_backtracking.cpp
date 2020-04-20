class Solution {
private: 
    int n;
    vector<int> nums;
    vector<int> st;
    vector<vector<int>> solutions;
    
    void back(int k){
        if(k <= n + 1){
            // save current solution
            vector<int> sol(k - 1);
            for(int i = 1; i <= k - 1; ++i){
                sol[i - 1] = nums[st[i] - 1];
            }
            solutions.push_back(sol);
            
            // generate next solution
            for(int i = st[k - 1] + 1; i <= n; ++i){
                st[k] = i;
                back(k + 1);
            }
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // init
        this->n = nums.size();
        this->nums = nums;
        this->st.resize(n + 1);
        this->solutions.clear();        
        
        // solve
        st[0] = 0;
        back(1);
            
        return solutions;
    }
};