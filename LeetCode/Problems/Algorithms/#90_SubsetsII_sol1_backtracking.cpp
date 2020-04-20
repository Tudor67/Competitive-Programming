class Solution {
private: 
    int n;
    vector<int> nums;
    vector<int> st;
    vector<vector<int>> solutions;
    
    void back(int k, bool check_unique){
        if(k <= n + 1){
            // save current solution
            vector<int> sol(k - 1);
            for(int i = 1; i <= k - 1; ++i){
                sol[i - 1] = nums[st[i] - 1];
            }
            solutions.push_back(sol);
            
            // generate next solution
            for(int i = st[k - 1] + 1; i <= n; ++i){
                bool ok = (check_unique ? (st[k] > 0 && nums[st[k] - 1] != nums[i - 1]) : 1); 
                if(ok){
                    st[k] = i;
                    check_unique = 0;
                    back(k + 1, check_unique);
                    check_unique = 1;
                }
            }
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        
        // init
        this->n = nums.size();
        this->nums = nums;
        this->st.resize(n + 1);
        this->solutions.clear();
        
        // solve
        st[0] = 0;
        back(1, 0);
        
        return solutions;
    }
};