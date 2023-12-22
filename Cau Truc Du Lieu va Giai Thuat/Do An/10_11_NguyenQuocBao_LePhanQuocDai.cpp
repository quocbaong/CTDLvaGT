#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct SinhVien{
    char maSoSV[9];
    char tenSinhVien[30];
    char lopHocPhan[15];
};
typedef struct SinhVien SV;

struct BangDiem {
    char tenMonHoc[30];
    char maSSV[9];
    double diemThuongKy;
    double diemGiuaKy;
    double diemCuoiKy;
    double diemThucHanh;
};
typedef struct BangDiem BD;

struct NodeSinhVien {
    SinhVien data;
    NodeSinhVien *pNext;
};
typedef struct NodeSinhVien NodeSinhVien;

struct NodeBangDiem {
    BangDiem data;
    NodeBangDiem *pNext;
};
typedef struct NodeBangDiem NodeBangDiem;

struct ListSinhVien {
    NodeSinhVien* pHead;
    NodeSinhVien* pTail;
};
typedef struct ListSinhVien ListSinhVien;

struct ListBangDiem {
    NodeBangDiem* pHead;
    NodeBangDiem* pTail;
};
typedef struct ListBangDiem ListBangDiem;

//Khai bao nguyen mau ham
void InitListSV(ListSinhVien &ListSV);
void InitListBD(ListBangDiem &ListBD);
void nhapThongTinSV(SinhVien &x);
void nhapDiem(float diem);
void nhapBangDiem(BangDiem &x);
void themSV(ListSinhVien &L, SinhVien x);
void themBangDiem(ListBangDiem &L, SinhVien x);
void xuatThongTinSV(SinhVien sv);
void xuatThongTinListSV(ListSinhVien ListSV);
void xuatBangDiem(BangDiem bd);
void xuatDanhSachBD(ListBangDiem ListBD);
int readDataFromFile(int &numStudent, int &numScore, ListSinhVien &listSV, ListBangDiem &listBD, char fileName[]);
NodeSinhVien* timSinhVienTheoMSSV(ListSinhVien listSV, char maSVTim[]);
NodeSinhVien* timSinhVienTheoTen(ListSinhVien listSV, char tenSV[]);
void ouputThongTinSV(ListSinhVien listSV, ListBangDiem listBD, NodeSinhVien* pSV);
void xuatToanBoThongTin(ListSinhVien listSV, ListBangDiem listBD);
void xoaSinhVienTheoMSSV(ListSinhVien &listSV, ListBangDiem &listBD, char maSSVDel[]);
void xuatFile(ListSinhVien listSV, ListBangDiem listBD, char fileName[]);
void xuatFileSVTheoLop(ListSinhVien listSV, ListBangDiem listBD, char fileName[], char className[]);
float diemTrungBinhTungSV(ListBangDiem listBD, NodeSinhVien* pSV);
void sapXepTheoDiemTrungBinh(ListSinhVien &listSV, ListBangDiem listBD);
void capNhatThongTinSV(ListSinhVien &listSV, char maSVUpdate[]);
void capNhatBangDiem(ListBangDiem &listBD, char maSVUpdate[]);
void capNhatThongTinSVVaBangDiem(ListSinhVien &listSV, ListBangDiem &listBD, char maSVUpdate[]);
void hienThiDanhSachSVTheoLop(ListSinhVien listSV, char className[]);
void hienThiDanhSachSVGioiTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[]);
void hienThiDanhSachSVXuatSacTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[]);
void hienThiDanhSachSVKhaTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[]);
void hienThiDanhSachSVTrungBinhTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[]);
void topNamSVCoDiemCaoNhat(ListSinhVien listSV, ListBangDiem listBD);
void xoaManHinh();
void biaDoAn();
void Menu(ListSinhVien &listSV, ListBangDiem &listBD);

//DINH NGHIA HAM

//Nhap thong tin SV
void nhapThongTinSV(SinhVien &x)
{
    printf("\nNhap Thong Tin Sinh Vien:");
	do {
    printf("\n\t>Nhap Ma So Sinh Vien(8 so): ");
    fflush(stdin);
    gets(x.maSoSV);
    }while(strlen(x.maSoSV) != 8);
    printf("\t>Nhap Ho Ten: ");
    fflush(stdin);
    gets(x.tenSinhVien);
    printf("\t>Nhap Lop Hoc Phan: ");
    fflush(stdin);
    gets(x.lopHocPhan);
}
void nhapDiem(double &diem)
{
    do {
        scanf("%lf", &diem);
        if(diem < 0 || diem > 10)
            printf("\t>>Diem khong hop le. Vui long nhap lai!\n");
    }while (diem < 0 || diem > 10);
}

//Nhap bang diem
void nhapBangDiem(BangDiem &x)
{
    int chonTH;
    printf("\nNhap noi dung bang diem: ");
    printf("\n\t>Nhap ten mon hoc: ");
    fflush(stdin);
    gets(x.tenMonHoc);
    do {
    printf("\t>Nhap Ma So Sinh Vien(8 so): ");
    fflush(stdin);
    gets(x.maSSV);
    }while(strlen(x.maSSV) != 8);
    printf("\t>Nhap diem thuong ky: ");
    nhapDiem(x.diemThuongKy);
    printf("\t>Nhap diem giua ky: ");
    nhapDiem(x.diemGiuaKy);
    printf("\t>Nhap diem cuoi ky: ");
    nhapDiem(x.diemCuoiKy);
    printf("\t>Mon co diem thuc hanh? (1. Co, 0. Khong): ");
    scanf("%d",&chonTH);
    if(chonTH == 1)
    {
        printf("\t>Nhap diem thuc hanh: ");
        nhapDiem(x.diemThucHanh);
    }else 
        x.diemThucHanh = 0;
}
//Khoi tao List
void InitListSV(ListSinhVien &ListSV)
{
    ListSV.pHead = ListSV.pTail = NULL;
}

void InitListBD(ListBangDiem &ListBD)
{
    ListBD.pHead = ListBD.pTail = NULL;
}

//Them SV vao List
void themSV(ListSinhVien &L, SinhVien x)
{
    NodeSinhVien *p = new NodeSinhVien;
    if(p == NULL) {
        printf("\n\tThem sinh vien that bai.");
        return;
    }
    p->data = x;
    p->pNext = NULL;
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else{
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

//Them bang diem vao List
void themBangDiem(ListBangDiem &L, BangDiem x)
{
    NodeBangDiem *p = new NodeBangDiem;
    if(p == NULL)
    {
        printf("\n\tThem bang diem that bai.\n");
        return;
    }
    p->data = x;
    p->pNext = NULL;
    if(L.pHead == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else{
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

//Xuat thong tin sinh vien
void xuatThongTinSV(SinhVien sv)
{
	printf("\n\t>Ma so sinh vien: %s", sv.maSoSV);
    printf("\n\t>Ho va ten sinh vien: %s", sv.tenSinhVien);
    printf("\n\t>Lop hoc phan: %s\n", sv.lopHocPhan);
}
//Xuat danh sach SV
void xuatThongTinListSV(ListSinhVien ListSV) {
    NodeSinhVien* p = ListSV.pHead;
    while (p != NULL) {
        xuatThongTinSV(p->data);
        p = p->pNext;
    }
    printf("\n");
}
//Xuat bang diem
void xuatBangDiem(BangDiem bd)
{
    printf("\n\t>Ma so sinh vien: %s", bd.maSSV);
    printf("\n\t>Ten mon hoc: %s", bd.tenMonHoc);
    printf("\n\t>Diem thuong ky: %.2f", bd.diemThuongKy);
    printf("\n\t>Diem giua ky: %.2f", bd.diemGiuaKy);
    printf("\n\t>Diem cuoi ky: %.2f", bd.diemCuoiKy);
    if (bd.diemThucHanh != 0) 
        printf("\n\t>Diem thuc hanh: %.2f\n", bd.diemThucHanh);

    float diemTrungBinh;
    if(bd.diemThucHanh != 0) {
        diemTrungBinh = (((bd.diemThuongKy + bd.diemThucHanh)/2)*0.2 + bd.diemGiuaKy*0.3 
                + bd.diemCuoiKy*0.5);
        printf("\t>Diem trung binh: %.2f", diemTrungBinh);
    }else {
        diemTrungBinh = (bd.diemThuongKy*0.2 + bd.diemGiuaKy*0.3 + bd.diemCuoiKy*0.5);
        printf("\t>Diem trung binh: %.2f", diemTrungBinh);
    }
    if(diemTrungBinh >=9 && diemTrungBinh <=10)
        printf("\n\t>Thang diem: A+");
    else if(diemTrungBinh >= 8.5 && diemTrungBinh <9)
        printf("\n\t>Thang diem: A");
    else if(diemTrungBinh >= 8 && diemTrungBinh < 8.5)
        printf("\n\t>Thang diem: B+");
    else if (diemTrungBinh >= 7 && diemTrungBinh < 8)
        printf("\n\t>Thang diem: B");
    else if (diemTrungBinh >= 6.5 && diemTrungBinh < 7) {
        printf("\n\t>Thang diem: C+");
    } else if (diemTrungBinh >= 5.5 && diemTrungBinh < 6.5) {
        printf("\n\t>Thang diem: C");
    } else if (diemTrungBinh >= 5 && diemTrungBinh < 5.5) {
        printf("\n\t>Thang diem: D+");
    } else if (diemTrungBinh >= 4 && diemTrungBinh < 5) {
        printf("\n\t>Thang diem: D");
    } else {
        printf("\n\t>Thang diem: F");
    }
}
//Xuat danh sach BD
void xuatDanhSachBD(ListBangDiem ListBD)
{
    NodeBangDiem *p = ListBD.pHead;
    while(p != NULL)
    {
        xuatBangDiem(p->data);
        p = p->pNext;
    }
    printf("\n");
}
//Doc file du lieu
int readDataFromFile(int &numStudent, int &numScore, ListSinhVien &listSV, ListBangDiem &listBD, char fileName[]) {
    FILE *f = fopen(fileName, "r");
    if (f == NULL) {
        return 0;
    }
    // Ðoc du lieu SinhVien
    SinhVien svNew;
    while (fscanf(f, "sv %10[^,], %29[^,], %14[^\n]\n", svNew.maSoSV, svNew.tenSinhVien, svNew.lopHocPhan) == 3) {
        numStudent++;
        themSV(listSV, svNew);
    }
    
    fseek(f, 0, SEEK_SET); 
    
    BangDiem bdNew;
    char buffer[1000];
    // Ðoc du lieu BangDiem
    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        if (sscanf(buffer, "diem %10[^,], %49[^,], %lf, %lf, %lf, %lf", bdNew.maSSV, bdNew.tenMonHoc,
        &bdNew.diemThuongKy, &bdNew.diemGiuaKy, &bdNew.diemCuoiKy, &bdNew.diemThucHanh) == 6) {
            numScore++;
            themBangDiem(listBD, bdNew);
        }
    }
    
    fclose(f);
    return 1;
}
//Tim kiem sinh vien theo mssv
NodeSinhVien* timSinhVienTheoMSSV(ListSinhVien listSV, char maSVTim[])
{
    NodeSinhVien *p = listSV.pHead;
    while(p != NULL)
    {
        if(strcmp(p->data.maSoSV, maSVTim) == 0)
            return p;
        p= p->pNext;
    }
    return NULL;
}
//Tim kiem sinh vien theo ten
NodeSinhVien* timSinhVienTheoTen(ListSinhVien listSV, char tenSV[])
{
    NodeSinhVien *p = listSV.pHead;
    while(p != NULL)
    {
        if(strcmp(p->data.tenSinhVien, tenSV) == 0)
            return p;
        p = p->pNext;
    }
    return NULL;
}
//Xuat Thong Tin 
void ouputThongTinSV(ListSinhVien listSV, ListBangDiem listBD, NodeSinhVien* pSV)
{
    NodeSinhVien* p = listSV.pHead;
    NodeBangDiem* pBD = listBD.pHead;
    while (p != NULL)
    {
        if(strcmp(p->data.maSoSV, pSV->data.maSoSV) == 0)
        {
            xuatThongTinSV(p->data);
            
            while(pBD != NULL)
            {
                if(strcmp(pBD->data.maSSV, pSV->data.maSoSV) == 0)
                {
                    printf("\n\t>Ten mon hoc: %s", pBD->data.tenMonHoc);
                    printf("\n\t>Diem thuong ky: %.2f", pBD->data.diemThuongKy);
                    printf("\n\t>Diem giua ky: %.2f", pBD->data.diemGiuaKy);
                    printf("\n\t>Diem cuoi ky: %.2f", pBD->data.diemCuoiKy);
                    if (pBD->data.diemThucHanh != 0) 
                    printf("\n\t>Diem thuc hanh: %.2f", pBD->data.diemThucHanh);
                    float diemTrungBinh;
                    if(pBD->data.diemThucHanh != 0) {
                        diemTrungBinh = (((pBD->data.diemThuongKy + pBD->data.diemThucHanh)/2)*0.2 + pBD->data.diemGiuaKy*0.3 
                                + pBD->data.diemCuoiKy*0.5);
                        printf("\n\t>Diem trung binh: %.2f", diemTrungBinh);
                    }else {
                        diemTrungBinh = (pBD->data.diemThuongKy*0.2 + pBD->data.diemGiuaKy*0.3 + pBD->data.diemCuoiKy*0.5);
                        printf("\n\t>Diem trung binh: %.2f", diemTrungBinh);
                    }
                    if(diemTrungBinh >=9 && diemTrungBinh <=10)
                        printf("\n\t>Thang diem: A+\n");
                    else if(diemTrungBinh >= 8.5 && diemTrungBinh <9)
                        printf("\n\t>Thang diem: A\n");
                    else if(diemTrungBinh >= 8 && diemTrungBinh < 8.5)
                        printf("\n\t>Thang diem: B+\n");
                    else if (diemTrungBinh >= 7 && diemTrungBinh < 8)
                        printf("\n\t>Thang diem: B\n");
                    else if (diemTrungBinh >= 6.5 && diemTrungBinh < 7) {
                        printf("\n\t>Thang diem: C+\n");
                    } else if (diemTrungBinh >= 5.5 && diemTrungBinh < 6.5) {
                        printf("\n\t>Thang diem: C\n");
                    } else if (diemTrungBinh >= 5 && diemTrungBinh < 5.5) {
                        printf("\n\t>Thang diem: D+\n");
                    } else if (diemTrungBinh >= 4 && diemTrungBinh < 5) {
                        printf("\n\t>Thang diem: D\n");
                    } else {
                        printf("\n\t>Thang diem: F\n");
                    }
                }
                pBD = pBD->pNext;
            }
            break;
        }
        p = p->pNext;
    }
}
//Xuat toan bo thong tin
void xuatToanBoThongTin(ListSinhVien listSV, ListBangDiem listBD)
{
    NodeSinhVien* p = listSV.pHead;
    while (p != NULL)
    {
        xuatThongTinSV(p->data);
        
        NodeBangDiem* pBD = listBD.pHead;
        while(pBD != NULL)
        {
            if(strcmp(pBD->data.maSSV, p->data.maSoSV) == 0)
            {
                printf("\n\t>Ten mon hoc: %s", pBD->data.tenMonHoc);
                printf("\n\t>Diem thuong ky: %.2f", pBD->data.diemThuongKy);
                printf("\n\t>Diem giua ky: %.2f", pBD->data.diemGiuaKy);
                printf("\n\t>Diem cuoi ky: %.2f", pBD->data.diemCuoiKy);
                if (pBD->data.diemThucHanh != 0) 
                    printf("\n\t>Diem thuc hanh: %.2f", pBD->data.diemThucHanh);
                float diemTrungBinh;
                if(pBD->data.diemThucHanh != 0) {
                    diemTrungBinh = (((pBD->data.diemThuongKy + pBD->data.diemThucHanh)/2)*0.2 + pBD->data.diemGiuaKy*0.3 
                                + pBD->data.diemCuoiKy*0.5);
                    printf("\n\t>Diem trung binh: %.2f", diemTrungBinh);
                }else {
                    diemTrungBinh = (pBD->data.diemThuongKy*0.2 + pBD->data.diemGiuaKy*0.3 + pBD->data.diemCuoiKy*0.5);
                    printf("\n\t>Diem trung binh: %.2f", diemTrungBinh);
                }
                if(diemTrungBinh >=9 && diemTrungBinh <=10)
                    printf("\n\t>Thang diem: A+\n");
                else if(diemTrungBinh >= 8.5 && diemTrungBinh <9)
                    printf("\n\t>Thang diem: A\n");
                else if(diemTrungBinh >= 8 && diemTrungBinh < 8.5)
                    printf("\n\t>Thang diem: B+\n");
                else if (diemTrungBinh >= 7 && diemTrungBinh < 8)
                    printf("\n\t>Thang diem: B\n");
                else if (diemTrungBinh >= 6.5 && diemTrungBinh < 7) {
                    printf("\n\t>Thang diem: C+\n");
                } else if (diemTrungBinh >= 5.5 && diemTrungBinh < 6.5) {
                    printf("\n\t>Thang diem: C\n");
                } else if (diemTrungBinh >= 5 && diemTrungBinh < 5.5) {
                    printf("\n\t>Thang diem: D+\n");
                } else if (diemTrungBinh >= 4 && diemTrungBinh < 5) {
                    printf("\n\t>Thang diem: D\n");
                } else {
                    printf("\n\t>Thang diem: F\n");
                }
            }
            pBD = pBD->pNext;
            }
        p = p->pNext;
        printf("\n\t---------------------------------------------\n");
    }
}
//Xoa sinh vien theo MSSV
void xoaSinhVienTheoMSSV(ListSinhVien &listSV, ListBangDiem &listBD, char maSSVDel[])
{
    NodeSinhVien *pSV = listSV.pHead;
    NodeSinhVien *qSV = NULL;
    NodeBangDiem *pBD = listBD.pHead;
    NodeBangDiem *qBD = NULL;

    // Tìm và xóa sinh viên trong danh sách sinh viên
    while (pSV != NULL)
    {
        if (strcmp(pSV->data.maSoSV, maSSVDel) == 0)
        {
            if (qSV != NULL)
            {
                qSV->pNext = pSV->pNext;
                if (pSV == listSV.pTail)
                {
                    listSV.pTail = qSV;
                }
            }
            else
            {
                listSV.pHead = pSV->pNext;
                if (pSV == listSV.pTail)
                {
                    listSV.pTail = NULL;
                }
            }

            delete pSV;
            break;
        }

        qSV = pSV;
        pSV = pSV->pNext;
    }

    // Tìm và xóa bảng điểm trong danh sách bảng điểm
    while (pBD != NULL)
    {
        if (strcmp(pBD->data.maSSV, maSSVDel) == 0)
        {
            if (qBD != NULL)
            {
                qBD->pNext = pBD->pNext;
                if (pBD == listBD.pTail)
                {
                    listBD.pTail = qBD;
                }
            }
            else
            {
                listBD.pHead = pBD->pNext;
                if (pBD == listBD.pTail)
                {
                    listBD.pTail = NULL;
                }
            }

            delete pBD;
        }

        qBD = pBD;
        pBD = pBD->pNext;
    }
}
//Xoa sinh vien theo ten
void xoaSinhVienTheoTen(ListSinhVien &listSV, ListBangDiem &listBD, char tenSVDel[])
{
    NodeSinhVien *pSV = listSV.pHead;
    NodeSinhVien *qSV = NULL;
    NodeBangDiem *pBD = listBD.pHead;
    NodeBangDiem *qBD = NULL;

    // Tìm và xóa sinh viên trong danh sách sinh viên
    while (pSV != NULL)
    {
        if (strcmp(pSV->data.tenSinhVien, tenSVDel) == 0)
        {
            if (qSV != NULL)
            {
                qSV->pNext = pSV->pNext;
                if (pSV == listSV.pTail)
                {
                    listSV.pTail = qSV;
                }
            }
            else
            {
                listSV.pHead = pSV->pNext;
                if (pSV == listSV.pTail)
                {
                    listSV.pTail = NULL;
                }
            }
            while (pBD != NULL)
            {
                if (strcmp(pBD->data.maSSV, pSV->data.maSoSV) == 0)
                {
                    if (qBD != NULL)
                    {           
                        qBD->pNext = pBD->pNext;
                        if (pBD == listBD.pTail)
                        {
                            listBD.pTail = qBD;
                        }
                    }
                else
                {
                    listBD.pHead = pBD->pNext;
                    if (pBD == listBD.pTail)
                    {
                        listBD.pTail = NULL;
                    }
                }
                delete pBD;
            }
                qBD = pBD;
                pBD = pBD->pNext;
            }
            delete pSV;
            break;
        }
        qSV = pSV;
        pSV = pSV->pNext;
    }
}
//Xuat file thong tin
void xuatFile(ListSinhVien listSV, ListBangDiem listBD, char fileName[])
{
    FILE *f;
    f = fopen(fileName, "w");
    if (f == NULL)
    {
        printf("\n\tError file.Khong the xuat file.\n");
        return;
    }
    NodeSinhVien *p = listSV.pHead;
    while(p != NULL)
    {
        fprintf(f, "sv %s, %s, %s\n", p->data.maSoSV, p->data.tenSinhVien, p->data.lopHocPhan);
        p = p->pNext;
    }
    fprintf(f,"\n");
    NodeBangDiem *q = listBD.pHead;
    while(q != NULL)
    {
        fprintf(f, "diem %s, %s, %.2f, %.2f, %.2f, %.2f\n", q->data.maSSV, q->data.tenMonHoc, q->data.diemThuongKy,
                                        q->data.diemGiuaKy, q->data.diemCuoiKy, q->data.diemThucHanh);
        q = q->pNext;
    }
    fclose(f);
}
//Xuat thong tin ra file moi theo lop
void xuatFileSVTheoLop(ListSinhVien listSV, ListBangDiem listBD, char fileName[], char className[])
{
    FILE *f;
    f = fopen(fileName, "w");
    if(f == NULL)
    {
        printf("\n\tError file. Khong the xuat danh sach sinh vien theo lop.\n");
        return;
    }
    NodeSinhVien *p = listSV.pHead;
    while(p != NULL)
    {
        if(strcmp(p->data.lopHocPhan, className) == 0)
        {
            fprintf(f, "sv %s, %s, %s\n", p->data.maSoSV, p->data.tenSinhVien, p->data.lopHocPhan);
            NodeBangDiem *q = listBD.pHead;
            while(q != NULL)
            {
                if(strcmp(q->data.maSSV, p->data.maSoSV) == 0)
                    fprintf(f, "diem %s, %s, %.2f, %.2f, %.2f, %.2f\n", q->data.maSSV, q->data.tenMonHoc, q->data.diemThuongKy,
                                                            q->data.diemGiuaKy, q->data.diemCuoiKy, q->data.diemThucHanh);
                q = q->pNext;
            }
            fprintf(f,"\n");
        }
        p = p->pNext;
    }
    printf("\n\tXuat file thanh cong.\n");
    fclose(f);
}
//Diem trung binh tung sinh vien
float diemTrungBinhTungSV(ListBangDiem listBD, NodeSinhVien* pSV)
{
    float diemTong = 0;
    int soMon = 0;
    NodeBangDiem* pBD = listBD.pHead;
    while(pBD != NULL)
    {
        if(strcmp(pBD->data.maSSV, pSV->data.maSoSV) == 0) {
            float diemMonHoc;
            if(pBD->data.diemThucHanh == 0)
            {
                diemMonHoc = (pBD->data.diemThuongKy*0.2 + pBD->data.diemGiuaKy*0.3 + pBD->data.diemCuoiKy*0.5);
            }else {
                diemMonHoc = (((pBD->data.diemThuongKy + pBD->data.diemThucHanh)/2)*0.2 + pBD->data.diemGiuaKy*0.3 
                                + pBD->data.diemCuoiKy*0.5);
            }
            diemTong += diemMonHoc;
            soMon++;
        }
        pBD = pBD->pNext;
    }
    if(soMon > 0)
        return diemTong/soMon;
    else   
        return 0;
}
//Sap xep theo diem trung binh
void sapXepTheoDiemTrungBinh(ListSinhVien &listSV, ListBangDiem listBD)
{
    NodeSinhVien* p, * q;
    for(p = listSV.pHead; p!=NULL; p = p->pNext)
    {
        for(q = p->pNext; q != NULL; q = q->pNext)
        {
            double diemP = diemTrungBinhTungSV(listBD, p);
            double diemQ = diemTrungBinhTungSV(listBD,q);
            if(diemP < diemQ)
            {
                SinhVien temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}
//Cap nhat thong tin theo MSSV
void capNhatThongTinSV(ListSinhVien &listSV, char maSVUpdate[])
{
    NodeSinhVien* p = listSV.pHead;
    while (p != NULL)
    {
        if(strcmp(p->data.maSoSV, maSVUpdate) == 0)
        {
            printf("\n\tNhap thong tin moi cho sinh vien %s:\n", maSVUpdate);
            nhapThongTinSV(p->data);
            printf("\n\tCap nhat thong tin thanh cong.\n");
            return;
        }
        p = p->pNext;
    }
    printf("\n\tKhong tim thay sinh vien voi ma so %s.\n", maSVUpdate);
    printf("\n\tCap nhat thong tin that bai.\n");
}
void capNhatBangDiem(ListBangDiem &listBD, char maSVUpdate[])
{
    NodeBangDiem* p = listBD.pHead;
    while(p!=NULL)
    {
        if(strcmp(p->data.maSSV, maSVUpdate) == 0)
        {
            printf("\n\tCap nhat bang diem cho sinh vien co ma %s: \n", maSVUpdate);
            nhapBangDiem(p->data);
            printf("\n\tCap nhat thong tin thanh cong.\n");
            return;
        }
        p = p->pNext;
    }
    printf("\n\tKhong tim thay bang diem cua sinh co ma %s.", maSVUpdate);
    printf("\n\tCap nhat thong tin that bai.\n");
}
void capNhatThongTinSVVaBangDiem(ListSinhVien &listSV, ListBangDiem &listBD, char maSVUpdate[]) {
    NodeSinhVien* pSV = listSV.pHead;
    while (pSV != NULL) {
        if (strcmp(pSV->data.maSoSV, maSVUpdate) == 0) {
            // Tim thay sinh vien can cap nhat
            printf("\n\tNhap thong tin moi cho sinh vien %s:\n", maSVUpdate);
            nhapThongTinSV(pSV->data);  

            NodeBangDiem* pBD = listBD.pHead;
            while (pBD != NULL) {
                if (strcmp(pBD->data.maSSV, maSVUpdate) == 0) {
                    
                    printf("\n\tCap nhat bang diem cho sinh vien co ma %s: \n", maSVUpdate);
                    nhapBangDiem(pBD->data);  
                    printf("\n\tCap nhat thong tin thanh cong.\n");
                    return;
                }
                pBD = pBD->pNext;
            }
            printf("\n\tKhong tim thay bang diem cua sinh vien co ma %s.\n", maSVUpdate);
            printf("\n\tCap nhat thong tin sinh vien thanh cong. Cap nhat bang diem that bai.\n");
            return;
        }
        pSV = pSV->pNext;
    }

    // Nếu không tìm thấy sinh viên với mã số đã cho
    printf("\n\tKhong tim thay sinh vien voi ma so %s.\n", maSVUpdate);
    printf("\n\tCap nhat thong tin that bai.");
}
//Hien thi danh sach sinh vien theo lop
void hienThiDanhSachSVTheoLop(ListSinhVien listSV, char className[])
{
    NodeSinhVien *p = listSV.pHead;
    while(p != NULL)
    {
        if(strcmp(p->data.lopHocPhan, className) == 0)
        {
            xuatThongTinSV(p->data);
        }
        p = p->pNext;
    }
}
//Hien thi danh sach sinh vien theo xep loai cua lop
void hienThiDanhSachSVGioiTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[])
{
    int svGioi = 0;
    int sv = 0;
    NodeSinhVien* pSV = listSV.pHead;
    NodeBangDiem* pBD = listBD.pHead;
    while(pSV != NULL)
    {
        if(strcmp(pSV->data.lopHocPhan, className) == 0)
        {
            sv++;
            double diemTB = diemTrungBinhTungSV(listBD, pSV);
            if(diemTB >= 8.0 && diemTB < 9.0)
            {
                xuatThongTinSV(pSV->data);
                printf("\t>Diem trung binh: %.2f\n", diemTB);
                svGioi++;
            }
        }
        pSV = pSV->pNext;
    }
    if(svGioi != 0)
    {
        printf("\n\t>>>>>>Ti le sinh vien gioi cua lop: %.2f%%<<<<<", (double)svGioi/sv*100);
    }else{
        printf("\n\tLop %s khong co sinh vien Gioi.", className);
    }
}
void hienThiDanhSachSVXuatSacTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[])
{
    int svXuatSac = 0;
    int sv = 0;
    NodeSinhVien* pSV = listSV.pHead;
    NodeBangDiem* pBD = listBD.pHead;
    while(pSV != NULL)
    {
        if(strcmp(pSV->data.lopHocPhan, className) == 0)
        {
            sv++;
            double diemTB = diemTrungBinhTungSV(listBD, pSV);
            if(diemTB >= 9.0)
            {
                xuatThongTinSV(pSV->data);
                printf("\t>Diem trung binh: %.2f\n", diemTB);
                svXuatSac++;
            }
        }
        pSV = pSV->pNext;
    }
    if(svXuatSac != 0)
    {
        printf("\n\t>>>>>Ti le sinh vien Xuat Sac cua lop: %.2f%%<<<<<<", (double)svXuatSac/sv*100);
    }else{
        printf("\n\tLop %s khong co sinh vien Xuat Sac.", className);
    }
}
void hienThiDanhSachSVKhaTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[])
{
    int svKha = 0;
    int sv = 0;
    NodeSinhVien* pSV = listSV.pHead;
    NodeBangDiem* pBD = listBD.pHead;
    while(pSV != NULL)
    {
        if(strcmp(pSV->data.lopHocPhan, className) == 0)
        {
            sv++;
            double diemTB = diemTrungBinhTungSV(listBD, pSV);
            if(diemTB >= 6.5 && diemTB < 8.0)
            {
                xuatThongTinSV(pSV->data);
                printf("\t>Diem trung binh: %.2f\n", diemTB);
                svKha++;
            }
        }
        pSV = pSV->pNext;
    }
    if(svKha != 0)
    {
        printf("\n\t>>>>>Ti le sinh vien Kha cua lop: %.2f%%<<<<<", (double)svKha/sv*100);
    }else{
        printf("\n\tLop %s khong co sinh vien Kha.", className);
    }
}
void hienThiDanhSachSVTrungBinhTheoLop(ListSinhVien listSV, ListBangDiem listBD, char className[])
{
    int svTB = 0;
    int sv = 0;
    NodeSinhVien* pSV = listSV.pHead;
    NodeBangDiem* pBD = listBD.pHead;
    while(pSV != NULL)
    {
        if(strcmp(pSV->data.lopHocPhan, className) == 0)
        {
            sv++;
            double diemTB = diemTrungBinhTungSV(listBD, pSV);
            if(diemTB >= 6.5 && diemTB < 8.0)
            {
                xuatThongTinSV(pSV->data);
                printf("\n\t>Diem trung binh: %.2f\n", diemTB);
                svTB++;
            }
        }
        pSV = pSV->pNext;
    }
    if(svTB != 0)
    {
        printf("\n\t>>>>>Ti le sinh vien Trung Binh cua lop: %.2f%%<<<<<<", (double)svTB/sv*100);
    }else{
        printf("\n\tLop %s khong co sinh vien Trung Binh.", className);
    }
}
//Top 5 Sinh vien co diem cao nhat danh sach SV
void topNamSVCoDiemCaoNhat(ListSinhVien listSV, ListBangDiem listBD)
{
    NodeSinhVien* pSV = listSV.pHead;

    printf("\n  ********TOP 5 SINH VIEN CO DIEM CAO NHAT*********\n");
    int count = 0;
    while(pSV != NULL && count < 5)
    {
        float diemTrungBinh = diemTrungBinhTungSV(listBD, pSV);
        xuatThongTinSV(pSV->data);
        printf("\t>Diem trung binh: %.2f\n", diemTrungBinh);

        pSV = pSV->pNext;
        count++;
    }
}
//Tao mau
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Aqua = 3,
    Red = 4,
    Purple = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightAqua = 11,
    LightRed = 12,
    LightPurple = 13,
    LightYellow = 14,
    BrightWhite = 15
};
void SetConsoleTextColor(ConsoleColor textColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
}
//Xoa man hinh
void xoaManHinh() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
//Bia
void biaDoAn()
{
    SetConsoleTextColor(LightAqua);
    printf("\t\t\t\t\t**************************************\n");
    printf("\t\t\t\t\t*                                    *\n");
    printf("\t\t\t\t\t*       QUAN LY DIEM SINH VIEN       *\n");
    printf("\t\t\t\t\t*                                    *\n");
    printf("\t\t\t\t\t**************************************\n");
    SetConsoleTextColor(White);
}
//Menu
void Menu(ListSinhVien &listSV, ListBangDiem &listBD)
{
    int chon, numStudent = 0, numScore = 0;
    do
    {
        xoaManHinh();
        biaDoAn();
        printf("\n\n\n\t********************* MENU **********************\n");
        printf("\t* 1. Doc du lieu tu file.                       *\n");
        printf("\t* 2. Xuat thong tin ra file.                    *\n");
        printf("\t* 3. Them du lieu.                              *\n");
        printf("\t* 4. Tim kiem.                                  *\n");
        printf("\t* 5. Xoa sinh vien.                             *\n");
        printf("\t* 6. Sap xep sinh vien theo diem trung binh.    *\n");
        printf("\t* 7. Cap nhat thong tin.                        *\n");
        printf("\t* 8. Hien thi danh sach sinh vien.              *\n");
        printf("\t* 9. Top 5 sinh vien co diem cao nhat lop.      *\n");
        printf("\t* 10. Thoat chuong trinh.                       *\n");
        printf("\t*************************************************\n");

        SetConsoleTextColor(LightBlue);
        printf("\tMoi ban nhap lua chon: ");
        SetConsoleTextColor(White);
        scanf("%d", &chon);

        switch(chon) {
            case 1:
                xoaManHinh();
                biaDoAn();
                char fileName[30];
                printf("\n\n\t>Nhap ten file: ");
                fflush(stdin);
                gets(fileName);
                if(readDataFromFile(numStudent, numScore, listSV, listBD, fileName) == 1) {
                    SetConsoleTextColor(LightBlue);
                    printf("\tDoc file du lieu thanh cong.\n");
                    SetConsoleTextColor(White);
                } else if(readDataFromFile(numStudent, numScore, listSV, listBD, fileName) == 0){
                    SetConsoleTextColor(LightBlue);
                    printf("\tError file. Doc file du lieu khong thanh cong.\n");
                    SetConsoleTextColor(White);
                }
                printf("\n\tSo luong sinh vien: %d", numStudent);
                printf("\n\tSo luong bang diem: %d\n", numScore);
                system("pause");
            break;
            case 2:
                xoaManHinh();
                biaDoAn();
                int chon2;
                do {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Xuat toan bo thong tin ra file.            *\n");
                    printf("\t* 2. Xuat thong tin theo lop.                   *\n");
                    printf("\t* 3. Thoat                                      *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon2);

                    switch(chon2) {
                        case 1:
                            char fileName[30];
                            printf("\n\tNhap ten file can xuat: ");
                            fflush(stdin);
                            gets(fileName);
                            SetConsoleTextColor(LightBlue);
                            xuatFile(listSV, listBD, fileName);
                            printf("\n\t Xuat file thanh cong.");
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            char fileName2[30], className[15];
                            printf("\n\tNhap ten file can xuat: ");
                            fflush(stdin);
                            gets(fileName2);
                            printf("\n\tNhap ten lop hoc phan can xuat thong tin: ");
                            gets(className);
                            SetConsoleTextColor(LightBlue);
                            xuatFileSVTheoLop(listSV, listBD, fileName2, className);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                }while(chon2 != 3);
            break;
            case 3:
                xoaManHinh();
                biaDoAn();
                int chon3;
                do {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Them sinh vien.                            *\n");
                    printf("\t* 2. Them bang diem.                            *\n");
                    printf("\t* 3. Thoat                                      *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon3);

                    switch(chon3) {
                        case 1:
                            SinhVien x;
                            nhapThongTinSV(x);
                            themSV(listSV, x);
                            SetConsoleTextColor(LightBlue);
                            printf("\n\tThem sinh vien thanh cong.\n");
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            BangDiem bd;
                            nhapBangDiem(bd);
                            themBangDiem(listBD,bd);
                            SetConsoleTextColor(LightBlue);
                            printf("\n\tThem bang diem thanh cong.\n");
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                }while(chon3 != 3);
            break;
            case 4:
                xoaManHinh();
                biaDoAn();
                int chon4;
                NodeSinhVien* pSVT;
                do
                {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Tim kiem sinh vien theo MSSV.              *\n");
                    printf("\t* 2. Tim kiem sinh vien theo ten sinh vien      *\n");
                    printf("\t* 3. Thoat                                      *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon4);

                    switch(chon4) {
                        case 1:
                            char maSVTim[9];
                            printf("\n\tMoi nhap ma sinh vien can tim: ");
                            fflush(stdin);
                            gets(maSVTim);
                            pSVT = timSinhVienTheoMSSV(listSV, maSVTim);
                            if(pSVT != NULL)
                            {
                                SetConsoleTextColor(LightYellow);
                                printf("\n\t        THONG TIN SINH VIEN %s      ", maSVTim);
                                SetConsoleTextColor(White);
                                ouputThongTinSV(listSV, listBD, pSVT);
                            }else {
                                SetConsoleTextColor(LightBlue);
                                printf("\n\tKhong tim thay sinh vien co ma %s", maSVTim);
                                SetConsoleTextColor(White);
                            }
                            printf("\n");
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            char tenSVTim[30];
                            printf("\n\tMoi nhap ten sinh vien can tim: ");
                            fflush(stdin);
                            gets(tenSVTim);
                            pSVT = timSinhVienTheoTen(listSV, tenSVTim);
                            if(pSVT != NULL)
                            {
                                SetConsoleTextColor(LightYellow);
                                printf("\n\t\t\t\tTHONG TIN SINH VIEN TEN %s", tenSVTim);
                                SetConsoleTextColor(White);
                                ouputThongTinSV(listSV, listBD, pSVT);
                            }else {
                                SetConsoleTextColor(LightBlue);
                                printf("\n\tKhong tim thay sinh vien co ten %s", tenSVTim);
                                SetConsoleTextColor(White);
                            }
                            printf("\n");
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                } while (chon4 != 3);
            break;
            case 5:
                xoaManHinh();
                biaDoAn();
                int chon5;
                do {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Xoa sinh vien theo MSSV.                   *\n");
                    printf("\t* 2. Xoa sinh vien theo ten.                    *\n");
                    printf("\t* 3. Thoat.                                     *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon5);

                    switch(chon5) {
                        case 1:
                            char maSVDel[9];
                            printf("\n\tNhap MSSV can xoa: ");
                            fflush(stdin);
                            gets(maSVDel);
                            xoaSinhVienTheoMSSV(listSV, listBD, maSVDel);
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(LightBlue);
                            printf("\n\tXoa sinh vien co ma %s thanh cong.\n", maSVDel);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            char nameDel[30];
                            printf("\n\tNhap ten sinh vien can xoa: ");
                            fflush(stdin);
                            gets(nameDel);
                            xoaSinhVienTheoTen(listSV, listBD, nameDel);
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(LightBlue);
                            printf("\n\tXoa sinh vien co ten %s thanh cong.\n", nameDel);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                }while(chon5 != 3);
            break;
            case 6:
                xoaManHinh();
                biaDoAn();
                sapXepTheoDiemTrungBinh(listSV, listBD);
                SetConsoleTextColor(LightBlue);
                printf("\n\tSap xep sinh vien theo diem trung binh thanh cong.\n");
                SetConsoleTextColor(White);
                system("pause");
                system("cls");
                biaDoAn();
            break;
            case 7:
                xoaManHinh();
                biaDoAn();
                int chon6;
                char maSVUpdate[9];
                do {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Cap nhat thong tin sinh vien.              *\n");
                    printf("\t* 2. Cap nhat bang diem.                        *\n");
                    printf("\t* 3. Cap nhat thong tin va bang diem sinh vien. *\n");
                    printf("\t* 4. Thoat.                                     *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon6);

                    switch(chon6) {
                        case 1:
                            printf("\n\tNhap MSSV can cap nhat thong tin: ");
                            fflush(stdin);
                            gets(maSVUpdate);
                            SetConsoleTextColor(LightBlue);
                            capNhatThongTinSV(listSV, maSVUpdate);
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            printf("\n\tNhap MSSV can cap nhat thong tin: ");
                            fflush(stdin);
                            gets(maSVUpdate);
                            SetConsoleTextColor(LightBlue);
                            capNhatBangDiem(listBD, maSVUpdate);
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 3:
                            printf("\n\tNhap MSSV can cap nhat thong tin: ");
                            fflush(stdin);
                            gets(maSVUpdate);
                            SetConsoleTextColor(LightBlue);
                            capNhatThongTinSVVaBangDiem(listSV, listBD, maSVUpdate);
                            xuatFile(listSV, listBD, fileName);
                            SetConsoleTextColor(White);
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                }while(chon6!=4);
            break;
            case 8:
                xoaManHinh();
                biaDoAn();
                int chon7;
                do {
                    printf("\n\n\n\t********************* MENU **********************\n");
                    printf("\t* 1. Hien thi toan bo danh sach sinh vien.      *\n");
                    printf("\t* 2. Hien thi danh sach sinh vien theo lop.     *\n");
                    printf("\t* 3. Hien thi sinh vien theo xep loai cua lop.  *\n");
                    printf("\t* 4. Thoat.                                     *\n");
                    printf("\t*************************************************\n");
                    SetConsoleTextColor(LightBlue);
                    printf("\tMoi ban nhap lua chon: ");
                    SetConsoleTextColor(White);
                    scanf("%d", &chon7);

                    switch(chon7) {
                        case 1:
                            xoaManHinh();
                            biaDoAn();
                            SetConsoleTextColor(LightBlue);
                            printf("\n\t**********DANH SACH SINH VIEN********** \n");
                            SetConsoleTextColor(White);
                            xuatToanBoThongTin(listSV, listBD);
                            printf("\n");
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 2:
                            xoaManHinh();
                            biaDoAn();
                            char className2[15];
                            SetConsoleTextColor(LightGreen);
                            printf("\n\tMoi ban nhap lop: ");
                            SetConsoleTextColor(White);
                            fflush(stdin);
                            gets(className2);
                            SetConsoleTextColor(LightBlue);
                            printf("\n\n\tDANH SACH SINH VIEN LOP %s: \n", className2);
                            SetConsoleTextColor(White);
                            hienThiDanhSachSVTheoLop(listSV, className2);
                            printf("\n");
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                        case 3:
                            xoaManHinh();
                            biaDoAn();
                            int chon8;
                            char className3[15];
                            SetConsoleTextColor(LightGreen);
                            printf("\n\tMoi ban nhap lop: ");
                            SetConsoleTextColor(White);
                            fflush(stdin);
                            gets(className3);
                            
                            do {
                                xoaManHinh();
                                biaDoAn();
                                printf("\n\n\n\t****************************** MENU ******************************\n");
                                printf("\t* 1. Hien thi danh sach sinh vien loai Xuat Sac lop %s.   *\n", className3);
                                printf("\t* 2. Hien thi danh sach sinh vien loai Gioi lop %s.       *\n", className3);
                                printf("\t* 3. Hien thi danh sach sinh vien loai Kha lop %s.        *\n", className3);
                                printf("\t* 4. Hien thi danh sach sinh vien loai Trung Binh lop %s. *\n", className3);
                                printf("\t* 5. Thoat.                                                      *\n");
                                printf("\t******************************************************************\n");

                                SetConsoleTextColor(LightBlue);
                                printf("\tMoi ban nhap lua chon: ");
                                SetConsoleTextColor(White);
                                scanf("%d", &chon8);
                                
                                switch(chon8) {
                                    case 1:
                                        xoaManHinh();
                                        biaDoAn();
                                        SetConsoleTextColor(LightBlue);
                                        printf("\n\n\tDANH SACH SINH VIEN XEP LOAI XUAT SAC LOP %s: \n", className3);
                                        SetConsoleTextColor(White);
                                        hienThiDanhSachSVXuatSacTheoLop(listSV, listBD, className3);
                                        printf("\n");
                                        system("pause");
                                        system("cls");
                                        biaDoAn();
                                    break;
                                    case 2:
                                        xoaManHinh();
                                        biaDoAn();
                                        SetConsoleTextColor(LightBlue);
                                        printf("\n\n\tDANH SACH SINH VIEN XEP LOAI GIOI LOP %s: \n", className3);
                                        SetConsoleTextColor(White);
                                        hienThiDanhSachSVGioiTheoLop(listSV, listBD, className3);
                                        printf("\n");
                                        system("pause");
                                        system("cls");
                                        biaDoAn();
                                    break;
                                    case 3:
                                        xoaManHinh();
                                        biaDoAn();
                                        SetConsoleTextColor(LightBlue);
                                        printf("\n\n\tDANH SACH SINH VIEN XEP LOAI KHA LOP %s: \n", className3);
                                        SetConsoleTextColor(White);
                                        hienThiDanhSachSVKhaTheoLop(listSV, listBD, className3);
                                        printf("\n");
                                        system("pause");
                                        system("cls");
                                        biaDoAn();
                                    break;
                                    case 4:
                                        xoaManHinh();
                                        biaDoAn();
                                        SetConsoleTextColor(LightBlue);
                                        printf("\n\n\tDANH SACH SINH VIEN XEP LOAI TRUNG BINH LOP %s: \n", className3);
                                        SetConsoleTextColor(White);
                                        hienThiDanhSachSVTrungBinhTheoLop(listSV, listBD, className3);
                                        printf("\n");
                                        system("pause");
                                        system("cls");
                                        biaDoAn();
                                    break;
                                }
                            }while(chon8 != 5);
                            printf("\n");
                            system("pause");
                            system("cls");
                            biaDoAn();
                        break;
                    }
                }while(chon7!=4);
            break;
            case 9:
                xoaManHinh();
                biaDoAn();
                sapXepTheoDiemTrungBinh(listSV, listBD);
                topNamSVCoDiemCaoNhat(listSV, listBD);
                system("pause");
                system("cls");
                biaDoAn();
            break;
            case 10:
                SetConsoleTextColor(LightGreen);
                printf("\n\tThoat chuong trinh thanh cong.");
                SetConsoleTextColor(White);
                return;
            break;
        }
    }while(chon != 11);
}

//cHAY CHUONG TRINH
int main()
{
    SinhVien ds_SV;
    BangDiem ds_BD;
    ListSinhVien listSV;
    ListBangDiem listBD;
    InitListSV(listSV);
    InitListBD(listBD);
    Menu(listSV, listBD);
    return 0;
}

