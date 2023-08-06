#include <iostream>
#include <vector>

// Membuat fungsi binary_search()
std::vector<int> binary_search(int arr[], int left, int right, int target) {
    std::vector<int> indices; // Menyimpan indeks ditemukan

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            indices.push_back(mid); // Menyimpan indeks yang ditemukan
            left = mid + 1; // Melanjutkan pencarian di sebelah kanan
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1; // Melanjutkan pencarian di sebelah kiri
        }
    }

    return indices;
}

// Membuat fungsi bubble_sort untuk melakukan sorting array
int bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main() {
    // Deklarasi array
    int arr[] = {19, 40, 10, 90, 2, 50, 60, 50, 1};

    // Menghitung jumlah elemen pada array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting array
    bubble_sort(arr, n);

    // Membuat input untuk test case
    int input;
    std::cout << "Input Angka: ";
    std::cin >> input;

    std::vector<int> results = binary_search(arr, 0, n - 1, input);

    if (!results.empty()) {
        std::cout << "Output: Angka " << input << " ada di indeks ke: ";
        for (int index : results) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Output: Angka " << input << " tidak ada dalam array" << std::endl;
    }

    return 0;
}
