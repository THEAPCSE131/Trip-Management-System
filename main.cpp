#include <mysql.h>
#include <iostream>
#include <istream>
#include<sstream>
#include <stdlib.h>
#include <string>
#include<ctime>
using namespace std;



int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

void title();
void lastpage();
void time();
void sqlconn();
int main();

class trip
{
public:
    void UCreTrip();
    void ChekTripD(string userid);
    void TripExp();
};




class admin : public trip
{
public:

    //void adminhomepage();
    //void adminloginpage();
    //void adminlogin();
    //void adminforgot();

    void adminhomepage()
    {
        system("cls");
        int ch;
        title();
        cout << "\t\t\t|                        WELCOME TO ADMIN                        |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout<<"\t\t\t1.Find Name Of All Users"<<endl;
        cout<<"\t\t\t2.Find Trip Details For All Users."<<endl;
        cout<<"\t\t\t3.Find Trip Expense Details For All Users."<<endl;
        cout<<"\t\t\t4.Find Total Amount Spend By All Users On Trip."<<endl;
        cout<<"\t\t\t5.Find Out Number Of Times Each User Has Travelled Till Date."<<endl;
        cout<<"\t\t\t6.Find The Total Amount Spent By All Usersfor Expense Category “Food”."<<endl;
        cin>>ch;

        switch(ch)
            {
            case 1:
                {
                    FUname();
                    break;
                }
            case 2:
                {
                    FUTdetails();
                    break;
                }
            case 3:
                {
                    FUTEdetails();
                    break;
                }
            case 4:
                {
                    FUTTCost();
                    break;
                }
            case 5:
                {
                    FUTNall();
                    break;
                }
                case 6:
                    {
                       FUTEFood();
                       break;
                    }


            }


    }
    void FUname()
    {
        system("cls");
        title();
        sqlconn();
        int i=1;
        string query = "SELECT * FROM trip";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tNAME OF ALL USERS:"<<endl<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout<<"\t\t\t"<<i<<")"<<row[2]<<endl;
                i++;
            }
        }

            cin.get();
            cin.get();
            adminhomepage();
    }

    void FUTdetails()
    {
        system("cls");
        title();
        sqlconn();
        int i=1;
        string query = "SELECT * FROM trip";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tTRIP DETAILS OF ALL USERS:"<<endl<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                    cout << endl;
                    cout <<"\t\t\t"<<i<<")"<< endl;
                    cout << "\t\t\t TRIP ID: " << row[0] <<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t USERID: " << row[1]<<"                                           " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t FULL NAME: " << row[2]<<"                                        " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t CITY: " << row[3]<<"                                             " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t NUMBER OF PERSON: " << row[4]<<"                                 " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t START DATE: " << row[5]<<"                                       " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t END DATE: " << row[6]<<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t TOTAL COST: " << row[7]<<"                                       " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\t******************************************************************" << endl;
                    i++;
            }
        }
            cin.get();
            cin.get();
            adminhomepage();
    }

    void FUTEdetails()
    {
                system("cls");
        title();
        sqlconn();
        int i=1;
        string query = "SELECT * FROM tripexp";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tTRIP EXPANCE DETAILS OF ALL USERS:"<<endl<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                    cout << endl;
                    cout <<"\t\t\t"<<i<<")"<< endl;
                    cout << "\t\t\t TRIP EXP ID: " << row[0] <<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t USERID: " << row[1]<<"                                           " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t FULL NAME: " << row[2]<<"                                        " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t TRIP ID: " << row[3]<<"                                          " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t CITY: " << row[4]<<"                                             " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE NAME: " << row[5]<<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE CAT: " << row[6]<<"                                      " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE COST: " << row[7]<<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t NUMBER OF PERSONS: " << row[8]<<"                                " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE TOTAL COST: " << row[9]<<"                               " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\t******************************************************************" << endl;
                    i++;
            }
        }
            cin.get();
            cin.get();
            adminhomepage();
    }

    void FUTTCost()
    {

        system("cls");
        title();
        sqlconn();
        int i=1;
        string query = "SELECT SUM(TRIPCOST) FROM TRIP";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tTOTAL COST SPEND BY ALL USERS ON TRIP:"<<endl<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout<<row[0];
            }
        }

            cin.get();
            cin.get();
            adminhomepage();

    }

    void FUTNall()
    {
        system("cls");
        title();
        sqlconn();
        int i=1;
        string query = "SELECT Full_name,count(*) AS TOTAL FROM trip group by Full_name";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tTOTAL NUMBER OF TIMES EACH USER HAS TRAVELLED TILL DATE:"<<endl<<endl;
        cout<<"\t\t\t NAME"<<"\t\t\t NUMBER"<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout<<"\t\t\t "<<row[0]<<"\t\t\t "<<row[1]<<endl;
            }
        }

            cin.get();
            cin.get();
            adminhomepage();
    }

    void FUTEFood()
    {
        system("cls");
        title();
        sqlconn();
        string query = "select sum(E_Tcost) from tripexp where (E_cat='food')";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        cout<<"\t\t\tTOTAL COST SPENT BY ALL USERS ON EXPANCE CATEGORY FOOD:"<<endl<<endl;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                cout<<"\t\t\t"<<row[0]<<endl;
            }
        }

            cin.get();
            cin.get();
            adminhomepage();
    }



    void adminloginpage()
    {
        system("cls");
        title();
        int choice;
        cout << "\t\t\t|                          LOGIN PAGE                            |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        cout << "\t\t\t----------------------------------------------------------------- " << endl;
        cout << "\t\t\t|  1. LOGIN                                                      |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  2. FORGOT USERNAME (or) PASSWORD                              |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  3. EXIT                                                       |" << endl;
        cout << "\t\t\t------------------------------------------------------------------\n" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> choice;


        switch (choice)
        {
        case 1:
        {
            adminlogin();
            break;
        }
        case 2:
        {
            adminforgot();
            break;
        }
        case 3:
        {
            lastpage();
            break;
        }
        default:
        {
            system("cls");
            title();
            cout << "\t\t\tYou've made a mistake , give it a try again\n"<< endl;
            adminloginpage();
        }
        }
    }

    void adminlogin()
    {
        system("cls");
        int count = 0;
        string userid, pass;
        sqlconn();
        title();
        cout << "\t\t\tPLEASE ENTER THE FOLLOWING DETAILS" << endl;
        cout << "\t\t\tUSERNAME :";
        cin >> userid;
        cout << "\t\t\tPASSWORD :";
        cin >> pass;

        string query = "SELECT * FROM admin";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                if (userid == row[0] && pass == row[1])
                {
                    count = 1;
                    system("cls");
                }
            }
        }


        if (count == 1)
        {
            system("cls");
            title();
            cout << "\n\t\t\tHELLO " << userid << "\n\t\t\tLOGIN SUCESS\n\t\t\tWe are glad that YOU HERE\n\t\t\t THANKS FOR LOGIN\n\t\t\tPRESS ENTER TO CONTINUE";
            cin.get();
            cin.get();
            adminhomepage();
        }

        else
        {
            system("cls");
            title();
            cout << "\t\t\tLogin ERROR\n\t\t\tPlease cheCK YOUR USERNAME AND PASSWORD\n\t\t\tPRESS ENTER TO CONTINUE.....";
            cin.get();
            cin.get();
            adminforgot();
        }

    }

    void adminforgot()
    {
        system("cls");
        title();
        int ch;
        cout << "\t\t\t|                   FORGOT USERNAME (or) PASSWORD                |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        cout << "\t\t\t----------------------------------------------------------------- " << endl;
        cout << "\t\t\t|  FORGOTTEN ?we'RE HERE FOR HELP......                           " << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  1. SEARCH YOUR ID BY USERNAME                                 |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  2. SEARCH YOUR ID BY PASSWORD                                 |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  3. EXIT                                                       |" << endl;
        cout << "\t\t\t------------------------------------------------------------------\n" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> ch;
        switch (ch)
        {

        case 1:
        {
            system("cls");
            int count = 0;
            string userid;
            sqlconn();
            title();
            cout << "\n\t\t\tENTER YOUR REMEBERED USERNAME";
            cin >> userid;

            string query = "SELECT * FROM admin";

            const char* q = query.c_str();
            qstate = mysql_query(conn, q);

            string pass;
            if (!qstate)
            {
                res = mysql_store_result(conn);

                while (row = mysql_fetch_row(res))
                {
                    if (userid == row[0])
                    {
                        pass = row[1];
                        count = 1;
                        system("cls");
                    }
                }
            }
            if (count == 1)
            {
                system("cls");
                title();
                cout << "\n\n\t\t\tHURRY,ACCOUNT FOUND\n";
                cout << "\n\t\t\tYOUR PASSWORD IS :" << pass << endl;
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                adminloginpage();
            }
            else
            {
                system("cls");
                title();
                cout << "\n\t\t\tSORRY YOUR USERID IS NOT FOUND IN OUR DATABASE\n";
                cout << "\n\t\t\tKINDLY CONTACT YOUR SYSTEM ADMINISTRATOR FOR MORE DETAIL\n";
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                adminloginpage();
            }
            break;
        }

        case 2:
        {
            system("cls");
            int count = 0;
            string userid, pass;
            sqlconn();
            title();
            cout << "\n\t\t\tENTER YOUR REMEBERED PASSWORD:";
            cin >> pass;

            string query = "SELECT * FROM admin";

            const char* q = query.c_str();
            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                res = mysql_store_result(conn);

                while (row = mysql_fetch_row(res))
                {
                    if (pass == row[1])
                    {
                        userid = row[0];
                        count = 1;
                        system("cls");
                    }
                }
            }
            if (count == 1)
            {
                system("cls");
                title();
                cout << "\n\n\t\t\tHURRY,ACCOUNT FOUND\n";
                cout << "\n\t\t\tYOUR USERID IS :" << userid<< endl;
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                adminloginpage();
            }
            else
            {
                system("cls");
                title();
                cout << "\n\t\t\tSORRY YOUR USERID IS NOT FOUND IN OUR DATABASE\n";
                cout << "\n\t\t\tKINDLY CONTACT YOUR SYSTEM ADMINISTRATOR FOR MORE DETAIL\n";
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                lastpage();
            }
            break;
        }
        case 3:
        {
            lastpage();
            break;
        }
        default:
        {
            cout << "\t\t\tSORRY::YOU ENTERED WRONG CHOICE!!!\n\t\t\tKINDLEY TRY AGAIN";
            adminforgot();
            break;
        }
        }
    }

};

class user : public trip
{

public:

    //void userhomepage();
    //void userloginpage();
    //void userregister();
    //void userlogin();
    //void userforgot();
    //void userdetails();

    void userhomepage(string userid)
    {
        system("cls");
        int choice;
        title();
        cout << "\t\t\t|                            WELCOME                             |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout<<endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 1. ACCOUNT DETAILS                                             |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 2. CREATE TRIP                                                 |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 3. CHECK TRIP DETAILS                                          |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 4. ADD TRIP EXPANSE                                                |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 5. CHECK TRIP EXPANSE DETAILS                                      |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 6. EXIT                                                        |" << endl;
        cout << "\t\t\t------------------------------------------------------------------\n" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 1:
        {
            userdata(userid);
            break;
        }
        case 2:
        {
            UCreTrip(userid);
            break;
        }
        case 3:
        {
            ChekTripD(userid);
            break;
        }
        case 4:
            {
                TripExp(userid);
                break;
            }

        case 5:
        {
            TripExpdisplay(userid);
            break;
        }
        case 6:
            {
                lastpage();
                break;
            }
        default:
        {
            system("cls");
            cout << "\t\t\tYou've made a mistake , give it a try again\n" << endl;
            userhomepage(userid);
            break;
        }

        }
    }

    void userloginpage()
    {
        system("cls");
        title();
        int choice;
        cout << "\t\t\t|                           LOING PAGE                           |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 1. LOGIN                                                       |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 2. REGISTER                                                    |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 3..FORGOT USERNAME (or) PASSWORD                               |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t| 4. EXIT                                                        |" << endl;
        cout << "\t\t\t------------------------------------------------------------------\n" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            userlogin();
            break;
        }
        case 2:
        {
            userreg();
            break;
        }
        case 3:
        {
            userforgot();
            break;
        }
        case 4:
        {
            lastpage();
            break;
        }
        default:
        {
            system("cls");
            cout << "\t\t\tYou've made a mistake , give it a try again\n" << endl;
            userloginpage();
            break;
        }
        }
    }
    void userreg()
    {
        system("cls");
        title();
        sqlconn();
        cout << "\t\t\t|                         REGISTRATION                           |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        cout << "\t\t\tENTER THE FOLLOWING DETAILS" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        string userid, pass, Full_name,email, phno;
        cout << "\t\t\tENTER USERNAME:";
        cin >> userid;
        cout << "\n\t\t\tENTER PASSWORD:";
        cin >> pass;
        cout << "\n\t\t\tENTER FULL NAME:";
        cin.ignore(100, '\n');
        getline( cin, Full_name);
        cout << "\n\t\t\tENTER EMAIL ID:";
        cin >> email;
        cout << "\n\t\t\tENTER PHONE NUMBER:";
        cin >> phno;

        string su = "INSERT INTO user(userid,pass,Full_name,email,phno) VALUES('" + userid + "','" + pass + "','" + Full_name + "','" + email + "','" + phno + "')";

        const char* q = su.c_str();
        qstate = mysql_query(conn, q);

        if (qstate == 0)
        {
            system("cls");
            title();
            cout << "\t\t\tHELLO..!! " << Full_name << "\n\t\t\tREGISTRATION SUCESSFULL...!!" <<"\n\t\t\t PRESS ENTER TO CONTINUE...."<< endl;
            cin.get();
            cin.get();
            userloginpage();
        }
        else
        {
            cout << "\t\t\tERROR" << endl;
        }
    }

    void userdata(string userid)
    {

        system("cls");
        title();
        int count=0;

        string query = "SELECT * FROM user";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {

                if(userid==row[0])
                {
                    system("cls");
                    title();
                    cout << "\t\t\t|                       ACCOUNT DETAILS                          |" << endl;
                    cout << "\t\t\t******************************************************************" << endl;
                    cout << endl;
                    cout << "\t\t\t USER ID: " << row[0] <<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t PASSWORD: " << row[1]<<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t FULL NAME: " << row[2]<<"                                        " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EMAIL ID: " << row[3]<<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t PHONE NUMBER: " << row[4]<<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cin.get();
                    cin.get();
                    userhomepage(userid);
                }
                else
                {
                    cout<<"\t\t\tSORRY YOU HAVE ENTERD WRONG PASSWORD..TRY AGAIN";
                    cin.get();
                    cin.get();
                    userhomepage(userid);
                }

            }
        }

    }

    void userlogin()
    {
        system("cls");
        title();
        sqlconn();
        cout << "\t\t\t|                            LOGIN                               |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        int count = 0;
        string userid, pass;
        cout << "\t\t\tENTER THE FOLLOWING DETAILS" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\tUSERNAME :";
        cin >> userid;
        cout << "\n\t\t\tPASSWORD :";
        cin >> pass;

        string query = "SELECT * FROM user";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        string Full_name,userid1;
        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                userid1=row[0];
                Full_name = row[2];
                if (userid == row[0] && pass == row[1])
                {
                    count = 1;
                }
            }
        }

        if (count == 1)
        {
            system("cls");
            title();
            cout << "\n\t\t\tHELLO..!! " << Full_name << "\n\t\t\tLOGIN SUCESS\n\t\t\tWe are glad that YOU HERE\n\t\t\t THANKS FOR LOGIN\n\t\t\t PRESS ENTER TO CONTINUE";
            cin.get();
            cin.get();
            userhomepage(userid1);
        }
        else
        {
            system("cls");
            title();
            cout << "\t\t\tLogin ERROR\n\t\t\tPlease cheCK YOUR USERNAME AND PASSWORD\n\t\t\tPRESS ENTER TO CONTINUE.....";
            cin.get();
            cin.get();
            userforgot();
        }

    }

    void userforgot()
    {
        system("cls");
        title();
        int ch;
        cout << "\t\t\t|                 FORGOT USERNAME (or) PASSWORD                  |" << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << endl;
        cout << "\t\t\t----------------------------------------------------------------- " << endl;
        cout << "\t\t\t|  FORGOTTEN ?we'RE HERE FOR HELP......                           " << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  1. SEARCH YOUR ID BY USERNAME                                 |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  2. SEARCH YOUR ID BY PASSWORD                                 |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  3. EXIT                                                       |" << endl;
        cout << "\t\t\t------------------------------------------------------------------\n" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> ch;

        switch (ch)
        {

        case 1:
        {
            system("cls");
            int count = 0;
            string userid;
            sqlconn();
            title();
            cout << "\n\t\t\tENTER YOUR REMEBERED USERNAME:";
            cin >> userid;

            string query = "SELECT * FROM user";

            const char* q = query.c_str();
            qstate = mysql_query(conn, q);

            string pass;
            if (!qstate)
            {
                res = mysql_store_result(conn);

                while (row = mysql_fetch_row(res))
                {
                    if (userid == row[0])
                    {
                        pass = row[1];
                        count = 1;
                        system("cls");
                    }
                }
            }
            if (count == 1)
            {
                system("cls");
                title();
                cout << "\n\n\t\t\tHURRY,ACCOUNT FOUND\n";
                cout << "\n\t\t\tYOUR PASSWORD IS :" << pass << endl;
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                userloginpage();
            }
            else
            {
                system("cls");
                title();
                cout << "\n\t\t\tSORRY YOUR USERID IS NOT FOUND IN OUR DATABASE\n";
                cout << "\n\t\t\tKINDLY CONTACT YOUR SYSTEM ADMINISTRATOR FOR MORE DETAIL\n";
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                userloginpage();
            }
            break;
        }

        case 2:
        {
            system("cls");
            int count = 0;
            string userid, pass;
            sqlconn();
            title();
            cout << "\n\t\t\tENTER YOUR REMEBERED PASSWORD:";
            cin >> pass;

            string query = "SELECT * FROM user";

            const char* q = query.c_str();
            qstate = mysql_query(conn, q);

            if (!qstate)
            {
                res = mysql_store_result(conn);

                while (row = mysql_fetch_row(res))
                {
                    if (pass == row[1])
                    {
                        userid = row[0];
                        count = 1;
                        system("cls");
                    }
                }
            }
            if (count == 1)
            {
                system("cls");
                title();
                cout << "\n\n\t\t\tHURRY,ACCOUNT FOUND\n";
                cout << "\n\t\t\tYOUR USERID IS :" << userid << endl;
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                userloginpage();
            }
            else
            {
                system("cls");
                title();
                cout << "\n\t\t\tSORRY YOUR USERID IS NOT FOUND IN OUR DATABASE\n";
                cout << "\n\t\t\tKINDLY CONTACT YOUR SYSTEM ADMINISTRATOR FOR MORE DETAIL\n";
                cout << "\t\t\t******************************************************************" << endl;
                cin.get();
                cin.get();
                lastpage();
            }
            break;
        }
        case 3:
        {
            lastpage();
            break;
        }
        default:
        {
            cout << "\t\t\tSORRY::YOU ENTERED WRONG CHOICE!!!\n\t\t\tKINDLEY TRY AGAIN";
            userforgot();
            break;
        }
        }
    }

    void UCreTrip(string userid)
    {

        system("cls");
        title();
        sqlconn();
        string Tuserid,Full_name,TripCity,TripSdt,TripEdt,TripCost,TripPNum;
        long int temp,tcost;
        int choice,num;

        //----------------------------------------------------------------------------------------
        string query = "SELECT * FROM user";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);

            while (row = mysql_fetch_row(res))
            {
                if (userid == row[0])
                {
                    Full_name = row[2];
                }
            }
        }

        Tuserid=userid;
        //----------------------------------------------------------------------------------------
        t1:
        system("cls");
        title();
        cout<<endl;
        cout << "\t\t\t                     SELECT YOUR DESTINATION                      " << endl;
        cout << "\t\t\t******************************************************************" << endl;
        cout << "\n\t\t\t----------------------------------------------------------------- " << endl;
        cout << "\t\t\t|  1. TAJ MAHAL - AGRA                                           |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  2. STATUE OF UNITY - KEVADIA,GUJARAT                          |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  3. AJANTA & ELLORA CAVES - AURANGABAD,MAHARASHTRA             |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  4. LADAKH - KASHMIR                                           |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\t\t\t|  5. GOA BEACHES - GOA                                          |" << endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t******************************************************************" << endl;
        cout << "\t\t\tENTER YOUR CHOISE:";
        cin >> choice;

        //----------------------------------------------------------------------------------------
        switch(choice)
        {
        case 1:
        {
            string com;
            system("cls");
            title();
            cout << "\t\t\t                        TAJ MAHAL - AGRA                          " << endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\tAn immense mausoleum of white marble, built in Agra between 1631"
                 << "\n\t\t\tand 1648 by order of the Mughal emperor Shah Jahan in memory of"
                 << "\n\t\t\this favourite wife,the Taj Mahal is the jewel of Muslim art in"
                 << "\n\t\t\tIndia and one of the universally admired masterpieces of the"
                 << "\n\t\t\tworld's heritage."<<endl;
            cout<<"\n\t\t\tWEBSITE: "<<"https://www.tajmahal.gov.in/"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\t Places To Visit In TAJ MAHAL - AGRA"<<endl;
            cout<<"\n\t\t\t >Fatehpur Sikri"<<endl;
            cout<<"\t\t\t >Agra Fort"<<endl;
            cout<<"\t\t\t >Itimad-ud-daulah's Tomb"<<endl;
            cout<<"\t\t\t >Mehtab Bagh"<<endl;
            cout<<"\t\t\t >Shopping In Agra"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tDESTINATION: TAJ MAHAL - AGRA"<<endl;
            cout<<"\n\t\t\tCOST: 10,000RS(Per person)"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;

            cout<<"\t\t\tTYPE [YES] OR [yes] IF U AGREE... :";

            cin>>com;

            if(com=="yes" || com=="YES")
            {
                TripCity = "TAJ MAHAL-AGRA";
                temp=10000;
            }
            else
            {
                goto t1;
            }
            break;

        }

        case 2:
        {
            string com;
            system("cls");
            title();
            cout << "\t\t\t               STATUE OF UNITY - KEVADIA,GUJARAT                  " << endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\tWith the opening of the Statue of Unity, dedicated to the ‘Iron"
                 << "\n\t\t\tMan ofIndia’, Sardar Vallabhbhai Patel, India just made its entry"
                 <<"\n\t\t\tinto the club of the tallest statues in the world.Dedicated to one"
                 <<  "\n\t\t\tof India’s founding fathers,and the country’s first Deputy Prime"
                 <<"\n\t\t\tMinister, Sardar Vallabhbhai Patel,the Statue of Unity, stands tall"
                 <<"\n\t\t\ta top Sadhu Bet island on the Narmada facing the Sardar Sarovar Dam"
                 <<"\n\t\t\tdownstream in Kevadiya colony,"<<endl;
            cout<<"\n\t\t\tWEBSITE: "<<"https://statueofunity.in/"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\t Places To Visit In Statue Of Unity"<<endl;
            cout<<"\n\t\t\t >Sardar Sarovar Dam."<<endl;
            cout<<"\t\t\t >Valley of Flowers."<<endl;
            cout<<"\t\t\t >Jungle Safari Park"<<endl;
            cout<<"\t\t\t >Ninai Waterfalls"<<endl;
            cout<<"\t\t\t >Poicha"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tDESTINATION: STATUE OF UNITY - KEVADIA,GUJARA"<<endl;
            cout<<"\n\t\t\tCOST: 8000RS(Per person)"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;

            cout<<"\t\t\tTYPE [YES] OR [yes] IF U AGREE... :";
            cin>>com;

            if(com=="yes" || com=="YES")
            {
                TripCity = "STATUE OF UNITY-KEVADIA,GUJARA";
                temp=8000;
            }
            else
            {
                goto t1;
            }
            break;

        }


        case 3:
        {
            string com;
            system("cls");
            title();
            cout << "\t\t\t         AJANTA & ELLORA CAVES - AURANGABAD,MAHARASHTRA           " << endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\tAjanta and Ellora caves, considered to be one of the finest"
                 <<"\n\t\t\texamples of ancient rock-cut caves, are located near Aurangabad in"
                 <<"\n\t\t\tMaharashtra, India. Ajanta and Ellora caves complex is adorned with"
                 <<"\n\t\t\tbeautiful sculptures, paintings, and frescoes and include Buddhist"
                 <<"\n\t\t\tmonasteries, Hindu and Jain temples. The Ajanta caves are 29 in number"
                 <<"\n\t\t\tand were built between the 2nd century BC and 6th century AD, whereas"
                 <<"\n\t\t\tthe Ellora Caves are more spread out and 34 in number and dates to"
                 <<"\n\t\t\tthe period between 6th and 11th Century AD"<<endl;
            cout<<"\n\t\t\tWEBSITE: "<<"https://www.maharashtratourism.gov.in/treasures/caves"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\t Places To Visit In AJANTA & ELLORA CAVES - AURANGABAD,MAHARASHTRA"<<endl;
            cout<<"\n\t\t\t >Grishneshwar Temple, Ellora"<<endl;
            cout<<"\t\t\t >Bibi Ka Makbara, Aurangabad"<<endl;
            cout<<"\t\t\t >Jain Caves, Ellora"<<endl;
            cout<<"\t\t\t >Daulatabad Fort"<<endl;
            cout<<"\t\t\t >Aurangabad Caves"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tDESTINATION: AJANTA & ELLORA CAVES - AURANGABAD,MAHARASHTRA"<<endl;
            cout<<"\n\t\t\tCOST: 15,000RS(Per person)"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;

            cout<<"\t\t\tTYPE [YES] OR [yes] IF U AGREE... :";
            cin>>com;

            if(com=="yes" || com=="YES")
            {
                TripCity = "AJANTA & ELLORA CAVES-AURANGABAD,MAHARASHTRA";
                temp=15000;
            }
            else
            {
                goto t1;
            }
            break;

        }

        case 4:
        {
            string com;
            system("cls");
            title();
            cout << "\t\t\t                        LADAKH - KASHMIR                          " << endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\tLadakh, or La-dvags as it is known in Tibetan, is the ‘land of"
                 <<"\n\t\t\thigh passes’ and that has always been its biggest draw for tourists."
                 <<"\n\t\t\tA land known for its monasteries, its mountain peaks, its adventure"
                 <<"\n\t\t\tand thrills, it calls out to the adrenaline seeker within us, and"
                 <<"\n\t\t\tbecomes a destination that deserves a pilgrimage of sorts at least"
                 <<"\n\t\t\tonce in a lifetime. Come summer or winter, Ladakh tourism is a"
                 <<"\n\t\t\tmagnet all year round. Give heed to its untouched beauty and"
                 <<"\n\t\t\tfulfil your call to the pristine land with your visit to"
                 <<"\n\t\t\tthese majestic heights."<<endl;
            cout<<"\n\t\t\tWEBSITE: "<<"https://leh.nic.in/tourism/"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\t Places To Visit In LADAKH - KASHMIR"<<endl;
            cout<<"\n\t\t\t >Pangong Tso Lake"<<endl;
            cout<<"\t\t\t >Thiksey Monastery"<<endl;
            cout<<"\t\t\t >Khardung-la Pass"<<endl;
            cout<<"\t\t\t >Markha Valley"<<endl;
            cout<<"\t\t\t >Nubra Valley"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tDESTINATION: LADAKH - KASHMIR"<<endl;
            cout<<"\n\t\t\tCOST: 25,000RS(Per person)"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;

            cout<<"\t\t\tTYPE [YES] OR [yes] IF U AGREE... :";
            cin>>com;

            if(com=="yes" || com=="YES")
            {
                TripCity = "LADAKH-KASHMIR";
                temp=25000;
            }
            else
            {
                goto t1;
            }
            break;

        }

        case 5:
        {
            string com;
            system("cls");
            title();
            cout << "\t\t\t                       GOA BEACHES - GOA                          " << endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout << "\t\t\tA kaleidoscopic blend of Indian and Portuguese cultures,"
                 <<"\n\t\t\tsweetened with sun, sea, sand, seafood, susegad and spirituality,"
                 <<"\n\t\t\tGoa is India's pocket-sized paradise."<<endl;
            cout<<"\n\t\t\tWEBSITE: "<<"https://goa-tourism.com/"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\t Places To Visit In GOA BEACHES - GOA"<<endl;
            cout<<"\n\t\t\t >Panaji: A relaxed state capital!"<<endl;
            cout<<"\t\t\t >Margao: Cultural capital of Goa!"<<endl;
            cout<<"\t\t\t >Vasco da Gama"<<endl;
            cout<<"\t\t\t >Mapusa: Off to the Friday Bazaar!"<<endl;
            cout<<"\t\t\t >Calangute: A town with the Queen of Beaches!"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tDESTINATION: GOA BEACHES - GOA"<<endl;
            cout<<"\n\t\t\tCOST: 18,000RS(Per person)"<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;

            cout<<"\t\t\tTYPE [YES] OR [yes] IF U AGREE... :";
            cin>>com;

            if(com=="yes" || com=="YES")
            {
                TripCity = "GOA BEACHES-GOA";
                temp=18000;
            }
            else
            {
                goto t1;
            }
            break;

        }
        default:
        {
            cout<<"SORRY YOU ENTERED WORG CHOICE...";
            goto t1;
            break;
        }
        }
        //----------------------------------------------------------------------------------------

        system("cls");
        title();
        cout<<"\n\t\t\tENTER NUMMBER OF PERSON:";
        cin>>num;
        tcost=temp*num;

//        stringstream tc;
//        tc<<tcost;
//        tc>>TripCost;

        stringstream tn;
        tn<<num;
        tn>>TripPNum;


        cout<<"\n\t\t\tENTER START DATE:";
        cin>>TripSdt;

        cout<<"\n\t\t\tENTER END DATE:";
        cin>>TripEdt;
        //----------------------------------------------------------------------------------------
        system("cls");
        title();

        string done;
        cout<<"\n\t\t\tCHECK YOUR DETAILS!!!"<<endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout<<"\t\t\tUSERID:"<<Tuserid<<endl;
        cout<<"\n\t\t\tNAME:"<<Full_name<<endl;
        cout<<"\n\t\t\tCITY:"<<TripCity<<endl;
        cout<<"\n\t\t\tNUMBER OF PERSON:"<<TripPNum<<endl;
        cout<<"\n\t\t\tSTART DATE:"<<TripSdt<<endl;
        cout<<"\n\t\t\tEND DATE:"<<TripEdt<<endl;
        cout<<"\n\t\t\tTOTAL COST:"<< tcost<<endl;
        cout << "\t\t\t------------------------------------------------------------------" << endl;
        int mych;
        cout<<"\t\t\t1.PAYMENT:"<<endl;
        cout<<"\t\t\t2.CHANGE DETAILS:"<<endl;
         cout << "\t\t\t------------------------------------------------------------------" << endl;
        cout<<"\t\t\tENETR YOUR CHOICE:";
        cin>>mych;

        switch(mych)
        {
        case 1:
        {
t2:
            long int pay;
            system("cls");
            title();
            cout << "\t\t\t------------------------------------------------------------------" << endl;
            cout<<"\t\t\tNOTE:- IF YOUR PAYMENT AMMOUNT IS DIFFERENT FROM TOTAL COST OF YOUR"
                <<"\n\t\t\tTRIP IT WILL NOT BE ACCEPTED....!!"
                <<"\n\n\t\t\tTOTAL COST:"<<tcost
                <<"\n\n\t\t\tYOU HAVE ONLY 3 TRY TO MAKE PAYMENT...!! "<<endl;
            cout << "\t\t\t------------------------------------------------------------------" << endl;


            int i;
            int count=0;

            for(i=1; i<=3; i++)
            {

                cout<<"\n\t\t\t"<<i<<")"<<"PAY YOUR TOTAL AMOUNT:";
                cin>>pay;

                if(pay==tcost)
                {
                    stringstream tc;
                    tc<<tcost;
                    tc>>TripCost;
                    count=1;
                    break;
                }
            }

            if(count==1)
            {
                system("cls");
                string su = "INSERT INTO Trip(userid,Full_name,TripCity,TripPNum,TripSdt,TripEdt,TripCost) VALUES('" + Tuserid + "','" + Full_name + "','" + TripCity + "','" + TripPNum +"','" + TripSdt + "','" + TripEdt + "','" + TripCost + "')";


                const char* TRIP = su.c_str();
                qstate = mysql_query(conn, TRIP);

                if (qstate == 0)
                {
                    title();
                    cout << "\t\t\tHELLO..!! " << Full_name << "\n\t\t\t TRIP REGISTRATION SUCESSFULL...!!" <<"\n\t\t\t PRESS ENTER TO CONTINUE...."<< endl;
                    cin.get();
                    cin.get();
                    userhomepage(userid);
                }
                else
                {
                    cout << "\t\t\tERROR...IN REGISTRATION..\n\t\t\tPLEASE CHECK YOUR DETAILS..." << endl;
                }

            }
            else
            {
                system("cls");
                title();
                cout<<"\n\t\t\tERROR IN PAYMENT..!!";
                cin.get();
                cin.get();
                userhomepage(userid);

            }

            break;
        }
        case 2:
        {
            system("cls");
            title();
            cout<<"\n\t\t\tEDIT YOUR DETAILS AGAIN...!!";
            cin.get();
            cin.get();
            userhomepage(userid);
            break;
        }
        default:
        {
            cout<<"\n\t\t\tYOU HAVE ENTERED WORNG CHOICE...!!";
            break;
        }
        }
    }

    void ChekTripD(string userid)
    {
        system("cls");
        title();
        cout<<endl;
        cout << "\t\t\t                           TRIP DETAILS                           " << endl;
        cout << "\t\t\t******************************************************************" << endl;
        int count=0;

        string query = "SELECT * FROM trip";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {

                if(userid==row[1])
                {
                    cout << endl;
                    cout << "\t\t\t TRIP ID: " << row[0] <<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t USERID: " << row[1]<<"                                           " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t FULL NAME: " << row[2]<<"                                        " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t CITY: " << row[3]<<"                                             " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t NUMBER OF PERSON: " << row[4]<<"                                 " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t START DATE: " << row[5]<<"                                       " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t END DATE: " << row[6]<<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t TOTAL COST: " << row[7]<<"                                       " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\t******************************************************************" << endl;
                };

            }
        }
        cin.get();
        cin.get();
        userhomepage(userid);

    }
    void TripExp(string userid)
    {
        system("cls");
        title();
        sqlconn();
        cout<<endl;
        cout << "\t\t\t                           TRIP EXP                               " << endl;
        cout << "\t\t\t******************************************************************" << endl;

        string Tripid;
        string TripCity,Full_name,sdt,edt;
        cout<<"\t\t\tENTER YOUR TRIP ID:";
        cin>>Tripid;


        //---------------------------------------------------------------------------------------
        string query = "SELECT * FROM trip";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);


        system("cls");
        title();
        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {


                    if(Tripid == row[0] && userid==row[1])
                    //if(userid==row[1])
                    {
                     system("cls");
                    title();
                    Full_name=row[2];
                    TripCity=row[3];
                    sdt=row[5];
                    edt=row[6];
                    }


                else
                {
                    //cout<<"\t\t\tSORRY YOU HAVE NOT CREATED ANY  TRIP..!!";

                }

            }
        }
        //----------------------------------------------------------------------------------------------------

        system("cls");
        title();

        cout<<"\n\t\t\tUSERID: "<<userid;
        cout<<"\n\t\t\tNAME: "<<Full_name;
        cout<<"\n\t\t\tTripID: "<<Tripid;
        cout<<"\n\t\t\tCITY: "<<TripCity;
        cout<<"\n\t\t\tSTAT DATE: "<<sdt;
        cout<<"\n\t\t\tEND DATE: "<<edt;
        cin.get();
        cin.get();
        t5:

        int num=0,Tcost=0,E_cost=0;
        string E_userid,E_name,E_cat,E_PNum,E_Tcost,E_Cost;

        E_userid=userid;

       // -----------------------------------GOA------------------------------------------------------------------


        if(TripCity == "GOA BEACHES-GOA")
        {
            system("cls");
            title();
            int ch;
            int num=0,Tcost=0,Ecost=0;

            cout<<"\n\t\t\tSELECT YOUR CHOISE!!!!"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\t1.RESORT IN GOA"<<endl;
            cout<<"\n\t\t\t2.ADVENTURE SPORTS IN GOA"<<endl;
            cout<<"\n\t\t\t3.EXIT"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\tENTER YOUR CHOISE:";
            cin>>ch;

            switch(ch)//FOR HOTEL AND WATER SPORT
            {
            case 1://FOR HOTEL
                {
                system("cls");
                title();
                int hot;
                int num,Tcost,Ecost;
                cout<<"\n\t\t\tRESORT IN GOA"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\t1.Village Susegat Beach Resort"<<endl;
                cout<<"\n\t\t\t2.Caravela Beach Resort"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\tENTER YOUR CHOICE:";
                cin>>hot;


                    switch(hot)//FOR HOTEL OPENTION
                    {
                    case 1:
                        {
                            t7:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t Village Susegat Beach Resort"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\n\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "Village Susegat Beach Resort";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name ="Village Susegat Beach Resort";
                                E_cat="FOOD";
                                E_cost=800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto t7;
                            }
                        break;
                        }
                        case 2:
                        {
                            t6:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t Caravela Beach Resort"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "Caravela Beach Resort";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name = "Caravela Beach Resort";
                                E_cat="FOOD";
                                E_cost= 800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto t6;
                            }
                        break;
                    }
                    }
            case 2:
                {
                    system("cls");
                    title();
                    int spo;
                    cout<<"\n\t\t\tADVENTURE SPORTS IN GOA"<<endl;
                    cout <<"\t\t\t******************************************************************" << endl;
                    cout<<"\t\t\t1.Scuba Diving";
                    cout<<"\n\t\t\t2.Bungee Jumping";
                    cout <<"\n\t\t\t******************************************************************" << endl;
                    cout<<"\n\t\t\tEnter your choice!";
                    cin>>spo;

                    switch(spo)
                    {
                    case 1:
                        {
                                cout<<"\n\t\t\t Scuba Diving = 1000Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="Scuba Diving";
                                E_cost=1000;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);

                            break;
                        }
                    case 2:
                        {
                               cout<<"\n\t\t\tBungee Jumping = 800Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="Bungee Jumping";
                                E_cost=800;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON;";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                                break;
                        }
                        break;
                    }


                    break;
                }
            case 3:
                {
                    system("cls");
                    userhomepage(userid);
                    break;
                }
            default:
                {
                    cout<<"\n\t\t\tSORRY U HAVE ENTERED WORNG CHOICE!!!!"<<endl;
                    goto t5;
                    break;
                }
            }
        }
    }//TRIP CITY=GOA

    //------------------------------------------TAJ MAHAL-AGRA--------------------------------------------------------------
        if(TripCity == "TAJ MAHAL-AGRA")
        {
            system("cls");
            title();
            int ch;
            int num=0,Tcost=0,Ecost=0;

            cout<<"\n\t\t\tSELECT YOUR CHOISE!!!!"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\t1.HOTEL IN AGRA"<<endl;
            cout<<"\n\t\t\t2.EXIT"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\tENTER YOUR CHOISE:";
            cin>>ch;

            switch(ch)//FOR HOTEL AND WATER SPORT
            {
            case 1://FOR HOTEL
                {
                system("cls");
                title();
                int hot;
                int num,Tcost,Ecost;
                cout<<"\n\t\t\tHOTEL IN AGRA"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\t1. Tajview Hotel"<<endl;
                cout<<"\n\t\t\t2.The Oberoi Hotel"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\tENTER YOUR CHOICE:";
                cin>>hot;


                    switch(hot)//FOR HOTEL OPENTION
                    {
                    case 1:
                        {
                            taj7:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t Tajview Hotel"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\n\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "Tajview Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name ="Tajview Hotel";
                                E_cat="FOOD";
                                E_cost=800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto taj7;
                            }
                        break;
                        }
                        case 2:
                        {
                            taj6:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\tThe Oberoi Hotel"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "The Oberoi Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name = "The Oberoi Hotel";
                                E_cat="FOOD";
                                E_cost= 800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto taj6;
                            }
                        break;
                    }
                    }

            case 2:
                {
                    system("cls");
                    userhomepage(userid);
                    break;
                }
            default:
                {
                    cout<<"\n\t\t\tSORRY U HAVE ENTERED WORNG CHOICE!!!!"<<endl;
                    goto t5;
                    break;
                }
            }
        }
    }//TRIP CITY =TAJ MAHALK-AGRA

    //------------------------------------------LADAKH-KASHMIR------------------------------------------------------------
    if(TripCity == "LADAKH-KASHMIR")
        {
            system("cls");
            title();
            int ch;
            int num=0,Tcost=0,Ecost=0;

            cout<<"\n\t\t\tSELECT YOUR CHOISE!!!!"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\t1.HOTEL IN LADAKH"<<endl;
            cout<<"\n\t\t\t2.ADVENTURE SPORTS IN LADAKH"<<endl;
            cout<<"\n\t\t\t3.EXIT"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\tENTER YOUR CHOISE:";
            cin>>ch;

            switch(ch)//FOR HOTEL AND WATER SPORT
            {
            case 1://FOR HOTEL
                {
                system("cls");
                title();
                int hot;
                int num,Tcost,Ecost;
                cout<<"\n\t\t\tHOTEL IN LADAKH"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\t1.The Grand Dragon Hotel"<<endl;
                cout<<"\n\t\t\t2.MOONLAND Hotel"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\tENTER YOUR CHOICE:";
                cin>>hot;


                    switch(hot)//FOR HOTEL OPENTION
                    {
                    case 1:
                        {
                            leh7:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t The Grand Dragon Hotel"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\n\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "The Grand Dragon Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name ="The Grand Dragon Hotel";
                                E_cat="FOOD";
                                E_cost=800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto leh7;
                            }
                        break;
                        }
                        case 2:
                        {
                            leh6:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t MOONLAND Hotel"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "MOONLAND Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name = "MOONLAND Hotel";
                                E_cat="FOOD";
                                E_cost= 800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto leh6;
                            }
                        break;
                    }
                    }
            case 2:
                {
                    system("cls");
                    title();
                    int spo;
                    cout<<"\n\t\t\tADVENTURE SPORTS IN GOA"<<endl;
                    cout <<"\t\t\t******************************************************************" << endl;
                    cout<<"\t\t\t1.Mountain Biking";
                    cout<<"\n\t\t\t2.Camel Safari";
                    cout <<"\n\t\t\t******************************************************************" << endl;
                    cout<<"\n\t\t\tEnter your choice:";
                    cin>>spo;

                    switch(spo)
                    {
                    case 1:
                        {
                                cout<<"\n\t\t\tMountain Biking = 1000Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="Mountain Biking";
                                E_cost=1000;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON:";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);

                            break;
                        }
                    case 2:
                        {
                               cout<<"\n\t\t\tCamel Safari = 800Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="Camel Safari";
                                E_cost=800;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON:";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                                break;
                        }
                        break;
                    }


                    break;
                }
            case 3:
                {
                    system("cls");
                    userhomepage(userid);
                    break;
                }
            default:
                {
                    cout<<"\n\t\t\tSORRY U HAVE ENTERED WORNG CHOICE!!!!"<<endl;
                    goto t5;
                    break;
                }
            }
        }
    }//TRIP CITY=LADAKH-KASHMIR
    //------------------------------------------STATUE OF UNITY - KEVADIA,GUJARAT------------------------------------------------------------
    if(TripCity == "STATUE OF UNITY-KEVADIA,GUJARA")
        {
            system("cls");
            title();
            int ch;
            int num=0,Tcost=0,Ecost=0;

            cout<<"\n\t\t\tSELECT YOUR CHOISE!!!!"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\t1.HOTEL IN STATUE OF UNITY-KEVADIA"<<endl;
            cout<<"\n\t\t\t2.ADVENTURE SPORTS IN STATUE OF UNITY-KEVADIA"<<endl;
            cout<<"\n\t\t\t3.EXIT"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\tENTER YOUR CHOISE:";
            cin>>ch;

            switch(ch)//FOR HOTEL AND WATER SPORT
            {
            case 1://FOR HOTEL
                {
                system("cls");
                title();
                int hot;
                int num,Tcost,Ecost;
                cout<<"\n\t\t\tHOTEL IN STATUE OF UNITY-KEVADIA"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\t1.Statue Of Unity Tent City"<<endl;
                cout<<"\n\t\t\t2.The Fern Sardar Sarovar Resort"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\tENTER YOUR CHOICE:";
                cin>>hot;


                    switch(hot)//FOR HOTEL OPENTION
                    {
                    case 1:
                        {
                            sou7:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t Statue Of Unity Tent City"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\n\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "Statue Of Unity Tent City";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name ="Statue Of Unity Tent City";
                                E_cat="FOOD";
                                E_cost=800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto sou7;
                            }
                        break;
                        }
                        case 2:
                        {
                            sou6:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\tThe Fern Sardar Sarovar Resort"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "The Fern Sardar Sarovar Resort";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name = "The Fern Sardar Sarovar Resort";
                                E_cat="FOOD";
                                E_cost= 800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto sou6;
                            }
                        break;
                    }
                    }
            case 2:
                {
                    system("cls");
                    title();
                    int spo;
                    cout<<"\n\t\t\tADVENTURE SPORTS IN STATUE OF UNITY-KEVADIA"<<endl;
                    cout <<"\t\t\t******************************************************************" << endl;
                    cout<<"\t\t\t1.River Rafting";
                    cout<<"\n\t\t\t2.Jungle Safari";
                    cout <<"\n\t\t\t******************************************************************" << endl;
                    cout<<"\n\t\t\tEnter your choice:";
                    cin>>spo;

                    switch(spo)
                    {
                    case 1:
                        {
                                cout<<"\n\t\t\tRiver Rafting = 1000Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="River Rafting";
                                E_cost=1000;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON:";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);

                            break;
                        }
                    case 2:
                        {
                               cout<<"\n\t\t\Jungle Safari = 800Rs";

                                E_name = "ADVENTURE SPORTS";
                                E_cat="Jungle Safari";
                                E_cost=800;

                                cout<<"\n\t\t\tENETR THE NUMBER OF PERSON:";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                                break;
                        }
                        break;
                    }


                    break;
                }
            case 3:
                {
                    system("cls");
                    userhomepage(userid);
                    break;
                }
            default:
                {
                    cout<<"\n\t\t\tSORRY U HAVE ENTERED WORNG CHOICE!!!!"<<endl;
                    goto t5;
                    break;
                }
            }
        }
    }//TRIP CITY=STATUE OF UNITY - KEVADIA,GUJARAT
    //------------------------------AJANTA & ELLORA CAVES-AURANGABAD,MAHARASHTRA-----------------------------------------------------------
         if(TripCity == "AJANTA & ELLORA CAVES-AURANGABAD,MAHARASHTRA")
        {
            system("cls");
            title();
            int ch;
            int num=0,Tcost=0,Ecost=0;

            cout<<"\n\t\t\tSELECT YOUR CHOISE!!!!"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\t1.HOTEL IN AURANGABAD"<<endl;
            cout<<"\n\t\t\t2.EXIT"<<endl;
            cout <<"\t\t\t******************************************************************" << endl;
            cout<<"\t\t\tENTER YOUR CHOISE:";
            cin>>ch;

            switch(ch)//FOR HOTEL AND WATER SPORT
            {
            case 1://FOR HOTEL
                {
                system("cls");
                title();
                int hot;
                int num,Tcost,Ecost;
                cout<<"\n\t\t\tHOTEL IN AURANGABAD"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\t1.Tajview Hotel"<<endl;
                cout<<"\n\t\t\t2.The Oberoi Hotel"<<endl;
                cout << "\t\t\t******************************************************************" << endl;
                cout<<"\t\t\tENTER YOUR CHOICE:";
                cin>>hot;


                    switch(hot)//FOR HOTEL OPENTION
                    {
                    case 1:
                        {
                            ANE7:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\t Tajview Hotel"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout << "\t\t\t******************************************************************" << endl;
                            cout<<"\n\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "Tajview Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name ="Tajview Hotel";
                                E_cat="FOOD";
                                E_cost=800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto ANE7;
                            }
                        break;
                        }
                        case 2:
                        {
                            ANE6:
                            system("cls");
                            title();
                            int food;
                            cout<<"\n\t\t\tThe Oberoi Hotel"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tSELECT YOUR FOOD PREFRANCE"<<endl;
                            cout<<"\n\t\t\t1.Vegetarian"<<endl;
                            cout<<"\n\t\t\t2.Non-Vegetarian"<<endl;
                            cout <<"\t\t\t******************************************************************" << endl;
                            cout<<"\t\t\tENTER YOUR CHOICE:";
                            cin>>food;

                            if(food==1)
                            {
                                cout<<"\n\t\t\tVegetarian Dish Total Cost = 600RS";
                                E_name = "The Oberoi Hotel";
                                E_cat="FOOD";
                                E_cost=600;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else if(food==2)
                            {
                                cout<<"\n\t\t\tNon-Vegetarian Dish Total Cost = 800RS";

                                E_name = "The Oberoi Hotel";
                                E_cat="FOOD";
                                E_cost= 800;

                                cout<<"\n\t\t\tENTER NUMBER OF PERSON";
                                cin>>num;

                                Tcost=(E_cost*num);
                                TripExpadd(userid,Full_name,Tripid,TripCity,E_name,E_cat,num,E_cost,Tcost);
                            }
                            else
                            {
                              cout<<"\n\t\t\tWORNG CHOICE!!!";
                            goto ANE6;
                            }
                        break;
                    }
                    }

            case 2:
                {
                    system("cls");
                    userhomepage(userid);
                    break;
                }
            default:
                {
                    cout<<"\n\t\t\tSORRY U HAVE ENTERED WORNG CHOICE!!!!"<<endl;
                    goto t5;
                    break;
                }
            }
        }
    }//TRIP CITY = AJANTA & ELLORA CAVES-AURANGABAD,MAHARASHTRA
}



    void TripExpadd(string userid,string Full_name,string E_tripid,string TripCity,string E_name,string E_cat,int num,int E_cost,int Tcost)
    {

        system("cls");
        title();
        sqlconn();

        string E_PNum,E_Tcost,E_Cost;
        stringstream TN;
        TN<<num;
        TN>>E_PNum;

        stringstream TC;
        TC<<Tcost;
        TC>>E_Tcost;

        stringstream TCE;
        TCE<<E_cost;
        TCE>>E_Cost;

        string su="INSERT INTO tripexp(userid,Full_name,Tripid,TripCity,E_name,E_cat,E_cost,E_PNum,E_Tcost) VALUES( '" + userid + "' , '" + Full_name + "' ,'" + E_tripid + "', '" + TripCity + "' , '" + E_name + "'  , '" + E_cat + "' , '" + E_Cost + "' ,'" + E_PNum + "', '" + E_Tcost + "')";
        const char* T= su.c_str();
        qstate = mysql_query(conn,T);

        if (qstate == 0)
        {
            cout << "\t\t\tHELLO..!! " << Full_name << "\n\t\t\tREGISTRATION SUCESSFULL...!!" <<"\n\t\t\t PRESS ENTER TO CONTINUE...."<< endl;
            cin.get();
            cin.get();
            userhomepage(userid);
        }
        else
        {
            cout << "\t\t\tERROR" << endl;
        }
    }

    void TripExpdisplay(string userid)
    {
        system("cls");
        title();
        cout<<endl;
        cout << "\t\t\t                        TRIP  EXP DETAILS                         " << endl;
        cout << "\t\t\t******************************************************************" << endl;
        int count=1;
        string Tripid;
        cout<<"\t\t\tENTER YOUR TRIP ID TO CHECK YOUR DETAILS:";
        cin>>Tripid;

        string query = "SELECT * FROM tripexp";

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {

                if(userid==row[1] && Tripid==row[3])
                {
                    cout << endl;
                    cout << "\t\t\t TRIP EXP ID: " << row[0] <<"                                         " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t USERID: " << row[1]<<"                                           " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t FULL NAME: " << row[2]<<"                                        " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t TRIP ID: " << row[3]<<"                                          " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t CITY: " << row[4]<<"                                             " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE NAME: " << row[5]<<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE CAT: " << row[6]<<"                                      " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE COST: " << row[7]<<"                                     " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t NUMBER OF PERSONS: " << row[8]<<"                                " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\t\t\t EXPANCE TOTAL COST: " << row[9]<<"                               " << endl;
                    cout << "\t\t\t------------------------------------------------------------------" << endl;
                    cout << "\n\t\t\t******************************************************************" << endl;
                    count=2;
                    }

            }

            if(count==1)
            {
                cout<<"\n\t\t\tSORRY YOU HAVE NOT CREATED ANY TRIP..!!";
            }

        }
        cin.get();
        cin.get();
        userhomepage(userid);

    }


};



void sqlconn()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "heart2022", "tmsdb", 3306, NULL, 0);
}

void time()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    cout<<"\n\n";
    cout << "\t\t\t\tThe local date and time is:"<<dt;

}
void title()
{
    time();
    cout << "\n";
    cout << "\t\t\t******************************************************************" << endl;
    cout << "\t\t\t|                     TRIP MANAGEMENT SYSTEM                     |" << endl;
    cout << "\t\t\t******************************************************************" << endl;
}

void lastpage()
{
    system("cls");
    title();
    cout << "\t\t\tTHANK YOU VISIT AGAIN.....!!" << endl;
    cout << "\n\n\t\t\tTHIS PROGRAM IS CREATED BY    :- ABHISHEK PATHAK" << endl;
    cout << "\t\t\t                        EMAIL :- APCSE131@GMAIL.COM" << endl;
    cout << "\t\t\t******************************************************************" << endl;
}

int main()
{
    system("cls");
    system("color 0A");
    sqlconn();

    title();
    int ch;

    admin a1;
    user u1;
    trip t1;

    cout << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t|  1. ADMIN                                                      |" << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t|  2. USER                                                       |" << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------------------------------------------------" << endl;
    cout << "\t\t\t|  3. EXIT                                                       |" << endl;
    cout << "\t\t\t------------------------------------------------------------------\n" << endl;
    cout << "\t\t\tENTER YOUR CHOISE:";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
        a1.adminloginpage();
        break;
    }
    case 2:
    {
        u1.userloginpage();
        break;
    }
    case 3:
    {
        lastpage();
        break;
    }
    default:
    {
        system("cls");
        cout << "\t\t\tSORRY YOU HAVE ENTERED WRONG CHOISE:" << endl;
        main();
    }
    }
    return 0;

}
