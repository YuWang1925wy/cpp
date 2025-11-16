#include <iostream>
using namespace std;

void printArr(int arr[], int n) {
    // printing array elements
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // syntax: data_type array_name [size]
    int arr[5] = {2, 4, 8, 12, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "arr[0] size: " << sizeof(arr[0]) << endl; // -> 4 bytes
    cout << "arr length: " << n << endl; // length指有几个elements, size指有多少bytes
    printArr(arr, n);

    // partial initialization: 没初始值的默认为0
    int arr2[6] = {2, 4, 8};
    n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "arr2 length: " << n << endl;
    printArr(arr2, n);

    // initialized to 0
    int arr3[3] = {0};
    n = sizeof(arr3) / sizeof(arr3[0]);
    cout << "arr3 length: " << n << endl;
    printArr(arr3, n);

    // size of array can be skipped if size==number of values
    int arr4[] = {2, 4, 6};
    cout << "arr4 length: " << sizeof(arr4)/sizeof(arr4[0]) << endl; // -> 3

    // following two outputs should be the same
    // arr是一个地址，arr[0]的地址
    cout << arr << endl;
    cout << &arr[0] << endl; // & value->address, * address->value

    // Define a pointer ptr to first element, access array elements by tweaking address
    int* ptr = arr;
    cout << ptr + 1 << endl; // 在地址里实际+4了
    cout << *(ptr + 1) << endl; // 输出了arr[1]

    // multidimensional array syntax: data_type array_name[size 1][size 2]...[size n];
    int arr5[2][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}};
    int arr6[2][4] = {0, 1, 2, 3, 4, 5, 6, 7}; // arr5 and arr6 are the same

    int arr7[2][2][3] = {
        {{0, 1, 2}, {3, 4, 5}},
        {{6, 7, 8}, {9, 10, 11}}
    };
    int arr8[2][2][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // arr7 and arr8 are the same

    return 0;
}