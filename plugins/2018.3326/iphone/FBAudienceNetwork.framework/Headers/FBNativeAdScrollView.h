/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <FBAudienceNetwork/FBNativeAdView.h>
#import <FBAudienceNetwork/FBNativeAdsManager.h>
#import <Foundation/Foundation.h>
#import "FBAdDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FBNativeAdView;

/**
 Contains multiple ads in a scroll view.

 When adding this view to a XIB or Storyboard, you may receive the error "Unknown class FBNativeAdScrollView in
 Interface Builder file" in some cases. This error is caused by the linker failing to include FBNativeAdScrollView in
 your build. To resolve this, call [FBNativeAdScrollView class] in your project, or add "-all_load -ObjC" to "Other
 Linker Flags" in your project settings.

 */
FB_CLASS_EXPORT FB_SUBCLASSING_RESTRICTED @interface FBNativeAdScrollView : UIView

/**
 Maximum native ads that this scroll view will load. Defaults to 10. If changed after calling loadAds, all current ads
 will be discarded and loadAds must be called again.
 */
@property (nonatomic, assign, readonly) NSUInteger maximumNativeAdCount;

/**
 Toggles animating the loaded views. Default is YES.
 */
@property (nonatomic, assign, getter=isAnimationEnabled) BOOL animationEnabled;

/**
 Horizontal inset for views in the scroll view. Defaults to 8 points.
 */
@property (nonatomic, assign) CGFloat xInset;

/**
 Reloads the same ads for the same manager. Default is NO.
 */
@property (nonatomic, assign, getter=isAdPersistenceEnabled) BOOL adPersistenceEnabled;

/**
 A view controller that is used to present modal content. If nil, the view searches for a view controller.
 */
@property (nonatomic, weak, nullable) UIViewController *rootViewController;

/**
 Passes delegate methods from FBNativeAd. Separate delegate calls will be made for each native ad contained.
 */
@property (nonatomic, weak, nullable) id<FBNativeAdDelegate> delegate;

/**
 Initializes a native ad horizontal scroll view for a given native ads manager and native ad template. The manager can
 be preloaded with ads, and loadAds will use the preloaded ads from the manager. Otherwise, the scroll view uses the

 manager to load ads normally.
 @param manager An instance of FBNativeAdManager. Can be preloaded with ads.
 @param type The type of this native ad template. For more information, consult FBNativeAdViewType.
 */
- (instancetype)initWithNativeAdsManager:(FBNativeAdsManager *)manager withType:(FBNativeAdViewType)type;

/**
 Initializes a native ad horizontal scroll view for a given native ads manager and native ad template. The manager can
 be preloaded with ads, and loadAds will use the preloaded ads from the manager. Otherwise, the scroll view uses the

 manager to load ads normally.
 @param manager An instance of FBNativeAdManager. Can be preloaded with ads.
 @param type The type of this native ad template. For more information, consult FBNativeAdViewType.
 @param attributes The layout of this native ad template. For more information, consult FBNativeAdViewLayout.
 */
- (instancetype)initWithNativeAdsManager:(FBNativeAdsManager *)manager
                                withType:(FBNativeAdViewType)type
                          withAttributes:(FBNativeAdViewAttributes *)attributes;

/**
 Initializes a native ad horizontal scroll view for a given native ads manager and native ad template. The manager can
 be preloaded with ads, and loadAds will use the preloaded ads from the manager. Otherwise, the scroll view uses the

 manager to load ads normally.
 @param manager An instance of FBNativeAdManager. Can be preloaded with ads.
 @param type The type of this native ad template. For more information, consult FBNativeAdViewType.
 @param attributes The layout of this native ad template. For more information, consult FBNativeAdViewLayout.
 @param maximumNativeAdCount Maximum native ads to show at once.
 */
- (instancetype)initWithNativeAdsManager:(FBNativeAdsManager *)manager
                                withType:(FBNativeAdViewType)type
                          withAttributes:(FBNativeAdViewAttributes *)attributes
                             withMaximum:(NSUInteger)maximumNativeAdCount;

/**
 Initializes a native ad horizontal scroll view from the provided view.
 @param manager An instance of FBNativeAdManager. Can be preloaded with ads.
 @param childViewProvider Block that creates new views for each loaded native ad. Must not reuse the same instance, but
 return a new view for each call. Views may be arbitrarily resized and should support resizing their content through
 Auto Layout constraints, autoresizing masks, or manual resizing.
 */
- (instancetype)initWithNativeAdsManager:(FBNativeAdsManager *)manager
                        withViewProvider:(UIView * (^)(FBNativeAd *nativeAd, NSUInteger position))childViewProvider;

/**
 Initializes a native ad horizontal scroll view from the provided view.
 @param manager An instance of FBNativeAdManager. Can be preloaded with ads.
 @param childViewProvider Block that creates new views for each loaded native ad. Must not reuse the same instance, but
 return a new view for each call. Views may be arbitrarily resized and should support resizing their content through
 Auto Layout constraints, autoresizing masks, or manual resizing.
 @param maximumNativeAdCount Maximum native ads to show at once.
 */
- (instancetype)initWithNativeAdsManager:(FBNativeAdsManager *)manager
                        withViewProvider:(UIView * (^)(FBNativeAd *nativeAd, NSUInteger position))childViewProvider
                             withMaximum:(NSUInteger)maximumNativeAdCount NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
