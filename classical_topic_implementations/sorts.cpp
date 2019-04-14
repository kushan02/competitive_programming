#include<iostream>
#include<assert.h>
#include<algorithm>
#include<cmath>

using namespace std;

// <HELPER FUNCTIONS>
void print_array(const string &sorting, int ar[], int n) {
    cout << sorting << ":\n";
    for (int i = 0; i < n; ++i)
        cout << ar[i] << " ";
    cout << endl;
}

bool stress_test(int orig[], int ar[], int n) {
    sort(orig, orig + n);
    for (int i = 0; i < n; ++i) {
        cout << "ar[" << i << "] = " << ar[i] << ", orig[" << i << "] = " << orig[i] << "\n";
        assert(ar[i] == orig[i]);
    }
    cout << "Stress test successful!\n";
}
// </HELPER FUNCTIONS>

// -------------------------------------------

// <BUBBLE SORT>
void bubble_sort(int ar[], int n) {

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (ar[j + 1] < ar[j]) {
                int tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
        }
    }
}
// </BUBBLE SORT>

// -------------------------------------------

// <SELECTION SORT>
void selection_sort(int ar[], int n) {

    for (int i = 0; i < n; ++i) {

        int min = ar[i];
        int min_index = i;

        for (int j = i + 1; j < n; ++j) {
            if (ar[j] < min) {
                min = ar[j];
                min_index = j;
            }
        }

        swap(ar[i], ar[min_index]);
    }
}
// </SELECTION SORT>

// -------------------------------------------

// <INSERTION SORT>
void insertion_sort(int ar[], int n) {

    for (int i = 1; i < n; ++i) {

        // insert it into its correct position
        for (int j = i; j > 0; --j) {
            if (ar[j] < ar[j - 1]) {
                swap(ar[j], ar[j - 1]);
            }
        }
    }
}
// </INSERTION SORT>

// -------------------------------------------

// <QUICKSORT>
int partition(int ar[], int beg, int end) {

    int pivot_index = rand() % (end - beg + 1) + beg;
    swap(ar[beg], ar[pivot_index]);

    int pivot = ar[beg];

    // Now we need all the elements less than equal to ar[pivot] to the left of it
    // all the elements greater than the pivot to the right of it

    int border = beg;

    for (int i = beg + 1; i <= end; ++i) {
        if (ar[i] <= pivot) {
            border++;
            swap(ar[border], ar[i]);
        }
    }

    // bring the pivot element to its correct place
    swap(ar[beg], ar[border]);

    return border;
}

void quick_sort(int ar[], int beg, int end) {
    if (beg >= end)
        return;
    // [beg, end] (end is inclusive)

    int pos = partition(ar, beg, end);

    quick_sort(ar, beg, pos - 1);
    quick_sort(ar, pos + 1, end);

}

void quick_sort(int ar[], int n) {
    quick_sort(ar, 0, n - 1);
}
// </QUICKSORT>

// -------------------------------------------

// <MERGESORT>
void merge(int ar[], int beg, int end) {

    int mid = (beg + end) / 2;
    // [0,mid] to [mid+1, end]

    int *tmp = new int[end - beg + 1];
    int index = 0;

    int pointer_1 = beg, pointer_2 = mid + 1;

    while (pointer_1 <= mid && pointer_2 <= end) {

        if (ar[pointer_1] < ar[pointer_2]) {
            tmp[index++] = ar[pointer_1++];
        } else {
            tmp[index++] = ar[pointer_2++];
        }
    }

    for (int i = pointer_1; i <= mid; ++i)
        tmp[index++] = ar[i];
    for (int i = pointer_2; i <= end; ++i)
        tmp[index++] = ar[i];

    // copy back tmp to ar
    for (int i = beg; i <= end; ++i) {
        ar[i] = tmp[i - beg];
    }

}

void merge_sort(int ar[], int beg, int end) {
    if (beg >= end)
        return;

    int mid = (beg + end) / 2;

    merge_sort(ar, beg, mid);
    merge_sort(ar, mid + 1, end);

    merge(ar, beg, end);
}

void merge_sort(int ar[], int n) {
    merge_sort(ar, 0, n - 1);
}
// </MERGESORT>

// -------------------------------------------

// <SHELLSORT>
void shell_sort(int ar[], int n) {

    // This is not the traditional shell sort algorithm

    for (int gap = n / 2; gap > 0; gap = gap / 2) {

        for (int i = 0; i + gap < n; ++i) {
            if (ar[i] > ar[i + gap])
                swap(ar[i], ar[i + gap]);
        }

    }

    insertion_sort(ar, n); // this run will be a lot quicker and will have almost O(n) complexity for avg case
}
// </SHELLSORT>

// -------------------------------------------

int main() {

    int ar[] = {
            5744, 6371, 8110, 1144, 7164, 9326, 495, 5006, 8432, 1967, 4893, 1994, 9608, 614, 7238, 2503, 2674, 2753,
            5413, 83, 9534, 3070, 4548, 8478, 7879, 5010, 3443, 851, 1076, 9182, 66, 2455, 5680, 7450, 4672, 1650, 3695,
            5938, 3701, 1633, 1442, 2863, 9000, 8730, 3494, 147, 2310, 8097, 2267, 938, 7553, 7043, 6684, 8178, 5647,
            6459, 2402, 6626, 6087, 5431, 6416, 6125, 6963, 485, 5970, 970, 6046, 4900, 5808, 290, 1862, 2573, 8837,
            7856, 7252, 6191, 2055, 6882, 2588, 2398, 7745, 3132, 861, 8127, 1598, 3779, 1575, 5732, 3232, 6334, 6354,
            4820, 6733, 2266, 8261, 4661, 690, 866, 5828, 9880
    };
    int orig[] = {
            5744, 6371, 8110, 1144, 7164, 9326, 495, 5006, 8432, 1967, 4893, 1994, 9608, 614, 7238, 2503, 2674, 2753,
            5413, 83, 9534, 3070, 4548, 8478, 7879, 5010, 3443, 851, 1076, 9182, 66, 2455, 5680, 7450, 4672, 1650, 3695,
            5938, 3701, 1633, 1442, 2863, 9000, 8730, 3494, 147, 2310, 8097, 2267, 938, 7553, 7043, 6684, 8178, 5647,
            6459, 2402, 6626, 6087, 5431, 6416, 6125, 6963, 485, 5970, 970, 6046, 4900, 5808, 290, 1862, 2573, 8837,
            7856, 7252, 6191, 2055, 6882, 2588, 2398, 7745, 3132, 861, 8127, 1598, 3779, 1575, 5732, 3232, 6334, 6354,
            4820, 6733, 2266, 8261, 4661, 690, 866, 5828, 9880
    };
    int n = 100;

    // bubble_sort(ar, n);
    // print_array("Bubble Sort", ar, n);

    // selection_sort(ar,n);
    // print_array("Selection Sort", ar, n);

    // insertion_sort(ar,n);
    // print_array("Insertion Sort", ar, n);

    // quick_sort(ar, n);
    // print_array("Quick Sort", ar, n);

    // merge_sort(ar, n);
    // print_array("Merge Sort", ar, n);

    shell_sort(ar, n);
    print_array("Shell Sort", ar, n);

    stress_test(orig, ar, n);

    return 0;
}