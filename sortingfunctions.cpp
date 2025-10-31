#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];       // 1️⃣ Опорный элемент (последний)
    int i = low - 1;           // 2️⃣ Граница элементов < pivot

    for (int j = low; j < high; j++) { // 3️⃣ Проходим от low до high-1
        if (a[j] < pivot) {            // если текущий элемент меньше опорного
            i++;                       // двигаем границу
            swap(a[i], a[j]);          // и ставим этот элемент "влево"
        }
    }

    swap(a[i + 1], a[high]);           // 4️⃣ Ставим pivot на своё место
    return i + 1;                      // 5️⃣ Возвращаем индекс pivot
}


void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);   // разделяем массив
        quickSort(a, low, p - 1);          // сортируем левую часть
        quickSort(a, p + 1, high);         // сортируем правую часть
    }
}