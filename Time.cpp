//
//  Time.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "Time.hpp"



ostream & operator<<(ostream & Out, Time & RHS){return Out << RHS.GetTime();}
Time::Time(int InMinutes){Minutes = InMinutes;}
void Time::SetTime(int NewMinutes){Minutes = NewMinutes;}
int Time::GetTime() const {return Minutes;}



