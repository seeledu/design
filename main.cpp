#include<stdio.h>//����108 30 ������24 ����λ��150 50
#include<string.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include <iostream>
#include<algorithm>
#define BACKGREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE)
#define BACK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED)
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)//��ɫ
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED)//��ɫ
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)//��ɫ
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED)//��ɫ
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED)//��ɫ
#define admin "daisy"//����Ա�����֤����
#include<string>
#include<queue>
#include<utility>
#include<vector>
#include<map>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
using namespace std;
int errortime=0,usernum=0,goodsnum,goodsnum2;
typedef long long ll;
#define  maxn 10005
struct customer//�û�
{
    char name[30],code[30],nick[30];
    // long long tell,age;
} user[maxn];
struct goods//��Ʒ
{
    char name[30],type[30];
    int xse,yl,bh;//���۶����,���
    double  val,jj,yye;//�ۼ�,����(average),Ӫҵ��
    time_t now;
//  goods(ll xse,ll yl ,double val,double jj):xse(xse),yl(yl),val(val),jj(jj){}
} goo[maxn],goo2[maxn];
int cmp(customer a,customer b)//�û����ֵ�������,����ʹ��2��
{
    if(strcmp(a.name,b.name)>0)
        return 0;
    return 1;
}
int cmp1(goods a,goods b)//���ﰴ���ֵ������򣬺���ʹ��2��
{
    if (strcmp(a.name,b.name)>0)
        return 0;
    return 1;
}
int cmp2(goods a,goods b)//������Ϊ�ؼ��ֽ��������ٵ���ǰ
{
    return a.yl<b.yl;
}
int cmp3(goods a,goods b)//�����۶�Ϊ�ؼ��ֽ������򣬳�������ǰ
{
    return a.xse>b.xse;
}
int cmp4(goods a,goods b)//��ʱ��Ϊ�ؼ��ֽ�������ʱ�������ǰ
{
    return a.now<b.now;
}
int cmp5(goods a,goods b)//��Ӫҵ��Ϊ�ؼ��ֽ�������Ӫҵ������ǰ
{
    return a.yye>b.yye;
}
int cmp6(goods a,goods b)//�Ա��Ϊ�ؼ��ֽ�������С����ǰ
{
    return a.bh<b.bh;
}
void information_in();//�ı�¼����Ϣ
void information_out();//��Ϣ¼���ı�
void goods_in(int n);//��Ʒ¼����Ϣ��һλ�û���Ӧһ����Ʒ��
void goods_out(int n);//��Ʒ��Ϣ����
void login();//��½����
int welcome();//��ӭ����
void regist();//ע�����
void user_interface(int n);//�û�����
void user_information(int n);//�û���Ϣ
void alter_information(int n);//�޸��û���Ϣ
int close_project(int n);//�˳�����
void  adminstrator_change(int n);// ����Աģ�飬�������Ա��Կ����޸�����������
void goods_management(int n);//��Ʒ����
void statistic_function(int n);//ͳ�ƹ���
void buy_goods(int n);//�½���Ʒ
void find_goods(int n);//��ѯ��Ʒ
void sell_goods(int n);//������Ʒ
void go(int x,int y);//����ƶ�����
void statistic_gq(int n);//Ѱ�Ҽ������ڵ���Ʒ
void statistic_xs(int n);//��Ʒ�������ͳ��
void statistic_yl(int n);//��Ʒ����ͳ��
void statistic_yye(int n);//��ƷӪҵ��ͳ��
void statistic_jh(int n);//��������
void find_goodsbh(int n);//ʹ�ö���Ѱ����Ʒ(use bh)
void friends(int n);//�鿴ĳλ�̻������һ����Ʒ
void friends(int n)
{
    //FILE FP=freopen("data.txt","r");
    int i,t;
    goods_in(n);
    system("cls");
    go(23,7),printf("��ǰ��ϵͳ�������û�\n");
    for (i=0; i<usernum; i++)
    {
        go(23,9+2*i),printf("%s",user[i].name);
    }
    char name[50];
    go(23,9+2*i),printf("�����������ѯ���û���"),scanf("%s",name);
    i+=2;
    for(t=0; t<usernum; t++)
        if(strcmp(name,user[t].name)==0)
        {   system("cls");
            go(23,11),printf("���û������һ����Ʒ�ǣ�");i+=2;
            char nam[50];
            strcpy(nam,user[t].name);
            strcat(nam,".txt");
            FILE *fp=fopen(nam,"r");
            fscanf(fp,"%d",&goodsnum2);
            for (int i=0; i<goodsnum2; i++)
            {
                fscanf(fp,"%s%lf%lf%d%d%ld%lf%d",goo2[i].name,&goo2[i].val,&goo2[i].jj,&goo2[i].xse,&goo2[i].yl,&goo2[i].now,&goo2[i].yye,&goo2[i].bh);
            }
            //freopen("CON","r",stdin);
            fclose(fp);
            sort(goo2,goo2+goodsnum2,cmp3);
            printf("%s",goo2[0].name);
            go(23,13),GREEN,printf("����"),WHITE;
            go(1,1);
                       sort(goo2,goo2+goodsnum2,cmp1);
            char ch;
            while((ch=getch())!=13);
        }

    if (t>=usernum)

    {
        //system("slc")
        go(23,9+2*i),printf("��ѯ���û������ڵģ�");

    }
      goods_out(n);
    user_interface(n);
}
void statistic_gq(int n)//Ѱ�Ҽ������ڵ���Ʒ
{
    sort(goo,goo+goodsnum,cmp4);
    time_t today=time(NULL);
    system("cls"),YELLOW;
    //cout<<"hhhhhhh"<<endl,Sleep(1000);
    int p=0,l=0,i;//l��0��ʼ��׼�����ڵ���Ʒ����p��¼
    while (today-goo[l].now>60*60*24*7&&l<goodsnum)//Ѱ�ҽ����̵����7�����Ʒ���Ѵ����
    {
        l++;
    }
    if (l>=0&&today-goo[l].now<60*60*24*7)l--;
    if (l==0&&today-goo[l].now<60*60*24*7)
    {
        go(17,9),printf("��û�н������7�����Ʒ��");
    }
    else
    {
        go(17,7),printf("��ǰ�ֿ���%d����Ʒ��س���7��",l+1);
        for (i=0; i<=l; i++)
        {
            go(17,9+i);
            printf("��Ʒ����:%s  ��Ʒ����:%d   ����ʱ��:%s",goo[i].name,goo[i].yl,ctime(&goo[i].now));
        }
        go(17,9+i),GREEN,printf("����"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        return ;
    }
    sort(goo,goo+goodsnum,cmp1);
}
void statistic_xs(int n)//��Ʒ�������ͳ��
{
    sort(goo,goo+goodsnum,cmp3);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("����ǰ%d����Ʒ��",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("���۵�%d��Ʒ����:%s  ��Ʒ����:%d",i+1,goo[i].name,goo[i].xse);

    }
    go(17,13+i),GREEN,printf("����"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void statistic_yl(int n)//��Ʒ����ͳ��
{
    sort(goo,goo+goodsnum,cmp2);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("�������ٵ�%d����Ʒ��",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("%d.��Ʒ����:%s  ��Ʒ����:%d",i+1,goo[i].name,goo[i].yl);

    }
    go(17,13+i),GREEN,printf("����"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
}
void statistic_yye(int n)//��ƷӪҵ��ͳ��
{
    sort(goo,goo+goodsnum,cmp5);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("Ӫҵ��ǰ%d����Ʒ��",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("Ӫҵ���%d��Ʒ����:%s  ��ƷӪҵ��:%.2lf",i+1,goo[i].name,goo[i].yye);

    }
    go(17,13+i),GREEN,printf("����"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void statistic_jh(int n)//��������
{
    sort(goo,goo+goodsnum,cmp5);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("���������%d����Ʒ",min(3,goodsnum));
    for (i=0; i<min(3,goodsnum); i++)
    {
        go(17,11+i),printf("��Ʒ����:%s",goo[i].name);

    }
    go(17,13+i),GREEN,printf("����"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void buy_goods(int n)//�½���Ʒ
{
    go(0,0);
    system("cls");
    YELLOW;
    go(23,7),printf("����д���Ľ�����Ϣ");
    char nam[30];
    int num1;//numΪ��ǰ���ۣ�num1λ��ǰ��������
    double num;
    go(23,9),printf("��Ʒ����"),scanf("%s",nam);
    for(int i=0; i<goodsnum; i++)
        if(strcmp(nam,goo[i].name)==0)
        {
            go(23,11),printf("����д��Ʒ����:");
            scanf("%lf",&num);
            go(23,13),printf("����д��Ʒ��������:");
            scanf("%d",&num1);
            goo[i].jj=(double)(1.0*num*num1+1.0*goo[i].jj*goo[i].yl)/(goo[i].yl+num1);
            goo[i].yl+=num1;
            goo[i].now=time(NULL);
            go(0,0),system("cls");
            go(25,9),printf("�����ɹ���"),Sleep(500);
            sort(goo,goo+goodsnum,cmp1);
            system("cls");
            return ;
        }
    goodsnum++;
    strcpy(goo[goodsnum-1].name,nam);
    //goods goo[goodsnum-1](0,0,0,0);
    go(23,11),printf("����д��Ʒ����:");
    scanf("%lf",&goo[goodsnum-1].jj);
    go(23,13),printf("����д��Ʒ��������:");
    scanf("%d",&goo[goodsnum-1].yl);
    goo[goodsnum-1].val=(double)0;
    goo[goodsnum-1].xse=(int)0;
    goo[goodsnum-1].now=time(NULL);
    goo[goodsnum-1].bh=goodsnum;
    go(0,0),system("cls");
    go(25,9),printf("�����ɹ���"),Sleep(500);
    sort(goo,goo+goodsnum,cmp1);
    //system("cls");
    return ;
}
void find_goodsna(int n)//ʹ�ö���Ѱ����Ʒ(use name)
{
    char name[50];
    go(0,0);
    system("cls");
    YELLOW;

    go(23,9),cout<<"������Ҫ��ѯ����Ʒ���ƣ�";
    scanf("%s",name);
    int l=0,r=goodsnum-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(strcmp(name,goo[mid].name)<0)r=mid-1;
        else if(strcmp(name,goo[mid].name)>0)l=mid+1;
        else
        {
            l=mid;
            break;

        }
    }
    if (goodsnum==0||strcmp(name,goo[mid].name)!=0)
    {
        system("cls");
        go(23,11),printf("������Ʒ������������"),Sleep(1000);
        //goods_management(n);
    }
    else
    {
        // system("cls");
        //  go(23,9),printf("���ҳɹ���");
        go(23,11),printf("��Ʒ���ƣ�%s\n",goo[mid].name);
        go(23,13),printf("��Ʒƽ���ۼ�:%lf\n",goo[mid].val);
        go(23,15),printf("��Ʒƽ������:%lf\n",goo[mid].jj);
        go(23,17),printf("��Ʒ������:%d\n",goo[mid].xse);
        go(23,19),printf("��Ʒ����:%d\n",goo[mid].yl);
        go(23,21),printf("��Ʒ����ʱ��:%s\n",ctime(&goo[mid].now));
        go(24,23),GREEN,printf("����"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        return ;
    }
    //Sleep(1000);
}
void find_goodsbh(int n)//ʹ�ö���Ѱ����Ʒ(use bh)
{
    int bh;
    go(0,0);
    system("cls");
    YELLOW;
    sort(goo,goo+goodsnum,cmp6);
    go(23,9),cout<<"������Ҫ��ѯ����Ʒ��ţ�";
    scanf("%d",&bh);
    int l=0,r=goodsnum-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(bh<goo[mid].bh)r=mid-1;
        else if(bh>goo[mid].bh)l=mid+1;
        else
        {
            l=mid;
            break;

        }
    }
    if (goodsnum==0||bh!=goo[mid].bh)
    {
         system("cls");
        go(23,11),printf("������Ʒ������������"),Sleep(1000);
        sort(goo,goo+goodsnum,cmp1);
        //goods_management(n);
    }
    else
    {
        //  system("cls");
        //  go(23,9),printf("���ҳɹ���");
        go(23,11),printf("��Ʒ���ƣ�%s\n",goo[mid].name);
        go(23,13),printf("��Ʒƽ���ۼ�:%lf\n",goo[mid].val);
        go(23,15),printf("��Ʒƽ������:%lf\n",goo[mid].jj);
        go(23,17),printf("��Ʒ������:%d\n",goo[mid].xse);
        go(23,19),printf("��Ʒ����:%d\n",goo[mid].yl);
        go(23,21),printf("��Ʒ����ʱ��:%s\n",ctime(&goo[mid].now));
        go(24,23),GREEN,printf("����"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        sort(goo,goo+goodsnum,cmp1);
        return ;
    }
    //Sleep(1000);
}
void sell_goods(int n)//������Ʒ
{
    go(0,0);
    system("cls");
    YELLOW;
    char name[50];
    double num;
    int num1;
    go(23,7),cout<<"������Ҫ���۵���Ʒ���ƣ�";
    scanf("%s",name);
    int l=0,r=goodsnum-1,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(strcmp(name,goo[mid].name)<0)r=mid-1;
        else if(strcmp(name,goo[mid].name)>0)l=mid+1;
        else
        {
            l=mid;
            break;
        }
    }
    if (strcmp(name,goo[mid].name)!=0)
    {
        //system("cls");
        go(23,9),printf("������Ʒ������������"),Sleep(1000);
        //goods_management(n);
    }
    else
    {
        // system("cls");
        //   go(23,9),printf("���ҳɹ���");
        go(23,11),printf("����д��Ʒ�ۼ�:");
        scanf("%lf",&num);
        go(23,13),printf("����д��Ʒ��������(<=%d):",goo[mid].yl);
        scanf("%d",&num1);
        while (num1>goo[mid].yl)
        {
            go(23,13),printf("��������д��Ʒ��������(<=%d):",goo[mid].yl);
            scanf("%d",&num1);
        }
        goo[mid].val=(double)(goo[mid].val*goo[mid].xse+1.0*num*num1)/(goo[mid].xse+num1);

        goo[mid].xse+=num1;
        goo[mid].yl-=num1;
        goo[mid].yye=(double)goo[mid].val*goo[mid].xse;
    }
}
void goods_management(int n)//��Ʒ����ģ��
{
    // go(0,0);
    system("cls");
    YELLOW;
    goods_in(n);
    go(45,2),printf("��ӭ%s^.^",user[n].nick),GREEN;
    go(22,9),printf("�½���Ʒ");
    go(22,11),printf("��Ʒ��ѯ(name)");
    go(22,13),printf("��Ʒ��ѯ(number)");
    go(22,15),printf("��Ʒ����");
    go(22,17),printf("����");
    YELLOW;
    for(int x=21; x<=34; x++)//wҲ�Ш�  �� �� �� �� �� ��
    {
        go(x,5),printf("��");
        go(x,21),printf("��");
    }
    for(int y=5; y<=21; y++)
    {
        go(21,y),printf("��");
        go(34,y),printf("��");
    }
    go(21,5),printf("��"),go(21,21),printf("��"),go(34,5),printf("��"),go(34,21),printf("��");
    char arrow[]="��";
    go(31,9),printf("%s",arrow);
    char ch;
    int now=0;
    while((ch=getch())!=13)
    {
        if(ch==80)
        {
            go(31,now*2+9),printf("  ");
            now++;
            now=now%5;
            go(31,now*2+9),printf("%s",arrow);
        }
        else if(ch==72)
        {
            go(31,now*2+9),printf("  ");
            now--;
            if(now==-1)now=4;
            go(31,now*2+9),printf("%s",arrow);
        }
    }
    switch(now)
    {
    case 0:
        // system("cls");
        buy_goods(n);
        goods_out(n);
        break;
    case 1:
        find_goodsna(n);
        break;
    case 2:
        find_goodsbh(n);
        break;
    case 3:
        sell_goods(n);
        goods_out(n);
        break;
    case 4:
        user_interface(n);
        return ;
        break;
    }
    // system("cls");
    goods_management(n);

}
void statistic_function(int n)//ͳ�ƹ���
{
    system("cls"),YELLOW;
    go(45,2),printf("��ӭ%s^.^",user[n].nick);
    //WHITE;
    go(24,7);
    goods_in(n);
    //GREEN;
    printf("����������Ʒ����");
    go(24,9);
    printf("��Ʒ�������ͳ��");
    go(24,11);
    printf("��Ʒ����ͳ��");
    go(24,13);
    printf("Ӫҵ��ͳ��");
    go(24,15);
    printf("��������");
    go(24,17);
    printf("����");
    go(24,19);
    printf("�˳�ϵͳ");
    //YELLOW;
    go(34,7);
    char arrow[]="��";
    printf("%s",arrow);
    go(0,0);
    char ch;
    int now=0;
    while((ch=getch())!=13)
    {
        if(ch==80)
        {
            go(34,now*2+7);
            printf("  ");
            now++;
            now=now%7;
            go(34,now*2+7);
            printf("%s",arrow);
            go(1,1);
        }
        else if(ch==72)
        {
            go(34,now*2+7);
            printf("  ");
            now--;
            if(now==-1)now=6;
            go(34,now*2+7);
            printf("%s",arrow);
            go(0,0);
        }
    }
    switch(now)
    {
    case 0:
        statistic_gq(n);
        break;
    case 1:
        statistic_xs(n);
        break;
    case 2:
        statistic_yl(n);
        break;
    case 3:
        statistic_yye(n);
        break;
    case 4:
        statistic_jh(n);
        break;
    case 5:
        go(0,0);
        system("cls"),YELLOW;
        user_interface(n);
        return;
    case 6:
        if(close_project(n)==0)
        {
            information_out();
            goods_out(n);
            return ;
        }
        break;
    }
    statistic_function(n);
}
void go(int x, int y) //����ƶ�����
{
    COORD c;
    c.X=2*x;
    c.Y=y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void  adminstrator_change(int n)// ����Աģ�飬�������Ա��Կ����޸�����������
{
    system("cls");
    YELLOW;
    char code[30],ch;
    int num=0;
    go(20,3),printf("���������Ա��Կ:");
    while((ch=getch())!=13)
    {
        if(ch==8)
        {
            if(num>0)
            {
                code[--num]=0;
                printf("\b \b");
            }
            else ;
        }
        else
        {
            printf("*");
            code[num++]=ch;
        }
    }
    code[num]=0;
    if (strcmp(code,admin)!=0)
    {
        system("cls");
        go(20,9),printf("����Ա��Կ�������"),Sleep(1000);
        user_interface(n);
    }
    else
    {
        go(20,5),printf("��������Ҫ�޸ĵ��û�id:");
        char name[500];
        scanf("%s",name);
        int l=0,r=usernum-1,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(strcmp(name,user[mid].name)<0)r=mid-1;
            else if(strcmp(name,user[mid].name)>0)l=mid+1;
            else
            {
                l=mid;
                break;
            }
        }
        if (strcmp(name,user[l].name)!=0)
        {
            system("cls");
            go(18,9),printf("û���ҵ������û�"),Sleep(1000);

            user_interface(n);
        }
        else
        {
            go(20,7),printf("�����������룺");
            memset(user[n].code,0,sizeof(user[n].code));
            num=0;
            while((ch=getch())!=13)
            {
                if(ch==8)
                {
                    if(num>0)
                    {
                        code[--num]=0;
                        printf("\b \b");
                    }
                    else ;
                }
                else
                {
                    printf("*");
                    code[num++]=ch;
                }
            }
            code[num]=0;
            //scanf("%s",user[n].code);
            strcpy(user[n].code,code);
            user_interface(n);
        }
    }
}
void information_in()//�ı�¼����Ϣ
{
    freopen("data.txt","r",stdin);
    scanf("%d",&usernum);
    for(int i=0; i<usernum; i++)
    {
        scanf("%s%s%s",user[i].name,user[i].code,user[i].nick);
        for (int t=0; t<strlen(user[i].code); t++)
            user[i].code[t]+=1;
        // cout<<user[i].code<<endl;
    }
    freopen("CON","r",stdin);//�ص�����̨

}
int welcome()//��ӭ����
{
    system("cls");
    //printf("%lld\n",time_t());
    for(int x=10; x<=43; x++)//wҲ�Ш�  �� �� �� �� �� ��
    {
        go(x,5),printf("������");
        go(x,17),printf("������");
    }
    for(int y=5; y<=17; y++)
    {
        go(10,y),printf("��");
        go(45,y),printf("��");
    }
    go(10,5),printf("��"),go(10,17),printf("��"),go(45,5),printf("��"),go(45,17),printf("��");
    go(20,11),GREEN,printf("��½"),BLUE;
    go(20,13),printf("ע��");
    go(20,15),printf("�˳�");
    go(0,0);
    int now=0;
    char ch;
    while((ch=getch())!=13)
    {
        if(ch==72)
        {
            now--;
            if(now==-1)now=2;
        }
        else if(ch==80)
        {
            now++;
            now=now%3;
        }
        switch(now)
        {
        case 0:
            go(20,11),GREEN,printf("��½"),BLUE;
            go(20,13),printf("ע��");
            go(20,15),printf("�˳�");
            break;
        case 1:
            go(20,11),printf("��½");
            go(20,13),GREEN,printf("ע��"),BLUE;
            go(20,15),printf("�˳�");
            break;
        case 2:
            go(20,11),printf("��½");
            go(20,13),printf("ע��");
            go(20,15),GREEN,printf("�˳�"),BLUE;
            break;
        }
        go(0,0);
    }
    if(now==0)
        login();
    else if(now==1)
        regist();
    else if(now==2)
    {
        information_out();
        return 0;
    }
}
void regist()//ע�����
{
    system("cls");
    go(23,7),printf("����ϸ��д����ע����Ϣ");
    char name[30],code[30],ch,code2[30];
    int i,num=0;
    go(23,8),printf("�û�����"),scanf("%s",name);
    for(i=0; i<usernum; i++)
        if(strcmp(name,user[i].name)==0)
        {
            system("cls");
            go(20,9),printf(" �û����ѱ�ע�ᣬ����������"),Sleep(1400);
            regist();
            return ;
        }
    go(23,9),printf("  ���룺");
    while((ch=getch())!=13||num==0)
    {
        if(ch==8)
        {
            if(num>0)
            {
                code[--num]=0;
                printf("\b \b");
            }
            else ;
        }
        else if(ch==13);
        else
        {
            printf("*");
            code[num++]=ch;
        }
    }
    code[num]=0;
    go(22,10),printf("ȷ�����룺");
    num=0;
    while((ch=getch())!=13||num==0)
    {
        if(ch==8)
        {
            if(num>0)
            {
                code[--num]=0;
                printf("\b \b");
            }
            else ;
        }
        else if(ch==13);
        else
        {
            printf("*");
            code2[num++]=ch;
        }
    }
    code2[num]=0;
    if(strcmp(code,code2)!=0)
    {
        system("cls");
        go(20,9),printf(" �������벻ͬ������������"),Sleep(2000);
        regist();
    }
    usernum++;
    go(24,11),printf("�ǳƣ�"),scanf("%s",user[usernum-1].nick);
    strcat(user[usernum-1].name,name);
    strcat(user[usernum-1].code,code);
    system("cls");
    char nam[50];
    strcpy(nam,user[usernum-1].name);
    strcat(nam,".txt");
    FILE *fp=fopen(nam,"w");
    fprintf(fp,"0\n");
    fclose(fp);
    go(25,9),printf("ע��ɹ���"),Sleep(1400);
    sort(user,user+usernum,cmp);
    welcome();
}
void login()//��½����
{

    char name[30],code[30],ch;
    int num=0;
    BLUE;
    go(23,9),printf("������һ��������exit");
    go(24,11),printf(" �˻��� "),BACK,printf("              "),BLUE;//���˻�Ϊexit������
    go(24,13),printf(" ���룺 "),BACK,printf("              "),BLUE;
    go(23,15),printf(" ��֤�룺 "),BACK,printf("              "),BLUE;
    int a=clock()%10;
    srand(time(NULL));
    int b=(rand())%3;
    srand(time(NULL));
    int c=(rand())%10,answer;
    go(36,15),WHITE;
    switch(b)
    {
    case 0:
        printf("%d��%d���ڣ�",a,c);
        answer=a+c;
        break;
    case 1:
        printf("%d��%d���ڣ�",a,c);
        answer=a-c;
        break;
    case 2:
        printf("%d��%d���ڣ�",a,c);
        answer=a*c;
        break;
    }
    int myanswer;
    go(28,11),BACK,scanf("%s",&name);
    go(28,13);
    if (strcmp(name,"exit")==0)
    {
        system("cls");
        YELLOW;
        welcome();
    }
    else
    {
        while((ch=getch())!=13)
        {
            if(ch==8)
            {
                if(num>0)
                {
                    code[--num]=0;
                    printf("\b \b");
                }
                else ;
            }
            else
            {
                printf("*");
                code[num++]=ch;
            }
        }
        code[num]=0;
        go(28,15),scanf("%d",&myanswer),WHITE;
        if(myanswer==answer)
        {
            int l=0,r=usernum-1,mid;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(strcmp(name,user[mid].name)<0)r=mid-1;
                else if(strcmp(name,user[mid].name)>0)l=mid+1;
                else
                {
                    l=mid;
                    break;
                }
            }
            if(strcmp(name,user[mid].name)!=0||strcmp(code,user[l].code))
            {
                system("cls");
                go(18,9),printf(" �˻��������������������"),Sleep(1400);
                welcome();
            }
            else
            {
                YELLOW;
                user_interface(l);
            }
        }
        else
        {
            system("cls");
            go(18,9),printf(" ��֤���������������"),Sleep(1400);
            welcome();
        }
    }
}
void user_interface(int n)//�û�����
{
    system("cls"),YELLOW;
    go(45,2),printf("��ӭ%s^.^",user[n].nick);
    //WHITE;
    go(23,7);
    //GREEN;
    printf("�鿴�û���Ϣ");
    go(23,9);
    printf("�޸��û���Ϣ");
    go(23,11);
    printf("����Ա����");
    go(24,13);
    printf("��Ʒ����");
    go(24,15);
    printf("������ͳ��");
    go(24,17);
    printf("���������");
    go(24,19);
    printf("����");
    go(24,21);
    printf("�˳�ϵͳ");
    //YELLOW;
    go(30,7);
    char arrow[]="��";
    printf("%s",arrow);
    go(0,0);
    char ch;
    int now=0;
    while((ch=getch())!=13)
    {
        if(ch==80)
        {
            go(30,now*2+7);
            printf("  ");
            now++;
            now=now%8;
            go(30,now*2+7);
            printf("%s",arrow);
            go(1,1);
        }
        else if(ch==72)
        {
            go(30,now*2+7);
            printf("  ");
            now--;
            if(now==-1)now=7;
            go(30,now*2+7);
            printf("%s",arrow);
            go(0,0);
        }
    }
    switch(now)
    {
    case 0:
        user_information(n);
        break;
    case 1:
        alter_information(n);
        break;
    case 2:
        adminstrator_change(n);
        break;
    case 3:
        goods_management(n);
        break;
    case 4:
        statistic_function(n);
        break;
    case 5:
        friends(n);
        break;
    case 6:
        go(0,0);
        system("cls"),YELLOW;
        goods_out(n);
        welcome();
        break;
    case 7:
        if(close_project(n)==0)
        {
            information_out();
            goods_out(n);
        }
        else user_interface(n);
        return ;
        break;
    }

}
void user_information(int n)//�û���Ϣ
{
    system("cls");
    go(45,2);
    YELLOW,printf("��ӭ%s^.^",user[n].nick);
    for(int x=20; x<=33; x++)//wҲ�Ш�  �� �� �� �� �� ��
    {
        go(x,5),printf("��");
        go(x,19),printf("��");
    }
    for(int y=5; y<=19; y++)
    {
        go(20,y),printf("��");
        go(33,y),printf("��");
    }
    go(20,5),printf("��"),go(20,19),printf("��"),go(33,5),printf("��"),go(33,19),printf("��");
    go(22,7),printf("�û�����%s",user[n].name);
    go(23,9),printf("�ǳƣ�%s",user[n].nick);
    go(26,21);
    GREEN,printf("����"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    user_interface(n);
}
void alter_information(int n)//�޸��û���Ϣ
{
    system("cls");
    YELLOW;
    go(45,2),printf("��ӭ%s^.^",user[n].nick),GREEN;
    go(22,7),printf("ѡ������Ҫ�޸ĵ���Ϣ");
    go(22,9),printf("����");
    go(22,11),printf("�ǳ�");
    go(22,19),printf("����");
    YELLOW;
    for(int x=21; x<=34; x++)//wҲ�Ш�  �� �� �� �� �� ��
    {
        go(x,5),printf("��");
        go(x,21),printf("��");
    }
    for(int y=5; y<=21; y++)
    {
        go(21,y),printf("��");
        go(34,y),printf("��");
    }
    go(21,5),printf("��"),go(21,21),printf("��"),go(34,5),printf("��"),go(34,21),printf("��");
    char arrow[]="��";
    go(25,9),printf("%s",arrow);
    char ch;
    int now=0;
    while((ch=getch())!=13)
    {
        if(ch==80)
        {
            go(25,now*2+9),printf("  ");
            now++;
            now=now%6;
            go(25,now*2+9),printf("%s",arrow);
        }
        else if(ch==72)
        {
            go(25,now*2+9),printf("  ");
            now--;
            if(now==-1)now=5;
            go(25,now*2+9),printf("%s",arrow);
        }
    }
    printf("\b\b  \b\b��Ϊ��");
    switch(now)
    {
    case 0:
        memset(user[n].code,0,sizeof(user[n].code));
        scanf("%s",user[n].code);
        break;
    case 1:
        memset(user[n].nick,0,sizeof(user[n].nick));
        scanf("%s",user[n].nick);
        break;
    case 5:
        break;
    }
    user_interface(n);
}
int close_project(int n)//�˳�������ȷ���˳�����0
{
    system("cls");
    YELLOW;
    go(21,11),printf("%s�����Ҫ�˳���",user[n].nick);
    go(24,14),GREEN,printf("ȷ��  "),YELLOW,printf("ȡ��");
    go(0,0);
    char ch,ch1=75;
    while((ch=getch())!=13)
    {
        //printf("%lld",ch);
        if(ch==75)
        {
            go(24,14),printf("                    ");
            go(24,14),GREEN,printf("ȷ��  "),YELLOW,printf("ȡ��");
            ch1=ch;
        }
        else if(ch==77)
        {
            go(24,14),printf("                    ");
            go(24,14),printf("ȷ��  "),GREEN,printf("ȡ��"),YELLOW;
            ch1=ch;
        }
        go(0,0);
    }
    if(ch1==75)
        return 0;
    else
        return 1;
}
void information_out()//��Ϣ¼���ı�
{
    FILE *fp=fopen("data.txt","w");
    fprintf(fp,"%d\n",usernum);
    for(int i=0; i<usernum; i++)
    {
        for (int t=0; t<strlen(user[i].code); t++)
            user[i].code[t]-=1;
        fprintf(fp,"%s %s %s\n",user[i].name,user[i].code,user[i].nick);
        for (int t=0; t<strlen(user[i].code); t++)
            user[i].code[t]+=1;
    }
    fclose(fp);
}
void goods_in(int n)//��Ʒ��Ϣ����
{
    char nam[50];
    strcpy(nam,user[n].name);
    strcat(nam,".txt");
    FILE *fp=fopen(nam,"r");
    fscanf(fp,"%d",&goodsnum);
    for (int i=0; i<goodsnum; i++)
    {
        fscanf(fp,"%s%lf%lf%d%d%ld%lf%d",goo[i].name,&goo[i].val,&goo[i].jj,&goo[i].xse,&goo[i].yl,&goo[i].now,&goo[i].yye,&goo[i].bh);
    }
    //freopen("CON","r",stdin);
    fclose(fp);
}
void goods_out(int n)//��Ʒ��Ϣ���
{
    char nam[50];
    strcpy(nam,user[n].name);
    strcat(nam,".txt");
    FILE *fp=fopen(nam,"w");
    fprintf(fp,"%d\n",goodsnum);
    for (int i=0; i<goodsnum; i++)
    {
        fprintf(fp,"%s %lf %lf %d %d %ld %lf %d\n",goo[i].name,goo[i].val,goo[i].jj,goo[i].xse,goo[i].yl,goo[i].now,goo[i].yye,goo[i].bh);
    }
    fclose(fp);
    // freopen("CON","w",stdout);
}
main()
{
    information_in();
    //goods_in();
    welcome();
    information_out();
    //user_interface(7);
}
