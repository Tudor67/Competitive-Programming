class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void findFirstGreaterPos(int node, int l, int r, const int& L, const int& R, const int& THRESHOLD, int& firstGreaterPos){
        if(R < l || r < L || firstGreaterPos < N){
            // stop
        }else if(L <= l && r <= R){
            if(tree[node] > THRESHOLD){
                while(l != r){
                    int mid = (l + r) / 2;
                    if(tree[2 * node + 1] > THRESHOLD){
                        node = 2 * node + 1;
                        r = mid;
                    }else{
                        node = 2 * node + 2;
                        l = mid + 1;
                    }
                }
                firstGreaterPos = r;
            }
        }else{
            int mid = (l + r) / 2;
            findFirstGreaterPos(2 * node + 1, l, mid, L, R, THRESHOLD, firstGreaterPos);
            findFirstGreaterPos(2 * node + 2, mid + 1, r, L, R, THRESHOLD, firstGreaterPos);
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int findFirstGreaterPos(const int& L, const int& R, const int& THRESHOLD){
        int firstGreaterPos = N;
        if(L <= R){
            findFirstGreaterPos(0, 0, N - 1, L, R, THRESHOLD, firstGreaterPos);
        }
        return firstGreaterPos;
    }
};

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N);
        SegmentTree tree(N);
        for(int i = N - 1; i >= 0; --i){
            int firstGreaterPos = tree.findFirstGreaterPos(i + 1, N - 1, nums[i]);
            int secondGreaterPos = tree.findFirstGreaterPos(firstGreaterPos + 1, N - 1, nums[i]);
            if(secondGreaterPos < N){
                answer[i] = nums[secondGreaterPos];
            }else{
                answer[i] = -1;
            }
            tree.update(i, nums[i]);
        }
        
        return answer;
    }
};