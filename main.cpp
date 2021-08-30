#include <iostream>
using namespace std;
struct node
{
	int data;
	node* pLeft;
	node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoTree(TREE &t)
{
	t = NULL;
}
void ThemNodeVaoCay(TREE& t, int x)
{
	if (t == NULL)
	{
		node* p = new node;
		p->data = x;
		p->pLeft = p->pRight = NULL;
		t = p;
	}
	else
	{
		if (x < t->data)
			ThemNodeVaoCay(t->pLeft, x);
		else if (x > t->data)
			ThemNodeVaoCay(t->pRight, x);
	}
}
void NLR(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";// xuat node (gia tri cua node)
		NLR(t->pLeft);// duyet left
		NLR(t->pRight);//duyet right
	}
}
void NRL(TREE t)
{
	if (t != NULL)
	{
		cout << t->data << " ";
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}
void	LNR(TREE t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data << " ";
		LNR(t->pRight);
	}
}
void	RNL(TREE t)
{
	if (t != NULL)
	{
		RNL(t->pRight);
		cout << t->data << " ";
		RNL(t->pLeft);
	}
}
void	LRN(TREE t)
{
	if (t != NULL)
	{
		LRN(t->pLeft);
		LRN(t->pRight);
		cout << t->data << " ";
	}
}
void	RLN(TREE t)
{
	if (t != NULL)
	{
		RLN(t->pRight);
		RLN(t->pLeft);
		cout << t->data << " ";
	}
}
bool TimKiem(TREE t, int x)
{
	if (t == NULL)
		return false;
	else
	{
		if (x < t->data)
			TimKiem(t->pLeft, x);
		else if (x > t->data)
			TimKiem(t->pRight, x);
		else
			return true;
	}
}
void TimNodeTheMang(TREE& p, TREE& pTM)
{
	if (pTM->pRight != NULL)
		TimNodeTheMang(p, pTM->pRight);
	else
	{
		p->data = pTM->data;
		p = pTM;
		pTM = pTM->pLeft;
	}
}
bool XoaNode(TREE& t, int x)
{
	if (t != NULL)
	{
		if (x < t->data)
			XoaNode(t->pLeft, x);
		else if (x > t->data)
			XoaNode(t->pRight, x);
		else
		{
			NODE* p = t;
			if (t->pLeft == NULL)
				t = t->pRight;
			else if (t->pRight == NULL)
				t = t->pLeft;
			else
				TimNodeTheMang(p, p->pLeft);
			delete p;
			return true;
		}
	}
	else return false;
}
int DemSoNode(TREE t)
{
	if (t == NULL)
		return 0;
	int NNL = DemSoNode(t->pLeft);
	int NNR = DemSoNode(t->pRight);
	return 1 + NNL + NNR;
}
int DemSoNodeCoHaiCayCon(TREE t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->pLeft != NULL && t->pRight != NULL)
			return 1 + DemSoNodeCoHaiCayCon(t->pLeft) + DemSoNodeCoHaiCayCon(t->pRight);
		else
			return DemSoNodeCoHaiCayCon(t->pLeft) + DemSoNodeCoHaiCayCon(t->pRight);
	}
}
int DemSoNodeCoMotCayCon(TREE t)
{
	if (t == NULL)
		return 0;
	else
	{
		if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
			return 1 + DemSoNodeCoMotCayCon(t->pLeft) + DemSoNodeCoMotCayCon(t->pRight);
		else
			return DemSoNodeCoMotCayCon(t->pLeft) + DemSoNodeCoMotCayCon(t->pRight);
	}
}
int DemSoNodeCoMotCayConPhai(TREE t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->pLeft == NULL && t->pRight != NULL)
			return 1 + DemSoNodeCoMotCayConPhai(t->pLeft) + DemSoNodeCoMotCayConPhai(t->pRight);
		else 
			return DemSoNodeCoMotCayConPhai(t->pLeft) + DemSoNodeCoMotCayConPhai(t->pRight);
	}
}
int DemSoNodeLa(TREE t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->pLeft == NULL && t->pRight == NULL)
			return 1 + DemSoNodeLa(t->pLeft) + DemSoNodeLa(t->pRight);
		else
			return DemSoNodeLa(t->pLeft) + DemSoNodeLa(t->pRight);
	}
}
int ChieuCaoCay(TREE t)
{
	if (t == NULL)
		return 0;
	else
	{
		return 1 + max(ChieuCaoCay(t->pLeft), ChieuCaoCay(t->pRight));
	}
}
void InNodeChan(TREE t)
{
	if (t != NULL)
	{
		if ((t->data) % 2 == 0)
			cout << t->data << " ";
		InNodeChan(t->pLeft);
		InNodeChan(t->pRight);
	}
}
int DemNodeLonHonX(TREE t,int x)
{
	if (t == NULL)
		return 0;
	else
	{
		if ((t->data) > x)
			return 1 + DemNodeLonHonX(t->pLeft, x) + DemNodeLonHonX(t->pRight, x);
		else
			return DemNodeLonHonX(t->pLeft, x) + DemNodeLonHonX(t->pRight, x);
	}
}
int TimMax(TREE t)
{
	if (t->pRight == NULL)
		return t->data;
	return TimMax(t->pRight);
}
int TimMin(TREE t)
{
	if (t->pLeft == NULL)
		return t->data;
	return TimMin(t->pLeft);
}
int DoDaiDuongDi(TREE t, int x) {
	if (t == NULL || t->data == x) {
		return 0;
	}
	else 
	{
		if (t->data > x) {
			return 1 + DoDaiDuongDi(t->pLeft,x);
		}
		return 1 + DoDaiDuongDi(t->pRight,x);
	}
}
bool SNT(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
void DeleteAllNodeIsPrime(TREE& t)
{
	if (t != NULL)
	{
		if (SNT(t->data))
		{
			XoaNode(t, t->data);
		}
		DeleteAllNodeIsPrime(t->pLeft);
		DeleteAllNodeIsPrime(t->pRight);
	}
}
void menu(TREE& t)
{
	while (true)
	{
		system("cls");
		cout << "\n\t\t==========MENU==========";
		cout << "\n\t1. Nhap du lieu";
		cout << "\n\t2. Xuat NLR";
		cout << "\n\t3. Xuat NRL";
		cout << "\n\t4. Xuat LNR";// xuat cac gia tri tu be den lon
		cout << "\n\t5. Xuat RNL";//xuat cac gia tri tu lon den be
		cout << "\n\t6. Xuat LRN";
		cout << "\n\t7. Xuat RLN";
		cout << "\n\t8. Tim kiem node co khoa la x ";
		cout << "\n\t9. Xoa node co khoa la x ";
		cout << "\n\t10. Dem tong so node trong cay";
		cout << "\n\t11. Dem tong so node co 2 cay con";
		cout << "\n\t12. Dem tong so node co 1 cay con";
		cout << "\n\t13. Dem tong so node co 1 cay con phai";
		cout << "\n\t14. Dem tong so node la";
		cout << "\n\t15. Chieu cao cua cay ";
		cout << "\n\t16. In node co gia tri chan ";
		cout << "\n\t17. Dem so node co gia tri lon hon x ";
		cout << "\n\t18. Tim node co gia tri lon nhat";
		cout << "\n\t19. Tim node co gia tri nho nhat";
		cout << "\n\t20. Do dai duong di tu root den node co gia tri x ";
		cout << "\n\t21.Xoa all prime";

		cout << "\n\t0. Ket thuc";
		int lc;
		cout << "\nNhap lua chon : ";
		cin >> lc;
		if (lc == 1)
		{
			int x;
			cout << "\nNhap gia tri x = ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (lc == 2)
		{
			cout << "duyet cay nhi phan theo NLR : ";
			NLR(t);
			system("pause");
		}
		else if (lc == 3)
		{
			cout << "duyet cay nhi phan theo NRL : ";
			NRL(t);
			system("pause");
		}
		else if (lc == 4)
		{
			cout << "duyet cay nhi phan theo LNR : ";
			LNR(t);
			system("pause");
		}
		else if (lc == 5)
		{
			cout << "duyet cay nhi phan theo RNL : ";
			RNL(t);
			system("pause");
		}
		else if (lc == 6)
		{
			cout << "duyet cay nhi phan theo LRN : ";
			LRN(t);
			system("pause");
		}
		else if (lc == 7)
		{
			cout << "duyet cay nhi phan theo RLN : ";
			RLN(t);
			system("pause");
		}
		else if (lc == 8)
		{
			int x;
			cout << "\nTim kiem node co khoa la x \n";
			cout << "\nNhap khoa x = ";
			cin >> x;
			if (TimKiem(t, x))
				cout << "\nCO";
			else
				cout << "KHONG TIM DUOC\n";
			system("pause");
		}
		else if (lc == 9)
		{
			int x;
			cout << "\nXoa node co khoa la x \n";
			cout << "\nNhap khoa x = ";
			cin >> x;
			if (XoaNode(t,x))
				cout << "\nXoa thanh cong\n";
			else
				cout << "\nXoa khong thanh cong";
			system("pause");
		}
		else if (lc == 10)
		{
			cout << "\nTong so node trong cay : " << DemSoNode(t)<<endl;
			system("pause");
		}
		else if (lc == 11)
		{
			cout << "\nTong so node co 2 cay con : " << DemSoNodeCoHaiCayCon(t) << endl;
			system("pause");
		}
		else if (lc == 12)
		{
			cout << "\nTong so node co 1 cay con : " << DemSoNodeCoMotCayCon(t) << endl;
			system("pause");
		}
		else if (lc == 13)
		{
			cout << "\nTong so node co 1 cay con phai : " << DemSoNodeCoMotCayConPhai(t) << endl;
			system("pause");
		}
		else if (lc == 14)
		{
			cout << "\nTong so node la : " << DemSoNodeLa(t) << endl;
			system("pause");
		}
		else if (lc == 15)
		{
			cout << "\nChieu cao cua cay : " << ChieuCaoCay(t) << endl;
			system("pause");
		}
		else if (lc == 16)
		{
			cout << "\nNode co gia tri chan : "; InNodeChan(t);
			system("pause");
		}
		else if (lc == 17)
		{
			int x;
			cout << "Nhap gia tri x = ";
			cin >> x;
			cout << "So node co gia tri lon hon x : " << DemNodeLonHonX(t, x);
			system("pause");
		}
		else if (lc == 18)
		{
			cout << "\nNode co gia tri lon nhat : "<< TimMax(t);
			system("pause");
		}
		else if (lc == 19)
		{
			cout << "\nNode co gia tri nho nhat : " << TimMin(t);
			system("pause");
		}
		else if (lc == 20)
		{
		int x;
		cout << "Nhap gia tri x = ";
		cin >> x;
		cout << "Do dai duong di tu root den node co gia tri x : " << DoDaiDuongDi(t,x);
		system("pause");
		}
		else if (lc == 21)
		{
		DeleteAllNodeIsPrime(t);
		NLR(t);
		}
		else if (lc == 0)
			break;
	}
}
int main()
{
	TREE t;
 	KhoiTaoTree(t);
	menu(t);

}
