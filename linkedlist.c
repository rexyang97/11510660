#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *next;
	int value;
};
struct linkedlist
{
	struct node *head;
	struct node *tail;
};
struct linkedlist gene_list(){
    struct linkedlist *a;
    a->head=NULL;
    a->tail=NULL;
}
void addnode(struct linkedlist* a){//新加节点
	//printf("请输入data(int)\n");
	int data;
	//scanf("%d",data);
    data=10;
    //printf("%d\n",data);
    struct node *no;
    //printf("2\n");
    no = (struct node *) malloc(sizeof(struct node));
    //printf("3\n");
	no->value=data;
	no->next=NULL;
    printf("4\n");
	if(a->head==NULL){
		a->head=no;
		a->tail=no;
	}else{
		a->tail->next=no;
		a->tail=no;
	}
    printf("5\n");
}
int list_length(struct linkedlist* a){//求链表长度
	int i=0;
	struct node *p;
    p=a->head;//p指向链表的第一个结点。
    while(p!=NULL)
    {
    	++i;
    	p=p->next;
    }
    return i;
}
void printList(struct linkedlist* a)//打印链表
{
    if(a->head == NULL)   //链表为空
    {
        printf("PrintList函数执行，链表为空\n");
    }
    else
    {
    	struct node *p;
        p=a->head;//p指向链表的第一个结点。
        while(p != NULL)
        {
            printf("%d ",p->value);
            p = p->next;
        }
        printf("\n");
    }
}
int isEmptyList(struct linkedlist* a)//检查链表是否为空
{
    if(a->head == NULL)
    {
        printf("isEmptyList函数执行，链表为空\n");
        return 1;
    }
    printf("isEmptyList函数执行，链表非空\n");
 
    return 0;
}

int getValue(struct linkedlist* a, int pos)//返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 
{
    int i=0;
 
    if(pos < 1)
    {
        printf("getValue函数执行，pos值非法\n");
        return 0;
    }
    if(a->head == NULL)
    {
        printf("getValue函数执行，链表为空\n");
        return 0;
        //exit(1);
    }
    struct node *p;
    p=a->head;//p指向链表的第一个结点。
    while(p !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        p = p->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("getgetValue函数执行，pos值超出链表长度\n");
        return 0;
    }
    return p->value;
}
int delete(struct linkedlist* a, int pos)//删除单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 
{
    int i=0;
 
    if(pos < 1)
    {
        printf("delete函数执行，pos值非法\n");
        return 0;
    }
    if(a->head == NULL)
    {
        printf("delete函数执行，链表为空\n");
        return 0;
        //exit(1);
    }
    struct node *p;
    p=a->head;//p指向链表的第一个结点。
    if(pos==1){
    	a->head=p->next;
    	p->next=NULL;
    	return 1;
    }
   
    while(p !=NULL)
    {
        ++i;
        if(i == pos-1)
        {
            break;
        }
        p = p->next; //移到下一结点
    }
    if(i < pos-1)                  //链表长度不足则退出
    {
        printf("getgetValue函数执行，pos值超出链表长度\n");
        return 0;
    }
    return p->value;
}
int main()
{
    struct linkedlist *a;
    addnode(a);
    addnode(a);
    addnode(a);
    addnode(a);
    printf("%d\n",list_length(a) );
    printList(a);
    isEmptyList(a);
    printf("第三位数据为%d\n",getValue(a,3) );
    printf("删除第三位数据\n");
    delete(a,3);
    printList(a);
    return 1;
}