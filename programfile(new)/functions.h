#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "definition.h"
#include "Directions.h"
void Initlist(ProLists *p){
    p->len=0;
}//��ʼ��˳�����
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
    printf("�����������֡��������\n");
    printf("����0���������\n");
    scanf("%d",&flag);
    }
    
}//�˺����������¶�������
void Output(ProLists *p){
    printf("���\t���\t����\t�ͺ�\t����\t�۸�\t����\n");
    for(int i=0;i<p->len;i++){
        printf("%d\t",i+1);
        printf("%d\t",p->productions[i].SerialNumber);
        printf("%s\t",p->productions[i].name);
        printf("%s\t",p->productions[i].type);
        printf("%s\t",p->productions[i].manufacturers);
      printf("%2.lf\t",p->productions[i].price);
       printf("%d\n",p->productions[i].numbers);
    }
}//�˺��������������
//�˺������ڶ����ļ�������
void WriteFileOne(ProLists *p){
    if((fp=fopen("ProductInfo.txt","w"))==NULL){
        printf("�޷����ļ�");
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
        printf("�޷��ر��ļ�");
        exit(0);
    }
}//�˺�������д���ļ�����(����д��)
void ReadFile(ProLists *p){
    if((fp=fopen("ProductInfo.txt","r"))==NULL){
        printf("�޷����ļ�");
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
        printf("�޷��ر��ļ�");
        exit(0);
    }
}
void InputShortage(ProLists *p){
    int num,options,i;
    printf("����²�Ʒ�밴��0��\n�������в�Ʒ�����밴��1��\n");
    scanf("%d",&options);
    if(options==1){
        printf("��ѡ���Ʒ���");
        scanf("%d",&i);
        i--;
    printf("����������Ҫ���ӵ�������");
    scanf("%d",&num);
    p->productions[i].numbers=p->productions[i].numbers+num;
    }
    else{
          // ���Ӳ�Ʒ��������
        printf("����������Ʒ�ı�ţ�\n");
        scanf("%d", &p->productions[p->len].SerialNumber);
        printf("����������Ʒ�����֣�\n");
        scanf("%s", p->productions[p->len].name);
        printf("����������Ʒ���ͺţ�\n");
        scanf("%s", p->productions[p->len].type);
        printf("����������Ʒ�ĳ��ң�\n");
        scanf("%s", p->productions[p->len].manufacturers);
        printf("����������Ʒ�ļ۸�\n");
        scanf("%lf", &p->productions[p->len].price);
        printf("����������Ʒ��������\n");
        scanf("%d", &p->productions[p->len].numbers);
        ++(p->len);
        }
}//�˺����������
unsigned int OutputShortage(ProLists *p,int i){
    int num;
    printf("��������Ҫ�����������\n");
    scanf("%d",&num);
    p->productions[i].numbers=p->productions[i].numbers-num;
    return p->productions[i].numbers;
}//�˺������ڳ���
#endif // FUNCTIONS_H