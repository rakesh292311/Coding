#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Stack{
public:
    int top() {if(!empty()) return arr[t];}
    void push(int e) {arr[++t] = e;}
    void pop() {t--;}
    int size() {return t+1;}
    bool empty()  { return !size();}


private:
    array<int,10> arr;
    int t = -1;
};

int main()
{
    Stack st;
    st.push(10);
    cout << st.top() << endl;
    st.pop();
    cout << st.empty();
    return 0;
}