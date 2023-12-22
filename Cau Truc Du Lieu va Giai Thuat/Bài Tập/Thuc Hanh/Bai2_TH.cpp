#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50

// Khai báo cấu trúc mặt hàng
struct MatHang {
    char ma_mat_hang[20];
    char ten_mat_hang[50];
    float don_gia;
    char xuat_xu[50];
};

// Nhập danh sách các mặt hàng
void nhap_danh_sach_mat_hang(struct MatHang danh_sach_mat_hang[], int *so_mat_hang) {
    printf("Nhap so luong mat hang (toi da %d): ", MAX_ITEMS);
    scanf("%d", so_mat_hang);

    for (int i = 0; i < *so_mat_hang; i++) {
        printf("\nNhap thong tin mat hang thu %d:\n", i + 1);
        printf("Ma mat hang: ");
        scanf("%s", danh_sach_mat_hang[i].ma_mat_hang);
        printf("Ten mat hang: ");
        scanf("%s", danh_sach_mat_hang[i].ten_mat_hang);
        printf("Don gia: ");
        scanf("%f", &danh_sach_mat_hang[i].don_gia);
        printf("Xuat xu: ");
        scanf("%s", danh_sach_mat_hang[i].xuat_xu);
    }
}

// In ra danh sách mặt hàng
void in_danh_sach_mat_hang(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    printf("\nDanh sach mat hang trong cua hang:\n");
    for (int i = 0; i < so_mat_hang; i++) {
        printf("Ma: %s, Ten: %s, Don gia: %.2f, Xuat xu: %s\n",
               danh_sach_mat_hang[i].ma_mat_hang, danh_sach_mat_hang[i].ten_mat_hang,
               danh_sach_mat_hang[i].don_gia, danh_sach_mat_hang[i].xuat_xu);
    }
}

// Xuất thông tin của mặt hàng có mã số mặt hàng x
void xuat_thong_tin_mat_hang(struct MatHang danh_sach_mat_hang[], int so_mat_hang, char ma_mat_hang_x[]) {
    int tim_thay = 0;
    for (int i = 0; i < so_mat_hang; i++) {
        if (strcmp(danh_sach_mat_hang[i].ma_mat_hang, ma_mat_hang_x) == 0) {
            printf("\nThong tin mat hang co ma so %s:\n", ma_mat_hang_x);
            printf("Ma: %s, Ten: %s, Don gia: %.2f, Xuat xu: %s\n",
                   danh_sach_mat_hang[i].ma_mat_hang, danh_sach_mat_hang[i].ten_mat_hang,
                   danh_sach_mat_hang[i].don_gia, danh_sach_mat_hang[i].xuat_xu);
            tim_thay = 1;
            break;
        }
    }
    if (!tim_thay) {
        printf("Khong tim thay mat hang co ma so %s\n", ma_mat_hang_x);
    }
}

// Liệt kê tất cả các mặt hàng có giá cao hơn trung bình
void liet_ke_gia_cao_hon_trung_binh(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    float tong_gia = 0;
    for (int i = 0; i < so_mat_hang; i++) {
        tong_gia += danh_sach_mat_hang[i].don_gia;
    }

    float trung_binh = tong_gia / so_mat_hang;

    printf("\nDanh sach mat hang co gia cao hon trung binh:\n");
    for (int i = 0; i < so_mat_hang; i++) {
        if (danh_sach_mat_hang[i].don_gia > trung_binh) {
            printf("Ma: %s, Ten: %s, Don gia: %.2f, Xuat xu: %s\n",
                   danh_sach_mat_hang[i].ma_mat_hang, danh_sach_mat_hang[i].ten_mat_hang,
                   danh_sach_mat_hang[i].don_gia, danh_sach_mat_hang[i].xuat_xu);
        }
    }
}

// Liệt kê tất cả các mặt hàng có giá cao nhất
void liet_ke_gia_cao_nhat(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    float gia_cao_nhat = 0;
    for (int i = 0; i < so_mat_hang; i++) {
        if (danh_sach_mat_hang[i].don_gia > gia_cao_nhat) {
            gia_cao_nhat = danh_sach_mat_hang[i].don_gia;
        }
    }

    printf("\nDanh sach mat hang co gia cao nhat:\n");
    for (int i = 0; i < so_mat_hang; i++) {
        if (danh_sach_mat_hang[i].don_gia == gia_cao_nhat) {
            printf("Ma: %s, Ten: %s, Don gia: %.2f, Xuat xu: %s\n",
                   danh_sach_mat_hang[i].ma_mat_hang, danh_sach_mat_hang[i].ten_mat_hang,
                   danh_sach_mat_hang[i].don_gia, danh_sach_mat_hang[i].xuat_xu);
        }
    }
}

// Xóa các mặt hàng có xuất xứ China
void xoa_mat_hang_xuat_xu_china(struct MatHang danh_sach_mat_hang[], int *so_mat_hang) {
    for (int i = 0; i < *so_mat_hang; i++) {
        if (strcmp(danh_sach_mat_hang[i].xuat_xu, "China") == 0) {
            for (int j = i; j < *so_mat_hang - 1; j++) {
                danh_sach_mat_hang[j] = danh_sach_mat_hang[j + 1];
            }
            (*so_mat_hang)--;
            i--;
        }
    }
    printf("Da xoa cac mat hang co xuat xu China.\n");
}

// Sắp xếp danh sách mặt hàng theo thứ tự tăng dần của đơn giá (Bubble sort)
void bubble_sort(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    for (int i = 0; i < so_mat_hang - 1; i++) {
        for (int j = 0; j < so_mat_hang - i - 1; j++) {
            if (danh_sach_mat_hang[j].don_gia > danh_sach_mat_hang[j + 1].don_gia) {
                // Hoán đổi hai phần tử
                struct MatHang temp = danh_sach_mat_hang[j];
                danh_sach_mat_hang[j] = danh_sach_mat_hang[j + 1];
                danh_sach_mat_hang[j + 1] = temp;
            }
        }
    }

    printf("\nDanh sach mat hang sau khi sap xep (Bubble sort):\n");
    in_danh_sach_mat_hang(danh_sach_mat_hang, so_mat_hang);
}
// Sắp xếp danh sách mặt hàng theo thứ tự tăng dần của đơn giá (Interchange sort)
void interchange_sort(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    for (int i = 0; i < so_mat_hang - 1; i++) {
        for (int j = i + 1; j < so_mat_hang; j++) {
            if (danh_sach_mat_hang[i].don_gia > danh_sach_mat_hang[j].don_gia) {
                // Hoán đổi hai phần tử
                struct MatHang temp = danh_sach_mat_hang[i];
                danh_sach_mat_hang[i] = danh_sach_mat_hang[j];
                danh_sach_mat_hang[j] = temp;
            }
        }
    }
}
// Sắp xếp danh sách mặt hàng theo thứ tự tăng dần của đơn giá (Insertion sort)
void insertion_sort(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    int i, j;
    struct MatHang key;

    for (i = 1; i < so_mat_hang; i++) {
        key = danh_sach_mat_hang[i];
        j = i - 1;

        // Di chuyển các phần tử lớn hơn key đến một vị trí trước vị trí hiện tại của chúng
        while (j >= 0 && danh_sach_mat_hang[j].don_gia > key.don_gia) {
            danh_sach_mat_hang[j + 1] = danh_sach_mat_hang[j];
            j = j - 1;
        }
        danh_sach_mat_hang[j + 1] = key;
    }
}
// Sắp xếp danh sách mặt hàng theo thứ tự tăng dần của đơn giá (Selection sort)
void selection_sort(struct MatHang danh_sach_mat_hang[], int so_mat_hang) {
    int i, j, min_index;
    struct MatHang temp;

    for (i = 0; i < so_mat_hang - 1; i++) {
        min_index = i;

        // Tìm phần tử nhỏ nhất trong đoạn chưa sắp xếp
        for (j = i + 1; j < so_mat_hang; j++) {
            if (danh_sach_mat_hang[j].don_gia < danh_sach_mat_hang[min_index].don_gia) {
                min_index = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên chưa sắp xếp
        temp = danh_sach_mat_hang[min_index];
        danh_sach_mat_hang[min_index] = danh_sach_mat_hang[i];
        danh_sach_mat_hang[i] = temp;
    }
}
//Quick sort
int QuickSort(int a[], int left, int right)
{
    int i, j, x;
    if (left >= right) 
        return -1;
    x = a[(left+right)/2]; // chọn phần tử giữa làm giá trị mốc
    i = left; j = right;
do{
    while(a[i] < x) i++;
    while(a[j] > x) j--;
    if(i <= j) {
        Swap(a[i], a[j]);
        i++ ; j--;
    }
} while(i < j);
    if(left<j) QuickSort(a, left, j);
if(i<right) QuickSort(a, i, right);
}
// Hàm main
int main() {
    struct MatHang danh_sach_mat_hang[MAX_ITEMS];
    int so_mat_hang;

    nhap_danh_sach_mat_hang(danh_sach_mat_hang, &so_mat_hang);
    in_danh_sach_mat_hang(danh_sach_mat_hang, so_mat_hang);

    char ma_mat_hang_x[20];
    printf("\nNhap ma so mat hang de xuat thong tin: ");
    scanf("%s", ma_mat_hang_x);
    xuat_thong_tin_mat_hang(danh_sach_mat_hang, so_mat_hang, ma_mat_hang_x);

    liet_ke_gia_cao_hon_trung_binh(danh_sach_mat_hang, so_mat_hang);
    liet_ke_gia_cao_nhat(danh_sach_mat_hang, so_mat_hang);

    xoa_mat_hang_xuat_xu_china(danh_sach_mat_hang, &so_mat_hang);
    in_danh_sach_mat_hang(danh_sach_mat_hang, so_mat_hang);

    bubble_sort(danh_sach_mat_hang, so_mat_hang);

    return 0;
}
