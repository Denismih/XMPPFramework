#import "XMPPMessageCoreDataStorageObject.h"
#import "XMPPMessageContextCoreDataStorageObject.h"
#import "XMPPMessageContextItemCoreDataStorageObject+Protected.h"

NS_ASSUME_NONNULL_BEGIN

/// An API to be used by modules to manipulate auxiliary context objects assigned to a stored message.
@interface XMPPMessageCoreDataStorageObject (ContextHelpers)

/// Inserts a new context element associated with the message.
- (XMPPMessageContextCoreDataStorageObject *)appendContextElement;

@end

/// An API to be used by modules to manipulate auxiliary context object values assigned to a stored message.
@interface XMPPMessageContextCoreDataStorageObject (ContextHelpers)

/// Inserts a new JID value associated with the context element.
- (XMPPMessageContextJIDItemCoreDataStorageObject *)appendJIDItemWithTag:(XMPPMessageContextJIDItemTag)tag value:(XMPPJID *)value;

/// Inserts a new marker associated with the context element.
- (XMPPMessageContextMarkerItemCoreDataStorageObject *)appendMarkerItemWithTag:(XMPPMessageContextMarkerItemTag)tag;

/// Inserts a new string value associated with the context element.
- (XMPPMessageContextStringItemCoreDataStorageObject *)appendStringItemWithTag:(XMPPMessageContextStringItemTag)tag value:(NSString *)value;

/// Inserts a new timestamp value associated with the context element.
- (XMPPMessageContextTimestampItemCoreDataStorageObject *)appendTimestampItemWithTag:(XMPPMessageContextTimestampItemTag)tag value:(NSDate *)value;

/// Removes all JID values with the given tag associated with the context element.
- (void)removeJIDItemsWithTag:(XMPPMessageContextJIDItemTag)tag;

/// Removes all markers with the given tag associated with the context element.
- (void)removeMarkerItemsWithTag:(XMPPMessageContextMarkerItemTag)tag;

/// Removes all string values with the given tag associated with the context element.
- (void)removeStringItemsWithTag:(XMPPMessageContextStringItemTag)tag;

/// Removes all timestamp values with the given tag associated with the context element.
- (void)removeTimestampItemsWithTag:(XMPPMessageContextTimestampItemTag)tag;

@end

NS_ASSUME_NONNULL_END
