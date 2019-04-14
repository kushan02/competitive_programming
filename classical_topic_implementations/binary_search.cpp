#include<iostream>
#include<algorithm>

using namespace std;

bool binary_search(int key, int ar[], int begin, int end) {

    if (begin > end)
        return false;

    int mid = (begin + end) / 2;

    if (ar[mid] == key)
        return true;
    else if (ar[mid] > key)
        return binary_search(key, ar, begin, mid-1);
    else
        return binary_search(key, ar, mid + 1, end);
}

bool binary_search(int key, int ar[], int n) {
    return binary_search(key, ar, 0, n-1);
}


int main() {

    int ar[] = {4, 7, 19, 32, 45, 188, 482, 499, 500, 999};

    sort(ar, ar + 10);

    cout << binary_search(45, ar, 10) << endl;
    cout << binary_search(35, ar, 10) << endl;
    cout << binary_search(445, ar, 10) << endl;
    cout << binary_search(499, ar, 10) << endl;


    return 0;
}