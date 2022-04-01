/////*********************************************************/////
/////*          This program is created for final            */////
/////*          project in Applied Programming course        */////
/////*          in AAST,Cairo,Egypt         2022             */////
/////*********************************************************/////

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

#define N 100
void Menu();
void welcome_screen();
void MainMenu();
bool MenuOption(char c);
void Main_Array();
void Strings();
void Recursion();
void Struct();
void Files();
void Applications();
void Games();
void ExitScreen();
void gotoxy(int x, int y);
bool option;
char c;

int main()
{

  // welcome_screen();

  MainMenu();

  return 0;
}

void MainMenu()
{
  option = false;
  while (option == false)
  {
    Menu();
    printf("Enter which option do you want: ");
    c = getch();
    option = MenuOption(c);
  }
}

void welcome_screen()
{
  system("cls");
  system("color F0");
  gotoxy(40, 12);
  char helloStr[] = "Names: Hussein Shalaby and Anton Ashraf\n\t\t\t\t\tRegistration numbers: 20106681, 20105183\n\t\t\t\t\tCourse Name: Applied Programming\n\t\t\t\t\tCourse Code: CC212";
  for (int i = 0; i < strlen(helloStr); i++)
  {
    if (helloStr[i] == '\n' || helloStr[i] == '\t')
    {
      printf("%c", helloStr[i]);
    }
    else
    {
      printf("%c", helloStr[i]);
      Sleep(50);
    }
  }
  getch();
  system("color 07");
}

/////*********************************************************/////
/////*          Colors, Main Menu, options                   */////
/////*********************************************************/////

void Black()
{
  printf("\033[1;30m");
}
void Green()
{
  printf("\033[1;32m");
}
void Red()
{
  printf("\033[1;31m");
}
void Yellow()
{
  printf("\033[1;33m");
}
void Blue()
{
  printf("\033[1;34m");
}
void purple()
{
  printf("\033[1;35m");
}
void Cyan()
{
  printf("\033[1;36m");
}
void white()
{
  printf("\033[0;37m");
}
void offwhite()
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

void Menu()
{
  system("cls");
  offwhite();
  printf("\n\t\t\tWelcome To Our Final Project in Applied Programming Course\n\n\n");
  Yellow();
  printf("\t==     1 2D Arrays\n\n");
  Green();
  printf("\t==     2 Applications\n\n"); // morse // clock // other
  Cyan();
  printf("\t==     3 Games\n\n"); // ninja // connect4 // tic-tac-toe algo
  Red();
  printf("\t==     e Exit the program\n\n");
  white();
  printf("\n");
}

bool MenuOption(char c)
{
  switch (c)
  {
  case '1':
    Main_Array();
    return 1;
  case '2':
    Applications();
    return 1;
  case '3':
    Games();
    return 1;
  case 'e':
  case 'E':
    ExitScreen();
    return 1;
  default:
    Red();
    printf("Invalid Input!\n");
    Sleep(1000);
    return 0;
  }
}

void ExitScreen()
{
  system("cls");
  system("color F0");
  char helloStr[] = "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThank You for Using Our Program  :)";
  for (int i = 0; i < strlen(helloStr); i++)
  {
    if (helloStr[i] == '\n' || helloStr[i] == '\t')
    {
      printf("%c", helloStr[i]);
    }
    else
    {
      printf("%c", helloStr[i]);
      Sleep(100);
    }
  }
  // system("color 07");
  exit(0);
}

/////*********************************************************/////
/////*                2D Arrays and Matrcies                 */////
/////*********************************************************/////
void Main_Array();
void ArrayMenu();         // Display array menu
bool ArrayOption(char c); // preform based on option choosen
void Diagonals();         // Diagonals funcion                                                     // 1st option
void sumDiagonals();      // get sum of 2 diagonals
void Sum2D();             // Sum of 2 Matrcies                                                     // 2nd option
void addtion();           // prifoming addition of 2 matrcies and printing them with the sum
void Multiply();          // multiply 2 Matrcies                                                   // 3rd option
void Mult();
void MatrixInput();
void twoMatrixInput();
void print_matrix(int r, int c, int mat[][N]);

int mat1[N][N], mat2[N][N], r1, c1, r2, c2;

void Main_Array()
{
  option = false;
  while (option == false)
  {
    white();
    ArrayMenu();
    printf("Enter which option do you want: ");
    c = getch();
    option = ArrayOption(c);
  }
}
void ArrayMenu()
{
  system("cls");
  printf("\n\n\n");
  Blue();
  printf("\t==      1 Sum of main and inverse digonals\n\n");
  printf("\t==      2 Sum of two Matrcies\n\n");
  printf("\t==      3 Mutiply two Matrcies\n\n");
  Yellow();
  printf("\t==      4 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
}
bool ArrayOption(char c)
{
  switch (c)
  {
  case '1':
    Diagonals();
    return 1;
  case '2':
    Sum2D();
    return 1;
  case '3':
    Multiply();
    return 1;
  case '4':
    MainMenu();
    return 1;
  case 'e':
  case 'E':
    exit(0);
  default:
    Red();
    printf("Invalid Input!\n");
    Sleep(1000);
    white();
    return 0;
  }
}

//////*               Sum of Diagonals "First option"         */////
void Diagonals()
{
  system("cls");
  printf("\n\n\tGet the sum of Main and Inverse Diagonal Program\n\n\n");
  MatrixInput();
  system("cls");
  printf("\n\n\tGet the sum of Main and Inverse Diagonal Program\n\n\n");
  sumDiagonals();
}
void sumDiagonals()
{

  int Dsum = 0, IDsum = 0;
  for (int i = 0; i < r1; i++)
    Dsum += mat1[i][i];

  for (int i = 0; i < r1; i++)
  {
    int j = r1 - 1 - i;
    IDsum += mat1[i][j];
  }

  printf("\nThe Matrix is: \n\n");
  Cyan();
  print_matrix(r1, c1, mat1);
  printf("\n\n");
  Green();
  printf("Sum of main diagonal = %d\n", Dsum);
  printf("Sum of inverse diagonal = %d\n", IDsum);
}

/////*      Sum of 2 Matrcies "Second option"                */////
void Sum2D()
{
  system("cls");
  printf("\n\n\t\tGet the sum of two Matrcies Program\n\n");
  twoMatrixInput();
  system("cls");
  printf("\n\n\t\tGet the sum of two Matrcies Program\n\n");
  addtion();
}
void addtion()
{
  if (r1 != r2 || c1 != c2)
  { // check if they are equals in rows and coulumns
    Red();
    printf("\n\n\tSorry can't preform this opertion\nWrong Dimensions!\nThe two matrcies must be in equal dimensions\n");
    return;
  }
  // preform SUM
  int sum[N][N];
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      sum[i][j] = mat1[i][j] + mat2[i][j];
  printf("\n\tThe sum of matrix\n\n");
  Cyan();
  print_matrix(r1, c1, mat1);
  white();
  printf("\n\tAnd Matrix\n\n");
  Cyan();
  print_matrix(r2, c2, mat2);
  // print the sum matrix
  Green();
  printf("\n\tIs equal:\n\n");
  print_matrix(r1, c1, sum);
}

/////*      Multiply two Matrcies "Third option"                */////
void Multiply()
{
  system("cls");
  printf("\n\n\t\tGet the Multiplication of two Matrcies Program\n\n");
  twoMatrixInput();
  system("cls");
  printf("\n\n\t\tGet the Multiplication of two Matrcies Program\n\n");
  Mult();
}
void Mult()
{
  if (c1 != r2)
  {
    Red();
    printf("Sorry can't preform this opertion\nWrong Dimensions!");
    return;
  }
  int mult[N][N];
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c2; j++)
      for (int k = 0; k < c1; k++)
        mult[i][j] += mat1[i][k] * mat2[k][j];

  printf("\n\tThe multiplication of Matrix\n\n");
  Cyan();
  print_matrix(r1, c1, mat1);
  white();
  printf("\n\tAnd Matrix\n\n");
  Cyan();
  print_matrix(r2, c2, mat2);
  // print the sum matrix
  Green();
  printf("\n\tIs equal:\n\n");
  print_matrix(r1, c2, mult);
}

/////*           input & output                  */////
void twoMatrixInput()
{
  white();
  printf("Please enter rows and coulmns of first matrix:\n");
  printf("\nRows: ");
  scanf("%d", &r1);
  printf("coulmns: ");
  scanf("%d", &c1);
  printf("Enter the first matrix %d X %d\n", r1, c1);
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      scanf("%d", &mat1[i][j]);
  printf("Please enter rows and coulmns of second matrix:\n");
  printf("\nRows: ");
  scanf("%d", &r2);
  printf("coulmns: ");
  scanf("%d", &c2);
  printf("Enter the second matrix %d X %d\n", r2, c2);
  for (int i = 0; i < r2; i++)
    for (int j = 0; j < c2; j++)
      scanf("%d", &mat2[i][j]);
}
void MatrixInput()
{
  white();
  printf("Please enter rows and coulmns of the matrix:\n");
  Red();
  printf("note: rows & coulmns must be equal.\n");
  white();
  printf("\nRows: ");
  scanf("%d", &r1);
  printf("coulmns: ");
  scanf("%d", &c1);

  if (r1 != c1)
  { // Must be squaare Matrix
    Red();
    printf("Sorry can't preform this opertion\nWrong Dimensions!\n");
    return;
  }
  printf("Enter the matrix %d X %d\n", r1, c1);
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      scanf("%d", &mat1[i][j]);
}
void print_matrix(int r, int c, int mat[][N])
{
  for (int i = 0; i < r; i++)
  {
    printf("\t");
    for (int j = 0; j < c; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

/////*********************************************************/////
/////*                     Applications                      */////
/////*********************************************************/////
void Applications();
void ApplicationMenu();
bool ApplicationOption(char c);
void Leap_year();
int IsLeapYear(int n);
int GetNextLeapYear(int n);
void DigitalClock();
void DiffTime();
void decBinMenu();
struct TIME
{
  int hours;
  int minutes;
  int seconds;
};
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff);

void Applications()
{
  option = false;
  while (option == false)
  {
    white();
    ApplicationMenu();
    printf("Enter which option do you want: ");
    c = getch();
    option = ApplicationOption(c);
  }
}
void ApplicationMenu()
{
  system("cls");
  printf("\n\n\n");
  Green();
  printf("\t==      1 Check Leap Year\n\n");
  printf("\t==      2 Set a Digital Clock\n\n");
  printf("\t==      3 Diffrence between two times\n\n");
  printf("\t==      4 Convert Numbers\n\n");
  Yellow();
  printf("\t==      5 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
}
bool ApplicationOption(char c)
{
  switch (c)
  {
  case '1':
    Leap_year();
    return 1;
  case '2':
    DigitalClock();
    return 1;
  case '3':
    DiffTime();
    return 1;
  case '4':
    decBinMenu();
    return 1;
  case '5':
    MainMenu();
    return 1;
  case 'e':
  case 'E':
    ExitScreen();
  default:
    Red();
    printf("Invalid Input!\n");
    Sleep(1000);
    white();
    return 0;
  }
}
/////*             Leap Year                 */////

void Leap_year()
{
  //  Leap Year:
  //  If a year is divisible by 4, 100 and 400 then it is a leap year.
  //  If a year is divisible by 4 but not divisible by 100 then it is a leap year

  //  Not a Leap Year:
  //  If a year is not divisible by 4 then it is not a leap year
  //  If a year is divisible by 4 and 100 but not divisible by 400 then it is not a leap year
  system("cls");
  printf("\n\n\t\t\tCheck weather it is Leap year or not Program\n\n");

  int y;
  printf("\n\t\tEnter the year: ");
  scanf("%d", &y);
  if (IsLeapYear(y))
  {
    Green();
    printf("\n\n\t\tYeaaah %d is Leap year!", y);
    return;
  }
  int x = GetNextLeapYear(y);
  Red();
  printf("\t\tnope %d not Leap year\n\n", y);
  Green();
  printf("\t\tBut %d is the next Leap year", x);
  getch();
  Applications();
}
int IsLeapYear(int n)
{
  return (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0));
}
int GetNextLeapYear(int n)
{
  int CurrentYear = n;
  while (!IsLeapYear(CurrentYear))
    CurrentYear++;
  return CurrentYear;
}

/////*            Digital Clock                  */////

void DigitalClock()
{
  time_t seconds;
  struct tm *timeStruct;
  seconds = time(NULL);
  timeStruct = localtime(&seconds);
  char days[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  char months[12][20] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  int h, m, s, day, weekday, year, month;
  system("cls");
  h = timeStruct->tm_hour;
  m = timeStruct->tm_min;
  s = timeStruct->tm_sec;
  day = timeStruct->tm_mday;
  weekday = timeStruct->tm_wday;
  month = timeStruct->tm_mon;
  year = timeStruct->tm_year;
start:
  for (h; h < 24; h++)
  {
    for (m; m < 60; m++)
    {
      Beep(1500, 500);
      for (s; s < 60; s++)
      {
        system("cls");
        Red();
        printf("press e to exit or M to go back to Main Menu\n");
        Green();
        if (h < 12)
        {
          printf("\n\n\t\t\t%d:%d:%d", h, m, s);
          printf(" AM");
        }
        else
        {
          printf("\n\n\t\t\t%d:%d:%d", h - 12, m, s);
          printf(" PM");
        }
        printf("\n\n\t\t\t%s %d %s %d", days[weekday], day, months[month], year + 1900);
        Sleep(1000);
        if (kbhit())
        {
          c = getch();
          if (c == 'e' || c == 'E')
            exit(0);
          else if (c == 'm' || c == 'M')
            Applications();
        }
      }
      s = 0;
    }
    m = 0;
  }
  h = 0;
  goto start;
  getch();
}

/////*           Time Difference                  */////

void DiffTime()
{
  struct TIME startTime, stopTime, diff;
  system("cls");
  printf("\n\n\t\t\tGet the Time difference between time period Program\n\n");
  Green();
  printf("Enter the start time. \n\n");
  white();
  printf("Enter hours, minutes and seconds: ");
  scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

  Red();
  printf("\n\nEnter the stop time. \n\n");
  white();
  printf("Enter hours, minutes and seconds: ");
  scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

  // Difference between start and stop time
  differenceBetweenTimePeriod(startTime, stopTime, &diff);
  Cyan();
  printf("\nTime Difference: %d:%d:%d - ", stopTime.hours, stopTime.minutes, stopTime.seconds);
  printf("%d:%d:%d = ", startTime.hours, startTime.minutes, startTime.seconds);
  Green();
  printf("%d:%d:%d\n\n", diff.hours, diff.minutes, diff.seconds);
  Yellow();
  printf("Do you want to continue to other program: (y/n) ");
  scanf(" %c", &c);
  if (c == 'y' || c == 'Y')
    Applications();
  else
    exit(0);
}

// Computes difference between time periods
void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff)
{
  if (start.seconds > stop.seconds)
  {
    stop.seconds += 60;
    --stop.minutes;
  }

  if (start.minutes > stop.minutes)
  {
    stop.minutes += 60;
    --stop.hours;
  }
  diff->seconds = stop.seconds - start.seconds;
  diff->minutes = stop.minutes - start.minutes;
  diff->hours = stop.hours - start.hours;
}

/////*           Decimal to Binary                  */////
void dec2bin(int n);
int bin2dec(long long n);

void decBinMenu()
{
  system("cls");
  Green();
  printf("\n\n\n\t==      1 Convert from decimal to binary\n\n");
  printf("\t==      2 Convert from binary to decimal\n\n");
  Yellow();
  printf("\t==      3 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
  c = getch();
  if (c == '1')
  {
    system("cls");
    int dec;
    printf("\n\n\n\tEnter the Decimal number: ");
    scanf("%d", &dec);
    Green();
    printf("\n\n\t%d Binary representation is = ", dec);
    dec2bin(dec);
    white();
  }
  else if (c == '2')
  {
    system("cls");
    long long bin;
    printf("\n\n\n\tEnter the Binary number: ");
    scanf("%lld", &bin);
    Green();
    printf("\n\n\t%lld Decimal representation is = %d", bin, bin2dec(bin));
  }
  printf("\n\n\t\t\t\tEnter any key to continue . . .");
  getch();
  MainMenu();
}
void dec2bin(int n)
{
  if (n == 0)
  {
    printf("0");
    return;
  }
  dec2bin(n / 2);
  printf("%d", n % 2);
}
int bin2dec(long long n)
{
  long long num = n;
  int dec_value = 0;
  // Initializing base value to 1, i.e 2^0
  int base = 1;
  long long int temp = num;
  while (temp)
  {
    int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}

/////*********************************************************/////
/////*                     Games                             */////
/////*********************************************************/////
void snake();
void GamesOption(char c);
void ScrambleWords();

void Games()
{
  system("cls");
  printf("\n\n\n");
  Cyan();
  printf("\t==      1 Snake\n\n");
  printf("\t==      2 Scramble Words\n\n");
  Yellow();
  printf("\t==      3 Back to Main Menu\n\n");
  Red();
  printf("\t==      e Exit the program\n\n");
  white();
  printf("Enter which option do you want: ");
  c = getch();
  GamesOption(c);
}
void GamesOption(char c)
{
  switch (c)
  {
  case '1':
    snake();
    return;
  case '2':
    ScrambleWords();
    return;
  case '3':
    MainMenu();
    return;
  case 'e':
  case 'E':
    ExitScreen();
  default:
    Red();
    printf("Invalid Input!\n");
    Sleep(1000);
    white();
    Games();
  }
}
// rows and columns

/////*           Snake Game                 */////
#define R 25
#define C 60
void snakeInitialization();
void printBoard();
void ResetScreenPosition();
void randomSpawner();
void RandomObstacle();
void NewObstcale();
int getCharacter();
void movement();
void updateTail();
void gameOver();
char gamemode();

int i, j, field[R][C], x, y, Gy, head, tail, game, apples, a, b, userInput, direction, score, highScore, speed = 100, Obs;
char choice;
FILE *f;

void snake()
{
  gamemode();
  snakeInitialization();

  while (~game)
  {
    printBoard();
    ResetScreenPosition();
    NewObstcale();
    randomSpawner();
    movement();
    updateTail();
    Sleep(speed);
  }
  Blue();
  printf("\n\n\tPress any Key to continue . . . ");
  white();
  getch();
  Games();
}
// creates the body of the snake
void snakeInitialization()
{
  // coordinate points for the snake which is center of the screen
  f = fopen("highScore.txt", "r");
  fscanf(f, "%d", &highScore);
  fclose(f);

  for (int i = 0; i < R; i++)
    for (int j = 0; j <= C; j++)
      field[i][j] = 0;

  x = 20;
  y = 45;
  Gy = y;
  game = apples = a = b = userInput = direction = score = Obs = 0;
  head = 5;
  tail = 1;
  speed = 100;
  direction = 'd';
  // where to print the snakes body
  for (i = 0; i < head; i++)
  {
    Gy++;
    field[x][Gy - head] = i + 1;
  }

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j <= C; j++)
    {
      if (i == 12 && j == C / 2 - 1 && choice == '3') // middle char
        field[i][j] = -3;
      else if (i == 12 && j > 5 && j < 53 && choice == '3') // middle row
        field[i][j] = -3;
      else if (j == C / 2 - 1 && i > 3 && i < 22 && choice == '3') // middle coulmn
        field[i][j] = -3;
    }
  }
}
void printBoard()
{
  // creating walls
  printf("\n");
  Red();
  for (i = 0; i <= C + 1; i++)
  {
    if (i == 0)
    {
      printf("%c", 201); // ascii code for ╔ is 201
    }
    else if (i == C + 1)
    {
      printf("%c", 187); // ascii code for ╗ is 187
    }
    else
    {
      printf("%c", 205); // ascii code for ═ is 205
    }
  }
  printf("\tCurrent Score: %d\tHigh Score: %d", score, highScore);
  printf("\n");
  for (i = 0; i < R; i++)
  {
    printf("%c", 186);
    for (j = 0; j <= C; j++)
    {
      if (j == C)
        printf("%c", 186);
      else if (i == 12 && j == C / 2 - 1 && choice == '3') // middle char
        printf("%c", 206);

      else if (i == 12 && j > 5 && j < 53 && choice == '3') // middle row
        printf("%c", 205);

      else if (j == C / 2 - 1 && i > 3 && i < 22 && choice == '3')
      { // middle coulmn
        printf("%c", 186);
      }
      else if (field[i][j] > 0 && field[i][j] != head)
      {
        Cyan();
        printf("%c", 176);
      }

      else if (field[i][j] == head)
      {
        Cyan();
        printf("%c", 178);
      }

      else if (field[i][j] == 0)
        printf(" ");

      else if (field[i][j] == -1)
      {
        Green();
        printf("0");
      }

      else if (field[i][j] == -2)
      {
        Red();
        printf("X");
      }
    }
    printf("\n");
  }
  for (i = 0; i <= C + 1; i++)
  {
    if (i == 0)
    {
      printf("%c", 200);
    }
    else if (i == C + 1)
    {
      printf("%c", 188);
    }
    else
    {
      printf("%c", 205);
    }
  }
}
void ResetScreenPosition()
{
  HANDLE hOut;
  COORD position;
  CONSOLE_CURSOR_INFO ConCurInf;
  hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  ConCurInf.dwSize = 10;
  ConCurInf.bVisible = FALSE;
  position.X = 0;
  position.Y = 0;
  // starts printing from the top left corner of screen and sets the cursor to the top left corner
  SetConsoleCursorPosition(hOut, position);
  // hides cursor
  SetConsoleCursorInfo(hOut, &ConCurInf);
}
void randomSpawner()
{
  srand(time(0));
  // generates a number from 1:18
  a = 1 + rand() % 18;
  // generates a number from 1:38
  b = 1 + rand() % 38;
  if (!apples && field[a][b] == 0)
  {
    field[a][b] = -1;
    apples = 1;
    if (speed > 10 && score != 0)
    {
      speed -= 5;
    }
  }
}
void RandomObstacle()
{
  if (choice == '2' || choice == '3')
  {
    COORD a;
    a.X = 1 + rand() % 18;
    a.Y = 1 + rand() % 38;
    field[a.X][a.Y] = -2;
  }
}
int getCharacter()
{
  if (kbhit())
  {
    return getch();
  }
  else
  {
    return -1;
  }
}
void movement()
{
  userInput = getCharacter();
  userInput = tolower(userInput);

  if ((userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd') && abs(direction - userInput) > 5)
  {
    direction = userInput;
  }
  if (direction == 'w')
  {
    x--;
    if (field[x][y] != 0 && field[x][y] != -1)
    {
      game = -1;
      gameOver();
    }
    if (x == -1 && ((choice == '3') || (choice == '2')))
    {
      game = -1;
      gameOver();
    }
    if (x == -1)
      x = R - 1;
    if (field[x][y] == -1)
    {
      apples = 0;
      score += 10;
      tail -= 2;
    }
    head++;
    field[x][y] = head;
  }
  else if (direction == 'a')
  {
    y--;
    if (y == 0 && ((choice == '3') || (choice == '2')))
    {
      game = -1;
      gameOver();
    }
    if (field[x][y] != 0 && field[x][y] != -1)
    {
      game = -1;
      gameOver();
    }
    if (y == 0)
    {
      y = C - 1;
    }
    if (field[x][y] == -1)
    {
      apples = 0;
      score += 10;
      tail -= 2;
    }
    head++;
    field[x][y] = head;
  }
  else if (direction == 's')
  {
    x++;
    if (x == R && ((choice == '3') || (choice == '2')))
    {
      game = -1;
      gameOver();
    }
    if (field[x][y] != 0 && field[x][y] != -1)
    {
      game = -1;
      gameOver();
    }
    if (x == R)
    {
      x = 0;
    }
    if (field[x][y] == -1)
    {
      apples = 0;
      score += 10;
      tail -= 2;
    }
    head++;
    field[x][y] = head;
  }
  else if (direction == 'd')
  {
    y++;
    if (y == C && ((choice == '3') || (choice == '2')))
    {
      game = -1;
      gameOver();
    }
    if (field[x][y] != 0 && field[x][y] != -1)
    {
      game = -1;
      gameOver();
    }
    if (y == C)
    {
      y = 0;
    }
    if (field[x][y] == -1)
    {
      apples = 0;
      score += 10;
      tail -= 2;
    }
    head++;
    field[x][y] = head;
  }
}
void updateTail()
{
  for (i = 0; i < R; i++)
  {
    for (j = 0; j < C; j++)
    {
      if (field[i][j] == tail)
      {
        field[i][j] = 0;
      }
    }
  }
  tail++;
}
void gameOver()
{
  system("cls");

  if (score > highScore)
  {
    Green();
    printf("\n\n\t\tNew High Score: %d!\n\n\t\t", score);
    system("pause");
    f = fopen("highScore.txt", "w");
    fprintf(f, "%d", score);
    fclose(f);
  }

  Red();
  printf("\n\n\t\tGAME OVER!");
  white();
  printf("\n\n\t\tScore: %d", score);
}
char gamemode()
{
  do
  {
    system("cls");
    printf("\n\n\n\t\t\tPlease choose game Mode:\n\n");
    Green();
    printf("\t\t\t1 Easy\n\n");
    Yellow();
    printf("\t\t\t2 Normal\n\n");
    Red();
    printf("\t\t\t3 Hard\n\n");
    white();
    choice = getch();
  } while (choice != '1' && choice != '2' && choice != '3');
  system("cls");
  return choice;
}
void NewObstcale()
{
  if (score / 50 == Obs)
  {
    RandomObstacle();
    Obs++;
  }
}

/////*           Scramble Words                 */////

int mn, mx;
char op;
void scramble(char *s);

void ScrambleWords()
{

  srand(time(NULL));
  FILE *ptr = fopen("words.txt", "r");
  char word[100];
  char words[1000][50];
another_word:
  op = gamemode();
  switch (op)
  {
  case '1':
    mn = 3;
    mx = 4;
    break;
  case '2':
    mn = 4;
    mx = 7;
    break;
  case '3':
    mn = 7;
    mx = 15;
    break;
  default:
    goto another_word;
  }
  int randN;
  for (int i = 0; i < 1000; i++)
    fscanf(ptr, "%s", words[i]);
  do
  {
    randN = rand() % 1000;
    strcpy(word, words[randN]);

  } while (strlen(word) < mn || strlen(word) > mx);
  fclose(ptr);
  char original[100];
  char scrambled[100];
  char answer[100];

  strcpy(original, word);

  strcpy(scrambled, original);
  scramble(scrambled);

  bool game_over = false;
  do
  {
    printf("Unscramble the word: %s\n\n", scrambled);
    printf("Answer: ");
    scanf("%s", answer);
    if (strcmp(answer, original) == 0)
    {
      Green();
      printf("\n\t\tYou got it Right!\n\n\t\tIt is %s\n\n", original);
      game_over = true;
    }
    else
    {
      system("cls");
      Red();
      printf("\a\a\nTry again!\n\n");
      white();
    }
  } while (!game_over);

  printf("Press any Key to continue . . . ");
  getch();
  Games();
}

void scramble(char *s)
{
  int length = strlen(s);
  for (int i = 0; i < length; i++)
    s[i] = tolower(s[i]);

  if (length == 1)
    return;

  if (length == 2)
  {
    char temp = s[0];
    s[0] = s[1];
    s[1] = temp;
    return;
  }

  char *original = (char *)malloc((length + 1) * sizeof(char));
  strcpy(original, s);

  double diff = 0;
  bool same_start = false;
  bool same_end = false;
  int times_stuck = 0;

  do
  {
    int i = 0;
    while (i < length)
    {
      int pos1 = rand() % length;
      int pos2 = rand() % length;
      if (pos1 != pos2)
      {
        char temp = s[pos1];
        s[pos1] = s[pos2];
        s[pos2] = temp;
        i++;
      }
    }

    int differences = 0;
    for (int j = 0; j < length; j++)
      if (original[j] != s[j])
        differences++;

    diff = (double)differences / length;
    same_start = s[0] == original[0];
    same_end = s[length - 1] == original[length - 1];
    times_stuck++;

  } while (((same_start && same_end) || (diff < 0.5)) && (times_stuck < 100));
}
