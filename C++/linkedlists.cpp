#include <iostream>
#include <vector>
using namespace std;
int fnd(vector<int> a)
{
    int n = a.size();
    int ans =0;
    int count = 0;
    for(int i = 2; i <n; i++)
    {
        if(a[i] - a[i-1] == a[i-1] - a[i-2])
            count++;
        else 
            count = 0;
        ans += count;
    }
    return ans;
}

int main()
{
    vector <int> v = {-9,-7,-5, -3};
    fnd(v);
    return 0;
}