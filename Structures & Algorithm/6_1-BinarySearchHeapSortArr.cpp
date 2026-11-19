// Binary Search dengan Heap Sort

#include <iostream>
#include <utility>

using namespace std;

const int MAX_SIZE = 100;

void cetakData(const int data[], int jumlahData)
{
	for (int indeks = 0; indeks < jumlahData; ++indeks)
	{
		cout << data[indeks] << " ";
	}
	cout << "\n";
}

void heapify(int data[], int ukuranHeap, int akar)
{
	int terbesar = akar;
	int kiri = 2 * akar + 1;
	int kanan = 2 * akar + 2;

	if (kiri < ukuranHeap && data[kiri] > data[terbesar])
	{
		terbesar = kiri;
	}

	if (kanan < ukuranHeap && data[kanan] > data[terbesar])
	{
		terbesar = kanan;
	}

	if (terbesar != akar)
	{
		swap(data[akar], data[terbesar]);
		heapify(data, ukuranHeap, terbesar);
	}
}

void heapSort(int data[], int jumlahData)
{
	for (int indeks = jumlahData / 2 - 1; indeks >= 0; --indeks)
	{
		heapify(data, jumlahData, indeks);
	}

	for (int ukuranHeap = jumlahData - 1; ukuranHeap > 0; --ukuranHeap)
	{
		swap(data[0], data[ukuranHeap]);
		heapify(data, ukuranHeap, 0);
	}
}

int binarySearch(const int data[], int jumlahData, int target)
{
	int kiri = 0;
	int kanan = jumlahData - 1;

	while (kiri <= kanan)
	{
		int tengah = kiri + (kanan - kiri) / 2;

		if (data[tengah] == target)
		{
			return tengah;
		}

		if (data[tengah] < target)
		{
			kiri = tengah + 1;
		}
		else
		{
			kanan = tengah - 1;
		}
	}

	return -1;
}

int main()
{
	int jumlahData;

	cout << "=== Binary Search dengan Heap Sort ===\n";
	cout << "Masukkan jumlah data: ";
	cin >> jumlahData;

	if (jumlahData <= 0)
	{
		cout << "Jumlah data harus lebih dari 0.\n";
		return 1;
	}

	if (jumlahData > MAX_SIZE)
	{
		cout << "Jumlah data maksimal adalah " << MAX_SIZE << ".\n";
		return 1;
	}

	int data[MAX_SIZE];
	cout << "Masukkan " << jumlahData << " angka: ";
	for (int indeks = 0; indeks < jumlahData; ++indeks)
	{
		cin >> data[indeks];
	}

	cout << "Data sebelum diurutkan: ";
	cetakData(data, jumlahData);

	heapSort(data, jumlahData);

	cout << "Data setelah Heap Sort: ";
	cetakData(data, jumlahData);

	int target;
	cout << "Masukkan angka yang dicari: ";
	cin >> target;

	int posisi = binarySearch(data, jumlahData, target);
	if (posisi == -1)
	{
		cout << "Angka " << target << " tidak ditemukan.\n";
	}
	else
	{
		cout << "Angka " << target << " ditemukan pada indeks " << posisi
			 << " (posisi ke-" << posisi + 1 << ").\n";
	}

	return 0;
}
