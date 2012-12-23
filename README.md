#Description
Monotonous-queue is a kind data-strusture like queue,
which can add element at the end, and pop elements at both the front and end of the queue.

#Using Scenario
The head element in queue is the maximum/minimum value, it can retrieve the maximum/minimum value in O(1) times.

And the elements in queue are monotonous, that is a[i] <= a[i+1], i=1,..,n-1 or a[i] >= a[i+1], i=1,...,n-1

Here are the classical usage:

Given an array with size N and value k, calculate:
```
              i
    f(i) = Min/Max(array[j]), i = k,..,n
          j = i-k+1
```
The above equation often appears in dynamic equation.
Using monotonous-queue we can calculate all the values in O(n) time.

More abstract:
```
              i
    f(i) =   opt(const[j]), i = 1,..,n
           j = bound[i]
```
Which opt is operation, const[j] is any constant which can calculate in O(1),
and array bound should be monotonous, otherwise we can't use monotonous-queue.

#Details
Supposing calculate the maximum value, and the new add element is v, When adding new elements, the monotonous-queue rules are follows:

1. Scan the elments from the end of the queue to front, 
pop all elements(j+1, ..., len(queue)) until 
first facing one element which queue[j] > v, and then add element v after position j.

2. If the head element satisfy v.index - queue[head].index >=k, 
pop it, and the following maximum will be queue[head+1].value.

Here are the detail samples:
```
      n = 8, k = 3
       array                    queue
  [1], 7, 5, 3, 4, 2, 5, 6     [1,]
  [1, 7], 5, 3, 4, 2, 5, 6     [7,1,]
  [1, 7, 5], 3, 4, 2, 5, 6     [7,5,1]
  1, [7, 5, 3], 4, 2, 5, 6     [7,5,3]
  1, 7, [5, 3, 4], 2, 5, 6     [5,3] -> [5,4,3], index[4] - index[7] >= 3, pop head element
  1, 7, 5, [3, 4, 2], 5, 6     [4,3] -> [4,3,2], index[5] - index[2] >= 3, pop head element
  1, 7, 5, 3, [4, 2, 5], 6     [5]
  1, 7, 5, 3, 9, [2, 5, 6]     [6]
```

