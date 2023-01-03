#include <iostream>
#include <cmath>
#include "n97(dp).h"

using namespace std;

int main() {
    Solution solution;
    vector<int> asd{2,1,2};
    vector<vector<char>> asd1(200, vector<char>(200, '1'));
    vector<vector<int>> qwe{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};

    auto res = solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    cout << res << endl;

//    for (auto &item1:res)
//        cout << item1 << endl;

//    for (auto item:res) {
//        for (auto item1:item) {
//            cout << item1 << " ";
//        }
//        cout << endl;
//    }
    return 0;
}
