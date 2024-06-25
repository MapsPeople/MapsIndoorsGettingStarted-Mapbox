////
////  MPOfflineRoutingService.h
////  MapsIndoors
////
////  Created by Daniel Nielsen on 23/11/2017.
////  Copyright © 2017 MapsPeople A/S. All rights reserved.
////

#import <Foundation/Foundation.h>
@import MapsIndoors;

@protocol MPRoutingService;
@class MPDirectionsConfig;
@class MPRouteInternal;

#pragma mark - [INTERNAL - DO NOT USE]

typedef void(^MPRoutingServiceHandlerBlockType)(MPRouteInternal* _Nullable route, NSError* _Nullable error);

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPOfflineRoutingService: NSObject

- (void) getRouteForSolutionId:(NSString *_Nullable)solutionId
                       graphId:(NSString *_Nullable)graphId
                          from:(MPPoint*_Nullable)from
                     fromFloor:(int)fromFloor
                            to:(MPPoint*_Nullable)to
                       toFloor:(int)toFloor
                    travelMode:(NSString *_Nullable)travelMode
                         avoid:(NSArray<MPHighway*>*_Nullable)restrictions
                 departureTime:(NSDate *_Nullable)departureTime
                   arrivalTime:(NSDate *_Nullable)arrivalTime
                     userRoles:(nullable NSArray<MPUserRole*>*)userRoles
             completionHandler:(MPRoutingServiceHandlerBlockType _Nonnull )completion;

@end
