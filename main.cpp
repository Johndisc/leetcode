#include <iostream>
#include <cmath>
#include "n264(todo).h"

using namespace std;

int main() {

    set<int> s{1,2,3};
    auto it = s.end();
    transform(s.begin(), it, inserter(s, s.begin()), [] (int n) {
        return n * 2;
    });

    Solution solution;
    vector<int> asd{0,3,7,2,5,8,4,6,0,1};
    vector<int> asd1{9,3,15,20,7};
    vector<vector<int>> qwe{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};

    auto res = solution.nthUglyNumber(10);
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
