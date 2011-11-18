//
//  ViewController.m
//  iOSfilePlayer
//
//  Created by Aran Mulholland on 2/11/11.
//  Copyright (c) 2011 None. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize timeLabel;

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    
    
    
    NSURL *fileUrl = [NSURL fileURLWithPath:[[NSBundle mainBundle] pathForResource:@"808 loop" ofType:@"wav"]];	
    playFile = new PlayFile((__bridge CFURLRef)fileUrl);
    
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

-(void)updateUI {
    [timeLabel setText:[NSString stringWithFormat:@"%.2f", playFile->getTrackPosition()]];
}

-(void)runLoop{
	//grab the current thread
	NSThread *currentThread = [NSThread currentThread];
	
	//check if the thread has been cancelled, much nicer than just killing it
	while ([currentThread isCancelled] == NO){
		//redraw
		[self performSelectorOnMainThread:@selector(updateUI) withObject:nil waitUntilDone:NO];
		
		//sleep the thread
		[NSThread sleepForTimeInterval:1.0/30.0];
	}
}

- (void)viewDidAppear:(BOOL)animated
{
    NSThread *runLoopThread = [[NSThread alloc]initWithTarget:self selector:@selector(runLoop) object:nil];
	[runLoopThread start];
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

-(IBAction)setTrackPosition:(UISlider *)sender{
    playFile->setTrackPosition(sender.value);
}

@end
