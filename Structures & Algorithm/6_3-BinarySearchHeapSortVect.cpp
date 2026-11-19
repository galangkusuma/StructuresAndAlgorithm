// Binary Search dengan Heap Sort

#include <iostream>
#include <vector>

using namespace std;

void cetakData(const vector<int> &data)
{
	for (int nilai : data)
	{
		cout << nilai << " ";
	}
	cout << "\n";
}

void heapify(vector<int> &data, int ukuranHeap, int akar)
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

void heapSort(vector<int> &data)
{
	for (int indeks = static_cast<int>(data.size()) / 2 - 1; indeks >= 0; --indeks)
	{
		heapify(data, static_cast<int>(data.size()), indeks);
	}

	for (int ukuranHeap = static_cast<int>(data.size()) - 1; ukuranHeap > 0; --ukuranHeap)
	{
		swap(data[0], data[ukuranHeap]);
		heapify(data, ukuranHeap, 0);
	}
}

int binarySearch(const vector<int> &data, int target)
{
	int kiri = 0;
	int kanan = static_cast<int>(data.size()) - 1;

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

	vector<int> data(jumlahData);
	cout << "Masukkan " << jumlahData << " angka: ";
	for (int &nilai : data)
	{
		cin >> nilai;
	}

	cout << "Data sebelum diurutkan: ";
	cetakData(data);

	heapSort(data);

	cout << "Data setelah Heap Sort: ";
	cetakData(data);

	int target;
	cout << "Masukkan angka yang dicari: ";
	cin >> target;

	int posisi = binarySearch(data, target);
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
