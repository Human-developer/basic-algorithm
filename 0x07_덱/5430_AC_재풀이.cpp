/*

백준 5430번

AC

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	91958	20319	14334	19.843%

문제
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, 
"RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

예제 입력 1 
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

예제 출력 1 
[2,1]
error
[1,2,3,5,8]
error
 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; // 테스트 개수
    cin >> T;

    while(T--) {
        string p; // 수행할 함수
        cin >> p;

        int n; // 배열에 들어있는 수의 개수
        string arr; // 배열
        cin >> n >> arr;

        deque<int> DQ;
        int arrNum = 0; // 배열에 담긴 정수
        for (int i = 1; i+1 < arr.size(); i++) {
            if (arr[i] == ',') {
                DQ.push_back(arrNum);
                arrNum = 0;
            }else {
                arrNum = 10*arrNum + (arr[i] - '0');
            }
        }
        if (arrNum != 0) DQ.push_back(arrNum);

        int rev = 0; // 뒤집은 상태인지 판단
        bool isWrong = false; // error 판단
        for (auto f : p) {
            if (f == 'R')
                rev = 1 - rev;
            else {  // 'D'
                if (DQ.empty()) {
                    isWrong = true;
                    break;
                }else{
                    if (rev != 0) DQ.pop_back();
                    else DQ.pop_front();
                }
            }
        }

        if (isWrong)
            cout << "error" << '\n';
        else {
            if (rev != 0) reverse(DQ.begin(), DQ.end());
            cout << '[';
            for (int i = 0; i < DQ.size(); i++) {
                cout << DQ[i];
                if (i+1 != DQ.size()) cout << ',';
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}