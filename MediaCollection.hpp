//
//  MediaCollection.hpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

#ifndef MediaCollection_hpp
#define MediaCollection_hpp

#include <stdio.h>
#include <array>
#include <memory>

#include "Media.hpp"
#include "AudioCassette.hpp"
#include "AudioCD.hpp"
#include "VideoVHS.hpp"
#include "VideoDVD.hpp"

const int MEDIA_COLLECTION_SIZE = 5;
enum MediaType {AUDIO_CASSETTE = 1, AUDIO_CD = 2, VIDEO_VHS = 3, VIDEO_DVD = 4};

class MediaCollection
{
public:
    MediaCollection(string inCollectionName);
    //~MediaCollection();  // not needed if we use container of  “smart” pointers
    void AddMedia(const MediaType & inMedia,
                  const string &InTitle,
                  const string & InArtist,
                  const string & InWherePurchased,
                  const float & InCost,
                  const Time & InRunningTime,
                  const int & inNumberOfSelections,
                  const int & inCurrentSelection);
    void ListMediaTitles() const;
    void DeleteMedia(const int & mediaInCollection);
    void Play(const int & mediaInCollection);
    void FastForward(const int & mediaInCollection);
    void Rewind(const int & mediaInCollection);
    void PrintAllMediaDetails() const;
    void PrintAMediaDetail(const int & mediaInCollection) const;
    float CalculateMediaCollectionInvestment() const;
    int CalculateTotalCollectionPlayingTime() const;
    string GetCollectionName() const;
    int GetCurrentMCSize() const;
    
    void printArray();
    int getSelection();
    

    

protected:
    void DisplayMediaTypeMenu() const;
    MediaType GetMediaTypeSelection() const;
    
    
private:
    string CollectionName;
    array<unique_ptr<Media>, MEDIA_COLLECTION_SIZE > TheCollection;
    int CurrentMCSize;

};

#endif /* MediaCollection_hpp */
