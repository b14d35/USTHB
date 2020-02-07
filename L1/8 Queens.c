#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,M[8][8]={0};
    for (a=0;a<8;a++) {
        M[a][0]=1;
        for (b=0;b<8;b++) {
            M[b][1]=1;
            for (i=0;i<3;i++) {
                if (b-1+i>=0 || b-1+i<=7) {
                    if (M[b-1+i][0]==1) {
                        M[b][1]=0;
                    }
                }
            }
            if (M[b][1]==1) {
                for (c=0;c<8;c++) {
                    M[c][2]=1;
                    if (M[c][2]==1) {
                        for (d=0;d<8;d++) {
                            M[d][3]=1;
                            if (M[d][3]==1) {
                                for (e=0;e<8;e++) {
                                    M[e][4]=1;
                                    if (M[e][4]==1) {
                                        for (f=0;f<8;f++) {
                                            M[f][5]=1;
                                            if (M[f][5]==1) {
                                                for (g=0;g<8;g++) {
                                                    M[g][6]=1;
                                                    if (M[g][6]==1) {
                                                        for (h=0;h<8;h++) {
                                                            M[h][7]=1;
                                                                if (M[h][7]==1) {
                                                                    printf("%d|%d|%d|%d|%d|%d|%d|%d\n",a+1,b+1,c+1,d+1,e+1,f+1,g+1,h+1);
                                                                }
                                                            M[h][7]=0;
                                                        }
                                                    }
                                                    M[g][6]=0;
                                                }
                                            }
                                            M[f][5]=0;
                                        }
                                    }
                                    M[e][4]=0;
                                }
                            }
                            M[d][3]=0;
                        }
                    }
                    M[c][2]=0;
                }
            }
            M[b][1]=0;
        }
        M[a][0]=0;
    }
    for (a=0;a<8;a++) {
        for (b=0;b<8;b++) {
            printf("%d|",M[a][b]);
        }
        printf("\n");
    }
}
