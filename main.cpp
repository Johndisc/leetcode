#include <iostream>
#include <cmath>
#include "n89.h"

using namespace std;

void func(int *x, int *y) {
    (*y) = 1;
}

int main() {
    Solution solution;
    vector<int> asd{2,1,2};
    vector<vector<char>> asd1(200, vector<char>(200, '1'));
    vector<vector<int>> qwe{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};

//    auto res = solution.grayCode(3);
//    cout << res << endl;
    int x = 2;
    func(&x, &x);
    printf("%d\n", x);
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
