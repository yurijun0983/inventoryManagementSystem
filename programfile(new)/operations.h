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
}//�˺������ڰ����Ʋ���
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
}//�˺������Լ۸������������'
unsigned int InquireRemaining(ProLists *p,int options){
    return p->productions[options].numbers;
}//�˺������ڲ鿴ʣ����
void deletetion(ProLists* p,int i){
    for(int j=i;j<p->len;j++){
        p->productions[j]=p->productions[j+1];
    }
    p->len--;
}//ɾ��
void polish(ProLists *p,int i){
    int option,options1=1;
    while(options1){
        printf("�밴��1���޸Ĳ�Ʒ���\n����2���޸Ĳ�Ʒ����\n����3���޸��ͺ�\n����4���޸ĳ���\n����5���޸ļ۸�\n����6���޸Ŀ��");
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
    printf("���롾1������\n���롾0������\n");
    scanf("%d",&options1);
    if(options1==1){
        printf("��ѡ���޸Ĳ�Ʒλ�ú�");
        scanf("%d",&i);
    }
    }
}//�޸�
int statistics(ProLists *p,char *type){
    int sum=0;
    for(int i=0;i<p->len;i++){
        if(strcmp(p->productions[i].type,type)==0)
            sum+=p->productions[i].numbers;
    }
    return sum;
}//�˺�������ͳ��ĳһ�ͺŲ�Ʒ���������
#endif // OPERATIONS_H