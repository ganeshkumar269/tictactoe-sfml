#include<iostream>
#include<conio.h>
#include <time.h>
using namespace std;
//X is represented as -1 an empty cell is represented as a 0 and an O is represented as a 1

    void returnTranspose(int arr[][3],int arr2[][3]){ // takes an input matrix arr and converts arr2 to transpose of arr
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr2[i][j]=arr[j][i];
}
int isSame(int arr[3]){ // checks whether all the elements of the input matrix are of same value and return the value if true
    if(arr[1]==arr[0] && arr[2]==arr[0] && arr[0]!=0)
        return arr[0];
    return 0;
}
void prettyprint(int a[][3]){//prints the grid
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(a[i][j]==0)
            cout<<"\t"<<"_";
        else if(a[i][j]==-1)
            cout<<"\tX";
        else
            cout<<"\tO";
    }
    cout<<endl;
    }
}
int returnRandom(int arr[][3]){ // generates a random index 1-9 which is not already occupied in the grid
    int r = rand()%9;
    int i=r/3;
    int j=r%3;
    if(arr[i][j]!=0)
        return returnRandom(arr);
    return r;
}
int checkDiagnols(int arr[][3]){ //returns the value if all the diagonal elements are the same else return 0
    if(arr[1][1] == arr[0][0] && arr[2][2] == arr[0][0] && arr[0][0]!=0)
        return arr[0][0];
    if(arr[1][1] == arr[0][2] && arr[2][0] == arr[0][2] && arr[0][2]!=0)
        return arr[0][2];
    return 0;
}
bool gameOver(int arr[][3]){ // returns true if the game is over
    int arr2[3][3];
    returnTranspose(arr,arr2);
    for(int i=0;i<3;i++){
        int tmp1=isSame(arr[i]),tmp2=isSame(arr2[i]);
        if(tmp1 == -1 || tmp2 == -1){
            cout<<"Player Wins the Game, Congratulations"<<endl;
            return true;
        }
        if(tmp1 == 1 || tmp2 == 1){
            cout<<"Computer Wins the Game, We'll take over the world soon"<<endl;
            return true;
        }
    }
    int tmp=checkDiagnols(arr);
    if(tmp == -1){
            cout<<"Player Wins the Game, Congratulations"<<endl;
            return true;
        }
        if(tmp == 1){
            cout<<"Computer Wins the Game, We'll take over the world soon"<<endl;
            return true;
        }

    return false;
}
int checkForTwo(int a[3]){ // it check the given row whether it has 2 instances of the same type i.e either X or O
        int x=0,o=0;
        for(int i=0;i<3;i++){
            if(a[i]==-1)
                x++;
            else if(a[i]==1)
                o++;
        }
        cout<<"No.of X s:"<<x<<"- No.of O s:"<<o<<endl;
        if((x+o) == 2){
            if(o == 2){
                for(int k=0;k<3;k++)
                    if(a[k] == 0){
                        cout<<"return value:"<<k<<endl;
                        return k;
                    }
            }
            else if(x == 2){
                for(int k=0;k<3;k++)
                    if(a[k] == 0){
                        cout<<"return value:"<<k<<endl;
                        return k;
                    }
            }
        }
    cout<<"return value:-1"<<endl;
    return -1;
}
int returnOptimal(int arr[][3]){ // return an optimal index
    cout<<"Computer doing checkForTwo"<<endl;
    int v;
    for(int i=0;i<3;i++){
        cout<<"Computer Checking "<<i<<" row"<<endl;
        v=checkForTwo(arr[i]);
        if(v!=-1){
            cout<<"Computer Thinks "<<i<<","<<v<<" as the best move"<<endl;
            return i*3+v;
        }
    }
    int arr2[3][3];
    returnTranspose(arr,arr2);
    cout<<"Computer doing checkForTwo for Transpose"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Computer Checking "<<i<<" row"<<endl;
        v=checkForTwo(arr2[i]);
        if(v!=-1){
            cout<<"Computer Thinks "<<v<<","<<i<<" as the best move"<<endl;
            return i+v*3;
        }
    }
    int arrd1[3],arrd2[3];
    for(int i=0;i<3;i++){
        arrd1[i]=arr[i][i];
        arrd2[i]=arr[i][2-i];
    }
    cout<<"Computer Checking 1st diagonal"<<endl;
    v=checkForTwo(arrd1);
    if(v!=-1){
        cout<<"Computer Thinks "<<v<<","<<v<<" as the best move"<<endl;
        return v*3+v;
    }
    cout<<"Computer Checking 2nd diagonal"<<endl;
    v=checkForTwo(arrd2);
     if(v!=-1){
        cout<<"Computer Thinks "<<v<<","<<v<<" as the best move"<<endl;
        return 2-v+v*3;        //edited from (v+v*3) to 2-v +v*3
    }
    int r = returnRandom(arr);
    cout<<"Computer fetched a random value"<<r/3<<","<<r%3<<endl;
    return r;
}
bool isFull(int arr[][3]){ //checks if the grid is full and can no longer be played
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(arr[i][j] == 0)
                return false;
    return true;
}

/*int game(){
    srand(time(NULL));
    int arr[3][3]={0};
    prettyprint(arr);
    while(1){
        if(isFull(arr)){
            cout<<"Woah , It's a tie!"<<endl;
            break;
        }
        cout<<"Your Move, you are (X) , (1-9):";
        int m;
        cin>>m;
        system("cls");
        m--;
        int i=m/3;
        int j=m%3;
        if(arr[i][j]==1){
            cout<<"Invalid Move"<<endl;
            continue;
        }
        arr[i][j]=-1;
        cout<<"Your Move: ("<<i<<","<<j<<")"<<endl;
        if(gameOver(arr))
            break;
        if(isFull(arr)){
            cout<<"Woah , It's a tie!"<<endl;
            break;
        }
        int r=returnOptimal(arr);
        i=r/3;
        j=r%3;
        arr[i][j]=1;
        cout<<"Computer Move: ("<<i<<","<<j<<")"<<endl;
        prettyprint(arr);
        if(gameOver(arr))
            break;
    }

}*/

