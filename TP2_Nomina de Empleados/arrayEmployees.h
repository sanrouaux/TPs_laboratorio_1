
struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef sEmployee;


int initEmployees(sEmployee[], int);
int addEmployee(sEmployee[], int, int, char[], char[], float, int);
int findEmployeeById(sEmployee[], int, int);
int removeEmployee(sEmployee[], int, int);
int printEmployees(sEmployee[], int);
int modifyEmployee(sEmployee[], int, int);
int sortEmployees(sEmployee[], int, int);
