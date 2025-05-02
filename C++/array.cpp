#include <iostream>
#include <vector>

class Queue{
public:
    bool empty() {
        return size()==0;
    };
    void enqueue(int e) {vec.insert(vec.end(),e);};
    int dequeue() {
        int t = -1; 
        if(!empty())
        {
            t = *(vec.begin()); 
            vec.erase(vec.begin());
        }else
            std::cout << "Queue is empty" << std::endl;
        return t;
    };
    void push_front(int e) {vec.insert(vec.begin(),e);};
    int pop_back() {int t = -1; if(!empty()) {t = *(vec.end()); vec.erase(vec.end());} return t;};
    int size() {
        return vec.size();};
    void printQueue() { for(auto e: vec) std::cout << e << " "; std::cout << std::endl;};
    
private:
    std::vector<int> vec;
};
class Stack{
public:
    bool empty() {return size() == 0;}
    int size() {return vec.size();}
    void push(int e) {vec.insert(vec.end(), e);}
    int pop() {
        int t = -1;
        if(!empty())
        {
            t = *(vec.end()-1); 
            vec.erase(vec.end()-1);
        }else 
            std::cout << "Stack is empty" << std::endl; 
        return t;}

private:
    std::vector<int> vec;
};
int main(const int argc, const char *argv[])
{
    Queue q;
    q.enqueue(10);
    q.printQueue();
    int t = q.dequeue();
    q.printQueue();
    t = q.dequeue();
    q.printQueue();


    Stack st;
    st.push(10);
    st.pop();
    st.pop();

    std::cout << "hello world!!!";
    return 0;
}