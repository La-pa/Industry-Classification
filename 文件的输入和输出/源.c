#include <stdio.h>
#include <string.h>

//定义结构
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
    //数据的输入
    FILE* fp;
    fp = fopen("employ-data.txt", "r");
    int j;
    for ( j = 0; j < n; j++)
    {
        fscanf(fp,"%s %d",&nums[j].str, &nums[j].data);
    }
    fclose(fp);

    //排序
    Sort(nums, n);
    
    //数据的输出
    FILE* ffp;
    ffp = fopen("employ-sort.txt", "w");
    int k;
    for (k = 0; k < n; k++)
    {
        fprintf(ffp, "%s    %d\n", nums[k].str, nums[k].data);
    }
    fclose(ffp);

    //查找
    char workname[20] ;
    printf("请输入行业名称\n");
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
            printf("查询不成功\n");
            printf("请重新输入\n");
            printf("\n");
            scanf("%s", workname);

        }
    }
    
    return 0;
}

void Sort(Node a[], int n)                                      // 降序排序
{
    int i, j;
    for (i = 1; i < n; i++)
        if (a[i].data > a[i - 1].data)
        {
            int temp = a[i].data;                               //保存要比较的值
            char name[50] ;
            strcpy(name, a[i].str);
            for (j = i - 1; j >= 0 && a[j].data < temp; j--)    //从后向前查找待插入位置
                a[j + 1] = a[j];                                //挪位
            a[j + 1].data = temp;                               //复制到插入位置
            strcpy(a[j + 1 ].str, name);
        }
}
//要将源代码和txt文件放再同一文件夹中
// 

//如果输出的都是乱码的话
//打开对应的employ-data.txt文本文件
//左上角选择文件将其另存为
//最下面的编码将UTF - 8改为ANSI并保存
//再输出就可以正常输出文字了