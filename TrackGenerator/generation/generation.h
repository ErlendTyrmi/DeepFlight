//
// Created by malte on 09-Apr-20.
//

#ifndef TRACKGENERATOR_GENERATOR_H
#define TRACKGENERATOR_GENERATOR_H

#include "../model/planet.h"
#include "../model/track.h"

Track* generateTrackFromSeed(Planet *planet, TrackList *existingTracks, unsigned int seed);

Track* generateTrack(Planet *planet, TrackList *existingTracks);




typedef struct Node{
    struct Node* next;
    int x;
    int y;
    float direction;
} Node;


typedef struct NodePool{
    struct NodePool* next;
    Node* nodes;
    int used;
    unsigned int size;
} NodePool;


Node* NodePool_getNode(NodePool* pool);

int NodePool_totalUsed(NodePool*);

NodePool* NodePool_create(unsigned int size);

void NodePool_free(NodePool* pool);



#endif //TRACKGENERATOR_GENERATOR_H
