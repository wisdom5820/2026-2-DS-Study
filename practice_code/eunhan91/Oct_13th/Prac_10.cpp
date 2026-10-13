#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{8, 7, 1, 3, 10, 2, 5, 6, 4, 9};
    auto nth = v.begin() + 4;

    nth_element(v.begin(), nth, v.end());

    for (int x : v) cout << x << ' ';
    cout << "\n지정 위치의 값: " << *nth << '\n';

    cout << boolalpha;
    cout << "왼쪽 정렬 여부: "
         << is_sorted(v.begin(), nth) << '\n';
    cout << "오른쪽 정렬 여부: "
         << is_sorted(nth + 1, v.end()) << '\n';
         /*
         nth_element는 항상 내부 정렬이 보장되는 연산이 아니다.
         reference:Generic_algo - partition with nth_element( ).cpp
         */
}