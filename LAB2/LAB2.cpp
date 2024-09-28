#include <iostream>
#include <string>
#include <cassert> 

using namespace std;

int findme(string,char);
int findme(string, string);

int main()
{
    //test1
    string defaltmessage = "all is okay";
    char a = ' ';
    string tryme = "el";

    cout << "This is the string being compared: '" << defaltmessage << "' " << endl;
    
    int rchar = findme(defaltmessage, a);
    int rstri = findme(defaltmessage, tryme);
    cout << "\nTEST 1: " << endl;
    assert(rchar == 3);
    cout << "Test succeeded!\nthe character '" << a << "' is found in index: " << rchar << endl;
    assert(rstri == -1);
    cout << "Test succeeded!\nthe substring '" << tryme << "' wasnot found, so value returned is: " << rstri << endl;

    //test2
    string defaltmessage2 = "all is okay";
    char a2 = 'y';
    string tryme2 = "kay";

    int rchar2 = findme(defaltmessage2, a2);
    int rstri2 = findme(defaltmessage2, tryme2);
    cout << "\nTEST 2: " << endl;
    assert(rchar2 == 10);
    cout << "Test succeeded!\nthe character '" << a2 << "' is found in index: " << rchar2 << endl;
    assert(rstri2 == 8);
    cout << "Test succeeded!\nthe index where the substring '" << tryme2 << "' begins at: " << rstri2 << endl;

    //test3
    string defaltmessage3 = "all is okay";
    char a3 = 's';
    string tryme3 = "is";

    int rchar3 = findme(defaltmessage3, a3);
    int rstri3 = findme(defaltmessage3, tryme3);
    cout << "\nTEST 3: " << endl;
    assert(rchar3 == 5);
    cout << "Test succeeded!\nthe character '" << a3 <<  "' is found in index: " << rchar3 << endl;
    assert(rstri3 == 4);
    cout << "Test succeeded!\nthe index where the substring '" << tryme3 <<  "' begins at: " << rstri3 << endl;

    //test4
    string defaltmessage4 = "all is okay";
    char a4 = 'e';
    string tryme4 = "All";

    int rchar4 = findme(defaltmessage4, a4);
    int rstri4 = findme(defaltmessage4, tryme4);
    cout << "\nTEST 4: " << endl;
    assert(rchar4 == -1);
    cout << "Test succeeded!\nthe character '" << a4 << "' was not found, so value returned is: " << rchar4 << endl;
    assert(tryme4 == -1);
    cout << "Test succeeded!\nthe substring '" << tryme4 << "' was not found, so value returned is : " << rstri4 << endl;


    return 0;

}


int findme(string _stringf, char a)
{
    for (int i = 0; i < _stringf.length(); i++)
    {
            if (_stringf[i] == a)
            {

                return i;
                break;
            }
    }
    return -1;
}
int findme(string _stringf, string _tryme)
{
    int i = 0;
    int j = 0;

    while (_stringf[i] != '\0')
    {
        if (_stringf[i] == _tryme[0])
        {
           
            j = 1;
            while (_tryme[j] != '\0' && _stringf[j + 1] != '\0')
            {
                j++;

            }
            if (_tryme[j] == '\0')
            {
                return i;
            }
            
        
        }
        
        
        i++;
    }

 
    return -1;
}