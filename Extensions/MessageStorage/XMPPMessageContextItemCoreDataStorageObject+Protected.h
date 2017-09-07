#import "XMPPMessageContextItemCoreDataStorageObject.h"

NS_ASSUME_NONNULL_BEGIN

@class XMPPMessageContextCoreDataStorageObject, XMPPJID;

/// A tag assigned to a JID auxiliary value.
typedef NSString * XMPPMessageContextJIDItemTag NS_EXTENSIBLE_STRING_ENUM;

/// An tag assigned to an auxiliary marker.
typedef NSString * XMPPMessageContextMarkerItemTag NS_EXTENSIBLE_STRING_ENUM;

/// A tag assigned to a string auxiliary value.
typedef NSString * XMPPMessageContextStringItemTag NS_EXTENSIBLE_STRING_ENUM;

/// A tag assigned to a timestamp auxiliary value.
typedef NSString * XMPPMessageContextTimestampItemTag NS_EXTENSIBLE_STRING_ENUM;

@interface XMPPMessageContextItemCoreDataStorageObject (Protected)

/// The context element aggregating the value.
@property (nonatomic, strong, nullable) XMPPMessageContextCoreDataStorageObject *contextElement;

@end

/// A storage object representing a module-provided JID value assigned to a stored message.
@interface XMPPMessageContextJIDItemCoreDataStorageObject : XMPPMessageContextItemCoreDataStorageObject

/// The tag assigned to the value.
@property (nonatomic, copy, nullable) XMPPMessageContextJIDItemTag tag;

/// The stored JID value.
@property (nonatomic, strong, nullable) XMPPJID *value;

@end

/// A storage object representing a module-provided marker assigned to a stored message.
@interface XMPPMessageContextMarkerItemCoreDataStorageObject : XMPPMessageContextItemCoreDataStorageObject

/// The tag assigned to the marker.
@property (nonatomic, copy, nullable) XMPPMessageContextMarkerItemTag tag;

@end

/// A storage object representing a module-provided string value assigned to a stored message.
@interface XMPPMessageContextStringItemCoreDataStorageObject : XMPPMessageContextItemCoreDataStorageObject

/// The tag assigned to the value.
@property (nonatomic, copy, nullable) XMPPMessageContextStringItemTag tag;

/// The stored string value.
@property (nonatomic, copy, nullable) NSString *value;

@end

/// A storage object representing a module-provided timestamp value assigned to a stored message.
@interface XMPPMessageContextTimestampItemCoreDataStorageObject : XMPPMessageContextItemCoreDataStorageObject

/// The tag assigned to the value.
@property (nonatomic, copy, nullable) XMPPMessageContextTimestampItemTag tag;

/// The stored timestamp value.
@property (nonatomic, strong, nullable) NSDate *value;

@end

NS_ASSUME_NONNULL_END
