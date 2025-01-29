#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    public:
        int l; 
        int b;
        int h;  
        Box(){
            l = 0;
            b = 0;
            h = 0;
        }
        Box(int a, int b, int c): l(a), b(b), h(c) { }
        int getLength(){
            return l;
        }      
        int getBreadth(){
            return b;
        }
        int getHeight(){
            return h;
        }
        long CalculateVolume(){
            return b*h*l;
        }
};

bool operator< (const Box& a, const Box& b){
    bool return_val;
    if(a.l < b.l) return_val = true;
    else if(a.l == b.l){
        if(a.b < b.b) return_val = true;
        else if (a.b == b.b){
            if (a.h < b.h) return_val = true;
            else return_val = false;
        }
        else return_val = false;
    }
    else return_val = false;
    return return_val;
}


ostream& operator<< (ostream& os, const Box& a){
    os << a.l << " " << a.b << " " << a.h;
    return os;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}