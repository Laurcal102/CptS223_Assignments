## Linux Trivia Game
*By Lauri Calvert*

### Note on array of player profiles
I did not realize until completion of my project that the player profiles were meant to be stored in an array, I created a list structure and stored the player profiles in this instead. I didn't realize the mistake until looking at the readme questions. I would be very grateful for lenience on this mistake as it took a lot of work to implement the profile list. Thank you.

**Program Description**
The game is made using two linked lists, one to track player profiles and scores, and another to track Linux commands and their definitions. At the beginning of program execution two csv files containing player profiles and commands are read in and stored in their applicable linked lists. As the program executes and changes are made by the user the linked lists update then at program termination the GameWrapper destructor overwrites the csv's with the contents of the updated lists.

**Bugs/Design Flaws**
There were unfortunately some bugs and design flaws I did not have the time to address while programming. 
- Menu infinite generation for non-numeric characters
- Non-random correct answer placement
- Possibility of multiple same correct answers during one game cycle
- Created a list of player profiles rather than an array
- random number generator does not exceed 30

**Makefile Usage**
I included a makefile in the project that is ready to be used with the included launch json. The make can either be used with just *make* or *make mainexe* the program can then be ran with the executable *mainexe*

*I have also included a screenshot of a successful build using this method in the project.*

### Project Questions

*List 1 advantage and 1 disadvantage of using a linked list for the data structure involved with storing the commands and descriptions*
- An advantage of using a linked list as the data structure for the commands is that the linked list does not have to have a set amount of space allocated at compile time. The list can grow or shrink during running allowing players to add or remove as many commands as they like. A disadvantage is that it is not as easy to locate a specific command as say storing in an array, to find the desired command you have to traverse the tree either from the tail or head which can be time consuming compared to indexes.

*List 1 advantage and 1 disadvantage of using an array for the data structure involved with storing the user profiles*
- An advantage to storing the user profiles in an array would be having quick access to whichever user you wanted by simply looking up the players name as an index. Though the downside to this approach is that you run the risk of either allocating too much or too little space for the array. If you only have to store a few player profiles you could waste space by allocating for many people, though if you allocate too little space you may have to delete player profiles to fit new profiles in.