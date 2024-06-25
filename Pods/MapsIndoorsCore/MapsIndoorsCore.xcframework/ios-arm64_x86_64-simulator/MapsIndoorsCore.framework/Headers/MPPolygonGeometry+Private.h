//
//  MPPolygonGeometry+Private.h
//  MapsIndoors
//
//  Created by Michael Bech Hansen on 09/05/2018.
//  Copyright © 2018 MapsPeople A/S. All rights reserved.
//

@import MapsIndoors;

@class MIPolygon;

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPPolygonGeometry (Private)

@property (nonatomic, strong, readonly, nonnull) MIPolygon* miPolygon;

@end
