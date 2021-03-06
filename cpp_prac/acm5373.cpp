//200521 gold1 for sds 
#include<iostream>
#include<string>
#include<map>

using namespace std;

int t,n;
char cube[6][3][3];
map<string,int> pton;
int temp[12][12][3]= //F+,F-,D+,D-,B+,B-,U+,U-,L+,L-,R+,R-
{
    {{4,2,2},{4,1,2},{4,0,2},{3,2,0},{3,2,1},{3,2,2},{5,0,0},{5,1,0},{5,2,0},{1,0,2},{1,0,1},{1,0,0}},
    {{5,0,0},{5,1,0},{5,2,0},{1,0,2},{1,0,1},{1,0,0},{4,2,2},{4,1,2},{4,0,2},{3,2,0},{3,2,1},{3,2,2}},
    {{4,2,0},{4,2,1},{4,2,2},{0,2,0},{0,2,1},{0,2,2},{5,2,0},{5,2,1},{5,2,2},{2,2,0},{2,2,1},{2,2,2}},
    {{5,2,0},{5,2,1},{5,2,2},{2,2,0},{2,2,1},{2,2,2},{4,2,0},{4,2,1},{4,2,2},{0,2,0},{0,2,1},{0,2,2}},
    {{5,2,2},{5,1,2},{5,0,2},{3,0,2},{3,0,1},{3,0,0},{4,0,0},{4,1,0},{4,2,0},{1,2,0},{1,2,1},{1,2,2}},
    {{4,0,0},{4,1,0},{4,2,0},{1,2,0},{1,2,1},{1,2,2},{5,2,2},{5,1,2},{5,0,2},{3,0,2},{3,0,1},{3,0,0}},
    {{4,0,2},{4,0,1},{4,0,0},{2,0,2},{2,0,1},{2,0,0},{5,0,2},{5,0,1},{5,0,0},{0,0,2},{0,0,1},{0,0,0}},
    {{5,0,2},{5,0,1},{5,0,0},{0,0,2},{0,0,1},{0,0,0},{4,0,2},{4,0,1},{4,0,0},{2,0,2},{2,0,1},{2,0,0}},
    {{2,2,2},{2,1,2},{2,0,2},{3,0,0},{3,1,0},{3,2,0},{0,0,0},{0,1,0},{0,2,0},{1,0,0},{1,1,0},{1,2,0}},
    {{0,0,0},{0,1,0},{0,2,0},{1,0,0},{1,1,0},{1,2,0},{2,2,2},{2,1,2},{2,0,2},{3,0,0},{3,1,0},{3,2,0}},
    {{0,2,2},{0,1,2},{0,0,2},{3,2,2},{3,1,2},{3,0,2},{2,0,0},{2,1,0},{2,2,0},{1,2,2},{1,1,2},{1,0,2}},
    {{2,0,0},{2,1,0},{2,2,0},{1,2,2},{1,1,2},{1,0,2},{0,2,2},{0,1,2},{0,0,2},{3,2,2},{3,1,2},{3,0,2}}
};

int origin[12][12][3]=
{
    {{3,2,0},{3,2,1},{3,2,2},{5,0,0},{5,1,0},{5,2,0},{1,0,2},{1,0,1},{1,0,0},{4,2,2},{4,1,2},{4,0,2}},
    {{3,2,0},{3,2,1},{3,2,2},{5,0,0},{5,1,0},{5,2,0},{1,0,2},{1,0,1},{1,0,0},{4,2,2},{4,1,2},{4,0,2}},
    {{0,2,0},{0,2,1},{0,2,2},{5,2,0},{5,2,1},{5,2,2},{2,2,0},{2,2,1},{2,2,2},{4,2,0},{4,2,1},{4,2,2}},
    {{0,2,0},{0,2,1},{0,2,2},{5,2,0},{5,2,1},{5,2,2},{2,2,0},{2,2,1},{2,2,2},{4,2,0},{4,2,1},{4,2,2}},
    {{3,0,2},{3,0,1},{3,0,0},{4,0,0},{4,1,0},{4,2,0},{1,2,0},{1,2,1},{1,2,2},{5,2,2},{5,1,2},{5,0,2}},
    {{3,0,2},{3,0,1},{3,0,0},{4,0,0},{4,1,0},{4,2,0},{1,2,0},{1,2,1},{1,2,2},{5,2,2},{5,1,2},{5,0,2}},
    {{2,0,2},{2,0,1},{2,0,0},{5,0,2},{5,0,1},{5,0,0},{0,0,2},{0,0,1},{0,0,0},{4,0,2},{4,0,1},{4,0,0}},
    {{2,0,2},{2,0,1},{2,0,0},{5,0,2},{5,0,1},{5,0,0},{0,0,2},{0,0,1},{0,0,0},{4,0,2},{4,0,1},{4,0,0}},
    {{3,0,0},{3,1,0},{3,2,0},{0,0,0},{0,1,0},{0,2,0},{1,0,0},{1,1,0},{1,2,0},{2,2,2},{2,1,2},{2,0,2}},
    {{3,0,0},{3,1,0},{3,2,0},{0,0,0},{0,1,0},{0,2,0},{1,0,0},{1,1,0},{1,2,0},{2,2,2},{2,1,2},{2,0,2}},
    {{3,2,2},{3,1,2},{3,0,2},{2,0,0},{2,1,0},{2,2,0},{1,2,2},{1,1,2},{1,0,2},{0,2,2},{0,1,2},{0,0,2}},
    {{3,2,2},{3,1,2},{3,0,2},{2,0,0},{2,1,0},{2,2,0},{1,2,2},{1,1,2},{1,0,2},{0,2,2},{0,1,2},{0,0,2}},
};
void rotate(string pandw);
void rotatep(string pandw);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>t;
    pton["F+"]=0; pton["F-"]=1; pton["D+"]=2; pton["D-"]=3; pton["B+"]=4; pton["B-"]=5;
    pton["U+"]=6; pton["U-"]=7; pton["L+"]=8; pton["L-"]=9; pton["R+"]=10; pton["R-"]=11;
    string color="ryowgb";

    for(int tc=1; tc<=t; ++tc)
    {
        for(int i=0; i<6; ++i)
        {
            char c=color[i];
            for(int j=0; j<3; ++j){for(int k=0; k<3; ++k){cube[i][j][k]=c;}}
        }
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            string pandw;
            cin>>pandw;
            rotate(pandw);
        }
        for(int i=0; i<3; ++i){for(int j=0; j<3; ++j){cout<<cube[3][i][j];} cout<<"\n";}
    }
    return 0;
}

void rotate(string pandw)
{
    int p=pton[pandw];
    string str="000000000000";
    for(int i=0; i<12; ++i){str[i]=cube[temp[p][i][0]][temp[p][i][1]][temp[p][i][2]];}
    for(int i=0; i<12; ++i){cube[origin[p][i][0]][origin[p][i][1]][origin[p][i][2]]=str[i];}
    rotatep(pandw);
};

void rotatep(string pandw)
{
    int p=pton[pandw]/2;
    char c=cube[p][0][0];
    int i,j;
    int num[8];
    int index=0;
    if(pandw[1]=='-'){ i=0; j=2;}
    else if(pandw[1]=='+'){i=2; j=0;}
    while(1)
    {
        if(i<2 && j==2)
        {
            num[index++]=cube[p][i][j];
            i++;
        }else if(i==2 && j>0)
        {
            num[index++]=cube[p][i][j];
            j--;
        }else if(i>0 && j==0)
        {
            num[index++]=cube[p][i][j];
            i--;
        }else if(i==0 && j<2)
        {
            num[index++]=cube[p][i][j];
            j++;
        }
        if(index==8) break;
    }
    i=0; j=0; index=0;
    while(1)
    {
        if(i<2 && j==2)
        {
            cube[p][i][j]=num[index++];
            i++;
        }else if(i==2 && j>0)
        {
            cube[p][i][j]=num[index++];
            j--;
        }else if(i>0 && j==0)
        {
            cube[p][i][j]=num[index++];
            i--;
        }else if(i==0 && j<2)
        {
            cube[p][i][j]=num[index++];
            j++;
        }
        if(index==8) break;
    }
}


