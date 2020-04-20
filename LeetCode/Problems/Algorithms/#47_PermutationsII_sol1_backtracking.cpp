class Solution {
private:
    int n;
    vector<int> nums;
    vector<int> st;
    vector<bool> vis;
    vector<vector<int>> permutations;
    
    void back(int k, bool check_unique){
        if(k == n){
            vector<int> p(n);
            for(int i = 0; i < n; ++i){
                p[i] = nums[st[i]];
            }
            permutations.push_back(p);
        }else{
            for(int i = 0; i < n; ++i){
                if(!vis[i]){
                    bool ok = (check_unique ? (nums[st[k]] != nums[i]) : 1);
                    if(ok){
                        st[k] = i;
                        vis[st[k]] = 1;
                        check_unique = 0;
                        back(k + 1, check_unique);
                        check_unique = 1;
                        vis[st[k]] = 0;
                    }
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort
        sort(nums.begin(), nums.end());
        
        // init
        this->n = nums.size();
        this->nums = nums;
        this->permutations.clear();
        this->st.resize(n);
        this->vis.resize(n);
        
        fill(st.begin(), st.end(), 0);
        fill(vis.begin(), vis.end(), 0);
        
        // solve
        back(0, 0);
        
        return permutations;        
    }
};