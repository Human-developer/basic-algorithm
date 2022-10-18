/*

백준 3273번

두 수의 합

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	26096	9259	7066	35.531%

문제
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 
1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

출력
문제의 조건을 만족하는 쌍의 개수를 출력한다.

예제 입력 1 
9
5 12 7 10 9 1 2 3 11
13

예제 출력 1 
3

*/

#include <bits/stdc++.h>

using namespace std;

int arr[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x, cnt = 0;
    cin >> n;
    while(n--) {
        int num;
        cin >> num;
        arr[num]++;
    }
    cin >> x;

    for (int i = 0; i < x; i++){
        if (arr[i] == 1) {
            if (i != x-i && arr[x-i] == 1) {
                cnt++;
                arr[x-i]--;
            }    
        }
    }
    cout << cnt;

    return 0;
}