// Assume f(i): maximium sum of sub sequence which len < given value k 
//              in array[0,...,i] 
// So we will have:
//            i  
//    f(i) = MAX (sum[i]-sum[j])
//          j=i-k+1
//                     i
//         = sum[i] - MIN(sum[j])
//                   j=i-k+1
//          i
// The MIN(sum[j]) calculation can use monotonous-queue optimise 
//     j=i-k+1
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 

const int N = 1000005;
const int INF = 1000000000;

struct element {
  int pos;
  int val;
  element() {}
  element(int pos, int val) {
    this->pos = pos;
    this->val = val;
  }
};

int data[N];
element queue[N];
int sum[N];

int main() { 

  int cases;
  int n, k;

  cin >> cases;
  while (cases--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> data[i];
    }

    for (int i = 1; i < k; ++i) {
      data[++n] = data[i];
    }

    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1] + data[i];
    }

    int front = 0;
    int rear = 1;

    queue[0] = element(1, sum[0]);
    int maximium = -INF;
    int ans_len = INF;
    int ans_pos;

    for (int i = 1; i <= n; ++i) {
      if (i - queue[front].pos >= k) {
        front++;
      }

      int j = rear-1;
      for (;j >= front && queue[j].val >= sum[i-1]; --j) {
        rear--;
      }
      queue[rear++] = element(i, sum[i-1]);
      if (sum[i] - queue[front].val > maximium || 
          sum[i] - queue[front].val == maximium && i < ans_len) {
        maximium = sum[i] - queue[front].val;
        ans_len = i - queue[front].pos + 1;
        ans_pos = i - ans_len + 1;
      }
    }

    n -= k-1;
    int ans_end = ans_pos+ans_len-1;
    ans_end = ans_end > n?ans_end-n:ans_end;
    cout << maximium << " " << ans_pos << " " << ans_end << endl;
  }
  
  return 0;
}
