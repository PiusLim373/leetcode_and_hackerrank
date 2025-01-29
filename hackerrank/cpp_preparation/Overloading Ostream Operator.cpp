#include <iostream>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
// Enter your code here.
ostream& operator<<(ostream& os, Person& p){
    // first_name=john,last_name=doe registered
    os <<"first_name="<< p.get_first_name() << ",last_name=" << p.get_last_name(); 
    return os;
}

int main() {
    string first_name = "john", last_name = "doe", event = "registered";
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}