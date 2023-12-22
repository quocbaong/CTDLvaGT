/*
    Ho va ten SV: Nguyen Quoc Bao
    MSSV: 22001745
    Yeu cau bai: : Cho mang 1 chieu quan ly thong tin cac sinh vien cua 1 lop hoc (toi da 50 sinh vien).
    Moi sinh vien gom các thong tin: MSSV, ho và ten, gioi tinh, dia chi va diem trung binh. Viet
    chuong trinh thuc hien cac yeu cau sau:
    1. Nhap danh sach sinh vien.
    2. In ra danh sach sinh vien.
    3. Xaa 1 sinh viên voi ma so x cho truoc khoi danh sach.
    4. S?p x?p danh sách sinh viên theo th? t? tang d?n c?a di?m trung bình
    5. S?p x?p danh sách sinh viên theo th? t? tang d?n c?a h? và tên
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct SINHVIEN{
    char MSSV[10];
    char hoTen[30];
    int gioiTinh;
    char diaChi[50];
    float dtb;
};

typedef struct SINHVIEN SV;

//Khai bao nguyen mau ham
void nhapSoLuongSV(int &n);
void nhap1SV(SV &sv);
void nhapDSSV(SINHVIEN dssv[], int n);
void xuat1SV(SINHVIEN sv);
int timSV(SINHVIEN dssv[], int n, char maso[]);
void xoaSV(SINHVIEN dssv[], int &n, char maSo[]);
void hoanVi(SINHVIEN &a, SINHVIEN &b);
void sapTheoDTB(SINHVIEN dssv[], int n);
void sapTheoHoTen(SINHVIEN dssv[], int n);
//Dinh nghia ham
void nhapSoLuongSV(int &n) 
{
    do {
        printf("Nhap so luong sinh Vien(0<n<=50): ");
        scanf("%d", &n);
    }while(n<0 || n>50);
}
void nhap1SV(SV &sv) {
    do {
    printf("\n\tNhap MSSV: ");
    fflush(stdin);
    gets(sv.MSSV);
    }while(strlen(sv.MSSV) > 10);

    printf("\n\tNhap Ho va Ten Sinh Vien: ");
    fflush(stdin);
    gets(sv.hoTen);

    do {
    printf("\n\tNhap gioi tinh(1: nu, 0: nam): ");
    scanf("%d", &sv.gioiTinh);
    }while((sv.gioiTinh != 0) && (sv.gioiTinh != 1));

    printf("\n\tNhap dia chi: ");
    fflush(stdin);
    gets(sv.diaChi);

    do {
        printf("\n\tNhap diem TB: ");
        scanf("%f", &sv.dtb);
    }while((sv.dtb < 0) || (sv.dtb > 10));
} 
void nhapDSSV(SINHVIEN dssv[], int n) 
{
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d: ", i+1);
        nhap1SV(dssv[i]);
    }
}
void xuat1SV(SINHVIEN sv) 
{
    printf("\n%-10s%-25s%-3d%-30s%-8.2f", sv.MSSV, sv.hoTen, sv.gioiTinh, sv.diaChi, sv.dtb);
}
void xuatDSSV(SV dssv[], int n) {
	printf("\n%-10s%-25s%-3s%-30s%-8.2s", "MSSV", "Ho Va Ten", "Gt", "Dia Chi", "DTB");
    for(int i = 0; i < n; i++) {
        xuat1SV(dssv[i]);
    }
}
int timSV(SINHVIEN dssv[], int n, char maSo[]) 
{
    for(int i = 0; i , n; i++) {
		if(stricmp(dssv[i].MSSV, maSo) == 0)
			return i;
	}
	return -1;
}
void xoaSV(SINHVIEN dssv[], int &n, char maSo[])
{
    int viTri = timSV(dssv, n, maSo);
	if(viTri == -1) {
		printf("\nKhong co SV ma: %s", maSo);
		return;
	} else{
		for(int i = viTri; i<n-1; i++)
			dssv[i] = dssv[i+1];
	}
	n--;
}
void hoanVi(SINHVIEN &a, SINHVIEN &b) 
{
    SV temp;
    temp = a;
    a = b;
    b = temp;
}
void sapTheoDTB(SINHVIEN dssv[], int n)
{
    int min;
    for(int i = 0; i < n-1; i++) {
        min = i;
        for(int j = i+1; j < n; j++) {
            if(dssv[j].dtb < dssv[min].dtb)
                min = j;
        }
        if(min != i) {
            hoanVi(dssv[min], dssv[i]);
        }
    }
}
void sapTheoHoTen(SINHVIEN dssv[], int n)
{
    for(int i = 0; i < n-1; i++) {
        for(int j = i; j<n; j++) {
            if(stricmp(dssv[i].hoTen, dssv[j].hoTen) > 0)
                hoanVi(dssv[i], dssv[j]);
        }
    }
}
int main() {
    SINHVIEN SV[100];
    int n, chon;
    nhapSoLuongSV(n);
    while(true) {
    printf("\n\n---------------MENU-----------------");
    printf("\n1. Nhap danh sach sinh vien.");
    printf("\n2. Xuat thong tin danh sach sinh vien.");
    printf("\n3. Xoa sinh vien.");
    printf("\n4. Sap xep theo diem trung binh.");
    printf("\n5. Sap xep theo ho ten snh vien.");
    printf("\n6. Thoat.");
    do {
        printf("\nNhap lua chon: ");
        scanf("%d", &chon);
        switch(chon) {
            case 1:
                nhapDSSV(SV, n);
                break;
            case 2:
                printf("\nDANH SACH SINH VIEN:\n");
                xuatDSSV(SV,n);
                break;
            case 3: 
                char maSo[10];
                printf("\nNhap MSSV can xoa: ");
                fflush(stdin);
                gets(maSo);
                xoaSV(SV, n, maSo);
                printf("\nDANH SACH SAU KHI XOA SINH VIEN: \n");
                xuatDSSV(SV,n);
                break;
            case 4:
                sapTheoDTB(SV,n);
                printf("\nDANH SACH SAU KHI SAP XEP THEO DIEM TRUNG BINH: \n");
                xuatDSSV(SV,n);
                break;
            case 5:
                sapTheoHoTen(SV,n);
                printf("\nDANH SANH SAU KHI SAP XEP THEO TEN: \n");
                xuatDSSV(SV,n);
                break;
            case 6:
                printf("\nThoat thanh cong.");
                return 0;
                break;
            default:
                printf("\nLua chon khong hop le. Moi ban nhap lai.");
                break;
        }
    }while(chon<1 || chon > 6);
    };
    return 0;
}
