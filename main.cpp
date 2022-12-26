#include <iostream>
#include <cmath>
#include "n81.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> asd{2,5,6,0,0,1,2};
    vector<int> asd1{9,3,15,20,7};
    vector<vector<int>> qwe{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};

    auto res = solution.search(asd, 5);
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
