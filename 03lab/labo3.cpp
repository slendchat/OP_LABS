#include <iostream>

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

// void arrayShiftRight(char* s,int cnt, int size)
// {   
//     for (int i = 0; i < cnt; i++)
//     {
//         for (int j = size-3; j>=0; j--)
//         {
//             s[j+1] = s[j];
//         }
//     }
// }

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

// void postfixSpaceRemove(char* s, int size)
// {
//     int cnt=0;
//     for (int i = 0; s[i]!='\0'; i++)
//     {
//         if (s[i]==' ')
//         {
//             cnt++;  
//         }
//         else if(s[i]!=' ')
//         {
//             cnt=0;
//         }
//     }
//     arrayShiftRight(s,cnt,size);
// }

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
    char s[]="  hello  ";
    std::cout<<s<<std::endl;
    prefSpaceRem(s,sizeof(s)/sizeof(s[0]));
    postSpaceRem(s,sizeof(s)/sizeof(s[0]));
    postPrefSpaceRem(s,sizeof(s)/sizeof(s[0]));
    std::cout<<s<<std::endl;
    
}