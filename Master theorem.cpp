/*The Master Theorem is a tool used to solve recurrence relations that arise in the analysis of divide-and-conquer algorithms. The Master Theorem provides a systematic way of solving recurrence relations of the form:

T(n) = aT(n/b) + f(n)


Time Complexity Analysis – 
 

Example-1: Binary Search – T(n) = T(n/2) + O(1) 
a = 1, b = 2, k = 0 and p = 0 
bk = 1. So, a = bk and p > -1 [Case 2.(a)] 
T(n) = θ(nlogba logp+1n) 
T(n) = θ(logn)
Example-2: Merge Sort – T(n) = 2T(n/2) + O(n) 
a = 2, b = 2, k = 1, p = 0 
bk = 2. So, a = bk and p > -1 [Case 2.(a)] 
T(n) = θ(nlogba logp+1n) 
T(n) = θ(nlogn)
Example-3: T(n) = 3T(n/2) + n2 
a = 3, b = 2, k = 2, p = 0 
bk = 4. So, a < bk and p = 0 [Case 3.(a)] 
T(n) = θ(nk logpn) 
T(n) = θ(n2) 
 

Example-4: T(n) = 3T(n/2) + log2n 
a = 3, b = 2, k = 0, p = 2 
bk = 1. So, a > bk [Case 1] 
T(n) = θ(nlogba ) 
T(n) = θ(nlog23) 
 

Example-5: T(n) = 2T(n/2) + nlog2n 
a = 2, b = 2, k = 1, p = 2 
bk = 2. So, a = bk [Case 2.(a)] 
T(n) = θ(nlogbalogp+1n ) 
T(n) = θ(nlog22log3n) 
T(n) = θ(nlog3n) 
 

Example-6: T(n) = 2nT(n/2) + nn 
This recurrence can’t be solved using above method since function is not of form T(n) = aT(n/b) + θ(nk logpn) 
*/
 