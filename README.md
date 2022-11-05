# basic-algorithm

## [다시풀어보기 링크](./다시풀어보기.md)

## 익숙해지기

>공백이 포함된 문자열을 받아야 할 때
- getline 함수

```c
string s;
getline(cin, s);
cout << s;
```
---

>최대값
- max 함수

```c
max(a, b);
```

---

>전체를 특정 값으로 초기화 시킬 때
- fill

```c
int a[21];
int b[21][21];

fill(a, a+21, 0);
for (int i = 0; i < 21; i++)
  fill(b[i], b[i]+21, 0);
```

---
>STL 벡터 (vector)
- 기본 사용 방법

```c
vector<int> v1(3, 5); // {5,5,5};
cout << v1.size() << '\n'; // 3
v1.push_back(7); // {5,5,5,7};

vector<int> v2(2); // {0,0};
v2.insert(v2.begin()+1, 3); // {0,3,0};

vector<int> v3 = {1,2,3,4}; // {1,2,3,4}
v3.erase(v3.begin()+2); // {1,2,4};

vector<int> v4; // {}
v4 = v3; // {1,2,4}
cout << v4[0] << v4[1] << v4[2] << '\n';
v4.pop_back(); // {1,2}
v4.clear(); // {}
```
- 주의 사항

```c
vector<int> v1 = {1,2,3,4,5,6};

// 1. range-based for loop (since c++11)
for (int e : v1)
    cout << e << ' ';

// 2. not bad
for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << ' ';

// 3. *** WRONG *** unsigned int overflow로 런타임에러 발생
for (int i = 0; i <= v1.size()-1; i++)
    cout << v1[i] << ' ';
```

---
>STL 리스트 (list)
- 기본 사용 방법

```c
list<int> L = {1,2}; // 1 2
list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
L.push_front(10); // 10 1 2
cout << *t << '\n'; // t가 가리키는 값 = 1을 출력
L.push_back(5); // 10 1 2 5
L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                // 10 6 1 5, t가 가리키는 값은 5
cout << *t << '\n'; // 5

// c++11 이상
for(auto i : L) 
  cout << i << ' ';

cout << '\n';

// c++11 미만
for(list<int>::iterator it = L.begin(); it != L.end(); it++)
  cout << *it << ' ';
```

---
>STL 스택 (stack)
- 기본 사용 방법

```c
stack<int> S;
S.push(10); // 10
S.push(20); // 10 20
S.push(30); // 10 20 30
cout << S.size() << '\n'; // 3
if(S.empty()) cout << "S is empty\n";
else cout << "S is not empty\n"; // S is not empty
S.pop(); // 10 20
cout << S.top() << '\n'; // 20
S.pop(); // 10
cout << S.top() << '\n'; // 10
S.pop(); // empty
if(S.empty()) cout << "S is empty\n"; // S is empty
cout << S.top() << '\n'; // runtime error 발생
```

---
>STL 큐 (queue)
- 기본 사용 방법

```c
queue<int> Q;
Q.push(10); // 10
Q.push(20); // 10 20
Q.push(30); // 10 20 30
cout << Q.size() << '\n'; // 3
if(Q.empty()) cout << "Q is empty\n";
else cout << "Q is not empty\n"; // Q is not empty
Q.pop(); // 20 30
cout << Q.front() << '\n'; // 20
cout << Q.back() << '\n'; // 30
Q.push(40); // 20 30 40
Q.pop(); // 30 40
cout << Q.front() << '\n'; // 30
```

---
>STL 덱 (deque)
- 기본 사용 방법
```c
deque<int> DQ;
DQ.push_front(10); // 10
DQ.push_back(50); // 10 50
DQ.push_front(24); // 24 10 50
for(auto x : DQ)cout<<x;
cout << DQ.size() << '\n'; // 3
if(DQ.empty()) cout << "DQ is empty\n";
else cout << "DQ is not empty\n"; // DQ is not empty
DQ.pop_front(); // 10 50
DQ.pop_back(); // 10
cout << DQ.back() << '\n'; // 10
DQ.push_back(72); // 10 72
cout << DQ.front() << '\n'; // 10
DQ.push_back(12); // 10 72 12
DQ[2] = 17; // 10 72 17
DQ.insert(DQ.begin()+1, 33); // 10 33 72 17
DQ.insert(DQ.begin()+4, 60); // 10 33 72 17 60
for(auto x : DQ) cout << x << ' ';
cout << '\n';
DQ.erase(DQ.begin()+3); // 10 33 72 60
cout << DQ[3] << '\n'; // 60
DQ.clear(); // DQ의 모든 원소 제거
```