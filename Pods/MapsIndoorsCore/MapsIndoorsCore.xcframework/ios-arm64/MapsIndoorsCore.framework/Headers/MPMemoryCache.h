//
//  MPMemoryCache.h
//  MapsIndoors App
//
//  Created by Daniel Nielsen on 17/06/2019.
//  Copyright © 2019 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - [INTERNAL - DO NOT USE]

/// > Warning: [INTERNAL - DO NOT USE]
@interface MPMemoryCache : NSCache<NSString*, id>

- (NSString* _Nullable)cacheKeyForUrl:(NSString* _Nullable)sUrl;
- (void)clearCache;

@end

NS_ASSUME_NONNULL_END
