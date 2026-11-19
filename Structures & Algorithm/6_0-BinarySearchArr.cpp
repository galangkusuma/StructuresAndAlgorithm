#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
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
	cout << "=== Binary Search Tanpa Sorting ===\n";
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
	cout << "Masukkan " << jumlahData << " angka dalam urutan menaik: ";
	for (int indeks = 0; indeks < jumlahData; ++indeks)
	{
		cin >> data[indeks];
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