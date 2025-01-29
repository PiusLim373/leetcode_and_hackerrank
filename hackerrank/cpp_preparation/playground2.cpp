#include <iostream>
#include <vector>
using namespace std;

class Animal {
   public:

        virtual string GetNoise() const {return "0";}
};
class Dog : public Animal {
   public:
      string GetNoise() const { return "Bark!"; }
};
class Cat : public Animal {
   public:
      string GetNoise() const { return "Meow"; }
};

int main(){
    Dog* d = new Dog;
    Cat* c = new Cat;
    Animal* a = new Animal;
    vector<Animal*> all_animals;
    all_animals.push_back(d);
    all_animals.push_back(c);
    all_animals.push_back(a);

    // then, later...

    // this will print "Bark!"
    cout << all_animals[2]->GetNoise()<< endl;
}
