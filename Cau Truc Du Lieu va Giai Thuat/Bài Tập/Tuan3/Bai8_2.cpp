#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc dữ liệu cho sinh viên
typedef struct Student {
    int mssv;
    char hoten[50];
    char gioitinh[10];
    char diachi[100];
    float diem;
    struct Student* next;
    struct Student* prev;
} Student;

// Khởi tạo danh sách liên kết đôi rỗng
Student* head = NULL;

// Hàm để tạo một nút sinh viên mới
Student* createStudent(int mssv, const char* hoten, const char* gioitinh, const char* diachi, float diem) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->mssv = mssv;
    strcpy(newStudent->hoten, hoten);
    strcpy(newStudent->gioitinh, gioitinh);
    strcpy(newStudent->diachi, diachi);
    newStudent->diem = diem;
    newStudent->next = NULL;
    newStudent->prev = NULL;
    return newStudent;
}

// Hàm để thêm một sinh viên vào danh sách
void addStudent(int mssv, const char* hoten, const char* gioitinh, const char* diachi, float diem) {
    Student* newStudent = createStudent(mssv, hoten, gioitinh, diachi, diem);

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newStudent;
        newStudent->prev = current;
    }
}

// Hàm để in ra danh sách sinh viên
void printStudents() {
    Student* current = head;
    while (current != NULL) {
        printf("MSSV: %d\n", current->mssv);
        printf("Họ và tên: %s\n", current->hoten);
        printf("Giới tính: %s\n", current->gioitinh);
        printf("Địa chỉ: %s\n", current->diachi);
        printf("Điểm trung bình: %.2f\n", current->diem);
        printf("\n");
        current = current->next;
    }
}

// Hàm để xóa một sinh viên với MSSV cho trước khỏi danh sách
void deleteStudent(int mssv) {
    Student* current = head;
    while (current != NULL) {
        if (current->mssv == mssv) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Không tìm thấy sinh viên có MSSV %d.\n", mssv);
}

// Hàm để sắp xếp danh sách sinh viên theo điểm trung bình tăng dần
void sortStudentsByDiem() {
    int swapped;
    Student* ptr1;
    Student* lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->diem > ptr1->next->diem) {
                // Hoán đổi thông tin của hai sinh viên
                int tempMSSV = ptr1->mssv;
                char tempHoten[50];
                char tempGioitinh[10];
                char tempDiachi[100];
                float tempDiem = ptr1->diem;

                ptr1->mssv = ptr1->next->mssv;
                strcpy(ptr1->hoten, ptr1->next->hoten);
                strcpy(ptr1->gioitinh, ptr1->next->gioitinh);
                strcpy(ptr1->diachi, ptr1->next->diachi);
                ptr1->diem = ptr1->next->diem;

                ptr1->next->mssv = tempMSSV;
                strcpy(ptr1->next->hoten, tempHoten);
                strcpy(ptr1->next->gioitinh, tempGioitinh);
                strcpy(ptr1->next->diachi, tempDiachi);
                ptr1->next->diem = tempDiem;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Hàm để liệt kê các sinh viên có điểm trung bình >= 5.0
void listStudentsWithDiemOver5() {
    Student* current = head;
    while (current != NULL) {
        if (current->diem >= 5.0) {
            printf("MSSV: %d\n", current->mssv);
            printf("Họ và tên: %s\n", current->hoten);
            printf("Giới tính: %s\n", current->gioitinh);
            printf("Địa chỉ: %s\n", current->diachi);
            printf("Điểm trung bình: %.2f\n", current->diem);
            printf("\n");
        }
        current = current->next;
    }
}

// Hàm để đếm số lượng sinh viên nam
int countMaleStudents() {
    int count = 0;
    Student* current = head;
    while (current != NULL) {
        if (strcmp(current->gioitinh, "Nam") == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int main() {
    int choice;
    int mssv;
    char hoten[50];
    char gioitinh[10];
    char diachi[100];
    float diem;

    do {
        printf("Menu:\n");
        printf("1. Nhập n sinh viên\n");
        printf("2. Thêm 1 sinh viên\n");
        printf("3. In ra danh sách sinh viên\n");
        printf("4. Xóa 1 sinh viên\n");
        printf("5. Sắp xếp theo điểm trung bình\n");
        printf("6. Liệt kê sinh viên có điểm >= 5.0\n");
        printf("7. Đếm số lượng sinh viên nam\n");
        printf("0. Thoát\n");
        printf("Chọn một lựa chọn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập số lượng sinh viên: ");
                int n;
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhập thông tin cho sinh viên %d:\n", i + 1);
                    printf("MSSV: ");
                    scanf("%d", &mssv);
                    printf("Họ và tên: ");
                    scanf(" %[^\n]", hoten);
                    printf("Giới tính: ");
                    scanf(" %[^\n]", gioitinh);
                    printf("Địa chỉ: ");
                    scanf(" %[^\n]", diachi);
                    printf("Điểm trung bình: ");
                    scanf("%f", &diem);
                    addStudent(mssv, hoten, gioitinh, diachi, diem);
                }
                break;
            case 2:
                printf("Nhập thông tin cho sinh viên mới:\n");
                printf("MSSV: ");
                scanf("%d", &mssv);
                printf("Họ và tên: ");
                scanf(" %[^\n]", hoten);
                printf("Giới tính: ");
                scanf(" %[^\n]", gioitinh);
                printf("Địa chỉ: ");
                scanf(" %[^\n]", diachi);
                printf("Điểm trung bình: ");
                scanf("%f", &diem);
                addStudent(mssv, hoten, gioitinh, diachi, diem);
                break;
            case 3:
                printStudents();
                break;
            case 4:
                printf("Nhập MSSV của sinh viên cần xóa: ");
                scanf("%d", &mssv);
                deleteStudent(mssv);
                break;
            case 5:
                sortStudentsByDiem();
                break;
            case 6:
                listStudentsWithDiemOver5();
                break;
            case 7:
                printf("Số lượng sinh viên nam: %d\n", countMaleStudents());
                break;
            case 0:
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ khi kết thúc chương trình
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
