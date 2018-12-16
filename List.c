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

//头插
bool Insert_Head(int data,List plist)
{
    if(NULL == plist)
        printf("ok");
    Node* pnewNode = BuyNode();
    pnewNode -> _data = data;
    pnewNode -> _pnext = plist -> _pnext;
    plist -> _pnext = pnewNode;
    return true;
}

//尾插
bool Inser_tail(List plist, int data)
{
    Node* pnewNode = BuyNode();
    Node* pNode = plist;
    while(pNode -> _pnext != NULL)
    {
        pNode = pNode -> _pnext;
    }
    pNode -> _pnext = pnewNode;
    pnewNode -> _pnext = NULL;
    return true;
}

//找到data所在的节点
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
    Init_List(plist);
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
    Inser_tail(plist,1);
    Resver_List_digui(plist);
    show(plist);
    return 0;
}


#endif