#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void doctor(char[],int);
void tech(char[],int);
void mergesort(int,int);
void merge(int,int,int);
void screen();
void pat();
void doc();
char book();
int timing();
void sort(int);
void med();
void  lab();
struct patient{
    char name[20];
    int time;
    struct patient *next;
}*first=NULL,*first1=NULL;
struct tree{
    char dr[100];
    struct tree *left;
    struct tree *right;
}*root,*p,*test,*blood,*sugar,*check;
int g[10]={0},b[10]={0},z[10]={0},a[20]={0};
void main()
{
   
   screen();
   getch();
}
void screen(){
  int choice;
  printf("\t\t*****************************************\n");
  printf("\t\t\tWelcome to Bhargav Hospital\n");
   printf("\t\t*****************************************\n\n\n");
  printf("\t\t1.PATIENT");
  printf("\n\t\t2.DOCTOR");
  printf("\n\t\t3.LAB TECHNICIAN");
  printf("\n\t\t4.PHARMACIST");
  printf("\n\t\t0.EXIT");
  printf("\n\n\tEnter your choice: ");
  scanf("%d",&choice);
switch(choice)
{
    case 1:
	    pat();
	    break;
    case 2:
	    doc();
	    break;
    case 3:
	    lab();
	    break;
    case 4:
	    med();
	    break;
    case 0:
	    exit(1);
}
}
void pat(){
    static int i=0;
    int n,m;
    char xyz[20];
    char choice;
    int ch;
  struct patient *r,*s,*p,*q;
    printf("\n\t\t1.BOOK APPOINTMENT");
    printf("\n\t\t0.EXIT\t");
    printf("\n\tEnter your choice:");
    scanf("%d",&n);
    if(n==1){
	choice=book();
	if(choice=='g'){
	ch=timing();
	if(g[ch]==0)
	g[ch]=1;
	else{
	  printf("\t\t***Already Booked.Select another slot.***\n");
	  ch=timing();
	  g[ch]=1;
	}
	printf("Do you want to buy prescription?(Enter 1:Yes 2:No):");
	scanf("%d",&m);
	if(m==1){
	a[i]=ch;
	i++;
	sort(i);
	}
	printf("Enter your name: ");
	scanf("%s",xyz);
	doctor(xyz,ch);
	printf("\n\t\tYour appointment is booked\n\t\t\tThank You!! :)\n");
	screen();
	}
	else{
	ch=timing();
	if(b[ch]==0)
	b[ch]=1;
	else{
	  printf("\t\tAlready Booked.Select another slot.\n");
	  ch=timing();
	  b[ch]=1;
	}
	   printf("Enter your name:");
	   scanf("%s",xyz);
	   tech(xyz,ch);
	   printf("\n\t\tYour slot is Booked.\n\t\tThank You:)\n");
	   screen();
	}
	}
	else
	    exit(1);
}
void doctor(char xyz[20],int ch){
   struct patient *p,*q;
   p=(struct patient*)malloc(sizeof(struct patient*));
   q=(struct patient*)malloc(sizeof(struct patient*));
   p->next=NULL;
   p->time=ch;
   strcpy(p->name,xyz);
   if(first==NULL){
      first=p;
      p->next=NULL;
      }
   else{
      q=first;
      while(q->next!=NULL){
	q=q->next;
	}
	q->next=p;
	}
    }
void tech(char xyz[20],int ch){
   struct patient *p,*q;
   p=(struct patient*)malloc(sizeof(struct patient*));
   q=(struct patient*)malloc(sizeof(struct patient*));
   p->next=NULL;
   p->time=ch;
   strcpy(p->name,xyz);
   if(first1==NULL){
      first1=p;
      p->next=NULL;
      }
   else{
      q=first1;
      while(q->next!=NULL){
	q=q->next;
	}
	q->next=p;
	}
    }
void doc(){
    struct patient *p;
    p=first;
   printf("\nList of patients for todays appointment:\n");
    while(p!=NULL){
	   printf("\t->%s\n",p->name);
	   p=p->next;
	   }
	   screen();
}
char book(){
    int n,m;
    strcpy(root->dr,"surya");
    test=(struct tree*)malloc(sizeof(struct tree));
    strcpy(test->dr,"1.Test");
    root->left=test;
    blood=(struct tree*)malloc(sizeof(struct tree));
    strcpy(blood->dr,"1.Bloodtest");
    test->left=blood;
    sugar=(struct tree*)malloc(sizeof(struct tree));
    strcpy(sugar->dr,"2.Sugartest");
    test->right=sugar;
    check=(struct tree*)malloc(sizeof(struct tree));
    strcpy(check->dr,"2.Checkup");
    root->right=check;
    p=root;
    printf("\t\t%s\n\t\t%s\n",p->left->dr,p->right->dr);
    printf("\tSelect your option(1 or 2):");
    scanf("%d",&n);
    if(n==2){
	 return 'g';
	 }
    else{
	p=p->left;
	 printf("\n\t\t%s\n\t\t%s\n",p->left->dr,p->right->dr);
	 printf("\tSelect your option(1 or 2):");
	 scanf("%d",&m);
	 if(m==1)
	   return 'b';
	  else
	      return 's';
    }

}
int timing(){
  char choice;
  printf("\n\t\tSelect your slot:\n");
  printf("\n\t1)->9am-10am");
  printf("\n\t2)->10am-11am");
  printf("\n\t3)->11am-12pm");
  printf("\n\t4)->12pm-1pm");
  printf("\n\t5)->1pm-2pm");
  printf("\n\t6)->2pm-3pm");
  printf("\n\t7)->3pm-4pm");
  printf("\n\t8)->4pm-5pm");
  printf("\n\t9)->5pm-6pm");
  printf("\n\n\tEnter your choice: ");
  scanf("%d",&choice);
  return choice;
}
void sort(int n){
      int  l,r,i;
     l=0;
     r=n-1;
     mergesort(l,r);
}
void med(){
   int i;
   printf("Allotted slot number for medicine:\n");
   for(i=0;i<(sizeof(a)/sizeof(int));i++) {
     if(a[i]!=0)
     printf("->\t%d\n",a[i]);
     }
     screen();
     }
void mergesort(int l,int r){
   if(r>l){
       int m=(l+r)/2;
       mergesort(l,m);
       mergesort(m+1,r);
       merge(l,m,r);
   }
}
void merge(int l,int m,int r){
   int i,j,k;
     int n1=m-l+1;
     int n2=r-m;
     int L[100],R[100];
       for(i=0;i<n1;i++)
	  L[i]=a[l+i];
       for(i=0;i<n2;i++)
	  R[i]=a[m+i+1];
   i=0;j=0;k=l;
   while(i<n1&&j<n2){
	if(L[i]<=R[j]){
	  a[k]=L[i];
	  i++;
	}
	else{
	  a[k]=R[j];
	  j++;
	}
   k++;
   }
   while(i<n1){
     a[k]=L[i];
     i++;
     k++;
   }
   while(j<n2){
     a[k]=R[j];
     j++;
     k++;
}
   }
void lab(){
     struct patient *p;
     p=first1;
    while(p!=NULL){
	   printf("%s\n",p->name);
	   p=p->next;
	   }
}
