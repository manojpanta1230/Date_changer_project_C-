#include <iostream>          //HEADER FILE
using namespace std;

 void title_as(){
     cout<<"                                       <This is our OOP Assesment1>"<<endl;             //This is self made function to show given information
     cout<<"                                        <SUMMITED TO:KUMRAR LOHOLA SIR>"<<endl;
     cout<<"                                            <DONE BY:MANOJ PANTA> "<<endl;}


 string get_month(int m)        //CREATING FUNCTION TO GET MONTH IN STRING

{
    if(m == 1)                   //using if else ladder CASE
        return "January";
    else if(m==2)
        return "February";
    else if(m==3)
        return "March";
    else if (m==4)
        return "April";
    else if (m==5)
        return "May";
    else if (m==6)
        return "June";
    else if (m==7)
        return "July";
    else if (m==8)
        return "August";
    else if (m==9)
        return "September";
    else if (m==10)
        return "October";
    else if (m==11)
        return "November";
    else
        return "December";
}



  int get_no_of_days(int m, int y)     //getter function for int type //TWO arugment is passed
{
    int total_days_in_month;         //int varaibles is declared to store value of no of days
        if(m==1)
            total_days_in_month = 31;
        else if(m==2)
    {
        if (y % 4 ==0)   //for finding leap year //If the entered year is exactly divisible by 4, if gets executed otherwise it passes to else condition
            total_days_in_month = 29;
        else
            total_days_in_month = 28;
    }
        else if (m==3)
            total_days_in_month = 31;
        else if (m==4)
            total_days_in_month = 30;
        else if (m==5)
            total_days_in_month = 31;
        else if (m==6)
            total_days_in_month = 30;
        else if (m==7)
            total_days_in_month = 31;
        else if (m==8)
            total_days_in_month = 31;
        else if (m==9)
            total_days_in_month = 30;
        else if (m==10)
            total_days_in_month = 31;
        else if (m==11)
            total_days_in_month = 30;
        else
            total_days_in_month = 31;

    return total_days_in_month;    //returns the number of days in a month
}


    class Date                 //Creating class named Date
{
        int date,month,year; // private data
    public:                   //public decleration
        void set_date(){            //setter functions definition //Function is created to set Date that accepts year,month and day
            cout<<"ENTER FULL DATE" << endl;
            cout<<"Enter year : ";
            cin>>year;

        do                          // beginning of do while loop
        {
            cout<<"Enter month : ";
            cin>>month;
            if(month<1 || month>12)
                cout<<"Error Try Again " <<endl;
        }while(month<1 || month>12);

        int last_date_of_month = get_no_of_days(month,year);   // this will accept two arguments and call the function and store the date in int varaible last_date _of_month

        do
        {
            cout<<"Enter day : ";
            cin>>date;
            if(date<1 || date>last_date_of_month)
                cout<<"Error Try Again " <<endl;
        }while(date<1 || date>last_date_of_month);
    }


    void display_date()      //creating function to display value of date class object

    {
        cout <<"Following different types of date Format"<<endl<<"Date is " << month << "/" << date << "/" << year<<endl<<endl; //Date in mm/dd/yy format

        cout << "Date is " << get_month(month) << " " << date << ", " << year <<endl<<endl; //Date in "monthName dd, yy" format

        cout << "Date is " << date << " " << get_month(month) << " " << year << endl<<endl; //Date in   "dd monthName yy" format
    }

    void operator++ ()              //Prefix Increment of entered date
    {
        ++date;                   //date will increase
        int total_days= get_no_of_days(month,year);//calls the getter function and takes the argument month and date

        if(date>total_days)         //it checks whether entered date is greater than total days.
        {
            date = 1;
            ++month;
            if (month>12)
            {
                month = 1;
                ++year;
            }

        }
        cout<<"The date after using prefix increment is : \n"<<endl;
    }

    void operator++(int)                //Postfix Increment  to increase date
    {
        date++;
        int total_days= get_no_of_days(month,year);//calls the getter function and takes the argument month and date

        if(date>total_days)
        {
            date = 1;
            month++;
            if (month>12)
            {
                month = 1;
                year++;
            }
        }
        cout << "The date after using postfix increment is : \n"<<endl;
    }

    friend Date operator--(Date obj);       //creating friend function to access private data of Class Date
    friend void operator--(Date obj , int);


//Binary operator overloading
    int operator-(Date obj)   //return type is int operator (-) and argument b is passed in class Date                //

    {
        int year_gap = year - obj.year;//year is the value given by b2 whereas b.year is value given by the obj b3
        int month_gap = month - obj.month;
        int date_gap = date - obj.date;

        int total_gap = year_gap * 365 + month_gap * 30 + date_gap;

        return total_gap;
    }

};

    Date operator--(Date obj)     //Prefix Decrement is used to decrease date and to return  type date with obj argument
{

        --obj.date;
        if(obj.date < 1)
    {
        --obj.month;
        if(obj.month < 1)
       {
           obj.month = 12;
           --obj.year;
       }
       int last_date = get_no_of_days(obj.month,obj.year);
       obj.date = last_date;
    }
    cout << "The date after using prefix decrement is : \n "<<endl;
    return obj; //IT store the value of date in this obj.
}

    void operator--(Date obj,int)      //Postfix Decrement is used to decrease date and to return date with obj argument
{
        obj.date--;
        if(obj.date < 1)
    {
        obj.month--;
        if(obj.month < 1)
       {
           obj.month = 12;
           obj.year--;
       }
       int last_date = get_no_of_days(obj.month,obj.year);
       obj.date = last_date;
    }
    cout << "The date after using postfix decrement is : \n"<<endl;
    obj.display_date();
}
//******************************//
//      MAIN FUNCTION           //
//******************************//

int main()

{
    title_as();                   //FUNCTION IS CALLED
    Date obj1  ;                  //CREATING OBJECT OF class Date
    obj1.set_date();              //calling set function of class Date
    obj1.display_date();          //calling printing function which dispaly date in format

    ++obj1;                       // prefix incresement which call void operator ++()
    obj1.display_date();           //calling printing function which dispaly date in format  after incresement

    obj1++;                       // postfix incresement which call void operator ++(int)
    obj1.display_date();           //calling printing function which dispaly date in format  after incresement


    obj1=--obj1;                   // here we can assign obj1=--obj1 because in above decresment function there is return type which return obj
     obj1.display_date();           //display date after decresement
     obj1--;



    cout << "                            Enter date to be subtracted            " <<endl<<endl;
    Date b2;              //second object is created b2 ;
    b2.set_date();         // set date for object b2
    Date b3;                //third object is created b3;
    b3.set_date();           //set date for obj3
    int total_gap = b2 - b3; //binary operator overloading function is called to subtract the no of days
    cout << " Total number of gap between two dates are : " <<total_gap<<endl; //display the no of days gap

    return 0;
}
