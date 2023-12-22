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
};
//Khai bao nguyen mau ham
void createList(List &L);
void addFrist(List &L, Node *p);
Node* createNode(int x);
void nhapList(List &L);
void printfList(List L);
void xuatChan(List L);
int tongChan(List L);
Node *timMax(List L);
bool laSNT(int x);
int demSNT(List L);
Node *timMin(List L);
void xoaDau(List &L);
void xoaCuoi(List &L);
void xoaP(List &L, Node* p);
void xoaMin(List &L);
Node *timX(List L, int X);
void xoakTruocp(List &L, Node *p, Node *k) ;
void xoakSaup(List &L, Node *p, Node *q);
//Khai bao dinh nghia ham
void createList(List &L) {
	L.pHead = NULL;
}
//1. Them 1 node vao dau danh sach
void addFrist(List &L, Node* p) {
	if(L.pHead == NULL) 
		L.pHead = p;
	else {
		p->pNext = L.pHead;
		L.pHead = p;
	}
}
Node* createNode(int x) {
	Node *p = (Node*)malloc(sizeof(Node));
	if(p == NULL)
		printf("Khong du bo nho");
	else {
		p->Data = x;
		p->pNext = NULL;
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
		p = createNode(x);
		addFrist(L, p);
	}while(true);
}
//2. Xuat cac phan tu cua List
void printfList(List L) {
	Node *p = L.pHead;
	while(p!= NULL) {
		printf("%d ", p->Data);
		p = p->pNext;
	}
}
//3. Liet ke cac phan tu chan
void xuatChan(List L) {
	Node *p = L.pHead;
	while(p!=NULL) {
		if(p->Data % 2 == 0) 
		printf("%d ", p->Data);
		p = p -> pNext;
	}
}
//4. Tinh tong cac phan tu mang gia tri chan
int tongChan(List L) {
	Node *p = L.pHead;
	int sum = 0;
	while(p != NULL) {
		if(p->Data %2 == 0) 
			sum = sum + p->Data;
		p = p->pNext;
	}
	return sum;
}
//5.Tim phan tu co gia tri lon nhat
Node *timMax(List L) {
	Node *max = L.pHead;
	for(Node *p = L.pHead->pNext; p!=NULL; p = p->pNext) {
		if(max->Data < p->Data)
			max = p;
	}
	return max;
}
//6.Dem so luong SNT trong danh sach
bool laSNT(int x) {
	if(x<2) 
		return false;
	for(int i = 2; i*i <=x; i++) {
		if(x%i==0)
			return false;
	}
	return true;
}
int demSNT(List L) {
	int dem=0;
	Node *p = L.pHead;
	while(p!= NULL) {
		if(laSNT(p->Data) == true) {
			dem++;
		}
		p = p->pNext;
	}
	return dem;
}
//7.Xoa phan tu nho nhat trong danh sach
Node *timMin(List L) {
	Node *min = L.pHead;
	for(Node *p = L.pHead->pNext; p!=NULL; p = p->pNext) {
		if(min->Data > p->Data)
			min = p;
	}
	return min;
}
void xoaDau(List &L) 
{
	if(L.pHead != NULL) {
		Node* p = L.pHead;
		L.pHead = p->pNext;
		free(p);
	}
}
void xoaCuoi(List &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) {
        xoaDau(L);
        return;
    }
    Node* p = L.pHead;
    while (p->pNext->pNext != NULL) {
        p = p->pNext;
    }
    free(p->pNext);
    p->pNext = NULL;
}
void xoaP(List &L, Node* p) {
    if (L.pHead == NULL) {
        return;
    }
    if (L.pHead == p) {
        xoaDau(L);
        return;
    }
    Node* q = L.pHead;
    while (q->pNext != NULL && q->pNext != p) {
        q = q->pNext;
    }
    if (q->pNext == p) {
        q->pNext = p->pNext;
        free(p);
    }
}
//Ham xoa min
void xoaMin(List &L) {
    Node* min = timMin(L);
    xoaP(L, min);
}
//Ham tim Node X
Node *timX(List L, int x)
{
	Node *p = L.pHead;
	while(p!=NULL) {
		if(p->Data == x) 
			return p;
		p = p->pNext;
	}
	return NULL;
}
void xoakTruocp(List &L, Node *p, Node *k) 
{
	if (L.pHead == NULL || p == NULL || p == L.pHead) {
        return; // Không có gì d? xóa
    }
    if (k == NULL || k == L.pHead) {
        L.pHead = p; // Xóa t?t c? các NODE d?ng tru?c NODE p
        while (L.pHead != p) {
            Node *tmp = L.pHead;
            L.pHead = L.pHead->pNext;
            free(tmp);
        }
        return;
    }
    Node* q = k;
    while (q->pNext != p) {
        q = q->pNext;
    }
    q->pNext = p;
    while (k != p) {
        Node* tmp = k;
        k = k->pNext;
        free(tmp);
    }
}
void xoakSaup(List &L, Node *p, Node *q) {
    if (L.pHead == NULL || p == NULL || q == NULL) {
        return; // Không có gì d? xóa
    }
    p->pNext = q->pNext;
    while (q != NULL) {
        Node* tmp = q;
        q = q->pNext;
        free(tmp);
    }
}
int main() {
	List L;
	Node *p;
	int chon;
	createList(L);
	nhapList(L);
	printfList(L);
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
				createNode(a);
				addFrist(L,p);
				break;
			case 2: 
				printfList(L);
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
				printfList(L);
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
					xoakTruocp(L,p,k);
					xoakSaup(L,p,q);
					printf("\nDa xoa cac phan tu truoc va sau gia tri X.");
					printfList(L);
				}
				printf("\nDanh sach sau khi xoa: ");
				printfList(L);
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
	return 0;
}
