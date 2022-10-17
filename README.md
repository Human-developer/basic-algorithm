# basic-algorithm

## 익숙해지기

>공백이 포함된 문자열을 받아야 할 때
- getline 함수

```c
string s;
getline(cin, s);
cout << s;
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
>STL vector
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


