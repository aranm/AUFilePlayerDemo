//
//  AudioComponentDescriptionHelper.h
//  DJMixer
//
//  Created by Aran Mulholland on 4/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef DJMixer_AudioComponentDescriptionHelper_h
#define DJMixer_AudioComponentDescriptionHelper_h

#include <AudioUnit/AUComponent.h>

AudioComponentDescription getRemoteIODescription();
AudioComponentDescription getFilePlayerDescription();
AudioComponentDescription getMultiChannelMixerDescription();
AudioComponentDescription getVarispeedDescription();   


AudioComponentDescription getRemoteIODescription(){
    AudioComponentDescription remoteIODescription = {0};
    
    remoteIODescription.componentFlags = 0;
    remoteIODescription.componentFlagsMask = 0;
    remoteIODescription.componentType = kAudioUnitType_Output;
    remoteIODescription.componentSubType = kAudioUnitSubType_RemoteIO;
    remoteIODescription.componentManufacturer = kAudioUnitManufacturer_Apple;
    
    return remoteIODescription;
}

AudioComponentDescription getFilePlayerDescription(){
    AudioComponentDescription filePlayerDescription = {0};
    
    filePlayerDescription.componentType = kAudioUnitType_Generator;
    filePlayerDescription.componentSubType = kAudioUnitSubType_AudioFilePlayer;
    filePlayerDescription.componentManufacturer = kAudioUnitManufacturer_Apple;
    filePlayerDescription.componentFlags = 0;
    filePlayerDescription.componentFlagsMask = 0;
    
    return filePlayerDescription;
}


AudioComponentDescription getMultiChannelMixerDescription(){
    AudioComponentDescription mixerDescription = {0};
    
    mixerDescription.componentFlags = 0;
    mixerDescription.componentFlagsMask = 0;
    mixerDescription.componentType = kAudioUnitType_Mixer;
    mixerDescription.componentSubType = kAudioUnitSubType_MultiChannelMixer;
    mixerDescription.componentManufacturer = kAudioUnitManufacturer_Apple;
    
    return mixerDescription;
}

AudioComponentDescription getVarispeedDescription() {
    AudioComponentDescription varispeedDescription = {0};
    
    varispeedDescription.componentFlags = 0;
    varispeedDescription.componentFlagsMask = 0;
    varispeedDescription.componentType = kAudioUnitType_FormatConverter;
    varispeedDescription.componentSubType = kAudioUnitSubType_Varispeed;
    varispeedDescription.componentManufacturer = kAudioUnitManufacturer_Apple;
    
    return varispeedDescription;  
}

#endif
