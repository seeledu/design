#include<stdio.h>//窗口108 30 新宋体24 窗口位置150 50
#include<string.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include <iostream>
#include<algorithm>
#define BACKGREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE)
#define BACK SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_RED)
#define BLUE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)//蓝色
#define RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED)//红色
#define GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)//绿色
#define YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED)//黄色
#define WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED)//白色
#define admin "daisy"//管理员身份验证密码
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
struct customer//用户
{
    char name[30],code[30],nick[30];
    // long long tell,age;
} user[maxn];
struct goods//商品
{
    char name[30],type[30];
    int xse,yl,bh;//销售额，余量,编号
    double  val,jj,yye;//售价,进价(average),营业额
    time_t now;
//  goods(ll xse,ll yl ,double val,double jj):xse(xse),yl(yl),val(val),jj(jj){}
} goo[maxn],goo2[maxn];
int cmp(customer a,customer b)//用户按字典序排序,后续使用2分
{
    if(strcmp(a.name,b.name)>0)
        return 0;
    return 1;
}
int cmp1(goods a,goods b)//货物按照字典序排序，后续使用2分
{
    if (strcmp(a.name,b.name)>0)
        return 0;
    return 1;
}
int cmp2(goods a,goods b)//以余量为关键字进行排序，少的在前
{
    return a.yl<b.yl;
}
int cmp3(goods a,goods b)//以销售额为关键字进行排序，畅销的在前
{
    return a.xse>b.xse;
}
int cmp4(goods a,goods b)//以时间为关键字进行排序，时间早的在前
{
    return a.now<b.now;
}
int cmp5(goods a,goods b)//以营业额为关键字进行排序，营业额大的在前
{
    return a.yye>b.yye;
}
int cmp6(goods a,goods b)//以编号为关键字进行排序，小的在前
{
    return a.bh<b.bh;
}
void information_in();//文本录入信息
void information_out();//信息录入文本
void goods_in(int n);//商品录入信息，一位用户对应一个商品库
void goods_out(int n);//商品信息导出
void login();//登陆界面
int welcome();//欢迎界面
void regist();//注册界面
void user_interface(int n);//用户界面
void user_information(int n);//用户信息
void alter_information(int n);//修改用户信息
int close_project(int n);//退出程序
void  adminstrator_change(int n);// 管理员模块，输入管理员密钥后可修改任意人密码
void goods_management(int n);//商品管理
void statistic_function(int n);//统计功能
void buy_goods(int n);//新进商品
void find_goods(int n);//查询商品
void sell_goods(int n);//销售商品
void go(int x,int y);//光标移动函数
void statistic_gq(int n);//寻找即将过期的商品
void statistic_xs(int n);//商品销售情况统计
void statistic_yl(int n);//商品余量统计
void statistic_yye(int n);//商品营业额统计
void statistic_jh(int n);//进货建议
void find_goodsbh(int n);//使用二分寻找商品(use bh)
void friends(int n);//查看某位商户最畅销的一样商品
void friends(int n)
{
    //FILE FP=freopen("data.txt","r");
    int i,t;
    goods_in(n);
    system("cls");
    go(23,7),printf("当前本系统有如下用户\n");
    for (i=0; i<usernum; i++)
    {
        go(23,9+2*i),printf("%s",user[i].name);
    }
    char name[50];
    go(23,9+2*i),printf("请输入你想查询的用户："),scanf("%s",name);
    i+=2;
    for(t=0; t<usernum; t++)
        if(strcmp(name,user[t].name)==0)
        {   system("cls");
            go(23,11),printf("该用户最畅销的一件商品是：");i+=2;
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
            go(23,13),GREEN,printf("返回"),WHITE;
            go(1,1);
                       sort(goo2,goo2+goodsnum2,cmp1);
            char ch;
            while((ch=getch())!=13);
        }

    if (t>=usernum)

    {
        //system("slc")
        go(23,9+2*i),printf("查询的用户不存在的！");

    }
      goods_out(n);
    user_interface(n);
}
void statistic_gq(int n)//寻找即将过期的商品
{
    sort(goo,goo+goodsnum,cmp4);
    time_t today=time(NULL);
    system("cls"),YELLOW;
    //cout<<"hhhhhhh"<<endl,Sleep(1000);
    int p=0,l=0,i;//l从0开始找准备过期的商品，用p记录
    while (today-goo[l].now>60*60*24*7&&l<goodsnum)//寻找进入商店大于7天的商品提醒处理掉
    {
        l++;
    }
    if (l>=0&&today-goo[l].now<60*60*24*7)l--;
    if (l==0&&today-goo[l].now<60*60*24*7)
    {
        go(17,9),printf("您没有进库大于7天的商品！");
    }
    else
    {
        go(17,7),printf("当前仓库有%d件商品库藏超过7天",l+1);
        for (i=0; i<=l; i++)
        {
            go(17,9+i);
            printf("商品名称:%s  商品余量:%d   进仓时间:%s",goo[i].name,goo[i].yl,ctime(&goo[i].now));
        }
        go(17,9+i),GREEN,printf("返回"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        return ;
    }
    sort(goo,goo+goodsnum,cmp1);
}
void statistic_xs(int n)//商品销售情况统计
{
    sort(goo,goo+goodsnum,cmp3);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("销量前%d的商品是",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("销售第%d商品名称:%s  商品销量:%d",i+1,goo[i].name,goo[i].xse);

    }
    go(17,13+i),GREEN,printf("返回"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void statistic_yl(int n)//商品余量统计
{
    sort(goo,goo+goodsnum,cmp2);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("余量最少的%d件商品是",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("%d.商品名称:%s  商品余量:%d",i+1,goo[i].name,goo[i].yl);

    }
    go(17,13+i),GREEN,printf("返回"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
}
void statistic_yye(int n)//商品营业额统计
{
    sort(goo,goo+goodsnum,cmp5);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("营业额前%d的商品是",min(5,goodsnum));
    for (i=0; i<min(5,goodsnum); i++)
    {
        go(17,11+i),printf("营业额第%d商品名称:%s  商品营业额:%.2lf",i+1,goo[i].name,goo[i].yye);

    }
    go(17,13+i),GREEN,printf("返回"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void statistic_jh(int n)//进货建议
{
    sort(goo,goo+goodsnum,cmp5);
    system("cls"),YELLOW;
    int i;
    go(17,9),printf("建议进货这%d样商品",min(3,goodsnum));
    for (i=0; i<min(3,goodsnum); i++)
    {
        go(17,11+i),printf("商品名称:%s",goo[i].name);

    }
    go(17,13+i),GREEN,printf("返回"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    sort(goo,goo+goodsnum,cmp1);
    return ;
}
void buy_goods(int n)//新进商品
{
    go(0,0);
    system("cls");
    YELLOW;
    go(23,7),printf("请填写您的进货信息");
    char nam[30];
    int num1;//num为当前进价，num1位当前进货数量
    double num;
    go(23,9),printf("货品名："),scanf("%s",nam);
    for(int i=0; i<goodsnum; i++)
        if(strcmp(nam,goo[i].name)==0)
        {
            go(23,11),printf("请填写商品进价:");
            scanf("%lf",&num);
            go(23,13),printf("请填写商品进货数量:");
            scanf("%d",&num1);
            goo[i].jj=(double)(1.0*num*num1+1.0*goo[i].jj*goo[i].yl)/(goo[i].yl+num1);
            goo[i].yl+=num1;
            goo[i].now=time(NULL);
            go(0,0),system("cls");
            go(25,9),printf("进货成功！"),Sleep(500);
            sort(goo,goo+goodsnum,cmp1);
            system("cls");
            return ;
        }
    goodsnum++;
    strcpy(goo[goodsnum-1].name,nam);
    //goods goo[goodsnum-1](0,0,0,0);
    go(23,11),printf("请填写商品进价:");
    scanf("%lf",&goo[goodsnum-1].jj);
    go(23,13),printf("请填写商品进货数量:");
    scanf("%d",&goo[goodsnum-1].yl);
    goo[goodsnum-1].val=(double)0;
    goo[goodsnum-1].xse=(int)0;
    goo[goodsnum-1].now=time(NULL);
    goo[goodsnum-1].bh=goodsnum;
    go(0,0),system("cls");
    go(25,9),printf("进货成功！"),Sleep(500);
    sort(goo,goo+goodsnum,cmp1);
    //system("cls");
    return ;
}
void find_goodsna(int n)//使用二分寻找商品(use name)
{
    char name[50];
    go(0,0);
    system("cls");
    YELLOW;

    go(23,9),cout<<"请输入要查询的商品名称：";
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
        go(23,11),printf("查无商品，请重新输入"),Sleep(1000);
        //goods_management(n);
    }
    else
    {
        // system("cls");
        //  go(23,9),printf("查找成功！");
        go(23,11),printf("商品名称：%s\n",goo[mid].name);
        go(23,13),printf("商品平均售价:%lf\n",goo[mid].val);
        go(23,15),printf("商品平均进价:%lf\n",goo[mid].jj);
        go(23,17),printf("商品销售量:%d\n",goo[mid].xse);
        go(23,19),printf("商品余量:%d\n",goo[mid].yl);
        go(23,21),printf("商品进货时间:%s\n",ctime(&goo[mid].now));
        go(24,23),GREEN,printf("返回"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        return ;
    }
    //Sleep(1000);
}
void find_goodsbh(int n)//使用二分寻找商品(use bh)
{
    int bh;
    go(0,0);
    system("cls");
    YELLOW;
    sort(goo,goo+goodsnum,cmp6);
    go(23,9),cout<<"请输入要查询的商品编号：";
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
        go(23,11),printf("查无商品，请重新输入"),Sleep(1000);
        sort(goo,goo+goodsnum,cmp1);
        //goods_management(n);
    }
    else
    {
        //  system("cls");
        //  go(23,9),printf("查找成功！");
        go(23,11),printf("商品名称：%s\n",goo[mid].name);
        go(23,13),printf("商品平均售价:%lf\n",goo[mid].val);
        go(23,15),printf("商品平均进价:%lf\n",goo[mid].jj);
        go(23,17),printf("商品销售量:%d\n",goo[mid].xse);
        go(23,19),printf("商品余量:%d\n",goo[mid].yl);
        go(23,21),printf("商品进货时间:%s\n",ctime(&goo[mid].now));
        go(24,23),GREEN,printf("返回"),WHITE;
        go(1,1);
        char ch;
        while((ch=getch())!=13);
        sort(goo,goo+goodsnum,cmp1);
        return ;
    }
    //Sleep(1000);
}
void sell_goods(int n)//销售商品
{
    go(0,0);
    system("cls");
    YELLOW;
    char name[50];
    double num;
    int num1;
    go(23,7),cout<<"请输入要销售的商品名称：";
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
        go(23,9),printf("查无商品，请重新输入"),Sleep(1000);
        //goods_management(n);
    }
    else
    {
        // system("cls");
        //   go(23,9),printf("查找成功！");
        go(23,11),printf("请填写商品售价:");
        scanf("%lf",&num);
        go(23,13),printf("请填写商品销售数量(<=%d):",goo[mid].yl);
        scanf("%d",&num1);
        while (num1>goo[mid].yl)
        {
            go(23,13),printf("请重新填写商品销售数量(<=%d):",goo[mid].yl);
            scanf("%d",&num1);
        }
        goo[mid].val=(double)(goo[mid].val*goo[mid].xse+1.0*num*num1)/(goo[mid].xse+num1);

        goo[mid].xse+=num1;
        goo[mid].yl-=num1;
        goo[mid].yye=(double)goo[mid].val*goo[mid].xse;
    }
}
void goods_management(int n)//商品管理模块
{
    // go(0,0);
    system("cls");
    YELLOW;
    goods_in(n);
    go(45,2),printf("欢迎%s^.^",user[n].nick),GREEN;
    go(22,9),printf("新进商品");
    go(22,11),printf("商品查询(name)");
    go(22,13),printf("商品查询(number)");
    go(22,15),printf("商品销售");
    go(22,17),printf("返回");
    YELLOW;
    for(int x=21; x<=34; x++)//w也行█  ━ ┃ ┓ ┗ ┏ ┛
    {
        go(x,5),printf("━");
        go(x,21),printf("━");
    }
    for(int y=5; y<=21; y++)
    {
        go(21,y),printf("┃");
        go(34,y),printf("┃");
    }
    go(21,5),printf("┏"),go(21,21),printf("┗"),go(34,5),printf("┓"),go(34,21),printf("┛");
    char arrow[]="←";
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
void statistic_function(int n)//统计功能
{
    system("cls"),YELLOW;
    go(45,2),printf("欢迎%s^.^",user[n].nick);
    //WHITE;
    go(24,7);
    goods_in(n);
    //GREEN;
    printf("即将过期商品提醒");
    go(24,9);
    printf("商品销售情况统计");
    go(24,11);
    printf("商品余量统计");
    go(24,13);
    printf("营业额统计");
    go(24,15);
    printf("进货建议");
    go(24,17);
    printf("返回");
    go(24,19);
    printf("退出系统");
    //YELLOW;
    go(34,7);
    char arrow[]="←";
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
void go(int x, int y) //光标移动函数
{
    COORD c;
    c.X=2*x;
    c.Y=y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void  adminstrator_change(int n)// 管理员模块，输入管理员密钥后可修改任意人密码
{
    system("cls");
    YELLOW;
    char code[30],ch;
    int num=0;
    go(20,3),printf("请输入管理员密钥:");
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
        go(20,9),printf("管理员密钥输入错误！"),Sleep(1000);
        user_interface(n);
    }
    else
    {
        go(20,5),printf("请输入你要修改的用户id:");
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
            go(18,9),printf("没有找到所需用户"),Sleep(1000);

            user_interface(n);
        }
        else
        {
            go(20,7),printf("请输入新密码：");
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
void information_in()//文本录入信息
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
    freopen("CON","r",stdin);//回到控制台

}
int welcome()//欢迎界面
{
    system("cls");
    //printf("%lld\n",time_t());
    for(int x=10; x<=43; x++)//w也行█  ━ ┃ ┓ ┗ ┏ ┛
    {
        go(x,5),printf("━━━");
        go(x,17),printf("━━━");
    }
    for(int y=5; y<=17; y++)
    {
        go(10,y),printf("┃");
        go(45,y),printf("┃");
    }
    go(10,5),printf("┏"),go(10,17),printf("┗"),go(45,5),printf("┓"),go(45,17),printf("┛");
    go(20,11),GREEN,printf("登陆"),BLUE;
    go(20,13),printf("注册");
    go(20,15),printf("退出");
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
            go(20,11),GREEN,printf("登陆"),BLUE;
            go(20,13),printf("注册");
            go(20,15),printf("退出");
            break;
        case 1:
            go(20,11),printf("登陆");
            go(20,13),GREEN,printf("注册"),BLUE;
            go(20,15),printf("退出");
            break;
        case 2:
            go(20,11),printf("登陆");
            go(20,13),printf("注册");
            go(20,15),GREEN,printf("退出"),BLUE;
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
void regist()//注册界面
{
    system("cls");
    go(23,7),printf("请仔细填写您的注册信息");
    char name[30],code[30],ch,code2[30];
    int i,num=0;
    go(23,8),printf("用户名："),scanf("%s",name);
    for(i=0; i<usernum; i++)
        if(strcmp(name,user[i].name)==0)
        {
            system("cls");
            go(20,9),printf(" 用户名已被注册，请重新输入"),Sleep(1400);
            regist();
            return ;
        }
    go(23,9),printf("  密码：");
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
    go(22,10),printf("确认密码：");
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
        go(20,9),printf(" 两次密码不同，请重新输入"),Sleep(2000);
        regist();
    }
    usernum++;
    go(24,11),printf("昵称："),scanf("%s",user[usernum-1].nick);
    strcat(user[usernum-1].name,name);
    strcat(user[usernum-1].code,code);
    system("cls");
    char nam[50];
    strcpy(nam,user[usernum-1].name);
    strcat(nam,".txt");
    FILE *fp=fopen(nam,"w");
    fprintf(fp,"0\n");
    fclose(fp);
    go(25,9),printf("注册成功！"),Sleep(1400);
    sort(user,user+usernum,cmp);
    welcome();
}
void login()//登陆界面
{

    char name[30],code[30],ch;
    int num=0;
    BLUE;
    go(23,9),printf("返回上一层请输入exit");
    go(24,11),printf(" 账户： "),BACK,printf("              "),BLUE;//若账户为exit，返回
    go(24,13),printf(" 密码： "),BACK,printf("              "),BLUE;
    go(23,15),printf(" 验证码： "),BACK,printf("              "),BLUE;
    int a=clock()%10;
    srand(time(NULL));
    int b=(rand())%3;
    srand(time(NULL));
    int c=(rand())%10,answer;
    go(36,15),WHITE;
    switch(b)
    {
    case 0:
        printf("%d加%d等于？",a,c);
        answer=a+c;
        break;
    case 1:
        printf("%d减%d等于？",a,c);
        answer=a-c;
        break;
    case 2:
        printf("%d乘%d等于？",a,c);
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
                go(18,9),printf(" 账户或密码出错，请重新输入"),Sleep(1400);
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
            go(18,9),printf(" 验证码出错，请重新输入"),Sleep(1400);
            welcome();
        }
    }
}
void user_interface(int n)//用户界面
{
    system("cls"),YELLOW;
    go(45,2),printf("欢迎%s^.^",user[n].nick);
    //WHITE;
    go(23,7);
    //GREEN;
    printf("查看用户信息");
    go(23,9);
    printf("修改用户信息");
    go(23,11);
    printf("管理员管理");
    go(24,13);
    printf("商品管理");
    go(24,15);
    printf("进销存统计");
    go(24,17);
    printf("别人最畅销的");
    go(24,19);
    printf("返回");
    go(24,21);
    printf("退出系统");
    //YELLOW;
    go(30,7);
    char arrow[]="←";
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
void user_information(int n)//用户信息
{
    system("cls");
    go(45,2);
    YELLOW,printf("欢迎%s^.^",user[n].nick);
    for(int x=20; x<=33; x++)//w也行█  ━ ┃ ┓ ┗ ┏ ┛
    {
        go(x,5),printf("━");
        go(x,19),printf("━");
    }
    for(int y=5; y<=19; y++)
    {
        go(20,y),printf("┃");
        go(33,y),printf("┃");
    }
    go(20,5),printf("┏"),go(20,19),printf("┗"),go(33,5),printf("┓"),go(33,19),printf("┛");
    go(22,7),printf("用户名：%s",user[n].name);
    go(23,9),printf("昵称：%s",user[n].nick);
    go(26,21);
    GREEN,printf("返回"),WHITE;
    go(1,1);
    char ch;
    while((ch=getch())!=13);
    user_interface(n);
}
void alter_information(int n)//修改用户信息
{
    system("cls");
    YELLOW;
    go(45,2),printf("欢迎%s^.^",user[n].nick),GREEN;
    go(22,7),printf("选择您想要修改的信息");
    go(22,9),printf("密码");
    go(22,11),printf("昵称");
    go(22,19),printf("返回");
    YELLOW;
    for(int x=21; x<=34; x++)//w也行█  ━ ┃ ┓ ┗ ┏ ┛
    {
        go(x,5),printf("━");
        go(x,21),printf("━");
    }
    for(int y=5; y<=21; y++)
    {
        go(21,y),printf("┃");
        go(34,y),printf("┃");
    }
    go(21,5),printf("┏"),go(21,21),printf("┗"),go(34,5),printf("┓"),go(34,21),printf("┛");
    char arrow[]="←";
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
    printf("\b\b  \b\b改为：");
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
int close_project(int n)//退出程序，若确认退出返回0
{
    system("cls");
    YELLOW;
    go(21,11),printf("%s，真的要退出吗？",user[n].nick);
    go(24,14),GREEN,printf("确认  "),YELLOW,printf("取消");
    go(0,0);
    char ch,ch1=75;
    while((ch=getch())!=13)
    {
        //printf("%lld",ch);
        if(ch==75)
        {
            go(24,14),printf("                    ");
            go(24,14),GREEN,printf("确认  "),YELLOW,printf("取消");
            ch1=ch;
        }
        else if(ch==77)
        {
            go(24,14),printf("                    ");
            go(24,14),printf("确认  "),GREEN,printf("取消"),YELLOW;
            ch1=ch;
        }
        go(0,0);
    }
    if(ch1==75)
        return 0;
    else
        return 1;
}
void information_out()//信息录入文本
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
void goods_in(int n)//商品信息读入
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
void goods_out(int n)//商品信息输出
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
