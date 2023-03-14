#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

// Function to stores the values of x and y
// and find the value of gcd(a, b)
long long ExtendedEuclidAlgo(
    long long a, long long b,
    long long& x, long long& y)
{

    //AX=B (mod N)⇒ there exist a number Y such that AX = B + NY ⇒ AX-NY=B 
    
    // Base Case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {

        // Store the result of recursive call
        long long x1, y1;
        long long gcd
            = ExtendedEuclidAlgo(b, a % b, x1, y1);

        // Update x and y using results of
        // recursive call
        x = y1;
        y = x1 - floor(a / b) * y1;

        return gcd;
    }
}

// Function to give the distinct
// solutions of ax = b (mod n)
void linearCongruence(long long A,
    long long B,
    long long N)
{
    A = A % N;
    B = B % N;

    long long u = 0, v = 0;

    // Function Call to find
    // the value of d and u
    //The number of solutions for X(mod N) is GCD(A, N)=d
    //Au+Nv=GCD(A, N)=d
    long long d = ExtendedEuclidAlgo(A, N, u, v);

    // No solution exists
    if (B % d != 0) {
        cout << -1 << endl;
        return;
    }

    // Else, initialize the value of x0
    long long x0 = (u * (B / d)) % N;
    if (x0 < 0)
        x0 += N;

    // Print all the answers
    for (long long i = 0; i <= d - 1; i++)
        cout << (x0 + i * (N / d)) % N << " ";
}

// Driver Code
int main()
{
    // Input
    // other ex: for a=9,b=21,n=30 we get x= 9,19,20
    long long A = 15;
    long long B = 9;
    long long N = 18;

    // Function Call
    linearCongruence(A, B, N);

    return 0;
}

//explanation:
//Given three positive integers A, B, and N, which represent a linear congruence of the form 
//AX=B (mod N), the task is to print all possible values of X (mod N)
//i.e in the range [0, N-1] that satisfies this equation. If there is no solution, print -1

//the algorithm is based on:
//A solution exists if and only if B is divisible by GCD(A, N) i.e B%GCD(A, N)=0.
//The number of solutions for X (mod N) is GCD(A, N).