/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : -
*Hari dan Tanggal : Kamis, 14 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define MAT_SIZE 10

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/**
 * @brief fungsi untuk membaca file masukkan dan mengisi matriks
 *
 * @param filename nama file masukkan
 * @param mat matriks yang akan diisi
 */
void readFile(char *filename, int mat[MAT_SIZE][MAT_SIZE])
{
	char buffer[BUFFER_SIZE], *token;
	int i = 0, j = 0;
	FILE *f = fopen(filename, "r");

	while (fgets(buffer, BUFFER_SIZE, f))
	{
		j = 0;
		token = strtok(buffer, ",");
		while (token != NULL)
		{
			mat[i][j] = atoi(token);
			token = strtok(NULL, ",");
			j++;
		}
		i++;
	}
}

/**
 * @brief fungsi untuk mengunjungi semua titik pada sebuah kluster
 *
 * @param mat matriks yang digunakan
 * @param vis matriks yang menandakan titik yang telah dikunjungi
 * @param x koordinat x sekarang
 * @param y koordinat y sekarang
 * @param limit batas nilai klaster
 */
void dfs(int mat[MAT_SIZE][MAT_SIZE], int vis[MAT_SIZE][MAT_SIZE], int x, int y, int limit)
{
	vis[y][x] = 1;

	for (int i = 0; i < 8; i++)
	{
		int xNew = x + dx[i], yNew = y + dy[i];
		if (xNew > -1 && yNew > -1 && xNew < MAT_SIZE && yNew < MAT_SIZE)
		{
			if (vis[yNew][xNew] == 0 && mat[yNew][xNew] >= limit)
			{
				dfs(mat, vis, xNew, yNew, limit);
			}
		}
	}
}

int main()
{
	// Inisialisasi
	char filename[256];
	int clusterCount = 0;
	int limit;
	int mat[MAT_SIZE][MAT_SIZE];
	int vis[MAT_SIZE][MAT_SIZE];
	for (int i = 0; i < MAT_SIZE; i++)
		for (int j = 0; j < MAT_SIZE; j++)
			vis[i][j] = 0;

	// Meminta masukkan
	printf("Masukkan nama file: ");
	scanf("%s", filename);
	printf("Masukkan nilai batas: ");
	scanf("%d", &limit);

	// Membaca file dan mengisi matriks
	readFile(filename, mat);

	// Mengunjungi semua elemen dalam matriks untuk mencari klaster-klaster
	for (int y = 0; y < MAT_SIZE; y++)
	{
		for (int x = 0; x < MAT_SIZE; x++)
		{
			for (int i = 0; i < 8; i++)
			{
				int xNew = x + dx[i], yNew = y + dy[i];
				if (xNew > -1 && yNew > -1 && xNew < MAT_SIZE && yNew < MAT_SIZE)
				{
					// Kondisi ketika sebuah klaster ditemukan
					if (vis[yNew][xNew] == 0 && mat[yNew][xNew] >= limit)
					{
						// Inkremen jumlah klaster
						clusterCount++;

						// Menggunakan DFS untuk mengunjungi semua titik dalam klaster
						// dan menandakan bahwa titik-titik tersebut telah dikunjungi
						dfs(mat, vis, xNew, yNew, limit);
					}
				}
			}
		}
	}

	// Mencetak jumlah klaster
	printf("Jumlah klaster: %d\n", clusterCount);

	return 0;
}
