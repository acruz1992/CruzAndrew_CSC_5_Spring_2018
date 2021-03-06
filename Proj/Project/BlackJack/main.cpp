/* 
 * File:   main.cpp
 * Author: Andrew Cruz
 * Created on April 22nd, 2018, 6:05 PM
 * Purpose:  Blackjack Game Project
 */

//System Libraries
#include <iostream>     //Input/Output Stream Library
#include <cstdlib>      //Library set random number seed
#include <ctime>        //Libary to seed the random number generator
#include <iomanip>      //Format Library
#include <fstream>      //File Library
#include <string.h>     //String Library
using namespace std; 


int main(int argc, char** argv) {
    int choice;                         //to chose how many games the user would like to play
    float pctotal,dctotal;              //the total amount of value of he cards
    char ch;                            //to have the user press enter between card draws
    char hit;                           //to have the user draw a 3rd card
    string name;                        //string to enter the users name
    const int SIZE=20;
    char fileOut[SIZE]="BlackjackOut.dat";
    string fileIn="BlackjackIn.dat";
    ofstream out;
    ifstream in;
    out.open(fileOut);
    in.open(fileIn.c_str());
    
    cout<<"\t\tBlackjack\n\n"<<endl;
    cout<<"welcome to blackjack. What is your first name? "<<endl;
    cin>>name;
    cout<<"How many games would you like to play?: ";
    cin>>choice;
    cin.ignore();                       //had to place this to allow the program have different kinds of inputs
    cout<<endl;
    do{                                 //do while loop for the number of games to play
        {
        cout<<name<<"'s hand:"<<endl;
        int pcard1=(rand()%(14-2+1))+2;  //random dealer card 1
        int pcard2=(rand()%(14-2+1))+2;  //random dealer card 2
        
                switch (pcard1)
                {
                    case 11: cout<<setw(10)<<"Ace";
                    break;
                    case 12: cout<<setw(10)<<"Jack";
                    break;
                    case 13: cout<<setw(10)<<"Queen";
                    break;
                    case 14: cout<<setw(10)<<"King";
                    break;
                    default: cout<<setw(10)<<pcard1;
                    break;
                }
                cout<<" and ";
                switch (pcard2)
                {
                    case 11: cout<<"Ace";
                    break;
                    case 12: cout<<"Jack";
                    break;
                    case 13: cout<<"Queen";
                    break;
                    case 14: cout<<"King";
                    break;
                    default: cout<<pcard2;
                    break;
                }
                cout<<endl;
                if(pcard1>=12)pcard1=10; //jack,queen,king have a 10 value
                if(pcard2>=12)pcard2=10; //jack,queen,king have a 10 value
                pctotal=pcard1+pcard2;
                cout<<"\tTotal is "<<pctotal<<endl;
                if (pctotal<=20)         //if the hand has a value of 20 or less the user can request a 3rd card
                {
                    do
                    {
                        cout<<name<<", would you like to hit again? Y/N: ";
                        cin>>hit;
                        if (hit=='Y'||hit=='y')
                        {
                            int pcard=(rand()%(14-2+1))+2;  //player card 3 to hit if needed
                            cout<<"\tNew card ";
                            switch (pcard)
                            {
                                case 11: cout<<"Ace";
                                break;
                                case 12: cout<<"Jack";
                                break;
                                case 13: cout<<"Queen";
                                break;
                                case 14: cout<<"King";
                                break;
                                default: cout<<pcard;
                                break;
                            }
                            if(pcard>=12){      //jack,queen,king have a 10 value
                                pcard=10;}
                            else if(pcard==11){ //Ace has a value of 1 at the third card
                                pcard=1;}
                            cout<<endl;
                            pctotal+=pcard;     //add the third card value to the original
                            cout<<"\tNew total is "<<pctotal<<"\n"<<endl;
                        }
                    }while ((!(hit=='n'||hit=='N'))||!pctotal>=21);
                }
        }
        cin.ignore();
        cout<<"Press enter to continue."<<endl;
        cin.get(ch);
        cout<<"Now the dealers turn."<<endl;
        {
        cout<<"Dealers hand: "<<endl;
        int dcard1=(rand()%(14-2+1))+2;  //dealer card 1
        int dcard2=(rand()%(14-2+1))+2;  //dealer card 2
        switch (dcard1)
                {
                    case 11: cout<<setw(10)<<"Ace";
                    break;
                    case 12: cout<<setw(10)<<"Jack";
                    break;
                    case 13: cout<<setw(10)<<"Queen";
                    break;
                    case 14: cout<<setw(10)<<"King";
                    break;
                    default: cout<<setw(10)<<dcard1;
                    break;
                }
                cout<<" and ";
                switch (dcard2)
                {
                    case 11: cout<<"Ace";
                    break;
                    case 12: cout<<"Jack";
                    break;
                    case 13: cout<<"Queen";
                    break;
                    case 14: cout<<"King";
                    break;
                    default: cout<<dcard2;
                    break;
                }
                if(dcard1>=12){ //jack,queen,king have a 10 value
                    dcard1=10;}
                if(dcard2>=12){ //jack,queen,king have a 10 value
                    dcard2=10;}
                dctotal=dcard1+dcard2;
                cout<<endl;
                cout<<"\tTotal is "<<dctotal<<endl;
                if (dctotal<=12)
                        {
                            int dcard=(rand()%(14-2+1))+2;  //dealer card 3 to hit if needed
                            cout<<"\tNew card ";
                            switch (dcard)
                            {
                                case 11: cout<<"Ace";
                                break;
                                case 12: cout<<"Jack";
                                break;
                                case 13: cout<<"Queen";
                                break;
                                case 14: cout<<"King";
                                break;
                                default: cout<<dcard;
                                break;
                            }
                            if(dcard>=12){      //jack,queen,king have a 10 value
                                dcard=10;}
                            else if(dcard==11){ //Ace has a value of 1 at the 3rd card
                                dcard=1;}
                            dctotal+=dcard;
                            cout<<endl;
                            cout<<"\tNew total is "<<dctotal<<endl;
                        }
        }
        cout<<endl;
        
        //possible outcomes of the points from under the 21 score to over the 21 score
        {if(dctotal>21&&pctotal>21)
            cout<<"Both of you lost";
        else if (dctotal<=21&&pctotal>21)
            cout<<"Dealer wins"<<endl;
        else if (dctotal>21&&pctotal<=21)
            cout<<name<<" wins"<<endl;
        else if (dctotal<=21&&pctotal<=21&&pctotal==dctotal)
            cout<<"Its a Draw"<<endl;
        else if (dctotal<=21&&pctotal<=21&&pctotal>dctotal)
            cout<<name<<" wins"<<endl;
        else if (dctotal<=21&&pctotal<=21&&pctotal<dctotal)
            cout<<"Dealer wins"<<endl;
        }
        cout<<endl;
        cout<<"Press enter to continue."<<endl;
        cin.get(ch);
        
            
    }while(--choice>=1);
    out.close();
    in.close();
    return 0;
}