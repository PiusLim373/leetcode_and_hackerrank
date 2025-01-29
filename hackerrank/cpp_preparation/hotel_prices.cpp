#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    virtual int get_price() {
        
        cout <<bedrooms_ << bathrooms_<< 50*bedrooms_ + 100*bathrooms_ << endl;
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        cout << "hi" << endl;
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    // int n;
    // cin >> n;
    // vector<HotelRoom*> rooms;
    // for (int i = 0; i < n; ++i) {
    //     string room_type;
    //     int bedrooms;
    //     int bathrooms;
    //     cin >> room_type >> bedrooms >> bathrooms;
    //     if (room_type == "standard") {
    //         rooms.push_back(new HotelRoom(bedrooms, bathrooms));
    //     } else {
    //         rooms.push_back(new HotelApartment(bedrooms, bathrooms));
    //     }
    // }

    vector<HotelRoom*> rooms;
    rooms.push_back(new HotelRoom(3, 1));
    rooms.push_back(new HotelApartment(1, 1));

    int total_profit = 0;
    for (auto room : rooms) {
        cout << total_profit <<endl;
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}