#include<stdio.h>
#include<stdio.h>
//khai bao Node
struct Node{
	int data;
	Node* pNext;
};
struct List {
	Node *pHead;
	Node *pTail;
};
//ham tao list rong
void Init(List &L){
	L.pHead=L.pTail=NULL;
}
//ham tao Node
Node *createNode(int x){
	Node *p = (Node*)malloc(sizeof(Node));
	if(p==NULL){
		printf("Khong du bo nho");
		return NULL;
	}
	p->data=x;
	p->pNext=NULL;
	free(p);
	return p;
}
//
void InsertFirst(List &L, int x)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Khong du bo nho cap phat.");
        return;
    }
    p->data = x;
    p->pNext = NULL;
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
//
void InsertFirst(List &L, int x)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("Khong du bo nho cap phat.");
        return;
    }
    p->data = x;
    p->pNext = NULL;
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else {
        p->pNext = L.pHead;
        L.pHead = p;
    }
}
//ham khoi tao danh sach lien ket don
void createList(List &L, int n){
	int x;
	Node *p;
	L.pHead=L.pTail=NULL;
	for(int i=0; i<n; i++){
		printf("\nNhap vao phan tu %d trong dslk",i);
		scanf("%d",&x);
		p=createNode(x);
		if(p!=NULL){
			printf("\nKhong du bo nho");
			return;
		} else if(L.pHead==NULL){
			L.pHead=L.pTail=p;
		} else {
			L.pTail->pNext=p;
			L.pTail=p;
		}
	}
}
//ham gan Node vao dau danh sach
void addHead(List &L, Node *p){
	if(L.pHead==NULL)
		L.pHead=L.pTail=p;
	else {
		p->pNext=L.pHead;
		L.pHead=p;
	} 
}
//ham gan Node vao cuoi danh sach
void addTail(List &L, Node *p){
	if(L.pTail==NULL)
		L.pTail=L.pHead=p;
	else { 
		L.pTail->pNext=p;
		L.pTail=p;
	}
}
//ham xoa node dau danh sach
int removeHead(List &L){
	if(L.pHead==NULL) {
		return 0;
	}
	Node* p=L.pHead;
	L.pHead=p->pNext;
	p->pNext=NULL;
	delete p;
	return 1;
}
//ham xoa node cuoi danh sach
int removeTail(List &L){
	if(L.pHead==NULL){
		return 0;
	}
	Node* p=L.pHead;
	while(p->pNext!=L.pTail){
		p=p->pNext;
	p->pNext=NULL;
	L.pTail=p;
	delete L.pTail;
	return 1;
	}
}
//them mot phan tu sau q
void addAfter(List &L, Node *q, Node *p){
	if(q!=NULL && p!=NULL){
		p->pNext=q->pNext;
		q->pNext=p;
		if(q==L.pTail)
			L.pTail=p;
	}
}
//xoa mot phan tu sau q
int removeAfter(List &L, Node *q){
	if(q!=NULL && q->pNext!=NULL){
		Node* p=q->pNext;
		q->pNext=p->pNext;
		if(p==L.pTail)
			L.pTail=q;
		delete p;
		return 1;
	} else return o;
}
//them mot phan tu truoc q
void addBefore(List &L, Node* q, Node* p){
	if(q!=NULL){
		if(q==L.pHead){
			addHead(L,p);
			return;
		}
		Node* p=L.pHead;
		while (p->pNext!=q){
			p=p->pNext;
		}
		addAfter(L,q,p);
	}
}
//xoa mot phan tu truoc q
void removeBefore(List &L,int x){
	if(L.pHead->data==x)
		return ;
	Node* q=L.pHead;
	if(q->pNext->data){
		removeHead(s);
		return;
	}
		
	Node* p=q->pNext->pNext;
	while (p->pNext!=NULL){
		if(p->data==x);
			break;
		q=q->pNext;
		p=p->pNext;
	}
	if(p==NULL)
		return;
	if(p!=NULL){
		q->pNext->pNext=NULL;
		delete q->pNext;
		q->pNext=p;
	}
}
//ham xuat node 
void printList(List L){
	Node *p;
	for(p=L.pHead; p!=NULL; p=p->pNext){
		printf("%d\n",p->data);
	}
}
//ham xoa node
void deleteNode(Node *p){
	if(p==NULL)
		return;
	p->pNext=NULL;
	delete p;
}
//tim kiem mot phan tu co khoa x WHILE
Node* search(List L, int x){
	Node* p=L.pHead;
	while(p!=NULL){
		if(p->data==x)
			return p;
		p=p->pNext;
	}
	return NULL;
}
//tim kiem mot phan tu co khoa x FOR
Node* search(List L, int x){
	Node* p=L.pHead;
	for(p; p!=NULL; p=p->pNext){
		if(p->data==x)
			return p;
	}
	return NULL;
}
//them mot thanh phan du lieu vao dau
void Insertfirst(List &L, int x){
	Node* p=createNode(x);
	if(p==NULL)
		return;
	else 
		addHead(L,p);
}
//them mot thanh phan du lieu vao cuoi
void Insertlast(List &L, int x){
	Node* p=createNode(x);
	if(p==NULL)
		return;
	else 
		addTail(L,p);
}
//xoa toan bo danh sach
void removeList(List *L){
	Node *p;
	while(L.pHead!=NULL){
		p=L.pHead;
		L.pHead=p->pNext;
		delete p;
	}
	L.pTail=NULL;
}
//dem so nut trong danh sach
int CountNode(List L){
	int count=0;
	Node *p=L.pHead;
	while(p!=NULL){
		count++;
		p=p->pNext;
	}
	return count;
}
//sap xep tang trong dslk
void interChangeSortList(List L){
	for(Node *p=L.pHead; p!=L.pTail; p=p->pNext){
		for(Node *q=p->pNext; q!=NULL; q=q->pNext){
			if(p->pNext > q->data){
				Node *temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}
//tim min
Node *findMin(List L){
	if(L.pHead==NULL)
		return NULL;
	Node *min=L.pHead;
	Node *p=L.pHead->pNext;
	while(p!=NULL){
		if(p->data < min->data)
			min=p;
		p=p->pNext;
	}
	return min
}
//tim max
Node *findMax(List L) {
    if (L.pHead == NULL)
        return NULL;
    Node *max = L.pHead;
    Node *p = L.pHead->pNext;
    while (p != NULL) {
        if (p->data > max->data)
            max = p;
        p = p->pNext;
    }
    return max;
}
//timkiem tra ve -1, va 1
int SearchKey(List L, int x) {
    Node* p = L.pHead;
    while (p != NULL) {
        if (p->data == x)
            return 1;  
        p = p->pNext;
    }
    return -1; 
}

//H�m AppendList c� c�c tham so dau v�o l� danh s�ch li�n ket, mang phan tu v� kich thuoc cua mang.
//H�m ch�n tung phan tu v�o mang bang c�ch th�m ch�ng v�o cuoi danh s�ch li�n k?t.
void AppendList( List &L, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        Node* p = (Node*)malloc(sizeof( Node));
        p->data = arr[i];
        p->pNext = NULL;
        if (L.pHead == NULL) {
            L.pHead = L.pTail = p;     
        } else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}
//H�m CountKLinkedList dem c�c phan tu trong danh s�ch li�n ket c� gi� tra k v� tri ve ket qua
int CountKLinkedList( List &L, int k) {
    int count = 0;
    Node* current = L.pHead;
    while (current != NULL) {
        if (current->data == k) {
            count++;
        }
        current = current->pNext;
    }
    return count;
}
//H�m SumLinkedList t�nh tong tat ca c�c phan tu trong danh s�ch li�n ket v� tra ve ket qua
int SumLinkedList (List &L) {
    int sum = 0;
    struct Node* current = L.pHead;
    while (current != NULL) {
        sum += current->data;
        current = current->pNext;
    }
    return sum;
}

