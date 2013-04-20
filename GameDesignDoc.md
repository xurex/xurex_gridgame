# Game Design Document

##Basic Gameplay Description
> A figure moves within a 10x10 grid to avoid objects that are flying across the screen. This top down game is "won" by achieving the highest score possible which entails staying alive as long as possible and picking up powerups. There are three levels of increasing difficulty in which different "enemies" are introduced.

###Objects
> There are numerous objects that appear sporadically throughout gameplay. Some are enemies that do damage upon collision while others are powerups that improve either performance or score.

####Protagonist
![alt text](https://github.com/usc-csci102-spring2013/game_rexxu/redekopp.jpg "Mad Computer Scientist")
>  Our favorite computer programmer is controlled via the keyboard arrow keys and attempts to avoid the malicious computer science objects to score a good grade. He starts with three lives and loses them upon collision with these enemies. However, he can gain back lives. If he needs a break, spacebar pauses the game.

####Life Up
![alt text](https://github.com/usc-csci102-spring2013/game_rexxu/redekopp.jpg "Life Up")
>  This floating head will give a life back if our protagonist is not at full health. However, if he is then the life up will provide a significant point boost. These objects occur once per level.

####Pointers
![alt text](http://www.psdgraphics.com/file/mouse-cursor-icon.jpg "Pointer")
>   This is the most basic item that attacks horizontally or vertically. It occupies one space and is the most common enemy. It takes one life on collision.

####Trees
![alt text](http://theory.cs.uvic.ca/inf/tree/redblack.gif "Red Black Tree")
>  This object attacks by "adding" nodes. It will branch out across the game board and take away a life upon collision.

####RAM
![alt text](http://www.animateit.net/data/media/124/ram.gif "RAM")
![alt text](http://www.mattbors.com/images/turd.gif "Heap")
>  This "ram" will run across the top of the board and rain down "heaps" of excrement that take away two lives upon impact.

####Debug
![alt text]
