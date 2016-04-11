/*
�ڲ������㷨�����ܷ���

���ܣ����һ�����Գ���Ƚϼ����ڲ������㷨�Ĺؼ��ֱȽϴ������ƶ�������

���룺
��һ��������ļ�¼�������С����ǰ���Ѿ�������ļ����ʵ�λ���ϣ�ֱ��ȫ��������Ϊֹ��

ð�ݣ�
�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�

ѡ��
���������������ҵ���С�ģ�Ȼ��ŵ���һ��λ�á�֮���ٿ�ʣ��Ԫ������С�ģ��ŵ��ڶ���λ�á����Դ�����

���٣�
��������ѡȡһ��������Ϊ�ؼ����ݣ�Ȼ�����б���С�������ŵ���ǰ�棬���б�����������ŵ�������
�ٴζ����ߵ�����ֱ�ִ�д˲��裬Ȼ���ٷֽ����飬ֱ�����鲻���ٷֽ�Ϊֹ

ϣ����
�Ƚ���������Ԫ�����зָ�����ɸ������У������ĳ������������Ԫ����ɵģ��ֱ����ֱ�Ӳ�������
Ȼ���������������ٽ������򣬴����������е�Ԫ�ػ������������㹻С��ʱ���ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ�������

�ѣ�
�����󶥶ѣ��Ѷ�Ԫ�غ����һ��Ԫ�ؽ���������Ѷ�Ԫ��֮�󣬵���ʣ��Ԫ�س�Ϊһ���µĴ󶥶�
���Ͻ��д˲�������ʣ�µ�Ԫ�����µ���Ϊ�ѣ�Ȼ������Ѷ�Ԫ�ص���������ÿ�ν���������������-1��������+1�������ظ��˹���
*/# include <iostream>
# include <iomanip>
# include <string>
# include <ctime>
using namespace std;

//����˳���
typedef struct
{
	int elem[100];
	int length;
}SqList;

//�Ƚϼ��ƶ�����
int com = 0, mov = 0;

//����100�������
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

//��������
void show(SqList &q)
{
	cout << "��ʼԪ��Ϊ:";
	for (int i = 0; i < q.length; i++)
	{
		if (i % 20 == 0)
			cout << endl;
		cout << setw(4) << q.elem[i] << " ";
	}
	cout << endl;
}

//�Ƚϼ��ƶ�������0
void BeforeSort() 
{
	com = 0, mov = 0;
}

//����p��q
void copy(SqList &p, SqList &q)
{
	q.length = p.length;
	for (int i = 0; i < p.length; i++)
		q.elem[i] = p.elem[i];
}

//����Ƚϼ��ƶ�����
void output()
{
	cout << setw(10) << com << "|" << setw(10) << mov << "|";
}

//����ʽ
void outline()
{
	cout << "--------|       |----------|----------|      |----------|----------|      |----------|----------|" << endl;
}

//����
void back(SqList &p, SqList &q)
{
	for (int i = 0; i < 100; i++)
		p.elem[i] = q.elem[99 - i];
	p.length = q.length;
}

//��������
void insert(SqList &q)
{
	BeforeSort();
	int i, j, key;
	for (i = 1; i<q.length; i++)//������Ҫ�����Ԫ��
	{
		com++;
		key =q.elem[i]; //keyΪҪ�����Ԫ��
		mov++;
		for (j = i; j>0 && q.elem[j - 1]>key; j--) //����Ҫ�����λ��,ѭ������,���ҵ�����λ��
		{
			com++;
			q.elem[j] = q.elem[j - 1]; //�ƶ�Ԫ�ص�λ��.��Ҫ����Ԫ��ʹ��
			mov++;
		}
		q.elem[j] = key; //������Ҫ�����Ԫ��
		mov++;
	}
	output();
}

//ð������
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

//ѡ������
void select(SqList &q)
{
	BeforeSort();
	int i, j, min, t;
	for (i = 0; i<q.length - 1; i++)
	{
		com++;
		min = i;//������Сֵ
		mov++;
		for (j = i + 1; j < q.length; j++)
		{
			com++;
			if (q.elem[min] > q.elem[j])
			{
				com++;
				min = j;//����
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

//��������
void Qsort(SqList &q, int low, int high)
{
	if (low >= high)
	{
		com++;
		return;
	}
	int first = low;
	int last = high;
	int key = q.elem[first];/*���ֱ�ĵ�һ����¼��Ϊ����*/
	while (first < last)
	{
		com++;
		while (first < last && q.elem[last] >= key)
		{
			com++;
			com++;
			--last;
		}

		q.elem[first] = q.elem[last];/*���ȵ�һ��С���Ƶ��Ͷ�*/
		mov++;

		while (first < last && q.elem[first] <= key)
		{
			com++;
			++first;
		}

		q.elem[last] = q.elem[first];
		mov++;
		/*���ȵ�һ������Ƶ��߶�*/
	}
	q.elem[first] = key;/*�����¼��λ*/
	mov++;
	Qsort(q, low, first - 1);
	Qsort(q, first + 1, high);
}

//��������
void quick(SqList &q)
{
	BeforeSort();
	Qsort(q, 0, q.length-1);
	output();
}

//ϣ������
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

//�ѵ���
void HeapAdjust(SqList &q, int start, int end)
{

	int temp = q.elem[start];
	mov++;
	for (int i = 2 * start + 1; i <= end; i *= 2)
	{
		com++;
		//��Ϊ������������Ϊ0������1������i������Ӻ��Һ��ӷֱ�Ϊ2i+1��2i+2
		if (i<end && q.elem[i]<q.elem[i + 1])//���Һ��ӵıȽ�
		{
			com += 2;
			++i;//iΪ�ϴ�ļ�¼���±�
		}

		if (temp > q.elem[i])//���Һ����л�ʤ���븸�׵ıȽ�
		{
			com++;
			break;
		}

		//�����ӽ����λ�����Ժ��ӽ���λ�ý�����һ�ֵ�ɸѡ
		q.elem[start] = q.elem[i];
		start = i;
		mov += 2;
	}

	q.elem[start] = temp; //�����ʼ����г��Ԫ��
	mov++;
}

//������
void heap(SqList &q)
{
	BeforeSort();
	//�Ƚ����󶥶�
	for (int i = q.length-1 / 2; i >= 0; --i)
	{
		com++;
		HeapAdjust(q, i, q.length-1);
	}
	//��������
	for (int i = 100 - 1; i>0; --i)
	{
		com++;
		//���һ��Ԫ�غ͵�һԪ�ؽ��н���
		int temp = q.elem[i];
		q.elem[i] = q.elem[0];
		q.elem[0] = temp;
		mov += 3;
		//Ȼ��ʣ�µ�����Ԫ�ؼ�������Ϊ�󶥶�
		HeapAdjust(q, 0, i - 1);
	}
	output();
}

int main()
{
	SqList p, q ,b;
	CreateSqList(p);
	show(p);
	
	outline(); cout << "\t|  ��� " <<"| �Ƚϴ��� | �ƶ����� | ���� | �Ƚϴ��� | �ƶ����� | ���� | �Ƚϴ��� | �ƶ����� |" << endl; outline();
	cout << "��������|\t|"; copy(p, q); quick(q);  cout << "      |"; quick(q);  cout << "      |"; back(b, q); quick(b);  cout << endl; outline();
    cout << "ֱ������|\t|"; copy(p, q); insert(q); cout << "      |"; insert(q); cout << "      |"; back(b, q); insert(b); cout << endl; outline();
	cout << "ð������|\t|"; copy(p, q); bubble(q); cout << "      |"; bubble(q); cout << "      |"; back(b, q); bubble(b); cout << endl; outline();
	cout << "ѡ������|\t|"; copy(p, q); select(q); cout << "      |"; select(q); cout << "      |"; back(b, q); select(b); cout << endl; outline();
	cout << "ϣ������|\t|"; copy(p, q); shell(q);  cout << "      |"; shell(q);  cout << "      |"; back(b, q); shell(b);  cout << endl; outline();
	cout << "������  |\t|"; copy(p, q); heap(q);   cout << "      |"; heap(q);   cout << "      |"; back(b, q); heap(b);   cout << endl; outline();
	getchar();
	return 0;
}
