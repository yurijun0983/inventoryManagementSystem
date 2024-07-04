#include"functions.h"
#include"Directions.h"
#include"operations.h"
#include"definition.h"
ProLists p;
int main(){
    int options1=1;
    int options2=1;
    int options3;
    int i;
    char SearchName[40];
    while(options1)
    {
        printf("******************************************************\n    ");
        printf("\t\t秋叶原库存管理系统\n");
        printf("\t\t作者:陈豪陈祚黄忠炜\n");
        printf("按【1】使用产品录入\n");
        printf("按【2】浏览产品信息\n");
        printf("按【3】产品入库\n");
        printf("按【4】产品出库\n");
        printf("按【5】进行查询\n");
        printf("按【6】价格排序\n");
        printf("按【7】查询某一产品剩余库存\n");
        printf("按【8】修改产品信息\n");
        printf("按【9】查看帮助\n");
        printf("按【0】退出\n");
        scanf("%d",&options1);
        if(options1>=0&&options1<=9){
            switch(options1){
            case 1:
            Initlist(&p);
            printf("按【1】选择重新写入产品信息\n");
            printf("按【2】选择读取产品信息\n");
            scanf("%d",&options2);
            while(options2>2||options2<=0){
                printf("非法输入,请重新输入");
                scanf("%d",&options2);
            }
            if(options2==1){
                Initlist(&p);
                printf("请依次输入产品的信息(顺序(1个产品的产品编号、名称、型号、厂家、价格、数量))\n");
                Input(&p);
                WriteFileOne(&p);
                printf("产品信息已录入\n");
            }else if(options2==2){
                Initlist(&p);
                ReadFile(&p);
                printf("产品信息已读取\n");
            }
            break;
            case 2:
            Output(&p);//输出
            break;
            case 3:
            InputShortage(&p);//入库
            WriteFileOne(&p);
            break;
            case 4:
            printf("请输入出库产品序号\n");
            scanf("%d",&i);
            i--;
            OutputShortage(&p,i);//出库
            WriteFileOne(&p);
            break;
            case 5:
            printf("请输入名称以查找");
            getchar();
            gets(SearchName);
            int a;
            a=search(&p,SearchName);//查询
            if(a!=-1){
                printf("已找到'\n");
                printf("序号\t编号\t名称\t型号\t厂家\t价格\t数量\n");
                printf("%d\t",a+1);
        printf("%d\t",p.productions[a].SerialNumber);
        printf("%s\t",p.productions[a].name);
        printf("%s\t",p.productions[a].type);
        printf("%s\t",p.productions[a].manufacturers);
        printf("%2.lf\t",p.productions[a].price);
       printf("%d\n",p.productions[a].numbers);
            }else{
                printf("未找到该产品\n");
            }
            break;
            case 6:
            PricePirorSort(&p);
            Output(&p);//按价格排序
            break;
            case 7:
            printf("请输入出库产品序号\n");
            scanf("%d",&i);
            i--;
            unsigned int d=InquireRemaining(&p,i);
            printf("第%d个产品的剩余库存是%d\n",i,d);//统计产品的库存数量并输出
            break;
            case 8:
            printf("选择【1】删除\n选择【2】修改\n");
            scanf("%d",&options3);
            if(options3==1){
                printf("请选择删除的产品\n");
                scanf("%d",&i);
                i--;
                deletetion(&p,i);
                WriteFileOne(&p);
                printf("删除成功\n");
            }
            if(options3==2){
                printf("请选择修改的产品\n");
                scanf("%d",&i);
                i--;
                polish(&p,i);
                WriteFileOne(&p);
                printf("修改成功\n");
            }
            //产品信息删除（按产品编号）、修改功能（按产品编号
            break;
            case 9:
            help();
            break;
            case 0:
            printf("感谢使用");
            break;
        }
        }else{
            printf("输入错误,请重新选择\n");
            continue;
        }
    }
}