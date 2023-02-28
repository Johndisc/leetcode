#include <iostream>
#include "n343.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> asd{2,7,13,19};
    vector<int> asd1{3,4,3};
    vector<vector<int>> qwe{{1,0}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};
	
	auto res = solution.integerBreak(10);
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
