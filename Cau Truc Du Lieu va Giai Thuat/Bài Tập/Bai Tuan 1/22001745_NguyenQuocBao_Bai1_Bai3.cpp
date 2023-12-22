/*
	Ho va ten SV: Nguyen Quoc Bao
	MSSV: 22001745
	Yeu cau bai: Viet chuong trinh cai dat giai thuat tim kiem tuyen tinh de xac dinh vi tri(neu co) va so lan so sanh
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Khai bao nguyen mau cua ham
void phatSinhMang(int A[], int n);
void xuatMang(int A[], int n);
int timTuyenTinh(int A[], int n, int x, int &ss);
int timTuyenTinh_CaiTien(int A[], int n, int x, int &ss);

//Dinh nghia ham
void phatSinhMang(int A[], int n) 
{
	srand((unsigned)(time(NULL)));
	for(int i = 0; i < n; i++) {
		A[i] = rand()%1000;
	} 
}

void xuatMang(int A[], int n)
{
	printf("\nMang: ");
	for(int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
}

int timTuyenTinh(int A[], int n, int x, int &ss)
{
	int find = -1;
	for(int i = 0; i < n; i++) {
		ss++;
		if(A[i] == x) {
			find = i;
			break;
		}
	}
	return find;
}

int timTuyenTinh_CaiTien(int A[], int n, int x, int &ss)
{
	int i = 0; 
	A[n] = x;
	while(A[i] != x)
		ss++;
		i++;
	if(i < n)
		return i;
	return -1;
}

int main() {
	int A[100], n, x, ss = 0;
	do {
		printf("Nhap so phan tu: ");
		scanf("%d", &n);
	}while(n < 0);
	phatSinhMang(A, n);
	xuatMang(A, n);
	do {
		printf("\nNhap vao gia tri can tim: ");
		scanf("%d", &x);
	}while(x<0);
	int viTri = timTuyenTinh(A,n,x,ss);
	if(viTri != -1) {
		printf("\nVi tri cua %d can tim: %d", x, viTri);
		printf("\nSo lan so sanh: %d", ss);
	} else {
		printf("\nKhong tim thay vi tri cua %d", x);
		printf("\nSo lan so sanh: %d", ss);
	}
	return 0;
}
