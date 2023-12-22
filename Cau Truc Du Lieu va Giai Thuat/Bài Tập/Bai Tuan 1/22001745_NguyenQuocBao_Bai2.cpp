/*
	Ho va ten SV: Nguyen Quoc Bao
	MSSV: 22001745
	Yeu cau bai: Viet chuong trinh cai dat giai thuat tim kiem nhi phan de xac dinh vi tri(neu co) va so lan so sanh
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Khai bao nguyen mau cua ham
void phatSinhMangTang(int A[], int n);
void xuatMang(int A[], int n);
int timNhiPhan(int A[], int n, int x, int &ss);

//Dinh nghia ham
void phatSinhMangTang(int A[], int n)
{
	srand((unsigned)(time(NULL)));
	A[0] = rand()%100;
	for(int i = 0; i < n; i++) {
		A[i] = A[i-1] + rand()%100;
	}
}

void xuatMang(int A[], int n)
{
	printf("\nMang: ");
	for(int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
}

int timNhiPhan(int A[], int n, int x, int &ss) 
{
	int left = 0, right = n - 1, mid, find = 0;
	while(left<=right) {
		ss++;
		mid = (left+right)/2;
		if(A[mid] == x) {
			find = mid;
			break;
		}else if(A[mid] < x)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return find;
}
int main() {
	int A[100], n, x, ss = 0;
	do {
		printf("Nhap so phan tu mang: ");
		scanf("%d", &n);
	}while(n < 0);
	phatSinhMangTang(A, n);
	xuatMang(A,n);
	do{
		printf("\nNhap gia tri can tim: ");
		scanf("%d", &x);
	}while(x < 0);
	int viTri = timNhiPhan(A,n,x,ss);
	if(viTri != 0) {
		printf("\nVi tri cua %d can tim: %d", x, viTri);
		printf("\nSo lan so sanh: %d", ss);
	}
	else {
		printf("\nKhong tim thay %d.", x);
		printf("\nSo lan so sanh: %d", ss);
	}
	return 0;
}

