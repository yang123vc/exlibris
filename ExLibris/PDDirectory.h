//
//  PDDirectory.h
//  Disk II
//
//  Created by David Schweinsberg on 2/01/08.
//  Copyright 2008 David Schweinsberg. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class PDVolume;
@class PDEntry;
@class PDFileEntry;

@interface PDDirectory : NSObject
{
    PDFileEntry *fileEntry;
    PDVolume *volume;
    NSMutableArray *blocks;
    NSMutableArray *entries;
    BOOL allEntriesVisible;
}

@property(strong, readonly) PDFileEntry *fileEntry;
@property(strong, readonly) NSArray *blocks;
@property(strong, readonly) NSArray *entries;
@property(copy) NSString *name;
@property BOOL allEntriesVisible;

- (id)initWithVolume:(PDVolume *)aVolume
         blockNumber:(unsigned int)aBlockNumber;

- (id)initWithFileEntry:(PDFileEntry *)aFileEntry;

- (BOOL)createFileWithEntry:(PDFileEntry *)aFileEntry
                       data:(NSData *)aData;

- (PDFileEntry *)createDirectoryWithName:(NSString *)name error:(NSError **)outError;

- (void)deleteFileEntry:(PDFileEntry *)aFileEntry;

- (NSString *)uniqueNameFromString:(NSString *)string;

@end
