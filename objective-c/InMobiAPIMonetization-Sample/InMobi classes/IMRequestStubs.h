//
//  IMStubs.h
//  Native ad sample
//
// This class is split into various data structures,
// based on the JSON request format of InMobi API 2.0
// Visit https://www.inmobi.com/support/art/26555436/22465648/api-2-0-integration-guidelines/


#import <Foundation/Foundation.h>
#import "IMUtils.h"
#import "IMValidator.h"
#import <CoreLocation/CoreLocation.h>
/**
 * Gender type description. Use this object to send user gender info.
 */
typedef enum {
    IMGenderMale,
    IMGenderFemale,
    IMGenderNone
} IMGender;

typedef enum {
    IMAdRequestTypeNone,
    IMAdRequestTypeBanner,
    IMAdRequestTypeInterstitial,
    IMAdRequestTypeNative
} IMAdRequestType;

@class IMRequest;
/**
 * Internal object, used to store property Id
 */
@interface IMProperty : NSObject <IMValidator>
/*
 * The Property ID, as obtained from Inmobi.
 */
@property(nonatomic,copy) NSString *propertyId;
- (id)initWithPropertyID:(NSString *)ID;
@end


/*
 * This class stores the 'imp' object, as part of the InMobi API 2.0
 */
@class IMSlot;
@interface IMImpression : NSObject <IMValidator>

@property(nonatomic,assign) int noOfAds;
@property(nonatomic,assign) BOOL isInterstitial;
@property(nonatomic,retain) IMSlot *slot;
@property(nonatomic,retain) NSString *displayManager,*displayManagerVersion;
- (id)initWithSlot:(IMSlot *)slot;
@end
@class IMGeo;
/*
 * This class stores the 'device' object, as part of InMobi API 2.0
 */
@interface IMDevice : NSObject <IMValidator>

@property(nonatomic,copy) NSString *carrierIP;
@property(nonatomic,readonly) NSString *userAgent;
@property(nonatomic,readonly) NSString *IDFA,*IDV;
@property(nonatomic,assign) int adt;
@property(nonatomic,retain) IMGeo *geo;

- (id)initWithCarrierIP:(NSString *)ip;

@end

/*
 * This class stores the 'geo' object, within the 'device' object.
 */
@interface IMGeo : NSObject <IMValidator>
@property(nonatomic,assign) double lat,lon;
@property(nonatomic,assign) int accu;
- (void)setLocation:(CLLocation *)location;
@end

@class IMData;
/*
 * This class stores the 'user' object, as part of InMobi API 2.0
 */
@interface IMUser : NSObject <IMValidator>

@property(nonatomic,assign) int yob;
@property(nonatomic,assign) IMGender gender;
@property(nonatomic,retain) IMData *dataObj;
@end
/*
 * This class store the required banner info, as part of the 'imp' object
 */
@interface IMSlot : NSObject <IMValidator>

@property(nonatomic,assign) int adSize;
//optional
@property(nonatomic,copy) NSString *position;
- (id)initWithAdSize:(int)size pos:(NSString *)pos;
@end


@class IMUserSegment;
/*
 * This class stores the 'data' object, within the 'user' object
 */
@interface IMData : NSObject <IMValidator>

@property(nonatomic,assign) int ID;
@property(nonatomic,copy) NSString *name;
@property(nonatomic,retain) IMUserSegment *segmentObj;
@end

/*
 * This class stores the 'segment' object, within the 'data' object
 */
@interface IMUserSegment : NSObject <IMValidator>
@property(nonatomic,retain) NSArray *userSegmentArray;
@end