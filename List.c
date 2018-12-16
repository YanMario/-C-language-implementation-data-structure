//
// Created by yanpan on 2018/12/14.
//

#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int ElemType;
typedef struct Node
{
    ElemType _data;
    struct Node* _pnext;
}Node,*List;


void Init_List(List plist)
{
    if(NULL == plist)
        return;
    plist -> _pnext = NULL;
}

Node* BuyNode()
{
    Node* pnode = (Node*)malloc(sizeof(Node));
    assert(pnode!=NULL);
    return pnode;
}


void Insert_Head(int data,List plist)
{
    if(NULL == plist)
        return;
    Node* pnewNode = BuyNode();
    pnewNode -> _data = data;
    pnewNode -> _pnext = plist -> _pnext;
    plist -> _pnext = pnewNode;
}



bool Inser_tail(List plist, int data)
{
    return true;
}

Node* Search(List plist,int data)
{
    Node *pNode = plist;
    while(pNode != NULL)
    {
        if(pNode -> _data == data)
        {
            return pNode;
        }
        pNode = pNode -> _pnext;
    }
    return NULL;
}

Node* Search_Prev(List plist, int data)
{
    Node *pNode = plist;
    while(pNode -> _pnext != NULL)
    {
        if(pNode -> _pnext -> _data == data)
        {
            return pNode;
        }
        pNode = pNode -> _pnext;
    }
    return NULL;
}
bool FreeNode(Node *pNode)
{
    free(pNode);
    return true;
}
bool Delete(List plist, int data)
{
    if(!plist)
        return false;
    Node* pNode = Search(plist,data);
    if(!pNode)
        return false;
    Node* qNode = Search_Prev(plist,data);
    if(!qNode)
        return false;
    qNode -> _pnext = pNode -> _pnext;
    FreeNode(pNode);
    return true;
}

void show(List plist)
{
    if(!plist)
        return;
    Node *pnode = plist -> _pnext;
    while(pnode != NULL)
    {
        printf("%d\n", pnode -> _data);
        pnode = pnode -> _pnext;
    }
}

/*
bool resver_List(List plist)
{
    if(!plist){
        printf("ok");
        return false;}
    printf("ok");
    Node *pNode = plist -> _pnext;
    Node *qNode = plist;
    while(qNode -> _pnext != NULL)
    {
        qNode = qNode -> _pnext;
    }
    plist -> _pnext = qNode;
    while(pNode -> _pnext != qNode)
    {
        pNode = pNode -> _pnext;
        pNode -> _pnext = qNode -> _pnext;
        qNode -> _pnext = pNode;
    }
    printf("ok\n");
    return true;
}*/






//链表逆置
void Resver(List plist,Node *cur)
{
    if(cur -> _pnext == NULL)
    {
        plist->_pnext = cur;
        return;
    }
    Node* rear = cur -> _pnext;
    Resver(plist,rear);
    rear -> _pnext = cur;
}
void Resver_List_digui(List plist)
{
    //链表为NULL 或 链表只有一个元素不用逆置
    if(plist -> _pnext == NULL || plist -> _pnext ->_pnext == NULL)
        return;
    Node* cur = plist -> _pnext;
    Resver(plist,cur);
    cur -> _pnext = NULL;
}


//链表逆置
void Resver_List(List plist)
{
    Node* pNode = plist -> _pnext;
    Node* pre = plist -> _pnext;
    if(pre == NULL || pre -> _pnext == NULL)
        return;
    Node *cur,*rear;
    cur = pre -> _pnext;
    while(cur)
    {
        rear = cur -> _pnext;
        cur -> _pnext = pre;
        pre = cur;
        cur = rear;
    }
    pNode -> _pnext = NULL;
    plist -> _pnext = pre;
}
int main()
{
    Node* plist;
    plist = BuyNode();
    if(plist == NULL)
        printf("头节点内存申请失败");
    //Init_List(plist);
    plist -> _pnext = NULL;
    Insert_Head(10,plist);
    Insert_Head(9,plist);
    Insert_Head(8,plist);
    Insert_Head(7,plist);
    Insert_Head(6,plist);
    Insert_Head(5,plist);
    Insert_Head(4,plist);
    Insert_Head(3,plist);
    Insert_Head(2,plist);
    Insert_Head(1,plist);
    Delete(plist,5);
    Delete(plist,1);
    Resver_List_digui(plist);
    show(plist);
    return 0;
}


#endif