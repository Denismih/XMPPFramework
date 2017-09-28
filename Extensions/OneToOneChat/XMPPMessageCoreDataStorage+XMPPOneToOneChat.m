#import "XMPPMessageCoreDataStorage+XMPPOneToOneChat.h"
#import "XMPPMessageCoreDataStorageObject+Protected.h"

@implementation XMPPMessageCoreDataStorageTransaction (XMPPOneToOneChat)

- (void)storeReceivedChatMessage:(XMPPMessage *)message
{
    [self scheduleStorageUpdateWithBlock:^(XMPPMessageCoreDataStorageObject * _Nonnull messageObject) {
        [messageObject registerIncomingMessageCore:message];
    }];
}

- (void)registerSentChatMessage
{
    [self scheduleStorageUpdateWithBlock:^(XMPPMessageCoreDataStorageObject * _Nonnull messageObject) {
        // No additional processing required
    }];
}

@end
