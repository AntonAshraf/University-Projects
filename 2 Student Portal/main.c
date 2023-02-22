#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define Computer 1
#define Electric 2
#define Communication 3

int comp, comm, elec, N;
char op;
void option (char o);
void Menu();
void add_student();
void student_data ();
void numberofstudents();
void GPA_Grades_Menu();
void Top_student();
void Top_student_in_semester ();
void Top_student_in_Course ();
void read_previous_data();
void read_our_File();
void END_program();
void Start_screen();
void Array2D() ;

struct course {
  int term;
  char name[30];
  float grade;
};

struct info {
  char Name[30];
  char Depatment[20];
  int ID;
  int semester;
  float GPA;
  int ncources;
  struct course subject[10];
} student[100];


FILE *R;
FILE *STnum;


int main () {

   read_our_File();

  while (1) {
    Menu();
    char o;
    scanf(" %c",&o);
    option(o);
  }


  STnum = fopen("STnum.txt","w");
  fprintf(STnum, "%d",N);
  fclose(STnum);

  return 0;
}


void Menu() {
  system ("cls");
  printf ("\n\n\n\t\t< 1 > Add new student.\n\n");
  printf ("\t\t< 2 > Preview student Data.\n\n");
  printf ("\t\t< 3 > Numbers of students.\n\n");
  printf ("\t\t< 4 > GPA & Grades.\n\n");
  printf ("\t\t< e > Exit.\n\n");
  printf ("\t\tEnter option you want: ");
}

void option (char o) {
  switch (o){
  case '1':
    add_student();
    break;
  case '2':
    student_data();
    break;
  case '3':
    numberofstudents();
    break;
  case '4':
    GPA_Grades_Menu();
    break;
  case 'e':
  case 'E':
    END_program();
    break;
  default:
    printf ("Invalid Input!\n");
    Sleep(1000);
    return ;
  }
}

void numberofstudents() {
  system ("cls");
  printf ("\n\n\t\t< 1 > Total number of students.\n\n");
  printf ("\t\t< 2 > Students in Computer.\n\n");
  printf ("\t\t< 3 > Students in Communication.\n\n");
  printf ("\t\t< 4 > Students in Electric.\n\n");
  printf ("\t\t< e > Exit.\n\n");
  printf ("\t\tEnter option you want: ");
  scanf(" %c", &op);
  switch (op){
  case '1':
    printf("\n\t\tTotal number of students = %d", N);
    break;
  case '2':
    printf("\n\t\tNumber of students in Computer = %d", comp);
    break;
  case '3':
    printf("\n\t\tNumber of students in Communication = %d", comm);
    break;
  case '4':
    printf("\n\t\tNumber of students in Electric = %d", elec);
    break;
  case 'e':
  case 'E':
    END_program();
    break;
  default:
    break;
  }
  getch();
}

void GPA_Grades_Menu() {
  start:
  system("cls");
  printf ("\n\n\t\t< 1 > Highest student's GPA in the university.\n\n");
  printf ("\t\t< 2 > Highest GPA in specific semester.\n\n");
  printf ("\t\t< 3 > Highest Grade in specific Course.\n\n");
  printf ("\t\t< e > Exit.\n\n\n");
  printf ("\t\tEnter option you want: ");
  scanf(" %c", &op);
  switch (op){
  case '1':
    Top_student();
    break;
  case '2':
    Top_student_in_semester();
    break;
  case '3':
    Top_student_in_Course();
    break;
  case 'e':
  case 'E':
    END_program();
    break;
  default:
    printf("Invalid Input");
    Sleep(1000);
    goto start;
    break;
  }
}

void Top_student() {
  system("cls");
  if (N == 0) {
    printf("\n\n\n\t\tNo student found");
    getch();
    Menu();
    return;
  }
  float mx = student[0].GPA;
  int st = 0;
  for (int i = 0; i < N; i++){
    if (mx < student[i].GPA){
      mx = student[i].GPA;
      st = i;
    }
  }
  printf("\n\n\n\tHighest student's GPA in the university is %s with\tID: %d\t GPA %.2f", student[st].Name
                                                                                        , student[st].ID
                                                                                        , student[st].GPA);
  getch();
  Menu();
}

void Top_student_in_semester () {
  system("cls");

  int term;
  int flag = 0;
  int mx;
  int st;
  printf("\n\n\n\t\tEnter student semester: ");
  scanf("%d",&term);
  for (int i = 0; i < N; i++)
  {
    if (student[i].semester == term) {
      if (flag == 0) {
        mx = student[i].GPA;
        flag = 1;
        st = i;
        continue;
      }
      if (mx < student[i].GPA) {
        mx = student [i].GPA;
        st = i;
      }
    }
  }
  if (flag == 0) {
    printf("\n\n\n\t\tNo student found in this semseter");
    getch();
    Menu();
    return;
  }
  printf("\n\n\t\t\t The Highest student in Semster %d is %s with\tID: %d\t GPA %.2f", term
                                                                                     , student[st].Name
                                                                                     , student[st].ID
                                                                                     , student[st].GPA);
  getch();
  Menu();
}
void Top_student_in_Course () {
  system("cls");
  printf("\n\n\nPlease enter course details\n\n");
  char name[30];
  int term;
  int st = 0;
  int nsub;
  int flag = 1;
  float mx = 0;
  printf("\t\tName: ");
  scanf(" %[^\n]",name);
  printf("\n\t\tSemster: ");
  scanf("%d",&term);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < student[i].ncources; j++){
      if(student[i].subject[j].term == term){
        if (!strcmp(student[i].subject[j].name,name))
          if (flag) {
            mx = student[i].subject[j].grade;
            flag = 0;
            st = i;
            nsub = j;
            continue;
          }
          if (mx < student[i].subject[j].grade){
            mx = student[i].subject[j].grade;
            st = i;
            nsub = j;
          }
      }
    }
  }
  if (flag == 1) {
    printf("\n\n\n\t\tNo student found in this course!");
    getch();
    Menu();
    return;
  }
  printf("\n\n\t\t\t The Highest student in course %s is %s with\tID: %d\t Grade %.2f", name
                                                                                      , student[st].Name
                                                                                      , student[st].ID
                                                                                      , student[st].subject[nsub].grade);
  getch();
  Menu();
}



void add_student() {
  system("cls");
  R = fopen("Data.txt","a");
  STnum = fopen ("STnum.txt", "w");
    printf("\n\n\n\tEnter Student Details\n\n");

    printf("\tStudent Name: ");
    scanf(" %[^\n]",student[N].Name);
    fprintf(R,"%s\n",student[N].Name);

    printf("\tStudent ID: ");
    scanf(" %d",&student[N].ID);
    fprintf(R,"%d\n",student[N].ID);

    printf("\n\t1 Computer \n\t2 Electric \n\t3 Communication \n\n");
    printf("\tWhich Department: ");
    int d;
    scanf("%d",&d);
    if (d == 1){
      strcpy(student[N].Depatment,"Computer");
      fprintf(R,"Computer\n");
      comp++;
    } else if (d == 2) {
            fprintf(R,"Electric\n");
      strcpy(student[N].Depatment,"Electric");
      elec++;
    }else if (d == 3){
      comm++;
      fprintf(R,"Communication\n");
      strcpy(student[N].Depatment,"Communication");
    } 

    printf("\n\tStudent Semster: ");
    scanf("%d",&student[N].semester);
    fprintf(R,"%d\n",student[N].semester);

    printf("\tStudent GPA: ");
    scanf("%f",&student[N].GPA);
    fprintf(R,"%f\n", student[N].GPA);

    printf("\tHow many subject student take: ");
    scanf("%d",&student[N].ncources);
    int x = student[N].ncources;
    fprintf(R,"%d\n",x);

    for (int i = 0; i < x; i++){
    printf("\tSubject number %d:\n", i+1);
    printf("\tName: ");
    scanf(" %[^\n]",student[N].subject[i].name);
    fprintf(R,"%s\n",student[N].subject[i].name);

    printf("\tSemster: ");
    scanf("%d",&student[N].subject[i].term);
    fprintf(R,"%d\n",student[N].subject[i].term);
    printf("\tgrade: ");
    scanf("%f",&student[N].subject[i].grade);
    fprintf(R,"%f\n",student[N].subject[i].grade);
    }

    N++;
  fprintf(STnum,"%d",N);
  fclose(STnum);
  fclose(R);
}

void student_data () {
  system("cls");
  printf("\n\n\t\tEnter Student ID: ");
  int x;
  int found = 0;
  scanf("%d", &x);
  for (int i = 0; i < N; i++){
    if (x == student[i].ID){
      printf("\n\n\n\t\t\tName: %s\n\n", student[i].Name);
      printf("\t\t\tDepatment: %s\n\n", student[i].Depatment);
      printf("\t\t\tsemester: %d\n\n", student[i].semester);
      printf("\t\t\tGPA: %.2f\n\n", student[i].GPA);
      int n = student[i].ncources;
      for (int j = 0; j < n; j++){
        printf("\t\t\tName: %s\t",student[i].subject[j].name);
        printf("Semster: %d\t",student[i].subject[j].term);
        printf("Grade: %.2f\n\n",student[i].subject[j].grade);
      }
      found = 1;
    }
  }
  if (!found)
    printf("\n\n\n\t\t\tNOT Found!");
  getch();
}

void read_our_File() {

  STnum = fopen("STnum.txt","r");
  if (STnum == NULL) {
    printf("Error 404\nn File not found");
    return;
  }
  fscanf(STnum,"%d",&N);
  fclose(STnum);

  R = fopen("Data.txt","r");
  if (R == NULL){
    printf("Error 404\nData File not found");
    return;
  }
  for (int i = 0; i < N ;i ++){
    fscanf(R," %[^\n] %d %[^\n] %d %f %d", student[i].Name
                                         , &student[i].ID
                                         , &student[i].Depatment
                                         , &student[i].semester
                                         , &student[i].GPA
                                         , &student[i].ncources);

    for (int j = 0; j < student[i].ncources; j++){
    fscanf(R," %[^\n] %d %f", student[i].subject[j].name
                            , &student[i].subject[j].term
                            , &student[i].subject[j].grade);
    }
  }
  fclose(R);

}

void END_program() {

  exit(0);
}
