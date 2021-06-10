/*
ESTE ARCHIVO NO SE USA, FUE SÓLO PARA PRUEBAS.
SE UTILIZÓ PARA PODER DETECTAR EL TECLADO EN UNIX.
*/
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
//#include <curses.h>
#include <iostream>
//#include <string>
int main()
{
  struct termios oldt, newt;
  char ch, command[20];
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  int number1 = 0;
  int number2 = 0;
  int number3 = 0;

  while(1)
  {
    ch = getchar_unlocked();
    
    
    number1 = (int)ch;
    ch = getchar_unlocked();
    number2 = (int)ch;
    ch = getchar_unlocked();
    number3 = (int)ch;
    //ch = getchar();
    //ch = getchar();

    if (ch != -1)//(ch == static_cast<char>(KEY_DOWN)/*'\033'*/)
    { 
      std::cout << number1 << std::endl;
      std::cout << number2 << std::endl;
      std::cout << number3 << std::endl;
      printf("Arrow key\n");
      
      ch=-1;
      break;
      }
    else if(ch == -1) // by default the function returns -1, as it is non blocking
    {
      continue;
    }
    else
    {
      break;
    }

  }
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch,stdin);//ith
    putchar(ch);
    scanf("%s",command);
    printf("\n%s\n",command);

    return 1;
  }

  return 0;
}