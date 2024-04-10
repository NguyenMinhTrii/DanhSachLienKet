#include <iostream>
using namespace std;

//Khai báo cấu trúc 1 node
struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE ;

//Khai báo cấu trúc của một danh sách
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;


//Khởi tạo cấu trúc danh sách liên kết đơn
void KhoiTaoDSLK(LIST &l)
{
    //Khai báo cho 2 node đầu và cuối trỏ tới vùng nhớ rỗng
    l.pHead = NULL;
    l.pTail = NULL;
}

//Hàm khỏi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
    NODE *p = new NODE;
    if ( p == NULL)
    {
        cout <<"Bo nho da het ! ";
        return NULL;
    }
    p -> data = x; // gán x cho data
    p -> pNext = NULL;
    return p;
}

//Hàm thêm node p vào đầu danh sách
void ThemVaoDau(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }    
    else
    {
        p -> pNext = l.pHead ;// dùng con trỏ của node p liên kết và l.pHead
        l.pHead = p; // cập nhật lại node đầu là p
    }


}
//Hàm thêm node p vào cuối danh sách
void ThemVaoCuoi(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail -> pNext = p ;// dùng con trỏ của node p liên kết và l.pTail
        l.pTail = p; // cập nhật lại node cuối là p
    }
}

void XuatDanhSach(LIST l)
{
    //for (int i = 0 ; i < n ; i++)
    for (NODE *k = l.pHead ;k != NULL ; k = k -> pNext )
    {
        cout << k-> data <<" " ;
    }
}

//Hàm tim Max
int TimMax(LIST l)
{
    int max = l.pHead -> data;
    for (NODE *k = l.pHead ->pNext ; k != NULL ; k = k -> pNext)
    {
        if (max < k -> data)
            max = k ->data ;
    }
    return max;
}


void ThemNode_p_VaoSauNode_q(LIST &l , NODE *p)
{
    //Khởi tạo node q
    int x;
    cout <<"Nhap gia tri node q : ";
    cin >>  x ;
    NODE *q = KhoiTaoNode(x);

    if (q ->data == l.pHead -> data && l.pHead -> pNext == NULL)
    {
        ThemVaoCuoi(l,p);
    }
    else
    {
        for (NODE *k = l.pHead ; k != NULL ; k = k ->pNext)
        {
            //Nếu q có tồn tại
            if ( q -> data == k ->data)
            {
                NODE *h = KhoiTaoNode(p -> data);//Khởi tạo node h để thêm vào sau node q
                NODE *g = k ->pNext;    // Cho node g trỏ tới node nằm sau q
                h ->pNext = g;
                k ->pNext = h;
            }
        }
    }

}


void ThemNode_p_VaotruocNode_q(LIST &l, NODE *p)
{
    int x;
    cout <<"Nhap gia tri node q : ";
    cin >> x;
    NODE *q = KhoiTaoNode(x);
    
    if (q ->data == l.pHead ->data && l.pHead ->pNext == NULL)
    {
        ThemVaoDau(l,p);
    }
    else
    {
        for (NODE *k = l.pHead ; k != NULL ; k = k->pNext)
        {
            if (q ->data == p ->data)
            {
                
            }
        }
    }
}

void Menu(LIST &l)
{
    int luachon;
    while(1)
    {
        system("cls");
        cout <<"\n\t1. Them node vao danh sach";
        cout <<"\n\t2. Xuat danh sach lien ket don";
        cout <<"\n\t3. Them node p vao sau node q trong danh sach";

        cout <<"\nNhap lua chon : ";
        cin >> luachon;

        if (luachon < 1 || luachon > 3 )
        {

            cout <<"Lua chon khong hop le !";
            system("pause");
        }
        else if (luachon == 1)
        {
            int x;
            cout <<"Nhap gia tri so nguyen : ";
            cin >> x;
            NODE *p = KhoiTaoNode(x);
            ThemVaoCuoi(l,p);

        }
        else if (luachon == 2)
        {
            XuatDanhSach(l);
            system("pause");
        }
        else if (luachon == 3)
        {
            int x;
            cout <<"Nhap gia tri node can them : ";
            cin >> x;
            NODE *p = KhoiTaoNode(x);
            ThemNode_p_VaoSauNode_q(l,p);
        }
       
    }
}

int main()
{
    LIST l;
    KhoiTaoDSLK(l);
    Menu(l);

    /*int n;
    cout <<"Nhap so luong node : " ;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int x;
        cout <<"Nhap gia tri cua node " ;
        cin >> x;
        NODE *p = KhoiTaoNode(x);
        ThemVaoCuoi(l,p);

    }
    cout <<"Danh sach lien ket don : " ;
    XuatDanhSach(l);
    cout << endl;/*

    /**cout <<"Gia tri lon nhat : " << TimMax(l);
    int x;
    NODE *p = KhoiTaoNode(x);
    ThemNode_p_VaoSauNode_q(l,p);*/
    
    
    return 0;
}