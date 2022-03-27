#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

/****************************************************************/
/* Global function                                              */
/****************************************************************/
void clear_screen(int direction, int color = 0);
void beep(int freq, int duration);
void end(int color);
char curser_point(int x, int y, int color);

/***************************************************************/
/*GRAPHICS CLASS                                               */
/***************************************************************/
class Graphics
{
  public:
    void first_page();
    void loading_screen();
    void sbi_logo(int x, int y);
    void user_logo(int x, int y);
    void group_members();
    void left_member(int from, int upto,int y, char name[]);
    void right_member(int from, int upto,int y, char name[]);
    void login_page();
    void menu_page();
    void button(int x, int y, int length, int color, char str[]);
    void toggle(int x, int y, int length, int color, char str[]);
    void selected(int x, int y, int length);
    void box(char str[20]);
    void box(int x, int y, int column, int row, char ch);
};

/****************************************************************/
/*Login class                                                   */
/****************************************************************/
class Login
{
   public:
   char user_name[20],password[20],user_n[20],user_p[20];
   public:
    Login()
    {
       user_name[0] = 'u';
       password[0] = 'p';
       user_n[0] = 's';
       user_p[0] = 'a';
    }
    int login();
    int signup();
    void signup_note();
};
/****************************************************************/
/*Customer class                                                */
/****************************************************************/
class Customer
{
 private:
    long account_no;
    char customer_name[20];
    char address[20];
    char nominee[20];
    float amount;
    int dd,mm,yy;
 public:
    Customer()
    {
       account_no = 1045010000;
       customer_name[0] = '\0';
       nominee[0] = '\0';
       address[0] = '\0';
       amount = 0.0;
       struct date d;
       getdate(&d);
       dd = d.da_day;
       mm = d.da_mon;
       yy = d.da_year;
    }
    void create_acc();
    void modify_acc();
    void delete_acc();
    void display_acc();
    void passbook();
    void banking();
    void help();
    char* today(int day=0, int mon = 0, int year = 0);
    void write_on_file();
};
class Account
{
  private:
    char date[20];
    long account_no;
    char customer_name[20];
    char type[20];
    char action[20];
    float amount;
  public:
    void display_tran();
    void to_file(long, char*, char*, char*, char*, float);
};
/***************************************************************/
/*GRAPHICS CLASS FUNCTION DEFNITION                            */
/***************************************************************/
void Graphics :: first_page()
{
   cleardevice();
   settextstyle(1,0,7);
   for(int i=0; i<101; i++)
   {
      int y;
      if(i<=30)
	y=i;
      else if(i<=50)
	y--;
      else if(i<=70)
	y++;
      else if(i<=80)
	y--;
      else if(i<=90)
	y++;
      else if(i<=95)
	y--;
      else
	y++;
      if(y==30)
	beep(500,20);
      setcolor(0);
      outtextxy(90,y-1,"WELCOME");
      setcolor(7);
      outtextxy(90,y,"WELCOME");
      delay(5);
   }
   for(i=-50; i<101; i++)
   {
      int y;
      if(i<=30)
	y=i;
      else if(i<=50)
	y--;
      else if(i<=70)
	y++;
      else if(i<=80)
	y--;
      else if(i<=90)
	y++;
      else if(i<=95)
	y--;
      else
	y++;
      if(y==30)
	 beep(500,20);
      setcolor(0);
      outtextxy(530-y,30,"TO");
      setcolor(7);
      outtextxy(529-y,30,"TO");
      delay(5);
   }
   for(i=-300; i<101; i++)
   {
      int y;
      if(i<=30)
	y=i;
      else if(i<=50)
	y--;
      else if(i<=70)
	y++;
      else if(i<=80)
	y--;
      else if(i<=90)
	y++;
      else if(i<=95)
	y--;
      else
	y++;
      if(y==30)
	beep(500,30);
      setcolor(0);
      outtextxy(169+y,120,"PROJECT");
      setcolor(7);
      outtextxy(170+y,120,"PROJECT");
      delay(3);
   }
   setcolor(15);
   settextstyle(7,0,4);
   outtextxy(100,260,"ON");
   for(i=-200; i<101; i++)
   {
      int y;
      if(i<=30)
	y=i;
      else if(i<=50)
	y--;
      else if(i<=70)
	y++;
      else if(i<=80)
	y--;
      else if(i<=90)
	y++;
      else if(i<=95)
	y--;
      else
	y++;
      if(y==30)
	beep(500,20);
      rectangle(150,311-y,490,411-y);
      setfillstyle(1,0);
      floodfill(150,311-y,0);
      sbi_logo(150,310-y);
      if(i<30)
	delay(10);
      else
	delay(5);
   }

   for(i=0; i<51; i++)
   {
      setcolor(i);
      settextstyle(1,0,7);
      outtextxy(90,30,"WELCOME");
      outtextxy(499,30,"TO");
      outtextxy(200,120,"PROJECT");
      settextstyle(7,0,4);
      outtextxy(100,260,"ON");
      delay(5);
   }
   delay(50);
}
void Graphics :: group_members()
{
   clear_screen(4);
   setcolor(7);
   settextstyle(1,0,6);
   left_member(-400,121,20,"GROUP MEMBER");
   settextstyle(1,0,4);
   left_member(-272,5,100,"1.ANKUSH KUMAR");
   right_member(640,320,100,"2.HARSH");
   left_member(-296,5,175,"3.SHUBHAM KUMAR");
   right_member(640,320,175,"4.AMIT RAJ");
   left_member(-238,5,250,"5.VICKY KUMAR");
   right_member(640,320,250,"6.DEVASHISH KUMAR");
   left_member(-253,5,325,"7.SHALINI KUMARI");
   right_member(640,320,325,"8.NEERA RANI");
   left_member(-253,5,400,"9.PUJA KUMARI");
   right_member(640,320,400,"10.SURUCHI KUMARI");

   for(int i=0; i<96; i++)
   {
      setcolor(i);
      settextstyle(1,0,6);
      outtextxy(121,20,"GROUP MEMBER");
      settextstyle(1,0,4);
      outtextxy(5,100,"1.ANKUSH KUMAR");
      outtextxy(320,100,"2.HARSH");
      outtextxy(5,175,"3.SHUBHAM KUMAR");
      outtextxy(320,175,"4.AMIT RAJ");
      outtextxy(5,250,"5.VICKY KUMAR");
      outtextxy(320,250,"6.DEVASHISH KUMAR");
      outtextxy(5,325,"7.SHALINI KUMARI");
      outtextxy(320,325,"8.NEERA RANI");
      outtextxy(5,400,"9.PUJA KUMARI");
      outtextxy(320,400,"10.SURUCHI KUMARI");
      delay(10);
   }
   clear_screen(4);

   int font;
   for(i = 0; i<100; i++)
   {
      font = (int)(i / 15);
      setcolor(7);
      settextstyle(1,0,4+font);
      outtextxy(320-(i*2),100-(i/2),"HARSH");
      delay(10);
      setcolor(0);
      settextstyle(1,0,4+font);
      outtextxy(320-(i*2),100-(i/2),"HARSH");
   }
   setcolor(7);
   settextstyle(1,0,4+font);
   outtextxy(120,50,"HARSH");
   settextstyle(1,0,5);
   left_member(-135,80,200,"ROLL. NO ");
   right_member(640,300,200,"2030721880");
   left_member(-107,40,275,"REG.NO ");
   right_member(640,210,275,"1726300922/2017");
   left_member(-127,100,350,"PROJECT");
   right_member(640,320,350,"DEVELOPER");
   for(i=0; i<58; i++)
   {
      setcolor(i);
      settextstyle(1,0,4+font);
      outtextxy(120,50,"HARSH");
      settextstyle(1,0,5);
      outtextxy(80,200,"ROLL. NO ");
      outtextxy(300,200,"2030721880");
      outtextxy(40,275,"REG.NO ");
      outtextxy(210,275,"1726300922/2017");
      outtextxy(100,350,"PROJECT");
      outtextxy(320,350,"DEVELOPER");
      delay(20);
   }

   clear_screen(4);

   settextstyle(1,0,6);
   left_member(-535,50,50,"PROJECT SUPERVISOR");
   settextstyle(1,0,4);
   right_member(640,160,150,"PARMANAND PRASAD");
   left_member(-203,225,225,"M.Sc. (MATHS)");
   right_member(640,155,300,"B.ED (GAWHATI UNIV.)");
   left_member(-549,50,375,"FACULTY IN NALANDA COLLEGE BCA");

   for(i=0; i<95; i++)
   {
      setcolor(i);
      settextstyle(1,0,6);
      outtextxy(50,50,"PROJECT SUPERVISOR");
      settextstyle(1,0,4);
      outtextxy(160,150,"PARMANAND PRASAD");
      outtextxy(225,225,"M.Sc. (MATHS)");
      outtextxy(155,300,"B.ED (GAWHATI UNIV.)");
      outtextxy(50,375,"FACULTY IN NALANDA COLLEGE BCA");
      delay(25);
   }
   delay(50);
}
void Graphics :: left_member(int from, int upto, int y, char name[])
{
   for(int i=from; i<=upto; i++)
   {
      setcolor(0);
      outtextxy(i-1,y,name);
      setcolor(7);
      outtextxy(i,y,name);
      delay(4);
   }
}
void Graphics :: right_member(int from, int upto, int y, char name[])
{
   for(int i=from; i>=upto; i--)
   {
      setcolor(0);
      outtextxy(i+1,y,name);
      setcolor(7);
      outtextxy(i,y,name);
      delay(4);
   }
}
void Graphics :: loading_screen()
{
   clear_screen(1);
   sbi_logo(150,50);
   settextstyle(8,0,1);
   outtextxy(240,365,"Loading");
   settextstyle(4,0,5);
   outtextxy(330,345,". . .");

   //Loding B0X
   setcolor(15);
   rectangle(100,400,540,430);
   arc(100,415,90,270,15);
   arc(540,415,270,90,15);
   setcolor(0);
   line(100,401,100,429);
   line(540,401,540,429);
   setcolor(11);
   //Loding Meter
   for(int i = 0; i<14; i++)
     ellipse(100,415,90,270,13-i,13);
   for(i = 0; i<14; i++)
     ellipse(98,415,270,90,13-i,13);
   for(i = 0; i<442; i++)
   {
     if(i%80 <= 20 )
     {
       setcolor(0);
       outtextxy(330,345,". . .");
     }
     else if(i%80 <= 40)
     {
       setcolor(14);
       outtextxy(330,345,".");
     }
     else if(i%80 <= 60)
     {
       setcolor(14);
       outtextxy(330,345,". .");
     }
     else
     {
       setcolor(14);
       outtextxy(330,345,". . .");
     }
     setcolor(11);
     arc(99+i,415,270,90,13);
     delay(10);
   }
   setcolor(0);
   settextstyle(4,0,5);
   outtextxy(330,345,". . .");
   settextstyle(8,0,1);
   outtextxy(240,365,"Loading");
   setcolor(14);
   outtextxy(240,365,"Completed.");
   int color = 0;

   while(1)
   {
      delay(40);
      if(color == 0)
      {
	 color=11;
	 sound(500);
      }
      else
	color = 0;
      setcolor(color);
      settextstyle(3,0,1);
      outtextxy(200,300,"Press Any key to continue...");
      delay(50);
      nosound();
      if(kbhit())
      {
	getch();
	break;
      }
   }
}
void Graphics :: sbi_logo(int x, int y)
{
   setcolor(1);
   rectangle(x,y,x+340,y+100);
   setfillstyle(1,1);
   floodfill(x+2,y+2,1);
   setcolor(11);
   circle(x+115,y+45,28);
   circle(x+115,y+45,10);
   setfillstyle(1,11);
   floodfill(x+115,y+30,11);
   setcolor(1);
   rectangle(x+112,y+45,x+118,y+75);
   setfillstyle(1,1);
   floodfill(x+115,y+65,1);
   setcolor(15);
   settextstyle(10,0,5);
   outtextxy(x+160,y-10,"SBI");
   setfillstyle(1,15);
   floodfill(x+175,y+45,15);
   floodfill(x+205,y+45,15);
   floodfill(x+250,y+45,15);
   setcolor(14);
   settextstyle(2,0,4);
   outtextxy(x+155,y+73,"STATE BANK OF INDIA");
}
void Graphics :: user_logo(int x, int y)
{
   setcolor(7);
   rectangle(x+5,y,x+140,y+150);
   arc(x+75,y+50,315,225,30); //head
   arc(x+43,y+88,315,60,20); //Neack
   arc(x+107,y+88,120,225,20);
   line(x+57,y+103,x+5,y+125);
   line(x+93,y+103,x+140,y+125);
   setfillstyle(1,7);
   floodfill(x+75,y+50,7);
   setfillstyle(1,1);
   floodfill(x+7,y+2,7);
}
void Graphics :: login_page()
{
   int flag,flag1;
   Login login;
   char ch;
   while(1)
   {
      clear_screen(3,9);
      flag1 = 1;flag = 0;
      user_logo(75,90);
      box("LOGIN PAGE");
      settextstyle(1,0,2);
      outtextxy(460,2,"ESC -> EXIT");
      outtextxy(50,350,"NOTE :- ");
      outtextxy(50,380,"1. SELECT LOGIN IF ALREADY A USER.");
      outtextxy(50,410,"2. SELECT SIGNUP IF YOU ARE A NEW USER.");
      button(50,280,200,2,"LOGIN");
      button(385,280,200,3,"SIGNUP");

      settextstyle(1,0,2);
      outtextxy(250,125,"Username :- //////////// ");
      outtextxy(250,175,"Password  :- ----------- ");
      while(1)
      {
	 if(kbhit())
	 {
	    ch = getch();
	    if(ch == 77 || ch == 'd' || ch == 'D' || ch == 6)
	    {
	       if(flag == 0)
	       {
		  toggle(50,280,200,3,"LOGIN");
		  toggle(385,280,200,2,"SIGNUP");
		  flag = 1;
	       }
	       else
	       {
		  toggle(50,280,200,2,"LOGIN");
		  toggle(385,280,200,3,"SIGNUP");
		  flag = 0;
	       }
	    }
	    else if(ch == 75 || ch == 'a' || ch == 'A' || ch == 4)
	    {
	       if(flag == 0)
	       {
		  toggle(50,280,200,3,"LOGIN");
		  toggle(385,280,200,2,"SIGNUP");
		  flag = 1;
	       }
	       else
	       {
		  toggle(50,280,200,2,"LOGIN");
		  toggle(385,280,200,3,"SIGNUP");
		  flag = 0;
	       }
	    }
	    else if(ch == 13)
	    {
	       if(flag == 0)
	       {
		  selected(50,280,200);
		  flag1 = login.login();
		  break;
	       }
	       else
	       {
		  selected(385,280,200);
		  login.signup();
		  break;
	       }
	    }
	    else if(ch == 27)
	    {
	       end(1); exit(0);
	    }
	 }
      }
      if(flag1 == 0)
	 break;
   }
}
void Graphics :: menu_page()
{
   int prev_btn,btn_no,temp;
   char ch;
   Customer customer;
   int flag;
   while(1)
   {
      flag = 0; prev_btn = 0; btn_no = 1; temp = 0;
      clear_screen(3,9);
      box("MENU");
      settextstyle(1,0,2);
      outtextxy(460,2,"ESC -> EXIT");
      button(70,90,200,2,"NEW ACCOUNT");
      button(370,90,200,3,"ACCOUNTS LIST");
      button(70,180,200,3,"PASSBOOK");
      button(370,180,200,3,"BANKING");
      button(70,270,200,3,"MODIFY ACCOUNT");
      button(370,270,200,3,"DELETE ACCOUNT");
      button(70,360,200,3,"HELP");
      button(370,360,200,3,"QUIT");
      while(1)
      {
	    ch = getch();
	    switch(ch)
	    {
	       case 'w':
	       case 'W':
	       case 72 : temp = -2;
	       break;
	       case 's':
	       case 'S':
	       case 80 : temp = 2;
	       break;
	       case 'd':
	       case 'D':
	       case 77 : temp = 1;
	       break;
	       case 'a':
	       case 'A':
	       case 75 : temp = -1;
	       break;
	       case 13 : temp = 13;
	       break;
	       case 27 : end(1);exit(0);
	    }
	    if(temp != 13 && temp != 0)
	       prev_btn = btn_no;
	    if(temp == -1 && btn_no == 1)
	       btn_no = 2;
	    else if(temp == 1 && btn_no == 8)
	       btn_no = 7;
	    else if(temp == -2 && btn_no == 1)
	       btn_no = 7;
	    else if(temp == -2 && btn_no == 2)
	       btn_no = 8;
	    else if(temp == 2 && btn_no == 7)
	       btn_no = 1;
	    else if(temp == 2 && btn_no == 8)
	       btn_no = 2;
	    else if(temp <= 3)
	       btn_no += temp;
	    switch(btn_no)
	    {
	       case 1: toggle(70,90,200,2,"NEW ACCOUNT");break;
	       case 2: toggle(370,90,200,2,"ACCOUNTS LIST");break;
	       case 3: toggle(70,180,200,2,"PASSBOOK");break;
	       case 4: toggle(370,180,200,2,"BANKING");break;
	       case 5: toggle(70,270,200,2,"MODIFY ACCOUNT");break;
	       case 6: toggle(370,270,200,2,"DELETE ACCOUNT");break;
	       case 7: toggle(70,360,200,2,"HELP");break;
	       case 8: toggle(370,360,200,2,"QUIT");break;
	    }
	    switch(prev_btn)
	    {
	       case 1: toggle(70,90,200,3,"NEW ACCOUNT");break;
	       case 2: toggle(370,90,200,3,"ACCOUNTS LIST");break;
	       case 3: toggle(70,180,200,3,"PASSBOOK");break;
	       case 4: toggle(370,180,200,3,"BANKING");break;
	       case 5: toggle(70,270,200,3,"MODIFY ACCOUNT");break;
	       case 6: toggle(370,270,200,3,"DELETE ACCOUNT");break;
	       case 7: toggle(70,360,200,3,"HELP");break;
	       case 8: toggle(370,360,200,3,"QUIT");break;
	    }
	    if(temp == 13)
	    {
	       switch(btn_no)
	       {
		  case 1: selected(70,90,200);
			  customer.create_acc();  flag = 1;break;
		  case 2: selected(370,90,200);
			  customer.display_acc(); flag = 1;break;
		  case 3: selected(70,180,200);
			  customer.passbook();    flag = 1;break;
		  case 4: selected(370,180,200);
			  customer.banking();     flag = 1;break;
		  case 5: selected(70,270,200);
			  customer.modify_acc();  flag = 1;break;
		  case 6: selected(370,270,200);
			  customer.delete_acc();  flag = 1;break;
		  case 7: selected(70,360,200);
			  customer.help();	  flag = 1;break;
		  case 8: selected(370,360,200);  end(1);exit(0);
	       }
	    }//if with temp
	 temp = 0;
	 if(flag == 1)
	    break;
      }//inner while
   }//outer while
}//menu closing
void Graphics :: button(int x, int y, int length, int color, char str[])
{
   int a;
   setcolor(15);
   rectangle(x,y,x+length+2,y+1);
   rectangle(x,y+2,x+1,y+52);
   setcolor(0);
   rectangle(x,y+53,x+length+4,y+54);
   rectangle(x+length+3,y,x+length+4,y+54);
   setcolor(color);
   for(int i = 0; i<51; i++)
      line(x+2,y+2+i,x+length+2,y+2+i);
   setcolor(15);
   a = (x+5+length/2)-(7*strlen(str));
   settextstyle(1,0,3);
   outtextxy(a,y+12,str);
}
void Graphics :: toggle(int x, int y, int length, int color, char str[])
{
   int a;
   setcolor(color);
   for(int i = 0; i<51; i++)
      line(x+2,y+2+i,x+length+2,y+2+i);
   setcolor(15);
   a = (x+5+length/2)-(7*strlen(str));
   settextstyle(1,0,3);
   outtextxy(a,y+12,str);
}
void Graphics :: selected(int x, int y, int length)
{
   setcolor(0);
   rectangle(x,y,x+length+2,y+1);
   rectangle(x,y+2,x+1,y+52);
   setcolor(15);
   rectangle(x,y+53,x+length+4,y+54);
   rectangle(x+length+3,y,x+length+4,y+54);
   delay(300);
   setcolor(15);
   rectangle(x,y,x+length+2,y+1);
   rectangle(x,y+2,x+1,y+52);
   setcolor(0);
   rectangle(x,y+53,x+length+4,y+54);
   rectangle(x+length+3,y,x+length+4,y+54);
   delay(400);
}
void Graphics :: box(char str[20])
{
   setcolor(15);
   //box top
   rectangle(0,0,639,30);
   rectangle(1,1,638,29);
   //box left
   rectangle(0,36,30,443);
   rectangle(1,37,29,442);
   // box right
   rectangle(609,36,639,443);
   rectangle(610,37,638,442);
   //box bottom
   rectangle(0,449,639,479);
   rectangle(1,450,638,478);
   //box center
   for(int i = 0; i<= 3; i++)
      rectangle(35+i,50+i,605-i,443-i);
   for(i = 0; i<= 40; i++)
      line(220,30+i,420,30+i); //Top white board
   setcolor(1);
   for(i = 0; i<= 26; i++)
      line(225,36+i,415,36+i); //Top blue board
   setcolor(15);
   settextstyle(1,0,2);	//Text
   outtextxy(315 - (6*strlen(str)),35,str);
}
void Graphics :: box(int x, int y, int column, int row, char ch)
{
   char ch1 = 196,ch2 = 179,corner[3];
   if(ch == ch1 || ch == ch2)
   {
      ch = 196; ch1 = 179;
      corner[0] = 218; corner[1] = 191;
      corner[2] = 192; corner[3] = 217;
   }
   else
      ch1 = ch;
   for(int i = 0; i<row; i++)
      for(int j = 0; j<column; j++)
      {
	 gotoxy(x+j,y+i);
	 if(j == 0 || j == column - 1)
	    cout<<ch1;
	 else if(i == 0 || i == row - 1)
	    cout<<ch;
	 else
	    cout<<" ";
      }
   if(ch1 == ch2)
   {
      gotoxy(x,y);
      cout<<corner[0];
      gotoxy(x+column-1,y);
      cout<<corner[1];
      gotoxy(x,y+row-1);
      cout<<corner[2];
      gotoxy(x+column-1,y+row-1);
      cout<<corner[3];
   }
}
/***************************************************************/
/*Login CLASS FUNCTION DEFNITION                               */
/***************************************************************/
int Login :: login()
{
   clear_screen(3,9);
   int i,attempt=0,flag;
   char ch;
   Graphics g;
   g.box("LOGIN PORTAL");
   g.user_logo(430,120);
   while(1)
   {
      flag = 0;
      g.button(370,350,200,3,"LOGIN");
      g.button(70,350,200,3,"CANCEL");
      settextstyle(1,0,2);
      outtextxy(460,2,"ESC -> BACK");
      ifstream fin("password");
      window(10,10,80,25);
      g.box(1,1,40,7,196);
      gotoxy(2,2);
      cout<<"Username:- ";
      gotoxy(2,5);
      cout<<"Password:- ";
      //Input Username
      i=0;
      while(1)
      {
	 ch = curser_point(176+(8*i),161,0);
	 if(ch == 13)
	    break;
	 else if(ch == 27)
	    return 1;
	 else if(ch == 8 && i >= 1 )
	 {
	    gotoxy(13+i,2);
	    cout<<" ";
	    i--;
	 }
	 else if(ch >= 97 || ch <= 122 || ch >= 65 || ch <= 90 || ch >= 48 || ch <= 57)
	    user_name[i] = ch;
	 if(ch != 8)
	 {
	    gotoxy(14+i,2);
	    cout<<ch;
	    i++;
	 }
      }
      user_name[i] = '\0';
      //Input Password
      gotoxy(14,5);
      i=0;
      while(1)
      {
	 ch = curser_point(176+(8*i),211,0);
	 if(ch == 13)
	    break;
	 else if(ch == 27)
	    return 1;
	 else if(ch == 8 && i >= 1 )
	 {
	    gotoxy(13+i,5);
	    cout<<" ";
	    i--;
	 }
	 else if(ch >= 97 || ch <= 122 || ch >= 65 || ch <= 90 || ch >= 48 || ch <= 57)
	    password[i] = ch;
	 if(ch != 8)
	 {
	    gotoxy(14+i,5);
	    cout<<"*";
	    i++;
	 }
      }
      password[i] = '\0';
      if(strlen(user_name) >= 3 && strlen(user_name) <= 15)
      {
	 while(!fin.eof())
	 {
	    fin >> user_n >> user_p;
	    if(strcmp(user_n,user_name) == 0)
	    {
	       fin.close();
	       break;
	    }
	 }
      }
      else
	 continue;
      g.button(370,350,200,2,"LOGIN");
      while(1)
      {
	 ch = getch();
	 if(ch == 77 || ch == 'd' || ch == 'D' || ch == 6)
	 {
	    if(flag == 0)
	    {
	       g.toggle(370,350,200,3,"LOGIN");
	       g.toggle(70,350,200,2,"CANCEL");
	       flag = 1;
	    }
	    else
	    {
	       g.toggle(70,350,200,3,"CANCEL");
	       g.toggle(370,350,200,2,"LOGIN");
	       flag = 0;
	    }
	 }
	 else if(ch == 75 || ch == 'a' || ch == 'A' || ch == 4)
	 {
	    if(flag == 0)
	    {
	       g.toggle(370,350,200,3,"LOGIN");
	       g.toggle(70,350,200,2,"CANCEL");
	       flag = 1;
	    }
	    else
	    {
	       g.toggle(70,350,200,3,"CANCEL");
	       g.toggle(370,350,200,2,"LOGIN");
	       flag = 0;
	    }
	 }
	 else if(ch == 13)
	 {
	    if(flag == 0)
	    {
	       g.selected(370,350,200);
	       break;
	    }
	    else
	    {
	       g.selected(70,350,200);
	       return 1;
	    }
	 }
	 else if(ch == 27)
	    return 1;
      }//while
      settextstyle(1,0,3);
      if(strcmp(user_p,password) == 0 && strcmp(user_n,user_name) == 0)
      {
	 setcolor(9);
	 outtextxy(100,450,"INVALID USERNAME OR PASSWORD");
	 while(!kbhit())
	 {
	    setcolor(10);
	    outtextxy(200,450,"LOGEDIN SUCCESSFULLY.");
	    delay(200);
	    setcolor(9);
	    outtextxy(200,450,"LOGEDIN SUCCESSFULLY.");
	    delay(100);
	 }
	 getch();
	 return 0;
      }
      else if(attempt == 5)
      {
	 setcolor(9);
	 outtextxy(100,450,"INVALID USERNAME OR PASSWORD");
	 setcolor(10);
	 outtextxy(200,450,"FIRST SIGNUP THEN LOGIN");
	 delay(500);
	 return 1;
      }
      else
      {
	 setcolor(13);
	 outtextxy(100,450,"INVALID USERNAME OR PASSWORD");
	 attempt++;
	 delay(300);
      }
   }
}
int Login :: signup()
{
   clear_screen(3,9);
   fflush(stdin);
   signup_note();
   Graphics g;
   char c_password[20],ch;
   ofstream fout("password",ios::app);
   ifstream fin("password");
   settextstyle(1,0,3);
   g.box("SIGNUP PORTAL");
   g.user_logo(430,100);
   int flag,i;
   while(1)
   {
      flag = 0;
      g.button(70,350,200,3,"CANCEL");
      g.button(370,350,200,3,"SIGN UP");
      settextstyle(1,0,2);
      outtextxy(460,2,"ESC -> BACK");
      window(10,7,80,25);
      g.box(1,1,40,10,196);
      gotoxy(2,2);
      cout<<"Username:- ";
      gotoxy(2,5);
      cout<<"Password:- ";
      gotoxy(2,8);
      cout<<"Confirm Password:- ";
      //Input Username
      i=0;
      while(1)
      {
	 ch = curser_point(176+(8*i),115,0);
	 if(ch == 13)
	    break;
	 else if(ch == 27)
	   return 0;
	 else if(ch == 8 && i >= 1 )
	 {
	    gotoxy(13+i,2);
	    cout<<" ";
	    i--;
	 }
	 else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
	    user_name[i] = ch;
	 else
	 {
	    i = 0;
	    gotoxy(2,9);
	    cout<<"Special Character not allowd.";
	    getch();
	    gotoxy(2,9);
	    cout<<"                             ";
	    fflush(stdin);
	    continue;
	 }
	 if(ch != 8)
	 {
	    gotoxy(14+i,2);
	    cout<<ch;
	    i++;
	 }
      }
      user_name[i] = '\0';
      //Checking username is available
      if(strlen(user_name) >= 3 && strlen(user_name) <= 15)
      {
	 while(!fin.eof())
	 {
	    fin >> user_n >> user_p;
	    if(strcmp(user_n,user_name) == 0)
	    {
	       flag = 1;
	       break;
	    }
	 }
      }
      else
	 flag = 1;
      if(flag == 1)
	 continue;

      //Input Password
      gotoxy(14,5);
      i=0;
      while(1)
      {
	 ch = curser_point(176+(8*i),163,0);
	 if(ch == 13)
	    break;
	 else if(ch == 27)
	   return 0;
	 else if(ch == 8 && i >= 1 )
	 {
	    gotoxy(13+i,5);
	    cout<<" ";
	    i--;
	 }
	 else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
	    password[i] = ch;
	 else
	 {
	    i = 0;
	    gotoxy(2,9);
	    cout<<"Special Character not allowd.";
	    getch();
	    gotoxy(2,9);
	    cout<<"                             ";
	    fflush(stdin);
	    continue;
	 }
	 if(ch != 8)
	 {
	    gotoxy(14+i,5);
	    cout<<"*";
	    i++;
	 }
      }
      password[i] = '\0';
      //Checking password satisfying criteria
      if(!(strlen(password) >= 3 && strlen(password) <= 15))
	 flag = 1;
      if(flag == 1)
	 continue;
      //Input confirm password
      gotoxy(22,8);
      i=0;
      while(1)
      {
	 ch = curser_point(232+(8*i),211,0);
	 if(ch == 13)
	    break;
	 else if(ch == 27)
	   return 0;
	 else if(ch == 8 && i >= 1 )
	 {
	    gotoxy(21+i,8);
	    cout<<" ";
	    i--;
	 }
	 else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
	    c_password[i] = ch;
	 else
	 {
	    i = 0;
	    gotoxy(2,9);
	    cout<<"Special Character not allowd.";
	    getch();
	    gotoxy(2,9);
	    cout<<"                             ";
	    fflush(stdin);
	    continue;
	 }
	 if(ch != 8)
	 {
	    gotoxy(21+i,8);
	    cout<<"*";
	    i++;
	 }
      }
      c_password[i] = '\0';
      g.button(370,350,200,2,"SIGN UP");
      while(1)
      {
	 ch = getch();
	 if(ch == 77 || ch == 'd' || ch == 'D')
	 {
	    if(flag == 0)
	    {
	       g.toggle(370,350,200,3,"SIGN UP");
	       g.toggle(70,350,200,2,"CANCEL");
	       flag = 1;
	    }
	    else
	    {
	       g.toggle(70,350,200,3,"CANCEL");
	       g.toggle(370,350,200,2,"SIGN UP");
	       flag = 0;
	    }
	 }
	 else if(ch == 75 || ch == 'a' || ch == 'A')
	 {
	    if(flag == 0)
	    {
	       g.toggle(370,350,200,3,"SIGN UP");
	       g.toggle(70,350,200,2,"CANCEL");
	       flag = 1;
	    }
	    else
	    {
	       g.toggle(70,350,200,3,"CANCEL");
	       g.toggle(370,350,200,2,"SIGN UP");
	       flag = 0;
	    }
	 }
	 else if(ch == 13)
	 {
	    if(flag == 0)
	    {
	       g.selected(370,350,200);
	       break;
	    }
	    else
	    {
	       g.selected(70,350,200);
	       return 0;
	    }
	 }
	 else if(ch == 27)
	   return 0;
      }
      if(strlen(password) <= 8 && strlen(password) >= 3)
	 for(i=0;i<strlen(password);i++)
	    if(!isalnum(password[i]))
	    {
	       flag = 1;
	       break;
	    }
	    else
	       flag = 0;
      if(strcmp(c_password,password) == 0 && flag == 0)
      {
	 if(fout)
	 {
	    fout << user_name <<" " << password <<"\n";
	    fout.close();
	    fin.close();
	 }
	 settextstyle(1,0,3);
	 setcolor(9);
	 outtextxy(180,450,"PASSWORD DIDNOT MATCH.");
	 while(!kbhit())
	 {
	    setcolor(10);
	    outtextxy(180,450,"SIGNED UP SUCCESSFULLY.");
	    delay(200);
	    setcolor(9);
	    outtextxy(180,450,"SIGNED UP SUCCESSFULLY.");
	    delay(100);
	 }
	 getch();
	 return 0;
      }
      else
      {
	 setcolor(15);
	 settextstyle(1,0,3);
	 outtextxy(180,450,"PASSWORD DIDNOT MATCH.");
	 delay(500);
      }
   }
}
void Login :: signup_note()
{
   Graphics g;
   g.box("");
   settextstyle(3,0,1);
   outtextxy(70,90,"# USERNAME");
   outtextxy(70,115,"1. Username should not contain space.");
   outtextxy(70,135,"2. Maximum length of username should not exceed");
   outtextxy(70,155,"   15 characters.");
   outtextxy(70,175,"3. Min length of username is 3 characters.");
   outtextxy(70,195,"4. No special characters is required in username.");
   outtextxy(70,245,"# PASSWORD");
   outtextxy(70,270,"1. Password should not contain space.");
   outtextxy(70,290,"2. Maximum length of password should not exceed");
   outtextxy(70,310,"   8 characters");
   outtextxy(70,330,"3. Min length of password is 3 characters.");
   outtextxy(70,350,"4. Password should be alphanumeric.");
   outtextxy(70,370,"5. No special characters is required in password.");
   while(1)
   {
      if(kbhit())
	 break;
      setcolor(15);
      outtextxy(230,37,"SIGNUP INSTRUCTIONS");
      setcolor(6);
      outtextxy(200,452,"PRESS ANY KEY TO CONTINUE");
      delay(150);
      setcolor(1);
      outtextxy(230,37,"SIGNUP INSTRUCTIONS");
      setcolor(9);
      outtextxy(200,452,"PRESS ANY KEY TO CONTINUE");
      delay(75);
   }
   getch();
   setcolor(9);
   for(int i = 0; i<=240; i++)
      rectangle(i,i,640-i,480-i);
}

/****************************************************************/
/*Customer CLASS FUNCTION DEFNITION                             */
/****************************************************************/
void Customer :: create_acc()
{
   int i = 0,y = 80,color=9;
   char ch1[2],ch,t_date[20],amo[20],account[20];
   Graphics g;
   ifstream fin("customer.dat",ios::app|ios::binary);
   while(fin.read((char *) this, sizeof(Customer)));
   fin.close();
   customer_name[0] = '\0';
   nominee[0] = '\0';
   address[0] = '\0';
   account_no += 1;
   clear_screen(4,color);
   g.box("ACCOUNT FORM");
   g.user_logo(456,150);
   g.button(70,350,200,3,"CANCEL");
   g.button(370,350,200,3,"SUBMIT");
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   ltoa(account_no,account,10);
   settextstyle(8,0,1);
   outtextxy(70,y,"ACCONUNT NUMBER");
   outtextxy(100,y+20,account);
   outtextxy(480,y,"DATE");
   strcpy(t_date,today());
   outtextxy(440,y+20,t_date);
   outtextxy(70,90+y,"Full name:- ");
   rectangle(265,85+y,455,115+y);
   outtextxy(70,120+y,"Address:- ");
   rectangle(265,115+y,455,145+y);
   outtextxy(70,150+y,"Nominee:- ");
   rectangle(265,145+y,455,175+y);
   outtextxy(70,180+y,"Deposit Amount:- ");
   rectangle(265,175+y,455,205+y);
   i=0;
   //Input Costmer name
   while(1)
   {
      ch = curser_point(270+(13*i),95+y,color);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 0)
	if(customer_name[0] != 32 && strlen(customer_name) <= 16)
	   break;
	else
	{
	   i=0;
	   for(int j = 0; j<=13*strlen(customer_name); j++)
	     line(270+j,90+y,270+j,110+y);
	   continue;
	 }
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 customer_name[i] = '\0';
	 for(int j = 0; j<14; j++)
	    line(270+j+(13*i),90+y,270+j+(13*i),110+y);
      }
      else if(ch == 32 || ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
      {
	 if(ch >= 97 && ch <= 122)
	    ch1[0] -= 32;
	 strcat(customer_name,ch1);
      }
      else
      {
	 i=0;
	 for(int j = 0; j<=13*strlen(customer_name); j++)
	    line(270+j,90+y,270+j,110+y);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),85+y,ch1);
	 i++;
      }
   }
   //Input Address
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),125+y,color);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 0)
	break;
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 address[i] = '\0';
	 for(int j = 0; j<14; j++)
	    line(270+j+(13*i),120+y,270+j+(13*i),140+y);
      }
      else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
      {
	 if(ch >= 97 && ch <= 122)
	    ch1[0] -= 32;
	 strcat(address,ch1);
      }
      else if(strlen(address) > 16)
      {
	 i=0;
	 for(int j = 0; j<=13*strlen(address); j++)
	    line(270+j,120+y,270+j,140+y);
	 continue;
      }
      else
      {
	 i=0;
	 for(int j = 0; j<=13*strlen(address); j++)
	    line(270+j,120+y,270+j,140+y);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),115+y,ch1);
	 i++;
      }
   }
   //Input Nominee
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),155+y,color);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 0)
      {
	 if(nominee[0] != 32 && strlen(nominee) < 17)
	    break;
	 else
	 {
	    i=0;
	    for(int j = 0; j<=(13*strlen(nominee)); j++)
	       line(270+j,150+y,270+j,170+y);
	    continue;
	 }
      }
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 nominee[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),150+y,270+j+(13*i),170+y);
      }
      else if(ch == 32 || ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
      {
	 if(ch >= 97 && ch <= 122)
	    ch1[0] -= 32;
	 strcat(nominee,ch1);
      }
      else
      {
	 i=0;
	 for(int j = 0; j<=(13*strlen(nominee)); j++)
	    line(270+j,150+y,270+j,170+y);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),145+y,ch1);
	 i++;
      }
   }
   //Depost Amount
   amo[0]='\0';
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),185+y,color);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 1)
      {
	 amount = atof(amo);
	 if(amount >= 500.0 && amount <= 100000.0)
	    break;
	 else
	 {
	    i=0;
	    for(int j = 0; j<=13*strlen(amo); j++)
	       line(270+j,180+y,270+j,200+y);
	    setcolor(10);
	    outtextxy(6,450,"AMOUNT SHOULD BE GREATER THAN 500 AND LESS THAN 1 LAKH");
	    continue;
	 }
      }
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 amo[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),180+y,270+j+(13*i),200+y);
      }
      else if(ch >= 48 && ch <= 57)
	 strcat(amo,ch1);
      else
      {
	 i=0;
	 for(int j = 0; j<12; j++)
	    line(270+j,180+y,270+j,200+y);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),175+y,ch1);
	 i++;
      }
   }
   setcolor(9);
   outtextxy(6,455,"AMOUNT SHOULD BE GREATER THAN 500 AND LESS THAN 1 LAKH");
   g.toggle(370,350,200,2,"SUBMIT");
   int flag=1;
   while(1)
   {
      ch = getch();
      if(ch == 77 || ch == 'd' || ch == 'D')
      {
	 if(flag == 0)
	 {
	    g.toggle(70,350,200,3,"CANCEL");
	    g.toggle(370,350,200,2,"SUBMIT");
	    flag = 1;
	 }
	 else
	 {
	    g.toggle(70,350,200,2,"CANCEL");
	    g.toggle(370,350,200,3,"SUBMIT");
	    flag = 0;
	 }
      }
      else if(ch == 75 || ch == 'a' || ch == 'A')
      {
	 if(flag == 0)
	 {
	    g.toggle(70,350,200,3,"CANCEL");
	    g.toggle(370,350,200,2,"SUBMIT");
	    flag = 1;
	 }
	 else
	 {
	    g.toggle(70,350,200,2,"CANCEL");
	    g.toggle(370,350,200,3,"SUBMIT");
	    flag = 0;
	 }
      }
      else if(ch == 13)
      {
	 if(flag == 1)
	 {
	    g.selected(370,350,200);
	    write_on_file();
	    while(!kbhit())
	    {
	       setcolor(10);
	       outtextxy(170,450,"ACCOUNT CREATED SUCCESSFULLY.");
	       delay(200);
	       setcolor(9);
	       outtextxy(170,450,"ACCOUNT CREATED SUCCESSFULLY.");
	       delay(100);
	    }
	    getch();
	    break;
	 }
	 else
	    return;
      }
      else if(ch == 27)
	 return;
   }//while
   delay(500);
}
void Customer :: modify_acc()
{
   clear_screen(4,9);
   Graphics g;
   g.box("MODIFY FORM");
   long acc;
   int i,y=80;
   char ch,ch1[2],accno[20],t_date[20],amo[20];
   g.user_logo(456,150);
   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   outtextxy(70,170,"ACCOUNT NO:- ");
   rectangle(265,165,455,195);
   accno[0]='\0';
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),175,9);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 1)
	    break;
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 accno[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),170,270+j+(13*i),190);
      }
      else if(ch >= 48 && ch <= 57)
	 strcat(accno,ch1);
      else
      {
	 i=0;
	 for(int j = 0; j<12; j++)
	    line(270+j,170,270+j,190);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),165,ch1);
	 i++;
      }
   }
   acc = atol(accno);
   ifstream fin("customer.dat",ios::in|ios::binary);
   ofstream fout("temp.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   int flag = 0;
   for(int j = 164; j<197; j++)
      line(70,j,456,j);
   setcolor(15);
   outtextxy(70,90+y,"Full name:- ");
   rectangle(265,85+y,455,115+y);
   outtextxy(70,120+y,"Address:- ");
   rectangle(265,115+y,455,145+y);
   outtextxy(70,150+y,"Nominee:- ");
   rectangle(265,145+y,455,175+y);
   while(fin.read((char *) this, sizeof(Customer)))
   {
      if(account_no == acc)
      {
	  customer_name[0] = '\0';
	  nominee[0] = '\0';
	  address[0] = '\0';
	  flag = 1;
	  i=0;
	  //Input Costmer name
	  while(1)
	  {
	     ch = curser_point(270+(13*i),95+y,9);
	     ch1[0] = ch;
	     ch1[1] = '\0';
	     if(ch == 13 && i > 0)
		 if(customer_name[0] != 32 && strlen(customer_name) <= 16)
		     break;
	     else
	     {
		i=0;
		for(int j = 0; j<=11*strlen(customer_name); j++)
			 line(270+j,90+y,270+j,110+y);
		    continue;
		 }
	     else if(ch == 27)
		    return;
	     else if(ch == 8 && i >= 1 )
	     {
		    i--;
		    customer_name[i] = '\0';
		for(int j = 0; j<14; j++)
			line(270+j+(13*i),90+y,270+j+(13*i),110+y);
	     }
	     else if(ch == 32 || ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
	     {
		if(ch >= 97 && ch <= 122)
		    ch1[0] -= 32;
		strcat(customer_name,ch1);
	     }
	     else
	     {
		i=0;
		for(int j = 0; j<=13*strlen(customer_name); j++)
			line(270+j,90+y,270+j,110+y);
		continue;
	     }
	     if(ch != 8)
	     {
		setcolor(15);
		outtextxy(270+(13*i),85+y,ch1);
		i++;
	     }
	  }
	  //Input Address
	  i=0;
	  while(1)
	  {
		ch = curser_point(270+(13*i),125+y,9);
		ch1[0] = ch;
		ch1[1] = '\0';
		if(ch == 13 && i > 0)
			break;
		else if(ch == 27)
			return;
		else if(ch == 8 && i >= 1 )
		{
			i--;
			address[i] = '\0';
			for(int j = 0; j<14; j++)
			   line(270+j+(13*i),120+y,270+j+(13*i),140+y);
		}
		else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
		{
			if(ch >= 97 && ch <= 122)
				ch1[0] -= 32;
			strcat(address,ch1);
		}
		else if(strlen(address) > 16)
		{
			i=0;
			for(int j = 0; j<=13*strlen(address); j++)
				line(270+j,120+y,270+j,140+y);
			continue;
		}
		else
		{
			i=0;
			for(int j = 0; j<=13*strlen(address); j++)
			line(270+j,120+y,270+j,140+y);
			continue;
		}
		if(ch != 8)
		{
			setcolor(15);
			outtextxy(270+(13*i),115+y,ch1);
			i++;
		}
	  }
	  //Input Nominee
	  i=0;
	  while(1)
	  {
		ch = curser_point(270+(13*i),155+y,9);
		ch1[0] = ch;
		ch1[1] = '\0';
		if(ch == 13 && i > 0)
		{
			if(nominee[0] != 32 && strlen(nominee) < 17)
			break;
			else
			{
				i=0;
				for(int j = 0; j<=(13*strlen(nominee)); j++)
				line(270+j,150+y,270+j,170+y);
					continue;
			}
		}
		else if(ch == 27)
			return;
		else if(ch == 8 && i >= 1 )
		{
			i--;
			nominee[i] = '\0';
			for(int j = 0; j<12; j++)
				line(270+j+(13*i),150+y,270+j+(13*i),170+y);
		}
		else if(ch == 32 || ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
		{
			if(ch >= 97 && ch <= 122)
				ch1[0] -= 32;
			strcat(nominee,ch1);
		}
		else
		{
			i=0;
			for(int j = 0; j<=(13*strlen(nominee)); j++)
				line(270+j,150+y,270+j,170+y);
			continue;
		}
		if(ch != 8)
		{
			setcolor(15);
			outtextxy(270+(13*i),145+y,ch1);
			i++;
		}
	 }
	 fout.write((char *) this, sizeof(Customer));
      }
      else
	 fout.write((char *) this, sizeof(Customer));
   }
   if(flag == 0)
   {
      setcolor(15);
      outtextxy(70,330,"ACCOUNT NUMBER NOT FOUND !!!");
   }
   else
   {
      setcolor(15);
      outtextxy(70,330,"ACCOUNT MODIFIED SUCESSFULLY !!!");
   }
   fin.close();
   fout.close();
   remove("customer.dat");
   rename("temp.dat","customer.dat");
   while(!kbhit())
   {
       setcolor(11);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(200);
       setcolor(9);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(100);
   }
   getch();
}
void Customer :: delete_acc()
{
   clear_screen(2,9);
   Graphics g;
   g.box("DELETE FORM");
   long acc;
   int i;
   char ch,ch1[2],accno[20],ch2;
   g.user_logo(456,150);
   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   outtextxy(70,170,"ACCOUNT NO:- ");
   rectangle(265,165,455,195);
   accno[0]='\0';
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),175,9);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 1)
	    break;
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 accno[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),170,270+j+(13*i),190);
      }
      else if(ch >= 48 && ch <= 57)
	 strcat(accno,ch1);
      else
      {
	 i=0;
	 for(int j = 0; j<12; j++)
	    line(270+j,170,270+j,190);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),165,ch1);
	 i++;
      }
   }
   acc = atol(accno);
   ifstream fin("customer.dat",ios::in|ios::binary);
   ofstream fout("temp.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   int flag = 0;
   for(int j = 164; j<197; j++)
      line(70,j,456,j);
   while(fin.read((char *) this, sizeof(Customer)))
   {
      if(account_no == acc)
      {
	 flag = 1;
	 setcolor(13);
	 outtextxy(60,230,"ARE YOU SURE WANT TO DELETE(Y/N)!!!");
	 while(1)
	 {
	    if(kbhit())
	    {
	       ch2 = getch();
	       if(ch2 == 'Y' || ch2 == 'y')
		  break;
	       else if(ch2 == 'N' || ch2 == 'n' || ch2 == 27)
		  return;
	    }
	 }
      }
      else
	 fout.write((char *) this, sizeof(Customer));
   }
   setcolor(9);
   outtextxy(60,230,"ARE YOU SURE WANT TO DELETE(Y/N)!!!");
   if(flag == 0)
   {
      setcolor(15);
      outtextxy(70,230,"ACCOUNT NUMBER NOT FOUND !!!");
   }
   else
   {
      setcolor(15);
      outtextxy(70,230,"ACCOUNT DELETED SUCESSFULLY !!!");
   }
   fin.close();
   fout.close();
   remove("customer.dat");
   rename("temp.dat","customer.dat");
   while(!kbhit())
   {
       setcolor(11);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(200);
       setcolor(9);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(100);
   }
   getch();
}
void Customer :: display_acc()
{
   clear_screen(2,9);
   Graphics g;
   int i,j;
   char t_date[20];
   g.box("ACCOUNTS LIST");
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   settextstyle(8,0,1);
   outtextxy(6,0,"DATE: ");
   strcpy(t_date,today());
   outtextxy(70,0,t_date);
   rectangle(60,75,580,430);
   setcolor(15);
   outtextxy(62,75,"SNO");
   outtextxy(110,75,"DATE");
   outtextxy(210,75,"ACCOUNT NO. ");
   outtextxy(360,75,"NAME");
   outtextxy(490,75,"BALANCE");
   char srn[5],accno[15],amt[20];
   int y=1,k=0,flag=0;
   ifstream fin("customer.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   while(fin.read((char *) this, sizeof(Customer)))
   {
      j=0;
      if(flag == 0)
      {
	 flag = 1;
	 for(i=105; i<430; i++)
	 {
	    if(j%60 < 30)
	       setcolor(3);
	    else
	       setcolor(11);
	    line(61,i,579,i);j++;
	 }
      }
      setcolor(15);
      itoa(y,srn,10); ltoa(account_no,accno,10); gcvt(amount,5,amt);
      strcpy(t_date,today(dd,mm,yy));
      settextstyle(8,0,0);
      setusercharsize(7, 18, 1, 2);
      outtextxy(65,108+k,srn);
      outtextxy(110,108+k,t_date);
      outtextxy(210,108+k,accno);
      outtextxy(360,108+k,customer_name);
      outtextxy(490,108+k,amt);
      y++;
      k += 30;
      if(y%12 == 0)
	flag = 0;
   }
   settextstyle(8,0,1);
   j=1;
   while(1)
   {
      if(j < 0)
	 setcolor(15);
      else
	 setcolor(9);
      outtextxy(180,450,"PRESS ANY KEY TO CONTINUE");
      delay(300);
      j *= -1;
      if(kbhit())
	 break;
   }
   getch();
}
void Customer :: passbook()
{
   clear_screen(4,9);
   long acc;
   int i;
   char ch,ch1[2],accno[20],t_date[20],amo[20];
   Graphics g;
   Account a;
   g.box("PASSBOOK");
   g.user_logo(456,150);
   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   outtextxy(70,170,"ACCOUNT NO:- ");
   rectangle(265,165,455,195);
   accno[0]='\0';
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),175,9);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 1)
	    break;
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 accno[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),170,270+j+(13*i),190);
      }
      else if(ch >= 48 && ch <= 57)
	 strcat(accno,ch1);
      else
      {
	 i=0;
	 for(int j = 0; j<12; j++)
	    line(270+j,170,270+j,190);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),165,ch1);
	 i++;
      }
   }
   acc = atol(accno);
   ifstream fin("customer.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   int flag = 0;
   while(fin.read((char *) this, sizeof(Customer)))
   {
      for(int j = 164; j<197; j++)
	 line(70,j,456,j);
      if(account_no == acc)
      {
	 setcolor(15);
	 settextstyle(8,0,1);
	 outtextxy(40,80,"ACCONUNT NUMBER");
	 outtextxy(70,100,accno);
	 outtextxy(480,80,"DATE");
	 strcpy(t_date,today(dd,mm,yy));
	 outtextxy(440,100,t_date);
	 outtextxy(70,170,"Full name:- ");
	 rectangle(265,165,455,195);
	 outtextxy(270,170,customer_name);
	 outtextxy(70,200,"Address:- ");
	 rectangle(265,195,455,225);
	 outtextxy(270,200,address);
	 outtextxy(70,230,"Nominee:- ");
	 rectangle(265,225,455,255);
	 outtextxy(270,230,nominee);
	 outtextxy(70,260,"Total Amount:- ");
	 rectangle(265,255,455,285);
	 gcvt(amount,5,amo);
	 outtextxy(270,260,amo);
	 flag = 1;
	 break;
      }
   }
   fin.close();
   if(flag == 0)
   {
      setcolor(15);
      outtextxy(70,230,"ACCOUNT NUMBER NOT FOUND !!!");
   }
   while(!kbhit())
   {
       setcolor(10);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(200);
       setcolor(9);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(100);
   }
   getch();
   if(flag == 1)
   {
      setcolor(15);
      outtextxy(270,80,customer_name);
      outtextxy(280,100,address);
      a.display_tran();
   }
}
void Customer :: banking()
{
   clear_screen(2,9);
   Graphics g;
   g.box("BANKING");
   long acc;
   int i;
   char ch,ch1[2],accno[20],type[10],action[10],t_date[20],amo[20];
   float amou;
   g.user_logo(456,150);
   setcolor(15);
   settextstyle(1,0,2);
   outtextxy(460,2,"ESC -> BACK");
   outtextxy(70,170,"ACCOUNT NO:- ");
   rectangle(265,165,455,195);
   accno[0]='\0';
   i=0;
   while(1)
   {
      ch = curser_point(270+(13*i),175,9);
      ch1[0] = ch;
      ch1[1] = '\0';
      if(ch == 13 && i > 1)
	    break;
      else if(ch == 27)
	 return;
      else if(ch == 8 && i >= 1 )
      {
	 i--;
	 accno[i] = '\0';
	 for(int j = 0; j<12; j++)
	    line(270+j+(13*i),170,270+j+(13*i),190);
      }
      else if(ch >= 48 && ch <= 57)
	 strcat(accno,ch1);
      else
      {
	 i=0;
	 for(int j = 0; j<12; j++)
	    line(270+j,170,270+j,190);
	 continue;
      }
      if(ch != 8)
      {
	 setcolor(15);
	 outtextxy(270+(13*i),165,ch1);
	 i++;
      }
   }
   acc = atol(accno);
   Account a;
   ifstream fin("customer.dat",ios::in|ios::binary);
   ofstream fout("temp.dat",ios::out|ios::binary);
   fin.seekg(0,ios::beg);
   int flag = 0;
   for(int j = 164; j<197; j++)
      line(70,j,456,j);
   setcolor(15);
   outtextxy(70,80,"ACCONUNT NUMBER");
   outtextxy(100,100,accno);
   outtextxy(480,80,"DATE");
   strcpy(t_date,today());
   outtextxy(440,100,t_date);
   outtextxy(70,170,"Cash/Cheque:- ");
   rectangle(275,165,455,195);
   outtextxy(70,200,"Deposite/Withdraw:- ");
   rectangle(275,195,455,225);
   outtextxy(70,230,"Amount:- ");
   rectangle(275,225,455,255);
   while(fin.read((char *) this, sizeof(Customer)))
   {
      if(account_no == acc)
      {
	  flag = 1;
	  setcolor(9);
	  i=0; type[0] = '\0';
	  while(1)
	  {
		ch = curser_point(280+(13*i),175,9);
		ch1[0] = ch;
		ch1[1] = '\0';
		if(ch == 13 && i > 0)
		   if(strcmp(type,"CASH") == 0 || strcmp(type,"CHEQUE") == 0)
		      break;
		   else
		   {
		      i=0;
		      for(int j = 0; j<=13*strlen(type); j++)
			 line(280+j,170,280+j,190);
		      continue;
		   }
		else if(ch == 27)
		   return;
		else if(ch == 8 && i >= 1 )
		{
		   i--;
		   type[i] = '\0';
		   for(int j = 0; j<14; j++)
		      line(280+j+(13*i),170,280+j+(13*i),190);
		}
		else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
		{
		   if(ch >= 97 && ch <= 122)
		      ch1[0] -= 32;
		   strcat(type,ch1);
		}
		else if(strlen(type) > 16)
		{
		   i=0;
		   for(int j = 0; j<=13*strlen(type); j++)
		      line(280+j,170,280+j,190);
		   continue;
		}
		else
		{
		   i=0;
		   for(int j = 0; j<=13*strlen(type); j++)
		      line(280+j,170,280+j,190);
		   continue;
		}
		if(ch != 8)
		{
			setcolor(15);
			outtextxy(280+(13*i),165,ch1);
			i++;
		}
	  }
	  //Input Action (deposite/withdraw)
	  i=0;action[0] = '\0';
	  while(1)
	  {
		ch = curser_point(280+(13*i),205,9);
		ch1[0] = ch;
		ch1[1] = '\0';
		if(ch == 13 && i > 0)
		   if(strcmp(action,"DEPOSITE") == 0 || strcmp(action,"WITHDRAW") == 0)
		      break;
		   else
		   {
		      i=0;
		      for(int j = 0; j<=13*strlen(action); j++)
			 line(280+j,200,280+j,220);
		      continue;
		   }
		else if(ch == 27)
		   return;
		else if(ch == 8 && i >= 1 )
		{
		   i--;
		   action[i] = '\0';
		   for(int j = 0; j<14; j++)
		      line(280+j+(13*i),200,280+j+(13*i),220);
		}
		else if(ch >= 97 && ch <= 122 || ch >= 65 && ch <= 90 || ch >= 48 && ch <= 57)
		{
		   if(ch >= 97 && ch <= 122)
		      ch1[0] -= 32;
		   strcat(action,ch1);
		}
		else if(strlen(action) > 16)
		{
		   i=0;
		   for(int j = 0; j<=13*strlen(action); j++)
		      line(280+j,200,280+j,220);
		   continue;
		}
		else
		{
		   i=0;
		   for(int j = 0; j<=13*strlen(action); j++)
		      line(280+j,200,280+j,220);
		   continue;
		}
		if(ch != 8)
		{
			setcolor(15);
			outtextxy(280+(13*i),195,ch1);
			i++;
		}
	  }
	  //Input amount
	  amo[0]='\0'; i=0;
	  while(1)
	  {
	     ch = curser_point(280+(13*i),235,9);
	     ch1[0] = ch;
	     ch1[1] = '\0';
	     if(ch == 13 && i > 1)
	     {
		amou = atof(amo);
		break;
	     }
	     else if(ch == 27)
		return;
	     else if(ch == 8 && i >= 1 )
	     {
		i--;
		amo[i] = '\0';
		for(int j = 0; j<12; j++)
		   line(280+j+(13*i),230,280+j+(13*i),250);
	     }
	     else if(ch >= 48 && ch <= 57)
		strcat(amo,ch1);
	     else
	     {
		i=0;
		for(int j = 0; j<12; j++)
		   line(280+j,230,280+j,250);
		continue;
	      }
	      if(ch != 8)
	      {
		 setcolor(15);
		 outtextxy(280+(13*i),225,ch1);
		 i++;
	      }
	  }
	  if(strcmp(action,"DEPOSITE") == 0)
	     amount += amou;
	  else
	     amount -= amou;
	  fout.write((char*) this,sizeof(Customer));
	  a.to_file(acc,t_date,customer_name,type,action,amou);
      }
      else
	 fout.write((char*) this,sizeof(Customer));
   }
   if(flag == 0)
   {
      setcolor(15);
      outtextxy(70,330,"ACCOUNT NUMBER NOT FOUND !!!");
   }
   else
   {
      setcolor(15);
      outtextxy(70,330,"TRANSECTION SUCCESSFULL !!!");
   }
   fin.close();
   fout.close();
   remove("customer.dat");
   rename("temp.dat","customer.dat");
   while(!kbhit())
   {
       setcolor(11);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(200);
       setcolor(9);
       outtextxy(170,450,"PRESS ANY KETY TO CONTINUE.");
       delay(100);
   }
   getch();
}
void Customer :: write_on_file()
{
   Account a;
   char t_date[20];
   ofstream fo("customer.dat",ios::app|ios::binary);
   fo.write((char *) this, sizeof(Customer));
   strcpy(t_date,today());
   a.to_file(account_no,t_date,customer_name,"INITAL","DEPOSITE",amount);
   fo.close();
}
void Customer :: help()
{
   clear_screen(4,9);
   Graphics g;
   g.box("HELP");
   settextstyle(3,0,1);
   outtextxy(70,90,"WELCOME TO THE PROJECT ON SBI BANK");
   outtextxy(70,115,"1. Username should not contain space.");
   outtextxy(70,135,"2. Maximum length of username should not exceed");
   outtextxy(70,155,"   15 characters.");
   outtextxy(70,175,"3. Min length of username is 3 characters.");
   outtextxy(70,195,"4. No special characters is required in password.");
   outtextxy(70,245,"# PASSWORD");
   outtextxy(70,270,"1. Password should not contain space.");
   outtextxy(70,290,"2. Maximum length of password should not exceed");
   outtextxy(70,310,"   8 characters");
   outtextxy(70,330,"3. Min length of username is 3 characters.");
   outtextxy(70,350,"4. Password should be alphanumeric.");
   outtextxy(70,370,"5. No special characters is required in password.");
   while(1)
   {
      if(kbhit())
	 break;
      setcolor(10);
      outtextxy(200,452,"PRESS ANY KEY TO CONTINUE");
      delay(150);
      setcolor(9);
      outtextxy(200,452,"PRESS ANY KEY TO CONTINUE");
      delay(75);
   }
   getch();
   setcolor(9);
   for(int i = 0; i<=240; i++)
      rectangle(i,i,640-i,480-i);
}
char* Customer :: today(int day, int mon, int year)
{
   char t_day[20],temp1[15],temp2[15],temp3[15];
   int i = 0,j=0,d1,m1,y1;
   temp1[0] = temp2[0] = temp3[0] = '\0';
   struct date d;
   getdate(&d);
   d1 = d.da_day;
   m1 = d.da_mon;
   y1 = d.da_year;
   if(day == 0)
   {
      itoa(d1,temp1,10);
      itoa(m1,temp2,10);
      itoa(y1,temp3,10);
   }
   else
   {
      itoa(day,temp1,10);
      itoa(mon,temp2,10);
      itoa(year,temp3,10);
   }
   while(temp1[i] != '\0')
   {
      t_day[j] = temp1[i];
      i++;j++;
   }
   t_day[j]=47;j++;i=0;
   while(temp2[i] != '\0')
   {
      t_day[j] = temp2[i];
      i++;j++;
   }
   t_day[j]=47;j++;i=0;
   while(temp3[i] != '\0')
   {
      t_day[j] = temp3[i];
      i++;j++;
   }t_day[j]='\0';
   return t_day;
}
/***************************************************************/
/*Account CLASS FUNCTION DEFNITION                             */
/***************************************************************/
void Account :: to_file(long accno, char t_date[20], char name[20],
			char c_type[20], char act[20], float amo)
{
   strcpy(date,t_date);
   account_no = accno;
   strcpy(customer_name,name);
   strcpy(type,c_type);
   strcpy(action,act);
   amount = amo;
   ofstream fout("account.dat",ios::app|ios::binary);
   fout.write((char*) this, sizeof(Account));
   fout.close();
}
void Account :: display_tran()
{
   int i,j;
   char t_date[20];
   settextstyle(8,0,1);
   setcolor(9);
   for(i = 140; i<= 350; i++)
      line(60,i,600,i);
   setcolor(15);
   outtextxy(62,135,"SNO");
   outtextxy(105,135,"DATE");
   outtextxy(190,135,"MODE");
   outtextxy(260,135,"DEPOSITE");
   outtextxy(370,135,"WITHDRAW");
   outtextxy(490,135,"BALANCE");
   char srn[5],amt[20];
   int y=1,k=0,flag=0;
   ifstream fin("account.dat",ios::in|ios::binary);
   fin.seekg(0,ios::beg);
   while(fin.read((char *) this, sizeof(Account)))
   {
      j=0;
      if(flag == 0)
      {
	 flag = 1;
	 for(i=165; i<430; i++)
	 {
	    if(j%60 < 30)
	       setcolor(3);
	    else
	       setcolor(11);
	    line(61,i,579,i);j++;
	 }
      }
      setcolor(15);
      itoa(y,srn,10); gcvt(amount,5,amt);
      settextstyle(8,0,0);
      setusercharsize(7, 18, 1, 2);
      outtextxy(65,168+k,srn);
      outtextxy(105,168+k,date);
      outtextxy(190,168+k,type);
      if(strcmp(action,"DEPOSITE") == 0)
	 outtextxy(260,168+k,action);
      else
	 outtextxy(370,168+k,action);
      outtextxy(490,168+k,amt);
      y++;
      k += 30;
      if(y%10 == 0)
	flag = 0;
   }
   settextstyle(8,0,1);
   j=1;
   while(1)
   {
      if(j < 0)
	 setcolor(15);
      else
	 setcolor(9);
      outtextxy(180,450,"PRESS ANY KEY TO CONTINUE");
      delay(300);
      j *= -1;
      if(kbhit())
	 break;
   }
   getch();
}
/***************************************************************/
/*GLOBEL FUNCTION DEFNITION                                    */
/***************************************************************/
char curser_point(int x, int y, int color)
{
   while(1)
   {
      if(kbhit())
	 return getch();
      else
      {
      setcolor(15);
      line(x,y-5,x,y+15);
      delay(300);
      setcolor(color);
      line(x,y-5,x,y+15);
      delay(200);
      }
   }
}
void clear_screen(int direction, int color)
{
   //direction = 1    top to bottom
   //direction = 2    right to left
   //direction = 3    bottom to top
   //direction = 4    left to right
   setcolor(color);
   int start, end, dir = 1;
   if(direction == 1 || direction == 3)
   {
      if(direction == 1)
      {
	 end = 0;
	 dir = -1;
      }
      else
	 end = 481;
      for(start = 0; start<=482; start++)
      {
	sound(663-start);
	line(0,end-(start*dir),642,end-(start*dir));
	delay(2);
      }
      nosound();
   }
   else
   {
      if(direction == 2)
	 end = 641;
      else
      {
	 end = 0;
	 dir = -1;
      }
      for(start = 0; start<=642; start++)
      {
	sound(663-start);
	line(end-(start*dir),0,end-(start*dir),482);
	delay(2);
      }nosound();
   }
}
void end(int color)
{
   setcolor(color);
   for(int i = 0; i<=240; i++)
   {
      rectangle(i,i,640-i,480-i);
      sound(520-2*i);
      delay(5);
   }
   nosound();
}
void beep(int freq, int duration)
{
   sound(freq);
   delay(duration);
   nosound();
}
void main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"..//bgi");
   Graphics g;
   g.first_page();
   g.group_members();
   g.loading_screen();
   g.login_page();
   g.menu_page();
   getch();
   closegraph();
}