#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
 

 int main () 
 {
// open your vending machine file 
ifstream inFile;
inFile.open("vending.dat");

// declaring vending data array
string name[5][5];
int quantity[5][5];
float price[5][5];
// declare selection
int row = 0;
int column = 0;
//declare payment 
int picked;
int newqt;
float payment;
float currency;
int userinput;
int choice;
int confirm;
float refund;
//variables for money 
double dollars = 20 ;
double quarters = 40;
double dimes = 100;
double nickels = 200;
double total = (dollars * 1) + (quarters * .25) + (dimes * .10)+(nickels * .05);
double user_dollars;
double user_quarters;
double user_dimes;
double user_nickels; 
int change;
//variable for replenishing 
int items;
int qt;
cout << "                           * PLEASE BROWSE THE VENDING MACHINE MENU *                   "<< endl;
cout <<"  _________________________________________________________________________________________________ " << endl;

cout << "***************************************************************************************************************************" << endl;
cout << fixed << setw(33)<< left << "*SNACK* " << setw(33)<< right << " *QUANTITY* " <<setw(33)<< right<<" *PRICE* "<<endl;
  for (int i = 0; i < 5; i++)
    {
        //cout << left << setw(3) << i ;
        for (int j = 0; j < 5; j++)
         {
            
            inFile >> name[i][j];
            cout << setw(30)<<left<<name[i][j]<< " " ;
            
            
            
            inFile >> quantity[i][j];
            cout << setw(30)<<right<< quantity[i][j]<< " " ;

            
            inFile >> price[i][j];
            cout << setw(33)<<right<<setprecision(2)<<price[i][j]<< " " ;
            //inFile.ignore(100,'\n');
            cout << endl;

          
           
                    
    }
        } 
bool repeat = true; 


while(repeat == true)
{
cout << "1. Make Selection"<<endl;
cout << "2. Cancel Selection"<<endl;
cout << "3. Maintenance"<<endl;
cout << "4. exit menu" << endl;
cin >> userinput;


switch(userinput)

case 1 :
    {
    cout << "please pick between 0-4" << endl;
    cout << "Please enter a row: " << endl;
    cin >> row; 
            
    cout << "Please enter a column: ";
    cin >> column;
    
   

    
    while(row < 0 || row > 4 || column < 0 || column > 4 )
        {
            cout << "Please try again"<<endl;
            cout << "Please enter a row: " << endl;
            cin >> row; 
            cout << "Please enter a column: ";
            cin >> column;
        }
            cout << "You picked: " << name[row][column]<< "which is: $ " << price[row][column] << endl;
            if (quantity[row][column]==0)
            {
                cout << "There is no items left please select something else" << row << column ;
                cout << "You picked: " << name[row][column]<< "which is: $ " << price[row][column] << endl;
            }
            else 
            {
                quantity[row][column] = quantity[row][column]-1;
                cout << "the quantity of " << name[row][column] << " is " << quantity[row][column]<<endl;
            }
            
            cout << "Please confirm your item: 1 - yes and 2 - no " << endl;
            cin >> confirm; 
            cout << endl;

            if (confirm == 1 )
            {
                
                cout << "please enter a payment equal to or higher than your item cost:" <<endl;
                cin >> payment;
                cout << endl;
                

                
            }
            else if (confirm == 2)
            {
                cout << "Please enter a row: " << endl;
                cin >> row; 
            
                cout << "Please enter a column: ";
                cin >> column;
                cout << "You picked: " << name[row][column]<< "which is: $ " << price[row][column] << endl;
                cout << "please enter a payment equal to or higher than your item cost:" <<endl;
                cin >> payment;
                cout << endl;
            //take payment
            }
            
            
     while(payment < price[row][column])
        {
            cout << "insufficient payment " << endl;
            cout << "please enter a payment equal to or higher than your item cost:";
            cin >> payment;
            
              
         }
         cout <<"-----------------------------"<<endl;
           if(payment == price[row][column])
            {
             cout << "Enjoy your item" << endl;
            }
          if(payment > price[row][column])
           { 
             change = ((payment - price[row][column]) * 100);
           }
             if(change/100>=1) 
             {
                user_dollars=-change/100;
                cout <<"your change in dollars: " << change/100<<endl;
                change = change%100;
             }
              if (change/25==0||change/25>0)
              {
                user_quarters-=change/25;
                cout <<"your change in quarters: " << change/25 << endl;
                change = change%25;
              }
             if (change/10==0||change/10>0)
             {
                user_dimes-=change/10;
                cout<< "your change in dimes: " << change/10 << endl;
                change = change%10;
             }
             if(change/5==0||change/5>0)
             {
                 user_nickels-=change/5;
                 cout<< "your change in nickels: " << change/5 << endl;
                 change = change%5;
             }
              cout <<"-----------------------------"<<endl;
              total = (total + price[row][column]);
              cout << "The machine total cost: $ " << total << endl;
              cout <<"-----------------------------"<<endl;
 
           
             break;
            
                 case 2:
                    {  
                        refund = price[row][column];
                        cout << " Your refund is : $ " << refund << endl; 
                        cout << "Would you like to make another purchase: enter 1 " << endl;
                        cout << "If you would like to exit program : enter 4 " << endl;
                        total = total - price[row][column];
                        quantity[row][column] = quantity[row][column] + 1;
                        cout << "the quantity of " << name[row][column] << " is now  " << quantity[row][column]<<endl;
                        cout << "New total " << total << endl;
                    }
                    break;
                         
                            case 3:
                            cout << "Would you like to maintenance on inventory or currency" << endl;
                            cout << "1. INVENT0RY and 2. CURRENCY" << endl;
                            cin >> choice;
                                if (choice == 1)
                                {
                                cout << "What items need to be replenished?" << endl;
                                cin >> row >> column;
                                cout << "The items that need to be replenished is: " << name[row][column] << endl;
                                cout << endl;
                                if(quantity[row][column] < 10)
                                {
                                    cout << "the quantity of " << name[row][column] << " is  " << quantity[row][column]<<endl;
                                    cout << "How much does the item need to be replenished? " << endl;
                                    cin >> qt;
                                    quantity[row][column] = quantity[row][column]+ qt;
                                    cout << "the quantity of " << name[row][column] << " is now  " << quantity[row][column]<<endl;
                                }
                                
                                else if (quantity[row][column]==10)
                                    {
                                        cout << "This item does not need to be replenished pick something else" << endl;
                                        cout << "please enter 3 and try again" << endl;

                                        
                                    }
                                    }
                                 if (choice == 2)
                                 {
                                     cout << "CURRENCY" << endl;
                                     cout <<"-----------------------------"<<endl;
                                     cout << "How much is in your current change" << endl;
                                     cout << "Current Vending Machine change is $"<<total<<endl;
                                     if (total == (dollars * 1) + (quarters * .25) + (dimes * .10)+(nickels * .05))
                                     {
                                         cout << "Your total is $50 no need to replenish" <<endl;
                                     }
                                         if (total < (dollars * 1) + (quarters * .25) + (dimes * .10)+(nickels * .05))
                                           {
                                                cout << "How much would you like to enter to replenish change"<<endl;
                                                cin >> currency;
                                                cout << endl;
                                                total = (currency + total);
                                                cout << "The change in the vending machine is now $" << total << endl;
                                            }
                                                if (total > (dollars * 1) + (quarters * .25) + (dimes * .10)+(nickels * .05))
                                                    { 
                                                        cout << "Thank you the current change is fine" <<endl;
                                                    }

                                 }
                                break;
                            
                                
                                case 4: 
                                     {
                                        repeat = false;
                                        cout << "Enjoy. Thank You" <<endl;
                                      }
    

    }
}
    inFile.close();

     return 0;
}