#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Khai bao nguyen mau cua ham
void PhatSinhMang(int a[], int n);
void xuatMang(int a[], int n);
int TimTuyenTinh(int a[], int n, int x);

//Dinh nghia ham
void PhatSinhMang(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		a[i] = rand()%10;
	}
}
void xuatMang(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d", a[i]);
	printf("\n");
	}
}
int TimTuyenTinh(int a[], int n, int x){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==x)
			return i;
	}
    return -1;
}

int main(){
	int a[100], n,x,vt;
	do{
		printf("\tNhap so phan tu cua mang: ");
		scanf("%d", &n);
	}while(n<=0 || n>100);
		PhatSinhMang(a,n);
		xuatMang(a,n);
		do{
		printf("Nhap gia tri can tim: ");
		scanf("%d", &x);
	}while(x<0);
	vt = TimTuyenTinh(a,n,x);
	if(vt>=0){
		printf("Gia tri %d xuat hien tai vi tri %d trong mang\n", x, vt);
	}else
		printf("Khong tim thay gia tri %d trong mang\n", x);
	return 0;
}