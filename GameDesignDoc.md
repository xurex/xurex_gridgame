# Game Design Document

##Basic Gameplay Description
//STILL NEED IMAGE FOR GAME SCREEN
> A figure moves within a 8x8 grid to avoid objects that are flying across the screen. This top down game is "won" by achieving the highest score possible which entails staying alive as long as possible and picking up powerups. The game increases in speed as the game progresses until it becomes impossible to play.

###Scoring
>  Score increases automatically as the game progresses and the player stays alive. The higher the level, the faster the game increments. A score boost can be obtained by aquiring a life up with full health. Scores will eventually be stored in a hi-score list.

###Objects
> There are numerous objects that appear sporadically throughout gameplay. Some are enemies that do damage upon collision while others are powerups that improve either performance or score.

####Protagonist
(for image see ./Images/redekopp.png)
>  Our favorite computer programmer is controlled via the keyboard arrow keys and attempts to avoid the malicious computer science objects to score a good grade. He starts with five lives and loses them upon collision with these enemies. However, he can gain back lives.

####Life Up
(for image see ./Images/redekopp.png)
>  This floating head will give a life back if our protagonist is not at full health. However, if he is then the life up will provide a significant point boost.

####Pointers
(for image see ./Images/pointer_up.png)
>   This is the most basic item that attacks horizontally or vertically. It occupies one space and is the most common enemy. It takes one life on collision.

####Trees
(for image see ./Images/rainbow-satan-tree.png)
>  This object will spawn sporadically and remain on the board for a predetermined amount of time. Contact with the 'tree' will cost the player a life.

####RAM
(for image see ./Images/ram.png)
(for image see ./Images/heap.png)
>  This "ram" will run across the top of the board and rain down "heaps" of excrement that take away a life upon impact.

####Debug
(for image see./Images/ladebug.png)
>  This crucial tool of all good programmers removes all the objects on the screen.

