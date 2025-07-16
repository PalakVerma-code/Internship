#include<iostream>
using namespace std;
char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int col;
char turn='X';
bool tie=false;
string p1,p2;
void functionOne(){
    
  
    
    cout<<"   |    "<<"     |"<<"   \n";
    cout<<" "<<arr[0][0]<<" |"<<"   "<<arr[0][1]<<"     |"<<" "<<arr[0][2]<<endl;
    cout<<"   |    "<<"     |"<<"   \n";
    cout<<"--------------------\n";
    cout<<"   |    "<<"     |"<<"   \n";
     cout<<" "<<arr[1][0]<<" |"<<"   "<<arr[1][1]<<"     |"<<" "<<arr[1][2]<<endl;
    cout<<"   |    "<<"     |"<<"   \n";
    cout<<"--------------------\n";
    cout<<"   |    "<<"     |"<<"   \n";
     cout<<" "<<arr[2][0]<<" |"<<"   "<<arr[2][1]<<"     |"<<" "<<arr[2][2]<<endl;
    cout<<"   |    "<<"     |"<<"   \n";

}
void functionTwo(){
    int digit;
    if(turn=='X'){
        cout<<p1<<"please Enter";
        cin>>digit;
    }
    if (turn=='0'){
        cout<<p2<<"please Enter";
        cin>>digit;
    }if(digit==1){
        row=0;col=0;
    }
    if(digit==2){
        row=0;col=1;
    }if(digit==3){
        row=0;col=2;
    }if(digit==4){
        row=1;col=0;
    }if(digit==5){
        row=1;col=1;
    }if(digit==6){
        row=1;col=2;
    }if(digit==7){
        row=2;col=0;
    }if(digit==8){
        row=2;col=1;
    }if(digit==9){
        row=2;col=2;
    }
    else if(digit<1||digit>9){
        cout<<"invalid \n";
    }
    if(turn=='X'&&arr[row][col]!='X'&& arr[row][col]!='0'){
        arr[row][col]='X';
        turn='0';
    } else  if(turn=='0'&&arr[row][col]!='X'&& arr[row][col]!='0'){
        arr[row][col]='0';
        turn='X';
    }else{
       functionTwo();
    }
    functionOne();
}
bool functionThree(){
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1]&& arr[i][0]==arr[i][2]||arr[0][i]==arr[1][i]&&arr[0][i]==arr[2][i])
        return true;
    }
{if(arr[0][0]==arr[1][1]&& arr[1][1]==arr[2][2]||arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])
    return true;}


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!='X'&&arr[i][j]!='0'){
                return false;
            }
        }
    }
    tie=true;
    return false;
}
int main(){
    
    cout<<"Enter the name of Player1: \n";
    getline(cin,p1);
    cout<<"Enter the name of Player2: \n";
    getline(cin,p2);
    cout<<p1<<"is player1 so your turn is first\n";
     cout<<p2<<"is player2 so your turn is second\n";
     while (!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
     }
     if(turn =='X'&&tie==false){
        cout<<p2<<"Wins!!\n";
     }else if(turn =='0'&&tie==false){
        cout<<p1<<"wins!!\n";
     }else{
        cout<<"Draw\n";
     }

}