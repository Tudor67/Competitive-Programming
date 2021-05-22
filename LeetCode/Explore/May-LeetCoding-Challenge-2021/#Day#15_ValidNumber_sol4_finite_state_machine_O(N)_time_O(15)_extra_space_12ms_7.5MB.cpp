class FSM{
private:
    enum State{
        START_STATE, SIGN_STATE, INTEGER_STATE, DOT_STATE, DECIMAL_STATE, EXP_STATE, EXP_SIGN_STATE, EXP_INTEGER_STATE, INVALID_STATE
    };
    
    enum Symbol{
        SIGN_SYMBOL, DIGIT_SYMBOL, DOT_SYMBOL, EXP_SYMBOL, INVALID_SYMBOL
    };
    
    using StateSymbol = int;

    const unordered_map<StateSymbol, State> STATE_TRANSITION_FUNCTION = {
        {getStateSymbol(START_STATE, SIGN_SYMBOL), SIGN_STATE},
        {getStateSymbol(START_STATE, DIGIT_SYMBOL), INTEGER_STATE},
        {getStateSymbol(START_STATE, DOT_SYMBOL), DOT_STATE},
        
        {getStateSymbol(SIGN_STATE, DIGIT_SYMBOL), INTEGER_STATE},
        {getStateSymbol(SIGN_STATE, DOT_SYMBOL), DOT_STATE},
        
        {getStateSymbol(INTEGER_STATE, DIGIT_SYMBOL), INTEGER_STATE},
        {getStateSymbol(INTEGER_STATE, DOT_SYMBOL), DECIMAL_STATE},
        {getStateSymbol(DOT_STATE, DIGIT_SYMBOL), DECIMAL_STATE},
        {getStateSymbol(DECIMAL_STATE, DIGIT_SYMBOL), DECIMAL_STATE},
        
        {getStateSymbol(INTEGER_STATE, EXP_SYMBOL), EXP_STATE},
        {getStateSymbol(DECIMAL_STATE, EXP_SYMBOL), EXP_STATE},
        
        {getStateSymbol(EXP_STATE, SIGN_SYMBOL), EXP_SIGN_STATE},
        {getStateSymbol(EXP_STATE, DIGIT_SYMBOL), EXP_INTEGER_STATE},
        
        {getStateSymbol(EXP_SIGN_STATE, DIGIT_SYMBOL), EXP_INTEGER_STATE},
        
        {getStateSymbol(EXP_INTEGER_STATE, DIGIT_SYMBOL), EXP_INTEGER_STATE}
    };
    
    State state;
    
    Symbol getSymbol(char c){
        if(c == '+' || c == '-'){
            return SIGN_SYMBOL;
        }
        if(isdigit(c)){
            return DIGIT_SYMBOL;
        }
        if(c == '.'){
            return DOT_SYMBOL;
        }
        if(c == 'e' || c == 'E'){
            return EXP_SYMBOL;
        }
        return INVALID_SYMBOL;
    }
    
    StateSymbol getStateSymbol(State state, Symbol symbol){
        return 100 * state + symbol;
    }
    
public:
    FSM(){
        state = START_STATE;
    }
    
    void updateState(char c){
        if(state != INVALID_STATE){
            Symbol symbol = getSymbol(c);
            StateSymbol stateSymbol = getStateSymbol(state, symbol);
            if(STATE_TRANSITION_FUNCTION.count(stateSymbol)){
                state = STATE_TRANSITION_FUNCTION.at(stateSymbol);
            }else{
                state = INVALID_STATE;
            }
        }
    }
    
    bool isValid(){
        return (state == INTEGER_STATE || state == DECIMAL_STATE || state == EXP_INTEGER_STATE);
    }
};

class Solution {
public:
    bool isNumber(string s) {
        FSM fsm;
        for(char c: s){
            fsm.updateState(c);
        }
        return fsm.isValid();
    }
};