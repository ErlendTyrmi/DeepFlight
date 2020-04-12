//
// Created by malte on 09-Apr-20.
//

#include <stdio.h>
#include <malloc.h>

#include "track.h"

Track* Track_create(){
    Track* track = (Track*) calloc(1, sizeof(Track)) ;
    return track;
}

void Track_free(Track* track){
    if( track->data != NULL ){
        free(track->data);
    }

    if( track->image != NULL ) {
        free(track->image);
    }
}

void Track_print(Track *track){
    printf(
            "Track( id=%lld, name='%s', planet='%s', seed=%lld, length=%0.f, checkpoints=%d, startDir=%0.3f, data=%0.3fmb,  )",
            track->id, track->name, track->planet->name, track->seed, track->length, track->numCheckpoints, track->startDirection, track->data_size/1000000.0
    );
}


void Track_saveToFile(Track* track, const char* fileName){
    FILE *file = fopen(fileName, "wb");

    // ID
    fwrite(&track->id, 8, 1, file);

    // Name
    char* c = track->name;
    while(*c != '\0'){
        fwrite(c, sizeof(char), 1, file);
        c++;
    }
    fwrite(c, sizeof(char), 1, file); // Append null


    // TODO: Add remaining Track data


    // Starting position
    fwrite(&track->startingX, sizeof(int), 1, file);
    fwrite(&track->startingY, sizeof(int), 1, file);

    // Starting direction
    fwrite(&track->startDirection, sizeof(double), 1, file);

    if( track->data == NULL )
        printf("WARNING: Track data is NULL\n");
    else{
        fwrite(track->data, sizeof(char), track->data_size, file);
    }

    fclose(file);


    /*// Seed
    fwrite(&track->seed, sizeof(long), 1, file);

    // Planet
    fwrite(&track->id, sizeof(long), 1, file);

    // Planet
    Planet* planet = track->planet;
    if( planet != NULL){
        fwrite(, sizeof(long), 1, file);
    }
    fwrite(polanet, sizeof(long), 1, file);
*/






}

