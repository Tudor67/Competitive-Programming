class SegmentTree{
private:
    const int N;
    vector<int> zerosCount;
    
    void buildTree(int node, int l, int r){
        if(l == r){
            zerosCount[node] = 1;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid);
            buildTree(2 * node + 2, mid + 1, r);
            zerosCount[node] = zerosCount[2 * node + 1] + zerosCount[2 * node + 2];
        }
    }
    
    void removeZero(int node, int l, int r, const int& POS){
        if(l == r){
            zerosCount[node] = 0;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                removeZero(2 * node + 1, l, mid, POS);
            }else{
                removeZero(2 * node + 2, mid + 1, r, POS);
            }
            zerosCount[node] = zerosCount[2 * node + 1] + zerosCount[2 * node + 2];
        }
    }
    
    int getKthZeroIndex(int node, int l, int r, int k){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(k <= zerosCount[2 * node + 1]){
            return getKthZeroIndex(2 * node + 1, l, mid, k);
        }
        return getKthZeroIndex(2 * node + 2, mid + 1, r, k - zerosCount[2 * node + 1]);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        zerosCount.resize(2 * minLeaves);
        buildTree(0, 0, N - 1);
    }
    
    void removeZero(const int& POS){
        removeZero(0, 0, N - 1, POS);
    }
    
    int getKthZeroIndex(const int& K){
        return getKthZeroIndex(0, 0, N - 1, K);
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = people.size();
        
        // sort people in increasing order of heights (in case of ties: decreasing order of k)
        vector<vector<int>> sortedPeople = people;
        sort(sortedPeople.begin(), sortedPeople.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                 return (LHS[0] < RHS[0] || (LHS[0] == RHS[0] && LHS[1] > RHS[1]));
             });
        
        // insert the shortest person at index equal to his k (==sortedPersons[0][1])
        // insert the second shortest person at index i such that there are k (==sortedPersons[1][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        // insert the third shortest person at index i such that there are k (==sortedPersons[2][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        // ...
        // insert the (N - 1)th shortest person at index i such that there are k (==sortedPersons[N - 1][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        SegmentTree segmentTree(N + 1);
        vector<vector<int>> res(N, vector<int>(2, -1));
        for(const vector<int>& PERSON: sortedPeople){
            int h = PERSON[0];
            int k = PERSON[1];
            int i = segmentTree.getKthZeroIndex(k + 1);
            res[i] = PERSON;
            segmentTree.removeZero(i);
        }
        
        return res;
    }
};