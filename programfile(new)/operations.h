#ifndef OPERATIONS_H
#define OPERATIONS_H 
#include "definition.h"
int search(ProLists *p,char *name){
    int found=-1;
    int i;
    for(i=0;i<p->len;i++){
        if(strcmp(p->productions[i].name,name)==0){\
        found=i;
        break;
        }
    }
    return found;
}//此函数用于按名称查找
void PricePirorSort(ProLists *p){
    int i,j;
    for(i=0;i<p->len-1;i++){
        for(j=0;j<p->len-i-1;j++){
            if(p->productions[j].price> p->productions[j+1].price){
                products temp=p->productions[j];
                p->productions[j]=p->productions[j+1];
                p->productions[j+1]=temp;
            }
        }
    }
}//此函数将以价格优先排序输出'
unsigned int InquireRemaining(ProLists *p,int options){
    return p->productions[options].numbers;
}//此函数用于查看剩余库存
void deletetion(ProLists* p,int i){
    for(int j=i;j<p->len;j++){
        p->productions[j]=p->productions[j+1];
    }
    p->len--;
}//删除
void polish(ProLists *p,int i){
    int option,options1=1;
    while(options1){
        printf("请按【1】修改产品编号\n按【2】修改产品名程\n按【3】修改型号\n按【4】修改厂家\n按【5】修改价格\n按【6】修改库存");
        scanf("%d",&option);
    switch(option){
    case 1:
        scanf("%d",&p->productions[i].SerialNumber);
        break;
    case 2:
        scanf("%s",p->productions[i].name);
        break;
    case 3:
        scanf("%s",p->productions[i].type);
        break;
    case 4:
        scanf("%s",p->productions[i].manufacturers);
        break;
    case 5:
        scanf("%lf",&p->productions[i].price);
        break;
    case 6:
        scanf("%d",&p->productions[i].numbers);
        break;
    }
    printf("输入【1】继续\n输入【0】结束\n");
    scanf("%d",&options1);
    if(options1==1){
        printf("请选择修改产品位置号");
        scanf("%d",&i);
    }
    }
}//修改
int statistics(ProLists *p,char *type){
    int sum=0;
    for(int i=0;i<p->len;i++){
        if(strcmp(p->productions[i].type,type)==0)
            sum+=p->productions[i].numbers;
    }
    return sum;
}//此函数用于统计某一型号产品数量并输出
#endif // OPERATIONS_H