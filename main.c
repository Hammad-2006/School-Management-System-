#include <stdio.h> 
#include <ctype.h>
#include <string.h>


void Take_Admission();
void display();
void search();
void searchByRoll();
void searchByName();
void Modify();  
void del();    

struct student {

   char name[50];
   char father_name[50];
   char subj1[50];
   char subj2[50];
   char subj3[50];
   int rl;

} x;

FILE *fp;
long ez = sizeof(x);




 
int main(){ 
   int n;
   char z;
   int a=0;
   //do {
   printf("**************************************\n");
   printf("*                                    *\n");
   printf("*     SCHOOL MANAGEMENT SYSTEM       *\n");
   printf("*                                    *\n");
   printf("**************************************\n");

   printf("\n 1. Take Admission");
   printf("\n 2. Student Info");
   printf("\n 3. Search");
   printf("\n 4. Modify");
   printf("\n 5. Delete");
   
   printf("\n 0. Exit");  
   printf("\nSelect an Option: ");
   scanf("%d", &n);

   switch (n){
      case 0:
      printf("Exiting the programm......");
      return 0;
      break;
      case 1 :
      Take_Admission(); 
      break;
      case 2 : 
      display();
      break;

      case 3:
      search();
      break;

      case 4 :
      Modify();
      break;

      case 5:
      del();
      break;

      default:
      printf("Enter Correct Option");
   }
   // printf ("\n\nBack to main Menu.... (y/n)\n");
   // fflush(stdin);
   // scanf("%c", &z);
//    if (z == 'y'){
//       a =1;
//    }
//    else {
//       printf("Exiting the programm......");
//       return 0;
//    }
// }while (a==1);
   return 0;
}








void Take_Admission(){

   // Note: in order to make a file and store struct in a file first we have to open a file and apend
   //it wit "ab" and then we have to write the print and scanf/fgets and then write the struct control var (x)
   // in fwrite , we have to write in file 


   fp = fopen ("Student_data.txt", "a");


   // for(int i=0; i<9; i++){
   //    for(int j=0; j==i; j++){

   //       printf("*");
   //    }
   //    printf("\n");
   // }
   printf("Enter Student Name: ");
   while (getchar() != '\n'); // Used this to empty the input buffer
   //fflush(stdin); // can use but not recomend
   fgets(x.name, sizeof(x.name), stdin);
   x.name[strcspn(x.name, "\n")] = '\0';

   printf ("Enter Father Name: ");
   fflush(stdin);
   //while (getchar() != '\n');
   fgets(x.father_name, sizeof(x.father_name), stdin);
   x.father_name[strcspn(x.father_name, "\n")] = '\0';

   printf("Enter Subject Choice 1:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj1, sizeof(x.subj1), stdin);
   x.subj1[strcspn(x.subj1, "\n")] = '\0';

   printf("Enter Subject Choice 2:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj2, sizeof(x.subj2), stdin);
   x.subj2[strcspn(x.subj2, "\n")] = '\0';

   printf("Enter Subject Choice 3:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj3, sizeof(x.subj3), stdin);
   x.subj3[strcspn(x.subj3, "\n")] = '\0';

   printf("Enter Roll No.(Must be of positive integers) : ");
   scanf("%d", &x.rl);
   while (getchar() != '\n'); 

   fwrite (&x, ez, 1, fp);
   //fprintf(fp, "%s %s %s \n", x.father_name, x.name, x.subj1 );
   printf("Record Saved Successfully.. ");
   fclose(fp); 



}  


void display(){


   //system("cls");
   printf("== Student Info ==\n ");
   fp = fopen ("Student_data.txt", "r");
   if (fp ==NULL){
      printf("Data not entered");
   }
   // if  (fread (&x, ez, 1, fp)< 1){
   //    printf("Data Not Entered Yet....");
   // }
   else {
      fp = fopen ("Student_data.txt", "r");
      
      printf("%-20s | %-20s | %-30s | %-30s | %-30s | %-6s\n" , "Full Name", "Father Name", "subject 1", "subject 2","subject 3", "roll" );
      printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
      //fprintf(fp,"%-50s %-30s %-20s %-10s %-5s %s ", "Full Name", "Father Name", "subject 1", "subject 2","subject 3", "roll" );
      

      while (fread (&x, ez, 1, fp) ==1 ){
      printf(" %-20s | %-20s | %-30s | %-30s | %-30s | %-6d\n", x.name, x.father_name, x.subj1, x.subj2,x.subj3, x.rl);
   }
   fclose(fp);
   
   }

      


   
}


void search(){
   fp = fopen("Student_data.txt", "r");
   
   int num;
   int roll;
   char name[55];
   
   
   printf("<== Serach ==> \n");
   printf("1. Search by Roll No. \n");
   printf("2. Search by Name \n");
   printf("0. Back to main menu \n");
   printf("Choose an Option: \n");
   scanf("%d", &num);

   
   
   switch(num){

      case 0:
         main();
      case 1:
         searchByRoll();
         break;
      case 2:
         searchByName();
         break;
      default:
      printf("Enter Correct Choice");
      break;

      

   }

   
   
   
}


void searchByRoll(){
   int Roll_No;
   int f=0;
   
   
      printf("Enter Roll No.: ");
      scanf("%d", &Roll_No);

      
      printf("%-20s | %-20s | %-30s | %-30s | %-30s | %-6s\n" , "Full Name", "Father Name", "subject 1", "subject 2","subject 3", "roll" );
      printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
      while (fread (&x, ez, 1, fp) ==1 ){
         if (Roll_No == x.rl)
         {
         f=1;
         printf(" %-20s | %-20s | %-30s | %-30s | %-30s | %-6d\n", x.name, x.father_name, x.subj1, x.subj2,x.subj3, x.rl);
         break;
         }

   }
   fclose(fp);
   if (f==0){
      printf("Record Not Found\n");
   }
   
   }
   

void searchByName(){
   char name1[55];
   int f=0;


   printf("Enter Name: ");
   //gets(&name1, sizeof(name1), FILE *restrict File)
   fflush(stdin);
   gets(name1);

   
   while (fread(&x, ez, 1, fp) ==1){
      printf("%-20s | %-20s | %-30s | %-30s | %-30s | %-6s\n" , "Full Name", "Father Name", "subject 1", "subject 2","subject 3", "roll" );
      printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
      if (strcmp(x.name, name1) == 1)
      //if (name1 == x.name)
      {
         f=1;
         printf(" %-20s | %-20s | %-30s | %-30s | %-30s | %-6d\n", x.name, x.father_name, x.subj1, x.subj2,x.subj3, x.rl);
         
         
      }
      break;
   }
   fclose(fp);

   
   if (f==0){
      printf("Record Not Found \n");
   }
   else {
      printf("Record Found Successfully");
   }
   
   }
   
void Modify(){
   int Roll_no;
   int f=0;
   fp = fopen ("Student_data.txt" ,"r+" );
   printf ("Enter Roll No.: ");
   scanf("%d", &Roll_no);

   while (fread(&x, ez, 1, fp) ==1){
      //printf("%-20s | %-20s | %-30s | %-30s | %-30s | %-6s\n" , "Full Name", "Father Name", "subject 1", "subject 2","subject 3", "roll" );
      //printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
      if (Roll_no == x.rl){
         f=1;
      
      printf("Enter New Student Name: ");
   while (getchar() != '\n'); // Used this to empty the input buffer
   //fflush(stdin); // can use but not recomend
   fgets(x.name, sizeof(x.name), stdin);
   x.name[strcspn(x.name, "\n")] = '\0';

   printf ("Enter New Father Name: ");
   fflush(stdin);
   //while (getchar() != '\n');
   fgets(x.father_name, sizeof(x.father_name), stdin);
   x.father_name[strcspn(x.father_name, "\n")] = '\0';

   printf("Enter New Subject Choice 1:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj1, sizeof(x.subj1), stdin);
   x.subj1[strcspn(x.subj1, "\n")] = '\0';

   printf("Enter New Subject Choice 2:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj2, sizeof(x.subj2), stdin);
   x.subj2[strcspn(x.subj2, "\n")] = '\0';

   printf("Enter New Subject Choice 3:  ");
   fflush(stdin); 
   //while (getchar() != '\n');
   fgets(x.subj3, sizeof(x.subj3), stdin);
   x.subj3[strcspn(x.subj3, "\n")] = '\0';

   printf("Enter New Roll No.: ");
   scanf("%d", &x.rl);
   while (getchar() != '\n'); 
      fseek(fp, -ez, 1);
   fwrite (&x, ez, 1, fp);
   //fprintf(fp, "%s %s %s \n", x.father_name, x.name, x.subj1 );
   printf(" Record Updated Successfully.. ");
   fclose(fp); 
   break;    
         
   }


}
if (f==0){
   printf("Record Not Found..");
}


}


void del(){
   int Roll_no1;
   int f=0;
   
   printf ("Enter Roll No.: ");
   scanf("%d", &Roll_no1);
   FILE *newfp;
   fp = fopen ("Student_data.txt" ,"rb" );
   if (fp == NULL) {
      printf("Could not open file for reading.\n");
      return;
   }
   newfp = fopen ("Student_data_temp.txt" ,"wb" );
   if (newfp == NULL) {
      printf("Could not open temp file for writing.\n");
      fclose(fp);
      return;
   }

   while (fread(&x, ez, 1, fp) == 1){
      if (Roll_no1 == x.rl) {
         f = 1;
         
      } else {
         fwrite(&x, ez, 1, newfp);
      }
   }
   fclose(fp);
   fclose(newfp);
   if (f == 0){
      printf("Record Not Found ");
      remove("Student_data_temp.txt");
   }
   else {
      remove("Student_data.txt");
      rename("Student_data_temp.txt", "Student_data.txt");
      printf("Record Deleted Successfully");
   }
}