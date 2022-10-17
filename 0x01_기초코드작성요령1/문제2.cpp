/*

문제2
주어진 길이 N의 int 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성하라.
arr의 각 수는 0 이상 100 이하이고 N은 1000 이하이다.

func2({1, 52, 48}, 3) = 1,
func2({50, 42}, 2) = 0,
func2({4, 13, 63, 87}, 4) = 1

*/

#include <bits/stdc++.h>

using namespace std;

int temp[101]; // 임력 받은 배열을 카운트할 임시 배열

int func2(int arr[], int N) {
    
    for (int i = 0; i < N; i++) {
        if (temp[100 - arr[i]] != 0) return 1;
        temp[arr[i]]++;
    }

    return 0;
}

int main()
{
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};
    
    cout << func2(arr1, 3) << "\n"; 
    cout << func2(arr2, 2) << "\n"; 
    cout << func2(arr3, 4) << "\n"; 
}