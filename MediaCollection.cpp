//
//  MediaCollection.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#include "MediaCollection.hpp"


MediaCollection::MediaCollection(string inCollectionName)
{
    CollectionName = inCollectionName;
    array<unique_ptr<Media>, MEDIA_COLLECTION_SIZE > TheCollection;
    CurrentMCSize = MEDIA_COLLECTION_SIZE;
    
    //Below I am just adding 5 items into the array of pointers to simulate that the collection already has 5 Media to start with.
    
}


int MediaCollection::GetCurrentMCSize() const
{
    int a = 0;
    int b = (sizeof(TheCollection));
    int c = (sizeof(&TheCollection));
    //int d = (sizeof(TheCollection[0]));
    //int e = (sizeof(&TheCollection[0]));
    a = b/c;
    return (a);
}

void MediaCollection::AddMedia(const MediaType & inMedia,
                               const string &InTitle,
                               const string & InArtist,
                               const string & InWherePurchased,
                               const float & InCost,
                               const Time & InRunningTime,
                               const int & inNumberOfSelections,
                               const int & inCurrentSelection)
{
    for (int i = 0; i < 5; i++)
        {
        if (NULL == TheCollection[i])
        {
            if (inMedia == 1)
            {
                //unique_ptr<AudioCassette> Cassette(new AudioCassette);
                //unique_ptr<Media> tCassette(new AudioCassette);
                TheCollection[i] = unique_ptr<Media>(new AudioCassette);
                TheCollection[i]-> LoadMedia(InTitle,
                                             InArtist,
                                             InWherePurchased,
                                             InCost,
                                             InRunningTime,
                                             inNumberOfSelections,
                                             inCurrentSelection);
                //TheCollection[0]-> PrintMedia(cout);
                CurrentMCSize++;
                break;
            }
            else if (inMedia == 2)
            {
                TheCollection[i] = unique_ptr<Media>(new AudioCD);
                TheCollection[i]-> LoadMedia(InTitle,
                                             InArtist,
                                             InWherePurchased,
                                             InCost,
                                             InRunningTime,
                                             inNumberOfSelections,
                                             inCurrentSelection);
                //TheCollection[0]-> PrintMedia(cout);
                CurrentMCSize++;
                break;
            }
            else if (inMedia == 3)
            {
                TheCollection[i] = unique_ptr<Media>(new VideoVHS);
                TheCollection[i]-> LoadMedia(InTitle,
                                             InArtist,
                                             InWherePurchased,
                                             InCost,
                                             InRunningTime,
                                             inNumberOfSelections,
                                             inCurrentSelection);
                //TheCollection[0]-> PrintMedia(cout);
                CurrentMCSize++;
                break;
            }
            else if (inMedia == 4)
            {
                TheCollection[i] = unique_ptr<Media>(new VideoDVD);
                TheCollection[i]-> LoadMedia(InTitle,
                                             InArtist,
                                             InWherePurchased,
                                             InCost,
                                             InRunningTime,
                                             inNumberOfSelections,
                                             inCurrentSelection);
                //TheCollection[0]-> PrintMedia(cout);
                CurrentMCSize++;
                break;
}}}}

void MediaCollection::PrintAllMediaDetails() const
{
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i]){TheCollection[i]-> PrintMedia(cout);}
    }
}
void MediaCollection::PrintAMediaDetail(const int & mediaInCollection)const{TheCollection[mediaInCollection]-> PrintMedia(cout);}


    
    
    
    
    
    
    
    
//    if (TheCollection[i]){cout << "Not Null" << endl;}
//
//    for (int i = 0; i < 5; i++)
//    {
//        cout << Media::Title <<
//    }
//
//
//
//        cout << "Title:     " << Media::Title <<
//        "\nArtist:    " << Media::Artist <<
//        "\nPurchased: " <<  Media::WherePurchased <<
//        "\nCost:      $" <<  Media::Cost << endl;
//
//
//
//
//
//        if (TheCollection[i]){cout << "Not Null" << endl;}
//        else cout << " Null" << endl;
//        //cout << i+1 << ")";
//        //TheCollection[i]-> PrintMedia(cout);
    


void MediaCollection::DeleteMedia(const int & mediaInCollection)
{
    TheCollection[mediaInCollection].reset();
}

void MediaCollection::ListMediaTitles() const
{
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i])
        {
            cout << i+1 << ")" << TheCollection[i]->GetTitle() << endl;
        }
    }
}

int MediaCollection::getSelection()
{
    for (int i = 0; i < 5; i++)
        {
            if (TheCollection[i])
            {
                cout << i+1 << ") " << TheCollection[i]-> GetTitle() << endl;
            }
            else if (NULL == TheCollection[i])
            {
                cout << i+1 << ") ---Empty---" << endl;
            }
        }
    cout << "Select the Media: ";
    int Selection;
    cin >> Selection;
    
    while (Selection < 5 || Selection > 0)
    {
        if (Selection == 1) {
            return Selection-1;
        }
        else if (Selection == 2) {
            return Selection-1;
        }
        else if (Selection == 3) {
            return Selection-1;
        }
        else if (Selection == 4) {
            return Selection-1;
        }
        else if (Selection == 5) {
            return Selection-1;
        }
        cout << "\nINVALID! --Re Enter: ";
        cin >> Selection;
    }
}

void MediaCollection::Play(const int & mediaInCollection)
{
    TheCollection[mediaInCollection]->Play();
}

void MediaCollection::Rewind(const int & mediaInCollection)
{
    TheCollection[mediaInCollection]->Rewind();
}

void MediaCollection::FastForward(const int & mediaInCollection)
{
    TheCollection[mediaInCollection]->FastForward();
}




void MediaCollection::printArray()
{
    cout << "Media:       ";
    for (int i = 0; i < 5; i++)
    {
        string temp = " ";
        while (temp.size() < 14)
        {
            
            temp.append(" ");
        }
        cout << "-" << i+1 << "-" << temp.append(" ");
    }
    
    
    
    cout << "\nTitle:       ";
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i])
        {
            string temp = "";
            while (TheCollection[i]-> GetTitle().size() + temp.size() < 17)
            {
                
                temp.append(" ");
            }
            cout << TheCollection[i]-> GetTitle() << temp.append(" ");
            
        }
        else //(NULL != TheCollection[i])
        {
            string temp = "    ";
            while (4 + temp.size() < 18)
            {
                temp.append(" ");
            }
            cout << "NULL" << temp.append(" ");
        }
    }
    
    
    
    cout << "\nArtist:      ";
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i])
        {
            string temp = "";
            while (TheCollection[i]-> GetArtist().size() + temp.size() < 17)
            {
                
                temp.append(" ");
            }
            cout << TheCollection[i]-> GetArtist() << temp.append(" ");
            
        }
        else //(NULL != TheCollection[i])
        {
            string temp = "    ";
            while (4 + temp.size() < 17)
            {
                temp.append(" ");
            }
            cout << "NULL" << temp.append(" ");
        }
    }
    
    
    
    
    cout << "\nPurchased:   ";
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i])
        {
            string temp = "";
            while (TheCollection[i]-> GetWherePurchased().size() + temp.size() < 17)
            {
                
                temp.append(" ");
            }
            cout << TheCollection[i]-> GetWherePurchased() << temp.append(" ");
            
        }
        else //(NULL != TheCollection[i])
        {
            string temp = "    ";
            while (4 + temp.size() < 17)
            {
                temp.append(" ");
            }
            cout << "NULL" << temp.append(" ");
        }
    }
    
    
    cout << "\nCost:        ";
    for (int i = 0; i < 5; i++)
    {
        if (TheCollection[i])
        {
            string temp = "";
            while (6 + temp.size() < 17)
            {
                
                temp.append(" ");
            }
            cout << "$" << TheCollection[i]-> GetCost() << temp.append(" ");
            
        }
        else //(NULL != TheCollection[i])
        {
            string temp = "    ";
            while (4 + temp.size() < 17)
            {
                temp.append(" ");
            }
            cout << "NULL" << temp.append(" ");
        }
    }
    cout << endl;
}


float MediaCollection::CalculateMediaCollectionInvestment() const
{
    float Total = 0;
    for (int i = 0; i < 5; i++)
    {
        if (NULL != TheCollection[i])
        {
            Total += TheCollection[i]->GetCost();
        }
    }
    return Total;
    
}

int MediaCollection::CalculateTotalCollectionPlayingTime() const
{
    int TotalTime = 0;

    for (int i = 0; i < 5; i++)
    {
        if (NULL != TheCollection[i])
        {
            
            TotalTime += TheCollection[i]->GetRunningTime().GetTime();
        }
    }
    return TotalTime;
    
}

