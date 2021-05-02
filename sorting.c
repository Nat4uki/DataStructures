//
// Created by Natsuki on 2021/4/27.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"array.h"
#include"sort.h"
#include"sequencelist.h"
#define INITSIZE 50



int main() {
    SeqList sql;
    initSeqList(&sql,50,1);
    printSeqList(sql);
    seqListInsert(&sql,1,40);
    seqListInsert(&sql,3,100);
    //    quickSort(sql.data,0,sql.length-1);
    printSeqList(sql);
    int a = seqListDelete(&sql, 2);
    printSeqList(sql);
    printf("The locate of 100:%d\n", seqListLocateElem(sql,100));
    return 0;
}
