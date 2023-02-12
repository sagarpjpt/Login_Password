#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t_____________________________________________\n\n\n";
    cout<<"\t\t\t              welcome to the login page      \n\n\n";
    cout<<"\t\t\t__________________     menu    ______________\n\n\n";
    cout<<"                                                   \n\n\n";
    cout<<"\t| press 1 to LOGIN                      |"<<endl;
    cout<<"\t| press 2 to REGISTER                   |"<<endl;
    cout<<"\t| press 3 to if you forgot your PASSWORD|"<<endl;
    cout<<"\t| press 4 to EXIT                       |"<<endl;
    cout<<"\n\t\t\t Please enter your choice : "; 
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1 :
            login();
            break;
        case 2 :
            registration();
            break;
        case 3 :
            forgot();
            break;
        case 4 :
            cout<<"\t\t\t thank you \n\n";
            break;
        default :
            system("cls");
            cout<<"\t\t\t Please select from the option given above \n"<<endl;
            main();
    }
}
void login()
{
    int count=0;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t Please enter the usrename and password : "<<endl;
    cout<<"\t\t\t Username ";
    cin>>userId;
    cout<<"\t\t\t Password ";
    cin>>password;

    ifstream input;
    input.open("record.txt");
    if(input.is_open()){
        while(input.good()){
            input>>id;//input read til first space
            input>>pass;
            if(id==userId && pass==password){
                count=1;
                system("cls");
                break;
            }
        }  
    } 
    else{
        cout<<"\t\t\tfile not opened\n\n";
    }
    /*while(input>>id>>pass){
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }*/
    input.close();
    if(count==1)
    {
        cout<<userId<<"\n Your login is succesfull \n thanks for login in\n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n please register first \n";
        main();
    }
}
void registration()
{
    string ruserId,rpassword;
    system("cls");
    cout<<"\t\t\t enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t enter the password : ";
    cin>>rpassword;
    ofstream f1("record.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\tregistration is successfull \n";
    main();
}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t you forget the password No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go the main menu "<<endl;
    cout<<"\t\t\tenter your choice : ";
    cin>>option;

    switch(option){
        case 1 :
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"enter the username that you remembered : ";
            cin>>suserId;
            
            ifstream f2("record.txt");
            while(f2)
            {
                f2>>sId;
                f2>>spass;
                if(sId==suserId){
                    count=1;
                    break;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n Your account is found : \n";
                cout<<"\n\n Your password is : "<<spass;
                main();
            }
            else{
                cout<<"\n\tsorry your account is not found !";
                main();
            }
            break;
        }
        case 2 :
        {
            main();
            
        }
        default :
            cout<<"\t\t\t wrong choice ! please try again "<<endl;
            forgot(); 
    }
}