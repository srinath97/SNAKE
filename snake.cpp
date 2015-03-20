#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
const int N=1000;
int queue[2][N];
int front=-1,rear=-1;
void qinsert(int i,int j)				//For inserting the i and j values
{
     if(front==-1)
     {
           front=rear=0;
           queue[0][rear]=i;
           queue[1][rear]=j;
     }
     else if((front==0 && rear==N-1)||rear==front-1)
		{}

     else if(rear==N-1)
     {
          rear=0;
          queue[0][rear]=i;
          queue[1][rear]=j;
     }
     else
     {
		    queue[0][++rear]=i;
		    queue[1][rear]=j;
    }
}
void qdelete(int &i,int &j)				//For deleting i and j values
{
     if(front==-1)
     {
         //cout<<"queue Empty"<<endl;
     }
     else if(rear==front)
     {
          i=queue[0][front];
          j=queue[1][front];
          front=rear=-1;
     }
     else if(front==N-1)
     {
          i=queue[0][front];
          j=queue[1][front];
          front=0;
     }
     else
     {
         i=queue[0][front];
         j=queue[1][front++];
     }
}
int main()
{
	unsigned int s;
	time_t t;
	s=(unsigned)time(&t);
	srand(s);
	int a[25][80],i,j,k,i1=1,j1=1;
	for(i=0;i<24;i++)
	{
		for(j=0;j<80;j++)
		{
			if(i==0||i==23||j==0||j==79)
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	a[12][7]=a[12][8]=a[12][9]=2;				//starting place
	qinsert(12,7);
	qinsert(12,8);
	qinsert(12,9);
	int flag=1,n=1,sum=0,dir=1,ti=12,tj=9,ri=12,rj=7,score=-1;
	while(flag)	
	{
        for(i=0;i<24;i++)						//a[i][j] = 1- empty Space 2-snake 3-target 
	    	for(j=0;j<80;j++)
				if(a[i][j]==1)
					printf(" ");
   				else if(a[i][j]==2||a[i][j]==3)
   			    	printf("o");
				else
					printf(" ");
		if(n)
		{
			score++;
			do
			{
				i1=rand()%24;
				j1=rand()%80;
			}while(a[i1][j1]!=0);				// RANDOM values
			n=0;
		}
		a[i1][j1]=3;
		char b;
		ti=queue[0][rear];
		tj=queue[1][rear];
		ri=queue[0][front];
		rj=queue[1][front];
		if(kbhit())
		{  
            b=getch();
            if(b==72)				//UP arrow key	
            {
                  if(dir==1||dir==3)
                   {
                          if(a[ti-1][tj]==1||a[ti-1][tj]==2)
                          {
                                cout<<"\a";
                                flag=0;
                          }
                          else 
                          {
                                qinsert(ti-1,tj);
                                if(a[ti-1][tj]==3)
                                    n=1;
                                else
                                {
									qdelete(ri,rj);
								    a[ri][rj]=0;
								}
                                a[ti-1][tj]=2;
                          }
                          dir=4;
                    }
            }
            else if(b==75)				//LEFT arrow key
            {
                   if(dir==2||dir==4)
                   {
                          if(a[ti][tj-1]==1||a[ti][tj-1]==2)
                          {
                                cout<<"\a";
                                flag=0;
                          }
                          else 
                          {
                                qinsert(ti,tj-1);
                                if(a[ti][tj-1]==3)
                                    n=1;
                                else
                                {
                                    a[ri][rj]=0;
                                    qdelete(ri,rj);
                                }
                                a[ti][tj-1]=2;
                          }
                          dir=3;
                    }
            }
            else if(b==77)				//DOWN arrow key
            {
                   if(dir==2||dir==4)
                   {
                          if(a[ti][tj+1]==1||a[ti][tj+1]==2)
                          {
                                cout<<"\a";
                                flag=0;
                          }
                          else 
                          {
                                qinsert(ti,tj+1);
                                if(a[ti][tj]==3)
                                    n=1;
                                else
                                {
                                	qdelete(ri,rj);
                                    a[ri][rj]=0;
                                }
                                a[ti][tj+1]=2;
                          }
                          dir=1;
                    }
            }
            else if(b==80)				// RIGHT arrow key
            {
                   if(dir==1||dir==3)
                   {
                          if(a[ti+1][tj]==1||a[ti+1][tj]==2)
                          {
                                cout<<"\a";
                                flag=0;
                          }
                          else 
                          {
                                qinsert(ti+1,tj);
                                if(a[ti+1][tj]==3)
                                    n=1;
                                else
                                {
                                	qdelete(ri,rj);	
                                    a[ri][rj]=0;
                                }
                                a[ti+1][tj]=2;
                          }
                          dir=2;
                    }
            }
        }
        else				//IF no key is pressed
        {
            if(dir==1)				//SNAKE moving downwards
            {
                      if(a[ti][tj+1]==1||a[ti][tj+1]==2)
                      {
                            cout<<"\a";
                            flag=0;
                      }
                      else 
                      {
                            qinsert(ti,tj+1);
                            if(a[ti][tj+1]==3)
                                n=1;
                            else
                            {
                            	qdelete(ri,rj);
							    a[ri][rj]=0;
							}
                            a[ti][tj+1]=2;
                      }
            } 
            else if(dir==2)			//SNAKE moving Right side
            {
                      if(a[ti+1][tj]==1||a[ti+1][tj]==2)
                      {
                            cout<<"\a";
                            flag=0;
                      }
                      else 
                      {
                            qinsert(ti+1,tj);
                            if(a[ti+1][tj]==3)
                                n=1;
                            else
                            {
                            	qdelete(ri,rj);	
                                a[ri][rj]=0;
                            }
                            a[ti+1][tj]=2;
                      }
            }
            else if(dir==3)			//SNAKE moving leftwards
            {
                      if(a[ti][tj-1]==1||a[ti][tj-1]==2)
                      {
                            cout<<"\a";
                            flag=0;
                      }
                      else 
                      {
                            qinsert(ti,tj-1);
                            if(a[ti][tj-1]==3)
                                n=1;
                            else
                            {
                                a[ri][rj]=0;
                                qdelete(ri,rj);
                            }
                            a[ti][tj-1]=2;      
                      }
            }
            else if(dir==4)			////SNAKE moving upwards
            {
                      if(a[ti-1][tj]==1||a[ti-1][tj]==2)
                      {
					        cout<<"\a";
                            flag=0;
                      }
					  else 
                      {
							qinsert(ti-1,tj);
	                        if(a[ti-1][tj]==3)
                                n=1;
                            else
                            {
                                a[ri][rj]=0;
                                qdelete(ri,rj);
							}
                            a[ti-1][tj]=2;
                      }
            }
		    //Sleep(50);
		    //cout<<"SCORE: "<<score;
	        system("cls");
        }
	 }
	 
	for(int i=0;i<10;i++)
	    cout<<"\n";
	cout<<"\t\t\tGAME OVER!!!\n\n";
	cout<<"\t\t\tSCORE: "<<score<<"\n\n";
    cout<<"\t\t\tDONE BY:-\n";
	cout<<"\t\t\t\tP SRINATH";
	cin.get();
	 
}
