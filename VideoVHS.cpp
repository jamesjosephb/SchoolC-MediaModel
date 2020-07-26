//
//  VideoVHS.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "VideoVHS.hpp"


VideoVHS::VideoVHS():Media(){}
VideoVHS::VideoVHS(const string &InTitle,
                   const string & InArtist,
                   const string & InWherePurchased,
                   const float & InCost,
                   const Time & InRunningTime,
                   const int & inNumberOfTracks,
                   const int & inCurrentTrack)
                   :Media(InTitle, InArtist, InWherePurchased, InCost,  InRunningTime)
{
    NumberOfTracks = inNumberOfTracks;
    CurrentTrack = inCurrentTrack;
}
void VideoVHS::LoadMedia(const string &InTitle,
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





//----------------Getters
string VideoVHS::GetTitle() const{return Media::Title;}
string VideoVHS::GetArtist() const{return Media::Artist;}
string VideoVHS::GetWherePurchased() const{return Media::WherePurchased;}
float VideoVHS::GetCost() const{return Media::Cost;}
Time VideoVHS::GetRunningTime() const{return Media::RunningTime;}
int VideoVHS::GetNumberOfTracks() const{return NumberOfTracks;}
int VideoVHS::GetCurrentTrack() const{return CurrentTrack;}


void VideoVHS::Play()
{
    if (Media::IsMediaAtEnd(CurrentTrack, NumberOfTracks))
    {
        cout << "Cannot Play! ----> " << Media::Title << "Must Rewind First\n";}
    else
    {
        cout << "<---Playing Track: " << VideoVHS::CurrentTrack <<"--->\n";
        
    }
}
void VideoVHS::FastForward()
{
    if (Media::IsMediaAtEnd(CurrentTrack, NumberOfTracks))
    {
        cout << "Cannot Fast Forward! ----> " << Media::Title << "Must Rewind First\n";
        
    }
    else
    {
        VideoVHS::CurrentTrack ++;
        cout << "<---Fast Forwarding to Track: " << VideoVHS::CurrentTrack << "--->\n";
    }
}
void VideoVHS::Rewind()
{
    if (Media::IsMediaAtBeginning(CurrentTrack))
    {
        cout << "Cannot Rewind! ----> " << Media::Title << " Already on first track.\n";
        
    }
    else
    {
        VideoVHS::CurrentTrack --;
        cout << "<---Rewinding to track: " << VideoVHS::CurrentTrack << "--->\n";
    }
}
void VideoVHS::PrintMedia(ostream & Out) const
//// Displays media type, calls parent to display inherited members, then
////   displays NumberOfTracks
{
    cout << "\nType:      Video VHS\n";
    Media::PrintMedia(Out);
    cout << "Tracks:    " << CurrentTrack << endl << endl;
    
}

