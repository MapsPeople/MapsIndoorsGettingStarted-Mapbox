//
//  MPLocationIndexer.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 29/11/2018.
//  Copyright © 2018 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>
@import MapsIndoors;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPLocationSourceIndex : NSObject

+ (MPLocationSourceIndex*) current;

/// A static mapping between human readable ids and location ids. This serves to give building and floor locations a possible mapping to locations - due to a lack of `floorId` or `buildingId` relation on locations in the data model
- (nullable NSMutableDictionary<NSString*, NSString*>*) readableLocationIdMap;

+ (void) clear;

@end

NS_ASSUME_NONNULL_END
