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
    
    void findFirstGreater(int node, int l, int r, const int& L, const int& R, const int& THRESHOLD, int& firstGreater){
        if(R < l || r < L || firstGreater >= 0){
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
                firstGreater = tree[node];
            }
        }else{
            int mid = (l + r) / 2;
            findFirstGreater(2 * node + 1, l, mid, L, R, THRESHOLD, firstGreater);
            findFirstGreater(2 * node + 2, mid + 1, r, L, R, THRESHOLD, firstGreater);
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
    
    int findFirstGreater(const int& L, const int& R, const int& THRESHOLD){
        int firstGreater = -1;
        if(L <= R){
            findFirstGreater(0, 0, N - 1, L, R, THRESHOLD, firstGreater);
        }
        return firstGreater;
    }
};

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> nextGreater(N, N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] < nums[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> answer(N);
        SegmentTree tree(N);
        for(int i = N - 1; i >= 0; --i){
            answer[i] = tree.findFirstGreater(nextGreater[i] + 1, N - 1, nums[i]);
            tree.update(i, nums[i]);
        }
        
        return answer;
    }
};