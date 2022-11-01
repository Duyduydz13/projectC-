#include <iostream>

#include "console.h"
#include<conio.h>
#include"myLib.h"
#include"dataBase.h"
using namespace std;
 typedef char str[31];
 #define MAUNEN 0
 #define MAUCHU 7
 str thaotac[4]={"Add New Data","View List Of Donar","Search Donar","Exit"};
 bool over =true;
 enum trangThai{UP,
				 DOWN,
				 RIGHT,
				 ENTER
 				};
 				
trangThai key(int z){
	if (z==224){
		char c;
		c=getch();
		if (c==72){
			return UP;
		}
		if (c==80){
			return DOWN;
		}
		if (c==77){
			return RIGHT;
		}
		if (c==13){
			return ENTER;
		}
	}
}
//
int menu (str thaotac[],int n);
int menuTinh(int n);
void printTie();
 int main(){
 	DataBase db;
 	menu (thaotac,4);
 	system("cls");
 	return 0;
 }
 int menu (str thaotac[],int n){
 	int tt=0;// chi ra dang nam o thao tac nao 
 	int *mau=new int [n];
 	for (int i=0;i<n;i++){
 		mau[i]=MAUCHU;
	 }
	 mau[0]=MAUNEN;//point dang nam o dong 1
	 while(over){
	 	system("cls");
	 	//in giao dien menu
	 	printTie();
	 	for (int i=0;i<n;i++){
	 		textcolor(mau[i]);
	 		cout<<i+1<<" "<<thaotac[i]<<endl;
		 }
	 	int z=getch();
	 	trangThai trangthai=key(z);
	 	switch(trangthai){
	 		case UP:{
	 			if (tt==0){
	 				tt=n-1;
				 }
				 else tt--;
				break;
			 }
			case DOWN:{
				if (tt==n-1){
					tt=0;
				}
				else
				   tt++;
				break;
			}
			case RIGHT :{
				
				menuTinh(tt);
			}
	 			
		 }
		for (int i=0;i<n;i++){
 		mau[i]=MAUCHU;
	 }
	 mau[tt]=MAUNEN;
	 }
 	
 }
 void printTie(){
	cout<<"\n\t\t\t\t\t===========================================";
    cout<<"\n\t\t\t\t\t|   Simple Blood Bank Management System   |"<<endl;
    cout<<"\t\t\t\t\t===========================================";
    cout<<endl;
		
}

int menuTinh(int n)
{
    DataBase db;
    while (true){
        switch (n+1)
        {

        case 1:
        {
            system("cls");
            db.data("add");
            system("cls");
            menu (thaotac,4);
        }

        case 2:
        {
            system("cls");
            db.data("view");
            system("cls");
            menu (thaotac,4);
        }
        case 3:
        {
            system("cls");
            db.data("search");
            system("cls");
            menu (thaotac,4);
        }

        case 4:
        {
            over=false;
            return 0;
        }

}
    }
    return 0;
}
