#include <iostream>
using namespace std;
#define max 5
#define fee 2
typedef struct Car//车的信息结构体
{
	int num;
	int time;
}car;
typedef struct Node//结点
{
	car* data;
	struct Node* next;
}node;
class stack
{
public:
	stack();
	bool push(car* x);
	car* pop();
	car* gettop();
	bool isEmpty();
	int gett();//获得个数
private:
	int top;
	int stacksize;
	car* data[max];
};
class queue
{
public:
	queue();
	void InQueue(Car* x);
	bool isEmpty();
	car* DeQueue();
	int  gett();
private:
	node *front, *rear;
	int geshu;
};
int main()
{
	cout << "停车场管理系统" << endl;
	cout << "****************************************************************" << endl;
	cout << "A 停入，D 驶出，P 输出停车场数量，W 输出候车厂数量，E 退出" << endl;
	char state;
	int num, time;
	stack park = stack();
	stack temp = stack();
	queue road = queue();
	while (cin>>state,state != 'E')
	{
		cin >> num >> time;
		car *a = new car;
		a->num = num;
		a->time = time;
		if (state == 'A')
		{
			bool flag = park.push(a);
			if (!flag)
			{
				cout << "停车场已满,进入便道" << endl;
				road.InQueue(a);
			}
			else
			{
				cout << "恭喜！" << a->num << "号车已停入" << endl;
			}
		}
		else if (state == 'D')
		{
			if (!park.isEmpty())
			{
				car* d = park.pop();
				while (d->num != num && !park.isEmpty())
				{
					temp.push(d);
					//cout << d->num << "进队！！";
					while (!park.isEmpty()&&d->num != num )
					{
						d = park.pop();
						temp.push(d);
					}
				}
				if (d->num == num)
				{
					temp.pop();
					cout << "停留时间:" << time - d->time << endl;
					cout << "费用:" << (time - d->time) * fee << "元" << endl;
					delete d;
				}
				else
				{
					cout << "未找到该车" << endl;
					temp.push(d);//把车送到便道因为74设置
				}
				if (!temp.isEmpty())//当临时便道不是空的
				{
					d = temp.pop();//把第一个弹出
					while (d != NULL)
					{
						park.push(d);//把d放入停车场
						d = temp.pop();
					}
					delete d;
				}
				if ((!road.isEmpty())&&(park.gett()!=max))//停车场没满，便道有车
				{
					d = road.DeQueue();
					d->time = time;
					park.push(d);
					cout << d->num << "号车进入停车场" << endl;
				}
			}
			else
			{
				cout << "停车场已空" << endl;
			}
		}
		else if (state == 'P')
		{
			cout << "停车场车数:" << park.gett();
		}
		else if (state == 'W')
		{
			cout << "便道车数:" << road.gett();
		}
		else
		{
			cout << "请输入正确指令" << endl;
		}
	}
	cout << "感谢使用！" << endl;
}

stack::stack()
{
	top = -1;
	stacksize = max-1;
}
bool stack::push(car* x)
{
	if (top == stacksize)
		return false;
	else
	{
		data[++top] = x;
		return true;
	}
}
car* stack::pop()
{
	if (top == -1)
		return NULL;
	else
	{
		car* x;
		x = data[top--];
		return x;
	}
}
car* stack::gettop()
{
	if (top != -1)
		return data[top];
}
bool stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
int stack::gett()
{
	return top + 1;
}
queue::queue()
{
	node *p = new node;
	p->next = NULL;
	front = rear = p;
	geshu = 0;
}

void queue::InQueue(Car* x)
{
	node* n = new node;
	n->data = x;
	n->next = NULL;
	rear->next = n;
	rear = n;
	geshu++;
	cout << "进入便道" << endl;
}

bool queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}

car* queue::DeQueue()
{
	if (rear ==front)
		return NULL;
	Node* n = new Node;
	Car* x;
	n = front->next;
	x = n->data;
	front->next = n->next;
	geshu--;
	if (n->next == NULL)
		rear = front;
	delete n;
	return x;
}

int queue::gett()
{
	return geshu;
}
