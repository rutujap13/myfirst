#include<stdio.h>


 int main()
 {

 int MoveGen[4][9]={
 {3, 5, 0, 5, 0, 5, 3, 3, 0},
{ 0, 5, 3, 5, 0, 5, 3, 3, 0},
{ 0, 5 ,0 ,5 ,3 ,5 ,3 ,3 ,0},
 {0 ,5 ,0 ,5 ,0, 5, 3 ,3 ,3}};
 int count =4;
int h1,h2,h3,v1,v2,v3,d1,d2,score=0;

 for (int r=0;r<count;r++)
     { score=0;
          printf("%d",r);
           h1=MoveGen[r][0] + MoveGen[r][1] + MoveGen[r][2];
            h2=MoveGen[r][4] + MoveGen[r][5] + MoveGen[r][3];
            h3=MoveGen[r][6] + MoveGen[r][7] + MoveGen[r][8];
            d1=MoveGen[r][0] + MoveGen[r][4] + MoveGen[r][8];
            v1=MoveGen[r][0] + MoveGen[r][3] + MoveGen[r][6];
            v2=MoveGen[r][1] + MoveGen[r][4] + MoveGen[r][7];
            d2=MoveGen[r][2] + MoveGen[r][4] + MoveGen[r][6];
           v3=MoveGen[r][2] + MoveGen[r][5] + MoveGen[r][8];

           //printf("h1:%d\nh2:%d\nh3:%d\nv1:%d\nv2:%d\nv3:%d\nd1:%d\nd2:%d\n",h1,h2,h3,v1,v2,v3,d1,d2);
int play=3;
      //check win
      if(h1==3*play || h2==3*play || h3==3*play ||v1==3*play || v2==3*play || v3==3*play ||d1==3*play || d2==3*play )
              score=60;

     else if( (play==3) &&  (h1==13 || h2==13 ||  h3==13 || v1==13 ||  v2==13 || v3==13 ||  d1==13 ||  d2==13 ) )
            score=40;

    else if ((play==5) &&  (h1==11 || h2==11 ||  h3==11 || v1==11 ||  v2==11 || v3==11 ||  d1==11 ||  d2==11 ))
            score=40;

      else
        score=count-1;
     }

    for(int r=0;r<count;r++)
    {printf("\n%d\n",r+1);
         printf("h1:%d\nh2:%d\nh3:%d\nv1:%d\nv2:%d\nv3:%d\nd1:%d\nd2:%d\n",h1,h2,h3,v1,v2,v3,d1,d2);

        printf("score %d:%d\n",r,score);}



}

//
