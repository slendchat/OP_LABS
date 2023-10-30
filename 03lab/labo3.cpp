#include <iostream>

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
    
}

void arrayShiftRight(char* s,int cnt, int size)
{   
    for (int i = 0; i < cnt; i++)
    {
        char t = s[size-2];
        for (int j = size-3; j>=0; j--)
        {
            s[j+1] = s[j];
        }
        s[0]=t;
    }
    
}

void prefixSpaceRemove(char* s, int size)
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

void postfixSpaceRemove(char* s, int size)
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
            cnt=0;
        }
    }
    arrayShiftRight(s,cnt,size);
}

int main()
{
    char s[]="  hello  ";
    std::cout<<s<<std::endl;
    prefixSpaceRemove(s,sizeof(s)/sizeof(s[0]));
    std::cout<<s<<std::endl;
    
}