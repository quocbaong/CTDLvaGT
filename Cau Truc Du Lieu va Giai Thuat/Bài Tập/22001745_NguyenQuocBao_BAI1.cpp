#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ham nhap mang
void nhapMang(int A[], int &n) {
    do {
        printf("Nhap so phan tu mang: ");
        scanf("%d", &n);
    }while(n <= 0);
    printf("\nNhap cac phan tu mang:\n");
    for(int i = 0; i < n; i++) {
        printf("\nA[%d] = ", i);
        scanf("%d", &A[i]);
    }
}
//Ham xuat mang
void xuatMang(int A[], int n) {
    for(int i = 0; i < n; i++) {
        printf("A[%d] = %d\t", i, A[i]);
    }
}
//Ham tim vi tri cua gia tri x
void viTriTim(int A[], int n) {
    int k, count = 0;
    char viTri[100];
    viTri[0] = '\0';
    printf("\nNhap gia tri can tim: ");
    scanf("%d", &k);
    for(int i = 0; i < n; i++) {
        if(A[i] == k) {
            if(count > 0)
                strcat(viTri, ", ");
            char temp[10];  //Mang tam de chuyen so sang chuoi
            sprintf(temp, "%d", i);     //Chuyen so thanh ki tu(chuoi)
            strcat(viTri, temp);    //Them vi tri vao chuoi viTri
            count++;
        }
    }
    if (count == 0)
    {
        printf("\nGia tri can tim khong co trong mang.");
    }else{
        printf("\nVi tri cua gia tri %d: %s", k, viTri);
    }
}
void swap(int &a, int &b) {
    int temp = a;
    a = b; 
    b = temp;
}
//Ham sap xep mang co thu tu
void sapXepMangTang(int A[], int n) {
    printf("\nMang sap xep tang dan: ");
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if (A[i] > A[j])
                swap(A[i], A[j]);
        }
    }
}
//Ghi du lieu cua mang ra file
void ghiDuLieuRaFile(int A[], int n) {
    FILE *f;
    f = fopen("22001745_NguyenQuocBao_Bai1.txt", "w");
    if(f == NULL) {
        printf("\nLoi tao file.");
        exit(1);
    }
    fprintf(f,"Du lieu cua mang:\n");
    for(int i = 0; i < n; i++) {
        fprintf(f, "A[%d] = %d\t", i, A[i]);
    }
    fclose(f);
}
int main() {
    int n, A[1001];
    nhapMang(A, n);
    printf("\nMang vua tao:\n");
    xuatMang(A, n);
    viTriTim(A, n);
    sapXepMangTang(A, n);
    xuatMang(A, n);
    ghiDuLieuRaFile(A, n);
    return 0;
}