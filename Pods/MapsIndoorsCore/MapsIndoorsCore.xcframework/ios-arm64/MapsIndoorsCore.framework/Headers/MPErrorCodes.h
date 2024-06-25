//
//  MPError.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 05/02/16.
//  Copyright  Daniel Nielsen. All rights reserved.
//

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
static NSInteger const kMPErrorCodeLocationsCacheNotBuilt                          = 100100;
static NSInteger const kMPErrorCodeLocationsCacheNotAvailableForMapExtend          = 100130;
static NSInteger const kMPErrorCodeLocationsNotFound                               = 100110;
static NSInteger const kMPErrorCodeLocationDetailsNotFound                         = 100120;

static NSInteger const kMPErrorCodeVenueDetailsNotFound                            = 100200;
static NSInteger const kMPErrorCodeVenuesNotFound                                  = 100210;

static NSInteger const kMPErrorCodeBuildingDetailsNotFound                         = 100300;
static NSInteger const kMPErrorCodeBuildingsNotFound                               = 100310;

static NSInteger const kMPErrorCodeSolutionDetailsNotFound                         = 100400;
static NSInteger const kMPErrorCodeSolutionsNotFound                               = 100410;

static NSInteger const kMPErrorCodeMessagesNotFound                                = 100500;
static NSInteger const kMPErrorCodeMessageDetailsNotFound                          = 100510;

static NSInteger const kMPErrorCodeDirectionsRouteNotFound                         = 100610;
static NSInteger const kMPErrorCodeDirectionsMatrixNotFound                        = 100620;
static NSInteger const kMPErrorCodeDirectionsOriginAndDestinationTooCloseOrTheSame = 100630;

static NSInteger const kMPErrorCodeCategoriesNotFound                              = 100710;
static NSInteger const kMPErrorCodeAppDataNotFound                                 = 100810;
static NSInteger const kMPErrorCodeUserRolesNotFound                               = 100910;
static NSInteger const kMPErrorCodeDerivedGeometryNotFound                         = 100920;

static NSInteger const kMPErrorCodeOfflineContentNotFound                          = 101010;

static NSInteger const kMPErrorCodeImageAssetNotFound                              = 101110;

static NSInteger const kMPErrorCodeParameterAssert                                 = 101200;

static NSInteger const kMPErrorCodeTilePackagesNotFound                            = 101210;

static NSInteger const kMPErrorCodeHttpError                                       = 101300;

static NSInteger const kMPErrorCodeRouteNetworkNotFound                            = 101400;

static NSInteger const kMPErrorCodeInvalidApiKey                                   = 101500;
static NSInteger const kMPErrorCodeInvalidGraphId                                  = 101510;
static NSInteger const kMPErrorCodeInvalidSolutionId                               = 101520;

static NSInteger const kMPErrorCodeSynchronizeContentCancelled                     = 101600;
static NSInteger const kMPErrorCodeSynchronizeContentDataLoadingError              = 101610;
static NSString* const kMPErrorCodeSynchronizeContentDataLoadingErrorKey           = @"syncContent::underlyingError";
static NSInteger const kMPErrorCodeSaveDataError                                   = 101620;
static NSInteger const kMPErrorCodeSynchronizeContentDataNotAvailableOffline       = 101620;

static NSInteger const kMPErrorCodeLiveDataSubscriptionFailedNotActive             = 102000;

static NSInteger const kMPErrorCodeDependingConnectionWasLost                      = 103000;

static NSInteger const kMPErrorCodeRouteLayerNotFound                              = 103010;

static NSInteger const kMPErrorCodeNotAuthorised                                   = 104000;

static NSInteger const kMPErrorCodeNetworkUnreachable                              = 104010;

static NSString* const kMPMapsIndoorsDomain                                        = @"com.mapspeople.MapsIndoors";

#define MPMakeErrorWithCode(cODE,uSRiNFOdICT)   [NSError errorWithDomain:kMPMapsIndoorsDomain code:cODE userInfo:uSRiNFOdICT]
