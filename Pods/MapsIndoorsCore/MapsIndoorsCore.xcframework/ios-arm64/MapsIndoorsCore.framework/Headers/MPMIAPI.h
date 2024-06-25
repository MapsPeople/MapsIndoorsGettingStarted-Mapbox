//
//  MPMIAPI.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 15/08/16.
//  Copyright © 2015-2017 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - [INTERNAL - DO NOT USE]
@import MapsIndoors;

@class MPUserRole;
@class MPAuthDetails;

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPMIAPI : NSObject

+ (instancetype) sharedInstance;

+ (NSString*) baseUrl;

#pragma mark - Session info
@property (nonatomic, strong, readonly, nonnull) NSString*      currentBaseUrl;     // May change dynamically.
@property (nonatomic, strong, readonly, nullable) NSString*     sessionToken;
@property (nonatomic, strong, nullable) NSString*     accessToken;
@property (nonatomic, strong, readonly, nullable) id<MPAuthDetails>     authDetails;
@property (nonatomic, strong, readonly, nullable) NSError*      sessionTokenRefreshError;
@property (nonatomic, readonly) BOOL                            apiKeyValid;
@property (nonatomic, readonly) BOOL                            isAuthorised;
@property (nonatomic, readwrite) BOOL                           useDevEnvironment;
@property (nonatomic, strong, readonly, nullable) NSDictionary* proxySettings;

#pragma mark - API Endpoint getters
@property (nonatomic, strong, readonly, nonnull) NSString*      gatewayUrl;

@property (nonatomic, strong, readonly, nonnull) NSString*      datasetSizeSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      graphSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      locationSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      venueSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      buildingSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      appDataSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      solutionSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      tileSyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      categorySyncUrl;
@property (nonatomic, strong, readonly, nonnull) NSString*      userRolesSyncUrl;

@property (nonatomic, strong, readonly, nonnull) NSString*      liveUpdateUrl;

- (nullable NSString*) graphSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*)  graphSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language venueId:(nullable NSString*)venueId;
- (nullable NSString*) locationSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) locationSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language userRoles:(nullable NSArray<MPUserRole*>*) roles;
- (nullable NSString*) locationSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language userRoles:(nullable NSArray<MPUserRole*>*) roles venueId:(nullable NSString*) venueId;
- (nullable NSString*) venueSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) buildingSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) buildingSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language venueId:(nullable NSString*) venueId;
- (nullable NSString*) solutionSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) appDataSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) categorySyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) tileSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) userRolesSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) routeLayerSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) dataSetSyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) derivedGeometrySyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;
- (nullable NSString*) derivedGeometrySyncUrlForSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language venueId:(nullable NSString*) venueId;
- (nullable NSString*) liveDataUrl:(nullable NSString*)endpoint apiKey:(nullable NSString*)apiKey;
- (nullable NSString*) liveDataStateUrl:(nullable NSString*)topic;
- (nullable NSString*) loggingUrl:(nullable NSString*)apiKey;

- (nullable NSArray<NSString*>*) allEndpointUrlsForSyncingSolutionId:(nullable NSString*)solutionId language:(nullable NSString*)language;

#pragma mark - Booking service related
- (nullable NSString*) urlForFetchingBookableLocations:(nullable NSString*)solutionId;
- (nullable NSString*) urlForFetchingLocationsConfiguredForBooking:(nullable NSString*)solutionId;
- (NSString*) urlForFetchingLocationBookings:(NSString*)solutionId;
- (NSString*) urlForFetchingUserBookings:(NSString*)solutionId;
- (NSString*) urlForBooking:(NSString*)solutionId;

- (BOOL) isEqualMapsIndoorsBackendUrl:(nullable NSString*)url1 toUrl:(nullable NSString*)url2;

@end

NS_ASSUME_NONNULL_END
