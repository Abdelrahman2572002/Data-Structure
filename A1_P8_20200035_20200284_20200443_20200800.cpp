// =============================================================
// Student: Ahmed Salman Fahmin
// StudentID: 20200035
// =============================================================
// Student: Abdelrahamn Ramdan AboElela
// StudentID: 20200284
// =============================================================
// Student: Mohamed Refaat Mohamed
// StudentID: 20200443
// =============================================================
// Student: Adel Tarek Mouneer
// StudentID: 20200800
// =============================================================


#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
int binarySearch(int a[], int element,
                 int low, int high)
{
    if (high <= low)
        return (element > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (element == a[mid])
        return mid + 1;

    if (element > a[mid])
        return binarySearch(a, element,
                            mid + 1, high);
    return binarySearch(a, element, low,
                        mid - 1);
}
void BinaryinsertionSort(int a[], int n)
{
    int selected;
    int curr;

    for (int i = 1; i < n; ++i)
    {
        int j = i - 1;
        selected = a[i];

        // find the location of the element to be inserted
        curr = binarySearch(a, selected, 0, j);

        // shift elements to unsorted space "to the right"
        while (j >= curr)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
// and the worst case for it is "O(n^2);"

void insertionSort(int a[], int n)
{
    int i, cur, j;
    for (i = 1; i < n; i++)
    {
        cur = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > cur)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = cur;
    }
}
// time compexity for best case is "O(n)"
// and the worst case for it is "O(n^2);"

int main()
{
    int n;
    cout << "Enter Data Size to Test: ";
    cin >> n;
    int a[n];


    auto Bgn = high_resolution_clock::now();                    // the time at the begining before we  call the fuction to sort
     BinaryinsertionSort(a, n);                                  // our fuction which we want to calc it's time
    auto Ending = high_resolution_clock::now();                 // the time at the end after we called the function
    auto TimeTaken = duration_cast<microseconds>(Ending - Bgn); // the time was taken in the run time
    cout << "in insertion sort : " << TimeTaken.count() << " microseconds" << endl;

// and for the insertion sort
// cin >> n;
    int b[n];

    auto Bgn2 = high_resolution_clock::now();                    // the time at the begining before we  call the fuction to sort
    insertionSort(b, n);                                  // our fuction which we want to calc it's time
    auto Ending2 = high_resolution_clock::now();                 // the time at the end after we called the function
    auto TimeTaken2 = duration_cast<microseconds>(Ending2 - Bgn2); // the time was taken in the run time
    cout << "in Binary insertion sort : " << TimeTaken2.count() << " microseconds" << endl;


}


