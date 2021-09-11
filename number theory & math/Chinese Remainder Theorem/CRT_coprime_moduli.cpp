// complexity: O(n×log(L)) , n is the size of the array and L is the product of all elements of mod array.
// Tutorial1: https://forthright48.com/chinese-remainder-theorem-part-1-coprime-moduli/
// Tutorial2: https://www.geeksforgeeks.org/chinese-remainder-theorem-set-1-introduction/

#include <bits/stdc++.h>
using namespace std;
/** Return {-1,-1} if invalid input.
    Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
int ext_gcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}
pair<int, int> chinese_remainder_theorem(vector<int> A, vector<int> M) {
    if (A.size() != M.size()) return { -1,-1 }; /** Invalid input*/

    int n = A.size();

    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/

    /** Merge the solution with remaining equations */
    for (int i = 1; i < n; i++) {
        int a2 = A[i];
        int m2 = M[i];

        /** Merge the two equations*/
        int p, q;
        ext_gcd(m1, m2, p, q);

        //! We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.
        int x = (a1 * m2 * q + a2 * m1 * p) % (m1 * m2);

        /** Merged equation*/
        a1 = x;
        m1 = m1 * m2;
    }
    if (a1 < 0) a1 += m1; /** Result is not suppose to be negative*/
    return { a1, m1 };
}

int main()
{
    vector<int> a, m;
    a = { 2,3,1 }; // remainders 
    m = { 3,4,5 }; // mod values

    pair<int, int> p = chinese_remainder_theorem(a, m);
    cout << p.first << " " << p.second << endl;
}