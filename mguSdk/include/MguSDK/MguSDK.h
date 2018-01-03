//
//  MguSDK.h
//  MguSDK
//
//  Created by Samit Vaidya on 9/22/15.
//  Copyright (c) 2015 matchingu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MguSDKDelegate <NSObject>
@optional
- (void) mguSDKDidGetInternalBrowserCallWithUrl: (NSString*) url;
- (void) mguSDKDidGetHtmlString: (NSString*) htmlString;
@end

@interface MguSDK : NSObject
@property (nonatomic, weak) id <MguSDKDelegate> delegate;
//methods available to host apps for communication to MguSDK

/* set token and hostAppId */
+(void) setToken:(NSString*) token andHostAppId: (NSString*) hostAppId;

/* get Matchinguu device unique ID */
+(NSString*) getClientId;

/* set production mode or sandbox mode of MguSDK */
+(void) setProductionMode:(BOOL) switchMode;

/* specifiy if location based service should be turned on or off, 
    if set value YES: location based service is turned off, only push service is turned on
    if set value NO: both locatio based service and push service is turned on
 */
+(void) useLocationBasedService:(BOOL) value;

/* set global notification cap and notification period */
+(void) setGlobalNotificationCap:(int) maximumNumber fornotificationPeriod:(NSString*) period;

/* set logging on or off */
+(void) setLoggingMode:(BOOL) mode;

/* set inapp alert notification, with preferred style
    preferred style can be set as UIAlertControllerStyleActionSheet or UIAlertControllerStyleAlert
 */
+(void) allowInAppAlertNotification:(BOOL) value withPreferredStyle:(UIAlertControllerStyle) alertControllerStyle;

/*  set sound for local notifications
    soundFileName: name of the file with extension, which is bundled with
    the app, if not called local notification sound will be default sound
 */
+(void) setLocalNotificationSound:(NSString*) soundFileName;

/* set in app messages on or off
 */
+(void) registerForInappMessages:(BOOL) status;

/* provides shared instance of the MguSDK */
+(MguSDK*) sdk;

/* provides shared instance of the MguSDK */
+(MguSDK*) instance;

/* provides shared instance of the MguSDK */
-(void) activatePush: (BOOL) value forTimePeriod: (int) timePeriod;

/* To be called when a MGU Local Notification has been received */
-(BOOL) handleNotificationClick:(UILocalNotification *)notification;

/* upload meta data with array */
-(void) uploadMetaData: (NSArray*) datamap;

/* To be called when a arbitrary data is to be uploaded to MGU Server */
-(void) uploadArbitraryData:(NSDictionary*) arbitraryDataDictionary;

/* To be called when a push device token has been received and to be sent to MGU Server */
-(void) registerForMguPushWithDeviceToken:(NSData*) deviceToken;

/* To be called when a MGU Push Notification has been received */
-(void) gotMguPushNotification:(NSDictionary*) notification;

/* get in app messages */
-(NSArray*) getInAppMessages;

/* update the in app messages */
-(void) updateInAppMessages: (NSArray*) updatedInAppArray;

/* To be called when a MGU In-App Notification has been clicked */
-(void) openedInAppMguMsg: (UILocalNotification*) notification;

/* Notify mgusdk that app has been opened */
- (void) notifyAppVisible;

/* Notify mgusdk that app has been closed */
- (void) notifyAppInvisible;

@end
