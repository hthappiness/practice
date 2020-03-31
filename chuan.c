#include <stdio.h>
#include <string.h>

#define MAXLEN 20
typedef struct
{
	char ch[MAXLEN];
	int len;
}SString;

int StrInsert(SString *s,int pos,SString t)/*在串s中序号为pos的字符之前插入串t*/
{
	int i;
	if(pos<0||pos>s->len)return(0);/*插入位置不合法*/
	if(s->len+t.len<=MAXLEN)/*插入后串长<=MAXLEN*/
	{
		for(i=s->len+t.len-1;i>=t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];/*移动位置*/
		for(i=0;i<t.len;i++)s->ch[i+pos]=t.ch[i];
		s->len=s->len+t.len;
	}
	else if(pos+t.len<=MAXLEN)/*插入后串长>MAXLEN，但串t的字符序列可以全部插入*/
	{
		for(i=MAXLEN-1;i>t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)s->ch[pos+i]=t.ch[i];
		s->len=MAXLEN;
	}
	else                                    /*串t的部分序列要舍弃*/
	{
		for(i=0;i<MAXLEN-pos;i++)s->ch[pos+i]=t.ch[i];
		s->len=MAXLEN;
	}
	printf("%s",s);
	return(1);
}
void main()
{
	int x;
	SString a,b;
	printf("请输入字符串a:\n");
	gets(a.ch);
	a.len = strlen(a.ch);
	printf("请输入要插入的字符串b:\n");
	gets(b.ch);
	b.len = strlen(b.ch);
	printf("请输入要插入字符串的位置:\n");
	scanf("%d",&x);
	StrInsert(&a,x,b);
}