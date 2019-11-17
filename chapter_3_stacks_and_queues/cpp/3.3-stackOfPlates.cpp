#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks
{
public:
    int length = 0;

    SetOfStacks(int capacity);
    void push(int value);
    int pop();
    stack<int> *getLastStack();

private:
    int capacity;
    vector<stack<int>> stacks;
};

SetOfStacks::SetOfStacks(int capacity)
{
    this->capacity = capacity;
}

void SetOfStacks::push(int value)
{
    stack<int> *last;

    last = this->getLastStack();
    if (!last || last->size() >= this->capacity)
    {
        /* create new stack */
        stack<int> newStack;
        newStack.push(value);
        this->stacks.push_back(newStack);
        this->length++;
    }
    else
    {
        /* add to last stack */
        last->push(value);
    }
}

stack<int> *SetOfStacks::getLastStack()
{
    if (this->length == 0)
        return nullptr;
    return &this->stacks.back();
}

int SetOfStacks::pop()
{
    stack<int> *last;
    int value;

    last = this->getLastStack();
    if (!last)
        throw runtime_error("stacks are empty");
    value = last->top();
    last->pop();
    if (last->empty())
    {
        /* If stack is empty, remove it from stacks */
        this->stacks.pop_back();
        this->length--;
    }
    return value;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int i;

    SetOfStacks sos(3);
    for (auto i : arr)
        sos.push(i);
    cout << sos.length << endl; // 3
    i = 7;
    while (i--)
        sos.pop();
    // sos.pop() exception
    return 0;
}