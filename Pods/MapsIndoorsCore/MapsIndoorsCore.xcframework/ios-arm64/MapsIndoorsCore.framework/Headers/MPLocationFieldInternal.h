//
//  MPLocationFieldInternal.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 15/12/14.
//  Copyright (c) 2014 MapsPeople A/S. All rights reserved.
//

#import "JSONModel.h"
@import MapsIndoors;

NS_ASSUME_NONNULL_BEGIN

static NSString* const MPLocationFieldName = @"name";
static NSString* const MPLocationFieldDescription = @"description";
static NSString* const MPLocationFieldAlias = @"alias";
static NSString* const MPLocationFieldPhone = @"phone";
static NSString* const MPLocationFieldEmail = @"email";
static NSString* const MPLocationFieldImageUrl = @"imageUrl";
static NSString* const MPLocationFieldWebsite = @"website";

@interface MPLocationFieldInternal : JSONModel <MPLocationField>

@property (nonatomic, copy, readonly) NSString* type;
@property (nonatomic, copy, readonly) NSString* text;
@property (nonatomic, copy, nullable, readonly) NSString* value;

@end

NS_ASSUME_NONNULL_END
