//
// Created by Natsuki on 2021/4/27.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
#include"sort.h"
#include"sequencelist.h"

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

/**
 * @brief 初始化链表头结点
 * @return 链表头结点指针
 */
LNode *initLinkList() {
    LNode *p = (LNode *) malloc(sizeof(LNode));
    p->data = 0;
    p->next = NULL;
    return p;
}
/**
 * @brief 在链表的指定位置插入元素
 * @param p 头结点
 * @param element 插入元素
 * @param index 插入位置下标，从0开始
 */
void linkListInsert(LNode *p, int element, int index) {
    LNode * temp = p;
    for(int i =0;i<index;i++){
        temp = temp->next;
        if(temp==NULL){
            printf("error index\n");
            return;
        }
    }
    LNode * s = (LNode*)malloc(sizeof(LNode));
    s->data= element;
    s->next = temp->next;
    temp->next = s;
}

/**
 * @brief 遍历链表输出链表数据
 * @param p 头结点
 */
void printLinkListData(LNode *p) {
    LNode *lnode = p->next;
    while (lnode) {
        printf("%d ", lnode->data);
        lnode = lnode->next;
    }
}

/**
 * @brief 从初始位置插入元素
 * @param p 头结点
 * @param element 要插入的元素
 */
void headInsertLinkList(LNode *p, int element) {
    if (!p) {
        printf("Error LinkList\n");
        return;
    }
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    temp->data = element;
    temp->next = p->next;
    p->next = temp;
}

int main() {
    LNode *lList = initLinkList(&lList);
    headInsertLinkList(lList, 25);
    headInsertLinkList(lList, 23);
    linkListInsert(lList,24,3);
    printLinkListData(lList);
    return 0;
}
