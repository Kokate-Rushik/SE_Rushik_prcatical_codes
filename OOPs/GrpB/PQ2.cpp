//Code by kokate Rushik

#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    float floatArray[] = {64.5f, 25.2f, 12.3f, 22.1f, 11.0f};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "\nUnsorted Integer Array: ";
    printArray(intArray, intSize);
    selectionSort(intArray, intSize);
    cout << "\nSorted Integer Array: ";
    printArray(intArray, intSize);

    cout << "\nUnsorted Float Array: ";
    printArray(floatArray, floatSize);
    selectionSort(floatArray, floatSize);
    cout << "\nSorted Float Array: ";
    printArray(floatArray, floatSize);
	cout<<endl;
    return 0;
}
