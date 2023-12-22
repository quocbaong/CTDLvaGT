/*
	Ho va ten SV: Nguyen Quoc Bao
	MSSV: 22001745
	Yeu cau: Ap dung giai thuat cho bai toan tong quat: Neu day khong co thu tu thi tim tuyen tinh,
	nguoc lai ap dung phuong phap tim nhi phan
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Khai bao nguyen mau ham
void phatSinhMang(int A[], int n);
void xuatMang(int A[], int n);
int timTuyenTinh(int A[], int n, int x);
int timNhiPhan(int A[], int n, int x);
int timNhiPhan2(int A[], int n, int x);
bool kiemTraTang(int A[], int n);
bool kiemTraGiam(int A[], int n);

//Dinh nghia ham
void phatSinhMang(int A[], int n)
{
	srand((unsigned)(time(NULL)));
	for(int i = 0; i < n; i++) {
		A[i] = rand()%100;
	}
}

void xuatMang(int A[], int n)
{
	printf("\nMang: ");
	for(int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
}

int timTuyenTinh(int A[], int n, int x)
{
	int find = -1;
	for(int i = 0; i < n; i++) {
		if(A[i] == x) {
			find = i;
			break;
		}
	}
	return find;
}

int timNhiPhan(int A[], int n, int x) 
{
	int left = 0, right = n - 1, mid, find = -1;
	while(left<=right) {
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

int timNhiPhan2(int A[], int n, int x) 
{
	int left = 0, right = n - 1, mid, find = -1;
	while(left<=right) {
		mid = (left+right)/2;
		if(A[mid] == x) {
			find = mid;
			break;
		}else if(A[mid] > x)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return find;
}

bool kiemTraTang(int A[], int n)
{
	for(int i = 0; i < n; i++) {
		if(A[i] < A[i+1])
			return false;
	}
	return true;
}

bool kiemTraGiam(int A[], int n) {
	for(int i = 0; i < n; i++) {
		if(A[i] > A[i+1])
			return false;
	}
	return true;
}
int main() {
	int A[100], n, x, viTri;
	do{
		printf("Nhap so phan tu: ");
		scanf("%d", &n);
	}while(n<0);
	phatSinhMang(A,n);
	xuatMang(A,n);
	do {
		printf("\nNhap vao gia tri can tim: ");
		scanf("%d", &x);
	}while(x<0);
	if(kiemTraTang(A,n))
		viTri = timNhiPhan(A,n,x);
	else if(kiemTraGiam(A,n))
		viTri = timNhiPhan2(A,n,x);
	else
		viTri = timTuyenTinh(A,n,x);
	if(viTri != -1) 
		printf("\nVi tri cua %d trong mang: %d", x, viTri);
	else 
		printf("\nKhong tim thay vi tri cua %d", x);
	return 0;
}
