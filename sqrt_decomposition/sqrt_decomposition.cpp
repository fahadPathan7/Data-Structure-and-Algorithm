// Time complexity O(sqrt(n))
// Tutorial : http://www.shafaetsplanet.com/?p=3416
#include <bits/stdc++.h>
using namespace std;

int segment[10000];
int preprocess(int input[], int n) {
    int current_segment = -1;
    int segment_size = sqrt(n); // should take ceiling . (my opinion)

    for (int i = 0; i < n; i++) {
        if (i % segment_size == 0) {
            current_segment++;  //new segment
        }
        segment[current_segment] += input[i];
    }

    return segment_size;
}
int query(int input[], int segment_size, int l, int r) {
    int sum = 0;

    //loop the first segment
    //until we reach r or a starting index

    while (l < r && l % segment_size != 0) {
        sum += input[l];
        l++;
    }

    //Loop until we reach
    //segment that contains r
    while (l + segment_size <= r) {
        sum += segment[l / segment_size];
        l += segment_size;
    }

    //loop until r
    while (l <= r) {
        sum += input[l];
        l++;
    }

    return sum;
}
void update(int input[], int segment_size, int i, int val) {
    int segment_no = i / segment_size;

    segment[segment_no] -= input[i];
    segment[segment_no] += val;
    input[i] = val;
}
int main()
{
}