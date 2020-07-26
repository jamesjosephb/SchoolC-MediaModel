//
//  AudioCassette.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "AudioCassette.hpp"

AudioCassette::AudioCassette():Media(){}
AudioCassette::AudioCassette(const string &InTitle,
                             const string & InArtist,
                             const string & InWherePurchased,
                             const float & InCost,
                             const Time & InRunningTime,
                             const int & inNumberOfSelections,
                             const int & inCurrentSelection)
                            :Media(InTitle,
                                   InArtist,
                                   InWherePurchased,
                                   InCost,
                                   InRunningTime)
{
    NumberOfSelections = inNumberOfSelections;
    if (inCurrentSelection <= 1 or inCurrentSelection >= NumberOfSelections)
    {
        CurrentSelection = 1;
    }
    else{CurrentSelection = inCurrentSelection;}
}

//--------------Getters
string AudioCassette::GetTitle() const{return Media::Title;}
string AudioCassette::GetArtist() const{return Media::Artist;}
string AudioCassette::GetWherePurchased() const{return Media::WherePurchased;}
float AudioCassette::GetCost() const{return Media::Cost;}
Time AudioCassette::GetRunningTime() const{return Media::RunningTime;}
int AudioCassette::GetNumberOfSelections() const{ return NumberOfSelections;}
int AudioCassette::GetCurrentSelection() const{ return CurrentSelection;}















void AudioCassette::Play()
{
    if (Media::IsMediaAtEnd(CurrentSelection, NumberOfSelections))
        {
            cout << "Cannot Play! ----> " << Media::Title << "Must Rewind First\n";}
    else
        {
            cout << "<---Playing Track: " << AudioCassette::CurrentSelection <<"--->\n";
            
        }
}

void AudioCassette::FastForward()
{
    if (Media::IsMediaAtEnd(CurrentSelection, NumberOfSelections))
        {
            cout << "Cannot Fast Forward! ----> " << Media::Title << "Must Rewind First\n";
            
        }
    else
        {
            AudioCassette::CurrentSelection ++;
            cout << "<---Fast Forwarding to Track: " << AudioCassette::CurrentSelection << "--->\n";
        }
}
void AudioCassette::Rewind()
{
    if (Media::IsMediaAtBeginning(CurrentSelection))
        {
            cout << "Cannot Rewind! ----> " << Media::Title << " Already on first track.\n";
            
        }
    else
        {
            AudioCassette::CurrentSelection --;
            cout << "<---Rewinding to track: " << AudioCassette::CurrentSelection << "--->\n";
        }
}
void AudioCassette::PrintMedia(ostream & Out) const
{
    cout << "\nType:      Audio Cassette\n";
    Media::PrintMedia(Out);
    cout << "Tracks:    " << NumberOfSelections << endl << endl;
    
}

void AudioCassette::LoadMedia(const string &InTitle,
                  const string & InArtist,
                  const string & InWherePurchased,
                  const float & InCost,
                  const Time & InRunningTime,
                  const int & inNumberOfSelections,
                  const int & inCurrentSelection)
{
    Media::LoadMedia(InTitle,
                     InArtist,
                     InWherePurchased,
                     InCost,
                     InRunningTime,
                     inNumberOfSelections,
                     inCurrentSelection);
    NumberOfSelections = inNumberOfSelections;
    CurrentSelection = inCurrentSelection;
}








