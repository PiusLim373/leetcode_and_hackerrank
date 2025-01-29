#include <iostream>
#include <exception>
#include <string>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <typeinfo>
using namespace std;

int g_cur_id = 1;

class Person{
    public:
        string name;
        int age;
        virtual void get_data(){ }
        virtual void put_data(){ }
};

class Professor: public Person{
    private:
        int publications;
        int cur_id;
        Professor(){
            cur_id = g_cur_id;
            g_cur_id++;
            
        }
        void get_data(){
            name = "walter";
            age = 59;
            publications = 99;
        }
        void put_data(){
            cout << name <<" "<< age <<" "<< publications << " " << cur_id << endl;
        }
};

class Student: public Person{
    public:
        int marks[6];
        int cur_id;
};

int main()
{
    // Person *mae[3];
    // mae[0] = new Professor;
    // mae[0]->name = "piuu";
    Person *pp[2];
    pp[1] = new Professor;
    pp[2] = new Professor;
    pp[1]->get_data();
    pp[1]->put_data();
    pp[2]->put_data();

}