#include <stdio.h>
#include <string.h>

//����ṹ
struct _node 
{
    char str[50];
    int data;
};
typedef struct _node Node;

void Sort(Node a[], int n);

int main()
{
    Node nums[200];
    const int n = 101;
    //���ݵ�����
    FILE* fp;
    fp = fopen("employ-data.txt", "r");
    int j;
    for ( j = 0; j < n; j++)
    {
        fscanf(fp,"%s %d",&nums[j].str, &nums[j].data);
    }
    fclose(fp);

    //����
    Sort(nums, n);
    
    //���ݵ����
    FILE* ffp;
    ffp = fopen("employ-sort.txt", "w");
    int k;
    for (k = 0; k < n; k++)
    {
        fprintf(ffp, "%s    %d\n", nums[k].str, nums[k].data);
    }
    fclose(ffp);

    //����
    char workname[20] ;
    printf("��������ҵ����\n");
    scanf("%s", workname);
    int m = 0;
    for (; m == 0; )
    {
        int i;
        for ( i = 0; i < n; i++)
        {
            int ret = strcmp(workname, nums[i].str);
            int j;
            if (ret == 0)
            {
                printf("%d\n", nums[i].data);
                m = 1;
            }
        }
        if (m == 0)
        {
            printf("��ѯ���ɹ�\n");
            printf("����������\n");
            printf("\n");
            scanf("%s", workname);

        }
    }
    
    return 0;
}

void Sort(Node a[], int n)                                      // ��������
{
    int i, j;
    for (i = 1; i < n; i++)
        if (a[i].data > a[i - 1].data)
        {
            int temp = a[i].data;                               //����Ҫ�Ƚϵ�ֵ
            char name[50] ;
            strcpy(name, a[i].str);
            for (j = i - 1; j >= 0 && a[j].data < temp; j--)    //�Ӻ���ǰ���Ҵ�����λ��
                a[j + 1] = a[j];                                //Ųλ
            a[j + 1].data = temp;                               //���Ƶ�����λ��
            strcpy(a[j + 1 ].str, name);
        }
}
//Ҫ��Դ�����txt�ļ�����ͬһ�ļ�����
// 

//�������Ķ�������Ļ�
//�򿪶�Ӧ��employ-data.txt�ı��ļ�
//���Ͻ�ѡ���ļ��������Ϊ
//������ı��뽫UTF - 8��ΪANSI������
//������Ϳ����������������