#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElemType;

typedef struct tagPloynode
{
	int coef;
	int exp;
	struct tagPloynode *next;
}Polynode,*Polylist;

void polycreate(Polynode **LL,int n)
{
	int i;
	Polynode *p,*q, *L;
	L=(Polynode *)malloc(sizeof(Polynode));
	L->next=NULL;
	q=L;
	printf("�ɶ�����%d������\n",n);
	for(i=0;i<n;i++)
	{
		p=(Polynode *)malloc(sizeof(Polynode));
		scanf("%d%d",&p->coef,&p->exp);
		//p->coef=c;
		//p->exp=e;
		q->next=p;
		q=q->next;
	}
	p->next=NULL;
	*LL = L;
}
void visit(ElemType c,ElemType e)
{
	if(c!=0)
		printf("%dx^%d",c,e);
}
void Print(Polylist L)
{
	Polylist p=L->next;
	while(p)
	{
		visit(p->coef,p->exp);
		if(p->next)
		{
			printf("+");
		}
		p=p->next;
	}
	printf("\n");
}

Polylist Mergelist(Polylist La,Polylist Lb)
{
	Polylist pa,pb,pc,Lc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
		if(pa->exp<pb->exp)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->exp>pb->exp)
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else
		{
			pa->coef=pa->coef+pb->coef;
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			pb=pb->next;
		}
	}
	pc->next=(pc->next==pa)?pa:pb;
	return Lc;
}
void main()
{
	int n,m;
	Polylist La,Lb,Lc;
	printf(" �������ʽLa������n:\n");
	scanf("%d",&n);
	printf("�������ʽLa:");
	polycreate(&La,n);
	printf(" �������ʽLb������m:\n");
	scanf("%d",&m);
	printf("�������ʽLb:");
	polycreate(&Lb,m);
	printf("����ʽLa:");
	Print(La);
	printf("\n");
	printf("����ʽLb:");
	Print(Lb);
	printf("\n");
	Lc=Mergelist(La,Lb);
	Print(Lc);
}