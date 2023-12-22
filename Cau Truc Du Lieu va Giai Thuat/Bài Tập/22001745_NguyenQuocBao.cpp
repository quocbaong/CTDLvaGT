#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Ham nhap n phan tu
void nhapN(int &n) {
    do {
    printf("Nhap so luong phan tu mang(n > 0): ");
    scanf("%d", &n);
    }while(n < 1);
}
//Ham nhap mang so nguyen
void nhapMangSoNguyen(int A[], int n) {
    for(int i = 0; i < n; i++) {
        printf("A[%d] = ", i); 
        scanf("%d", &A[i]);
    }
}
//Ham phat sinh n phan tu ngau nhien cho mang so nguyen
void mangNgauNhien(int A[], int n) {
    srand((unsigned)(time(NULL)));
    for(int i = 0; i < n; i++){
        A[i] = rand();
    }
}
//Ham phat sinh n phan tu ngau nhien tang dan cho mang so nguyen
void mangNgauNhienTangDan(int A[], int n) {
    int x;
    srand((unsigned)(time(NULL)));
    A[0] = rand();
    for(int i = 1; i < n; i++){
        while ((true))
        {
            x = rand();
            if(x > A[i-1]) {
                A[i] = x;
                break;
            }
        }
    }
}
//Ham xuat mang
void xuatMang(int A[], int n) {
    for(int i = 0; i < n; i++) {
        printf("A[%d] = %d\t", i, A[i]);
    }
}
int main() {
    int n, A[1000];
    nhapN(n);
    //Mang tu tao
    printf("Nhap cac phan tu cua mang tu tao: \n");
    nhapMangSoNguyen(A, n);
    printf("Xuat mang vua tao:\n");
    xuatMang(A, n);
    //Mang ngau nhien
    printf("\nMang ngau nhien vua tao:\n");
    mangNgauNhien(A, n);
    xuatMang(A, n);
    //Mang ngau nhien tang dan
    printf("\nMang ngau nhien tang dan vua tao:\n");
    mangNgauNhienTangDan(A, n);
    xuatMang(A, n);
    return 0;
}
