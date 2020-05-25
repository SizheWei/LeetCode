//
//  main.cpp
//  TA_test
//
//  Created by 魏思哲 on 4/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

//#include <iostream>
//
//using namespace std;
//
//
//int Loop(int amount,int count)
//{
//    int result = 0;
//    for(int i=2 ; i<=amount ; ++i)
//    {
//        result = (result + count)%i;
//    }
//    return result;
//}
//
//int main()
//{
//    int amount,count;
//    cin>>amount;
//    cin>>count;
//    cout<<Loop(amount,count)+1<<endl;
//
//
//    return 0;
//}


#include <iostream>
using namespace std;

typedef struct List
{
    int num;
    struct List *next;
}*pList;


class Josephus
{
    public:
        Josephus() {}
        Josephus(int number, int mes):
            n(number),
            m(mes){}
        void set();
        void creat();
        void del();
    private:
        pList head;
        int n, m, tmp_n;
};

void Josephus::set()
{
    cin >> n;
    tmp_n = n;
    cin >> m;
}

void Josephus::creat()
{
    pList p1, p2;
    pList p = new List;
    n += 1;
    p -> num = 1;
    p2 = head = p;
    for(int i = 2; i < n; i++)
    {
        p = new List;
        p -> num = i;

        p1 = p2;
        p2 = p;
        p1 -> next = p2;
    }

    p2 -> next = head;
    p = head;
}

void Josephus::del()
{
    pList p1 = NULL;
    pList p2 = head;

    n = tmp_n + 1;
    while(n--)
    {
        int s = m - 1;
        while(s--)
        {
            p1 = p2;
            p2 = p2 -> next;
        }

        if(n == 0)
        {
            p2 = p2 -> next;
            p1 -> next = NULL;
            cout << p2 -> num << endl;
        }
        else
        {
            p2 = p2 -> next;
            p1 -> next = p2;
        }
    }
}

int main()
{
    Josephus t;
    t.set();
    t.creat();
    t.del();
    cout<<9/2<<endl;
    return 0;
}

