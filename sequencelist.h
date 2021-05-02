//
// Created by 19614 on 2021/5/2.
//

#ifndef DATASTRUCTURES_SEQUENCELIST_H
#define DATASTRUCTURES_SEQUENCELIST_H

#endif //DATASTRUCTURES_SEQUENCELIST_H


typedef struct {
    int *data;
    int length, maxSize;
} SeqList;
/**
 * @brief 初始化顺序表
 * @param list 顺序表指针
 * @param maxSize 顺序表最大容量
 * @param initSize 初始化长度
 */
void initSeqList(SeqList *list, int maxSize, int initSize) {
    list->maxSize = maxSize;
    list->length = initSize;
    if (initSize&&maxSize&&initSize<=maxSize) {
        list->data = mallocArray(initSize,0,100);
    } else
        printf("Error init size.\n");
}

/**
 * @brief 查找元素在顺序表的位置
 * @param list 顺序表
 * @param element 查询的元素
 * @return 返回查找元素的下标
 */
int seqListLocateElem(SeqList list,int element){
    for(int i=0;i<list.length;i++){
        if(list.data[i]==element)
            return i+1;
    }
    printf("Can't find.\n");
    return -1;
}
/**
 * @brief 删除指定位置的元素
 * @param list 顺序表指针
 * @param index 要删除元素的下标
 * @return 返回删除元素的值
 */
int seqListDelete(SeqList *list,int index){
    if(!index||index>list->length+1){
        printf("Error index.\n");
        return 0;
    }
    int element = list->data[index-1];
    for(int i = index;i<list->length;i++){
        list->data[i-1] = list->data[i];
    }
    list->length--;
    return element;
}
/**
 * @brief 修改指定位置的值
 * @param list 顺序表指针
 * @param index 元素位置
 * @param element 要修改为的值
 */
void seqListSetData(SeqList *list,int index,int element){
    if(!index||index>list->length+1){
        printf("Error index.\n");
        return ;
    }
    list->data[index-1] = element;
}
/**
 * @brief 在指定位置插入元素
 * @param list 顺序表指针
 * @param index 要插入的位置
 * @param element 要插入的元素的值
 */
void seqListInsert(SeqList *list,int index,int element){
    if(!index||index>list->length+1){
        printf("Error index.\n");
        return;
    }
    if(list->length>=list->maxSize) {
        printf("Full list.\n");
        return;
    }
    for(int i =list->length;i>=index;i--)
        list->data[i] = list->data[i-1];
    list->data[index-1] = element;
    list->length++;
}
/**
 * @brief 打印顺序表
 * @param list 顺序表
 */
void printSeqList(SeqList list) {
    printf("Length:%d,MaxSize:%d\n",list.length,list.maxSize);
    printArray(list.data,list.length);
}