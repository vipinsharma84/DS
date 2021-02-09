#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            if(map.find(target - nums[i]) != map.end())
            {
                return vector<int>{map[target - nums[i]],i};
            }
            
            map[nums[i]] = i;
        }
        return vector<int>{-1,-1};        
    }
};

int main() {
    Solution Test;
    int target = 13;
    vector <int> vect {2,5,6,7,9,3,8};
    vector <int> res = Test.twoSum(vect,target);
    for (int x : res)
        cout << x << " ";
    return 0;
}