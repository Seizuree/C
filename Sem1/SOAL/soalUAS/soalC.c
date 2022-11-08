#include <stdio.h>

char kingdom[255][255];
int sum = 0;

void recursive(int x, int y, int a, int b)
{
	if(x >= a || y >= b || kingdom[x][y] == '#' || kingdom[x][y] == '\n' || kingdom[x][y] == '\0' || x < 0 || y < 0) 
    {
	    return;
	}
	
    else if(kingdom[x][y] == '.')
    {
	   sum++; // apabila bertemu '.', maka sum di increment
	}
	
    kingdom[x][y] = '#';
	recursive(x + 1, y, a, b); // bergerak ke atas
	recursive(x - 1, y, a, b); // bergerak ke bawah
	recursive(x, y + 1, a, b); // bergerak ke kanan
	recursive(x, y - 1, a, b); // bergerak ke kiri
}

int main()
{
	int m,n;
	int baris = 0;
	int kolom = 0;
	scanf("%d %d", &m, &n); getchar(); // scan untuk mendapatkan luas peta
	for(int i = 0; i < m; i++)
    {
		for(int j = 0; j < m; j++)
        {
			scanf("%c", &kingdom[i][j]); // scan isi kingdom
		}
		getchar();
	}
	char start1 = 'a';
	int res[n];
	for(int i = 0; i < n; i++)
    {
		res[i] = 0; // semua index di set 0 agar tidak terjadi garbage value
	}
	for(int x = 0; x < n; x++)
    {
		for(int i = 0; i < m; i++)
        {
			for(int j = 0; j < m; j++)
            {
				if(kingdom[i][j] == start1) // pengecekan dan apabila indexnya sesuai dengan start1 yaitu 'a' maka program akan lanjut
                {
					baris = i; // assign baris menjadi i
					kolom = j; // assign kolom menjadi j
				}
			}
		}
		
        recursive(baris, kolom, m, m); // menjalankan recursive
		res[x] = sum; 
		sum = 0; // agar aman dari garbage value
		start1 += 1; // agar lanjut ke karakter berikutnya
	}
	char start2 = 'a';
	for(int i = 0; i < n; i++)
    {
		printf("%c %d\n", start2, res[i]+1); // print hasil dari perhitungan jarak
		start2 += 1; // agar lanjut ke karakter berikutnya
	}
	return 0;
}