#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

/* �ⷽ��ʽ */

typedef struct tagEquation
{
    int x;
	//int min;
	int max;
}QEUATION_S;

int isHave =0 ;

void output(int *arr,QEUATION_S *Qarr, int dst, int k)
{
	int i , j=0;
	//printf("output:K:%d\n", k);
	for(i = 0; i < k; i++)
	{
		if(0 != Qarr[i].x)
		{
			/*Ϊ���õ�һ�������ǰ��Ĳ���+�ţ�����һ���жϡ��տ�ʼ��i��
			*�������i��ѭ���ģ�i=0��ʱ�򲢲�һ��������������i�����ȼ���
			*�ҵ��߼��е�"��һ�������"�������߼��������߼�����ȷ��
			*"��һ�������"����һ����"����ĵ�һ��Ԫ��"�������߼������Ժ���Ҫ��
			*����������Ȼ���ԣ����б�����ԣ����ܹ���ȷ�������������߼�
			*�͹�ϵ�ı���������������Ȼ���Ա������ٷ���ɱ������
			*/
    		if(j==0)
    		{
                printf("%d*%d",arr[i],Qarr[i].x);
				j = 1;
    		}
    		else
    		{
                printf("+%d*%d",arr[i],Qarr[i].x);
    		}
			#if 0
			if(i==0)
    		{
                printf("%d*%d",arr[i],Qarr[i].x);
				//j = 1;
    		}
    		else
    		{
                printf("+%d*%d",arr[i],Qarr[i].x);
    		}
			#endif
		}
	}
	printf("=%d\n",dst);
}

/* ����˼·���Ǳ������е�ÿһ��������ֵ��Ȼ���ж��Ƿ����Ŀ����
 * �㷨ʱ�䡢�ռ临�ӶȽϸߣ� 
 * 
 */
void solveSon(int *arr /* ����ϵ������ */, 
			  QEUATION_S *Qarr /* ��¼ϵ����Ӧ�Ĵ�С���� */, 
			  int k,  /* k��level��ԣ�k��0��ʼ */
			  int intSum,  /* ��ǰ���ܺ� */
			  int level, /* ��Σ������ֵ��ʼ��0��ʾ���� */ 
			  int dst /* ������������ֵ */)
{
	if(level == 0)
	{
		if(dst == intSum)
		{
			isHave = 1;
            output(arr, Qarr, dst, k);
		}
		
        return;
	}
	
	int i;
	for(i=0; i <= (Qarr+k)->max; i++)
	{
		//�����޸ĳ��������Ͳ��ü���
		//int intTempSum = intSum + (*(arr+k)) * i;
		
		/* intSum���Ǿֲ�����������������ˣ�����Ҫ��ȥ */
        intSum += (*(arr+k)) * i;
		
		(Qarr+k)->x = i;
		//printf("x[%d] is %d level:%d\n",k, i, level);
		solveSon(arr, Qarr, k+1, intSum,level-1,dst);
		intSum -= (*(arr+k)) * i;//intsumֻ������ݹ���level�������򣬵���������ݹ�������ѭ���ı���ֵ
	}
}

void solveEquation(int *arr, int numCount, int dst)
{
	int i, j=1,k=0, sum=0;
	QEUATION_S x[numCount];

	memset(x, 0 ,sizeof(QEUATION_S) * numCount);
	
	/* ����ÿһ����ÿһ������ֵ����Ϊ���ǷǸ�����������5x + 6y = 30����x<=6,y<=5  */
    for(i = 0; i < numCount; i++)
    {
        while(*(arr+i) * j <= dst)
        {
            j++;
		}
		x[i].max = --j;
		j = 1;
	}
	
	/*��ʼ�ݹ鴦��*/
	solveSon(arr, x, k, sum, numCount, dst);
}

int main()
{
    int numCount = 0, i;
	int array[MAX_NUM] = {0};
	int dstNum;
	
	printf("��������ϵ����࣬���10��\n");
	while(1)
	{
		printf("������:");
	    scanf("%d",&numCount);
		if(numCount >10)
		{
            printf("���㲻Ҫ����10�����ҳ�?\n");
		}
		else
		{
			break;
		}
	};
	
	printf("����������ԭ���ϵĳ���\n");
	for(i=0 ; i < numCount;i++)
	{
        printf("������� %d ��", i+1);
		scanf("%d",array+i);
	}

	printf("������������Ҫ�ĳ���:");
	scanf("%d",&dstNum);

	solveEquation(array, numCount, dstNum);
	if(0 == isHave)
	{
        printf("�����û�н�\n");
	}
	getch();
	return 0;
}
