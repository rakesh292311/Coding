#include <iostream>
#include <vector>
using namespace std;

class Heap {
public:
    void insert(int e) {
        
        arr.emplace_back(e);
        percolateUp(arr.size()-1);

    }
    void remove(){

        if(arr.size() == 0) return;
        swap(arr[0], arr[arr.size()-1]);
        arr.erase(arr.end()-1);
        percolateDown(0);
    }
    
    int getMin() {
        if(arr.size()>0) 
            return arr[0];
        else
            return -1;
    }
    void heapify(vector<int> v) {}
    void print() {
        for(auto e:arr)
            cout << e << " ";
        cout << endl;
    }
private:
    vector<int> arr;
    int parent(int idx) { return (idx-1)/2; }
    void percolateUp(int idx) {
        if(idx <= 0) return;
        int p = parent(idx);
        if(arr[p] > arr[idx])
            swap(arr[p], arr[idx]);
        percolateUp(p);
    }
    void percolateDown(int idx) {
        int lchild = 2*idx + 1; //operator preference will take care
        int rchild = 2*idx + 2;
        int cur = arr[idx];
        if(lchild >= arr.size()) return; //no children present;
        if(rchild >= arr.size()) {
            // right child is empty
            if(cur < arr[lchild]) return;
            swap(arr[idx], arr[lchild]);
            percolateDown(lchild);
        }
        else
        {   if(cur < arr[lchild] && cur < arr[rchild]) return; //already heapified
            if(arr[lchild] > arr[rchild])
            {
                swap(arr[idx], arr[rchild]);
                percolateDown(rchild);
            }
            else
            {
                swap(arr[idx], arr[lchild]);
                percolateDown(lchild);
            }

        }
    }
};


int main()
{
    Heap h;
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);
    h.print();
    h.insert(-1);
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();
    
    return 0;
}