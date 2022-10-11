1. Define a class Person with instance members name and age. Also define member
       functions setName(), setAge(), getName(), getAge(). Now define class Employee by
inheriting Person class. In the Employee class define empid and salary as instance
       members. Also define setEmpid, setSalary, getEmpid, getSalary.


#include <iostream>
#include <cstring>
using namespace std;

class Person{
private:
   char name[20];
   short int age;
public:
   void setName(char a[]){
       strcpy(name,a);
   }
   void setAge(short int a){
       age=a;
   }
    char *getName(){
        return name;
   }

   short int getAge(){
       return age;
   }

};
class Employee:public Person{
private:
   int empid;
   float salary;
public:
   void setEmpid(int id){
       this->empid=id;
   }
   void setSalary(float salary){
       this->salary=salary;
   }

   int getEmpid(){
       return this->empid;
   }
   float getSalary(){
       return this->salary;
   }

};

int main(){
   return 0;
}


2. Write a C++ program to add two numbers using single inheritance. Accept these two
numbers from the user in base class and display the sum of these two numbers in
derived class.

#include <iostream>
#include <cstring>

using namespace std;

class BaseClass {
protected:
   float num1;
   float num2;
public:
   void setNumbers() {
       cout << "Enter two numbers";
       cin >> this->num1 >> this->num2;
   }
};

class DerivedClass: public BaseClass{
public:
   float sum(){
       return (this->num1+ this->num2);
   }


};
int main() {
   DerivedClass d;
   d.setNumbers();
   cout<<d.sum();
   return 0;
}

3. Write a C++ program to calculate the percentage of a student using multi-level
inheritance. Accept the marks of three subjects in base class. A class will be derived
from the above mentioned class which includes a function to find the total marks
obtained and another class derived from this class which calculates and displays the
percentage of students.


#include <iostream>

using namespace std;

class BaseClass {
protected:

   float physics_marks;
   float maths_marks;
   float english_marks;
public:
   void setmark(float physics, float maths, float english) {
       this->physics_marks = physics;
       this->maths_marks = maths;
       this->english_marks = english;
   }
};

class Derivedclass : public BaseClass {
protected:
   float total;
public:
   float total_marks() {
       total = (this->physics_marks + this->maths_marks + this->english_marks);
   }
};

class Student : public Derivedclass {
private:
   float percent;
public:
   void percentage() {
       this->percent = (this->total / 300) * 100;
   }

   float display() {
       return percent;
   }


};

int main() {

   Student s;
   s.setmark(45, 78, 89);
   s.total_marks();
   s.percentage();
   cout << s.display();
   return 0;
}

4. Write a C++ program to design a base class Person (name, address,
phone_no). Derive a class Employee (eno, ename) from Person. Derive a
class Manager (designation, department name, basic-salary) from
Employee.

#include <iostream>

using namespace std;

class Person {
protected:
   char name[50];
   char address[150];
   double phone_num;
};

class Employee : public Person {
protected:
   int eno;
   char ename[50];

};

class Manager : public Employee {
private:
   char designation[20];
   char department_name[50];
   float basic_salary;
public:
   void manager_details() {

       for (int i = 0; i < 1; ++i) {
           cout << "Enter managers details" << endl;
           cout << "----------------------" << endl;
           cout << "Enter Employee no." << endl;
           cin >> this->eno;
           cout << "Enter name" << endl;
           cin >> this->name;
           cout << "Enter address" << endl;
           cin >> this->address;
           cout << "Enter phone number:" << endl;
           cin >> this->phone_num;
           cout << "Enter designation" << endl;
           cin >> this->designation;
           cout << "enter department name:" << endl;
           cin >> this->department_name;
           cout << "Enter basic salary" << endl;
           cin >> this->basic_salary;
       }
   }

   float highsalary() {
       return this->basic_salary;
   }

   char *managername() {
       return this->name;
   }

};

int main() {
   int n;
   cout << "How many managers you want to enter:" << endl;
   cin >> n;
   Manager m[n];
   for (int i = 0; i < n; ++i) {
       m[i].manager_details();
   }
   float sal = m[0].highsalary();
   float highsal = 0;
   int index = 0;
   for (int i = 0; i < n; ++i) {
       highsal = m[i].highsalary();
       if (highsal>sal){
           index = i;
           sal=highsal;
       }
   }

   cout<<"Manager with higest salary is : "<<sal<<endl;
   cout<<" And manager name is "<<m[index].managername();
   return 0;
}

5. Write a C++ program to define a base class Item (item-no, name, price).
Derive a class Discounted-Item (discount-percent). A customer purchases
'n' items. Display the item-wise bill and total amount using appropriate
format

#include <iostream>

using namespace std;

class Item {
protected:
   int item_no;
   char name[20];
   float price;
};

class Discounted_Item : public Item {
protected:
   float discount_percent;
public:
   void item_details() {
       cout << "Enter item name:" << endl;
       cin >> this->name;
       cout << "Enter item no." << endl;
       cin >> this->item_no;
       cout << "Enter item price:" << endl;
       cin >> this->price;
       cout << "Enter discount price:" << endl;
       cin >> this->discount_percent;
   }

   void display() {
       float selling = (this->price) - ((this->discount_percent * this->price) / 100);
       cout << "Item name:" << this->name << endl;
       cout << "Item no." << this->item_no << endl;
       cout << "Item price" << this->price << endl;
       cout << "Discount price" << this->discount_percent << endl;
       cout << "Discounted price" << selling << endl;
   }

   float bill() {
       return this->price;
   }

   float total_discount(){
       return this->discount_percent;
   }
};

int main() {
   cout << "Enter number of items:" << endl;
   int n;
   cin >> n;
   Discounted_Item i[n];
   for (int j = 0; j < n; ++j) {
       i[j].item_details();
   }
   for (int j = 0; j < n; ++j) {
       i[j].display();
   }
   float sum = 0;
   for (int j = 0; j < n; ++j) {
       sum += i[j].bill();
   }
   cout << "Total price " << sum << endl;
   float totalDiscount = 0;
   for (int j = 0; j < n; ++j) {
       totalDiscount+=i[j].total_discount();
   }
   float selling = sum - ((totalDiscount * sum) / 100);

   cout<<"Total Discount "<<selling;
   return 0;
}

6. Write a C++ program to demonstrate how a common friend function can
be used to exchange the private values of two classes. (Use call by
reference method).

#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
   char bname[20];
   float bprice;
public:
   Book() {};

   Book(char name[], float bprice) {
       strcpy(this->bname, name);
       this->bprice = bprice;
   }

   void display() {
       cout << "Book name " << this->bname << endl;
       cout << "Book price " << this->bprice << endl;
   }

   friend void exchange(Book&, Book&);
};

void exchange(Book &b1, Book &b2) {
   float t = b1.bprice;
   b1.bprice = b2.bprice;
   b2.bprice = t;

   char x[20];
   strcpy(x, b1.bname);
   strcpy(b1.bname, b2.bname);
   strcpy(b2.bname, x);
}

int main() {
   Book physics("physics", 600);
   Book maths("maths", 900);
   physics.display();
   maths.display();
   cout << "After Exchanging" << endl;
   cout<<endl;
   exchange(physics, maths);
   physics.display();
   maths.display();
   return 0;
}


7. Write class declarations and member function definitions for a C++ base
class to represent an Employee (emp-code, name).
Derive two classes as Fulltime (daily rate, number of days, salary) and
Parttime (number of working hours, hourly rate, salary).

#include <iostream>
#include <cstring>

using namespace std;

class Employee {
protected:
   int emp_code;
   char name[20];
public:
   void setEmpcode(int a) {
       this->emp_code = a;
   }

   int get() { return this->emp_code; };

   void setName(char name[20]) {
       strcpy(this->name, name);
   }

   char *getName() {
       return this->name;
   }
};

class Fulltime : public Employee {

protected:
   float salary;
   int daily_rate;
   int number_of_days;
   string status;
public:
   void setSalary(float salary) {
       this->salary = salary;
   }

   float getSalary() {
       return this->salary;
   }

};

class Parttime : public Fulltime {
private:
   int number_of_working_hours;
   int hourly_rate;
   float salary;
public:
   void setRecords() {
       cout << "Employee Number" << endl;
       cin >> emp_code;
       cout << "Employee Name" << endl;
       cin >> name;
       cout << "Employee Salary" << endl;
       cin >> salary;
       cout << "Employee status" << endl;
       cin >> status;
   }

   void display() {
       cout << emp_code << endl;
       cout << name << endl;
       cout << salary << endl;
       cout << status << endl;
   }

   void search(int code) {
       if (code == this->emp_code) {
           cout << this->emp_code << endl;
           cout << this->name << endl;
           cout << this->salary << endl;
           cout << this->status << endl;
       } else cout << "Not found" << endl;
   }
};

int main() {
   int n;
   cout << "Enter number of Employee" << endl;
   cin >> n;
   Parttime p[n];

   while (1) {
       int value;
       cout << "1.Enter Records" << endl;
       cout << "2.Display Records" << endl;
       cout << "3.search Records" << endl;
       cout << "4.Quit" << endl;
       cin >> value;
       switch (value) {
           case 1:
               p->setRecords();
               break;
           case 2:
               p->display();
               break;
           case 3:
               p->search(789);
               break;
           case 4:
               exit(0);
       }
   }
   return 0;
}


8).In a bank, different customers have savings account. Some customers may
       have taken a loan from the bank. So bank always maintain information about
bank depositors and borrowers


#include<iostream>
#include<stdio.h>
using namespace std;

class customer
{
   char nm[20];
   long phno;
public:
   void acceptc()
   {
       cout<<"\n Enter Customer Name      :  ";
       cin>>nm;
       cout<<"\n Enter Customer Phone No. :  ";
       cin>>phno;
   }
   void dispc()
   {
       cout<<"\n Details of Customer \n";
       cout<<"\n ----------------------------------------\n";
       cout<<"\n Customer Name            :  "<<nm;
       cout<<"\n Customer Phone No.       :  "<<phno;
   }
};
class deposit:public customer
{
   int accno, balance;
public:
   void acceptd()
   {
       cout<<"\n Enter Customer A/c No    :  ";
       cin>>accno;
       cout<<"\n Enter Balance            :  ";
       cin>>balance;
   }
   void dispd()
   {
       cout<<"\n Customer A/c No          :  "<<accno;
       cout<<"\n Balance                  :  "<<balance;
       cout<<"\n ----------------------------------------\n";
   }
};
class borrow:public deposit
{
   int loan_no,loan_amt;
public:
   void acceptb()
   {
       cout<<"\n Enter Loan No            :  ";
       cin>>loan_no;
       cout<<"\n Enter Loan Amount        :  ";
       cin>>loan_amt;
       cout<<"\n ----------------------------------------\n";
   }
   void dispb()
   {
       cout<<"\n Loan No                  :  "<<loan_no;
       cout<<"\n Loan Amount              :  "<<loan_amt;
       cout<<"\n ----------------------------------------\n";
   }
};
int main()
{
   borrow *b1;
   int n,i;
   cout<<"\n Enter No. of Customer Details You Want  :  ";
   cin>>n;
   b1=new borrow[n];
   for(i=0; i<n; i++)
   {
       1[i].acceptc();
       b1[i].acceptd();
       b1[i].acceptb();
   }
   for(i=0; i<n; i++)
   {
       b1[i].dispc();
       b1[i].dispd();
       b1[i].dispb();
   }
   return 0;
}


9. Write a C++ program to implement the following class hierarchy:

#include <iostream>

using namespace std;
class Student{
protected:
   int id;
   string name;
public:
   void setId(){
       cout<<"Enter id"<<endl;
       cin>>id;
   }

   void setName(){
       cout<<"Enter name of student"<<endl;
       cin>>name;
   }
};
class StudentExam:public Student{
protected:
   float physicsmark,mathsmarks,english,hindi,Marathi;
public:
   void Setmarks(){
       cout<<"Enter marks for physicsmark"<<endl;
       cin>> this->physicsmark;
       cout<<"Enter marks for mathsmarks"<<endl;
       cin>>mathsmarks;
       cout<<"Enter marks for english"<<endl;
       cin>>english;
       cout<<"Enter marks for hindi"<<endl;
       cin>>hindi;
       cout<<"Enter marks for Marathi"<<endl;
       cin>>Marathi;
   }

};

class StudentResult:public StudentExam{
   float percen;
public:
   float percentage(){
       float total = (physicsmark+mathsmarks+english+hindi+Marathi);
       return (total/500)*100;
   }

   void show(){
       cout<<"physicsmark "<<physicsmark<<endl;
       cout<<"mathsmarks "<<mathsmarks<<endl;
       cout<<"english "<<english<<endl;
       cout<<"hindi "<<hindi<<endl;
       cout<<"Marathi "<<Marathi<<endl;

   }

};

int main(){
int n;
   cout<<"Enter number of student you want to enter:"<<endl;
   cin>>n;
   StudentResult s[n];
   for (int i = 0; i < n; ++i) {
       s[i].setId();
       s[i].setName();
       s[i].Setmarks();
       s[i].show();

       cout<<"percentage is "<<s[i].percentage();
   }
   return 0;
}

10. Consider two base classes
worker(int code, char name, float salary),
officer(float DA, HRA)
class manger(float TA(is 10% of salary), gross salary) is derived from both base
classes.


#include <iostream>
using namespace std;

class Worker{
protected:
   int code;
   char name;
   float salary;
public:
   void set(){
       cout<<"Enter Code"<<endl;
       cin>>code;
       cout<<"Enter name"<<endl;
       cin>>name;
       cout<<"Enter salary"<<endl;
       cin>>salary;
   }
};

class Officer:public Worker{
   float DA, HRA;
public:
   void setData(){
       cout<<"Enter DA"<<endl;
       cin>>DA;
       cout<<"Enter HRA"<<endl;
       cin>>HRA;
   }
};


class Manager:public Officer{
   float TA;
public:
   void setTA(){
       float a;
       cout<<"Enter TA"<<endl;
       cin>>a;
       TA = (salary*10)/100;
   }
};
int main(){

   cout<<"Enter Manager Count"<<endl;
   cout<<"Enter worker information"<<endl;
   Manager m;
   m.set();
   m.setData();
   m.setTA();
   return 0;
}
