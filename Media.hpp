//
//  Media.hpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#ifndef Media_hpp
#define Media_hpp

#include <stdio.h>
#include <string>
#include <string>
#include "Time.hpp"



class Media  // An Abstract Base Class
{
public:
    Media();
    Media(const string &InTitle,
          const string & InArtist,
          const string & InWherePurchased,
          const float & InCost,
          const Time & InRunningTime);
    
    //Getters
    virtual string GetTitle() const;
    virtual string GetArtist() const;
    virtual string GetWherePurchased() const;
    virtual float GetCost() const;
    virtual Time GetRunningTime() const;
    
    
    bool IsMediaAtBeginning(int currentTrack) const;
    bool IsMediaAtEnd(int currentTrack ,int endTrack) const;
    
    
    virtual ~Media() { }    // virtual destructor so polymorphic-destruction works properly
    virtual void PrintMedia(ostream & Out) const;  // Prints common data members to output
    
    
    // stream
    virtual void Play() = 0;        // Can only play a media item if it is NOT at its end
    virtual void FastForward() = 0; // Can only fast-forward a media item if it is NOT at its end
    virtual void Rewind() = 0;      // Can only rewind a media item if it is NOT at its beginning
    virtual void LoadMedia(const string &InTitle,
                           const string & InArtist,
                           const string & InWherePurchased,
                           const float & InCost,
                           const Time & InRunningTime,
                           const int & inNumberOfSelections,
                           const int & inCurrentSelection);
    
protected:
    string Title;
    string Artist;
    string WherePurchased;
    float Cost;
    bool MediaAtBeginning;
    bool MediaAtEnd;
    Time RunningTime;
};




#endif /* Media_hpp */
