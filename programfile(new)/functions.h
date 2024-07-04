#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "definition.h"
#include "Directions.h"
void Initlist(ProLists *p){
    p->len=0;
}//初始化顺序表长度
void Input(ProLists *p){
    int flag=1;
    while(flag){
    scanf("%d",&p->productions[p->len].SerialNumber);
    scanf("%s",p->productions[p->len].name);
    scanf("%s",p->productions[p->len].type);
    scanf("%s",p->productions[p->len].manufacturers);
    scanf("%lf",&p->productions[p->len].price);
    scanf("%d",&p->productions[p->len].numbers);
    p->len++;
    printf("按【其它数字】继续添加\n");
    printf("按【0】结束添加\n");
    scanf("%d",&flag);
    }
    
}//此函数用于重新读入数据
void Output(ProLists *p){
    printf("序号\t编号\t名称\t型号\t厂家\t价格\t数量\n");
    for(int i=0;i<p->len;i++){
        printf("%d\t",i+1);
        printf("%d\t",p->productions[i].SerialNumber);
        printf("%s\t",p->productions[i].name);
        printf("%s\t",p->productions[i].type);
        printf("%s\t",p->productions[i].manufacturers);
      printf("%2.lf\t",p->productions[i].price);
       printf("%d\n",p->productions[i].numbers);
    }
}//此函数用于输出数据
//此函数用于读入文件中数据
void WriteFileOne(ProLists *p){
    if((fp=fopen("ProductInfo.txt","w"))==NULL){
        printf("无法打开文件");
        exit(0);
    }
    for(int i=0;i<p->len;i++){
        fprintf(fp,"%d\t",p->productions[i].SerialNumber);
        fprintf(fp,"%s\t",p->productions[i].name);
        fprintf(fp,"%s\t",p->productions[i].type);
        fprintf(fp,"%s\t",p->productions[i].manufacturers);
        fprintf(fp,"%2.lf\t",p->productions[i].price);
        fprintf(fp,"%d\t",p->productions[i].numbers);
    }
    if(fclose(fp)){
        printf("无法关闭文件");
        exit(0);
    }
}//此函数用于写入文件数据(重新写入)
void ReadFile(ProLists *p){
    if((fp=fopen("ProductInfo.txt","r"))==NULL){
        printf("无法打开文件");
        exit(0);
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&p->productions[p->len].SerialNumber);
        fscanf(fp,"%s",p->productions[p->len].name);
        fscanf(fp,"%s",p->productions[p->len].type);
        fscanf(fp,"%s",p->productions[p->len].manufacturers);
        fscanf(fp,"%lf",&p->productions[p->len].price);
        fscanf(fp,"%d\n",&p->productions[p->len].numbers);
        (p->len)++;
    }
    if(fclose(fp)){
        printf("无法关闭文件");
        exit(0);
    }
}
void InputShortage(ProLists *p){
    int num,options,i;
    printf("添加新产品请按【0】\n增加已有产品数量请按【1】\n");
    scanf("%d",&options);
    if(options==1){
        printf("请选择产品序号");
        scanf("%d",&i);
        i--;
    printf("请输入你想要增加的数量：");
    scanf("%d",&num);
    p->productions[i].numbers=p->productions[i].numbers+num;
    }
    else{
          // 增加产品数量计数
        printf("请输入入库产品的编号：\n");
        scanf("%d", &p->productions[p->len].SerialNumber);
        printf("请输入入库产品的名字：\n");
        scanf("%s", p->productions[p->len].name);
        printf("请输入入库产品的型号：\n");
        scanf("%s", p->productions[p->len].type);
        printf("请输入入库产品的厂家：\n");
        scanf("%s", p->productions[p->len].manufacturers);
        printf("请输入入库产品的价格：\n");
        scanf("%lf", &p->productions[p->len].price);
        printf("请输入入库产品的数量：\n");
        scanf("%d", &p->productions[p->len].numbers);
        ++(p->len);
        }
}//此函数用于入库
unsigned int OutputShortage(ProLists *p,int i){
    int num;
    printf("请输入你要出库的数量：\n");
    scanf("%d",&num);
    p->productions[i].numbers=p->productions[i].numbers-num;
    return p->productions[i].numbers;
}//此函数用于出库
#endif // FUNCTIONS_H