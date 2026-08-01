class FreqStack {
public:
    unordered_map<int, int> freq;  
    unordered_map<int, stack<int>> mp;
    int max_freq;

    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;

        int f = freq[val];

        if(f > max_freq) {
            max_freq = f;
        }

        mp[f].push(val);
    }
    
    int pop() {
        int val = mp[max_freq].top();
        mp[max_freq].pop();

        freq[val]--;

        if(mp[max_freq].empty()) {
            max_freq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */