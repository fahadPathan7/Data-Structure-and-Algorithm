/* modular multiplicative inverse is possible if and only if a and m are coprime.
a.x=1 (mod m). here x is the modular inverse of a under mod m. */
// tutorial : https://cp-algorithms.com/algebra/module-inverse.html
#include <iostream>
using namespace std;

// A naive method to find modular 
// multiplicative inverse of 'a' 
// under modulo 'm'
int modInverse(int a, int m)
{
	for (int x = 1; x < m; x++)
		if (((a%m) * (x%m)) % m == 1)
			return x;
    
    return 0;
}

// Driver code
int main()
{
	int a = 3, m = 11;

	// Function call
	cout << modInverse(a, m);
    // If output is zero , then their is no mmi.
	return 0;
}
/* another implementation:
inv[1] = 1;
for(int i = 2; i < m; ++i)
    inv[i] = m - (m/i) * inv[m%i] % m; */

// Or the X in the extended euclidean algorithm is the mmi of a.