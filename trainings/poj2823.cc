#include <iostream>
#include <cstdio>
#include <cstring>
#include <functional>
using namespace std; 

const int N = 1000005;
int queue[N], data[N];
int n, k;

template<typename T>
void solve(T cmp) {
  int front = 0; 
  // Notice: here rear need to be front+1 and for loop begin at 0
  // consider: when n = 1 and window size k = 1
  //           we need to enter the loop once for output the ans.
  int rear = 1; 
  queue[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i - queue[front] >= k) {
      front++;
    }
    
    // Filter the rear element which >= or <= data[i]
    for (int j = rear-1; j >= front && cmp(data[queue[j]], data[i]); --j) {
      rear--;
    }
    queue[rear++] = i; // fill

    if (i >= k-1) {
      printf("%d ", data[queue[front]]);
    }
  }
  printf("\n");
}

int main() { 
  while (scanf("%d%d", &n, &k) != EOF) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &data[i]);
    }

    solve(greater_equal<int>());
    solve(less_equal<int>());
  }

  return 0;
}
