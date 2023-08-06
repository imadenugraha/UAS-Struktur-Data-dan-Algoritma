#include <iostream>
#include <string>

// Menggunakan struct untuk membuat unit bernama Mahasiswa
struct Mahasiswa {
    std::string nama;
    std::string kota;
};

// Membuat fungsi bubble_selection_sort
void bubble_selection_sort(Mahasiswa arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Menggunakan algoritma Bubble Sort
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].nama > arr[j + 1].nama) {
                Mahasiswa temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // Jika tidak ada pertukaran, berarti array sudah terurut
        if (!swapped) {
            break;
        }

        // Menggunakan algoritma Selection Sort
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].kota < arr[min_index].kota) {
                min_index = j;
            }
        }

        Mahasiswa temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    // Deklarasi data Mahasiswa dengan array
    Mahasiswa arr[] = {
            {"Fahmi", "Jakarta"},
            {"Romi", "Solo"},
            {"Andri", "Jakarta"},
            {"Fadillah", "Banyuwangi"},
            {"Ruli", "Bandung"},
            {"Rudi", "Bali"},
            {"Dendi", "Purwokerto"},
            {"Zaki", "Madiun"}
    };

    // Menghitung jumlah elemen pada array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Menampilkan data mahasiswa sebelum diurutkan
    std::cout << "Data mahasiswa sebelum diurutkan:" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "|" << arr[i].nama << " | " << arr[i].kota << "|" << std::endl;
    }
    std::cout << "---------------" << std::endl;

    bubble_selection_sort(arr, n);

    // Menampilkan data mahasiswa setelah diurutkan
    std::cout << "\nMahasiswa setelah diurutkan:" << std::endl;
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "|" << arr[i].nama << " | " << arr[i].kota << "|" << std::endl;
    }
    std::cout << "---------------" << std::endl;

    return 0;
}