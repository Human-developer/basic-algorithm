/*

백준 1475번

방 번호

시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	48430	22090	15957	44.267%

문제
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 필요한 세트의 개수를 출력한다.

예제 입력 1 
9999
예제 출력 1 
2

예제 입력 2 
122
예제 출력 2 
2

예제 입력 3 
12635
예제 출력 3 
1

예제 입력 4 
888888
예제 출력 4 
6

*/

#include <bits/stdc++.h>

using namespace std;

int arr[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    /**
     * 내 풀이
     * 바킹독 풀이와 비교해서 느낀점
     * - max 함수 활용시 풀이가 간단해진다.
     * - 바킹독은 입력값 0을 예상해서 예외처리를 신경썼지만, 문제에 입력값은 자연수 이기 때문에 예외처리가 필요없다. 다만 다음부터는 신경써야할듯..
     */

    int N;
    cin >> N;

    while(N) {
        arr[N % 10]++;
        N /= 10;
    }

    int n = 0; // 필요한 세트 수
    int sum = 0; // 6, 9 합
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        if (n < arr[i]) n = arr[i];
    }
    sum = (arr[6]+arr[9]+1)/2;
    if (n < sum) n = sum;
    cout << n;    
    
    /**
     * 바킹독 풀이
     */

    /*
    // ans = 1로 둠으로서 N = 0일때에 대한 예외처리가 자연스럽게 가능해짐
    int N, a[10] = {}, ans = 1;
    cin >> N;
    
    // 자리수 추출
    while(N){
        a[N%10]++;
        N /= 10;
    }

    for(int i = 0; i < 10; i++){
        if(i == 6 || i == 9) continue;
        ans = max(ans, a[i]);
    }
    // (a[6]+a[9])/2를 올림한 값이 6, 9에 대한 필요한 세트의 수이므로 (a[6]+a[9]+1)/2을 계산
    ans = max(ans, (a[6]+a[9]+1)/2);
    cout << ans;
    */

    return 0;
}