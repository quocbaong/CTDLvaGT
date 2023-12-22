#include<stdio.h>
#include<string.h>

struct THISINH {
    char soBaoDanh[10];
    char truongDuThi[30];
    char khoiThi[10];
    float diemMonMot;
    float diemMonHai;
    float diemMonBa;
    float diemCong;
    float tongDiem;
};
typedef THISINH TS;

//Nhap so luong thi sinh
void nhapN(int &n) {
    do {
        printf("Nhap so luong thi sinh: ");
        scanf("%d", &n);
    }while(n < 1);
}
//Check so
bool checkSBD(char A[]) {
    if(A[0] <= '0' || A[0] > '9')
        return false;
    for (int i = 1; i < strlen(A); i++) {
		if(A[i] < '0' || A[i] > '9')
			return false;
    }
    return true;
}
//Check khoi thi
bool checkKhoiThi(char A[]) {
    if((A[0] < 'A' || A[0] > 'Z') && (A[0] < 'a' || A[0] > 'z')) 
        return false;
    for(int i = 1; i < strlen(A); i++) {
        if(A[i] < '0' || A[i] > '9')
            return false;
    }
    return true;
}
//Nhap Thong Tin 1 thi sinh
void nhapThongTin(THISINH &x) {
    do {
        printf("\n\tNhap so bao danh: ");
        scanf("%s", &x.soBaoDanh);
    }while(strlen(x.soBaoDanh) != 8 || checkSBD(x.soBaoDanh) != true);

    do {
        printf("\tNhap truong du thi: ");
        fflush(stdin);
        gets(x.truongDuThi);
    }while(strlen(x.truongDuThi) > 30);

    do {
        printf("\tNhap khoi thi: ");
        fflush(stdin);
        gets(x.khoiThi);
    }while(strlen(x.khoiThi) != 3 || checkKhoiThi(x.khoiThi) != true);

    do {
        printf("\tNhap diem mon 1(0-10): ");
        scanf("%f", &x.diemMonMot);
    }while(x.diemMonMot < 0 || x.diemMonMot > 10);

    do {
        printf("\tNhap diem mon 2(0-10): ");
        scanf("%f", &x.diemMonHai);
    }while(x.diemMonHai < 0 || x.diemMonHai > 10);

    do {
        printf("\tNhap diem mon 3(0-10): ");
        scanf("%f", &x.diemMonBa);
    }while(x.diemMonBa < 0 || x.diemMonBa > 10);

    do {
        printf("\tNhap diem cong(0-10): ");
        scanf("%f", &x.diemCong);
    }while(x.diemCong < 0 || x.diemCong > 10);
}
//Xuat thong tin 1 thi sinh
void xuatThongTin(THISINH x) {
    printf("\n\t%-12s\t%-20s\t%-4s\t%13.2f\t%13.2f\t%13.2f\t%13.2f", x.soBaoDanh, x.truongDuThi, x.khoiThi,
                                    x.diemMonMot, x.diemMonHai, x.diemMonBa, x.diemCong);
}
//Nhap thong tin nhieu thi sinh
void nhapDanhSachThiSinh(THISINH ds[], int n) {
    printf("\nNhap thong tin cac thi sinh: ");
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin thi sinh %d: ", i+1);
        nhapThongTin(ds[i]);
    }
}
//Xuat thong tin nhieu thi sinh
void xuatDanhSachThiSinh(THISINH ds[], int n) {
    printf("\n\tSo Bao Danh\tDiem Du Thi\t\tKhoi Thi\tDiem Mon 1\t Diem Mon 2\tDiem Mon 3\tDiem Cong");
    for(int i = 0; i < n; i++) {
        xuatThongTin(ds[i]);
    }
}
//Ham tinh tong diem cac thi sinh
void tongDiemThiSinh(TS ds[], int n) {
    printf("\n\nTong diem cac thi sinh: ");
    for(int i = 0; i < n; i++) {
        ds[i].tongDiem = ds[i].diemMonMot + ds[i].diemMonHai + ds[i].diemMonBa+ ds[i].diemCong;
        printf("\nThi sinh %s: %.2f", ds[i].soBaoDanh, ds[i].tongDiem);
    }
}
void xuatDanhSachThiSinhMoi(THISINH ds[], int n) {
    printf("\n\tSo Bao Danh\tDiem Du Thi\t\tKhoi Thi\tDiem Mon 1\t Diem Mon 2\tDiem Mon 3\tDiem Cong\tTong Diem");
    for(int i = 0; i < n; i++) {
        xuatThongTin(ds[i]);
        printf("\t%15.2f", ds[i].tongDiem);
    }
}
//Sap xep danh sach thi sinh theo SBD
void sapXepTheoSBD(THISINH ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(stricmp(ds[i].soBaoDanh, ds[j].soBaoDanh) > 0) {
                TS temp;
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}
//Sap xep theo tong diem
void sapXepTheoDiem(TS ds[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(ds[i].tongDiem > ds[j].tongDiem) {
                TS temp;
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}
//Tim kiem thi sinh vowi thong tin cho truoc
void timThiSinh(TS ds[], int n) {
    char SBD[10];
    int count = 0;
    do {
    printf("\nNhap so bao danh can tim thong tin: ");
    fflush(stdin);
    gets(SBD);
    for(int i = 0; i < n; i++) {
        if(stricmp(ds[i].soBaoDanh, SBD) == 0) {
            printf("\n\tSo Bao Danh\tDiem Du Thi\t\tKhoi Thi\tDiem Mon 1\t Diem Mon 2\tDiem Mon 3\tDiem Cong\tTong Diem");
            xuatThongTin(ds[i]);
            printf("\t%13.2f", ds[i].tongDiem);
            count++;
            break;
        }
    }
    if(count == 0) 
        printf("\nThong tin cua So Bao Danh %s khong ton tai", SBD);
    if(stricmp(SBD,"0") != 0) 
        printf("\nMoi nhap so bao danh thi sinh can tim tiep theo. Neu khong thi nhap 0.");
    else
        return;
	}while(stricmp(SBD,"0") != 0);
}
//Ham in danh sach K thi sinh theo diem tu cao den thap
void inDanhSachKThiSinh(THISINH ds[], int n) {
    int k;
    do {
        printf("\nNhap so thi sinh can in danh sach: ");
        scanf("%d", &k);
    }while(k<0 || k > n);
    printf("\n\nDANH SACH K THI SINH CAN IN:");
    printf("\n\tSo Bao Danh\tDiem Du Thi\t\tKhoi Thi\tDiem Mon 1\t Diem Mon 2\tDiem Mon 3\tDiem Cong\tTong Diem");
    for (int i=n-1 ; i >= n - k; i--) {
    printf("\n\t%-12s\t%-20s\t%-4s\t%12.2f\t%13.2f\t%13.2f\t%13.2f\t%13.2f", ds[i].soBaoDanh, ds[i].truongDuThi, ds[i].khoiThi,
                                    ds[i].diemMonMot, ds[i].diemMonHai, ds[i].diemMonBa, ds[i].diemCong, ds[i].tongDiem);
    }
}
int main() {
    THISINH ds[1000];
    int n;
    nhapN(n);
    //Nhap thong tin cac thi sinh
    nhapDanhSachThiSinh(ds, n);
    //Xuat thong tin cac thi sinh
    printf("\n\nDANH SACH THI SINH: ");
    xuatDanhSachThiSinh(ds, n);
    tongDiemThiSinh(ds, n);
    //Sap xep theo SBD
    sapXepTheoSBD(ds, n);
    printf("\n\nDANH SACH THI SINH SAP XEP THEO SBD:");
    xuatDanhSachThiSinhMoi(ds, n);
    //Sap xep theo tong diem
    sapXepTheoDiem(ds,n);
    printf("\n\nDANH SACH THI SINH SAP XEP THEO DIEM:");
    xuatDanhSachThiSinhMoi(ds, n);
    //Tim thong tin thi sinh
    timThiSinh(ds, n);
    //Xuat danh sach k thi sinh
    inDanhSachKThiSinh(ds, n);
    return 0;
}