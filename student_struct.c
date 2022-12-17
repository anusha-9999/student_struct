#include<stdio.h>   
#include<string.h>
#include<dos.h>
/*Anusha Upadhyay
Section-E
Program of Student Managment*/
//Student strucutre
struct student {
	char name[15];
	int rollno;
	int phy;
	int chem;
	int math;
} stud[10];

int i,num,c,j,total,s;
int per;
void main() {
	do {
		system("cls");
		printf("\t\t\t\t\t\tStudent Managment System\n");
		printf("\n\t\t\t\t\t=============================================\n");
		printf("\t\t\t\t\t\tChoose:\n");
		printf("\t\t\t\t\t\t0)Add student record\n");
		printf("\t\t\t\t\t\t1)To sort student names\n");
		printf("\t\t\t\t\t\t2)To sort student roll numbers\n");
		printf("\t\t\t\t\t\t3)To display report cards\n");
		printf("\t\t\t\t\t\t4)To search student record\n");
		printf("\t\t\t\t\t\t5)To exit\n");
		printf("\t\t\t\t\t=============================================\n");
		scanf("%d",&c);
		switch(c) {
			case 0:
				input_data();
				break;
			case 1:
				printf("\n\n\t\t\t------------------SORT BY NAMES------------------\n");
				sort();
				display();
				break;
			case 2:
				printf("\n\n\t\t\t------------------SORT BY ROLL NUMBER------------------\n");
				sort();
				display();
				break;
			case 3:
				printf("\n\n\t\t\t------------------REPORT CARD------------------\n\n");
				repo();
				break;
			case 4:
				printf("\n\n\t\t\t------------------SEARCH STUDENT RECORD BY NAME OR ROLL NUMBER------------------\n\n");
				printf("Choose\n1)Search by name\n\n2)Search by Roll number: ");
				scanf("%d",&s);
				search();
				break;
			case 5:
				printf("\n\nProgram Exited!");
				system("exit");
				break;
			default:
				printf("INVALID INPUT");
				getch();
				break;
		}
	} while(c!=5);
}
void sort() {
	struct student temp;
	for(i=0; i<num; i++) {
		for(j=i+1; j<num; j++) {
			//-----Sorting of names---------------
			if(c==1) {
				if(strcmp(stud[i].name,stud[j].name)>0) {
					temp=stud[i];
					stud[i]=stud[j];
					stud[j]=temp;
				}
			}
			//------------Sorting of roll numbers--------
			if(c==2) {
				if(stud[i].rollno>stud[j].rollno) {
					temp=stud[i];
					stud[i]=stud[j];
					stud[j]=temp;
				}
			}
		}
	}
}
//--------Report card----
void repo() {

	for(i=1; i<num; i++) {
		printf("\n\n\t\t\t\t==========================================================================\t\t\t\t\n");
		printf("\t\t\t\tName: %s  \t\t\t\tRoll Number: %d\n",stud[i].name,stud[i].rollno);
		printf("\t\t\t\t--------------------------------------------------------------------------\t\t\t\t");
		printf("\n\t\t\t\tSubjects:\t\t\t\t\t\t\t Marks: \n ");
		printf("\n\t\t\t\tPhysics:\t\t\t\t\t\t\t %d",stud[i].phy);
		printf("\n\t\t\t\tChemistry:\t\t\t\t\t\t\t %d",stud[i].chem);
		printf("\n\t\t\t\tMathematics:\t\t\t\t\t\t\t %d\n\n",stud[i].math);
		printf("\t\t\t\t--------------------------------------------------------------------------\t\t\t\t");
		total=stud[i].phy+stud[i].chem+stud[i].math;
		per=(total*100)/240; 		
		printf("\n\t\t\t\tTotal Marks: %d/240\t\t\ Percentage: %d",total,per);
		if(per<100 && per>55) {
			printf("\n\n\t\t\t\tStatus: Pass");
			printf("\n\t\t\t\t\t\t\tCongo! You passed the exam ");
		} else {
			printf("\n\n\t\t\t\tStatus: Fail");
			printf("\n\t\t\t\t\t\t\tBetter Luck next time! ");
		}
		printf("\n\n\t\t\t\t==========================================================================\t\t\t\t\n");
	}
	printf("Press any key to continue...");
	getch();
}
//---------------Record Display----------
void display() {

	for(i=0; i<num; i++) {
		if(c==1||c==2) {

			printf("\n\n\t\t\t\t==========================================================================\t\t\t\t\n");
			printf("\t\t\t\tName: %s  \t\t\t\tRoll Number: %d\n",stud[i].name,stud[i].rollno);
			printf("\t\t\t\t--------------------------------------------------------------------------\t\t\t\t");

		}
	}
	printf("Press any key to continue...");
	getch();
}

//---------------Record Search----------
void search() {
	int rn;
	char sn[15];
	switch(s) {
		case 1:
			printf("Enter Student name: ");
			scanf("%s",&sn);
			for(i=0; i<=num; i++) {

				if(strcmp(sn,stud[i].name) == 0) {

					printf("\n\n\t\t\t\t==========================================================================\t\t\t\t\n");
					printf("\t\t\t\tName: %s  \t\t\t\tRoll Number: %d\n",stud[i].name,stud[i].rollno);
					printf("\t\t\t\t--------------------------------------------------------------------------\t\t\t\t");
					printf("\n\t\t\t\tSubjects:\t\t\t\t\t\t\t Marks: \n ");
					printf("\n\t\t\t\tPhysics:\t\t\t\t\t\t\t %d",stud[i].phy);
					printf("\n\t\t\t\tChemistry:\t\t\t\t\t\t\t %d",stud[i].chem);
					printf("\n\t\t\t\tMathematics:\t\t\t\t\t\t\t %d\n\n",stud[i].math);
					break;
				}
			}
			if(!strcmp(sn,stud[i].name) == 0) {
				printf("\n\nNO RECORD FOUND!\n\n");
			}
			break;
		case 2:
			printf("Enter Student Roll number: ");
			scanf("%d",&rn);
			for(i=0; i<num; i++) {
				if(rn==stud[i].rollno) {
					printf("\n\n\t\t\t\t==========================================================================\t\t\t\t\n");
					printf("\t\t\t\tName: %s  \t\t\t\tRoll Number: %d\n",stud[i].name,stud[i].rollno);
					printf("\t\t\t\t--------------------------------------------------------------------------\t\t\t\t");
					printf("\n\t\t\t\tSubjects:\t\t\t\t\t\t\t Marks: \n ");
					printf("\n\t\t\t\tPhysics:\t\t\t\t\t\t\t %d",stud[i].phy);
					printf("\n\t\t\t\tChemistry:\t\t\t\t\t\t\t %d",stud[i].chem);
					printf("\n\t\t\t\tMathematics:\t\t\t\t\t\t\t %d\n\n",stud[i].math);
					break;
				}
			}
			if(!(rn==stud[i].rollno)) {
				printf("\n\nNO RECORD FOUND!\n\n");
			}
			break;		
	}
	printf("Press any key to continue...");
	getch();
}
void input_data() {
	system("cls");
	printf("Enter number of students: ");
	scanf("%d",&num);
	for(i=0; i<num; i++) {
		fflush(stdin);
		printf("\n\nEnter student %d Name: ",(i+1));
		fflush(stdin);
		gets(stud[i].name);
		printf("Enter student %d Roll Number: ",(i+1));
		scanf("%d",&stud[i].rollno);
		printf("Enter student %d physics marks: ",(i+1));
		scanf("%d",&stud[i].phy);
		printf("Enter student %d chemistry marks: ",(i+1));
		scanf("%d",&stud[i].chem);
		printf("Enter student %d maths marks: ",(i+1));
		scanf("%d",&stud[i].math);
	}
	printf("\n\nData added successfully...");
	printf("\n\n\nPress any key to continue...");
	getch();


}


