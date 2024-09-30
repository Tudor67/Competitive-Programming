class CustomStack {
private:
    int maxSize;
    vector<int> st;
    vector<int> delta;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if((int)st.size() < maxSize){
            st.push_back(x);
            delta.push_back(0);
        }
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }

        int val = st.back() + delta.back();
        if((int)delta.size() >= 2){
            delta[(int)delta.size() - 2] += delta[(int)delta.size() - 1];
        }

        st.pop_back();
        delta.pop_back();

        return val;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)st.size());
        if(k >= 1){
            delta[k - 1] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */