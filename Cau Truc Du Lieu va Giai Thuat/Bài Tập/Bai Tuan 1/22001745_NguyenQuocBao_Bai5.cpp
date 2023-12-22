/*
    Ho va ten SV: Nguyen Quoc Bao
    MSSV: 22001745
    Yeu cau bai: Cai dat cac giai thuat sap xep theo cac phuong phap:
    1. Chon truc tiep
    2. Chen truc tiep
    3. Doi cho truc tiep
    4. Noi bot
    5. Quicksort.
    Theo yêu c?u sau:
    - Du lieu phat sinh ngau nhien
    - In ra man hinh ket qua chay tung buoc cua tung giai thuat
    - Tinh so lan so sanh va so phep gan
    
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Khai bao nguyen mau ham
void phatSinhMang(int A[], int n);
void xuatMang(int A[], int n);
void swap(int &a, int &b);
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void interchangeSort(int A[], int n);
void bubbleSort(int A[], int n);
int phanTuChot(int A[], int left, int right);


//Dinh nghia ham
void phatSinhMang(int A[], int n) {
    for(int i = 0; i < n; i++) {
        A[i] = rand()%100;
    }
}

void xuatMang(int A[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ",A[i]);
    }
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void selectionSort(int A[], int n) {
	clock_t start,end;
	float t;
	start = clock();
    int min, soSanh = 0, gan = 0;
    for(int i = 0; i < n-1; i++) {
        min = i;
        gan++;
        for(int j = i+1; j < n; j++) {
            soSanh++;
            if(A[j] < A[min])
                min = j;
                gan++;
        }
        soSanh++;
        if(min != i) {
            swap(A[min], A[i]);
            gan+=3;
        }
    }
    end = clock();
    t = (end - start)/CLOCKS_PER_SEC;
    printf("\nMang sau sap xep theo SelectionSort: ");
    xuatMang(A, n);
    printf("\n");
    printf("\nSo lan so sanh: %d", soSanh);
    printf("\nSo phep gan: %d", gan);
    printf("\nThoi gian thuc hien giai thuat: %f", t);
}

void insertionSort(int A[], int n) {
	clock_t start,end;
	float t;
	start = clock();
    int pos, x, soSanh = 0, gan = 0;
    for(int i = 1; i < n; i++) {
    	printf("\n+i = %d\n", i);
        x = A[i];
        printf("\tGan x = A[%d]\n", i);
        gan++;
        pos = i-1;
        printf("\tpos = %d\n", pos);
        gan++;
        while(pos >= 0 && A[pos] > x) {
            soSanh++;
            printf("\n\tNeu pos = %d >= 0 && A[pos] = %d > %d thi:\n", pos, A[pos], x);
            A[pos+1] = A[pos];
            printf("\tA[%d] = A[%d]\n", pos+1, pos);
            pos--;
            gan++;
        }
        printf("\tSau khi kiem tra dieu kien ket thuc: A[%d] = %d\n", pos+1, x);
        A[pos+1] = x;
        gan++;
        printf("\tMang: ");
        xuatMang(A,n);
    }
    end = clock();
    t = end - start;
    printf("\n\nMang sau sap xep theo InsertionSort: ");
    xuatMang(A, n);
    printf("\nSo lan so sanh: %d", soSanh);
    printf("\nSo phep gan: %d", gan);
    printf("\nThoi gian thuc hien giai thuat: %f", t);
}

void interchangeSort(int A[], int n) {
	clock_t start,end;
	float t;
	start = clock();
    int soSanh = 0, gan = 0;
    for(int i = 0; i < n-1; i++) {
    	printf("\n+i = %d\n", i);
        for(int j = i+1; j < n; j++) {
            soSanh++;
            if(A[i] > A[j]) {
            	printf("\nA[%d] > A[%d] nen hoan doi vi tri A[%d] = %d voi A[%d] = %d\n", i,j, i, A[i], j, A[j]);
                swap(A[i], A[j]);
                gan+=3;;
                printf("Mang: ");
                xuatMang(A,n);
            }
        }
    }
    end = clock();
    t = end - start;
    printf("\nMang sau sap xep Interchange Sort: ");
    xuatMang(A, n);
    printf("\nSo lan so sanh: %d", soSanh);
    printf("\nSo phep gan: %d", gan);
    printf("\nThoi gian thuc hien giai thuat: %f", t);
}

void bubbleSort(int A[], int n) {
	clock_t start,end;
	float t;
	start = clock();
    int soSanh = 0, gan = 0;
    for(int i = 0; i < n-1; i++) {
    	printf("\n+i = %d\n", i);
        for(int j = n-1; j > i; j--) {
            soSanh++;
            if(A[j] < A[j-1]) {
            	printf("\n\t+j = %d\n", j);
                swap(A[j], A[j-1]);
                gan+=3;
                printf("\n\tMang: ");
                xuatMang(A,n);
            } else {
            	printf("\n\t+j = %d\n", j);
            	printf("\n\tMang: ");
            	xuatMang(A,n);
			}
        }
    }
    end = clock();
    t = end - start;
    printf("\nMang sau sap xep BubbleSort: ");
    xuatMang(A, n);
    printf("\nSo lan so sanh: %d", soSanh);
    printf("\nSo phep gan: %d\n", gan);
    printf("\nThoi gian thuc hien giai thuat: %f", t);
}
// Phuong phap dua tren phan hoach
int QuickSort(int A[], int left, int right,int &ss, int &gan)
{
	int i, j, x;
	ss++;
	if(left>=right)
		return -1;
	x = A[(left+right)/2];
	i = left; 
	j = right;
	gan +=3;
	do
	{
		while(A[i]<x)
			i++;
		while(A[j]>x)
			j--;
		ss++;
		if(i<=j){
			swap(A[i], A[j]);
			i++;
			j--;
			gan +=3;
		}
	}while(i<j);
	ss++;
	if(left<j)
		QuickSort(A,left,j,ss,gan);
	ss++;
	if(i<right)
		QuickSort(A,i,right,ss,gan);
}
int main() {
    int n, A[1000], chon;
    int left = 0;
    int right = n-1;
    int ss = 0;
    int gan = 0;
    do {
        printf("Nhap so luong phan tu: ");
        scanf("%d", &n);
    }while(n<0);
    phatSinhMang(A,n);
    printf("\nXuat Mang: ");
    xuatMang(A,n);
    printf("\n");
    printf("\n---------------MENU-----------------");
    printf("\n1. Selection Sort.");
    printf("\n2. Insertion Sort.");
    printf("\n3. Interchange Sort.");
    printf("\n4. Bubble Sort.");
    printf("\n5. Quick Sort");
    printf("\n6. Thoat.");
    printf("\nNhap vao lua chon: ");
    scanf("%d", &chon);
	
	switch(chon) {
		case 1: 
			selectionSort(A,n);
			break;
		case 2: 			
			insertionSort(A, n);
			break;
		case 3:
			interchangeSort(A, n);
			break;
		case 4: 
			bubbleSort(A, n);
			break;
		case 5: 
            QuickSort(A,left,right,ss,gan);
            printf("\nSo lan so sanh: %d\n", ss);
            printf("\nSo phep gan: %d", gan);
            xuatMang(A,n);
			break;
		case 6: 
			printf("\nThoat chuong trinh thanh cong.");
			break;
		default: 
			printf("\nChon khong hop le.");
			break;
	}
    return 0;
}
