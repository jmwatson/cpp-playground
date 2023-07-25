#include <bits/stdc++.h>

using namespace std;

using iter = string::const_iterator;

// class CommonChildMemoizer
// {
//     public:
//         CommonChildMemoizer(const string& s1, const string& s2)
//             :
//             n1{s1.size() + 1},
//             n2{s2.size() + 1},
//             s1{s1},
//             s2{s2}
//         {
//             memory.resize(n1 * n2, -1);
//         }

//         int Go()
//         {
//             return MaxChildRanges(begin(s1), end(s1), begin(s2), end(s2));
//         }
//     private:
//         size_t n1;
//         size_t n2;
//         const string& s1;
//         const string& s2;
//         vector<int> memory;

//         int& At(size_t i1, size_t i2)
//         {
//             return memory[n1 * i2 + i1];
//         }

//         int MaxChildRanges(iter b1, iter e1, iter b2, iter e2)
//         {
//             auto& mem = At(e1 - b1, e2 - b2);
//             if (mem != -1)
//             {
//                 return mem;
//             }

//             if (b1 == e1 || b2 == e2)
//             {
//                 mem = 0;
//                 return mem;
//             }

//             if (*b1 == *b2)
//             {
//                 mem = 1 + MaxChildRanges(next(b1), e1, next(b2), e2);;
//                 return mem;
//             }

//             mem = max(
//                 MaxChildRanges(next(b1), e1, b2, e2),
//                 MaxChildRanges(b1, e1, next(b2), e2)
//             );
//             return mem;
//         }
// };

int& At(int memory[], size_t n1, size_t i1, size_t i2)
{
    return memory[n1 * i2 + i1];
}

int MaxChildRanges(int memory[], size_t n1, iter b1, iter e1, iter b2, iter e2)
{
    auto& mem = At(memory, n1, e1 - b1, e2 - b2);
    if (mem != -1)
    {
        return mem;
    }

    if (b1 == e1 || b2 == e2)
    {
        mem = 0;
        return mem;
    }

    if (*b1 == *b2)
    {
        mem = 1 + MaxChildRanges(memory, n1, next(b1), e1, next(b2), e2);;
        return mem;
    }

    mem = max(
        MaxChildRanges(memory, n1, next(b1), e1, b2, e2),
        MaxChildRanges(memory, n1, b1, e1, next(b2), e2)
    );
    return mem;
}

int Go(const string& s1, const string& s2)
{
    int n1 = s1.size() + 1,
        n2 = s2.size() + 1,
        size = n1 * n2;

    int memory[n1 * n2];
    
    for (int i = 0; i < n1 * n2; i++)
    {
        memory[i] = -1;
    }

    return MaxChildRanges(memory, n1, begin(s1), end(s1), begin(s2), end(s2));
}

int main()
{
    const string s1 = "shinchan";
    const string s2 = "nohaaraa";

    cout << Go(s1, s2) << endl;
}