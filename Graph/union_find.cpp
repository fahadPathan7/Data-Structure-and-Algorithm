/* 
This data structure provides the following capabilities. We are given several elements, each of which is a separate set. 
A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is. 
The classical version also introduces a third operation, it can create a set from a new element. 
*/
// tutorial : https://cp-algorithms.com/data_structures/disjoint_set_union.html

#include <bits/stdc++.h>
using namespace std;

// The implementation is with size. and the implementation with rank is given below.
int parent[10000], size[10000];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
}

/* Here is the implementation of union by rank based on the depth of the trees (by rank):
// The rank of a node using rank union by size indicate how many nodes are in the subtree of that node.
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
} */