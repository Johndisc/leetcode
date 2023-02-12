#include <iostream>
#include "n174.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> asd{3,6,9,1};
    vector<int> asd1{3,4,3};
    vector<vector<int>> qwe{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};

    auto res = solution.maximumGap(asd);
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
