/*

문제4
N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성하라. N은 10억 이하의 자연수이다.

func4(5) = 4,
func4(97615282) = 67108864,
func4(1024) = 1024

*/

#include <bits/stdc++.h>

using namespace std;

// 내가 짠 코드
int func4(int N) {
    int result = 0;
    for (int i = 1; i*2 <= N; i=i*2) {
        if (i*2 <= N) result = i*2;
    }
    return result;
}

// 바킹독 코드 -> 훨씬 깔끔하다.
int _func4(int N) {
    int val = 1;
    while(2*val <= N) val*=2;
    return val;
}

int main()
{   
    cout << _func4(10) << "\n";
    cout << _func4(97615282) << "\n";
    cout << _func4(1024) << "\n";
}