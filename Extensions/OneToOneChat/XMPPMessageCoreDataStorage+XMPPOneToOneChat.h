#import "XMPPMessageCoreDataStorage.h"

NS_ASSUME_NONNULL_BEGIN

@class XMPPMessage;

@interface XMPPMessageCoreDataStorageTransaction (XMPPOneToOneChat)

/// Stores core XMPP properties for the received chat message.
- (void)storeReceivedChatMessage:(XMPPMessage *)message;

/**
 Registers outgoing stream event information for the chat message processed in the transaction.

 A prerequisite is that the application registers the event ID for the respective storage object before sending the message,
 see registerOutgoingMessageStreamEventID: method on XMPPMessageCoreDataStorageObject.
 */
- (void)registerSentChatMessage;

@end

NS_ASSUME_NONNULL_END
