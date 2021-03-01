class FreqStack {
private:
    map<int, int> freqOf;
    map<int, stack<int>> posOf;
    set<tuple<int, int, int>> freqPosElem;
    int currentPos;
    
public:
    FreqStack() {
        currentPos = -1;
    }
    
    void push(int x) {
        if(freqOf[x] >= 1){
            freqPosElem.erase({freqOf[x], posOf[x].top(), x});
        }
        currentPos += 1;
        posOf[x].push(currentPos);
        freqOf[x] += 1;
        freqPosElem.insert({freqOf[x], currentPos, x});
    }
    
    int pop() {
        int x = get<2>(*prev(freqPosElem.end()));
        freqPosElem.erase(prev(freqPosElem.end()));
        freqOf[x] -= 1;
        posOf[x].pop();
        if(freqOf[x] >= 1){
            freqPosElem.insert({freqOf[x], posOf[x].top(), x});
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */