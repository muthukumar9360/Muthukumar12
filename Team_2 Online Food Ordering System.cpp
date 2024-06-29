#include<iostream>
#include<fstream>
#include<cstdlib>
#include<regex>
#include<iomanip>
#include<exception>

using namespace std;

string phno;
int cop=1;

class MenuItem
{
protected:
    string fn,fn1,ft,ft1,uid,name,name1,dob,dob1,gender,gender1,userid,userid1,pass,pass1,ph,ph1,gmail,gmail1;
    int fid,fid1,fdis,fdis1,option,quan;
    float fp,fp1,tp;
    char ch;
    string dis="district.txt";
    float rating;
    string sf;
public:
    MenuItem() {}
    ~MenuItem() {}

    void mainmenu()
    {
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t__________________________________________\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t| WELCOME TO ONLINE FOOD ORDERING SYSTEM |\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t__________________________________________\n"<<endl<<endl;
error:
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t              -----------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t               HOME PAGE\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t              -----------\n"<<endl<<endl<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t1) MANAGER PAGE \n\n\t\t\t\t2) CUSTOMER PAGE \n\n\t\t\t\t3) EXIT [QUIT]\n\n\n\t\t\t\tENTER YOUR OPTION : ";
        cin>>option;
        system("cls");
        if(option == 1 || option == 2)
        {
            system("cls");
            chooseusertype();
        }
        else if(option== 3)
        {
            system("cls");
            return;
        }
        else
        {
            system("cls");
            cerr<<"\n\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT OPTION...\n";
            goto error;
        }
    }
    void chooseusertype()
    {
        int choice;
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t              MAIN MENU\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t            _____________\n";
        if(option==1)
        {
            cout<<"\n\n\n\n\t\t\t\t    MANAGER";
            cout<<"\n\t\t\t\t   _________\n";
        }
        else if(option==2)
        {
            cout<<"\n\n\n\n\t\t\t\t    CUSTOMER";
            cout<<"\n\t\t\t\t    __________\n";
        }
        cout<<"\n\n\n\t\t\t\t1) SIGNUP [CREATE AN NEW ACCOUNT]\n\n\t\t\t\t2) LOGIN [ALREADY ACCOUNT EXISTS]\n\n\t\t\t\t3) BACK TO HOME PAGE ";
        cout<<"\n\n\n\t\t\t\tENTER YOUR OPTION : ";
        cin>>choice;
        if(choice==1)
        {
            system("cls");
            signup();
        }
        else if(choice==2)
        {
            system("cls");
            login();
        }
        else if(choice==3)
        {
            mainmenu();
        }
        else
        {
            system("cls");
            cerr<<"\n\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT OPTION...\n";
            chooseusertype();
        }
    }
    void signup()
    {
        string sp;
        int sc;
        if(option==1)
        {
            cout<<"\n\n\n\n\n\t\t\t\t    | SIGNUP PAGE [MANAGER] |";
            cout<<"\n\t\t\t\t    ________________________\n";
        }
        else if(option==2)
        {
            cout<<"\n\n\n\n\n\t\t\t\t    | SIGNUP PAGE [CUSTOMER] |";
            cout<<"\n\t\t\t\t    __________________________\n";
        }
reenter:
        cout<<"\n\n\t\t\t\tENTER FULLNAME [without spaces] : ";
        cin.get();
        getline(cin,name);
emch:
        cout<<"\n\t\t\t\tENTER YOUR EMAIL ID             : ";
        cin>>gmail;
        regex email_pattern("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+.[a-zA-Z0-9-.]+$)");
        try
        {
            if (!regex_match(gmail, email_pattern))
            {
                throw(gmail);
            }
        }
        catch(...)
        {
            cerr << "\n\n\t\t\t\tERROR : PLEASE ENTER A VALID EMAIL ID...\n";
            goto emch;
        }
phch:
        cout<<"\n\t\t\t\tENTER YOUR MOBILE NUMBER(+91)   : ";
        cin>>ph;
        try
        {
            if(ph.length()!=10)
            {
                throw(ph);
            }
        }
        catch(...)
        {
            cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER 10 DIGIT NUMBER....\n";
            goto phch;
        }

dobch:
        cout<<"\n\t\t\t\tENTER YOUR DOB (DD/MM/YY)       : ";
        cin>>dob;
        try
        {
            if(dob[2]!='/' && dob[5]!='/'&& (dob.length()!=10))
            {
                throw(dob);
            }
        }
        catch(...)
        {
            cout<<"\n\n\t\t\t\tERROR : PLEASE ENTER DOB AS THIS FORMAT[DDMMYY]....\n";
            goto dobch;
        }
        cout<<"\n\t\t\t\tENTER YOUR GENDER[Male/Female]  : ";
        cin>>gender;
usps:
        system("cls");
        cerr<<"\n\n\t\t\t\tNOTE : [USERID AND PASSWORD CAN'T BE SAME....]\n";
        cout<<"\n\t\t\t\tCREATE YOUR USERID              : ";
        cin>>userid;
        cout<<"\n\t\t\t\tCREATE YOUR PASSWORD            : ";
        cin>>pass;
        if(userid==pass)
        {
            goto usps;
        }
check:
        if(option==1)
        {
            cout<<"\n\t\t\t\tENTER COMPANY'S SECRET CODE     : ";
            cin>>sc;
            cout<<"\n\t\t\t\tENTER COMPANY'S SECRET PASSWORD : ";
            cin>>sp;
        }
        if((sc==2024 && sp=="Mass12" && option==1) || option==2)
        {
            ifstream f1;
            ofstream f;
            if(option==1)
            {
                f1.open("manager.txt");
                f.open("manager.txt",ios::app);
            }
            else if(option==2)
            {
                f1.open("customer.txt");
                f.open("customer.txt",ios::app);
            }
            int c=0;
            while(f1>>userid1>>pass1>>name1>>gmail1>>dob1>>gender1>>ph1)
            {
                if(userid1==userid)
                {
                    c=1;
                    system("cls");
                    cerr<<"\n\t\t\t\tERROR : USERID ALREADY EXIST.PLEASE TRY TO LOGIN USING YOUR USERID AND PASSWORD OR CREATE NEW ONE\n";
                    chooseusertype();
                    break;
                }
            }
            f1.close();
            if(c==0)
            {
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t\tYOUR NAME     : "<<name;
                cout<<"\n\n\t\t\t\tUSERID        : "<<userid;
                cout<<"\n\n\t\t\t\tPASSWORD      : "<<pass;
                cout<<"\n\n\t\t\t\tEMAIL ID      : "<<gmail;
                cout<<"\n\n\t\t\t\tMOBILE NUMBER : "<<ph;
                cout<<"\n\n\t\t\t\tDATE OF BIRTH : "<<dob;
                cout<<"\n\n\t\t\t\tGENDER        : "<<gender;
            }
            cout<<"\n\n\t\t\t\tIS ALL YOUR DETAILS ARE CORRECT (Y/N) : ";
            cin>>ch;
            if(ch=='Y' || ch=='y')
            {
                system("cls");
                cout<<"\n\n\n\n\t\t\t\tACCOUNT CREATED SUCCESSFULLY....\n";
                f<<left<<setw(25)<<userid<<' '<<left<<setw(25)<<pass<<' '<<left<<setw(30)<<name<<' '<<left<<setw(35)<<gmail<<' '<<left<<setw(15)<<dob<<' '<<left<<setw(15)<<ph<<' '<<left<<setw(10)<<gender<<endl;
                f.close();
                login();
            }
            else
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : PLEASE RE-ENTER YOUR DETAILS ";
                goto reenter;
            }
        }
        else
        {
            system("cls");
            cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT SECRET CODE AND SECRET PASSWORD....\n";
            goto check;
        }
    }
    void login()
    {
        ifstream f1;
        cerr<<"\n\n\n\n\t\t\t\tNOTE : PLEASE LOGIN USING YOUR USERID AND PASSWORD....\n\n";
        if(option==1)
        {
            cout<<"\n\n\n\t\t\t\t  | LOGIN PAGE [MANAGER] |";
            cout<<"\n\t\t\t\t   ______________________\n";
            f1.open("manager.txt");
        }
        else if(option==2)
        {
            cout<<"\n\n\n\t\t\t\t  | LOGIN PAGE [CUSTOMER] |";
            cout<<"\n\t\t\t\t   _______________________\n";
            f1.open("customer.txt");
        }
        cout<<"\n\n\t\t\t\tENTER USER ID  : ";
        cin>>userid;
        cout<<"\n\t\t\t\tENTER PASSWORD : ";
        cin>>pass;
        int c=0;
        while(f1>>userid1>>pass1>>name1>>gmail1>>dob1>>ph1>>gender1)
        {
            if(userid==userid1 && pass==pass1)
            {
                c=1;
                ::phno=ph1;
                if(option==1)
                {
                    ::cop=1;
                }
                else if(option==2)
                {
                    ::cop=2;
                }
                break;
            }
        }
        f1.close();
        if(c==1)
        {
            system("cls");
            uid=userid;
            food();
        }
        else
        {
            system("cls");
            cout<<"\n\n\t\t\t\tDO YOU FORGOT YOUR USER ID AND PASSWORD [Y/N] : ";
            cin>>ch;
            if(ch=='Y' || ch=='y')
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : PLEASE SIGNUP FOR ANOTHER TIME"<<endl;
                signup();
            }
            else
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : FAILED TO LOGIN...\n";
                login();
            }
        }
    }
    void food()
    {
retry:
        int c;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t              MAIN MENU\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t\t            _____________\n";
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        if(option==1)
        {
            cout<<"\n\n\t\t\t\t1) DISPLAY THE ITEMS \n\n\t\t\t\t2) ADD AN NEW ITEM \n\n\t\t\t\t3) UPDATE AN EXISTING ITEM \n\n\t\t\t\t4) DELETE AN EXISTING ITEM \n\n\t\t\t\t5) VIEW YOUR PROFILE \n\n\t\t\t\t6) VIEW ORDER DETAILS \n\n\t\t\t\t7) VIEW CUSTOMERS RATING AND FEEDBACK \n\n\t\t\t\t8) BACK TO HOME PAGE [QUIT]\n\n\n\t\t\t\tENTER YOUR OPTION : ";
            cin>>c;
            try
            {
                if(c==1)
                {
                    system("cls");
                    display();
                }
                else if(c==2)
                {
                    system("cls");
                    add();
                }
                else if(c==3)
                {
                    system("cls");
                    update();
                }
                else if(c==4)
                {
                    system("cls");
                    del();
                }
                else if(c==5)
                {
                    system("cls");
                    profile();
                }
                else if(c==6)
                {
                    system("cls");
                    orderdetails();
                }
                else if(c==7)
                {
                    system("cls");
                    ratfeed();
                }
                else if(c==8)
                {
                    mainmenu();
                }
                else
                {
                    throw(option);
                }
            }
            catch(...)
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT OPTION.... ";
                goto retry;
            }
        }
        else if(option==2)
        {
            cout<<"\n\n\t\t\t\t1) DISPLAY THE ITEMS \n\n\t\t\t\t2) VIEW ITEMS IN THE CART {PAYMENT PAGE]\n\n\t\t\t\t3) ADD AN NEW ITEM TO CART\n\n\t\t\t\t4) DELETE AN ITEM FROM CART \n\n\t\t\t\t5) VIEW YOUR PROFILE \n\n\t\t\t\t6) BACK TO HOME PAGE [QUIT] \n\n\n\t\t\t\tENTER YOUR OPTION : ";
            cin>>c;
            try
            {
                if(c==1)
                {
                    system("cls");
                    display();
                }
                else if(c==2)
                {
                    system("cls");
                    viewcart();
                }
                else if(c==3)
                {
                    system("cls");
                    addtocart();
                }
                else if(c==4)
                {
                    system("cls");
                    delcart();
                }
                else if(c==5)
                {
                    system("cls");
                    profile();
                }
                else if(c==6)
                {
                    mainmenu();
                }
                else
                {
                    throw(option);
                }
            }
            catch(...)
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT OPTION.... ";
                goto retry;
            }
        }
    }
    void ratfeed()
    {
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t***RATINGS AND FEEDBACKS***"<<endl<<endl;
        int i=1;
        ifstream f("ratingfeedback.txt");
        if(!f)
        {
            cout<<"\n\n\n\t\t\t\tCURRENTLY NO RATINGS OR FEEDBACKS AVAILABLE ....";
        }
        while (f >> userid1 >> gmail1 >> ph1 >> rating)
        {
            cout<<"\n\t\t\t"<<i<<")";
            f.ignore();
            getline(f, sf);
            cout << "\n\t\t\t\tUSER ID      : " << userid1 << "\n\t"
                 << "\t\t\tEMAIL ID     : " << gmail1 << "\n\t"
                 << "\t\t\tPHONE NUMBER : " << ph1 << "\n\t"
                 << "\t\t\tRATING       : " << rating << "\n\t"
                 << "\t\t\tFEEDBACK     : " << sf << "\n\t";
                 cout<<endl<<endl;
                 i++;
        }
        f.close();
        cout<<"\n\n\n\t\t\t\tENTER [C] TO CONTINUE | [R] TO REMOVE FEEDBACKS .... ";
        cin>>ch;
        if(ch=='c' || ch=='C')
        {
            system("cls");
            food();
        }
        else if(ch=='R' || ch=='r')
        {
            remove("ratingfeedback.txt");
            system("cls");
            cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t    ***FEEDBACKS REMOVED SUCCESSFULLY***";
            ratfeed();
        }
        else
        {
            system("cls");
            ratfeed();
        }
    }
    void orderdetails()
    {
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        ifstream f("order.txt");
        string id,d,t;
        float sum=0.0,p;
        cout << "\n\n\n\t\t\t\t | ORDER DETAILS |";
        cout << "\n\t\t\t\t _________________\n";
        cout<<endl<<endl;
        cout << "\t\t\t\t-------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|" << left << setw(30) <<"   USERID   " << "|" << "  " << left << setw(20) << "AMOUNT" << "|" << "  " << left << setw(15) << "DATE" << "|" << "  "
             << left << setw(15) << "TIME" << "|" << endl;
        cout << "\t\t\t\t-------------------------------------------------------------------------------------------" << endl;
        while (f >> id >> p >> d >> t)
        {
            sum+=p;
            cout << "\t\t\t\t|   " << setw(24) << id << "   |  ";
            cout << setw(20) << p << "|  ";
            cout << setw(15) << d << "|  ";
            cout << setw(15) << t << "|";
            cout << "\n\t\t\t\t-------------------------------------------------------------------------------------------" << endl;
        }
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTOTAL PRICE : "<<sum<<"/-";
        f.close();
        cout<<"\n\n\n\t\t\t\tENTER [C] TO CONTINUE .... ";
        cin>>ch;
        if(ch=='c' || ch=='C')
        {
            system("cls");
            food();
        }
        else
        {
            system("cls");
            orderdetails();
        }
    }
    virtual void display()
    {
        ifstream f("foodlist.txt");
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t_____________________________________________________________________________________"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t"<<setw(8)<<left<<"|  ID No.  "<<setw(25)<<left<<"|      FOOD NAME "<<setw(15)<<left<<"|     TYPE"<<setw(15)<<left<<"  |    PRICE     "<<setw(1)<<left<<" |  DISCOUNT[%] |"<<endl;
        cout<<"\t\t\t\t\t\t\t\t_____________________________________________________________________________________"<<endl;
        if(f.peek()==EOF)
        {
            cerr<<"\n\n\t\t\t\t\t\t\tERROR : CURRENTLY NO ITEMS AVAILABLE \n";
        }
        else
        {
            while(f>>fid1>>fn1>>ft1>>fp1>>fdis1)
            {
                cout<<"\n\t\t\t\t\t\t\t\t|  "<<setw(8)<<left<<fid1<<"|  \t"<<setw(14)<<left<<fn1<<"      |\t "<<setw(10)<<left<<ft1<<"  |\t  "<<setw(10)<<left<<fp1<<" |   "<<setw(11)<<left<<fdis1<<'|'<<endl;
                cout<<"\t\t\t\t\t\t\t\t_____________________________________________________________________________________"<<endl;
            }
        }
        f.close();
        cout<<"\n\n\t\t\t\tENTER [C] TO CONTINUE .... ";
        cin>>ch;
        if(ch=='C' || ch=='c')
        {
            system("cls");
            food();
        }
        else
        {
            system("cls");
            display();
        }
    }
    void add()
    {
retry1:
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t*** ADD NEW ITEM ***"<<endl<<endl;
        cout<<"\n\t\t\t\tENTER FOOD ID    : ";
        cin>>fid;
        cout<<"\n\t\t\t\tENTER FOOD NAME  : ";
        cin>>fn;
        ifstream f1("foodlist.txt");
        int c=0;
        while(f1>>fid1>>fn1>>ft1>>fp1>>fdis1)
        {
            if(fid1==fid || fn1==fn)
            {
                c=1;
                break;
            }
        }
        f1.close();
        if(c==0)
        {
            cout<<"\n\t\t\t\tENTER FOOD TYPE  : ";
            cin>>ft;
            cout<<"\n\t\t\t\tENTER FOOD PRICE : ";
            cin>>fp;
            cout<<"\n\t\t\t\tENTER DISCOUNT(%): ";
            cin>>fdis;
            ofstream f("foodlist.txt",ios::app);
            f<<left<<setw(10)<<fid<<' '<<left<<setw(20)<<fn<<' '<<left<<setw(15)<<ft<<' '<<left<<setw(10)<<fp<<' '<<left<<setw(10)<<fdis<<endl;
            f.close();
            cout<<"\n\n\n\t\t\t\t\t\t   ***** ITEM ADDED SUCCESSFULLY *****\n\n\n";
        }
        else
        {
            system("cls");
            cerr<<"\n\n\t\t\t\tERROR : FOOD ALREADY EXIST WITH THIS ID AND NAME...PLEASE ENTER DIFFERENT ID AND NAME\n\n";
            goto retry1;
        }
        cout<<"\n\t\t\t\tDO YOU WANT TO ADD MORE ITEMS (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            add();
        }
        else
        {
            system("cls");
            food();
        }
    }
    void update()
    {
retry2:
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE AN ITEM ***"<<endl<<endl;
        cout<<"\n\t\t\t\tENTER THE ID OF THE FOOD THAT YOU WANT TO UPDATE : ";
        cin>>fid;
        ifstream f("foodlist.txt");
        ofstream f1("temp.txt",ios::app);
        int c=0;
        while(f>>fid1>>fn1>>ft1>>fp1>>fdis1)
        {
            if(fid==fid1)
            {
                c=1;
                int ch;
ch:
                cout<<"\n\n\t\t\t\t.....YOUR SELECTED ITEM IS "<<fn1<<" ....."<<endl<<endl;
                cout<<"\n\t\t\t\t1)NAME \n\t\t\t\t2)TYPE \n\t\t\t\t3)PRICE \n\t\t\t\t4)DISCOUNT\n";
                cout<<"\n\t\t\t\tENTER THE OPTION OF WHICH YOU WANT TO UPDATE : ";
                cin>>ch;
                if(ch==1)
                {
                    cout<<"\n\t\t\t\tENTER THE FOOD NAME : ";
                    cin>>fn;
                    f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<endl;
                }
                else if(ch==2)
                {
                    cout<<"\n\t\t\t\tENTER THE FOOD TYPE : ";
                    cin>>ft;
                    f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<endl;
                }
                else if(ch==3)
                {
                    cout<<"\n\t\t\t\tENTER THE FOOD PRICE : ";
                    cin>>fp;
                    f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<fp<<' '<<left<<setw(10)<<fdis1<<endl;
                }
                else if(ch==4)
                {
                    cout<<"\n\t\t\t\tENTER THE FOOD DISCOUNT : ";
                    cin>>fdis;
                    f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis<<endl;
                }
                else
                {
                    system("cls");
                    cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT OPTION.... ";
                    goto ch;
                }
            }
            else
            {
                f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<endl;
            }
        }
        f.close();
        f1.close();
        if(c==0)
        {
            system("cls");
            cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT FOOD ID THAT YOU WANT TO UPDATE...";
            goto retry2;
        }
        remove("foodlist.txt");
        rename("temp.txt","foodlist.txt");
        cout<<"\n\n\n\t\t\t\t\t\t ***** ITEM UPDATED SUCCESSFULLY *****\n\n\n";
        cout<<"\n\t\t\t\tDO YOU WANT TO UPDATE MORE ITEMS (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            update();
        }
        else
        {
            system("cls");
            food();
        }
    }
    void del()
    {
retry1:
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t*** DELETE AN ITEM ***"<<endl<<endl;
        cout<<"\n\t\t\t\tENTER THE ID OF THE FOOD THAT YOU WANT TO DELETE : ";
        cin>>fid;
        ifstream f("foodlist.txt");
        ofstream f1("temp.txt",ios::app);
        int c=0;
        while(f>>fid1>>fn1>>ft1>>fp1>>fdis1)
        {
            if(fid==fid1)
            {
                c=1;
                continue;
            }
            else
            {
                f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<endl;
            }
        }
        f.close();
        f1.close();
        if(c==0)
        {
            system("cls");
            cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT FOOD ID THAT YOU WANT TO UPDATE...";
            goto retry1;
        }
        remove("foodlist.txt");
        rename("temp.txt","foodlist.txt");
        cout<<"\n\n\n\t\t\t\t\t\t ***** ITEM DELETED SUCCESSFULLY *****\n\n\n";
        cout<<"\n\t\t\t\tDO YOU WANT TO DELETE MORE ITEMS (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            del();
        }
        else
        {
            system("cls");
            food();
        }
    }
    void profile()
    {
        ifstream f;
        if(option==1)
        {
            f.open("manager.txt");
            cout<<"\n\n\n\n\t\t\t\t  [MANAGER]";
            cout<<"\n\t\t\t\t  _________";
        }
        else if(option==2)
        {
            f.open("customer.txt");
            cout<<"\n\n\n\n\t\t\t\t  [CUSTOMER]";
            cout<<"\n\t\t\t\t  __________";
        }
        while(f>>userid1>>pass1>>name1>>gmail1>>dob1>>ph1>>gender1)
        {
            if(uid==userid1)
            {
                cout<<"\n\n\t\t\t\tFULL NAME      :  "<<name1;
                cout<<"\n\n\t\t\t\tUSERID         :  "<<userid1;
                cout<<"\n\n\t\t\t\tPASSWORD       :  "<<pass1;
                cout<<"\n\n\t\t\t\tEMAIL ID       :  "<<gmail1;
                cout<<"\n\n\t\t\t\tMOBILE NUMBER  :  "<<ph1;
                cout<<"\n\n\t\t\t\tDATE OF BIRTH  :  "<<dob1;
                cout<<"\n\n\t\t\t\tGENDER         :  "<<gender1;
                break;
            }
        }
        f.close();
        cout<<"\n\n\n\t\t\t\tENTER {U} FOR UPDATE PROFILE | {C} FOR CONTINUE  .... ";
        cin>>ch;
        if(ch=='c' || ch=='C')
        {
            system("cls");
            food();
        }
        else if(ch=='u' || ch=='U')
        {
            system("cls");
            updateprofile();
        }
    }
    void updateprofile()
    {
        ifstream f1;
        int op;
        if(option==1)
        {
            f1.open("manager.txt");
        }
        else if(option==2)
        {
            f1.open("customer.txt");
        }
        ofstream f("temp.txt",ios::app);
        while(f1>>userid1>>pass1>>name1>>gmail1>>dob1>>ph1>>gender1)
        {
            if(uid==userid1)
            {
                retry:
                cout<<endl<<endl;
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
                cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                cout<<"\n\n\t\t\t\t1) FULL NAME \n\n\t\t\t\t2) PASSWORD \n\n\t\t\t\t3) GENDER \n\n\t\t\t\t4) PHONE NUMBER \n\n\t\t\t\t5) EMAIL \n\n\t\t\t\t6) DATE OF BIRTH\n";
                cout<<"\n\n\t\t\t\tENTER THE OPTION WHICH YOU WANT TO UPDATE : ";
                cin>>op;
                string temp;
                system("cls");
                if(op==1)
                {
                    cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                    cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\t\t\t\tENTER FULLNAME [without spaces] : ";
                    cin.get();
                    getline(cin,temp);
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<temp<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<gender1<<endl;
                }
                else if(op==2)
                {
                    usps:
                    cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                    cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\n\n\t\t\t\tNOTE : [USERID AND PASSWORD CAN'T BE SAME....]\n";
                    cout<<"\n\n\n\t\t\t\tENTER YOUR NEW PASSWORD : ";
                    cin>>temp;
                    if(uid==temp)
                    {
                        goto usps;
                    }
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<temp<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<gender1<<endl;
                }
                else if(op==3)
                {
                    cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                    cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\t\t\t\tENTER GENDER [Male/Female] : ";
                    cin>>temp;
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<temp<<endl;
                }
                else if(op==4)
                {
                    phch:
                        cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                        cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\t\t\t\tENTER NEW PHONE NUMBER [+91] : ";
                    cin>>temp;
                    try
                    {
                        if(temp.length()!=10)
                        {
                            throw(temp);
                        }
                    }
                    catch(...)
                    {
                        system("cls");
                        cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER 10 DIGIT NUMBER....\n";
                        goto phch;
                    }
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<temp<<' '<<left<<setw(10)<<gender1<<endl;
                }
                else if(op==5)
                {
                    emch:
                        cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                        cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\t\t\t\tENTER NEW EMAIL ID : ";
                    cin>>temp;
                    regex email_pattern("(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+.[a-zA-Z0-9-.]+$)");
                    try
                    {
                        if (!regex_match(temp, email_pattern))
                        {
                            throw(temp);
                        }
                    }
                    catch(...)
                    {
                        system("cls");
                        cerr << "\n\n\t\t\t\tERROR : PLEASE ENTER A VALID EMAIL ID...\n";
                        goto emch;
                    }
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<temp<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<gender1<<endl;
                }
                else if(op==6)
                {
                    dobch:
                        cout<<"\n\n\t\t\t\t\t\t\t*** UPDATE PROFILE ***";
                        cout<<"\n\t\t\t\t\t\t\t   ________________   "<<endl<<endl;
                    cout<<"\n\n\n\t\t\t\tENTER NEW DOB (DD/MM/YY) : ";
                    cin>>temp;
                    try
                    {
                        if(temp[2]!='/' && temp[5]!='/'&& (temp.length()!=10))
                        {
                            throw(temp);
                        }
                    }
                    catch(...)
                    {
                        system("cls");
                        cout<<"\n\n\t\t\t\tERROR : PLEASE ENTER DOB AS THIS FORMAT[DD/MM/YY]....\n";
                        goto dobch;
                    }
                    f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<temp<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<gender1<<endl;
                }
                else
                {
                    system("cls");
                    cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT UPDATE OPTION ...";
                    goto retry;
                }
            }
            else
            {
                f<<left<<setw(25)<<userid1<<' '<<left<<setw(25)<<pass1<<' '<<left<<setw(30)<<name1<<' '<<left<<setw(35)<<gmail1<<' '<<left<<setw(15)<<dob1<<' '<<left<<setw(15)<<ph1<<' '<<left<<setw(10)<<gender1<<endl;
            }
        }
        f1.close();
        f.close();
        if(option==1)
        {
            remove("manager.txt");
            rename("temp.txt","manager.txt");
        }
        else if(option==2)
        {
            remove("customer.txt");
            rename("temp.txt","customer.txt");
        }
        cout<<"\n\n\n\t\t\t\t\t\t ***** PROFILE UPDATED SUCCESSFULLY *****\n\n\n";
        cout<<"\n\n\t\t\t\tDO YOU WANT TO UPDATE MORE DETAILS (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            updateprofile();
        }
        else
        {
            system("cls");
            profile();
        }
    }
    void viewcart()
    {
        string ouser=uid+".txt";
        ifstream f(ouser);
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t***** CART ITEMS *****";
        cout<<"\n\t\t\t\t\t\t\t______________________\n\n";
        int i=1;
        if(f.peek()==EOF)
        {
            cerr<<"\n\n\t\t\t\t\t\tNO ITEMS AVAILABLE IN THE CART.PLEASE TRY TO ADD ITEMS\n";
            cout<<"\n\n\t\t\t\tENTER [C] TO CONTINUE ....";
            cin>>ch;
            if(ch=='c' || ch=='C')
            {
                system("cls");
                food();
            }
            else
            {
                system("cls");
                viewcart();
            }
        }
        else
        {
            retry:
            while(f>>fid1>>fn1>>ft1>>quan>>fp1>>fdis1>>tp)
            {
                cout<<"\t\t\t"<<i<<')'<<endl;
                cout<<"\n\t\t\t\tFOOD ID          :  "<<fid1;
                cout<<"\n\t\t\t\tFOOD NAME        :  "<<fn1;
                cout<<"\n\t\t\t\tFOOD TYPE        :  "<<ft1;
                cout<<"\n\t\t\t\tORIGINAL PRICE   :  "<<fp1;
                cout<<"\n\t\t\t\tFOOD DISCOUNT    :  "<<fdis1;
                cout<<"\n\t\t\t\tFOOD QUANTITY    :  "<<quan;
                cout<<"\n\t\t\t\tTOTAL PRICE      :  "<<tp;
                cout<<endl<<endl;
                i++;
            }
            f.close();
            cout<<"\n\t\t\t\tENTER  {P} FOR PAYMENT | {C} FOR CONTINUE  .... ";
            cin>>ch;
            if(ch=='p' || ch=='P')
            {
                system("cls");
                payment();
            }
            else if(ch=='c' || ch=='C')
            {
                system("cls");
                food();
            }
            else
            {
                system("cls");
                cerr<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT FOOD ID THAT YOU WANT TO UPDATE...";
                goto retry;
            }
        }
    }
    int displayordersummary(string ouser,float sum)
    {
        ifstream f(ouser.c_str());
        cout << "\n\n\n\t\t\t\t | ORDER SUMMARY |";
        cout << "\n\t\t\t\t _________________\n";
        cout << "\t\t\t\t-----------------------------------------------------------------------------------------" << endl;
        cout << "\t\t\t\t|" << left << setw(8) << "ID" << "|" << "  " << left << setw(17) << "Name" << "|" << "  " << left << setw(11) << "Type" << "|" << "  "
             << left << setw(9) << "Quantity" << "|" << "  " << left << setw(8) << "Price" << "|" << "  " << left << setw(8) << "Discount" << "|" << "  " << left << setw(8) << "Total" << "|" << endl;
        cout << "\t\t\t\t-----------------------------------------------------------------------------------------" << endl;
        while (f >> fid >> fn >> ft >> quan >> fp >> fdis >> tp)
        {
            cout << "\t\t\t\t|" << setw(8) << fid << "|";
            cout << setw(19) << fn << "|";
            cout << setw(13) << ft << "|";
            cout << setw(11) << quan << "|";
            cout << setw(10) << fp << "|";
            cout << setw(10) << fdis << "|";
            cout << setw(10) << tp << "|" <<endl;
            cout <<"\t\t\t\t-----------------------------------------------------------------------------------------" << endl;
        }
        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTOTAL PRICE : "<<sum;
        f.close();
        cout<<"\n\n\n\t\t\t\tDO YOU WANT TO CHECKOUT THE ITEMS (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            return 1;
        }
        else
        {
            system("cls");
            viewcart();
            return -1;
        }
    }
    void payment()
    {
        string mno,address;
        string ouser=uid+".txt";
        ifstream f(ouser);
        float sum=0.0;
        string fname,ft;
        int fid,quan,fd;
        while(f>>fid1>>fn1>>ft1>>quan>>fp1>>fdis1>>tp)
        {
            sum+=tp;
        }
        f.close();
        ch:
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\n\t\t\t\t | PAYMENT PAGE |";
        cout<<"\n\t\t\t\t ________________\n";
        cout<<"\n\t\t\t\tENTER YOUR MOBILE NUMBER   : ";
        cin>>mno;
        char choice;
        if(mno==::phno)
        {
            int res=displayordersummary(ouser.c_str(),sum);
            if(res==1)
            {
                system("cls");
                cout<<"\n\n\n\n\t\t\t\tENTER YOUR DEIVERY ADDRESS : ";
                cin.ignore();
                getline(cin,address);
                retry:
                cout << "\n\n\n\t\t\t\tCHOOSE ANY OF THE PAYMENT METHOD : "<<endl;
                cout << "\n\n\t\t\t\t1) CREDI/DEBIT CARD";
                cout << "\n\n\t\t\t\t2) NET BANKING";
                cout << "\n\n\t\t\t\t3) DIGITAL WALLET";
                cout << "\n\n\n\t\t\t\tENTER YOUR CHOICE : ";
                int pc;
                cin >> pc;
                system("cls");
                switch (pc)
                {
                    case 1:
                        cout<<"\n\n\t\t\t\tPROCESSING PAYMENT THROUGH CREDIT/DEBIT CARD...\n";
                        break;
                    case 2:
                        cout<<"\n\n\t\t\t\tPROCESSING PAYMENT THROUGH NET BANKING...\n";
                        break;
                    case 3:
                        cout<<"\n\n\t\t\t\tPROCESSING PAYMENT THROUGH DIGITAL WALLET...\n";
                        break;
                    default:
                        system("cls");
                        cerr<<"\n\n\t\t\t\tERROR : INVALID PAYMENT OPTION . PLEASE SELECT THE CORRECT PAYMENT OPTION...\n";
                        goto retry;
                }
                cout<<"\n\n\t\t\t\tYOUR ORDERS IS ON THE WAY TO THIS ADDRESS : "<<address<<endl;
                cout << "\n\n\n\t\t\t\t | PAYMENT RECEIPT |";
                cout << "\n\t\t\t\t ___________________\n";
                cout << "\n\t\t\t\t_________________________________________________________________________________________________"<<endl;
                cout << "\n\t\t\t\t  USER ID : " << uid;
                cout << "\n\n\t\t\t\t  AMOUNT : Rs." << sum;
                cout << "\n\n\t\t\t\t  DELIVERY ADDRESS : " << address;
                cout << "\n\t\t\t\t_________________________________________________________________________________________________";
                ofstream f1("order.txt",ios::app);
                time_t now=time(0);
                tm *ltm=localtime(&now);
                f1<<left<<setw(25)<<uid<<' '<<left<<setw(20)<<sum<<"    ";
                f1<<1900+ltm->tm_year<<"-"<<1+ltm->tm_mon<<"-"<<ltm->tm_mday<<"    ";
                f1<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"    "<<endl;
                remove(ouser.c_str());
                f1.close();
                cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n";
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   | ..THANK YOU.. | ";
                cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n\n";
                cout<<"\n\n\n\t\t\t\tENTER [C] TO CONTINUE ....";
                cin>>choice;
                if(choice=='c' || choice=='C')
                {
                    system("cls");
                    food();
                }
                else
                {
                    goto retry;
                }
            }
        }
        else
        {
            system("cls");
            cerr<<"\n\t\t\t\tERROR : PLEASE ENTER YOUR CORRECT REGISTERED MOBILE NUMBER... ";
            goto ch;
        }
    }
    void addtocart()
    {
        string ouser=uid+".txt";
        float disp,opr;
        ifstream f("foodlist.txt");
        ofstream f1(ouser,ios::app);
retry:
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t*** ADD TO CART LIST ***";
        cout<<"\n\t\t\t\t\t\t\t________________________\n\n";
        cout<<"\n\t\t\t\tENTER THE ID OF THE FOOD THAT YOU WANT TO ORDER : ";
        cin>>fid;
        int c=0;
        while(f>>fid1>>fn1>>ft1>>fp1>>fdis1)
        {
            if(fid==fid1)
            {
                c=1;
                cout<<"\n\t\t\t\tFOOD DETAILS...\n";
                cout<<"\n\t\t\t\tFOOD NAME       :  "<<fn1;
                cout<<"\n\t\t\t\tFOOD TYPE       :  "<<ft1;
                cout<<"\n\t\t\t\tORIGINAL PRICE  :  "<<fp1;
                cout<<"\n\t\t\t\tDISCOUNT[%]     :  "<<fdis1;
                cout<<"\n\n\t\t\t\tENTER THE QUANTITY : ";
                cin>>quan;
                disp=(fdis1/100)*fp1;
                opr=fp1-disp;
                tp=opr*quan;
                cout<<"\n\t\t\t\tAFTER APPLYING DISCOUNT FOR ["<<quan<<"] ITEMS TOTAL PRICE : "<<tp<<endl;
                cout<<"\n\t\t\t\tDO YOU WANT TO ADD THIS ITEM TO YOUR CART [Y/N] : ";
                cin>>ch;
                if(ch=='Y' || ch=='y')
                {
                    f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<quan<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<' '<<left<<setw(10)<<tp<<endl;
                    cout<<"\n\n\t\t\t\t\t\t\t**** ITEM ADDED TO CART SUCCESFULLY ****"<<endl;
                }
                else
                {
                    system("cls");
                    food();
                    break;
                }
                f1.close();
                break;
            }
        }
        f.close();
        if(c==0)
        {
            system("cls");
            cerr<<"\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT ID OF THE FOOD THAT YOU WANT TO ADD TO CART...\n";
            goto retry;
        }
        cout<<"\n\t\t\t\tDO YOU WANT TO ADD MORE ITEMS TO CART (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            addtocart();
        }
        else
        {
            system("cls");
            food();
        }
    }
    void delcart()
    {
        string ouser=uid+".txt";
        float fp,tp;
retry:
        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tUSER ID : "<<uid<<endl<<endl;
        cout<<"\n\n\t\t\t\t\t\t\t*** DELETE FROM CART LIST ***";
        cout<<"\n\t\t\t\t\t\t\t_____________________________\n\n";
        cout<<"\n\t\t\t\tENTER THE ID OF THE FOOD THAT YOU WANT TO REMOVE FROM YOUR CART : ";
        cin>>fid;
        ifstream f(ouser);
        ofstream f1("temp1.txt",ios::app);
        int c=0;
        while(f>>fid1>>fn1>>ft1>>quan>>fp1>>fdis1>>tp)
        {
            if(fid==fid1)
            {
                c=1;
                continue;
            }
            else
            {
                f1<<left<<setw(10)<<fid1<<' '<<left<<setw(20)<<fn1<<' '<<left<<setw(15)<<ft1<<' '<<left<<setw(10)<<quan<<' '<<left<<setw(10)<<fp1<<' '<<left<<setw(10)<<fdis1<<' '<<left<<setw(10)<<tp<<endl;
            }
        }
        f.close();
        f1.close();
        if(c==0)
        {
            system("cls");
            cerr<<"\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT ID OF THE FOOD THAT YOU WANT TO DELETE FROM CART...\n";
            goto retry;
        }
        remove(ouser.c_str());
        rename("temp1.txt",ouser.c_str());
        cout<<"\n\n\n\t\t\t\t\t\t *****ITEM REMOVED FROM THE CART SUCCESSFULLY*****\n\n\n";
        cout<<"\n\t\t\t\tDO YOU WANT TO DELETE MORE ITEMS IN THE CART (Y/N) : ";
        cin>>ch;
        if(ch=='y' || ch=='Y')
        {
            system("cls");
            delcart();
        }
        else
        {
            system("cls");
            food();
        }
    }
};

class SpecialMenu:public MenuItem
{
protected:
    string chefspecial;
    string seasonaldish;
    float pricecs,pricesd,tp;
    int dispricecs,dispricesd;
public:
    SpecialMenu(string cs,float pc,int dpc,string s,float ps,int dsd)
    {
        chefspecial=cs;
        pricecs=pc;
        dispricecs=dpc;
        seasonaldish=s;
        pricesd=ps;
        dispricesd=dsd;
    }
    friend void calculatediscount(SpecialMenu &sp);
    friend ostream& operator<<(ostream& os, const SpecialMenu& sp);
    ~SpecialMenu() {}
    void ratingfeedback()
    {
        int c=0;
        retry:
        cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t*** RATING PAGE ***";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t___________________";
        cout<<"\n\n\n\t\t\t\tNOTE : PLEASE RATE OUR SERVICE AND PROVIDE YOUR FEEDBACK....."<<endl;
        cout<<"\n\n\t\t\t\tENTER YOUR USER ID        : ";
        cin>>userid;
        cout<<"\n\t\t\t\tENTER YOUR EMAIL ID       : ";
        cin>>gmail;
        cout<<"\n\t\t\t\tENTER YOUR PHONE NUMBER   : ";
        cin>>ph;
        ifstream f1("customer.txt");
        while(f1>>userid1>>pass1>>name1>>gmail1>>dob1>>ph1>>gender1)
        {
            if(userid==userid1 && gmail==gmail1 && ph==ph1)
            {
                c=1;
                retry1:
                cout<<"\n\t\t\t\tENTER RATING ( out of 5 ) : ";
                cin>>rating;
                if(rating>5.0)
                {
                    system("cls");
                    cout<<"\n\t\t\t\tERROR : PLEASE PROVIDE RATING FOR OUT OF 5 ";
                    goto retry1;
                }
                cout<<"\n\t\t\t\tPROVIDE FEEDBACK TO US    : ";
                cin.ignore();
                getline(cin,sf);
                ofstream f("ratingfeedback.txt",ios::app);
                {
                    f<<left<<setw(25)<<userid<<left<<setw(30)<<gmail<<left<<setw(15)<<ph<<left<<setw(10)<<rating<<endl;
                    f<<sf<<endl;
                    if(rating<2.5)
                    {
                        cout<<"\n\n\n\t\t\t\tSORRY FOR THE INCONVINENCE THAT YOU FACE . WE TRY TO RECTIFY IT ...."<<endl<<endl;
                    }
                }
                cout<<"\n\t\t\t\t\t\t\t\t\t\t    THANK YOU FOR PROVIDE YOUR RATING AND FEEDBACK ";
                f.close();
                break;
            }
        }
        f1.close();
        if(c==0)
        {
            system("cls");
            cout<<"\n\n\t\t\t\tERROR : PLEASE ENTER THE CORRECT DETAILS...\n";
            goto retry;
        }
        else
        {
            ret:
            cout<<"\n\n\n\n\n\n\t\t\t\tENTER [C] TO CONTINUE ....";
            cin>>ch;
            if(ch=='c' || ch=='C')
            {
                return;
            }
            else
            {
                goto ret;
            }
        }
    }
    void display() override
    {
        cout<<"\n\n\n\t\t\t\tSPECIAL DISHES LIST"<<endl;
        cout<<"\t\t\t\t-------------------"<<endl<<endl;
        cout<<"\t\t\t\tSEASONAL DISH           : "<<seasonaldish<<endl;
        cout<<"\t\t\t\tSEASONAL DISH PRICE     : "<<pricesd<<endl;
        cout<<"\t\t\t\tSEASONAL DISH DISCOUNT  : "<<dispricesd<<endl;
        cout<<"\t\t\t\tCHEF'S SPECIAL          : "<<chefspecial<<endl;
        cout<<"\t\t\t\tCHEF'S SPECIAL PRICE    : "<<pricecs<<endl;
        cout<<"\t\t\t\tCHEF'S SPECIAL DISCOUNT : "<<dispricecs<<endl;
    }
    int displaybranch()
    {
        string a,d;
        int s;
        char ch;
        vector<string> area;
        vector<string> district;
        vector<int> sno;
        ifstream f(dis.c_str());
        while(f>>s>>a>>d)
        {
            sno.push_back(s);
            area.push_back(a);
            district.push_back(d);
        }
        int si=sno.size();
        cout<<"\n\n\n\t\t\t\tOUR OTHER BRANCHES LIST - DISTRICT WISE....";
        cout<<"\n\t\t\t\t---------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t| S.NO\t|\tAREA\t\t|\tDISTRICT\t|";
        cout<<"\n\t\t\t\t---------------------------------------------------------"<<endl;
        for(int i=0;i<si;i++)
        {
            cout << "\t\t\t\t| " << sno[i] << "\t|\t";
            cout << area[i] << "\t|\t";
            cout << left<<setw(16) << district[i] << "|" ;
            cout <<"\n\t\t\t\t---------------------------------------------------------"<<endl;
        }
        cout<<"\n\t\t\t\tPRESS [x] TO CLOSE THE ADVERTISEMENT : ";
        cin>>ch;
        if(ch=='x' || ch=='X')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

ostream& operator<<(ostream& os,const SpecialMenu& sp)
{
    os << "\t\t\t\t\t     -------";
    os << "\n\t\t\t\tTOTAL PRICE : " << sp.tp;
    os << "\n\t\t\t\t\t     -------";
    os << "\n\t\t\t\tYOU HAVE RECEIVED COUPON FOR THE ABOVE SPECIAL ITEMS.[PLEASE VISIT NEARBY BRANCH TO GET THE COUPON]";
    return os;
}

void calculatediscount(SpecialMenu &sp)
{
    float cstemp=sp.pricecs*(sp.dispricecs/100);
    float sdtemp=sp.pricesd*(sp.dispricesd/100);
    sp.tp=(sp.pricecs-cstemp)+(sp.pricesd-sdtemp);
}

int main()
{
    MenuItem mn;
    mn.mainmenu();
    SpecialMenu sm("LOBSTER",1000,10,"BARBEQUE",2000,20);
    calculatediscount(sm);
    MenuItem *m;
    m=&sm;
    if(cop==2)
    {
        system("cls");
        sm.ratingfeedback();
        retry:
        system("cls");
        m->display();
        cout<<sm;
        int res=sm.displaybranch();
        if(res==0)
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   | ..THANK YOU.. | ";
            cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n\n"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\n\n\n\n";;
        }
        else
        {
            system("cls");
            goto retry;
        }
    }
    else
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   | ..THANK YOU.. | ";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t   _________________ \n\n"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\n\n\n\n";;
    }
    return 0;
}
