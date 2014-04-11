//
//  RZCollectionListTableViewDataSource.h
//  RZCollectionList-Demo
//
//  Created by Joe Goullaud on 9/14/12.
//  Copyright (c) 2012 Raizlabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RZCollectionListProtocol.h"

/**
 *  An object that adopts the RZCollectionListTableViewDataSourceDelegate protocol is responsible for providing the data and views required by an
 *  RZCollectionListTableViewDataSource instance for a UITableView. It also handles the creation and configuration of cells
 *  used by the table view to display the data in the supplied id<RZCollecitonList>.
 */
@protocol RZCollectionListTableViewDataSourceDelegate <NSObject>

@required

/**
 *  Use this callback instead of - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
 *  @warning Must return a valid UITableViewCell from - (id)dequeueReusableCellWithIdentifier:(NSString *)identifier;
 *
 *  @param tableView The table view associated with this data source.
 *  @param object    Use this object to populate your cell.
 *  @param indexPath The index path of the object in your id<RZCollectionList>.
 *
 *  @return A configured UITableViewCell object. You must not return nil from this method.
 */
- (UITableViewCell*)tableView:(UITableView*)tableView cellForObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

@optional

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead. Implement this to immediately update a cell's contents as part of a batch update, as opposed to reloading after a batch animation.
 *
 *  @param tableView The table view associated with this data source.
 *  @param cell      The cell to be updated.
 *  @param object    The object used to populate the cell.
 *  @param indexPath The index path of the cell being updated.
 */
- (void)tableView:(UITableView*)tableView updateCell:(UITableViewCell*)cell forObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView The table view associated with this data source.
 *  @param section   The section to be associated with the provided title.
 *
 *  @return A string to be shown in the header of this section of the table view.
 */
- (NSString*)tableView:(UITableView*)tableView titleForHeaderInSection:(NSInteger)section;

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView The table view associated with this data source.
 *  @param section   The section to be associated with the provided title.
 *
 *  @return A string to be shown in the footer of this section of the table view.
 */
- (NSString*)tableView:(UITableView*)tableView titleForFooterInSection:(NSInteger)section;

/**
 * A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView The table view associated with this data source.
 *  @param object    The object used to populate the cell.
 *  @param indexPath The index path of the cell requesting this information.
 *
 *  @return A boolean to allow or disallow the editing of the cell.
 */
- (BOOL)tableView:(UITableView*)tableView canEditObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView The table view associated with this data source.
 *  @param object    The object used to populate the cell.
 *  @param indexPath The index path of the cell requesting this information.
 *
 *  @return A boolean to allow or disallow the reordering of the cell.
 */
- (BOOL)tableView:(UITableView*)tableView canMoveObject:(id)object atIndexPath:(NSIndexPath*)indexPath;

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView    The table view associated with this data source.
 *  @param editingStyle UITableViewCellEditingStyleNone, UITableViewCellEditingStyleDelete, or UITableViewCellEditingStyleInsert
 *  @param indexPath    The index path of the cell requesting this information.
 */
- (void)tableView:(UITableView*)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  A mirror of the UITableViewDataSource callback, use this method instead.
 *
 *  @param tableView            The table view associated with this data source.
 *  @param sourceIndexPath      The current index path for the object.
 *  @param destinationIndexPath The new index path for the object.
 */
- (void)tableView:(UITableView*)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;

@end

@interface RZCollectionListTableViewDataSource : NSObject <UITableViewDataSource>

@property (nonatomic, strong, readonly) id<RZCollectionList> collectionList;
@property (nonatomic, weak, readonly) UITableView *tableView;

@property (nonatomic, weak) id<RZCollectionListTableViewDataSourceDelegate> delegate;

@property (nonatomic, assign, getter = shouldShowTableIndex) BOOL showTableIndex;                           // Defaults to NO
@property (nonatomic, assign, getter = shouldShowSectionHeaders) BOOL showSectionHeaders;                   // Defaults to NO, Overridden if the delegate implements tableView:titleForHeaderInSection:
@property (nonatomic, assign, getter = shouldAnimateTableChanges) BOOL animateTableChanges;                 // Defaults to YES

@property (nonatomic, assign) UITableViewRowAnimation addSectionAnimation;      // Defaults to UITableViewRowAnimationFade
@property (nonatomic, assign) UITableViewRowAnimation removeSectionAnimation;   // Defaults to UITableViewRowAnimationFade
@property (nonatomic, assign) UITableViewRowAnimation addObjectAnimation;       // Defaults to UITableViewRowAnimationFade
@property (nonatomic, assign) UITableViewRowAnimation removeObjectAnimation;    // Defaults to UITableViewRowAnimationFade
@property (nonatomic, assign) UITableViewRowAnimation updateObjectAnimation;    // Defaults to UITableViewRowAnimationFade


- (id)initWithTableView:(UITableView*)tableView collectionList:(id<RZCollectionList>)collectionList delegate:(id<RZCollectionListTableViewDataSourceDelegate>)delegate;

// TableViewAnimations
- (void)setAllAnimations:(UITableViewRowAnimation)animation;
- (void)setAllSectionAnimations:(UITableViewRowAnimation)animation;
- (void)setAllObjectAnimations:(UITableViewRowAnimation)animation;

@end
