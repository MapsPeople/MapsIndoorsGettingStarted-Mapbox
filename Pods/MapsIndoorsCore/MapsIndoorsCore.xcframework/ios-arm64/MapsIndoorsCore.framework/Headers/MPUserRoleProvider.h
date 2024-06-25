//
//  MPUserRoleProvider.h
//  MapsIndoors
//
//  Created by Michael Bech Hansen on 07/06/2019.
//  Copyright © 2019 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MPUserRole;

NS_ASSUME_NONNULL_BEGIN

/**
 Callback block for getting user roles

 - Parameter userRoles: list of user roles, possibly empty
 - Parameter error: error, nil of no error occured
 */
typedef void(^mpUserRoleCompletion)( NSArray<MPUserRole*>* _Nullable userRoles, NSError* _Nullable error );


#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPUserRoleProvider : NSObject

- (void) getUserRolesWithCompletion:(mpUserRoleCompletion)completionHandler;

/**
 Determine if cached or preloaded data is available for the given solutionId.

 - Parameter solutionId: solutionId to check for offline data availability.
 - Parameter language: Language to check for offline data availability.
 - Returns: YES if offline or preloaded data is available, else NO,
 */
+ (BOOL) isOfflineDataAvailableForSolutionId:(nonnull NSString*)solutionId language:(nonnull NSString*)language;

@end

NS_ASSUME_NONNULL_END
