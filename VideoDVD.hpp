//
//  VideoDVD.hpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#ifndef VideoDVD_hpp
#define VideoDVD_hpp

#include <stdio.h>
#include "Media.hpp"




class VideoDVD: public Media
{
public:
    VideoDVD();
    VideoDVD(const string &InTitle,
             const string & InArtist,
             const string & InWherePurchased,
             const float & InCost,
             const Time & InRunningTime,
             const int & inNumberOfScenes,
             const int & inCurrentScene);
    void LoadMedia(const string &InTitle,
                   const string & InArtist,
                   const string & InWherePurchased,
                   const float & InCost,
                   const Time & InRunningTime,
                   const int & inNumberOfScenes,
                   const int & inCurrentScene);
    
    //----------------Getters
    virtual string GetTitle() const;
    virtual string GetArtist() const;
    virtual string GetWherePurchased() const;
    virtual float GetCost() const;
    virtual Time GetRunningTime() const;
    int GetNumberOfScenes() const;
    int GetCurrentScene() const;

    
    
    
    virtual void Play();
    virtual void FastForward();
    virtual void Rewind();
    virtual void PrintMedia(ostream & Out) const;
             // Displays media type, calls parent to display inherited members, then
             //   displays NumberOfScenes
             
protected:
    int NumberOfScenes;
    int CurrentScene;
};
    

#endif /* VideoDVD_hpp */
