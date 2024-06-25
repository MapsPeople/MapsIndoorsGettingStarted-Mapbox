//
//  MapsIndoors.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 30/08/16.
//  Copyright  Daniel-Nielsen. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import <MapsIndoorsCore/MPSolutionInternal.h>
#import <MapsIndoorsCore/MPSolutionProvider.h>
#import <MapsIndoorsCore/MPDerivedGeometryProvider.h>
#import <MapsIndoorsCore/MPDerivedGeometry.h>
#import <MapsIndoorsCore/MPDerivedGeometryCollection.h>

#import <MapsIndoorsCore/MPAppData.h>
#import <MapsIndoorsCore/MPBuildingInternal.h>
#import <MapsIndoorsCore/MPBuildingInfo.h>
#import <MapsIndoorsCore/MPFloorInternal.h>
#import <MapsIndoorsCore/MPFloorSelectorControl.h>
#import <MapsIndoorsCore/MPLocationProperty.h>
#import <MapsIndoorsCore/MPMapStyleInternal.h>

#import <MapsIndoorsCore/MPVenueInternal.h>
#import <MapsIndoorsCore/MPVenueProvider.h>
#import <MapsIndoorsCore/MPImageRenderer.h>
#import <MapsIndoorsCore/NSObject+MPLanguageSupport.h>

#import <MapsIndoorsCore/MPBuildingCollection.h>
#import <MapsIndoorsCore/MPMemoryCache.h>
#import <MapsIndoorsCore/MPCategories.h>
#import <MapsIndoorsCore/MPErrorCodes.h>
#import <MapsIndoorsCore/MPAppDataProvider.h>
#import <MapsIndoorsCore/MPMenuItem.h>
#import <MapsIndoorsCore/MPMapsIndoorsLegacy.h>

#import <MapsIndoorsCore/MPLocationFieldInternal.h>
#import <MapsIndoorsCore/MPLocationField+Mutable.h>
#import <MapsIndoorsCore/MPMQTTSubscriptionClient.h>

#import <MapsIndoorsCore/MPMapRouteLegButton.h>

#import <MapsIndoorsCore/MPDataSetCacheManagerInternal.h>
#import <MapsIndoorsCore/MPDataSetCacheInternal.h>
#import <MapsIndoorsCore/MPDataSetCacheItemInternal.h>
#import <MapsIndoorsCore/MPDataSetEnums.h>

#import <MapsIndoorsCore/MPLocationDataset.h>

#import <MapsIndoorsCore/MPLocationInternal.h>
#import <MapsIndoorsCore/MPTypeInternal.h>

#import <MapsIndoorsCore/MPGraphNode.h>
#import <MapsIndoorsCore/MPLocationCoordinate3D.h>
#import <MapsIndoorsCore/MPURITemplate.h>
#import <MapsIndoorsCore/MPTileCache.h>
#import <MapsIndoorsCore/NSString+MPPropertyClassification.h>
#import <MapsIndoorsCore/NSObject+GeometryProperties.h>
#import <MapsIndoorsCore/MPRouteNode.h>

#import <MapsIndoorsCore/MPMIAPI.h>
#import <MapsIndoorsCore/MPGeometryHelper.h>

#import <MapsIndoorsCore/MPRouteNetworkService.h>
#import <MapsIndoorsCore/MPRouteNetworkData.h>
#import <MapsIndoorsCore/MPRouteNetwork.h>

#import <MapsIndoorsCore/MPUserRoleProvider.h>
#import <MapsIndoorsCore/MPBuildingProvider.h>

#import <MapsIndoorsCore/MPGeometryHelper.h>
#import <MapsIndoorsCore/MPMIAPI.h>

#import <MapsIndoorsCore/MPGraph.h>
#import <MapsIndoorsCore/MPGraphEdge.h>
#import <MapsIndoorsCore/MPRouteEdge.h>

#import <MapsIndoorsCore/MPDirectionsHelper.h>
#import <MapsIndoorsCore/MPReachability.h>
#import <MapsIndoorsCore/NSString+MapsPeopleExtendedFileAttributes.h>
#import <MapsIndoorsCore/MPOfflineBundleHelper.h>
#import <MapsIndoorsCore/MPFileCache.h>

#import <MapsIndoorsCore/MPLocationSourceIndex.h>
#import <MapsIndoorsCore/MPOfflineRoutingService.h>

#import <MapsIndoorsCore/MPPolygonGeometry+Private.h>
