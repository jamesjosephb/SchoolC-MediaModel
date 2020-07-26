//
//  AudioCD.hpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#ifndef AudioCD_hpp
#define AudioCD_hpp

#include <stdio.h>
#include "Media.hpp"


class AudioCD: public Media
{
public:
    AudioCD();
    AudioCD(const string &InTitle,
            const string & InArtist,
            const string & InWherePurchased,
            const float & InCost,
            const Time & InRunningTime,
            const int & inNumberOfTracks,
            const int & inCurrentTrack);
    
//---------------Getters
    virtual string GetTitle() const;
    virtual string GetArtist() const;
    virtual string GetWherePurchased() const;
    virtual float GetCost() const;
    virtual Time GetRunningTime() const;
    int GetNumberOfTracks() const;
    int GetCurrentTrack() const;

    virtual void Play();
    virtual void FastForward();
    virtual void Rewind();
    virtual void PrintMedia(ostream & Out) const;
            // Displays media type, calls parent to display inherited members, then
            //   displays NumberOfTracks
    
    void LoadMedia(const string &InTitle,
                   const string & InArtist,
                   const string & InWherePurchased,
                   const float & InCost,
                   const Time & InRunningTime,
                   const int & inNumberOfTracks,
                   const int & inCurrentTrack);
            
protected:
    int NumberOfTracks;
    int CurrentTrack;
};



#endif /* AudioCD_hpp */
