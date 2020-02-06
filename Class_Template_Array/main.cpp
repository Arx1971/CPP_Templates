#include <iostream>

using namespace std;

template<typename T>
class Array {
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);

    void print();

    void bubble_sort(T arr[], int s);
};

template<typename T>
Array<T>::Array(T *arr, int s) {
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void Array<T>::bubble_sort(T *arr, int s) {

    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int arr[] = {1, 5, 3, 4, 2, 4};

    int array_len = (sizeof(arr) / sizeof(arr[0]));

    Array<int> a(arr, array_len);

    a.print();
    a.bubble_sort(arr ,array_len);
    a.print();
    return 0;
}