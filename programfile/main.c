/*����23 ������ϵͳ
1)��������
�����һ������ϵͳ����Ʒ��Ϣ������Ʒ��š����ơ��ͺš����ҡ��۸������ȣ���Ʒ��Ų��ظ�����
2) ����Ҫ��
��ϵͳӦ�������¹��ܣ�
��1����Ʒ��Ϣ¼�빦��(��Ʒ��Ϣ���ļ�����)��������?
��2����Ʒ��Ϣ������� �������?
��3����Ʒ���
��4����Ʒ����
��5����ѯ�������ܣ�
    ��1�����۸�Ӵ�С����
    ��2�������Ʋ�ѯ
��6����Ʒ��Ϣɾ��������Ʒ��ţ����޸Ĺ��ܣ�����Ʒ��ţ���
��7��ͳ�ƹ��ܣ���ѯĳ���ͺŲ�Ʒ�Ŀ�������������
��8�����棺���������Դ������档
��9����ȡ����������������ݶ����ڴ����������*/
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
        printf("beta");
        scanf("%d",&options1);
        if(options1>=0&&options1<=9){
            switch(options1){
            case 1:
            Initlist(&productions);
            printf("�����������Ʒ����Ϣ(˳��(1����Ʒ�Ĳ�Ʒ��š����ơ��ͺš����ҡ��۸�����))\n");
            scanf("%d",&options2);
            while(options2!=1||options2!=2){
                printf("�Ƿ�����,����������");
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
            //���
            break;
            case 3:
            printf("beta");
            //���
            break;
            case 4:
            printf("beta");
            //����
            break;
            case 5:
            printf("beta");
            //��ѯ
            break;
            case 6:
            printf("beta");
            //���۸�����
            break;
            case 7:
            printf("beta");
            //ͳ�Ʋ�Ʒ�Ŀ�����������
            break;
            case 8:
            printf("beta");
            //��Ʒ��Ϣɾ��������Ʒ��ţ����޸Ĺ��ܣ�����Ʒ���
            break;
            case 9:
            printf("beta");
            //�鿴����
            break;
            case 0:
            printf("beta");
            //�˳�
            break;
        }
        }else{
            printf("�������,������ѡ��\n");
            continue;
        }
    }
    
}