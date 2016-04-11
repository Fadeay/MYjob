/*
内部排序算法的性能分析

功能：设计一个测试程序比较几种内部排序算法的关键字比较次数和移动次数。

插入：
将一个待排序的纪录，按其大小插入前面已经排序的文件中适当位置上，直到全部插入完为止。

冒泡：
比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

选择：
从所有序列中先找到最小的，然后放到第一个位置。之后再看剩余元素中最小的，放到第二个位置……以此类推

快速：
首先任意选取一个数据作为关键数据，然后将所有比它小的数都放到它前面，所有比它大的数都放到它后面
再次对两边的数组分别执行此步骤，然后再分解数组，直到数组不能再分解为止

希尔：
先将整个待排元素序列分割成若干个子序列（由相隔某个“增量”的元素组成的）分别进行直接插入排序，
然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序

堆：
建立大顶堆，堆顶元素和最后一个元素交换，输出堆顶元素之后，调整剩余元素成为一个新的大顶堆
不断进行此操作，将剩下的元素重新调整为堆，然后输出堆顶元素到有序区。每次交换都导致无序区-1，有序区+1。不断重复此过程
*/# include <iostream>
# include <iomanip>
# include <string>
# include <ctime>
using namespace std;

//定义顺序表
typedef struct
{
	int elem[100];
	int length;
}SqList;

//比较及移动次数
int com = 0, mov = 0;

//产生100个随机数
void CreateSqList(SqList &q)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 100; i++)
	{
		q.elem[i] = rand() % 1000;
	}
	q.length = i;
}

//输出随机数
void show(SqList &q)
{
	cout << "初始元素为:";
	for (int i = 0; i < q.length; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << setw(4) << q.elem[i] << " ";
	}
	cout << endl;
}

//比较及移动次数归0
void BeforeSort() 
{
	com = 0, mov = 0;
}

//复制p至q
void copy(SqList &p, SqList &q)
{
	q.length = p.length;
	for (int i = 0; i < p.length; i++)
		q.elem[i] = p.elem[i];
}

//输出比较及移动次数
void output()
{
	cout << setw(10) << com << "|" << setw(10) << mov << "|";
}

//表格格式
void outline()
{
	cout << "--------|       |----------|----------|      |----------|----------|      |----------|----------|" << endl;
}

//反序
void back(SqList &p, SqList &q)
{
	for (int i = 0; i < 100; i++)
		p.elem[i] = q.elem[99 - i];
	p.length = q.length;
}

//插入排序
void insert(SqList &q)
{
	BeforeSort();
	int i, j, key;
	for (i = 1; i<q.length; i++)//控制需要插入的元素
	{
		com++;
		key =q.elem[i]; //key为要插入的元素
		mov++;
		for (j = i; j>0 && q.elem[j - 1]>key; j--) //查找要插入的位置,循环结束,则找到插入位置
		{
			com++;
			q.elem[j] = q.elem[j - 1]; //移动元素的位置.供要插入元素使用
			mov++;
		}
		q.elem[j] = key; //插入需要插入的元素
		mov++;
	}
	output();
}

//冒泡排序
void bubble(SqList &q)
{
	BeforeSort();
	int i, j, temp;
	for (j = 0; j < q.length - 1; j++)
	{
		com++;
		for (i = 0; i < q.length - 1 - j; i++)
		{
			com++;
			if (q.elem[i] > q.elem[i + 1])
			{
				com++;
				temp = q.elem[i];
				q.elem[i] = q.elem[i + 1];
				q.elem[i + 1] = temp;
				mov += 3;
			}
		}
	}
	output();
}

//选择排序
void select(SqList &q)
{
	BeforeSort();
	int i, j, min, t;
	for (i = 0; i<q.length - 1; i++)
	{
		com++;
		min = i;//查找最小值
		mov++;
		for (j = i + 1; j < q.length; j++)
		{
			com++;
			if (q.elem[min] > q.elem[j])
			{
				com++;
				min = j;//交换
				mov++;
			}
		}
		if (min != i)
		{
			com++;
			t = q.elem[min];
			q.elem[min] = q.elem[i];
			q.elem[i] = t;
			mov += 3;
		}
	}
	output();
}

//快速排序
void Qsort(SqList &q, int low, int high)
{
	if (low >= high)
	{
		com++;
		return;
	}
	int first = low;
	int last = high;
	int key = q.elem[first];/*用字表的第一个记录作为枢轴*/
	while (first < last)
	{
		com++;
		while (first < last && q.elem[last] >= key)
		{
			com++;
			com++;
			--last;
		}

		q.elem[first] = q.elem[last];/*将比第一个小的移到低端*/
		mov++;

		while (first < last && q.elem[first] <= key)
		{
			com++;
			++first;
		}

		q.elem[last] = q.elem[first];
		mov++;
		/*将比第一个大的移到高端*/
	}
	q.elem[first] = key;/*枢轴记录到位*/
	mov++;
	Qsort(q, low, first - 1);
	Qsort(q, first + 1, high);
}

//快速排序
void quick(SqList &q)
{
	BeforeSort();
	Qsort(q, 0, q.length-1);
	output();
}

//希尔排序
void shell(SqList &q)
{
	BeforeSort();
	int temp;
	for (int div = q.length / 2; div >= 1; div /= 2)
	{
		com++;
		for (int i = div; i<q.length; i++)
		{
			com++;
			for (int j = i; (q.elem[j]<q.elem[j - div]) && j >= 0; j -= div)
			{
				com++;
				com++;
				temp = q.elem[j];
				mov++;
				q.elem[j] = q.elem[j - div];
				mov++;
				q.elem[j - div] = temp;
				mov++;
			}
		}
	}
	output();
}

//堆调整
void HeapAdjust(SqList &q, int start, int end)
{

	int temp = q.elem[start];
	mov++;
	for (int i = 2 * start + 1; i <= end; i *= 2)
	{
		com++;
		//因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
		if (i<end && q.elem[i]<q.elem[i + 1])//左右孩子的比较
		{
			com += 2;
			++i;//i为较大的记录的下标
		}

		if (temp > q.elem[i])//左右孩子中获胜者与父亲的比较
		{
			com++;
			break;
		}

		//将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
		q.elem[start] = q.elem[i];
		start = i;
		mov += 2;
	}

	q.elem[start] = temp; //插入最开始不和谐的元素
	mov++;
}

//堆排序
void heap(SqList &q)
{
	BeforeSort();
	//先建立大顶堆
	for (int i = q.length-1 / 2; i >= 0; --i)
	{
		com++;
		HeapAdjust(q, i, q.length-1);
	}
	//进行排序
	for (int i = 100 - 1; i>0; --i)
	{
		com++;
		//最后一个元素和第一元素进行交换
		int temp = q.elem[i];
		q.elem[i] = q.elem[0];
		q.elem[0] = temp;
		mov += 3;
		//然后将剩下的无序元素继续调整为大顶堆
		HeapAdjust(q, 0, i - 1);
	}
	output();
}

int main()
{
	SqList p, q ,b;
	CreateSqList(p);
	show(p);
	
	outline(); cout << "\t|  随机 " <<"| 比较次数 | 移动次数 | 正序 | 比较次数 | 移动次数 | 逆序 | 比较次数 | 移动次数 |" << endl; outline();
	cout << "快速排序|\t|"; copy(p, q); quick(q);  cout << "      |"; quick(q);  cout << "      |"; back(b, q); quick(b);  cout << endl; outline();
    cout << "直接排序|\t|"; copy(p, q); insert(q); cout << "      |"; insert(q); cout << "      |"; back(b, q); insert(b); cout << endl; outline();
	cout << "冒泡排序|\t|"; copy(p, q); bubble(q); cout << "      |"; bubble(q); cout << "      |"; back(b, q); bubble(b); cout << endl; outline();
	cout << "选择排序|\t|"; copy(p, q); select(q); cout << "      |"; select(q); cout << "      |"; back(b, q); select(b); cout << endl; outline();
	cout << "希尔排序|\t|"; copy(p, q); shell(q);  cout << "      |"; shell(q);  cout << "      |"; back(b, q); shell(b);  cout << endl; outline();
	cout << "堆排序  |\t|"; copy(p, q); heap(q);   cout << "      |"; heap(q);   cout << "      |"; back(b, q); heap(b);   cout << endl; outline();
	getchar();
	return 0;
}
