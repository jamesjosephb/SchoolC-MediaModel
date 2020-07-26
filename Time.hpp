//
//  Time.hpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class Time
{
    friend ostream & operator<<(ostream & Out, Time & RHS);
public:
    Time(int InMinutes = 0);
    void SetTime( int NewMinutes);
    int GetTime() const;
private:
    int Minutes;
};



#endif /* Time_hpp */
