#include<simplecpp>
#include <string>
#define LEN 990
#define BRD 690
#include<vector>
#include<stdlib.h>


int LE=LEN/2,BR=BRD/2;
vector<double> vx = {495,495,570,570,420,420,370,370,295,295,370,370,495,495};
vector<double> vy = {345,295,295,445,445,395,395,445,445,245,245,295,295,345};

vector<double> vx1 = {520,495,495,420,420,570,570,645,645,695,695,620,620,420,420,495,495,520};
vector<double> vy1 = {345,345,295,295,245,245,295,320,345,345,445,445,395,395,295,295,345,345};

vector<double> vx2 = {470,495,495,620,620,695,695,570,570,445,445,345,345,495,495,445};
vector<double> vy2 = {345,345,295,295,245,245,345,345,445,445,395,395,295,295,345,345};

vector<double> v2x = {495,495,470,470,420,420,470,470,370,370,295,295,370,370,295,295,320,320,295,295,470,470,420,420,470,470,420,420,495,495};
vector<double> v2y = {345,295,295,245,245,195,195,120,120,195,195,245,245,445,445,495,495,545,545,595,595,545,545,495,495,445,445,295,295,245};

vector<double> v2x1 = {520,495,495,520,520,570,570,520,520,695,695,620,620,570,570,420,420,495,495};
vector<double> v2y1 = {345,345,295,295,245,245,195,195,120,120,245,245,345,345,395,395,295,295,345};

vector<double> v2x2 = {470,495,495,420,420,470,470,570,570,520,520,695,695,620,620,570,570,495,495};
vector<double> v2y2 = {345,345,295,295,445,445,495,495,545,545,595,595,545,545,345,345,295,295,345};




class button                     //Buttons to play/help/about/exit.
{
public:
    Rectangle r;
    Text  t;
void hide()
    {
        r.hide();
        t.hide();
    }
    void show()
    {
        r.show();
        t.show();
    }

};
bool validMove(int a,int b)
{
    bool f;
    if(a>=295&&a<=695&&b>=245&&b<=445){
             f=1;
        }
        if(b>245&&b<295||b>395&&b<445){
            if(a==295||a==370||a==420||a==570||a==620||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>270&&b<345||b>345&&b<420){
            if(a==295||a>340&&a<650||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>295&&b<395&&a>420&&a<570){f=0; return f;}
        if(b>295&&b<345||b>345&&b<395){
            if(a==295||a==345||a==420||a==570||a==645||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(a>370&&a<420||a>570&&a<620){
            if(b==295||b==345||b==395){
                f=1;
            }
            else {f=0; return f;}
        }
        return f;
}
bool validMove2(int a,int b){
        bool f;
        if(a>=295&&a<=695&&b>=120&&b<=595){
             f=1;
        }
        if(b>295&&b<395&&a>420&&a<570){f=0; return f;}
        if(b>120&&b<195){
            if(a==295||a==370||a==470||a==520||a==620||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>195&&b<245){
            if(a==295||a==370||a==420||a==570||a==620||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>245&&b<295){
            if(a==370||a==470||a==520||a==620){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>395&&b<445){
            if(a==370||a==420||a==570||a==620){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>245&&b<345||b>345&&b<445){
            if(a==370||(a>=420&&a<=570)||a==620){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>445&&b<495){
            if(a==295||a==370||a==470||a==520||a==620||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>495&&b<545){
            if(a==320||a==370||a==420||a==570||a==620||a==670){
                f=1;
            }
            else {f=0; return f;}
        }
        if(b>545&&b<595){
            if(a==295||a==470||a==520||a==695){
                f=1;
            }
            else {f=0; return f;}
        }
        if(a>370&&a<420||a>570&&a<620){
            if(b==120||b==195||b==345||b==445||b==495||b==595){
                f=1;
            }
            else {f=0; return f;}
        }
        if(a>470&&a<520){
            if(b==195||b==295||b==395||b==495||b==595){
                f=1;
            }
            else {f=0; return f;}
         }
        if(a>320&&a<370||a>620&&a<670){
            if(b==120||b==195||b==245||b==345||b==445||b==545||b==595){
                f=1;
            }
            else {f=0; return f;}
         }

        return f;
}
void pacman(){

  end_finish:
    Circle C(LE,BR+50,20),c1(LE,BR,5),c2(0,0,9);
    C.setColor(YELLOW);
    C.setFill();
    c2.setColor(BLACK),c2.setFill();

    Circle bot_1(495,345,10);
    bot_1.setColor(COLOR("red"));
    bot_1.setFill();

    Circle bot_2(520,345,10);
    bot_2.setColor(MAGENTA);
    bot_2.setFill();

    Circle bot_3(470,345,10);
    bot_3.setColor(COLOR("white"));
    bot_3.setFill();

    XEvent e1;
    nextEvent(e1);
    char pos, chpos;
    bool flag=0;
    int x=495,y=395;
    C.moveTo(x,y);

    double x1=vx[0],y1=vy[0];
    double x2=vx1[0],y2=vy1[0];
    double x3=vx2[0],y3=vy2[0];
    int n0 =1;
    int n1 =1;
    int n2 =1;



    while(1){
        checkEvent(e1);
        chpos=charFromEvent(e1);
        if(chpos==66||chpos==97||chpos==68||chpos==100||chpos==83||chpos==115||chpos==87||chpos==119||chpos==27||chpos==32) pos=chpos;

        switch(pos){
            case  87:
            case 119:
                 y-=5;
                 break;

            case 66:
            case 97:
                  x-=5;
                  break;

            case 83:
            case 115:
                 y+=5;
                 break;

            case 68:
            case 100:
                 x+=5;
                 break;

            case 32:
                break;

            case 27:
                return;

            default:
                 break;
        }

        flag=validMove(x,y);

        if(!flag){
            switch(pos){
                case 87:
                case 119:
                     y+=5;
                     break;

                case 66:
                case 97:
                      x+=5;
                      break;

                case 83:
                case 115:
                     y-=5;
                     break;

                case 68:
                case 100:
                     x-=5;
                     break;

                default:
                     break;
            }

            flag=1;
        }
        else{
            beginFrame();
            c2.moveTo(x,y);
            c2.show(),c2.imprint();
            c2.hide();
            endFrame();
            C.moveTo(x,y);
        }




        if(bot_1.getX()==x1&&bot_1.getY()==y1)
        {
          if(n0==14){
            x1=vx[0];
            y1=vy[0];
            n0=1;
          }
          x1=vx[0+n0];
          y1=vy[0+n0];

          n0++;
        }
        else{
          if(bot_1.getX()!=x1){
            if(bot_1.getX()<x1)
            {
              bot_1.move(5,0);
            }
            else{
              bot_1.move(-5,0);
            }
            wait(0.01);

          }
          else if(bot_1.getY()!=y1){
            if(bot_1.getY()<y1){
              bot_1.move(0,5);
            }
            else{
              bot_1.move(0,-5);
            }
            wait(0.01);
          }
        }



        if(bot_2.getX()==x2&&bot_2.getY()==y2){
          if(n1==18){
            x2=vx1[0];
            y2=vy1[0];
            n1=1;
          }
          x2=vx1[0+n1];
          y2=vy1[0+n1];
          n1++;
          }
          else{
            if(bot_2.getX()!=x2){
              if(bot_2.getX()<x2){
                bot_2.move(5,0);
              }
              else{
                bot_2.move(-5,0);
              }
              wait(0.01);

            }
            else if(bot_2.getY()!=y2){
              if(bot_2.getY()<y2){
                bot_2.move(0,5);
              }
              else{
                bot_2.move(0,-5);
              }
              wait(0.01);
            }

        }



        if(bot_3.getX()==x3&&bot_3.getY()==y3){
          if(n2==14){
            x3=vx2[0];
            y3=vy2[0];
            n2=1;
          }
          x3=vx2[0+n2];
          y3=vy2[0+n2];

          n2++;
        }
        else{
          if(bot_3.getX()!=x3){
            if(bot_3.getX()<x3){
              bot_3.move(5,0);
            }
            else{
              bot_3.move(-5,0);
            }
            wait(0.01);

          }
          else if(bot_3.getY()!=y3){
            if(bot_3.getY()<y3){
              bot_3.move(0,5);
            }
            else{
              bot_3.move(0,-5);
            }
            wait(0.01);
          }
        }


         if(C.getX()==bot_1.getX()&&C.getY()==bot_1.getY()){
           goto end_finish;
         }

         if(C.getX()==bot_2.getX()&&C.getY()==bot_3.getY()){
           goto end_finish;
         }

         if(C.getX()==bot_3.getX()&&C.getY()==bot_3.getY()){
           goto end_finish;
         }


      }

    }


void pacman2(){

  end_finish:
    Circle C(LE,BR+50,20),c1(LE,BR,5),c2(0,0,10);
    C.setColor(YELLOW);
    C.setFill();
    c2.setColor(BLACK),c2.setFill();

    Circle bot_1(495,345,10);
    bot_1.setColor(COLOR("red"));
    bot_1.setFill();

    Circle bot_2(520,345,10);
    bot_2.setColor(MAGENTA);
    bot_2.setFill();

    Circle bot_3(470,345,10);
    bot_3.setColor(COLOR("white"));
    bot_3.setFill();


    double x12=v2x[0],y12=v2y[0];
    double x22=v2x1[0],y22=v2y1[0];
    double x32=v2x2[0],y32=v2y2[0];
    int n02 =1;
    int n12 =1;
    int n22 =1;

    XEvent e1;
    nextEvent(e1);
    char pos, chpos;
    bool flag=0;
    int x=495,y=395;
    C.moveTo(x,y);
    while(1){
        checkEvent(e1);
        chpos=charFromEvent(e1);
        if(chpos==66||chpos==97||chpos==68||chpos==100||chpos==83||chpos==115||chpos==87||chpos==119||chpos==27||chpos==32) pos=chpos;

        switch(pos){
            case  87:
            case 119:
                 y-=5;
                 break;

            case 66:
            case 97:
                  x-=5;
                  break;

            case 83:
            case 115:
                 y+=5;
                 break;

            case 68:
            case 100:
                 x+=5;
                 break;

            case 32:
                break;

            case 27:
                return;

            default:
                 break;
        }

        flag=validMove2(x,y);

        if(!flag){
            switch(pos){
                case 87:
                case 119:
                     y+=5;
                     break;

                case 66:
                case 97:
                      x+=5;
                      break;

                case 83:
                case 115:
                     y-=5;
                     break;

                case 68:
                case 100:
                     x-=5;
                     break;

                default:
                     break;
            }
            flag=1;
        }
        else{
            if(x==295&&y==345)
            if(pos==66||pos==97)
            x=700;

            if(x==695&&y==345)
            if(pos==68||pos==100)
            x=290;

            beginFrame();
            c2.moveTo(x,y);
            c2.show(),c2.imprint();
            c2.hide();
            endFrame();
            C.moveTo(x,y);
        }
        wait(0.05);


        if(bot_1.getX()==x12&&bot_1.getY()==y12){
          if(n02==30){
            x12=v2x[0];
            y12=v2y[0];
            n02=1;
          }
          x12=v2x[0+n02];
          y12=v2y[0+n02];

          n02++;
        }
        else{
          if(bot_1.getX()!=x12){
            if(bot_1.getX()<x12){
              bot_1.move(5,0);
            }
            else{
              bot_1.move(-5,0);
            }
            wait(0.01);

          }
          else if(bot_1.getY()!=y12){
            if(bot_1.getY()<y12){
              bot_1.move(0,5);
            }
            else{
              bot_1.move(0,-5);
            }
            wait(0.01);
          }
        }



        if(bot_2.getX()==x22&&bot_2.getY()==y22){
          if(n12==19){
            x22=v2x1[0];
            y22=v2y1[0];
            n12=1;
          }
          x22=v2x1[0+n12];
          y22=v2y1[0+n12];
          n12++;
          }
          else{
            if(bot_2.getX()!=x22){
              if(bot_2.getX()<x22){
                bot_2.move(5,0);
              }
              else{
                bot_2.move(-5,0);
              }
              wait(0.01);

            }
            else if(bot_2.getY()!=y22){
              if(bot_2.getY()<y22){
                bot_2.move(0,5);
              }
              else{
                bot_2.move(0,-5);
              }
              wait(0.01);
            }
        }

        if(bot_3.getX()==x32&&bot_3.getY()==y32){
          if(n22==19){
            x32=v2x2[0];
            y32=v2y2[0];
            n22=1;
          }
          x32=v2x2[0+n22];
          y32=v2y2[0+n22];

          n22++;
        }
        else{
          if(bot_3.getX()!=x32){
            if(bot_3.getX()<x32){
              bot_3.move(5,0);
            }
            else{
              bot_3.move(-5,0);
            }
            wait(0.01);

          }
          else if(bot_3.getY()!=y32){
            if(bot_3.getY()<y32){
              bot_3.move(0,5);
            }
            else{
              bot_3.move(0,-5);
            }
            wait(0.01);
          }
        }

        if(C.getX()==bot_1.getX()&&C.getY()==bot_1.getY()){
          goto end_finish;
        }

        if(C.getX()==bot_2.getX()&&C.getY()==bot_3.getY()){
          goto end_finish;
        }

        if(C.getX()==bot_3.getX()&&C.getY()==bot_3.getY()){
          goto end_finish;
        }

    }
}
int positionclicked(int x1,int x2,int y1,int y2)        //created to check position of click on buttons
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
main_program
{
//Write youir code here
    char name[100];

	cout<<"\t\t\t WELCOME TO THE PAC MAN GAME\n\n";
	cout<<"ENTER YOUR NAME:";
	cin.getline(name,100);
	cout<<"__________\n\n";
	system("PAUSE");

	system("CLS");
	cout<<"__________\n\n";
	cout<<"\t\t\t THANK YOU FOR PLAYING !!!!!!!!!!!!!!!!!!!!!\n\n";
    cout<<"__________\n\n";

    initCanvas("Pac man",1320,720);                  //creating canvas and displaying buttons to play/get help /about/exit etc.
    Here:

    Text t1(660,150,"WELCOME TO PAC-MAN");


    Rectangle r(660,400,400,450);
    r.setColor(COLOR(255,220,142));
	r.setFill();

    button play;
    play.r.reset(660,250,100,50);
    play.t.reset(660,250,"Start Game");
    play.r.setFill();
    play.r.setColor(COLOR(225,253,248));

    button instructions;
    instructions.r.reset(660,350,100,50);
    instructions.t.reset(660,350,"HELP");
    instructions.r.setFill();
    instructions.r.setColor(COLOR(225,253,248));

    button about;
    about.r.reset(660,450,100,50);
    about.t.reset(660,450,"ABOUT");
    about.r.setFill();
    about.r.setColor(COLOR(225,253,248));

    button exit;
    exit.r.reset(660,550,100,50);
    exit.t.reset(660,550,"EXIT");
    exit.r.setFill();
    exit.r.setColor(COLOR(226,42,199));


    while(1)                       //detecting click position when buttons are clicked and going to the next step.
    {
        int a=getClick();
        int x=a/65536;
        int y=a%65536;
        if(positionclicked(x,660,y,250)<50)
        {
            t1.hide();
            play.hide();
            instructions.hide();
            about.hide();

            Text mapnos(660,150,"CHOOSE THE MAP TO PLAY..!!");

            button map1;
            map1.r.reset(660,250,100,50);
            map1.t.reset(660,250,"Map 1");
            map1.r.setFill();
            map1.r.setColor(COLOR(225,253,248));

            button map2;
            map2.r.reset(660,350,100,50);
            map2.t.reset(660,350,"Map 2");
            map2.r.setFill();
            map2.r.setColor(COLOR(225,253,248));

            while(1)
            {
                int click3=getClick();
                int x3=click3/65536;
                int y3=click3%65536;
                r.hide();
                mapnos.hide();
                map1.hide();
            map2.hide();
            about.hide();
            exit.hide();
                if(positionclicked(x3,660,y3,250)<50)
                {
                int i,j,k;
    beginFrame();
    Rectangle r1(LE,BR,450,250),r2(LE,BR,100,50),r3(LE,BR,LEN,BRD),r4(LE,BR,LEN,BRD);
    r1.setColor(COLOR("blue"));
    r2.setColor(COLOR("blue"));
    r3.setColor(COLOR("black"));
    r3.setFill();
    r3.imprint(),r3.hide();
    r4.setColor(COLOR("white"));
    r4.setFill();
    r4.hide();
    Line l1(LE-25,BR-25,LE+25,BR-25),l2(LE-100,BR-25,LE-75,BR-25),l3(LE-50,BR-75,LE+50,BR-75);
    Line l4(LE-100,BR-75,LE-100,BR-125);
    l1.setColor(COLOR("black"));
    l2.setColor(COLOR("blue"));
    l3.setColor(COLOR("blue"));
    l4.setColor(COLOR("blue"));

    Circle c1(LE,BR,5);
    c1.setColor(GREEN),c1.setFill();

    for(i=0;i<2;i++){
        r1.moveTo(LE+i,BR+i);
        r1.imprint();
        r1.moveTo(LE-i,BR-i);
        r1.imprint();
        r1.moveTo(LE+i,BR-i);
        r1.imprint();
        r1.moveTo(LE-i,BR+i);
        r1.imprint();

        r2.moveTo(LE+i,BR+i);
        r2.imprint();
        r2.moveTo(LE-i,BR-i);
        r2.imprint();
        r2.moveTo(LE+i,BR-i);
        r2.imprint();
        r2.moveTo(LE-i,BR+i);
        r2.imprint();

        l1.moveTo(LE,BR-25-i);
        l1.imprint();
        l1.moveTo(LE,BR-25+i);
        l1.imprint();

        l2.moveTo(LE-112,BR-25-i);
        l2.imprint();
        l2.moveTo(LE-112,BR-25+i);
        l2.imprint();
        l2.moveTo(LE-112,BR+25-i);
        l2.imprint();
        l2.moveTo(LE-112,BR+25+i);
        l2.imprint();

        l2.moveTo(LE+112,BR-25-i);
        l2.imprint();
        l2.moveTo(LE+112,BR-25+i);
        l2.imprint();
        l2.moveTo(LE+112,BR+25-i);
        l2.imprint();
        l2.moveTo(LE+112,BR+25+i);
        l2.imprint();

        l3.moveTo(LE,BR-75-i);
        l3.imprint();
        l3.moveTo(LE,BR-75+i);
        l3.imprint();
        l3.moveTo(LE,BR+75-i);
        l3.imprint();
        l3.moveTo(LE,BR+75+i);
        l3.imprint();

        l4.moveTo(LE-100-i,BR-100);
        l4.imprint();
        l4.moveTo(LE-100+i,BR-100);
        l4.imprint();
        l4.moveTo(LE+100-i,BR-100);
        l4.imprint();
        l4.moveTo(LE+100+i,BR-100);
        l4.imprint();

        l4.moveTo(LE-100-i,BR+100);
        l4.imprint();
        l4.moveTo(LE-100+i,BR+100);
        l4.imprint();
        l4.moveTo(LE+100-i,BR+100);
        l4.imprint();
        l4.moveTo(LE+100+i,BR+100);
        l4.imprint();

        l2.moveTo(LE-163,BR-75-i);
        l2.imprint();
        l2.moveTo(LE-163,BR-75+i);
        l2.imprint();
        l2.moveTo(LE-163,BR+75-i);
        l2.imprint();
        l2.moveTo(LE-163,BR+75+i);
        l2.imprint();

        l2.moveTo(LE+163,BR-75-i);
        l2.imprint();
        l2.moveTo(LE+163,BR-75+i);
        l2.imprint();
        l2.moveTo(LE+163,BR+75-i);
        l2.imprint();
        l2.moveTo(LE+163,BR+75+i);
        l2.imprint();

        l4.moveTo(LE-175-i,BR-50);
        l4.imprint();
        l4.moveTo(LE-175+i,BR-50);
        l4.imprint();
        l4.moveTo(LE+175-i,BR-50);
        l4.imprint();
        l4.moveTo(LE+175+i,BR-50);
        l4.imprint();

        l4.moveTo(LE+175-i,BR+50);
        l4.imprint();
        l4.moveTo(LE+175+i,BR+50);
        l4.imprint();
        l4.moveTo(LE-175-i,BR+50);
        l4.imprint();
        l4.moveTo(LE-175+i,BR+50);
        l4.imprint();
    }
    l1.hide(),l2.hide(),l3.hide(),l4.hide(),r1.hide(),r2.hide();

    int x=295,y=245,X,Y;
    for(i=0;i<425;i+=25)
    for(j=0;j<225;j+=25){
        X=x+i,Y=y+j;
        c1.moveTo(X,Y);
        if(j==25||j==7*25){
            if(i==0||i==3*25||i==5*25||i==11*25||i==13*25||i==16*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j>2*25&&j<6*25&&i>2*25&&i<14*25){
            if(i==5*25||i==11*25||j==4*25&&i==3*25||j==4*25&&i==3*25||j==4*25&&i==4*25||j==4*25&&i==12*25||j==4*25&&i==13*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(i==25||i==15*25){
            if(j==0||j==4*25||j==8*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(i==4*25||i==12*25){
            if(j==2*25||j==4*25||j==6*25){
                c1.imprint();
                continue;
            }
            continue;
        }

        c1.imprint();
    }

    c1.hide();
    endFrame();

    pacman();
    r4.show(),r4.imprint(),r4.hide();
    goto Here;

                    break;

                }

                else if(positionclicked(x3,660,y3,350)<50)
                {

   int i,j,k;
   beginFrame();

   Rectangle r1(LE,BR,450,525),r2(LE,BR,100,50),r3(LE,BR,LEN,BRD),r4(LE,BR,50,25),r5(LE,BR,25,25),r6(LE,BR,LEN,BRD);
   r1.setColor(COLOR("blue"));
   r2.setColor(COLOR("blue"));
   r3.setColor(COLOR("black"));
   r3.setFill();
   r3.imprint();
   r3.hide();
   r6.setColor(COLOR("white"));
   r6.setFill();
   r6.hide();
   r4.setColor(COLOR("blue"));
   r5.setColor(COLOR("blue"));

   Line l1(LE-25,BR-25,LE+25,BR-25),l2(LE,BR,LE+100,BR),l3(LE,BR,LE,BR+50);
   Line l4(LE,BR,LE+25,BR),l5(LE,BR,LE,BR+144);
   l1.setColor(COLOR("black"));
   l2.setColor(COLOR("blue"));
   l3.setColor(COLOR("blue"));
   l4.setColor(COLOR("blue"));
   l5.setColor(COLOR("black"));

    Circle c1(LE,BR,5);
    c1.setColor(GREEN),c1.setFill();

   for(i=0;i<2;i++){
        r1.moveTo(LE+i,BR+12+i);
        r1.imprint();
        r1.moveTo(LE-i,BR+12-i);
        r1.imprint();
        r1.moveTo(LE+i,BR+12-i);
        r1.imprint();
        r1.moveTo(LE-i,BR+12+i);
        r1.imprint();

        r2.moveTo(LE+i,BR+i);
        r2.imprint();
        r2.moveTo(LE-i,BR-i);
        r2.imprint();
        r2.moveTo(LE+i,BR-i);
        r2.imprint();
        r2.moveTo(LE-i,BR+i);
        r2.imprint();

        r4.moveTo(LE-75+i,BR-187+i);
        r4.imprint();
        r4.moveTo(LE-75-i,BR-187-i);
        r4.imprint();
        r4.moveTo(LE-75+i,BR-187-i);
        r4.imprint();
        r4.moveTo(LE-75-i,BR-187+i);
        r4.imprint();
        r4.moveTo(LE+75+i,BR-187+i);
        r4.imprint();
        r4.moveTo(LE+75-i,BR-187-i);
        r4.imprint();
        r4.moveTo(LE+75+i,BR-187-i);
        r4.imprint();
        r4.moveTo(LE+75-i,BR-187+i);
        r4.imprint();

        r5.moveTo(LE-163+i,BR-187+i);
        r5.imprint();
        r5.moveTo(LE-163-i,BR-187-i);
        r5.imprint();
        r5.moveTo(LE-163+i,BR-187-i);
        r5.imprint();
        r5.moveTo(LE-163-i,BR-187+i);
        r5.imprint();
        r5.moveTo(LE+163+i,BR-187+i);
        r5.imprint();
        r5.moveTo(LE+163-i,BR-187-i);
        r5.imprint();
        r5.moveTo(LE+163+i,BR-187-i);
        r5.imprint();
        r5.moveTo(LE+163-i,BR-187+i);
        r5.imprint();

        l1.moveTo(LE,BR-25-i);
        l1.imprint();
        l1.moveTo(LE,BR-25+i);
        l1.imprint();

        l2.moveTo(LE,BR-125-i);
        l2.imprint();
        l2.moveTo(LE,BR-125+i);
        l2.imprint();

        l3.moveTo(LE-i,BR-100);
        l3.imprint();
        l3.moveTo(LE+i,BR-100);
        l3.imprint();

        l3.moveTo(LE-i,BR-200);
        l3.imprint();
        l3.moveTo(LE+i,BR-200);
        l3.imprint();

        l2.moveTo(LE,BR+175-i);
        l2.imprint();
        l2.moveTo(LE,BR+175+i);
        l2.imprint();

        l3.moveTo(LE-i,BR+200);
        l3.imprint();
        l3.moveTo(LE+i,BR+200);
        l3.imprint();

        l2.moveTo(LE,BR+75-i);
        l2.imprint();
        l2.moveTo(LE,BR+75+i);
        l2.imprint();

        l3.moveTo(LE-i,BR+100);
        l3.imprint();
        l3.moveTo(LE+i,BR+100);
        l3.imprint();

        l3.moveTo(LE-100+i,BR+50);
        l3.imprint();
        l3.moveTo(LE-100-i,BR+50);
        l3.imprint();
        l3.moveTo(LE+100+i,BR+50);
        l3.imprint();
        l3.moveTo(LE+100-i,BR+50);
        l3.imprint();

        l3.moveTo(LE-150+i,BR+150);
        l3.imprint();
        l3.moveTo(LE-150-i,BR+150);
        l3.imprint();
        l3.moveTo(LE+150+i,BR+150);
        l3.imprint();
        l3.moveTo(LE+150-i,BR+150);
        l3.imprint();

        l3.moveTo(LE-100+i,BR+200);
        l3.imprint();
        l3.moveTo(LE-100-i,BR+200);
        l3.imprint();
        l3.moveTo(LE+100+i,BR+200);
        l3.imprint();
        l3.moveTo(LE+100-i,BR+200);
        l3.imprint();

        l3.moveTo(LE-150+i,BR+50);
        l3.imprint();
        l3.moveTo(LE-150-i,BR+50);
        l3.imprint();
        l3.moveTo(LE+150+i,BR+50);
        l3.imprint();
        l3.moveTo(LE+150-i,BR+50);
        l3.imprint();
        l3.moveTo(LE-150+i,BR-50);
        l3.imprint();
        l3.moveTo(LE-150-i,BR-50);
        l3.imprint();
        l3.moveTo(LE+150+i,BR-50);
        l3.imprint();
        l3.moveTo(LE+150-i,BR-50);
        l3.imprint();

        l2.moveTo(LE-125,BR+225+i);
        l2.imprint();
        l2.moveTo(LE-125,BR+225-i);
        l2.imprint();
        l2.moveTo(LE+125,BR+225+i);
        l2.imprint();
        l2.moveTo(LE+125,BR+225-i);
        l2.imprint();

        l2.rotate(1.57);
        l2.moveTo(LE-100-i,BR-75);
        l2.imprint();
        l2.moveTo(LE-100+i,BR-75);
        l2.imprint();
        l2.moveTo(LE+100-i,BR-75);
        l2.imprint();
        l2.moveTo(LE+100+i,BR-75);
        l2.imprint();

        l3.rotate(1.57);
        l3.moveTo(LE-75,BR-75-i);
        l3.imprint();
        l3.moveTo(LE-75,BR-75+i);
        l3.imprint();
        l3.moveTo(LE+75,BR-75-i);
        l3.imprint();
        l3.moveTo(LE+75,BR-75+i);
        l3.imprint();

        l3.moveTo(LE-75,BR+125+i);
        l3.imprint();
        l3.moveTo(LE-75,BR+125-i);
        l3.imprint();
        l3.moveTo(LE+75,BR+125+i);
        l3.imprint();
        l3.moveTo(LE+75,BR+125-i);
        l3.imprint();

        l3.moveTo(LE-75,BR+225+i);
        l3.imprint();
        l3.moveTo(LE-75,BR+225-i);
        l3.imprint();
        l3.moveTo(LE+75,BR+225+i);
        l3.imprint();
        l3.moveTo(LE+75,BR+225-i);
        l3.imprint();

        l3.moveTo(LE+200,BR-75+i);
        l3.imprint();
        l3.moveTo(LE+200,BR-75-i);
        l3.imprint();
        l3.moveTo(LE+200,BR+75+i);
        l3.imprint();
        l3.moveTo(LE+200,BR+75-i);
        l3.imprint();
        l3.moveTo(LE-200,BR-75+i);
        l3.imprint();
        l3.moveTo(LE-200,BR-75-i);
        l3.imprint();
        l3.moveTo(LE-200,BR+75+i);
        l3.imprint();
        l3.moveTo(LE-200,BR+75-i);
        l3.imprint();

        l4.moveTo(LE-163,BR+75+i);
        l4.imprint();
        l4.moveTo(LE-163,BR+75-i);
        l4.imprint();
        l4.moveTo(LE-163,BR-75+i);
        l4.imprint();
        l4.moveTo(LE-163,BR-75-i);
        l4.imprint();
        l4.moveTo(LE+163,BR+75+i);
        l4.imprint();
        l4.moveTo(LE+163,BR+75-i);
        l4.imprint();
        l4.moveTo(LE+163,BR-75+i);
        l4.imprint();
        l4.moveTo(LE+163,BR-75-i);
        l4.imprint();

        l3.moveTo(LE+200,BR-25+i);
        l3.imprint();
        l3.moveTo(LE+200,BR-25-i);
        l3.imprint();
        l3.moveTo(LE+200,BR+25+i);
        l3.imprint();
        l3.moveTo(LE+200,BR+25-i);
        l3.imprint();
        l3.moveTo(LE-200,BR-25+i);
        l3.imprint();
        l3.moveTo(LE-200,BR-25-i);
        l3.imprint();
        l3.moveTo(LE-200,BR+25+i);
        l3.imprint();
        l3.moveTo(LE-200,BR+25-i);
        l3.imprint();

        l4.moveTo(LE-163,BR+25+i);
        l4.imprint();
        l4.moveTo(LE-163,BR+25-i);
        l4.imprint();
        l4.moveTo(LE-163,BR-25+i);
        l4.imprint();
        l4.moveTo(LE-163,BR-25-i);
        l4.imprint();
        l4.moveTo(LE+163,BR+25+i);
        l4.imprint();
        l4.moveTo(LE+163,BR+25-i);
        l4.imprint();
        l4.moveTo(LE+163,BR-25+i);
        l4.imprint();
        l4.moveTo(LE+163,BR-25-i);
        l4.imprint();

        l4.moveTo(LE-163,BR+125+i);
        l4.imprint();
        l4.moveTo(LE-163,BR+125-i);
        l4.imprint();
        l4.moveTo(LE-163,BR-125+i);
        l4.imprint();
        l4.moveTo(LE-163,BR-125-i);
        l4.imprint();
        l4.moveTo(LE+163,BR+125+i);
        l4.imprint();
        l4.moveTo(LE+163,BR+125-i);
        l4.imprint();
        l4.moveTo(LE+163,BR-125+i);
        l4.imprint();
        l4.moveTo(LE+163,BR-125-i);
        l4.imprint();

        l4.moveTo(LE-213,BR+175+i);
        l4.imprint();
        l4.moveTo(LE-213,BR+175-i);
        l4.imprint();
        l4.moveTo(LE+213,BR+175+i);
        l4.imprint();
        l4.moveTo(LE+213,BR+175-i);
        l4.imprint();

        l4.rotate(1.57);
        l4.moveTo(LE+i,BR-237);
        l4.imprint();
        l4.moveTo(LE-i,BR-237);
        l4.imprint();

        l5.moveTo(LE-225+i,BR);
        l5.imprint();
        l5.moveTo(LE-225-i,BR);
        l5.imprint();
        l5.moveTo(LE+225+i,BR);
        l5.imprint();
        l5.moveTo(LE+225-i,BR);
        l5.imprint();

        l2.rotate(1.57),l3.rotate(1.57),l4.rotate(1.57);;
   }
   l1.hide(),l2.hide(),l3.hide(),l4.hide(),r1.hide(),r2.hide(),r3.hide(),r4.hide(),r5.hide();
   int x=295,y=120,X,Y;
   for(i=0;i<425;i+=25)
   for(j=0;j<500;j+=25){
        X=x+i,Y=y+j;
        c1.moveTo(X,Y);
        if(j>5*25&&j<9*25&&i<3*25||j>5*25&&j<9*25&&i>13*25||j>9*25&&j<13*25&&i<3*25||j>9*25&&j<13*25&&i>13*25)
        continue;
        if(j>0&&j<3*25&&i>0*25&&i<16*25){
            if(i==3*25||i==7*25||i==9*25||i==13*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j==4*25){
            if(i==0||i==3*25||i==13*25||i==5*25||i==11*25||i==16*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j==6*25){
             if(i==3*25||i==7*25||i==9*25||i==13*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j>7*25&&j<11*25&&i>5*25&&i<11*25)
        continue;
        if(j==12*25){
             if(i==3*25||i==5*25||i==11*25||i==13*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j==14*25){
             if(i==0||i==3*25||i==13*25||i==7*25||i==9*25||i==16*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j==15*25&&i==2*25||j==15*25&&i==14*25)
        continue;
        if(j==16*25){
            if(i==1*25||i==3*25||i==5*25||i==11*25||i==13*25||i==15*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(j==18*25){
            if(i==0||i==7*25||i==9*25||i==16*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(i==4*25||i==12*25){
            if(j==0||j==3*25||j==9*25||j==13*25||j==15*25||j==19*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        if(i==8*25){
            if(j==3*25||j==6*25||j==7*25||j==11*25||j==15*25||j==19*25){
                c1.imprint();
                continue;
            }
            continue;
        }
        c1.imprint();
    }

   c1.hide();
   endFrame();

    pacman2();
    r6.show(),r6.imprint(),r6.hide();
    goto Here;

                    break;
                }
                else
                {
                    return 0;
                }


            }

            map1.hide();
            map2.hide();
            about.hide();
            mapnos.hide();
            exit.hide();

            break;

        }

        else if(positionclicked(x,660,y,350)<50)
        {
            t1.hide();
            play.hide();
            instructions.hide();
            exit.hide();
            Text a(660,250,"Press w to move ABOVE.");
            Text b(660,270,"Press s to move DOWN. ");
            Text c(660,290,"Press a to move LEFT.");
            Text d(660,310,"Press d to move RIGHT.");
            Text e(660,330,"To Win The Game The Pacman Must Eat All The Food ");
            Text f(660,350,"Best Of Luck");
            button backtomainmenu;
            backtomainmenu.r.reset(660,450,100,50);
            backtomainmenu.t.reset(660,450,"Back To Main Menu");
            backtomainmenu.r.setFill();
            backtomainmenu.r.setColor(COLOR(0,250,0));

            while(1)
            {
                int click2 =getClick();
                int x2=click2/65536;
                int y2=click2%65536;
                if(positionclicked(x2,660,y2,440)<50)
                {
                    a.hide();
                    b.hide();
                    c.hide();
                    d.hide();
                    e.hide();
                    backtomainmenu.hide();
                    break;
                }
            }
            t1.show();
            play.show();
            instructions.show();
            exit.show();
            continue;


        }
        else if(positionclicked(x,660,y,450)<50)
        {
            t1.hide();
            play.hide();
            instructions.hide();
            exit.hide();
            Text a(660,200,"This is a Game  of Pacman.");
            Text b(660,220,"This has been developed by ");
            Text c(660,240,"Yash Karapurkar ");
            Text d(660,260,"Germano D'costa ");
            Text e(660,280,"Steven Mascarenhas");
            Text f(660,300,"Tanay Rataboli");

            button backtomainmenu;
            backtomainmenu.r.reset(660,450,100,50);
            backtomainmenu.t.reset(660,450,"Back To Main Menu");
            backtomainmenu.r.setFill();
            backtomainmenu.r.setColor(COLOR(0,250,0));

            while(1)
            {
                int click2 =getClick();
                int x2=click2/65536;
                int y2=click2%65536;
                if(positionclicked(x2,660,y2,440)<50)
                {
                    a.hide();
                    b.hide();
                    c.hide();
                    d.hide();
                    e.hide();
                    backtomainmenu.hide();
                    break;
                }
            }
            t1.show();
            play.show();
            instructions.show();
            exit.show();
            continue;


        }

        else if(positionclicked(x,660,y,550)<50)
        {
            return 0;

        }



    }
}
