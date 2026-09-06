class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        moveElements();
        
        int x = output.top();
        output.pop();
        return x;
    }

    int peek() {
        moveElements();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

private:
    void moveElements() {
        // Move elements only when output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }
};
