//
// Created by yanpan on 2018/12/10.
//


#if 1
#include <stdio.h>
#include <stdlib.h>
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

//bool Inser_tail(List plist, int data)
//{
//    return true;
//}
//
//bool Delete(List plist, int data)
//{
//    return true;
//}

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
int main()
{
    Node* plist;
    plist = BuyNode();
    if(plist == NULL)
        printf("头节点内存申请失败");
    //Init_List(plist);
    plist -> _pnext = NULL;
    Insert_Head(5,plist);
    Insert_Head(4,plist);
    Insert_Head(3,plist);
    Insert_Head(2,plist);
    Insert_Head(1,plist);
    show(plist);

    return 0;
}


#endif



/Users/yanpan/CLionProjects/2018_12_10/字符串.c

//c语言处理字符串相关代码
#if 0
#include <stdio.h>
#include <string.h>


void option(char *str)
{
    if (str == NULL)
        return;
}

void show(char *str,int len)
{
    if(NULL == str)
        return;
    int i = 0;
    int j = 0;
    for(i = 0; i<len-1; ++i)
    {
        for(j = i+1; j < len; ++j)
        {
            printf("%s\n",str);
        }
    }
}

int main()
{
    char str[] = "helloworld";
    int len = strlen(str);
    option(str);
    show(str,len);
    return 0;
}
#endif
