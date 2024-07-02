/*任务23 库存管理系统
1)问题描述
试设计一库存管理系统，产品信息包括产品编号、名称、型号、厂家、价格、数量等（产品编号不重复）。
2) 基本要求
该系统应具有以下功能：
（1）产品信息录入功能(产品信息用文件保存)－－输入?
（2）产品信息浏览功能 －－输出?
（3）产品入库
（4）产品出库
（5）查询和排序功能：
    （1）按价格从大到小排序
    （2）按名称查询
（6）产品信息删除（按产品编号）、修改功能（按产品编号）。
（7）统计功能：查询某种型号产品的库存数量并输出。
（8）保存：数据永久性存放至外存。
（9）读取：将存放于外存的数据读入内存继续操作。*/
#include"functions.h"
#include"Directions.h"
#include"operations.h"
#include"definition.h"
ProLists productions;
int main(){
    int options1=1;
    int options2=1;
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
        printf("beta");
        scanf("%d",&options1);
        if(options1>=0&&options1<=9){
            switch(options1){
            case 1:
            Initlist(&productions);
            printf("请依次输入产品的信息(顺序(1个产品的产品编号、名称、型号、厂家、价格、数量))\n");
            scanf("%d",&options2);
            while(options2!=1||options2!=2){
                printf("非法输入,请重新输入");
                scanf("%d",&options2);
            }
            if(options2==1){
                Initlist(&productions);
            }else if(options2==2){
                Initlist(&productions);
            }
            break;
            case 2:
            printf("beta");
            //输出
            break;
            case 3:
            printf("beta");
            //入库
            break;
            case 4:
            printf("beta");
            //出库
            break;
            case 5:
            printf("beta");
            //查询
            break;
            case 6:
            printf("beta");
            //按价格排序
            break;
            case 7:
            printf("beta");
            //统计产品的库存数量并输出
            break;
            case 8:
            printf("beta");
            //产品信息删除（按产品编号）、修改功能（按产品编号
            break;
            case 9:
            printf("beta");
            //查看帮助
            break;
            case 0:
            printf("beta");
            //退出
            break;
        }
        }else{
            printf("输入错误,请重新选择\n");
            continue;
        }
    }
    
}