#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

/* 解方程式 */

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
			/*为了让第一个输出的前面的不带+号，做了一个判断。刚开始用i，
			*但是这个i是循环的，i=0的时候并不一定输出，所以这个i并不等价于
			*我的逻辑中的"第一个输出的"。区分逻辑和物理，逻辑的正确表达，
			*"第一个输出的"并不一定是"数组的第一个元素"。对于逻辑，语言很重要，
			*不仅仅是自然语言，还有编程语言，用能够正确表述、表达这个逻辑
			*和关系的变量阐述。先用自然语言表述，再翻译成编程语言
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

/* 整体思路就是遍历可行的每一个方程数值，然后判断是否等于目标结果
 * 算法时间、空间复杂度较高， 
 * 
 */
void solveSon(int *arr /* 方程系数数组 */, 
			  QEUATION_S *Qarr /* 记录系数对应的大小区间 */, 
			  int k,  /* k与level配对，k从0开始 */
			  int intSum,  /* 当前的总和 */
			  int level, /* 层次，从最大值开始，0表示结束 */ 
			  int dst /* 方程组的最后数值 */)
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
		//可以修改成这样，就不用减了
		//int intTempSum = intSum + (*(arr+k)) * i;
		
		/* intSum不是局部变量，所以这里加了，下面要减去 */
        intSum += (*(arr+k)) * i;
		
		(Qarr+k)->x = i;
		//printf("x[%d] is %d level:%d\n",k, i, level);
		solveSon(arr, Qarr, k+1, intSum,level-1,dst);
		intSum -= (*(arr+k)) * i;//intsum只在这个递归层次level有作用域，但是在这个递归层次上有循环改变了值
	}
}

void solveEquation(int *arr, int numCount, int dst)
{
	int i, j=1,k=0, sum=0;
	QEUATION_S x[numCount];

	memset(x, 0 ,sizeof(QEUATION_S) * numCount);
	
	/* 遍历每一项，获得每一项的最大值，因为都是非负整数，比如5x + 6y = 30，则x<=6,y<=5  */
    for(i = 0; i < numCount; i++)
    {
        while(*(arr+i) * j <= dst)
        {
            j++;
		}
		x[i].max = --j;
		j = 1;
	}
	
	/*开始递归处理*/
	solveSon(arr, x, k, sum, numCount, dst);
}

int main()
{
    int numCount = 0, i;
	int array[MAX_NUM] = {0};
	int dstNum;
	
	printf("请输入材料的种类，最多10种\n");
	while(1)
	{
		printf("请输入:");
	    scanf("%d",&numCount);
		if(numCount >10)
		{
            printf("让你不要超过10个，找抽?\n");
		}
		else
		{
			break;
		}
	};
	
	printf("请依次输入原材料的长度\n");
	for(i=0 ; i < numCount;i++)
	{
        printf("请输入第 %d 个", i+1);
		scanf("%d",array+i);
	}

	printf("请依次输入需要的长度:");
	scanf("%d",&dstNum);

	solveEquation(array, numCount, dstNum);
	if(0 == isHave)
	{
        printf("该组合没有解\n");
	}
	getch();
	return 0;
}
