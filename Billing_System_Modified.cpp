#include<iostream>
#include<fstream>

using namespace std;
//create a class for the shopping market
class shopping
{
    //data and variable
private:
    int prcode;
    float price;
    float discount;
    string prname;
public:
    //sufficient function for project
    void menu();
    void admin();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
//function for show the menu both for admin and buyers

void shopping::menu()
{
    int choice;
    string email;
    string password;

    while(true) // Keep showing the menu until the user chooses to exit
    {
        cout<<"\t\t\t\t_____________________________\n";
        cout<<"\t\t\t\t                             \n";
        cout<<"\t\t\t\t    Supermarket Main manu    \n";
        cout<<"\t\t\t\t_____________________________\n";
        cout<<"\t\t\t\t                             \n";
        cout<<"\t\t\t\t|  1) Administrator   |\n";
        cout<<"\t\t\t\t|                     |\n";
        cout<<"\t\t\t\t|  2) Buyer           |\n";
        cout<<"\t\t\t\t|                     |\n";
        cout<<"\t\t\t\t|  3) Exit            |\n";
        cout<<"\t\t\t\t|                     |\n";
        cout<<"\n\t\t\t please , select an Option : ";
        cin>>choice;

        switch(choice)
        {
            case 1://administrator can access
                cout<<"\t\t\t Please Login\n";
                cout<<"\t\t\t Enter Email : \n";
                cin>>email;
                cout<<"Enter The Password :   \n";
                cin>>password;

                if (email=="nomanjoy9925@gmail.com"&&password=="noman@123")
                {
                    admin();
                }
                else
                {
                    cout <<"Invalid Email Or Password!";
                    cout<<"Please, recheck the password or Email you provide";
                }
                break;

            case 2: //buyer can access
                buyer();
                break;

            case 3:
                exit(0);

            default :
                cout<<"Please select from the given options";
        }
    }
}

//function for the machanism of admid.here the admin can add new product,mofiy his product,delete his product
void shopping:: admin()
{
    //main_manu:
    while(true)
    {
    int choice;
    cout<<"\n\n\n\t\t\t Administrator manu";
    cout<<"\n\t\t\t|___1) Add the Product_____|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___2) Modify the Product__|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___3)Delete the Product___|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|__4)Back to the main manu_|";

    cout<<"\n\n\t Please Enter your Choice : ";
    cin>>choice;

    //blocks for choose option
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        {
            edit();
            break;
        }
    case 3:
        {
            rem();
            break;
        }
    case 4:
        {
            menu();
            break;
        }
    default:
        cout<<"Invalid Choice!!";
      }
    }
}

//blocks for buyers.here they can buys products to do some comand
void shopping::buyer()
{
    while(true)
    {
    int choice;

    cout<<"\t\t\t Buyer  \n";
    cout<<"\t\t\t_____________ \n";
    cout<<"                    \n";
    cout<<"\t\t\t 1)Buy Product\n";
    cout<<"                    \n";
    cout<<"\t\t\t 2)Go back    \n";
    cout<<"\t\t\t Enter Your Choice : ";
    cin>>choice;

    switch(choice)
    {
           case 1:
               receipt();
               break;
           case 2:
            menu();
           default:
            cout<<"Invalid Choice";
    }
    }
}

//function to add product

void shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    while(true) // Keep asking for a new product until a unique product code is entered
    {
        cout <<"\n\n\t\t\tAdd new Product";
        cout<<"\n\n\tCode of the Product :";
        cin>>prcode;
        cout<<"\n\n\t Name of the product : ";
        cin>>prname;
        cout<<"\n\n\t Price of the product :";
        cin>>price;
        cout<<"\n\n\t Discount on product :";
        cin>>discount;

        data.open("database.txt",ios::in);
        if(!data)
        {
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<prcode<<" "<<prname<<" "<<price<<" "<<discount<<"\n";
            data.close();
            break; // Exit the loop if the file was not initially present
        }
        else
        {
            data>>c>>n>>p>>d;
            while(!data.eof())
            {
                if(c==prcode)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();

            if(token==0) // If the product code is unique, add the product and exit the loop
            {
                data.open("database.txt",ios::app|ios::out);
                data<<" "<<prcode<<" "<<prname<<" "<<price<<" "<<discount<<"\n";
                data.close();
                break;
            }
            else // If the product code is not unique, inform the user and ask for a new product
            {
                cout << "\nThe product code already exists. Please enter a new product.\n";
                token = 0; // Reset token for the next iteration
            }
        }
    }

    cout<<"\n\n\t\t Record Inserted!";
}

//adding a product of the market(ex:juice instead of Milk)

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\tModify the Record";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't Exist!";
        return; // Return from the function if the file doesn't exist
    }

    data1.open("database1.txt",ios::app|ios::out);
    data>>prcode>>prname>>price>>discount;
    while(!data.eof())
    {
        if(pkey==prcode)
        {
            cout<<"\n\t\t Enter the Product new code :";
            cin>>c;
            cout<<"\n\t\t Name of the product :";
            cin>>n;
            cout<<"\n\t\t Price of the product :";
            cin>>p;
            cout<<"\n\t\t Discount : ";
            cin>>d;
            data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            cout<<"\n\t\t RECORD EDITED";
            token++;
        }
        else
        {
            data1<<" "<<prcode<<" "<<prname<<" "<<price<<" "<<discount<<"\n";
        }
        data>>prcode>>prname>>price>>discount;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
        cout<<"\n\nRecord not found!";
    }
}

//remove function
void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\n\tDelete Product";
    cout<<"\n\n\t Product Code :";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"File Doesn't Exist";
        return; // Return from the function if the file doesn't exist
    }

    data1.open("database1.txt",ios::app|ios::out);

    data>>prcode>>prname>>price>>discount;

    while(!data.eof())
    {
        if(prcode==pkey)
        {
            cout<<"\n\n\t Product Delete Successfully";
            token++;
        }
        else
        {
          data1<<" "<<prcode<<" "<<prname<<" "<<price<<" "<<discount<<"\n";
        }

        data>>prcode>>prname>>price>>discount;

    }

    data.close();

    data1.close();

    remove("database.txt");

    rename("database1.txt","database.txt");

     if(token==0)
     {
         cout<<"\n\n Record Not Found";
     }
}

//the function will help us to ensuring the list to the customer or buyer
void shopping ::list()
{
    fstream data;
    data.open("database.txt",ios::in);//open the database file
    cout<<"\n\n|___________________________\n";
    cout<<"proNO\t\tName\t\tPrice\n";
    cout<<"\n\n|___________________________\n";
    data>>prcode>>prname>>price>>discount;
    while(!data.eof())
    {
        cout<<prcode<<"\t\t"<<prname<<"\t\t"<<price<<"\n";
        data>>prcode>>prname>>price>>discount;
    }
    data.close();
}

//BLOCK of BUYERS TOTAL DATA CALCULATION
//here all the customer operation will take place

void shopping::receipt()
{
    system("cls");
    fstream data;

    int arrc[100],arrq[100];
    char choice;
    int c=0; //counter variable
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT : ";

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
        return; // Return from the function if the file doesn't exist
    }

    data.close();
    list(); //product which will available in the market

    cout<<"\n____________________________\n";
    cout<<"\n|                            |";
    cout<<"\n|    Please place the order  |";
    cout<<"\n|____________________________|\n";

    do
    {
        cout<<"\n\n Product Code : ";
        cin>>arrc[c];
        cout<<"\n Product Quantity : ";
        cin>>arrq[c];

        for(int i=0;i<c;i++) //if the product code is same then we will show that the code is duplicate
        {
            if(arrc[c] == arrc[i])
            {
                cout<<"\n\n Duplicate Product Code. Please try again!";
                goto m;
            }
        }
        c++; //if the product code is not duplicate then we will increment c

        cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
        cin>>choice;

        m: ; // Label for goto statement

    } while(choice == 'y');

    system("cls");

    cout<<"\n\n\t\t\t__________RECEIPT______________\n";
    cout<<"\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";

    for(int i=0;i<c;i++)
    {
        data.open("database.txt",ios::in);
        data>>prcode>>prname>>price>>discount;

        while(!data.eof())
        {
            if(prcode == arrc[i])
            {
                amount = price*arrq[i];
                dis = amount - (amount*discount/100); // Update 'dis' with the correct discount
                total += dis; // Add 'dis' to 'total'
                cout<<"\n"<<prcode<<"\t\t"<<prname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
            }
            data>>prcode>>prname>>price>>discount;
        }
        data.close();
    }

    float cashback = 0;

    if(total > 5000)
       cashback = total * 0.20; // 20% discount

   else if(total > 1000)
       cashback = total * 0.10; // 10% discount

   total -= cashback;

   cout << "\n\nCashback: " << cashback;
   cout << "\nTotal Amount after Cashback: " << total;
}

//MAIN FUNCTION TO CALL
int main()
{
	shopping s;
	s.menu();
}

