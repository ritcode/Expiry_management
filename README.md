# Expiry_management

This console based Mini Project in cpp is all about adding items and 
tracking their expiry date which is too taken as input.
With multiple user account maintainable just in a compact .dat file.


## What? 
- Allows user to store items with their expiry dates.
- Makes easy to store items details and keep an eye on the items and their time before expiry remaining.
- Supports multiple user functionality which makes it more systematic to manage.
- Can be used at general stores also where getting data for each and every item gets very messy with increasing number of items. 
- A decent UI adds simplicity to this minimalist application.


## How?  
#### Stage 1
1. At the start of program prompts for login with username and password.
2. User can create a new acount also if he is new with the application.

#### Stage 2 
``` Prompts to enter particular option to perform given sort of operations```

1. Add new item : Adds a new item to the  current user's account.
- Input
   1. Item name.
   2. Item description (related info user wants to save)
   3. Item's expiry date in dd/mm/yyyy format.
                  
2. Show expired items : Shows items which have crossed their expiry date.
3. Show all items : Shows all items which are present in user's account with their item ids, name, details, and time remaining to expire.
 
4. Remove an item : Every item is assigned id . user can enter an item's id to remove that particular item. user can check item id by pressing '3' or show items at second stage.
5. Remove all expired items : Clears all items from the list which have passed their expiry date.
6. Logout and Save : saves all the changes user had made and stores them in a file.


### To be 
- Add user security
- GUI
- Encryption on data files


