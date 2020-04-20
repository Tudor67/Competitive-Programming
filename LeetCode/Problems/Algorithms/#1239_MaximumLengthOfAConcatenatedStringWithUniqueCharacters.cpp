class Solution {
private:
    void set(vector<bool>& vis, const string& s, const bool& val){
        for(char c: s){
            vis[c - 'a'] = val;
        }
    }
    
    bool valid(const vector<bool>& vis, const string& s){
        vector<bool> vis2 = vis;
        bool ok = 1;
        for(char c: s){
            if(vis2[c - 'a']){
                ok = 0;
            }
            vis2[c - 'a'] = 1;
        }
        return ok;
    }
    
    void back(int k, const int& n, const int& last_i, const int& cur_len, int& max_len,
              vector<bool>& vis, const vector<string>& arr){
        max_len = max(cur_len, max_len);
        for(int i = last_i + 1; i < n; ++i){
            if(valid(vis, arr[i])){
                set(vis, arr[i], 1);
                back(k + 1, n, i, cur_len + arr[i].length(), max_len, vis, arr);
                set(vis, arr[i], 0);
            }
        }
    }
    
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<bool> vis(26, false);
        int max_len = 0;
        back(0, n, -1, 0, max_len, vis, arr);
        return max_len;
    }
};