#include <bits/stdc++.h>
using namespace std;

int i = 0;
int counter = 0;
mutex m;
void producer()
{
    while (counter < 10)
    {
        m.lock();
        if (i)
            m.unlock();
        else
        {
            i++;
            counter++;
            cout << "producer running,  i: " << i << ", counter: " << counter << endl;
            m.unlock();
        }
    }
}

void consumer()
{
    while (counter < 10)
    {
        m.lock();
        if (!i)
            m.unlock();
        else
        {
            i--;
            cout << "consumer running,  i: " << i << ", counter: " << counter << endl;
            m.unlock();
        }
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    cout << "ended" << endl;
}
