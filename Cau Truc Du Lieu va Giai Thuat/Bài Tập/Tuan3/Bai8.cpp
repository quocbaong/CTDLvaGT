#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc SinhVien
typedef struct SinhVien {
    char mssv[10];
    char hoTen[50];
    char gioiTinh[5];
    char diaChi[100];
    float diemTrungBinh;
    struct SinhVien* next;
    struct SinhVien* prev;
} SinhVien;

// Hàm để tạo một nút mới SinhVien
SinhVien* createSinhVien(char mssv[], char hoTen[], char gioiTinh[], char diaChi[], float diemTrungBinh) {
    SinhVien* newSinhVien = (SinhVien*)malloc(sizeof(SinhVien));
    strcpy(newSinhVien->mssv, mssv);
    strcpy(newSinhVien->hoTen, hoTen);
    strcpy(newSinhVien->gioiTinh, gioiTinh);
    strcpy(newSinhVien->diaChi, diaChi);
    newSinhVien->diemTrungBinh = diemTrungBinh;
    newSinhVien->next = NULL;
    newSinhVien->prev = NULL;
    return newSinhVien;
}

// Hàm để thêm SinhVien mới vào danh sách
void themSinhVien(SinhVien** head, SinhVien* newSinhVien) {
    if (*head == NULL) {
        *head = newSinhVien;
    } else {
        SinhVien* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSinhVien;
        newSinhVien->prev = current;
    }
}

// Hàm để in ra thông tin của một SinhVien
void inSinhVien(SinhVien* sv) {
    printf("MSSV: %s\n", sv->mssv);
    printf("Họ và tên: %s\n", sv->hoTen);
    printf("Giới tính: %s\n", sv->gioiTinh);
    printf("Địa chỉ: %s\n", sv->diaChi);
    printf("Điểm trung bình: %.2f\n", sv->diemTrungBinh);
    printf("\n");
}

// Hàm để in danh sách các SinhVien
void inDanhSach(SinhVien* head) {
    SinhVien* current = head;
    while (current != NULL) {
        inSinhVien(current);
        current = current->next;
    }
}

// Hàm để xóa một SinhVien dựa trên MSSV
void xoaSinhVien(SinhVien** head, char mssv[]) {
    SinhVien* current = *head;
    while (current != NULL) {
        if (strcmp(current->mssv, mssv) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// Hàm để sắp xếp danh sách sinh viên theo điểm trung bình tăng dần
void sapXepDanhSach(SinhVien** head) {
    if (*head == NULL) return;

    SinhVien* current, *next;
    int swapped;
    do {
        swapped = 0;
        current = *head;
        while (current->next != NULL) {
            next = current->next;
            if (current->diemTrungBinh > next->diemTrungBinh) {
                // Swap data
                float temp = current->diemTrungBinh;
                current->diemTrungBinh = next->diemTrungBinh;
                next->diemTrungBinh = temp;

                char tempMSSV[10];
                strcpy(tempMSSV, current->mssv);
                strcpy(current->mssv, next->mssv);
                strcpy(next->mssv, tempMSSV);

                char tempHoTen[50];
                strcpy(tempHoTen, current->hoTen);
                strcpy(current->hoTen, next->hoTen);
                strcpy(next->hoTen, tempHoTen);

                char tempGioiTinh[5];
                strcpy(tempGioiTinh, current->gioiTinh);
                strcpy(current->gioiTinh, next->gioiTinh);
                strcpy(next->gioiTinh, tempGioiTinh);

                char tempDiaChi[100];
                strcpy(tempDiaChi, current->diaChi);
                strcpy(current->diaChi, next->diaChi);
                strcpy(next->diaChi, tempDiaChi);

                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

// Hàm để liệt kê các sinh viên có điểm trung bình >= 5.0
void danhSachDiemTren5(SinhVien* head) {
    printf("Danh sách sinh viên có điểm trung bình >= 5.0:\n");
    SinhVien* current = head;
    while (current != NULL) {
        if (current->diemTrungBinh >= 5.0) {
            inSinhVien(current);
        }
        current = current->next;
    }
}

// Hàm để đếm số lượng sinh viên nam
int demSinhVienNam(SinhVien* head) {
    int count = 0;
    SinhVien* current = head;
    while (current != NULL) {
        if (strcmp(current->gioiTinh, "Nam") == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Hàm để cập nhật điểm trung bình của một sinh viên thông qua MSSV
void capNhatDiem(SinhVien* head, char mssv[], float newDiem) {
    SinhVien* current = head;
    while (current != NULL) {
        if (strcmp(current->mssv, mssv) == 0) {
            current->diemTrungBinh = newDiem;
            return;
        }
        current = current->next;
    }
    printf("Không tìm thấy sinh viên có MSSV: %s\n", mssv);
}

int main() {
    SinhVien* danhSachSinhVien = NULL;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char mssv[10], hoTen[50], gioiTinh[5], diaChi[100];
        float diemTrungBinh;
        printf("Nhập thông tin cho sinh viên %d:\n", i + 1);
        printf("MSSV: ");
        scanf("%s", mssv);
        printf("Họ và tên: ");
        scanf("%s", hoTen);
        printf("Giới tính: ");
        scanf("%s", gioiTinh);
        printf("Địa chỉ: ");
        scanf("%s", diaChi);
        printf("Điểm trung bình: ");
        scanf("%f", &diemTrungBinh);

        SinhVien* newSinhVien = createSinhVien(mssv, hoTen, gioiTinh, diaChi, diemTrungBinh);
        themSinhVien(&danhSachSinhVien, newSinhVien);
    }

    // Thêm một sinh viên mới
    char mssv[10], hoTen[50], gioiTinh[5], diaChi[100];
    float diemTrungBinh;
    printf("Nhập thông tin cho sinh viên mới:\n");
    printf("MSSV: ");
    scanf("%s", mssv);
    printf("Họ và tên: ");
    scanf("%s", hoTen);
    printf("Giới tính: ");
    scanf("%s", gioiTinh);
    printf("Địa chỉ: ");
    scanf("%s", diaChi);
    printf("Điểm trung bình: ");
    scanf("%f", &diemTrungBinh);

    SinhVien* newSinhVien = createSinhVien(mssv, hoTen, gioiTinh, diaChi, diemTrungBinh);
    themSinhVien(&danhSachSinhVien, newSinhVien);

    printf("Danh sách sinh viên:\n");
    inDanhSach(danhSachSinhVien);

    // Xóa một sinh viên
    char mssvXoa[10];
    printf("Nhập MSSV của sinh viên cần xóa: ");
    scanf("%s", mssvXoa);
    xoaSinhVien(&danhSachSinhVien, mssvXoa);

    printf("Danh sách sinh viên sau khi xóa:\n");
    inDanhSach(danhSachSinhVien);

    // Sắp xếp danh sách theo điểm trung bình
    sapXepDanhSach(&danhSachSinhVien);

    printf("Danh sách sau khi sắp xếp theo điểm trung bình tăng dần:\n");
    inDanhSach(danhSachSinhVien);

    danhSachDiemTren5(danhSachSinhVien);

    int countNam = demSinhVienNam(danhSachSinhVien);
    printf("Số lượng sinh viên nam: %d\n", countNam);

    // Cập nhật điểm trung bình của một sinh viên
    char mssvCapNhat[10];
    float newDiem;
    printf("Nhập MSSV của sinh viên cần cập nhật điểm: ");
    scanf("%s", mssvCapNhat);
    printf("Nhập điểm mới: ");
    scanf("%f", &newDiem);
    capNhatDiem(danhSachSinhVien, mssvCapNhat, newDiem);

    printf("Danh sách sau khi cập nhật điểm:\n");
    inDanhSach(danhSachSinhVien);

    return 0;
}
