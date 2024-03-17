#include "all.h"

Node* LinklistCreate()
{
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("there is something wrong with the distribution.");
			exit(-1);//错误中止
	}
	int number;
	printf("请输入数字");
	scanf_s("%d",&number);
	head->next = NULL;
	head->num = number;
	return head;
}

void LinklistIncrease(int t,int n)
{	
	
	int i = 1;
	Node* p = head;
	Node* p1 = (Node*)malloc(sizeof(Node));
	if (p1 != NULL) {

		p1->num = t;

		if (head == NULL)
		{
			head = p1;
			(head)->next = NULL;
			return;
		}
		while (p->next != NULL && i < n - 1)
		{
			p = p->next;
			i++;
		}
		if (p->next == NULL)
		{
			p->next = p1;
			p1->next = NULL;
			return;
		}
		if (i == 1)
		{
			p1->next = (head)->next;
			(head)->next = p1;
			return;
		}
		else
		{
			p1->next = p->next;
			p->next = p1;
			return;
		}
	}

}

void LinklistDelet(int n)
{	
	if ((head) == NULL) {
		return;
	}
	Node* p1 = (head);
	Node*p2=NULL;
	if ((head) == NULL) {
		printf("没有创建链表");
		return;
	}
	while (p1 != NULL && p1->num != n)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1 == NULL)
	{
		printf("不存在该数据");
	}
	if (p2 == NULL)//要删除第一个结点即头指针
	{
		head = head->next;
	}
	else {

			p2->next = p1->next;
	}
	free(p1);
}

void LinklistDestroy() {
	if ((head) == NULL) {
		return;
	}
	Node* p1 = (head);
	Node* p2 = NULL;
	while (p1 != NULL) {
		p2 = p1;
		p1 = p1->next;
		free(p2);//不断释放内存

	}
	(head) = NULL;//销毁链表
}


void Linklistsearch(int n) {
	int i = 1;
	if ((head) == NULL) {
		return;
	}
	Node* p = (head);
	while (p->next != NULL && p->num != n)
	{
		p = p->next;
		i++;
	}
	if (p->num == n)
	{
		printf("该数据存在，编号为%d\n", i);
		return;
	}
	if (p->next == NULL)
	{
		printf("没有找到该数据\n");
	}
		
}

void print() {
	if ((head) == NULL) {
		return;
	}
	Node* p = (head);
	while (p != NULL) {
		printf("%d\n", p->num);
		p = p->next;
	}
}

void LinklistReverse()
{	
	if ((head) == NULL) {
		return;
	}
	Node* p;
	Node* q;
	p = (head)->next;
	while (p->next)
	{
		q = p->next;//反转结点
		p->next = q->next;//保存连接剩下的结点
		q->next = (head)->next;//q的下一结点指向新链表的第一个结点
		(head)->next = q;//将链表第一个结点改为q
	}
}

void  LinklistMiddle() {
	if ((head) == NULL) {
		return;
	}
	Node* p1=NULL;
	Node* p2=NULL;
	if (p1 != NULL && p2 != NULL) {
		p1 = (head);
		p2 = (head);
		while (p1->next) {
			p1 = p1->next->next;
			p2 = p1->next;
		}
		printf("中间数据为%d\n", p2->num);
	}
}


int main()
{
	head = NULL;
	int num;
	int t, n;
	int command;
	do {
		printf("单链表ADT:\n");
		printf("1. 创建链表\n");
		printf("2. 插入数据\n");
		printf("3. 删除数据\n");
		printf("4. 找到中间值\n");
		printf("5. （遍历）打印链表\n");
		printf("6. 销毁链表\n");
		printf("7. 查找数据\n");
		printf("8. 反转链表\n");
		printf("9. 退出\n");
		printf("请输入命令 \n");
		scanf_s("%d", &command);


		switch (command) {
		case 1:
			head=LinklistCreate();
			printf("创建链表成功\n");
			break;
		case 2:
			printf("请输入您需要添加的数据\n");

			scanf_s("%d", &t);
			printf("请输入该数据的编号（头指针编号为1）：\n");
			scanf_s("%d", &n);
			LinklistIncrease(t,n);
			break;
		case 3:
			printf("请输入您要删除的数据\n");

			scanf_s("%d", &num);
			LinklistDelet( num);
			printf("删除成功！\n");
			break;
		case 4:
			LinklistMiddle();
			break;
		case 5:
			print();
			break;
		case 6:
			printf("滴滴！执行销毁操作——\n");
			LinklistDestroy();
			printf("销毁成功\n");
			break;
		case 7:
			printf("请输入你要查找的数据:\n");
			scanf_s("%d", &num);
			Linklistsearch( num);
			break;
		case 8:
			printf("滴滴！正在反转中——\n");
			LinklistReverse();
			printf("反转成功\n");
			break;
		default:
			command = 9;
			break;
		}
	} while (command!=9);

	return 0;
}