#include <iostream>
#include "n207.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> asd{3,6,9,1};
    vector<int> asd1{3,4,3};
    vector<vector<int>> qwe{{1,0}};
    vector<string> zxc{"apple","pen","applepen","pine","pineapple"};
	
	auto res = solution.canFinish(2, qwe);
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
