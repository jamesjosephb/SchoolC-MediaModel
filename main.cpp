//
//  main.cpp
//  Lab 5
//
//  Created by JamesJoseph Burch on 12/3/17.
//  Copyright © 2017 JamesJoseph Burch. All rights reserved.
//

//#include <iostream>
#include "MediaCollection.hpp"


int main(int argc, const char * argv[]) {

    

//    MediaType media;
//    media = AUDIO_CASSETTE;
//    cout << media << endl << endl;
//
//    MediaCollection a("do");
//    //cout << a.GetCurrentMCSize() << endl << endl;
//    a.AddMedia(VIDEO_DVD, "Josie", "Saves the Day", "Amazon", 10.22, 40, 10, 7);
//    a.AddMedia(VIDEO_VHS, "Toto", "Saves the Day", "Amazon", 10.22, 40, 10, 7);
//    a.AddMedia(AUDIO_CD, "Jimmy", "Saves", "Amazon", 10.22, 40, 10, 7);
//    a.PrintAllMediaDetails();
//    //a.DeleteMedia(1);
//    a.printArray();
//    //a.ListMediaTitles();
//    cout << endl;
//    int s;
//    s = a.getSelection();
//    //a.DeleteMedia(s);
//    a.printArray();
//
//    a.Play(1);
//
//};
    
    int Selection;
    string collection;
    
    int running = 1;

    cout << "What is the name of this Media Collection? \nEnter: ";
    cin >> collection;
    MediaCollection a(collection);
    a.AddMedia(VIDEO_DVD, "Josie", "Saves the Day", "Amazon", 10.22, 40, 10, 7);
    a.AddMedia(VIDEO_VHS, "Toto", "Saves the Day", "Amazon", 10.22, 40, 10, 7);
    a.AddMedia(AUDIO_CD, "Jimmy", "Saves", "Amazon", 10.22, 40, 10, 7);


    while(running == 1) {
    cout << "\n-----------------------------------------------------------\n";
    cout << "<<<<<<<   " << collection << " Media Collection Menu   >>>>>>>\n\n";
        cout << "______________________Current Collection_____________________\n\n";
    a.printArray();
    cout << "\n\nSelect from the following choices:\n"
    "1.     Add Media Item to Collection\n"
    "2.     Delete Media Item from Collection\n"
    "3.     Play a Selection\n"
    "4.     Fast Forward a Selection\n"
    "5.     Rewind a Selection\n"
    "6.     List a Specific Media’s Details\n"
    "7.     List All Media Titles\n"
    "8.     Calculate Media Collection Investment\n"
    "9.     Calculate Total Playing Time of Collection\n"
    "10.    Terminate the Simulation\n\n"

    "\n-----------------------------------------------------------\n"
    "Enter your Selection: ";
    
        cin >> Selection;
        if (Selection == 1) {
            MediaType type;
            int media;
            string title;
            string artist;
            string wherePurchased;
            float cost;
            int runningTime;
            int numberOfSelections;
            int currentSelection;
            cout << "\n---------------------------------------------\n";
            cout << "Adding media to " << collection << "!!\n";
            cout << "Enter the following fields.\n";
            cout << "What type of media: \n1) Cassette \n2) CD \n3) VHS \n4) DVD \nSelect Number associated with type: ";
            cin >> media;
            if (media == 1){type = AUDIO_CASSETTE;}
            else if (media == 2){type = AUDIO_CD;}
            else if (media == 3){type = VIDEO_VHS;}
            else if (media == 4){type = VIDEO_DVD;}
            //MediaType {AUDIO_CASSETTE = 1, AUDIO_CD = 2, VIDEO_VHS = 3, VIDEO_DVD = 4};
            cout << "Title: "; cin >> title;
            cout << "Artist: "; cin >> artist;
            cout << "Purchased: "; cin >> wherePurchased;
            cout << "Cost: $"; cin >> cost;
            cout << "Running Time: "; cin >> runningTime;
            cout << "Number of Selectons :"; cin >> numberOfSelections;
            cout << "Current Selection :"; cin >> currentSelection;


            a.AddMedia(type,
                       title,
                       artist,
                       wherePurchased,
                       cost,
                       runningTime,
                       numberOfSelections,
                       currentSelection);
            
            
        }
        else if (Selection == 2) {
            int deleting;
            cout << "Select the media to be deleted:\nSelect 1-5----->Enter:";
            cin >> deleting;
            a.DeleteMedia(deleting-1);
            
            
        }
        else if (Selection == 3) {
            int playing;
            cout << "Select a media to play:\nSelect 1-5----->Enter:";
            cin >> playing;
            a.Play(playing - 1);
            

        }
        else if (Selection == 4) {
            int FF;
            cout << "Select a media to Fast Forward:\nSelect 1-5----->Enter:";
            cin >> FF;
            a.FastForward(FF - 1);
            
        }
        else if (Selection == 5) {
            int Rewind;
            cout << "Select a media to Rewind:\nSelect 1-5----->Enter:";
            cin >> Rewind;
            a.Play(Rewind - 1);
            
        }
        else if (Selection == 6) {
            int Details;
            cout << "Select the media you would like to view ther details of:\nSelect 1-5----->Enter:";
            cin >> Details;
            a.PrintAMediaDetail(Details - 1);
            

        }
        else if (Selection == 7) {
            cout << "These are the current title's in the media collection:\n";
            a.ListMediaTitles();
            Dor
            
        }
        else if (Selection == 8) {
            cout << "These are the current title's in the media collection:\n";
            cout << "Total: $" << a.CalculateMediaCollectionInvestment();
            
        }
        
        else if(Selection == 9){
            cout << "This is the total Playing Time of the media collection\n";
            cout << "Total Min: " << a.CalculateTotalCollectionPlayingTime();
            
            
        }
        
        else if(Selection == 10){
            exit(0);
            
        }
        
    }
};






    
    
    

    
    
    





