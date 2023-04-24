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
#include <bits/stdc++.h>
#include <random>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

// ====================================================
//             Abstract Class for Sorters
// ====================================================
class Sorter
{
    public:
        virtual void Sort(int arr[], int size) = 0;
};

// ===================================================================
//             Selection Sorter Class inherited from Sorter
// ===================================================================
class SelectionSorter : public Sorter
{

    public:
    // ===================================
    //           Swap Function
    // ===================================
    void swap(int *ptr1, int *ptr2) 
    { 
        int temp = *ptr1; 
        *ptr1 = *ptr2; 
        *ptr2 = temp; 
    } 
    // ===========================================
    //           Selection Sort Function
    // ===========================================
    void Sort(int arr[], int size)
    {
        int tmp,tmp_i;

        for(int i=0,j; i < size-1;i++)
        {
            tmp_i=i;
            for(int j=i+1; j < size;j++)
            {
                if(arr[j]<arr[tmp_i])
                {
                    tmp_i=j;
                    // min = arr[j];
                }
            }
            tmp=arr[i];
            arr[i]=arr[tmp_i];
            arr[tmp_i]=tmp;
        }
    }
};
class QuickSorter : public Sorter
{

    public:
    // ===================================
    //           Swap Function
    // ===================================

    void swap(int *xp, int *yp) 
    { 
        int temp = *xp; 
        *xp = *yp; 
        *yp = temp; 
    } 
    // ======================================================================
    //           Partitioning Function for the quick sort algorithm
    // ======================================================================
    int partition(int arr[], int l, int r)
    {
        int i = l;
        int j = r;
        int pivotIndex = i;
        while(1)
        {
            while(arr[pivotIndex] <= arr [j] && pivotIndex != j)
            {
                j--;
            }
            if(pivotIndex == j)
                break;
            else if(arr[pivotIndex]>arr[j])
            {
                swap(&arr[j], &arr[pivotIndex]);
                pivotIndex =j;
            }
            while(arr[pivotIndex] >= arr[i] && pivotIndex != i)
                i++;
            if(pivotIndex == i)
                break;
            else if(arr[pivotIndex] < arr[i])
            {
                swap(&arr[i], &arr[pivotIndex]);
                pivotIndex =i;
                return pivotIndex;
            }
        }
        return i+1;
    }

    // ===========================================
    //           Main Quick Sort Function
    // ===========================================

    void quickSort(int arr[], int l, int r)
    {
        if(l < r)
        {
            int pivot = partition(arr,l,r);
            quickSort(arr, l, pivot-1);
            quickSort(arr, pivot+1, r);


        }
    }
    // ===========================================================
    //          Function to Trigger The Main Quick Sort Functiion
    // ============================================================

    void Sort(int arr[], int size)
    {
        quickSort(arr, 0, size-1);
    }
};

class Testbed
{
    
    public:
    // ===========================================================
    //          Function to Array with Random Data
    // ============================================================
    int* GenerateRandomList(int min, int max, int size)
    {
        int* arr = new int[size];
        for(int i =0; i < size; i++)
        {
            int range = max - min +1;
            // srand(time(0));
            int num = rand() % range + min;
            arr[i] = num;
        }
        return arr;
    }
    // ===========================================================
    //          Function to Array with Reversed Random Data
    // ============================================================
    int* GenerateRandomReverseOrderedList(int min, int max, int size)
    {
        int* arr = new int[size];
        // srand(time(0));
        for(int i =0; i < size; i++)
        {
            int range = max - min +1;
            // srand(time(0));
            int num = rand() % range + min;
            arr[i] = num;
        }
        int tmp,tmp_i;

        for(int i=0,j; i < size-1;i++)
        {
            tmp_i=i;
            for(int j=i+1; j < size;j++)
            {
                if(arr[j]>arr[tmp_i])
                {
                    tmp_i=j;
                    // min = arr[j];
                }
            }
            tmp=arr[i];
            arr[i]=arr[tmp_i];
            arr[tmp_i]=tmp;
        }
        return arr;
    }
    // ===========================================================
    //          Function to Calculate Algorithm Time
    // ============================================================
    int RunOnce(Sorter& alg, int arr[], int size)
    {
        auto start = high_resolution_clock::now();

        alg.Sort(arr, size);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        return duration.count();
 
    }
    // ================================================================================
    //          Function to Calculate Average Algorithm Time on Several Sets
    // ================================================================================
    double RunAndAverage(Sorter& alg, bool type, int min, int max, int size, int sets_num)
    {
        double avg = 0;
        int* randArr = new int [size];
        if(type)
        {
            for(int i =0 ; i < sets_num; i++)
            {
                randArr = GenerateRandomReverseOrderedList(min, max, size); 
                avg += RunOnce(alg, randArr, size);

            }

        }else
        {
            for(int i =0 ; i < sets_num; i++)
            { 
                randArr = GenerateRandomList(min, max, size); 
                avg += RunOnce(alg, randArr, size);
            }

        }
        return avg/sets_num;
    }
    // =====================================================================================================
    //          Function to Calculate Average Algorithm Time on Several Sets with Different Sizes
    // =====================================================================================================
    void RunExperiment(Sorter& alg, bool type, int min, int max, int min_val, int max_val, int sets_num, int step)
    {
        cout << "Set Size" << setw(25) << "Average Time" << endl;
        for(int i =0 ; i <= ((max_val-min_val)/step); i++)
        {
            int size = min_val + i*step;
            cout << size << setw(25) <<RunAndAverage(alg, type, min, max, size, sets_num) <<endl;
        }
    }
};

int main()
{
    QuickSorter quickSortme1;
    QuickSorter quickSortme2;
    SelectionSorter selectionSortme1;
    SelectionSorter selectionSortme2;
    Testbed test;

    cout << "Sorting Random Set Using quick sort algorithm. " << endl;
    test.RunExperiment(quickSortme1, 0, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "Sorting Random Set Using selection sort algorithm. " << endl;
    test.RunExperiment(selectionSortme1, 0, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "=====================================================" << endl;
    cout << "Sorting Reversed Set Using quick sort algorithm. " << endl;
    test.RunExperiment(quickSortme2, 1, 200, 1000000, 1000, 10000, 50, 1000);
    cout << "Sorting Reversed Set Using selection sort algorithm. " << endl;
    test.RunExperiment(selectionSortme2, 1, 200, 1000000, 1000, 10000, 50, 1000);
    return 0;
}