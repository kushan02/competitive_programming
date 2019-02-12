#include <iostream>
#include <vector>

using namespace std;

long long get_inversion_count(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    size_t ave = left + (right - left) / 2;
    // a[left...ave)
    // b[ave... right)]

    // Count the pairs from the sorted halves
    // merge the arrays into b
    // copy the merged array back to a to make it sorted

    long long count = 0;

    size_t left_index = left;
    size_t right_index = ave;

    size_t b_index = left;

    // <counting logic>
    while (left_index < ave && right_index < right) {
        if (a[left_index] > a[right_index]) {
            count += (ave - left_index);
            ++right_index;
        } else {
            left_index++;
        }
    }
    // </counting logic>

    left_index = left;
    right_index = ave;

    while (left_index < ave && right_index < right) {
        if (a[right_index] < a[left_index]) {
            b[b_index] = a[right_index];
            ++right_index;
        } else {
            b[b_index] = a[left_index];
            ++left_index;
        }
        ++b_index;
    }


    for (int i = left_index; i < ave; ++i) {
        b[b_index] = a[i];
        ++b_index;
    }
    for (int i = right_index; i < right; ++i) {
        b[b_index] = a[i];
        ++b_index;
    }

    for (int i = left; i < right; ++i)
        a[i] = b[i];


    return count;

}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {

    long long number_of_inversions = 0;

    if (right <= left + 1) return number_of_inversions;

    size_t ave = left + (right - left) / 2;

    number_of_inversions += get_number_of_inversions(a, b, left, ave);
    number_of_inversions += get_number_of_inversions(a, b, ave, right);

    number_of_inversions += get_inversion_count(a, b, left, right);

    return number_of_inversions;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    vector<int> b(a.size());


    /*
     * Logic:
     * We modify the merge sort procedure in the following way
     * Merge(B,C) returns the resulting sorted array & the number of pairs (b,c)
     * such that bCB and cCC & b>c
     * MergeSort(A) returns a sorted array & the number of inversions in A
     *
     * Pseudo code:
     * =>Merge(B,C):
     *  left_index = B.begin()
     *  right_index = C.begin()
     *
     *  count = 0
     *
     *  while left_index < B.end() AND right_index < C.end():
     *      if B[left_index] > C[right_index]:
     *          count = count + (B.end() - left_index)
     *          right_index++
     *      else:
     *          left_index++
     *
     *  return count
     *
     *=>MergeSort(A):
     *  (B,x) = MergeSort(A[1...mid])
     *  (C,y) = MergeSort(A[mid+1...n])
     *
     *  z = Merge(B,C)
     *
     *  return x + y + z
     *  {x, y, z are counts of inversions}
     *
     * */

    std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
