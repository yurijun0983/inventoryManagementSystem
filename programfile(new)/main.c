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
        printf("\t\t��Ҷԭ������ϵͳ\n");
        printf("\t\t����:�º���������\n");
        printf("����1��ʹ�ò�Ʒ¼��\n");
        printf("����2�������Ʒ��Ϣ\n");
        printf("����3����Ʒ���\n");
        printf("����4����Ʒ����\n");
        printf("����5�����в�ѯ\n");
        printf("����6���۸�����\n");
        printf("����7����ѯĳһ��Ʒʣ����\n");
        printf("����8���޸Ĳ�Ʒ��Ϣ\n");
        printf("����9���鿴����\n");
        printf("����0���˳�\n");
        scanf("%d",&options1);
        if(options1>=0&&options1<=9){
            switch(options1){
            case 1:
            Initlist(&p);
            printf("����1��ѡ������д���Ʒ��Ϣ\n");
            printf("����2��ѡ���ȡ��Ʒ��Ϣ\n");
            scanf("%d",&options2);
            while(options2>2||options2<=0){
                printf("�Ƿ�����,����������");
                scanf("%d",&options2);
            }
            if(options2==1){
                Initlist(&p);
                printf("�����������Ʒ����Ϣ(˳��(1����Ʒ�Ĳ�Ʒ��š����ơ��ͺš����ҡ��۸�����))\n");
                Input(&p);
                WriteFileOne(&p);
                printf("��Ʒ��Ϣ��¼��\n");
            }else if(options2==2){
                Initlist(&p);
                ReadFile(&p);
                printf("��Ʒ��Ϣ�Ѷ�ȡ\n");
            }
            break;
            case 2:
            Output(&p);//���
            break;
            case 3:
            InputShortage(&p);//���
            WriteFileOne(&p);
            break;
            case 4:
            printf("����������Ʒ���\n");
            scanf("%d",&i);
            i--;
            OutputShortage(&p,i);//����
            WriteFileOne(&p);
            break;
            case 5:
            printf("�����������Բ���");
            getchar();
            gets(SearchName);
            int a;
            a=search(&p,SearchName);//��ѯ
            if(a!=-1){
                printf("���ҵ�'\n");
                printf("���\t���\t����\t�ͺ�\t����\t�۸�\t����\n");
                printf("%d\t",a+1);
        printf("%d\t",p.productions[a].SerialNumber);
        printf("%s\t",p.productions[a].name);
        printf("%s\t",p.productions[a].type);
        printf("%s\t",p.productions[a].manufacturers);
        printf("%2.lf\t",p.productions[a].price);
       printf("%d\n",p.productions[a].numbers);
            }else{
                printf("δ�ҵ��ò�Ʒ\n");
            }
            break;
            case 6:
            PricePirorSort(&p);
            Output(&p);//���۸�����
            break;
            case 7:
            printf("����������Ʒ���\n");
            scanf("%d",&i);
            i--;
            unsigned int d=InquireRemaining(&p,i);
            printf("��%d����Ʒ��ʣ������%d\n",i,d);//ͳ�Ʋ�Ʒ�Ŀ�����������
            break;
            case 8:
            printf("ѡ��1��ɾ��\nѡ��2���޸�\n");
            scanf("%d",&options3);
            if(options3==1){
                printf("��ѡ��ɾ���Ĳ�Ʒ\n");
                scanf("%d",&i);
                i--;
                deletetion(&p,i);
                WriteFileOne(&p);
                printf("ɾ���ɹ�\n");
            }
            if(options3==2){
                printf("��ѡ���޸ĵĲ�Ʒ\n");
                scanf("%d",&i);
                i--;
                polish(&p,i);
                WriteFileOne(&p);
                printf("�޸ĳɹ�\n");
            }
            //��Ʒ��Ϣɾ��������Ʒ��ţ����޸Ĺ��ܣ�����Ʒ���
            break;
            case 9:
            help();
            break;
            case 0:
            printf("��лʹ��");
            break;
        }
        }else{
            printf("�������,������ѡ��\n");
            continue;
        }
    }
}