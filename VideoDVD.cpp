//
//  VideoDVD.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "VideoDVD.hpp"

VideoDVD::VideoDVD():Media(){}
VideoDVD::VideoDVD(const string &InTitle,
                   const string & InArtist,
                   const string & InWherePurchased,
                   const float & InCost,
                   const Time & InRunningTime,
                   const int & inNumberOfScenes,
                   const int & inCurrentScene)
                   :Media(InTitle, InArtist, InWherePurchased, InCost,  InRunningTime)
{
    NumberOfScenes = inNumberOfScenes;
    CurrentScene = 1;
}
void VideoDVD::LoadMedia(const string &InTitle,
               const string & InArtist,
               const string & InWherePurchased,
               const float & InCost,
               const Time & InRunningTime,
               const int & inNumberOfScenes,
               const int & inCurrentScene)
{
    Media::LoadMedia(InTitle,
                     InArtist,
                     InWherePurchased,
                     InCost,
                     InRunningTime,
                     inNumberOfScenes,
                     inCurrentScene);
    NumberOfScenes = inNumberOfScenes;
    CurrentScene = inCurrentScene;
}


string VideoDVD::GetTitle() const{return Media::Title;}
string VideoDVD::GetArtist() const{return Media::Artist;}
string VideoDVD::GetWherePurchased() const{return Media::WherePurchased;}
float VideoDVD::GetCost() const{return Media::Cost;}
Time VideoDVD::GetRunningTime() const{return Media::RunningTime;}
int VideoDVD::GetNumberOfScenes() const{return NumberOfScenes;}
int VideoDVD::GetCurrentScene() const{return CurrentScene;}



void VideoDVD::Play()
{
    if (Media::IsMediaAtEnd(NumberOfScenes, NumberOfScenes))
    {
        cout << "Cannot Play! ----> " << Media::Title << "Must Rewind First\n";}
        else
        {
            cout << "<---Playing Track: " << VideoDVD::CurrentScene <<"--->\n";
            
        }
}
        
void VideoDVD::FastForward()
{
    if (Media::IsMediaAtEnd(CurrentScene, NumberOfScenes))
    {
        cout << "Cannot Fast Forward! ----> " << Media::Title << "Must Rewind First\n";
        
    }
    else
    {
        VideoDVD::CurrentScene ++;
        cout << "<---Fast Forwarding to Track: " << VideoDVD::CurrentScene << "--->\n";
    }
}

void VideoDVD::Rewind()
{
    if (Media::IsMediaAtBeginning(CurrentScene))
    {
        cout << "Cannot Rewind! ----> " << Media::Title << " Already on first track.\n";
        
        }
        else
        {
            VideoDVD::CurrentScene --;
            cout << "<---Rewinding to track: " << VideoDVD::CurrentScene << "--->\n";
        }
    }
void VideoDVD::PrintMedia(ostream & Out) const
//// Displays media type, calls parent to display inherited members, then
////   displays NumberOfScenes
{
    cout << "\nType:      Video DVD\n";
    Media::PrintMedia(Out);
    cout << "Tracks:    " << NumberOfScenes << endl << endl;
    }



