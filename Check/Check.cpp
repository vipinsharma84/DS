#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myvec;
    myvec.resize(10);
    myvec.insert(myvec.begin()+0, 1);
    myvec.insert(myvec.begin()+10, 10);
    return 0;

}
