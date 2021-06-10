#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    //define something for Windows (32-bit and 64-bit, this part is common)
    #include <conio.h> // Librería para control de teclado

    int getKey() {
      return getch();
    }

    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    #define KEY_ENTER 13

#elif __APPLE__ || __linux__ || __unix__ || defined(_POSIX_VERSION)
    //define something for Apple platforms, Linux, Unix, & POSIX.
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>

    #define KEY_UP 65
    #define KEY_DOWN 66
    #define KEY_LEFT 68
    #define KEY_RIGHT 67
    #define KEY_ENTER 67 // ENTER is 10, uses right arrow on Mac
    
    int getKey() {
      
      struct termios oldt, newt;
      char ch, command[20];
      int oldf;

      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

      int number = 0;
        
      ch = getchar();
      ch = getchar();
      ch = getchar();
      number = (int)ch;
      ch = -1;
      
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);

      if (ch != EOF) {
        ungetc(ch,stdin);//ith
        putchar(ch);
        scanf("%s",command);
        printf("\n%s\n",command);

        //return -1;
      }      

      return number;
    }

#else
#   error "Unknown compiler" // Unsupported platform for the game
#endif