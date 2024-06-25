//
//  MPBuildingProvider.h
//  MapsIndoorsCore
//
//  Created by Frederik Hansen on 21/07/2023.
//  Copyright © 2023 MapsPeople A/S. All rights reserved.
//

#ifndef MPBuildingProvider_h
#define MPBuildingProvider_h


#import <Foundation/Foundation.h>
@import MapsIndoors;

@class MPBuildingInternal;
@class MPFloorInternal;


#pragma mark - typedefs

/**
 Handler block for fetching buildings

 - Parameter building: Building object. Can be nil.
 - Parameter error: Error object. Can be nil.
 */
typedef void(^mpBuildingDetailsHandlerBlockType)(id<MPBuilding> _Nullable building, NSError* _Nullable error);

/**
 Handler block for fetching buildings

 - Parameter buildings: Building objects. Can be nil.
 - Parameter error: Error object. Can be nil.
 */
typedef void(^mpBuildingListHandlerBlockType)(NSArray<id<MPBuilding>>* _Nullable buildings, NSError* _Nullable error);

#pragma mark - MPBuildingProviderProviderDelegate

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
/**
 Venue provider delegate.
 */
@protocol MPBuildingProviderDelegate <NSObject>

@required
/**
 Building data ready event method.
 - Parameter building: The building data object.
 */
- (void) onBuildingWithinBoundsReady: (nonnull MPBuildingInternal*)building;
/**
 Building data ready event method.
 - Parameter building: The building data object.
 */
- (void) onBuildingDetailsReady: (nonnull id<MPBuilding>)building;
/**
 Building data ready event method.
 - Parameter buildings: The buildings data object.
 */
- (void) onBuildingsReady: (nonnull NSArray<id<MPBuilding>>*)buildings;
@end


#pragma mark - MPBuildingProvider

/// > Warning: [INTERNAL - DO NOT USE]
/**
 Building provider interface, that defines a delegate and a method for building queries.
 */
@interface MPBuildingProvider : NSObject

@property (nullable) NSString* venueId;

- (nonnull instancetype)initWithVenueId:(nullable NSString*)venueId;

/**
 Building provider delegate.
 */
@property (nonatomic, weak, nullable) id <MPBuildingProviderDelegate> delegate;

/**
 Get a single building within given bounds
 
 - Parameter mapExtend: The geographic bounds, defined by north, south, west and east
 */
- (void)getBuildingWithinBounds: (nonnull MPGeoBounds*)bounds;

/**
 Get buildings from this provider

 */
- (void)getBuildings;

/**
 Get a single building detail object
 
 - Parameter buildingId: Building id
 */
- (void)getBuildingWithId: (nonnull NSString*)buildingId;

/**
 Get a single building within given bounds
 
 - Parameter mapExtend: The geographic bounds, defined by north, south, west and east
 - Parameter handler: Building fetch callback block
 */
- (void)getBuildingWithinBounds: (nonnull MPGeoBounds*)bounds completionHandler:(nullable mpBuildingDetailsHandlerBlockType)handler;
/**
 Get buildings from this provider
 
 - Parameter handler: Buildings fetch callback block
 */
- (void)getBuildingsWithCompletion:(nullable mpBuildingListHandlerBlockType)handler;

/**
 Get single building detail object
 
 - Parameter buildingId: Building id
 - Parameter handler: Building details fetch callback block
 */
- (void)getBuildingWithId: (nonnull NSString*)buildingId completionHandler:(nullable mpBuildingDetailsHandlerBlockType)handler;

- (void)getBuildingsAsync:(nonnull NSString*)venue arg:(nonnull NSString*)solutionId language: (nonnull NSString*) language completionHandler:(nonnull mpBuildingListHandlerBlockType)handler;

@end

#endif /* MPBuildingProvider_h */
