#include <iostream>
#include <string>
#include <cassert> 

using namespace std;

int findme(string,char);
int findme(string, string);
string case_sensitivity_option_string(string, string);
char case_sensitivity_option_char(char, string);


string Choose_Sensi;

int main()
{
     
     //test1
     string defaltmessage = "all is okay";
     char a = 'I';
     string tryme = "ALL";
     // s for case-sensitive and ns for no case-sensitive (one credit - portfolio 1)
     string option_Sens = "s";  
    
    cout << "This is the string being compared: '" << defaltmessage << "' " << endl;
    
    string new_tryme1 = case_sensitivity_option_string(tryme, option_Sens);
    char new_a1 = case_sensitivity_option_char(a, option_Sens);

    int rchar = findme(defaltmessage, new_a1);
    int rstri = findme(defaltmessage, new_tryme1);
    cout << "\nTEST 1 - case sensitive: " << endl;
    assert(rchar == -1);
    cout << "Test succeeded!\nthe character '" << a << "' was not found, so value returned is: " << rchar << endl;
    assert(rstri == -1);
    cout << "Test succeeded!\nthe substring '" << tryme << "' was not found, so value returned is: " << rstri << endl;

   
   
    //test2
    string defaltmessage2 = "all is okay";
    char a2 = 'Y';
    string tryme2 = "Kay";
    string option_Sens2 = "ns"; 

    string new_tryme2 = case_sensitivity_option_string(tryme2, option_Sens2);
    char new_a2 = case_sensitivity_option_char(a2, option_Sens2);

    int rchar2 = findme(defaltmessage2, new_a2);
    int rstri2 = findme(defaltmessage2, new_tryme2);
    cout << "\nTEST 2 - No case-sensitive: " << endl;
    assert(rchar2 == 10);
    cout << "Test succeeded!\nthe character '" << a2 << "' is found in index: " << rchar2 << endl;
    assert(rstri2 == 8);
    cout << "Test succeeded!\nthe index where the substring '" << tryme2 << "' begins at: " << rstri2 << endl;

    //test3
    string defaltmessage3 = "all is okay";
    char a3 = 'O';
    string tryme3 = "OKAY";

    string new_tryme3 = case_sensitivity_option_string(tryme3, "ns");
    char new_a3 = case_sensitivity_option_char(a3, "s");

    int rchar3 = findme(defaltmessage3, new_a3);
    int rstri3 = findme(defaltmessage3, new_tryme3);
    cout << "\nTEST 3 - no case sensitive for string but case sensitive for char: " << endl;
    assert(rchar3 == -1);
    cout << "Test succeeded!\nthe character '" << a3 <<  "' was not found, so value returned is: " << rchar3 << endl;
    assert(rstri3 == 7);
    cout << "Test succeeded!\nthe index where the substring '" << tryme3 <<  "' begins at: " << rstri3 << endl;

    
 

    return 0;

}

string case_sensitivity_option_string(string tryme, string choose_Sensi)
{
    string new_tryme;
    if (choose_Sensi == "ns")
    {
        for (char ch : tryme) {
            new_tryme += tolower(ch);
        }
        return new_tryme;

    }
    else
    {
        new_tryme = tryme;
        return new_tryme;

    }
}
char case_sensitivity_option_char(char a,string choose_Sensi)
{
    char new_a;
    if (choose_Sensi == "ns")
    {
        new_a = tolower(a);
        return  new_a;
    }
    else
    {
        new_a = a;
        return new_a;
    }

}

int findme(string _stringf, char new_a)
{
    int lengthS = _stringf.length();

    for (int i = 0; i < lengthS; i++)
    {
            if (_stringf[i] == new_a)
            {
                return i;
                break;
            }
    }
    return -1;
}
int findme(string _stringf, string new_tryme)
{

    int i = 0;
    int j = 0;

    while (_stringf[i] != '\0')
    {
        if (_stringf[i] == new_tryme[0])
        {
           
            j = 1;
            while (new_tryme[j] != '\0' && _stringf[j + 1] != '\0')
            {
                j++;

            }
            if (new_tryme[j] == '\0')
            {
                return i;
            }
            
        
        }
        
        
        i++;
    }

 
    return -1;
}