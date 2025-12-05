#include <stack>
#include <iostream>

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.size() == 0)
        {
            curr_min = val;
            st.push({val, val});
        }
        else
        {
            curr_min = std::min(val, curr_min);
            st.push({val, curr_min});
        }
    }

    void pop()
    {
        if (st.size() == 1)
        {
            curr_min = st.top().second;
            st.pop();
        }
        else
        {
            st.pop();
            curr_min = st.top().second;
        }
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }

private:
    std::stack<std::pair<int, int>> st;
    int curr_min;
};

int main()
{
    MinStack *minStack = new MinStack();
    // minStack->push(-2);
    // minStack->push(0);
    // minStack->push(-3);
    // std::cout << minStack->getMin() << std::endl; // return -3
    // minStack->pop();
    // std::cout << minStack->top() << std::endl;    // return 0
    // std::cout << minStack->getMin() << std::endl; // return -2

    // minStack->push(-10);
    // minStack->push(14);
    // std::cout << minStack->getMin() << std::endl;
    // std::cout << minStack->getMin() << std::endl;
    // minStack->push(-20);
    // std::cout << minStack->getMin() << std::endl;
    // std::cout << minStack->getMin() << std::endl;
    // std::cout << minStack->top() << std::endl; // return 0
    // std::cout << minStack->getMin() << std::endl;
    // minStack->pop();
    // minStack->push(10);
    // minStack->push(-7);
    // std::cout << minStack->getMin() << std::endl;
    // minStack->push(-7);
    // minStack->pop();
    // std::cout << minStack->top() << std::endl; // return 0
    // std::cout << minStack->getMin() << std::endl;
    // minStack->pop();

    minStack->push(0);
    minStack->push(1);
    minStack->push(0);
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    minStack->push(-2);
    minStack->push(-1);
    minStack->push(-2);
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->top() << std::endl; // return 0
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
    std::cout << minStack->getMin() << std::endl;
    minStack->pop();
}