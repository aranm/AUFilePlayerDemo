//
//  PlayFile.h
//  iOSfilePlayer
//
//  Created by Aran Mulholland on 2/11/11.
//  Copyright (c) 2011 None. All rights reserved.
//

#ifndef iOSfilePlayer_PlayFile_h
#define iOSfilePlayer_PlayFile_h

#include <AudioToolbox/AudioToolbox.h>
#include <AudioUnit/AudioUnit.h>

#include "CAXException.h"
#include "CAStreamBasicDescription.h"

class PlayFile {
    AUGraph theGraph;
	AudioUnit fileAU;
    AudioUnit remoteIOUnit;
    AudioFileID audioFile;
    
    UInt32 startFrame;
    
public:
    
    PlayFile(CFURLRef theURL);
    ~PlayFile();
    void setTrackPosition(float position);
    Float64 getTrackPosition();
    float getTrackRelativePosition();
    Float64 getTrackTotalLength();
};

#endif
