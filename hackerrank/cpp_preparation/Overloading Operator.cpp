//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex operator+(Complex s1, Complex s2){
    Complex return_val;
    return_val.a = s1.a + s2.a;
    return_val.b = s1.b + s2.b;
    return return_val;
}

ostream& operator<<(ostream& os, Complex& c){
    os << c.a << "+i" << c.b;
    return os;
}

int main()
{
    Complex x,y;
    string s1 = "3+i4",s2 = "5+i6";
    // cin>>s1;
    // cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
