#include "all.h"

void LinklistCreate()
{
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("there is something wrong with the distribution.");
			exit(-1);//������ֹ
	}
	int number;
	printf("����������");
	scanf_s("%d",&number);
	head->next = NULL;
	head->num = number;
}

void LinklistIncrease(Node**head ,int t,int n)
{
	int i = 1;
	Node* p1 = (Node*)malloc(sizeof(Node));
	Node* p = *head;
	p1->num = t;
	if (*head=NULL)
	{
		*head = p1;
		(*head)->next = NULL;
		return;
	}
	while (p->next!=NULL && i < n-1)
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
		p1->next = (*head)->next;
		(*head)->next = p1;
		return;
	}
	else
	{
		p1->next = p->next;
		p->next = p1;
		return;
	}

}

void LinklistDelet(Node**head,int n)
{	
	Node* p1 = (*head);
	Node*p2=NULL;
	if ((*head) == NULL) {
		printf("û�д�������");
		return;
	}
	while (p1 != NULL && p1->num != n)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1 == NULL)
	{
		printf("�����ڸ�����");
	}
	if (p2 == NULL)//Ҫɾ����һ����㼴ͷָ��
	{
		*(head) = (*head)->next;
	}
	else {
		p2->next = p1->next;
	}
	free(p1);
}

void LinklistDestroy(Node** head) {
	if ((*head) == NULL) {
		return;
	}
	Node* p1 = (*head);
	Node* p2 = NULL;
	while (p1 != NULL) {
		p2 = p1;
		p1 = p1->next;
		free(p2);//�����ͷ��ڴ�

	}
	(*head) = NULL;//��������
}


void Linklistsearch(Node** head,int n) {
	int i = 1;
	if ((*head) == NULL) {
		return;
	}
	Node* p = (*head);
	while (p->next != NULL && p->num != n)
	{
		p = p->next;
		i++;
	}
	if (p->num == n)
	{
		printf("�����ݴ��ڣ����Ϊ%d", i);
		return;
	}
	if (p->next == NULL)
	{
		printf("û���ҵ�������");
	}
		
}

void print(Node** head) {
	Node* p = (*head);
	while (p != NULL) {
		printf("%d\n", p->num);
		p = p->next;
	}
}

void LinklistReverse(Node** head)
{
	Node* p;
	Node* q;
	p = (*head)->next;
	while (p->next)
	{
		q = p->next;//��ת���
		p->next = q->next;//��������ʣ�µĽ��
		q->next = (*head)->next;//q����һ���ָ��������ĵ�һ�����
		(*head)->next = q;//�������һ������Ϊq
	}
}

void  LinklistMiddle(Node** head) {
	Node* p1;
	Node* p2;
	p1 = (*head);
	p2 = (*head);
	while (p1->next) {
		p1 = p1->next->next;
		p2 = p1->next;
	}
	printf("�м�����Ϊ%d", p2->num);
}


int main()
{	
	int num;
	int t, n;
	int command;
	do {
		printf("������ADT:\n");
		printf("1. ��������\n");
		printf("2. ��������\n");
		printf("3. ɾ������\n");
		printf("4. �ҵ��м�ֵ\n");
		printf("5. ����������ӡ����\n");
		printf("6. ��������\n");
		printf("7. ��������\n");
		printf("8. ��ת����\n");
		printf("9. �˳�\n");
		printf("���������� \n");
		scanf_s("%d", &command);


		switch (command) {
		case 1:
			LinklistCreate();
			printf("��������ɹ�\n");
			break;
		case 2:
			printf("����������Ҫ��ӵ�����\n");

			scanf_s("%d", &t);
			printf("����������ݵı�ţ�ͷָ����Ϊ1����\n");
			scanf_s("%d", &n);
			LinklistIncrease(&head, t,n);
			break;
		case 3:
			printf("��������Ҫɾ��������\n");

			scanf_s("%d", &num);
			LinklistDelet(&head, num);
			break;
		case 4:
			LinklistMiddle(&head);
			break;
		case 5:
			print(&head);
			break;
		case 6:
			printf("�εΣ�ִ�����ٲ�������\n");
			LinklistDestroy(&head);
			printf("���ٳɹ�\n");
			break;
		case 7:
			printf("��������Ҫ���ҵ�����:\n");
			scanf_s("%d", &num);
			Linklistsearch(&head, num);
			break;
		case 8:
			printf("�εΣ����ڷ�ת�С���\n");
			LinklistReverse(&head);
			printf("��ת�ɹ�\n");
		default:
			command = 9;
			break;
		}
	} while (command!=9);

	return 0;
}