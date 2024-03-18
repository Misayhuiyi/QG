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
        printf("出现错误！\n");
        exit(1);                    //内存分配失败，退出
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);             //往前插入数据，头插入法。并更新头指针
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
        while (temp->next != NULL) {                //往后插入数据。
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    printf("链表数据如下: ");
    while (temp != NULL) {
        printf("%d ", temp->data);//遍历的同时打印数据
        temp = temp->next;       
    }
    printf("\n");
}

void deleteNode(Node** head, int n) {
    if (*head == NULL) {
        printf("该链表是空的~~\n");
        return;
    }
    Node* temp = *head;
    if (temp->data == n) { 
        (*head) = temp->next;
        if (*head != NULL) {         
            (*head)->prev = NULL;//头结点为要删的数据
        }
        free(temp);//释放内存
        return;
    }
    while (temp != NULL && temp->data != n) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("不存在该数据%d~\n", n);//遍历结束都没有找到该结点
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;//删除的结点不为最后一个结点的情况
    }
    free(temp);
}

void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;//遍历逐步删除结点，释放内存。
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    do {
        printf("\n实现双链表ADT\n");
        printf("1. 在头指针前插入数据\n");
        printf("2. 在链表尾插入数据\n");
        printf("3. 删除数据\n");
        printf("4. 打印链表\n");
        printf("5. 退出\n");
        printf("请输入指令: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("请输入你要插入在前面的数据: ");
            scanf_s("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("请输入你要插入在尾部的数据: ");
            scanf_s("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("请输入你要删除的数据: ");
            scanf_s("%d", &key);
            deleteNode(&head, key);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            printf("退出中.....\n");
            break;
        default:
            printf("请输入正确指令\n");
        }
    } while (choice != 5);

    freeList(&head);

    return 0;
}