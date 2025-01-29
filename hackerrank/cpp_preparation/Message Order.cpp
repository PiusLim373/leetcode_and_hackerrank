#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Message {
public: 
    Message() {}
    const string& get_text() {
        return text;
    }   
    void stored_msg(string text, int counter){
        ordered_msg.insert(make_pair(counter, text));  
    }
private:
    map<int, string> ordered_msg;
    string text;
};

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message::stored_msg(text, count);
        count++;
    }
private:
    int count = 0;
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    // string text;
    messages.push_back(message_factory.create_message("Alex"));
    messages.push_back(message_factory.create_message("Hello Monique!"));
    messages.push_back(message_factory.create_message("What'up?"));
    messages.push_back(message_factory.create_message("Not much :("));
    // while (getline(cin, text)) {
    //     messages.push_back(message_factory.create_message(text));
    // }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
