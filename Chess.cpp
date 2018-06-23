#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
 
bool valid(const int a)
{
    if (
        a<=8 && a>=1
        )
      return true;
    else return false;
}
 
bool slon (const int x, const int y, const int a, const int b)
{
    if (abs(x-a) == abs(y-b))
        return true;
    else
        return false;
}
bool slon2 (const int x, const int y, const int a, const int b)
{
    if (abs(x-a) == abs(y-b))
        return true;
    else
        return false;
}
 
bool horse(const int a, const int b, const int x, const int y)
{
    if (abs(x-a)*abs(y-b)==2)
        return true;
    else
        return false;
}
 
 
bool udar(const int a0, const int a1, const int a2, const int a3, const int a4, const int a5, const int x, const int y)
{
    if (a0 == a2 == a4)
    {
        if (a2 - a3 > 0 && x < a3)
            return false;
        if (a2 - a3 < 0 && x > a3)
            return false;
        if (a4 - a5 < 0 && x > a5)
            return false;
		if (a4 - a5 < 0 && x < a5)
            return false;
    }
    else
 
    if (a1 == a3 == a5)
    {
        if (a0 - a2 > 0 && y < a2)
            return false;
        if (a0 - a2 < 0 && y > a2)
            return false;
		if (a2 - a4 > 0 && y < a4)
            return false;
		if (a2 - a4 > 0 && y > a4)
            return false;
    }
    else
    return true;
}
 
int main()
{
    int a[6]; 
    for (int i=0; i<=5; ++i)
    {
        scanf("%d", &a[i]);     
        if (!valid(a[i]))
        {
            puts("Error! Try again!");
            --i;
        }
    }
 
 
    for (int x=8; x>=1; --x){
        for (int y=1; y<=8; ++y)
        {
            if (            
            !slon(x, y, a[2], a[3])
            &&  
            horse(a[0],a[1],x,y)
            &&
			!slon(x, y, a[4], a[5])
            &&  
           udar(a[0], a[1], a[2], a[3], a[4], a[5], x, y)
            )
            printf(" o ");
            else
                printf(" * ");
        }
        puts("\n");
    }
    _getch();
    return EXIT_SUCCESS;
}
