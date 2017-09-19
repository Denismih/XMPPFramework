#import "XMPPMessageCoreDataStorage+XEP_0203.h"
#import "XMPPMessageCoreDataStorageObject+Protected.h"
#import "XMPPMessageCoreDataStorageObject+ContextHelpers.h"
#import "XMPPMessage.h"
#import "NSXMLElement+XEP_0203.h"

static XMPPMessageContextTimestampItemTag const XMPPMessageContextDelayedDeliveryTimestampTag = @"XMPPMessageContextDelayedDeliveryTimestamp";
static XMPPMessageContextJIDItemTag const XMPPMessageContextDelayedDeliveryFromTag = @"XMPPMessageContextDelayedDeliveryFrom";
static XMPPMessageContextStringItemTag const XMPPMessageContextDelayedDeliveryReasonDescriptionTag = @"XMPPMessageContextDelayedDeliveryReasonDescription";

@implementation XMPPMessageCoreDataStorageTransaction (XEP_0203)

- (void)registerDelayedDeliveryForReceivedMessage:(XMPPMessage *)message
{
    [self scheduleStorageUpdateWithBlock:^(XMPPMessageCoreDataStorageObject * _Nonnull messageObject) {
        [messageObject setDelayedDeliveryDate:[message delayedDeliveryDate]
                                         from:[message delayedDeliveryFrom]
                            reasonDescription:[message delayedDeliveryReasonDescription]];
    }];
}

@end

@implementation XMPPMessageCoreDataStorageObject (XEP_0203)

- (NSDate *)delayedDeliveryDate
{
    return [self lookupInContextWithBlock:^id _Nullable(XMPPMessageContextCoreDataStorageObject * _Nonnull contextElement) {
        return [contextElement timestampItemValueForTag:XMPPMessageContextDelayedDeliveryTimestampTag];
    }];
}

- (XMPPJID *)delayedDeliveryFrom
{
    return [self lookupInContextWithBlock:^id _Nullable(XMPPMessageContextCoreDataStorageObject * _Nonnull contextElement) {
        return [contextElement jidItemValueForTag:XMPPMessageContextDelayedDeliveryFromTag];
    }];
}

- (NSString *)delayedDeliveryReasonDescription
{
    return [self lookupInContextWithBlock:^id _Nullable(XMPPMessageContextCoreDataStorageObject * _Nonnull contextElement) {
        return [contextElement stringItemValueForTag:XMPPMessageContextDelayedDeliveryReasonDescriptionTag];
    }];
}

- (void)setDelayedDeliveryDate:(NSDate *)delayedDeliveryDate from:(XMPPJID *)delayedDeliveryFrom reasonDescription:(NSString *)delayedDeliveryReasonDescription
{
    NSAssert(![self delayedDeliveryDate], @"Delayed delivery information is already present");
    
    [self retireStreamTimestamp];
    
    XMPPMessageContextCoreDataStorageObject *delayedDeliveryContextElement = [self appendContextElement];
    
    [delayedDeliveryContextElement appendTimestampItemWithTag:XMPPMessageContextDelayedDeliveryTimestampTag value:delayedDeliveryDate];
    if (delayedDeliveryFrom) {
        [delayedDeliveryContextElement appendJIDItemWithTag:XMPPMessageContextDelayedDeliveryFromTag value:delayedDeliveryFrom];
    }
    if (delayedDeliveryReasonDescription) {
        [delayedDeliveryContextElement appendStringItemWithTag:XMPPMessageContextDelayedDeliveryReasonDescriptionTag value:delayedDeliveryReasonDescription];
    }
}

@end

@implementation XMPPMessageContextItemCoreDataStorageObject (XEP_0203)

+ (NSPredicate *)delayedDeliveryTimestampKindPredicate
{
    return [XMPPMessageContextTimestampItemCoreDataStorageObject tagPredicateWithValue:XMPPMessageContextDelayedDeliveryTimestampTag];
}

@end
