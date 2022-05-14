#ifndef COLOR_H
#define COLOR_H

// color functions
inline void Red(){
  printf("\033[1;31m");
}
inline void Green(){
  printf("\033[1;32m");
}
inline void white()
{
  printf("\033[0;37m");
}
inline void Cyan()
{
  printf("\033[1;36m");
}
inline void offwhite()
{
  printf("\033[0;18m");
}

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void welcome_screen()
{
  system("cls");
  system("color F0");
  gotoxy(40, 12);
  char helloStr[] = "Names: Filopateer Fouad and Anton Ashraf\n\t\t\t\t\tRegistration numbers: 20106168, 20105183\n\t\t\t\t\tCourse Name: Data Structres\n\t\t\t\t\tCourse Code: CC215";
  for (int i = 0; i < strlen(helloStr); i++)
  {
    if (helloStr[i] == '\n' || helloStr[i] == '\t')
    {
      printf("%c", helloStr[i]);
    }
    else
    {
      printf("%c", helloStr[i]);
      Sleep(10);
    }
  }
  getch();
  system("color 07");
}


#endif