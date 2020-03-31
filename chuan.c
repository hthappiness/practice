#include <stdio.h>
#include <string.h>

#define MAXLEN 20
typedef struct
{
	char ch[MAXLEN];
	int len;
}SString;

int StrInsert(SString *s,int pos,SString t)/*�ڴ�s�����Ϊpos���ַ�֮ǰ���봮t*/
{
	int i;
	if(pos<0||pos>s->len)return(0);/*����λ�ò��Ϸ�*/
	if(s->len+t.len<=MAXLEN)/*����󴮳�<=MAXLEN*/
	{
		for(i=s->len+t.len-1;i>=t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];/*�ƶ�λ��*/
		for(i=0;i<t.len;i++)s->ch[i+pos]=t.ch[i];
		s->len=s->len+t.len;
	}
	else if(pos+t.len<=MAXLEN)/*����󴮳�>MAXLEN������t���ַ����п���ȫ������*/
	{
		for(i=MAXLEN-1;i>t.len+pos;i--)
			s->ch[i]=s->ch[i-t.len];
		for(i=0;i<t.len;i++)s->ch[pos+i]=t.ch[i];
		s->len=MAXLEN;
	}
	else                                    /*��t�Ĳ�������Ҫ����*/
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
	printf("�������ַ���a:\n");
	gets(a.ch);
	a.len = strlen(a.ch);
	printf("������Ҫ������ַ���b:\n");
	gets(b.ch);
	b.len = strlen(b.ch);
	printf("������Ҫ�����ַ�����λ��:\n");
	scanf("%d",&x);
	StrInsert(&a,x,b);
}