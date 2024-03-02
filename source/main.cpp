#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

int main() 
{
    //Function's proptotypes
    void Pause();
    void RetSequence(int);//For Option A.
    void GenSequence(int&); //For Option B.
    int intNumChars(string);//For Option C.
    
    //Variables.
   const int ERR_CONV = -1;
    bool blnContinue = true;
    
  do //Use of do while.
  {
    //Menu
    cout << "Menu \n"
         << "A. Output n number of terms in a sequence. " << endl 
         << "B. Generate user sequence." << endl
         << "C. Count number of alphabetic characters entered. " << endl
         << "X. Exit the program." << endl;
       
         char chChoice = '\0';
         cout << "Enter either option A, B, C OR X: ";
         cin >> chChoice;
         
         switch(chChoice)
         {
             case 'a':
             case 'A':
             
             {
                 int intNumbers = 0;
                cout << "Enter the amount of numbers you would like to output: ";
                cin >> intNumbers;
                if(cin.fail())
                {
                    cerr << "Enter a valid integer, Program terminated!!!!";
                    exit(ERR_CONV);
                }
              
                RetSequence(intNumbers);
               cout << endl;// outputs inseterd data.
            break;
             }
             
             case 'b':
             case 'B':
             {
                 int intStartValue = 0;
                 cout << "Enter Start Value: ";
                 cin >> intStartValue;
                 
                if(cin.fail())
                {
                    cerr << "Enter a valid integer, Program terminated!!!!";
                    exit(ERR_CONV);
                }
                 
                 GenSequence(intStartValue);
                     cout << endl;
                     break;
             }
             case 'c':
             case 'C':
              {
                 string  strWord = " ";//Declaring and initialising the string datatype. 
                 cout << "Enter a string: ";
                 cin >> strWord;
                 
                   int intCounter = 0;
                   intCounter = intNumChars(strWord);
                  cout << "The number of alphabetic characters is: " << intCounter <<endl;//Outputting into console.
                  break;
               }   
               
             case 'x':
             case 'X':
             {
                 cout <<"Thank you, bye!" << endl;
                 blnContinue = false;
                 break;
             }
             default:
                cerr << "Enter either A, B, C OR X!!" << endl;
         }
         Pause();
   }while(blnContinue);
   return 0;
}
//Functions.

//A.
void RetSequence(int intNumbers)//A non-value-returning function using an argument that is passed by value.
{
               int intMod1Value = 0, intMod0Value = 0;
               for(int i = 1 ; i <= intNumbers; i++)
               {
                   if(i % 2 == 0)
                   {
                      intMod0Value +=  4;
                      cout << intMod0Value << " ";// Inserts data to output stream
                   }
                   else 
                   {
                       intMod1Value += 2;
                       cout << intMod1Value << " ";
                   }
               }
}
//B
void GenSequence(int& x)
{
           const int ERR_CONV = -1;
             int intStopValue = 0;
                 cout << "Enter Stop Value: ";
                 cin >> intStopValue;
                 
                if(cin.fail())
                {
                    cerr << "Enter a valid integer, Program terminated!!!!";
                    exit(ERR_CONV);
                }
             int intStepValue = 0;
                  cout << "Enter Step Value: ";
                 cin >> intStepValue;
                 
                if(cin.fail())
                {
                    cerr << "Enter a valid integer, Program terminated!!!!";
                    exit(ERR_CONV);
                }
             int intNewVal = x;
                 while(intNewVal <= intStopValue)
                 {
                     int i = intNewVal;
                     intNewVal+= intStepValue;
                     cout << i << " "; //Insert the new value into the output stream.
                 }
}

//C
int intNumChars(string Word)// A value-returning function, using byref.
{
             int intX= 0;
                for (char chChar : Word)
                {
                  if (isalpha(chChar)) //Evaluate if entered string is an alphabetic character.
                   {
                       intX++;//increament the count of alphabetic characyers in the string.
                   }  
                  }
    return intX;
}

//Function that Pauses the program
void Pause()
{
   cin.ignore(100,'\n') ;
   cout << "Press Enter to Continue" << endl;
   cin.get();
}

