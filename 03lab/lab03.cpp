#include <iostream>
#include <windows.h>

void removeLastSpaces(char *str,int len)
{
    for (int i = len-1; i >= 0; i--) //перебрать с конца
    {
        if (str[i]==' ' || str[i]=='\0') //если символ пробел или \0 то запиши туда ноль(условие с \0 чтобы уменьшить колво кода)
        {
            str[i]='\0';
        }
        else
        {
            break;
        }
    }
}
void removeFirstSpaces(char *str,int len)
{
    while (str[0]==' ')
    {
        for (int j = 0; str[j]!='\0'; j++)
        {
            str[j] = str[j+1];
        }
    }
    
    
}
void removeBoth(char *str,int len)
{
    removeLastSpaces(str,len);
    removeFirstSpaces(str,len);
}
int main()
{
    // для отображения русского язык в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    int n;
    std::cout<<"Введите количество символов в строке\n";
    std::cin>>n;

    char *str1 = new char[n];
    char *str2 = new char[n];
    char *str3 = new char[n];
    
    std::cin.ignore(); //очистеть буфер потому что поссле ввода n в буфере остался \n который помешает считыванию строк
    std::cout<<"Введите строки(1)\n";
    std::cin.getline(str1,n+1);
    std::cout<<"Введите строки(2)\n";
    std::cin.getline(str2,n+1);
    std::cout<<"Введите строки(3)\n";
    std::cin.getline(str3,n+1);

    std::cout<<"===Строки до форматирования===\n";
    std::cout<<"|"<<str1<<"|\n";
    std::cout<<"|"<<str2<<"|\n";
    std::cout<<"|"<<str3<<"|\n";

    removeLastSpaces(str1,n);
    removeFirstSpaces(str2,n);
    removeBoth(str3,n);

    std::cout<<"===Строки после форматирования===\n";
    std::cout<<"|"<<str1<<"|\n";
    std::cout<<"|"<<str2<<"|\n";
    std::cout<<"|"<<str3<<"|\n";

}