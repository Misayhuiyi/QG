#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("���ִ���\n");
        exit(1);                    //�ڴ����ʧ�ܣ��˳�
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);             //��ǰ�������ݣ�ͷ���뷨��������ͷָ��
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* temp = *head;
        while (temp->next != NULL) {                //����������ݡ�
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    printf("������������: ");
    while (temp != NULL) {
        printf("%d ", temp->data);//������ͬʱ��ӡ����
        temp = temp->next;       
    }
    printf("\n");
}

void deleteNode(Node** head, int n) {
    if (*head == NULL) {
        printf("�������ǿյ�~~\n");
        return;
    }
    Node* temp = *head;
    if (temp->data == n) { 
        (*head) = temp->next;
        if (*head != NULL) {         
            (*head)->prev = NULL;//ͷ���ΪҪɾ������
        }
        free(temp);//�ͷ��ڴ�
        return;
    }
    while (temp != NULL && temp->data != n) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("�����ڸ�����%d~\n", n);//����������û���ҵ��ý��
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;//ɾ���Ľ�㲻Ϊ���һ���������
    }
    free(temp);
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;//������ɾ����㣬�ͷ��ڴ档
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    do {
        printf("\nʵ��˫����ADT\n");
        printf("1. ��ͷָ��ǰ��������\n");
        printf("2. ������β��������\n");
        printf("3. ɾ������\n");
        printf("4. ��ӡ����\n");
        printf("5. �˳�\n");
        printf("������ָ��: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("��������Ҫ������ǰ�������: ");
            scanf_s("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("��������Ҫ������β��������: ");
            scanf_s("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("��������Ҫɾ��������: ");
            scanf_s("%d", &key);
            deleteNode(&head, key);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            printf("�˳���.....\n");
            break;
        default:
            printf("��������ȷָ��\n");
        }
    } while (choice != 5);

    freeList(&head);

    return 0;
}