class Solution {
private:
    int n;
    vector<int> nums;
    vector<int> st;
    vector<bool> vis;
    vector<vector<int>> permutations;
    
    void back(int k){
        if(k == n){
            vector<int> p(n);
            for(int i = 0; i < n; ++i){
                p[i] = nums[st[i]];
            }
            permutations.push_back(p);
        }else{
            for(int i = 0; i < n; ++i){
                if(!vis[i]){
                    st[k] = i;
                    vis[st[k]] = 1;
                    back(k + 1);
                    vis[st[k]] = 0;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // init
        this->n = nums.size();
        this->nums = nums;
        this->permutations.clear();
        this->st.resize(n);
        this->vis.resize(n);
        fill(vis.begin(), vis.end(), 0);
        
        // solve
        back(0);
        
        return permutations;
    }
};