#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@class XMPPJID;

typedef NS_ENUM(int16_t, XMPPMessageDirection) {
    /// A value indicating that the message's origin is not defined.
    XMPPMessageDirectionUnspecified,
    /// A value indicating that the message has been received from the stream.
    XMPPMessageDirectionIncoming,
    /// A value indicating that the message is originating from the device.
    XMPPMessageDirectionOutgoing
};

typedef NS_ENUM(int16_t, XMPPMessageType) {
    /// A value indicating normal message type as per RFC 3921/6121
    XMPPMessageTypeNormal,
    /// A value indicating chat message type as per RFC 3921/6121
    XMPPMessageTypeChat,
    /// A value indicating error message type as per RFC 3921/6121
    XMPPMessageTypeError,
    /// A value indicating groupchat message type as per RFC 3921/6121
    XMPPMessageTypeGroupchat,
    /// A value indicating headline message type as per RFC 3921/6121
    XMPPMessageTypeHeadline
};

/**
 An object storing the core XMPP message properties defined in RFC 3921/6121.
 
 @see XMPPMessageCoreDataStorage
 @see XMPPMessageContextCoreDataStorageObject
 @see XMPPMessageContextItemCoreDataStorageObject
 */
@interface XMPPMessageCoreDataStorageObject : NSManagedObject

/// The value of "from" attribute (transient).
@property (nonatomic, strong, nullable) XMPPJID *fromJID;

/// The value of "to" attribute (transient).
@property (nonatomic, strong, nullable) XMPPJID *toJID;

/// The contents of "body" child element.
@property (nonatomic, copy, nullable) NSString *body;

/// The value of "id" attribute.
@property (nonatomic, copy, nullable) NSString *stanzaID;

/// The contents of "subject" child element.
@property (nonatomic, copy, nullable) NSString *subject;

/// The contents of "thread" child element.
@property (nonatomic, copy, nullable) NSString *thread;

/// The transmission direction from client's point of view.
@property (nonatomic, assign) XMPPMessageDirection direction;

/// The value of "type" attribute.
@property (nonatomic, assign) XMPPMessageType type;

@end

NS_ASSUME_NONNULL_END
