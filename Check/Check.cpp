#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> myvec;
    myvec.resize(10);
    myvec.insert(myvec.begin()+0, 0);
    myvec.insert(myvec.begin()+9, 9);
    myvec.insert(myvec.begin()+3, 3);
    myvec.insert(myvec.begin()+7, 7);
    return 0;

}
