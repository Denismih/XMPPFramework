#import "XMPPMessageCoreDataStorageObject.h"

NS_ASSUME_NONNULL_BEGIN

@class XMPPMessageContextCoreDataStorageObject;

/// An API to be used by modules to manipulate core message objects.
@interface XMPPMessageCoreDataStorageObject (Protected)

/// The persistent attribute storing the domain component of @c fromJID property.
@property (nonatomic, copy, nullable) NSString *fromDomain;

/// The persistent attribute storing the resource component of @c fromJID property.
@property (nonatomic, copy, nullable) NSString *fromResource;

/// The persistent attribute storing the user component of @c fromJID property.
@property (nonatomic, copy, nullable) NSString *fromUser;

/// The persistent attribute storing the domain component of @c toJID property.
@property (nonatomic, copy, nullable) NSString *toDomain;

/// The persistent attribute storing the resource component of @c toJID property.
@property (nonatomic, copy, nullable) NSString *toResource;

/// The persistent attribute storing the user component of @c toJID property.
@property (nonatomic, copy, nullable) NSString *toUser;

/// The auxiliary context objects assigned to the message.
@property (nonatomic, copy, nullable) NSSet<XMPPMessageContextCoreDataStorageObject *> *contextElements;

@end

@interface XMPPMessageCoreDataStorageObject (CoreDataGeneratedRelationshipAccesssors)

- (void)addContextElementsObject:(XMPPMessageContextCoreDataStorageObject *)value;
- (void)removeContextElementsObject:(XMPPMessageContextCoreDataStorageObject *)value;
- (void)addContextElements:(NSSet<XMPPMessageContextCoreDataStorageObject *> *)value;
- (void)removeContextElements:(NSSet<XMPPMessageContextCoreDataStorageObject *> *)value;

@end

NS_ASSUME_NONNULL_END
