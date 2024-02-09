#include<stdio.h>
#include<stdlib.h>

/*Name: Anandapadmanabhan.B 
Batch: S3 CS-2, Roll No. 15,
Linear Search On Array of Structures*/

typedef struct
{
    char Name[15];
    int EmpId;
    int Salary;
}emp;

void LinearSearch(emp* array,int length, int empid);

int main(){
    int n;//No.of employees
    emp *array;//array of structures
    printf("\n--:Linear Search On Array of Structures:-- \n");
    printf("Enter the number of Employees: ");
    scanf("%d", &n);
    //Allocating the required memory
    array = (emp*)calloc(n, sizeof(emp));
    int i = 0;
    for(i=0; i<n; i++){
        printf("\nEmployee %d", i+1);
        printf("\nName: ");
        scanf("%s", &array[i].Name);
        printf("EmpId: ");
        scanf("%d", &array[i].EmpId);
        printf("Salary: ");
        scanf("%d", &array[i].Salary);
    }
    printf("Data Stored.....");
    int idx; //EmpId to be searched
    while(idx != -1){
        printf("\nEnter the EmpId to be Searched(-1 to Exit): ");
        scanf("%d", &idx);
        LinearSearch(array, n, idx);
    }
    free(array);
    return 0;
}

void LinearSearch(emp* array,int length, int empid){
    int i = 0;
    for(i; i<length; i++){
        if(array[i].EmpId == empid){
            printf("\nEmployee Found with Empid : %d",array[i].EmpId);
            printf("\nName: %s", array[i].Name);
            printf("\nSalary: %d\n", array[i].Salary);
            break;
        }
    }
    if(i == length){
        printf("EmpId is NOT FOUND....");
    }
}