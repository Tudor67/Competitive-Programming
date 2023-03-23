class BrowserHistory {
private:
    stack<string> backSt;
    stack<string> forwSt;
    string currentURL;

public:
    BrowserHistory(string homepage) {
        currentURL = homepage;
    }
    
    void visit(string url) {
        backSt.push(currentURL);
        currentURL = url;
        while(!forwSt.empty()){
            forwSt.pop();
        }
    }
    
    string back(int steps) {
        while(steps >= 1 && !backSt.empty()){
            forwSt.push(currentURL);
            currentURL = backSt.top();
            backSt.pop();
            steps -= 1;
        }
        return currentURL;
    }
    
    string forward(int steps) {
        while(steps >= 1 && !forwSt.empty()){
            backSt.push(currentURL);
            currentURL = forwSt.top();
            forwSt.pop();
            steps -= 1;
        }
        return currentURL;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */