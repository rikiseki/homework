
#include <iostream>
#include <string>
using namespace std;

struct userData {
	string name;
	char tel[12];
	string  address;
};
typedef struct hashTable {
	struct hashTable* next;
	userData data;
}*table;

void build(table& tab);
void inputInfo(userData& p);
void insert(table& tab);
void del(table& tab);
table searchAddr(table tab);
void search(table tab);
bool equals(char* a, char* b);
int hash1(char* a);
void print(table tab);

int main()
{
	table tab;
	build(tab);
	while (1) {
		cout << "请输入指令，d删除，s查找，i添加新的数据,p打印表格" << endl;
		char code;
		cin >> code;
		switch (code) {
		case'd':
			del(tab);
			break;
		case's':
			search(tab);
			break;
		case'i':
			insert(tab);
			break;
		case'p':
			print(tab);
		default:
			return 0;
		}
	}
	return 0;
}

void build(table& tab)
{
	tab = new hashTable[8];
	int num;
	for (int i = 0; i < 8; i++) {
		tab[i].next = NULL;
	}
	cout << "请输入将要输入的数据的个数: ";
	cin >> num;
	for (int i = 0; i < num; i++) {
		insert(tab);
	}
}
void inputInfo(userData& p)///储存信息
{
	cout << "请输入姓名:";
	cin >> p.name;
	cout << "请输入电话:";
	for (int i = 0; i < 11; i++) {
		p.tel[i] = '\0';
	}
	cin >> p.tel;
	cout << "请输入地址:";
	cin >> p.address;
}
void insert(table& tab)
{
	table p = new hashTable;
	inputInfo(p->data);
	int loc = hash1(p->data.tel);///电话号码作为主关键字得到的序位
	p->next = tab[loc].next;
	tab[loc].next = p;
}
void del(table& tab)
{
	table p = searchAddr(tab);
	if (p == NULL) {
		cout << "未找到该数据" << endl;
	}
	else {
		table q = p->next;
		p->next = q->next;
		delete q;
		cout << "删完了" << endl;
	}
}
table searchAddr(table tab)//返回的是前键
{
	char tel[12];
	/*for (int i = 0; i < 11; i++) {
		tel[i] = '\0';
	}*/
	cin >> tel;
	int loc = hash1(tel);
	table p = tab[loc].next;
	table rp = &tab[loc];
	while (p != NULL) {

		if (equals(p->data.tel, tel)) {
			return rp;
		}
		else {
			p = p->next;
			rp = rp->next;
		}
	}
	return NULL;
}
void search(table tab)
{
	table p = searchAddr(tab);
	if (p == NULL)
		cout << "没有找到" << endl;
	else {
		p = p->next;
		cout << "姓名: " << p->data.name << " 电话: " << p->data.tel << " 地址: " << p->data.address << endl;
	}
}
bool equals(char* a, char* b)
{
	for (int i = 0; i < 11; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}
int hash1(char* a)//除留余数
{
	int sum = 0;
	for (int i = 0; i < 11; i++)
		sum = sum + a[i];//将电话号码11位相加
	int b = ((sum - '0' * 11) % 7 + 7) % 7;//模7取余
	return b;
}
void print(table tab)
{
	table temp;
	for (int i = 0; i < 8; i++) {
		temp = tab[i].next;
		cout << i << endl;
		while (temp != NULL) {
			cout << "姓名: " << temp->data.name << " 电话: " << temp->data.tel << " 地址: " << temp->data.address<<endl;
			temp = temp->next;
		}
	}
}




