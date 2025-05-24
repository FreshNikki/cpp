#include "Dialog.h"
#include "Employee.h"
#include <iostream>

using namespace std;

Dialog::Dialog() : Vector()
{
    beg = nullptr;
    EndState = 0;
}
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event)
{
    string s;
    cout << "\nEnter command: ";
    cin >> s;
    event.what = evMessage;

    if (s == "+") event.command = cmAdd;
    else if (s == "-") event.command = cmDel;
    else if (s == "s") event.command = cmShow;
    else if (s == "q") event.command = cmQuit;
    else if (s == "m") {
        event.command = cmMake;
        cin >> event.a;
    } else if (s == "z") {
        event.command = cmGet;
        cin >> event.a;
    } else event.what = evNothing;
}

int Dialog::Execute()
{
    TEvent event;
    do {
        GetEvent(event);
        HandleEvent(event);
    } while (!EndState);
    return 0;
}

void Dialog::HandleEvent(TEvent& event)
{
    if (event.what == evMessage) {
        switch (event.command) {
            case cmAdd: Add(); break;
            case cmDel: Del(); break;
            case cmShow: Show(); break;
            case cmMake:
                if (beg != nullptr) {
                    for (int i = 0; i < cur; ++i) delete beg[i];
                    delete[] beg;
                }
                size = event.a;
                beg = new Object*[size];
                cur = 0;
                cout << "Group of size " << size << " created.\n";
                break;
            case cmGet:
                if (event.a >= 0 && event.a < cur) {
                    Person* p = dynamic_cast<Person*>(beg[event.a]);
                    if (p) cout << "Name: " << p->Get_name() << "\n";
                } else cout << "Invalid index.\n";
                break;
            case cmQuit:
                EndExec();
                break;
        }
    }
}

void Dialog::ClearEvent(TEvent&)
{
    
}
void Dialog::EndExec()
{
    EndState = 1;
}
