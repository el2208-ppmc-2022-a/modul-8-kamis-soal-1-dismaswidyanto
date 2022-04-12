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

int main()
{
	// Meminta masukkan
	printf("Masukkan nama file: ");
	scanf("%s", ...);
	printf("Masukkan nilai batas: ");
	scanf("%d", ...);
	
	// Membaca file dan mengisi matriks
	readFile(..., ...);

	// Mencetak jumlah klaster
	printf("Jumlah klaster: %d\n", ...);

	return 0;
}
