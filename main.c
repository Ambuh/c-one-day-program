#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
The pseudocode is written in the comments

function addRecord (string * student){
  global array add studentResults
}
function showRecords(){
  if (file !=null){
    $open=readfile();
    int $overallMark=0;
    int $studentNo=0;
    while($open !=null){

        $result=fget($open);

        $grade=computeGrade($result[cw1],$result[cw2],$result[exam]);

        $overallMark=$overallMark+grade;

        $studentNo=$studentNo+1;

        printf($result[studentName],$result[studentId],result[cw1...exam],grade);
    }
    printf("\n \n The Overall Grade %s ",($overallMark/$studentNo));
  }
}
 double grading(int cw1,int cw2,int exam){

    double $result=(cw1*0.3) + (cw2 *0.4) + (exam*0.3)

    return result;
  }
  void saveStudents(){
    if(file exits){
        delete;
    }else{
     create(f);

    for(int i=0;i<20;i++){
     write("%s \n",students[i]);
    }

    }
  }

  void modifyStudentRecord($string,$record){
    for(i=0;i<20;i++){
        split(student[i];

        if(strcompare(student['upNumber],$string)==0){
            if(strcompare(record,"firstname"){
                  $student['firstname']=0;
               }
        }
    }
  }
  void deleteStudentRecord($upnumber){
    for(i=0;i<20;i++){
        split(student[i];

        if(strcompare(student['upNumber],$upnumber)==0){
            $student[i]="";
        }
    }
  }

*/
char students[20][60];
int main()
{

    FILE * fpointer;

    fpointer=fopen("results.txt","w");

    if(fpointer !=NULL){
        fclose(fpointer);
    }

    fpointer=fopen("results.txt","r");

    char singlLine[150];
    int i=0;
    while(!feof(fpointer)){
        fgets(singlLine,150,fpointer);

        char * student=singlLine;

        strcpy(students[i],singlLine);

        i++;
    }
    fclose(fpointer);

    handleSelections();


    return 0;
}
void handleSelections(){
    /* handles what the commands that the user will enter */
     char commands[23];

     printf(" The following commands are allowed  get, add , view ,edit ,delete ,Save  \n");

     scanf("%s",commands);

    if(strcmp(commands,"get")==0){
          char id[20];
          printf("Enter the student id \n");
          scanf("%s",id);
          showSpecificStudent(id);
    }
    if(strcmp(commands,"view")==0){
         showStudentsResults();
    }
    if(strcmp(commands,"add")==0){
          char fname[20],sname[20],up[10],cw1[3],cw2[3],exam[3];

          printf("\n Enter firstname:");

          scanf("%s",fname);

          printf("Second name:");
          scanf("%s",sname);
          printf("up number:");
          scanf("%s",up);
          printf("cw1:");
          scanf("%s",cw1);
          printf("cw2:");
          scanf("%s",cw2);
          printf("Exam :");
          scanf("%s",exam);

          char  fulldetails[100]=" ";

               strcat(fulldetails,fname);
               strcat(fulldetails," ");
               strcat(fulldetails,sname);
               strcat(fulldetails," ");
               strcat(fulldetails,up);
               strcat(fulldetails," ");
               strcat(fulldetails,cw1);
               strcat(fulldetails," ");
               strcat(fulldetails,cw2);
               strcat(fulldetails," ");
               strcat(fulldetails,exam);



          for(int i=0;i<20;i++){
            if(students[i]==" "){
                strcpy(students[i],fulldetails);
            }
          }
          printf("Student %s added successfully ...",fulldetails);

    }
    if(strcmp(commands,"edit")==0){
      char studentId[10];char field[20];char value[20];

      printf("Student id :");
      scanf("%s",studentId);
      printf(" change {firstname,secondname,upnumber,cw1,cw2,exam}?");
      scanf("%s",field);
      printf("Enter new value :");
      scanf("%s",value);

      editStudentDetails(studentId,field,value);

    }
    if(strcmp(commands,"delete")==0){
        char *upId;
        printf("Enter Student id :  {this action is irreversible}");
        scanf("%s",upId);

        deleteStudent(upId);
    }
    if(strcmp(commands,"save")==0){
        saveStudentsResults();
    }



}
void addStudentResults(char results[]){
    /* add students to the current collection without saving to the text file */
    for(int i=0;i<20;i++){
        if(students[i]==""){
            strcpy(students[i],results);
            i=20;
        }
    }

    printf("Student added successfully \n \n ");

    showStudentsResults();
}
void showStudentsResults(){
/* show all students their total marks and the average student score for the year */
  double studentsTotal=0;
   for (int i=0;i<20;i++){
        char * firstname =strtok(students[i]," ");

        char * secondname=strtok(NULL," ");

        char * regid=strtok(NULL," ");

        char * cw1=strtok(NULL," ");

        char * cw2=strtok(NULL," ");

        char * examW=strtok(NULL," ");

        char * exam=strtok(examW,"\n");

       int w1=atoi(cw1);
       int w2=atoi(cw2);
       int egzam=atoi(exam);
       double total=(w1*0.3)+(w2*0.4)+(egzam*0.3);

       studentsTotal=studentsTotal+total;

       if(firstname !=NULL && secondname !=NULL  && cw1 !=NULL)
                printf(" %s %s cw1(%s) cw2(%s) exam(%s) total %i \n ",firstname,secondname,cw1,cw2,exam,total);
   }
   printf ("\n \n The average total is ",studentsTotal);
   handleSelections();
}
void showSpecificStudent(char * id){
    /*function to check for a specific student */
    FILE * fpointer;
    fpointer=fopen("results.txt","r");

    char singlLine[150];

    int status=0;
    while(!feof(fpointer)){
        fgets(singlLine,150,fpointer);

        char * student=singlLine;

        char * firstname =strtok(student," ");

        char * secondname=strtok(NULL," ");

        char * regid=strtok(NULL," ");

        char * cw1=strtok(NULL," ");

        int * cw2=strtok(NULL," ");

        char * examW=strtok(NULL," ");

        int * exam=strtok(examW,"\n");

        if(strcmp(id,regid)==0){
            printf(" %s %s cw1(%s) cw2(%s) exam(%s) total \n ",firstname,secondname,cw1,cw2,exam);
            status=1;
        }

    }
    if(status==0){
      printf("Student was not found");
    }

    fclose(fpointer);
    handleSelections();
}
void saveStudentsResults(){
    FILE * tester;

    tester=fopen("results.txt","r");

    if(tester !=NULL){
        fclose(tester);
        remove("results.txt");
    }

    FILE * fpointer;

    fpointer=fopen("results.txt","w");

    for(int i=0;i<20;i++){
        fprintf(fpointer,"\n %s",students[i]);
    }
    fclose(fpointer);

    printf("Student added succesfully");

    showStudentsResults();
}

void editStudentDetails(char * up,char * item,char * value){
    char fulldetails[100]=" ";
  for(int i=0;i<20;i++){
        char * firstname =strtok(students[i]," ");

        char * secondname=strtok(NULL," ");

        char * regid=strtok(NULL," ");

        char * cw1=strtok(NULL," ");

        int * cw2=strtok(NULL," ");

        char * examW=strtok(NULL," ");

        int * exam=strtok(examW,"\n");

        if(strcmp(up,regid)==0){
             if(strcmp("firstname",item)==0){
                firstname=value;
             }
             if(strcmp("secondname",item)==0)
                secondname=value;
             if(strcmp("upnumber",item)==0)
               regid=value;
             if(strcmp("cw1",item)==0)
               cw1=value;
             if(strcmp("cw2",item)==0)
               cw2=value;
             if(strcmp("exam",item)==0)
               exam=value;

               strcat(fulldetails,firstname);
               strcat(fulldetails," ");
               strcat(fulldetails,secondname);
               strcat(fulldetails," ");
               strcat(fulldetails,regid);
               strcat(fulldetails," ");
               strcat(fulldetails,cw1);
               strcat(fulldetails," ");
               strcat(fulldetails,cw2);
               strcat(fulldetails," ");
               strcat(fulldetails,exam);
               strcpy(students[i],fulldetails);
        }
  }
  handleSelections();
}
void  deleteStudent(char * id){
 for(int i=0;i<20;i++){
        char * firstname =strtok(students[i]," ");

        char * secondname=strtok(NULL," ");

        char * regid=strtok(NULL," ");

        char * cw1=strtok(NULL," ");

        int * cw2=strtok(NULL," ");

        char * examW=strtok(NULL," ");

        int * exam=strtok(examW,"\n");

        if(strcmp(id,regid)==0){
              strcpy(students[i]," ");
        }
  }
 handleSelections();
}
