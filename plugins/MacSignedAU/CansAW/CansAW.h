/*
*	File:		CansAW.h
*	
*	Version:	1.0
* 
*	Created:	1/28/25
*	
*	Copyright:  Copyright � 2025 Airwindows, Airwindows uses the MIT license
* 
*	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc. ("Apple") in 
*				consideration of your agreement to the following terms, and your use, installation, modification 
*				or redistribution of this Apple software constitutes acceptance of these terms.  If you do 
*				not agree with these terms, please do not use, install, modify or redistribute this Apple 
*				software.
*
*				In consideration of your agreement to abide by the following terms, and subject to these terms, 
*				Apple grants you a personal, non-exclusive license, under Apple's copyrights in this 
*				original Apple software (the "Apple Software"), to use, reproduce, modify and redistribute the 
*				Apple Software, with or without modifications, in source and/or binary forms; provided that if you 
*				redistribute the Apple Software in its entirety and without modifications, you must retain this 
*				notice and the following text and disclaimers in all such redistributions of the Apple Software. 
*				Neither the name, trademarks, service marks or logos of Apple Computer, Inc. may be used to 
*				endorse or promote products derived from the Apple Software without specific prior written 
*				permission from Apple.  Except as expressly stated in this notice, no other rights or 
*				licenses, express or implied, are granted by Apple herein, including but not limited to any 
*				patent rights that may be infringed by your derivative works or by other works in which the 
*				Apple Software may be incorporated.
*
*				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO WARRANTIES, EXPRESS OR 
*				IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY 
*				AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE 
*				OR IN COMBINATION WITH YOUR PRODUCTS.
*
*				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL 
*				DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
*				OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, 
*				REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER 
*				UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN 
*				IF APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
#include "AUEffectBase.h"
#include "CansAWVersion.h"

#if AU_DEBUG_DISPATCHER
	#include "AUDebugDispatcher.h"
#endif


#ifndef __CansAW_h__
#define __CansAW_h__


#pragma mark ____CansAW Parameters

// parameters

static CFStringRef kParameterAName = CFSTR("seatPos");

static const int kA = 0;
static const int kB = 1;
static const int kC = 2;
static const int kD = 3;
static const int kDefaultValue_ParamA = kB;
static CFStringRef kMenuItem_A = CFSTR ("Bypass");
static CFStringRef kMenuItem_B = CFSTR ("UpFront");
static CFStringRef kMenuItem_C = CFSTR ("SitBack");
static CFStringRef kMenuItem_D = CFSTR ("Hallway");

enum {
	kParam_A =0,
	//Add your parameters here...
	kNumberOfParameters=1
};

const int kshortA = 193;
const int kshortB = 464;
const int kshortC = 422;
const int kshortD = 36;
const int kshortE = 166;
const int kshortF = 427;
const int kshortG = 162;
const int kshortH = 476;
const int kshortI = 23;
const int kshortJ = 345;
const int kshortK = 298;
const int kshortL = 296;
const int kshortM = 12;
const int kshortN = 989;
const int kshortO = 65;
const int kshortP = 484;

#pragma mark ____CansAW
class CansAW : public AUEffectBase
{
public:
	CansAW(AudioUnit component);
#if AU_DEBUG_DISPATCHER
	virtual ~CansAW () { delete mDebugDispatcher; }
#endif
	
	virtual ComponentResult Reset(AudioUnitScope inScope, AudioUnitElement inElement);

	virtual OSStatus ProcessBufferLists(AudioUnitRenderActionFlags & ioActionFlags, 
						const AudioBufferList & inBuffer, AudioBufferList & outBuffer, 
						UInt32 inFramesToProcess);
	virtual UInt32 SupportedNumChannels(const AUChannelInfo ** outInfo);

	virtual	ComponentResult		GetParameterValueStrings(AudioUnitScope			inScope,
														 AudioUnitParameterID		inParameterID,
														 CFArrayRef *			outStrings);
    
	virtual	ComponentResult		GetParameterInfo(AudioUnitScope			inScope,
												 AudioUnitParameterID	inParameterID,
												 AudioUnitParameterInfo	&outParameterInfo);
    
	virtual ComponentResult		GetPropertyInfo(AudioUnitPropertyID		inID,
												AudioUnitScope			inScope,
												AudioUnitElement		inElement,
												UInt32 &			outDataSize,
												Boolean	&			outWritable );
	
	virtual ComponentResult		GetProperty(AudioUnitPropertyID inID,
											AudioUnitScope 		inScope,
											AudioUnitElement 		inElement,
											void *			outData);

	virtual ComponentResult    Initialize();
	virtual bool				SupportsTail () { return true; }
    virtual Float64				GetTailTime() {return (1.0/GetSampleRate())*0.0;} //in SECONDS! gsr * a number = in samples
    virtual Float64				GetLatency() {return (1.0/GetSampleRate())*0.0;}	// in SECONDS! gsr * a number = in samples
	
	/*! @method Version */
	virtual ComponentResult		Version() { return kCansAWVersion; }
	
private: 
	double aAL[kshortA+5];
	double aBL[kshortB+5];
	double aCL[kshortC+5];
	double aDL[kshortD+5];
	double aEL[kshortE+5];
	double aFL[kshortF+5];
	double aGL[kshortG+5];
	double aHL[kshortH+5];
	double aIL[kshortI+5];
	double aJL[kshortJ+5];
	double aKL[kshortK+5];
	double aLL[kshortL+5];
	double aML[kshortM+5];
	double aNL[kshortN+5];
	double aOL[kshortO+5];
	double aPL[kshortP+5];
	
	double aAR[kshortA+5];
	double aBR[kshortB+5];
	double aCR[kshortC+5];
	double aDR[kshortD+5];
	double aER[kshortE+5];
	double aFR[kshortF+5];
	double aGR[kshortG+5];
	double aHR[kshortH+5];
	double aIR[kshortI+5];
	double aJR[kshortJ+5];
	double aKR[kshortK+5];
	double aLR[kshortL+5];
	double aMR[kshortM+5];
	double aNR[kshortN+5];
	double aOR[kshortO+5];
	double aPR[kshortP+5];
	
	double feedbackAL;
	double feedbackBL;
	double feedbackCL;
	double feedbackDL;
	double feedbackAR;
	double feedbackBR;
	double feedbackCR;
	double feedbackDR;
	
	double iirInL;
	double iirFAL;
	double iirFBL;
	double iirFCL;
	double iirFDL;
	double iirOutL;
	double iirInR;
	double iirFAR;
	double iirFBR;
	double iirFCR;
	double iirFDR;
	double iirOutR;
	
	int countA;
	int countB;
	int countC;
	int countD;
	int countE;
	int countF;
	int countG;
	int countH;
	int countI;
	int countJ;
	int countK;
	int countL;		
	int countM;		
	int countN;		
	int countO;		
	int countP;		
	
	int shortA;
	int shortB;
	int shortC;
	int shortD;
	int shortE;
	int shortF;
	int shortG;
	int shortH;
	int shortI;
	int shortJ;
	int shortK;
	int shortL;
	int shortM;
	int shortN;
	int shortO;
	int shortP;
		
	enum {
		bez_AL,
		bez_AR,
		bez_BL,
		bez_BR,
		bez_CL,
		bez_CR,	
		bez_InL,
		bez_InR,
		bez_UnInL,
		bez_UnInR,
		bez_SampL,
		bez_SampR,
		bez_cycle,
		bez_total
	}; //the new undersampling. bez signifies the bezier curve reconstruction
	double bez[bez_total];
	
	uint32_t fpdL;
	uint32_t fpdR;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif