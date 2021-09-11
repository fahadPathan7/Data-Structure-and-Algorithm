#include <bits/stdc++.h>
using namespace std;

#define MAX 32000
int List[300];
int Listsize = 0;
vector<int> primes;

void sieve()
{
    bool isprime[MAX];
    for (int i = 0; i <= MAX; i++)
    {
        isprime[i] = true;
    }
    for (int i = 3; i * i <= MAX; i += 2)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= MAX; j += i + i)
            {
                isprime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAX; i += 2)
    {
        if (isprime[i])
            primes.push_back(i);
    }
}
void primefactorization(long long int n)
{
    for (int i = 0; primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                List[Listsize++] = primes[i];
            }
        }
    }
}
int main()
{
    sieve();
    long long int n;
    cin >> n;
    primefactorization(n);
    for (int i = 0; i < Listsize; i++)
    {
        cout << List[i] << " ";
    }
}
