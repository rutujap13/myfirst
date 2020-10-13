#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{

    int matrix[]={0,5,0,5,0,5,3,3,0},index[9],MoveGen[9][9];
    int i,j=0,h1,h2,h3,v1,v2,v3,d1,d2,r,c,play;
    char turn;
    int max=0,its_index;

    printf("intial matrix:\n[");
     for (i=0;i<9;i++)
        printf("%d ",matrix[i]);
    printf("]\n");


    printf("enter who would make the move('x'=3 or 'o'=5): ");
    scanf("%d",&play);

//for move generation
    int count=0;
    for(i=0;i<9;i++)
    {
        if(matrix[i]==0)
           {
            count+=1;//to find required row for movgen
            index[j]=i;//to find zeroes
            j++;
           }
    }

    for(i=0;i<count;i++)
    {
        for(j=0;j<9;j++)
        {
            MoveGen[i][j]=matrix[j];
            if(j==index[i])
                MoveGen[i][j]=play;
        }
    }

    for(i=0;i<count;i++)
    {
        for(j=0;j<9;j++)
        {
            printf(" %d", MoveGen[i][j]);
        }printf("\n");
    }

//evaluator
        printf("\n");

//////////////////////
     for (int r=0;r<count;r++)
     { int score=0;

           h1=MoveGen[r][0] + MoveGen[r][1] + MoveGen[r][2];
            h2=MoveGen[r][4] + MoveGen[r][5] + MoveGen[r][3];
            h3=MoveGen[r][6] + MoveGen[r][7] + MoveGen[r][8];
            d1=MoveGen[r][0] + MoveGen[r][4] + MoveGen[r][8];
            v1=MoveGen[r][0] + MoveGen[r][3] + MoveGen[r][6];
            v2=MoveGen[r][1] + MoveGen[r][4] + MoveGen[r][7];
            d2=MoveGen[r][2] + MoveGen[r][4] + MoveGen[r][6];
           v3=MoveGen[r][2] + MoveGen[r][5] + MoveGen[r][8];

         //int play=3;
      //check win
      if(h1==3*play || h2==3*play || h3==3*play ||v1==3*play || v2==3*play || v3==3*play ||d1==3*play || d2==3*play )
              score=60;

     else if( (play==3) &&  (h1==13 || h2==13 ||  h3==13 || v1==13 ||  v2==13 || v3==13 ||  d1==13 ||  d2==13 ) )
            score=40;

    else if ((play==5) &&  (h1==11 || h2==11 ||  h3==11 || v1==11 ||  v2==11 || v3==11 ||  d1==11 ||  d2==11 ))
            score=40;

      else
        score=count-1;

      if (score>max)
        {
            max=score;
            its_index=r;
        }
      printf("score %d:%d\n",r+1,score);

       }

       printf("Best move: ");
       for(i=0;i<9;i++)
       {
           printf("%d ",MoveGen[its_index][i]);

       }
    printf("\n\n");
}

