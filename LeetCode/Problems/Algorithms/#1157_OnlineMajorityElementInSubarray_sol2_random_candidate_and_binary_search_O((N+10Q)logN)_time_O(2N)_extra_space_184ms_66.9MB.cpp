class MajorityChecker {
private:
    vector<int> arr;
    map<int, vector<int>> positionsOf;
    
public:
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        for(int i = 0; i < (int)this->arr.size(); ++i){
            positionsOf[this->arr[i]].push_back(i);
        }
        srand(time(NULL));
    }
    
    int query(int left, int right, int threshold) {
        const int LEN = right - left + 1;
        for(int iteration = 1; iteration <= 10; ++iteration){
            int randIndex = left + rand() % LEN;
            int candidateElem = arr[randIndex];
            vector<int>::iterator it1 = lower_bound(positionsOf[candidateElem].begin(), positionsOf[candidateElem].end(), left);
            vector<int>::iterator it2 = upper_bound(positionsOf[candidateElem].begin(), positionsOf[candidateElem].end(), right);
            int candidateElemCount = it2 - it1;
            if(candidateElemCount >= threshold){
                return candidateElem;
            }
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */