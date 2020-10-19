//
//  PeachCollectorProperties.h
//  PeachCollector
//
//  Created by Rayan Arnaout on 24.09.19.
//  Copyright © 2019 European Broadcasting Union. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PeachCollectorDataFormat.h"

NS_ASSUME_NONNULL_BEGIN

@interface PeachCollectorProperties : NSObject <NSCopying> 

/**
 *  The playlist ID of the playlist the media is added to or removed from
 *
 *  @return Playlist ID
 */
@property (nullable, nonatomic, copy) NSString *playlistID;

/**
 *  The position of the item in the playlist refered py `playlistID`
 *  Can be either "top" or "end"
 *
 *  @return Playlist insert position
 */
@property (nullable, nonatomic, copy) NSString *insertPosition;

/**
 *  The time spent by the user watching this media
 *
 *  @return time spent in seconds.
 */
@property (nullable, nonatomic, copy) NSNumber *timeSpent;

/**
 *  Playback position for the media.
 *  For a live stream 0.0 is the max value. A negative value mean a timeshift in the past
 *
 *  @return playback position in seconds.
 */
@property (nullable, nonatomic, copy) NSNumber *playbackPosition;
/**
 *  Previous playback position for the media.
 *  For a live stream 0.0 is the max value. A negative value mean a timeshift in the past
 *  Usually used along a media seek event or after a media pause event
 *
 *  @return previous playback position in seconds.
 */
@property (nullable, nonatomic, copy) NSNumber *previousPlaybackPosition;

/**
 *  Boolean value to know if media is playing at the moment of the event
 *  Usefull for the `media_seek` event
 *
 *  @return a boolean value wrapped in an NSNumber. YES is the media is playing, NO otherwise
 */
@property (nullable, nonatomic, copy) NSNumber *isPlaying;

/**
 *  In case of "auto continue" start mode, previousMediaID should be defined
 *
 *  @return previous media identifier
 */
@property (nullable, nonatomic, copy) NSString *previousMediaID;

/**
 *  Speed of playback. Value is relative to normal playback speed
 *  - 0.5 for 2x slow motion
 *  - 1 for normal playback
 *  - 2 for fast forward
 *
 *  @return playback rate
 */
@property (nullable, nonatomic, copy) NSNumber *playbackRate;

/**
 *  Volume of playback in percentage.
 *  - 0 means the media is muted.
 *  - 1 is 100% volume level
 *
 *  @return volume of playback
 */
@property (nullable, nonatomic, copy) NSNumber *volume;

/**
 *  Mode for a video media : bar, mini, normal, wide, pip, fullscreen, cast, preview
 *
 *  @return media video mode
 */
@property (nullable, nonatomic, copy) PCMediaVideoMode videoMode;

/**
 *  Describes how the media is listenned to : normal, in background or if it is muted
 *
 *  @return media audio mode
 */
@property (nullable, nonatomic, copy) PCMediaAudioMode audioMode;

/**
 *  How the media was started (normal, by "auto play", or by "auto continue")
 *
 *  @return media start mode
 */
@property (nullable, nonatomic, copy) PCMediaStartMode startMode;

/**
 * Add a custom number field to the properties (can be a number or a boolean)
 */
- (void)addNumber:(NSNumber *)number forKey:(nonnull NSString *)key;

/**
 * Add a custom string field to the properties
 */
- (void)addString:(NSString *)string forKey:(nonnull NSString *)key;

/**
 * Remove a custom string or number added previously
 * @param key the name of the custom field
 */
- (void)removeCustomField:(nonnull NSString *)key;

/**
 * Retrieve the value of a custom field previously set
 * @param key the name of the custom field
 * @return nil if the key was not found
 */
- (nullable id)valueForCustomField:(nonnull NSString *)key;

/**
 * @return a dictionary representation of the properties as defined in the Peach documentation
 */
- (nullable NSDictionary *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END
