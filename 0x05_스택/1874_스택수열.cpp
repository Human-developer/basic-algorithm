/*

백준 1874번

스택 수열

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	102662	38476	27200	36.683%

문제
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 
스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 
물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

예제 입력 1 
8
4
3
6
8
7
5
2
1

예제 출력 1 
+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-


예제 입력 2 
5
1
2
5
3
4

예제 출력 2 
NO

힌트
1부터 n까지에 수에 대해 차례로 [push, push, push, push, pop, pop, push, push, pop, push, push, pop, pop, pop, pop, pop] 
연산을 수행하면 수열 [4, 3, 6, 8, 7, 5, 2, 1]을 얻을 수 있다.

*/


/*
    느낀점 : 처음 풀었을때 통과는 되었지만, 시간도 너무 길고, 코드도 아직 너무 부족하다!!!
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> v1; // 수열을 저장하기 위한 변수
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v1.push_back(input);
    }

    int number = 1; // 1 ~ N 까지 숫자를 나타내기 위한 변수
    vector<char> v2; // '+', '-' 결과를 저장하기 위한 변수
    stack<int> s;
    for (int i = 0; i < N*2; i++) {
        if (!s.empty() && s.top() == *v1.begin()) {
            s.pop();
            v1.erase(v1.begin());
            v2.push_back('-');
        }else{
            s.push(number);
            v2.push_back('+');
            number++;    
        }
    }

    if (s.empty() && v1.empty()) {
        for (auto e : v2) cout << e << '\n';
    }else {
        cout << "NO" << '\n';
    }


    return 0;
}