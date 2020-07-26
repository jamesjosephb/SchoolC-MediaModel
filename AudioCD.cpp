//
//  AudioCD.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "AudioCD.hpp"
AudioCD::AudioCD():Media(){}

AudioCD::AudioCD(const string &InTitle,
               const string & InArtist,
               const string & InWherePurchased,
               const float & InCost,
               const Time & InRunningTime,
               const int & inNumberOfTracks,
               const int & inCurrentTrack)
               :Media(InTitle,
                      InArtist,
                      InWherePurchased,
                      InCost,
                      InRunningTime)
{
    NumberOfTracks = inNumberOfTracks;
    CurrentTrack = 1;
}
string AudioCD::GetTitle() const{return Media::Title;}
string AudioCD::GetArtist() const{return Media::Artist;}
string AudioCD::GetWherePurchased() const{return Media::WherePurchased;}
float AudioCD::GetCost() const{return Media::Cost;}
Time AudioCD::GetRunningTime() const{return Media::RunningTime;}
int AudioCD::GetNumberOfTracks() const {return NumberOfTracks;}
int AudioCD::GetCurrentTrack() const {return CurrentTrack;}







void AudioCD::Play()
{
    if (Media::IsMediaAtEnd(CurrentTrack, NumberOfTracks))
    {
        cout << "Cannot Play! ----> " << Media::Title << "Must Rewind First\n";}
    else
    {
        cout << "<---Playing Track: " << AudioCD::CurrentTrack <<"--->\n";
        
    }
}
void AudioCD::FastForward()
{
    if (Media::IsMediaAtEnd(CurrentTrack, NumberOfTracks))
    {
        cout << "Cannot Fast Forward! ----> " << Media::Title << "Must Rewind First\n";
        
    }
    else
    {
        AudioCD::CurrentTrack ++;
        cout << "<---Fast Forwarding to Track: " << AudioCD::CurrentTrack << "--->\n";
    }
}

void AudioCD::Rewind()
{
    if (Media::IsMediaAtBeginning(CurrentTrack))
    {
        cout << "Cannot Rewind! ----> " << Media::Title << " Already on first track.\n";
        
    }
    else
    {
        AudioCD::CurrentTrack --;
        cout << "<---Rewinding to track: " << AudioCD::CurrentTrack << "--->\n";
    }
}

void AudioCD::PrintMedia(ostream & Out) const
//// Displays media type, calls parent to display inherited members, then
////   displays NumberOfTracks
{
    cout << "\nType:      Audio CD\n";
    Media::PrintMedia(Out);
    cout << "Tracks:    " << CurrentTrack << endl << endl;
    
}

void AudioCD::LoadMedia(const string &InTitle,
               const string & InArtist,
               const string & InWherePurchased,
               const float & InCost,
               const Time & InRunningTime,
               const int & inNumberOfTracks,
               const int & inCurrentTrack)
{
    Media::LoadMedia(InTitle,
                     InArtist,
                     InWherePurchased,
                     InCost,
                     InRunningTime,
                     inNumberOfTracks,
                     inCurrentTrack);
    NumberOfTracks = inNumberOfTracks;
    CurrentTrack = inCurrentTrack;
}

