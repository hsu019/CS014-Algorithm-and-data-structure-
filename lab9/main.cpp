#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

const int NUMBER_SIZE = 50000;

int Partition(int numbers[], int i, int k) {
    int l = i;
    int h = k;
    bool done = false;
    int midpoint = (i + k) / 2;
    int pivot = numbers[midpoint];
    while (done == false) {
        while(numbers[l] < pivot){
            ++l;
        }
        while(numbers[h] > pivot){
            --h;
        }
        if(l >= h){
            done = true;
        }
        else{
            int temp = numbers[h];
            numbers[h] = numbers[l];
            numbers[l] = temp;

            ++l;
            --h;
        }

    }
    return h;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
    if(i >= k){
        return;
    }

    int j = Partition(numbers, i, k);

    Quicksort_midpoint(numbers,i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

int findPivot(int numbers[], int i, int k){
    int leftmost = i;
    int midpoint = (i + k) / 2;
    int rightmost = k;
    int pivot1 = numbers[leftmost];
    int pivot2 = numbers[midpoint];
    int pivot3 = numbers[rightmost];
    int pivots[] = {pivot1, pivot2, pivot3};
    Quicksort_midpoint(pivots, 0, 2);

    return pivots[1];
}

int Partitionforthree(int numbers[], int i, int k) {
    int l = i;
    int h = k;
    bool done = false;
    int pivot = findPivot(numbers, i , k);

    while (done == true) {
        while(numbers[l] < pivot){
            ++l;
        }
        while(numbers[h] > pivot){
            --h;
        }
        if(l >= h){
            done = true;
        }
        else{
            int temp = numbers[h];
            numbers[h] = numbers[l];
            numbers[l] = temp;

            ++l;
            --h;
        }

    }
    return h;
}

void Quicksort_medianOfThree(int numbers[], int i, int k){
    if(i >= k){
        return;
    }

    int j = Partitionforthree(numbers, i, k);

    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

void InsertionSort(int numbers[], int numbersSize){
    int i = 0;
    int j = 0;
    for(i = 1; i < numbersSize; ++i){
        j = i;
        while(j > 0 && numbers[j] < numbers[j - 1] ){
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            --j;
        }
    }
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]) {
    for(int i = 0; i < NUMBER_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBER_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main() {

    int arr1[NUMBER_SIZE],arr2[NUMBER_SIZE],arr3[NUMBER_SIZE];

    fillArrays(arr1,arr2,arr3);

    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

    clock_t Start1 = clock();
    Quicksort_midpoint(arr1,0,NUMBER_SIZE-1);
    clock_t End1 = clock();
    int elapsedTime1 = (End1 - Start1)/CLOCKS_PER_MS;
    cout << "Time for Quicksort_midpoint:" << elapsedTime1 << endl;

    clock_t Start2 = clock();
    Quicksort_medianOfThree(arr2,0,NUMBER_SIZE);
    clock_t End2 = clock();
    int elapsedTime2 = (End2 - Start2)/CLOCKS_PER_MS;
    cout << "Time for Quicksort_medianOfThree:" << elapsedTime2 << endl;

    clock_t Start3 = clock();
    InsertionSort(arr3,NUMBER_SIZE);
    clock_t End3 = clock();
    int elapsedTime3 = (End3 - Start3)/CLOCKS_PER_MS;
    cout << "Time for InsertionSort:" << elapsedTime3 << endl;

   return 0;
}
