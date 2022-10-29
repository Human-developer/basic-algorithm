/*

백준 10845번

큐

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
0.5 초 (추가 시간 없음)	256 MB	86726	39074	30574	48.954%

문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1 
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front

예제 출력 1 
1
2
2
0
1
2
-1
0
1
-1
0
3
 
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push (int x) {
    dat[tail++] = x;
}

void pop () {
    head++;
}

int size () {
    return (tail-head);
}

int empty () {
    if (head == tail)
        return 1;
    else 
        return 0;
}

int front () {
    return dat[head];
}

int back () {
    return dat[tail-1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // 명령 개수
    cin >> N;

    while(N--) {
        string s;
        cin >> s; // 명령

        if (s == "push") {
            int n;
            cin >> n;
            push(n);
        }
        else if (s == "pop") {
            if (empty()) {
                cout << -1 << '\n';
            }else {
                cout << front() << '\n';
                pop();
            }
        }
        else if (s == "size") {
            cout << size() << '\n';
        }
        else if (s == "empty") {
            cout << (int)(empty() == 1) << '\n';
        }
        else if (s == "front") {
            if (empty()) {
                cout << -1 << '\n';
            }else {
                cout << front() << '\n';
            }
        }
        else if (s == "back") {
            if (empty()) {
                cout << -1 << '\n';
            }else {
                cout << back() << '\n';
            }
        }
    }


    return 0;
}