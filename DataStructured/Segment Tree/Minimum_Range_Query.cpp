#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int start, int end, int index, int *arr, int *segmentTree) {

    //Base Case
    if (start == end) {
        segmentTree[index] = arr[start];
        return;
    }

    //Recursive Call
    int mid = (start + end) / 2;
    buildSegmentTree(start, mid, 2 * index, arr, segmentTree);
    buildSegmentTree(mid + 1, end, 2 * index + 1, arr, segmentTree);
    segmentTree[index] = min(segmentTree[2 * index], segmentTree[2 * index + 1]);

    return;

}

int query(int *segmentTree, int segS, int segE, int qryS, int qryE, int index) {

    // No overlap
    if (segE<qryS or segS>qryE)
        return INT_MAX;

    // Complete overlap
    if (segS >= qryS and segE <= qryE)
        return segmentTree[index];

    // Partial Overlap
    int mid = (segS + segE) / 2;
    int left = query(segmentTree, segS, mid, qryS, qryE, 2 * index);
    int right = query(segmentTree, mid + 1, segE, qryS, qryE, 2 * index + 1);
    return min(left, right);
}

void pointUpdate(int *segmentTree, int segS, int segE, int incr, int idx, int index) {

    // Out of bounds -> return
    if (idx<segS or idx>segE)
        return;

    // If the leaf node of that index
    if (segS == segE) {
        segmentTree[index] += incr;
        return;
    }

    //Otherwise
    int mid = (segS + segE) / 2;
    pointUpdate(segmentTree, segS, mid, incr, idx, 2 * index);
    pointUpdate(segmentTree, mid + 1, segE, incr, idx, 2 * index + 1);
    segmentTree[index] = min(segmentTree[2 * index], segmentTree[2 * index + 1]);

    return;

}

void rangeUpdate(int *segmentTree, int segS, int segE, int incr, int l, int r, int index) {

    // Out of bounds
    if (l > segE or r < segS)
        return;

    // leaf node update
    if (segS == segE) {
        segmentTree[index] += incr;
        return;
    }

    // Otherwise
    int mid = (segS + segE) / 2;
    rangeUpdate(segmentTree, segS, mid, incr, l, r, 2 * index);
    rangeUpdate(segmentTree, mid + 1, segE, incr, l, r, 2 * index + 1);
    segmentTree[index] = min(segmentTree[2 * index], segmentTree[2 * index + 1]);
    return;

}


int main()
{
    int n; cin >> n;
    int max_s = 4 * n + 2;
    int arr[n] ;
    int segmentTree[max_s] ;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    buildSegmentTree(0, n - 1, 1, arr, segmentTree);


    int q, l, r; cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << query(segmentTree, 0, n - 1, l, r, 1) << endl;
    }

    for (int i = 1; i <= 13; i++)
        if (segmentTree[i] < 20)
            cout << segmentTree[i] << " ";
        else cout << "* ";
    cout << endl;

    pointUpdate(segmentTree, 0, n - 1, 10, 3, 1);

    for (int i = 1; i <= 13; i++)
        if (segmentTree[i] < 20)
            cout << segmentTree[i] << " ";
        else cout << "* ";
    cout << endl;

    rangeUpdate(segmentTree, 0, n - 1, 10, 3, 5, 1);

    for (int i = 1; i <= 13; i++)
        if (segmentTree[i] < 20)
            cout << segmentTree[i] << " ";
        else cout << "* ";
    cout << endl;

    return 0;
}
