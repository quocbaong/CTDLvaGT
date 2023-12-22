//Bai4 
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

struct WORD{
    char Name[256];
    char Meaning[512];
};
void ReadData(WORD W[100], char fname[]) 
{
    FILE *f;
    f = fopen(fname, "r");
    if(f == NULL) {
        exit(1);
    }
    
    int i = 0;
	while(!feof(f)) {
		fscanf(f, "%255[^,],%511[^\n]\n", W[i].Name, W[i].Meaning);
		i++;
	}
    fclose(f);
}

int BinarySearch(WORD W[], int left, int right, const char name[]) {
    while(left <= right) {
        int mid = (left+right)/2;
        int cmp = strcmp(W[mid].Name, name);
        if(cmp == 0) {
            return mid;
            break;
        }
        else if(cmp < 0)
            left = mid + 1;
        else
            right = mid -1;
    }
    return -1;
}

//bai 5
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

struct WORD{
    char Name[256];
    char Meaning[512];
};
void ReadData(WORD W[100], char fname[]) 
{
    FILE *f;
    f = fopen(fname, "r");
    if(f == NULL) {
        exit(1);
    }
    
    int i = 0;
	while(!feof(f)) {
		fscanf(f, "%255[^,],%511[^\n]\n", W[i].Name, W[i].Meaning);
		i++;
	}
    fclose(f);
}
int BinarySearchNoRecursion(WORD W[], int n, const char name[]) {
    int find = -1, left = 0, right = n-1;
    while(left <= right) {
        int mid = (left+right)/2;
        int cmp = strcmp(W[mid].Name, name);
        if(cmp == 0) {
            find = mid;
            break;
        }
        else if(cmp < 0)
            left = mid + 1;
        else
            right = mid -1;
    }
    (find != -1)?(printf("%s", W[find].Meaning)):(printf("Not found"));
    return find;
}
//Bai 3
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}
#include<stdio.h>
#include<time.h>

int LinearSearch(int A[], int n, int k) 
{
    for(int i = 0; i < n; i++) {
        if (A[i] == k) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int A[], int left, int right, int k)
{
    if(left<=right) {
        int mid = (left+right)/2;
        if(k == A[mid])
            return mid;
        else if(k<A[mid])
            return BinarySearch(A, left, mid-1, k);
        else 
            return BinarySearch(A, mid+1, right, k);
    }
    return -1;
}

void CompareLinearBinarySearch(int A[], int n, int k) 
{

    clock_t starttt, endtt, startnp, endnp;
    float thoiGianTT, thoiGianNP;
    int kqTT, kqNP;
    starttt = clock();
    kqTT = LinearSearch(A, n, k);
    endtt = clock();
    
    startnp = clock();
    kqNP = BinarySearch(A, 0, n-1, k);
    endnp = clock();
    thoiGianTT = (endtt - starttt)/CLOCKS_PER_SEC;
    thoiGianNP = (endnp - startnp)/CLOCKS_PER_SEC;
    printf("%d\n", kqTT);
    printf("%d\n", kqNP);
    

    if(thoiGianTT < thoiGianNP) 
            printf("Linear faster than Binary");
    else if(thoiGianTT > thoiGianNP)
            printf("Binary faster than Linear");
    else 
            printf("Linear equal to Binary");
}