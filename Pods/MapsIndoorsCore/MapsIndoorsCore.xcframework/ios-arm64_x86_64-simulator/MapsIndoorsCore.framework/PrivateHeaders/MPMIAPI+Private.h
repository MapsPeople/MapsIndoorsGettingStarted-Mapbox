//
//  MPMIAPI.h
//  MapsIndoors
//
//  Created by Michael Bech Hansen on 19/09/2017.
//  Copyright © 2015-2017 MapsPeople A/S. All rights reserved.
//

#import "MPMIAPI.h"
@import MapsIndoors;

NS_ASSUME_NONNULL_BEGIN

static NSString* const kMPMI_EndPointGraph = @"graph";
static NSString* const kMPMI_EndPointLocation = @"locations";
static NSString* const kMPMI_EndPointVenue = @"venues";
static NSString* const kMPMI_EndPointBuilding = @"buildings";
static NSString* const kMPMI_EndPointSolution = @"solutions";
static NSString* const kMPMI_EndPointAppData = @"appconfig";
static NSString* const kMPMI_EndPointCategory = @"categories";
static NSString* const kMPMI_EndPointTile = @"tiles";
static NSString* const kMPMI_EndPointUserRole = @"appuserroles";
static NSString* const kMPMI_EndPointRouteLayer = @"routelayer";
static NSString* const kMPMI_EndPointDataSet = @"dataset";
static NSString* const kMPMI_EndPointDerivedGeometry = @"derivedGeometry";

typedef void (^RefreshSessionCompletionBlock)(void);

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPMIAPI (Private)

#pragma mark - Private API
- (void) refreshSessionWithCompletion:(nullable RefreshSessionCompletionBlock)completion;

- (BOOL) isMapsIndoorsBackendUrl:(nullable NSString*)url;
- (nullable NSString*) urlByNormalizingMapsIndoorsBackendUrls:(nullable NSString*)url;
- (BOOL) isEqualMapsIndoorsBackendUrl:(nullable NSString*)url1 toUrl:(nullable NSString*)url2;

@end


NS_ASSUME_NONNULL_END
