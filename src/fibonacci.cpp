#include <bits/stdc++.h>

using namespace std;

size_t fib(int n)
{
    size_t memory[n+1];

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            memory[i] = 0;
        if (i == 1)
            memory[i] = 1;
        if (i > 1)
            memory[i] = memory[i-1] + memory[i-2];
    }
    
    return memory[n];
}

int main()
{
    for (int i = 0; i <= 50; i++)
    {
        cout << "Fibonacci number at (" << i << "): " << fib(i) << endl;
    }

    cout << "Fibonacci number at (100): " << fib(100) << endl;
}