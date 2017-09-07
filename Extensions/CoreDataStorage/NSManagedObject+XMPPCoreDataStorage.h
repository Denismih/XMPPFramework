#import <CoreData/CoreData.h>

@interface NSManagedObject (XMPPCoreDataStorage)

/// @brief Inserts a managed object with an entity whose name matches the class name.
/// @discussion An assertion will be triggered if no matching entity is found in the model.
+ (instancetype)xmpp_insertNewObjectInManagedObjectContext:(NSManagedObjectContext *)managedObjectContext;

/// @brief Returns a fetch request for an entity whose name matches the class name.
/// @discussion An assertion will be triggered if no matching entity is found in the model.
+ (NSFetchRequest *)xmpp_fetchRequestInManagedObjectContext:(NSManagedObjectContext *)managedObjectContext;

@end

@interface NSManagedObjectContext (XMPPCoreDataStorage)

/// Executes the provided fetch request raising an assertion upon failure.
- (NSArray *)xmpp_executeForcedSuccessFetchRequest:(NSFetchRequest *)fetchRequest;

@end
