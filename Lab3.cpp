#include <iostream>
#include <stdio.h>

using namespace std;

bool sprchk(char a, char* separ)
{
    //char* separ = separators;
    while(*separ != '\0')
    {
        if (a == *separ)
        {
            return true;
        }
        separ++;
    }
    return false;
}
void bufins(int &bc, int &ws, char* arr, char* buf)
{
    for (int k = bc - 1; k >= 0; k--)
    {
        arr[ws] = buf[k];
        ws++;
    }
    bc = 0;
}

int main()
{
    char ustr[500], finstr[500], buf[500];
    cout << "Enter something:\n";
    cin.getline(ustr, 500, '\n');
    char separ[] = ",;.':@!#$%^&*()_+= ~[]{}|/";

    bool word = false, rev = false;
    int j = 0,bk =0;

    for (int i = 0; i < strlen(ustr); i++)
    {
        if (sprchk(ustr[i], separ) == true)
        {
            if (word == true)
            {
                if (rev == true)
                {
                    bufins(bk, j, finstr, buf);
                }
                rev = not rev;
            }
            finstr[j] = ustr[i];
            j++;
            word = false;
        }
        else
        {
            word = true;
            if (rev == true)
            {
                buf[bk] = ustr[i];
                bk++;
            }
        }
        
    }
    if (bk != 0)
        bufins(bk, j, finstr, buf);
    for (int k = 0; k <= j-1; k++)
        cout << finstr[k];
}

/*
Test1

Good morning
 gninrom

Test2

    hello; my friend
    ; ym

Test3

Big apl:le
 lpa:
*/