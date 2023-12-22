/*
	Ho va Ten: Nguyen Quoc Bao
	MSSV: 22001745
	Yeu cau: 1. Them mot phan tu vao dau danh sach
			2. Xuat danh sach ra man hinh
			3. Liet ke cac phan tu mang gia tri chan
			4. Tinh tong cac phan tu mang gia tri chan
			5. tim phan tu co gia tri lon nhat
			6. Dem so luong so nguyen to trong danh sach
			7. Xoa phan tu nho nhat trong danh sach
			8. Nhap vao phan tu X, xoa phan tu dung sau va dung truoc phan ta X trong danh sach
*/

#include<stdio.h>
#include<stdlib.h>
//khai bao cau truc  dien danh sach lien ket
struct Node {
	int Data;
	Node *pNext;
};
struct List{
	Node *pHead;
    Node *pTail;
};

//Khai bao nguyen mau ham
void khoiTao(List &L);
Node* getNode(int x);
void themDau(List& l, Node* p);
void nhapList(List &L);
void xuatList(List L);
void xuatChan(List L);
int tongChan(List L);
Node* timMax(List L);
bool LaSNT(int x);
int demSNT(List L);
Node* timMin(List L);
void xoaDau(List &L);
void xoaCuoi(List &L);
void xoaP(List &L, Node* p);
void xoaMin(List &L);
Node* timX(List L, int x);
void XoakTruocp(List &L, Node* p, Node* k);
void XoakSaup(List &L, Node* p, Node* q);

//Dinh nghia ham
void khoiTao(List &L)
{
    L.pHead = L.pTail = NULL;
}
//Tao mot Node moi
Node* getNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        exit(0);
    }
    p->Data = x;
    p->pNext = NULL;
    return p;
}
// 1. Thêm một phần tử vào đầu danh sách
void themDau(List& L, Node* p) {
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
//Nhap danh sach
void nhapList(List &L) {
	int x;
	Node *p;
	do{
		printf("Nhap phan tu can them: ");
		scanf("%d", &x);
		if(x==0) 
			break;
		p = getNode(x);
		themDau(L, p);
	}while(true);
}
// 2. Xuất danh sách ra màn hình
void xuatList(List L) {
    Node* p = L.pHead;
    while (p != NULL) {
        printf("%d ", p->Data);
        p = p->pNext;
    }
    printf("\n");
}
// 3. Liệt kê các phần tử mang giá trị chẵn
void xuatChan(List L) {
    Node* p = L.pHead;
    while (p != NULL) {
        if (p->Data % 2 == 0) {
            printf("%d ", p->Data);
        }
        p = p->pNext;
    }
    printf("\n");
}
// 4. Tính tổng các phần tử mang giá trị chẵn
int tongChan(List L) {
    Node* p = L.pHead;
    int S = 0;
    while (p != NULL) {
        if (p->Data % 2 == 0) {
            S += p->Data;
        }
        p = p->pNext;
    }
    return S;
}
// 5. Tìm phần tử có giá trị lớn nhất
Node* timMax(List L) {
    Node* max = L.pHead;
    for (Node* p = L.pHead->pNext; p != NULL; p = p->pNext) {
        if (p->Data > max->Data) {
            max = p;
        }
    }
    return max;
}
// 6. Kiểm tra x có phải là số nguyên tố
bool LaSNT(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
// Đếm số lượng số nguyên tố trong danh sách
int demSNT(List L) {
    Node* p = L.pHead;
    int count = 0;
    while (p != NULL) {
        if (LaSNT(p->Data)) {
            count++;
        }
        p = p->pNext;
    }
    return count;
}
// 7. Tìm node có giá trị nhỏ nhất
Node* timMin(List L) {
    if (L.pHead == NULL) {
        return NULL; // Danh sách rỗng
    }

    Node* min = L.pHead;
    Node* p = L.pHead->pNext;
    while (p != NULL) {
        if (p->Data < min->Data) {
            min = p;
        }
        p = p->pNext;
    }
    return min;
}

// Xóa node đầu của danh sách
void xoaDau(List &L) {
    if (L.pHead == NULL) {
        return; // Danh sách rỗng
    }
    Node* p = L.pHead;
    L.pHead = L.pHead->pNext;
    free(p);
}

// Xóa node cuối của danh sách
void xoaCuoi(List &L) {
    if (L.pHead == NULL) {
        return; // Danh sách rỗng
    }
    if (L.pHead == L.pTail) {
        free(L.pHead);
        L.pHead = L.pTail = NULL;
        return;
    }
    Node* p = L.pHead;
    while (p->pNext != L.pTail) {
        p = p->pNext;
    }
    free(L.pTail);
    p->pNext = NULL;
    L.pTail = p;
}

// Xóa node p
void xoaP(List &L, Node* p) {
    if (L.pHead == NULL) {
        return; // Danh sách rỗng
    }
    Node* prev = L.pHead;
    while (prev->pNext != p) {
        prev = prev->pNext;
    }
    prev->pNext = p->pNext;
    free(p);
}

// Xóa phần tử nhỏ nhất trong danh sách
void xoaMin(List &L) {
    Node *p;
    p = timMin(L);
    if(p == L.pHead)
        xoaDau(L);
    else if(p == L.pTail)
        xoaCuoi(L);
    else 
        xoaP(L,p);
}
// 8. Tìm node có giá trị X
Node* timX(List L, int x) {
    Node* p = L.pHead;
    while (p != NULL) {
        if (p->Data == x) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}
// Xóa k trước p
void XoakTruocp(List &L, Node* p, Node* k) {
    if (L.pHead == NULL || p == NULL || k == NULL || p == k || p->pNext == k) {
        return; // Danh sách rỗng hoặc p, k không hợp lệ
    }

    if (L.pHead == p) {
        L.pHead = k;
        while (p->pNext != k) {
            Node* temp = p->pNext;
            free(p);
            p = temp;
        }
        free(p);
        return;
    }

    Node* prev = L.pHead;
    while (prev->pNext != p) {
        prev = prev->pNext;
    }
    prev->pNext = k;
    while (p != k) {
        Node* temp = p->pNext;
        free(p);
        p = temp;
    }
    free(p);
}

// Xóa k sau p
void XoakSaup(List &L, Node* p, Node* q) {
    if (L.pHead == NULL || p == NULL || q == NULL || p == q || p->pNext == q) {
        return; // Danh sách rỗng hoặc p, q không hợp lệ
    }

    if (L.pHead == p) {
        L.pHead = q->pNext;
        while (p != q) {
            Node* temp = p->pNext;
            free(p);
            p = temp;
        }
        free(p);
        return;
    }

    Node* prev = L.pHead;
    while (prev->pNext != p) {
        prev = prev->pNext;
    }
    prev->pNext = q->pNext;
    while (p != q) {
        Node* temp = p->pNext;
        free(p);
        p = temp;
    }
    free(p);
}
int main() {
    List L;
    int chon;
    Node *p;
    khoiTao(L);
    nhapList(L);
    xuatList(L);
    while(true) {
	printf("\n----------------MENU--------------\n");
    printf("1. Them phan tu vao dau danh sach\n");
    printf("2. Xuat danh sach\n");
    printf("3. Xuat cac phan tu chan\n");
    printf("4. Tinh tong cac phan tu chan\n");
    printf("5. Tim phan tu lon nhat\n");
    printf("6. Dem so luong so nguyen to\n");
    printf("7. Xoa phan tu nho nhat\n");
	printf("8. Nhap vao phan tu X, xoa phan tu dung truoc va dung sau phan tu X.\n");
    printf("9. Thoat\n");
    do {
		printf("\nNhap vao lua chon: ");
		scanf("%d", &chon);

		switch(chon) {
			case 1 :
				int a;
				printf("\nNhap phan tu can them: ");
				scanf("%d", &a);
				getNode(a);
				themDau(L,p);
				break;
			case 2: 
				xuatList(L);
				break;
			case 3:
				xuatChan(L);
				break;
			case 4:
				printf("\nTong cac phan tu chan: %d", tongChan(L));
				break;
			case 5: 
				p = timMax(L);
				printf("\nMax trong danh sach: %d", p->Data);
				break;
			case 6: 
				printf("\nSo luong SNT trong danh sach: %d", demSNT(L));
				break;
			case 7: 
				xoaMin(L);
				printf("\nDanh sach sau xoa min: ");
				xuatList(L);
				break;
			case 8:
				int x;
				printf("\nNhap vao phan tu X: ");
				scanf("%d", &x);
				p = timX(L,x);
				if(p == NULL ) {
					printf("\nKhong tim thay phan tu trong danh sach.");
				}else {
					Node* k = p->pNext;
					Node* q = p->pNext->pNext;
					XoakTruocp(L,p,k);
					XoakSaup(L,p,q);
					printf("\nDa xoa cac phan tu truoc va sau gia tri X.");
				}
				printf("\nDanh sach sau khi xoa: ");
				xuatList(L);
				break;
			case 9:
				printf("\nKet thuc chuong trinh.");
				break;
			default:
				printf("\nLua chon khong hop le.");
				break;
			}
	}while(chon<1||chon >9);
	};
}