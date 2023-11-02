#include <iostream>
#include <stdio.h>

void moveNullTerm(char* s, int size)
{
    for (int i = size-2; i >=0; i--)
    {
        if (s[i]!=' ')
        {
            s[i+1]='\0';
            break;
        }
    }
}

void arrayShiftLeft(char* s,int cnt, int size)
{   
    for (int i = 0; i < cnt; i++)
    {
        char t = s[0];
        for (int j = 0; s[j]!='\0'; j++)
        {
            s[j] = s[j+1];
        }
        s[size-2] = t;
    }
    s[size-1-cnt]='\0';
}

void prefSpaceRem(char* s, int size)
{
    int cnt=0;
    for (int i = 0; s[i]!='\0'; i++)
    {
        if (s[i]==' ')
        {
            cnt++;  
        }
        else if(s[i]!=' ')
        {
            break;
        }
    }
    arrayShiftLeft(s,cnt,size);
}

void postSpaceRem(char* s, int size)
{
    moveNullTerm(s,size);
}

void postPrefSpaceRem(char* s, int size)
{
    prefSpaceRem(s,size);
    moveNullTerm(s,size);
}

int main()
{
    int len;
    std::cout<<"Type the len of string\n";
    std::cin>>len;
    char* s = new char[len];

    std::cin.ignore(); //clear the buffer
    std::cin.getline(s, len);

    std::cout<<s<<std::endl;
    postSpaceRem(s,len);
    prefSpaceRem(s,len);
    postPrefSpaceRem(s,len);
    std::cout<<s<<std::endl;
    delete[] s;
}