#include <iostream>
#include <vector>

using namespace std;

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

	cout << "=== Binary Search Tanpa Sorting ===\n";
	cout << "Masukkan jumlah data: ";
	cin >> jumlahData;

	if (jumlahData <= 0)
	{
		cout << "Jumlah data harus lebih dari 0.\n";
		return 1;
	}

	vector<int> data(jumlahData);
	cout << "Masukkan " << jumlahData << " angka dalam urutan menaik: ";
	for (int &nilai : data)
	{
		cin >> nilai;
	}

	for (int indeks = 1; indeks < jumlahData; ++indeks)
	{
		if (data[indeks] < data[indeks - 1])
		{
			cout << "Data harus sudah terurut dari kecil ke besar.\n";
			return 1;
		}
	}

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
