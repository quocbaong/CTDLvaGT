/*
    Để quản lý thống kê số lượng của mỗi kí tự xuất hiện trong một văn bản tiếng Anh. Người
ta đã tổ chức dữ liệu bằng cây nhị phân tìm kiếm. Thông tin của mỗi từ gồm có: kí tự (KiTu),
số lượng (SoLuong). Anh/chị hãy viết chương trình thực hiện các công việc sau:
1. Khai báo cấu trúc biểu diễn cây nhị phân tìm kiếm để lưu trữ thông tin của kí tự
2. Hàm Khởi tạo nút Node* TaoNode(char X).
3. Hàm thêm node Void ThemNode(Node* p, Tree &c).
4. Hãy viết hàm thực hiện thêm một kí tự X vào cây ( X là tham số của hàm). Biết rằng: nếu
X đã có trên cây thì tăng số lượng (SoLuong) của kí tự này lên 1 đơn vị, ngược lại: thì
tạo node mới chứa kí tự X và chèn node vào cây để cây kết quả là cây nhị phân tìm kiếm.
5. Hàm nhập void Nhap(Tree &c).
6. Liệt kê các kí tự trên cây theo thứ tự trước, giữa, sau
7. Viết hàm trả số lượng kí tự X trên cây có node gốc T. Nếu không có kí tự X thì hàm trả
về 0.
8. Đếm số nút lá của cây.
9. Đếm số nút có đúng 2 cây con.
10.Đếm số nút có đúng 1 cây con.
11.Liệt kê các kí tự nguyên âm
12. Xóa nút có kí tự x
*/

struct Node {
  char KiTu;
  int SoLuong;
  struct Node *pLeft, *pRight;
};

struct Tree {
  struct Node *pRoot;
};
struct Node* TaoNode(char X) {
  struct Node *pNew = (struct Node *)malloc(sizeof(struct Node));
  pNew->KiTu = X;
  pNew->SoLuong = 1;
  pNew->pLeft = NULL;
  pNew->pRight = NULL;
  return pNew;
}
void ThemNode(struct Node *p, struct Tree &c) {
  if (c.pRoot == NULL) {
    c.pRoot = p;
  } else {
    if (p->KiTu < c.pRoot->KiTu) {
      ThemNode(p, c.pRoot->pLeft);
    } else {
      ThemNode(p, c.pRoot->pRight);
    }
  }
}
void ThemKiTu(struct Tree &c, char X) {
  struct Node *p = TaoNode(X);
  ThemNode(p, c);
}
void Nhap(struct Tree &c) {
  char X;
  while (true) {
    printf("Nhập kí tự (xuống dòng để kết thúc): ");
    scanf("%c", &X);
    if (X == '\n') {
      break;
    }
    ThemKiTu(c, X);
  }
}
void DuyetTruoc(struct Node *p) {
  if (p != NULL) {
    printf("%c ", p->KiTu);
    DuyetTruoc(p->pLeft);
  }
}

void DuyetGiua(struct Node *p) {
  if (p != NULL) {
    DuyetGiua(p->pLeft);
    printf("%c ", p->KiTu);
  }
}

void DuyetSau(struct Node *p) {
  if (p != NULL) {
    DuyetSau(p->pLeft);
    DuyetSau(p->pRight);
    printf("%c ", p->KiTu);
  }
}

void Xuat(struct Tree c) {
  printf("Duyệt trước: ");
  DuyetTruoc(c.pRoot);
  printf("\n");
  printf("Duyệt giữa: ");
  DuyetGiua(c.pRoot);
  printf("\n");
  printf("Duyệt sau: ");
  DuyetSau(c.pRoot);
  printf("\n");
}
int DemKiTu(struct Tree c, char X) {
  struct Node *p = TimKiem(c.pRoot, X);
  if (p == NULL) {
    return 0;
  }
  return p->SoLuong;
}
int DemNutLa(struct Node *p) {
  if (p == NULL) {
    return 0;
  }
  if (p->pLeft == NULL && p->pRight == NULL) {
    return 1;
  }
  return DemNutLa(p->pLeft) + DemNutLa(p->pRight);
}

int DemNutLa(struct Tree c) {
  return DemNutLa(c
int DemNut2Con(struct Node *p) {
  if (p == NULL) {
    return 0;
  }
  if (p->pLeft != NULL && p->pRight != NULL) {
    return 1 + DemNut2Con(p->pLeft) + DemNut2Con(p->pRight);
  }
  return DemNut2Con(p->pLeft) + DemNut2Con(p->pRight);
}

int DemNut2Con(struct Tree c) {
  return DemNut2Con(c.pRoot);
}
int DemNut1Con(struct Node *p) {
  if (p == NULL) {
    return 0;
  }
  if (p->pLeft != NULL || p->pRight != NULL) {
    return 1 + DemNut1Con(p->pLeft) + DemNut1Con(p->pRight);
  }
  return 0;
}

int DemNut1Con(struct Tree c) {
  return DemNut1Con(c.pRoot);
}
void LietKeNguyenAm(struct Node *p) {
  if (p == NULL) {
    return;
  }
  if (p->KiTu == 'a' || p->KiTu == 'e' || p->KiTu == 'i' || p->KiTu == 'o' || p->KiTu == 'u') {
    printf("%c ", p->KiTu);
  }
  LietKeNguyenAm(p->pLeft);
  LietKeNguyenAm(p->pRight);
}

void LietKeNguyenAm(struct Tree c) {
  LietKeNguyenAm(
void XoaNut(struct Node *p, char x) {
  if (p == NULL) {
    return;
  }
  if (p->KiTu == x) {
    if (p->pLeft == NULL && p->pRight == NULL) {
      // Nút lá
      free(p);
      p = NULL;
    } else if (p->pLeft != NULL && p->pRight != NULL) {
      // Nút có 2 cây con
      struct Node *min = TimNutMin(p->pRight);
      // Chuyển giá trị của nút min sang nút cần xóa
      p->KiTu = min->KiTu;
      p->SoLuong = min->SoLuong;
      // Xóa nút min
      XoaNut(p->pRight, min->KiTu);
    } else {
      // Nút có 1 cây con
      struct Node *pSub = p->pLeft ? p->pLeft : p->pRight;
      // Thay thế nút cần xóa bằng nút con của nó
      *p = *pSub;
      // Xóa nút con
      free(pSub);
      pSub = NULL;
    }
  } else {
    if (x < p->KiTu) {
      XoaNut(p->pLeft, x);
    } else {
      XoaNut(p->pRight, x);
    }
  }
}

void XoaNut(struct Tree c, char x) {
  XoaNut(c.pRoot, x);
}
