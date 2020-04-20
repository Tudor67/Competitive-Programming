class Solution {
private:
    void back(int k, int last_elem, map<int, int>& cnt, const int& n, int& ans){
        if(k == n + 1){
            ++ans;
        }else{
            for(const pair<int, int>& p: cnt){
                if(p.second > 0){
                    int sum = last_elem + p.first;
                    int sqrt_sum = sqrt(sum);
                    bool is_valid = (k == 1 || sqrt_sum * sqrt_sum == sum);
                    if(is_valid){
                        --cnt[p.first];
                        back(k + 1, p.first, cnt, n, ans);
                        ++cnt[p.first];
                    }
                }
            }
        }
    }
    
public:
    int numSquarefulPerms(vector<int>& A) {
        map<int, int> cnt;
        for(int elem: A){
            ++cnt[elem];
        }

        int ans = 0;
        back(1, 1, cnt, A.size(), ans);
        
        return ans;
    }
};