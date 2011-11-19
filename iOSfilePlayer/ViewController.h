//
//  ViewController.h
//  iOSfilePlayer
//
//  Created by Aran Mulholland on 2/11/11.
//  Copyright (c) 2011 None. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PlayFile.h"

@interface ViewController : UIViewController {
    PlayFile *playFile;
    BOOL isSliding;
}

@property (nonatomic, strong) IBOutlet UILabel *timeLabel;
@property (nonatomic, strong) IBOutlet UISlider *timeSlider;

-(IBAction)setTrackPosition:(UISlider *)sender;

@end
