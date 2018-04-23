/* 
 * File:   main.cpp
 * Author: Andrew Cruz
 * Created on April 22nd, 2018, 6:05 PM
 * Purpose:  Blackjack Game Project
 */

//System Libraries
#include <iostream>
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
    cout<<"\t\tBlackjack\n\n"<<endl;
    cout<<"welcome to blackjack. What is your first name? "<<endl;
    cin>>name;
    cout<<"How many games would you like to play?: ";
    cin>>choice;
    cout<<endl;
    return 0;
}