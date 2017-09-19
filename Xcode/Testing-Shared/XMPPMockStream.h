//
//  XMPPStreamTest.h
//  XMPPFrameworkTests
//
//  Created by Andres Canal on 5/26/16.
//
//

@import XMPPFramework;

@interface XMPPMockStream : XMPPStream

- (void)fakeResponse:(NSXMLElement*)element;
- (void)fakeIQResponse:(XMPPIQ *) iq;
- (void)fakeMessageResponse:(XMPPMessage *) message;

- (void)fakeCurrentEventWithID:(NSString *)fakeEventID timestamp:(NSDate *)fakeEventTimestamp forActionWithBlock:(dispatch_block_t)block;

@property (nonatomic, copy) void (^elementReceived)(__kindof XMPPElement *element);

@end
